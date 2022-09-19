#include <iostream>
#include <vector>
#include <busca.h>


Busca::Busca(std::vector<std::vector<int>> listaadj)
{
    this->listaadj = listaadj;
}
void Busca::buscaLargura(int s)
{
    std::vector<int> F;

    for (size_t i = 0; i < listaadj.size(); i++)
    {
        visitado.push_back(0);
    }
    visitado.at(s) = 1;
    F.push_back(s);

    while (F.empty() != true)
    {
        int u = F.at(0);
        F.erase(F.begin());

        for (size_t i = 0; i < listaadj.at(u).size(); i++)
        {
            int v = listaadj.at(u).at(i);
            if(visitado[v] == 0)
            {
                visitado[v] = 1;
                std::cout << v << std::endl;
                F.push_back(v);
            }
        } 
    }
}

void Busca::buscaProfundidade(int s)
{
    for (size_t i = 0; i < listaadj.size(); i++)
    {
        visitado.push_back(0);
    }
    visitado.at(s) = 1;
    std::cout  << s << std::endl;

    for (size_t i = 0; i < listaadj.at(s).size(); i++)
    {
        int v = listaadj.at(s).at(i); 
        if (visitado[v] == 0)
        {
            buscaProfundidade(v);
        }         
    }
}


