static void __init m5249_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
writeb(MCFSIM_ICR_AUTOVEC | MCFSIM_ICR_LEVEL4 | MCFSIM_ICR_PRI0,
MCFSIM_QSPIICR);
mcf_mapirq2imr(MCF_IRQ_QSPI, MCFINTC_QSPI);
#endif
}
static void __init m5249_smc91x_init(void)
{
u32 gpio;
gpio = readl(MCFSIM2_GPIOINTENABLE);
writel(gpio | 0x40, MCFSIM2_GPIOINTENABLE);
gpio = readl(MCFINTC2_INTPRI5);
writel(gpio | 0x04000000, MCFINTC2_INTPRI5);
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
#ifdef CONFIG_M5249C3
m5249_smc91x_init();
#endif
m5249_qspi_init();
}
static int __init init_BSP(void)
{
platform_add_devices(m5249_devices, ARRAY_SIZE(m5249_devices));
return 0;
}
