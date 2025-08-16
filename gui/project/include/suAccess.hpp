/**
 * @file suAccess.hpp
 * @author @ZouariOmar (zouariomar20@gmail.com)
 * @brief # Sudo access header file
 * @version 0.1
 * @date 2025-01-10
 * @copyright Copyright (c) 2025
 * @link https://github.com/ZouariOmar/Crun/blob/main/GUI/project/inc/suAccess.hpp suAccess.hpp @endlink
 */

#ifndef __SUACCESS_HPP__
#define __SUACCESS_HPP__

// * Include std Qt6 libs
#include <iostream>
#include <qt6/QtCore/QProcess>
#include <qt6/QtWidgets/QDialog>

#include "../res/ui_suAccess.h"

namespace Ui {
class suAccess;
}

class suAccess : public QDialog {
  Q_OBJECT

public slots:
  void on_pushButton_clicked();
  void on_lineEdit_editingFinished();

private slots:

private:
  Ui::Form *ui;

public:
  bool is_access;
  suAccess(QWidget *);
  ~suAccess();
};

#endif // SuAccess_H
