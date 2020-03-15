#include <stdio.h>
#include <iostream>

const int n = 250000;
const int m = ((10 * n) / 3);

int main (void){

    int n;    
    std::cout << "Digite la cantidad de digitos de PI que quiere mostrar: ";
    std::cin >> n;    
    int resto, digant, nueves, aux;
    int pi [m + 1];

    for (int i=1;i<= m;i++) pi[i]=2;
    nueves=0; digant=0;
    for (int i=1;i<=n;i++)
    {
        resto=0;
        for (int j= m;j>=1;j--)
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
             for (int k=1;k<=nueves;k++) printf("0");
             digant=0;
             nueves=0;
        }
        else
        {
            printf("%i",digant);
            digant=resto;
            if (nueves!=0)
            {
                for(int k=1;k<=nueves;k++) printf("9");
                nueves=0;
            }
        }
    }
    scanf_s("%i",digant);
    system("pause");
}