#include <iostream>
using namespace std;
int search(int arr[], int length, int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int remove(int arr[], int length, int key)
{
    int index = search(arr, length, key);
    for (int i = index; i < length - 1; i++)
        arr[i] = arr[i + 1];
    length--;
    return index;
}
int main()
{
    cout << "请输入数组的长度：" << '\n';
    int n;
    cin >> n;
    int arr[n];
    cout << "请输入数组的值：" << '\n';
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "请输入要删除的值：" << '\n';
    int key;
    cin >> key;
    if (remove(arr, n, key) == -1)
        cout << "该值不存在" << '\n';
    else
    {
        cout << "删除后的数组为：" << '\n';
        for (int i = 0; i < n - 1; i++)
            cout << arr[i] << " ";
    }
    return 0;
}