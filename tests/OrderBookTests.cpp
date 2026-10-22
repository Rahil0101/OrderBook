
#include <gtest/gtest.h>
#include "Orderbook.hpp"
#include "Order.hpp"

// A basic smoke test to verify the testing framework works.
TEST(OrderBook, Unmatched_Buy_Sell_Orders)
{
    OrderBook orderBook(6 , 20, 90);

    Order order{0, 98 , 70 , Side::BUY , OrderType::LIMIT};

    orderBook.processOrderCalculation(order);

    int id = order.id;

    const Order * order_details = orderBook.getDetails(id);

    ASSERT_NE(order_details , nullptr);

    EXPECT_EQ (order_details->price , 98);
    EXPECT_EQ (order_details->quantity , 70);
    EXPECT_EQ (order_details->side , Side::BUY);
    EXPECT_EQ (order_details->order_type , OrderType::LIMIT);
    EXPECT_EQ (order_details->id , id);




}
