static void __init m54xx_uarts_init(void)
{
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD, MCFGPIO_PAR_PSC0);
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD | MCF_PAR_PSC_RTS_RTS,
MCFGPIO_PAR_PSC1);
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD | MCF_PAR_PSC_RTS_RTS |
MCF_PAR_PSC_CTS_CTS, MCFGPIO_PAR_PSC2);
__raw_writeb(MCF_PAR_PSC_TXD | MCF_PAR_PSC_RXD, MCFGPIO_PAR_PSC3);
}
static void mcf54xx_reset(void)
{
asm("movew #0x2700, %sr\n");
__raw_writel(0, MCF_GPT_GMS0);
__raw_writel(MCF_GPT_GCIR_CNT(1), MCF_GPT_GCIR0);
__raw_writel(MCF_GPT_GMS_WDEN | MCF_GPT_GMS_CE | MCF_GPT_GMS_TMS(4),
MCF_GPT_GMS0);
}
void __init config_BSP(char *commandp, int size)
{
#ifdef CONFIG_MMU
cf_bootmem_alloc();
mmu_context_init();
#endif
mach_reset = mcf54xx_reset;
mach_sched_init = hw_timer_init;
m54xx_uarts_init();
}
