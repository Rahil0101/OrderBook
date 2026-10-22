#pragma once

#include <list>

// Defined order-related types in one place
enum class Side {
    BUY,
    SELL
};

enum class OrderType {
    MARKET,
    LIMIT
};

struct Order {
    int id;
    int price;
    int quantity;
    Side side;
    OrderType order_type;
};

struct DeleteDetails {
    int price;
    std::list<Order>::iterator it;
    Side side;
};