/*
** EPITECH PROJECT, 2023
** get_speed_and_degree
** File description:
** calcul the speed and the degree of rotation for turning
*/

#include "n4s.h"

float get_speed(data_lidar_t lidar)
{
    if (lidar.lidar_front >= 2000 &&
    (lidar.lidar_left > 340 || lidar.lidar_right > 340))
        return 1.0;
    if (lidar.lidar_front >= 1600 &&
    (lidar.lidar_left > 340 || lidar.lidar_right > 340))
        return 0.8;
    if (lidar.lidar_front >= 1000 &&
    (lidar.lidar_left > 340 || lidar.lidar_right > 340))
        return 0.6;
    if (lidar.lidar_front >= 600 &&
    (lidar.lidar_left > 340 || lidar.lidar_right > 340))
        return 0.5;
    if (lidar.lidar_front >= 250 &&
    (lidar.lidar_left > 340 || lidar.lidar_right > 340))
        return 0.3;
    if (lidar.lidar_front >= 200 &&
    (lidar.lidar_left > 340 || lidar.lidar_right > 340))
        return 0.2;
    return 0.1;
}

float get_rotation(data_lidar_t lidar)
{
    if (lidar.lidar_front >= 1500)
        return 0.03;
    if (lidar.lidar_front >= 1000)
        return 0.06;
    if (lidar.lidar_front >= 600)
        return 0.13;
    if (lidar.lidar_front >= 400)
        return 0.20;
    if (lidar.lidar_front >= 200)
        return 0.35;

    return 0.5;
}
