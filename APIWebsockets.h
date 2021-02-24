  #ifndef APIWEBSOCKETS_H
  #define APIWEBSOCKETS_H

  #include <QtCore/QObject>
  #include <QtCore/QList>
  #include <QtCore/QByteArray>
  #include "mainwidget.h"

  QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
  QT_FORWARD_DECLARE_CLASS(QWebSocket)

  class MainWidget;

  class APIWebsockets : public QObject
  {
      Q_OBJECT
  public:
      explicit APIWebsockets(quint16 port, MainWidget *container, QObject *parent = Q_NULLPTR);
      virtual ~APIWebsockets();

  private Q_SLOTS:
      void onNewConnection();
      void processData(QString data);
      void socketDisconnected();

  private:
      QWebSocketServer *m_pWebSocketServer;
      QList<QWebSocket *> m_clients;
      MainWidget *m_container;
  };

  #endif //APIWEBSOCKETS_H