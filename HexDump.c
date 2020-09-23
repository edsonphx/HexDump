#include <stdio.h>

int main(void)
{
    long bytes;
    size_t bytesRead;
    int limit;
    unsigned char buffer[1024];

    FILE *inputFile;
    inputFile = fopen("file.file","rb");

    fseek(inputFile, 0, SEEK_END);
    bytes = ftell(inputFile);
    rewind(inputFile);

    FILE *outputFile;
    outputFile = fopen("hexdump.txt", "w+");

    if(sizeof buffer > bytes)
        limit = bytes;
    else
        limit = sizeof(buffer);

    while (0 < (bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)))
    {
        for(int i = 0; i < limit; i++)
            fprintf(outputFile,"%02x", buffer[i]);
    }

    fclose(outputFile);
    fclose(inputFile);

    return 0;
}
