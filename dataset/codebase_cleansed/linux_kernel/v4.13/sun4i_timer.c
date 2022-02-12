static void sun4i_clkevt_sync(void __iomem *base)
{
u32 old = readl(base + TIMER_CNTVAL_REG(1));
while ((old - readl(base + TIMER_CNTVAL_REG(1))) < TIMER_SYNC_TICKS)
cpu_relax();
}
static void sun4i_clkevt_time_stop(void __iomem *base, u8 timer)
{
u32 val = readl(base + TIMER_CTL_REG(timer));
writel(val & ~TIMER_CTL_ENABLE, base + TIMER_CTL_REG(timer));
sun4i_clkevt_sync(base);
}
static void sun4i_clkevt_time_setup(void __iomem *base, u8 timer,
unsigned long delay)
{
writel(delay, base + TIMER_INTVAL_REG(timer));
}
static void sun4i_clkevt_time_start(void __iomem *base, u8 timer,
bool periodic)
{
u32 val = readl(base + TIMER_CTL_REG(timer));
if (periodic)
val &= ~TIMER_CTL_ONESHOT;
else
val |= TIMER_CTL_ONESHOT;
writel(val | TIMER_CTL_ENABLE | TIMER_CTL_RELOAD,
base + TIMER_CTL_REG(timer));
}
static int sun4i_clkevt_shutdown(struct clock_event_device *evt)
{
struct timer_of *to = to_timer_of(evt);
sun4i_clkevt_time_stop(timer_of_base(to), 0);
return 0;
}
static int sun4i_clkevt_set_oneshot(struct clock_event_device *evt)
{
struct timer_of *to = to_timer_of(evt);
sun4i_clkevt_time_stop(timer_of_base(to), 0);
sun4i_clkevt_time_start(timer_of_base(to), 0, false);
return 0;
}
static int sun4i_clkevt_set_periodic(struct clock_event_device *evt)
{
struct timer_of *to = to_timer_of(evt);
sun4i_clkevt_time_stop(timer_of_base(to), 0);
sun4i_clkevt_time_setup(timer_of_base(to), 0, timer_of_period(to));
sun4i_clkevt_time_start(timer_of_base(to), 0, true);
return 0;
}
static int sun4i_clkevt_next_event(unsigned long evt,
struct clock_event_device *clkevt)
{
struct timer_of *to = to_timer_of(clkevt);
sun4i_clkevt_time_stop(timer_of_base(to), 0);
sun4i_clkevt_time_setup(timer_of_base(to), 0, evt - TIMER_SYNC_TICKS);
sun4i_clkevt_time_start(timer_of_base(to), 0, false);
return 0;
}
static void sun4i_timer_clear_interrupt(void __iomem *base)
{
writel(TIMER_IRQ_EN(0), base + TIMER_IRQ_ST_REG);
}
static irqreturn_t sun4i_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = (struct clock_event_device *)dev_id;
struct timer_of *to = to_timer_of(evt);
sun4i_timer_clear_interrupt(timer_of_base(to));
evt->event_handler(evt);
return IRQ_HANDLED;
}
static u64 notrace sun4i_timer_sched_read(void)
{
return ~readl(timer_of_base(&to) + TIMER_CNTVAL_REG(1));
}
static int __init sun4i_timer_init(struct device_node *node)
{
int ret;
u32 val;
ret = timer_of_init(node, &to);
if (ret)
return ret;
writel(~0, timer_of_base(&to) + TIMER_INTVAL_REG(1));
writel(TIMER_CTL_ENABLE | TIMER_CTL_RELOAD |
TIMER_CTL_CLK_SRC(TIMER_CTL_CLK_SRC_OSC24M),
timer_of_base(&to) + TIMER_CTL_REG(1));
if (of_machine_is_compatible("allwinner,sun4i-a10") ||
of_machine_is_compatible("allwinner,sun5i-a13") ||
of_machine_is_compatible("allwinner,sun5i-a10s"))
sched_clock_register(sun4i_timer_sched_read, 32,
timer_of_rate(&to));
ret = clocksource_mmio_init(timer_of_base(&to) + TIMER_CNTVAL_REG(1),
node->name, timer_of_rate(&to), 350, 32,
clocksource_mmio_readl_down);
if (ret) {
pr_err("Failed to register clocksource\n");
return ret;
}
writel(TIMER_CTL_CLK_SRC(TIMER_CTL_CLK_SRC_OSC24M),
timer_of_base(&to) + TIMER_CTL_REG(0));
sun4i_clkevt_time_stop(timer_of_base(&to), 0);
sun4i_timer_clear_interrupt(timer_of_base(&to));
clockevents_config_and_register(&to.clkevt, timer_of_rate(&to),
TIMER_SYNC_TICKS, 0xffffffff);
val = readl(timer_of_base(&to) + TIMER_IRQ_EN_REG);
writel(val | TIMER_IRQ_EN(0), timer_of_base(&to) + TIMER_IRQ_EN_REG);
return ret;
}
