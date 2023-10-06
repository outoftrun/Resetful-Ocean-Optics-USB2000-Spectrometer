#include <string.h>
#include <stdio.h>

#include <microhttpd.h>
#include "cjson/cJSON.h"
#include "utils.h"
#include "usb2000/seabreeze-util.h"

char *executeQueryToJson(const char *query);

//HTTP_response oceanOptics_get_all(const char *url) {
//    const char *query = "SELECT * FROM users";
//
//    char *result = executeQueryToJson(query);
//
//    return validate_result(result);
//}

char *urlencode(char *originalText) {
    // allocate memory for the worst possible case (all characters need to be encoded)
    char *encodedText = (char *) malloc(sizeof(char) * strlen(originalText) * 3 + 1);

    const char *hex = "0123456789abcdef";

    int pos = 0;
    for (int i = 0; i < strlen(originalText); i++) {
        if (('a' <= originalText[i] && originalText[i] <= 'z') || ('A' <= originalText[i] && originalText[i] <= 'Z') ||
            ('0' <= originalText[i] && originalText[i] <= '9')) {
            encodedText[pos++] = originalText[i];
        } else {
            encodedText[pos++] = '%';
            encodedText[pos++] = hex[originalText[i] >> 4];
            encodedText[pos++] = hex[originalText[i] & 15];
        }
    }
    encodedText[pos] = '\0';
    return encodedText;
}

HTTP_response seaBreeze(const char *user_id) {

    cJSON *res;
    static char *text = 0;
//    if (strcmp(user_id, "data") == 0) {
//        res = getDataFormated(0);
//    } else if (strcmp(user_id, "model") == 0) {
//        res = getModel(0);
//    }
    if (text != 0)
        free(text);
    text = cJSON_Print(res);
    cJSON_Delete(res);
    return validate_result(text);


}

//HTTP_response oceanOptics_create(const char *body) {
//    if (body == NULL) {
//        return (HTTP_response) {.body = simple_message("No body provided"), .status = BAD_REQUEST};
//    }
//
//    char query[256];
//    snprintf(query, sizeof(query), "INSERT INTO users (name, email) VALUES ('%s', '%s')", "name", "email");
//
//    char *result = executeQueryToJson(query);
//
//    return validate_result(result);
//}
//
//HTTP_response oceanOptics_update(const char *user_id, const char *body) {
//    if (user_id == NULL) {
//        return (HTTP_response) {.body = simple_message("No user id provided"), .status = BAD_REQUEST};
//    }
//
//    if (body == NULL) {
//        return (HTTP_response) {.body = simple_message("No body provided"), .status = BAD_REQUEST};
//    }
//
//    char query[256];
//    snprintf(query, sizeof(query), "UPDATE users SET name = '%s', email = '%s' WHERE id = %s", "name", "email",
//             user_id);
//
//    char *result = executeQueryToJson(query);
//
//    return validate_result(result);
//}
//
//HTTP_response oceanOptics_drop(const char *user_id) {
//    char query[64];
//    snprintf(query, sizeof(query), "DELETE FROM users WHERE id = %s", user_id);
//
//    char *result = executeQueryToJson(query);
//
//    return validate_result(result);
//}


HTTP_response ocean_router(struct MHD_Connection *connection, const char *url, const char *method, const char *body) {
    const char *users = "/ocean/";

//    char *user_id = strstr(url, users);
//    if (user_id != NULL) {
//        user_id += strlen(users);
//    }

    if (validate_method(method, "GET")) {
//        gArgs.debug = 0;
//        gArgs.getSpectrum = 0;
//        gArgs.raw = 0;
//        gArgs.integrationTimeUS = 100000; // default to 100ms
//        gArgs.list = 0;
//        gArgs.listDescriptors = 0;
//        gArgs.listEEPROMs = 0;
//        gArgs.listEDCPixels = 0;
//        gArgs.listIrrad = 0;
//        gArgs.index = -1;
//        gArgs.eepromIndex = 0;
//        gArgs.eepromValueHex = NULL;
//        gArgs.eepromValueAscii = NULL;
//        gArgs.irradFilename = NULL;
//        gArgs.serialNumber = NULL;
//        gArgs.type = NULL;

        cJSON *result = cJSON_CreateObject();


        MHD_get_connection_values(connection, MHD_GET_ARGUMENT_KIND, (MHD_KeyValueIterator) do_items, result);


//        char *data = MHD_lookup_connection_value(connection, MHD_GET_ARGUMENT_KIND, "data");
        static char *text = 0;
        if (text != 0)
            free(text);

//        if(data) {
//           puts(data);
//
//
//           cJSON *res;
//           if (strcmp(data, "model") == 0) {
//               res = getModel(0);
//           }



          // cJSON_AddItemToObject(result, "result", res);

        text = cJSON_Print(result);

        cJSON_Delete(result);

        return validate_result(text);

    }

//    if (validate_method(method, "POST")) {
//        return oceanOptics_create(body);
//    }

//    if (validate_method(method, "PUT")) {
//        return oceanOptics_update(user_id, body);
//    }
//
//    if (validate_method(method, "DELETE")) {
//        return oceanOptics_drop(user_id);
//    }

    return (HTTP_response) {.body = simple_message("Not implemented"), .status = NOT_IMPLEMENTED};
}