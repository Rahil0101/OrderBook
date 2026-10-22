#pragma once
#include "Order.hpp"
#include<map>
#include<list>

class OrderBook {

    std::map <int,std::list<Order>,std::greater<int>> buyMap;
    std::map<int,std::list<Order>> sellMap;
    std::unordered_map <int,DeleteDetails> deleteMap;
    int order_id , MAX_BAR , maxi;

    public:


    OrderBook(int order_id , int MAX_BAR , int maxi);


    template <typename Map>
    void printHelper(Map &orderbook, int maxi , std::string color);
    void print ();

    template <typename typemap>
    void cancelOrderHelper(typemap &orderbook, std::unordered_map<int,DeleteDetails>::iterator it);

    void cancelOrder(int delete_id);

    template <typename maptype>
    void helperMatchData(Order&order, maptype&oppositeBook);

    template <typename T>
    bool checkSign (Order &order , T& oppositeBook);

    void processOrderCalculation(Order &order);

    std::tuple<int,int,Side> check_modify_id (int &modify_id);

    void modify_order (int &modify_id , int &new_quantity);

    const Order * getDetails (int id) const;









};