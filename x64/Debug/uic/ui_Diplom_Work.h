/********************************************************************************
** Form generated from reading UI file 'Diplom_Work.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIPLOM_WORK_H
#define UI_DIPLOM_WORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_WindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *ButtonOpen;
    QPushButton *ButtomUpdate;
    QPushButton *ButtonDelete;
    QTableView *TableDataFromBD;
    QPushButton *Arhive;
    QPushButton *ShablonButtom;
    QPushButton *ButtonAdd;
    QPushButton *FindButton;
    QLineEdit *FindLine;
    QPushButton *RefreshButtom;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Diplom_WorkClass)
    {
        if (Diplom_WorkClass->objectName().isEmpty())
            Diplom_WorkClass->setObjectName(QString::fromUtf8("Diplom_WorkClass"));
        Diplom_WorkClass->resize(1107, 642);
        centralWidget = new QWidget(Diplom_WorkClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ButtonOpen = new QPushButton(centralWidget);
        ButtonOpen->setObjectName(QString::fromUtf8("ButtonOpen"));
        ButtonOpen->setGeometry(QRect(930, 190, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Bookman Old Style"));
        font.setPointSize(12);
        ButtonOpen->setFont(font);
        ButtomUpdate = new QPushButton(centralWidget);
        ButtomUpdate->setObjectName(QString::fromUtf8("ButtomUpdate"));
        ButtomUpdate->setGeometry(QRect(930, 250, 171, 41));
        ButtomUpdate->setFont(font);
        ButtonDelete = new QPushButton(centralWidget);
        ButtonDelete->setObjectName(QString::fromUtf8("ButtonDelete"));
        ButtonDelete->setGeometry(QRect(930, 310, 171, 41));
        ButtonDelete->setFont(font);
        TableDataFromBD = new QTableView(centralWidget);
        TableDataFromBD->setObjectName(QString::fromUtf8("TableDataFromBD"));
        TableDataFromBD->setGeometry(QRect(10, 60, 911, 521));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bookman Old Style"));
        TableDataFromBD->setFont(font1);
        TableDataFromBD->setSelectionMode(QAbstractItemView::SingleSelection);
        TableDataFromBD->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableDataFromBD->setGridStyle(Qt::SolidLine);
        TableDataFromBD->horizontalHeader()->setCascadingSectionResizes(false);
        TableDataFromBD->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        Arhive = new QPushButton(centralWidget);
        Arhive->setObjectName(QString::fromUtf8("Arhive"));
        Arhive->setGeometry(QRect(930, 370, 171, 41));
        Arhive->setFont(font);
        ShablonButtom = new QPushButton(centralWidget);
        ShablonButtom->setObjectName(QString::fromUtf8("ShablonButtom"));
        ShablonButtom->setGeometry(QRect(930, 70, 171, 41));
        ShablonButtom->setFont(font);
        ButtonAdd = new QPushButton(centralWidget);
        ButtonAdd->setObjectName(QString::fromUtf8("ButtonAdd"));
        ButtonAdd->setGeometry(QRect(930, 130, 171, 41));
        ButtonAdd->setFont(font);
        FindButton = new QPushButton(centralWidget);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setGeometry(QRect(930, 10, 171, 41));
        FindButton->setFont(font);
        FindLine = new QLineEdit(centralWidget);
        FindLine->setObjectName(QString::fromUtf8("FindLine"));
        FindLine->setGeometry(QRect(720, 10, 201, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bookman Old Style"));
        font2.setPointSize(11);
        font2.setItalic(true);
        FindLine->setFont(font2);
        RefreshButtom = new QPushButton(centralWidget);
        RefreshButtom->setObjectName(QString::fromUtf8("RefreshButtom"));
        RefreshButtom->setGeometry(QRect(10, 10, 41, 41));
        Diplom_WorkClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Diplom_WorkClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1107, 21));
        Diplom_WorkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Diplom_WorkClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Diplom_WorkClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Diplom_WorkClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Diplom_WorkClass->setStatusBar(statusBar);

        retranslateUi(Diplom_WorkClass);

        QMetaObject::connectSlotsByName(Diplom_WorkClass);
    } // setupUi

    void retranslateUi(QMainWindow *Diplom_WorkClass)
    {
        Diplom_WorkClass->setWindowTitle(QCoreApplication::translate("Diplom_WorkClass", "Diplom_Work", nullptr));
        ButtonOpen->setText(QCoreApplication::translate("Diplom_WorkClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        ButtomUpdate->setText(QCoreApplication::translate("Diplom_WorkClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        ButtonDelete->setText(QCoreApplication::translate("Diplom_WorkClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        Arhive->setText(QCoreApplication::translate("Diplom_WorkClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\260\321\200\321\205\320\270\320\262", nullptr));
        ShablonButtom->setText(QCoreApplication::translate("Diplom_WorkClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\276 \321\210\320\260\320\261\320\273\320\276\320\275\321\203", nullptr));
        ButtonAdd->setText(QCoreApplication::translate("Diplom_WorkClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        FindButton->setText(QCoreApplication::translate("Diplom_WorkClass", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        FindLine->setPlaceholderText(QCoreApplication::translate("Diplom_WorkClass", "   \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\321\201\320\272\320\276\320\274\320\276\320\265 \321\201\320\273\320\276\320\262\320\276", nullptr));
        RefreshButtom->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Main_Window : public Ui_Main_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIPLOM_WORK_H
