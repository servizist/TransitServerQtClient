#ifndef TABLEPASSAGEMODEL_H
#define TABLEPASSAGEMODEL_H

#include <QAbstractTableModel>
#include "waypointpassageparser.h"


class TablePassageModel : public QAbstractTableModel {
public:
    TablePassageModel();
    ~TablePassageModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QList<WaypointPassage *> *getPassages();
    void addPassage(WaypointPassage *passage);

private:
    QList<WaypointPassage *> passages;
};

#endif // TABLEPASSAGEMODEL_H
