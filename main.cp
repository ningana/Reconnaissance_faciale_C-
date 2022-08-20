#include "fenetreprincipale.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ReconnaissanceFaciale_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    FenetrePrincipale w;

    QFile fichierAlire("Medize.qss");
    fichierAlire.open(QFile::ReadOnly);
    QString stylsheet = QLatin1String(fichierAlire.readAll());
    a.setStyleSheet(stylsheet);
    w.showMaximized();
    return a.exec();
}
