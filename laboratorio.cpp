#include "laboratorio.h"
#include <algorithm>
laboratorio::laboratorio(){
}
void laboratorio::agregarCP(const computadora &cp){
    Lab.push_back(cp);    
}
    
void laboratorio::mostrar(){
    std::cout << std::left;
    std::cout << std::setw(19) << "Sistema Operativo";
    std::cout << std::setw(16) << "Nombre Equipo";
    std::cout << std::setw(6) << "RAM";
    std::cout << std::setw(15) << "CPU";
    std::cout << std::endl;
    for (int  i = 0; i < Lab.size(); i++)
    {
        computadora &pc = Lab[i];
        std::cout << pc;
        std::cout << std::endl;
    }
}
void laboratorio::respaldar_tabla(){
    std::ofstream archivo("Respaldo_PC");
    if (archivo.is_open())
    {
        archivo << std::left;
        archivo << std::setw(19) << "Sistema Operativo";
        archivo << std::setw(16) << "Nombre Equipo";
        archivo << std::setw(6) << "RAM";
        archivo << std::setw(15) << "CPU";
        archivo << std::endl;
        for (int  i = 0; i < Lab.size(); i++)
        {
            computadora &pc = Lab[i];
            archivo << pc;
        }
    }
    archivo.close();    
}
void laboratorio::respaldar(){
    std::ofstream archivo("Backup_PC");
    if (archivo.is_open())
    {
        for (int i = 0; i < Lab.size(); i++)
        {
            computadora &pc = Lab[i];
            archivo << pc.getSO() << std::endl;
            archivo << pc.getNombre() << std::endl;
            archivo << pc.getRAM() << std::endl;
            archivo << pc.getCPU() << std::endl;
        }
        
    }
    archivo.close();
}
void laboratorio::recuperar(){
    std::ifstream archivo("Backup_PC");
    if (archivo.is_open())
    {
        std::string temp;
        int ramus;
        computadora pc;
        while (!archivo.eof())
        {
            std::getline(archivo, temp);
            if (archivo.eof())
            {
                break;
            }
            
            pc.setSO(temp);

            std::getline(archivo, temp);
            pc.setNombre(temp);

            std::getline(archivo, temp);
            ramus = std::stoi(temp);
            pc.setRAM(ramus);
            
            std::getline(archivo, temp);
            pc.setCPU(temp);
            agregarCP(pc);
        }
        
    }
    archivo.close();
}

void laboratorio::insertar(const computadora &cp, size_t pos){
    Lab.insert(Lab.begin()+pos, cp);
}

void laboratorio::inicializar(const computadora &cp, size_t n){
    Lab = std::vector<computadora>(n, cp);
}

void laboratorio::eliminar(size_t pos){
    Lab.erase(Lab.begin()+pos);
}
void laboratorio::ordenar(){
    std::sort(Lab.begin(), Lab.end());
}
computadora* laboratorio::buscar(const computadora &p){
    auto it = std::find(Lab.begin(), Lab.end(), p);
    if( it == Lab.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}