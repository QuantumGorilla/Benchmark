#include <stdio.h>

const int n=250000;
const int dim=((10*n)/3);
int i,j,k, resto, digant, nueves, aux;
int pi[dim+1];

int main (void)
{
    for (i=1;i<=dim;i++) pi[i]=2;
    nueves=0; digant=0;
    for (i=1;i<=n;i++)
    {
        resto=0;
        for (j=dim;j>=1;j--)
        {
            aux=10*pi[j]+resto*j;
            pi[j]=aux % (2*j-1);
            resto=aux/(2*j-1);
        }
        pi[1]=resto % 10;
        resto=resto/10;
        if (resto==9) nueves++;
        else if (resto==10)
        {
             printf("%i",digant);
             for (k=1;k<=nueves;k++) printf("0");
             digant=0;
             nueves=0;
        }
        else
        {
            printf("%i",digant);
            digant=resto;
            if (nueves!=0)
            {
                for(k=1;k<=nueves;k++) printf("9");
                nueves=0;
            }
        }
    }
    printf("%i",digant);
    scanf("%i");
}