#include <REGX52.H>

void Timer0Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;		//设定计时器模式
	TMOD |= 0x01;		//设定计时器模式
	TL0 = 0x18;			//设置定时初值
	TH0 = 0xFC;			//设置定时初值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器从0开始计时
	//配置中断
	ET0=1;
	EA=1;
	PT0=0;
	
}

/*
void Timer0_Rountine() interrupt 1
{
	static unsigned int T0Count=0;		
	TL0 = 0x18;			//设置定时初值
	TH0 = 0xFC;	
	T0Count++;
	//1次中断一微秒，1000次就是1秒
	if(T0Count>=500)
	{
		T0Count=0;
		//使用INTRINS内置库进行循环左移或右移
		if(LEDMode==0)
			P2=_crol_(P2,1);
		if(LEDMode==1)
			P2=_cror_(P2,1);
	}
}
*/

