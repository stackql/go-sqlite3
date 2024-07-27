#ifndef INCLUDED_FUNCTIONS_H
#define INCLUDED_FUNCTIONS_H

// Include necessary headers for type definitions
#include <stdint.h>
#include <sqlite3ext.h>

// Define SQLITE_PRIVATE if not already defined
#ifndef SQLITE_PRIVATE
#define SQLITE_PRIVATE static
#endif

// Define types if not already defined
#ifndef u16
#define u16 uint16_t
#endif

#ifndef u8
#define u8 uint8_t
#endif

#ifndef i64
#define i64 int64_t
#endif

// Function declarations
SQLITE_PRIVATE int sqlite3TextInit(sqlite3*);
SQLITE_PRIVATE int sqlite3_unicode_init_impl(sqlite3*);
SQLITE_PRIVATE int sqlite3ReInit(sqlite3*);
SQLITE_PRIVATE int sqlite3MathInit(sqlite3*);

#endif // INCLUDED_FUNCTIONS_H
