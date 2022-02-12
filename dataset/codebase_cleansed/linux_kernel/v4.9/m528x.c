static void __init m528x_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
__raw_writeb(0x07, MCFGPIO_PQSPAR);
#endif
}
static void __init m528x_uarts_init(void)
{
u8 port;
port = readb(MCFGPIO_PUAPAR);
port |= 0x03 | (0x03 << 2);
writeb(port, MCFGPIO_PUAPAR);
}
static void __init m528x_fec_init(void)
{
u16 v16;
v16 = readw(MCFGPIO_PASPAR);
writew(v16 | 0xf00, MCFGPIO_PASPAR);
writeb(0xc0, MCFGPIO_PEHLPAR);
}
void wildfire_halt(void)
{
writeb(0, 0x30000007);
writeb(0x2, 0x30000007);
}
void wildfiremod_halt(void)
{
printk(KERN_INFO "WildFireMod hibernating...\n");
writew(readw(MCFGPIO_PEPAR) & ~(1 << (5 * 2)), MCFGPIO_PEPAR);
writeb(readb(MCFGPIO_PDDR_E) | (1 << 5), MCFGPIO_PDDR_E);
writeb(readb(MCFGPIO_PODR_E) & ~(1 << 5), MCFGPIO_PODR_E);
writeb(readb(MCFGPIO_PODR_E) | (1 << 5), MCFGPIO_PODR_E);
printk(KERN_EMERG "Failed to hibernate. Halting!\n");
}
void __init config_BSP(char *commandp, int size)
{
#ifdef CONFIG_WILDFIRE
mach_halt = wildfire_halt;
#endif
#ifdef CONFIG_WILDFIREMOD
mach_halt = wildfiremod_halt;
#endif
mach_sched_init = hw_timer_init;
m528x_uarts_init();
m528x_fec_init();
m528x_qspi_init();
}
