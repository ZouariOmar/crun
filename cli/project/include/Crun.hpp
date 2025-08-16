/**
 * @file      Crun.hpp
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     Crun header file
 * @version   0.1
 * @date      2025-04-28
 * @copyright Copyright (c) 2025
 * @link https://github.com/ZouariOmar Crun.hpp @endlink
 */

#ifndef __CRUN_HPP__
#define __CRUN_HPP__

//? Include prototype declaration part
//* Include stander C header(s)
#include <unistd.h>

//* Include stander C++ header(s)
#include <string>

/**
 * @enum  CrunProjectsFlags
 * @brief CrunProjectsFlags enum
 */
enum CrunProjectFlags {
  NORMAL_MODE,
  CX_FILE_MODE,
  CXX_FILE_MODE,
  JAVA_FILE_MODE
}; // CrunProjectsFlags enum

//? Class prototype declaration part

/**
 * @class Crun
 * @brief Crun class
 */
class Crun {
private:
  short usr_project, usr_language; // Usr choices
  std::string usrProjectName,      // The usr project title
      cpkgFileDir;                 // Directory after templates/*
  bool is_installed;               // Flag to detect if the project installed or not
  bool is_flag(std::string);
  void projects();
  void cx_projects();
  void cxx_projects();
  void java_projects();
  void setupProject(std::string filename, const CrunProjectFlags flag = NORMAL_MODE);
  void get_projectName();

public:
  Crun(const int, const char **);
  int generate();
  void notify();
}; // Crun class

#endif // __CRUN_HPP__
