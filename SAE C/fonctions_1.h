#ifndef FONCTIONS_1_H_INCLUDED
#define FONCTIONS_1_H_INCLUDED

/**
 * entr�es : test : FILE
 * pr�-cond: test != NULL
 *
 * entr�e/sortie: mot[] : char
 * post-cond: "mot" contient le mot extrait de test avec pour limite les caracteres ',', ' " ' et '('.
 */
void associe_structure1 (char *mot, FILE *test);

/**
 * entr�e/sortie : *chaine1 : char
 * entr�e : *chaine2 : char
 * pr�-cond : la taille max de "chaine1" doit �tre superieure ou �gale � celle de "chaine2".
 * post-cond : remplace la valeur de "chaine1" par celle de "chaine2".
 *
 */
void mettre_mot (char *chaine1, char *chaine2);

/**
 * entr�es : liste[50] : PASSAGERS
 * pr�-cond: NONE
 *
 * sortie : taille : int
 * post-cond: taille repr�sente la taille du tableau de structures "liste" pass� en argument.
 */
int taille_tab_struct_pass(PASSAGERS liste[50]);


/**
 * entr�es : tab[70] : INFO_VOL
 * pr�-cond: NONE
 *
 * sortie : taille : int
 * post-cond: taille repr�sente la taille du tableau de structures "tab" pass� en argument.
 */
int taille_tab_struct_vol(INFO_VOL tab[70]);

 /**
 * entr�es : *chaine : char
 * pr�-cond: NONE
 *
 * sortie : taille : int
 * post-cond: taille repr�sente la taille de la cha�ne de caract�re "chaine" pass�e en argument.
 */
 int taille_chaine(char *chaine);


/*  Fonctionnalit� 1  */


/**
 * entr�es\sorties : *a, *b : INFO_VOL
 * pr�-cond: NONE
 * post-cond: le vol "a" prends la place du vol "b" et vice-versa.
 * d�claration : tmp : INFO_VOL
 *
 */
void permuter_vol(INFO_VOL *a, INFO_VOL *b);

/**
 * entr�es\sorties : tab[70] : INFO_VOL
 * entr�es deb, fin : int
 * pr�-cond: fin < 70
 * post-cond: le tableau "tab" est tri� par ordre croissant par rapport aux heures de d�collage.
 * d�claration : pivot, i, j : int
 */
void tri_rapid_vol(INFO_VOL tab[70], int deb, int fin);

/**
 * entr�es : heure : int
 * sortie : valide : int
 * pr�-cond: "heure" repr�sente une heure sous le format HHMM.
 * post-cond: retourne 1 si l'heure sous format HHMM est correcte, 0 sinon.
 * d�claration : pivot, i, j : int
 */
int heure_valide (int heure);


/*  Fonctionnalit� 2  */


/**
 * entr�e/sortie : *vol1 : INFO_VOL
 * pr�-cond : vol1 contient des vols.
 * post-cond : affiche les vols qui correspondent aux crit�res saisis par l'utilisateur.
 * d�clarations : nom_compagnie, destination : char, heure_decollage, i : int
*/
void recherche_vol_criteres(INFO_VOL *vol1);


/*  Fonctionnalit� 3  */


/**
 * entr�es\sorties : *a, *b : PASSAGERS
 * pr�-cond: NONE
 * post-cond: le passager "a" prends la place du passager "b" et vice-versa.
 * d�claration : tmp : PASSAGERS
 *
 */
void permuter(PASSAGERS *a, PASSAGERS *b);

/**
 * entr�es\sorties : liste[50] : PASSAGERS
 * entr�es deb, fin : int
 * pr�-cond: fin < 50
 * post-cond: le tableau "liste" est tri� par ordre croissant par rapport au prix du billet de chacun des passagers.
 * d�claration : pivot, i, j : int
 */
void tri_rapid(PASSAGERS liste[50], int deb, int fin);

/**
 * entr�es\sorties : liste[50] : PASSAGERS
 * entr�es deb, fin : int
 * pr�-cond : le tableau "liste" est tri�, ordre croissant ou d�croissant.
 * post-cond : le tableau "liste" est renvers� dans l'autre ordre.
 * d�claration : ideb, ifin : int, pivot : PASSAGERS
 */
void inverse(PASSAGERS liste[50], int deb, int fin);

/**
 * entr�es\sorties : liste[50] : PASSAGERS
 * entr�es ind : int
 * pr�-cond : "ind" est strictement plus petit que le nombre de passager de "liste".
 * post-cond : traite le cas o� deux passagers ont le m�me prix de billet.
 * d�claration : i : int, pivot : PASSAGERS
 */
void inverser_pass (PASSAGERS liste[50], int ind);

/**
 * entr�es\sorties : liste[50] : PASSAGERS
 * pr�-cond : NONE
 * post-cond : le tableau "liste" est modifi� de mani�re � mettre au d�but les passagers qui ont moins de 12 ans,
 * et trie tout le tableau dans l'ordre d�croissant, en laissant les passagers de moins de 12 ans au d�but.
 * d�claration : nb_pass, i, j : int, pivot : PASSAGERS
 */
void fonctionallite_3(PASSAGERS liste[50]);


/*  Fonctionnalit� 4  */


/**
 * entr�e/sortie : heure : int
 * entr�e : retard : int
 * pr�-cond : "heure" est sous format HHMM, retard est en minutes (on a consid�r� un vol avec plus d'une heure de retard comme annul�).
 * post-cond : renvoie l'heure obtenue par addition de "heure" et "retard".
 *
 */
int change_heure (int heure, int retard);

/**
 * entr�es : num_vol : int, tab_vols[70] : INFO_VOLS
 * sortie : indice : int
 * pr�-cond : "num_vol" peut �tre retrouv� dans "tab_vols".
 * post-cond : retourne l'indice dans le tableau "tab_vols" du vol recherch�.
 *
 */
int recherche (int num_vol, INFO_VOL tab_vols[70]);

/**
 * entr�e/sortie : INFO_VOL *tab_vol_trie
 * entr�e : vol_retarde : INFO_VOL
 * pr�-cond : NONE
 * post-cond : ins�re "vol_retarde" dans "tab_vol_trie" en respectant les conditions de la fonctionnalit� 4 qui sont
 * de ne pas avoir de vols � moins de 5 min d'�cart du prochain ou du pr�c�dent, et de ne pas partir apr�s 22h ou avant 6h.
 * d�claration : i, j, tmp : int
 */
void insertion_vol_retade (INFO_VOL vol_retarde, INFO_VOL tab_vol_trie[70]);

/**
 * entr�e/sortie : INFO_VOL tab_vol_retarde[70]
 * entr�e : tab_vol[70] : INFO_VOL
 * pr�-cond : les deux tableaux ont la m�me taille.
 * post-cond : Modifie "tab_vol_retarde" de fa�on � mettre les vols retard�s pr�sent dans "tab_vol" � le bonne place,
 * mais dans le tableau "tab_vol_retarde".
 * d�claration : i, j : int
 */
void remplissage_tableau_fonct_4 (INFO_VOL tab_vol[70], INFO_VOL tab_vol_retarde[70]);


/*  Non Utile  */

void fonctionallite_4 (int ind, INFO_VOL tab_vols[70]);

#endif // FONCTIONS_1_H_INCLUDED
