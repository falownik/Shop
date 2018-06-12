#ifndef SHOP_HPP
#define SHOP_HPP

#include <iostream>
#include <string>
#include <vector>
#include "producer.hpp"



class Product
{
public:
    std::string name;
    std::string package;
    long long int nip;
    long int quantityInShop;
    double price;
    Product(){};
    //virtual void addProductConsole(){};
    //virtual void deleteProductConsole(){};
    virtual void resupplyProduct(){};
    virtual double sellProduct(){};
    virtual void printProduct(){};
};


#endif

