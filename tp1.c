#include <stdio.h>
#include <stdlib.h>

struct tp1
{
    int info;
    struct tp1*suivant;
};

typedef struct tp1*liste;

liste inserer_en_tete(int elt, liste Q)
{
    liste p;
    p = (liste)malloc(sizeof(struct tp1));
    p->info = elt;
    p->suivant = Q;
    return p;
}

liste inserer_en_queue(int elt, liste Q)
{
    liste p, tmp;
    tmp = Q;
    p = (liste)malloc(sizeof(struct tp1));
    p->info = elt;
    p->suivant = NULL;
    if (Q == NULL) {return p;}
    while (tmp->suivant != NULL) tmp = tmp->suivant;
    tmp->suivant = p;
    return Q;
}

liste supprimer_tete(liste Q)
{
    liste suivant;
    suivant = Q;
    if (Q != NULL)
    {
        suivant = Q->suivant;
        free(Q);
    }
    return suivant;
}

void afficher_liste(liste Q)
{
    liste tmp;
    tmp = Q;
    while (tmp != NULL)
    {
        printf("%d-> \t", tmp->info);
        tmp = tmp->suivant;
    }
    printf("NULL\n");
}



int main()
{   
    liste Q;
    printf("INSERTION DE 14, 2, 3, ET 10 EN TETE DE LISTE : \n\n");
    Q = inserer_en_tete(14,
    inserer_en_tete(2,
    inserer_en_tete(3,
    inserer_en_tete(10,NULL)
    )));

    printf("IMPRESSION DE LA LISTE CREEE : \n\n ");
    afficher_liste(Q);

    printf("INSERTION DE 130 EN QUEUE DE LISTE PRECEDENTE : \n");
    Q = inserer_en_queue(130, Q);
    printf("IMPRESSION DE LA NOUVELLE LISTE : \n\n ");
    afficher_liste(Q);

    printf("SUPPRESSION DE L'ELEMENT EN TETE DE LISTE : \n\n ");
    Q = supprimer_tete(Q);
    printf("IMPRESSION DE LA NOUVELLE LISTE : \n\n ");
    afficher_liste(Q);
}