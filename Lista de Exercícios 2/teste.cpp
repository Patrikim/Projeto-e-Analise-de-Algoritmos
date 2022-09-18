#include <iostream>
#include <string.h>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>

void selectionSort(int vetor[])
{
    int i , j ,aux , min, count=10;

    for ( i = 0; i < count; i++)
    {
        min = i ;
        for ( j = i + 1; j < count; j++)
        {
            if (vetor[ j ] < vetor[min])
            {
                min = j ;
                aux = vetor[min] ;
                vetor[min] = vetor[ i ] ;
                vetor[ i ] = aux;
            }
        }
    }

   for (i = 0; i < count; i++)
   {
        std::cout << vetor[i] << "\n";
   } 
}

void bubbleSort(int vetor[])
{
    int i, j, aux, count = 10;

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count-1; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
        
    }

    for (i = 0; i < count; i++)
    {
        std::cout << vetor[i] << "\n";
    }
}

void sequencialSearch(int vetor[], int value)
{
    int i, k = value, count=10;

    for (i = 0; i < count; i++)
    {
        if(vetor[i] == k)
        {
            std::cout << "O valor esta no vetor!";
        }
    }
}

void bruteForceStringMatch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int j;

    for (int i = 0; i < n - m; i++)
    {
        j = 0;
        while ((j < m) and (pattern[j] == text[i + j]))
        {
            j +=1;     
        }
        if (j == m)
        {
            std::cout << "A string esta no texto!";
        }                 
    }
}

template<typename T> void bruteForceClosestPair(std::vector<std::vector<T>> pontos)
{

    float d = 99999;


    for (size_t i = 0; i < pontos.size() - 1; i++)
    {
        for (size_t j = i+1; j < pontos.size(); j++)
        {
            //std::cout << "ola mundo";
            //std::cout << pontos[i][0] << pontos[i+1][0] << pontos[i][1] << pontos[i+1][1];
            float k1 = std::pow((pontos[i][0] - pontos[j][0]), 2);
            float k2 = std::pow((pontos[i][1] - pontos[j][1]), 2);
            float k3 = k1 + k2;
            float k4 = std::sqrt(k3);
            //std::cout << k3;
            //std::cout << k4;


            std::cout << i << " " << j << std::endl;
            d = std::min(d, k4);
            std::cout<< i << " iteracao: " << k4 << std::endl;
        }
    }
}




void bruteForceClosestPair1(std::vector<std::vector<int>> pontos)
{
    float d = 9999;
    int i, j;

    for (i = 0; i < pontos.size() - 1; i++)
    {
        for (j = 0; j < 1; j++)
        {
            //std::cout << "ola mundo";
            std::cout << pontos[i][0] << pontos[i+1][0] << pontos[i][1] << pontos[i+1][1];
            float k1 = std::pow((pontos[i][0] - pontos[i+1][0]), 2);
            float k2 = std::pow((pontos[i][1] - pontos[i+1][1]), 2);
            float k3 = k1 + k2;
            float k4 = std::sqrt(k3);
            //std::cout << k3;
            //std::cout << k4;
            d = std::min(d, k4);
            std::cout << d;
        }
        
    }
}

int main()
{
    //int vetor[10] = {1,5,6,9,8,2,3,10,4,7};

    //char text[] = "dwafggwkgwqghellewqeasdwhellodwd";
    //char pattern[] = "hello";

    std::vector<std::vector<float>> pontos{{1.2, 3}, {4, 1}, {1, 2}, {2,6} , {6,9}, {2,1}}; 


    bruteForceClosestPair(pontos);

    //bruteForceClosestPair(pontos);

    //for (int i = 0; i < pontos.size(); i++) {
    //    for (int j = 0; j < pontos[i].size(); j++)
    //        std::cout << pontos[i][j] << " ";
    //    std::cout << std::endl;
    //}
    
    //selectionSort(vetor);
    //bubbleSort(vetor);
    //sequencialSearch(vetor, 11);
    //bruteForceStringMatch(text, pattern);
    return 0;
}
