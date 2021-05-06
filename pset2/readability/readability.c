#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
string sentence = get_string("Text: ");

int L, W, S, W2;
float aveL, aveS;

L = 0;
W = 0;
S = 0;


for (int i = 0, len = strlen(sentence); i < len  ; i++){

    if (isalpha(sentence[i])) {
       L++;
    }

    if (isblank(sentence[i])){
        W++;
    }

    if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?'){
        S++;
    }

}

W2 = W + 1;
aveL = (L / (float)W2) * 100;
aveS = (S / (float)W2) * 100;

int index = round(0.0588 * aveL - 0.296 * aveS - 15.8);

if (index > 16){
    printf("Grade 16+\n");
}

else if (index < 1) {
    printf("Before Grade 1\n");
}

else {
    printf("Grade %i\n", index);
}

}

