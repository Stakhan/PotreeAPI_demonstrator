  #include "APIWebsockets.h"
  #include "QtWebSockets/QWebSocketServer"
  #include "QtWebSockets/QWebSocket"
  #include <QtCore/QDebug>
  #include <QWidget>
  #include <iostream>
  #include "mainwidget.h"

  QT_USE_NAMESPACE

  APIWebsockets::APIWebsockets(quint16 port, MainWidget *container, QObject *parent) :
      QObject(parent),
      m_pWebSocketServer(Q_NULLPTR),
      m_clients()
  {
      m_pWebSocketServer = new QWebSocketServer(QStringLiteral("Potree API"),
                                                QWebSocketServer::NonSecureMode,
                                                this);
      m_container = container;     
      if (m_pWebSocketServer->listen(QHostAddress::Any, port))
      {
          this->m_container->log("Potree API listening on port");
          connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                  this, &APIWebsockets::onNewConnection);
      }
  }

  APIWebsockets::~APIWebsockets()
  {
      m_pWebSocketServer->close();
      qDeleteAll(m_clients.begin(), m_clients.end());
  }

  void APIWebsockets::onNewConnection()
  {
      QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

      connect(pSocket, &QWebSocket::textMessageReceived, this, &APIWebsockets::processData);
      connect(pSocket, &QWebSocket::disconnected, this, &APIWebsockets::socketDisconnected);

      m_clients << pSocket;
  }

  void APIWebsockets::processData(QString data)
  {
      this->m_container->log("Data received:" + data);
  }

  void APIWebsockets::socketDisconnected()
  {
      QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
      if (pClient)
      {
          m_clients.removeAll(pClient);
          pClient->deleteLater();
      }
  }