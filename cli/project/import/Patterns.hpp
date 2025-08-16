/**
 * @file      patterns.hpp
 * @author    ZouariOmar (zouariomar20@gmail.com)
 * @brief     patterns header file
 * @version   0.1
 * @date      2024-10-19
 * @copyright Copyright (c) 2024
 * @link https://github.com/ZouariOmar/crun/project/import/patterns.hpp patterns.hpp @endlink
 */

// Custom include files
#include "Color.h"

//? Menus patterns
#define CRUN_HEADER                                                            \
  system("echo \"\033[0;32m$(figlet -w $(tput cols) '                        " \
         "        Crun - V1.3')\033[0m\"")

#define CRUN_BANNER                                                         \
  std::cout << bleu                                                         \
            << "\t\t\t\t=================== Crun Project "                  \
               "===================\n\t\t\t\t================== By "        \
               "@ZouariOmar ==================\n\t\t\t\t==== Visit Us In: " \
               "https://github.com/ZouariOmar ===="                         \
            << def << "\n\n"

#define PROJECT_MENU                                                                                              \
  std::cout << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
            << red                                                                                                \
            << "\t\tProject Language:\n"                                                                          \
            << yellow                                                                                             \
            << "\t\t\t[1] C\n"                                                                                    \
               "\t\t\t[2] C++\n"                                                                                  \
               "\t\t\t[3] Java\n"                                                                                 \
               "\t\t\t[0] Exit\n"                                                                                 \
            << red                                                                                                \
            << "\t\tVisit https://github.com/ZouariOmar/crun for more info\n"                                     \
            << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
               "..."                                                                                              \
            << def

#define CX_MENU                                                                                                   \
  std::cout << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
            << red                                                                                                \
            << "\t\tC Projects:\n"                                                                                \
            << yellow                                                                                             \
            << "\t\t\t[1] C Code Practice      [2] C Contest         [3] Quick C Project\n"                       \
               "\t\t\t[4] Normal C Project     [5] SDL C Project     [6] Arduino C Project\n"                     \
               "\t\t\t[0] Exit\n"                                                                                 \
            << red                                                                                                \
            << "\t\tVisit https://github.com/ZouariOmar/crun for more info\n"                                     \
            << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
               "..."                                                                                              \
            << def

#define CXX_MENU                                                                                                  \
  std::cout << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
            << red                                                                                                \
            << "\t\tC++ Projects:\n"                                                                              \
            << yellow                                                                                             \
            << "\t\t\t[1] C++ Code Practice    [2] C++ Contest       [3] Quick C++ Project\n"                     \
               "\t\t\t[4] Normal C++ Project   [5] SDL C++ Project   [6] Qt C++ Project\n"                        \
               "\t\t\t[7] Arduino C++ Project\n"                                                                  \
               "\t\t\t[0] Exit\n"                                                                                 \
            << red                                                                                                \
            << "\t\tVisit https://github.com/ZouariOmar/crun for more info\n"                                     \
            << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
               "..."                                                                                              \
            << def

#define JAVA_MENU                                                                                                 \
  std::cout << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
            << red                                                                                                \
            << "\t\tJava Projects:\n"                                                                             \
            << yellow                                                                                             \
            << "\t\t\t[1] Java Code Practice\n"                                                                   \
            << "\t\t\t[2] Java Contest\n"                                                                         \
            << "\t\t\t[3] Java Project (maven)\n"                                                                 \
               "\t\t\t[0] Exit\n"                                                                                 \
            << red                                                                                                \
            << "\t\tVisit https://github.com/ZouariOmar/crun for more info\n"                                     \
            << yellow                                                                                             \
            << "\t\t------------------------------------------------------------------------------------------\n" \
               "..."                                                                                              \
            << def

#define PROJECT_NAME std::cout << yellow << "\n\nProject Name..." << def

//? Messages patterns
#define HELP_MSG                                                                                  \
  std::cout << yellow                                                                             \
            << "Usage:\n"                                                                         \
            << def                                                                                \
            << "  --language <c|cpp|java> Set the language (c = 1, cpp = 2, java = 3)\n"          \
            << "  --project <N>           Set the project ID (N must be a number from 1 to 9+)\n" \
            << "  --name <NAME>           Set the user name (only letters A-Z, a-z)\n"            \
            << "  --help                  Display this help message\n";

#define INVALID_OPTION_MSG std::cout << red << "\n\n[WARR] Invalid Option !\n\n" \
                                     << def
#define EXIT_SUCCESS_MSG                                        \
  std::cout << green << "\n\n[SUCCESS] See You Next Time !\n\n" \
            << def

#define INSTALLATION_COMPLETE_MSG std::cout << green << "Installation Complete!\nHAPPY CODING ⚡️" \
                                            << def

#define Debug(x, y, z) std::cerr << x << " --- " << y << " --- " << z << '\n'

//? Internal Crun patterns
#define CRUN_LANGUAGE_REGEX_PATTERN "--language([1-9]+)"
#define CRUN_PROJECT_REGEX_PATTERN "--project([1-9]+)"
#define CRUN_NAME_REGEX_PATTERN "--name([A-Za-z]+)"
#define CRUN_HELP_REGEX_PATTERN "--help"

//? CMD's patterns
#define _GET(x)                                                              \
  "wget https://github.com/ZouariOmar/cpkg/raw/refs/heads/main/templates/" + \
      x + ".zip";
#define _UNZIP(x) "unzip " + x;
#define _DEL_ZIP(x) "rm " + x + ".zip";
#define _SET_NAME(x, y) \
  "mv " + x + " '" + y + "'";
