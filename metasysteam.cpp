#include "metasysteam.h"
#include "Tperson.h"
#include <QMetaProperty>

metasysteam::metasysteam(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    ui.add_boy->setProperty("isboy", true);
    ui.add_girl->setProperty("isboy", false);
    boy = new Tperson("boy", "Ham", 14, this);
    girl = new Tperson("girl", "Alice", 14, this);
    QObject::connect(boy, SIGNAL(age_c(quint8)), this, SLOT(do_age_changed(int)));
    QObject::connect(girl, SIGNAL(age_c(quint8)), this, SLOT(do_age_changed(int)));
    QObject::connect(ui.boy_age, SIGNAL(valueChanged(int)), this, SLOT(do_spin_changed(int)));
    QObject::connect(ui.girl_age, SIGNAL(valueChanged(int)), this, SLOT(do_spin_changed(int)));
    QObject::connect(ui.add_boy, SIGNAL(clicked()), this, SLOT(do_boy_add()));
    QObject::connect(ui.add_girl, SIGNAL(clicked()), this, SLOT(do_girl_add()));
    QObject::connect(ui.clear, SIGNAL(clicked()), this, SLOT(do_clear()));
    QObject::connect(ui.get_information, SIGNAL(clicked()), this, SLOT(do_get_information()));
}

metasysteam::~metasysteam()
{}

void metasysteam::do_age_changed(int value) {
    Tperson* person = qobject_cast<Tperson*>(sender());
    if (person == boy) {
        ui.boy_age->setValue(value);
    }
    else if (person == girl) {
        ui.girl_age->setValue(value);
    }
    QString str = QString("age=%1").arg(value);
    ui.show_text->appendPlainText(str);
}

void metasysteam::do_spin_changed(int value) {
    QSpinBox* spin = qobject_cast<QSpinBox*>(sender());
    if (spin->property("isboy").toBool()) {
        boy->set_age(value);
    }
    else {
        girl->set_age(value);
    }
    QString str = QString("age=%1").arg(value);
    ui.show_text->appendPlainText(str);
}

void metasysteam::do_boy_add() {
    boy->age_cha();
    // Temporarily block signals to avoid looping
    ui.boy_age->blockSignals(true);
    ui.boy_age->setValue(boy->get_age());
    QString str = QString("age=%1").arg(boy->get_age());
    ui.show_text->appendPlainText(str);
    ui.boy_age->blockSignals(false);
}

void metasysteam::do_girl_add() {
    girl->age_cha();
    // Temporarily block signals to avoid looping
    ui.girl_age->blockSignals(true);
    ui.girl_age->setValue(girl->get_age());
    QString str = QString("age=%1").arg(girl->get_age());
    ui.show_text->appendPlainText(str);
    ui.girl_age->blockSignals(false);
}


void metasysteam::do_clear() {
    ui.show_text->clear();
}

void metasysteam::do_get_information() {
    const QMetaObject* meta = boy->metaObject();
    auto meta_boy = meta;
    auto meta_girl = girl->metaObject();
    ui.show_text->appendPlainText(QString("class name:%1").arg(meta->className()));
    ui.show_text->appendPlainText("class information:");
    for (int i = meta->classInfoOffset(); i < meta->classInfoCount(); i++) {
        auto c = meta->classInfo(i);
        ui.show_text->appendPlainText(QString("property name:%1,property value:%2").arg(c.name()).arg(c.value()));
    }
    ui.show_text->appendPlainText(QString("\nboy information:"));
    for (int i = meta_boy->propertyOffset(); i < meta_boy->propertyCount(); i++) {
        auto c = meta_boy->property(i).name();
        auto d = boy->property(c).toString();
        ui.show_text->appendPlainText(QString("property name=%1,property value=%2").arg(c).arg(d));
    }
    ui.show_text->appendPlainText(QString("\ngirl information:"));
    for (int i = meta_girl->propertyOffset(); i < meta_girl->propertyCount(); i++) {
        auto c = meta_girl->property(i).name();
        auto d = girl->property(c).toString();
        ui.show_text->appendPlainText(QString("property name=%1,property value=%2").arg(c).arg(d));
    }
}
