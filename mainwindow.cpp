#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPalette>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

       QPixmap bkgnd("/Users/prakashgurung/Desktop/background.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/Users/prakashgurung/Desktop/notes.txt");

    if(!mydb.open())
        ui->label->setText("Failed to open the database");
    else
          ui->label->setText("Database is loaded..");
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply= QMessageBox::question(this,
                                      "My Title", " Word not found, quit app?",
                                       QMessageBox::Yes | QMessageBox::No);


    if(reply == QMessageBox::Yes){
        QApplication::quit();
}


//    QString search;
//    search = ui->lineEdit->text();

//    if(!mydb.open()){
//        qDebug() <<
//    }


    }

