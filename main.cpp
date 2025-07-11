#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "roundrobin.h"
#include "agendamentos.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
 
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

    round_robin(avaliadores, imoveis);

    for(size_t ii = 0; ii < avaliadores.size(); ii++){
        std::vector<agendamento> resultado = organizar_visitas(avaliadores[ii]);
        std::cout << "Corretor " << avaliadores[ii].getId() << std::endl;

        for (size_t jj = 0; jj < resultado.size(); jj++ ){
            std::cout
            << std::setw(2) << std::setfill('0') << resultado[jj].hora << ":"
            << std::setw(2) << std::setfill('0') << resultado[jj].minuto
            << "  Imóvel " << resultado[jj].idImovel << std::endl;;
        }

    std::cout << '\n';
    }
    
    return 0;
}
