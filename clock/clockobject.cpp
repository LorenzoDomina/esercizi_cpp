#include "clockobject.h"

ClockObject::ClockObject(QObject *parent) : QAbstractListModel(parent)
{
    // Aggiungiamo alcune sveglie di esempio
//    m_alarms.append({true, QTime(7, 0)});
//    m_alarms.append({false, QTime(8, 30)});
//    m_alarms.append({true, QTime(12, 15)});

    m_alarms = {
        {
            true,
            "12:15",
        },
        {
           false,
            "8:30",
        },

    };
}

int ClockObject::rowCount(const QModelIndex &parent) const
{
    return m_alarms.size();
}

QVariant ClockObject::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_alarms.size())
        return QVariant();

    const AlarmData &alarm = m_alarms.at(index.row());

    switch (role) {
    case ActiveRole:
        return alarm.active;
    case DateTimeRole:
        return alarm.datetime;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ClockObject::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ActiveRole] = "isActive";
    roles[DateTimeRole] = "dateTime";
    return roles;
}

void ClockObject::addAlarm(QTime datatime)
{
    beginInsertRows(QModelIndex(), m_alarms.size(), m_alarms.size());
    m_alarms.append(AlarmData{true, datatime.toString("H:mm")});
    endInsertRows();
}

bool ClockObject::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == ActiveRole) {
        m_alarms[index.row()].active = value.toBool();
    }
    emit dataChanged(index, index);
    return true;
}



