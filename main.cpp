#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include<QTimer>
#include <QPageLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("/Users/prakashgurung/Desktop/splash.jpg"));
    splash->show();

    MainWindow w;

     QTimer::singleShot(2500, splash,SLOT(close()));
     QTimer::singleShot(2500,&w,SLOT(show()));



    return a.exec();
}
