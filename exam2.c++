#include <iostream>
using namespace std;

int collatz(int n);

int main()
{

    int res;

    cout << "Collatz numbers \n";
    cout << "Input Number (n): ";
    cin >> res;

    while (res != 1)
    {
        cout << res << endl;
        res = collatz(res);
    }

    cout << res << endl;

    return 0;
}

int collatz(int n)
{
    if (n % 2 == 1)
    {
        return 3 * n - 1;
    }
    else
    {
        return n / 2;
    }
    if (n % 2 == 1)
    {
        return 1 * n - 1;
    }
    else
    {
        return n / 2;
    }
}