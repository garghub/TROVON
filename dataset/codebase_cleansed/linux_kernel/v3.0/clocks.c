void set_au1x00_speed(unsigned int new_freq)
{
au1x00_clock = new_freq;
}
unsigned int get_au1x00_speed(void)
{
return au1x00_clock;
}
unsigned long get_au1x00_uart_baud_base(void)
{
return uart_baud_base;
}
void set_au1x00_uart_baud_base(unsigned long new_baud_base)
{
uart_baud_base = new_baud_base;
}
unsigned long au1xxx_calc_clock(void)
{
unsigned long cpu_speed;
if (au1xxx_cpu_has_pll_wo())
cpu_speed = 396000000;
else
cpu_speed = (au_readl(SYS_CPUPLL) & 0x0000003f) * AU1000_SRC_CLK;
mips_hpt_frequency = cpu_speed;
set_au1x00_uart_baud_base(cpu_speed / (2 * ((int)(au_readl(SYS_POWERCTRL)
& 0x03) + 2) * 16));
set_au1x00_speed(cpu_speed);
return cpu_speed;
}
