/**
  ******************************************************************************
  * @file    x_nucleo_iks01a1.h
  * @author  MEMS Application Team
  * @version V4.2.0
  * @date    01-February-2018
  * @brief   This file contains definitions for the x_nucleo_iks01a1.c
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2018 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __X_NUCLEO_IKS01A1_H
#define __X_NUCLEO_IKS01A1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "platform.h"

/* Includes ------------------------------------------------------------------*/

#ifdef USE_STM32F4XX_NUCLEO
#include "stm32f4xx_hal.h"
#endif

#ifdef USE_STM32L0XX_NUCLEO
#include "stm32l0xx_hal.h"
#endif

#ifdef USE_STM32L1XX_NUCLEO
#include "stm32l1xx_hal.h"
#endif

#ifdef USE_STM32L4XX_NUCLEO
#include "stm32l4xx_hal.h"
#endif

#ifdef USE_STM32WLXX_NUCLEO
#include "stm32wlxx_hal.h"
#endif

#include "accelerometer.h"
#include "gyroscope.h"
#include "magnetometer.h"
#include "humidity.h"
#include "temperature.h"
#include "pressure.h"

/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup X_NUCLEO_IKS01A1 X_NUCLEO_IKS01A1
 * @{
 */

/** @addtogroup X_NUCLEO_IKS01A1_IO IO
 * @{
 */

/** @addtogroup X_NUCLEO_IKS01A1_IO_Public_Constants Public constants
 * @{
 */

#define IKS01A1_HTS221_WHO_AM_I        (uint8_t)0xBC
#define IKS01A1_LPS25HB_WHO_AM_I       (uint8_t)0xBD
#define IKS01A1_LPS22HB_WHO_AM_I       (uint8_t)0xB1
#define IKS01A1_LSM6DS0_WHO_AM_I       (uint8_t)0x68
#define IKS01A1_LSM6DS3_WHO_AM_I       (uint8_t)0x69
#define IKS01A1_LIS3MDL_WHO_AM_I       (uint8_t)0x3D
#define IKS01A1_LSM6DSL_WHO_AM_I       (uint8_t)0x6A
#define IKS01A1_LSM303AGR_ACC_WHO_AM_I (uint8_t)0x33 /* Same value as IKS01A1_LIS2DH12_WHO_AM_I */
#define IKS01A1_LSM303AGR_MAG_WHO_AM_I (uint8_t)0x40 /* Same value as IKS01A1_LIS2MDL_WHO_AM_I */
#define IKS01A1_H3LIS331DL_WHO_AM_I    (uint8_t)0x32
#define IKS01A1_LIS2DH12_WHO_AM_I      (uint8_t)0x33 /* Same value as IKS01A1_LSM303AGR_ACC_WHO_AM_I */
#define IKS01A1_LIS2MDL_WHO_AM_I       (uint8_t)0x40 /* Same value as IKS01A1_LSM303AGR_MAG_WHO_AM_I */
#define IKS01A1_LIS2DW12_WHO_AM_I      (uint8_t)0x44

/* I2C clock speed configuration (in Hz) */
#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)))
#define NUCLEO_I2C_EXPBD_SPEED                         400000
#endif /* USE_STM32F4XX_NUCLEO or USE_STM32L1XX_NUCLEO */

/* Timing samples for L0 with SYSCLK 32MHz set in SystemClock_Config() */
#if (defined (USE_STM32L0XX_NUCLEO))
#define NUCLEO_I2C_EXPBD_TIMING_100KHZ       0x10A13E56 /* Analog Filter ON, Rise Time 400ns, Fall Time 100ns */
#define NUCLEO_I2C_EXPBD_TIMING_400KHZ       0x00B1112E /* Analog Filter ON, Rise Time 250ns, Fall Time 100ns */
#endif /* USE_STM32L0XX_NUCLEO */

/* Timing samples for L4 and WL  with SYSCLK 80MHz set in SystemClock_Config() */
#if (defined (USE_STM32L4XX_NUCLEO) || defined (USE_STM32WLXX_NUCLEO))
#define NUCLEO_I2C_EXPBD_TIMING_400KHZ       0x10D1143A /* Analog Filter ON, Rise time 250ns, Fall Time 100ns */
#define NUCLEO_I2C_EXPBD_TIMING_1000KHZ      0x00D00E28 /* Analog Filter ON, Rise time 120ns, Fall time 25ns */
#endif /* USE_STM32L4XX_NUCLEO */

/* I2C peripheral configuration defines */
#if (	(defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO))	\
	||	(defined (USE_STM32L0XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO))	\
	)

#define NUCLEO_I2C_EXPBD                            I2C1
#define NUCLEO_I2C_EXPBD_CLK_ENABLE()               __I2C1_CLK_ENABLE()
#define NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_CLK_ENABLE()  __GPIOB_CLK_ENABLE()
#define NUCLEO_I2C_EXPBD_SCL_SDA_AF                 GPIO_AF4_I2C1
#define NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_PORT          GPIOB
#define NUCLEO_I2C_EXPBD_SCL_PIN                    GPIO_PIN_8
#define NUCLEO_I2C_EXPBD_SDA_PIN                    GPIO_PIN_9

#define NUCLEO_I2C_EXPBD_FORCE_RESET()              __I2C1_FORCE_RESET()
#define NUCLEO_I2C_EXPBD_RELEASE_RESET()            __I2C1_RELEASE_RESET()

#endif

#if (defined (USE_STM32WLXX_NUCLEO))
#define NUCLEO_I2C_EXPBD                            I2C2
#define NUCLEO_I2C_EXPBD_CLK_ENABLE()               __I2C2_CLK_ENABLE()
#define NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_CLK_ENABLE()  __GPIOA_CLK_ENABLE()
#define NUCLEO_I2C_EXPBD_SCL_SDA_AF                 GPIO_AF4_I2C2
#define NUCLEO_I2C_EXPBD_SCL_SDA_GPIO_PORT          GPIOA
#define NUCLEO_I2C_EXPBD_SCL_PIN                    GPIO_PIN_12
#define NUCLEO_I2C_EXPBD_SDA_PIN                    GPIO_PIN_11

#define NUCLEO_I2C_EXPBD_FORCE_RESET()              __I2C2_FORCE_RESET()
#define NUCLEO_I2C_EXPBD_RELEASE_RESET()            __I2C2_RELEASE_RESET()

#endif

/* I2C interrupt requests */
#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define NUCLEO_I2C_EXPBD_EV_IRQn                    I2C1_EV_IRQn
#define NUCLEO_I2C_EXPBD_ER_IRQn                    I2C1_ER_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define NUCLEO_I2C_EXPBD_EV_IRQn                    I2C1_IRQn
#endif

#if (defined (USE_STM32WLXX_NUCLEO))
#define NUCLEO_I2C_EXPBD_EV_IRQn                    I2C2_EV_IRQn
#define NUCLEO_I2C_EXPBD_ER_IRQn                    I2C2_ER_IRQn
#endif

/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the I2C communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */
#define NUCLEO_I2C_EXPBD_TIMEOUT_MAX    0x4000 /*<! The value of the maximal timeout for BUS waiting loops */

/* Definition for interrupt Pins */
#define HTS221_DRDY_GPIO_PORT           GPIOB
#define HTS221_DRDY_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define HTS221_DRDY_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define HTS221_DRDY_PIN                 GPIO_PIN_10

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)) || defined (USE_STM32WLXX_NUCLEO))
#define HTS221_DRDY_EXTI_IRQn           EXTI15_10_IRQn		// EXTI10
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define HTS221_DRDY_EXTI_IRQn           EXTI4_15_IRQn
#endif

#define LSM6DS0_INT1_GPIO_PORT           GPIOB
#define LSM6DS0_INT1_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define LSM6DS0_INT1_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define LSM6DS0_INT1_PIN                 GPIO_PIN_5

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)) || defined (USE_STM32WLXX_NUCLEO))
#define LSM6DS0_INT1_EXTI_IRQn           EXTI9_5_IRQn		// EXTI5
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define LSM6DS0_INT1_EXTI_IRQn           EXTI4_15_IRQn
#endif

#define LIS3MDL_DRDY_GPIO_PORT           GPIOB
#define LIS3MDL_DRDY_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define LIS3MDL_DRDY_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define LIS3MDL_DRDY_PIN                 GPIO_PIN_13

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define LIS3MDL_DRDY_EXTI_IRQn           EXTI0_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define LIS3MDL_DRDY_EXTI_IRQn           EXTI0_1_IRQn
#endif

#if (defined (USE_STM32WLXX_NUCLEO))
#define LIS3MDL_DRDY_EXTI_IRQn           EXTI15_10_IRQn		// EXTI13
#endif

#define LIS3MDL_INT1_GPIO_PORT           GPIOB
#define LIS3MDL_INT1_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define LIS3MDL_INT1_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define LIS3MDL_INT1_PIN                 GPIO_PIN_14

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)) || defined (USE_STM32WLXX_NUCLEO))
#define LIS3MDL_INT1_EXTI_IRQn           EXTI1_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define LIS3MDL_INT1_EXTI_IRQn           EXTI0_1_IRQn
#endif

#define LPS25HB_INT1_GPIO_PORT           GPIOB
#define LPS25HB_INT1_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define LPS25HB_INT1_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define LPS25HB_INT1_PIN                 GPIO_PIN_8

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define LPS25HB_INT1_EXTI_IRQn           EXTI4_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define LPS25HB_INT1_EXTI_IRQn           EXTI4_15_IRQn
#endif

#if (defined (USE_STM32WLXX_NUCLEO))
#define LPS25HB_INT1_EXTI_IRQn           EXTI15_10_IRQn			// EXTI14
#endif

// ready for use
#define USER_INT_GPIO_PORT           	GPIOB
#define USER_INT_GPIO_CLK_ENABLE()   	__GPIOB_CLK_ENABLE()
#define USER_INT_GPIO_CLK_DISABLE() 	__GPIOB_CLK_DISABLE()
#define USER_INT_PIN                 	GPIO_PIN_12

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)) || defined (USE_STM32WLXX_NUCLEO))
#define USER_INT_EXTI_IRQn           	EXTI15_10_IRQn			// EXTI12 for WL
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define USER_INT_EXTI_IRQn           EXTI4_15_IRQn
#endif

// ready for use
#define M_INT1_GPIO_PORT           GPIOA
#define M_INT1_GPIO_CLK_ENABLE()   __GPIOA_CLK_ENABLE()
#define M_INT1_GPIO_CLK_DISABLE()  __GPIOA_CLK_DISABLE()
#define M_INT1_PIN                 GPIO_PIN_10

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define M_INT1_EXTI_IRQn           EXTI4_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define M_INT1_EXTI_IRQn           EXTI4_15_IRQn
#endif

#if (defined (USE_STM32WLXX_NUCLEO))
#define M_INT1_EXTI_IRQn           EXTI15_10_IRQn			// EXTI10
#endif

// ready for use
#define M_INT2_GPIO_PORT           GPIOB
#define M_INT2_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()
#define M_INT2_GPIO_CLK_DISABLE()  __GPIOB_CLK_DISABLE()
#define M_INT2_PIN                 GPIO_PIN_4

#if ((defined (USE_STM32F4XX_NUCLEO)) || (defined (USE_STM32L1XX_NUCLEO)) || (defined (USE_STM32L4XX_NUCLEO)))
#define M_INT2_EXTI_IRQn           EXTI0_IRQn
#endif

#if (defined (USE_STM32L0XX_NUCLEO))
#define M_INT2_EXTI_IRQn           EXTI0_1_IRQn
#endif

#if (defined (USE_STM32WLXX_NUCLEO))
#define M_INT2_EXTI_IRQn           EXTI4_IRQn
#endif


/**
  * @}
  */

/** @addtogroup X_NUCLEO_IKS01A1_IO_Public_FunctionPrototypes Public function prototypes
 * @{
 */

DrvStatusTypeDef Sensor_IO_Init(void);
DrvStatusTypeDef LSM6DS0_Sensor_IO_ITConfig(void);
DrvStatusTypeDef DIL24_Sensor_IO_ITConfig(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __X_NUCLEO_IKS01A1_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
