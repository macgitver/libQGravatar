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

#include "QtGravatarManager.h"
#include "QtGravatarManager_p.h"
#include "QtGravatarMemoryCache.h"

#define safesize(x) ( ( (x) == -1 ) ? d->mDefaultSize : (x) )

QtGravatarManager::Private::Private( QObject* parent )
	: QObject( parent )
{
	mCache = new QtGravatarMemoryCache( this );
	mNetAccess = new QNetworkAccessManager( this );

	mFallbackMethod = QtGravatarDefaultNone;
	mDefaultSize = 80;
}

QtGravatarManager::QtGravatarManager( QObject* parent )
	: QObject( parent )
{
	d = new Private( this );
}

QtGravatarManager::~QtGravatarManager()
{
	delete d;
}

bool QtGravatarManager::isOnline() const
{
	return d->mNetAccess->networkAccessible() == QNetworkAccessManager::Accessible;
}

QtGravatarAbstractCache* QtGravatarManager::cache()
{
	return d->mCache;
}

void QtGravatarManager::setCache( QtGravatarAbstractCache* cache )
{
	Q_ASSERT( cache );

	if( d->mCache->parent() == d )
	{
		d->mCache->deleteLater();
	}

	d->mCache = cache;
}

void QtGravatarManager::purgeCache()
{
	d->mCache->purge();
}

void QtGravatarManager::setCacheDuration( int sec )
{
	cache()->setDuration( sec );
}

int QtGravatarManager::cacheDuration() const
{
	return d->mCache->duration();
}

void QtGravatarManager::setFallbackImage( const QPixmap& pixmap )
{
	Q_ASSERT( !pixmap.isNull() );
	Q_ASSERT( pixmap.width() == pixmap.height() );	// Must be square

	d->mFallbackImages[ pixmap.width() ] = pixmap;
}

QPixmap QtGravatarManager::fallbackImage( int size ) const
{
	return d->mFallbackImages.value( safesize( size ) );
}

void QtGravatarManager::clearFallbackImages()
{
	d->mFallbackImages.clear();
}

void QtGravatarManager::setFallback( QtGravatarDefault fallback )
{
	d->mFallbackMethod = fallback;
}

QtGravatarDefault QtGravatarManager::fallback() const
{
	return d->mFallbackMethod;
}

void QtGravatarManager::setDefaultSize( int size )
{
	d->mDefaultSize = size;
}

int QtGravatarManager::defaultSize() const
{
	return d->mDefaultSize;
}

QtGravatar* QtGravatarManager::get( const QString& email, int size, QtGravatarRating maximumRating )
{

}

