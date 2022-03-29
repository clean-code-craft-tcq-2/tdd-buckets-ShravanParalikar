#include <stdio.h>
#include <stdlib.h>
#include <cmath.h>

int GetAnalogToDigitalConversion(int ADC_RESOLUTION);
int AnalogToDigitalConversion(int ADC_RESOLUTION);
void SensorAtoDConversion(int A2DSensor_Output[], int numberOfSamples, int ADC_RESOLUTION, int maxCurrentValue, int* currentConversionValues);
void FaultyReadings(void);
void ConvertinAmps(int A2DSensor_Output[], int numberOfSamples, int ADC_RESOLUTION, int maxCurrentValue, int* currentSenseValues);