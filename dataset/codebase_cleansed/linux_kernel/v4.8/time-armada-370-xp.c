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
static int armada_370_xp_clkevt_shutdown(struct clock_event_device *evt)
{
local_timer_ctrl_clrset(TIMER0_EN, 0);
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
return 0;
}
static int armada_370_xp_clkevt_set_periodic(struct clock_event_device *evt)
{
writel(ticks_per_jiffy - 1, local_base + TIMER0_RELOAD_OFF);
writel(ticks_per_jiffy - 1, local_base + TIMER0_VAL_OFF);
local_timer_ctrl_clrset(0, TIMER0_RELOAD_EN | enable_mask);
return 0;
}
static irqreturn_t armada_370_xp_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
writel(TIMER0_CLR_MASK, local_base + LCL_TIMER_EVENTS_STATUS);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int armada_370_xp_timer_starting_cpu(unsigned int cpu)
{
struct clock_event_device *evt = per_cpu_ptr(armada_370_xp_evt, cpu);
u32 clr = 0, set = 0;
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
evt->set_state_shutdown = armada_370_xp_clkevt_shutdown;
evt->set_state_periodic = armada_370_xp_clkevt_set_periodic;
evt->set_state_oneshot = armada_370_xp_clkevt_shutdown;
evt->tick_resume = armada_370_xp_clkevt_shutdown;
evt->irq = armada_370_xp_clkevt_irq;
evt->cpumask = cpumask_of(cpu);
clockevents_config_and_register(evt, timer_clk, 1, 0xfffffffe);
enable_percpu_irq(evt->irq, 0);
return 0;
}
static int armada_370_xp_timer_dying_cpu(unsigned int cpu)
{
struct clock_event_device *evt = per_cpu_ptr(armada_370_xp_evt, cpu);
evt->set_state_shutdown(evt);
disable_percpu_irq(evt->irq);
return 0;
}
static int armada_370_xp_timer_suspend(void)
{
timer0_ctrl_reg = readl(timer_base + TIMER_CTRL_OFF);
timer0_local_ctrl_reg = readl(local_base + TIMER_CTRL_OFF);
return 0;
}
static void armada_370_xp_timer_resume(void)
{
writel(0xffffffff, timer_base + TIMER0_VAL_OFF);
writel(0xffffffff, timer_base + TIMER0_RELOAD_OFF);
writel(timer0_ctrl_reg, timer_base + TIMER_CTRL_OFF);
writel(timer0_local_ctrl_reg, local_base + TIMER_CTRL_OFF);
}
static unsigned long armada_370_delay_timer_read(void)
{
return ~readl(timer_base + TIMER0_VAL_OFF);
}
static int __init armada_370_xp_timer_common_init(struct device_node *np)
{
u32 clr = 0, set = 0;
int res;
timer_base = of_iomap(np, 0);
if (!timer_base) {
pr_err("Failed to iomap");
return -ENXIO;
}
local_base = of_iomap(np, 1);
if (!local_base) {
pr_err("Failed to iomap");
return -ENXIO;
}
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
armada_370_delay_timer.freq = timer_clk;
register_current_timer_delay(&armada_370_delay_timer);
sched_clock_register(armada_370_xp_read_sched_clock, 32, timer_clk);
res = clocksource_mmio_init(timer_base + TIMER0_VAL_OFF,
"armada_370_xp_clocksource",
timer_clk, 300, 32, clocksource_mmio_readl_down);
if (res) {
pr_err("Failed to initialize clocksource mmio");
return res;
}
armada_370_xp_evt = alloc_percpu(struct clock_event_device);
if (!armada_370_xp_evt)
return -ENOMEM;
res = request_percpu_irq(armada_370_xp_clkevt_irq,
armada_370_xp_timer_interrupt,
"armada_370_xp_per_cpu_tick",
armada_370_xp_evt);
if (res) {
pr_err("Failed to request percpu irq");
return res;
}
res = cpuhp_setup_state(CPUHP_AP_ARMADA_TIMER_STARTING,
"AP_ARMADA_TIMER_STARTING",
armada_370_xp_timer_starting_cpu,
armada_370_xp_timer_dying_cpu);
if (res) {
pr_err("Failed to setup hotplug state and timer");
return res;
}
register_syscore_ops(&armada_370_xp_timer_syscore_ops);
return 0;
}
static int __init armada_xp_timer_init(struct device_node *np)
{
struct clk *clk = of_clk_get_by_name(np, "fixed");
int ret;
if (IS_ERR(clk)) {
pr_err("Failed to get clock");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret)
return ret;
timer_clk = clk_get_rate(clk);
return armada_370_xp_timer_common_init(np);
}
static int __init armada_375_timer_init(struct device_node *np)
{
struct clk *clk;
int ret;
clk = of_clk_get_by_name(np, "fixed");
if (!IS_ERR(clk)) {
ret = clk_prepare_enable(clk);
if (ret)
return ret;
timer_clk = clk_get_rate(clk);
} else {
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_err("Failed to get clock");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret)
return ret;
timer_clk = clk_get_rate(clk) / TIMER_DIVIDER;
timer25Mhz = false;
}
return armada_370_xp_timer_common_init(np);
}
static int __init armada_370_timer_init(struct device_node *np)
{
struct clk *clk;
int ret;
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_err("Failed to get clock");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret)
return ret;
timer_clk = clk_get_rate(clk) / TIMER_DIVIDER;
timer25Mhz = false;
return armada_370_xp_timer_common_init(np);
}
