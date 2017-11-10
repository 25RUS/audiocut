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
#include <QFile>
#include <QStringList>
#include <QFileDialog>
#include <QPushButton>
#include <QTextCodec>
#include <QTextDecoder>
#include <QTextStream>

void target(QString);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_2, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_4, &QAction::triggered, this, &MainWindow::translate);
}



MainWindow::~MainWindow()
{
    delete ui;
}

QProcess *cut = new QProcess();
QString infile="", incue=""; //сюда запишутся имена входных файлов
QString in_format = "*.flac *.ape *.wav", cue = "*.cue"; //форматы файлов на вход


void MainWindow::on_pushButton_clicked()
{

    ui->textEdit->clear();

    QString in = ui->lineEdit->text(); //исходная директория
    QString out = ui->lineEdit_2->text(); //целевая директория

    if(in!="" && out!="")
    {
        //определение путей
        target(in);

        //команда на начало резки файла
        cut->start("shnsplit -d " + out + '/' + /*outdir +*/ " -f " + in + '/' + incue + " -o \"flac flac -V --best -o %f -\" "  + in  + '/' + infile + " -t \"%n. %p - %t\"");

        //обработка ответов от команды
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
            QString dirname = QFileDialog::getExistingDirectory(
                       this,
                       tr("Select a Directory"),
                       QDir::currentPath() );

           ui->lineEdit->setText(dirname);
}

//open output directory
void MainWindow::on_pushButton_3_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(
                       this,
                       tr("Select a Directory"),
                       QDir::currentPath() );

           ui->lineEdit_2->setText(dirname);
}

void target(QString in)
{
    QDir sourcedir(in);

    //определение названия аудиофайлов
    QStringList audiofilelist = sourcedir.entryList(in_format.split(" "), QDir::Files);
    for (QStringList::const_iterator it = audiofilelist.constBegin(); it != audiofilelist.constEnd(); ++it)
        infile = (*it); //ну кагбэ так пока

    //определение .cue файлов
    QStringList cuefilelist = sourcedir.entryList(cue.split(" "), QDir::Files);
    for (QStringList::const_iterator it = cuefilelist.constBegin(); it != cuefilelist.constEnd(); ++it)
        incue = (*it); //ну кагбэ так пока
}

//converting to utf8 & removing " "
void MainWindow::translate()
{

    QString dir = ui->lineEdit->text();
    target(dir);
    QFile cuefile(dir + '/' + incue);
    QFile cuefileout(dir + '/' + "converted.cue");
    QString str;

    //преобразование к utf8
    if(cuefile.open(QIODevice::ReadOnly /*| QIODevice::Text*/))
    {
        QByteArray tmp = cuefile.readAll();
        QTextCodec* defaultTextCodec = QTextCodec::codecForName("Windows-1251");
        QTextDecoder *decoder = new QTextDecoder(defaultTextCodec);
        str = decoder->toUnicode(tmp);

            for(int i=0; i<str.size(); i++)
            {
               if(str[i]=="А")
                   str[i]='A';
               else if(str[i]=="а")
                   str[i]='a';
               else if(str[i]=="Б")
                   str[i]='B';
               else if(str[i]=="б")
                   str[i]='b';
               else if(str[i]=="В")
                   str[i]='V';
               else if(str[i]=="в")
                   str[i]='v';
               else if(str[i]=="Г")
                   str[i]='G';
               else if(str[i]=="г")
                   str[i]='g';
               else if(str[i]=="Д")
                   str[i]='D';
               else if(str[i]=="д")
                   str[i]='d';
               else if(str[i]=="Е")
                   str[i]='E';
               else if(str[i]=="е")
                   str[i]='e';
               else if(str[i]=="Ё")
                   str[i]='E';
               else if(str[i]=="ё")
                   str[i]='e';
               else if(str[i]=="Ж")
                   str[i]='J';
               else if(str[i]=="ж")
                   str[i]='j';
               else if(str[i]=="З")
                   str[i]='Z';
               else if(str[i]=="з")
                   str[i]='z';
               else if(str[i]=="И")
                   str[i]='I';
               else if(str[i]=="и")
                   str[i]='i';
               else if(str[i]=="Й")
                   str[i]='J';
               else if(str[i]=="й")
                   str[i]='j';
               else if(str[i]=="К")
                   str[i]='K';
               else if(str[i]=="к")
                   str[i]='k';
               else if(str[i]=="Л")
                   str[i]='L';
               else if(str[i]=="л")
                   str[i]='l';
               else if(str[i]=="М")
                   str[i]='M';
               else if(str[i]=="м")
                   str[i]='m';
               else if(str[i]=="Н")
                   str[i]='N';
               else if(str[i]=="н")
                   str[i]='n';
               else if(str[i]=="О")
                   str[i]='O';
               else if(str[i]=="о")
                   str[i]='o';
               else if(str[i]=="П")
                   str[i]='P';
               else if(str[i]=="п")
                   str[i]='p';
               else if(str[i]=="Р")
                   str[i]='R';
               else if(str[i]=="р")
                   str[i]='r';
               else if(str[i]=="С")
                   str[i]='S';
               else if(str[i]=="с")
                   str[i]='s';
               else if(str[i]=="Т")
                   str[i]='T';
               else if(str[i]=="т")
                   str[i]='t';
               else if(str[i]=="У")
                   str[i]='U';
               else if(str[i]=="у")
                   str[i]='u';
               else if(str[i]=="Ф")
                   str[i]='F';
               else if(str[i]=="ф")
                   str[i]='f';
               else if(str[i]=="Х")
                   str[i]='H';
               else if(str[i]=="х")
                   str[i]='h';
               else if(str[i]=="Ц")
                   str[i]='C';
               else if(str[i]=="ц")
                   str[i]='c';
               else if(str[i]=="Ч")
                   str[i]='C';
               else if(str[i]=="ч")
                   str[i]='c';
               else if(str[i]=="Ш")
                   str[i]='S';
               else if(str[i]=="ш")
                   str[i]='s';
               else if(str[i]=="Щ")
                   str[i]='S';
               else if(str[i]=="щ")
                   str[i]='s';
               else if(str[i]=="Ъ")
                   str[i]='\'';
               else if(str[i]=="ъ")
                   str[i]='\'';
               else if(str[i]=="Ы")
                   str[i]='I';
               else if(str[i]=="ы")
                   str[i]='i';
               else if(str[i]=="Ь")
                   str[i]='`';
               else if(str[i]=="ь")
                   str[i]='`';
               else if(str[i]=="Э")
                   str[i]='E';
               else if(str[i]=="э")
                   str[i]='e';
               else if(str[i]=="Ю")
                   str[i]='U';
               else if(str[i]=="ю")
                   str[i]='u';
               else if(str[i]=="Я")
                   str[i]='A';
               else if(str[i]=="я")
                   str[i]='a';
               else
                   str[i]=str[i];
            }
       // QMessageBox::information(this, "debug", str);
        cuefile.close();

        //сохранение сконвертированных данных
        if(cuefileout.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream write2cue(&cuefileout);
            write2cue << str;
            cuefileout.close();
        }

    }

    //переименование

}
