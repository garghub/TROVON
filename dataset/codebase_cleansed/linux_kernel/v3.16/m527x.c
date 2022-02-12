static void __init m527x_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
#if defined(CONFIG_M5271)
u16 par;
writeb(0x1f, MCFGPIO_PAR_QSPI);
par = readw(MCFGPIO_PAR_TIMER);
par &= 0x3f3f;
writew(par, MCFGPIO_PAR_TIMER);
#elif defined(CONFIG_M5275)
writew(0x003e, MCFGPIO_PAR_QSPI);
#endif
#endif
}
static void __init m527x_uarts_init(void)
{
u16 sepmask;
sepmask = readw(MCFGPIO_PAR_UART);
sepmask |= UART0_ENABLE_MASK | UART1_ENABLE_MASK | UART2_ENABLE_MASK;
writew(sepmask, MCFGPIO_PAR_UART);
}
static void __init m527x_fec_init(void)
{
u16 par;
u8 v;
#if defined(CONFIG_M5271)
v = readb(MCFGPIO_PAR_FECI2C);
writeb(v | 0xf0, MCFGPIO_PAR_FECI2C);
#else
par = readw(MCFGPIO_PAR_FECI2C);
writew(par | 0xf00, MCFGPIO_PAR_FECI2C);
v = readb(MCFGPIO_PAR_FEC0HL);
writeb(v | 0xc0, MCFGPIO_PAR_FEC0HL);
par = readw(MCFGPIO_PAR_FECI2C);
writew(par | 0xa0, MCFGPIO_PAR_FECI2C);
v = readb(MCFGPIO_PAR_FEC1HL);
writeb(v | 0xc0, MCFGPIO_PAR_FEC1HL);
#endif
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
m527x_uarts_init();
m527x_fec_init();
m527x_qspi_init();
}
