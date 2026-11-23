#include "OrderController.h"
#include "OrderService.hpp"
// Add definition of your processing function here
void OrderController::placeOrders (const drogon::HttpRequestPtr & req , std::function <void(const drogon::HttpResponsePtr & )> && callback)
{
    auto json = req->getJsonObject();

    if (!json)
    {
        Json::Value response;
        response["error"] = "Invalid JSON.";

        auto httpResponse = drogon::HttpResponse::newHttpJsonResponse(response);
        httpResponse->setStatusCode(drogon::k400BadRequest);
        callback(httpResponse);
        return;
    }
    auto & instance = OrderService::getInstance();
}