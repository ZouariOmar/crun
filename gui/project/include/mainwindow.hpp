/***************************************************
 * @file      mainwindow.hpp
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     IDE__VSC
 * @version   0.1
 * @date      2024-06-06
 * @copyright Copyright (c) 2024
 ***************************************************/

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

//? ----------------------------- INCLUDE PROTOTYPE DECLARATION PART -----------------------------

#include <filesystem>

// * Include std Qt6 libs
#include <qt6/QtCore/QDebug>
#include <qt6/QtCore/QProcess>
#include <qt6/QtCore/QTimer>
#include <qt6/QtGui/QPixmap>
#include <qt6/QtWidgets/QMainWindow>
#include <qt6/QtWidgets/QMessageBox>

//! Testing part
#include <iostream>

#include "../res/ui_mainWindow.h"

//? ------------------------------ STRUCT PROTOTYPE DECLARATION PART ------------------------------
struct CrunStrut {   //? Crun Structure
  QString pTitle,    // Project title
      pEnv,          // Project enviornment
      bSys;          // Build system
  std::string cPath; // Current usr path
  int pId,           // Project ID (QComboBox index holder)
      bId;           // Build system ID (QComboBox index holder)
};

//? ----------------------------- FUNCTIONS PROTOTYPE DECLARATION PART -----------------------------
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class CrunGUI {
protected:
  // Protected vars declaration part
  CrunStrut c;

  // Protected Custom methods declaration part
  inline bool with_buildSys();
  void setup_prj();
  std::string getOldPrjName();
  void clone_prj(std::string);

}; // CrunGUI class

class MainWindow : public QMainWindow, public CrunGUI {
  Q_OBJECT

private:
  Ui::MainWindow *ui;
  void notify(MainWindow *);

private slots:
  void on_pushButton_clicked();
  void on_comboBox_currentIndexChanged(int);

public:
  MainWindow(QWidget *);
  ~MainWindow();
};
#endif // __MAINWINDOW_HPP__
