#pragma once
#include <QObject>
#include <memory>
#include "SimpleLogger.h"

class RemoteControl : public QObject
{
	Q_OBJECT

public:
	enum class RemoteControlInputValue
	{
		//the Idea is to use predefined Integers from Conio which are mapped to arrow keys
		//https://stackoverflow.com/questions/8435923/getting-arrow-keys-from-cin
		UP = 72,
		DOWN = 80,
		RIGHT = 75,
		LEFT = 77
	};

	RemoteControl(const std::shared_ptr<SimpleLogger> p_simpleLogger);

	/// Listens for Incoming Signals from Remote Control
	void listen();

	//Returns Remote Control Input as QString
	static QString toQString(const RemoteControlInputValue p_remoteControlInput);

signals:
	void remoteInput(const RemoteControlInputValue p_remoteControlInput);

private:
	std::shared_ptr<SimpleLogger> m_simpleLogger;
};

