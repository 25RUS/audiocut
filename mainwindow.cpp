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

//translation to latin & removing " "
void MainWindow::translate()
{

    QString dir = ui->lineEdit->text();
    target(dir);

    QFile cuefile(dir + '/' + incue);
    if(cuefile.open(QIODevice::ReadWrite /*| QIODevice::Text*/))
    {
        QByteArray tmp = cuefile.readAll();
        QTextCodec* defaultTextCodec = QTextCodec::codecForName("Windows-1251");
        QTextDecoder *decoder = new QTextDecoder(defaultTextCodec);
        QString str = decoder->toUnicode(tmp);
        QTextStream write2cue(&cuefile);
        write2cue << str;
        //QMessageBox::information(this, "translate_debug", str);
    }

}
