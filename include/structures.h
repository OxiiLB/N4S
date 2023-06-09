/*
** EPITECH PROJECT, 2023
** structures.h
** File description:
** all the structures of the project
*/

#ifndef STRUCT_S
    #define STRUCT_S

    #include <stdbool.h>

    typedef struct data_lidar_s {
        float lidar_left;
        float lidar_right;
        float lidar_front;
        bool track_cleared;
        char **lidar;
    }data_lidar_t;

#endif /* !STRUCT_S */
