static u64 notrace nomadik_read_sched_clock(void)
{
if (unlikely(!mtu_base))
return 0;
return -readl(mtu_base + MTU_VAL(0));
}
static unsigned long nmdk_timer_read_current_timer(void)
{
return ~readl_relaxed(mtu_base + MTU_VAL(0));
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
static void nmdk_clkevt_reset(void)
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
static int nmdk_clkevt_shutdown(struct clock_event_device *evt)
{
writel(0, mtu_base + MTU_IMSC);
writel(0, mtu_base + MTU_CR(1));
writel(0xffffffff, mtu_base + MTU_LR(1));
return 0;
}
static int nmdk_clkevt_set_oneshot(struct clock_event_device *evt)
{
clkevt_periodic = false;
return 0;
}
static int nmdk_clkevt_set_periodic(struct clock_event_device *evt)
{
clkevt_periodic = true;
nmdk_clkevt_reset();
return 0;
}
static void nmdk_clksrc_reset(void)
{
writel(0, mtu_base + MTU_CR(0));
writel(nmdk_cycle, mtu_base + MTU_LR(0));
writel(nmdk_cycle, mtu_base + MTU_BGLR(0));
writel(clk_prescale | MTU_CRn_32BITS | MTU_CRn_ENA,
mtu_base + MTU_CR(0));
}
static void nmdk_clkevt_resume(struct clock_event_device *cedev)
{
nmdk_clkevt_reset();
nmdk_clksrc_reset();
}
static irqreturn_t nmdk_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evdev = dev_id;
writel(1 << 1, mtu_base + MTU_ICR);
evdev->event_handler(evdev);
return IRQ_HANDLED;
}
static void __init nmdk_timer_init(void __iomem *base, int irq,
struct clk *pclk, struct clk *clk)
{
unsigned long rate;
mtu_base = base;
BUG_ON(clk_prepare_enable(pclk));
BUG_ON(clk_prepare_enable(clk));
rate = clk_get_rate(clk);
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
#ifdef CONFIG_CLKSRC_NOMADIK_MTU_SCHED_CLOCK
sched_clock_register(nomadik_read_sched_clock, 32, rate);
#endif
setup_irq(irq, &nmdk_timer_irq);
nmdk_clkevt.cpumask = cpumask_of(0);
nmdk_clkevt.irq = irq;
clockevents_config_and_register(&nmdk_clkevt, rate, 2, 0xffffffffU);
mtu_delay_timer.read_current_timer = &nmdk_timer_read_current_timer;
mtu_delay_timer.freq = rate;
register_current_timer_delay(&mtu_delay_timer);
}
static void __init nmdk_timer_of_init(struct device_node *node)
{
struct clk *pclk;
struct clk *clk;
void __iomem *base;
int irq;
base = of_iomap(node, 0);
if (!base)
panic("Can't remap registers");
pclk = of_clk_get_by_name(node, "apb_pclk");
if (IS_ERR(pclk))
panic("could not get apb_pclk");
clk = of_clk_get_by_name(node, "timclk");
if (IS_ERR(clk))
panic("could not get timclk");
irq = irq_of_parse_and_map(node, 0);
if (irq <= 0)
panic("Can't parse IRQ");
nmdk_timer_init(base, irq, pclk, clk);
}
