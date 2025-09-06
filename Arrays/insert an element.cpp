#include <iostream>
using namespace std;
#define MAX_SIZE 6
int main()
{
    int arr[MAX_SIZE] = {1, 5, 10, 7, 31};
    int length = 5;
    int element = 52;
    int pos = 5;
    for (int i = length; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = element;
    length++;
    cout << "插入后的数组为：" << '\n';
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    return 0;
}