#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int game()
{

    int a, b, c, d;
    int e, f, g, h;
    int number, guess;

    do
    {
        srand(time(0));
        a = rand() % 10;
        b = rand() % 10;
        c = rand() % 10;
        d = rand() % 10;
    } while ((a == b) || (a == c) || (a == d) || (b == c) || (b == d) || (c == d));

    number = (a * 1000) + (b * 100) + (c * 10) + d;

    cout << "Your guess: " << endl;
    cin >> guess;

    while (guess != number)
    {
        int A = 0, B = 0;
        e = guess / 1000;
        f = guess / 100 % 10;
        g = guess / 10 % 10;
        h = guess % 10;

        if (guess >= 1000 && guess < 10000 && (e == f || e == g || e == h || f == g || f == h || g == h))
        {
            cout << "Four digits cannot be the same." << endl;
            cout << "Enter a number again : " << endl;
            cin >> guess;
        }
        else if (guess < 1000 || guess >= 10000)
        {
            cout << "Enter a 4-digit number." << endl;
            cout << "Enter a number again : " << endl;
            cin >> guess;
        }
        else
        {
            if (a == e)
                A++;
            if (b == f)
                A++;
            if (c == g)
                A++;
            if (d == h)
                A++;
            if (e == b || e == c || e == d)
                B++;
            if (f == a || f == c || f == d)
                B++;
            if (g == a || g == b || g == d)
                B++;
            if (h == a || h == b || h == c)
                B++;

            cout << A << " A " << B << " B " << endl;
            cout << "Enter a number again : " << endl;
            cin >> guess;
        }
    }
    cout << "CORRECT!" << endl;
    return 0;
}
