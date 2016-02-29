#include <iostream>
using namespace std;

struct Rational {
    int p, q;
};
void Farey2(int n, int &k, Rational *mass);

int main() {
    int  n;
    cout << "Enter n " << endl;
    cin >> n;

    struct Rational f [300];
    int l;

    Farey2(n, l, f);
    for (int i = 0; i < l; i++)

    {
        cout << f[i].p << '/' << f[i].q << endl;
    }
}

void Farey2(int n, int &k, Rational *mass){

    mass[0].p = 0;
    mass[0].q = 1;

    mass[1].p = 1;
    mass[1].q = 1;

    k = 2;

    for (int i = 2; i <= n ; i++) {
        int j = 0;

        while (j <= k - 2)  {
            if ((mass[j].q + mass[j + 1].q) == i)  {
                for (int l = k + 1; l > j + 1; l--) {
                    mass[l] = mass[l - 1];
                }
                mass[j + 1].p = mass[j].p + mass[j + 2].p;
                mass[j + 1].q = mass[j].q + mass[j + 2].q;
                j++;
                k++;

            }
            j++;
        }
    }
}