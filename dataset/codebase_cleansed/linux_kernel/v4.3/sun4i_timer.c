static void sun4i_clkevt_sync(void)
{
u32 old = readl(timer_base + TIMER_CNTVAL_REG(1));
while ((old - readl(timer_base + TIMER_CNTVAL_REG(1))) < TIMER_SYNC_TICKS)
cpu_relax();
}
static void sun4i_clkevt_time_stop(u8 timer)
{
u32 val = readl(timer_base + TIMER_CTL_REG(timer));
writel(val & ~TIMER_CTL_ENABLE, timer_base + TIMER_CTL_REG(timer));
sun4i_clkevt_sync();
}
static void sun4i_clkevt_time_setup(u8 timer, unsigned long delay)
{
writel(delay, timer_base + TIMER_INTVAL_REG(timer));
}
static void sun4i_clkevt_time_start(u8 timer, bool periodic)
{
u32 val = readl(timer_base + TIMER_CTL_REG(timer));
if (periodic)
val &= ~TIMER_CTL_ONESHOT;
else
val |= TIMER_CTL_ONESHOT;
writel(val | TIMER_CTL_ENABLE | TIMER_CTL_RELOAD,
timer_base + TIMER_CTL_REG(timer));
}
static int sun4i_clkevt_shutdown(struct clock_event_device *evt)
{
sun4i_clkevt_time_stop(0);
return 0;
}
static int sun4i_clkevt_set_oneshot(struct clock_event_device *evt)
{
sun4i_clkevt_time_stop(0);
sun4i_clkevt_time_start(0, false);
return 0;
}
static int sun4i_clkevt_set_periodic(struct clock_event_device *evt)
{
sun4i_clkevt_time_stop(0);
sun4i_clkevt_time_setup(0, ticks_per_jiffy);
sun4i_clkevt_time_start(0, true);
return 0;
}
static int sun4i_clkevt_next_event(unsigned long evt,
struct clock_event_device *unused)
{
sun4i_clkevt_time_stop(0);
sun4i_clkevt_time_setup(0, evt - TIMER_SYNC_TICKS);
sun4i_clkevt_time_start(0, false);
return 0;
}
static irqreturn_t sun4i_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = (struct clock_event_device *)dev_id;
writel(0x1, timer_base + TIMER_IRQ_ST_REG);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static u64 notrace sun4i_timer_sched_read(void)
{
return ~readl(timer_base + TIMER_CNTVAL_REG(1));
}
static void __init sun4i_timer_init(struct device_node *node)
{
unsigned long rate = 0;
struct clk *clk;
int ret, irq;
u32 val;
timer_base = of_iomap(node, 0);
if (!timer_base)
panic("Can't map registers");
irq = irq_of_parse_and_map(node, 0);
if (irq <= 0)
panic("Can't parse IRQ");
clk = of_clk_get(node, 0);
if (IS_ERR(clk))
panic("Can't get timer clock");
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
writel(~0, timer_base + TIMER_INTVAL_REG(1));
writel(TIMER_CTL_ENABLE | TIMER_CTL_RELOAD |
TIMER_CTL_CLK_SRC(TIMER_CTL_CLK_SRC_OSC24M),
timer_base + TIMER_CTL_REG(1));
if (of_machine_is_compatible("allwinner,sun4i-a10") ||
of_machine_is_compatible("allwinner,sun5i-a13") ||
of_machine_is_compatible("allwinner,sun5i-a10s"))
sched_clock_register(sun4i_timer_sched_read, 32, rate);
clocksource_mmio_init(timer_base + TIMER_CNTVAL_REG(1), node->name,
rate, 350, 32, clocksource_mmio_readl_down);
ticks_per_jiffy = DIV_ROUND_UP(rate, HZ);
writel(TIMER_CTL_CLK_SRC(TIMER_CTL_CLK_SRC_OSC24M),
timer_base + TIMER_CTL_REG(0));
sun4i_clkevt_time_stop(0);
sun4i_clockevent.cpumask = cpu_possible_mask;
sun4i_clockevent.irq = irq;
clockevents_config_and_register(&sun4i_clockevent, rate,
TIMER_SYNC_TICKS, 0xffffffff);
ret = setup_irq(irq, &sun4i_timer_irq);
if (ret)
pr_warn("failed to setup irq %d\n", irq);
val = readl(timer_base + TIMER_IRQ_EN_REG);
writel(val | TIMER_IRQ_EN(0), timer_base + TIMER_IRQ_EN_REG);
}
