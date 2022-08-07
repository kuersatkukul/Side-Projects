#pragma once

#include <QString>
#include <QDomDocument>
#include "ChannelModel.h"

const QString CHANNEL_TAG("Channel");
const QString CHANNEL_NAME("channelName");
const QString CHANNEL_LINK("channelLink");

class XmlReader
{
public:
	XmlReader(const QString& p_xmlFileName);
	QList<ChannelNameAndLink> getChannelsFromXml();
private:
	void createDomDocument();
	QString m_xmlFilePath;
	QDomDocument m_document;
};
