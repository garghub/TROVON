static int tegra_timer_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
u32 reg;
reg = 0x80000000 | ((cycles > 1) ? (cycles-1) : 0);
timer_writel(reg, TIMER3_BASE + TIMER_PTV);
return 0;
}
static inline void timer_shutdown(struct clock_event_device *evt)
{
timer_writel(0, TIMER3_BASE + TIMER_PTV);
}
static int tegra_timer_shutdown(struct clock_event_device *evt)
{
timer_shutdown(evt);
return 0;
}
static int tegra_timer_set_periodic(struct clock_event_device *evt)
{
u32 reg = 0xC0000000 | ((1000000 / HZ) - 1);
timer_shutdown(evt);
timer_writel(reg, TIMER3_BASE + TIMER_PTV);
return 0;
}
static u64 notrace tegra_read_sched_clock(void)
{
return timer_readl(TIMERUS_CNTR_1US);
}
static u64 tegra_rtc_read_ms(void)
{
u32 ms = readl(rtc_base + RTC_MILLISECONDS);
u32 s = readl(rtc_base + RTC_SHADOW_SECONDS);
return (u64)s * MSEC_PER_SEC + ms;
}
static void tegra_read_persistent_clock64(struct timespec64 *ts)
{
u64 delta;
last_persistent_ms = persistent_ms;
persistent_ms = tegra_rtc_read_ms();
delta = persistent_ms - last_persistent_ms;
timespec64_add_ns(&persistent_ts, delta * NSEC_PER_MSEC);
*ts = persistent_ts;
}
static unsigned long tegra_delay_timer_read_counter_long(void)
{
return readl(timer_reg_base + TIMERUS_CNTR_1US);
}
static irqreturn_t tegra_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = (struct clock_event_device *)dev_id;
timer_writel(1<<30, TIMER3_BASE + TIMER_PCR);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init tegra20_init_timer(struct device_node *np)
{
struct clk *clk;
unsigned long rate;
int ret;
timer_reg_base = of_iomap(np, 0);
if (!timer_reg_base) {
pr_err("Can't map timer registers\n");
return -ENXIO;
}
tegra_timer_irq.irq = irq_of_parse_and_map(np, 2);
if (tegra_timer_irq.irq <= 0) {
pr_err("Failed to map timer IRQ\n");
return -EINVAL;
}
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_warn("Unable to get timer clock. Assuming 12Mhz input clock.\n");
rate = 12000000;
} else {
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
}
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
sched_clock_register(tegra_read_sched_clock, 32, 1000000);
ret = clocksource_mmio_init(timer_reg_base + TIMERUS_CNTR_1US,
"timer_us", 1000000, 300, 32,
clocksource_mmio_readl_up);
if (ret) {
pr_err("Failed to register clocksource\n");
return ret;
}
tegra_delay_timer.read_current_timer =
tegra_delay_timer_read_counter_long;
tegra_delay_timer.freq = 1000000;
register_current_timer_delay(&tegra_delay_timer);
ret = setup_irq(tegra_timer_irq.irq, &tegra_timer_irq);
if (ret) {
pr_err("Failed to register timer IRQ: %d\n", ret);
return ret;
}
tegra_clockevent.cpumask = cpu_all_mask;
tegra_clockevent.irq = tegra_timer_irq.irq;
clockevents_config_and_register(&tegra_clockevent, 1000000,
0x1, 0x1fffffff);
return 0;
}
static int __init tegra20_init_rtc(struct device_node *np)
{
struct clk *clk;
rtc_base = of_iomap(np, 0);
if (!rtc_base) {
pr_err("Can't map RTC registers");
return -ENXIO;
}
clk = of_clk_get(np, 0);
if (IS_ERR(clk))
pr_warn("Unable to get rtc-tegra clock\n");
else
clk_prepare_enable(clk);
return register_persistent_clock(NULL, tegra_read_persistent_clock64);
}
