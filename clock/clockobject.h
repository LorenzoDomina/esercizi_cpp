#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QVector>
#include <QTime>

// Struttura per rappresentare una sveglia
struct AlarmData {
    bool active;
    QString datetime;
};

class ClockObject : public QAbstractListModel
{
    Q_OBJECT

public:
    enum AlarmRoles {
        ActiveRole = Qt::UserRole+1,
        DateTimeRole
    };

    explicit ClockObject(QObject *parent = nullptr);

    // Metodi richiesti per il modello
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addAlarm(QTime time);

private:
    QVector<AlarmData> m_alarms;

    // QAbstractItemModel interface
public:
    bool setData(const QModelIndex &index, const QVariant &value, int role);
};
