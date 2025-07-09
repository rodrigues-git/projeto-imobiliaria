#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

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


#endif