#pragma once

#include <QMainWindow>
#include <QtWidgets>

// Classes pour bases de données

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QSqlError>
#include <QFile>

// Les autres fenetres

#include "fenetresortie.h"
#include "fenetreconnexion.h"
#include "fenetreentree.h"

// Définition de la classe Principale de l'application Héritant de QMainWindow

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT
public slots :
    void Quitter();
    void Imprimer();
    void CacherLeTab();
    void CloseModal();

    void OuvrirDialog1();
    void OuvrirDialog2();
    void OuvrirDialog3();
    void OuvrirDialog4();
    void OuvrirDialog5();
    void OuvrirDialog6();
    void OuvrirDialog7();
    void OuvrirDialog8();

    void OuvrirImage1();
    void OuvrirImage2();
    void OuvrirImage3();
    void OuvrirImage4();

    void OuvrirApropos();
    void OuvrirNingana();
    void OuvrirEnastic();

    void AfficheFenEetudiant();
    void AfficheFenEenseignant();
    void AfficheFenEsurveillant();
    void AfficheFenAdministrateur();
    void AfficheFenConnexion();
    void AfficheFenAcceuille();
    void AfficheDialogueChoisirRecherche();
public: // Constructeur, Destructeur

    FenetrePrincipale(QWidget *parent = nullptr);
    ~FenetrePrincipale();

public : // Méthode de la classe

    void CreerMenu();
    void CreerAction();
    void CreerBarOutils();
    void CreerSousfenetre();
    void TabwidgetInvisible();
    void CreerDialogueEtudiant();
    void CreerDialogueEnseignant();
    void CreerDialogueAdministrateur();
    void CreerDialogueSurveillant();
    void CreateWelcomFen();
    void CreateInf1();
    void CreateInf2();
    void CreateInf3();
    void CreateInf4();
    void setDatabase(QSqlDatabase *newDatabase);

    QSqlDatabase *getDatabase() const;

private :
    // Fenetre D'acceuille

    QWidget *FenAcceuille;
    QGraphicsView *Gra1, *Gra2;
    QGraphicsPixmapItem *Image1,*Image2;
    QLabel *Innovation;
    QGraphicsScene *scene1, *scene2;
    QLabel *status;
    QStackedWidget *Fenetrecentrale;

    // Pour la barre à outils

    QToolBar *BarOutils;


     //Menu

    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuOutils;
    QMenu *menuAide;
    QMenu *menuSaisie;
    QMenu *menuRechercher;
    QMenu *menuConnexion;

    // Les actions

    QAction *menuParametre;
    QAction *connexion;
    QAction *quitter;
    QAction *parametre;
    QAction *Parametre;
    QAction *calculatrice;
    QAction *internet;
    QAction *blocNote;
    QAction *login;
    QAction *aproposDuDeveloppeur;
    QAction *aproposDelAppli;
    QAction *aproposDelEnastic;
    QAction *Newfile;
    QAction *openFIle;
    QAction *couper;
    QAction *copier;
    QAction *refaire;
    QAction *retour;
    QAction *supprimer;
    QAction *toutEnregister;
    QAction *toutFermer;
    QAction *coller;
    QAction *imprimer;
    QAction *aConnexion;
    QAction *aAcceuille;
    QAction *aEnregistrement;
    QAction *aRechercher;
    QAction *aAide;
    //Saisie des donnees pour :
    QAction *Eetudiant;
    QAction *Eenseignant;
    QAction *Eadministrateur;
    QAction *Esurveillant;
    // Recherche
    QAction *rEtudiant;
    QAction *renseignant;
    QAction *radministrateur;
    QAction *rsurveillant;


    QAction *Adaptic;
    QAction *Irrorater;
    QAction *Medize;
    QAction *Integrid;
    QAction *Darkeum;
    QAction *Fibers;

    // Sous fenetre

    FenetreEntree *FenEntree;
    FenetreSortie *FenSortie;
    FenetreConnexion *FenConnexion;

    // Impression

    QDialog *impression;
    QLabel *l1, *l2, *l3, *l4, *l5, *l6, *l7;
    QComboBox *nom,*config, *config2;
    QRadioButton *R1,*R2,*R3;
    QGroupBox *G1, *G2;
    QPushButton *pro, *trois_point, *annuler, *imprimeR, *option;
    QSpinBox *nimpression, *s1, *s2,*s3;
    QVBoxLayout *V1,*v1,*v2,*v3;
    QHBoxLayout *h1,*h2,*h3,*h4,*h5,*h6,*h7,*h8,*h9,*h10;
    QFormLayout *f1, *f2, *f3;
    QLineEdit *Fout, *page;
    QCheckBox *ch1,*ch2;

    // TabWidget visible par le bouton option

    QTabWidget *tab;
    QWidget *p1,*p2;


    // Les boites de dialog

    QString informationEtudiant;
    QString informationEnseignant;
    QString informationAdministrateur;
    QString informationSurveillant;


    QDialog *dialog1;
    QDialog *dialog2;
    QDialog *dialog3;
    QDialog *dialog4;
    QDialog *dialog5;
    QDialog *dialog6;
    QDialog *dialog7;
    QDialog *dialog8;
    QDialog *dialog9;
    QDialog *dialog10;
    QDialog *dialog11;
    QDialog *dialog12;

    QSplitter *splitt1;
    QSplitter *splitt2;
    QSplitter *splitt3;
    QSplitter *splitt4;

    QWidget *wi1;
    QWidget *wi2;
    QWidget *wi3;
    QWidget *wi4;
    QWidget *wi5;
    QWidget *wi6;
    QWidget *wi7;
    QWidget *wi8;


    QPushButton *Recherche1;
    QPushButton *Recherche2;
    QPushButton *Recherche3;
    QPushButton *Recherche4;

    QPushButton *fermer1;
    QPushButton *fermer2;
    QPushButton *fermer3;
    QPushButton *fermer4;

    QPushButton *CHooseIm1;
    QPushButton *CHooseIm2;
    QPushButton *CHooseIm3;
    QPushButton *CHooseIm4;

    QSpinBox *Matricule1;
    QSpinBox *Matricule2;
    QSpinBox *Matricule3;
    QSpinBox *Matricule4;

    QHBoxLayout *hbox1;
    QHBoxLayout *hbox2;
    QHBoxLayout *hbox3;
    QHBoxLayout *hbox4;

    QVBoxLayout *vbox1;
    QVBoxLayout *vbox2;
    QVBoxLayout *vbox3;
    QVBoxLayout *vbox4;

    QLabel *image1;
    QLabel *image2;
    QLabel *image3;
    QLabel *image4;
    QLabel *image5;
    QLabel *image6;
    QLabel *image7;
    QLabel *image8;

    QString fichier1;
    QString fichier2;
    QString fichier3;
    QString fichier4;

    QTextEdit *text1;
    QTextEdit *text2;
    QTextEdit *text3;
    QTextEdit *text4;

    QScrollArea *scrrol1;
    QScrollArea *scrrol2;
    QScrollArea *scrrol3;
    QScrollArea *scrrol4;


    QSqlDatabase *database;
};
