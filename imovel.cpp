#include "imovel.h"

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

std::string imovel::getTipo(){
    
    if(tipo == Casa){
        return "Casa";
    }
    else if(tipo == Apartamento){
        return "Apartamento";
    }
    else{
        return "Terreno";
    }
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

std::string imovel::getEndereco(){
    return endereco;
}

void imovel::setPreco(double preco){
    this->preco = preco;
}

double imovel::getPreco(){
    return preco;
}

