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
#include <QAction>
#include <QDir>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_2, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::close);
}



MainWindow::~MainWindow()
{
    delete ui;
}



QProcess *cut = new QProcess();


void MainWindow::on_pushButton_clicked()
{

    ui->textEdit->clear();

    QString in = ui->lineEdit->text();
    QString out = ui->lineEdit_2->text();


    //cut->isWritable();

    if(in!="" && out!="")
    {

        QDir sourcedir(in);
        QString infile="", incue="";
        QString in_format = "*.flac *.ape *.wav", cue = "*.cue";

        QStringList audiofilelist = sourcedir.entryList(in_format.split(" "), QDir::Files);
        for (QStringList::const_iterator it = audiofilelist.constBegin(); it != audiofilelist.constEnd(); ++it)
            infile = (*it); //ну кагбэ так пока

        QStringList cuefilelist = sourcedir.entryList(cue.split(" "), QDir::Files);
        for (QStringList::const_iterator it = cuefilelist.constBegin(); it != cuefilelist.constEnd(); ++it)
            incue = (*it); //ну кагбэ так пока

        QString outdir[20];// = in.split("/");

        for(int i=0, k=0; i<in.size(); i++)
        {
            if(in[i]!='/')
                outdir[k]+=in[i];
            else
                k++;
        }

        int cnt=outdir->count();
        QString outdir0 = outdir[cnt-1];
        cut->start("mkdir " + out + '/' + outdir0);

        if( !cut->waitForStarted() || !cut->waitForFinished() )
        {
            return;
        }
        ui->textEdit->insertPlainText(cut->readAllStandardOutput());
        ui->textEdit->insertPlainText(cut->readAllStandardError());
        cut->close();

        //cut->setWorkingDirectory(out);

        cut->start("shnsplit -d " + out + '/' + outdir0 + " -f " + in + '/' + incue + " -o \"flac flac -V --best -o %f -\" "  + in  + '/' + infile + " -t \"%n. %p - %t\"");

        if( !cut->waitForStarted() || !cut->waitForFinished() )
        {
            return;
        }
        ui->textEdit->insertPlainText(cut->readAllStandardOutput());
        ui->textEdit->insertPlainText(cut->readAllStandardError());
        cut->close();
    }
    else
        QMessageBox::critical(this, "ERROR!", "Заполните поля!");

}

//open input directory
void MainWindow::on_pushButton_2_clicked()
{

}

//open output directory
void MainWindow::on_pushButton_3_clicked()
{

}
