 #include "board.h"

 void board_init(void)
 {

  pinMode(water_status_led, OUTPUT);  
  pinMode(drain_status_led, OUTPUT); 

  pinMode(bnd_s__led, OUTPUT);  
  pinMode(vacuum_s_led, OUTPUT);  

  pinMode(unwrapped_led, OUTPUT);  
  pinMode(wrapped_led, OUTPUT); 
  pinMode(prion_led, OUTPUT); 
  pinMode(porous_led, OUTPUT); 

  pinMode(start_led, OUTPUT);  
  pinMode(vacuum_led, OUTPUT); 
  pinMode(serilize_led, OUTPUT); 
  pinMode(dry_led, OUTPUT); 
  pinMode(end_led, OUTPUT); 

  pinMode(t134_led, OUTPUT); 
  pinMode(t121_led, OUTPUT); 


  pinMode(WAT_VALVE, OUTPUT); 
  pinMode(AIR_VALVE, OUTPUT); 
  pinMode(EXST_VALVE, OUTPUT); 
  pinMode(VACU_VALVE, OUTPUT); 

  pinMode(WAT_PUMP, OUTPUT); 
  pinMode(VAC_PUMP, OUTPUT); 


  pinMode(PF4, INPUT);   // rtd2  PresssensorPin
  pinMode(PF5, INPUT);  
  pinMode(PF6, INPUT);  
  pinMode(PF7, INPUT); 
  pinMode(PK0, INPUT); 

 }




//  void LD_TEST(void)
// {
//
//  digitalWrite(water_status_led, HIGH);  
//  digitalWrite(drain_status_led, HIGH); 
////
////  digitalWrite(bnd_s__led, HIGH);  
////  digitalWrite(vacuum_s_led, HIGH);  
//
////  digitalWrite(unwrapped_led, HIGH);  
////  digitalWrite(wrapped_led, HIGH); 
////  digitalWrite(prion_led, HIGH); 
////  digitalWrite(porous_led, HIGH); 
////
////  digitalWrite(start_led, HIGH);  
////  digitalWrite(vacuum_led, HIGH); 
////  digitalWrite(serilize_led, HIGH); 
////  digitalWrite(dry_led, HIGH); 
////  digitalWrite(end_led, HIGH); 
////
////  digitalWrite(t134_led, HIGH); 
////  digitalWrite(t121_led, HIGH); 
////
////
////  digitalWrite(WAT_VALVE, HIGH); 
////  digitalWrite(AIR_VALVE, HIGH); 
////  digitalWrite(EXST_VALVE, HIGH); 
////  digitalWrite(VACU_VALVE, HIGH); 
////
////  digitalWrite(WAT_PUMP, HIGH); 
////  digitalWrite(VAC_PUMP, HIGH);  
//
////  DDRK |= 0xFF;
////PORTK |= 0xFF;
////
////
////  DDRA |= 0xFF;
////PORTA |= 0xFF;
////
////DDRA |= _BV(DDA7);
////PORTA |= _BV(PORTA7);
////
////DDRJ |= _BV(DDJ7);
////PORTJ |= _BV(PORTJ7);
//
// }
