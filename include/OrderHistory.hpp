#pragma once

#include "Trade.hpp"
#include "Order.hpp"

#include<vector>


class OrderHistory{
    int order_id;
    std::vector <Trade> trades; 
    std::chrono::system_clock::time_point timestamp;
    int quantity;
    Side side;
    OrderType order_type;


    public:

    OrderHistory(int order_id , Side side , OrderType order_type, int quantity);

    void trade_add (Trade & trade);

    void print();

};