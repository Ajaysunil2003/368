#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print(int q_count, int d_count, int n_count, int p_count) {
    printf("%d quarter(s), %d dime(s), %d nickel(s), %d pennie(s)\n", q_count, d_count, n_count, p_count);
}

void nickel_spread(int q_count,int d_count,int n_count,int p_count){ //funciton to spread out nickel and pennie values
    while(n_count>0){
        p_count = p_count +5;
        n_count = n_count -1;
        print(q_count, d_count, n_count, p_count);
    }

}

void dime_spread(int q_count,int d_count,int n_count,int p_count){ //funciton to spread out dime values
    while(d_count>0){
        n_count = n_count +2;
        d_count = d_count -1;
        print(q_count, d_count, n_count, p_count);
        nickel_spread(q_count, d_count, n_count, p_count);
    }

}

void quarter_spread(int q_count,int d_count,int n_count,int p_count){ //funciton to spread out quarter values
    while(q_count>0){
        d_count = d_count +2;
        n_count = n_count +1;
        q_count = q_count -1;
        print(q_count, d_count, n_count, p_count);
        nickel_spread(q_count, d_count, n_count, p_count);
        dime_spread(q_count, d_count, n_count, p_count);
    }

}

int main() {
    int cents;
    int quarters = 0;
    int q_count = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int d_count = 0;
    int n_count = 0;
    int p_count = 0;

    printf("What is the cent value: ");
    scanf("%d", &cents);

    if(cents < 0) {
        printf("Error! Cent value has to be greater than 0\n");
        return 1;
    }

    while(cents > 0){ //while loop for cents
        while (quarters >= 0){
            quarters = cents - 25;
            if(quarters >= 0){
                q_count += 1;
                cents -= 25;
            }
            else {
                break;
            }
        }

        while(dimes >= 0){  //while loop for dimes
            dimes = cents - 10;
            if (dimes >= 0){
                d_count += 1;
                cents -= 10;
            }
            else {
                break;
            }
        }

        while(nickels >= 0){ //while loop for nickels
            nickels = cents - 5;
            if (nickels >= 0){
                n_count += 1;
                cents -= 5;
            }
            else {
                break;
            }
        }

        while(pennies >= 0){ //while loop for pennies
            pennies = cents - 1;
            if (pennies >= 0){
                p_count += 1;
                cents -= 1;
            }
            else {
                break;
            }
        }

    }

    print(q_count, d_count, n_count, p_count);

    nickel_spread( q_count, d_count, n_count, p_count);
    dime_spread( q_count, d_count, n_count, p_count);
    quarter_spread( q_count, d_count, n_count, p_count);



    return 0;
}
