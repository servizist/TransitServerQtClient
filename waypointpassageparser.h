#ifndef WAYPOINTPASSAGEPARSER_H
#define WAYPOINTPASSAGEPARSER_H

#include <QObject>
#include <QDateTime>

class TablePassageModel;

/*"lineId" : 1974,
  "runId" : 3254,
  "waypointId" : 9422,
  "comCode" : "130",
  "destinationDE" : "ST.NIKOLAUS ÜBER GIRLAN",
  "destinationIT" : "S.NICOLÒ VIA CORNAIANO",
  "lastTxTime" : -1,
  "lastTxPoint" : -1,
  "dueIn" : 49,
  "delay" : "---",
  "key" : "W9422-L1974-R3254-63360",
  "scheduledTime" : "2015-04-20 17:36:00",
  "estimatedTime" : "2015-04-20 17:36:00"
} ]"*/

class WaypointPassage : public QObject {
public:
    int     lineId;
    int     runId;
    int     wayPointId;
    QString comCode;
    QString destinationDe;
    QString destinationIt;
    long    lastTxTime;
    int     lastTxPoint;
    int     dueIn;
    QString delay;
    QString key;
    QDateTime   scheduledTime;
    QDateTime   estimatedTime;
};

class WayPointPassageParser : public QObject {
    Q_OBJECT
public:
    explicit WayPointPassageParser(QObject *parent = 0);
    ~WayPointPassageParser();
    void jsonParse(QByteArray data);
    void setPassageModel( TablePassageModel *passageModel);

signals:

public slots:

private:
    TablePassageModel *passageModel;

};

#endif // WAYPOINTPASSAGEPARSER_H
