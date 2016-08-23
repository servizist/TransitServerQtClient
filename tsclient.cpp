#include "tsclient.h"
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QtNetwork/QNetworkRequest>
#include "tablepassagemodel.h"



TSClient::TSClient(QWidget *parent) : QWidget(parent) {
    //ui
    QGridLayout *grid = new QGridLayout(this);
    QPushButton *requestButton = new QPushButton("Next passages for waypoint");
    grid->addWidget(requestButton,0,4,1,4);
    waypointCode = new QLineEdit(this);
    grid->addWidget(waypointCode,0,0,1,4);
    passageView  = new QTableView(this);
    passageModel = new TablePassageModel();
    parser.setPassageModel(passageModel);
    passageView->setModel(passageModel);
    grid->addWidget(passageView,1,0,4,8);
    connect(requestButton,SIGNAL(clicked(bool)),this,SLOT(onClickRequest()));
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
}

TSClient::~TSClient() {
    delete passageModel;
}

void TSClient::onClickRequest() {

    const char* username = "test";
    const char* password = "<your_password>";

    qDebug() << "Clicked request" << waypointCode->text();
    QString urlPassage = QString("https://mocobus.sii.bz.it/transit-service/passage/%1/next").arg(waypointCode->text());
    QSslConfiguration config; //after this, above error pops up
    //config.setProtocol(QSsl::SslV3);
    QNetworkRequest request;
    request.setUrl(urlPassage);
    request.setSslConfiguration(config);
    //request.setRawHeader( "Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader( "Authorization", "Basic " + QByteArray(QString("%1:%2").arg(username).arg(password).toLatin1()).toBase64());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");
    //request.setRawHeader("X-Application","Somekey");
    manager->get(request);
    passageView->resizeColumnsToContents();
}

void TSClient::replyFinished(QNetworkReply *reply) {
    QByteArray netData = reply->readAll();
    qDebug() << netData.data();
    parser.jsonParse(netData);
    passageView->resizeColumnsToContents();
}

