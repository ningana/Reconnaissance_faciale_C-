#include "fenetreprincipale.h"


FenetrePrincipale::FenetrePrincipale(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Reconnaissance d'image ~ Ningana Jacques"));
    CreateWelcomFen();
    CreerSousfenetre();
    CreerAction();
    CreerMenu();
    CreerBarOutils();
    CreerDialogueEtudiant();
    CreerDialogueEnseignant();
    CreerDialogueAdministrateur();
    CreerDialogueSurveillant();
    CreateInf1();   // Information Etudiant dans la seconde boite
    CreateInf2();  // Information Esneignant dans la seconde boite
    CreateInf3(); // Information administrateur dans la seconde boite
    CreateInf4();// Information Enseignant dans la seconde boite
}

// Destructeur

FenetrePrincipale::~FenetrePrincipale()
{
}

// Creation d'action

void FenetrePrincipale::CreerAction()
{
    // Action Parametre

    parametre = new QAction();
    parametre->setIcon (QIcon("parametre.jpeg"));
    parametre->setToolTip (tr("Parametre"));

    // Axtion parametre dans la barre menu


    Parametre = new QAction();

    //Action calculatrice

    calculatrice = new QAction();
    calculatrice->setIcon (QIcon("calcul.jpeg"));
    calculatrice->setText (tr("Calculatrice"));
    calculatrice->setToolTip (tr("Cliquez pour calculer"));

    // Action Internet

    internet = new QAction();
    internet->setIcon (QIcon("net.jpeg"));
    internet->setText (tr("Internet"));
    internet->setToolTip (tr("Cliquez pour vous connecter"));

    // Action Bloc notes

    blocNote = new QAction();
    blocNote->setIcon (QIcon("note.jpeg"));
    blocNote->setText (tr("Bloc note"));
    blocNote->setToolTip (tr("Cliquez pour editer un texte"));

    // Action login

    login = new QAction();
    login->setIcon (QIcon("alogin.jpg"));
    login->setToolTip (tr("Fenetre connexion"));

    //connect (login,&QAction::triggered,this,&FenetrePrincipale::AfficheFenConnexion);

    aproposDuDeveloppeur = new QAction(tr("apropos du Dévelopeur"));
    aproposDuDeveloppeur->setIcon(QIcon("developper.jpeg"));
    connect (aproposDuDeveloppeur, &QAction::triggered, this, &FenetrePrincipale::OuvrirNingana);

    aproposDelAppli = new QAction(tr("apropos de l'application"));
    aproposDelAppli->setIcon(QIcon("about.png"));
    connect (aproposDelAppli, &QAction::triggered, this, &FenetrePrincipale::OuvrirApropos);

    aproposDelEnastic = new QAction(tr("apropos de l'énastic"));
    aproposDelEnastic->setIcon(QIcon("aboutenastic.jpg"));
    connect (aproposDelEnastic, &QAction::triggered, this, &FenetrePrincipale::OuvrirEnastic);

    // Action dans Menu Fichier

    quitter = new QAction(tr("Quitter"));
    quitter->setIcon (QIcon("aquitter.png"));
    quitter->setToolTip (tr("Ctrl+Q pour quitter"));
    quitter->setShortcut (QKeySequence("Ctrl+Q"));
    connect (quitter, &QAction::triggered, this, &FenetrePrincipale::Quitter);

    Newfile = new QAction(tr("Nouveau fichier"));
    Newfile->setIcon(QIcon("new-fileicon.png"));
    Newfile->setShortcut(QKeySequence("Ctrl+N"));
    Newfile->setStatusTip(tr("Cliquez pour créer un nouveau fichier"));

    openFIle = new QAction(tr("Ouvrir un fichier"));
    openFIle->setShortcut(QKeySequence("Ctrl+o"));
    openFIle->setIcon(QIcon("open-file.png"));

    toutEnregister = new QAction(tr("Tout Sauvegarder"));
    toutEnregister ->setShortcut(QKeySequence("Ctrl+Maj+s"));
    toutEnregister ->setIcon(QIcon("save2.jpg"));


    imprimer = new QAction(tr("Imprimer"));
    imprimer->setIcon(QIcon("impression.jpg"));
    imprimer->setShortcut(QKeySequence("Ctrl+p"));
    connect(imprimer,&QAction::triggered, this, &FenetrePrincipale::Imprimer);

    // Action tout fermer dans menu fichier

    toutFermer= new QAction(tr("Tout fermer"));

    // Actions du menu Edition

    refaire = new QAction(tr("Undo"));
    refaire->setIcon(QIcon("undo.png"));
    refaire->setShortcut(QKeySequence("Ctrl+z"));

    retour = new QAction(tr("Redo"));
    retour->setIcon(QIcon("redo.png"));
    retour->setShortcut(QKeySequence("Ctrl+y"));

    couper = new QAction(tr("Couper"));
    couper->setIcon(QIcon("couper.png"));
    couper->setShortcut(QKeySequence("Ctrl+x"));

    copier = new QAction(tr("Copier"));
    copier->setIcon(QIcon("copy.png"));
    copier->setShortcut(QKeySequence("Ctrl+c"));

    coller = new QAction(tr("Coller"));
    coller->setIcon(QIcon("coller.jpeg"));
    coller->setShortcut(QKeySequence("Ctrl+v"));

    supprimer = new QAction(tr("Supprimer"));
    supprimer->setShortcut(QKeySequence("Suppr"));

    Eetudiant = new QAction(tr("Etudiant"));
    connect(Eetudiant, &QAction::triggered, this, &FenetrePrincipale::AfficheFenEetudiant);
    Eetudiant->setShortcut(QKeySequence("Ctrl+shift+E"));
    Eetudiant->setIcon(QIcon("etu.png"));


    Eenseignant = new QAction(tr("Enseignant"));
    connect(Eenseignant, &QAction::triggered, this, &FenetrePrincipale::AfficheFenEenseignant);
    Eenseignant->setShortcut(QKeySequence("Ctrl+Alt+E"));
    Eenseignant->setIcon(QIcon("enseignant.png"));


    Eadministrateur = new QAction(tr("Administrateur"));
    connect(Eadministrateur, &QAction::triggered, this, &FenetrePrincipale::AfficheFenAdministrateur);
    Eadministrateur->setShortcut(QKeySequence("Ctrl+alt+A"));
    Eadministrateur->setIcon(QIcon("admin.png"));



    Esurveillant = new QAction(tr("Surveillant"));
    connect(Esurveillant, &QAction::triggered, this, &FenetrePrincipale::AfficheFenEsurveillant);
    Esurveillant->setShortcut(QKeySequence("Ctrl+shift+S"));
    Esurveillant->setIcon(QIcon("surv.png"));


    aConnexion = new QAction();
    aConnexion->setToolTip(tr("Cliquez pour vous connectez"));
    aConnexion->setShortcut(QKeySequence("ctrl+alt+c"));

    //Action dans menuRechercher

    rEtudiant = new QAction(tr("Etudiant"));
    rEtudiant->setIcon(QIcon("etu.png"));
    rEtudiant->setShortcut(QKeySequence("alt+shift+e"));
    connect(rEtudiant,&QAction::triggered,this,&FenetrePrincipale::OuvrirDialog1);

    renseignant = new QAction(tr("Enseignant"));
    renseignant->setIcon(QIcon("enseignant.png"));
    renseignant->setShortcut(QKeySequence("alt+shift+t"));
    connect(renseignant,&QAction::triggered,this,&FenetrePrincipale::OuvrirDialog2);

    radministrateur = new QAction(tr("Administrateur"));
    radministrateur->setIcon(QIcon("admin.png"));
    radministrateur->setShortcut(QKeySequence("ctrl+shift+a"));
    connect(radministrateur,&QAction::triggered,this,&FenetrePrincipale::OuvrirDialog3);

    rsurveillant = new QAction(tr("Surveillant"));
    rsurveillant->setIcon(QIcon("surv.png"));
    rsurveillant->setShortcut(QKeySequence("ctrl+alt+s"));
    connect(rsurveillant,&QAction::triggered,this,&FenetrePrincipale::OuvrirDialog4);

    // Acceuille

    aAcceuille = new QAction();
    aAcceuille->setToolTip(tr("Accueille"));
    aAcceuille->setIcon(QIcon("welcome.jpeg"));
    connect(aAcceuille,&QAction::triggered,this,&FenetrePrincipale::AfficheFenAcceuille);

    aEnregistrement = new QAction();
    aEnregistrement->setToolTip(tr("Enregistrement"));
    aEnregistrement->setIcon(QIcon("w.png"));
    connect(aEnregistrement,&QAction::triggered,this,&FenetrePrincipale::AfficheFenEetudiant);


    aRechercher = new QAction();
    aRechercher->setToolTip(tr("Recherche"));
    aRechercher->setIcon(QIcon("search.png"));
    connect(aRechercher,&QAction::triggered,this,&FenetrePrincipale::OuvrirDialog1);

    aAide = new QAction();
    aAide->setToolTip(tr("Aide"));
    aAide->setIcon(QIcon("aide.png"));
    //connect(aRechercher,&QAction::triggered,this,&FenetrePrincipale::AfficheDialogueAide);

    connexion = new QAction();
    connexion->setToolTip(tr("Connexion"));
    connexion->setIcon(QIcon("alogin.jpg"));
    connect(connexion, &QAction::triggered, this, &FenetrePrincipale::AfficheFenConnexion);

    Adaptic = new QAction();
    Irrorater = new QAction();
    Medize = new QAction();
    Darkeum = new QAction();
    Fibers = new QAction();
    Integrid = new QAction();

}

// Creation de Menu

void FenetrePrincipale::CreerMenu()
{
    menuFichier = new QMenu();
    menuEdition = new QMenu();
    menuOutils = new QMenu();
    menuAide = new QMenu();
    menuParametre = new QAction();
    menuSaisie = new QMenu();
    menuRechercher = new QMenu();

    //Ajout des menu dans le menuBar

    menuFichier = menuBar ()->addMenu (tr("&Fichier"));
    menuEdition = menuBar ()->addMenu (tr("&Edition"));
    menuOutils = menuBar ()->addMenu (tr("&Outils"));
    menuAide = menuBar ()->addMenu (tr("&Aide"));
    menuParametre = menuBar()->addAction(tr("&Parametre"));
    menuSaisie = menuBar()->addMenu(tr("&Enregistrement"));
    menuRechercher = menuBar()->addMenu(tr("&Rechercher"));

    // Ajout des actions dans le menuSaisie

    menuSaisie->addAction(Eetudiant);
    menuSaisie->addAction(Eenseignant);
    menuSaisie->addAction(Eadministrateur);
    menuSaisie->addAction(Esurveillant);

    // AJout des actions dans le menu Rechercher

    menuRechercher->addAction(rEtudiant);
    menuRechercher->addAction(renseignant);
    menuRechercher->addAction(radministrateur);
    menuRechercher->addAction(rsurveillant);

    // Ajout de l'action connexion dans le menuBar

    aConnexion = menuBar()->addAction(tr("&Connexion"));
    connect(aConnexion, &QAction::triggered, this, &FenetrePrincipale::AfficheFenConnexion);

    // Ajout des actions dans Outils

    menuOutils->addAction (calculatrice);
    menuOutils->addAction (internet);
    menuOutils->addAction (blocNote);

    // AJout dans Fichier

    menuFichier->addAction(Newfile);
    menuFichier->addAction(openFIle);
    menuFichier->addAction(toutEnregister);
    menuFichier->addAction(imprimer);
    menuFichier->addAction (quitter);

    // Ajout dans Aide

    menuAide->addAction(aproposDelAppli);
    menuAide->addAction(aproposDuDeveloppeur);
    menuAide->addAction(aproposDelEnastic);

    // Ajout dans Edition

    menuEdition->addAction(refaire);
    menuEdition->addAction(retour);
    menuEdition->addAction(couper);
    menuEdition->addAction(copier);
    menuEdition->addAction(coller);
    menuEdition->addAction(supprimer);


    menuBar()->hide();
    menuBar()->setEnabled(false);
    //menuFichier->setEnabled(false);
    //menuEdition->setEnabled(false);
    //menuAide->setEnabled(false);
    //menuOutils->setEnabled(false);
    //menuParametre->setEnabled(false);
    //menuConnexion->setEnabled(false);
    //menuRechercher->setEnabled(false);
    //menuSaisie->setEnabled(false);
}


// Creation de bar à outils

void FenetrePrincipale::CreerBarOutils()
{
    BarOutils = new QToolBar();
    BarOutils->setMovable(false);
    addToolBar(BarOutils);
    BarOutils->addAction(aAcceuille);
    BarOutils->addAction(aEnregistrement);
    BarOutils->addAction(aRechercher);
    BarOutils->addAction(connexion);
    BarOutils->addAction(parametre);
    BarOutils->addAction(aAide);
    BarOutils->addSeparator();

    auto *enastic = new QLabel();
    enastic->setPixmap(QPixmap("logo.png").scaled(400,40));
    BarOutils->addWidget(enastic);

    BarOutils->setEnabled(false);
    BarOutils->hide();
}


void FenetrePrincipale::CreateWelcomFen()
{
    FenAcceuille = new QWidget();

    Image1 = new QGraphicsPixmapItem();
    Image1->setPixmap(QPixmap("face5.jpg").scaled(1330,545));

   // Image2 = new QGraphicsPixmapItem();
   // Image2->setPixmap(QPixmap("Tel1.jpg").scaled(665,560));

    scene1 = new QGraphicsScene();
    scene1->addItem(Image1);

   // scene2 = new QGraphicsScene();
   // scene2->addItem(Image2);

    Gra1 = new QGraphicsView();
    Gra1->setScene(scene1);

   // Gra2 = new QGraphicsView();
   // Gra2->setScene(scene2);


    Innovation = new QLabel();
    Innovation->setText(tr("                                   "
                           "                                    "
                           "L'intelligence Artificiele au coeur de notre vie"));
    Innovation->setFont(QFont("Comic Sans Ms",20,QFont::Bold,true));
    //Innovation->setStyleSheet("background-color : red");

    auto *vlLayout = new QVBoxLayout();
   // auto *Split = new QSplitter();

   // auto *hlayout = new QHBoxLayout();
   // hlayout->addWidget(Gra1);
   // hlayout->addWidget(Gra2);

   // Split->addWidget(Gra1);
   // Split->addWidget(Gra2);

    vlLayout->addWidget(Innovation);
    vlLayout->addWidget(Gra1);

    FenAcceuille->setLayout(vlLayout);
}

// Creation des Sousfenetres

void FenetrePrincipale::CreerSousfenetre()
{
    // Création dees sous classes
    Fenetrecentrale = new QStackedWidget(); // Contiendra toutes les autres fenetres
    FenConnexion = new FenetreConnexion();
    FenEntree = new FenetreEntree();

    // Label à mettre dans le status Bar
    auto labelStatus = new QLabel("Déconnecté");
    labelStatus->setFont(QFont(" ",15));
    statusBar()->addWidget(labelStatus);

    // Création d'un pointer sur this, puisque this ne peut jamais etre transmis en argument dans
    auto me = this;

    // Connexio au slot isCreated en use le signal onConnected dans la fenetre de Connexion, se signal est émis dès que la base de donnée est crée
    connect(FenConnexion, &FenetreConnexion::onConnected, [me, labelStatus](bool isCreated){
        /*if(isCreated){
            me->BarOutils->setEnabled(true);
        }else
            me->BarOutils->setEnabled(false);
            */
        if(isCreated){ // si c'est connecté
            me->Fenetrecentrale->setCurrentWidget(me->FenAcceuille); // On affiche la fenetre d'acceuil
            labelStatus->setText("Connecté"); // Et le status Change
        }else{
            labelStatus->setText("Deconnecté");
        }
        me->BarOutils->setEnabled(isCreated);
        me->menuBar()->setEnabled(isCreated);
        me->BarOutils->show();
        me->menuBar()->show();
        //me->menuEdition->setEnabled(isCreated);
        //me->menuAide->setEnabled(isCreated);
        //me->menuOutils->setEnabled(isCreated);
        //me->menuParametre->setEnabled(isCreated);
        //me->menuConnexion->setEnabled(isCreated);
        //me->menuRechercher->setEnabled(isCreated);
        //me->menuSaisie->setEnabled(isCreated);
    });
    FenEntree->setDatabase(FenConnexion->getDatabase());

    // Ajout des fenetres dans le QstackedWidget

    Fenetrecentrale->addWidget(FenConnexion);
    Fenetrecentrale->addWidget(FenEntree);
    Fenetrecentrale->addWidget(FenAcceuille);

    this->setDatabase(FenConnexion->getDatabase());
    // Par defaut, la fenetre s'ouvre sur La fenetre Entreé

    Fenetrecentrale->setCurrentWidget(FenConnexion);

    // Status de la fenetre

   // status = new QLabel();
   // status->setFont (QFont("",13));
   // statusBar ()->addWidget (status);
   // if(FenConnexion->getDatabase()->isOpen()){
   //     status->setText("<h4>Connecté<h4>");
   // }
   // status->setText (tr("<h4>Déconnecter</h4>"));

    // On demande à la fenetre principale d'utiliser le stacked Widget

    this->setCentralWidget(Fenetrecentrale);
}

// Méthode pour quitter la fenetre

void FenetrePrincipale::Quitter()
{
    int Answer = QMessageBox::question (this,tr("Quitter"),tr("Voulez vous vraiment quitter?"),QMessageBox::No | QMessageBox::Yes);
    if (Answer==QMessageBox::Yes){
        qApp->quit ();
    }
}

// Le tabWidget de la boite de dialogue est d'abors invisible, il le sera quand on cliquera sur le boutton option

void FenetrePrincipale::TabwidgetInvisible()
{
    //Construction du tab

    tab = new QTabWidget();
    tab->setTabShape (QTabWidget::Triangular);
    tab->setCursor (Qt::PointingHandCursor);

    p1 = new QWidget(); p2 = new QWidget(); //Construction de deux Widget

    //Ajout des widgets dans le tabWidget

    tab->addTab(p1,tr("Copies"));    tab->addTab(p2,tr("Options"));
    //Construction du GroupeBox
    G1 = new QGroupBox(tr("Imprimer la selection")); // Ce groupeBox Utilisera un layout Vertical (contenu=QradioBox+Qlinedit)

    // Construction de trois boutton radio R1, R2, R3

    R1 = new QRadioButton(tr("Imprimer tout"));
    R2 = new QRadioButton(tr("Pages de"));
    R3 = new QRadioButton(tr("Pages"));

    // Construction des deux spinbox ( impremer de S1 à S2

    s1 = new QSpinBox();
    s2 = new QSpinBox();

    QLabel *label = new QLabel(tr("à")); // Label "à" parmi les spinBox

    h6 = new QHBoxLayout(); // Layout contenaire

    h6->addWidget(R2);
    h6->addWidget(s1);
    h6->addWidget(label);
    h6->addWidget(s2);

    page = new QLineEdit();
    h7 = new QHBoxLayout(); // Layout horizontal qui contiendra le radio Page suivi du Qlinedit
    h7->addWidget(R3); h7->addWidget(page); // Ajout des deux widgets, R3 et page(Qlinedit)

    config2 = new QComboBox();
    //config2->setMask()
    config2 ->addItem(tr("Toutes les pages"));
    config2 ->addItem(tr("Page actuelle"));

    QLabel *l= new QLabel(tr("Configuration de la page: "));
    h8 = new QHBoxLayout();
    h8->addWidget(l); h8->addWidget(config2);
    v1 = new QVBoxLayout(); // Conteneur de la premiere section, utilisé par G1
    v1->addWidget(R1);
    v1->addLayout(h6);
    v1->addLayout(h7);
    v1->addLayout(h8);

    G1->setLayout(v1);


    G2 = new QGroupBox(tr("Paramètre de sortie"));

    s3 = new QSpinBox();

    QLabel *lab = new QLabel(tr("Copies")); // Label Copies :

     h9 = new QHBoxLayout(); // Contenuer du label lab et du spinBOx s3
     h9->addWidget(lab); h9->addWidget(s3);

     ch1 = new QCheckBox(tr("Assembler"));
     ch1->setChecked(true);

    ch2 = new QCheckBox(tr("Ordre inverser"));

    v2 = new QVBoxLayout();

    v2->addLayout(h9);
    v2->addWidget(ch1);
    v2->addWidget(ch2);

    G2->setLayout(v2);


    h10 = new QHBoxLayout();

    h10 ->addWidget(G1);
    h10 ->addWidget(G2);


    p1->setLayout(h10);
    tab->hide();
    /*Le tabwidget et son contenu est caché à l'avance, il sera visible des quon clic sur le bouton option
     On pouvait use setVisible(false)
     */

}

void FenetrePrincipale::CreerDialogueEtudiant()
{
    dialog1 = new QDialog(this);
    dialog1->setWindowTitle(tr("Rechercher un etudiant"));
    dialog1->setFixedSize(400,500);
    hbox1 = new QHBoxLayout();
    auto *form1 = new QFormLayout();

    Matricule1 = new QSpinBox();
    CHooseIm1 = new QPushButton(tr("Choisir une image"));
    Recherche1=  new QPushButton();
    connect(Recherche1,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirDialog5);
    connect(CHooseIm1,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirImage1);

    image1 = new QLabel();
    image1->setPixmap(QPixmap("et1.jpeg").scaled(400,500));

    Recherche1->setIcon((QIcon("search.png")));

    form1->addRow(tr("Matricule"),Matricule1);

    hbox1->addLayout(form1);
    hbox1->addWidget(CHooseIm1);
    hbox1->addWidget(Recherche1);

    vbox1 = new QVBoxLayout();
    vbox1->addLayout(hbox1);
    vbox1->addWidget(image1);

    dialog1->setLayout(vbox1);

}

void FenetrePrincipale::CreerDialogueEnseignant()
{
    dialog2 = new QDialog(this);
    dialog2->setWindowTitle(tr("Rechercher un enseignant"));
    dialog2->setFixedSize(400,550);
    hbox2 = new QHBoxLayout();
    auto *form2 = new QFormLayout();

    Matricule2 = new QSpinBox();
    CHooseIm2= new QPushButton(tr("Choisir une image"));
    Recherche2=  new QPushButton();
    connect(Recherche2,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirDialog6);
    connect(CHooseIm2,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirImage2);

    image2 = new QLabel();
    image2->setPixmap(QPixmap("enseignant.png").scaled(400,500));

    Recherche2->setIcon((QIcon("search.png")));

    form2->addRow(tr("Matricule"),Matricule2);

    hbox2->addLayout(form2);
    hbox2->addWidget(CHooseIm2);
    hbox2->addWidget(Recherche2);

    vbox2 = new QVBoxLayout();
    vbox2->addLayout(hbox2);
    vbox2->addWidget(image2);

    dialog2->setLayout(vbox2);

}

void FenetrePrincipale::CreerDialogueAdministrateur()
{
    dialog3 = new QDialog(this);
    dialog3->setWindowTitle(tr("Rechercher un administrateur"));
    dialog3->setFixedSize(400,550);
    hbox3 = new QHBoxLayout();
    auto *form3 = new QFormLayout();

    Matricule3= new QSpinBox();
    CHooseIm3= new QPushButton(tr("Choisir une image"));
    Recherche3=  new QPushButton();
    connect(Recherche3,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirDialog7);
    connect(CHooseIm3,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirImage3);

    image3 = new QLabel();
    image3->setPixmap(QPixmap("admin.png").scaled(400,500));

    Recherche3->setIcon((QIcon("search.png")));

    form3->addRow(tr("Matricule"),Matricule3);

    hbox3->addLayout(form3);
    hbox3->addWidget(CHooseIm3);
    hbox3->addWidget(Recherche3);

    vbox3 = new QVBoxLayout();
    vbox3->addLayout(hbox3);
    vbox3->addWidget(image3);

    dialog3->setLayout(vbox3);
}

void FenetrePrincipale::CreerDialogueSurveillant()
{
    dialog4 = new QDialog(this);
    dialog4->setWindowTitle(tr("Rechercher un surveillant"));
    dialog3->setFixedSize(400,550);
    hbox4 = new QHBoxLayout();
    auto *form4 = new QFormLayout();

    Matricule4= new QSpinBox();
    CHooseIm4= new QPushButton(tr("Choisir une image"));
    Recherche4=  new QPushButton();
    connect(Recherche4,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirDialog8);
    connect(CHooseIm4,&QPushButton::clicked,this,&FenetrePrincipale::OuvrirImage4);

    image4 = new QLabel();
    image4->setPixmap(QPixmap("surv.png").scaled(400,500));

    Recherche4->setIcon((QIcon("search.png")));

    form4->addRow(tr("Matricule"),Matricule4);

    hbox4->addLayout(form4);
    hbox4->addWidget(CHooseIm4);
    hbox4->addWidget(Recherche4);

    vbox4 = new QVBoxLayout();
    vbox4->addLayout(hbox4);
    vbox4->addWidget(image4);

    dialog4->setLayout(vbox4);
}


void FenetrePrincipale::CreateInf1(){

    dialog5 = new QDialog();

    auto *hb1 = new QHBoxLayout();
    //auto *vb1 = new QVBoxLayout();
    //auto *vb2 = new QVBoxLayout();

    image5 = new QLabel();
    image5->setPixmap(QPixmap("et1.jpeg").scaled(300,250));

    text1 = new QTextEdit();
   // text1->setPlainText(informationEtudiant);
    text1->setReadOnly(true);

   // vb1->addWidget(text1);
   // vb2->addWidget(image5);

    //wi1 = new QWidget();
    //wi1->setLayout(vb1);

   // wi2 = new QWidget();
   // wi2->setLayout(vb2);

    //splitt1 = new QSplitter();
    //splitt1->addWidget(wi1);
    //splitt1->addWidget(wi2);

    //scrrol1 = new QScrollArea();
    //scrrol1->setWidget(splitt1);

    hb1->addWidget(text1);
    hb1->addWidget(image5);
    dialog5->setLayout(hb1);
}

void FenetrePrincipale::CreateInf2()
{
    dialog6 = new QDialog();

    auto *hb2 = new QHBoxLayout();

    image6 = new QLabel();
    image6->setPixmap(QPixmap("et1.jpeg").scaled(300,250));

    text2 = new QTextEdit();
    text2->setReadOnly(true);

    hb2->addWidget(text2);
    hb2->addWidget(image6);

    dialog6->setLayout(hb2);

}

void FenetrePrincipale::CreateInf3()
{
    dialog7 = new QDialog();
    dialog7->setWindowTitle(tr("Tout savoir sur ..."));

    auto *hb3 = new QHBoxLayout();
    auto *vb3 = new QVBoxLayout();
    auto *vb23 = new QVBoxLayout();

    image7 = new QLabel();
    image7->setPixmap(QPixmap("et1.jpeg"));

    text3 = new QTextEdit();
   // text3->setPlainText(informationEtudiant);
    text3->setReadOnly(true);

    vb3->addWidget(text3);
    vb23->addWidget(image7);

    wi5 = new QWidget();
    wi5->setLayout(vb3);

    wi6 = new QWidget();
    wi6->setLayout(vb23);

    splitt3 = new QSplitter();
    splitt3->addWidget(wi5);
    splitt3->addWidget(wi6);

    scrrol3 = new QScrollArea();
    scrrol3->setWidget(splitt3);
    hb3->addWidget(scrrol3);
    dialog7->setLayout(hb3);
}

void FenetrePrincipale::CreateInf4()
{
    dialog8 = new QDialog();
    dialog8->setWindowTitle(tr("Tout savoir sur ..."));

    auto *hb4 = new QHBoxLayout();
    auto *vb4 = new QVBoxLayout();
    auto *vb24 = new QVBoxLayout();

    image8 = new QLabel();
    image8->setPixmap(QPixmap("et1.jpeg"));

    text4 = new QTextEdit();
   // text4->setPlainText(informationEtudiant);
    text4->setReadOnly(true);

    vb4->addWidget(text4);
    vb24->addWidget(image7);

    wi7 = new QWidget();
    wi7->setLayout(vb4);

    wi8 = new QWidget();
    wi8->setLayout(vb24);

    splitt4 = new QSplitter();
    splitt4->addWidget(wi7);
    splitt4->addWidget(wi8);

    scrrol4 = new QScrollArea();
    scrrol4->setWidget(splitt4);
    hb4->addWidget(scrrol4);
    dialog8->setLayout(hb4);
}

void FenetrePrincipale::setDatabase(QSqlDatabase *newDatabase)
{
    database = newDatabase;
}

QSqlDatabase *FenetrePrincipale::getDatabase() const
{
    return database;
}

void FenetrePrincipale::Imprimer()
{
    // Construction de la boite

    impression = new QDialog(this);
    impression->setWindowTitle(tr("Imprimer un document"));
    impression->resize(500,500);

    l1 = new QLabel(tr("Imprimente"));

    nom = new QComboBox();
    nom->addItem(tr("Imprimer dans un fichier (PDF)"));
    nom->addItem(tr("Imprimer dans un autre fichier ()"));

    l2 = new QLabel(tr("Nom : "));
    pro = new QPushButton(tr("Propriétés"));

    h1 = new QHBoxLayout();
    h1->addWidget(l2);
    h1->addWidget(nom);
    h1->addWidget(pro);

    l3 = new QLabel(tr("Emplacement :"));
    l4 = new QLabel(tr("Fichier local"));

    h2 = new QHBoxLayout();
    h2->addWidget(l3);
    h2->addWidget(l4);

    l5 = new QLabel(tr("Type : "));
    l6 = new QLabel(tr("imprime dans un fichier PDF"));

    h3 = new QHBoxLayout();
    h3->addWidget(l5);
    h3->addWidget(l6);

    l7 = new QLabel(tr("Fichier de sortie : "));
    Fout = new QLineEdit();
    Fout->setText(tr("/home/ningana/print.pdf"));
    trois_point = new QPushButton("...");

    h4 = new QHBoxLayout();
    h4->addWidget(l7);
    h4->addWidget(Fout);
    h4->addWidget(trois_point);

    f1 = new QFormLayout();
    f1->addRow(l1);
    f1->addRow(h1);
    f1->addRow(h2);
    f1->addRow(h3);
    f1->addRow(h4);

    option = new QPushButton(tr("Option>>"));
    QObject::connect(option,&QPushButton::clicked,this,&FenetrePrincipale::CacherLeTab);
    annuler = new QPushButton(tr("Annuler"));
    QObject::connect(annuler,&QPushButton::clicked,this,&FenetrePrincipale::CloseModal);
    annuler->setIcon(QIcon("aquitter.png"));

    imprimeR = new QPushButton(tr("Imprimer"));

    h5 = new QHBoxLayout ();
    h5->addWidget(option);
    h5->addWidget(annuler);
    h5->addWidget(imprimeR);
    TabwidgetInvisible();
    V1 = new QVBoxLayout();
    V1->addLayout(f1);
    V1->addWidget(tab);
    // Apres ajout du tab, on redimentionne, comme il est encore caché
    impression->resize(500,180);
    // Et on ajoute le h5 apres 😁😁😁😁😁😁😁 Malin nespa?
    V1->addLayout(h5);

    impression->setLayout(V1);
    impression->exec();


}

void FenetrePrincipale::CacherLeTab()
{
    if (!tab->isVisible()){

        impression->setFixedHeight(400);
        tab->show();
        option->setText(tr("Option<<"));

    }else{
        tab->hide();
        impression->setFixedHeight(180);
        option->setText(tr("Option>>"));
      }
}

// Fermer la boite de dialogue

void FenetrePrincipale::CloseModal()
{
    // Ferme la boite de dialog
    impression->done(0);
}

void FenetrePrincipale::AfficheFenEetudiant(){
    if (Fenetrecentrale->currentWidget() != FenEntree){
        Fenetrecentrale->setCurrentWidget(FenEntree);
        FenEntree->ShowtabSTudent();
    }
}

// Si la fenetreCentrale n'est pas l'enrée, change cela et change également la page
void FenetrePrincipale::AfficheFenConnexion(){
    if (Fenetrecentrale->currentWidget() != FenConnexion){
        Fenetrecentrale->setCurrentWidget(FenConnexion);
    }
}

void FenetrePrincipale::AfficheFenAcceuille()
{
    if (Fenetrecentrale->currentWidget() != FenAcceuille){
        Fenetrecentrale->setCurrentWidget(FenAcceuille);
    }
}

void FenetrePrincipale::AfficheDialogueChoisirRecherche()
{
    dialog9 = new QDialog();
    dialog9->setModal(false);
    dialog9->setFixedWidth(200);
    dialog9->setWindowTitle(tr("Ningana Jacques"));

    auto *B1 = new QPushButton(tr("Etudiant"));
    connect(B1,&QPushButton::clicked, this, &FenetrePrincipale::OuvrirDialog1);
    auto *B2 = new QPushButton(tr("Enseignant"));
    connect(B2,&QPushButton::clicked, this, &FenetrePrincipale::OuvrirDialog2);
    auto *B3 = new QPushButton(tr("Administrateur"));
    connect(B3,&QPushButton::clicked, this, &FenetrePrincipale::OuvrirDialog3);
    auto *B4 = new QPushButton(tr("Surveillant"));
    connect(B4,&QPushButton::clicked, this, &FenetrePrincipale::OuvrirDialog4);
    auto *vl = new QVBoxLayout();

    vl->addWidget(B1);
    vl->addWidget(B2);
    vl->addWidget(B3);
    vl->addWidget(B4);

    dialog9->setLayout(vl);
    dialog9->exec();
    //auto *B1 = new QPushButton();

}
// Si la fenetreCentrale n'est pas l'enrée, change cela et change également la page
void FenetrePrincipale::AfficheFenEenseignant(){
    if (Fenetrecentrale->currentWidget() != FenEntree){
        Fenetrecentrale->setCurrentWidget(FenEntree);
    }
    FenEntree->ShowtabTich(); // On appel ce slot depuis la classe Fenetreentree
}

// Si la fenetreCentrale n'est pas l'enrée, change cela et change également la page

void FenetrePrincipale::AfficheFenEsurveillant(){
    if (Fenetrecentrale->currentWidget() != FenEntree){
        Fenetrecentrale->setCurrentWidget(FenEntree);
    }
    FenEntree->ShowtabSurv(); // On appel ce slot depuis la classe Fenetreentree
}

// Si la fenetreCentrale n'est pas l'enrée, change cela et change également la page
void FenetrePrincipale::AfficheFenAdministrateur(){
    if (Fenetrecentrale->currentWidget() != FenEntree){
        Fenetrecentrale->setCurrentWidget(FenEntree);
    }
    FenEntree->ShowTabAdmin(); // On appel ce slot depuis la classe Fenetreentree
}

// Ouverture pour etudiant
void FenetrePrincipale::OuvrirDialog1(){
    dialog1->exec();
}


// Ouverture pour enseignant
void FenetrePrincipale::OuvrirDialog2()
{
    dialog2->exec();
}

void FenetrePrincipale::OuvrirDialog3()
{
    dialog3->exec();
}

void FenetrePrincipale::OuvrirDialog4()
{
    dialog4->exec();
}

// Ouverture de la seconde boite  de l'étudiant

void FenetrePrincipale::OuvrirDialog5()
{
    QSqlQuery querry = QSqlQuery(*database);
    int id = Matricule1->text().toInt();

    if (id==0){
          querry.prepare("SELECT * FROM Etudiant WHERE Image= :image");
          querry.bindValue(":image", fichier1);
    }
    else{
        querry.prepare("SELECT * FROM Etudiant WHERE Matricule= :matricule");
        querry.bindValue(":matricule", id);
    }

    QString nom;
    QString Information;
    QString image;

    if (querry.exec()){
        while(querry.next()){
            image = querry.value("Image").toString();
            nom = querry.value("Nom").toString();
            Information = "Nom : " + querry.value("Nom").toString();
            Information.append("\nPrenom : " + querry.value("Prenom").toString());
            Information.append("\nDate de Naissance : " + querry.value("DateNaissance").toString());
            Information.append("\nLieu de naissance : " + querry.value("LieuNaissance").toString());
            Information.append("\nSexe : " + querry.value("Sexe").toString());
            Information.append("\nVenu du lycée : " + querry.value("Lycee").toString());
            Information.append("\nLicence : " + querry.value("Licence").toString());
            Information.append("\nFiliere : " + querry.value("Filiere").toString());
            Information.append("\nSalle : " + querry.value("Salle").toString());
            Information.append("\nEmail : " + querry.value("Email").toString());
            Information.append("\nDescription complete : " + querry.value("Description").toString());
        }
    }

    dialog5->setWindowTitle("Tout savoir sur " + nom);
    text1->setPlainText(Information);
    image5->setPixmap(QPixmap(image).scaled(400,350));
    dialog5->exec();
}

void FenetrePrincipale::OuvrirDialog6()
{
    QSqlQuery querry = QSqlQuery(*database);
    int id = Matricule2->text().toInt();

    if (id==0){
          querry.prepare("SELECT * FROM Enseignant WHERE Image= :image");
          querry.bindValue(":image", fichier2);
    }
    else{
        querry.prepare("SELECT * FROM Enseignant WHERE Matricule= :matricule");
        querry.bindValue(":matricule", id);
    }

    QString nom;
    QString Information;
    QString image;

    if (querry.exec()){
        while(querry.next()){
            image = querry.value("Image").toString();
            nom = querry.value("Nom").toString();
            Information = "Nom : " + querry.value("Nom").toString();
            Information.append("\nPrenom : " + querry.value("Prenom").toString());
            Information.append("\nDate de Naissance : " + querry.value("DateNaissance").toString());
            Information.append("\nLieu de naissance : " + querry.value("LieuNaissance").toString());
            Information.append("\nSexe : " + querry.value("Sexe").toString());
            Information.append("\nDiplome : " + querry.value("Diplome").toString());
            Information.append("\nSpécialité : " + querry.value("Specialite").toString());
            Information.append("\nContact : " + querry.value("Contact").toString());
            Information.append("\nNombre dematiers Enseignées : " + querry.value("NbreMat").toString());
            Information.append("\nSalles tenus : " + querry.value("Matiere").toString());
            Information.append("\nEmail : " + querry.value("Email").toString());
            Information.append("\nDescription complete : " + querry.value("Description").toString());
        }
    }

    dialog6->setWindowTitle("Tout savoir sur " + nom);
    text2->setPlainText(Information);
    image6->setPixmap(QPixmap(image).scaled(400,350));
    dialog6->exec();
}

void FenetrePrincipale::OuvrirDialog7()
{
    dialog7->exec();
}

void FenetrePrincipale::OuvrirDialog8()
{
    dialog8->exec();
}

void FenetrePrincipale::OuvrirImage1(){
        fichier1 = QFileDialog::getOpenFileName(this, "Ouvrir un fichier"," ", "Images (*.png *.gif *.jpg *.jpeg)");
        image1->setPixmap(QPixmap(fichier1).scaled(400,500));
}

void FenetrePrincipale::OuvrirImage2()
{
    fichier2 = QFileDialog::getOpenFileName(this, "Ouvrir un fichier"," ", "Images (*.png *.gif *.jpg *.jpeg)");
    image2->setPixmap(QPixmap(fichier2).scaled(400,500));
    image6->setPixmap(QPixmap(fichier2));
}

void FenetrePrincipale::OuvrirImage3()
{
    fichier3 = QFileDialog::getOpenFileName(this, "Ouvrir un fichier"," ", "Images (*.png *.gif *.jpg *.jpeg)");
    image3->setPixmap(QPixmap(fichier3));
    image7->setPixmap(QPixmap(fichier3));
}

void FenetrePrincipale::OuvrirImage4()
{
    fichier4 = QFileDialog::getOpenFileName(this, "Ouvrir un fichier"," ", "Images (*.png *.gif *.jpg *.jpeg)");
    image4->setPixmap(QPixmap(fichier4).scaled(400,500));
    image8->setPixmap(QPixmap(fichier4));
}

void FenetrePrincipale::OuvrirApropos()
{
    dialog10 = new QDialog();
    dialog10->setWindowTitle(tr("A propos de l'application"));
    dialog10->setFixedSize(500,450);

    QString AproposApplciation;
    QFile fichierAppli;

    fichierAppli.setFileName("Application.txt");

    if (fichierAppli.open(QFile::ReadOnly)){
        AproposApplciation=fichierAppli.readAll();
    }

    auto *Text = new QTextEdit();
    Text->setReadOnly(true);
    Text->setPlainText(AproposApplciation);

    auto *vb = new QVBoxLayout();
    vb->addWidget(Text);
    dialog10->setLayout(vb);

    dialog10->exec();
}

void FenetrePrincipale::OuvrirNingana()
{
    dialog11 = new QDialog();
    dialog11->setWindowTitle(tr("A propos du <strong>Developpeur</strong>"));
    dialog11->setFixedSize(500,450);

    QString AproposNingana;
    QFile fichierNingana;

    fichierNingana.setFileName("Ningana.txt");

    if (fichierNingana.open(QFile::ReadOnly)){
        AproposNingana=fichierNingana.readAll();
    }

    auto *Text1 = new QTextEdit();
    Text1->setReadOnly(true);
    Text1->setPlainText(AproposNingana);

    auto *vb1 = new QVBoxLayout();
    vb1->addWidget(Text1);
    dialog11->setLayout(vb1);

    dialog11->exec();
}

void FenetrePrincipale::OuvrirEnastic()
{
    dialog12 = new QDialog();
    dialog12->setWindowTitle(tr("A propos du <strong>L\'énastic</strong>"));
    dialog12->setFixedSize(500,450);

    QString AproposEnastic;
    QFile fichiEnastic;

    fichiEnastic.setFileName("Enastic.txt");

    if (fichiEnastic.open(QFile::ReadOnly)){
        AproposEnastic=fichiEnastic.readAll();
    }

    auto *Text2 = new QTextEdit();
    Text2->setReadOnly(true);
    Text2->setPlainText(AproposEnastic);

    auto *vb2 = new QVBoxLayout();
    vb2->addWidget(Text2);
    dialog12->setLayout(vb2);

    dialog12->exec();
}
