/**
 * @file      crun.h
 * @author    @ZouariOmar (zouariomar20@gmail.com)
 * @brief     crun header file
 * @version   0.1
 * @date      2025-04-28
 * @copyright Copyright (c) 2025
 * @link https://github.com/ZouariOmar crun.h @endlink
 */

#ifndef __CRUN_H__
#define __CRUN_H__

//? Include prototype declaration part
//* Include stander C header(s)
#include <stdlib.h>

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

// ============================================
// === Functions prototype declaration part ===
// ============================================
void __init__();
int is_file_exist(const char *);
char *get_crun_stacks_json_path();
int generate();
void notify();

// Libcurl function(s)
size_t write_data(void *, size_t, size_t, void *);
int download_file(const char *, const char *);

#endif // __CRUN_H__
