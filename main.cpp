#include <iostream>
///вспомогательные функции
int getArraySum(int * arr , int size)
{

    int sum = 0;
    for ( int i = 0 ; i < size ; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

void printArray(int * arr, int size)
{

    for(int i = 0 ; i < size ; i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
}

///функции для лабы
void invertArray(int * arr , int size)
{
    int temp;
    for(int i = 0 ; i < size / 2 ; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size-1-i] = temp;
    }

}

void sortArrayUp(int * arr , int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = size - 1; j > i; j--) {
            if (arr[j] < arr[j-1]) {
                int t = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = t;
            }
        }
    }

}

void sortArrayDown(int * arr , int size)
{
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = size - 1; j > i; j--) {
            if (arr[j] > arr[j-1]) {
                int t = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = t;
            }
        }
    }

}

///функция выбор
void(*pickFunc(int*arr , int size))(int*,int)
{
     void(*fptr)(int*,int) = NULL;
     int sum = getArraySum(arr , size);
     if(sum == arr[0]) fptr = invertArray;
     if(sum > arr[0]) fptr = sortArrayUp;
     else fptr = sortArrayDown;
     return fptr;
}


int main() {
    int N = 15;
    int *arr = new int[N];
    void(*fptr)(int*,int);
    for(int i = 0 ; i < N ; i++)
    {
        arr[i] = rand();
    }
    fptr = pickFunc(arr , N);
    fptr(arr , N);
    printArray(arr, N);



    return 0;
}

