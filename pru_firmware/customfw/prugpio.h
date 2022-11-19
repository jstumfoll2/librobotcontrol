// This file defines the GPIO port addresses and PRU address

#if defined(CHIP) && defined(CHIP_IS_am57xx)
#warning "Found AI"
// These are addresses for the am5729
// First define the 9 GPIO port addresses
#define GPIO1 0x4AE10000
#define GPIO2 0x48055000
#define GPIO3 0x48057000
#define GPIO4 0x48059000
#define GPIO5 0x4805B000
#define GPIO6 0x4805D000
#define GPIO7 0x48051000
#define GPIO8 0x48053000

// These define which bits in a given port go to the USR LEDs
// GPIO3
#define USR0 (1<<17)
#define USR2 (1<<15)
#define USR3 (1<<14)
#define USR4 (1<< 7)
// GPIO5
#define USR1 (1<< 5)
// The define a couple of GPIO pin addresses
// GPIO6
#define P9_25   (1<<17)
// GPIO8
#define P8_17   (1<18)



// These define which bin in register R30 go to which header pins

/// PR1_PRU0

// R30/R31 bits - Output/Input on pru1_0
#define PR1_P8_12   (1<<3)
#define PR1_P8_11   (1<<4)
#define PR1_P9_15   (1<<5)
#define PR1_P9_26   (1<<17)


// R30/R31  bits - Output/Input on pru1_1
#define PR1_P9_20   (1<<1)
#define PR1_P9_19   (1<<2)
#define PR1_P9_41   (1<<3)
#define PR1_P8_18   (1<<5)
#define PR1_P8_19   (1<<6)
#define PR1_P8_13   (1<<7)
#define PR1_P8_14   (1<<9)
#define PR1_P9_42   (1<<10)
#define PR1_P9_27   (1<<11)
#define PR1_P9_14   (1<<14)
#define PR1_P9_16   (1<<15)
#define PR1_P8_15   (1<<16)
#define PR1_P8_26   (1<<17)
#define PR1_P8_16   (1<<18)


/// PR2_PRU0
// R30/R31 bits - Output/Input on pru2_0

// two sets of pins connected to these signals
#define PR2_P8_21    (1<<2) 
#define PR2_P8_20    (1<<3) 
#define PR2_P8_25    (1<<4) 
#define PR2_P8_24    (1<<5) 
#define PR2_P8_5     (1<<6)
#define PR2_P8_6     (1<<7)
#define PR2_P8_23    (1<<8) 
#define PR2_P8_22    (1<<9) 
#define PR2_P8_3     (1<<10)
#define PR2_P8_4     (1<<11)
#define PR2_P9_11    (1<<14) 
#define PR2_P9_13    (1<<15) 
#define PR2_P8_8     (1<<20)

#define PR2_P8_44    (1<<0)   
#define PR2_P8_41    (1<<1)   
#define PR2_P8_42    (1<<2)   
#define PR2_P8_39    (1<<3)   
#define PR2_P8_40    (1<<4)   
#define PR2_P8_37    (1<<5)   
#define PR2_P8_38    (1<<6)   
#define PR2_P8_36    (1<<7)   
#define PR2_P8_34    (1<<8)   
#define PR2_P8_35    (1<<9)   
#define PR2_P8_33    (1<<10)   
#define PR2_P8_31    (1<<11)   
#define PR2_P8_32a   (1<<12)    
#define PR2_P8_45b   (1<<13)    
#define PR2_P9_11    (1<<14)   
#define PR2_P8_17    (1<<15)   
#define PR2_P8_27b   (1<<16)    
#define PR2_P8_28    (1<<17)   
#define PR2_P8_29    (1<<18)   
#define PR2_P8_30    (1<<19)   
#define PR2_P8_46b   (1<<20)   

/// PR2_PRU1
// R30/R31 bits - Output/Input on pru2_1
// Note all not available for both input and output options, check pin defintions
#define PR2_P8_32b   (1<<0)    
#define PR2_P9_25    (1<<5)   
#define PR2_P8_9     (1<<6)  
#define PR2_P9_31b   (1<<7)    
#define PR2_P9_18    (1<<8)   
#define PR2_P9_17    (1<<9)   
#define PR2_P9_31a   (1<<10)    
#define PR2_P9_29    (1<<11)   
#define PR2_P9_30    (1<<12)   
#define PR2_P9_26    (1<<13)    
#define PR2_P9_28    (1<<13)   
#define PR2_P9_42    (1<<14)   
#define PR2_P8_10    (1<<15)   
#define PR2_P8_7     (1<<16)  
#define PR2_P8_27a   (1<<17)    
#define PR2_P8_45a   (1<<18)    
#define PR2_P8_46a   (1<<19)    
#define PR2_P8_43    (1<<20)  



// Shared memory
#define AM33XX_DATARAM0_PHYS_BASE1		0x4b200000
#define AM33XX_DATARAM1_PHYS_BASE1		0x4b202000
#define AM33XX_PRUSS_SHAREDRAM_BASE1	0x4b210000

#define AM33XX_DATARAM0_PHYS_BASE2		0x4b280000
#define AM33XX_DATARAM1_PHYS_BASE2		0x4b282000
#define AM33XX_PRUSS_SHAREDRAM_BASE2	0x4b290000

#else

#warning "Found am335x"
// These are addresses for the am35xx
#define GPIO0 0x44E09000
#define GPIO1 0x4804C000
#define GPIO2 0x481AC000
#define GPIO3 0x481AE000

// USR LED bit positions
// GPIO 1
#define USR0 (1<<21)
#define USR1 (1<<22)
#define USR2 (1<<23)
#define USR3 (1<<24)
// The define a couple of GPIO pin addresses on Black
// GPIO1
#define P9_14 (1<<18)
#define P9_16 (1<<19)

// The define a couple of GPIO pin addresses on Pocket
// GPIO1
#define P2_1 (1<<18)
#define P1_32 (1<<10)

// R30 output bits on pru0
#define P9_31   (1<<0)
#define P9_29   (1<<1)
#define P9_30   (1<<2)
#define P9_28   (1<<3)
#define P9_92   (1<<4)
#define P9_27   (1<<5)
#define P9_91   (1<<6)
#define P9_25   (1<<7)

// R30 output bits on pru0 on Pocket
#define P1_36   (1<<0)
#define P1_33   (1<<1)
#define P2_32   (1<<2)
#define P2_30   (1<<3)
#define P1_31   (1<<4)
#define P2_34   (1<<5)
#define P2_28   (1<<6)
#define P1_29   (1<<7)

// Shared memory
#define AM33XX_DATARAM0_PHYS_BASE		0x4a300000
#define AM33XX_DATARAM1_PHYS_BASE		0x4a302000
#define AM33XX_PRUSS_SHAREDRAM_BASE		0x4a310000

#endif
// /4 to convert from byte address to word address
#define GPIO_CLEARDATAOUT	0x190/4     // Write 1 here to set a given bit    
#define GPIO_SETDATAOUT 	0x194/4     // A 1 here clears the corresponding bit
#define GPIO_DATAOUT		0x138/4     // For reading the GPIO registers
