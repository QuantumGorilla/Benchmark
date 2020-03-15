#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void archive5MB(){
   const int FILE_SIZE = 5000; //size in KB
   const int BUFFER_SIZE = 1024;
   char buffer [BUFFER_SIZE + 1];
   int i;
   for(i = 0; i < BUFFER_SIZE; i++)
      buffer[i] = (char)(i%8 + 'a');
   buffer[BUFFER_SIZE] = '\0';

   FILE *pFile = fopen ("5MB.txt", "w");
   for (i = 0; i < FILE_SIZE; i++)
     fprintf(pFile, buffer);

   fclose(pFile);

}

void archive10MB(){
   const int FILE_SIZE = 10000; //size in KB
   const int BUFFER_SIZE = 1024;
   char buffer [BUFFER_SIZE + 1];
   int i;
   for(i = 0; i < BUFFER_SIZE; i++)
      buffer[i] = (char)(i%8 + 'a');
   buffer[BUFFER_SIZE] = '\0';

   FILE *pFile = fopen ("10MB.txt", "w");
   for (i = 0; i < FILE_SIZE; i++)
     fprintf(pFile, buffer);

   fclose(pFile);
}

void archive100MB(){
   const int FILE_SIZE = 100000; //size in KB
   const int BUFFER_SIZE = 1024;
   char buffer [BUFFER_SIZE + 1];
   int i;
   for(i = 0; i < BUFFER_SIZE; i++)
      buffer[i] = (char)(i%8 + 'a');
   buffer[BUFFER_SIZE] = '\0';

   FILE *pFile = fopen ("100MB.txt", "w");
   for (i = 0; i < FILE_SIZE; i++)
     fprintf(pFile, buffer);

   fclose(pFile);
}

void archive500MB(){
   const int FILE_SIZE = 500000; //size in KB
   const int BUFFER_SIZE = 1024;
   char buffer [BUFFER_SIZE + 1];
   int i;
   for(i = 0; i < BUFFER_SIZE; i++)
      buffer[i] = (char)(i%8 + 'a');
   buffer[BUFFER_SIZE] = '\0';

   FILE *pFile = fopen ("500MB.txt", "w");
   for (i = 0; i < FILE_SIZE; i++)
     fprintf(pFile, buffer);

   fclose(pFile);
}

void archive1000MB(){
   const int FILE_SIZE = 1000000; //size in KB
   const int BUFFER_SIZE = 1024;
   char buffer [BUFFER_SIZE + 1];
   int i;
   for(i = 0; i < BUFFER_SIZE; i++)
      buffer[i] = (char)(i%8 + 'a');
   buffer[BUFFER_SIZE] = '\0';

   FILE *pFile = fopen ("1000MB.txt", "w");
   for (i = 0; i < FILE_SIZE; i++)
     fprintf(pFile, buffer);

   fclose(pFile);
}

int main ()
{
	printf("Generando archivo de 5MB...\n");
   archive5MB();
   printf("Generando archivo de 10MB...\n");
   archive10MB();
   printf("Generando archivo de 100MB...\n");
   archive100MB();
   printf("Generando archivo de 500MB...\n");
   archive500MB();
   printf("Generando archivo de 1000MB...\n");
   archive1000MB();
   printf("Archivos generados exitosamente.\n");
   system("pause");
   return 0;
}
