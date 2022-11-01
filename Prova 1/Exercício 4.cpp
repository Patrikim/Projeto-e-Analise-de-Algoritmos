#include <iostream>
#include <algorithm>
#include <vector>


void bruteForceSum(std::vector<std::vector<int>> m)
{
    int soma = 0;
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m.size(); j++)
        {
            soma = soma + m[i][j];
        }
    }
    std::cout << soma << std::endl;
    
}

int main(int argc, char const *argv[])
{
    
    std::vector<std::vector<int>> m{{1 ,2, 3}, {4, 5, 6}, {7, 8, 9}};
    int count = m.size();
    
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < count; j++)
        {
            std::cout << m[i][j] << " "; 
        }
        std::cout << std::endl;   
    }

    //bruteForceSum(m);
  
   
    return 0;
}
