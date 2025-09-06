#include <iostream>
using namespace std;
const int N = 1e6 + 9;
int a[N];
int search(int arr[], int length, int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int main()
{
    cout << "请输入数组的长度：" << '\n';
    int n;
    cin >> n;
    cout << "请输入数组的值：" << '\n';
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "请输入要查找的值：" << '\n';
    int key;
    cin >> key;
    if (search(a, n, key) == -1)
        cout << "该值不存在" << '\n';
    else
        cout << "它在数组中的下标为：" << search(a, n, key) << '\n';
    return 0;
}