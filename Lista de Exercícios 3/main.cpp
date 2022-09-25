#include <iostream>
#include <vector>




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


int main(int argc, char const *argv[])
{
    std::vector<int> v = {2, 5, 9, 1, 4, 7, 6, 3, 0, 12, 10, 20, 15, 13};
    
    //insertionSort(v);

    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    
    return 0;
}
