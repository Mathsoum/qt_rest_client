#include "myclient.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDataStream>

MyClient::MyClient()
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(received(QNetworkReply*)));
}

MyClient::~MyClient()
{

}

void MyClient::sendRequest(const QString &version)
{
    QUrl url("http://127.0.0.1:5000/get/" + version + "/");
    qDebug() << url.toString();
    QNetworkRequest request;
    request.setUrl(url);

    currentReply = networkManager.get(request);
}

void MyClient::received(QNetworkReply *reply)
{
    qDebug() << "Received !";
    QString data = (QString) reply->readAll();
    // qDebug() << data;
    QJsonDocument json = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject object = json.object();
    qDebug() << object["b64_data"].toString();

    QFile file("bender.png");
    if (file.open(QIODevice::ReadWrite))
    {
        QDataStream stream(&file);
        stream << QByteArray::fromBase64(object["b64_data"].toString().toUtf8());

    }
    file.close();
}
