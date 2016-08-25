#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct
{
    int jour;
    int mois;
     int annee;

}Date;

typedef struct
{
    unsigned int annee_de_fabrication;
    unsigned int nb_kilometres;
    char constructeur[16];
    char modele[16];
    double prime_assurance;
    Date miseEn_circulation;


}Voiture;
void afficherDate(const Date date);
void saisirDate (Date *date);
void saisirVoiture(Voiture * voiture);
void afficherVoiture(const Voiture voiture);
double calcul_moyenne_kms (const Voiture voiture);

void saisirDate (Date *date)
{
    do
    {
        printf("veuillez saisir un jour (1-->31)\n");
        scanf("%d", &date-> jour);
    }
    while (  date->jour < 1 ||  date->jour > 31  );

    do
    {
        printf("veuillez saisir un mois (1-->12)\n");
        scanf("%d", &date -> mois);

    }
    while (date -> mois < 1 || date-> mois >12  );
    do
    {
        printf("veuillez saisir une annee ( >0)\n");
        scanf("%d", &date -> annee);
    }

    while (date -> annee < 0);

}


void saisirVoiture(Voiture *voiture)
{


    printf("veuillez saisir le nom du constructeur:\n");

    scanf("%s", &voiture->constructeur);

    printf("veuillez saisir le nom du modele de la voiture:\n");

    scanf("%s", &voiture->modele);

    printf("veuillez saisir le nombre de kilometres:\n");

    scanf("%u", &voiture-> nb_kilometres);

    printf("veuillez saisir la prime d'assurance:\n");

    scanf("%lf", &voiture-> prime_assurance);

    printf("veuillez saisir l'annee de fabrication:\n");

    scanf("%u", &voiture->annee_de_fabrication);
    printf("Vous allez maintenant saisir la date de mise en circulation de la voiture:\n");
    saisirDate(&voiture->miseEn_circulation);
}
void afficherDate(const Date date)
{
    printf("la date de mise en circulation %u/%u/%u\n", date.jour, date.mois, date.annee);

}
void afficherVoiture ( const Voiture voiture)
{
    printf("Nom du constructeur : %s \n", voiture.constructeur);
    printf("Nom du modele : %s \n", voiture.modele);
    printf("Nombre de km : %u \n", voiture.nb_kilometres);
    printf("Montant de la prime : %lf \n", voiture.prime_assurance);
    printf("Annee de fabrication : %u \n", voiture.annee_de_fabrication);
    afficherDate(voiture.miseEn_circulation);

}



double calcul_moyenne_kms (const Voiture voiture)
{
    double kilometresMoyen_annuel = 0;
    int diff_mois = 0;
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant = *localtime(&secondes);
    diff_mois = (instant.tm_year + 1899) * 12 + instant.tm_mon
            - (voiture.miseEn_circulation.annee - 1) * 12
            - voiture.miseEn_circulation.mois + 1;
    printf("%d\n", diff_mois );

   kilometresMoyen_annuel = (voiture.nb_kilometres / (double)diff_mois) * 12.0;

    return kilometresMoyen_annuel;

}


int main()
{
 Voiture voiture;
 printf("\t\t*******************************\n");
 printf("\tSaisie des informations concernant votre voiture:\n");
 printf("\t\t*******************************\n\n");
 saisirVoiture(&voiture);
 printf("\n");
 printf("\t\t*******************************\n");
 printf("\tAffichage des donnees saisies:\n");
 printf("\t\t*******************************\n\n");
 afficherVoiture(voiture);
printf("\t\t*******************************\n\n");
printf("Calcul du la moyenne annuelle de kilometres\n");
printf("\t\t*******************************\n\n");
printf("%.2f kms", calcul_moyenne_kms(voiture));
return 0;

}
