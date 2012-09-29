
PROJECT( libQtGravatar )

SET( QT_USE_QTNETWORK		1 )
SET( QT_USE_QTSQL			1 )
INCLUDE( ${QT_USE_FILE} )

SET( SRC_FILES
	QtGravatar.cpp
	QtGravatarManager.cpp
	QtGravatarAbstractCache.cpp
	QtGravatarMemoryCache.cpp
)

SET( PRI_HDR_FILES
	QtGravatar_p.h
	QtGravatarManager_p.h
	QtGravatarMemoryCache.h
)

SET( PUB_HDR_FILES
	QtGravatar.h
	QtGravatarAbstractCache.h
	QtGravatarApi.h
	QtGravatarManager.h
)

SET( HDR_FILES ${PRI_HDR_FILES} ${PUB_HDR_FILES} )
QT4_MOC( MOC_FILES ${HDR_FILES} )

ADD_QT_LIBRARY(
	QtGravatar		SHARED

	${SRC_FILES}
	${HDR_FILES}
	${MOC_FILES}
)
