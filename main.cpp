#include <iostream>
#include <vector>
#include <string>
#include <cpr/cpr.h>

std::vector<cpr::Pair> args;

void getFunc()
{
    std::string request = "http://httpbin.org/get?";
    for (int i = 0; i < args.size(); ++i) {
        request += args[i].key + "=" + args[i].value + "&";
    }
    cpr::Response r = cpr::Get(cpr::Url(request));
    std::cout << r.text;
}

void postFunc()
{
    cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                cpr::Payload(args.begin(), args.end()));
    std::cout << r.text;
}

int main() {
    std::string key;
    std::string argument;

    while (key != "exit")
    {
        std::cout << "Input key & argument: ";
        std::cin >> key >> argument;
        if (argument == "get") getFunc();
        else if (argument == "post") postFunc();
        else if (key != "exit") args.push_back(cpr::Pair(key, argument));
    }
    return 0;
}
