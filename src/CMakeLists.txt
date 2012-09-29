
PROJECT( QtGravatarTest )

INCLUDE( ${QT_USE_FILE} )

SET( SRC_FILES
	main.cpp
	MainWindow.cpp
)

SET( HDR_FILES
	MainWindow.h
)

QT4_MOC( MOC_FILES ${HDR_FILES} )

ADD_QT_EXECUTABLE(
	QtGravatarTester

	${SRC_FILES}
	${HDR_FILES}
	${MOC_FILES}
)

TARGET_LINK_LIBRARIES(
	QtGravatarTester

	QtGravatar
)
