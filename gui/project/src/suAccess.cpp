/***************************************************
 * @file      suAccess.cpp
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     IDE__VSC
 * @version   0.1
 * @date      2024-06-06
 * @copyright Copyright (c) 2024
 ***************************************************/

#include "../inc/suAccess.hpp"

suAccess::suAccess(QWidget* parent)
    : QDialog(parent), ui(new Ui::Form), is_access(false) {
  ui->setupUi(this);

  // Disable the label_2 (Incorrect Password msg)
  ui->label_2->setVisible(false);
}

suAccess::~suAccess() {
  delete ui;
}

/**
 * @brief ### The ok button click event
 * *
 *
 * ! #### For the second input (or more) the `exitCode()` always equal to 0
 */
void suAccess::on_pushButton_clicked() {
  // Temporarily set the QLineEdit echo mode to Normal to show the entered password
  ui->lineEdit->setEchoMode(QLineEdit::Normal);

  // Get the password from the QLineEdit
  QString password = ui->lineEdit->text();

  // Set the command to execute using sudo with the provided password
  QString cmd = "echo " + password + " | sudo -S true";

  // Create a QProcess to execute the command
  QProcess* process = new QProcess(this);
  process->start("bash", QStringList() << "-c" << cmd);

  // Wait for the process to finish
  process->waitForFinished();

  // Check the exit code to determine if the password was correct
  std::cout << process->exitCode() << std::endl;
  if (!process->exitCode()) {
    is_access = true;
    close();  // Close the suAccess window
  }

  // Show the "Incorrect Password" msg
  ui->label_2->setVisible(true);

  // Restore the QLineEdit echo mode to Password to hide the entered password
  ui->lineEdit->setEchoMode(QLineEdit::Password);
}

/**
 * @brief ### Detect the lineEdit selections
 */
void suAccess::on_lineEdit_editingFinished() {
  ui->label_2->setVisible(false);
}
