#pragma once

#include <QWidget>
#include <QtWidgets>
#include "fenetreconnexion.h"

class FenetreEntree : public QWidget
{
    Q_OBJECT
public:
    FenetreEntree(QWidget *parent = nullptr);
    void CreerFormulaireEtudiant();
    void CreerImageBtnEtudiant();
    void FormulaireEnseignant();
    void ImageEnseignant();
    void CreateTableEtudiant();
    void CreateTableEnseignant();
    QSqlDatabase *getDatabase() const;
    void setDatabase(QSqlDatabase *newDatabase);

public slots :
    void OuvrirImage();
    void OuvrirImageE();        // Slot qui sera appélé quand on voudra ouvrir une image
    void ShowtabSTudent();     // Appélé pour afficher la page Etudiantine
    void ShowtabTich();       // Apélé pour afficher la page des enseignants
    void ShowTabAdmin();     // Apélé pour afficher la page des administrateurs
    void ShowtabSurv();     // Apélé pour afficher la page des surveillants
    void OnAddetudiant();
    void OnUpdateEtudiant();
    void OnAddEnseignant();
    void OnUpdateEnseignant();
    void ChekBox();
private :
    QVBoxLayout *vl;
    QString matiere;
    QVBoxLayout *VLGeneral;

    // Pour le formulaire Etudiant

    QLineEdit *nom, *prenom, *DateNaissance, *lieu, *Email;
    QSpinBox *Matricule,*salle, *Licence;
    QTextEdit *Description;
    QFormLayout *FormLayout;
    QLineEdit *Lycee;
    QComboBox *Filiere,*sexe;

    QPushButton *btnAjouter;
    QPushButton *supprimer;
    QPushButton *Restaurer;
    QPushButton *precedent;
    QPushButton *Suivant;
    QPushButton *nouveau;
    QVBoxLayout *vlSep;


    // Pour le second WIdget contenant l'image de l'tudiant

    QLabel *image;
    QPushButton *btnAjouterUneImage;
    QVBoxLayout *VerticalLim;

    // pour le tabWidgetEtudiant

    QTabWidget *onglet;
    QWidget *page1, *page2, *page3, *page4;
    QWidget *W1, *W2, *W3, *W4, *w, *w1,*contenuer2, *conteneur3;
    QSplitter *split1, *split2, *split3,*split4;
    QVBoxLayout *VL2, *VL3;

    QString fichier;
    QLineEdit *FICHIER;

   // Pour le formulaire Eseignant

   QLineEdit *nomEnse, *prenomEnse,*DateNaissanceEnse;
   QLineEdit *lieuEnse, *specialite, *email;
   QSpinBox *MatriculeEnse, *nbreMatiere;
   QLineEdit *Contact;
   QComboBox *diplome, *sexeEnse;
   QCheckBox *itm, *mtic1, *mtic2, *mtic3;
   QCheckBox *masterTel, *masterMtic, *info2;
   QCheckBox *cyber, *Genie, *telecom2, *telecom3;
   QGroupBox *groupe;
   QVBoxLayout *vlgroupe;
   QVBoxLayout *Vlform;
   QFormLayout *FormLayoutEnse;
   QPushButton *btnAjouterEnse;
   QTextEdit *DescriptionEnse;
   QString fichierEnse;
   QLineEdit *FFICHIER;
   QLabel *imageEnse;
   QPushButton *btnAjouterUneImageEnse;
   QVBoxLayout *VerticalLimEnse;
   QPushButton *Update;
   // Pour l'administrateur

   QLineEdit *nomA, *prenomA, *DateNaissanceA, *lieuNaissanceA, *fonctionA, *profession;
   QSpinBox *MatriculeA, *ContactA;
   QComboBox *diplomeA, *sexeA;

   QTableView *view, *view1;
   QStandardItemModel *model,*model1;
   QWidget *w3;
   QPushButton *btnUpdate, *btnUpdate1;

   FenetreConnexion *fenConnexion;
   QSqlDatabase *database;
};

