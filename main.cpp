#include <fstream>
#include <string.h>
#include "huff.h"

void help()
{
    printf("------------\n");
    printf(" Hufzip\n");
    printf(" v1.0.0\n");
    printf("------------\n");
    printf("-h\t\t\t\tShow help and exit.\n");
    printf("-c (filename)\tCompress the specified file.\n");
    printf("-d (filename)\tDecompress the specified file.\n");
}

void notRecognized()
{
    printf("Comando não reconhecido. Experimente adicionar algum dos parâmetros mostrados na ajuda.\n");
    help();
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        help();
        return 0;
    }

    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-help") == 0 || strcmp(argv[i], "-h") == 0)
        {
            help();
            return 0;
        }

        Huff* huff = new Huff();

        if(strcmp(argv[i], "-c") == 0)
        {
            if ((i + 1) < argc)
            {
                string filename = (string)argv[i + 1];
                huff->compress(filename);
            }
            else
            {
                notRecognized();
            }
        }
        else if(strcmp(argv[i], "-d") == 0)
        {
            if ((i + 1) < argc)
            {
                string filename = (string)argv[i + 1];
                huff->expand(filename);
            }
            else
            {
                notRecognized();
            }
        }
    }
}