#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPalette>
#include <QSqlQuery>
#include <QFileInfo>
#include <QPixmap>

#define Path_to_DB "/Users/prakashgurung/Desktop/nep_eng-2.sqlite"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
          ui->setupUi(this);
          QPixmap bkgnd("/Users/prakashgurung/Desktop/3.jpg");
          bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
          QPalette palette;
          palette.setBrush(QPalette::Background, bkgnd);
          this->setPalette(palette);


       myDB = QSqlDatabase::addDatabase("QSQLITE");
       myDB.setDatabaseName(Path_to_DB);
       QFileInfo checkFile(Path_to_DB);



       if(checkFile.isFile())
       {
           if(myDB.open())
           {
             ui->label->setText("<b>The database is connected<b>"
                                "");
           }

       }else{
           ui->label->setText("No file found!");
       }


}

MainWindow::~MainWindow()
{
    delete ui;
    myDB.close();
}


void MainWindow::on_pushButton_clicked()
{
    if(!myDB.isOpen()){
        qDebug() << " No connection to db";
        return;
    }

    QString wordInput;
    wordInput = ui->lineEdit->text();

    QSqlQuery qry;

    qry.prepare("SELECT Column1,Column2 FROM Nepali WHERE Column1  = :input");
    qry.bindValue(":input",wordInput);

    if(qry.exec())
    {


      if (qry.next())
      {
         // Retrieve Values from select statement
         QString inputWord = qry.value(0).toString();
         QString wordDefinition = qry.value(1).toString();

         // Display values
        // ui->output->setText(wordDefinition);
         ui->textBrowser->setText(wordDefinition);


    } else {
        qDebug() << "query failed to execute";
        QMessageBox::StandardButton reply= QMessageBox::question(this,
                                             "My Title", " Word not found, quit app?",
                                               QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {

                QApplication::quit();
              }

             }
     }



}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");

}
