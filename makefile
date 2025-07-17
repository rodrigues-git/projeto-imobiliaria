all: imobiliaria

imobiliaria: main.o cliente.o corretor.o imovel.o roundrobin.o agendamentos.o calculo_distancia.o
	g++ -Wall main.o cliente.o corretor.o imovel.o roundrobin.o agendamentos.o calculo_distancia.o -o imobiliaria

main.o: main.cpp
	g++ -Wall -c main.cpp

cliente.o: cliente.cpp cliente.h
	g++ -Wall -c cliente.cpp

corretor.o: corretor.cpp corretor.h
	g++ -Wall -c corretor.cpp

imovel.o: imovel.cpp imovel.h
	g++ -Wall -c imovel.cpp

roundrobin.o: roundrobin.cpp roundrobin.h
	g++ -Wall -c roundrobin.cpp

agendamentos.o: agendamentos.cpp agendamentos.h
	g++ -Wall -c agendamentos.cpp

calculo_distancia.o: calculo_distancia.cpp calculo_distancia.h
	g++ -Wall -c calculo_distancia.cpp

clean:
	del *.o *.exe 2>nul || rm -f *.o *.exe
