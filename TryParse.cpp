

#include <stdio.h>

int TryParse(char numb, bool &sucsess );



int main() {
    printf("Enter the length of number\n");
    int n;
    scanf( "%d", &n);

    char str[n] ;

    printf("Enter number \n");
    scanf("%s", str);

    int x, sum = 0;
    bool success;
    for (int i = 0; i < n; i++) {

        x = TryParse(str[i], success);
        printf("%d \n", x);

        if (success){
            sum = sum * 10 + x;
        }
        else{
            return -1;
        }
    }
    printf("This is normal number = %d", sum);
    return 0;
}

int TryParse(char numb, bool &sucsess ){
    if  (numb <= '9' and numb >= '0'){
        sucsess = true;
        return numb - '0';
    }
    else{
        sucsess = false;
        return -1;
    }
}