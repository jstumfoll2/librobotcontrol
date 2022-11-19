////////////////////////////////////////
//	gpio_rpmsg.c
//	Uses rpmsg to control GPIO PRU pin via /dev/rpmsg_pru32 on the ARM
//	Usage:	echo 1 > /dev/rpmsg_pru32 to set the GPIO high
//			echo 0 > /dev/rpmsg_pru32 to set the GPIO low
//	Wiring:	Controls GPIO on pin P9_13
//
//	Setup:	None
//	See:	 
//	PRU:	pru2_0
////////////////////////////////////////


#include <stdint.h>
#include <stdlib.h>			// atoi
#include <pru_cfg.h>
#include <pru_intc.h>
#include <pru_rpmsg.h>

#include "prugpio.h"
#include "resource_table_0.h"

volatile register uint32_t __R30;
volatile register uint32_t __R31;

/* Host-0 Interrupt sets bit 30 in register R31 */
#define HOST_INT			((uint32_t) 1 << 30)	

// PRU timing variables
#define resetCycles		51000/5	// Must be at least 50u, use 51u
#define SPEED 20000000/5		// Time to wait between updates

/* The PRU-ICSS system events used for RPMsg are defined in the Linux device tree
 * PRU0 uses system event 16 (To ARM) and 17 (From ARM)
 * PRU1 uses system event 18 (To ARM) and 19 (From ARM)
 * Be sure to change the values in resource_table_0.h too.
 */
#define TO_ARM_HOST			16
#define FROM_ARM_HOST		17

/*
* Using the name 'rpmsg-pru' will probe the rpmsg_pru driver found
* at linux-x.y.z/drivers/rpmsg/rpmsg_pru.c
*/
#define CHAN_NAME			"rpmsg-pru"
#define CHAN_DESC			"Channel 32"
#define CHAN_PORT			32

/*
 * Used to make sure the Linux drivers are ready for RPMsg communication
 * Found at linux-x.y.z/include/uapi/linux/virtio_config.h
 */
#define VIRTIO_CONFIG_S_DRIVER_OK	4

char payload[RPMSG_BUF_SIZE];

void main(void)
{
	// rpmsg veriables
	struct pru_rpmsg_transport transport;
	uint16_t src, dst, len;
	volatile uint8_t *status;
	
	// corresponds to motor pin MDIR_1B
	uint32_t gpio = PR2_P9_13;	//  Pin to toggle

	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
	
	/* Clear the status of the PRU-ICSS system event that the ARM will use to 'kick' us */
#ifdef CHIP_IS_am57xx
	CT_INTC.SICR_bit.STATUS_CLR_INDEX = FROM_ARM_HOST;
#else
	CT_INTC.SICR_bit.STS_CLR_IDX = FROM_ARM_HOST;
#endif	

	/* Make sure the Linux drivers are ready for RPMsg communication */
	status = &resourceTable.rpmsg_vdev.status;
	while (!(*status & VIRTIO_CONFIG_S_DRIVER_OK));

	/* Initialize the RPMsg transport structure */
	pru_rpmsg_init(&transport, &resourceTable.rpmsg_vring0, &resourceTable.rpmsg_vring1, TO_ARM_HOST, FROM_ARM_HOST);

	/* Create the RPMsg channel between the PRU and ARM user space using the transport structure. */
	while (pru_rpmsg_channel(RPMSG_NS_CREATE, &transport, CHAN_NAME, CHAN_DESC, CHAN_PORT) != PRU_RPMSG_SUCCESS);	

	while(1) {
		/* Check bit 30 of register R31 to see if the ARM has kicked us */
		if (__R31 & HOST_INT) {
			/* Clear the event status */
#ifdef CHIP_IS_am57xx
			CT_INTC.SICR_bit.STATUS_CLR_INDEX = FROM_ARM_HOST;
#else
			CT_INTC.SICR_bit.STS_CLR_IDX = FROM_ARM_HOST;
#endif
			/* Receive all available messages, multiple messages can be sent per kick */
			while (pru_rpmsg_receive(&transport, &src, &dst, payload, &len) == PRU_RPMSG_SUCCESS) {
			    int enable;	// enable bit
			    // Input format is:  enable
			    enable = atoi(payload);	
			    
			    if (enable) {
					__R30 |= gpio;		// Set the GPIO pin to 1
			    }
			    else  {
					__R30 &= ~gpio;		// Clear the GPIO pin
			    }

				__delay_cycles(resetCycles);
	
				// Wait
				__delay_cycles(SPEED);
		    }
		}
	}
}
