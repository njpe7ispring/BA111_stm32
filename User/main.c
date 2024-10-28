#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

//uint8_t Serial_TxPacket[6];   //外部使用，用extern，或者用GET函数，指针传递；即可在其他的文件中使用
//uint8_t Serial_RxPacket[6];
//uint8_t Serial_GetDrvFlag();
uint8_t RxData;	 		//定义用于接收串口数据的变量

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "HaoShui:");
	OLED_ShowString(2, 1, "TDS:");
	OLED_ShowString(3, 1, "TEM:");
	/*串口初始化*/
	Serial_Init();		//串口初始化
	//我要一个个用屏幕发数据进行验证
	BA111_calibration();
	while (1)                                                                                                                     
	{
		BA111_Getsensordata(); 
		Delay_ms(1000);
			OLED_ShowHexNum(4, 1, Serial_RxPacket[0], 2);
			OLED_ShowHexNum(4, 4, Serial_RxPacket[1], 2);	//显示串口接收的数据
			OLED_ShowHexNum(4, 6, Serial_RxPacket[2], 2);
			OLED_ShowHexNum(4, 8,Serial_RxPacket[3], 2);
			OLED_ShowHexNum(4, 10,Serial_RxPacket[4], 2);
			OLED_ShowHexNum(4, 12,Serial_RxPacket[5], 2);
		//Sdata = BA111_ParseData(); // 更新全局的data
		OLED_ShowString(2, 1, "TDS:"); // 重新打印，避免闪烁
		OLED_ShowNum(2, 5, Sdata.tds, 3);
		printf("TDS:%d",Sdata.tds);
		OLED_ShowString(3, 1, "TEM:");
		printf("TDS:%d",Sdata.tds);
		OLED_ShowNum(3, 5, Sdata.temp, 2);
		Delay_ms(1000); // 为显示更新留出时间
		
		
	}
}
