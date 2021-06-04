#include "header.h"

int main()
{
    abr a = NULL ;
    etudiant e ;
    int choix ; 
    liste l = NULL ;
    FILE *f ;

    do
    {
        do
        {
            printf("\n1.Insere etudiant ");
            printf("\n2.construire arbre (fichier) ");
            printf("\n3.Afficher ( decroissant ) ");
            printf("\n4.calculer nombre etudiant");
            printf("\n5.construire liste DC");
            printf("\n6.Backup data");
            printf("\n7.Backup data(BST)");
            printf("\n0.QUITTER");
            printf("\nTapez votre choix = ");
            scanf("%d",&choix); 
            } while (choix < 0 || choix > 7);
            switch (choix)
            {
            case 1 :
                printf("\n ID = ");
                scanf("%d",&e.ID);
                printf("\nnom = ");
                fflush(stdin);
                gets(e.nom);
                printf("\nprenom = ");
                fflush(stdin);
                gets(e.prenom);
                printf("\nniveau = ");
                scanf("%d",&e.niveau);
                printf("\n moyene = ");
                scanf("%f",&e.moyene);
                a = inserer(a , e);
                break;

                case 2 : 
                a = construire_arbre(a , "backup.txt");
                break ; 

                case 3 : 
                afficher(a);
                break ;

                case 4 : 
                printf("\n nbr nodes = %d " , calculnombre(a));
                break;

                case 5 : 
                construire_liste(a , &l , 10 , 14.99 );
                afficher_listeDC(l);
                break;

                case 6 : 
                backup_data(l , "backup.txt");
                break;

                case 7 : 
                f = fopen("backup.txt" , "w+");
                backup_data_BST(a ,f );
                fclose(f);
                break;

            default:
                break;
            }
        
        
    } while (choix != 0);

    return 0 ; 

    
}