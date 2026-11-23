#pragma once

#include "Orderbook.hpp"
#include <json/json.h>

class OrderService {
    OrderBook orderbook ;
    public:
    OrderService();
    static OrderService& getInstance();
    std::string placeOrder(const Json::Value & json);
};