#include "shop.hpp"
#include "product_chemicals.hpp"
#include "product_food.hpp"



class Shop
{
    public:
    void initialize();
    void deleteProducer();
    void printProducers();
    void printProductsChemicals();
    void printProductsFood();
    void saveAllToFile();
    void deleteFile();
    void doShoping();
    void sortChemicalsByPriceRising();
    void sortChemicalsByPriceDecreasing();
    void sortFoodByPriceRising();
    void sortFoodByPriceDecreasing();
    std::string getProducersName(long long int );
    std::vector <Chemicals> chemicals;
    std::vector <Food> food;
    std::vector <Producer> producer;
};

class Interface
{
    public:
    Shop shop;
    Interface()
    {
        shop.initialize();
    };

    void menu();
    void initialize();
    void printProductsAll();

};