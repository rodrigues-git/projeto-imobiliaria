#include <iostream>
#include <vector>
#include <sstream>
#include "header.h" // contém corretor, cliente e imovel

int main() {
    std::vector<corretor> corretores;
    std::vector<cliente> clientes;
    std::vector<imovel> imoveis;

    int n;

    // --- Corretores ---
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string linha;
        std::getline(std::cin, linha);
        std::istringstream iss(linha);

        int telefone, avaliadorInt;
        double lat, lng;
        std::string nome;

        iss >> telefone >> avaliadorInt >> lat >> lng;
        std::getline(iss, nome);
        if (!nome.empty() && nome[0] == ' ') nome.erase(0, 1);

        corretor c;
        c.setTel(telefone);
        c.setAvaliador(avaliadorInt == 1);
        c.setLat(lat);
        c.setLng(lng);
        c.setNome(nome);
        corretores.push_back(c);
    }

    // --- Clientes ---
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string linha;
        std::getline(std::cin, linha);
        std::istringstream iss(linha);

        int telefone;
        std::string nome;

        iss >> telefone;
        std::getline(iss, nome);
        if (!nome.empty() && nome[0] == ' ') nome.erase(0, 1);

        cliente c;
        c.setTel(telefone);
        c.setNome(nome);
        clientes.push_back(c);
    }

    // --- Imóveis ---
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string linha;
        std::getline(std::cin, linha);
        std::istringstream iss(linha);

        int tipoInt, propId;
        double lat, lng, preco;
        std::string endereco;

        iss >> tipoInt >> propId >> lat >> lng >> preco;
        std::getline(iss, endereco);
        if (!endereco.empty() && endereco[0] == ' ') endereco.erase(0, 1);

        imovel im;
        im.setTipo(static_cast<imovel::TipoImovel>(tipoInt));
        im.setProprietarioId(propId);
        im.setLat(lat);
        im.setLng(lng);
        im.setPreco(preco);
        im.setEndereco(endereco);
        imoveis.push_back(im);
    }

    // Teste simples para confirmar leitura
    std::cout << "Corretores: " << corretores.size()
              << ", Clientes: " << clientes.size()
              << ", Imoveis: " << imoveis.size() << std::endl;

    return 0;
}
