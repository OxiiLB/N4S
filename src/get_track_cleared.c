/*
** EPITECH PROJECT, 2023
** get_track_cleared
** File description:
** get the track cleared
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "n4s.h"
#include "structures.h"

static void slow_then_stop(FILE *file, data_lidar_t lidar)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char *buf = NULL;
    size_t len = 0;
    for (int i = 0; lidar.lidar[i] != NULL; i++) {
        free(lidar.lidar[i]);
    }
    free(lidar.lidar);
    printf("CAR_FORWARD:0\n");
    getline(&buf, &len, file);
    printf("CYCLE_WAIT:15\n");
    getline(&buf, &len, file);
    printf("STOP_SIMULATION\n");
    getline(&buf, &len, file);
}

bool get_track_cleared(char *buffer, FILE *file, data_lidar_t lidar)
{
    char **data = my_strtok(buffer, ":");
    for (int i = 0; data[i] != NULL; i++) {
        if (strcmp(data[i], "Track Cleared") == 0) {
            slow_then_stop(file, lidar);
            return true;
        }
    }
    for (int i = 0; data[i] != NULL; i++) {
        free(data[i]);
    }
    free(data);
    return false;
}
