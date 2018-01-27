/*Ho-Ren Kang horenk 21397985*/
#include <stdio.h>
#include <string.h>
int array[11];
int sizeArray = 0;
//will return a -1 if arr_file has a negative num or size > 10
int readRequirementFile(char filename[20])
{
    FILE *file = NULL;
    file = fopen (filename,"r");
    char string[100];
    if(fgets(string, 100, file)) 
    {
        char *token = strtok(string, " ");
        while (token != NULL)
        {
            char *newline = strchr( token, '\n' );
            if (newline)
            *newline = 0;
            int number = atoi(token);
            if(number < 0)
            {
              printf("ERROR");
              return -1;
            }
            array[sizeArray] = number;
            sizeArray++;
          
            if(sizeArray > 10)
            {
              return -1;
            }
            token = strtok(NULL, " ");
        }
    }
}
void printArray()
{
  int i = 0;
  for(; i < sizeArray; i++)
  {
    printf("%d, ", array[i]);
  }
}
int main(int argc, char *argv[]) {
    char file[20];
    int target = 0;
    int test = 5;
//     strcpy(file, argv[1]);
//     target = atoi(argv[2]);
    readRequirementFile("arr_file.txt");
    printArray();
    return 0;
}