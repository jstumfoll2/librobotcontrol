/**
 * @example    rc_test_drivers.c
 *
 * without actually calling library functions, this checks that all the drivers
 * necessary for the robot control library to fully work.
 **/

#include <stdio.h>
#include <stdlib.h> // for system()
#include <unistd.h> // for access()
#include <rc/model.h>
#include <rc/version.h>


int main()
{
	printf("\n");
	printf("Test Build with updated i2c ports\n");
	printf("Kernel: ");
	fflush(stdout);
	system("uname -r");
	system("cat /etc/dogtag");
	printf("Debian: ");
	fflush(stdout);
	system("cat /etc/debian_version");
	printf("\n");

	// gpio
	if(access("/dev/gpiochip0", F_OK ) != 0){
		printf("ERROR:  gpio 0 driver not loaded\n");
	} else printf("PASSED: gpio 0\n");
	if(access("/dev/gpiochip1", F_OK ) != 0){
		printf("ERROR:  gpio 1 driver not loaded\n");
	} else printf("PASSED: gpio 1\n");
	if(access("/dev/gpiochip2", F_OK ) != 0){
		printf("ERROR:  gpio 2 driver not loaded\n");
	} else printf("PASSED: gpio 2\n");
	if(access("/dev/gpiochip3", F_OK ) != 0){
		printf("ERROR:  gpio 3 driver not loaded\n");
	} else printf("PASSED: gpio 3\n");

	// pwm 0, 1, 2, 3
	if(access("/sys/devices/platform/44000000.ocp/48440000.epwmss/48440200.pwm/pwm/pwmchip0/pwm-0:0/duty_cycle", F_OK ) != 0){
		printf("ERROR:  ti-pwm driver not loaded for hrpwm1\n");
	} else printf("PASSED: pwm0\n");

	if(access("/sys/devices/platform/44000000.ocp/48440000.epwmss/48440200.pwm/pwm/pwmchip0/pwm-0:1/duty_cycle", F_OK ) != 0){
		printf("ERROR:  ti-pwm driver not loaded for hrpwm2\n");
	} else printf("PASSED: pwm1\n");
	
	if(access("/sys/devices/platform/44000000.ocp/48442000.epwmss/48442200.pwm/pwm/pwmchip2/pwm-2:0/duty_cycle", F_OK ) != 0){
		printf("ERROR:  ti-pwm driver not loaded for hrpwm3\n");
	} else printf("PASSED: pwm2\n");

	if(access("/sys/devices/platform/44000000.ocp/48442000.epwmss/48442200.pwm/pwm/pwmchip2/pwm-2:1/duty_cycle", F_OK ) != 0){
		printf("ERROR:  ti-pwm driver not loaded for hrpwm4\n");
	} else printf("PASSED: pwm3\n");
	
	// eqep 0,1,2 eqep 4843e180.eqep eqep 48440180.eqep eqep 48442180.eqep
	if(access("/sys/devices/platform/44000000.ocp/4843e000.epwmss/4843e180.eqep/position", F_OK ) != 0){
		printf("ERROR:  ti-eqep driver not loaded for eqep0\n");
	} else printf("PASSED: eqep0\n");

	if(access("/sys/devices/platform/44000000.ocp/48440000.epwmss/48440180.eqep/position", F_OK ) != 0){
		printf("ERROR:  ti-eqep driver not loaded for eqep1\n");
	} else printf("PASSED: eqep1\n");

	if(access("/sys/devices/platform/44000000.ocp/48442000.epwmss/48442180.eqep/position", F_OK ) != 0){
		printf("ERROR:  ti-eqep driver not loaded for eqep2\n");
	} else printf("PASSED: eqep2\n");

	// rproc
	//if(access("/sys/class/remoteproc/remoteproc1/state", F_OK ) != 0){
	if(access("/dev/remoteproc/pruss1-core0/state", F_OK ) != 0){
		printf("ERROR:  pru-rproc driver not loaded for pruss1-core0\n");
	} else printf("PASSED: pru-rproc1-0\n");
	if(access("/dev/remoteproc/pruss1-core1/state", F_OK ) != 0){
		printf("ERROR:  pru-rproc driver not loaded for pruss1-core1\n");
	} else printf("PASSED: pru-rproc1-1\n");
	if(access("/dev/remoteproc/pruss2-core0/state", F_OK ) != 0){
		printf("ERROR:  pru-rproc driver not loaded for pruss2-core0\n");
	} else printf("PASSED: pru-rproc2-0\n");
	if(access("/dev/remoteproc/pruss2-core1/state", F_OK ) != 0){
		printf("ERROR:  pru-rproc driver not loaded for pruss2-core1\n");
	} else printf("PASSED: pru-rproc2-1\n");

	// uart
	if(access("/dev/ttyO1", F_OK ) != 0){
		printf("ERROR:  uart1 driver not loaded\n");
	} else printf("PASSED: uart1\n");
	if(access("/dev/ttyO2", F_OK ) != 0){
		printf("ERROR:  uart2 driver not loaded\n");
	} else printf("PASSED: uart2\n");
	if(access("/dev/ttyO4", F_OK ) != 0){
		printf("ERROR:  uart4 driver not loaded\n");
	} else printf("PASSED: uart4\n");
	if(access("/dev/ttyO5", F_OK ) != 0){
		printf("ERROR:  uart5 driver not loaded\n");
	} else printf("PASSED: uart5\n");

	// i2c i2c-3
	if(access("/dev/i2c-3", F_OK ) != 0){
		printf("ERROR:  i2c3 driver not loaded\n");
	} else printf("PASSED: i2c3\n");
	if(access("/dev/i2c-4", F_OK ) != 0){
		printf("ERROR:  i2c4 driver not loaded\n");
	} else printf("PASSED: i2c4\n");

	// spi
	if(access("/dev/spidev1.0", F_OK ) != 0){
		if(access("/dev/spidev2.0", F_OK ) != 0){
			printf("ERROR: spi driver not loaded\n");
		}
		else{
			printf("WARNING: SPI1 loaded but incorrectly enumerated as /dev/spidev2\n");
		}
	} else printf("PASSED: spi\n");

	// LEDs
	if(access("/sys/class/leds/green/brightness", F_OK ) != 0){
		printf("ERROR:  LED driver not loaded\n");
	} else printf("PASSED: LED\n");

	// ADC
	if(access("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", F_OK ) != 0){
		printf("ERROR:  ADC iio driver not loaded\n");
	} else printf("PASSED: ADC iio\n");

	printf("\nCurrently running on a:\n");
	rc_model_print();
	printf("\nRobot Control library Version:\n");
	rc_version_print();
	printf("\n");


	return 0;
}
