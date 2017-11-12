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
#include <QCheckBox>

void target(QString);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_4, &QAction::triggered, this, &MainWindow::translate);
    connect(ui->action_5, &QAction::triggered, this, &MainWindow::about);
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

    if(ui->checkBox->isChecked())
        translate();

    QString in = ui->lineEdit->text(); //исходная директория
    QString out = ui->lineEdit_2->text(); //целевая директория

    if(in!="" && out!="")
    {
        //определение путей
        target(in);

        //команда на начало резки файла
        cut->start("shnsplit -d " + out + '/' + " -f " + in + '/' + incue + " -o \"flac flac -V --best -o %f -\" "  + in  + '/' + infile + " -t \"%n. %p - %t\"");

        //обработка ответов от команды
        if( !cut->waitForStarted() || !cut->waitForFinished() )
        {
            return;
        }
        ui->textEdit->insertPlainText(cut->readAllStandardOutput());
        ui->textEdit->insertPlainText(cut->readAllStandardError());

        ui->textEdit->insertPlainText("Дождитесь окончания процесса!\n");
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
    if(dir=="")
        QMessageBox::critical(this, "ERROR!", "Заполните поля!");
    else
    {
        target(dir);
        QFile cuefile(dir + '/' + incue);
        QFile cuefileout(dir + '/' + "converted.cue");
        QString str, str0;

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
                   str0+='A';
               else if(str[i]=="а")
                   str0+='a';
               else if(str[i]=="Б")
                   str0+='B';
               else if(str[i]=="б")
                   str0+='b';
               else if(str[i]=="В")
                   str0+='V';
               else if(str[i]=="в")
                   str0+='v';
               else if(str[i]=="Г")
                   str0+='G';
               else if(str[i]=="г")
                   str0+='g';
               else if(str[i]=="Д")
                   str0+='D';
               else if(str[i]=="д")
                   str0+='d';
               else if(str[i]=="Е")
                   str0+='E';
               else if(str[i]=="е")
                   str0+='e';
               else if(str[i]=="Ё")
               {
                    str0+='Y';
                    str0+='o';
               }
               else if(str[i]=="ё")
               {
                    str0+='y';
                    str0+='o';
               }
               else if(str[i]=="Ж")
               {
                    str0+='Z';
                    str0+='h';
               }
               else if(str[i]=="ж")
               {
                    str0+='z';
                    str0+='h';
               }
               else if(str[i]=="З")
                   str0+='Z';
               else if(str[i]=="з")
                   str0+='z';
               else if(str[i]=="И")
                   str0+='I';
               else if(str[i]=="и")
                   str0+='i';
               else if(str[i]=="Й")
                   str0+='J';
               else if(str[i]=="й")
                   str0+='j';
               else if(str[i]=="К")
                   str0+='K';
               else if(str[i]=="к")
                   str0+='k';
               else if(str[i]=="Л")
                   str0+='L';
               else if(str[i]=="л")
                   str0+='l';
               else if(str[i]=="М")
                   str0+='M';
               else if(str[i]=="м")
                   str0+='m';
               else if(str[i]=="Н")
                   str0+='N';
               else if(str[i]=="н")
                   str0+='n';
               else if(str[i]=="О")
                   str0+='O';
               else if(str[i]=="о")
                   str0+='o';
               else if(str[i]=="П")
                   str0+='P';
               else if(str[i]=="п")
                   str0+='p';
               else if(str[i]=="Р")
                   str0+='R';
               else if(str[i]=="р")
                   str0+='r';
               else if(str[i]=="С")
                   str0+='S';
               else if(str[i]=="с")
                   str0+='s';
               else if(str[i]=="Т")
                   str0+='T';
               else if(str[i]=="т")
                   str0+='t';
               else if(str[i]=="У")
                   str0+='U';
               else if(str[i]=="у")
                   str0+='u';
               else if(str[i]=="Ф")
                   str0+='F';
               else if(str[i]=="ф")
                   str0+='f';
               else if(str[i]=="Х")
                   str0+='H';
               else if(str[i]=="х")
                   str0+='h';
               else if(str[i]=="Ц")
                   str0+='C';
               else if(str[i]=="ц")
                   str0+='c';
               else if(str[i]=="Ч")
               {
                    str0+='C';
                    str0+='h';
               }
               else if(str[i]=="ч")
               {
                    str0+='c';
                    str0+='h';
               }
               else if(str[i]=="Ш")
               {
                    str0+='S';
                    str0+='h';
               }
               else if(str[i]=="ш")
               {
                    str0+='s';
                    str0+='h';
               }
               else if(str[i]=="Щ")
               {
                    str0+='S';
                    str0+='h';
               }
               else if(str[i]=="щ")
               {
                    str0+='s';
                    str0+='h';
               }
               else if(str[i]=="Ъ")
                   /*str0+=""*/;
               else if(str[i]=="ъ")
                   /*str0+=""*/;
               else if(str[i]=="Ы")
                   str0+='I';
               else if(str[i]=="ы")
                   str0+='i';
               else if(str[i]=="Ь")
                   /*str0+=""*/;
               else if(str[i]=="ь")
                   /*str0+=""*/;
               else if(str[i]=="Э")
                   str0+='E';
               else if(str[i]=="э")
                   str0+='e';
               else if(str[i]=="Ю")
                   str0+='U';
               else if(str[i]=="ю")
                   str0+='u';
               else if(str[i]=="Я")
               {
                    str0+='Y';
                    str0+='a';
               }
               else if(str[i]=="я")
               {
                    str0+='y';
                    str0+='a';
               }
               else
                   str0+=str[i];
            }

            cuefile.close();
        }

        //сохранение сконвертированных данных
        if(cuefileout.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream write2cue(&cuefileout);
            write2cue << str0;
            cuefileout.close();
        }

        //определение расширения
        QStringList type = infile.split(".");

        //модификация строки FILE
        QStringList lines;
        if(cuefileout.open(QIODevice::ReadOnly | QIODevice::Text))
        {

//            for(int i=0; i<=cuefileout.atEnd(); i++)
//                lines[i]=cuefileout.readLine(i);
            QString txt = cuefileout.readAll();
            lines = txt.split("\n");

            for(int k=0; k<lines.count(); k++)
            {
                QStringList words = lines[k].split(" ");
                if(words[0]=="FILE")
                    lines[k]="FILE \"audiotrack." + type[1] + "\" WAVE";
            }
            cuefileout.close();
        }
        //стирание
         if(cuefileout.open(QIODevice::WriteOnly | QIODevice::Text))
         {
             QTextStream write2cue(&cuefileout);
             write2cue << "";
             cuefileout.close();
         }
         //перезапись
         if(cuefileout.open(QIODevice::Append | QIODevice::Text))
         {
             QTextStream write2cue(&cuefileout);
             for(int i=0; i<lines.count(); i++)
                write2cue << lines[i] <<'\n';
             cuefileout.close();
         }

        //переименование
        QFile::rename(dir + '/' + incue, dir + '/' + incue + ".old");

        //просто убрать пробелы
//        QString infileout;
//        for(int i=0; i<infile.count(); i++)
//        {
//            if(infile[i]==" ")
//                infileout+='_';
//            else
//                infileout+=infile[i];
//        }

        QFile::rename(dir + '/' + infile, dir + '/' + /*infileout*/ "audiotrack." + type[1]);

        ui->textEdit->insertPlainText("Преобразование исходных файлов успешно.\n");
    }

}


void MainWindow::about()
{
    QMessageBox::information(this, "About AudioCut", "AudioCut - графическая оболочка для shnsplit\n"
                                                     "поддерживаются форматы .flac .ape .wav\n"
                                                     "Исходники https://github.com/25RUS/audiocut\n"
                                                     "Автор: Ревчук Ю.Ю. "
                                                     "adnet_9@live.com"
                                                    );
}
