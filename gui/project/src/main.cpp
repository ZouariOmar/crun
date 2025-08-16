/***************************************************
 * @file      main.cpp
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     IDE__VSC
 * @version   0.1
 * @date      2024-06-06
 * @copyright Copyright (c) 2024
 ***************************************************/

//? ------------------------------ INCLUDE PROTOTYPE DECLARATION PART ------------------------------
#include "../inc/mainwindow.hpp"
#include <qt6/QtWidgets/QApplication>

//? --------------------------------- MAIN() INT FUNCTION DEV PART ---------------------------------

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w(nullptr);
  w.show();
  return a.exec();
}
