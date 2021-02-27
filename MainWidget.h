

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include "APIWebsockets.h"

class QPushButton;
class QPlainTextEdit;
class QWebEngineView;
class APIWebsockets;

/**
 * @brief Implements the graphical interface of the demonstrator
 * 
 * The main components of the graphical interface are described in this class.
 * It inherits from QWidget and contains a button, a plain text field, and a web view.
 */
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Main Widget object
     *
     * Initiates all the GUI elements (button, web view and text field).
     * Defines a layout to arrange these elements.
     * Initiate the Websocket server to listen for Potree.
     * Connects the proper signal and slots.
     * 
     * @param parent parent Widget, optional
     */
    explicit MainWidget(QWidget *parent = 0);
    
    /**
     * @brief Destroy the Main Widget object
     */
    ~MainWidget();

    /**
     * @brief Appends log to demonstrator text field
     * 
     * Provided string is appended to demonstrator text field.
     *
     * @param text text data to log 
     */
    void log(QString text);

private:
   QPushButton* button_;
   QPlainTextEdit* logger_;
   QWebEngineView* webEngineView_;
   APIWebsockets* socketServer_;
};

#endif // MAINWIDGET_H

