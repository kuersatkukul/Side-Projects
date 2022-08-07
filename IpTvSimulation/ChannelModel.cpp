#include "ChannelModel.h"

ChannelModel::ChannelModel(const QList<ChannelNameAndLink>& p_channels, QObject* parent)
	: QAbstractListModel(parent)
	, m_channels(p_channels)
{
	
	SimpleLogger::instance().log("CHannelModel: Initialized");
}

int ChannelModel::rowCount(const QModelIndex& p_parent) const
{
	return m_channels.size();
}

QVariant ChannelModel::data(const QModelIndex& p_index, int p_role) const
{
	if (!p_index.isValid() || p_index.row() >= m_channels.size())
		return QVariant();
	else
		switch (p_role)
		{
		case Qt::DisplayRole:
		{
			return QString::number(p_index.row()) + " " + m_channels.at(p_index.row()).channelName;
		}
		default:
			return QVariant();
		}
}

QVariant ChannelModel::headerData(int p_section, Qt::Orientation p_orientation, int p_role) const
{
	//funktioniert nicht wie gewollt, eigentlich toter Code
	if (p_role == Qt::DisplayRole && p_orientation == Qt::Vertical)
		return QStringLiteral("%0").arg(p_section);
	return QVariant();
}

QString ChannelModel::getLinkByIndex(const int p_idx)
{
	return m_channels[p_idx].channelLink;
}
