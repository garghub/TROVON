static void __init m520x_clk_init(void)
{
unsigned i;
for (i = 0; i < ARRAY_SIZE(enable_clks); ++i)
__clk_init_enabled(enable_clks[i]);
for (i = 0; i < ARRAY_SIZE(disable_clks); ++i)
__clk_init_disabled(disable_clks[i]);
}
static void __init m520x_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
u16 par;
writeb(0x3f, MCF_GPIO_PAR_QSPI);
par = readw(MCF_GPIO_PAR_UART);
par &= 0x00ff;
writew(par, MCF_GPIO_PAR_UART);
#endif
}
static void __init m520x_i2c_init(void)
{
#if IS_ENABLED(CONFIG_I2C_IMX)
u8 par;
par = readb(MCF_GPIO_PAR_FECI2C);
par |= 0x0f;
writeb(par, MCF_GPIO_PAR_FECI2C);
#endif
}
static void __init m520x_uarts_init(void)
{
u16 par;
u8 par2;
par = readw(MCF_GPIO_PAR_UART);
par |= MCF_GPIO_PAR_UART_PAR_UTXD0 | MCF_GPIO_PAR_UART_PAR_URXD0;
par |= MCF_GPIO_PAR_UART_PAR_UTXD1 | MCF_GPIO_PAR_UART_PAR_URXD1;
writew(par, MCF_GPIO_PAR_UART);
par2 = readb(MCF_GPIO_PAR_FECI2C);
par2 &= ~0x0F;
par2 |= MCF_GPIO_PAR_FECI2C_PAR_SCL_UTXD2 |
MCF_GPIO_PAR_FECI2C_PAR_SDA_URXD2;
writeb(par2, MCF_GPIO_PAR_FECI2C);
}
static void __init m520x_fec_init(void)
{
u8 v;
v = readb(MCF_GPIO_PAR_FEC);
writeb(v | 0xf0, MCF_GPIO_PAR_FEC);
v = readb(MCF_GPIO_PAR_FECI2C);
writeb(v | 0x0f, MCF_GPIO_PAR_FECI2C);
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
m520x_clk_init();
m520x_uarts_init();
m520x_fec_init();
m520x_qspi_init();
m520x_i2c_init();
}
