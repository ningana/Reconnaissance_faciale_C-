#include "fenetreconnexion.h"

FenetreConnexion::FenetreConnexion(QWidget *parent)
    : QWidget{parent}
{
    database = new QSqlDatabase(QSqlDatabase::addDatabase ("QMYSQL"));
    image = new QLabel();// image avec cadena
    login = new QLineEdit();      // Champ pour Nom d'utilisateur
    login->setText(tr("ningana"));    // Par defaut, le login contient le nom de l'utilisateur
    login->setFixedWidth(190);
    passwd = new QLineEdit();    // Champ pour le mot de passe, par defaut, il est remplie
    passwd->setFixedWidth(190);
    passwd->setEchoMode(QLineEdit::Password);    // On cache le mot de passe
    //passwd->setText(" ");   // Mot de passe par defaut

    showPasswd = new QCheckBox();   // Champ pour l'affichage du Mot de passe, si ce checkBox est coché,le mot de passe devient visible
    //showPasswd->setFixedWidth(100);
    // Connection du Chekbox au slot RendreVisibleMotdePasse qui fait setEcho::Normal
    connect(showPasswd, &QCheckBox::stateChanged, this,&FenetreConnexion::RendreVisibleMotdePasse);
    Connexion  = new QPushButton(tr("Connexion"));
    connect(Connexion, &QPushButton::clicked, this, &FenetreConnexion::CreateDatabase);
    Connexion->setStyleSheet(tr("background-color : blue")); // On met en bleu

    image->setPixmap(QPixmap("alogin.jpg").scaled(360,300));

    LF = new QFormLayout();
    LF->addRow(tr("Nom d'utilisateur"),login);
    LF->addRow(tr("Mot de passe"),passwd);
    LF->addRow(tr("Afficher le mot de passe"),showPasswd);
    LF->addRow(Connexion);

   // LF->setAlignment(Qt::AlignCenter);
    LF->setAlignment (Connexion, Qt::AlignHCenter);
    LF->setAlignment (login, Qt::AlignHCenter);
    LF->setAlignment (passwd, Qt::AlignHCenter);
    //LF->setAlignment (showPasswd, Qt::AlignHCenter);
    // Conteneur generale

    //auto *scr = new QScrollArea();
    //scr->setWidget(image2);
    LV = new QVBoxLayout();
    LV->addWidget(image,0,Qt::AlignHCenter);
    LV->addLayout(LF,0);
    LV->setAlignment(Qt::AlignCenter);
    this->setLayout(LV);

}

void FenetreConnexion::RendreVisibleMotdePasse(){
    if(showPasswd->isChecked()){
        passwd->setEchoMode(QLineEdit::Normal);
    }else{
        passwd->setEchoMode(QLineEdit::Password);
    }
}

void FenetreConnexion::CreateDatabase()
{

    if(database->isOpen()){ // Si la base de données est ouverte
        database->close(); // On la ferme
        QMessageBox::information(this,tr("Déconnxion"),tr("Déconnecté de la base de données <strong>ReconaissanceFaciale</strong> "));
        Connexion->setText("Connexion"); // Le bouton de connexion devient connecter
        emit onConnected(false);
    }
    else // Si elle est fermée,on essaie de l'ouvrir
    {
        database->setUserName(login->text());
        database->setPassword(passwd->text());
        database->setDatabaseName ("ReconnaissanceFaciale");
        database->open(); // Ouverture ou Connexion à la base de données

        if(database->open()) // Si elle s'ouvre vraiment
        {
            emit onConnected(true); // On emmet le signal
            //QMessageBox::information(this,tr("Connecter"),tr("Connecter à la base de données <strong>ReconaissanceFaciale</strong>"));
            Connexion->setText("Deconnexion"); // Le bouton change, permetant de cliquer encore pour se deconnecter
            login->clear();
            passwd->clear();
        }
        else{
            emit onConnected(false);
            QMessageBox::critical(this, "Erreur de connexion", database->lastError().text());
        }
    }

    //database->setUserName (login->text());
    //database->setPassword (passwd->text());
    //database->setDatabaseName ("ReconnaissanceFaciale");

    //if (!database->open ()){
    //    QMessageBox::critical (this,tr("Error"),database->lastError ().text ());
    //}else{
    //    QMessageBox::information (this,"",tr("Connecté"));
    //    Connexion->setText(tr("Deconnexion"));
    //    connect (Connexion,&QPushButton::clicked,this, &FenetreConnexion::Deconnexion);
    //}

}

void FenetreConnexion::Deconnexion(){

    if (database->isOpen ()){
        database->close();
    }else{
        Connexion->setText(tr("Connexion"));
    }
}

QSqlDatabase *FenetreConnexion::getDatabase() const
{
    return database;
}

void FenetreConnexion::setDatabase(QSqlDatabase *newDatabase)
{
    database = newDatabase;
}
