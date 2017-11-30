/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_3;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(409, 503);
        QIcon icon;
        icon.addFile(QStringLiteral("audiocut.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 391, 441));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 120, 361, 20));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 370, 151, 31));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 160, 211, 16));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 80, 41, 31));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 80, 311, 29));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 291, 16));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 180, 361, 181));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 30, 41, 31));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 311, 29));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 301, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 381, 241));
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 50, 361, 181));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(290, 10, 81, 31));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 240, 381, 161));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 80, 83, 29));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(100, 80, 83, 29));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 120, 141, 31));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 40, 311, 29));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(330, 40, 41, 31));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(210, 120, 161, 31));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 351, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 85, 31, 21));
        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(240, 80, 83, 29));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 85, 31, 21));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 409, 27));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(action_3);
        menu_2->addAction(action_4);
        menu_3->addAction(action_5);
        menu_3->addAction(action_6);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AudioCut", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\276 \320\272\321\200\320\276\321\210\320\270\321\202\321\214", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\232\321\203\320\264\320\260 \320\272\321\200\320\276\321\210\320\270\321\202\321\214", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        action_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 .&cue", Q_NULLPTR));
        action_5->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", Q_NULLPTR));
        action_6->setText(QApplication::translate("MainWindow", "\320\233\320\270\321\206\320\265\320\275\320\267\320\270\321\217", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\272\320\276\320\275\320\262\320\265\321\200\321\202\320\260\321\206\320\270\321\217 .cue \320\262 \320\273\320\260\321\202\320\270\320\275\320\270\321\206\321\203", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\320\265\320\267\320\260\321\202\321\214!", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\272\320\276\320\275\321\201\320\276\320\273\320\270:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        lineEdit_2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\262\321\213\320\262\320\276\320\264\320\260:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        lineEdit->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\277\320\260\320\277\320\272\320\265 \321\201 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\274 \320\260\321\203\320\264\320\270\320\276 \321\204\320\260\320\271\320\273\320\276\320\274:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\265\320\267\320\272\320\260", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273\321\213 \320\264\320\273\321\217 \320\272\320\276\320\275\320\262\320\265\321\200\321\202\320\260\321\206\320\270\320\270", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\272\320\276\320\275\320\262\320\265\321\200\321\202\320\260\321\206\320\270\320\270", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\321\217\321\202\321\214 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\265", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\260\321\206\320\270\321\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \321\201\320\272\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\321\205 \320\277\320\265\321\201\320\265\320\275", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "kbps", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Hz", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\260\321\206\320\270\321\217", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
