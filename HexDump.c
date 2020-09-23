#include <stdio.h>

int main(void)
{
    unsigned char buffer[8];

    FILE *inputFile;
    inputFile = fopen("file.file","rb");

    FILE *outputFile;
    outputFile = fopen("hexdump.txt", "w+");
    
    while(0 < fread(buffer, 1, sizeof(buffer), inputFile))
    {
        for(int i = 0; i < sizeof(buffer); i++)
            fprintf(outputFile,"%02x", buffer[i]);
    }

    fclose(outputFile);
    fclose(inputFile);

    return 0;
}
