#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include <iostream>
#include <iomanip>

class computadora{
    private:
    std::string SO;
    std::string Nommbre;
    unsigned int RAM;
    std::string CPU;
    public:
    computadora();
    computadora(std::string, std::string, unsigned int, std::string);
    void setSO(std::string &so);
    void setNombre(std::string &nom);
    void setRAM(unsigned int ram);
    void setCPU(std::string &cpu);

    std::string getSO();
    std::string getNombre();
    unsigned int getRAM();
    std::string getCPU();

    friend std::ostream& operator<<(std::ostream &out, const computadora &c){
        out << std::left;
        out << std::setw(19) << c.SO;
        out << std::setw(16) << c.Nommbre;
        out << std::setw(6) << c.RAM;
        out << std::setw(15) << c.CPU;
        out << std::endl;
        return out;
    } 

    friend std::istream& operator>>(std::istream &in, computadora &pc){
        std::cout << "Sistema Operativo: ";
        std::getline(std::cin, pc.SO);
        std::cout << "Nombre equipo: ";
        std::getline(std::cin, pc.Nommbre);
        std::cout << "RAM: ";
        std::cin >> pc.RAM;
        std::fflush(stdin);
        std::cout << "CPU: ";
        std::getline(std::cin, pc.CPU);
        return in;
    }
    bool operator== (const computadora& p){
        return SO == p.SO ;  
        }

    bool operator== (const computadora& p) const{
    return SO == p.SO ;  
    }
    bool operator< (const computadora& p){
        return Nommbre < p.Nommbre;
    }
    bool operator< (const computadora& p)const{
        return Nommbre < p.Nommbre;
    }
};


#endif
