#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//INCLUDES
#include <stdio.h>
#include <stdlib.h>

//STRUCTS
typedef struct 
{
    int ID ; 
    char nom[20];
    char prenom[20];
    int niveau ; 
    float moyene;
}etudiant;

struct root
{
    etudiant data;
    struct root *right;
    struct root *left;
};

struct node
{
    etudiant data;
    struct node *next;
    struct node *prec;
};

typedef struct root* abr ; 
typedef struct node* liste ; 

//FUNCTIONS 
abr initialiser (etudiant e );
abr inserer ( abr a , etudiant e );
abr construire_arbre(abr a , char nomFich[]);
void afficher (abr a);
int calculnombre(abr a);
void construire_liste (abr a , liste *l , float BI , float BS );
void backup_data (liste l , char nomFich[]);
void afficher_listeDC(liste l);
void backup_data_BST( abr a , FILE *f);

#endif