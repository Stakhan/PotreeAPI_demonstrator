

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include "APIWebsockets.h"

class QPushButton;
class QPlainTextEdit;
class QWebEngineView;
class APIWebsockets;
// This is the declaration of our MainWidget class
// The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0); //Constructor
    ~MainWidget(); // Destructor
    void log(QString text);

private:
   QPushButton* button_;
   QPlainTextEdit* logger_;
   QWebEngineView* webEngineView_;
   APIWebsockets* socketServer_;
};

#endif // MAINWIDGET_H

