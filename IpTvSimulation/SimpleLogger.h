#pragma once
#include <QFile>
#include <QTextStream>

class SimpleLogger
{
public:
	static SimpleLogger& instance();
	void log(const QString& p_logMsg);
	void cleanUp();
private:
	QString m_logFilePath;
	QFile m_logFile;
	QTextStream m_fileStream;
};
