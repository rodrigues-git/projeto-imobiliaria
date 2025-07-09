#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

class imovel{
    public:
        enum TipoImovel { Casa, Apartamento, Terreno };

    private:
        TipoImovel tipo;
        static int nextId;
        int id;
        int proprietarioId;
        double lat;
        double lng;
        std::string endereco;
        double preco;

    public:
        imovel();

        void setTipo(TipoImovel tipo);
        std::string getTipo();

        int getId();
        
        void setProprietarioId(int proprietarioId);
        int getProprietarioId();

        void setLat(double lat);
        double getLat();

        void setLng(double lng);
        double getLng();

        void setEndereco(std::string endereco);
        std::string getEndereco();

        void setPreco(double preco);
        double getPreco();

};

#endif