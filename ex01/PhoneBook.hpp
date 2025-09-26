#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
    Contact _contact[8];
    int _totalContact;
    int _currentIndex;

    void _printcolumn(const std::string &str);
    void _viewcontactlist();
    void _viewcontact(int index);
    std::string _getInput(const std::string &prompt);
    bool _isValidIndex(const std::string &input, int &index);
public:
    PhoneBook();
    ~PhoneBook();

    void addcontact();
    void searchcontact();
    void run();

};



#endif