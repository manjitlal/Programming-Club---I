#include<stdio.h>
int nPr(int, int);
int digitsInANumber(int);
int checkForBinaryNumber(int);
int power(int, int);
int SIZE = 1;
void title();
int main() {
    system("color a");
    void size() {
        if(SIZE == 1) {
            SIZE = 0;
            system("mode 100");
            title();
        }
    }
    size();
    int N;
    printf("\nEnter the value of N: ");
    scanf("%d", &N);
    int subN;
    printf("\nEnter the substring: ");
    scanf("%d", &subN);
    int length = digitsInANumber(subN);
    int check = checkForBinaryNumber(subN);
    if(length > N || check == 0)
        printf("\nWrong value of the substring!\n");
    else if(length == N)
        printf("\nTotal number of match = %d\n", 1);
    else {
        int blankSpaces = N - length;
        int var1 = power(2, blankSpaces);
        int var2 = nPr(blankSpaces+1, blankSpaces+1);
        int result = var1 * var2;
        printf("\nTotal number of match = %d\n", result);
    }
    main();
    return 0;
}
int nPr(int n, int r) {
    int i, value = 1;
    for(i = 1; i <= r; i++) {
        value *= n;
        n--;
    }
    return value;
}
int digitsInANumber(int number) {
    int count = 0;
    while(number != 0) {
        number /= 10;
        count++;
    }
    return count;
}
int checkForBinaryNumber(int number) {
    while(number != 0) {
        if(number % 10 != 0 && number % 10 != 1) {
            return 0;
        }
        number /= 10;
    }
    return 1;
}
int power(int n, int x) {
    int i, pow = 1;
    for(i = 1; i <= x; i++) {
        pow *= n;
    }
    return pow;
}
void title() {
    int i, j;
    for(i = 1; i < 50; i++)
        printf("#");
    printf("\n#");
    for(i = 1; i < 48; i++)
        printf(" ");
    printf("#\n#");
    printf("\t\tMANJIT LAL");
    for(i = 1; i < 23; i++)
        printf(" ");
    printf("#\n#");
    for(i = 1; i < 48; i++)
        printf(" ");
    printf("#\n#");
    printf("\tID : 77657874738432766576");
    for(i = 1; i < 16; i++)
        printf(" ");
    printf("#\n");
    for(i = 1; i < 50; i++)
        printf("#");
    printf("\n\n");
}
/**
/*  Manjit Lal
/*  ID : 77657874738432766576
*/
