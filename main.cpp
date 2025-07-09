#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "roundrobin.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
 
int main(){
    std::vector<corretor> corretores;
    std::vector<cliente> clientes;
    std::vector<imovel> imoveis;
    std::vector<corretor> avaliadores;

    int n;

    //Corretores 
    std::cin >> n;
    std::cin.ignore(); // descarta o /n e permite ir para a próxima linha
    for (int i = 0; i < n; i++){
        std::string linha; // declaração de varíavel do tipo string para armazenar a linha de informações
        std::getline(std::cin, linha); // armazenando a linha de informações como uma única string na varíavel linha,  que é do tipo string.
        std::istringstream iss(linha); // carregando a string como um fluxo de entrada (cin)

        int tel;
        bool avaliador;
        double lat, lng;
        std::string nome;

        iss >> tel >> avaliador >> lat >> lng; // quebra a linha em pedaços de acordo com os espaços e armazena nas respectivas variáveis
        std::getline(iss >> std::ws, nome); // armazena o restante da string na varíavel nome
        
        // cria objeto do tipo corretor, faz o armazenamento dos atributos através dos métodos set e adiciona o objeto à coleção
        corretor corretor; 
        corretor.setTel(tel);
        corretor.setAvaliador(avaliador);
        corretor.setLat(lat);
        corretor.setLng(lng);
        corretor.setNome(nome);
        corretores.push_back(corretor);

        if(avaliador){
            avaliadores.push_back(corretor);
        }
    }

    //Clientes
    std::cin >> n;
    std::cin.ignore(); // descarta o /n e permite ir para a próxima linha
    for (int i = 0; i < n; i++){
        std::string linha; // declaração de variável do tipo string para armazenar a linha de informações
        std::getline(std::cin, linha); // armazenando a linha de informações como uma única string na varíavel linha,  que é do tipo string.
        std::istringstream iss(linha); // carregando a string como um fluxo de entrada (cin)

        int tel;
        std::string nome;

        iss >> tel; // quebra a linha em pedaços de acordo com os espaços e armazena nas respectivas variáveis
        std::getline(iss >> std::ws, nome); // armazena o restante da string na varíavel nome

        //cria objeto do tipo cliente, faz o armazenamento dos atributos através dos métodos set e adiciona o objeto à coleção
        cliente cliente;
        cliente.setTel(tel);
        cliente.setNome(nome);
        clientes.push_back(cliente);
    }

    //Imóveis
    std::cin >> n;
    std::cin.ignore(); // descarta o /n e permite ir para a próxima linha
    for (int i = 0; i < n; i++) {
        std::string linha; // declaração de variável do tipo string para armazenar a linha de informações
        std::getline(std::cin, linha); // armazenando a linha de informações como uma única string na varíavel linha,  que é do tipo string.
        std::istringstream iss(linha); // carregando a string como um fluxo de entrada (cin)

        imovel::TipoImovel tipo;
        std::string tipo_tmp;
        int proprietarioId;
        double lat, lng, preco;
        std::string endereco;


        iss >> tipo_tmp >> proprietarioId >> lat >> lng >> preco; // quebra a linha em pedaços de acordo com os espaços e armazena nas respectivas variáveis
        std::getline(iss >> std::ws, endereco); // armazena o restante da string na varíavel endereco

        // conversão de todas os caracteres da string "tipo_tmp" para minúsculas
        std::transform(tipo_tmp.begin(), tipo_tmp.end(), tipo_tmp.begin(), ::tolower);


        // definição da varíavel "tipo", do tipo enum, de acordo com a "tipo_tmp", do tipo string
        if(tipo_tmp == "casa"){
            tipo = imovel::Casa;
        }
        else if(tipo_tmp == "apartamento"){
            tipo = imovel::Apartamento;
        }
        else if(tipo_tmp == "terreno"){
            tipo = imovel::Terreno;
        }
        else{
            std::cout << "Tipo de Imovel Invalido!" << std::endl;
        }

        //cria objeto do tipo imovel, faz o armazenamento dos atributos através dos métodos set e adiciona o objeto à coleção
        imovel imovel;
        imovel.setTipo(tipo);
        imovel.setProprietarioId(proprietarioId);
        imovel.setLat(lat);
        imovel.setLng(lng);
        imovel.setPreco(preco);
        imovel.setEndereco(endereco);
        imoveis.push_back(imovel);
    }

    std::cout << corretores.size() << std::endl;
    for(size_t ii = 0; ii < corretores.size(); ii++){
        std::cout << corretores[ii].getId() << " " << corretores[ii].getTel() << " " << corretores[ii].getAvaliador() << " " << corretores[ii].getLat() << " " << corretores[ii].getLng() << " " << corretores[ii].getNome() << std::endl;
    }

    std::cout << std::endl;

    std::cout << clientes.size() << std::endl;
    for(size_t ii = 0; ii < clientes.size(); ii++){
        std::cout << clientes[ii].getId() << " " << clientes[ii].getTel() << " " << clientes[ii].getNome() << std::endl;
    }

    std::cout << std::endl;

    std::cout << imoveis.size() << std::endl;
    for(size_t ii = 0; ii < imoveis.size(); ii++){
        std::cout << imoveis[ii].getId() << " " << imoveis[ii].getTipo() << " " << imoveis[ii].getProprietarioId() << " " << imoveis[ii].getLat() << " " << imoveis[ii].getLng() << " " << imoveis[ii].getPreco() << " " << imoveis[ii].getEndereco() << std::endl;
    }

    std::cout << std::endl;

    round_robin(avaliadores, imoveis); //chama de função para realizar o round_robin.

    for (size_t i = 0; i < avaliadores.size(); i++){
        std::cout << "Corretor ID " << avaliadores[i].getId() << " recebeu os imóveis: ";

        std::vector<imovel*>& lista = avaliadores[i].getImoveisAtribuidos();

        for (size_t j = 0; j < lista.size(); j++) {
            std::cout << lista[j]->getId() << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    system("pause");

    return 0;
 }
