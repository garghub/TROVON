static u32 notrace armada_370_xp_read_sched_clock(void)
{
return ~readl(timer_base + TIMER0_VAL_OFF);
}
static int
armada_370_xp_clkevt_next_event(unsigned long delta,
struct clock_event_device *dev)
{
u32 u;
writel(TIMER1_CLR_MASK, timer_base + TIMER_EVENTS_STATUS);
writel(delta, timer_base + TIMER1_VAL_OFF);
u = readl(timer_base + TIMER_CTRL_OFF);
u = ((u & ~TIMER1_RELOAD_EN) | TIMER1_EN |
TIMER1_DIV(TIMER_DIVIDER_SHIFT));
writel(u, timer_base + TIMER_CTRL_OFF);
return 0;
}
static void
armada_370_xp_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *dev)
{
u32 u;
if (mode == CLOCK_EVT_MODE_PERIODIC) {
writel(ticks_per_jiffy - 1, timer_base + TIMER1_RELOAD_OFF);
writel(ticks_per_jiffy - 1, timer_base + TIMER1_VAL_OFF);
u = readl(timer_base + TIMER_CTRL_OFF);
writel((u | TIMER1_EN | TIMER1_RELOAD_EN |
TIMER1_DIV(TIMER_DIVIDER_SHIFT)),
timer_base + TIMER_CTRL_OFF);
} else {
u = readl(timer_base + TIMER_CTRL_OFF);
writel(u & ~TIMER1_EN, timer_base + TIMER_CTRL_OFF);
writel(TIMER1_CLR_MASK, timer_base + TIMER_EVENTS_STATUS);
}
}
static irqreturn_t armada_370_xp_timer_interrupt(int irq, void *dev_id)
{
writel(TIMER1_CLR_MASK, timer_base + TIMER_EVENTS_STATUS);
armada_370_xp_clkevt.event_handler(&armada_370_xp_clkevt);
return IRQ_HANDLED;
}
void __init armada_370_xp_timer_init(void)
{
u32 u;
struct device_node *np;
unsigned int timer_clk;
np = of_find_compatible_node(NULL, NULL, "marvell,armada-370-xp-timer");
timer_base = of_iomap(np, 0);
WARN_ON(!timer_base);
if (of_find_property(np, "marvell,timer-25Mhz", NULL)) {
u = readl(timer_base + TIMER_CTRL_OFF);
writel(u | TIMER0_25MHZ | TIMER1_25MHZ,
timer_base + TIMER_CTRL_OFF);
timer_clk = 25000000;
} else {
unsigned long rate = 0;
struct clk *clk = of_clk_get(np, 0);
WARN_ON(IS_ERR(clk));
rate = clk_get_rate(clk);
u = readl(timer_base + TIMER_CTRL_OFF);
writel(u & ~(TIMER0_25MHZ | TIMER1_25MHZ),
timer_base + TIMER_CTRL_OFF);
timer_clk = rate / TIMER_DIVIDER;
}
timer_irq = irq_of_parse_and_map(np, 1);
ticks_per_jiffy = (timer_clk + HZ / 2) / HZ;
setup_sched_clock(armada_370_xp_read_sched_clock, 32, timer_clk);
writel(0xffffffff, timer_base + TIMER0_VAL_OFF);
writel(0xffffffff, timer_base + TIMER0_RELOAD_OFF);
u = readl(timer_base + TIMER_CTRL_OFF);
writel((u | TIMER0_EN | TIMER0_RELOAD_EN |
TIMER0_DIV(TIMER_DIVIDER_SHIFT)), timer_base + TIMER_CTRL_OFF);
clocksource_mmio_init(timer_base + TIMER0_VAL_OFF,
"armada_370_xp_clocksource",
timer_clk, 300, 32, clocksource_mmio_readl_down);
setup_irq(timer_irq, &armada_370_xp_timer_irq);
armada_370_xp_clkevt.cpumask = cpumask_of(0);
clockevents_config_and_register(&armada_370_xp_clkevt,
timer_clk, 1, 0xfffffffe);
}
