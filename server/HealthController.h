#pragma once

#include <drogon/HttpController.h>


class HealthController : public drogon::HttpController<HealthController>
{
  public:
  void getHealth( const drogon::HttpRequestPtr& req,
    std::function<void(const drogon::HttpResponsePtr&)>&& callback);



    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(HealthController::get, "/{2}/{1}", Get); // path is /HealthController/{arg2}/{arg1}
    // METHOD_ADD(HealthController::your_method_name, "/{1}/{2}/list", Get); // path is /HealthController/{arg1}/{arg2}/list
    // ADD_METHOD_TO(HealthController::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
    

    ADD_METHOD_TO(HealthController::getHealth, "/health", drogon::Get);

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
};
