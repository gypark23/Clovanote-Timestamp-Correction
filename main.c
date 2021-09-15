#include <stdio.h>
#include <string.h>

const int MAX_CHAR_LENGTH = 1000000;
const int MAX_WORDS = 500000;
const int MAX_LETTERS_PER_WORD = 255;
const int LINE = 10000;

int separateString(char* str)
{
   char* token = strtok(str, " ");
   while(token!=NULL)
   {
      printf("%s\n", token);
      token = strtok(NULL, " ");
   }

   return 0;
}


void modifyTimeStamp(char* line, char* str, int index)
{
  
   if(index==-1)
   {
      strcat(str, line);
   }

   else
   {
      char before[255];
      char after[255];
      
      memset(before, '\0', sizeof(before));
      memset(after, '\0', sizeof(after));
      
      //printf("%d\n", '\0'==after[5]);
      strncpy(before, line, index-2);
      strncpy(after, line + (index-2), 255 - (index - 2));
      
      char modified[20];
      memset(modified, '\0', sizeof(modified));

      if(strlen(after) < 10)
      {  
         strcpy(modified, "00:");
         strcat(modified, after);
      }
      strcat(before, modified);
      strcat(str, before);
   }
}

int firstCollonIndex(char *str)
{
   const char COLLON = ':';
   char* temp;
   int index;

   temp = strchr(str, COLLON);
   if(temp==NULL)
      return -1;
   index = (int)(temp - str);
   return index;
}




int main()
{
   
   char str[MAX_CHAR_LENGTH];

   FILE *file;
   file = fopen("test.txt", "r");

   if(file==NULL)
   {
      printf("No file found");
      return -1;
   }
   
   char line[MAX_LETTERS_PER_WORD];
   char arr[LINE][MAX_LETTERS_PER_WORD];
   
   while(fgets(line, sizeof(line), file)!=NULL)
   {
      
      int i = firstCollonIndex(line);
      modifyTimeStamp(line, str, i);
   }

   FILE *out;
   out = fopen("output.txt", "w+");
   fputs(str, out);
   fclose(out);
   fclose(file);

   
   return 0;
}



