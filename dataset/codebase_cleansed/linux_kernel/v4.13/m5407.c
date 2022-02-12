static void __init m5407_i2c_init(void)
{
#if IS_ENABLED(CONFIG_I2C_IMX)
writeb(MCFSIM_ICR_AUTOVEC | MCFSIM_ICR_LEVEL5 | MCFSIM_ICR_PRI0,
MCFSIM_I2CICR);
mcf_mapirq2imr(MCF_IRQ_I2C0, MCFINTC_I2C);
#endif
}
void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
mcf_mapirq2imr(25, MCFINTC_EINT1);
mcf_mapirq2imr(27, MCFINTC_EINT3);
mcf_mapirq2imr(29, MCFINTC_EINT5);
mcf_mapirq2imr(31, MCFINTC_EINT7);
m5407_i2c_init();
}
