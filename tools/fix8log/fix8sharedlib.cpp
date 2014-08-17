#include "fix8sharedlib.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QLibrary>
#include <QString>

Fix8SharedLib::Fix8SharedLib():count(0)
{
}
Fix8SharedLib * Fix8SharedLib::create(QString fileName)
{
    bool bstatus;
    QString str;
    Fix8SharedLib *f8sl = new Fix8SharedLib();
    f8sl->fileName = fileName;
    QFile file(fileName);
    if (!file.exists()) {
        f8sl->errorMessage  = "Error - No such library found for: " + fileName;
        qWarning() << f8sl->errorMessage << __FILE__ << __LINE__;
        f8sl->isOK = false;
        return f8sl;
    }
    QFileInfo fi(fileName);
    qDebug() << "FILE PATH + " << fi.absoluteFilePath() << __FILE__ << __LINE__;
    QString baseName = fi.baseName();
    QString libStr = baseName.left(3);
    if (libStr != "lib") {
        f8sl->errorMessage  = "Error - " + fileName + "does not appear to be a library";
        qWarning() << f8sl->errorMessage << __FILE__ << __LINE__;
        f8sl->isOK = false;
        return f8sl;
    }
    f8sl->name = baseName.right(baseName.length()-3);


    bstatus = f8sl->loadFix8so();
    f8sl->isOK = bstatus;
    qDebug() << "\tAFTER LOAD bstatus =" << bstatus << __FILE__ << __LINE__;
    return f8sl;
}
bool Fix8SharedLib::loadFix8so()
{
    bool bstatus;
    QString key;
    QString value;
    MessageField *messageField;
    fixLib = new QLibrary(fileName);

    bstatus = fixLib->load();
    if (!bstatus) {
        qWarning() << ">>>>> Error - failed loading library " << fileName << __FILE__ << __LINE__;
        errorMessage  =  "Error - failed loading library " + fileName;
        isOK = false;
        delete fixLib;
        return false;
    }
    QFunctionPointer _handle;
    QString ctxStr(name + "_ctx");
    const char *ctxfuncstr = ctxStr.toLatin1().data();
    _handle = fixLib->resolve(ctxfuncstr);
    if (!_handle) {
        qWarning()  << "Failed to get handle " << ctxfuncstr << " in library: " << fileName << __FILE__ << __LINE__;
        errorMessage = "Failed to get handle " +  ctxStr +  " in library: " + fileName;
        isOK = false;
        delete fixLib;
        return false;
    }
    int level;
    qDebug() << "EVERYTHING OK " << __FILE__ << __LINE__;
    bstatus = true;
    ctxFunc   = reinterpret_cast<const F8MetaCntx& (*)()> (_handle);
    int messageCount = ctxFunc()._bme.size();
    messageFieldList = new MessageFieldList();
    for(int ii=0;ii < messageCount; ii++) {
        const char *kk = ctxFunc()._bme.at(ii)->_key;
        const TraitHelper tr = ctxFunc()._bme.at(ii)->_value._create._get_traits();
        QBaseEntryList *qbaseEntryList = new QBaseEntryList();
        value = QString::fromStdString(ctxFunc()._bme.at(ii)->_value._name);
        key   = QString::fromStdString(ctxFunc()._bme.at(ii)->_key);

        messageField = new MessageField(key,value);
        int level = 0;
        generate_traits(tr,baseMap,fieldUseList,messageField,qbaseEntryList,&level);
        messageField->qbel = qbaseEntryList;
        messageFieldList->append(messageField);
    }
    QListIterator <FieldUse *> fieldIter(fieldUseList);
    while(fieldIter.hasNext()) {
        FieldUse *mf = fieldIter.next();
        fieldUsePairList.append(qMakePair(mf->name,mf));
    }
    qSort(fieldUsePairList.begin(), fieldUsePairList.end());
    return bstatus;
}
void Fix8SharedLib::generate_traits(const TraitHelper& tr,QMap <QString, QBaseEntry *> &baseMap,FieldUseList &ful,
                              MessageField *mf,QList <QBaseEntry *> *qbaseEntryList,int *level)
{
    int ii = 0;
    for (F8MetaCntx::const_iterator itr(F8MetaCntx::begin(tr)); itr != F8MetaCntx::end(tr); ++itr)
    {
        QBaseEntry *qbe;
        FieldUse *fieldUse = 0;
        QString name;
        const BaseEntry *be(ctxFunc().find_be(itr->_fnum)); // lookup the field
        if(qbaseEntryList) {
            qbe = baseMap.value(be->_name);
            if (!qbe) {
                qbe  = new QBaseEntry(*be);
                qbe->ft = new FieldTrait(*itr);
                baseMap.insert(qbe->name,qbe);
            }
            name = qbe->name;
            qbaseEntryList->append(qbe);
            if (defaultHeaderStrs.contains(name)) {
                if (!defaultHeaderItems.findByName(name))
                    defaultHeaderItems.append(qbe);
            }
            fieldUse = ful.findByName(name);
            if (!fieldUse) {
                fieldUse = new FieldUse();
                fieldUse->name = name;
                fieldUse->field = qbe->ft;
                ful.append(fieldUse);
            }
            fieldUse->messageFieldList.append(mf);
        }
        else
            qWarning() << "\t\tERROR QBASELIST = 0" ;
        //MessageBase *header =  new Message::Header();
        //cout << "Field Type: " << ft._ftype << endl;
        //cout << spacer << "\t" << *itr << endl; // use FieldTrait insert operator. g out traits.
        if (itr->_field_traits.has(FieldTrait::group)) {// any nested repeating groups?
            qbe->baseEntryList = new QList<QBaseEntry *>();
            generate_traits(itr->_group,baseMap,ful,mf,qbe->baseEntryList,level); // descend into repeating groups
        }
        ii++;
    }
}
void Fix8SharedLib::generate_traits(const TraitHelper& tr,QMap <QString, QBaseEntry *> &baseMap,FieldUseList &ful,
                              MessageField *mf,QBaseEntryList *qbaseEntryList,int *level)
{
    int ii = 0;
    QString name;
    for (F8MetaCntx::const_iterator itr(F8MetaCntx::begin(tr)); itr != F8MetaCntx::end(tr); ++itr)
    {
        QBaseEntry *qbe;
        FieldUse *fieldUse = 0;
        const BaseEntry *be(ctxFunc().find_be(itr->_fnum)); // lookup the field
        if(qbaseEntryList) {
            qbe = baseMap.value(be->_name);
            if (!qbe) {
                qbe  = new QBaseEntry(*be);
                qbe->ft = new FieldTrait(*itr);
                baseMap.insert(qbe->name,qbe);
            }
            name = qbe->name;
            qbaseEntryList->append(qbe);
            fieldUse = ful.findByName(name);
            if (!fieldUse) {
                fieldUse = new FieldUse();
                fieldUse->name = name;
                fieldUse->field = qbe->ft;
                ful.append(fieldUse);
            }
            fieldUse->messageFieldList.append(mf);
            if (defaultHeaderStrs.contains(name)) {
                if (!defaultHeaderItems.findByName(name))
                    defaultHeaderItems.append(qbe);
            }
        }
        if (itr->_field_traits.has(FieldTrait::group)) {// any nested repeating groups?
            qbe->baseEntryList = new QList<QBaseEntry *>();
            (*level)++;
            generate_traits(itr->_group,baseMap,ful,mf,qbe->baseEntryList,level); // descend into repeating groups
        }
        ii++;
    }
}

Fix8SharedLibList::Fix8SharedLibList(): QList<Fix8SharedLib *>()
{

}
Fix8SharedLib * Fix8SharedLibList::findByName(QString  &name)
{
    Fix8SharedLib  *fsl = 0;
    QListIterator <Fix8SharedLib *> iter(*this);
    while(iter.hasNext()) {
        fsl = iter.next();
        if (fsl->name == name)
            return(fsl);
    }
    return(0);
}
Fix8SharedLib * Fix8SharedLibList::findByFileName(QString  &filename)
{
    Fix8SharedLib  *fsl = 0;
    QListIterator <Fix8SharedLib *> iter(*this);
    while(iter.hasNext()) {
        fsl = iter.next();
        if (fsl->fileName == filename)
            return(fsl);
    }
    return(0);
}
bool Fix8SharedLibList::removeByName(QString &name)
{
    bool bstatus = false;
    Fix8SharedLib  *fsl = 0;
    QList<Fix8SharedLib *>::iterator iter;
    for(iter = this->begin();iter != this->end();++iter) {
        fsl = *iter;
        if (fsl->name == name) {
            erase(iter);
            bstatus = true;
            break;
        }
    }
    return bstatus;
}