#include <QDateTime>
#include "SimpleLogger.h"
#include "Paths.h"

SimpleLogger& SimpleLogger::instance()
{
	static SimpleLogger m_logger;
	if(m_logger.m_logFile.fileName().isEmpty())
	{
		m_logger.m_logFile.setFileName(Paths::logFilePath);
		m_logger.m_logFile.open(QIODevice::ReadWrite);
		m_logger.m_fileStream.setDevice(&(m_logger.m_logFile));
		m_logger.log("** Logging started");
	}
	return m_logger;
}

void SimpleLogger::cleanUp()
{
	this->m_logFile.close();
}

void SimpleLogger::log(const QString& p_logMsg)
{
	m_fileStream<< QDateTime::currentDateTime().toString() << ":  " << p_logMsg + "\n";
}
