#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
   std::string _firstname;
   std::string _lastname;
   std::string _nickname;
   std::string _phonenumber;
   std::string _darkestsecret;
public:
    Contact();
    ~Contact();
    std::string getFirstname();
    std::string getLastname();
    std::string getNickname();
    std::string getPhonenumber();
    std::string getDarkestsecret();

    void setFirstname(std::string firstname);
    void setLastname(std::string lastname);
    void setNickname(std::string nickname);
    void setPhonenumber(std::string phonenumber);
    void setDarkestsecret(std::string darkestsecret);
};

#endif