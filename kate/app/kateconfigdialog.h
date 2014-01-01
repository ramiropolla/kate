/* This file is part of the KDE project
   Copyright (C) 2001 Christoph Cullmann <cullmann@kde.org>
   Copyright (C) 2002 Joseph Wenninger <jowenn@kde.org>
   Copyright (C) 2007 Mirko Stocker <me@misto.ch>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef __kate_configdialog_h__
#define __kate_configdialog_h__

#include <ktexteditor/applicationplugin.h>
#include <ktexteditor/configpageinterface.h>

#include <ktexteditor/editor.h>
#include <ktexteditor/document.h>
#include <ktexteditor/view.h>

#include <KPageDialog>
#include <QList>

class QCheckBox;
class QSpinBox;
class QRadioButton;
class KateMainWindow;

struct PluginPageListItem
{
  KTextEditor::ApplicationPlugin *plugin;
  KTextEditor::ConfigPageInterface *configPageInterface;
  uint idInPlugin;
  KTextEditor::ConfigPage *pluginPage;
  QWidget *pageParent;
  KPageWidgetItem *pageWidgetItem;
};

class KateConfigDialog : public KPageDialog
{
    Q_OBJECT

  public:
    KateConfigDialog (KateMainWindow *parent, KTextEditor::View *view);
    ~KateConfigDialog ();

  public:
    void addPluginPage (KTextEditor::ApplicationPlugin *plugin);
    void removePluginPage (KTextEditor::ApplicationPlugin *plugin);
    void showAppPluginPage(KTextEditor::ConfigPageInterface *configpageinterface,uint id);
  protected Q_SLOTS:
    void slotApply();
    void slotChanged();

    void slotCurrentPageChanged( KPageWidgetItem *current, KPageWidgetItem *before );

  private:
    KateMainWindow *m_mainWindow;

    KTextEditor::View* m_view;
    bool m_dataChanged;

    QCheckBox *m_modNotifications;
    QCheckBox *m_saveMetaInfos;
    QSpinBox *m_daysMetaInfos;
    QCheckBox *m_restoreVC;

    // sessions start group:
    QRadioButton *m_startNewSessionRadioButton;
    QRadioButton *m_loadLastUserSessionRadioButton;
    QRadioButton *m_manuallyChooseSessionRadioButton;

    QHash<KPageWidgetItem*, PluginPageListItem*> m_pluginPages;
    QList<KTextEditor::ConfigPage *> m_editorPages;
    KPageWidgetItem *m_applicationPage;
    KPageWidgetItem *m_editorPage;

    void addEditorPages();
};

#endif
// kate: space-indent on; indent-width 2; replace-tabs on;

