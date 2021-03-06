/***************************************************************************
 *   Copyright (C) 2005, Carnegie Mellon University.                       *
 *   Maintained by: Daniel Weller                                          *
 *                  Rahul Mangharam                                        *
 *                  and the rest of the GrooveNet Team                     *
 *                                                                         *
 *   Email: dweller@ece.cmu.edu or rahulm@ece.cmu.edu                      *
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
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _QMESSAGELIST_H
#define _QMESSAGELIST_H

#include <qwidget.h>
#include <qmutex.h>
#include <qlayout.h>
#include <qlistbox.h>
#include <qlineedit.h>
#include <qtextedit.h>

#include <vector>

class QLabel;
class QLineEdit;
class QPushButton;
class QPopupMenu;
class QListBox;

class QMessageList : public QWidget
{
Q_OBJECT
public:
	QMessageList(QWidget * parent = NULL, const char * name = 0, Qt::WFlags f = 0);
	QMessageList();
	~QMessageList();

	void addMessage(QString msg);
	void clear();
protected:
	QWidget * m_boxMessages;
	QListBox * m_listMessages;
	QBoxLayout * layout;
};

extern QMessageList * m_pMessageList;

#endif
