#ifndef TYPES1_H_INCLUDED
#define TYPES1_H_INCLUDED

typedef struct {
    int jour;
    int mois;
    int annee;
} DATE_N;

typedef struct {
    char nom[10];
    char prenom[10];
    DATE_N naiss;
    int place;
    float prix_bil;
}PASSAGERS;

typedef struct {
    char etat[10];
    int retard;
}ETAT_VOL;


typedef struct {
    int num_vol;
    char nom_compagnie[20];
    char destination[30];
    int num_comptoir;
    int heure_debut_comptoire;
    int heure_fin_comptoire;
    int num_salle_embarquement;
    int heure_debut_embarquement;
    int heure_fin_embarquement;
    int heure_decollage;
    ETAT_VOL etat_vol;
    PASSAGERS liste[50];
}INFO_VOL;

#endif // TYPES1_H_INCLUDED
