#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<unsigned short> v1, v2;
unsigned short x, count;

void initialize()
{
    cin >> x;

    while (x > 0)
    {
        v2.push_back(x % 10);
        x /= 10;
    }

    size_t n = v2.size();

    if (n > 0)
    {
        for (size_t i = 0; i < n; ++i)
        {
            size_t index = n - i - 1;
            unsigned short element = v2.at(index);

            v1.push_back(element);
        }
    }
}

void show(vector<unsigned short> v)
{
    for (size_t i = 0; i < v.size(); ++i)
        cout << v.at(i);
    cout << endl;
}

int main()
{
    initialize();

    if (v1.size() > 0)
    {
        while (true)
        {
            v2.clear();
            x = v1.at(0);
            count = 1;

            for (size_t i = 1; i < v1.size(); ++i)
            {
                if (v1.at(i) == x)
                {
                    ++count;
                }
                else
                {
                    v2.push_back(count);
                    v2.push_back(x);

                    x = v1.at(i);
                    count = 1;
                }
            }

            v2.push_back(count);
            v2.push_back(x);

            v1 = v2;
            show(v1);
            getch();
        }
    }

    return 0;
}
