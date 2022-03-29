#define CATCH_CONFIG_MAIN
#include "assert.h"
#include "test/catch.hpp"
#include "CalcFreqofOccurance.h"
#include "AnalogToDigitalConversion.h"

#define ADC_RESOLUTION  12
#define MAXCURRENTVALUE 10

int CurrentSamplesArray1[4] = {3, 3, 5, 4};
int CurrentSamplesArray2[3] = {10,11,12};

TEST_CASE("Get current samples from Array1")
{
    int Samples = sizeof(CurrentSamplesArray1)/sizeof(CurrentSamplesArray1[0]);
    int TotalNoOfSamples = GetCurrentSamples(CurrentSamplesArray1, Samples);
    REQUIRE(TotalNoOfSamples == 4);
}

TEST_CASE("Get current samples from Array2")
{
    int Samples = sizeof(CurrentSamplesArray2)/sizeof(CurrentSamplesArray2[0]);
    int TotalNoOfSamples = GetCurrentSamples(CurrentSamplesArray2, Samples);
    REQUIRE(TotalNoOfSamples == 3);
}

TEST_CASE("Checks for the current values for given ADC values from an array")
{
	
	int A2DSensor_Output[] = {64, 512, 1146, 1220, 1560, 2048, 4094};
	int numberOfSamples = sizeof(A2DSensor_Output) / sizeof(A2DSensor_Output[0]);
	int CurrentinAmps[] = {0, 2, 3, 3, 4, 5, 10};
	int currentSenseValues[numberOfSamples];

	ConvertinAmps(A2DSensor_Output, numberOfSamples, ADC_RESOLUTION, MAXCURRENTVALUE, currentSenseValues);
	for(int i = 0; i < numberOfSamples; i++)
	{
		REQUIRE(currentSenseValues[i] == CurrentinAmps[i]);
	}
}

TEST_CASE("Checks when given ADC value is 4095")
{
	
	int A2DSensor_Output[] = {4095};
	int numberOfSamples = sizeof(A2DSensor_Output) / sizeof(A2DSensor_Output[0]);
	int currentSenseValues[numberOfSamples];
	int expectednumberOfSamples = 1;
	
	ConvertinAmps(A2DSensor_Output, numberOfSamples, ADC_RESOLUTION, MAXCURRENTVALUE, currentSenseValues);

}

