#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){

        for (int j = 0; j < width; j++){

            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            float ave = (r + g + b) /3.000;
            float newVal = round(ave);

            if (newVal > 255) {
                    newVal = 255;
                }

            image[i][j].rgbtRed = newVal;
            image[i][j].rgbtGreen = newVal;
            image[i][j].rgbtBlue = newVal;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){

        for (int j = 0; j < width; j++){

            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int sepRed = round(.393 * r + .769 * g + .189 * b);
            int sepGreen = round(.349 * r + .686 * g + .168 * b);
            int sepBlue = round(.272 * r + .534 * g + .131 * b);



                if (sepRed > 255) {
                    sepRed = 255;
                }

                 if (sepGreen > 255) {
                    sepGreen = 255;
                }

                 if (sepBlue > 255) {
                    sepBlue = 255;
                }


            image[i][j].rgbtRed = sepRed;
            image[i][j].rgbtGreen = sepGreen;
            image[i][j].rgbtBlue = sepBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
for (int i = 0; i < height; i++){

    for (int j = 0; j < width / 2; j++){
     int tmp [3];

     tmp[0] = image[i][j].rgbtRed;
     tmp[1] = image[i][j].rgbtGreen;
     tmp[2] = image[i][j].rgbtBlue;

     image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
     image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
     image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

     image[i][width - j - 1].rgbtRed = tmp[0];
     image[i][width - j - 1].rgbtGreen = tmp[1];
     image[i][width - j - 1].rgbtBlue = tmp[2];

    }
}
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++){

        for (int j = 0; j < width; j++) {
            int r = 0;
            int g = 0;
            int b = 0;
            float counter = 0;


          for (int y = -1; y < 2; y++){

              if (j + y < 0 || j + y > height - 1)
                {
                    continue;
                }

              for (int x = -1; x < 2; x++){

                  if (i + x < 0 || i + x > width - 1)
                    {
                        continue;
                    }


                r += image[i + x][j + y].rgbtRed;
                g += image[i + x][j + y].rgbtGreen;
                b += image[i + x][j + y].rgbtBlue;
                counter++;
              }

              tmp[i][j].rgbtRed = round(r / counter);
              tmp[i][j].rgbtGreen = round(g / counter);
              tmp[i][j].rgbtBlue = round(b / counter);

          }
        }
    }

    for (int i = 0; i < height; i++){

        for (int j = 0; j < width; j++ ){

            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }
    return;
}
