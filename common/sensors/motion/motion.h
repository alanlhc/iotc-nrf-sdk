/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#ifndef MOTION_H_
#define MOTION_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file motion.h
 * @defgroup motion MOTION Motion sensor interface¨
 * @{
 * @brief Module for interfacing motion sensors for asset tracker
 *
 * @details Basic module for interfacing motion sensors for the
 *          asset tracker application.
 *
 */

#include <zephyr/types.h>

/**@brief Orientation states. */
typedef enum {
	MOTION_ORIENTATION_NOT_KNOWN,   /**< Initial state. */
	MOTION_ORIENTATION_NORMAL,      /**< Has normal orientation. */
	MOTION_ORIENTATION_UPSIDE_DOWN, /**< System is upside down. */
	MOTION_ORIENTATION_ON_SIDE      /**< System is placed on its side. */
} motion_orientation_state_t;

typedef struct {
	double x;			/**< X-axis acceleration [m/s^2]. */
	double y;			/**< y-axis acceleration [m/s^2]. */
	double z;			/**< z-axis acceleration [m/s^2]. */
} motion_acceleration_data_t;

typedef struct {
	motion_orientation_state_t orientation;
	motion_acceleration_data_t acceleration;
	/* TODO add timestamp */
} motion_data_t;

int accelerometer_init(void);

int accelerometer_get_data(motion_data_t *motion_data);

#ifdef __cplusplus
}
#endif

#endif /* MOTION_H_ */
