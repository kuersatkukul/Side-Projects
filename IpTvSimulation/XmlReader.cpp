#include <QFile>
#include <QDir>
#include <QDebug>
#include "XmlReader.h"

    XmlReader::XmlReader(const QString& p_xmlFileName) 
        : m_xmlFilePath(p_xmlFileName)
    {}

    QList<ChannelNameAndLink> XmlReader::getChannelsFromXml()
    {
        createDomDocument();
        QList<ChannelNameAndLink> ret;
        
        //Alle <Channel></Channel> rauslesen
        QDomNodeList channelNodes = m_document.elementsByTagName(CHANNEL_TAG);
        for (int i = 0; i < channelNodes.size(); i++)
        {
            QDomNamedNodeMap attributes = channelNodes.at(i).toElement().attributes();
            ChannelNameAndLink toAdd;
            toAdd.channelName = attributes.namedItem(CHANNEL_NAME).toAttr().value();
            toAdd.channelLink = attributes.namedItem(CHANNEL_LINK).toAttr().value();
            ret.append(toAdd);
        }
        qDebug() << "size: " << ret.size();
        Q_ASSERT(ret.size() > 0);
        return ret;
    }

    void XmlReader::createDomDocument()
    {
        //DOM erstellen
        QFile file(m_xmlFilePath);
        if (!file.open(QIODevice::ReadOnly))
            return;
        if (!m_document.setContent(&file)) {
            file.close();
            return;
        }
        file.close();
    }
