#include "cliente.h"

int cliente::nextId = 1;

cliente::cliente(){
    id = nextId++;
}

int cliente::getId(){
    return id;
}

void cliente::setNome(std::string nome){
    this->nome = nome;
}

std::string cliente::getNome(){
    return nome;
}

void cliente::setTel(int tel){
    this->tel = tel;
}

int cliente::getTel(){
    return tel;
}