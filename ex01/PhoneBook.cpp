#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(): _totalContact(0),_currentIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}
void PhoneBook::_printcolumn(const std::string &str)
{
    if (str.length() > 10)
    {
        std::cout<< std::setw(10) << str.substr(0 , 9) + ".";
    }
    else{
        std::cout<< std::setw(10) <<str;
    }
}
void PhoneBook::_viewcontactlist()
{
    std::cout<< std::setw(10) <<std::right << "Index" << "|";
    std::cout<< std::setw(10) <<std::right << "Firstname" << "|";
    std::cout<< std::setw(10) <<std::right << "Lastname" << "|";
    std::cout<< std::setw(10) <<std::right << "Nickname" <<std::endl;

    for (int i = 0; i < _totalContact; i++)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        _printcolumn(_contact[i].getFirstname()); std::cout << "|";
        _printcolumn(_contact[i].getLastname());  std::cout << "|";
        _printcolumn(_contact[i].getNickname());  std::cout << "|";
        std::cout << std::endl;
    }
}
bool PhoneBook::_isValidIndex(const std::string &input, int &index)
{
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
		return false;
	
	index = input[0] - '0';
	return (index < _totalContact);
}
void PhoneBook::_viewcontact(int index)
{
    std::cout<< "Firstname: " << _contact[index].getFirstname() <<std:: endl;
    std::cout<< "Lastname: " << _contact[index].getLastname() <<std::endl;
    std::cout<< "Nickname: " << _contact[index].getNickname() <<std::endl;
    std::cout<< "Phonenumber: " << _contact[index].getPhonenumber() <<std::endl;
    std::cout<< "Darkestsecret: " << _contact[index].getDarkestsecret() <<std::endl;
}
std::string PhoneBook::_getInput(const std::string &prompt)
{
    std::string input;

    while(true)
    {
        std::cout<< prompt;
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout<<"Error: failed cannot be empty.Try again."<<std::endl;
        }else{
            return input;
        }
    }
}
void PhoneBook::addcontact() 
{
    _contact[_currentIndex].setFirstname(_getInput("Enter first name: "));
    _contact[_currentIndex].setLastname(_getInput("Enter last name: "));
    _contact[_currentIndex].setNickname(_getInput("Enter nickname: "));
    _contact[_currentIndex].setPhonenumber(_getInput("Enter phone number: "));
    _contact[_currentIndex].setDarkestsecret(_getInput("Enter darkest secret: "));

    _currentIndex = (_currentIndex + 1) % 8;

    if (_totalContact < 8)
        _totalContact++;
    std::cout << "Contact added successfully ✅" << std::endl;
}
void PhoneBook::searchcontact()
{
    if (_totalContact == 0)
    {
        std::cout << "PhoneBook is empty"<< std::endl;
    }
    _viewcontactlist();

    std::string input;
    int index;
    std::cout << "Enter the index contact to view: ";
    std::getline(std::cin, input);

    if (_isValidIndex(input, index))
        _viewcontact(index);
    else
        std::cout << "Error: invalid index" <<std::endl;

}
void PhoneBook::run()
{
    std::string command;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

    while(true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);

        if (command == "ADD")
            addcontact();
        else if(command == "SEARCH")
            searchcontact();
        else if(command == "EXIT")
        {
            std::cout << "Au revoir!" <<std::endl;
            break;
        }
        else if (!command.empty())
			std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
    }
}