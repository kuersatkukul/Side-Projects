#pragma once
#include <QMainWindow>
#include <QListView>
#include <QWebEngineView>
#include <memory>
#include "ChannelModel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);

public slots:
	void onSelectionChanged(const QModelIndex& p_index, const QModelIndex& p_current);
private:
	std::unique_ptr<QListView> m_listView;
	QWebEngineView m_webEngineView;
	std::shared_ptr<ChannelModel> m_channelModel;
};
