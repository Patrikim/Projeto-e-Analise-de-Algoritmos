#include <iostream>
#include <vector>

class Busca
{
    public:
        std::vector<int> visitado;
        std::vector<std::vector<int>> listaadj;


        Busca(std::vector<std::vector<int>> listaadj)
        {
            this->listaadj = listaadj;
        }

        void buscaLargura(int s)
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
        
        void buscaProfundidade(int s)
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
};


int main(int argc, char const *argv[])
{   
    std::vector<std::vector<int>> listaadj;
    //std::vector<int> v0 = {1, 2, 4};
    //std::vector<int> v1 = {0, 3, 5};
    //std::vector<int> v2 = {0, 5};
    //std::vector<int> v3 = {1, 4};
    //std::vector<int> v4 = {0, 3, 5};
    //std::vector<int> v5 = {2, 4};
    std::vector<int> v0 = {1, 2};
    std::vector<int> v1 = {3, 4};
    std::vector<int> v2 = {5, 6};
    std::vector<int> v3 = {7, 8};
    std::vector<int> v4 = {9, 10};
    std::vector<int> v5 = {11, 12};
    std::vector<int> v6 = {13, 14};
    std::vector<int> v7 = {};
    std::vector<int> v8 = {};
    std::vector<int> v9 = {};
    std::vector<int> v10 = {};
    std::vector<int> v11 = {};
    std::vector<int> v12 = {};
    std::vector<int> v13 = {};
    std::vector<int> v14 = {};


    listaadj.push_back(v0);
    listaadj.push_back(v1);
    listaadj.push_back(v2);
    listaadj.push_back(v3);
    listaadj.push_back(v4);
    listaadj.push_back(v5);
    listaadj.push_back(v6);
    listaadj.push_back(v7);
    listaadj.push_back(v8);
    listaadj.push_back(v9);
    listaadj.push_back(v10);
    listaadj.push_back(v11);
    listaadj.push_back(v12);
    listaadj.push_back(v13);
    listaadj.push_back(v14);


    Busca B = Busca(listaadj);
    B.buscaLargura(0);
    //B.buscaProfundidade(0);

	
    return 0;
}

