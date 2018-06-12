#include "product_chemicals.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>

//sellProduct used to make a purchase
//returns amount to pay
double Chemicals::sellProduct()
{
    int number;
    std::cout << "Ile zakupić sztuk?: " << std::endl;
    std::cin >> number;
    if (number < 0)
    {
        std::cout << "błędne dane" << std::endl;
        return 0;
    }
    else if (number > quantityInShop)
    {
        std::cout << "nie ma tylu produktów" << std::endl;
        return 0;
    }
    quantityInShop -= number;
    return number*price;
}

//resupplying products (increase number of items)
void Chemicals::resupplyProduct()
{
    long int number;
    std::cout << "Ile dodać sztuk?: " << std::endl;
    std::cin >> number;
    if (number < 0)
    {
        std::cout << "błędne dane" << std::endl;
        return;
    }
    quantityInShop = quantityInShop + number;
}

//adding number of random nameP products
void Chemicals::addProductConsoleRandom(int number, std::string nameP)
{
    std::fstream file;
    file.open("data/product_chemicals.txt", std::fstream::app);
    if (!file)
    {
        std::cout << "Problem z otwarciem pliku product_chemicals.txt";
        return;
    }

    for (int i = 0; i < number; i++ )
    {
        file << nameP << std::endl;
        file << std::to_string(70*(rand()%10)) << " ml" << std::endl;
        file << rand() % 500 << std::endl;
        file << 1 + rand() % 10 << std::endl;
        file << 11.1 + (rand() % 10) << std::endl;
    }

    file.close();
}

//Print product's attributes in console
void Chemicals::printProduct(int number, std::string producersName)
{

        std::cout << std::setw(3) << std::left <<  number <<  "                    nazwa: " << name <<
         " " << producersName << std::endl;
        std::cout << "                    objętość: " << package << std::endl;
        std::cout << "                        cena: " << price << " zł" << std::endl;
        std::cout << "                   producent: " << producersName << std::endl;
        std::cout << "   liczba sztuk na magazynie: " << quantityInShop << std::endl;
        std::cout << std::endl << std::endl;
}

//append product to data/product_food.txt
void Chemicals::addProductToFile()
{
        std::fstream file;
    file.open("data/product_chemicals.txt", std::fstream::app);
    if (!file)
    {
        std::cout << "Problem z otwarciem pliku product_chemicals.txt";
        return;
    }

        file << name << std::endl;  //name
        file << package << std::endl; //weight
        file << quantityInShop << std::endl; // quantity in magazine
        file << nip << std::endl; // producer's nip
        file << price << std::endl; // price

    file.close();
}