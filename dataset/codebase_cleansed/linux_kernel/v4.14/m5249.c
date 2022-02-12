static void __init m5249_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
writeb(MCFSIM_ICR_AUTOVEC | MCFSIM_ICR_LEVEL4 | MCFSIM_ICR_PRI0,
MCFSIM_QSPIICR);
mcf_mapirq2imr(MCF_IRQ_QSPI, MCFINTC_QSPI);
#endif
}
static void __init m5249_i2c_init(void)
{
#if IS_ENABLED(CONFIG_I2C_IMX)
u32 r;
writeb(MCFSIM_ICR_AUTOVEC | MCFSIM_ICR_LEVEL5 | MCFSIM_ICR_PRI0,
MCFSIM_I2CICR);
mcf_mapirq2imr(MCF_IRQ_I2C0, MCFINTC_I2C);
r = readl(MCFINTC2_INTPRI_REG(MCF_IRQ_I2C1));
r &= ~MCFINTC2_INTPRI_BITS(0xf, MCF_IRQ_I2C1);
r |= MCFINTC2_INTPRI_BITS(0x5, MCF_IRQ_I2C1);
writel(r, MCFINTC2_INTPRI_REG(MCF_IRQ_I2C1));
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
m5249_i2c_init();
}
static int __init init_BSP(void)
{
platform_add_devices(m5249_devices, ARRAY_SIZE(m5249_devices));
return 0;
}
