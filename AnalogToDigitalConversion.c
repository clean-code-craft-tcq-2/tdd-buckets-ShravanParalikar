#include "AnalogToDigitalConversion.h"

void FaultyReadings(void)
{
	printf("Faulty Readings\n");
}

int GetAnalogToDigitalConversion(int ADC_RESOLUTION)
{
	return (pow(2,ADC_RESOLUTION) - 2);
}

int AnalogToDigitalConversion(int ADC_RESOLUTION)
{
	return (pow(2,ADC_RESOLUTION) - 1);
}

void SensorAtoDConversion(int A2DSensor_Output[], int numberOfSamples, int ADC_RESOLUTION, int MAXCURRENTVALUE, int* currentConversionValues)
{
	float currentValue;
	int   AToDSensorValue;
	
	for (int i=0; i< numberOfSamples; ++i)
	{
		AToDSensorValue = (MAXCURRENTVALUE * A2DSensor_Output[i]);
		currentValue    = (AToDSensorValue/(GetAnalogToDigitalConversion(ADC_RESOLUTION)));
		currentConversionValues[i] = round(currentValue);
		if(currentConversionValues[i] < 0)
		{
			currentConversionValues[i] = abs(currentConversionValues[i]);
		}
	}
}

void ConvertinAmps(int A2DSensor_Output[], int numberOfSamples, int ADC_RESOLUTION, int MAXCURRENTVALUE, int* currentSenseValues)
{
	for (int i = 0; i< numberOfSamples; ++i)
	{
		if(A2DSensor_Output[i] < (AnalogToDigitalConversion(ADC_RESOLUTION)))
		{
			SensorAtoDConversion(A2DSensor_Output, numberOfSamples, ADC_RESOLUTION, MAXCURRENTVALUE,currentSenseValues);
		}
		else
		{
			FaultyReadings();	
		}
	}
}