#include "shop.hpp"

class Chemicals : public Product
{
public:
    Chemicals(){};
    virtual void initialize(){};
    double sellProduct();
    virtual void resuplyProduct();
    void addProductConsoleRandom(int, std::string);
    virtual void printProduct(int, std::string);
};

class Makeup : public Chemicals
{
public:
    Makeup();
    
};

class Washing : public Chemicals
{
public:
    Washing();
};

