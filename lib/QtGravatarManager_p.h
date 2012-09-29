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

#ifndef QTGRAVATAR_MANAGER_P_H
#define QTGRAVATAR_MANAGER_P_H

#include <QHash>
#include <QPixmap>
#include <QNetworkAccessManager>

#include "QtGravatarManager.h"

class QtGravatarManager::Private : public QObject
{
	Q_OBJECT
public:
	Private( QObject* parent );

public:
	QNetworkAccessManager*		mNetAccess;
	QtGravatarAbstractCache*	mCache;
	QtGravatarDefault			mFallbackMethod;
	QHash< int, QPixmap >		mFallbackImages;
	int							mDefaultSize;
};

#endif