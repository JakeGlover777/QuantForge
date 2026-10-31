
#ifndef QUANTFORGE_MARKETDATA_H
#define QUANTFORGE_MARKETDATA_H

#include <stdexcept>
#include <cmath>

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
        if (!std::isfinite(open) ||
            !std::isfinite(high) ||
            !std::isfinite(low) ||
            !std::isfinite(close)) {
            throw std::invalid_argument("Prices must be finite");
            }

        if (open <= 0 || high <= 0 ||
            low <= 0 || close <= 0) {
            throw std::invalid_argument("Prices must be positive");
            }

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

    double getOpen() const { return open; }
    double getHigh() const { return high; }
    double getLow() const { return low; }
    double getClose() const { return close; }
    long long getVolume() const { return volume; }
};

#endif // QUANTFORGE_MARKETDATA_H
