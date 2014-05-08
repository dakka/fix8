/********************************************************************
File		nameDelegte.cpp
Descript:	USed to paint tab  column for ModelView

Protject:	ClassMaster

Author:		David N Boosalis
Date:		Jan 4, 2011 Allrights reserverd by author
*******************************************************************/
#include "dateTimeDelegate.h"
#include <QDateTime>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QStandardItemModel>
#include <QStyleOptionViewItem>
#include <dateTimeDelegate.h>

GUI::Globals::TimeFormat DateTimeDelegate::timeFormat =
        GUI::Globals::HHMMSS;
DateTimeDelegate::DateTimeDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{
    configPixmap= QPixmap(":/images/svg/config.svg");

}
void DateTimeDelegate::setTimeFormat(GUI::Globals::TimeFormat tf)
{
    timeFormat = tf;
}

QSize	DateTimeDelegate::sizeHint( const QStyleOptionViewItem & option,
                                    const QModelIndex & index ) const
{
    QSize s = QStyledItemDelegate::sizeHint(option,index);
   return s;
} 

/****************************************************************/
void DateTimeDelegate::paint(QPainter *painter,
                             const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QString str;
    //QStyledItemDelegate::paint(painter,option,index);
    painter->save();
    QDateTime dt = index.data(Qt::UserRole + 2).toDateTime();
    switch(timeFormat) {
    case GUI::Globals::DAYMONYRHHMMSS:
        str = dt.toString("ddd-mm-yy hh:mm:ss");
        break;
    case GUI::Globals::DAYMMMHHMMSS:
        str = dt.toString("ddd-mm hh:mm:ss");
        break;
    case GUI::Globals::HHMMSS:
        str = dt.toString("hh:mm:ss");
        break;
    case GUI::Globals::HHMM:
        str = dt.toString("hh:mm");
        break;
    default:
        qWarning() << "DateTimeDeleaget = format unknown" << __FILE__ << __LINE__;
        str = dt.toString("hh:mm:ss");
    }

    QRect rect = option.rect;
    /*
    QRect pixRect;
    pixRect.setX(rect.x()*1.1);
    pixRect.setY(rect.y() + rect.height()*.1);
    pixRect.setHeight(rect.height() *.80);
    pixRect.setWidth(pixRect.height());

    painter->setClipRect(option.rect);
    painter->drawPixmap(pixRect,configPixmap);
    */
    painter->drawText(rect,Qt::AlignVCenter,str);
    painter->restore();
}
