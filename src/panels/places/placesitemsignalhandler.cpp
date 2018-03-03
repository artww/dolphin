/***************************************************************************
 *   Copyright (C) 2012 by Peter Penz <peter.penz19@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#include "placesitemsignalhandler.h"

#include "placesitem.h"

PlacesItemSignalHandler::PlacesItemSignalHandler(PlacesItem* item,
                                                 QObject* parent) :
    QObject(parent),
    m_item(item)
{
}

PlacesItemSignalHandler::~PlacesItemSignalHandler()
{
}

void PlacesItemSignalHandler::onAccessibilityChanged()
{
    if (m_item) {
        m_item->onAccessibilityChanged();
    }
}

void PlacesItemSignalHandler::onTrashDirListerCompleted()
{
    if (m_item) {
        m_item->onTrashDirListerCompleted();
    }
}

void PlacesItemSignalHandler::onTearDownRequested(const QString& udi)
{
    Q_UNUSED(udi)
    if (m_item) {
        Solid::StorageAccess *tmp = m_item->device().as<Solid::StorageAccess>();
        if (tmp) {
            QString mountPath = tmp->filePath();
            emit tearDownExternallyRequested(mountPath);
        }
    }
}

