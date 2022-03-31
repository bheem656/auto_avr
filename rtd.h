
#ifndef RTD_h
#define RTD_h
#include "Arduino.h"


// int Vin = A0; // Vin is Analog Pin A0

uint8_t rtd5 = A8;
uint8_t rtd2 = A5;
uint8_t rtd3 = A6;
uint8_t rtd4 = A7;

/* RTD */
// #define Internal_TS   P5// to measure temp inside the chamber
// #define HR_TS  P6  // TO MEASURE TEMP OF THE HEATING RING
// #define SG_TS  P7 // TO measure temp of the steam generator
// #define PS   p4   // to measure pressure of the chamber

// float V;
float temp1;
float temp2;
float temp3;
float temp4;


float Rx1;
float Rx2;
float Rx3;
float Rx4;

// Variables to convert voltage to resistance
float C = 79.489;
float slope = 14.187;

// Variables to convert resistance to temp
float R0 = 100.0;
float alpha = 0.00385;

float ts1;
float ts2;
float ts3;
float ts4;

float V1;
float V2;
float V3;
float V4;

int PresssensorPin = A4;    // Select input pin for the pressure sensor
// int PsensorValue = 0;   // Variable stores value coming from the sensor
int rawADC;
float PsensorValue;
float PpressureValue;

void get_pressure(void);
void takePressReading(void);

void takeTempReading(void);





// void takeReading();

#endif