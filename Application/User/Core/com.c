/**
  *******************************************************************************
  * @file    Projects/Multi/Examples/IKS01A1/DataLogExtended/Src/com.c
  * @author  CL
  * @brief   USART message handler
  *******************************************************************************
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
  * ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "com.h"

/** @addtogroup X_NUCLEO_IKS01A1_Examples
  * @{
  */

/** @addtogroup DATALOG_EXTENDED
  * @{
  */

/* Private defines -----------------------------------------------------------*/
#define Uart_Msg_Max_Size TMsg_MaxLen

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef UartHandle;
DMA_HandleTypeDef hdma_rx;
DMA_HandleTypeDef hdma_tx;

volatile uint8_t UART_RxBuffer[UART_RxBufferSize];
volatile uint8_t UART_TxBuffer[TMsg_MaxLen * 2];
TUart_Engine Uart_Engine;
volatile uint32_t Usart_BaudRate = 921600;

/**
  * @brief  Check if a message is received via UART
  * @param  Msg the pointer to the message to be received
  * @retval 1 if a complete message is found, 0 otherwise
  */
int UART_ReceivedMSG(TMsg *Msg)
{
  uint16_t i, j, k, j2;
  uint16_t DmaCounter, length;
  uint8_t Data;
  uint16_t source = 0;
  uint8_t inc = 0;

  if (Get_DMA_Flag_Status(&hdma_rx) == RESET)
  {

    DmaCounter = UART_RxBufferSize - Get_DMA_Counter(&hdma_rx);

    if (DmaCounter >= Uart_Engine.StartOfMsg)
    {
      length = DmaCounter - Uart_Engine.StartOfMsg;
    }
    else
    {
      length = UART_RxBufferSize + DmaCounter - Uart_Engine.StartOfMsg;
    }
    j = Uart_Engine.StartOfMsg;

    for (k = 0; k < length; k++)
    {
      Data = UART_RxBuffer[j];
      j++;
      if (j >= UART_RxBufferSize)
      {
        j = 0;
      }
      if (Data == TMsg_EOF)
      {
        j = Uart_Engine.StartOfMsg;
        for (i = 0; i < k; i += inc)
        {
          uint8_t  Source0;
          uint8_t  Source1;
          uint8_t *Dest;

          j2 = (j + 1) % UART_RxBufferSize;

          Source0 = UART_RxBuffer[j];
          Source1 = UART_RxBuffer[j2];
          Dest    = &Msg->Data[source];

          inc = ReverseByteStuffCopyByte2(Source0, Source1, Dest);
          if (inc == 0)
          {
            Uart_Engine.StartOfMsg = j2;
            return 0;
          }
          j = (j + inc) % UART_RxBufferSize;
          source++;
        }
        Msg->Len = source;
        j = (j + 1) % UART_RxBufferSize; // skip TMsg_EOF
        Uart_Engine.StartOfMsg = j;
        if (CHK_CheckAndRemove(Msg))   // check message integrity
        {
          return 1;
        }
      }
    }
    if (length > Uart_Msg_Max_Size)
    {
      Uart_Engine.StartOfMsg = DmaCounter;
    }
  }
  return 0;
}


/**
  * @brief  Send a message via UART
  * @param  Msg the pointer to the message to be sent
  * @retval None
  */
void UART_SendMsg(TMsg *Msg)
{
  uint16_t CountOut;

  CHK_ComputeAndAdd(Msg);

  CountOut = ByteStuffCopy((uint8_t *) UART_TxBuffer, Msg);

  HAL_UART_Transmit(&UartHandle, (uint8_t *)UART_TxBuffer, CountOut, 5000);
}


/**
 * @}
 */

/**
 * @}
 */
