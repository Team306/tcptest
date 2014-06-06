#ifndef SERVER_H
#define SERVER_H
#include <QList>
#include <QtNetwork/QTcpServer>
class SERVER : public QTcpServer
{
    Q_OBJECT

public:
    inline SERVER() {}
    static SERVER *instance();

    //void addClient(TorrentClient *client);
    //void removeClient(TorrentClient *client);

protected:
    void incomingConnection(qintptr socketDescriptor);

private slots:
    //void removeClient();
    //void processInfoHash(const QByteArray &infoHash);


private:
    //QList<TorrentClient *> clients;
};

#endif // SERVER_H
