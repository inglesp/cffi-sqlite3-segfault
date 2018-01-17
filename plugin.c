#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1

static void rot13(sqlite3_context *context, int argc, sqlite3_value **argv);

int sqlite3_testplugin_init(sqlite3 *db, char **pzErrMsg,
                     const sqlite3_api_routines *pApi) {
  int rc = SQLITE_OK;
  SQLITE_EXTENSION_INIT2(pApi);
  printf("Hello from C!\n");
  printf("pApi %p\n", pApi);
  printf("pApi->value_type %p\n", pApi->value_type);
  rc = sqlite3_create_function(db, "rot13", 1, SQLITE_UTF8, 0, rot13, 0, 0);
  return rc;
}
