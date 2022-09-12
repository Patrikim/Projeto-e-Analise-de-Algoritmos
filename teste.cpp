#include <iostream>


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




int main(int argc, char const *argv[])
{
    int vetor[10] = {1,5,6,9,8,2,3,10,4,7};
    //SelectionSort(vetor);
    BubbleSort(vetor);

    
    return 0;
}
