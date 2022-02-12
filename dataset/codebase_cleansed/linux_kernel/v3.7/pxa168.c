void __init pxa168_init_irq(void)
{
icu_init_irq();
}
static int __init pxa168_init(void)
{
if (cpu_is_pxa168()) {
mfp_init_base(MFPR_VIRT_BASE);
mfp_init_addr(pxa168_mfp_addr_map);
pxa_init_dma(IRQ_PXA168_DMA_INT0, 32);
pxa168_clk_init();
}
return 0;
}
static void __init pxa168_timer_init(void)
{
__raw_writel(APBC_APBCLK | APBC_RST, APBC_TIMERS);
__raw_writel(TIMER_CLK_RST, APBC_TIMERS);
timer_init(IRQ_PXA168_TIMER1);
}
void pxa168_clear_keypad_wakeup(void)
{
uint32_t val;
uint32_t mask = APMU_PXA168_KP_WAKE_CLR;
val = __raw_readl(APMU_WAKE_CLR);
__raw_writel(val | mask, APMU_WAKE_CLR);
}
int __init pxa168_add_usb_host(struct mv_usb_platform_data *pdata)
{
pxa168_device_usb_host.dev.platform_data = pdata;
return platform_device_register(&pxa168_device_usb_host);
}
void pxa168_restart(char mode, const char *cmd)
{
soft_restart(0xffff0000);
}
