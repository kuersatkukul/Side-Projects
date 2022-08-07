#include <QThread>
#include <conio.h>
#include "RemoteControl.h"

RemoteControl::RemoteControl(const std::shared_ptr<SimpleLogger> p_simpleLogger)
{
	qRegisterMetaType<RemoteControlInputValue>("RemoteControlInputValue");
	m_simpleLogger = p_simpleLogger;
	m_simpleLogger->writeToLogFile("RemoteControl started.");
}

void RemoteControl::listen()
{
	m_simpleLogger->writeToLogFile("Remontrol listen() ...");
	while (1)
	{
		m_simpleLogger->writeToLogFile("Remontrol listen() ...");
		int arrowKeyAsInt = _getch();
		RemoteControlInputValue remoteInput = static_cast<RemoteControlInputValue>(arrowKeyAsInt);

		switch (remoteInput)
		{
		case RemoteControlInputValue::UP:
			m_simpleLogger->writeToLogFile(toQString(RemoteControlInputValue::UP));
			emit(RemoteControlInputValue::UP);
			break;
		case RemoteControlInputValue::DOWN:
			m_simpleLogger->writeToLogFile(toQString(RemoteControlInputValue::DOWN));
			emit(RemoteControlInputValue::DOWN);
			break;
		case RemoteControlInputValue::RIGHT:
			m_simpleLogger->writeToLogFile(toQString(RemoteControlInputValue::RIGHT));
			emit(RemoteControlInputValue::RIGHT);
			break;
		case RemoteControlInputValue::LEFT:
			m_simpleLogger->writeToLogFile(toQString(RemoteControlInputValue::LEFT));
			emit(RemoteControlInputValue::LEFT);
			break;
		default:
			break;
		}

		QThread::msleep(1000);
	}
}

QString RemoteControl::toQString(const RemoteControlInputValue p_remoteControlInput)
{
	switch (p_remoteControlInput)
	{
	case RemoteControlInputValue::UP:
		return QString("UP");
	case RemoteControlInputValue::DOWN:
		return QString("DOWN");
	case RemoteControlInputValue::RIGHT:
		return QString("RIGHT");
	case RemoteControlInputValue::LEFT:
		return QString("LEFT");
	default:
		break;
	}
	return QString("Not UP, DOWN, RIGHT or LEFT");
}
