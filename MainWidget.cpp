

#include <QtWidgets>
#include <QWebEngineView>
#include "MainWidget.h"
#include "APIWebsockets.h"

// Constructor for main widget
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
   button_ = new QPushButton(tr("Pick a point"));
   logger_ = new QPlainTextEdit();
   logger_->setReadOnly(true);
   socketServer_ = new APIWebsockets(1111, this);
   webEngineView_ = new QWebEngineView(this);
   webEngineView_->load(QUrl("http://localhost:1234/examples/test_projet_info.html"));

   QHBoxLayout *mainLayout = new QHBoxLayout();
   QGridLayout *leftLayout = new QGridLayout();
   leftLayout->addWidget(button_,0,0);
   leftLayout->addWidget(logger_,1,0);
   
   mainLayout->addLayout(leftLayout);
   mainLayout->addWidget(webEngineView_);
   mainLayout->setStretch(1,2);

   setLayout(mainLayout);
   setWindowTitle(tr("PotreeAPI demonstrator"));

   //Signal and slots connexion
   connect(button_, SIGNAL(released()), socketServer_, SLOT(initPointPicking()));
   
}

// Destructor
MainWidget::~MainWidget()
{
   delete button_;
   delete logger_;
   delete webEngineView_;
}

void MainWidget::log(QString text)
{
    this->logger_->appendPlainText(text);
}
