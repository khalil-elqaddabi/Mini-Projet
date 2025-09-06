#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char titre[100][50], auteur[100][50];
// Q = quontiter
int Q[100];
// P = prix
float P[100];
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
        scanf(" %[^\n]s", titre[i]);
        printf("le Auteur du livre :");
        scanf(" %[^\n]s", auteur[i]);
        printf("le Prix du livre :");
        scanf("%f", &P[i]);
        printf("le Quantite en stock :");
        scanf("%d", &Q[i]);
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
        printf("%s\n", titre[i]);
        printf("%s\n", auteur[i]);
        printf("%.2f\n", P[i]);
        printf("%d\n", Q[i]);
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
        if (strcmp(titre[i], titre_r) == 0)
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
        if (strcmp(titre[i], titre_r) == 0)
        {
            printf("la quontiter acuille : %d\n", Q[i]);
            printf("nouvelle quantite : ");
            scanf("%d", &Q[i]);

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
        if (strcmp(titre[i], titer_r) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                strcpy(titre[j], titre[j + 1]);
                strcpy(auteur[j], auteur[j + 1]);
                P[j] = P[j + 1];
                Q[j] = Q[j + 1];
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
        total += Q[i];
    }
    printf("le totale des livres das le stack est : %d .\n", total);
}

int main()
{
    int k;
    printf("Système de Gestion de Stock dans une Librairie .\n");
    printf("================================================\n");
    do
    {
        printf("________\n");
        printf("minu :");
        printf("__________________________________________________\n");
        printf("1 : pour Ajouter un livre au stock.\n");
        printf("2 : pour Afficher tous les livres disponibles.\n");
        printf("3 : pour Rechercher un livre par son titre.\n");
        printf("4 : pour Mettre a jour la quantite d'un livre\n");
        printf("5 : pour Supprimer un livre du stock.\n");
        printf("6 : pour Afficher le nombre total de livres en stock.\n");
        printf("7 : pour quittez .\n");
        printf("________________________________________________________\n");
        printf("selectione le choix : ");
        scanf("%d", &k);
        printf("-----------------------\n");
        switch (k)
        {
        case 1:
            ajoutre();
            break;
        case 2:
            afficher();
            break;
        case 3:
            rechercher();
            break;
        case 4:
            modifier();
            break;
        case 5:
            supprimer();
            break;
        case 6:
            total();
            break;
        case 7:
            printf("Au revoir!\n");
            break;
        default:
            printf("les choix invalide !\n");
        }
    } while (k != 7);
}
