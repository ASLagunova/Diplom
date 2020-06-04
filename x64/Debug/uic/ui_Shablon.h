/********************************************************************************
** Form generated from reading UI file 'Shablon.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHABLON_H
#define UI_SHABLON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shablon_Window
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *choiseButtom;
    QComboBox *comboBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QPushButton *AddType;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(351, 182);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 140, 311, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bookman Old Style"));
        okButton->setFont(font);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font);

        hboxLayout->addWidget(cancelButton);

        choiseButtom = new QPushButton(Dialog);
        choiseButtom->setObjectName(QString::fromUtf8("choiseButtom"));
        choiseButtom->setGeometry(QRect(310, 30, 31, 31));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(12, 40, 291, 21));
        comboBox->setFont(font);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(2, 10, 351, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bookman Old Style"));
        font1.setPointSize(9);
        label->setFont(font1);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(12, 110, 291, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bookman Old Style"));
        font2.setPointSize(9);
        font2.setItalic(true);
        lineEdit->setFont(font2);
        comboBox_2 = new QComboBox(Dialog);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(12, 80, 291, 22));
        comboBox_2->setFont(font);
        AddType = new QPushButton(Dialog);
        AddType->setObjectName(QString::fromUtf8("AddType"));
        AddType->setGeometry(QRect(310, 70, 31, 31));

        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        okButton->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
        choiseButtom->setText(QString());
        label->setText(QCoreApplication::translate("Dialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\210\320\260\320\261\320\273\320\276\320\275 \320\270\320\267 \321\203\320\266\320\265 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\321\213\321\205 \320\270\320\273\320\270 \320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\320\265 \321\201\320\262\320\276\320\271", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\275\320\276\320\262\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260", nullptr));
        AddType->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Shablon_Window : public Ui_Shablon_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHABLON_H
