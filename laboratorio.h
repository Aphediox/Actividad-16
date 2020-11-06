#ifndef LABORATORIO_H
#define LABORATORIO_H
#include "computadora.h"
#include <fstream>
#include <vector>

class laboratorio:public computadora{
    private:
        std::vector<computadora> Lab;

    public:
    laboratorio();
    void agregarCP(const computadora &cp);
    void mostrar();
    friend laboratorio& operator<<(laboratorio &lab, const computadora &pc){
        lab.agregarCP(pc);
        return lab;
    }
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const computadora &cp, size_t pos);
    size_t size(){ return Lab.size();}
    void inicializar(const computadora &cp, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    computadora* buscar(const computadora &p);
};

#endif