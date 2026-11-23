cmake_minimum_required(VERSION 3.20)

project(OrderBook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


find_package(Drogon CONFIG REQUIRED)
# Your normal interactive application


# Download and configure GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

# Compile the OrderBook implementation into a reusable library
add_library(orderbook_lib
    src/OrderBook.cpp
    src/OrderHistory.cpp
    src/Trade.cpp
)



target_include_directories(orderbook_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/application

)

add_executable(orderbook
    src/main.cpp
)


target_link_libraries(orderbook PRIVATE orderbook_lib Drogon::Drogon)


add_executable(orderbook_server
    server/main.cpp
    server/HealthController.cc
    server/OrderController.cc
    application/OrderService.cpp

)

target_link_libraries(orderbook_server
    PRIVATE
    orderbook_lib
    Drogon::Drogon
)

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
