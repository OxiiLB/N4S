/*
** EPITECH PROJECT, 2023
** print_car_instructions
** File description:
** print in the good fd the instructions for the car
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "n4s.h"
#include "structures.h"

static bool print_car_instructions_right(char *buf, size_t len, FILE *file,
data_lidar_t lidar)
{
    if (lidar.lidar_left < lidar.lidar_right) {
        printf("CAR_FORWARD:%f\n", get_speed(lidar));
        getline(&buf, &len, file);
        if (get_track_cleared(buf, file, lidar) == true)
            return true;
        printf("WHEELS_DIR:-%f\n", get_rotation(lidar));
        getline(&buf, &len, file);
        if (get_track_cleared(buf, file, lidar) == true)
            return true;
    }
    return false;
}

bool print_car_instructions_left(char *buf, size_t len, FILE *file,
data_lidar_t lidar)
{
    if (lidar.lidar_left > lidar.lidar_right) {
        printf("CAR_FORWARD:%f\n", get_speed(lidar));
        getline(&buf, &len, file);
        if (get_track_cleared(buf, file, lidar) == true)
            return true;
        printf("WHEELS_DIR:%f\n", get_rotation(lidar));
        getline(&buf, &len, file);
        if (get_track_cleared(buf, file, lidar) == true)
            return true;
    }
    return print_car_instructions_right(buf, len, file, lidar);
}
