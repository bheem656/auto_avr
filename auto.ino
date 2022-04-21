#include <SPI.h>

#include "rtd.h"
#include "mpx5700.h"
#include "Timer.h"
#include "board.h"
#include "disp.h"

Timer t;  // Define Timer object
mpx5700 mpx;

uint8_t sw_p_status = 1;
uint8_t sw_t_status = 1;
uint8_t sw_s_status = 1;


 void LD_TEST(void)
 {

  digitalWrite(water_status_led, HIGH);  
  digitalWrite(drain_status_led, HIGH); 
//
  digitalWrite(bnd_s__led, HIGH);  
  digitalWrite(vacuum_s_led, HIGH);  

  digitalWrite(unwrapped_led, HIGH);  
  digitalWrite(wrapped_led, HIGH); 
  digitalWrite(prion_led, HIGH); 
  digitalWrite(porous_led, HIGH); 
//
  digitalWrite(start_led, HIGH);  
  digitalWrite(vacuum_led, HIGH); 
  digitalWrite(serilize_led, HIGH); 
  digitalWrite(dry_led, HIGH); 
  digitalWrite(end_led, HIGH); 
//
  digitalWrite(t134_led, HIGH); 
  digitalWrite(t121_led, HIGH); 
//
//
  digitalWrite(WAT_VALVE, HIGH); 
  digitalWrite(AIR_VALVE, HIGH); 
  digitalWrite(EXST_VALVE, HIGH); 
  digitalWrite(VACU_VALVE, HIGH); 
//
  digitalWrite(WAT_PUMP, HIGH); 
  digitalWrite(VAC_PUMP, HIGH);  

//  DDRK |= 0xFF;
//PORTK |= 0xFF;
//
//
//  DDRA |= 0xFF;
//PORTA |= 0xFF;
//
//DDRA |= _BV(DDA7);
//PORTA |= _BV(PORTA7);
//
//DDRJ |= _BV(DDJ7);
//PORTJ |= _BV(PORTJ7);

 }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Set Baudrate at 9600

  initialize_lcd();
  Disp_board_config();
  board_init();        // SET Direction all GPIO
 LD_TEST();
//  t.every(100, takeTempReading);   // Take Reading Every 100ms
//  t.every(150, takePressReading);  // Take Reading Every 100ms

//  attachInterrupt(digitalPinToInterrupt(DIST_WATER_SENSE), water_level_dist, CHANGE);
//  attachInterrupt(digitalPinToInterrupt(USE_WATER_SENSE), water_level_used, CHANGE);

  lcd1_temp(134.77);
lcd2_press(-87.77);
//lcd3_time_incr(1,30);
delay(1000);
 
 delay(1000);
}

void loop() {

//  t.update();  // Update Timer
uint8_t prgm_count = 0;
uint8_t test_prgm_count = 5;
uint8_t prgm_running = 0;

//sw_p_status = 0;
//sw_t_status = 0;

  // read the state of the pushbutton value:
  // sw_p_status = digitalRead(SW_program);
  // sw_s_status = digitalRead(SW_start);
  // sw_t_status = digitalRead(SW_test);

//  if ((digitalRead(SW_program) == 0) && (prgm_running == 0))
//   {
//   
//    if(prgm_count <= 5)
//      prgm_count++;
//    else
//      prgm_count = 0;
//    
//    sw_p_status = 1;
//    sw_t_status = 0;
//    program_status_led_glow(prgm_count);   
//
//  } 
//
//  
// if ((digitalRead(SW_test) == 0) && (prgm_running == 0))
//  {    
//
//    if(test_prgm_count == 5)
//      test_prgm_count = 6;
//    else
//      test_prgm_count = 5;
//
//    sw_p_status = 0;
//    sw_t_status = 1;
//    program_status_led_glow(prgm_count); 

//  } 
//
//    
//  if (digitalRead(SW_start) == 0) 
//  {
//    
//
//    if(prgm_running)
//      {
//      prgm_running = 0;
//      // pause all items
//      
//      }
//
//    else
//    {
//      prgm_running = 1;
//
//      if(sw_p_status)
//        program_run(prgm_count);
//
//      if(sw_t_status)
//        program_run(test_prgm_count);
//
//    }
//
//  } 

  
}




void get_pressure(void) {
  //this example will presesnt pressure if you have a >= 0 pressure value else it prints the vacuum in inHg
  // int sensorPin = A1;
  int psi = mpx.getPsi(PresssensorPin);
  if (psi >= 0) {
    Serial.println(mpx.getPsi(PresssensorPin), DEC);
    Serial.println("maxpsi");
    Serial.println(mpx.maxPsi(psi), DEC);
    delay(1000);

  } else {
    Serial.println(mpx.getVac(PresssensorPin), DEC);
    Serial.println("max vac");
    Serial.println(mpx.maxVac(psi), DEC);
    delay(1000);
  }
  // Display result
  delay(40);  // Wait 400 milliseconds
}

void takePressReading(void) {
  rawADC = analogRead(PresssensorPin);                  // raw data
  PsensorValue = (float)rawADC * 5.0 / 1024.0;          // raw data convert to volt
  PpressureValue = (PsensorValue - 0.2) / 4.5 * 700.0;  // sensor-offset = 0.2V, voltage range = 4.5V, pressure range = 700kPa, pressure = mV/kPa
}

void takeTempReading(void) {
  // Bits to Voltage
  ts1 = analogRead(rtd2);
  ts2 = analogRead(rtd3);
  ts3 = analogRead(rtd4);
  ts4 = analogRead(rtd5);

  V1 = (ts1 / 1023.0) * 5.0;  // (bits/2^n-1)*Vmax
  V2 = (ts1 / 1023.0) * 5.0;  // (bits/2^n-1)*Vmax
  V3 = (ts1 / 1023.0) * 5.0;  // (bits/2^n-1)*Vmax
  V4 = (ts1 / 1023.0) * 5.0;  // (bits/2^n-1)*Vmax
  // Voltage to resistance
  Rx1 = V1 * slope + C;  //y=mx+c
  Rx2 = V2 * slope + C;  //y=mx+c
  Rx3 = V3 * slope + C;  //y=mx+c
  Rx4 = V4 * slope + C;  //y=mx+c
  // Resistance to Temperature
  temp1 = (Rx1 / R0 - 1.0) / alpha;  // from Rx = R0(1+alpha*X)
  temp2 = (Rx2 / R0 - 1.0) / alpha;  // from Rx = R0(1+alpha*X)
  temp3 = (Rx3 / R0 - 1.0) / alpha;  // from Rx = R0(1+alpha*X)
  temp4 = (Rx4 / R0 - 1.0) / alpha;  // from Rx = R0(1+alpha*X)
  // Uncommect to convet celsius to fehrenheit
  // temp = temp*1.8+32;
  Serial.println(temp1);
  Serial.println(temp2);
  Serial.println(temp3);
  Serial.println(temp4);
}




void water_level_dist(void) {
  uint8_t buttonState = digitalRead(DIST_WATER_SENSE);
  if (buttonState == HIGH)
    digitalWrite(water_status_led, HIGH);
  else
    digitalWrite(water_status_led, LOW);
}
void water_level_used(void) {
  uint8_t buttonState = digitalRead(USE_WATER_SENSE);
  if (buttonState == HIGH)
    digitalWrite(drain_status_led, HIGH);
  else
    digitalWrite(drain_status_led, LOW);
}
void door_status(void) {
  uint8_t buttonState = digitalRead(DOOR_SENSE);
  // if(buttonState == HIGH)
  //   digitalWrite(buzzer, HIGH);
  // else
  //   digitalWrite(buzzer, LOW);
}

void unwrapped_cycle()
{ 

 
}
void wrapped_cycle()
{

}
void prion_cycle()
{

}
void poros_cycle()
{

}
void all_prgrm_cycle()
{

}
void bnd_prgrm_cycle()
{

}
void vaccum_prgrm_cycle()
{

}

void program_run(uint8_t num)
{
   switch (num)
  {
  case unwrapped: unwrapped_cycle();  break;
  case wrapped: wrapped_cycle();  break;
  case prion: prion_cycle(); break;
  case poros:  poros_cycle();  break;
  case all_prgrm: all_prgrm_cycle(); break;
  case bnd_prgrm: bnd_prgrm_cycle(); break;
  case vaccum_prgrm: vaccum_prgrm_cycle(); break;
  default:  break;
  }
}

void program_status_led_glow(uint8_t num)
{

  switch (num)
  {
  case unwrapped:
    digitalWrite(unwrapped_led,HIGH); // unwrapped  
    digitalWrite(wrapped_led,LOW);
    digitalWrite(prion_led,LOW);
    digitalWrite(porous_led,LOW);

    digitalWrite(bnd_s__led,LOW);
    digitalWrite(vacuum_s_led,LOW);

    digitalWrite(t134_led,HIGH); //   
    break;

  case wrapped:
    digitalWrite(unwrapped_led,LOW);
    digitalWrite(wrapped_led, HIGH); //   
    digitalWrite(prion_led,LOW);
    digitalWrite(porous_led,LOW);

    digitalWrite(bnd_s__led,LOW);
    digitalWrite(vacuum_s_led,LOW);

    digitalWrite(t134_led, HIGH); //   
    break;

  case prion:
    digitalWrite(unwrapped_led,LOW);
    digitalWrite(wrapped_led,LOW);
    digitalWrite(prion_led, HIGH); //   
    digitalWrite(porous_led,LOW);

    digitalWrite(bnd_s__led,LOW);
    digitalWrite(vacuum_s_led,LOW);

    digitalWrite(t134_led, HIGH); //   
    break;

  case poros:
    digitalWrite(wrapped_led,LOW);
    digitalWrite(wrapped_led,LOW);
    digitalWrite(prion_led,LOW);
    digitalWrite(porous_led, HIGH); //   

    digitalWrite(bnd_s__led,LOW);
    digitalWrite(vacuum_s_led,LOW);

    digitalWrite(t121_led, HIGH); //   
    break;

  case all_prgrm:
    digitalWrite(unwrapped_led,HIGH); //   
    digitalWrite(wrapped_led,HIGH);   //   
    digitalWrite(prion_led,HIGH);     //   
    digitalWrite(porous_led,HIGH);    //   

    digitalWrite(bnd_s__led,LOW);
    digitalWrite(vacuum_s_led,LOW);

    digitalWrite(t134_led,HIGH); //   
    break;

  case bnd_prgrm:
    digitalWrite(unwrapped_led,LOW); //   
    digitalWrite(wrapped_led,LOW);   //   
    digitalWrite(prion_led,LOW);     //   
    digitalWrite(porous_led,LOW);    //   

    digitalWrite(bnd_s__led,HIGH);
    digitalWrite(vacuum_s_led,LOW);

    digitalWrite(t134_led, HIGH); //   
    break;

  case vaccum_prgrm:
    digitalWrite(unwrapped_led,LOW); //   
    digitalWrite(wrapped_led,LOW);   //   
    digitalWrite(prion_led,LOW);     //   
    digitalWrite(porous_led,LOW);    //   

    digitalWrite(bnd_s__led,LOW);
    digitalWrite(vacuum_s_led, HIGH);

    digitalWrite(t134_led, HIGH); //   
    break;

  default:
    break;
  }
}

void board_init(void) {

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
  pinMode(buzzer, OUTPUT);




  pinMode(rtd2, INPUT);  // rtd2  PresssensorPin
  pinMode(rtd3, INPUT);
  pinMode(rtd4, INPUT);
  pinMode(rtd4, INPUT);
  pinMode(PresssensorPin, INPUT);

  pinMode(SW_program, INPUT);
  pinMode(SW_start, INPUT);
  pinMode(SW_test, INPUT);

  pinMode(DIST_WATER_SENSE, INPUT);
  pinMode(USE_WATER_SENSE, INPUT);
  pinMode(DOOR_SENSE, INPUT);
}
