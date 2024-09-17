#ifndef FONCTIONS_1_H_INCLUDED
#define FONCTIONS_1_H_INCLUDED

/**
 * entrées : test : FILE
 * pré-cond: test != NULL
 *
 * entrée/sortie: mot[] : char
 * post-cond: "mot" contient le mot extrait de test avec pour limite les caracteres ',', ' " ' et '('.
 */
void associe_structure1 (char *mot, FILE *test);

/**
 * entrée/sortie : *chaine1 : char
 * entrée : *chaine2 : char
 * pré-cond : la taille max de "chaine1" doit être superieure ou égale à celle de "chaine2".
 * post-cond : remplace la valeur de "chaine1" par celle de "chaine2".
 *
 */
void mettre_mot (char *chaine1, char *chaine2);

/**
 * entrées : liste[50] : PASSAGERS
 * pré-cond: NONE
 *
 * sortie : taille : int
 * post-cond: taille représente la taille du tableau de structures "liste" passé en argument.
 */
int taille_tab_struct_pass(PASSAGERS liste[50]);


/**
 * entrées : tab[70] : INFO_VOL
 * pré-cond: NONE
 *
 * sortie : taille : int
 * post-cond: taille représente la taille du tableau de structures "tab" passé en argument.
 */
int taille_tab_struct_vol(INFO_VOL tab[70]);

 /**
 * entrées : *chaine : char
 * pré-cond: NONE
 *
 * sortie : taille : int
 * post-cond: taille représente la taille de la chaîne de caractère "chaine" passée en argument.
 */
 int taille_chaine(char *chaine);


/*  Fonctionnalité 1  */


/**
 * entrées\sorties : *a, *b : INFO_VOL
 * pré-cond: NONE
 * post-cond: le vol "a" prends la place du vol "b" et vice-versa.
 * déclaration : tmp : INFO_VOL
 *
 */
void permuter_vol(INFO_VOL *a, INFO_VOL *b);

/**
 * entrées\sorties : tab[70] : INFO_VOL
 * entrées deb, fin : int
 * pré-cond: fin < 70
 * post-cond: le tableau "tab" est trié par ordre croissant par rapport aux heures de décollage.
 * déclaration : pivot, i, j : int
 */
void tri_rapid_vol(INFO_VOL tab[70], int deb, int fin);

/**
 * entrées : heure : int
 * sortie : valide : int
 * pré-cond: "heure" représente une heure sous le format HHMM.
 * post-cond: retourne 1 si l'heure sous format HHMM est correcte, 0 sinon.
 * déclaration : pivot, i, j : int
 */
int heure_valide (int heure);


/*  Fonctionnalité 2  */


/**
 * entrée/sortie : *vol1 : INFO_VOL
 * pré-cond : vol1 contient des vols.
 * post-cond : affiche les vols qui correspondent aux critères saisis par l'utilisateur.
 * déclarations : nom_compagnie, destination : char, heure_decollage, i : int
*/
void recherche_vol_criteres(INFO_VOL *vol1);


/*  Fonctionnalité 3  */


/**
 * entrées\sorties : *a, *b : PASSAGERS
 * pré-cond: NONE
 * post-cond: le passager "a" prends la place du passager "b" et vice-versa.
 * déclaration : tmp : PASSAGERS
 *
 */
void permuter(PASSAGERS *a, PASSAGERS *b);

/**
 * entrées\sorties : liste[50] : PASSAGERS
 * entrées deb, fin : int
 * pré-cond: fin < 50
 * post-cond: le tableau "liste" est trié par ordre croissant par rapport au prix du billet de chacun des passagers.
 * déclaration : pivot, i, j : int
 */
void tri_rapid(PASSAGERS liste[50], int deb, int fin);

/**
 * entrées\sorties : liste[50] : PASSAGERS
 * entrées deb, fin : int
 * pré-cond : le tableau "liste" est trié, ordre croissant ou décroissant.
 * post-cond : le tableau "liste" est renversé dans l'autre ordre.
 * déclaration : ideb, ifin : int, pivot : PASSAGERS
 */
void inverse(PASSAGERS liste[50], int deb, int fin);

/**
 * entrées\sorties : liste[50] : PASSAGERS
 * entrées ind : int
 * pré-cond : "ind" est strictement plus petit que le nombre de passager de "liste".
 * post-cond : traite le cas où deux passagers ont le même prix de billet.
 * déclaration : i : int, pivot : PASSAGERS
 */
void inverser_pass (PASSAGERS liste[50], int ind);

/**
 * entrées\sorties : liste[50] : PASSAGERS
 * pré-cond : NONE
 * post-cond : le tableau "liste" est modifié de manière à mettre au début les passagers qui ont moins de 12 ans,
 * et trie tout le tableau dans l'ordre décroissant, en laissant les passagers de moins de 12 ans au début.
 * déclaration : nb_pass, i, j : int, pivot : PASSAGERS
 */
void fonctionallite_3(PASSAGERS liste[50]);


/*  Fonctionnalité 4  */


/**
 * entrée/sortie : heure : int
 * entrée : retard : int
 * pré-cond : "heure" est sous format HHMM, retard est en minutes (on a considéré un vol avec plus d'une heure de retard comme annulé).
 * post-cond : renvoie l'heure obtenue par addition de "heure" et "retard".
 *
 */
int change_heure (int heure, int retard);

/**
 * entrées : num_vol : int, tab_vols[70] : INFO_VOLS
 * sortie : indice : int
 * pré-cond : "num_vol" peut être retrouvé dans "tab_vols".
 * post-cond : retourne l'indice dans le tableau "tab_vols" du vol recherché.
 *
 */
int recherche (int num_vol, INFO_VOL tab_vols[70]);

/**
 * entrée/sortie : INFO_VOL *tab_vol_trie
 * entrée : vol_retarde : INFO_VOL
 * pré-cond : NONE
 * post-cond : insère "vol_retarde" dans "tab_vol_trie" en respectant les conditions de la fonctionnalité 4 qui sont
 * de ne pas avoir de vols à moins de 5 min d'écart du prochain ou du précédent, et de ne pas partir après 22h ou avant 6h.
 * déclaration : i, j, tmp : int
 */
void insertion_vol_retade (INFO_VOL vol_retarde, INFO_VOL tab_vol_trie[70]);

/**
 * entrée/sortie : INFO_VOL tab_vol_retarde[70]
 * entrée : tab_vol[70] : INFO_VOL
 * pré-cond : les deux tableaux ont la même taille.
 * post-cond : Modifie "tab_vol_retarde" de façon à mettre les vols retardés présent dans "tab_vol" à le bonne place,
 * mais dans le tableau "tab_vol_retarde".
 * déclaration : i, j : int
 */
void remplissage_tableau_fonct_4 (INFO_VOL tab_vol[70], INFO_VOL tab_vol_retarde[70]);


/*  Non Utile  */

void fonctionallite_4 (int ind, INFO_VOL tab_vols[70]);

#endif // FONCTIONS_1_H_INCLUDED
