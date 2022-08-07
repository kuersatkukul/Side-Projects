#include <QListWidget>
#include <QWebEngineSettings>
#include "MainWindow.h"
#include "SimpleLogger.h"
#include "XmlReader.h"
#include "ChannelModel.h"
#include "Paths.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow()
{
	auto setStyleSheet = [&]()
	{
		m_listView->setStyleSheet(
		"QListView"
		"{"
		"background: steelblue;"
		"font-family: Comic Sans MS;"
		"font-size: 16px;"
		"font-style: bold;"
		"outline: 0"
		"}"

		"QListView::item::selected "
		"{"
		"background: lightgrey;"
		"}"
		);

	};
	m_listView = std::make_unique<QListView>();

	XmlReader reader = {Paths::channelsXml};
	m_channelModel = std::make_shared<ChannelModel>(reader.getChannelsFromXml());
	setStyleSheet();
	m_listView->setModel(m_channelModel.get());
	m_listView->resize(500,500);
	this->setCentralWidget(m_listView.get());

	QObject::connect(m_listView->selectionModel(), &QItemSelectionModel::currentChanged, this, &MainWindow::onSelectionChanged);
	m_webEngineView.settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
	m_webEngineView.settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);
	m_webEngineView.settings()->setAttribute(QWebEngineSettings::ScreenCaptureEnabled, true);
	m_webEngineView.settings()->setAttribute(QWebEngineSettings::AutoLoadImages, false);
	m_webEngineView.settings()->setAttribute(QWebEngineSettings::PlaybackRequiresUserGesture, false);
}

void MainWindow::onSelectionChanged(const QModelIndex& p_index, const QModelIndex& p_current)
{
	//Preventing the framework to start a QWebEngineView on initialization
	static int i = 0;
	if (i == 0)
	{
		i++;
		return;
	}
	this->setCentralWidget(&m_webEngineView);
	m_webEngineView.load(QUrl(m_channelModel->getLinkByIndex(p_index.row())));
	this->showFullScreen();
	m_webEngineView.show();

}
