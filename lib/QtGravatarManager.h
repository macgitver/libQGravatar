/*
 * libQtGravatar
 * Cached accessor library to gravatar.com written in C++ and Qt
 * Copyright (C) 2012 Sascha Cunz <sascha@babbelbox.org>
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the
 * GNU General Public License (Version 2) as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program; if
 * not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef QTGRAVATAR_MANAGER_H
#define QTGRAVATAR_MANAGER_H

#include "QtGravatarApi.h"

#include <QObject>

class QPixmap;

class QtGravatar;
class QtGravatarAbstractCache;

class QTGRAVATAR_API QtGravatarManager : public QObject
{
	class Private;
	Q_OBJECT
public:
	QtGravatarManager( QObject* parent = 0 );
	~QtGravatarManager();

public:
	bool isOnline() const;

	QtGravatarAbstractCache* cache();
	void setCache( QtGravatarAbstractCache* cache );

	void purgeCache();

	void setCacheDuration( int sec );
	int cacheDuration() const;

	void setFallbackImage( const QPixmap& pixmap );
	QPixmap fallbackImage( int size = -1 ) const;
	void clearFallbackImages();

	void setFallback( QtGravatarDefault fallback );
	QtGravatarDefault fallback() const;

	void setDefaultSize( int size );
	int defaultSize() const;

	QtGravatar* get( const QString& email,
					 int size = -1,
					 QtGravatarRating maximumRating = QtGravatarRatedG );

signals:
	void gotAvailable( const QString& email, int size, const QPixmap& avatar );

private:
	Private* d;
};

#endif
