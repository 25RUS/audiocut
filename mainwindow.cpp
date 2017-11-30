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
#include <QComboBox>
#include <QProgressDialog>

#include "replace.cpp"

void target(QString); //получение имён файлов

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_3, &QAction::triggered, this, &MainWindow::close);
    connect(ui->action_4, &QAction::triggered, this, &MainWindow::translate);
    connect(ui->action_5, &QAction::triggered, this, &MainWindow::about);
    connect(ui->action_6, &QAction::triggered, this, &MainWindow::license);

    QStringList af = {"формат", "mp3", "aac", "ogg"};
    ui->comboBox->addItems(af);

    QStringList f = {"96000", "48000", "44100", "32000", "24000", "22050", "16000", "11025", "8000"};
    ui->comboBox_3->addItems(f);
}



MainWindow::~MainWindow()
{
    delete ui;
}

QProcess *cut = new QProcess();
QProcess *converter = new QProcess;
QString infile="", incue="", new_audio_name=""; //сюда запишутся имена входных файлов
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
        //cut->start("shnsplit -d " + out + '/' + " -f " + in + '/' + incue + " -o \"flac flac -V --best -o %f -\" "  + in  + '/' + infile + " -t \"%n. %p - %t\"");

        /*QMessageBox::information(this, "command",*/ cut->start("shnsplit -d \"" + out + '/' + '\"' + " -f \"" + in + '/' + incue + '\"' + " -o \"flac flac -V --best -o %f -\" "  + in  + '/' + infile + " -t \"%n. %p - %t\"");

        //обработка ответов от команды
        if( !cut->waitForStarted() || !cut->waitForFinished() )
        {
            return;
        }
        ui->textEdit->insertPlainText(cut->readAllStandardOutput());
        ui->textEdit->insertPlainText(cut->readAllStandardError());

        ui->textEdit->insertPlainText("Дождитесь окончания процесса!\n");
        cut->close();
        //getflacnames(); //заполнения списка конвертации
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

//выбор директории сохранения сконверченых песенок
void MainWindow::on_pushButton_4_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(
                       this,
                       tr("Select a Directory"),
                       QDir::currentPath() );

           ui->lineEdit_3->setText(dirname);
}

//запуск конвертации
void MainWindow::on_pushButton_5_clicked()
{
    convert();
}

//получение имён .flac файлов после нарезки
void MainWindow::on_pushButton_6_clicked()
{
    getflacnames();
}

//*****************************************************************************************************

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
        QFile cuefileout(dir + '/' + replace(incue, 1));
        new_audio_name = replace(infile, 1); //новое имя для трека
        QString str, str0;

        //преобразование к utf8
        if(cuefile.open(QIODevice::ReadOnly))
        {
            QByteArray tmp = cuefile.readAll();
            QTextCodec* defaultTextCodec = QTextCodec::codecForName("Windows-1251");
            QTextDecoder *decoder = new QTextDecoder(defaultTextCodec);
            str = decoder->toUnicode(tmp);
            str0 = replace(str, 0);
            cuefile.close();
        }

        //сохранение сконвертированных данных
        if(cuefileout.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream write2cue(&cuefileout);
            write2cue << str0;
            cuefileout.close();
        }

        //модификация строки FILE
        QStringList lines;
        if(cuefileout.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString txt = cuefileout.readAll();
            lines = txt.split("\n");

            for(int k=0; k<lines.count(); k++)
            {
                QStringList words = lines[k].split(" ");
                if(words[0]=="FILE")
                    lines[k]="FILE \"" + new_audio_name + "\" WAVE";
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

        //переименование старого .cue
        QFile::rename(dir + '/' + incue, dir + '/' + incue + ".old");
        //переименование .flac
        QFile::rename(dir + '/' + infile, dir + '/' + new_audio_name);

        ui->textEdit->insertPlainText("Преобразование исходных файлов успешно.\n");
    }

}



//about
void MainWindow::about()
{
    QFile readme("/usr/share/doc/audiocut/README.md");
    QString txt;
    if(readme.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        txt=readme.readAll();
    }
    ui->textEdit->setText(txt);
}

//license
void MainWindow::license()
{
    QFile lic("/usr/share/doc/audiocut/LICENSE");
    QString txt;
    if(lic.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        txt=lic.readAll();
    }
    ui->textEdit->setText(txt);
}

QStringList flacfilelist;

//получение имён .flac файлов после нарезки
void MainWindow::getflacnames()
{
    QDir flacdir(ui->lineEdit_2->text());
    QStringList srcfilename = flacdir.entryList(QStringList() << "*.flac", QDir::Files);
    for(int i=0; i<srcfilename.count(); i++)
        QFile::rename(ui->lineEdit_2->text() + '/' + srcfilename[i], ui->lineEdit_2->text() + '/' + replace(srcfilename[i], 1));

    flacfilelist = flacdir.entryList(QStringList() << "*.flac", QDir::Files);
    for(int i=0; i<flacfilelist.count(); i++)
        ui->textEdit_2->insertPlainText(flacfilelist[i]+'\n');
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QStringList bitrate={"320", "256", "224", "192", "160", "128", "96", "64", "56", "48", "32", "24", "16", "12", "8"};
    ui->comboBox_2->clear();
    if(ui->comboBox->currentText()=="mp3")
    {
        ui->comboBox_2->addItems(bitrate);
    }
    else if(ui->comboBox->currentText()=="aac")
    {
        ui->comboBox_2->addItems(bitrate);
    }
    else if(ui->comboBox->currentText()=="ogg")
    {
        ui->comboBox_2->addItems(bitrate);
    }
}

//конвертация
void MainWindow::convert()
{
    QProgressDialog* pprd = new QProgressDialog("Ждать!!!", "&Cancel", 0, flacfilelist.count());
    pprd->setMinimumDuration(0);
    pprd->setWindowTitle("Идёт конвертация!");

    for(int i=0; i<flacfilelist.count(); i++)
    {
        pprd->setValue(i);
        qApp->processEvents();
        if (pprd->wasCanceled())
        {
             break;
        }

        converter->setWorkingDirectory(ui->lineEdit_3->text());
        QStringList audioname=flacfilelist[i].split(".");

        int title;
        if(audioname.count()>2)
            title=audioname.count()-2;
        else if(audioname.count()==2)
            title=audioname.count()-1;

        QString newout = replace(audioname[title], 1);
        QString command;
        if(ui->comboBox->currentText()=="mp3")
           command = "ffmpeg -i \"" + ui->lineEdit_2->text() + '/' + flacfilelist[i] + "\" -ar " + ui->comboBox_3->currentText() + " -ab " + ui->comboBox_2->currentText() + " -f " + ui->comboBox->currentText() + " " +  newout + '.' + ui->comboBox->currentText();
        else if(ui->comboBox->currentText()=="aac")
           command = "ffmpeg -i \"" + ui->lineEdit_2->text() + '/' + flacfilelist[i] + "\" -acodec aac -ar " + ui->comboBox_3->currentText() + " -ab " + ui->comboBox_2->currentText() + "k " +  newout + '.' + ui->comboBox->currentText();
        else if(ui->comboBox->currentText()=="ogg")
           command = "ffmpeg -i \"" + ui->lineEdit_2->text() + '/' + flacfilelist[i] + "\" -acodec libvorbis -ar " + ui->comboBox_3->currentText() + " -ab " + ui->comboBox_2->currentText() + "k " +  newout + '.' + ui->comboBox->currentText();
        else
        {
            QMessageBox::critical(this, "ERROR", "Select format!");
            break;
        }

        converter->start(command);
        if(!converter->waitForStarted() || !converter->waitForFinished())
            return;
        converter->close();

        if(ui->checkBox_2->isChecked())
            QFile(ui->lineEdit_2->text() + '/' + flacfilelist[i]).remove();
    }
    pprd->setValue(flacfilelist.count()) ;
    delete pprd;
}
