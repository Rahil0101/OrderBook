#include "../include/OrderHistory.hpp"

#include<iostream>
#include<iomanip>

OrderHistory::OrderHistory(int order_id , Side side , OrderType order_type, int quantity): order_id(order_id) , side(side) , order_type(order_type) , quantity(quantity) {
    timestamp = std::chrono::system_clock::now();
}

void OrderHistory::trade_add(Trade & trade)
{
    trades.push_back(trade);
}

void OrderHistory::print()
{
    std::cout << "\n========== ORDER DETAILS ==========\n";

    std::cout << "Order ID: " << order_id << '\n';
    std::cout << "Total Quantity Requested: " << quantity << '\n';

    std::cout << "Side: "
            << (side == Side::BUY ? "BUY" : "SELL") << '\n';

    std::cout << "Order Type: "
            << (order_type == OrderType::MARKET ? "MARKET" : "LIMIT")
            << '\n';

    // Convert the timestamp to a readable date and time.
    std::time_t time = std::chrono::system_clock::to_time_t(timestamp);
    std::cout << "Timestamp: "
            << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
            << '\n';
    std::cout << "\n========== EXECUTED TRADES ==========\n";

    if (trades.empty()) {
        std::cout << "\nNo trades executed.\n"<<std::endl;
    }
    for (auto trade : trades)
    {
        trade.print();
    }
}