/***************************************************************************
   qgsdbsourceselectbase.h
    --------------------------------------
   Date                 : 08.11.2021
   Copyright            : (C) 2021 Denis Rouzaud
   Email                : denis@opengis.ch
***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/

#ifndef QGSDBSOURCESELECTBASE_H
#define QGSDBSOURCESELECTBASE_H


#include "qgis_gui.h"
#include "ui_qgsdbsourceselectbase.h"
#include "qgsabstractdatasourcewidget.h"

class QSortFilterProxyModel;
class QgsAbstractDbTableModel;

/**
 * \ingroup gui
 * \brief The QgsDbSourceSelectBase class is a base class for database source widget selector
 * \since QGIS 3.24
 */
class GUI_EXPORT QgsDbSourceSelectBase : public QgsAbstractDataSourceWidget, protected Ui::QgsDbSourceSelectBase
{
    Q_OBJECT
  public:
    //! Constructor
    QgsDbSourceSelectBase( QWidget *parent = nullptr, Qt::WindowFlags fl = QgsGuiUtils::ModalDialogFlags, QgsProviderRegistry::WidgetMode widgetMode = QgsProviderRegistry::WidgetMode::None );

  protected:
    //! Sets the source model for the widget
    void setSourceModel( QgsAbstractDbTableModel *model );

    //! Returns the proxy model used to filter the results
    QSortFilterProxyModel *proxyModel() {return mProxyModel;}

  private:
    void filterResults();

    QSortFilterProxyModel *mProxyModel = nullptr;
    QMenu *mSearchSettingsMenu = nullptr;

    QAction *mSearchColumnAllAction = nullptr;
    QList<QAction *> mSearchColumnActions;
    QAction *mSearchModeWildCardAction = nullptr;
    QAction *mSearchModeRegexAction = nullptr;

};

#endif // QGSDBSOURCESELECTBASE_H
