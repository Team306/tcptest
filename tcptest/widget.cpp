#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *mainlayout = new QHBoxLayout;
    QVBoxLayout *leftlayout = new QVBoxLayout;
    QVBoxLayout *rightlayout = new QVBoxLayout;
    servertext = new QTextEdit;
    QPushButton *start = new QPushButton("start");
    connect(start,SIGNAL(clicked()),this,SLOT(start_clicked()));
    QPushButton *sendserver = new QPushButton(tr("send"));
    leftlayout->addWidget(servertext);
    leftlayout->addWidget(start);
    leftlayout->addWidget(sendserver);
    clienttext = new QTextEdit;
    QPushButton *connect1 = new QPushButton("connect");
    connect(connect1,SIGNAL(clicked()),this,SLOT(clientconnect()));
    QPushButton *sendclient = new QPushButton(tr("send"));
    connect(sendclient,SIGNAL(clicked()),this,SLOT(clientsend()));
    rightlayout->addWidget(clienttext);
    rightlayout->addWidget(connect1);
    rightlayout->addWidget(sendclient);
    mainlayout->addLayout(leftlayout);
    mainlayout->addLayout(rightlayout);
    setLayout(mainlayout);


}

Widget::~Widget()
{

}

void Widget::start_clicked(){
    servertext->setPlainText("server start");
    server = new QTcpServer;
    server->listen(QHostAddress::Any,19999);
    connect(server,SIGNAL(newConnection()),this,SLOT(newconnection()));
}

void Widget::newconnection(){
    newclient = server->nextPendingConnection();
    connect(newclient,SIGNAL(readyRead()),this,SLOT(serverget()));

}

void Widget::serverget(){
    //servertext->setPlainText(tr("new connection from client"));
    QByteArray qba = newclient->readAll();
    QString str = QVariant(qba).toString();
    servertext->setPlainText(str);
}

void Widget::clientconnect(){
    clienttext->setPlainText(tr("connecting......."));
    client = new QTcpSocket;
    client->abort();
    client->connectToHost("10.147.123.28",19999);
}

void Widget::clientsend(){
    QString str = clienttext->toPlainText();
    client->write(str.toStdString().c_str(),strlen(str.toStdString().c_str()));
}
