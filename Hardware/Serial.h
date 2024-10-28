#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>
typedef enum { false, true } bool;
typedef struct {
    uint16_t tds;
    float temp;
} SensorData;
extern SensorData Sdata;
void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);

void BA111_calibration(void);
void BA111_Calibration(void);
void BA111_sendHexData(char *hexString);
void BA111_Check_callback(void);
bool BA111_Check_DataReceived(void);
void BA111_Set_res(void);
void BA111_Set_B_NTC(void);
void BA111_Getsensordata(void);
SensorData BA111_ParseData(void);
//extern uint8_t Serial_GetDrvFlag(void);
extern uint8_t Serial_TxPacket[6];   //外部使用，用extern，或者用GET函数，指针传递；即可在其他的文件中使用
extern uint8_t Serial_RxPacket[6];
uint8_t Serial_GetRxFlag(void);
//uint8_t Serial_GetRxData(void);
void Serial_SendPacket(void);
#endif
