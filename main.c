#include <stdio.h>
int main(int argc, char* argv[]) {
    if (argc != 2) {
        puts("Usage: ");
        puts(argv[0]);
        puts(" <filename>\n");
        return 1;
    }
    FILE *fptr1, *fptr2;
    char* filename = argv[1];
    char* filenameptr = filename;
    int c = 0;
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return 1;
    }
    int i = 0;
    while(*filenameptr){
        ++i;
        ++filenameptr;
    }
    filename[i-4] = 0;
    char newFilename[127];
    filenameptr = filename;
    i = 0;
    while(*filenameptr){
        newFilename[i] = filename[i];
        ++filenameptr;
        ++i;
    }
    newFilename[i] = '_';
    newFilename[++i] = 'f';
    newFilename[++i] = 'i';
    newFilename[++i] = 'x';
    newFilename[++i] = 'e';
    newFilename[++i] = 'd';
    newFilename[++i] = '.';
    newFilename[++i] = 'i';
    newFilename[++i] = 'f';
    newFilename[++i] = 'r';
    newFilename[++i] = 0;

    fptr2 = fopen(newFilename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", newFilename);
        return 1;
    }
    i = 0;
    while ((c = fgetc(fptr1)) != EOF)
    {
        if(i < 0x5568){
            fputc(c, fptr2);
            ++i;
        }
        else{
            fputc(0, fptr2);
        }
    }
    return 0;
}

