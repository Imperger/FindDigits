/********************************************************************************
** Form generated from reading UI file 'finddigits.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIGITS_H
#define UI_FINDDIGITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindDigitsClass
{
public:
    QAction *open;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *expressionsGrid;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *e2g3;
    QLabel *label_4;
    QLineEdit *e1g1;
    QLineEdit *e1g2;
    QLabel *e1op;
    QLineEdit *e1g3;
    QLabel *label_2;
    QLabel *e5op;
    QLineEdit *e2g2;
    QLabel *e6op;
    QLineEdit *e2g1;
    QLabel *e4op;
    QLabel *e2op;
    QLineEdit *e3g1;
    QLineEdit *e3g2;
    QLabel *e3op;
    QLabel *label_6;
    QLineEdit *e3g3;
    QGridLayout *resultGrid;
    QLabel *labelA;
    QLabel *labelC;
    QLabel *labelB;
    QLabel *labelD;
    QLabel *labelF;
    QLabel *labelG;
    QLabel *labelE;
    QLabel *labelI;
    QLabel *labelH;
    QLabel *labelJ;
    QPushButton *solveButton;
    QVBoxLayout *verticalLayout_2;
    QListWidget *logList;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FindDigitsClass)
    {
        if (FindDigitsClass->objectName().isEmpty())
            FindDigitsClass->setObjectName(QString::fromUtf8("FindDigitsClass"));
        FindDigitsClass->resize(1040, 633);
        open = new QAction(FindDigitsClass);
        open->setObjectName(QString::fromUtf8("open"));
        centralWidget = new QWidget(FindDigitsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        expressionsGrid = new QGridLayout();
        expressionsGrid->setSpacing(6);
        expressionsGrid->setObjectName(QString::fromUtf8("expressionsGrid"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(24);
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        expressionsGrid->addWidget(label_12, 3, 4, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        expressionsGrid->addWidget(label_10, 3, 0, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        expressionsGrid->addWidget(label_11, 3, 2, 1, 1);

        e2g3 = new QLineEdit(centralWidget);
        e2g3->setObjectName(QString::fromUtf8("e2g3"));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        e2g3->setFont(font1);
        e2g3->setStyleSheet(QString::fromUtf8("margin-left: 20px"));

        expressionsGrid->addWidget(e2g3, 2, 4, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        expressionsGrid->addWidget(label_4, 2, 3, 1, 1);

        e1g1 = new QLineEdit(centralWidget);
        e1g1->setObjectName(QString::fromUtf8("e1g1"));
        e1g1->setFont(font1);
        e1g1->setStyleSheet(QString::fromUtf8("margin-right: 20px;"));

        expressionsGrid->addWidget(e1g1, 0, 0, 1, 1);

        e1g2 = new QLineEdit(centralWidget);
        e1g2->setObjectName(QString::fromUtf8("e1g2"));
        e1g2->setFont(font1);
        e1g2->setStyleSheet(QString::fromUtf8("margin: 0 20px"));

        expressionsGrid->addWidget(e1g2, 0, 2, 1, 1);

        e1op = new QLabel(centralWidget);
        e1op->setObjectName(QString::fromUtf8("e1op"));
        e1op->setFont(font1);
        e1op->setAlignment(Qt::AlignCenter);
        e1op->setProperty("operator", QVariant(true));

        expressionsGrid->addWidget(e1op, 0, 1, 1, 1);

        e1g3 = new QLineEdit(centralWidget);
        e1g3->setObjectName(QString::fromUtf8("e1g3"));
        e1g3->setFont(font1);
        e1g3->setStyleSheet(QString::fromUtf8("margin-left: 20px"));

        expressionsGrid->addWidget(e1g3, 0, 4, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        expressionsGrid->addWidget(label_2, 0, 3, 1, 1);

        e5op = new QLabel(centralWidget);
        e5op->setObjectName(QString::fromUtf8("e5op"));
        e5op->setFont(font1);
        e5op->setAlignment(Qt::AlignCenter);
        e5op->setProperty("operator", QVariant(true));

        expressionsGrid->addWidget(e5op, 1, 2, 1, 1);

        e2g2 = new QLineEdit(centralWidget);
        e2g2->setObjectName(QString::fromUtf8("e2g2"));
        e2g2->setFont(font1);
        e2g2->setStyleSheet(QString::fromUtf8("margin: 0 20px"));

        expressionsGrid->addWidget(e2g2, 2, 2, 1, 1);

        e6op = new QLabel(centralWidget);
        e6op->setObjectName(QString::fromUtf8("e6op"));
        e6op->setFont(font1);
        e6op->setAlignment(Qt::AlignCenter);
        e6op->setProperty("operator", QVariant(true));

        expressionsGrid->addWidget(e6op, 1, 4, 1, 1);

        e2g1 = new QLineEdit(centralWidget);
        e2g1->setObjectName(QString::fromUtf8("e2g1"));
        e2g1->setFont(font1);
        e2g1->setStyleSheet(QString::fromUtf8("margin-right: 20px;"));

        expressionsGrid->addWidget(e2g1, 2, 0, 1, 1);

        e4op = new QLabel(centralWidget);
        e4op->setObjectName(QString::fromUtf8("e4op"));
        sizePolicy.setHeightForWidth(e4op->sizePolicy().hasHeightForWidth());
        e4op->setSizePolicy(sizePolicy);
        e4op->setFont(font1);
        e4op->setStyleSheet(QString::fromUtf8(""));
        e4op->setAlignment(Qt::AlignCenter);
        e4op->setProperty("operator", QVariant(true));

        expressionsGrid->addWidget(e4op, 1, 0, 1, 1);

        e2op = new QLabel(centralWidget);
        e2op->setObjectName(QString::fromUtf8("e2op"));
        e2op->setFont(font1);
        e2op->setAlignment(Qt::AlignCenter);
        e2op->setProperty("operator", QVariant(true));

        expressionsGrid->addWidget(e2op, 2, 1, 1, 1);

        e3g1 = new QLineEdit(centralWidget);
        e3g1->setObjectName(QString::fromUtf8("e3g1"));
        e3g1->setFont(font1);
        e3g1->setStyleSheet(QString::fromUtf8("margin-right: 20px;"));

        expressionsGrid->addWidget(e3g1, 4, 0, 1, 1);

        e3g2 = new QLineEdit(centralWidget);
        e3g2->setObjectName(QString::fromUtf8("e3g2"));
        e3g2->setFont(font1);
        e3g2->setStyleSheet(QString::fromUtf8("margin: 0 20px"));

        expressionsGrid->addWidget(e3g2, 4, 2, 1, 1);

        e3op = new QLabel(centralWidget);
        e3op->setObjectName(QString::fromUtf8("e3op"));
        e3op->setFont(font1);
        e3op->setAlignment(Qt::AlignCenter);
        e3op->setProperty("operator", QVariant(true));

        expressionsGrid->addWidget(e3op, 4, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        expressionsGrid->addWidget(label_6, 4, 3, 1, 1);

        e3g3 = new QLineEdit(centralWidget);
        e3g3->setObjectName(QString::fromUtf8("e3g3"));
        e3g3->setFont(font1);
        e3g3->setStyleSheet(QString::fromUtf8("margin-left: 20px"));

        expressionsGrid->addWidget(e3g3, 4, 4, 1, 1);


        verticalLayout->addLayout(expressionsGrid);

        resultGrid = new QGridLayout();
        resultGrid->setSpacing(6);
        resultGrid->setObjectName(QString::fromUtf8("resultGrid"));
        labelA = new QLabel(centralWidget);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        QFont font2;
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        labelA->setFont(font2);

        resultGrid->addWidget(labelA, 0, 0, 1, 1);

        labelC = new QLabel(centralWidget);
        labelC->setObjectName(QString::fromUtf8("labelC"));
        labelC->setFont(font2);

        resultGrid->addWidget(labelC, 2, 0, 1, 1);

        labelB = new QLabel(centralWidget);
        labelB->setObjectName(QString::fromUtf8("labelB"));
        labelB->setFont(font2);

        resultGrid->addWidget(labelB, 1, 0, 1, 1);

        labelD = new QLabel(centralWidget);
        labelD->setObjectName(QString::fromUtf8("labelD"));
        labelD->setFont(font2);

        resultGrid->addWidget(labelD, 0, 1, 1, 1);

        labelF = new QLabel(centralWidget);
        labelF->setObjectName(QString::fromUtf8("labelF"));
        labelF->setFont(font2);

        resultGrid->addWidget(labelF, 2, 1, 1, 1);

        labelG = new QLabel(centralWidget);
        labelG->setObjectName(QString::fromUtf8("labelG"));
        labelG->setFont(font2);

        resultGrid->addWidget(labelG, 0, 2, 1, 1);

        labelE = new QLabel(centralWidget);
        labelE->setObjectName(QString::fromUtf8("labelE"));
        labelE->setFont(font2);

        resultGrid->addWidget(labelE, 1, 1, 1, 1);

        labelI = new QLabel(centralWidget);
        labelI->setObjectName(QString::fromUtf8("labelI"));
        labelI->setFont(font2);

        resultGrid->addWidget(labelI, 2, 2, 1, 1);

        labelH = new QLabel(centralWidget);
        labelH->setObjectName(QString::fromUtf8("labelH"));
        labelH->setFont(font2);

        resultGrid->addWidget(labelH, 1, 2, 1, 1);

        labelJ = new QLabel(centralWidget);
        labelJ->setObjectName(QString::fromUtf8("labelJ"));
        labelJ->setFont(font2);

        resultGrid->addWidget(labelJ, 3, 2, 1, 1);

        solveButton = new QPushButton(centralWidget);
        solveButton->setObjectName(QString::fromUtf8("solveButton"));
        solveButton->setEnabled(false);
        solveButton->setMinimumSize(QSize(0, 50));

        resultGrid->addWidget(solveButton, 4, 0, 1, 1);


        verticalLayout->addLayout(resultGrid);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        logList = new QListWidget(centralWidget);
        logList->setObjectName(QString::fromUtf8("logList"));
        logList->setAutoScroll(true);

        verticalLayout_2->addWidget(logList);


        verticalLayout->addLayout(verticalLayout_2);

        FindDigitsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FindDigitsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1040, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        FindDigitsClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(FindDigitsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FindDigitsClass->setStatusBar(statusBar);
        QWidget::setTabOrder(e1g1, e1g2);
        QWidget::setTabOrder(e1g2, e1g3);
        QWidget::setTabOrder(e1g3, e2g1);
        QWidget::setTabOrder(e2g1, e2g2);
        QWidget::setTabOrder(e2g2, e2g3);
        QWidget::setTabOrder(e2g3, e3g1);
        QWidget::setTabOrder(e3g1, e3g2);
        QWidget::setTabOrder(e3g2, e3g3);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(open);

        retranslateUi(FindDigitsClass);

        QMetaObject::connectSlotsByName(FindDigitsClass);
    } // setupUi

    void retranslateUi(QMainWindow *FindDigitsClass)
    {
        FindDigitsClass->setWindowTitle(QCoreApplication::translate("FindDigitsClass", "FindDigits", nullptr));
        open->setText(QCoreApplication::translate("FindDigitsClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("FindDigitsClass", "<html><head/><body><p>=</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("FindDigitsClass", "<html><head/><body><p>=</p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("FindDigitsClass", "<html><head/><body><p>=</p></body></html>", nullptr));
        e2g3->setText(QString());
        e2g3->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "GHI", nullptr));
        label_4->setText(QCoreApplication::translate("FindDigitsClass", "<html><head/><body><p>=</p></body></html>", nullptr));
        e1g1->setText(QString());
        e1g1->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "ABC", nullptr));
        e1g2->setText(QString());
        e1g2->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "DEF", nullptr));
        e1op->setText(QCoreApplication::translate("FindDigitsClass", "<a style=\"text-decoration:none;color:black\"  href=\"#plus\">+</a>", nullptr));
        e1g3->setText(QString());
        e1g3->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "GHI", nullptr));
        label_2->setText(QCoreApplication::translate("FindDigitsClass", "<html><head/><body><p>=</p></body></html>", nullptr));
        e5op->setText(QCoreApplication::translate("FindDigitsClass", "<a style=\"text-decoration:none;color:black\"  href=\"#plus\">+</a>", nullptr));
        e2g2->setText(QString());
        e2g2->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "DEF", nullptr));
        e6op->setText(QCoreApplication::translate("FindDigitsClass", "<a style=\"text-decoration:none;color:black\"  href=\"#plus\">+</a>", nullptr));
        e2g1->setText(QString());
        e2g1->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "ABC", nullptr));
#if QT_CONFIG(tooltip)
        e4op->setToolTip(QCoreApplication::translate("FindDigitsClass", "<html><head/><body><p>\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\264\320\273\321\217 \321\201\320\274\320\265\320\275\321\213 \320\267\320\275\320\260\320\272\320\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        e4op->setText(QCoreApplication::translate("FindDigitsClass", "<a style=\"text-decoration:none;color:black\"  href=\"#plus\">+</a>", nullptr));
        e2op->setText(QCoreApplication::translate("FindDigitsClass", "<a style=\"text-decoration:none;color:black\"  href=\"#plus\">+</a>", nullptr));
        e3g1->setText(QString());
        e3g1->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "ABC", nullptr));
        e3g2->setText(QString());
        e3g2->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "DEF", nullptr));
        e3op->setText(QCoreApplication::translate("FindDigitsClass", "<a style=\"text-decoration:none;color:black\"  href=\"#plus\">+</a>", nullptr));
        label_6->setText(QCoreApplication::translate("FindDigitsClass", "<html><head/><body><p>=</p></body></html>", nullptr));
        e3g3->setText(QString());
        e3g3->setPlaceholderText(QCoreApplication::translate("FindDigitsClass", "GHI", nullptr));
        labelA->setText(QCoreApplication::translate("FindDigitsClass", "A= ?", nullptr));
        labelC->setText(QCoreApplication::translate("FindDigitsClass", "C= ?", nullptr));
        labelB->setText(QCoreApplication::translate("FindDigitsClass", "B= ?", nullptr));
        labelD->setText(QCoreApplication::translate("FindDigitsClass", "D= ?", nullptr));
        labelF->setText(QCoreApplication::translate("FindDigitsClass", "F= ?", nullptr));
        labelG->setText(QCoreApplication::translate("FindDigitsClass", "G= ?", nullptr));
        labelE->setText(QCoreApplication::translate("FindDigitsClass", "E= ?", nullptr));
        labelI->setText(QCoreApplication::translate("FindDigitsClass", "I= ?", nullptr));
        labelH->setText(QCoreApplication::translate("FindDigitsClass", "H= ?", nullptr));
        labelJ->setText(QCoreApplication::translate("FindDigitsClass", "J= ?", nullptr));
        solveButton->setText(QCoreApplication::translate("FindDigitsClass", "\320\240\320\265\321\210\320\270\321\202\321\214", nullptr));
        menu_File->setTitle(QCoreApplication::translate("FindDigitsClass", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDigitsClass: public Ui_FindDigitsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIGITS_H
