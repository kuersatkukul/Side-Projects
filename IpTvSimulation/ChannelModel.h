#pragma once
#include <QObject>
#include <QAbstractListModel>
#include "SimpleLogger.h"

struct ChannelNameAndLink
{
	QString channelName;
	QString channelLink;

	void logChannel() const
	{
		SimpleLogger::instance().log(QString("ChannelName: %1  ChannelLink: %2").arg(channelName).arg(channelLink));
	}
};

class ChannelModel : public QAbstractListModel
{
	Q_OBJECT

public:
	explicit ChannelModel(const QList<ChannelNameAndLink>& p_channels, QObject* parent = nullptr);
	int rowCount(const QModelIndex& p_parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& p_index, int p_role) const override;
	QVariant headerData(int p_section, Qt::Orientation p_orientation, int p_role = Qt::DisplayRole) const override;

	QString getLinkByIndex(const int p_idx);
private:
	QList<ChannelNameAndLink> m_channels;
};
