
#ifndef UNTITLED2_MARKETDATA_H
#define UNTITLED2_MARKETDATA_H

#include <stdexcept>

class MarketData {
private:
    double open;
    double high;
    double low;
    double close;
    long long volume;

public:
    MarketData(double open, double high, double low,
               double close, long long volume)
        : open(open),
          high(high),
          low(low),
          close(close),
          volume(volume)
    {
        if (low > high) {
            throw std::invalid_argument("Low cannot exceed high");
        }

        if (open < low || open > high) {
            throw std::invalid_argument("Open must be between low and high");
        }

        if (close < low || close > high) {
            throw std::invalid_argument("Close must be between low and high");
        }

        if (volume < 0) {
            throw std::invalid_argument("Volume cannot be negative");
        }
    }
};

#endif // UNTITLED2_MARKETDATA_H
