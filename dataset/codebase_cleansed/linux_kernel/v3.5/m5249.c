static void __init m5249_qspi_init(void)
{
writeb(MCFSIM_ICR_AUTOVEC | MCFSIM_ICR_LEVEL4 | MCFSIM_ICR_PRI0,
MCF_MBAR + MCFSIM_QSPIICR);
mcf_mapirq2imr(MCF_IRQ_QSPI, MCFINTC_QSPI);
}
static void __init m5249_smc91x_init(void)
{
u32 gpio;
gpio = readl(MCF_MBAR2 + MCFSIM2_GPIOINTENABLE);
writel(gpio | 0x40, MCF_MBAR2 + MCFSIM2_GPIOINTENABLE);
gpio = readl(MCF_MBAR2 + MCFSIM2_INTLEVEL5);
writel(gpio | 0x04000000, MCF_MBAR2 + MCFSIM2_INTLEVEL5);
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
#ifdef CONFIG_M5249C3
m5249_smc91x_init();
#endif
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
m5249_qspi_init();
#endif
}
static int __init init_BSP(void)
{
platform_add_devices(m5249_devices, ARRAY_SIZE(m5249_devices));
return 0;
}
