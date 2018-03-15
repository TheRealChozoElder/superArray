#define CATCH_CONFIG_MAIN // this tells catch to provide a main()
// Only do this in one cpp file
#include "catch.hpp" // load test driven Lib
#include "SuperArray.h"

TEST_CASE("1) Test Constructor")
{
    INFO("Testing SuperArray class with Regular indexes");
    int low = 0; //low index
    int cap = 5;
    int high = low + cap -1; //high index
    //create instance of the SuperArray
    SuperArray sa(low, cap);
    for (int i = low; i <= high; i++){
        sa[i] = i + 20;
    }
    SECTION("Test #1: Constructor")
    {
        REQUIRE(arrayToString(sa) == "20 21 22 23 24");
    }
}

TEST_CASE("2) Test Constructor")
{
    INFO("Testing SuperArray class with super indexes");
    int low = 5; //low index
    int cap = 5;
    int high = low + cap -1; //high index
    //create instance of the SuperArray
    SuperArray sa(low, cap);
    for (int i = low; i <= high; i++){
        sa[i] = i + 100;
    }
    SECTION("Test #2: Super Index Constructor")
    {
        REQUIRE(arrayToString(sa) == "105 106 107 108 109");
    }
}

TEST_CASE("3) Test Constructor with Negative Index")
{
    INFO("Testing SuperArray class with negative indexes");
    int low = -20; //low index
    int cap = 5;
    int high = low + cap -1; //high index
    //create instance of the SuperArray
    SuperArray sa(low, cap);
    for (int i = low; i <= high; i++){
        sa[i] = i - 10;
    }
    SECTION("Test #3: Negative Index Constructor")
    {
        REQUIRE(arrayToString(sa) == "-30 -29 -28 -27 -26");
    }
}
