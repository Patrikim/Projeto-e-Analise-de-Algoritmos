#include <iostream>
#include <string.h>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>


void SelectionSort(int vetor[])
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

void BubbleSort(int vetor[])
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

void SequencialSearch(int vetor[], int value)
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

void BruteForceStringMatch(char text[], char pattern[])
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

void BruteForceClosestPair(std::vector<std::vector<int>> pontos)
{
    float d = 9999;
    int i, j;

    for (i = 0; i < pontos.size() - 1; i++)
    {
        for (j = 0; j < i+1; j++)
        {
            //std::cout << "ola mundo";
            //std::cout << pontos[0][0] << pontos[1][0] << pontos[0][1] << pontos[1][1];
            float k1 = std::pow((pontos[0][0] - pontos[1][0]), 2);
            float k2 = std::pow((pontos[0][1] - pontos[1][1]), 2);
            float k3 = k1 + k2;
            float k4 = std::sqrt(k3);
            //std::cout << k3;
            //std::cout << k4;
            d = std::min(d, k4);
            std::cout << d;
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int vetor[10] = {1,5,6,9,8,2,3,10,4,7};

    char text[] = "dwafggwkgwqghellewqeasdwhellodwd";
    char pattern[] = "hello";

    std::vector<std::vector<int>> pontos{{1, 3}, {4, 1}}; 

    BruteForceClosestPair(pontos);

    //for (int i = 0; i < pontos.size(); i++) {
    //    for (int j = 0; j < pontos[i].size(); j++)
    //        std::cout << pontos[i][j] << " ";
    //    std::cout << std::endl;
    //}
    
    //SelectionSort(vetor);
    //BubbleSort(vetor);
    //SequencialSearch(vetor, 11);
    //BruteForceStringMatch(text, pattern);

    
    return 0;
}
