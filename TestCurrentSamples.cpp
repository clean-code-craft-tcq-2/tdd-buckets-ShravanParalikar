#define CATCH_CONFIG_MAIN
#include "assert.h"
#include "catch.hpp"
#include "CalcFreqofOccurance.h"

int Current_Samples = 0;

TEST_CASE("Get current samples from session")
{
 Current_Samples = GetCurrentSamples(4,5);
 REQUIRE(Current_Samples == 2);
}

TEST_CASE("Get samples from 10-12 range")
{
 Current_Samples = GetCurrentSamples(10,12);
 REQUIRE(Current_Samples == 3);
}
