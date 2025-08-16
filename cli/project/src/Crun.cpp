/**
 * @file      Crun.cpp
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     Crun source file
 * @version   0.1
 * @date      2025-01-10
 * @copyright Copyright (c) 2025
 * @link https://github.com/ZouariOmar/crun/project/src/Crun.cpp Crun.cpp @endlink
 */

//? Include prototype declaration part
//* Include stander C++ header(s)
#include <iostream>
#include <regex>

//* Include custom header(s)
#include "../import/Patterns.hpp"
#include "../include/Crun.hpp"

//? Functions prototype dev part

/**
 * @fn         Crun::Crun(const int, const char **)
 * @brief      Construct a new
 * Crun::Crun object
 * @param argc {const int}
 * @param argv {const char **}
 */
Crun::Crun(const int argc, const char **argv)
    : usr_project(-1),
      usr_language(-1),
      usrProjectName(""),
      cpkgFileDir("/"),
      is_installed(false) {
  if (!((argc == 1) ||
        (argc == 2 && is_flag(std::string(argv[1]))) ||
        (argc == 3 && is_flag(std::string{argv[1]} + std::string{argv[2]})) ||
        (argc == 5 && is_flag(std::string{argv[1]} + std::string{argv[2]}) && is_flag(std::string{argv[3]} + std::string{argv[4]})) ||
        (argc == 7 && is_flag(std::string{argv[1]} + std::string{argv[2]}) && is_flag(std::string{argv[3]} + std::string{argv[4]}) && is_flag(std::string{argv[5]} + std::string{argv[6]})))) {
    INVALID_OPTION_MSG;
    return;
  }
  system("clear"); // Clear the cli
  CRUN_HEADER;     // Show Crun Top header
  CRUN_BANNER;     // Show Crun header menu
}

/**
 * @fn        Crun::is_flag(std::string)
 * @brief     Return `ture` if there is flag match, otherwise return `false`
 * @param str string
 * @return    bool
 */
bool Crun::is_flag(std::string str) {
  if (str == CRUN_HELP_REGEX_PATTERN) {
    HELP_MSG;
    exit(EXIT_SUCCESS);
  }

  std::regex r(CRUN_LANGUAGE_REGEX_PATTERN);
  std::smatch match;
  if (std::regex_search(str, match, r)) {
    usr_language = std::stoi(match[1]);
    return true;
  }

  r = std::regex(CRUN_PROJECT_REGEX_PATTERN);
  if (std::regex_search(str, match, r)) {
    usr_project = std::stoi(match[1]);
    return true;
  }

  r = std::regex(CRUN_NAME_REGEX_PATTERN);
  if (std::regex_search(str, match, r)) {
    usrProjectName = match[1];
    return true;
  }
  return false;
}

/**
 * @fn     Crun::generate()
 * @brief  The main Crun function
 * @return int
 */
int Crun::generate() {
  while (!is_installed) {
    if (usr_language == -1) {
      PROJECT_MENU;             // Show the Crun menu
      std::cin >> usr_language; // Take the usr input
    }
    projects();
  }
  return EXIT_SUCCESS;
}

/**
 * @fn     Crun::projects()
 * @brief  Match `usr_language` with the availble crun spported languages
 * @return void
 */
void Crun::projects() {
  switch (usr_language) {
  case 1:
    cpkgFileDir = "c/";
    cx_projects();
    break;

  case 2:
    cpkgFileDir = "cpp/";
    cxx_projects();
    break;

  case 3:
    cpkgFileDir = "java/";
    java_projects();
    break;

  case 0:
    EXIT_SUCCESS_MSG;
    exit(EXIT_SUCCESS); //* Exit the program
    break;

  default:
    INVALID_OPTION_MSG;
    usr_language = -1; // Ask the usr again (reset proccess)
    break;
  }
}

/**
 * @fn     Crun::cx_projects()
 * @brief  Match `usr_project` with the availble crun cx spported projects
 * @return void
 */
void Crun::cx_projects() {
  while (!is_installed) {
    if (usr_project == -1) {
      CX_MENU;
      std::cin >> usr_project;
    }

    switch (usr_project) {
    case 1:
      setupProject("CXCodePracticeEnv", CX_FILE_MODE);
      break;

    case 2:
      setupProject("CXContestEnv");
      break;

    case 3:
      setupProject("QuickCXProjectEnv");
      break;

    case 4:
      setupProject("NormalCXProjectEnv");
      break;

    case 5:
      setupProject("SDLCXProjectEnv");
      break;

    case 6:
      setupProject("ArduinoCXProjectEnv");
      break;

    case 0:
      EXIT_SUCCESS_MSG;
      exit(EXIT_SUCCESS); //* Exit the program
      break;

    //* Invalid option
    default:
      INVALID_OPTION_MSG;
      usr_project = -1; // Ask the usr again (reset proccess)
      break;
    }
  }
}

/**
 * @fn     Crun::cxx_projects()
 * @brief  Match `usr_project` with the availble crun cxx spported projects
 * @return void
 */
void Crun::cxx_projects() {
  while (!is_installed) {
    if (usr_project == -1) {
      CXX_MENU;
      std::cin >> usr_project;
    }

    switch (usr_project) {
    case 1:
      setupProject("CXXCodePracticeEnv", CXX_FILE_MODE);
      break;

    case 2:
      setupProject("CXXContestEnv");
      break;

    case 3:
      setupProject("QuickCXXProjectEnv");
      break;

    case 4:
      setupProject("NormalCXXProjectEnv");
      break;

    case 5:
      setupProject("SDLCXXProjectEnv");
      break;

    case 6:
      setupProject("QtCXXProjectEnv");
      break;

    case 7:
      setupProject("ArduinoCXXProjectEnv");
      break;

    case 0:
      EXIT_SUCCESS_MSG;
      exit(EXIT_SUCCESS); //* Exit the program
      break;

    //* Invalid option
    default:
      INVALID_OPTION_MSG;
      usr_project = -1; // Ask the usr again (reset proccess)
      break;
    }
  }
}

/**
 * @fn     Crun::java_projects()
 * @brief  Match `usr_project` with the availble crun java spported projects
 * @return void
 */
void Crun::java_projects() {
  while (!is_installed) {
    if (usr_project == -1) {
      JAVA_MENU;
      std::cin >> usr_project;
    }

    switch (usr_project) {
    case 1:
      setupProject("JavaCodePracticeEnv", JAVA_FILE_MODE);
      break;

    case 2:
      setupProject("JavaContestEnv");
      break;

    case 3:
      setupProject("JavaProjectEnv");
      break;

    case 0:
      EXIT_SUCCESS_MSG;
      exit(EXIT_SUCCESS); //* Exit the program
      break;

    //* Invalid option
    default:
      INVALID_OPTION_MSG;
      usr_project = -1; // Ask the usr again (reset proccess)
      break;
    }
  }
}

/**
 * @fn    Crun::setupProject(std::string, const CrunProjectsFlags)
 * @brief Setup the selected usr project
 *
 * @details Actions:
 *            Clone(git) - Clone the pkg
 *            Delete(rm) - Delete the unnecessary .zip file
 *            Rename(mv) - Change the default project name to `usrProjectName`
 *
 * @param old_prj_name std::string
 * @param flag         {const CrunProjectsFlags}
 * @return             void
 */
void Crun::setupProject(std::string filename, const CrunProjectFlags flag) {
  //* Get the project name if `usrProjectName` is empty
  if (usrProjectName.empty())
    get_projectName();

  std::string cmd = _GET(cpkgFileDir + filename);
  system(cmd.c_str());

  cmd = _UNZIP(filename);
  system(cmd.c_str());

  cmd = _DEL_ZIP(filename);
  system(cmd.c_str());

  is_installed = true; // Done :)

  if (flag == CX_FILE_MODE) {
    usrProjectName = usrProjectName + ".c";
    (std::rename((filename + ".c").c_str(), usrProjectName.c_str()) != 0) ? std::cerr << "[ERROR] Renaming file error\n" : std::cout << "[INFO] File renamed successfully\n";
    return;
  }

  if (flag == CXX_FILE_MODE) {
    usrProjectName = usrProjectName + ".cpp";
    (std::rename((filename + ".cpp").c_str(), usrProjectName.c_str()) != 0) ? std::cerr << "[ERROR] Error renaming file\n" : std::cout << "[INFO] File renamed successfully\n";
    return;
  }

  if (flag == JAVA_FILE_MODE) {
    usrProjectName = usrProjectName + ".java";
    (std::rename((filename + ".java").c_str(), usrProjectName.c_str()) != 0) ? std::cerr << "[ERROR] Error renaming file\n" : std::cout << "[INFO] File renamed successfully\n";
    return;
  }

  cmd = _SET_NAME(filename, usrProjectName);
  system(cmd.c_str());
}

/**
 * @fn     Crun::get_projectName()
 * @brief  Get the usr project name
 * @return void
 */
void Crun::get_projectName() {
  PROJECT_NAME;
  std::cin.ignore();
  getline(std::cin, usrProjectName);
}

/**
 * @fn     Crun::notify()
 * @brief  Installation complete successfully notification
 * @return void
 */
void Crun::notify() {
  //* Notify the user
  printf("%sInstallation Complete!%s\n", green, def);

  //* Open the project with NVIM/VIM
  system(("nvim '" + usrProjectName + "' || vim '" + usrProjectName + "'").c_str());
}
