#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <iostream>
#include <string>
#include <vector>

class Producer
{
public:
    Producer();
    int id;
    std::string name;
    std::string adress;
    std::string telephone;
    std::string mail;

    void addProducerConsole();
    Producer initialize();

};

#endif