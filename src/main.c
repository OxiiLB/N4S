/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "n4s.h"
#include "structures.h"

static data_lidar_t set_lidar_struct(data_lidar_t data, char **lidar)
{
    data.track_cleared = false;
    data.lidar_right = atof((const char *)lidar[34]);
    data.lidar_left = atof((const char *)lidar[3]);
    data.lidar_front = atof((const char *)lidar[19]);
    data.lidar = lidar;
    return data;
}

static data_lidar_t lidar_info_right_left_side(FILE *file)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    data_lidar_t data;
    char *buf = NULL;
    size_t len = 0;
    char **lidar = NULL;
    printf("GET_INFO_LIDAR\n");
    getline(&buf, &len, file);
    lidar = my_str_to_word_array_minishell(buf, ':');
    data = set_lidar_struct(data, lidar);
    return data;
}

static void loop(char *buf, size_t len, FILE *file,
data_lidar_t lidar)
{

    while (lidar.track_cleared == false) {
        lidar = lidar_info_right_left_side(file);
        if (print_car_instructions_left(buf, len, file, lidar) == true)
            break;
    }
    for (int i = 0; lidar.lidar[i] != NULL; i++) {
        free(lidar.lidar[i]);
    }
    free(lidar.lidar);
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    FILE *file = fopen(".fifo_n4s", "r");
    char *buf = NULL;
    size_t len = 0;
    data_lidar_t lidar;

    printf("START_SIMULATION\n");
    getline(&buf, &len, file);
    if (get_track_cleared(buf, file, lidar) == true)
        return 0;
    printf("CAR_FORWARD:0.3\n");
    getline(&buf, &len, file);
    if (get_track_cleared(buf, file, lidar) == true)
        return 0;
    loop(buf, len, file, lidar);
    fclose(file);
    return 0;
}
