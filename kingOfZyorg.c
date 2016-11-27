#include<stdio.h>
#define absent 0
#define present 1
int fact(int);
void initializeZeroCycle(int [][2], int);
void initializeOneCycle(int [][2], int);
int getValueFromCycle(int [][2], int);
int isCycleComplete(int [][2], int);
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

    /** Functions */
    void print(int P[][N+1],int N) {
        int i, j;
        for(i = 0; i < fact(N); i++) {
            printf("\n");
            for(j = 0; j <= N; j++) {
                printf("%d\t", P[i][j]);
            }
        }
        printf("\n");
    }

    void changeCycle(int P[][N+1], int cycle[][2], int N, int row, int column) {
        int i, j;
        for(i = 0; i < column-1; i++) {
            for(j = 0; j < N; j++) {
                if(P[row][i] == cycle[j][0])
                {
                    cycle[j][1] = present;
                    break;
                }
            }
        }
    }

    void fillTheCycle(int P[][N+1], int cycle[][2], int N, int row) {
        int i, j;
        for(i = 0; i < N - 2; i++) {
            for(j = 0; j < N; j++) {
                if(P[row][i] == cycle[j][0]) {
                    cycle[j][1] = present;
                    break;
                }
            }
        }
    }

    int getTheValue(int P[][N+1], int cycle[][2], int N, int row) {
        int i, j;
        for(i = 0; i < N; i++) {
            if(cycle[i][1] == absent) {
                cycle[i][1] = present;
                return cycle[i][0];
            }
        }
    }

    int i, j, k;
    int K = N - 1;
    if(N >= 9) {
        printf("\nProvide values between 1 to 8, values greater than or equal to 9 suffers memory deficiency!\n");
    } else {
        if(fact(N) != -1) {
            /** Generate all possible combinations of arrangement NPN */
            int P[fact(N)][N+1];
            for(i = 0; i < fact(N); i++) {
                for(j = 0; j <= N; j++) {
                    P[i][j] = 0;
                    if(j == N)
                        P[i][j] = 1;
                }
            }
            /** Generate Cycle */
            int cycle[N][2];
            for(i = 0; i < N; i++) {
                cycle[i][0] = i+1;
                cycle[i][1] = 0;
            }
            int columnFill = N-2;
            int value, partitions, times, row;
            for(i = 1; i <= columnFill; i++) {  // selects the column but to be taken as i-1
                times = fact(N - i);
                partitions = fact(N) / times;
                row = 0, value = 1;
                for(j = 1; j <= partitions; j++) {
                    if(i!=1) {
                        if(isCycleComplete(cycle, N))
                            initializeZeroCycle(cycle, N);
                        changeCycle(P, cycle, N, row, i);
                        value = getValueFromCycle(cycle, N);
                    }
                    for(k = 1; k <= times; k++) {

                        P[row][i-1] = value;
                        row++;
                    }
                    if(i!=1) {

                    } else {
                        value++;
                    }
                }
            }
            /** Provide the values for last two columns */
            for(i = 0; i < fact(N); i += 2) {
                initializeZeroCycle(cycle, N);
                fillTheCycle(P, cycle, N, i);
                int temp1 = getTheValue(P, cycle, N, i);
                int temp2 = getTheValue(P, cycle, N, i);
                P[i][N-2] = temp1;
                P[i][N-1] = temp2;
                P[i+1][N-2] = temp2;
                P[i+1][N-1] = temp1;
            }
            /** check for K */
            int max;
            for(k = 1; k <= K; k++) {
                for(i = 0; i < fact(N); i++) {
                    max = 0;
                    for(j = 0; j < k; j++) {
                        if(P[i][j] > max)
                            max = P[i][j];
                    }
                    if(max <= k)
                        P[i][N] = 0;
                }
            }
            /** Count the number of possible ways */
            int count = 0;
            for(i = 0; i < fact(N); i++) {
                if(P[i][N] == 1)
                    count++;
            }
            if(N == 1) {
                count = 0;
                printf("\nThe total number of possible ways = %d\n\n", count);
                printf("No possible ways!");
            } else {
                printf("\nThe total number of possible ways = %d\n\n", count);
            }
            if(N!=1) {
                /** Comment out this if block if not needed to see the combinations */
                for(i = 0; i < fact(N); i++) {
                    if(P[i][N] == present) {
                        printf("(");
                        for(j = 0; j < N; j++) {
                            if(j == N-1)
                                printf("%d)\t\t", P[i][j]);
                            else
                                printf("%d,", P[i][j]);
                        }
                    }
                }
                /** Comment out this if block if not needed to see the combinations */
            }
            printf("\n");
            printf("\nThe total number of possible ways = %d\n", count);
            //print(P, N);
        }
        else
            printf("\nWrong value of \"N\"!\n");
    }
    main();
    return 0;
}
int fact(int N) {
    int i, factorial = N;
    if(N > 0) {
        for(i = 2; i < N; i++) {
            factorial *= i;
        }
        return factorial;
    }
    else
        return -1;
}
void initializeZeroCycle(int cycle[][2], int N) {
    int i;
    for(i = 0; i < N; i++) {
        cycle[i][1] = 0;
    }
}
void initializeCycle(int cycle[][2], int N) {
    int i;
    for(i = 0; i < N; i++) {
        cycle[i][1] = 1;
    }
}
int getValueFromCycle(int cycle[][2], int N) {
    int i, j;
    for(i = 0; i < N; i++) {
        if(cycle[i][1] == absent) {
            cycle[i][1] = present;
            return cycle[i][0];
        }
    }
}
int isCycleComplete(int cycle[][2], int N) {
    int i, count = 0;
    for(i = 0; i < N; i++) {
        if(cycle[i][1] == present)
            count++;
    }
    if(count == N)
        return 1;   /** Complete */
    else
        return 0;   /** Not Complete */
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

