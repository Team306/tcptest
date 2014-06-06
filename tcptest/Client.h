#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork/QTcpSocket>
class CLIENT : public QTcpSocket{
    Q_OBJECT
 public:
    inline CLIENT(){}
    ~CLIENT(){}

};

#endif // CLIENT_H
