#include "Tperson.h"

Tperson::Tperson(QString sex, QString name, quint8 age, QObject* parent)
    : QObject(parent), t_sex(sex), t_name(name), t_age(age) {}

int Tperson::get_age() {
    return t_age;
}

void Tperson::set_age(quint8 age) {
    if (t_age != age)
        emit age_c(age);
    t_age = age;
}

QString Tperson::get_t_sex() {
    return t_sex;
}

void Tperson::set_t_sex(QString sex) {
    t_sex = sex;
}

QString Tperson::get_t_name() {
    return t_name;
}

void Tperson::set_t_name(QString name) {
    t_name = name;
}
int Tperson::age_cha() {
    t_age++;
    emit age_c(t_age);
    return t_age;
}