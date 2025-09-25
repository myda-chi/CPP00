#include "Contact.hpp"
#include <iostream>


Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstname(std::string firstname)
{
    this->_firstname = firstname;
}
void Contact::setLastname(std::string lastname)
{
    this->_lastname = lastname;
}
void Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}
void Contact::setPhonenumber(std::string phonenumber)
{
    this->_phonenumber = phonenumber;
}
void Contact::setDarkestsecret(std::string darkestsecret)
{
    this->_darkestsecret = darkestsecret;
}

std::string Contact::getFirstname()
{
    return _firstname;
}
std::string Contact::getLastname()
{
    return _lastname;
}
std::string Contact::getNickname()
{
    return _nickname;
}
std::string Contact::getPhonenumber()
{
    return _phonenumber;
}
std::string Contact::getDarkestsecret()
{
    return _darkestsecret;
}