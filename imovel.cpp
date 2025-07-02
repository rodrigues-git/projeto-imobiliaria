#include "header.h"

int imovel::nextId = 1;

imovel::imovel(){
    id = nextId++;
}

int imovel::getId(){
    return id;
}

void imovel::setTipo(TipoImovel tipo){
    this->tipo = tipo;
}

imovel::TipoImovel imovel::getTipo(){
    return tipo;
}

void imovel::setProprietarioId(int proprietarioId){
    this->proprietarioId = proprietarioId;
}

int imovel::getProprietarioId(){
    return proprietarioId;
}

void imovel::setLat(double lat){
    this->lat = lat;
}

double imovel::getLat(){
    return lat;
}

void imovel::setLng(double lng){
    this->lng = lng;
}

double imovel::getLng(){
    return lng;
}

void imovel::setEndereco(std::string endereco){
    this->endereco = endereco;
}

void imovel::setPreco(double preco){
    this->preco = preco;
}

double imovel::getPreco(){
    return preco;
}

