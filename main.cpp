
#include <iostream>
#include <cassert>
#include <limits>
#include "MarketData.h"

int main() {

    // Valid market data
    MarketData data(100.50, 105.75, 98.25, 103.20, 15000);

    std::cout << "Opening Price: " << data.getOpen() << '\n';
    std::cout << "High Price: " << data.getHigh() << '\n';
    std::cout << "Low Price: " << data.getLow() << '\n';
    std::cout << "Close Price: " << data.getClose() << '\n';
    std::cout << "Volume: " << data.getVolume() << '\n';

    // Basic getter assertions
    assert(data.getOpen() == 100.50);
    assert(data.getHigh() == 105.75);
    assert(data.getLow() == 98.25);
    assert(data.getClose() == 103.20);
    assert(data.getVolume() == 15000);

    std::cout << "Getter tests passed!\n";

    // Negative volume test
    try {
        MarketData invalidVolume(100, 105, 95, 102, -500);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Validation Error: " << e.what() << '\n';
    }

    // Non-positive price test
    try {
        MarketData invalidPrice(0, 105, 95, 102, 15000);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Validation Error: " << e.what() << '\n';
    }

    // Infinite price test
    try {
        MarketData invalidInfinity(
            std::numeric_limits<double>::infinity(),
            105, 95, 102, 15000
        );
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Validation Error: " << e.what() << '\n';
    }

    return 0;
}
