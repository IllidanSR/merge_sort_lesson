#include <iostream>
#include <vector>

void mergeSort(std::vector<int> &vector, size_t start, size_t end){
    if(end - start < 2) return;
    if(end - start == 2) {
        if (vector[start] > vector[start + 1]) {
            std::swap(vector[start], vector[start + 1]);
        }
    }
    //==================================================================================================================
    mergeSort(vector, start, start+(end - start)/2);
    mergeSort(vector, start+(end - start)/2, end);
    //==================================================================================================================

    std::vector<int> b;

    size_t begin_1 = start;
    size_t end_1 = start + (end - start)/2;
    size_t begin_2 = end_1;

    while(b.size() < end - start){
        if(begin_1 >= end_1 || (begin_2 < end && vector[begin_2] <= vector[begin_1])){
            b.push_back(vector[begin_2]);
            ++begin_2;
        } else{
            b.push_back(vector[begin_1]);
            ++begin_1;
        }
    }

    for(size_t i = start; i < end; i++)
        vector[i] = b[i - start];

}

void bubbleSort(std::vector<int> arrForSort)
{
    int buff = 0;

    for (int i = 0; i < arrForSort.size() - 1; i++) //
    {
        for (int j = arrForSort.size() - 1; j > i; j--)
        {
            if (arrForSort[j] < arrForSort[j - 1])
            {
                buff = arrForSort[j - 1];
                arrForSort[j - 1] = arrForSort[j];
                arrForSort[j] = buff;
            }
        }

    }
}

int main()
{
    std::vector<int> vector;
    for(int i = 0; i < 20000; i++)
        vector.push_back(i);

    for(size_t i = 0; i<vector.size(); i++)
        std::swap(vector[i], vector[rand()%(vector.size() - i) + i]);


    for(auto i : vector)
        std::cout << i << " ";
    std::cout << "\n";

    std::cout << "MERGE SORT" << std::endl;

    unsigned int start_time =  clock();
    mergeSort(vector, 0, vector.size());
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for(auto i : vector)
        std::cout << i << " ";
    std::cout << "\n";

    std::cout << "MERGE SORT TIME : " << search_time <<"ms"<< std::endl;

    std::cout << "BUBBLE SORT" << std::endl;
    unsigned int start_time_bubble_sort =  clock();
    bubbleSort(vector);
    unsigned int end_time_bubble_sort = clock();
    unsigned int bubble_sort_time = end_time_bubble_sort - start_time_bubble_sort;

    std::cout << "BUBBLE SORT TIME : " << bubble_sort_time << "ms" << std::endl;

    std::cout << "Массив после сортировки :\n";
    for (int i : vector)
    {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

}