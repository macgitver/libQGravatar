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

#ifndef QTGRAVATAR_ABSTRACT_CACHE_H
#define QTGRAVATAR_ABSTRACT_CACHE_H

#include <QObject>
#include <QDateTime>
#include <QPixmap>

#include "QtGravatarApi.h"

class QtGravatarCacheEntry
{
public:
	struct Avatar
	{
		QtGravatarRating	mMaximumRating;
		QDateTime			mExpires;
		QPixmap				mImage;
	};

	QString				mMail;
	QList< Avatar >		mAvatars;
};

class QTGRAVATAR_API QtGravatarAbstractCache : public QObject
{
	Q_OBJECT
public:
	QtGravatarAbstractCache( QObject* parent = 0 );

public:

	virtual void purge() = 0;

	void setDuration( int sec );
	int duration() const;
};

#endif
