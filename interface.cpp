#include "interface.hpp"


Interface::Interface()
{
    shop.initialize();
}

void Interface::printProductsAll()
{

}

void Interface::menu()
{
    int number;
    do 
    {
    std::cin >> number;
    switch(number)
    {
        case 0:
            std::cout << "Opuszczanie sklepu. Do zobaczenia" << std::endl;
            break;
        case 1:
            this->printProductsAll();
            break;
        case 2:
        break;  

    }

    }while(true);
    
    
}
