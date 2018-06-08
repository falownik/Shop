#include "shop.hpp"
#include "producer.hpp"



class Shop
{
    public:
    initialize();
    std::vector <Product> product;
    std::vector <Producer> producer;
};

class Interface
{
    public:
    Shop shop;
    Interface();
    void menu();
    void printProductsAll();

};