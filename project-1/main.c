#include <stdio.h>
#include "library.h"
int main()
{
    int k;
    printf("Systeme de Gestion de Stock dans une Librairie .\n");
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
    return 0;
}