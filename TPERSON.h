#pragma once
#include<qwidget.h>
class Tperson :public QObject {
	Q_OBJECT;
	Q_CLASSINFO("author","XuancaiNiu")
	Q_CLASSINFO("school", "Sysu")
	Q_CLASSINFO("verison", "1.0")
	Q_PROPERTY(QString t_sex READ get_t_sex WRITE set_t_sex)
	Q_PROPERTY(QString t_name READ get_t_name WRITE set_t_name)
	Q_PROPERTY(int t_age READ get_age WRITE set_age NOTIFY age_c)
public:explicit Tperson(QString sex="boy", QString name = "Ham", quint8 age = 14, QObject* parent = nullptr);
	  ~Tperson() { qDebug() << "already delete!"; }
	  int get_age();
	  void set_age(quint8 age);
	  QString get_t_sex();
	  void set_t_sex(QString sex);
	  QString get_t_name();
	  void set_t_name(QString name);
	  int age_cha();
signals: void age_c(quint8 age);
private: QString t_sex;
	   QString t_name;
	   quint8 t_age;

};