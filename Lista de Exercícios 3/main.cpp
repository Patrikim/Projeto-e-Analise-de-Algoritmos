#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>


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
