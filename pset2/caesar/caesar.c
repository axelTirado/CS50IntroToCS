#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
   if (argc == 2 ){
       if isdigit(*argv[1]){


          int k = atoi(argv[1]) % 26;

          string plain = get_string("PlainText: ");

          int nTxt = 0;

          printf("ciphertext: ");

          for (int i = 0, len = strlen(plain); i < len; i++){

             if (islower(plain[i])){
                 nTxt = (((int)plain[i] - 97 + k) % 26 )+ 97;
                 printf("%c", (char) nTxt);
             }

             else if (isupper(plain[i])){
                  nTxt = (((int)plain[i] - 65 + k) % 26 )+ 65;
                  printf("%c", (char) nTxt);
             }

             else {
                 printf("%c", plain[i]);
             }


          }

          printf("\n");
          return 0;
       }

       else if (!isdigit(*argv[1])) {
           printf("invalid key\n");
           return 1;
       }

   }
   else if (argc != 2) {
       printf("Usage: ./caesar key\n");
       return 1;
   }
}