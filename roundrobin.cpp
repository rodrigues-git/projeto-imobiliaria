#include "roundrobin.h"

// função que realiza round_robin através de uma ed vetor circular
void round_robin(std::vector<corretor>& avaliadores, std::vector<imovel>& imoveis){
    int indice;
    int num_avaliadores = avaliadores.size();
    imovel* ptr;

    for(size_t ii = 0; ii < imoveis.size(); ii++){
        ptr = &imoveis[ii];
        indice = ii % num_avaliadores;
        avaliadores[indice].atribuirImovel(ptr);
    }
    

}



