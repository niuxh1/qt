#pragma once

#include <QtWidgets/QWidget>
#include "ui_metasysteam.h"
class Tperson;
class metasysteam : public QWidget
{
    Q_OBJECT

public:
    metasysteam(QWidget *parent = nullptr);
    ~metasysteam();

private:
    Tperson* boy;
    Tperson* girl;
    Ui::metasysteamClass ui;
private slots:void do_age_changed(int value);
             void do_spin_changed(int value);
             void do_boy_add();
             void do_girl_add();
             void do_clear();
             void do_get_information();
};
