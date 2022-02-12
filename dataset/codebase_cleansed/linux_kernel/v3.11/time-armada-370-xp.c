static u32 notrace armada_370_xp_read_sched_clock(void)
{
return ~readl(timer_base + TIMER0_VAL_OFF);
}
static int
armada_370_xp_clkevt_next_event(unsigned long delta,
struct clock_event_device *dev)
{
u32 u;
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
writel(delta, local_base + TIMER0_VAL_OFF);
u = readl(local_base + TIMER_CTRL_OFF);
u = ((u & ~TIMER0_RELOAD_EN) | TIMER0_EN |
TIMER0_DIV(TIMER_DIVIDER_SHIFT));
writel(u, local_base + TIMER_CTRL_OFF);
return 0;
}
static void
armada_370_xp_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *dev)
{
u32 u;
if (mode == CLOCK_EVT_MODE_PERIODIC) {
writel(ticks_per_jiffy - 1, local_base + TIMER0_RELOAD_OFF);
writel(ticks_per_jiffy - 1, local_base + TIMER0_VAL_OFF);
u = readl(local_base + TIMER_CTRL_OFF);
writel((u | TIMER0_EN | TIMER0_RELOAD_EN |
TIMER0_DIV(TIMER_DIVIDER_SHIFT)),
local_base + TIMER_CTRL_OFF);
} else {
u = readl(local_base + TIMER_CTRL_OFF);
writel(u & ~TIMER0_EN, local_base + TIMER_CTRL_OFF);
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
}
}
static irqreturn_t armada_370_xp_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = *(struct clock_event_device **)dev_id;
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int armada_370_xp_timer_setup(struct clock_event_device *evt)
{
u32 u;
int cpu = smp_processor_id();
if (!smp_processor_id())
return 0;
u = readl(local_base + TIMER_CTRL_OFF);
if (timer25Mhz)
writel(u | TIMER0_25MHZ, local_base + TIMER_CTRL_OFF);
else
writel(u & ~TIMER0_25MHZ, local_base + TIMER_CTRL_OFF);
evt->name = armada_370_xp_clkevt.name;
evt->irq = armada_370_xp_clkevt.irq;
evt->features = armada_370_xp_clkevt.features;
evt->shift = armada_370_xp_clkevt.shift;
evt->rating = armada_370_xp_clkevt.rating,
evt->set_next_event = armada_370_xp_clkevt_next_event,
evt->set_mode = armada_370_xp_clkevt_mode,
evt->cpumask = cpumask_of(cpu);
*__this_cpu_ptr(percpu_armada_370_xp_evt) = evt;
clockevents_config_and_register(evt, timer_clk, 1, 0xfffffffe);
enable_percpu_irq(evt->irq, 0);
return 0;
}
static void armada_370_xp_timer_stop(struct clock_event_device *evt)
{
evt->set_mode(CLOCK_EVT_MODE_UNUSED, evt);
disable_percpu_irq(evt->irq);
}
void __init armada_370_xp_timer_init(void)
{
u32 u;
struct device_node *np;
int res;
np = of_find_compatible_node(NULL, NULL, "marvell,armada-370-xp-timer");
timer_base = of_iomap(np, 0);
WARN_ON(!timer_base);
local_base = of_iomap(np, 1);
if (of_find_property(np, "marvell,timer-25Mhz", NULL)) {
u = readl(local_base + TIMER_CTRL_OFF);
writel(u | TIMER0_25MHZ,
local_base + TIMER_CTRL_OFF);
u = readl(timer_base + TIMER_CTRL_OFF);
writel(u | TIMER0_25MHZ,
timer_base + TIMER_CTRL_OFF);
timer_clk = 25000000;
} else {
unsigned long rate = 0;
struct clk *clk = of_clk_get(np, 0);
WARN_ON(IS_ERR(clk));
rate = clk_get_rate(clk);
u = readl(local_base + TIMER_CTRL_OFF);
writel(u & ~(TIMER0_25MHZ),
local_base + TIMER_CTRL_OFF);
u = readl(timer_base + TIMER_CTRL_OFF);
writel(u & ~(TIMER0_25MHZ),
timer_base + TIMER_CTRL_OFF);
timer_clk = rate / TIMER_DIVIDER;
timer25Mhz = false;
}
armada_370_xp_clkevt.irq = irq_of_parse_and_map(np, 4);
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
armada_370_xp_clkevt.cpumask = cpumask_of(0);
clockevents_config_and_register(&armada_370_xp_clkevt,
timer_clk, 1, 0xfffffffe);
percpu_armada_370_xp_evt = alloc_percpu(struct clock_event_device *);
*__this_cpu_ptr(percpu_armada_370_xp_evt) = &armada_370_xp_clkevt;
res = request_percpu_irq(armada_370_xp_clkevt.irq,
armada_370_xp_timer_interrupt,
armada_370_xp_clkevt.name,
percpu_armada_370_xp_evt);
if (!res) {
enable_percpu_irq(armada_370_xp_clkevt.irq, 0);
#ifdef CONFIG_LOCAL_TIMERS
local_timer_register(&armada_370_xp_local_timer_ops);
#endif
}
}
