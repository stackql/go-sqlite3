// additional functions to include
#include "json/json_equal.c"
#include "math/math_fns.c"
#include "re/re_fns.c"
#include "unicode/unicode_fns.c"

// Function declarations
SQLITE_PRIVATE int sqlite3TextInit(sqlite3*);
SQLITE_PRIVATE int sqlite3_unicode_init_impl(sqlite3*);
SQLITE_PRIVATE int sqlite3ReInit(sqlite3*);
SQLITE_PRIVATE int sqlite3MathInit(sqlite3*);
