#include "MarketData.h"
#include <gtest/gtest.h>
#include <limits>

//
// Created by jakeg on 10/31/2026.
//
TEST(MarketDataTests, GetOpenReturnsCorrectValue) {
    MarketData md(100, 105, 95, 102, 15000);
    EXPECT_DOUBLE_EQ(md.getOpen(),100);
}

TEST(MarketDataTests, RejectsNegativeVolume) {
    EXPECT_THROW(MarketData(100, 105, 95, 102, -15000),
        std::invalid_argument);
}


TEST(MarketDataTests, RejectsZeroPrice) {
    EXPECT_THROW(MarketData(0, 105, 95, 102, 15000),
        std::invalid_argument);
}

TEST(MarketDataTests, RejectsInfinitePrice) {
    EXPECT_THROW(MarketData(std::numeric_limits<double>::infinity(), 105, 95, 102, 15000),
        std::invalid_argument);
    
}

TEST(MarketDataTests, RejectsNaNPrice) {
    EXPECT_THROW(MarketData(std::numeric_limits<double>::quiet_NaN(), 105, 95, 102, 15000),
        std::invalid_argument);

}




