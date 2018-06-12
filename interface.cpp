#include "interface.hpp"
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <algorithm>


//method returning name of producer with given nip number
std::string Shop::getProducersName(long long nip)
{
    for (auto i = 0; i < producer.size(); i++)
        if (nip == producer[i].nip)
            return producer[i].name;
    return "nie znaleziono";
}

//Prints all products of class Chemicals in console
void Shop::printProductsChemicals()
{
    //std::cout << chemicals.size();
    for (auto i = 1; i <= chemicals.size(); i++)
    {
        chemicals[i - 1].printProduct(i, this->getProducersName(chemicals[i - 1].nip));
    }
}

//Prints all products of class Food in console
void Shop::printProductsFood()
{
    //std::cout << chemicals.size();
    for (auto i = 1; i <= food.size(); i++)
    {
        food[i - 1].printProduct(i, this->getProducersName(food[i - 1].nip));
    }
}

//Copy producers from data/producers.txt to vector<>
void Shop::initializeProducers()
{
        std::fstream file;

    file.open("data/producers.txt");

    if (!file)
    {
        std::cout << "Problem z otwarciem pliku producentów" << std::endl;
        return;
    }

    while (!file.eof())
    {
        Producer prod;
        std::string buff;

        getline(file, prod.name);
        if (!(prod.name).compare(""))
            return;

        getline(file, prod.adress);
        getline(file, prod.telephone);
        getline(file, prod.mail);
        getline(file, buff);
        prod.nip = std::stoll(buff);

        producer.push_back(prod);
    }

    file.close();
}

//Copy chemicals from data/Chemicals.txt to vector<>
void Shop::initializeChemicals()
{
    std::fstream file;

    file.open("data/product_chemicals.txt");

    if (!file)
    {
        std::cout << "Problem z otwarciem pliku chemii" << std::endl;
        return;
    }

    while (!file.eof())
    {

        Chemicals chem;
        std::string buff;

        getline(file, chem.name);
        if (!(chem.name).compare(""))
            break;

        getline(file, chem.package);

        getline(file, buff);
        chem.quantityInShop = std::stol(buff);

        getline(file, buff);
        chem.nip = std::stoll(buff);

        getline(file, buff);
        chem.price = std::stod(buff);

        chemicals.push_back(chem);
    }

    file.close();
}

//Copy Food from data/food.txt to vector<>
void Shop::initializeFood()
{
        std::fstream file;

    file.open("data/product_food.txt");

    if (!file)
    {
        std::cout << "Problem z otwarciem pliku jedzenia" << std::endl;
        return;
    }

    while (!file.eof())
    {

        Food foo;
        std::string buff;

        getline(file, foo.name);
        if (!(foo.name).compare(""))
            return;

        getline(file, buff);
        foo.weight = std::stoi(buff);

        getline(file, buff);
        foo.quantityInShop = std::stol(buff);

        getline(file, buff);
        foo.nip = std::stoll(buff);

        getline(file, buff);
        foo.price = std::stod(buff);

        getline(file, buff);
        foo.nutrients.fat = std::stod(buff);

        getline(file, buff);
        foo.nutrients.carbohydrates = std::stod(buff);

        getline(file, buff);
        foo.nutrients.sugar = std::stod(buff);

        getline(file, buff);
        foo.nutrients.salt = std::stod(buff);

        getline(file, buff);
        foo.nutrients.protein = std::stod(buff);

        food.push_back(foo);

    }

    file.close();
}

//Copy database to vectors<>
void Shop::initialize()
{
    this->initializeProducers();
    this->initializeChemicals();
    this->initializeFood();
}

//Method reinitializes producers from file and prints attributes
void Shop::printProducers()
{
    producer.erase(producer.begin(), producer.end());
    this->initializeProducers();
    for (int i = 1; i <= producer.size(); i++)
    {
        std::cout << std::setw(3) << std::left << i << "      nazwa: " << producer[i - 1].name << std::endl;
        std::cout << "         adres: " << producer[i - 1].adress << std::endl;
        std::cout << "   nr telefonu: " << producer[i - 1].telephone << std::endl;
        std::cout << "         email: " << producer[i - 1].mail << std::endl;
        std::cout << "           NIP: " << producer[i - 1].nip << std::endl;
        std::cout << std::endl
                  << std::endl;
    }
}

//Copy producers to file data/producers.txt
void Shop::saveAllToFile()
{
    for (auto i = 0; i < producer.size(); i++)
        producer[i].addProducerToFile();
}

//Deletes choosen producer from vector<> and reinitializes data/producers.txt
void Shop::deleteProducer()
{
    std::cout << "Wybierz firme do usunięcia, jeżeli nie chcesz usuwać wybierz 0" << std::endl;
    this->printProducers();
    int number;
    std::cin >> number;
    if (number == 0)
        return;
    else if (number > 0 && number < producer.size())
    {
        producer.erase(producer.begin() + number - 1);
        producer.pop_back();
    }
    else
    {
        std::cout << "Podany numer firmy nie istnieje" << std::endl;
        return;
    }

    remove("data/producers.txt");
    this->saveAllToFile();
}

void Shop::sortChemicalsByPriceRising()
{
    std::sort(chemicals.begin(), chemicals.end(), [](Chemicals a, Chemicals b) { return a.price < b.price; });
}

void Shop::sortChemicalsByPriceDecreasing()
{
    std::sort(chemicals.begin(), chemicals.end(), [](Chemicals a, Chemicals b) { return a.price > b.price; });
}

void Shop::sortFoodByPriceRising()
{
    std::sort(food.begin(), food.end(), [](Food a, Food b) { return a.price < b.price; });
}

void Shop::sortFoodByPriceDecreasing()
{
    std::sort(food.begin(), food.end(), [](Food a, Food b) { return a.price > b.price; });
}


void Shop::doShopping()
{
    double bill = 0;
    int number;
    int choose;
    std::vector<Cart> cart;
    Cart car;
    double temp_bill = 0;
    do
    {
        long int quantity;
        std::cout << "Wybierz 0 aby powrócić do menu" << std::endl;
        std::cout << "Wybierz 1 aby zakupić chemię" << std::endl;
        std::cout << "Wybierz 2 aby zakupić jedzenie" << std::endl;
        std::cout << "jeżeli chcesz zobaczyć zawartośc koszyka wybierz 3" << std::endl;
        std::cin >> number;
        switch (number)
        {
        case 0:
            break;
        case 1:
            do
            {
                std::cout << "Wybierz 0 aby powrócić do menu" << std::endl;
                std::cout << "jeżeli chcesz posortować rosnąco wybierz 1" << std::endl;
                std::cout << "jeżeli chcesz posortować malejąco wybierz 2" << std::endl;
                std::cout << "jeżeli chcesz rozpocząć zakupy wybierz 3" << std::endl;
                std::cout << "jeżeli chcesz zakoczyć i zapłacić wybierz 4" << std::endl;
                std::cout << "______________________________________" << std::endl;
                std::cout << "wybrano produkty za: " << bill << " zł" << std::endl;
                std::cin >> choose;
                switch (choose)
                {
                case 0:
                    return;
                case 1:
                    this->sortChemicalsByPriceRising();
                    this->printProductsChemicals();
                    break;
                case 2:
                    this->sortChemicalsByPriceDecreasing();
                    this->printProductsChemicals();
                    break;
                case 3:
                    do
                    {
                        this->printProductsChemicals();
                        std::cout << "wybierz produkt: ";
                        std::cin >> choose;
                        if (choose == 0)
                            break;
                        //selling product and adding it to cart
                        //adding to cart copies name of product
                        //number of sold products and price
                        temp_bill = chemicals[choose - 1].sellProduct();
                        car.item = temp_bill/chemicals[choose - 1].price;
                        car.name = chemicals[choose - 1].name + " " + this->getProducersName(chemicals[choose - 1].nip);
                        car.price = temp_bill;
                        cart.push_back(car);
                        bill += temp_bill;
                        //print state of transaction
                        std::cout << "______________________________________" << std::endl;
                        std::cout << "wybrano produkty za: " << bill << " zł" << std::endl;
                    } while (choose != 0);
                    break;
                }
            } while (choose != 0);
            break;

        case 2:
            do
            {
                std::cout << "Wybierz 0 aby zakoczyć zakupy i wrócić do menu" << std::endl;
                std::cout << "jeżeli chcesz posortować rosnąco wybierz 1" << std::endl;
                std::cout << "jeżeli chcesz posortować malejąco wybierz 2" << std::endl;
                std::cout << "jeżeli chcesz rozpocząć zakupy wybierz 3" << std::endl;
                std::cout << "jeżeli chcesz zakoczyć i zapłacić wybierz 4" << std::endl;
                std::cout << "______________________________________" << std::endl;
                std::cout << "wybrano produkty za: " << bill << " zł" << std::endl;
                std::cin >> choose;
                switch (choose)
                {
                case 0:
                    return;
                case 1:
                    this->sortFoodByPriceRising();
                    this->printProductsFood();
                    break;
                case 2:
                    this->sortFoodByPriceDecreasing();
                    this->printProductsFood();
                    break;
                case 3:
                    do
                    {
                        this->printProductsFood();
                        std::cout << "wybierz produkt: ";
                        std::cin >> choose;
                        if (choose == 0)
                            break;
                        //selling product and adding it to cart
                        //adding to cart copies name of product
                        //number of sold products and price
                        temp_bill = food[choose - 1].sellProduct();
                        car.item = temp_bill/food[choose - 1].price;
                        car.name = food[choose - 1].name + " " + this->getProducersName(food[choose - 1].nip);
                        car.price = temp_bill;
                        cart.push_back(car);
                        bill += temp_bill;
                        //print state of transaction
                        std::cout << "______________________________________" << std::endl;
                        std::cout << "wybrano produkty za: " << bill << " zł" << std::endl;
                    } while (choose != 0);
                    break;
                }
            } while (choose != 0);
            break;
            case 3:
            //print content of cart
            std::cout << std::endl << "zawartość koszyka" << std::endl << std::endl;
            for (auto a : cart) std::cout << "nazwa: "<< a.name << std::endl <<
            "liczba sztuk: " << a.item << std:: endl <<
             "koszt: " << a.price << " zł " << std::endl << std::endl ;
             std::cout << "całkowity koszt: " << bill << " zł" <<  std::endl << std::endl;

            break;
        }
    } while (number != 0);
    //reinitialize database after transaction
    chemicals.erase(chemicals.begin(), chemicals.end());
    producer.erase(producer.begin(), producer.end());
    food.erase(food.begin(),food.end());
    this->initialize();
}


//
void Shop::resupplyProducts()
{
    int number;
    int choose;
    do
    {
    std::cout << "Wybierz 0 aby wrócić do menu" << std::endl;
    std::cout << "Wybierz 1 aby uzupełnić jedzenie" << std::endl;
    std::cout << "Wybierz 2 aby uzupełnić chemię" << std::endl;
    std::cin >> number;

    switch(number)
    {
        case 0:
            ;
            return;
        case 1:
            this->printProductsFood();
            std::cout << " Wybierz który produkt uzupełnić" << std::endl;
            std::cin >> choose;
            if (choose == 0) //leave
                break;
            else if (choose > food.size())//check if doesn't overflow umber of products
            {
                std::cout << "nie ma takiego produktu";
                break;
            }
            food[choose - 1].resupplyProduct();
            break;
        case 2:
            this->printProductsChemicals();
            std::cout << " Wybierz który produkt uzupełnić" << std::endl;
            std::cin >> choose;
            if (choose == 0)//leave
                break;
            else if (choose > chemicals.size())//check if doesn't overflow umber of products
            {
                std::cout << "nie ma takiego produktu";
                break;
            }
            chemicals[choose - 1].resupplyProduct();
            break;

    }
    }while(number != 0);



}

//remove all files before reinitialization
void Shop::removeAll()
{
    remove("data/producers.txt");
    remove("data/product_chemicals.txt");
    remove("data/product_food.txt");
}

//save all vectors<> to database
void Shop::save()
{
    for (auto obj : producer) obj.addProducerToFile();
    for (auto obj : food) obj.addProductToFile();
    for (auto obj : chemicals) obj.addProductToFile();
        
}