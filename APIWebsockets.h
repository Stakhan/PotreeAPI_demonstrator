  #ifndef APIWEBSOCKETS_H
  #define APIWEBSOCKETS_H

  #include <QtCore/QObject>
  #include <QtCore/QList>
  #include <QtCore/QByteArray>
  #include "MainWidget.h"

  QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
  QT_FORWARD_DECLARE_CLASS(QWebSocket)

  class MainWidget;
  
  /**
   * @brief Manages websocket connections with Potree mdInfinity API
   * 
   */
  class APIWebsockets : public QObject
  {
      Q_OBJECT
  public:
    /**
     * @brief Construct a new APIWebsockets object
     * 
     * Runs a websocket server to listen for Potree mdInfinityAPI
     * 
     * @param port port on which websocket server will run
     * @param container MainWidget instance containing this websocket server 
     * @param parent the parent widget
     */
    explicit APIWebsockets(quint16 port, MainWidget *container, QObject *parent = Q_NULLPTR);
    
    /**
     * @brief Destroy the APIWebsockets object
     */
    virtual ~APIWebsockets();

  private Q_SLOTS:
    /**
     * @brief Done on a new connection
     *
     *  Connects proper slots on 'textMessageReceived' and 'disconnected' signals.
     * 
     */
    void onNewConnection();

    /**
     * @brief Proceeses received data
     * 
     * Log received data using container log method.
     *
     * @param data received data
     */
    void processData(QString data);

    /**
     * @brief Closes websocket connection properly
     * 
     */
    void socketDisconnected();

    /**
     * @brief Sends initialization message to Potree
     * 
     * Provokes Potree to enable point ID selection tool.
     */
    void initPointPicking();

  private:
    QWebSocketServer *m_pWebSocketServer;
    QWebSocket *m_client;
    MainWidget *m_container;
  };

  #endif //APIWEBSOCKETS_H