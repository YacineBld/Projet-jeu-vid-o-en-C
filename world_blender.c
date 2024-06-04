/* Belabed Yacine 12211859
 * Je déclare qu'il s'agit de mon propre travail. */

#include <stdio.h>
#include <stdlib.h> /****exit()****/
#include <string.h> /****Manipulation de chaines de caractères****/

#define MAX_ELEMENTS_LG 200

/* Déclaration de tous les éléments à combiner dans des constantes et usage de pointeurs pour facilier l'accés à leur memoire au vue des mélanges effectuer */

const char* AIR = "air", *EAU = "eau", *TERRE = "terre", *FEU = "feu", *PLUIE = "pluie", *ENERGIE = "énergie", *POUSSIERE = "poussière", *PRESSION = "pression", *VAPEUR = "vapeur", *BOUE = "boue", 
*MER = "mer", *LAVE = "lave", *PLANTE = "plante", *INONDATION = "inondation", *VENT = "vent", *TREMBLEMENT_DE_TERRE = "tremblement de terre", *OURAGAN = "ouragan", *POUDRE_A_CANON = "poudre à canon", 
*ATMOSPHERE = "atmosphere", *GRANIT = "granit", *CHARBON = "charbon", *NUAGE = "nuage", *GEYSER = "geyser", *BRIQUE = "brique", *MARAIS = "marais", *OCEAN = "océan", 
*SEL = "sel", *SOUPE_PRIMORDIALE = "soupe primordiale", *ALGUE = "algue", *TSUNAMI = "tsunami",  *PIERRE = "pierre", *OBSIDIENNE = "obsidienne", *VOLCAN = "volcan", *COTON = "coton", 
*MOUSSE = "mousse", *JARDIN = "jardin", *HERBE = "herbe", *VAGUE = "vague", *SABLE = "sable", *DUNE = "dune", *MONTAGNE = "montagne", *TEMPETE_DE_SABLE = "tempête de sable", 
*EXPLOSION = "explosion", *DIAMANT = "diamant", *CIEL = "ciel", *TEMPETE = "tempête", *PLANETE = "planète", *VIE = "vie", *ANIMAL = "animal", *FIL = "fil", *CORDE = "corde",
*ARGILE = "argile", *HUMAIN = "humain", *SUPER_HERO = "super-hero", *OISEAU = "oiseau", *SOLEIL = "soleil", *OUTIL = "outil", *MAISON = "maison", *CONTINENT = "continent", *MUR = "mur",
*PHENIX = "phénix", *ARC_EN_CIEL = "arc-en-ciel", *FLEUR = "fleur", *METAL = "métal", *VERRE = "verre", *ELECTRICITE ="électricité", *ROBOT = "robot", *TERMINATOR = "terminator", *TEMPS = "temps",
*ARBRE = "arbre", *FRUIT = "fruit", *LAME = "lame", *FAUX = "faux", *MORT = "mort", *ZOMBIE = "zombie";

/* Déclaration de la base de tous les mélanges possibles dans le jeu */

struct melange {
    char premier_element[MAX_ELEMENTS_LG];
    char deuxieme_element[MAX_ELEMENTS_LG];
    char nouvel_element[MAX_ELEMENTS_LG];
    char nom[MAX_ELEMENTS_LG];
};

/* Fonction principale du jeu permettant de réaliser les mélanges */

void effectuer_melange(struct melange c, struct melange *e1, struct melange *e2, struct melange *e3, int *score);

int main()
{
struct melange e1, e2, e3;
strcpy(e1.premier_element," ");
strcpy(e2.deuxieme_element, " ");
strcpy(e3.nouvel_element, " ");

/* Mise en place d'un choix que le joueur pourra contrôler dans le menu */

int choix;

/* Mise en place d'un score qui évoluera au fil de la partie */

int score = 0;

/* Niveau du joueur qui évoluera donc en fonction de son score. C'est en quelque sorte une compétence assigné au joueur. */

char niveau[MAX_ELEMENTS_LG] ="";

/* BOUCLE PRINCIPALE ET MENU DU JEU */
    
    while (1) /* Tant que le joueur ne choisit pas l'option "2.Quitter le jeu", la boucle continue à afficher le menu et à demander une saisie à l'utilisateur */
{
if (score <= 5){
        strcpy(niveau, "Novice"); /* Le code compare le score avec différents seuils (5,10,15,30,40) et selon le score atteint, il attribue un niveau différent au joueur à l'aide la fonction "strcpy" */
        }
else if (score <=10){
        strcpy(niveau, "Humain lambda");
}
else if (score <=15){
        strcpy(niveau, "Scientifique");
}
else if (score <=30){
        strcpy(niveau, "Einstein");
}
else if (score <=40){
        strcpy(niveau, "Esprit créateur");
}

/* Affichage des options possibles pour le joueur (MENU du jeu). Les choix se font en tapant soit 1, soit 2, d'où l'usage d'entier (%d)  */
        
        printf("\n\e[36m===================== LABORATOIRE =====================\e[0m\n");
        printf("\n\e[4mElements dans l'inventaire\e[0m : %s, %s, %s, %s, %s\n",AIR,EAU,TERRE,FEU,e3.nouvel_element);
       
       if (strcmp(niveau, "") != 0) { /* Vérifie si le joueur a atteint un certain score pour ainsi lui attribué un niveau */
            printf("\nScore : \e[34m%d\e[0m | Niveau actuel : \e[34m%s\e[0m\n", score, niveau);
        }
        printf("\n\e[4mQue voulez-vous faire?\e[0m\n");
        printf("\n\e[32m1. Mélanger deux éléments\e[0m\n");
        printf("\n\e[31m2. Quitter le jeu\e[0m\n");
        printf("\n\e[33mVotre choix :\e[0m");
        
        int result = scanf("%d", &choix);  /* Affichage d'une erreur si le joueur saisis autre chose qu'un chiffre */
        
        if (result !=1) {
                printf("\n\e[41m\e[4m\e[1mErreur\e[0m\e[0m\e[0m : Entrer soit \e[32m1\e[0m pour continuer la partie, soit \e[32m2\e[0m pour quitter. \n");
        while (getchar() !='\n'){
        }
        continue; /* continuer la boucle while tant que le joueur ne saisit pas un choix valide */
        }

/* AFFICHAGE DES CHOIX */

    printf("\033[H\033[2J");  /* Actualiser la page afin de rendre plus propre l'affichage des résultats */
   
    switch (choix)  /* La fonction switch permet ici de gérer les différentes options possibles pour le joueur en fonction de son choix */
    {
        /* Demande des éléments à combiner */ 
        
        case 1 : /* CHOIX 1 */

        printf("\nEntrer le premier élément :");
        scanf("%s", e1.premier_element);
        printf("\nEntrer le second élément :");
        scanf("%s", e2.deuxieme_element);
        effectuer_melange(e3, &e1, &e2, &e3, &score);
        break;

     /* QUITTER LE JEU */
        
        case 2 : /* CHOIX 2 */
                
                printf("\nMerci d'avoir joué ! \e[4mScore enregistrée\e[0m : \e[36m%d\e[0m || \e[4mNiveau atteint\e[0m : \e[36m%s\e[0m\n", score, niveau);
                exit(0); /* Fonction qui permet de quitter le programme en prenant 0 comme code de sortie lorsque le joueur décide de quitter le jeu*/
                break;

            /* Choix invalide */
       
        default : /* mot-clé incorporée dans la structure switch-case permettant de gérer un choix non lié aux 2 cas précédents */
                printf("\n\e[31m\e[4mChoix invalide.\e[0m\e[0m Veuillez entrer un choix valide.\n");
                break;
        }
    }
        return 0;
}

/* Ensemble des Mélanges possibles */

void effectuer_melange(struct melange c, struct melange *e1, struct melange *e2, struct melange *e3, int *score)
{
if ((strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, EAU) == 0) ||
        (strcmp(e1->premier_element, EAU) == 0 && strcmp(e2->deuxieme_element, AIR) == 0)) {
        strcpy(e3->nouvel_element, "pluie");
        strcpy(e3->nom, "Pluie");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, AIR) == 0)) {
        strcpy(e3->nouvel_element, "énergie");
        strcpy(e3->nom, "Energie");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}
    
else if ((strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, AIR) == 0)) {
        strcpy(e3->nouvel_element, "poussière");
        strcpy(e3->nom, "Poussière");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, AIR) == 0) {
        strcpy(e3->nouvel_element, "pression");
        strcpy(e3->nom, "Pression");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) {
        strcpy(e3->nouvel_element, "continent ");
        strcpy(e3->nom, "Continent");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, EAU) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, EAU) == 0)) {
        strcpy(e3->nouvel_element, "vapeur");
        strcpy(e3->nom, "Vapeur");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, EAU) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, EAU) == 0)) {
        strcpy(e3->nouvel_element, "boue");
        strcpy(e3->nom, "Boue");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;} 

else if (strcmp(e1->premier_element, EAU) == 0 && strcmp(e2->deuxieme_element, EAU) == 0) {
        strcpy(e3->nouvel_element, "mer");
        strcpy(e3->nom, "Mer");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, FEU) == 0)) {
        strcpy(e3->nouvel_element, "lave");
        strcpy(e3->nom, "Lave");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;} 

else if (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) {
        strcpy(e3->nouvel_element, "pression");
        strcpy(e3->nom, "Pression");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLUIE) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, PLUIE) == 0)) {
        strcpy(e3->nouvel_element, "plante");
        strcpy(e3->nom, "Plante");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;} 

else if (strcmp(e1->premier_element, PLUIE) == 0 && strcmp(e2->deuxieme_element, PLUIE) == 0) {
        strcpy(e3->nouvel_element, "inondation");
        strcpy(e3->nom, "Inondation");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, ENERGIE) == 0 && strcmp(e2->deuxieme_element, AIR) == 0) ||
        (strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, ENERGIE) == 0)) {
        strcpy(e3->nouvel_element, "vent");
        strcpy(e3->nom, "Vent");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, ENERGIE) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, ENERGIE) == 0)) {
        strcpy(e3->nouvel_element, "tremblement de terre ");
        strcpy(e3->nom, "Tremblement de terre");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, ENERGIE) == 0 && strcmp(e2->deuxieme_element, VENT) == 0) ||
        (strcmp(e1->premier_element, VENT) == 0 && strcmp(e2->deuxieme_element, ENERGIE) == 0)) {
        strcpy(e3->nouvel_element, "ouragan");
        strcpy(e3->nom, "Ouragan");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, POUSSIERE) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, POUSSIERE) == 0)) {
        strcpy(e3->nouvel_element, "poudre à canon");
        strcpy(e3->nom, "Poudre à canon");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLANETE) == 0 && strcmp(e2->deuxieme_element, AIR) == 0) ||
        (strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, PLANETE) == 0)) {
        strcpy(e3->nouvel_element, "atmosphère");
        strcpy(e3->nom, "Atmosphère");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PRESSION) == 0 && strcmp(e2->deuxieme_element, LAVE) == 0) ||
        (strcmp(e1->premier_element, LAVE) == 0 && strcmp(e2->deuxieme_element, PRESSION) == 0)) {
        strcpy(e3->nouvel_element, "granit");
        strcpy(e3->nom, "Granit");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PRESSION) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0) ||
        (strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, PRESSION) == 0)) {
        strcpy(e3->nouvel_element, "charbon");
        strcpy(e3->nom, "Charbon");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}     

else if ((strcmp(e1->premier_element, VAPEUR) == 0 && strcmp(e2->deuxieme_element, AIR) == 0) ||
        (strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, VAPEUR) == 0)) {
        strcpy(e3->nouvel_element, "nuage");
        strcpy(e3->nom, "Nuage");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, VAPEUR) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, VAPEUR) == 0)) {
        strcpy(e3->nouvel_element, "geyser");
        strcpy(e3->nom, "Geyser");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, BOUE) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, BOUE) == 0)) {
        strcpy(e3->nouvel_element, "brique");
        strcpy(e3->nom, "Brique");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, BOUE) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0) ||
        (strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, BOUE) == 0)) {
        strcpy(e3->nouvel_element, "marais");
        strcpy(e3->nom, "Marais");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, MER) == 0 && strcmp(e2->deuxieme_element, MER) == 0) {
        strcpy(e3->nouvel_element, "océan");
        strcpy(e3->nom, "Océan");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, MER) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, MER) == 0)) {
        strcpy(e3->nouvel_element, "soupe primordiale");
        strcpy(e3->nom, "Soupe primordiale");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, MER) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, MER) == 0)) {
        strcpy(e3->nouvel_element, "sel");
        strcpy(e3->nom, "Sel");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, MER) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0) ||
        (strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, MER) == 0)) {
        strcpy(e3->nouvel_element, "algue");
        strcpy(e3->nom, "Algue");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, MER) == 0 && strcmp(e2->deuxieme_element, TREMBLEMENT_DE_TERRE) == 0) ||
        (strcmp(e1->premier_element, TREMBLEMENT_DE_TERRE) == 0 && strcmp(e2->deuxieme_element, MER) == 0)) {
        strcpy(e3->nouvel_element, "tsunami");
        strcpy(e3->nom, "Tsunami");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, LAVE) == 0 && strcmp(e2->deuxieme_element, AIR) == 0) ||
        (strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, LAVE) == 0)) {
        strcpy(e3->nouvel_element, "pierre");
        strcpy(e3->nom, "Pierre");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, LAVE) == 0 && strcmp(e2->deuxieme_element, EAU) == 0) ||
        (strcmp(e1->premier_element, EAU) == 0 && strcmp(e2->deuxieme_element, LAVE) == 0)) {
        strcpy(e3->nouvel_element, "obsidienne");
        strcpy(e3->nom, "Obsidienne");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, LAVE) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, LAVE) == 0)) {
        strcpy(e3->nouvel_element, "volcan");
        strcpy(e3->nom, "Volcan");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, NUAGE) == 0) ||
        (strcmp(e1->premier_element, NUAGE) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0)) {
        strcpy(e3->nouvel_element, "coton");
        strcpy(e3->nom, "Coton");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, PIERRE) == 0) ||
        (strcmp(e1->premier_element, PIERRE) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0)) {
        strcpy(e3->nouvel_element, "mousse");
        strcpy(e3->nom, "Mousse");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0) {
        strcpy(e3->nouvel_element, "jardin");
        strcpy(e3->nom, "Jardin");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0)) {
        strcpy(e3->nouvel_element, "herbe");
        strcpy(e3->nom, "Herbe");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, VENT) == 0 && strcmp(e2->deuxieme_element, MER) == 0) ||
        (strcmp(e1->premier_element, MER) == 0 && strcmp(e2->deuxieme_element, VENT) == 0)) {
        strcpy(e3->nouvel_element, "vague");
        strcpy(e3->nom, "Vague");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, VENT) == 0 && strcmp(e2->deuxieme_element, OCEAN) == 0) ||
        (strcmp(e1->premier_element, OCEAN) == 0 && strcmp(e2->deuxieme_element, VENT) == 0)) {
        strcpy(e3->nouvel_element, "vague");
        strcpy(e3->nom, "Vague");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, VENT) == 0 && strcmp(e2->deuxieme_element, PIERRE) == 0) ||
        (strcmp(e1->premier_element, PIERRE) == 0 && strcmp(e2->deuxieme_element, VENT) == 0)) {
        strcpy(e3->nouvel_element, "sable");
        strcpy(e3->nom, "Sable");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, VENT) == 0 && strcmp(e2->deuxieme_element, SABLE) == 0) ||
        (strcmp(e1->premier_element, SABLE) == 0 && strcmp(e2->deuxieme_element, VENT) == 0)) {
        strcpy(e3->nouvel_element, "dune");
        strcpy(e3->nom, "Dune");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, TREMBLEMENT_DE_TERRE) == 0 && strcmp(e2->deuxieme_element, TERRE) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, TREMBLEMENT_DE_TERRE) == 0)) {
        strcpy(e3->nouvel_element, "montagne");
        strcpy(e3->nom, "Montagne");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, OURAGAN) == 0 && strcmp(e2->deuxieme_element, SABLE) == 0) ||
        (strcmp(e1->premier_element, SABLE) == 0 && strcmp(e2->deuxieme_element, OURAGAN) == 0)) {
        strcpy(e3->nouvel_element, "tempête de sable");
        strcpy(e3->nom, "Tempête de sable");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, POUDRE_A_CANON) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, POUDRE_A_CANON) == 0)) {
        strcpy(e3->nouvel_element, "explosion");
        strcpy(e3->nom, "Explosion");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, CHARBON) == 0 && strcmp(e2->deuxieme_element, PRESSION) == 0) ||
        (strcmp(e1->premier_element, PRESSION) == 0 && strcmp(e2->deuxieme_element, CHARBON) == 0)) {
        strcpy(e3->nouvel_element, "diamant");
        strcpy(e3->nom, "Diamant");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, NUAGE) == 0 && strcmp(e2->deuxieme_element, AIR) == 0) ||
        (strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, NUAGE) == 0)) {
        strcpy(e3->nouvel_element, "ciel");
        strcpy(e3->nom, "Ciel");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, NUAGE) == 0 && strcmp(e2->deuxieme_element, EAU) == 0) ||
        (strcmp(e1->premier_element, EAU) == 0 && strcmp(e2->deuxieme_element, NUAGE) == 0)) {
        strcpy(e3->nouvel_element, "pluie");
        strcpy(e3->nom, "Pluie");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, NUAGE) == 0 && strcmp(e2->deuxieme_element, ENERGIE) == 0) ||
        (strcmp(e1->premier_element, ENERGIE) == 0 && strcmp(e2->deuxieme_element, NUAGE) == 0)) {
        strcpy(e3->nouvel_element, "tempête");
        strcpy(e3->nom, "Tempête");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, NUAGE) == 0 && strcmp(e2->deuxieme_element, AIR ) == 0) ||
        (strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, NUAGE) == 0)) {
        strcpy(e3->nouvel_element, "ciel");
        strcpy(e3->nom, "Ciel");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, CONTINENT) == 0 && strcmp(e2->deuxieme_element, CONTINENT) == 0) {
        strcpy(e3->nouvel_element, "planète");
        strcpy(e3->nom, "Planète");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, ENERGIE) == 0 && strcmp(e2->deuxieme_element, SOUPE_PRIMORDIALE ) == 0) ||
        (strcmp(e1->premier_element, SOUPE_PRIMORDIALE) == 0 && strcmp(e2->deuxieme_element, ENERGIE) == 0)) {
        strcpy(e3->nouvel_element, "vie");
        strcpy(e3->nom, "Vie");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, VIE) == 0 && strcmp(e2->deuxieme_element, TERRE ) == 0) ||
        (strcmp(e1->premier_element, TERRE) == 0 && strcmp(e2->deuxieme_element, VIE) == 0)) {
        strcpy(e3->nouvel_element, "animal");
        strcpy(e3->nom, "Animal");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, COTON) == 0 && strcmp(e2->deuxieme_element, COTON) == 0) {
        strcpy(e3->nouvel_element, "fil");
        strcpy(e3->nom, "Fil");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, FIL) == 0 && strcmp(e2->deuxieme_element, FIL) == 0) {
        strcpy(e3->nouvel_element, "corde");
        strcpy(e3->nom, "Corde");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, BOUE) == 0 && strcmp(e2->deuxieme_element, PIERRE) == 0) ||
        (strcmp(e1->premier_element, PIERRE) == 0 && strcmp(e2->deuxieme_element, BOUE) == 0)) {
        strcpy(e3->nouvel_element, "argile");
        strcpy(e3->nom, "Argile");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, ARGILE) == 0 && strcmp(e2->deuxieme_element, VIE) == 0) ||
        (strcmp(e1->premier_element, VIE) == 0 && strcmp(e2->deuxieme_element, ARGILE) == 0)) {
        strcpy(e3->nouvel_element, "humain");
        strcpy(e3->nom, "Humain");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, HUMAIN) == 0 && strcmp(e2->deuxieme_element, HUMAIN) == 0) {
        strcpy(e3->nouvel_element, "super-hero");
        strcpy(e3->nom, "Super-hero");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, AIR) == 0 && strcmp(e2->deuxieme_element, ANIMAL) == 0) ||
        (strcmp(e1->premier_element, ANIMAL) == 0 && strcmp(e2->deuxieme_element, AIR) == 0)) {
        strcpy(e3->nouvel_element, "oiseau");
        strcpy(e3->nom, "Oiseau");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLANETE) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, PLANETE) == 0)) {
        strcpy(e3->nouvel_element, "soleil");
        strcpy(e3->nom, "Soleil");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PIERRE) == 0 && strcmp(e2->deuxieme_element, HUMAIN) == 0) ||
        (strcmp(e1->premier_element, HUMAIN) == 0 && strcmp(e2->deuxieme_element, PIERRE) == 0)) {
        strcpy(e3->nouvel_element, "outil");
        strcpy(e3->nom, "Outil");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, MUR) == 0 && strcmp(e2->deuxieme_element, MUR) == 0) {
        strcpy(e3->nouvel_element, "maison");
        strcpy(e3->nom, "Maison");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, BRIQUE) == 0 && strcmp(e2->deuxieme_element, BRIQUE) == 0) {
        strcpy(e3->nouvel_element, "mur");
        strcpy(e3->nom, "Mur");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, VIE) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, VIE) == 0)) {
        strcpy(e3->nouvel_element, "phénix");
        strcpy(e3->nom, "Phénix");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, EAU) == 0 && strcmp(e2->deuxieme_element, SOLEIL) == 0) ||
        (strcmp(e1->premier_element, SOLEIL) == 0 && strcmp(e2->deuxieme_element, EAU) == 0)) {
        strcpy(e3->nouvel_element, "arc-en-ciel");
        strcpy(e3->nom, "Arc-en-ciel");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, ARC_EN_CIEL) == 0) ||
        (strcmp(e1->premier_element, ARC_EN_CIEL) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0)) {
        strcpy(e3->nouvel_element, "fleur");
        strcpy(e3->nom, "Fleur");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PIERRE) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, PIERRE) == 0)) {
        strcpy(e3->nouvel_element, "métal");
        strcpy(e3->nom, "Métal");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, SABLE) == 0 && strcmp(e2->deuxieme_element, FEU) == 0) ||
        (strcmp(e1->premier_element, FEU) == 0 && strcmp(e2->deuxieme_element, SABLE) == 0)) {
        strcpy(e3->nouvel_element, "verre");
        strcpy(e3->nom, "Verre");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, METAL) == 0 && strcmp(e2->deuxieme_element, ENERGIE) == 0) ||
        (strcmp(e1->premier_element, ENERGIE) == 0 && strcmp(e2->deuxieme_element, METAL) == 0)) {
        strcpy(e3->nouvel_element, "électricité");
        strcpy(e3->nom, "Electricité");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, METAL) == 0 && strcmp(e2->deuxieme_element, VIE) == 0) ||
        (strcmp(e1->premier_element, VIE) == 0 && strcmp(e2->deuxieme_element, METAL) == 0)) {
        strcpy(e3->nouvel_element, "robot");
        strcpy(e3->nom, "Robot");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, HUMAIN) == 0 && strcmp(e2->deuxieme_element, ROBOT) == 0) ||
        (strcmp(e1->premier_element, ROBOT) == 0 && strcmp(e2->deuxieme_element, HUMAIN) == 0)) {
        strcpy(e3->nouvel_element, "terminator");
        strcpy(e3->nom, "Terminator");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, SABLE) == 0 && strcmp(e2->deuxieme_element, VERRE) == 0) ||
        (strcmp(e1->premier_element, VERRE) == 0 && strcmp(e2->deuxieme_element, SABLE) == 0)) {
        strcpy(e3->nouvel_element, "temps");
        strcpy(e3->nom, "Temps");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, PLANTE) == 0 && strcmp(e2->deuxieme_element, TEMPS) == 0) ||
        (strcmp(e1->premier_element, TEMPS) == 0 && strcmp(e2->deuxieme_element, PLANTE) == 0)) {
        strcpy(e3->nouvel_element, "arbre");
        strcpy(e3->nom, "Arbre");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, ARBRE) == 0 && strcmp(e2->deuxieme_element, SOLEIL) == 0) ||
        (strcmp(e1->premier_element, SOLEIL) == 0 && strcmp(e2->deuxieme_element, ARBRE) == 0)) {
        strcpy(e3->nouvel_element, "fruit");
        strcpy(e3->nom, "Fruit");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, METAL) == 0 && strcmp(e2->deuxieme_element, PIERRE) == 0) ||
        (strcmp(e1->premier_element, PIERRE) == 0 && strcmp(e2->deuxieme_element, METAL) == 0)) {
        strcpy(e3->nouvel_element, "lame");
        strcpy(e3->nom, "Lame");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if (strcmp(e1->premier_element, LAME) == 0 && strcmp(e2->deuxieme_element, LAME) == 0) {
        strcpy(e3->nouvel_element, "faux");
        strcpy(e3->nom, "Faux");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, FAUX) == 0 && strcmp(e2->deuxieme_element, HUMAIN) == 0) ||
        (strcmp(e1->premier_element, HUMAIN) == 0 && strcmp(e2->deuxieme_element, FAUX) == 0)) {
        strcpy(e3->nouvel_element, "mort");
        strcpy(e3->nom, "Mort");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

else if ((strcmp(e1->premier_element, MORT) == 0 && strcmp(e2->deuxieme_element, VIE) == 0) ||
        (strcmp(e1->premier_element, VIE) == 0 && strcmp(e2->deuxieme_element, MORT) == 0)) {
        strcpy(e3->nouvel_element, "zombie");
        strcpy(e3->nom, "Zombie");
        printf("\nLa combinaison est valide ! Le résultat est : %s\n", e3->nouvel_element);
        *score = *score + 1;}

/* Si aucun mélange n'a été trouvé, retourne l'élément "inconnu" */
    
    else {
       strcpy(e3->nom, "\nCombinaison inconnu... Veuillez réessayer.\n");
    
       printf("%s",e3->nom);
   }
}



