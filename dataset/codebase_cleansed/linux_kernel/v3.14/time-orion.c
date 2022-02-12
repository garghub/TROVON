void orion_timer_ctrl_clrset(u32 clr, u32 set)
{
spin_lock(&timer_ctrl_lock);
writel((readl(timer_base + TIMER_CTRL) & ~clr) | set,
timer_base + TIMER_CTRL);
spin_unlock(&timer_ctrl_lock);
}
static u64 notrace orion_read_sched_clock(void)
{
return ~readl(timer_base + TIMER0_VAL);
}
static int orion_clkevt_next_event(unsigned long delta,
struct clock_event_device *dev)
{
writel(delta, timer_base + TIMER1_VAL);
orion_timer_ctrl_clrset(TIMER1_RELOAD_EN, TIMER1_EN);
return 0;
}
static void orion_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *dev)
{
if (mode == CLOCK_EVT_MODE_PERIODIC) {
writel(ticks_per_jiffy - 1, timer_base + TIMER1_RELOAD);
writel(ticks_per_jiffy - 1, timer_base + TIMER1_VAL);
orion_timer_ctrl_clrset(0, TIMER1_RELOAD_EN | TIMER1_EN);
} else {
orion_timer_ctrl_clrset(TIMER1_RELOAD_EN | TIMER1_EN, 0);
}
}
static irqreturn_t orion_clkevt_irq_handler(int irq, void *dev_id)
{
orion_clkevt.event_handler(&orion_clkevt);
return IRQ_HANDLED;
}
static void __init orion_timer_init(struct device_node *np)
{
struct clk *clk;
int irq;
timer_base = of_iomap(np, 0);
if (!timer_base)
panic("%s: unable to map resource\n", np->name);
clk = of_clk_get(np, 0);
if (IS_ERR(clk))
panic("%s: unable to get clk\n", np->name);
clk_prepare_enable(clk);
irq = irq_of_parse_and_map(np, 1);
if (irq <= 0)
panic("%s: unable to parse timer1 irq\n", np->name);
writel(~0, timer_base + TIMER0_VAL);
writel(~0, timer_base + TIMER0_RELOAD);
orion_timer_ctrl_clrset(0, TIMER0_RELOAD_EN | TIMER0_EN);
clocksource_mmio_init(timer_base + TIMER0_VAL, "orion_clocksource",
clk_get_rate(clk), 300, 32,
clocksource_mmio_readl_down);
sched_clock_register(orion_read_sched_clock, 32, clk_get_rate(clk));
if (setup_irq(irq, &orion_clkevt_irq))
panic("%s: unable to setup irq\n", np->name);
ticks_per_jiffy = (clk_get_rate(clk) + HZ/2) / HZ;
orion_clkevt.cpumask = cpumask_of(0);
orion_clkevt.irq = irq;
clockevents_config_and_register(&orion_clkevt, clk_get_rate(clk),
ORION_ONESHOT_MIN, ORION_ONESHOT_MAX);
}
