#include <stdio.h>

bool isPrime(int x) {
    bool f = true;
    for (int i = 2; i < x ; i++) {
        if (x % i == 0) {
            f = false;
        }
    }
    return f;
}

int main () {
    int a = 5;
    if (isPrime(a)){
        printf("Is prime");
    }
    else{
        printf("Is not prime");
    }

}
