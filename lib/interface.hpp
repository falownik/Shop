#include "shop.hpp"
#include "product_chemicals.hpp"
#include "product_food.hpp"



class Shop
{
    public:
    void initialize(); // load all products from database
    void initializeProducers();
    void initializeChemicals();
    void initializeFood();
    void save();
    void removeAll();
    void deleteProducer();
    void printProducers(); // print all producers
    void printProductsChemicals(); // print products of class Chemicals
    void printProductsFood(); // print products of class Food
    void saveAllToFile();
    void doShoping(); // shop's operations
    void sortChemicalsByPriceRising();       // 
    void sortChemicalsByPriceDecreasing();   //* sorting
    void sortFoodByPriceRising();            //
    void sortFoodByPriceDecreasing();        //
    void resupplyProducts();
    std::string getProducersName(long long int ); //auxiliary class to conenct nip from product with producer
    std::vector <Product> product;
    std::vector <Chemicals> chemicals;
    std::vector <Food> food;
    std::vector <Producer> producer;
};
