static void __init m523x_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
u16 par;
writeb(0x1f, MCFGPIO_PAR_QSPI);
par = readw(MCFGPIO_PAR_TIMER);
par &= 0x3f3f;
writew(par, MCFGPIO_PAR_TIMER);
#endif
}
static void __init m523x_i2c_init(void)
{
#if IS_ENABLED(CONFIG_I2C_IMX)
u8 par;
par = readb(MCFGPIO_PAR_FECI2C);
par |= 0x0f;
writeb(par, MCFGPIO_PAR_FECI2C);
#endif
}
static void __init m523x_fec_init(void)
{
writeb(readb(MCFGPIO_PAR_FECI2C) | 0xf0, MCFGPIO_PAR_FECI2C);
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
m523x_fec_init();
m523x_qspi_init();
m523x_i2c_init();
}
