#ifndef BUSCA_H
#define BUSCA_H

class Busca
{    
    public:
        std::vector<int> visitado;
        std::vector<std::vector<int>> listaadj;

        Busca(std::vector<std::vector<int>> L);
        
        void buscaLargura(int s);
        void buscaProfundidade(int s);
};

#endif // BUSCA_H