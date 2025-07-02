#ifndef IMOBILIARIA_H
#define IMOBILIARIA_H

#include <string>

class corretor{

    private:
        static int nextId;
        int id;
        std::string nome;
        int tel;
        bool avaliador;
        double lat;
        double lng;

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

};

class cliente{
    private:
        static int nextId;
        int id;
        std::string nome;
        int tel;

    public:
        cliente();

        int getId();

        void setNome(std::string nome);
        std::string getNome();

        void setTel(int tel);
        int getTel();
};

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
        TipoImovel getTipo();

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
