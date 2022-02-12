static int tegra_timer_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
u32 reg;
reg = 0x80000000 | ((cycles > 1) ? (cycles-1) : 0);
timer_writel(reg, TIMER3_BASE + TIMER_PTV);
return 0;
}
static void tegra_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
u32 reg;
timer_writel(0, TIMER3_BASE + TIMER_PTV);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
reg = 0xC0000000 | ((1000000/HZ)-1);
timer_writel(reg, TIMER3_BASE + TIMER_PTV);
break;
case CLOCK_EVT_MODE_ONESHOT:
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static u32 notrace tegra_read_sched_clock(void)
{
return timer_readl(TIMERUS_CNTR_1US);
}
static u64 tegra_rtc_read_ms(void)
{
u32 ms = readl(rtc_base + RTC_MILLISECONDS);
u32 s = readl(rtc_base + RTC_SHADOW_SECONDS);
return (u64)s * MSEC_PER_SEC + ms;
}
static void tegra_read_persistent_clock(struct timespec *ts)
{
u64 delta;
struct timespec *tsp = &persistent_ts;
last_persistent_ms = persistent_ms;
persistent_ms = tegra_rtc_read_ms();
delta = persistent_ms - last_persistent_ms;
timespec_add_ns(tsp, delta * NSEC_PER_MSEC);
*ts = *tsp;
}
static irqreturn_t tegra_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = (struct clock_event_device *)dev_id;
timer_writel(1<<30, TIMER3_BASE + TIMER_PCR);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init tegra20_init_timer(void)
{
struct device_node *np;
struct clk *clk;
unsigned long rate;
int ret;
np = of_find_matching_node(NULL, timer_match);
if (!np) {
pr_err("Failed to find timer DT node\n");
BUG();
}
timer_reg_base = of_iomap(np, 0);
if (!timer_reg_base) {
pr_err("Can't map timer registers\n");
BUG();
}
tegra_timer_irq.irq = irq_of_parse_and_map(np, 2);
if (tegra_timer_irq.irq <= 0) {
pr_err("Failed to map timer IRQ\n");
BUG();
}
clk = clk_get_sys("timer", NULL);
if (IS_ERR(clk)) {
pr_warn("Unable to get timer clock. Assuming 12Mhz input clock.\n");
rate = 12000000;
} else {
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
}
of_node_put(np);
np = of_find_matching_node(NULL, rtc_match);
if (!np) {
pr_err("Failed to find RTC DT node\n");
BUG();
}
rtc_base = of_iomap(np, 0);
if (!rtc_base) {
pr_err("Can't map RTC registers");
BUG();
}
clk = clk_get_sys("rtc-tegra", NULL);
if (IS_ERR(clk))
pr_warn("Unable to get rtc-tegra clock\n");
else
clk_prepare_enable(clk);
of_node_put(np);
switch (rate) {
case 12000000:
timer_writel(0x000b, TIMERUS_USEC_CFG);
break;
case 13000000:
timer_writel(0x000c, TIMERUS_USEC_CFG);
break;
case 19200000:
timer_writel(0x045f, TIMERUS_USEC_CFG);
break;
case 26000000:
timer_writel(0x0019, TIMERUS_USEC_CFG);
break;
default:
WARN(1, "Unknown clock rate");
}
setup_sched_clock(tegra_read_sched_clock, 32, 1000000);
if (clocksource_mmio_init(timer_reg_base + TIMERUS_CNTR_1US,
"timer_us", 1000000, 300, 32, clocksource_mmio_readl_up)) {
pr_err("Failed to register clocksource\n");
BUG();
}
ret = setup_irq(tegra_timer_irq.irq, &tegra_timer_irq);
if (ret) {
pr_err("Failed to register timer IRQ: %d\n", ret);
BUG();
}
tegra_clockevent.cpumask = cpu_all_mask;
tegra_clockevent.irq = tegra_timer_irq.irq;
clockevents_config_and_register(&tegra_clockevent, 1000000,
0x1, 0x1fffffff);
#ifdef CONFIG_HAVE_ARM_TWD
twd_local_timer_of_register();
#endif
register_persistent_clock(NULL, tegra_read_persistent_clock);
}
void tegra_timer_suspend(void)
{
usec_config = timer_readl(TIMERUS_USEC_CFG);
}
void tegra_timer_resume(void)
{
timer_writel(usec_config, TIMERUS_USEC_CFG);
}
