#ifndef board_h
#define board_h

 #include <Arduino.h>
// #include "Arduino.h"
// #include "rtd.h"

// int Vin = A0; // Vin is Analog Pin A0

#define SW_program  45 // PL4 // program
#define SW_start   44//PL5 //start
#define SW_test  43//PL6 //test SW_start
#define SW_D  42//PL7 //na
//
//uint8_t sw_p_status = 1;
//uint8_t sw_t_status = 1;
//uint8_t sw_s_status = 1;

/* SENSE */
#define DIST_WATER_SENSE PE7  // Water Level Sensor of dist water
#define USE_WATER_SENSE PE6  // Water Level Sensor of used tank
#define DOOR_SENSE 3 //PE5



#define water_status_led 28 //PA6  // water_status_LED
#define drain_status_led 26 //PA4  // d13  drain_status_led

#define bnd_s__led 24 //PA2  // d15  b&d_led
#define vacuum_s_led 66 //PK4  // d6 vacuum_led

#define unwrapped_led 29 //PA7 // d2  unwrappped_LED
#define wrapped_led 27 //PA5    // d16 wrapped_led
#define prion_led 25 //PA3  //d14 prion_led
#define porous_led 23 //PA1  //d12  porous_led



#define start_led 22 //PA0  // d17 start_led
#define vacuum_led 69 //PK7  // d3 vacuum_led
#define serilize_led 67 //PK5   // d5 serilize_led
#define dry_led 65 //PK3// d7 dry_led
#define end_led 64 // PK2 d8 end_led


#define t134_led PJ7  // d10 t134_led
#define t121_led 68 //PK6  //d11 t121_led

// #define free_led K,1  //NA free_led

// /* PWM */
// #define PWM0	0 //H,3	//4A	TIMER 4		ch0
// #define PWM1	1 //H,4	//4B	TIMER 4		ch1
// #define PWM3	2 //H,5	//4C	TIMER 4		ch2
// #define PWM4	3 //H,6	//2B	TIMER 2		ch3

// /* VALVE */
#define WAT_VALVE PJ6  //Water Inlet Solenoid Valve
#define AIR_VALVE PJ5  //  Air Inlet Solenoid valve

#define EXST_VALVE PJ4  // Exhausting Air Solenoid Valve (normal open)
#define VACU_VALVE PJ3 // Vacuume Solenoid Valve

// /* PUMP */
#define WAT_PUMP 32 //PC5  // water filling pump
#define VAC_PUMP 33 //PC4  // Vacuum Pump


/* SWITCH */
#define SW_program  PL4 // program
#define SW_start  PL5 //start
#define SW_test  PL6 //test SW_start
#define SW_D  PL7 //na

#define buzzer PB5


void board_init(void);
void water_level_used(void);
void water_level_dist(void);
void door_status(void);
void LD_TEST(void);

void program_status_led_glow(uint8_t num);
void program_run(uint8_t num);
//enum prog_list { unwrapped, wrapped,prion ,poros,all_prgrm,bnd_prgrm,vaccum_prgrm};
 enum prog_list { unwrapped , wrapped,prion ,poros,all_prgrm,bnd_prgrm,vaccum_prgrm};


void unwrapped_cycle();
void wrapped_cycle();
void prion_cycle();
void poros_cycle();
void all_prgrm_cycle();
void bnd_prgrm_cycle();
void vaccum_prgrm_cycle();


#endif
