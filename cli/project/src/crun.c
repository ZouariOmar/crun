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
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#else
#include <unistd.h>
#endif

//* Include custom header(s)
#include "../common/patterns.h"
#include "../inc/crun.h"

//? Functions prototype dev part

void __init__() {
  CRUN_HEADER;
  CRUN_BANNER;
  const char *crun_stacks_json_file_path = get_crun_stacks_json_path();
  // char buff[100];
  // PROJECT_MENU_FIELD(buff, 1, "java");
  // PROJECT_MENU(buff);

  if (is_file_exist(crun_stacks_json_file_path)) { // Download `crun_stacks_json`
    printf("[WARR] %s not exist!\n", crun_stacks_json_file_path);
    printf("[INFO] Downloading crun_stacks.json...\n");

    if (!download_file(CRUN_STACKS_JSON_URL, crun_stacks_json_file_path))
      fprintf(stdout, "[INFO] crun_stacks.json Downloaded successfully!\n");
    else
      fprintf(stderr, "[ERROR] crun_stacks.json Download failed!\n");
  }

  free((void *)crun_stacks_json_file_path);
}

int is_file_exist(const char *file_path) {
  return access(file_path, F_OK);
}

int generate() {
  return EXIT_SUCCESS;
}

void notify() {
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
  return fwrite(ptr, size, nmemb, (FILE *)stream);
}

int download_file(const char *url, const char *out) {
  CURL *curl = curl_easy_init();
  if (!curl)
    return EXIT_FAILURE; // Init failed

  FILE *fp = fopen(out, "wb");
  if (!fp) {
    fprintf(stdout, "[WARR] Can't open/write %s\n", out);
    curl_easy_cleanup(curl);
    return EXIT_FAILURE; // File open failed
  }
  CURLcode res;
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

  res = curl_easy_perform(curl);

  fclose(fp);
  curl_easy_cleanup(curl);

  return res != CURLE_OK;
}

char *get_crun_stacks_json_path() {
  const char *home = OS_HOME;
  if (!OS_HOME)
    return NULL;

#ifdef _WIN32
  const char *suffix = "\\crun\\crun_stacks.json";
#else
  const char *suffix = "/.local/share/crun/crun_stacks.json";
#endif

  size_t len = strlen(home) + strlen(suffix) + 1;
  char *path = (char *)malloc(len);
  if (!path)
    return NULL;

  snprintf(path, len, "%s%s", home, suffix);
  return path;
}
