//
// Created by nicked on 9/23/23.
//

#ifndef RESTFULLSPECTRUM_DUMP_H
#define RESTFULLSPECTRUM_DUMP_H

cJSON *dump_eeproms();

void dump_fpga_registers();

extern int error;
extern const int spec_index;
#endif //RESTFULLSPECTRUM_DUMP_H
