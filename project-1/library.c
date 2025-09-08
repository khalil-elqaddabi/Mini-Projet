#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char titre[50];
char auteur[50];
// Q = quontiter
int Q;
// P = prix
float P;
}books ;
books info[100];

int size = 0;
void ajoutre()
{
    int k;
    printf("\n");
    printf("combien du liver : ");
    scanf("%d", &k);
    for (int i = size; i < size + k; i++)
    {
        printf("======================\n");
        printf("---le titre N%d-----", i + 1);
        printf("\n");
        printf("le titre du livre :");
        scanf(" %[^\n]s", info[i].titre);
        printf("le Auteur du livre :");
        scanf(" %[^\n]s", info[i].auteur);
        printf("le Prix du livre :");
        scanf("%f", &info[i].P);
        printf("le Quantite en stock :");
        scanf("%d", &info[i].Q);
        }
    size += k;
}

void afficher()
{
    if (size == 0)
    {
        printf("le stock est vide !\n");
        return;
    }
    printf("lea livres dans le stok est :\n");
    for (int i = 0; i < size; i++)
    {
        printf("----le livre N%d :---\n", i + 1);
        printf("%s\n",info[i].titre);
        printf("%s\n", info[i].auteur);
        printf("%.2f\n",info[i].P);
        printf("%d\n", info[i].Q);
    }
}

void rechercher()
{
    char titre_r[100];
    if (size == 0)
    {
        printf("le stock est vide !\n");
        return;
    }
    printf("le nom de liver : ");
    scanf(" %[^\n]s", titre_r);
    int t = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcasecmp(info[i].titre, titre_r) == 0)
        {
            printf("Ce livre est disponible a la Librairie .\n ");
            t = 1;
        }
    }
    if (!t)
    {
        printf("ce livre n'xessite pas !\n");
    }
}

void modifier()
{
    char titre_r[100];
    if (size == 0)
    {
        printf("le stock est vide !\n");
        return;
    }
    printf("le nom de livre : ");
    scanf(" %[^\n]s", titre_r);
    int t = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcasecmp(info[i].titre, titre_r) == 0)
        {
            printf("la quontiter acuille : %d\n", info[i].Q);
            printf("nouvelle quantite : ");
            scanf("%d", &info[i].Q);

            printf("la quontiter mise a jour .\n");
            t = 1;
        }
    }
    if (!t)
    {
        printf("ce livre n'xessite pas !\n");
    }
}

void supprimer()
{
    char titer_r[100];
    if (size == 0)
    {
        printf("le stock est vide !\n");
        return;
    }
    printf("le nom de liver : ");
    scanf(" %[^\n]s", titer_r);
    int t = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcasecmp(info[i].titre, titer_r) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                info[j]= info[j + 1];
               
            }
            size--;
            printf("le livre est supprimer .\n");
            t = 1;
        }
    }
    if (!t)
    {
        printf("ce livre n'exessite pas !\n");
    }
}

void total()
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += info[i].Q;
    }
    printf("le totale des livres das le stack est : %d .\n", total);
}
