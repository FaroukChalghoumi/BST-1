#include "header.h"

abr initialiser (etudiant e )
{
    abr a ;
    a = (struct root*)malloc(sizeof(struct root));
    a->data = e ;
    a->left = a->right = NULL;
    return a;
}

abr inserer ( abr a , etudiant e )
{
    if ( a == NULL)
        {
            
            a = initialiser (e);

            return a ;
        }
        else
         {
            if (e.moyene > a->data.moyene)
                a->right = inserer(a->right , e );
                else 
                a->left = inserer(a->left , e);

                return a;
        }
}

abr construire_arbre(abr a , char nomFich[])
{
    FILE *f=NULL ;
    etudiant e;
    f = fopen(nomFich , "r");
    if ( f == NULL )
        return NULL ; 
        else 
        {
            while ( !feof(f) )
            {
                fscanf(f , "%d\t%s\t%s\t%d\t%f\n",&e.ID,e.nom,e.prenom,&e.niveau,&e.moyene);
                a = inserer(a , e);
            }
            fclose(f);
            return a;
        }

}

void afficher (abr a)
{
    if ( a != NULL )
     {
            afficher(a->left);
            printf("\n->%d\t\t%f",a->data.ID , a->data.moyene );
            afficher(a->right);
    }
}

int calculnombre(abr a)
{
    if ( a != NULL )
    {
        return 1 + calculnombre(a->left) + calculnombre(a->right);
    }
    else
    return 0 ;
}

void construire_liste (abr a , liste *l , float BI , float BS )
{
    if ( a != NULL )
    {
        
        if ( (a->data.moyene >= BI) && ( a->data.moyene < BS))
            {
                struct node *nov;
                nov= malloc ( sizeof ( struct node));
                if ( (*l) == NULL )
                    {
                        nov->next = nov->prec = NULL ;
                    }
                else
                {
                    nov->prec = NULL ; 
                    nov->next = (*l);
                    printf("\n%d\t\t%f",(*l)->data.ID ,(*l)->data.moyene );
                }
                 //printf("\n->%d\t\t%f",(*l)->data.ID ,(*l)->data.moyene );
                nov->data = a->data ;
                 printf("\n NOV = %d\t\t%f",nov->data.ID , nov->data.moyene );
                (*l) = nov ;
                
                
            }
        construire_liste ( a->left , l , BI  , BS  );
        construire_liste ( a->right , l , BI  , BS );
    }
    else return;
}

void backup_data (liste l , char nomFich[])
{
    FILE *f ; 
    f = fopen(nomFich,"w+");
    struct node *supp ;
    while (l != NULL )
    {
        supp = l ; 
        fprintf(f,"%d\t%s\t%s\t%d\t%f\n",l->data.ID ,l->data.nom , l->data.prenom , l->data.niveau , l->data.moyene);
        l = l->next ;
        if ( l != NULL)
        l->prec = NULL ;
        free(supp);
    }
    fclose(f);
    
}

void afficher_listeDC(liste l)
{
    if ( l == NULL )
        printf("\n liste vide ");
        else 
        {
            liste ptr ; 
            ptr = l ;
            while ( ptr )
            {
                 printf("\n->%d\t\t%f",ptr->data.ID , ptr->data.moyene );
                 ptr = ptr->next ; 
            }
        }
}

void backup_data_BST( abr a , FILE *f)
{

    if (a)
    {
        fprintf(f,"\n%d\t%s\t%s\t%d\t%f",a->data.ID ,a->data.nom , a->data.prenom , a->data.niveau , a->data.moyene);
        backup_data_BST(a->left , f);
        backup_data_BST(a->right , f);
    }
    
}


    
abr minValueNode(abr node)
{
abr current = node;
/* loop down to find the leftmost leaf */
while (current->left != NULL)
current = current->left;
return current;
}

/* Function to delete the given node */
abr delete_node(abr a, int data)
{
if (a == NULL)
return a;
// If the key to be deleted is smaller than the a's key,
if (data < a->data)
a->left = delete_node(a->left, data);
// If the key to be deleted is greater than the a's key,
else if (data > a->data)
a->right = delete_node(a->right, data);
else
{
// node with only one child or no child
if (a->left == NULL)
{
abr temp = a->right;
free(a);
return temp;
}
else if (a->right == NULL)
{
abr temp = a->left;
free(a);
return temp;
}
// node with two children:
abr temp = minValueNode(a->right);
// Copy the inorder successor's content to this node
a->data = temp->data;
// Delete the inorder successor
a->right = delete_node(a->right, temp->data);
}
return a;
}

}

