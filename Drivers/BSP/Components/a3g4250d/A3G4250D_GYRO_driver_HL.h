/**
 ******************************************************************************
 * @file    A3G4250D_GYRO_driver_HL.h
 * @author  MEMS Application Team
 * @brief   This file contains definitions for the A3G4250D_GYRO_driver_HL.c firmware driver
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
#ifndef __A3G4250D_GYRO_DRIVER_HL_H
#define __A3G4250D_GYRO_DRIVER_HL_H

#ifdef __cplusplus
extern "C" {
#endif



/* Includes ------------------------------------------------------------------*/

#include "gyroscope.h"

/* Include gyro sensor component drivers. */
#include "A3G4250D_GYRO_driver.h"



/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup COMPONENTS COMPONENTS
 * @{
 */

/** @addtogroup A3G4250D A3G4250D
 * @{
 */

/** @addtogroup A3G4250D_Public_Constants Public constants
 * @{
 */

#define A3G4250D_SENSORS_MAX_NUM  1     /**< A3G4250D max number of instances */

/** @addtogroup A3G4250D_GYRO_SENSITIVITY Gyro sensitivity values based on selected full scale
 * @{
 */

#define A3G4250D_GYRO_SENSITIVITY_FOR_FS_245DPS  8.750  /**< Sensitivity value for 245 dps full scale [mdps/LSB] */

/**
 * @}
 */

/**
 * @}
 */

/** @addtogroup A3G4250DPublic_Types A3G4250D Public Types
 * @{
 */

#if 0 /* _NOTE_: Remove this line if you plan to use this structure below */
/**
 * @brief A3G4250D gyro extended features driver internal structure definition
 */
typedef struct
{
  /* _NOTE_: Possible to add the functions for extended features of the sensor here */
} A3G4250D_ExtDrv_t;
#endif /* _NOTE_: Remove this line if you plan to use this structure above */

/**
 * @brief A3G4250D specific data internal structure definition
 */
typedef struct
{
  float Previous_ODR;
} A3G4250D_Data_t;

/**
 * @}
 */

/** @addtogroup A3G4250D_Public_Variables Public variables
 * @{
 */

extern GYRO_Drv_t A3G4250D_Drv;
#if 0 /* _NOTE_: Remove this line if you plan to use this structure below */
extern A3G4250D_ExtDrv_t A3G4250D_ExtDrv;
#endif /* _NOTE_: Remove this line if you plan to use this structure above */


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

#endif /* __A3G4250D_ACC_GYRO_DRIVER_HL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
