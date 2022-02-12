void __init pxa910_init_irq(void)
{
icu_init_irq();
}
static int __init pxa910_init(void)
{
if (cpu_is_pxa910()) {
#ifdef CONFIG_CACHE_TAUROS2
tauros2_init(0);
#endif
mfp_init_base(MFPR_VIRT_BASE);
mfp_init_addr(pxa910_mfp_addr_map);
pxa_init_dma(IRQ_PXA910_DMA_INT0, 32);
pxa910_clk_init();
}
return 0;
}
static void __init pxa910_timer_init(void)
{
__raw_writel(APBC_APBCLK | APBC_RST, APBC_TIMERS);
__raw_writel(TIMER_CLK_RST, APBC_TIMERS);
timer_init(IRQ_PXA910_AP1_TIMER1);
}
