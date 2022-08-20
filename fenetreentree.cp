#include "fenetreentree.h"

FenetreEntree::FenetreEntree(QWidget *parent)
    : QWidget{parent}
{
    VLGeneral = new QVBoxLayout();

    onglet = new QTabWidget();
    onglet->setTabShape (QTabWidget::Triangular);
    onglet->setCursor (Qt::PointingHandCursor);

    // Construction des pages de mon Qtab

    page1 = new QWidget();
    page2 = new QWidget();
    page3 = new QWidget();
    page4 = new QWidget();

    // J'ajoute les page dans l'onglet avec addTab

    onglet ->addTab(page1,tr("Etudiant"));
    onglet ->addTab(page2,tr("Enseignant"));
    onglet ->addTab(page3,tr("Administrateur"));
    onglet ->addTab(page4,tr("Surveillant"));

    // Appel des fonctions CreerFormulaire et CreerImageBtnEtudiant

    CreerFormulaireEtudiant();
    CreerImageBtnEtudiant();

    W1 = new QWidget(); // Premier widget dans le splitter de la page 1
    W1->setLayout(FormLayout); // Il renferme le formulaire

    W2 = new QWidget(); // 2e widget dans le splitter de la page 1
    W2->setLayout(VerticalLim); // Il renferme l'image de l'étudiant

    split1 = new QSplitter(); // Splitter de la page1
    split1->addWidget(W1); split1->addWidget(w1); split1->addWidget(W2); // Ajout de trois Widget

    split3 = new QSplitter(); // Spliter Vertical comportant le splitter1 ci dessus et la table de donnée
    split3->setOrientation(Qt::Vertical); // Il est vertical

    VL3 = new QVBoxLayout(); // Layout Conteneur du splitter3 qui contient le split1 et la table

    auto scroller = new QScrollArea; // scroller->setBackgroundRole( QPalette :: Dark); // scroller->setAlignment(Qt::AlignHCenter);
    scroller->setWidget(split1); // On met le split1 dnas le scroller

    CreateTableEtudiant();

    split3->addWidget(scroller); // Et on rajoute ce widget dans le split3
    split3->addWidget(view); // On ajoute également la table de donnée

    VL3->addWidget(split3); // Puis on met ce split dans un Layout vertical
    page1->setLayout(VL3); // Et on demande à la page 1 d'utilisez le layout


    ImageEnseignant();
    FormulaireEnseignant();
    CreateTableEnseignant();

    W3 = new QWidget();
    W3->setLayout(Vlform);

    W4 = new QWidget();
    W4->setLayout(VerticalLimEnse);

    w = new QWidget();
   // vl = new QVBoxLayout();

   // vl->addWidget(groupe);
   // vl->addWidget(btnAjouterEnse,0,Qt::AlignHCenter);

    w->setLayout(vl);

    split2 = new QSplitter();
    split2->addWidget(W3);
    split2->addWidget(w);
    split2->addWidget(W4);

    split4 = new QSplitter();
    split4->setOrientation(Qt::Vertical);

    auto scroll = new QScrollArea();
    scroll->setWidget(split2);

    VL2 = new QVBoxLayout();
    split4->addWidget(scroll);
    split4->addWidget(view1);
    VL2->addWidget(split4);

    page2->setLayout(VL2);


   VLGeneral->addWidget(onglet);
   this->setLayout(VLGeneral);

}

// Création du formulaire de l'étudiant

void FenetreEntree::CreerFormulaireEtudiant()
{
    FormLayout    = new QFormLayout();
    nom = new QLineEdit();
    prenom = new QLineEdit;
    DateNaissance = new QLineEdit();
    lieu = new QLineEdit();
    Email = new QLineEdit();

    sexe = new QComboBox();
    sexe->addItem(tr("Masculin"));
    sexe->addItem(tr("Féminin"));
    sexe->addItem(tr("Autres"));

    Filiere = new QComboBox();
    Filiere->addItem(tr("ITM"));
    Filiere->addItem(tr("Informatique"));
    Filiere->addItem(tr("Télécomunication"));
    Filiere->addItem(tr("MTIC"));
    Filiere->addItem(tr("Cyber Sécurité"));
    Filiere->addItem(tr("Génie Logiciel"));


    Lycee = new QLineEdit();
    Matricule = new QSpinBox();
    salle = new QSpinBox();
    Licence = new QSpinBox();

    Description = new QTextEdit();
   // Description->append(tr("Ecole Primaire :\nEcole Secondaire :\nContact du tuteur :\nReligion :\n"
   //          "Diplôme (s) :\nEtat civile :\nNiveau en français :\nNiveau en anglais :"));


    btnAjouter = new QPushButton();
   // btnAjouter->setStyleSheet("background-color : blue");
    btnAjouter->setText(tr("Valider"));
    btnAjouter->setFont(QFont("",13));
    connect(btnAjouter, &QPushButton::clicked, this, &FenetreEntree::OnAddetudiant);


    FormLayout->addRow(tr("Matricule :"),Matricule);
    FormLayout->addRow(tr("nom :"),nom);
    FormLayout->addRow(tr("Prenom :"),prenom);
    FormLayout->addRow(tr("Date de naissance :"),DateNaissance);
    FormLayout->addRow(tr("Lieu de Naissance :"),lieu);
    FormLayout->addRow(tr("sexe"),sexe);
    FormLayout->addRow(tr("Venu du Lycée :"),Lycee);
    FormLayout->addRow(tr("Licence :"),Licence);
    FormLayout->addRow(tr("Filière :"),Filiere);
    FormLayout->addRow(tr("Salle :"),salle);
    FormLayout->addRow(tr("Email :"),Email);
    FormLayout->addRow(tr("Description"),Description);

    supprimer = new QPushButton(tr("Supprimer"));
    Restaurer = new QPushButton(tr("Restaurer"));
    precedent = new QPushButton(tr("Précédent"));
    Suivant  = new QPushButton(tr("Suivant"));
    nouveau = new QPushButton(tr("Nouveau"));
    btnUpdate = new QPushButton(tr("Mis à jour"));
    connect(btnUpdate, &QPushButton::clicked, this, &FenetreEntree::OnUpdateEtudiant);

    btnAjouterUneImage = new QPushButton();
    btnAjouterUneImage->setText(tr("Ajouter une image"));
    //btnAjouterUneImage->setStyleSheet("background-color : blue");
    connect(btnAjouterUneImage, &QPushButton::clicked, this, &FenetreEntree::OuvrirImage);
   // connect(btnUpdate, &QPushButton::clicked, this, &FenetreEntree::On);

    vlSep = new QVBoxLayout();

    vlSep->addWidget(nouveau);
    vlSep->addWidget(supprimer);
    vlSep->addWidget(Restaurer);
    vlSep->addWidget(Suivant);
    vlSep->addWidget(precedent);
    vlSep->addWidget(btnAjouterUneImage);
    vlSep->addWidget(btnUpdate);
    vlSep->addWidget(btnAjouter);
    w1 =    new QWidget();
    w1->setLayout(vlSep);

}

// Image pour étudiant

void FenetreEntree::CreerImageBtnEtudiant(){
    image = new QLabel();
    image->setPixmap(QPixmap("et1.jpeg").scaled(700,600));

    VerticalLim = new QVBoxLayout();
    VerticalLim->addWidget(image,0,Qt::AlignCenter);

}

// Formulaire pour enseignant

void FenetreEntree::FormulaireEnseignant(){

    email = new QLineEdit();
    nomEnse       = new QLineEdit();
    prenomEnse    = new QLineEdit();
    lieuEnse      = new QLineEdit();
    specialite    = new QLineEdit();
    DateNaissanceEnse = new QLineEdit();
    Contact         = new QLineEdit();
    nbreMatiere     = new QSpinBox();
    MatriculeEnse   = new QSpinBox();
    DescriptionEnse = new QTextEdit();

    sexeEnse    = new QComboBox();
    sexeEnse->addItem(tr("Masculin"));
    sexeEnse->addItem(tr("Féminin"));
    sexeEnse->addItem(tr("Autres"));

    diplome     = new QComboBox();
    diplome->addItem(tr("Doctorat"));
    diplome->addItem(tr("Licence"));;
    diplome->addItem(tr("Maitrise"));
    diplome->addItem(tr("Professorat"));


   groupe = new QGroupBox(tr("Salles tenus"));
   vlgroupe = new QVBoxLayout();
   vlgroupe->setSpacing(5);

   itm = new QCheckBox(tr("Iformatique Télécom Multimédia"));
   connect(itm,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   mtic1 = new QCheckBox(tr("Management des TIC I"));
   connect(mtic1,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   mtic2 = new QCheckBox(tr("Management des TIC 2"));
   connect(mtic2,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   mtic3 = new QCheckBox(tr("Management des TIC 3"));
   connect(mtic3,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   info2= new QCheckBox(tr("Informatique 2"));
   connect(info2,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   Genie = new QCheckBox(tr("Genie Logiciel"));
   connect(Genie,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   telecom2 = new QCheckBox(tr("Télécomunication 2"));
   connect(telecom2,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   telecom3 = new QCheckBox(tr("Télécomunication 3"));
   connect(telecom3,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   cyber = new QCheckBox(tr("Cyber sécurité"));
   connect(cyber,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   masterMtic = new QCheckBox(tr("Master Management des TIC"));
   connect(masterMtic,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);

   masterTel = new QCheckBox(tr("Master Télécomunication"));
   connect(masterTel,&QCheckBox::stateChanged,this,&FenetreEntree::ChekBox);


   vlgroupe->addWidget(itm);
   vlgroupe->addWidget(mtic1);
   vlgroupe->addWidget(mtic2);
   vlgroupe->addWidget(mtic3);
   vlgroupe->addWidget(info2);
   vlgroupe->addWidget(telecom2);
   vlgroupe->addWidget(telecom3);
   vlgroupe->addWidget(cyber);
   vlgroupe->addWidget(Genie);
   vlgroupe->addWidget(masterMtic);
   vlgroupe->addWidget(masterTel);

   groupe->setLayout(vlgroupe);
   btnAjouterEnse = new QPushButton(tr("Valider"));
   connect(btnAjouterEnse,&QPushButton::clicked,this,&FenetreEntree::OnAddEnseignant);

   vl = new QVBoxLayout();
   vl->addWidget(groupe);
   vl->addWidget(btnAjouterEnse);

    FormLayoutEnse  = new QFormLayout();
    FormLayoutEnse->addRow(tr("&Matricule"),MatriculeEnse);
    FormLayoutEnse->addRow(tr("&nom"),nomEnse);
    FormLayoutEnse->addRow(tr("&prenom"),prenomEnse);
    FormLayoutEnse->addRow(tr("&Date de Naissance"),DateNaissanceEnse);
    FormLayoutEnse->addRow(tr("&Lieu de Naissance"),lieuEnse);
    FormLayoutEnse->addRow(tr("&sexe"),sexeEnse);
    FormLayoutEnse->addRow(tr("&diplome"),diplome);
    FormLayoutEnse->addRow(tr("&Spécialité"),specialite);
    FormLayoutEnse->addRow(tr("&Contact"),Contact);
    FormLayoutEnse->addRow(tr("Nombre de Matiere prises"),nbreMatiere);
    FormLayoutEnse->addRow(tr("&Email"),email);
    FormLayoutEnse->addRow(tr("&Description"),DescriptionEnse);
    Update = new QPushButton(tr("Mis à jour"));
    connect(Update,&QPushButton::clicked,this,&FenetreEntree::OnUpdateEnseignant);
    Vlform = new QVBoxLayout();
    Vlform->addLayout(FormLayoutEnse);
    Vlform->addWidget(Update,0,Qt::AlignHCenter);

}

// Image Enseignant

void FenetreEntree::ImageEnseignant()
{
    imageEnse = new QLabel();
    imageEnse->setPixmap(QPixmap("enseignant.png").scaled(500,550));

    btnAjouterUneImageEnse = new QPushButton();
    btnAjouterUneImageEnse->setText(tr("Choisir une image"));
    //btnAjouterUneImageEnse->setStyleSheet("background-color : blue");

    connect(btnAjouterUneImageEnse, &QPushButton::clicked, this, &FenetreEntree::OuvrirImageE);

    VerticalLimEnse = new QVBoxLayout();
    VerticalLimEnse->addWidget(imageEnse,0,Qt::AlignHCenter);
    VerticalLimEnse->addWidget(btnAjouterUneImageEnse,0,Qt::AlignHCenter);
}

// Image Enseignant

void FenetreEntree::OuvrirImage(){
    fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier"," ", "Images (*.png *.gif *.jpg *.jpeg)");
    image->setPixmap(QPixmap(fichier).scaled(400,450));
    FICHIER = new QLineEdit();
    FICHIER->setText(fichier);
}

void FenetreEntree::OuvrirImageE()
{
    fichierEnse = QFileDialog::getOpenFileName(this, "Ouvrir un fichier"," ", "Images (*.png *.gif *.jpg *.jpeg)");
    imageEnse->setPixmap(QPixmap(fichierEnse).scaled(500,550 ));
    FFICHIER = new QLineEdit();
    FFICHIER->setText(fichierEnse);
}

void FenetreEntree::ShowtabSTudent()
{
    if (onglet->currentWidget() != page1){
        onglet->setCurrentWidget(page1);
    }
}

void FenetreEntree::ShowtabTich()
{
    if (onglet->currentWidget() != page2){
        onglet->setCurrentWidget(page2);
    }
}

void FenetreEntree::ShowTabAdmin()
{
    if (onglet->currentWidget() != page3){
        onglet->setCurrentWidget(page3);
    }
}

void FenetreEntree::ShowtabSurv()
{
    if (onglet->currentWidget() != page4){
        onglet->setCurrentWidget(page4);
    }
}

// Ajout d'un étudiant dans la base de données

void FenetreEntree::OnAddetudiant()
{
    QSqlQuery query = QSqlQuery(*database);
    // Réquête SQL, ici on spécifie les noms dans la base de données suivie de quelque variable (:variable)
    query.prepare ("INSERT INTO Etudiant(Nom,Prenom,DateNaissance,LieuNaissance,Sexe,Lycee,Licence,Filiere,"
    "Salle,Description,Email,Image) VALUES (:nom,:prenom,:DateNaissance, :lieu,:sexe,:Lycee,:Licence,:Filiere,:Salle,:Description,:Email,:image"");");
    // On lie les variables aux différentes attributs du formulaire
    query.bindValue (":nom",nom->text ());
    query.bindValue (":prenom",prenom->text ());
    query.bindValue (":sexe",sexe->currentText ());
    query.bindValue (":Email",Email->text ());
    query.bindValue (":DateNaissance",DateNaissance->text ());
    query.bindValue (":lieu",lieu->text ());
    query.bindValue (":Description",Description->toPlainText ());
    query.bindValue (":Filière",Filiere->currentText());
    query.bindValue (":Licence",Licence->text());
    query.bindValue (":Salle",salle->text());
    query.bindValue (":Lycee",Lycee->text());
    query.bindValue (":image",FICHIER->text());
    // Si la resuête s'éxecute, on Affiche (Ajouter)
    if (query.exec ()){
        QMessageBox::information (this,"","Ajouter");
    }else // Si non on renvoie l'erreur
        QMessageBox::critical (this,"query error",query.lastError ().text ());
}

// Accesseur de la base de données
QSqlDatabase *FenetreEntree::getDatabase() const
{
    return database;
}

// Mutateur de la base de données
void FenetreEntree::setDatabase(QSqlDatabase *newDatabase)
{
    database = newDatabase;
}

void FenetreEntree::CreateTableEtudiant()
{
    view = new QTableView();
    model = new QStandardItemModel();
    view->setModel(model);

    QStringList headLabel;
    headLabel<<tr("Id")<<tr("Nom")<<tr("Prenom")<<tr("DateN")<<tr("LieuN")<<
    tr("Sexe")<<tr("Lycee")<<tr("Licence")<<tr("Filiere")<<tr("Salle")<<tr("Description")<<tr("Email")<<tr("Image");
    model->setHorizontalHeaderLabels(headLabel);
}

void FenetreEntree::CreateTableEnseignant()
{
    view1 = new QTableView();
    model1 = new QStandardItemModel();
    view1->setModel(model1);

    QStringList headLabel;
    headLabel<<tr("Id")<<tr("Nom")<<tr("Prenom")<<tr("DateN")<<tr("LieuN")<<
    tr("Sexe")<<tr("Diplôme")<<tr("Spécialité")<<tr("Contact")<<tr("NbreMatieres")<<tr("Matières")<<tr("Email")<<tr("Description")<<tr("Image");
    model1->setHorizontalHeaderLabels (headLabel);
}

void FenetreEntree::OnUpdateEtudiant(){
    QSqlQuery query = QSqlQuery(*database);
    if (query.exec("SELECT * FROM Etudiant;")){
        model = new QStandardItemModel();
        QStringList headLabel;
        headLabel<<tr("Id")<<tr("Nom")<<tr("Prenom")<<tr("DateN")<<tr("LieuN")<<
        tr("Sexe")<<tr("Lycee")<<tr("Licence")<<tr("Filiere")<<tr("Salle")<<tr("Description")<<tr("Email")<<tr("Image");
        model->setHorizontalHeaderLabels (headLabel);
        while(query.next()){

            QList<QStandardItem*> lsItem;
            QString Matricule = query.value("Matricule").toString();
            QString nom = query.value("nom").toString();
            QString prenom = query.value("prenom").toString();
            QString sexe = query.value("sexe").toString();
            QString Email = query.value("Email").toString();
            QString DateNaissance = query.value("DateNaissance").toString();
            QString lieu = query.value("LieuNaissance").toString();
            QString Description = query.value("Description").toString();
            QString Filiere = query.value("Filiere").toString();
            QString Licence = query.value("Licence").toString();
            QString salle = query.value("salle").toString();
            QString Lycee = query.value("Lycee").toString();
            QString image = query.value("image").toString();

            lsItem<<new QStandardItem(Matricule);
            lsItem<<new QStandardItem(nom);
            lsItem<<new QStandardItem(prenom);
            lsItem<<new QStandardItem(DateNaissance);
            lsItem<<new QStandardItem(lieu);
            lsItem<<new QStandardItem(sexe);
            lsItem<<new QStandardItem(Lycee);
            lsItem<<new QStandardItem(Licence);
            lsItem<<new QStandardItem(Filiere);
            lsItem<<new QStandardItem(salle);
            lsItem<<new QStandardItem(Description);
            lsItem<<new QStandardItem(Email);
            lsItem<<new QStandardItem(image);


            model->appendRow(lsItem);
        }

        view->setModel(model);
    }
    else
        QMessageBox::critical (this, "Error", "Erreur d'execution"+ query.lastError ().text ());
}


void FenetreEntree::ChekBox(){

    if (itm->isChecked()){
     matiere.append("Itm");
    }
    //}if (mtic1->isChecked()){
    // matiere->append("\n"+ mtic1->text());
    //} if (info2->isChecked()){
    // matiere->append("\n"+ info2->text());
    //} if (telecom2->isChecked()){
    // matiere->append("\n"+ mtic1->text());
    //} if (telecom3->isChecked()){
    // matiere->append("\n"+ telecom3->text());
    //} if (mtic2->isChecked()){
    // matiere->append("\n"+ mtic2->text());
    //} if (mtic3->isChecked()){
    // matiere->append("\n"+ mtic3->text());
    //} if (cyber->isChecked()){
    // matiere->append("\n"+ cyber->text());
    //} if (Genie->isChecked()){
    // matiere->append("\n"+ Genie->text());
    //} if (masterMtic->isChecked()){
    // matiere->append("\n"+ masterMtic->text());
    //} if (masterTel->isChecked()){
    //    matiere->append("\n"+ masterTel->text());
    //}
}

void FenetreEntree::OnAddEnseignant()
{
    QSqlQuery querry = QSqlQuery(*database);
    // Réquête SQL, ici on spécifie les noms dans la base de données suivie de quelque variable (:variable)
    querry.prepare ("INSERT INTO Enseignant(Nom,Prenom,DateNaissance,LieuNaissance,Sexe,Diplome,Specialite,Contact,"
    "NbreMat,Matiere,Email,Description,Image) VALUES (:noM,:prenoM,:DateNaissancE,:lieU,:sexE,:diplomE,:specialitE,:contacT,:nbreMaT,:matierE,:EmaiL,:descriptioN,:imagE"");");
    // On lie les variables aux différentes attributs du formulaire

    querry.bindValue (":noM",nomEnse->text ());
    querry.bindValue (":prenoM",prenomEnse->text ());
    querry.bindValue (":sexE",sexeEnse->currentText ());
    querry.bindValue (":EmaiL",email->text ());
    querry.bindValue (":DateNaissancE",DateNaissanceEnse->text ());
    querry.bindValue (":lieU",lieuEnse->text ());
    querry.bindValue (":descriptioN",DescriptionEnse->toPlainText ());
    querry.bindValue (":diplomE",diplome->currentText());
    querry.bindValue (":specialitE",specialite->text());
    querry.bindValue (":nbreMaT",nbreMatiere->text());
    querry.bindValue (":matierE",matiere);
    querry.bindValue (":imagE",FFICHIER->text());
    querry.bindValue (":contacT",Contact->text());

    // Si la resuête s'éxecute, on Affiche (Ajouter)
    if (querry.exec ()){
        QMessageBox::information (this,"","Ajouter");
    }else // Si non on renvoie l'erreur
        QMessageBox::critical (this,"query error",querry.lastError ().text ());
}

void FenetreEntree::OnUpdateEnseignant()
{
    QSqlQuery query = QSqlQuery(*database);
    if (query.exec("SELECT * FROM Enseignant;")){
        model1 = new QStandardItemModel();
        QStringList headLabel;
            headLabel<<tr("Id")<<tr("Nom")<<tr("Prenom")<<tr("DateN")<<tr("LieuN")<<
             tr("Sexe")<<tr("Dipôme")<<tr("Spécialité")<<tr("Contact")<<tr("NbreMatieres")<<tr("Matières")<<tr("Email")<<tr("Description")<<tr("Image");
        model1->setHorizontalHeaderLabels (headLabel);
        while(query.next()){

            QList<QStandardItem*> lsItem;
            QString Matricule = query.value("Matricule").toString();
            QString nom = query.value("Nom").toString();
            QString prenom = query.value("Prenom").toString();
            QString sexe = query.value("Sexe").toString();
            QString Email = query.value("Email").toString();
            QString DateNaissance = query.value("DateNaissance").toString();
            QString lieu = query.value("LieuNaissance").toString();
            QString Description = query.value("Description").toString();
            QString diplome = query.value("Diplome").toString();
            QString specialite = query.value("Specialite").toString();
            QString matieres = query.value("Matiere").toString();
            QString contact = query.value("Contact").toString();
            QString image = query.value("Image").toString();
            QString nbremat = query.value("NbreMat").toString();

            lsItem<<new QStandardItem(Matricule);
            lsItem<<new QStandardItem(nom);
            lsItem<<new QStandardItem(prenom);
            lsItem<<new QStandardItem(DateNaissance);
            lsItem<<new QStandardItem(lieu);
            lsItem<<new QStandardItem(sexe);
            lsItem<<new QStandardItem(diplome);
            lsItem<<new QStandardItem(specialite);
            lsItem<<new QStandardItem(contact);
            lsItem<<new QStandardItem(nbremat);
            lsItem<<new QStandardItem(matieres);
            lsItem<<new QStandardItem(Email);
            lsItem<<new QStandardItem(Description);
            lsItem<<new QStandardItem(image);


            model1->appendRow(lsItem);
        }

        view1->setModel(model1);
    }
    else
        QMessageBox::critical (this, "Error", "Erreur d'execution"+ query.lastError ().text ());
}
