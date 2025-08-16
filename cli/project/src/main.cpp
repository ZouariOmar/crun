/**
 * @file      main.cpp
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     Main source file
 * @version   0.1
 * @date      2025-04-28
 * @copyright Copyright (c) 2025
 * @link https://github.com/ZouariOmar/Crun/project/src/main.cpp main.cpp @endlink
 */

//? Include prototype declaration part
#include "../include/Crun.hpp"

//? Main function prototype dev part

/**
 * @fn         main(int, const char **)
 * @brief      The main Crun function
 * @param argc int
 * @param argv {const char **}
 * @return     int
 */
int main(int argc, const char **argv) {
  Crun crun(argc, argv);
  if (!crun.generate())
    crun.notify();
  return EXIT_SUCCESS;
}
