#pragma once

#include <QWidget>
#include <QtWidgets>


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtGui>
#include <QSqlError>


class FenetreConnexion : public QWidget
{
    Q_OBJECT
public slots :
    //void OnUpdtateEtudiant();
   //void OnAddetudiant();

signals:
    void onConnected(bool);
public:
    FenetreConnexion(QWidget *parent = nullptr);
    void RendreVisibleMotdePasse();
    void CreateDatabase();
    void Deconnexion();

    QSqlDatabase *getDatabase() const;
    void setDatabase(QSqlDatabase *newDatabase);

private :

    QLabel *image;
    QGraphicsPixmapItem *image2;
    QLineEdit *login;
    QLineEdit *passwd;
    QCheckBox *showPasswd;
    QPushButton *Connexion;
    QPushButton *nom;
    QPushButton *motdepasse;
    QPushButton *afficheMot;

    QHBoxLayout *H1,*H2,*H3;
    QVBoxLayout *LV;
    QFormLayout *LF;

    QTableView *view;
    QStandardItemModel *model;
    QSqlDatabase *database;

    QGraphicsView *VisionneurLogo;
    QGraphicsScene *scene;

};

