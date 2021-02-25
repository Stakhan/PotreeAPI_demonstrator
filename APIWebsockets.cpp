  #include "APIWebsockets.h"
  #include "QtWebSockets/QWebSocketServer"
  #include "QtWebSockets/QWebSocket"
  #include <QtCore/QDebug>
  #include <QWidget>
  #include <iostream>
  #include "MainWidget.h"

  QT_USE_NAMESPACE

  APIWebsockets::APIWebsockets(quint16 port, MainWidget *container, QObject *parent) :
      QObject(parent),
      m_pWebSocketServer(Q_NULLPTR),
      m_client()
  {
      m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Potree API"),
                                                QWebSocketServer::NonSecureMode,
                                                this);
      m_container = container;     
      if (m_pWebSocketServer->listen(QHostAddress::Any, port))
      {
          this->m_container->log("Potree API listening on port "+QString::number(port)+"\n");
          connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                  this, &APIWebsockets::onNewConnection);
      }
  }

  APIWebsockets::~APIWebsockets()
  {
      m_pWebSocketServer->close();
      //qDeleteAll(m_clients.begin(), m_clients.end());
      m_client = Q_NULLPTR;
  }

  void APIWebsockets::onNewConnection()
  {
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &APIWebsockets::processData);
    connect(pSocket, &QWebSocket::disconnected, this, &APIWebsockets::socketDisconnected);

    this->m_client = pSocket;
  }

  void APIWebsockets::processData(QString data)
  {
      this->m_container->log("\nData received:\n" + data);
  }

  void APIWebsockets::socketDisconnected()
  {
    //   QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    //   if (pClient)
    //   {
    //       m_client.removeAll(pClient);
    //       pClient->deleteLater();
    //   }
    m_client->deleteLater();
  }

  void APIWebsockets::initPointPicking()
  {
    this->m_container->log("init point picking");
    this->m_client->sendTextMessage("{ \"type\":\"init_point_picking\", \"content\":{} }");

  }