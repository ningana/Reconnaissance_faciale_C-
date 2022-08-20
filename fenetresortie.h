#pragma once

#include <QWidget>
#include <QtWidgets>

class FenetreSortie : public QWidget
{
    Q_OBJECT
public:
    explicit FenetreSortie(QWidget *parent = nullptr);
    void CreateInformationEtu();
    void CreateInformationEns();
    void CreateTableEtudiant();
    void CreateTableRnseignant();
    void CreateImageEtudiant();
    void CreateImageEnseignant();
public slots :
    void OuvrirImageEtudiant();
    void OuvrirImageEnseignant();
private :
    QVBoxLayout *LayoutGeneral;
    QTabWidget *onglets;
    QWidget *page5, *page6, *page7, *page8;
    QWidget *W5, *W6, *W7, *W8;
    QSplitter *split5, *split6, *split7,*split8;
    QVBoxLayout *VL5, *VL6;
    QScrollArea *scroll4, *scroll5;

    // Page Etudiant

    QTextEdit *Information1;
    QVBoxLayout *Linf1;
    QSpinBox  *Matricule4;
    QPushButton *ChoosePicture;
    QPushButton *Recherche;
    QHBoxLayout *Hbox1;
    QVBoxLayout *Vbox1;
    // page Enseignant
    QVBoxLayout *Linf2;
    QTextEdit *Information2;
    QSpinBox *Matricule5;
    QPushButton *ChoosePicture2;
    QPushButton *Recherche2;
    QHBoxLayout *Hbox2;
    QVBoxLayout *Vbox2;
    // Table Etudiant

    QTableView *view3;
    QStandardItemModel *model3;


    // Table Enseignant

    QTableView *view2;
    QStandardItemModel *model2;

    // Image enseignant

    QLabel *IMAGEENSE;
    QVBoxLayout *VerticalLimEnse;
    QString FICHIERENSE;

    // Image Etudiant

    QString FICHIER;
    QLabel *IMAGE3;
    QVBoxLayout *VerticalLimageEtudiant;


    QFormLayout *form;
    QFormLayout *formu;

};

