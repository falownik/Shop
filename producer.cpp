#include "interface.hpp"
#include <fstream>


void Producer::addProducerToFile()
{
      std::ofstream file;
    
    file.open("data/producers.txt", std::fstream::app);

    if (!file)
    {
        std::cout << "Problem z otwarciem pliku producentów" << std::endl;
        return;
    }
    
    file << std::endl << name << std::endl;
    file << adress << std::endl;
    file << telephone << std::endl;
    file << mail << std::endl;
    file << nip;

    file.close();

}

void Producer::addProducerConsole()
{

    std::cin.sync();
    std::cout << "Wpisz nazwę firmy" << std::endl;
    getline(std::cin,name);
    std::cin.sync();

    std::cout << "Wpisz adres firmy" << std::endl;
    getline(std::cin,adress);
    std::cin.sync();

    std::cout << "Wpisz telefon kontaktowy firmy" << std::endl;
    getline(std::cin,telephone);
    std::cin.sync();

    std::cout << "Wpisz adres email firmy" << std::endl;
    getline(std::cin,mail);
    std::cin.sync();

    std::cout << "Wpisz NIP firmy" << std::endl;
    std::cin >> nip ;
    std::cin.sync();

    this->addProducerToFile();
    
}