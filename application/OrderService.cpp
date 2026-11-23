#include "OrderService.hpp"

OrderService::OrderService() : orderbook(6 , 20 , 0 , 0)
{

}

OrderService& OrderService::getInstance()
{
    static OrderService orderservice;
    return orderservice;
}

std::string OrderService::placeOrder(const Json::Value & json)
{
    
} 