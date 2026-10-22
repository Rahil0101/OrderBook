#include<map>
#include<iostream>
#include<list>

#include "../include/Orderbook.hpp"


using namespace std;

OrderBook::OrderBook(int order_id , int MAX_BAR , int maxi) : order_id(order_id) , MAX_BAR(MAX_BAR) , maxi(maxi) {

            buyMap[100].push_back({1, 100, 30, Side::BUY,OrderType::LIMIT});
            buyMap[101].push_back({2, 101, 50, Side::BUY,OrderType::LIMIT});
            buyMap[102].push_back({3, 102, 60, Side::BUY,OrderType::LIMIT});

            sellMap[103].push_back({4, 103, 20, Side::SELL,OrderType::LIMIT});
            sellMap[104].push_back({5, 104, 90, Side::SELL,OrderType::LIMIT});
            sellMap[105].push_back({6, 105, 60, Side::SELL,OrderType::LIMIT});


}





        


       template <typename Map>
       void OrderBook::printHelper(Map &orderbook, int maxi , string color)
       {
             for (auto itt = orderbook.begin();itt!=orderbook.end();itt++)
            {
                for (auto listiter = itt->second.begin(); listiter != itt->second.end() ; listiter++) {

                int barLength = (listiter->quantity * MAX_BAR) / maxi;
                string bar(barLength,'#');


                cout << color;

                cout<<listiter->id<<"    "<<listiter->price<<"    "<<listiter->quantity <<"    "<<bar << endl;
                cout << "\033[0m";

                }
            }
       }

        void OrderBook::print () {


            auto it = buyMap.begin();
            auto itt = sellMap.end();
            int maxi = max(it->first,itt->first);
            
            
            printHelper(sellMap,maxi ,"\033[31m");
         
            cout<< "---------------------------------------------------"<<endl;


            printHelper(buyMap,maxi,"\033[32m" );


        }


        template <typename typemap>
        void OrderBook::cancelOrderHelper(typemap &orderbook, unordered_map<int,DeleteDetails>::iterator it){
            orderbook[it->second.price].erase(it->second.it);

        }

         void OrderBook::cancelOrder(int delete_id){
            stack <Order> temp;
            int flag = 0;
            auto it = deleteMap.find(delete_id);
            if (it != deleteMap.end()){

                it->second.side == Side::BUY ? cancelOrderHelper(buyMap,it) : cancelOrderHelper(sellMap,it);
                flag = 1;
            }
            flag == 1 ? cout<<"Order with id "<<delete_id<<" has been cancelled"<<endl : cout<<"No order with id "<<delete_id<<" found"<<endl;

        }

        template <typename maptype>
        void OrderBook::helperMatchData(Order&order, maptype&oppositeBook){
            auto it = oppositeBook.begin();
            int front = it->second.front().quantity;
                    if (front - order.quantity <= 0)
                    {
                        order.quantity = order.quantity - front;
                        deleteMap.erase(it->second.front().id);
                        it->second.pop_front();
                        if (it->second.empty())
                        {
                            oppositeBook.erase(it);
                        }
                    }
                    else {
                        it->second.front().quantity = it->second.front().quantity - order.quantity;
                        order.quantity = 0;
                        
                    }
        }
        template <typename T>
        bool OrderBook::checkSign (Order &order , T& oppositeBook)
        {
            auto it = oppositeBook.begin();
            return order.side == Side::BUY ? order.price >= it->second.front().price : order.price <= it->second.front().price;
        }

        void OrderBook::processOrderCalculation(Order &order)
        {
        order.id = ++order_id;

        if (order.side == Side::BUY){
            if (order.order_type == OrderType::MARKET){
                while (!sellMap.empty() && order.quantity > 0)
                {
                    helperMatchData(order,sellMap);
                }
               
            }
            else {
                while (!sellMap.empty() && order.quantity > 0 && checkSign(order,sellMap))
                {
                    helperMatchData(order,sellMap);
                }

                if (order.quantity != 0)
                {
                    buyMap[order.price].push_back(order);
                    auto it = buyMap[order.price].end();
                    it--;
                    deleteMap[order.id] = {order.price,it,order.side};
                    }
                }
             
            }

        else{
             if (order.order_type == OrderType::MARKET){
                while (!buyMap.empty() && order.quantity > 0)
                {
                    helperMatchData(order,buyMap);
                }
               
            }
        else {
                while (!buyMap.empty() && order.quantity > 0 && checkSign(order,buyMap))
                {
                    helperMatchData(order,buyMap);
                }
                if (order.quantity != 0)
                {
                    sellMap[order.price].push_back(order);
                    auto it = sellMap[order.price].end();
                    it--;
                    deleteMap[order.id] = {order.price,it,order.side};
                }
             
            }
        }

}

    tuple<int,int,Side> OrderBook::check_modify_id (int &modify_id)
        {
            if (deleteMap.find(modify_id) != deleteMap.end())
            {
                Side modify_side = deleteMap[modify_id].side;
                auto it = deleteMap[modify_id].it;
                int price = it->price;
                int quantity = it->quantity;
                
                cout<<"ID  "<< it->id<<"  Price  "<<it->price<<"  Quantity  "<<it->quantity << endl;

               

                return {price,quantity, modify_side};
                


              
            }
            return {-1,-1,Side::BUY};
        }

        void OrderBook::modify_order (int &modify_id , int &new_quantity) {
            deleteMap[modify_id].it->quantity = new_quantity;
        }


        



