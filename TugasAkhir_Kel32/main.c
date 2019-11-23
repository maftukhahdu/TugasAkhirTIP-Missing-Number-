#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "LCD_Driver.h"
#include "DrvSPI.h"
#include "ScanKey.h"
#include "Seven_Segment.h"


int acak, satuan;
int acak1, satuan1, puluhan1, ratusan1, ribuan1;
int i;
int time=400000;
int waktu=1500;
int life=3;
int temp;
int x;
int score;
int adc;
int tegangan;
int stop;

void opening()
{
	print_lcd(0,"   Tugas Akhir");
	DrvSYS_Delay(1000000);
	print_lcd(1,"  Praktikum TM");
	DrvSYS_Delay(1000000);
	print_lcd(2,"      2019");
	DrvSYS_Delay(1000000);
	print_lcd(3,"   Kelompok 32");
	DrvSYS_Delay(5000000);
	clr_all_pannal();

	print_lcd(0,"     WELCOME");
	DrvSYS_Delay(1000000);
	print_lcd(1,"   To Our Game");
	DrvSYS_Delay(1000000);
	print_lcd(2,"  Missing Number");
	DrvSYS_Delay(1000000);
	clr_all_pannal();

	print_lcd(1,"   Get Ready");
	DrvSYS_Delay(1000000);
	print_lcd(1,"Prepare Yourself in");
	DrvSYS_Delay(1000000);
	clr_all_pannal();

	print_lcd(1,"        3");
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(1000000);
	print_lcd(1,"        2");
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(1000000);
	print_lcd(1,"        1");
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(1000000);
	clr_all_pannal();
}

void soal1()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=1;i++)
	{
		clr_all_pannal();
		print_lcd(0, "5,4,3,2,...");
		DrvSYS_Delay(time);
	}
	print_lcd(1," Push The Keypad");
	print_lcd(2,"  Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==1)
	{
		clr_all_pannal();
		print_lcd(1,"    TRUE!");
		print_lcd(2,"   Next Level");
		DrvGPIO_SetBit(E_GPA, 12);
		DrvGPIO_ClrBit(E_GPA, 13);
		DrvGPIO_SetBit(E_GPA, 14);
		buzzer_benar();
		DrvSYS_Delay(2000000);
		score++;
		random();
	}
		if((temp==3)||(temp==2)||(temp==4)||(temp==5)||(temp==6)||(temp==7)||(temp==8)||(temp==9))
	{
		clr_all_pannal();
		print_lcd(1,"    FALSE!");
		print_lcd(2,"   Try Again");
		DrvGPIO_ClrBit(E_GPC, 12);
		DrvGPIO_ClrBit(E_GPC, 13);
		DrvGPIO_ClrBit(E_GPC, 14);
		DrvGPIO_ClrBit(E_GPC, 15);
		buzzer_salah();
		DrvSYS_Delay(2000000);
		life--;
		random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal2()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=2;i++)
	{
		clr_all_pannal();
		print_lcd(0, "10,8,6,4,...");
		DrvSYS_Delay(time);
	}
	print_lcd(1," Push The Keypad");
	print_lcd(2,"  Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==2)
	{
			clr_all_pannal();
			print_lcd(1,"    TRUE!");
			print_lcd(2,"   Next Level");
			DrvGPIO_SetBit(E_GPA, 12);
			DrvGPIO_ClrBit(E_GPA, 13);
			DrvGPIO_SetBit(E_GPA, 14);
			buzzer_benar();
			DrvSYS_Delay(2000000);
			score++;
			random();
	}
		if((temp==1)||(temp==4)||(temp==3)||(temp==5)||(temp==6)||(temp==7)||(temp==8)||(temp==9))
	{
			clr_all_pannal();
			print_lcd(1,"    FALSE!");
			print_lcd(2,"   Try Again");
			DrvGPIO_ClrBit(E_GPC, 12);
			DrvGPIO_ClrBit(E_GPC, 13);
			DrvGPIO_ClrBit(E_GPC, 14);
			DrvGPIO_ClrBit(E_GPC, 15);
			buzzer_salah();
			DrvSYS_Delay(2000000);
			life--;
			random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal3()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=3;i++)
	{
		clr_all_pannal();
		print_lcd(0, "-1,0,1,2,...");
		DrvSYS_Delay(time);
	}
	print_lcd(1,"Push The Keypad");
	print_lcd(2,"Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==3)
	{
			clr_all_pannal();
			print_lcd(1,"TRUE!");
			print_lcd(2,"Next Level");
			DrvGPIO_SetBit(E_GPA, 12);
			DrvGPIO_ClrBit(E_GPA, 13);
			DrvGPIO_SetBit(E_GPA, 14);
			buzzer_benar();
			DrvSYS_Delay(2000000);
			score++;
			random();
	}
		if((temp==1)||(temp==2)||(temp==4)||(temp==5)||(temp==6)||(temp==7)||(temp==8)||(temp==9))
	{
			clr_all_pannal();
			print_lcd(1,"FALSE!");
			print_lcd(2,"Try Again");
			DrvGPIO_ClrBit(E_GPC, 12);
			DrvGPIO_ClrBit(E_GPC, 13);
			DrvGPIO_ClrBit(E_GPC, 14);
			DrvGPIO_ClrBit(E_GPC, 15);
			buzzer_salah();
			DrvSYS_Delay(2000000);
			life--;
			random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal4()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=4;i++)
	{
		clr_all_pannal();
		print_lcd(0, "16,12,8,...,0");
		DrvSYS_Delay(time);
	}
	print_lcd(1,"Push The Keypad");
	print_lcd(2,"Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==4)
	{
			clr_all_pannal();
			print_lcd(1,"TRUE!");
			print_lcd(2,"Next Level");
			DrvGPIO_SetBit(E_GPA, 12);
			DrvGPIO_ClrBit(E_GPA, 13);
			DrvGPIO_SetBit(E_GPA, 14);
			buzzer_benar();
			DrvSYS_Delay(2000000);
			score++;
			random();
	}
		if((temp==1)||(temp==2)||(temp==3)||(temp==5)||(temp==6)||(temp==7)||(temp==8)||(temp==9))
	{
			clr_all_pannal();
			print_lcd(1,"FALSE!");
			print_lcd(2,"Try Again");
			DrvGPIO_ClrBit(E_GPC, 12);
			DrvGPIO_ClrBit(E_GPC, 13);
			DrvGPIO_ClrBit(E_GPC, 14);
			DrvGPIO_ClrBit(E_GPC, 15);
			buzzer_salah();
			DrvSYS_Delay(2000000);
			life--;
			random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal5()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=5;i++)
	{
		clr_all_pannal();
		print_lcd(0, "2,3,...,7,11");
		DrvSYS_Delay(time);
	}
	print_lcd(1,"Push The Keypad");
	print_lcd(2,"Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==5)
	{
			clr_all_pannal();
			print_lcd(1,"TRUE!");
			print_lcd(2,"Next Level");
			DrvGPIO_SetBit(E_GPA, 12);
			DrvGPIO_ClrBit(E_GPA, 13);
			DrvGPIO_SetBit(E_GPA, 14);
			buzzer_benar();
			DrvSYS_Delay(2000000);
			score++;
			random();
	}
		if((temp==1)||(temp==2)||(temp==3)||(temp==4)||(temp==6)||(temp==7)||(temp==8)||(temp==9))
	{
			clr_all_pannal();
			print_lcd(1,"FALSE!");
			print_lcd(2,"Try Again");
			DrvGPIO_ClrBit(E_GPC, 12);
			DrvGPIO_ClrBit(E_GPC, 13);
			DrvGPIO_ClrBit(E_GPC, 14);
			DrvGPIO_ClrBit(E_GPC, 15);
			buzzer_salah();
			DrvSYS_Delay(2000000);
			life--;
			random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal6()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=6;i++)
	{
		clr_all_pannal();
		print_lcd(0, "1,3,...,10,15");
		DrvSYS_Delay(time);
	}
	print_lcd(1,"Push The Keypad");
	print_lcd(2,"Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==6)
	{
			clr_all_pannal();
			print_lcd(1,"TRUE!");
			print_lcd(2,"Next Level");
			DrvGPIO_SetBit(E_GPA, 12);
			DrvGPIO_ClrBit(E_GPA, 13);
			DrvGPIO_SetBit(E_GPA, 14);
			buzzer_benar();
			DrvSYS_Delay(2000000);
			score++;
			random();
	}
		if((temp==1)||(temp==2)||(temp==3)||(temp==5)||(temp==4)||(temp==7)||(temp==8)||(temp==9))
	{
			clr_all_pannal();
			print_lcd(1,"FALSE!");
			print_lcd(2,"Try Again");
			DrvGPIO_ClrBit(E_GPC, 12);
			DrvGPIO_ClrBit(E_GPC, 13);
			DrvGPIO_ClrBit(E_GPC, 14);
			DrvGPIO_ClrBit(E_GPC, 15);
			buzzer_salah();
			DrvSYS_Delay(2000000);
			life--;
			random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal7()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=7;i++)
	{
		clr_all_pannal();
		print_lcd(0, "35,28,21,14,...");
		DrvSYS_Delay(time);
	}
	print_lcd(1,"Push The Keypad");
	print_lcd(2,"Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==7)
	{
			clr_all_pannal();
			print_lcd(1,"TRUE!");
			print_lcd(2,"Next Level");
			DrvGPIO_SetBit(E_GPA, 12);
			DrvGPIO_ClrBit(E_GPA, 13);
			DrvGPIO_SetBit(E_GPA, 14);
			buzzer_benar();
			DrvSYS_Delay(2000000);
			score++;
			random();
	}
		if((temp==1)||(temp==2)||(temp==3)||(temp==5)||(temp==6)||(temp==4)||(temp==8)||(temp==9))
	{
			clr_all_pannal();
			print_lcd(1,"FALSE!");
			print_lcd(2,"Try Again");
			DrvGPIO_ClrBit(E_GPC, 12);
			DrvGPIO_ClrBit(E_GPC, 13);
			DrvGPIO_ClrBit(E_GPC, 14);
			DrvGPIO_ClrBit(E_GPC, 15);
			buzzer_salah();
			DrvSYS_Delay(2000000);
			life--;
			random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal8()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=8;i++)
	{
		clr_all_pannal();
		print_lcd(0, "1,2,3,5,...,13");
		DrvSYS_Delay(time);
	}
	print_lcd(1,"Push The Keypad");
	print_lcd(2,"Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
	temp=Scankey();
	if (temp==8)
	{
		clr_all_pannal();
		print_lcd(1,"TRUE!");
		print_lcd(2,"Next Level");
		DrvGPIO_SetBit(E_GPA, 12);
		DrvGPIO_ClrBit(E_GPA, 13);
		DrvGPIO_SetBit(E_GPA, 14);
		buzzer_benar();
		DrvSYS_Delay(2000000);
		score++;
		random();
	}
	if((temp==1)||(temp==2)||(temp==3)||(temp==4)||(temp==6)||(temp==7)||(temp==5)||(temp==9))
	{
		clr_all_pannal();
		print_lcd(1,"FALSE!");
		print_lcd(2,"Try Again");
		DrvGPIO_ClrBit(E_GPC, 12);
		DrvGPIO_ClrBit(E_GPC, 13);
		DrvGPIO_ClrBit(E_GPC, 14);
		DrvGPIO_ClrBit(E_GPC, 15);
		buzzer_salah();
		DrvSYS_Delay(2000000);
		life--;
		random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void soal9()
{
	DrvGPIO_SetBit(E_GPA, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	point();
	for (i = 1; i<=9;i++)
	{
		clr_all_pannal();
		print_lcd(0, "3,5,7,...,11");
		DrvSYS_Delay(time);
	}
	print_lcd(1,"Push The Keypad");
	print_lcd(2,"Limited Time");
	nyawa();
	for (i=0;i<=waktu;i++)
	{
		temp=Scankey();
		if (temp==9)
	{
			clr_all_pannal();
			print_lcd(1,"TRUE!");
			print_lcd(2,"Next Level");
			DrvGPIO_SetBit(E_GPA, 12);
			DrvGPIO_ClrBit(E_GPA, 13);
			DrvGPIO_SetBit(E_GPA, 14);
			buzzer_benar();
			DrvSYS_Delay(2000000);
			score++;
			random();
	}
		if((temp==1)||(temp==2)||(temp==3)||(temp==5)||(temp==4)||(temp==7)||(temp==8)||(temp==6))
	{
			clr_all_pannal();
			print_lcd(1,"FALSE!");
			print_lcd(2,"Try Again");
			DrvGPIO_ClrBit(E_GPC, 12);
			DrvGPIO_ClrBit(E_GPC, 13);
			DrvGPIO_ClrBit(E_GPC, 14);
			DrvGPIO_ClrBit(E_GPC, 15);
			buzzer_salah();
			DrvSYS_Delay(2000000);
			life--;
			random();
	}
		point();
	}
		if(temp==0)Time_is_up();
}

void nyawa(void)
{
	if(life == 3)print_lcd(3,"Life : 3");
	if(life == 2)print_lcd(3,"Life : 2");
	if(life == 1)print_lcd(3,"Life : 1");
	if(life == 0)dead();
}

void Time_is_up(void)
{
	clr_all_pannal();
	close_seven_segment();
	print_lcd(1,"    Time Is Up");
	print_lcd(2,"     Try Again");
	buzzer_salah();
	life--;
	DrvSYS_Delay(2000000);
	point();
	nyawa();
}

void random(void)
{
	while(1)
	{
		clr_all_pannal();
		point();
		nyawa();
		time = time - 8000;
		if(time <= 500)waktu = 500;
		acak = i;
		satuan = acak%10;
		acak=acak/10;
		if(satuan == 0)soal3();
		if(satuan == 1)soal7();
		if(satuan == 2)soal9();
		if(satuan == 3)soal6();
		if(satuan == 4)soal4();
		if(satuan == 5)soal8();
		if(satuan == 6)soal1();
		if(satuan == 7)soal5();
		if(satuan == 8)soal2();
		if(satuan == 9)soal9();
	}
}

void point(void)
{
	acak1 = score;
	satuan1 = acak1%10;
	acak1=acak1/10;
	puluhan1 = acak1%10;
	acak1=acak1/10;
	ratusan1 = acak1%10;
	acak1=acak1/10;
	ribuan1 = acak1%10;
	close_seven_segment();
	show_seven_segment(0,satuan1);
	DrvSYS_Delay(1000);
	close_seven_segment();
	show_seven_segment(1,puluhan1);
	DrvSYS_Delay(1000);
	close_seven_segment();
	show_seven_segment(2,ratusan1);
	DrvSYS_Delay(1000);
	close_seven_segment();
	show_seven_segment(3,ribuan1);
	DrvSYS_Delay(1000);
}

void dead(void)
{
	clr_all_pannal();
	while(1)
	{
		point();
		print_lcd(1,"    Game Over");
		print_lcd(2,"   Try Again");
	}
}


void buzzer_benar(void)
{
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_SetBit(E_GPB,11);
}

void buzzer_salah(void)
{
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_ClrBit(E_GPB,11);
	DrvSYS_Delay(100000);
	DrvGPIO_SetBit(E_GPB,11);
	DrvSYS_Delay(100000);
}

int main(void)
{
	UNLOCKREG();
	DrvSYS_SetOscCtrl(E_SYS_XTL12M,1);
	SYSCLK->PWRCON.XTL12M_EN=1;
	DrvSYS_Delay(5000);
	DrvSYS_SelectHCLKSource(0);
	LOCKREG();
	DrvSYS_SetClockDivider(E_SYS_HCLK_DIV,0);
	uint8_t tekan;
	OpenKeyPad();
	Initial_pannel();
	clr_all_pannal();
	DrvGPIO_ClrBit(E_GPD,14);
	DrvSYS_Delay(1000000);

while(1)
{
	tegangan=((float)adc/4096)*5000;
	opening();
	random();
}
}
