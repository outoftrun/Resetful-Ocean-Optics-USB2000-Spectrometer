#include <stdio.h>


#include "src/handler.h"
#include "src/usb2000/usb2000.h"
#include "api/SeaBreezeWrapper.h"
#include "src/usb2000/util.h"
#include "cjson/cJSON.h"
#include "src/usb2000/seabreeze-util.h"

#define PORT 3000


int fn1() {
    printf("next.\n");
    return 0;
}


int main() {
    printf("Starting server on port %d nje\n", PORT);


    open_seabreeze();


    //   atexit( fn1 );

    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, PORT, NULL, NULL,
                              &default_handler, NULL, MHD_OPTION_END);
    if (!daemon)
        return 1;

    while (1)
        sleep(1);

    MHD_stop_daemon(daemon);

    return 0;
}
