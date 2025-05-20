#define rcc_base 0x40021000
#define tim2 0x40000000
#define rcc_gpioc_base 0x40011000

#define apb2_enr *(volatile unsigned int *)(rcc_base + 0x18)
#define apb1_enr *(volatile unsigned int *)(rcc_base + 0x1c)

#define rcc_crh *(volatile unsigned int *)(rcc_gpioc_base + 0x04)
//#define rcc_bsrr *(volatile unsigned int *)(rcc_gpioc_base+0x10)

#define tim2_odr *(volatile unsigned int *)(rcc_gpioc_base + 0x0c)
#define tim2_cr1 *(volatile unsigned int *)(tim2 + 0x00)
#define tim2_sr *(volatile unsigned int *)(tim2 + 0x10)
#define tim2_arr *(volatile unsigned int *)(tim2 + 0x2C)
#define tim2_psc *(volatile unsigned int *)(tim2 + 0x28)


//#define delay 100000

int main()
{
	apb2_enr |=(1u<<4);
	rcc_crh &=~(0xf<<20);
	rcc_crh |=(1u<<21);

	apb1_enr |=(1u<<0);
	tim2_psc =7999;
	tim2_arr =599; //1 sec 2 bar
	tim2_cr1 |=(1u<<0);


	while(1)
	{
//		for(int i=1;i<delay;i++);
//		rcc_bsrr |=(1u<<13);
//		for(int i=1;i<delay;i++);
//		rcc_bsrr |=(1u<<29);

		if(tim2_sr & (1u<<0))
		{
			tim2_sr &=~(1u<<0);
			tim2_odr ^=(1u<<13);
		}

	}

}
