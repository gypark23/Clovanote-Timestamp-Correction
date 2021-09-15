#include <stdio.h>
#include <string.h>

const int MAX_CHAR_LENGTH = 1000000;
const int MAX_WORDS = 500000;
const int MAX_LETTERS_PER_WORD = 255;
const int LINE = 10000;

void modifyTimeStamp(char *line, char *str, int index)
{
   if (index == -1)
   {
      strcat(str, line);
   }

   else
   {
      char before[255];
      char after[255];
      char modified[20];
      memset(before, '\0', sizeof(before));
      memset(after, '\0', sizeof(after));
      memset(modified, '\0', sizeof(modified));

      strncpy(before, line, index - 2);
      strncpy(after, line + (index - 2), 255 - (index - 2));

      if (strlen(after) < 7)
      {
         strcpy(modified, "00:");
         strcat(modified, after);
         strcat(before, modified);
         strcat(str, before);
      }
      else
      {
         strcat(str, line);
      }
   }
}

int firstCollonIndex(char *str)
{
   const char COLLON = ':';
   char *temp;
   int index;

   temp = strchr(str, COLLON);
   if (temp == NULL)
      return -1;

   index = (int)(temp - str);
   return index;
}

int main()
{
   char str[MAX_CHAR_LENGTH];
   memset(str, '\0', sizeof(str));
   char line[MAX_LETTERS_PER_WORD];
   char arr[LINE][MAX_LETTERS_PER_WORD];
   char fileName[100];

   printf("File Name?: ");
   scanf("%s", fileName);

   FILE *file;
   file = fopen(fileName, "r");

   if (file == NULL)
   {
      printf("No file found");
      return -1;
   }

   while (fgets(line, sizeof(line), file) != NULL)
   {

      int i = firstCollonIndex(line);
      modifyTimeStamp(line, str, i);
   }

   FILE *out;
   out = fopen(strcat(fileName, "_modified"), "w+");
   fputs(str, out);

   fclose(out);
   fclose(file);
   return 0;
}
