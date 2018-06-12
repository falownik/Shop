#include "product_food.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>


double Food::sellProduct()
{
    int number;
    std::cout << "Ile zakupić sztuk?: " << std::endl;
    std::cin >> number;
    quantityInShop -= number;
    return number*price;
}

void Food::resuplyProduct()
{
    int number;
    std::cout << "Ile dodać sztuk?: " << std::endl;
    std::cin >> number;
    quantityInShop += number;
}

void Food::addProductConsoleRandom(int number, std::string nameP)
{
    std::fstream file;
    file.open("data/product_food.txt", std::fstream::app);
    if (!file)
    {
        std::cout << "Problem z otwarciem pliku product_food.txt";
        return;
    }

    for (int i = 0; i < number; i++ )
    {
        file << nameP << std::endl;  //name
        file << std::to_string(70*(rand()%10)) << std::endl; //weight
        file << rand() % 500 << std::endl; // quantity in magazine
        file << 1 + rand() % 10 << std::endl; // producer's nip
        file << 1 + (rand() % 10) << std::endl; // price
        file << rand() % 30 << std::endl; //fat
        file << rand() % 30 << std::endl; // carbohydrates
        file << rand() % 30 << std::endl; // sugar
        file << rand() % 3 << std::endl; //salt
        file << rand() % 30 << std::endl; //protein
    }

    file.close();
}

void Food::printProduct(int number, std::string producersName)
{

        std::cout << std::setw(3) << std::left <<  number <<  "                    nazwa: " << name <<
         " " << producersName << std::endl;
        std::cout << "                        waga: " << weight << " g" << std::endl;
        std::cout << "                        cena: " << price << " zł" << std::endl;
        std::cout << "                   producent: " << producersName << std::endl;
        std::cout << "   liczba sztuk na magazycie: " << quantityInShop << std::endl;
        std::cout << "                     tłuszcz: " << nutrients.fat << std::endl;
        std::cout << "                 węglowodany: " << nutrients.carbohydrates << std::endl;
        std::cout << "                      cukier: " << nutrients.sugar << std::endl;
        std::cout << "                         sól: " << nutrients.salt << std::endl;
        std::cout << "                      białko: " << nutrients.protein << std::endl;
        std::cout << std::endl << std::endl;
}

/*
void Food::addProductConsole()
{
    std::cin.sync();
    std::cout << "Wpisz nazwę jedzenia" << std::endl;
    getline(std::cin,name);
    std::cin.sync();

    std::cin.sync();
    std::cout << "Wpisz zawartość tłuszczu na 100g " << std::endl;
    std::cin >> nutrients.fat;
    std::cin.sync();

    std::cin.sync();
    std::cout << "Wpisz zawartość węglowodanów na 100g " << std::endl;
    std::cin >> nutrients.carbohydrates;
    std::cin.sync();

    std::cin.sync();
    std::cout << "Wpisz zawartość cukru na 100g" << std::endl;
    std::cin >> nutrients.sugar;

    std::cin.sync();
    std::cout << "Wpisz zawartość soli na 100g" << std::endl;
    std::cin >> nutrients.salt;
    std::cin.sync();

    std::cin.sync();
    std::cout << "Wpisz zawartość białka na 100g" << std::endl;
    std::cin >> nutrients.protein;
    std::cin.sync();

    std::cin.sync();
    std::cout << "Opisz opakowanie: (masa/liczba sztuk)" << std::endl;
    getline(std::cin,package);
    std::cin.sync();

    std::cout << "Wpisz cenę za sztukę" << std::endl;
    std::cin >> price;
    std::cin.sync();

    std::cout << "Wpisz liczbę sztuk" << std::endl;
    std::cin >> quantityInShop;
    std::cin.sync();

    std::cout << "Wpisz nip producenta" << std::endl;
    std::cin >> nip;
    std::cin.sync();

    this->addProductToFile();
}*/
