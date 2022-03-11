#include "assert.h"
#include "catch.hpp"
#define CATCH_CONFIG_MAIN

int Current_Samples = 0;

TEST_CASE("Get current samples from session")
{
 Current_Samples = GetCurrentSamples(4,5);
 REQUIRE(Current_Samples == 2);
}
