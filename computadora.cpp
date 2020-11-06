#include "computadora.h"

computadora::computadora(){
    RAM=0;
}

computadora::computadora(std::string SO, std::string Nombre, unsigned int RAM, std::string CPU){
    this->SO = SO;
    this->Nommbre = Nombre;
    this->RAM = RAM;
    this->CPU = CPU;
}

void computadora::setSO(std::string &so){
    this->SO = so;
}
void computadora::setNombre(std::string &nom){
    this->Nommbre = nom;
}
void computadora::setRAM(unsigned int ram){
    this->RAM = ram;
}
void computadora::setCPU(std::string &cpu){
    this->CPU = cpu;
}

std::string computadora::getSO(){
    return SO;
}

std::string computadora::getNombre(){
    return Nommbre;
}
unsigned int computadora::getRAM(){
    return RAM;
}

std::string computadora::getCPU(){
    return CPU;
}