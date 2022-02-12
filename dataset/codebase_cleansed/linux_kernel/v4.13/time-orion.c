static unsigned long notrace orion_read_timer(void)
{
return ~readl(timer_base + TIMER0_VAL);
}
static void orion_delay_timer_init(unsigned long rate)
{
orion_delay_timer.freq = rate;
register_current_timer_delay(&orion_delay_timer);
}
static u64 notrace orion_read_sched_clock(void)
{
return ~readl(timer_base + TIMER0_VAL);
}
static int orion_clkevt_next_event(unsigned long delta,
struct clock_event_device *dev)
{
writel(delta, timer_base + TIMER1_VAL);
atomic_io_modify(timer_base + TIMER_CTRL,
TIMER1_RELOAD_EN | TIMER1_EN, TIMER1_EN);
return 0;
}
static int orion_clkevt_shutdown(struct clock_event_device *dev)
{
atomic_io_modify(timer_base + TIMER_CTRL,
TIMER1_RELOAD_EN | TIMER1_EN, 0);
return 0;
}
static int orion_clkevt_set_periodic(struct clock_event_device *dev)
{
writel(ticks_per_jiffy - 1, timer_base + TIMER1_RELOAD);
writel(ticks_per_jiffy - 1, timer_base + TIMER1_VAL);
atomic_io_modify(timer_base + TIMER_CTRL,
TIMER1_RELOAD_EN | TIMER1_EN,
TIMER1_RELOAD_EN | TIMER1_EN);
return 0;
}
static irqreturn_t orion_clkevt_irq_handler(int irq, void *dev_id)
{
orion_clkevt.event_handler(&orion_clkevt);
return IRQ_HANDLED;
}
static int __init orion_timer_init(struct device_node *np)
{
unsigned long rate;
struct clk *clk;
int irq, ret;
timer_base = of_iomap(np, 0);
if (!timer_base) {
pr_err("%s: unable to map resource\n", np->name);
return -ENXIO;
}
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_err("%s: unable to get clk\n", np->name);
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("Failed to prepare clock\n");
return ret;
}
irq = irq_of_parse_and_map(np, 1);
if (irq <= 0) {
pr_err("%s: unable to parse timer1 irq\n", np->name);
return -EINVAL;
}
rate = clk_get_rate(clk);
writel(~0, timer_base + TIMER0_VAL);
writel(~0, timer_base + TIMER0_RELOAD);
atomic_io_modify(timer_base + TIMER_CTRL,
TIMER0_RELOAD_EN | TIMER0_EN,
TIMER0_RELOAD_EN | TIMER0_EN);
ret = clocksource_mmio_init(timer_base + TIMER0_VAL,
"orion_clocksource", rate, 300, 32,
clocksource_mmio_readl_down);
if (ret) {
pr_err("Failed to initialize mmio timer\n");
return ret;
}
sched_clock_register(orion_read_sched_clock, 32, rate);
ret = setup_irq(irq, &orion_clkevt_irq);
if (ret) {
pr_err("%s: unable to setup irq\n", np->name);
return ret;
}
ticks_per_jiffy = (clk_get_rate(clk) + HZ/2) / HZ;
orion_clkevt.cpumask = cpumask_of(0);
orion_clkevt.irq = irq;
clockevents_config_and_register(&orion_clkevt, rate,
ORION_ONESHOT_MIN, ORION_ONESHOT_MAX);
orion_delay_timer_init(rate);
return 0;
}
