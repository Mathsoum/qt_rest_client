#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>

class QNetworkReply;

class MyClient : public QObject
{
    Q_OBJECT

public:
    MyClient();
    virtual ~MyClient();

    void sendRequest(const QString& version);

public slots:
    void received(QNetworkReply* reply);

private:
    QNetworkAccessManager networkManager;
    QNetworkReply* currentReply;
};

#endif // MYCLIENT_H
