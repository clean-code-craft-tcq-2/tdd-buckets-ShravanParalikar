#define CATCH_CONFIG_MAIN
#include "assert.h"
#include "test/catch.hpp"
#include "CalcFreqofOccurance.h"

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
