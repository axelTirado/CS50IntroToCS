#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTE_SIZE 512



int main(int argc, char *argv[])
{
FILE* inPoint = fopen(argv[1] , "r");

if (argc != 2) {
    printf("usage: ./recover <filename>\n");
    return 1;
}

if (argv[1] == NULL){
    printf("File not found\n");
    return 1;
}

char file[8];
FILE* outPoint = NULL;
uint8_t Byte_Buff[BYTE_SIZE];
int jpeg_count = 0;

while (fread(Byte_Buff, sizeof(uint8_t), BYTE_SIZE, inPoint) || feof(inPoint) == 0 ){
    if (Byte_Buff[0] == 0xff && Byte_Buff[1] == 0xd8 && Byte_Buff[2] == 0xff && (Byte_Buff[3] & 0xf0) == 0xe0){
        if (outPoint != NULL){
            fclose(outPoint);
        }
        sprintf(file, "%03i.jpg", jpeg_count);
        outPoint = fopen(file, "w");
        jpeg_count++;
    }

    if (outPoint != NULL) {
      fwrite(Byte_Buff, sizeof(Byte_Buff), 1, outPoint);
    }
}

if (inPoint == NULL){
    fclose(inPoint);
}

if (outPoint == NULL){
    fclose(outPoint);
}
return 0;


}
