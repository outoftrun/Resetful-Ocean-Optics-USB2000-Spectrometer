#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "dump.h"
#include "util.h"
#include "api/SeaBreezeWrapper.h"


int usb2000() {


    printf("opening %d\n", spec_index);

    puts("dump");
    cJSON *dump = dump_eeproms();
    char *data = cJSON_Print(dump);
    printf("dump %s\n", data);
    free(data);
    dump_fpga_registers();

//    seabreeze_close_spectrometer(spec_index, &error);
//    if (check_error(spec_index, &error, "seabreeze_close_spectrometer(0)"))
//        return 1;

    return 0;
}


