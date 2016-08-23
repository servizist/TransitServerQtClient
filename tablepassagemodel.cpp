#include "tablepassagemodel.h"

TablePassageModel::TablePassageModel() {
}

TablePassageModel::~TablePassageModel() {
}


int TablePassageModel::rowCount(const QModelIndex &parent) const {
    return passages.count();
}

int TablePassageModel::columnCount(const QModelIndex &parent) const {
    return 3;
}

QVariant TablePassageModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= passages.count() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        WaypointPassage *p = passages.at(index.row());
        if (index.column() == 0)
            return QVariant(p->comCode);
        else if (index.column() == 1)
            return QVariant(QString("%1- %2").arg(p->destinationDe).arg(p->destinationIt));
        else if (index.column() == 2)
            return QVariant(p->dueIn);
    }
    return QVariant();
}


QVariant TablePassageModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Linea - Linie");
        case 1:
            return tr("Destinazione - Ziel");
        case 2:
            return tr("Arriva tra - Ankunft in");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QList<WaypointPassage *> *TablePassageModel::getPassages() {
    return &passages;
}

void TablePassageModel::addPassage(WaypointPassage *passage) {
    passages.append(passage);
    emit layoutChanged();
}
