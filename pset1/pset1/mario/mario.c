#include <stdio.h>
#include <cs50.h>




int main(void) {

    int number;


    do{
     number = get_int("Height: ");

    }
    while (number < 1 || number > 8);

   for ( int i = 0; i < number; i++) {

       for ( int j = 0; j < number ; j++){

          if (i + j < number - 1)
              printf(" ");
          else
              printf("#");

       }

      printf("\n");
   }



}
