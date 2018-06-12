#include "interface.hpp"
#include <new>


int main()
{
    Producer prod;
    Shop shop;
    Chemicals chem;
    Food food;
    //food.addProductConsoleRandom(5, "guma");
    //chem.addProductConsoleRandom(5,"pasta do butów");

    shop.initialize();
    shop.printProductsFood();
    //shop.sortByPrice();
    //shop.printProductsAll();

    do
    {
        int number;
        std::cout << "Wybierz 0 aby opuścić program" << std::endl;
        std::cout << "Wybierz 1 aby dodać dane firmy" << std::endl;
        std::cout << "Wybierz 2 aby usunąć dane firmy" << std::endl;
        std::cout << "Wybierz 3 aby wypisać listę firm" << std::endl;
        std::cout << "Wybierz 4 aby dodać rodzaj produktu" << std::endl;
        std::cout << "Wybierz 5 aby usunąć klasę produktu" << std::endl;
        std::cout << "wybierz 9 aby zrobić zakupy" << std::endl;
        std::cin >> number;
        switch(number)
        {
            case 0:
                return 0;
            case 1:
                prod.addProducerConsole();
                break;
            case 2:
                shop.deleteProducer();
                break;
            case 3:
                shop.printProducers();
                break;
            case 4:
                shop.deleteFile();
                break;
            case 9:
                shop.doShoping();
                break;
            
        }
        std::cout << shop.producer.size();

    }while(true);
    return 0;
}

