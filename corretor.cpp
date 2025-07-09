#include "corretor.h"

int corretor::nextId = 1;

corretor::corretor(){
    id = nextId++;
}

int corretor::getId(){
    return id;
}

void corretor::setNome(std::string nome){
    this->nome = nome;

}

std::string corretor::getNome(){
    return nome;
}

void corretor::setTel(int tel){
    this->tel = tel;
}

int corretor::getTel(){
    return tel;
}

void corretor::setAvaliador(bool avaliador){
    this->avaliador = avaliador;
}

bool corretor::getAvaliador(){
    return avaliador;
}

void corretor::setLat(double lat){
    this->lat = lat;
}

double corretor::getLat(){
    return lat;
}

void corretor::setLng(double lng){
    this->lng = lng;
}

double corretor::getLng(){
    return lng;
}

void corretor::atribuirImovel(imovel* ptr){
    imoveisAtribuidos.push_back(ptr);
}

std::vector<imovel*>& corretor::getImoveisAtribuidos() {
    return imoveisAtribuidos;
}
