cmake_minimum_required(VERSION 3.24)
project(IpTvSimulation)

# Automatic handling of MOC generation
set(CMAKE_AUTOMOC ON)

# We expect the user to put in QT5_INSTALLDIR 
if("${QT5_INSTALLDIR}" STREQUAL "")
	message(FATAL_ERROR "Variable QT5_INSTALLDIR=<pathToQt5> is empty\nUse -DQT5_INSTALLDIR to pass the Qt5 Installation directory to the executable")
else()
	list(APPEND CMAKE_PREFIX_PATH ${QT5_INSTALLDIR})
endif()

file(GLOB SRCS "${CMAKE_CURRENT_LIST_DIR}/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/*.h" "${CMAKE_CURRENT_LIST_DIR}/*.ico")
#add_executable(IpTvSimulation ${SRCS})

add_executable(IpTvSimulation 
	"MainWindow.h"
	"MainWindow.cpp"
	#"ChannelView.h"
	"main.cpp"
	"XmlReader.h"
	"SimpleLogger.cpp"
	"SimpleLogger.h"
	#"RemoteControl.cpp"
	#"ChannelView.cpp"
	"ChannelModel.cpp"
	"ChannelModel.h"
	"XmlReader.cpp"
	"tv.ico"
	#	"RemoteControl.h"
	"Paths.h"
)

find_package(Qt5 COMPONENTS Core Widgets WebEngine WebEngineWidgets Xml REQUIRED)

target_link_libraries(IpTvSimulation
	Qt5::Core
	Qt5::Gui
	Qt5::WebEngine
	Qt5::WebEngineWidgets
	Qt5::Xml
)
