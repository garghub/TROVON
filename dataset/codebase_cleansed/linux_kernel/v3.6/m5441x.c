static void __init m5441x_clk_init(void)
{
unsigned i;
for (i = 0; i < ARRAY_SIZE(enable_clks); ++i)
__clk_init_enabled(enable_clks[i]);
for (i = 0; i < ARRAY_SIZE(disable_clks); ++i)
__clk_init_disabled(disable_clks[i]);
}
static void __init m5441x_uarts_init(void)
{
__raw_writeb(0x0f, MCFGPIO_PAR_UART0);
__raw_writeb(0x00, MCFGPIO_PAR_UART1);
__raw_writeb(0x00, MCFGPIO_PAR_UART2);
}
static void __init m5441x_fec_init(void)
{
__raw_writeb(0x03, MCFGPIO_PAR_FEC);
}
void __init config_BSP(char *commandp, int size)
{
m5441x_clk_init();
mach_sched_init = hw_timer_init;
m5441x_uarts_init();
m5441x_fec_init();
}
static int __init init_BSP(void)
{
platform_add_devices(m5441x_devices, ARRAY_SIZE(m5441x_devices));
return 0;
}
