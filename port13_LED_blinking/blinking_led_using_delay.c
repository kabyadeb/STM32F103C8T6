#define rcc_base 0x40021000
#define gpioc_base 0x40011000

#define rcc_apb2_enr *(volatile unsigned int *)(rcc_base + 0x18)
#define gpioc_crh *(volatile unsigned int *)(gpioc_base + 0x04)

#define  delay 100000
#define bsrr *(volatile unsigned int *)(gpioc_base + 0x10)



int main()
{
	rcc_apb2_enr |= (1u << 4); 
	// 20->0 21->0 22->0 23->0
	gpioc_crh &= ~(0xf << 20);
	//0010 
	gpioc_crh |=(1u<<21);

	while(1)
	{
		bsrr |=(1u<<13); // gpioc bsrr set 
		for(int i=1;i<delay;i++);
		bsrr |=(1u<<29);// gpioc bsrr reset 
		for(int i=1;i<delay;i++);
	}
}
