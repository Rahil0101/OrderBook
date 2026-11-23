#include "HealthController.h"

// Add definition of your processing function here
void HealthController::getHealth (const drogon::HttpRequestPtr & req, std::function<void (const drogon::HttpResponsePtr&)> && callback )
{
    Json::Value response;
    response["status"] = "healthy";
    response["service"] = "orderbook";

    auto httpResponse = drogon::HttpResponse::newHttpJsonResponse(response);
    callback(httpResponse);   

}