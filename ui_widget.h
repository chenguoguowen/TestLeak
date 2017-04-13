/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFormLayout *formLayout_3;
    QFormLayout *formLayout_2;
    QPushButton *pushButton;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_11;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(644, 523);
        formLayout_3 = new QFormLayout(Widget);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pushButton);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Andalus"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        verticalLayout_2->addWidget(label_9);

        label_11 = new QLabel(Widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        verticalLayout_2->addWidget(label_11);

        label_10 = new QLabel(Widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        verticalLayout_2->addWidget(label_10);

        label_12 = new QLabel(Widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        verticalLayout_2->addWidget(label_12);

        label_13 = new QLabel(Widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(Widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        verticalLayout_2->addWidget(label_14);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        QFont font1;
        font1.setFamily(QStringLiteral("Andalus"));
        font1.setPointSize(10);
        lineEdit->setFont(font1);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setFont(font1);

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setFont(font1);

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(Widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setFont(font1);

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(Widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setFont(font1);

        verticalLayout->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(Widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setEnabled(false);
        lineEdit_6->setFont(font1);

        verticalLayout->addWidget(lineEdit_6);

        lineEdit_8 = new QLineEdit(Widget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setEnabled(false);
        lineEdit_8->setFont(font1);

        verticalLayout->addWidget(lineEdit_8);

        lineEdit_7 = new QLineEdit(Widget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setEnabled(false);
        lineEdit_7->setFont(font1);

        verticalLayout->addWidget(lineEdit_7);

        lineEdit_9 = new QLineEdit(Widget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setEnabled(false);
        lineEdit_9->setFont(font1);

        verticalLayout->addWidget(lineEdit_9);

        lineEdit_10 = new QLineEdit(Widget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setEnabled(false);
        lineEdit_10->setFont(font1);

        verticalLayout->addWidget(lineEdit_10);

        lineEdit_14 = new QLineEdit(Widget);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setEnabled(false);
        lineEdit_14->setFont(font1);

        verticalLayout->addWidget(lineEdit_14);

        lineEdit_12 = new QLineEdit(Widget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setEnabled(false);
        lineEdit_12->setFont(font1);

        verticalLayout->addWidget(lineEdit_12);

        lineEdit_13 = new QLineEdit(Widget);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setEnabled(false);
        lineEdit_13->setFont(font1);

        verticalLayout->addWidget(lineEdit_13);

        lineEdit_11 = new QLineEdit(Widget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setEnabled(false);
        lineEdit_11->setFont(font1);

        verticalLayout->addWidget(lineEdit_11);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, formLayout);


        formLayout_3->setLayout(0, QFormLayout::SpanningRole, formLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\346\235\241\347\240\201:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "Value:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "Date:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "Time:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "Program:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "Sequence:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "Lot:", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "Operator:", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "Result:", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "Units:", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "Data1:", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "Data2:", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "Data3:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
