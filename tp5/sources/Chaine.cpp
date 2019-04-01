#include "Chaine.h"

#include <fstream>
#include <iostream>

Chaine::Chaine(string nom, string codePostal, string address):name_(nom),codePostal_(codePostal), address_(address)
{}

void Chaine::setName(string nom)
{
    name_ = nom;
}

void Chaine::setAddress(string address)
{
    address_ = address;
}

void Chaine::setCodePostal(string codePostal)
{
    codePostal_ = codePostal;
}

string Chaine::getName() const{
    return name_;
}

string Chaine::getCodePostal() const {
    return codePostal_;
}

string Chaine::getAddress() const 
{
    return address_;
}