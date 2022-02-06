/********************************************************************************
** Form generated from reading UI file 'studygraphicsscene.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYGRAPHICSSCENE_H
#define UI_STUDYGRAPHICSSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudyGraphicsSceneClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StudyGraphicsSceneClass)
    {
        if (StudyGraphicsSceneClass->objectName().isEmpty())
            StudyGraphicsSceneClass->setObjectName(QStringLiteral("StudyGraphicsSceneClass"));
        StudyGraphicsSceneClass->resize(600, 400);
        centralWidget = new QWidget(StudyGraphicsSceneClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        StudyGraphicsSceneClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StudyGraphicsSceneClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        StudyGraphicsSceneClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StudyGraphicsSceneClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StudyGraphicsSceneClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StudyGraphicsSceneClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StudyGraphicsSceneClass->setStatusBar(statusBar);

        retranslateUi(StudyGraphicsSceneClass);

        QMetaObject::connectSlotsByName(StudyGraphicsSceneClass);
    } // setupUi

    void retranslateUi(QMainWindow *StudyGraphicsSceneClass)
    {
        StudyGraphicsSceneClass->setWindowTitle(QApplication::translate("StudyGraphicsSceneClass", "StudyGraphicsScene", 0));
    } // retranslateUi

};

namespace Ui {
    class StudyGraphicsSceneClass: public Ui_StudyGraphicsSceneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYGRAPHICSSCENE_H
