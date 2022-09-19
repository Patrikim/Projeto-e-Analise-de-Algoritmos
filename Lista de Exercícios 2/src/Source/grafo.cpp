#include <iostream>
#include <vector>
#include "aresta.h"
#include "grafo.h"



class Grafo
{
    private:
        std::vector<int> V;
        std::vector<Aresta> E;
        std::vector<std::vector<int>> matrizadj;
        std::vector<std::vector<int>> listaadj;


    public:
        Grafo(std::vector<int> V, std::vector<Aresta> E, std::vector<std::vector<int>> matrizadj, std::vector<std::vector<int>> listaadj)
        {
            this->V = V;
            this->E = E;
            this->matrizadj = matrizadj;
            this->listaadj = listaadj;
        }

        void setV(std::vector<int> V)
        {
            this->V = V;
        }
        std::vector<int> getV()
        {
            return this->V;
        }
        void setV(std::vector<Aresta> E)
        {
            this->E = E;
        }
        std::vector<Aresta> getE()
        {
            return this->E;
        }
        void setMatrizadj(std::vector<std::vector<int>> matrizadj)
        {
            this->matrizadj = matrizadj;
        }
        std::vector<std::vector<int>> getMatrizadj()
        {
            return this->matrizadj;
        }
        void setMatrizadj(std::vector<std::vector<int>> listaadj)
        {
            this->listaadj = listaadj;
        }
        std::vector<std::vector<int>> getListaadj()
        {
            return this->listaadj;
        }
};