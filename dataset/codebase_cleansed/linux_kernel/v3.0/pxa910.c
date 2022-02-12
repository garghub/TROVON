static void __init pxa910_init_gpio(void)
{
int i;
__raw_writel(APBC_APBCLK | APBC_FNCLK, APBC_PXA910_GPIO);
for (i = 0; i < 4; i++)
__raw_writel(0xffffffff, APMASK(i));
pxa_init_gpio(IRQ_PXA910_AP_GPIO, 0, 127, NULL);
}
void __init pxa910_init_irq(void)
{
icu_init_irq();
pxa910_init_gpio();
}
static int __init pxa910_init(void)
{
if (cpu_is_pxa910()) {
mfp_init_base(MFPR_VIRT_BASE);
mfp_init_addr(pxa910_mfp_addr_map);
pxa_init_dma(IRQ_PXA910_DMA_INT0, 32);
clkdev_add_table(ARRAY_AND_SIZE(pxa910_clkregs));
}
return 0;
}
static void __init pxa910_timer_init(void)
{
__raw_writel(APBC_APBCLK | APBC_RST, APBC_PXA910_TIMERS);
__raw_writel(TIMER_CLK_RST, APBC_PXA910_TIMERS);
timer_init(IRQ_PXA910_AP1_TIMER1);
}
