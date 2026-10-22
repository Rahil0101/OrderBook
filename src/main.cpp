#include <iostream>
#include<stack>
#include<utility>
#include<map>
#include<list>
#include "../include/Orderbook.hpp"
using namespace std;











int main() {

    OrderBook orderBook(6,20,0);
  
    while (true){
    bool flag = false;
    int side,delete_id,quantity , modify_id;
    char choice,order_type;
    
    cout << "Select an option:\n1. View Orderbook\n2. Place Order\n3. Cancel Order\n4. Modify Order\n5. Exit\n";
    cin>>choice;
    switch(choice) {
        case '1':
            cout << "Viewing Orderbook...\n";

            orderBook.print();
            break;
            
        case '2':
            Order order;
            cout << "Do you want to buy or sell:\n1. Buy\n2. Sell\n";
            cin>>side;
            if (side == 1)order.side = Side::BUY;
            else order.side = Side::SELL;
            cout << "Do you want to place market order or limit order \n1. Market\n2. Limit\n";
            cin>>order_type;
            switch (order_type){
                case '1':
                    order.order_type = OrderType::MARKET;
                    cout<<"Enter quantity\n";
                    cin>>order.quantity;
                  
                    quantity = order.quantity;
                    orderBook.processOrderCalculation(order);
                    cout<<"Order placed for "<<quantity - order.quantity<<"/"<<quantity<<" units"<<endl;
                    
                    
                    break;
                    
                case '2':
                    order.order_type = OrderType::LIMIT;

                    cout<<"Enter limit price\n";
                    cin>>order.price;
                    cout<<"Enter quantity"<<endl; 
                    cin>>order.quantity;
                    quantity = order.quantity;
                    orderBook.processOrderCalculation(order);
                    cout<<"Order placed for "<<quantity - order.quantity<<"/"<<quantity<<" units"<<endl;
                    
 
                    break;
                default:
                    cout<<"Invalid choice. Please select a valid option.\n";
            }
            break;
        case '3':
            cout<<"Enter a valid id that you want to cancel"<<endl;
            cin>>delete_id;
            orderBook.cancelOrder(delete_id);
            break;

        case '4':
            {
                cout<<"Enter order id to be modified\n";
            cin>>modify_id;
            auto [price , quantity, side] = orderBook.check_modify_id(modify_id);
            if (price != -1 ) 
            {
                Order order;
                cout<<"Enter new quantity"<<endl;
                cin>>order.quantity;
                cout<<"Enter new price"<<endl;
                cin>>order.price;
                int temp_quantity = order.quantity;
                if (order.quantity > quantity || order.price != price) 
                {
                    order.order_type = OrderType::LIMIT;
                    order.side = side;
                
                    orderBook.cancelOrder(modify_id);
                    orderBook.processOrderCalculation(order);
                    cout<<"Created a new order with new price and quantity"<<endl;
                    cout<<"New order fulfilled for "<<temp_quantity - order.quantity<<"/"<<temp_quantity<<" units"<<endl;

                }
                else{
                    orderBook.modify_order(modify_id , order.quantity);
                    cout<<"Modified the order with the new price and quantity\n";
                    cout<<"Modified order fulfilled for "<<temp_quantity - order.quantity<<"/"<<temp_quantity<<" units"<<endl;


                }


            }
            else cout<<"Coudn't find the order with that id."<<endl;

            break;
        }
        case '5':
            cout << "Exiting...\n";
            flag = true;
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
    }
    if(flag) break;
}
return 0;
}
