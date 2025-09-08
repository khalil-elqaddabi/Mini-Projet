#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char titre[50];
    char auteur[50];
    char isbn[20];
    // Q = quontiter
    int Q;
    // P = prix
    float P;
} books;
books info[100];

int size = 0;
void bublle()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcasecmp(info[i].titre, info[j].titre) > 0)
            {
                books tmp = info[i];
                info[i] = info[j];
                info[j] = tmp;
            }
        }
    }
}
int binary(char titre[100] ){
    int left=0,right=size-1;
    while(left <=right){
        int mid =(left +right)/2;
        int cmp = strcasecmp(info[mid].titre,titre);
        if(cmp==0)
        return mid;
        else if (cmp<0)
        left =mid +1;
        else
        right =mid-1;
    }
    return -1;
}
int r_isbn(char isbn_r[20]){
    for(int i = 0 ;i <size;i++){
        if(strcasecmp(info[i].isbn,isbn_r)==0)
        return i;
    }
    return -1;
}
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
        printf("isbn du livre : ");
        scanf(" %[^\n]s",info[i].isbn);
        printf("le Prix du livre :");
        scanf("%f", &info[i].P);
        printf("le Quantite en stock :");
        scanf("%d", &info[i].Q);
    }
    size += k;
    bublle();
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
        printf("%s\n", info[i].titre);
        printf("%s\n", info[i].auteur);
        printf("%.2f\n", info[i].P);
        printf("%d\n", info[i].Q);
    }
}

void rechercher_t()
{
    char titre_r[100];
    if (size == 0)
    {
        printf("le stock est vide !\n");
        return;
    }
    printf("le nom de liver : ");
    scanf(" %[^\n]s", titre_r);
    int pos = binary(titre_r);
    if(pos!=-1)
    printf("livre trouve\n");
        
    
    else
    {
        printf("ce livre n'xessite pas !\n");
    }
}
int rechercher_isbn(){
    char isbn_r[20];
    if(size ==0){
        printf("le stoch est vide \n");
        return 0;
    }
    printf("le isbn du livre qui rechercher : ");
    scanf(" %[^\n]s",isbn_r);
    int pos = r_isbn(isbn_r);
    if(pos!=-1){
        printf("le livre est exeste\n");
    }
    else
    printf("le livre n-est pas exeste\n");
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
   int pos = binary(titre_r);
   if(pos !=-1)
        {
            printf("la quontiter acuille : %d\n", info[pos].Q);
            printf("nouvelle quantite : ");
            scanf("%d", &info[pos].Q);

            printf("la quontiter mise a jour .\n");
            
        }
    
    else
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
    int pos =binary(titer_r);
    if(pos!=-1)
    {
       
        
            for (int i=pos; i < size - 1; i++)
            {
                info[i] = info[i + 1];
            }
            size--;
            printf("le livre est supprimer .\n");
            
        
    }
    else
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
        printf("7 : pour Rechercher un livre par son isbn.\n ");
        printf("8 : pour quittez .\n");
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
            rechercher_t();
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
        case 7 :
            rechercher_isbn();
            break;
        case 8:
            printf("Au revoir!\n");
            break;
        default:
            printf("les choix invalide !\n");
        }
    } while (k != 8);
    return 0;
}
