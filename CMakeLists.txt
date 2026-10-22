cmake_minimum_required(VERSION 3.20)

project(OrderBook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Download and configure GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

# Compile the OrderBook implementation into a reusable library
add_library(orderbook_lib
    src/Orderbook.cpp
)

target_include_directories(orderbook_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Your normal interactive application
add_executable(orderbook
    src/main.cpp
    src/OrderBook.cpp
)

target_link_libraries(orderbook PRIVATE orderbook_lib)

# Automated tests
enable_testing()

add_executable(orderbook_tests
    tests/OrderBookTests.cpp
)

target_link_libraries(orderbook_tests
    PRIVATE orderbook_lib GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(orderbook_tests)
