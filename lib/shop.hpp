#include <iostream>
#include <string>
#include <vector>
#include "producer.hpp"



class Nutrients
{
public:
    Nutrients();
    int fat;
    int carbohydrates;
    int sugar;
    int salt;
    int protein;
};

class Product
{
public:
    int id;
    Producer producer;
    double price;
    Product();
    virtual void initialize();
    virtual void addToFile();
    virtual void printProduct();
};

class Food : public Product
{
public:
    Food();
    int weight;
    Nutrients nutrients;

};


class Beverage : public Product
{
public:
    Beverage();
    int volume;
    Nutrients nutrients;

};

class NonAlcohol : public Beverage
{
public:
    NonAlcohol();
    int abv; //< alcohol by volume

};


class Chemicals : public Product
{
public:
    Chemicals();
};

