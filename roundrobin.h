#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include "corretor.h"
#include "imovel.h"
#include <vector>

void round_robin(std::vector<corretor>& avaliadores, std::vector<imovel>& imoveis);

#endif