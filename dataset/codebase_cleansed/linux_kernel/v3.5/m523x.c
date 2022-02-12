static void __init m523x_qspi_init(void)
{
u16 par;
writeb(0x1f, MCFGPIO_PAR_QSPI);
par = readw(MCFGPIO_PAR_TIMER);
par &= 0x3f3f;
writew(par, MCFGPIO_PAR_TIMER);
}
static void __init m523x_fec_init(void)
{
u16 par;
u8 v;
par = readw(MCF_IPSBAR + 0x100082);
writew(par | 0xf00, MCF_IPSBAR + 0x100082);
v = readb(MCF_IPSBAR + 0x100078);
writeb(v | 0xc0, MCF_IPSBAR + 0x100078);
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
m523x_fec_init();
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
m523x_qspi_init();
#endif
}
