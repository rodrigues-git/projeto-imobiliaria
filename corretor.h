#ifndef CORRETOR_H
#define CORRETOR_H

#include "imovel.h"
#include <string>
#include <vector>

class corretor{

    private:
        static int nextId;
        int id;
        std::string nome;
        int tel;
        bool avaliador;
        double lat;
        double lng;
        std::vector <imovel*> imoveisAtribuidos;


    public:
        corretor();

        int getId();

        void setNome(std::string nome);
        std::string getNome();

        void setTel(int tel);
        int getTel();

        void setAvaliador(bool avaliador);
        bool getAvaliador();

        void setLat(double lat);
        double getLat();

        void setLng(double lng);
        double getLng();

        void atribuirImovel(imovel* ptr);

        std::vector<imovel*>& getImoveisAtribuidos();

};

#endif