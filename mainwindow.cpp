#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <QAction>
#include <QLineEdit>
#include <QProcess>
#include <QTextEdit>
#include <QComboBox>
//#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QStringLiteral(".cue .flac"), 1);
    ui->comboBox->addItem(QStringLiteral(".cue .ape"), 2);
    ui->comboBox->addItem(QStringLiteral(".cue .wav"), 3);

}



MainWindow::~MainWindow()
{
    delete ui;
}



QProcess *cut = new QProcess();


void MainWindow::on_pushButton_clicked()
{

    QString in = ui->lineEdit->text();
    QString out = ui->lineEdit_2->text();

    //cut->setWorkingDirectory(out);

    if(in!="" && out!="")
    {

        QString format = ui->comboBox->currentText(), fileformat;
        if(format ==".cue .flac")
            fileformat = "*.flac";
        else if(format ==".cue .ape")
            fileformat = "*.ape";
        else if(format ==".cue .wav")
            fileformat = "*.wav";

        cut->start("mkdir " + out + "/out");

        if( !cut->waitForStarted() || !cut->waitForFinished() )
        {
            return;
        }
        ui->textEdit->insertPlainText(cut->readAllStandardOutput());
        ui->textEdit->insertPlainText(cut->readAllStandardError());

        //QMessageBox::information(this, "debug", "shnsplit -d " + out + "/out -f " + in + "/*.cue -o \"flac flac -V --best -o %f -\" "  + in  + '/' + fileformat + " -t \"%n. %p - %t\"");
        cut->start("shnsplit -d " + out + "/out -f " + in + "/*.cue -o \"flac flac -V --best -o %f -\" "  + in  + '/' + fileformat + " -t \"%n. %p - %t\"");

        if( !cut->waitForStarted() || !cut->waitForFinished() )
        {
            return;
        }
        ui->textEdit->insertPlainText(cut->readAllStandardOutput());
        ui->textEdit->insertPlainText(cut->readAllStandardError());
    }
    else
        QMessageBox::critical(this, "ERROR!", "Заполните поля!");

}







