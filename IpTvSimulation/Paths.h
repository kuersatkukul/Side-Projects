#pragma once
#include <QString>
#include <QDir>

namespace Paths
{
	const QString executionDir = QDir::currentPath() + "/";
	const QString tvIconPath = executionDir + "tv.ico";
	const QString channelsXml = executionDir + "channels.xml";
	const QString logFilePath = executionDir + "log.txt";
}
