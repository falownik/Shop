#include "producer.hpp"
#include <fstream>

Producer Producer::initialize()
{
    std::fstream file;

    file.open("data/producers.txt");

    if (!file)
    {
        std::cout << "Problem z otwarciem pliku producentów" << std::endl;
        Producer producer;
        return producer;
    }

    while (!file.eof())
    {
        Producer producer;
        
        file << producer.id;
        getline (file, producer.name);
        getline (file, producer.adress);
        getline (file, producer.telephone);
        getline (file, producer.mail);

        return producer;
    }

    file.close();

}

void Producer::addProducerConsole()
{
    std::ifstream file;
    
    file.open("data/producers.txt");

    if (!file)
    {
        std::cout << "Problem z otwarciem pliku producentów" << std::endl;
        return;
    }
    std::cout << "Wpisz nazwę firmy" << std::endl;
    std::cin >> name;
    std::cout << "Wpisz adres firmy" << std::endl;
    std::cin >> adress;
    std::cout << "Wpisz telefon kontaktowy firmy" << std::endl;
    std::cin >> telephone;
    std::cout << "Wpisz adres email firmy" << std::endl;
    std::cin >> mail;
    file >> name;
    file >> adress;
    file >>telephone;
    file >> mail;

    file.close();
    
}