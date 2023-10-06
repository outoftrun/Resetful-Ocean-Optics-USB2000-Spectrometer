//
// Created by nicked on 9/24/23.
//

#ifndef RESTFULLSPECTRUM_SEABREEZE_UTIL_H
#define RESTFULLSPECTRUM_SEABREEZE_UTIL_H

cJSON *getModel(int i);

cJSON *getPixelsFormated(int i);

cJSON *getSerialNumber(int index);

cJSON *getDataFormated(int index);

cJSON *getWavelenght(int index);

void open_seabreeze();

int do_items(void *cls, enum MHD_ValueKind kind, const char *key, const char *value);
#endif //RESTFULLSPECTRUM_SEABREEZE_UTIL_H
