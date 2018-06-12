#include <iostream>
#include <string>
#include <vector>

class Producer
{
public:
    std::string name;
    std::string adress;
    std::string telephone;
    std::string mail;
    long long int nip;

    void addProducerConsole();
    void deleteProducerConsole();
    void addProducerToFile();
    Producer initialize();


};
