#include <iostream>
#include "aresta.h"

class Aresta
{
private:
    int u; // Vertice origem
    int v; // Vertice destino
    int w;

public:
    //Construtor padrão
    Aresta();
    //construtor 
    Aresta(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    //Getters e Setters
    void setU(int u)
    {
        this->u = u;
    }
    int getU()
    {
        return this->u;
    }
    void setV(int v)
    {
        this->v = v;
    }
    int getV()
    {
        return this->v;
    }
    void setW(int w)
    {
        this->w = w;
    }
    int getW()
    {
        return this->w;
    }
};