#include "../include/Trade.hpp"
#include<iostream>
#include<iomanip>


void Trade::set_trade(int trade_id , int price , int quantity , std::chrono::system_clock::time_point timestamp , int buy_order_id , int sell_order_id){

    this->trade_id = trade_id;
    this->price = price;
    this->quantity = quantity;
    this->timestamp = timestamp;
    this->buy_order_id = buy_order_id;
    this->sell_order_id = sell_order_id;
}

void Trade::print()
{
  
    std::cout << "Trade ID: " << trade_id << '\n';
    std::cout << "Price: " << price << '\n';
    std::cout << "Quantity: " << quantity << '\n';
    std::cout << "Buy Order ID: " << buy_order_id << '\n';
    std::cout << "Sell Order ID: " << sell_order_id << '\n';
    std::time_t time = std::chrono::system_clock::to_time_t(timestamp);
    std::cout << "Timestamp: "
            << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
            << '\n';
    std::cout << "------------------------------------\n";

}