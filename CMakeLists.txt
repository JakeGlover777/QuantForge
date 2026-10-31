cmake_minimum_required(VERSION 4.1)

project(QuantForge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QuantForge
        main.cpp
        MarketData.h
)

# Enable automated testing
enable_testing()

# Download GoogleTest
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Build MarketData unit tests
add_executable(MarketDataTests
        tests/MarketDataTests.cpp
        tests/MarketdataTests.cpp
)

target_include_directories(MarketDataTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MarketDataTests PRIVATE
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MarketDataTests)
