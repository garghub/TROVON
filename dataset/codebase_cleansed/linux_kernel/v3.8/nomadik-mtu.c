static u32 notrace nomadik_read_sched_clock(void)
{
if (unlikely(!mtu_base))
return 0;
return -readl(mtu_base + MTU_VAL(0));
}
static int nmdk_clkevt_next(unsigned long evt, struct clock_event_device *ev)
{
writel(1 << 1, mtu_base + MTU_IMSC);
writel(evt, mtu_base + MTU_LR(1));
writel(MTU_CRn_ONESHOT | clk_prescale |
MTU_CRn_32BITS | MTU_CRn_ENA,
mtu_base + MTU_CR(1));
return 0;
}
void nmdk_clkevt_reset(void)
{
if (clkevt_periodic) {
writel(nmdk_cycle, mtu_base + MTU_LR(1));
writel(nmdk_cycle, mtu_base + MTU_BGLR(1));
writel(MTU_CRn_PERIODIC | clk_prescale |
MTU_CRn_32BITS | MTU_CRn_ENA,
mtu_base + MTU_CR(1));
writel(1 << 1, mtu_base + MTU_IMSC);
} else {
(void) nmdk_clkevt_next(nmdk_cycle, NULL);
}
}
static void nmdk_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *dev)
{
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
clkevt_periodic = true;
nmdk_clkevt_reset();
break;
case CLOCK_EVT_MODE_ONESHOT:
clkevt_periodic = false;
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
writel(0, mtu_base + MTU_IMSC);
writel(0, mtu_base + MTU_CR(1));
writel(0xffffffff, mtu_base + MTU_LR(1));
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static irqreturn_t nmdk_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evdev = dev_id;
writel(1 << 1, mtu_base + MTU_ICR);
evdev->event_handler(evdev);
return IRQ_HANDLED;
}
void nmdk_clksrc_reset(void)
{
writel(0, mtu_base + MTU_CR(0));
writel(nmdk_cycle, mtu_base + MTU_LR(0));
writel(nmdk_cycle, mtu_base + MTU_BGLR(0));
writel(clk_prescale | MTU_CRn_32BITS | MTU_CRn_ENA,
mtu_base + MTU_CR(0));
}
void __init nmdk_timer_init(void __iomem *base, int irq)
{
unsigned long rate;
struct clk *clk0, *pclk0;
mtu_base = base;
pclk0 = clk_get_sys("mtu0", "apb_pclk");
BUG_ON(IS_ERR(pclk0));
BUG_ON(clk_prepare(pclk0) < 0);
BUG_ON(clk_enable(pclk0) < 0);
clk0 = clk_get_sys("mtu0", NULL);
BUG_ON(IS_ERR(clk0));
BUG_ON(clk_prepare(clk0) < 0);
BUG_ON(clk_enable(clk0) < 0);
rate = clk_get_rate(clk0);
if (rate > 32000000) {
rate /= 16;
clk_prescale = MTU_CRn_PRESCALE_16;
} else {
clk_prescale = MTU_CRn_PRESCALE_1;
}
nmdk_cycle = DIV_ROUND_CLOSEST(rate, HZ);
nmdk_clksrc_reset();
if (clocksource_mmio_init(mtu_base + MTU_VAL(0), "mtu_0",
rate, 200, 32, clocksource_mmio_readl_down))
pr_err("timer: failed to initialize clock source %s\n",
"mtu_0");
#ifdef CONFIG_NOMADIK_MTU_SCHED_CLOCK
setup_sched_clock(nomadik_read_sched_clock, 32, rate);
#endif
setup_irq(irq, &nmdk_timer_irq);
nmdk_clkevt.cpumask = cpumask_of(0);
clockevents_config_and_register(&nmdk_clkevt, rate, 2, 0xffffffffU);
}
