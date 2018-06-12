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
    //virtual void addProductConsole(){};
    virtual double sellProduct();
    virtual void resupplyProduct();
    void addProductConsoleRandom(int, std::string);
    virtual void printProduct(int, std::string);

};