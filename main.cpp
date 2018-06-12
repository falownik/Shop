#include "interface.hpp"

int main()
{
    Producer prod;
    Shop shop;
    Food food;

    shop.initialize();

    do
    {
        int number;
        std::cout << "Wybierz 0 aby opuścić program" << std::endl;
        std::cout << "Wybierz 1 aby dodać dane firmy" << std::endl;
        std::cout << "Wybierz 2 aby usunąć dane firmy" << std::endl;
        std::cout << "Wybierz 3 aby wypisać listę firm" << std::endl;
        std::cout << "Wybierz 4 aby wypisać chemię" << std::endl;
        std::cout << "Wybierz 5 aby wypisać jedzenie" << std::endl;
        std::cout << "Wybierz 6 aby dodać dane jedzenia" << std::endl;
        std::cout << "Wybierz 8 aby uzupełnić sklep" << std::endl;
        std::cout << "wybierz 9 aby zrobić zakupy" << std::endl;
        std::cin >> number;
        switch (number)
        {
        case 0:
            shop.removeAll();
            shop.save();
            return 0;
        case 1:
            prod.addProducerConsole();
            shop.producer.erase(shop.producer.begin(),shop.producer.end());
            shop.initializeProducers();
            break;
        case 2:
            shop.deleteProducer();
            break;
        case 3:
            shop.printProducers();
            break;
        case 4:
            shop.printProductsChemicals();
            break;
        case 5: 
            shop.printProductsFood();
            break;
        case 6:
            food.addProductConsole();
            shop.food.erase(shop.food.begin(),shop.food.end());
            shop.initializeFood();
            break;
        case 8:
            shop.resupplyProducts();
            shop.removeAll();
            shop.save();

            break;
        case 9:
            shop.doShoping();
            shop.removeAll();
            shop.save();
            break;
        }

    } while (true);
    return 0;
}
