#include <stdio.h>
#include <stdlib.h>
#include "types1.h"
#include "fonctions_1.h"
#include <stddef.h.>
#include <string.h>

void associe_structure1 (char *mot, FILE *test)
{
    char carac='b';                                                      /* initialisation de carac à un caractère quelconque pour éviter un souci lors du premier test.*/
    int i=0;
    while (!feof(test) && carac != ',' && carac!='(' && carac!='\"') {   /* Les différents cas d'erreurs rencontrés lors de l'extraction de données.*/
        carac = fgetc(test);
        if (carac!=',' && carac!='(')
            mot[i] = carac;
        i++;

    }
}

void mettre_mot (char *chaine1, char *chaine2)
{
    int i=0;
    do {
        chaine1[i]=chaine2[i];
        i++;
    }while (chaine2[i-1]!='\0');
}

int taille_tab_struct_vol(INFO_VOL tab[70])
{
    int taille=0;
    while (tab[taille].num_vol!=0){
        taille++;
    }
    return taille;
}

int taille_tab_struct_pass(PASSAGERS liste[50])
{
    int taille=0;
    while (liste[taille].place!=0){
        taille++;
    }
    return taille;
}

int taille_chaine(char *chaine)
{
    int taille=0;
    while (chaine[taille]!='\0'){
        taille++;
    }
    return (taille);
}


/*  Fonctionnalité 1  */


void permuter_vol(INFO_VOL *a, INFO_VOL *b)
{
    INFO_VOL tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void tri_rapid_vol(INFO_VOL tab[70], int deb, int fin)
{
    int pivot, i, j;
    if(deb < fin) {
        pivot = deb;
        i = deb;
        j = fin;
        while (i < j) {
            while(tab[i].heure_decollage <= tab[pivot].heure_decollage && i < fin)
                i++;
            while(tab[j].heure_decollage > tab[pivot].heure_decollage)
                j--;
            if(i < j) {
                permuter_vol(&tab[i], &tab[j]);
            }
        }
        permuter_vol(&tab[pivot], &tab[j]);
        tri_rapid_vol(tab, deb, j-1);
        tri_rapid_vol(tab, j+1, fin);
    }
}

int heure_valide (int heure)
{
    int valide=1;
    if (heure <600 || heure > 2200)
        valide = 0;
    else {
        if (heure % 100>=60)
            valide = 0;
    }
    return valide;
}


/*  Fonctionnalité 2  */


void recherche_vol_criteres(INFO_VOL *vol1)
{

    char nom_compagnie[20];
    char destination[20];
    int heure_decollage;
    int i=0;

    printf("\nSi vous ne souhaitez pas remplir la case, saisissez -1 \n");
    printf("\nEntrez la destination recherch%ce (ou -1 sinon) : ",130);
    getchar();
    fgets(destination, 20, stdin);
    destination[strcspn(destination, "\n")] = '\0';
    printf("\nEntrez la compagnie recherch%ce (ou -1 sinon) : ",130);
    fgets(nom_compagnie, 20, stdin);
    destination[strcspn(destination, "\n")] = '\0';
    printf("\nEntrez l'heure de decollage sous le format HHMM (ou -1 sinon): ");
    scanf("%d", &heure_decollage);
    printf("\n Affichage des vols correspondants aux crit%cres saisis sous la forme :\n",138);
    printf("\nHeure_dec | Num_vol | Nom_comp        | Desti    | Num_compt | Heure_deb_enr / Fin | Salle_embar | Heure_deb_emb / Fin | Etat\n");
    printf("============================================================================================================================================\n");
    do{
        /*Vérifie pour chaque vol :
            si la destination saisie est celle du vol OU si la destination saisie est '-1' (non saisie)
            si la compagnie saisie est celle du vol OU si la compagnie saisie est '-1' (non saisie)
            si l'heure est comprise dans l'heure(1h) qui suit l'heure saisie OU si l'heure vaut -1 (non saisie)
        */
        if ((strncmp(destination,"-1",2)==0 || strncmp(destination,vol1[i].destination,strlen(vol1[i].destination))==0) && (strncmp(nom_compagnie,"-1",2)==0 || strncmp(nom_compagnie,vol1[i].nom_compagnie,strlen(vol1[i].nom_compagnie))==0) && (heure_decollage == -1 || heure_decollage<=vol1[i].heure_decollage && vol1[i].heure_decollage<=(heure_decollage+100))){
            printf("%02dh%02d     | %7d | %15s | %8s | %9d |    %02dh%02d / %02dh%02d    | %11d |    %02dh%02d / %02dh%02d    | %s (%02d min)\n",vol1[i].heure_decollage/100,vol1[i].heure_decollage%100,vol1[i].num_vol,vol1[i].nom_compagnie,vol1[i].destination,vol1[i].num_comptoir,vol1[i].heure_debut_comptoire/100,vol1[i].heure_debut_comptoire%100,vol1[i].heure_fin_comptoire/100,vol1[i].heure_fin_comptoire%100,vol1[i].num_salle_embarquement,vol1[i].heure_debut_embarquement/100,vol1[i].heure_debut_embarquement%100,vol1[i].heure_fin_embarquement/100,vol1[i].heure_fin_embarquement%100,vol1[i].etat_vol.etat,vol1[i].etat_vol.retard);
        }
        i++;
    }while (vol1[i].num_vol!=0);
}


/*  Fonctionnalité 3  */


void permuter(PASSAGERS *a, PASSAGERS *b)
{
    PASSAGERS tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void tri_rapid(PASSAGERS liste[50], int deb, int fin)
{
    int pivot, i, j;
    if(deb < fin) {
        pivot = deb;
        i = deb;
        j = fin;
        while (i < j) {
            while(liste[i].prix_bil <= liste[pivot].prix_bil && i < fin)
                i++;
            while(liste[j].prix_bil > liste[pivot].prix_bil)
                j--;
            if(i < j) {
                permuter(&liste[i], &liste[j]);
            }
        }
        permuter(&liste[pivot], &liste[j]);
        tri_rapid(liste, deb, j-1);
        tri_rapid(liste, j+1, fin);
    }
}

void inverse(PASSAGERS liste[50],int deb,int fin)
{
    int ideb = deb;
    int ifin = fin;
    PASSAGERS pivot;
    while (ideb<ifin){
        pivot=liste[ideb];
        liste[ideb]= liste[ifin];
        liste[ifin]=pivot;
        ideb++;
        ifin--;
    }
}

void inverser_pass (PASSAGERS liste[50], int ind)
{
    PASSAGERS pivot;
    int i=0;
    /* on cherche les premières lettres des deux noms qui sont différentes, puis on les compare.*/
    while (liste[ind].nom[i]==liste[ind+1].nom[i]){
        i++;
    }
    if (i <= taille_chaine(liste[ind].nom)){  /* Si cette condition n'est pas satisfaite, cela veut dire que aucun passager ne dispose du même prix.*/
        if (liste[ind].nom[i] > liste[ind+1].nom[i]){
            pivot = liste[ind+1];
            liste[ind+1] = liste[ind];
            liste[ind] = pivot;
        }
    }
}

void fonctionallite_3(PASSAGERS liste[50])
{
    PASSAGERS pivot;
    int nb_pass= taille_tab_struct_pass(liste);
    int j=0;
    for (int i=0;i<nb_pass;i++){
        if (2024-liste[i].naiss.annee<=12){
            pivot = liste[i];
            liste[i]=liste[j];
            liste[j]=pivot;
            j++;
        }
    }
    /*Création d'un "sous-tableau" d'indice final j-1 contenant uniquement les passagers plus petits que 12ans.*/
    tri_rapid(liste,0,j-1);
    tri_rapid(liste,j,nb_pass-1);
    /* On a convenu du parti pris que tous les passagers devaient être classés par prix décroissants, donc on inverse chaques parties du tableau.*/
    inverse(liste,0,j-1);
    inverse(liste,j,nb_pass-1);
    int i=0;
    /*On traite ici le cas où deux passagers ont le même prix de billet. */
    do{
        if (liste[i].prix_bil==liste[i+1].prix_bil){
            inverser_pass(liste,i);
        }
        i++;
    }while (liste[i].place!=0);


}


/*  Fonctionnalité 4  */


int change_heure (int heure, int retard)
{
    if (heure % 100 + retard>=60) /* on regarde la somme des minutes (heure%100 représente le MM de HHMM)*/
        heure = heure + retard + 40;
    else
        heure = heure + retard;
    return heure;
}

int recherche (int num_vol, INFO_VOL tab_vols[70])
{
    int indice=0;
    while (num_vol!=tab_vols[indice].num_vol){ /*On recherche l'indice du vol dans le tableau tab_vols à partir de son numéro.*/
        indice++;
    }
    return indice;
}

void insertion_vol_retade (INFO_VOL vol_retarde, INFO_VOL tab_vol_trie[70])
{
    int i=0;
    int j;
    int tmp;
    vol_retarde.heure_decollage = change_heure(vol_retarde.heure_decollage, vol_retarde.etat_vol.retard);
    /* On ajoute le retard du vol à son heure de décollage.*/
    tri_rapid_vol(tab_vol_trie,0,taille_tab_struct_vol(tab_vol_trie)-1);
    if (vol_retarde.heure_decollage > 2200){ /* On traite ici le cas où le retard du vol dépasse 22h. */
        mettre_mot(vol_retarde.etat_vol.etat, "Annule");
        vol_retarde.etat_vol.retard=-1;
    }
    else{
        do {
            i++;
        }while (tab_vol_trie[i].heure_decollage+5<vol_retarde.heure_decollage);
        /* On se place ici au premier écart de vols entre lesquels le vol peut se placer.*/
        do {
            if (tab_vol_trie[i+1].heure_decollage/100 == tab_vol_trie[i].heure_decollage/100){
                /* On taitera dans cette condition les cas où les vols adjacents sont dans la même tranche d'heure.*/
                if (((tab_vol_trie[i+1].heure_decollage - tab_vol_trie[i].heure_decollage) >= 10)){
                    /* Cette condition vérifie que l'écart entre les deux vols et suffisant pour placer notre vol retardé*/
                    vol_retarde.heure_decollage = tab_vol_trie[i].heure_decollage + 5;
                    mettre_mot(vol_retarde.etat_vol.etat, "A l'heure");
                    vol_retarde.etat_vol.retard = 0;
                    /*On décale de 1 tous les autres vols depuis la fin du tableau, donc le tableau gagne 1 élément puis
                    on insère le vol retardé à sa place*/
                    for (j=taille_tab_struct_vol(tab_vol_trie);j>i;j--){
                        tab_vol_trie[j]=tab_vol_trie[j-1];
                    }
                    tab_vol_trie[i] = vol_retarde;
                    break;
                }
            }
            else{
                /* Comme on va devoir modifier l'heure de décollage du vol suivant, pour pouvoir faire la différence,
                il faut créer une variable qui stocke cette valeur, tmp.*/
                tmp = tab_vol_trie[i+1].heure_decollage;
                do{
                    tmp = tmp - 40;
                }while (tmp/100 != tab_vol_trie[i].heure_decollage/100); /*Cette boucle traite le cas où les vols sont espacés de plusieures heures.*/
                /*A partir de là, c'est le même schéma qui plus haut.*/
                if ((tmp - tab_vol_trie[i].heure_decollage) >= 10){
                    vol_retarde.heure_decollage = tab_vol_trie[i].heure_decollage + 5;
                    mettre_mot(vol_retarde.etat_vol.etat, "A l'heure");
                    vol_retarde.etat_vol.retard = 0;
                    /*Seule différence, il faut traiter le cas ou la nouvelle heure dépasse 60 minutes.*/
                    if (vol_retarde.heure_decollage % 100 >= 60)
                        vol_retarde.heure_decollage = vol_retarde.heure_decollage + 40;

                    for (j=taille_tab_struct_vol(tab_vol_trie);j>i;j--){
                        tab_vol_trie[j]=tab_vol_trie[j-1];
                    }
                    tab_vol_trie[i] = vol_retarde;
                    break;
                }
            }
            i++;
        }while (vol_retarde.etat_vol.retard!=0 || vol_retarde.etat_vol.retard!=-1);
    }
}

void remplissage_tableau_fonct_4 (INFO_VOL tab_vol[70], INFO_VOL tab_vol_retarde[70])
{
    tri_rapid_vol(tab_vol,0,taille_tab_struct_vol(tab_vol)-1);
    int i=0,j=0; /* j nous servira à parcourir le tableau tab_vol_retarde, et i le tableau tab_vol.*/
    /* On stocke dans le tableau tab_vol_retarde tous les vols non-retardés*/
    do {
        if (tab_vol[i].etat_vol.etat[0]!='R'){
            tab_vol_retarde[j]=tab_vol[i];
            j++;
        }
        i++;
    }while (tab_vol[i].num_vol!=0);
    i=0;
    tri_rapid_vol(tab_vol_retarde,0,taille_tab_struct_vol(tab_vol_retarde)-1);
    do {
        if (tab_vol[i].etat_vol.etat[0]=='R'){
            insertion_vol_retade(tab_vol[i], tab_vol_retarde);
            /*On insère directemement à la bonne place le vol détecté comme retardé.*/
        }
        i++;
    }while (tab_vol[i].num_vol!=0);
}




/*
void fonctionallite_4 (int ind, INFO_VOL tab_vols[50])
{
    int retard = tab_vols[ind].etat_vol.retard;
    int new_heure_deco = change_heure(tab_vols[ind].heure_decollage, retard);
    int tmp;
    printf("%s\n",tab_vols[ind].nom_compagnie);

    int i=0;

    if (new_heure_deco > 2200){
        tab_vols[ind].etat_vol.etat[10]="Annule";
        tab_vols[ind].etat_vol.retard=0;
    }
    else{
        do {
            i++;
        }while (tab_vols[i].heure_decollage+5<new_heure_deco);
        do{

            if (tab_vols[i+1].heure_decollage/100 == tab_vols[i].heure_decollage/100){
                if (((tab_vols[i+1].heure_decollage-tab_vols[i].heure_decollage)>=10)){
                    new_heure_deco = tab_vols[i].heure_decollage + 5;
                    if (new_heure_deco%100>60)
                        new_heure_deco=new_heure_deco+40;
                    tab_vols[ind].heure_decollage=new_heure_deco;
                    tab_vols[ind].etat_vol.retard=-1;
                    break;
                }
            }
            else {
                tmp = tab_vols[i+1].heure_decollage;

                do{
                    tmp = tmp - 40;
                }while (tmp/100 != tab_vols[i].heure_decollage/100);
                if ((tmp - tab_vols[i].heure_decollage)>=10){

                    new_heure_deco = tab_vols[i].heure_decollage + 5;
                    if (new_heure_deco%100>60)
                        new_heure_deco=new_heure_deco+40;
                    tab_vols[ind].heure_decollage=new_heure_deco;
                    tab_vols[ind].etat_vol.retard=-1;
                    break;
                }
            }
            i++;

        }while(tab_vols[i].heure_decollage + 5 < 2200 && tab_vols[i].num_vol!=0);
    }
}
*/



/*
void fonctionallite_4 (INFO_VOL vol_retarde, INFO_VOL tab_vols[50])
{
    int retard = vol_retarde.etat_vol.retard;
    int new_heure_deco = change_heure(vol_retarde.heure_decollage, retard);

    int tmp;
    tri_rapid_vol(tab_vols,0,40);
    int i=0;
    if (new_heure_deco > 2200){
        vol_retarde.etat_vol.etat[10]="Annule";
        vol_retarde.etat_vol.retard=0;
    }
    else{
        do {
            i++;
        }while (tab_vols[i].heure_decollage+5<new_heure_deco);
        do{

            if (tab_vols[i+1].heure_decollage/100 == tab_vols[i].heure_decollage/100){
                printf("%d\n",new_heure_deco);
                if (((tab_vols[i+1].heure_decollage-tab_vols[i].heure_decollage)>=10)){
                    new_heure_deco = tab_vols[i].heure_decollage + 5;
                    if (new_heure_deco%100>60)
                        new_heure_deco=new_heure_deco+40;
                    vol_retarde.heure_decollage=new_heure_deco;

                    vol_retarde.etat_vol.etat[10]="A l'heure";
                    vol_retarde.etat_vol.retard=0;
                    printf("%d\n",vol_retarde.heure_decollage);
                    break;
                }
            }
            else {
                tmp = tab_vols[i+1].heure_decollage;
                do{
                    tmp = tmp - 40;
                }while (tmp/100 != tab_vols[i].heure_decollage/100);
                if ((tmp - tab_vols[i].heure_decollage)>=10){
                    new_heure_deco = tab_vols[i].heure_decollage + 5;
                    if (new_heure_deco%100>60)
                        new_heure_deco=new_heure_deco+40;
                    vol_retarde.heure_decollage=new_heure_deco;
                    vol_retarde.etat_vol.etat[10]="A l'heure";
                    vol_retarde.etat_vol.retard=0;
                    break;
                }
            }
            i++;

        }while(tab_vols[i].heure_decollage + 5 < 2200 && tab_vols[i].num_vol!=0);
    }


}*/



