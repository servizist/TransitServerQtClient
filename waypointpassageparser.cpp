#include "waypointpassageparser.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include "tablepassagemodel.h"

WayPointPassageParser::WayPointPassageParser(QObject *parent) : QObject(parent) {
}

WayPointPassageParser::~WayPointPassageParser() {
}

void WayPointPassageParser::jsonParse(QByteArray data) {
        QJsonDocument jDoc = QJsonDocument::fromJson(data);
        QJsonArray jsonPassages = jDoc.array();
        WaypointPassage *passage;
        foreach (QJsonValue jV, jsonPassages) {
            passage = new WaypointPassage();
            QJsonObject jsonPassage = jV.toObject();
            passage->lineId        = jsonPassage.value("lineId").toInt();
            passage->runId         = jsonPassage.value("runId").toInt();
            passage->wayPointId    = jsonPassage.value("waypointId").toInt();
            passage->comCode       = jsonPassage.value("comCode").toString();
            passage->lastTxTime    = jsonPassage.value("lastTxTime").toInt();
            passage->lastTxPoint   = jsonPassage.value("lastTxPoint").toInt();
            passage->destinationDe = jsonPassage.value("destinationDE").toString();
            passage->destinationIt = jsonPassage.value("destinationIT").toString();
            passage->dueIn         = jsonPassage.value("dueIn").toInt();
            passage->delay         = jsonPassage.value("delay").toString();
            passage->key           = jsonPassage.value("key").toString();
            passage->scheduledTime = QDateTime::fromString(jsonPassage.value("scheduledTime").toString(),"hh:mm:ss");
            passage->estimatedTime = QDateTime::fromString(jsonPassage.value("estimatedTime").toString(),"hh:mm:ss");
            passageModel->addPassage(passage);
        }
}

void WayPointPassageParser::setPassageModel(TablePassageModel *passageModel) {
    this->passageModel = passageModel;
}


