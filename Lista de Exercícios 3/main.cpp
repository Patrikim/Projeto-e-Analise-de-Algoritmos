#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

#include <iostream>
#include <vector>
#include <cmath>

//Variáveis globais para o algoritmo de Johnson-Trotter
bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;


template<typename T> void insertionSort(std::vector<T> &v)
{
    int k, j;

    for (size_t i = 1; i < v.size(); i++)
    {
        k = v[i];
        j = i-1;

        while (j>=0 && v[j] > k)
        {
            v[j+1] = v[j];
            j = j-1;
        }
        v[j+1] = k;  
    }  
}


//Algoritmo de Johnson-Trotter
int fatorial(int n)
{
    return std::tgamma(n+1);
}
int searchArr(std::vector<int> &p, int n, int mobile)
{
    for (size_t i = 0; i < n; i++)
        if (p.at(i) == mobile)
           return i + 1;
}
int getMobile(std::vector<int> &p, std::vector<bool> &dir, int n)
{
    int mobileprev = 0, mobile = 0;
    
    for (int i = 0; i < n; i++)
    {
        // direction 0 represents RIGHT TO LEFT.
        if (dir[p[i]-1] == RIGHT_TO_LEFT && i!=0)
        {
            if (p[i] > p[i-1] && p[i] > mobileprev)
            {
                mobile = p[i];
                mobileprev = mobile;
            }
        }
  
        // direction 1 represents LEFT TO RIGHT.
        if (dir[p[i]-1] == LEFT_TO_RIGHT && i!=n-1)
        {
            if (p[i] > p[i+1] && p[i] > mobileprev)
            {
                mobile = p[i];
                mobileprev = mobile;
            }
        }
    }

    if (mobile == 0 && mobileprev == 0)
        return 0;
    else
        return mobile;
}
int permutation(std::vector<int> &p, std::vector<bool> &dir, int n)
{
    int mobile = getMobile(p, dir, n);
    int pos = searchArr(p, n, mobile);


    if (dir[p[pos - 1] - 1] ==  RIGHT_TO_LEFT)
    {
       std::swap(p[pos-1], p[pos-2]);
    }
  
    else if (dir[p[pos - 1] - 1] == LEFT_TO_RIGHT)
    {
       std::swap(p[pos], p[pos-1]);
    }
  
    for (size_t i = 0; i < n; i++)
    {
        if (p[i] > mobile)
        {
            if (dir[p[i] - 1] == LEFT_TO_RIGHT)
            {
                dir[p[i] - 1] = RIGHT_TO_LEFT;
            }
            else if (dir[p[i] - 1] == RIGHT_TO_LEFT)
            {  
                dir[p[i] - 1] = LEFT_TO_RIGHT;
            }
        }
    }
  
    for (int i = 0; i < n; i++)
    {
        std::cout << p[i];
    }
    std::cout << std::endl;

} 
void permutations(int n)
{
    std::vector<int> p;
    std::vector<bool> dir;

    for (size_t i = 0; i < n; i++)
    {
        p.push_back(i+1);
        std::cout << p[i];
    }
    std::cout << std::endl ;

    for (size_t i = 0; i < n; i++)
    {
        dir.push_back(RIGHT_TO_LEFT);
    }

    for (size_t i = 1; i < fatorial(n); i++)
    {
        permutation(p, dir, n);
    }

}
//Busca binária
int binarySearch(std::vector<int> v, int k)
{
    int min = 0, max = v.size()-1, x;

    while (min <= max)
    {
        x = (min + max) / 2;
        if (k == v.at(x))
        {
            return x;
        }
        else if(k > v.at(x))
        {
            min = x+1;
        }
        else
        {
            max = x-1;
        }
    }

    return -1;
}

//Interpolation Search
int interpolationSearch(std::vector<int> v, int k)
{
    int min = 0, max = v.size() - 1;

    while(min <= max && k >= v.at(min) && k <= v.at(max))
    {

        if(min == max)
        {
            if(v.at(min) == k)
            {
                return min;
            }
            else
            {
                return -1;
            }
        }

        int pos = min + (((double)(max - min) / (v.at(max) - v.at(min))) * (k - v.at(min)));

        //Condição para quanto o valor é encontrado
        if(v.at(pos) == k)
        {
            return pos;
        }


        if(v.at(pos) < k)
        {
            min = pos + 1;
        }
        else
        {
            max = pos - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    //std::vector<int> v = {2, 5, 9, 1, 4, 7, 6, 3, 0, 12, 10, 20, 15, 13};
    //insertionSort(v);
    //for (size_t i = 0; i < v.size(); i++)
    //{
    //    std::cout << v[i] << std::endl;
    //}


    //int n = 4;
    //permutations(n);


    //std::vector<int> v = {0, 2, 3, 5, 7, 8, 10, 15, 18, 22, 24, 26, 30, 35, 36, 39, 45};
    //std::cout << binarySearch(v, 30);
    //std::cout << interpolationSearch(v, 18);
    //
    return 0;
}


int max(std::vector<int>& v, int begin, int end)
{
    if (end - begin == 1)
    {
        return begin;
    }
    else
    {
        int idx1 = max(v, begin, (begin + end) / 2);
        int idx2 = max(v, (begin + end) / 2, end);
        return v.at(idx1) > v.at(idx2) ? idx1 : idx2;
    }
}

int main(int argc, char const *argv[])
{
    //std::vector<int> v = {2, 5, 9, 1, 4, 7, 6, 3, 0, 12, 10, 20, 15, 13};
    //insertionSort(v);
    //for (size_t i = 0; i < v.size(); i++)
    //{
    //    std::cout << v[i] << std::endl;
    //}


    //int n = 4;
    //permutations(n);


    //std::vector<int> v = {0, 2, 3, 5, 7, 8, 10, 15, 18, 22, 24, 26, 30, 35, 36, 39, 45};
    //std::cout << binarySearch(v, 30);
    //std::cout << interpolationSearch(v, 18);

    //std::vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    //int end = v.size()  - 1;
    //fakeCoinSolveRecursive(v, 0, end);

    std::vector<int> v = {23, 5, 3, 9, 10, 8, 7, 6, 4, 10, 23};
    std::cout << max(v, 0, v.size());


    return 0;
}
