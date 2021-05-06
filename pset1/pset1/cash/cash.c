#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float cash;
    int cents;
    int count = 0;


    do {
      cash = get_float("Change owed: ");

    }
    while(cash < 0);

    cents = round(cash * 100);

   int denom[]= {25,10,5,1};
   int size = sizeof(denom)/sizeof(int);

   for(int i = 0; i < size; i++ ) {

       count = count + cents/denom[i];
       cents %= denom[i];
   }

     printf("%i\n", count);
}