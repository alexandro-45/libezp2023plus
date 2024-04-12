#ifndef LIBEZP2023PLUS_EZP_PROG_H
#define LIBEZP2023PLUS_EZP_PROG_H

#include "ezp_chips_data_file.h"
#include <libusb-1.0/libusb.h>

typedef struct {
    libusb_device_handle *handle;
} ezp_programmer;

typedef enum {
    SPEED_12MHZ = 0,
    SPEED_6MHZ = 1,
    SPEED_3MHZ = 2,
    SPEED_1_5MHZ = 3,
    SPEED_750KHZ = 4,
    SPEED_375KHZ = 5,
} ezp_speed;

typedef enum {
    EZP_READY,
    EZP_CONNECTED,
    EZP_DISCONNECTED
} ezp_status;

typedef void (*ezp_callback)(uint32_t current, uint32_t max);
typedef void (*ezp_status_callback)(ezp_status status);

int ezp_init();

ezp_programmer *ezp_find_programmer();

int ezp_read_flash(ezp_programmer *programmer, uint8_t **data, ezp_chip_data *chip_data, ezp_speed speed, ezp_callback callback);

int ezp_write_flash(ezp_programmer *programmer, const uint8_t *data, ezp_chip_data *chip_data, ezp_speed speed, ezp_callback callback);

int ezp_test_flash(ezp_programmer *programmer, ezp_flash *type, uint32_t *chip_id);

int ezp_listen_programmer_status(ezp_status_callback callback);

void ezp_free_programmer(ezp_programmer *programmer);

void ezp_free();

#endif //LIBEZP2023PLUS_EZP_PROG_H
