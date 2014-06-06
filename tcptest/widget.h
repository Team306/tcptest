#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QObject>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>
#include <QByteArray>
#include <QVariant>
//#include "server.h"
//#include "Client.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void start_clicked();
    void newconnection();
    void serverget();
    void clientsend();
    void clientconnect();
    void clientread();
private:
    QTextEdit *servertext;
    QTextEdit *clienttext;
    QTcpServer *server;
    QTcpSocket *newclient;
    QTcpSocket *client;
};

#endif // WIDGET_H
