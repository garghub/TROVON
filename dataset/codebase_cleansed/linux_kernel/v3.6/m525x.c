static void __init m525x_qspi_init(void)
{
#if IS_ENABLED(CONFIG_SPI_COLDFIRE_QSPI)
u32 f = readl(MCFSIM2_GPIOFUNC);
f |= (1 << MCFQSPI_CS2) | (1 << MCFQSPI_CS1) | (1 << MCFQSPI_CS0);
writel(f, MCFSIM2_GPIOFUNC);
writeb(MCFSIM_ICR_AUTOVEC | MCFSIM_ICR_LEVEL4 | MCFSIM_ICR_PRI0,
MCF_MBAR + MCFSIM_QSPIICR);
mcf_mapirq2imr(MCF_IRQ_QSPI, MCFINTC_QSPI);
#endif
}
static void __init m525x_i2c_init(void)
{
#if IS_ENABLED(CONFIG_I2C_COLDFIRE)
u32 r;
writeb(MCFSIM_ICR_AUTOVEC | MCFSIM_ICR_LEVEL5 | MCFSIM_ICR_PRI0,
MCF_MBAR + MCFSIM_I2CICR);
mcf_mapirq2imr(MCF_IRQ_I2C0, MCFINTC_I2C);
r = readl(MCFINTC2_INTPRI_REG(MCF_IRQ_I2C1));
r &= ~MCFINTC2_INTPRI_BITS(0xf, MCF_IRQ_I2C1);
r |= MCFINTC2_INTPRI_BITS(0x5, MCF_IRQ_I2C1);
writel(r, MCFINTC2_INTPRI_REG(MCF_IRQ_I2C1));
#endif
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
m525x_qspi_init();
m525x_i2c_init();
}
