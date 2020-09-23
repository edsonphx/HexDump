#include <stdio.h>

int main(void)
{
    long bytes;

    FILE *inputFile;
    inputFile = fopen("C:/inputFile.file","rb");

    fseek(inputFile, 0, SEEK_END);
    bytes = ftell(inputFile);
    rewind(inputFile);

    unsigned char buffer[bytes];

    fread(&buffer,sizeof(buffer),1, inputFile);

    FILE *outputFile;
    outputFile = fopen("C:/HexDump.txt", "w+");

    for(int i = 0; i<sizeof(buffer); i++)
        fprintf(outputFile,"%02x", buffer[i]);

    fclose(outputFile);
    fclose(inputFile);

    return 0;
}
