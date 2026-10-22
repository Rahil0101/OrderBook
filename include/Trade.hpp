#pragma once
#include<map>
#include<list>

struct Trade {
    int trade_id;
    int price;
    int quantity;
    int buy_order_id;
    int sell_order_id;
    std::chrono::system_clock::time_point timestamp;


    public :

    void set_trade(int trade_id , int price , int quantity , std::chrono::system_clock::time_point timestamp , int buy_order_id , int sell_order_id);
    void print();

};