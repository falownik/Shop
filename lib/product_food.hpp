#include "shop.hpp"


class Nutrients
{
public:
    Nutrients(){};
    double fat;
    double carbohydrates;
    double sugar;
    double salt;
    double protein;
};

class Food : public Product
{
public:
    Food(){};
    int weight;
    Nutrients nutrients;
    virtual double sellProduct();
    virtual void resupplyProduct();
    void addProductConsoleRandom(int, std::string);
    void addProductToFile();
    void addProductConsole();
    virtual void printProduct(int, std::string);

};

class Cart
{
public: 
    Cart(){};
    std::string name;
    int item;
    double price;
};