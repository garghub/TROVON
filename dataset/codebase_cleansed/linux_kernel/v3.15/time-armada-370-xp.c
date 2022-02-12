static void local_timer_ctrl_clrset(u32 clr, u32 set)
{
writel((readl(local_base + TIMER_CTRL_OFF) & ~clr) | set,
local_base + TIMER_CTRL_OFF);
}
static u64 notrace armada_370_xp_read_sched_clock(void)
{
return ~readl(timer_base + TIMER0_VAL_OFF);
}
static int
armada_370_xp_clkevt_next_event(unsigned long delta,
struct clock_event_device *dev)
{
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
writel(delta, local_base + TIMER0_VAL_OFF);
local_timer_ctrl_clrset(TIMER0_RELOAD_EN, enable_mask);
return 0;
}
static void
armada_370_xp_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *dev)
{
if (mode == CLOCK_EVT_MODE_PERIODIC) {
writel(ticks_per_jiffy - 1, local_base + TIMER0_RELOAD_OFF);
writel(ticks_per_jiffy - 1, local_base + TIMER0_VAL_OFF);
local_timer_ctrl_clrset(0, TIMER0_RELOAD_EN | enable_mask);
} else {
local_timer_ctrl_clrset(TIMER0_EN, 0);
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
}
}
static irqreturn_t armada_370_xp_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int armada_370_xp_timer_setup(struct clock_event_device *evt)
{
u32 clr = 0, set = 0;
int cpu = smp_processor_id();
if (timer25Mhz)
set = TIMER0_25MHZ;
else
clr = TIMER0_25MHZ;
local_timer_ctrl_clrset(clr, set);
evt->name = "armada_370_xp_per_cpu_tick",
evt->features = CLOCK_EVT_FEAT_ONESHOT |
CLOCK_EVT_FEAT_PERIODIC;
evt->shift = 32,
evt->rating = 300,
evt->set_next_event = armada_370_xp_clkevt_next_event,
evt->set_mode = armada_370_xp_clkevt_mode,
evt->irq = armada_370_xp_clkevt_irq;
evt->cpumask = cpumask_of(cpu);
clockevents_config_and_register(evt, timer_clk, 1, 0xfffffffe);
enable_percpu_irq(evt->irq, 0);
return 0;
}
static void armada_370_xp_timer_stop(struct clock_event_device *evt)
{
evt->set_mode(CLOCK_EVT_MODE_UNUSED, evt);
disable_percpu_irq(evt->irq);
}
static int armada_370_xp_timer_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_STARTING:
armada_370_xp_timer_setup(this_cpu_ptr(armada_370_xp_evt));
break;
case CPU_DYING:
armada_370_xp_timer_stop(this_cpu_ptr(armada_370_xp_evt));
break;
}
return NOTIFY_OK;
}
static void __init armada_370_xp_timer_common_init(struct device_node *np)
{
u32 clr = 0, set = 0;
int res;
timer_base = of_iomap(np, 0);
WARN_ON(!timer_base);
local_base = of_iomap(np, 1);
if (timer25Mhz) {
set = TIMER0_25MHZ;
enable_mask = TIMER0_EN;
} else {
clr = TIMER0_25MHZ;
enable_mask = TIMER0_EN | TIMER0_DIV(TIMER_DIVIDER_SHIFT);
}
atomic_io_modify(timer_base + TIMER_CTRL_OFF, clr | set, set);
local_timer_ctrl_clrset(clr, set);
armada_370_xp_clkevt_irq = irq_of_parse_and_map(np, 4);
ticks_per_jiffy = (timer_clk + HZ / 2) / HZ;
writel(0xffffffff, timer_base + TIMER0_VAL_OFF);
writel(0xffffffff, timer_base + TIMER0_RELOAD_OFF);
atomic_io_modify(timer_base + TIMER_CTRL_OFF,
TIMER0_RELOAD_EN | enable_mask,
TIMER0_RELOAD_EN | enable_mask);
sched_clock_register(armada_370_xp_read_sched_clock, 32, timer_clk);
clocksource_mmio_init(timer_base + TIMER0_VAL_OFF,
"armada_370_xp_clocksource",
timer_clk, 300, 32, clocksource_mmio_readl_down);
register_cpu_notifier(&armada_370_xp_timer_cpu_nb);
armada_370_xp_evt = alloc_percpu(struct clock_event_device);
res = request_percpu_irq(armada_370_xp_clkevt_irq,
armada_370_xp_timer_interrupt,
"armada_370_xp_per_cpu_tick",
armada_370_xp_evt);
if (!res)
armada_370_xp_timer_setup(this_cpu_ptr(armada_370_xp_evt));
}
static void __init armada_xp_timer_init(struct device_node *np)
{
struct clk *clk = of_clk_get_by_name(np, "fixed");
BUG_ON(IS_ERR(clk));
timer_clk = clk_get_rate(clk);
armada_370_xp_timer_common_init(np);
}
static void __init armada_370_timer_init(struct device_node *np)
{
struct clk *clk = of_clk_get(np, 0);
BUG_ON(IS_ERR(clk));
timer_clk = clk_get_rate(clk) / TIMER_DIVIDER;
timer25Mhz = false;
armada_370_xp_timer_common_init(np);
}
