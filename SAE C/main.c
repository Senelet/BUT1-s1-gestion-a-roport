#include <stdio.h>
#include <stdlib.h>
#include "types1.h"
#include "fonctions_1.h"
#include <stddef.h.>
#include <string.h>


int main()
{
    char en_tete[1000];
    INFO_VOL vol1[70];  /* Tableau utilisé pour l'extraction de données, il stockera les informations de tous les vols.*/
    INFO_VOL vol_retardes[70];  /* Tableau utilisé pour la fonctionnalité 4 qui stockera les vols de vol1 mais en prenant les retards en compte.*/
    int j=0;
    int i=0;
    int l=0;
    char cpt;   /* Variable utilisée pour l'extraction de données, afin d'avancer le curseur de 1.*/
    int fonct;  /* Variable utilisée pour le switch, afin de savoir quelle fonctionnalité est demandée par l'utilisateur.*/
    int heure=0; /* variable utilisée pour stocker l'heure saisie dans la fonctionnalité 1*/
    int vol_cible; /* variable utilisée pour stocker le numéro de vol recherché dans la fonctionnalité 3*/
    FILE * fic = fopen("data_vols.csv","r");
    if (fic==NULL){
        printf("fichier non ouvrable");
        exit(EXIT_FAILURE);
    }
    fgets(en_tete,1000,fic);
    do {

        fscanf(fic,"%d,",&vol1[j].num_vol);
        associe_structure1(vol1[j].nom_compagnie,fic);
        associe_structure1(vol1[j].destination,fic);
        fscanf(fic,"%d,",&vol1[j].num_comptoir);
        fscanf(fic,"%d,",&vol1[j].heure_debut_comptoire);
        fscanf(fic,"%d,",&vol1[j].heure_fin_comptoire);
        fscanf(fic,"%d,",&vol1[j].num_salle_embarquement);
        fscanf(fic,"%d,",&vol1[j].heure_debut_embarquement);
        fscanf(fic,"%d,",&vol1[j].heure_fin_embarquement);
        fscanf(fic,"%d,",&vol1[j].heure_decollage);
        associe_structure1(vol1[j].etat_vol.etat,fic);
        l=0;
        while(vol1[j].etat_vol.etat[l]!='\0'){
            l++;
        }
        if (l == 8){
            fscanf(fic,"%d min),",&vol1[j].etat_vol.retard);

        }
        else{
            if (l == 6){
                vol1[j].etat_vol.retard=-1;

            }
            else{
                vol1[j].etat_vol.retard=0;
            }
        }
        cpt=fgetc(fic);
        i=0;
        do{
            associe_structure1(vol1[j].liste[i].nom,fic);
            associe_structure1(vol1[j].liste[i].prenom,fic);
            fscanf(fic,"%02d/",&vol1[j].liste[i].naiss.jour);
            fscanf(fic,"%02d/",&vol1[j].liste[i].naiss.mois);
            fscanf(fic,"%04d,",&vol1[j].liste[i].naiss.annee);
            fscanf(fic,"%d,",&vol1[j].liste[i].place);
            fscanf(fic,"%f",&vol1[j].liste[i].prix_bil);
            cpt = fgetc(fic);
            i++;
        }while (cpt!='\"' && !feof(fic));
        vol1[j].liste[i].place=0; /* création d'une condition d'arrêt pour le parcours de la liste des passagers*/
        j++;

    }while (!feof(fic));
    vol1[j+1].num_vol=0; /* création d'une condition d'arrêt pour le parcours du tableau vol1*/

    do{
        printf("\nS%clectionner la fonctionnalit%c voulue : \n =======================================\n 1-Affichage des vols %c moins de 3h. \n =======================================\n 2-Recherche d'un vol par crit%cres.\n =======================================\n 3-Affichage de la liste d'un passager du vol cibl%c.\n =======================================\n 4-Gestion des vols retard%cs.\n =======================================\n 0-Quitter.\n",130,130,133,138,130,130);
        printf("\nFonctionnalit%c voulue :",130);
        scanf("%d",&fonct);
        switch (fonct){
            case 1: printf("\n");
                    do{
                        printf("Saisissez une heure comprise en 6h et 22h, sous le format HHMM : ");
                        scanf("%d",&heure);
                    }while(heure_valide(heure)==0 && (heure <600 || heure > 2200));
                    int i=0;
                    tri_rapid_vol(vol1,0,taille_tab_struct_vol(vol1)-1);

                    printf("Heure_dec | Num_vol | Nom_comp        | Desti    | Num_compt | Heure_deb_enr / Fin | Salle_embar | Heure_deb_emb / Fin | Etat\n");
                    printf("============================================================================================================================================\n");
                    do{
                        /*Affichage des informations des vols uniquement si ils sont à moins de 3h de l'heure saisie.*/
                        if (vol1[i].heure_decollage<=heure+300 && vol1[i].heure_decollage>=heure){
                            printf("%02dh%02d     | %7d | %15s | %8s | %9d |    %02dh%02d / %02dh%02d    | %11d |    %02dh%02d / %02dh%02d    | %s (%02d min)\n",vol1[i].heure_decollage/100,vol1[i].heure_decollage%100,vol1[i].num_vol,vol1[i].nom_compagnie,vol1[i].destination,vol1[i].num_comptoir,vol1[i].heure_debut_comptoire/100,vol1[i].heure_debut_comptoire%100,vol1[i].heure_fin_comptoire/100,vol1[i].heure_fin_comptoire%100,vol1[i].num_salle_embarquement,vol1[i].heure_debut_embarquement/100,vol1[i].heure_debut_embarquement%100,vol1[i].heure_fin_embarquement/100,vol1[i].heure_fin_embarquement%100,vol1[i].etat_vol.etat,vol1[i].etat_vol.retard);
                        }
                        i++;
                    }while(vol1[i].heure_decollage<=heure+300);
                     printf("\n");
                    break;

            case 2: recherche_vol_criteres(vol1);
                    break;
            case 3:
                    printf("\n");
                    do{
                        printf("Saisissez le num%cro de vol dont vous voulez afficher la liste des passasgers (compris entre 1 et 40) :",130);
                        scanf("%d",&vol_cible);
                    }while(vol_cible<1 || vol_cible>taille_tab_struct_vol(vol1));
                    i=0;
                    while(vol1[i].num_vol!=vol_cible){   /* Recherche du numéro de vol recherché par l'utilisateur */
                        i++;
                    }
                    fonctionallite_3(vol1[i].liste); /* fonctionallite_3 modifie le tableau vol1[i].liste pour pouvoir correctement l'afficher.*/
                    printf("NOM \t|\t Prenom \t|\t Date de naissance \t|\t Place \t|\t Prix du billet\n");
                    printf("===============================================================================================================\n");
                    int k=0;
                    do{
                        printf("%s \t|\t %s \t|\t   %d/%d/%d        \t|\t %d \t|\t %.2f \n", vol1[i].liste[k].nom,vol1[i].liste[k].prenom,vol1[i].liste[k].naiss.jour,vol1[i].liste[k].naiss.mois,vol1[i].liste[k].naiss.annee,vol1[i].liste[k].place,vol1[i].liste[k].prix_bil,128);
                        k++;
                    }while(vol1[i].liste[k].prix_bil!=0);
                    printf("\n");
                    break;
            case 4: tri_rapid_vol(vol1,0,taille_tab_struct_vol(vol1)-1);
                    printf("\n Voici la liste des vols retard%cs : ",130);
                    i=0;
                    do{
                        if (vol1[i].etat_vol.etat[0]=='R')
                            printf("|  %d  |",vol1[i].num_vol);
                        i++;
                    }while (vol1[i].num_vol!=0);
                    printf("\n\n");
                    remplissage_tableau_fonct_4(vol1,vol_retardes); /* On appelle ici la fonction remplissage_tableau_fonct_4 pour
                                                                    stocker les vols de vol1 dans vol_retardes mais en prenant
                                                                    les retards en compte.*/
                    i=0;
                    do{
                        if (vol1[i].etat_vol.etat[0]=='R'){   /*On repère les vols anciennement retardés.*/
                            j=0;
                            do{
                                j++;
                            }while (vol_retardes[j].num_vol != vol1[i].num_vol); /*On recherche ces vols dans vol_retardes,
                                                                                 puis on affiche les déplacements d'heures.*/
                            if (vol_retardes[j].etat_vol.retard == 0 ){
                                printf("Le vol num%cro %d, initialement pr%cvu a %02dh%02d, a %ct%c d%ccal%c a %02dh%02d.\n",130,vol_retardes[j].num_vol,130,vol1[i].heure_decollage/100,vol1[i].heure_decollage%100,130,130,130,130,vol_retardes[j].heure_decollage/100,vol_retardes[j].heure_decollage%100);
                            }
                            else{
                                printf("Le vol num%cro %d, initialement pr%cvu a %02dh%02d, a %ct%c annul%c.\n",130,vol_retardes[j].num_vol,130,vol1[i].heure_decollage/100,vol1[i].heure_decollage%100,130,130,130);
                            }

                        }
                        i++;

                    }while (vol_retardes[i].num_vol!=0);
        }
    }while(fonct!=0);
    fclose(fic);

    return 0;
}
