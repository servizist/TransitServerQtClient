#ifndef TSCLIENT_H
#define TSCLIENT_H

#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>
#include <QtNetwork/QSslError>
#include "waypointpassageparser.h"
#include "tablepassagemodel.h"

class TSClient : public QWidget {
    Q_OBJECT

public:
    TSClient(QWidget *parent = 0);
    ~TSClient();

public slots:
    void onClickRequest();
    void replyFinished(QNetworkReply *reply);

private:
    QLineEdit *waypointCode;
    QNetworkAccessManager *manager;
    WayPointPassageParser parser;
    QTableView *passageView;
    TablePassageModel *passageModel;

};

#endif // TSCLIENT_H
