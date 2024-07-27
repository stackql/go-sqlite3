#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT1

#include <cjson/cJSON.h>
#include <string.h>

// Helper function to compare JSON strings
static void json_equal(sqlite3_context *context, int argc, sqlite3_value **argv) {
    if (argc != 2) {
        sqlite3_result_error(context, "json_equal() requires exactly two arguments", -1);
        return;
    }

    const char *json1 = (const char *)sqlite3_value_text(argv[0]);
    const char *json2 = (const char *)sqlite3_value_text(argv[1]);

    if (json1 == NULL || json2 == NULL) {
        sqlite3_result_error(context, "Invalid JSON strings", -1);
        return;
    }

    cJSON *json_obj1 = cJSON_Parse(json1);
    cJSON *json_obj2 = cJSON_Parse(json2);

    if (json_obj1 == NULL || json_obj2 == NULL) {
        sqlite3_result_error(context, "Error parsing JSON strings", -1);
        cJSON_Delete(json_obj1);
        cJSON_Delete(json_obj2);
        return;
    }

    cJSON_bool result = cJSON_Compare(json_obj1, json_obj2, cJSON_True);

    cJSON_Delete(json_obj1);
    cJSON_Delete(json_obj2);

    sqlite3_result_int(context, result);
}

// SQLite extension entry point
int sqlite3_jsonequal_init(sqlite3 *db, char **pzErrMsg, const sqlite3_api_routines *pApi) {
    SQLITE_EXTENSION_INIT2(pApi)
    sqlite3_create_function(db, "json_equal", 2, SQLITE_UTF8, NULL, json_equal, NULL, NULL);
    return SQLITE_OK;
}
