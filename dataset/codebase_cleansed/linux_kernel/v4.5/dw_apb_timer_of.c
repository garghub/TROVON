static void __init timer_get_base_and_rate(struct device_node *np,
void __iomem **base, u32 *rate)
{
struct clk *timer_clk;
struct clk *pclk;
*base = of_iomap(np, 0);
if (!*base)
panic("Unable to map regs for %s", np->name);
pclk = of_clk_get_by_name(np, "pclk");
if (!IS_ERR(pclk))
if (clk_prepare_enable(pclk))
pr_warn("pclk for %s is present, but could not be activated\n",
np->name);
timer_clk = of_clk_get_by_name(np, "timer");
if (IS_ERR(timer_clk))
goto try_clock_freq;
if (!clk_prepare_enable(timer_clk)) {
*rate = clk_get_rate(timer_clk);
return;
}
try_clock_freq:
if (of_property_read_u32(np, "clock-freq", rate) &&
of_property_read_u32(np, "clock-frequency", rate))
panic("No clock nor clock-frequency property for %s", np->name);
}
static void __init add_clockevent(struct device_node *event_timer)
{
void __iomem *iobase;
struct dw_apb_clock_event_device *ced;
u32 irq, rate;
irq = irq_of_parse_and_map(event_timer, 0);
if (irq == 0)
panic("No IRQ for clock event timer");
timer_get_base_and_rate(event_timer, &iobase, &rate);
ced = dw_apb_clockevent_init(0, event_timer->name, 300, iobase, irq,
rate);
if (!ced)
panic("Unable to initialise clockevent device");
dw_apb_clockevent_register(ced);
}
static void __init add_clocksource(struct device_node *source_timer)
{
void __iomem *iobase;
struct dw_apb_clocksource *cs;
u32 rate;
timer_get_base_and_rate(source_timer, &iobase, &rate);
cs = dw_apb_clocksource_init(300, source_timer->name, iobase, rate);
if (!cs)
panic("Unable to initialise clocksource device");
dw_apb_clocksource_start(cs);
dw_apb_clocksource_register(cs);
sched_io_base = iobase + 0x04;
sched_rate = rate;
}
static u64 notrace read_sched_clock(void)
{
return ~readl_relaxed(sched_io_base);
}
static void __init init_sched_clock(void)
{
struct device_node *sched_timer;
sched_timer = of_find_matching_node(NULL, sptimer_ids);
if (sched_timer) {
timer_get_base_and_rate(sched_timer, &sched_io_base,
&sched_rate);
of_node_put(sched_timer);
}
sched_clock_register(read_sched_clock, 32, sched_rate);
}
static unsigned long dw_apb_delay_timer_read(void)
{
return ~readl_relaxed(sched_io_base);
}
static void __init dw_apb_timer_init(struct device_node *timer)
{
switch (num_called) {
case 0:
pr_debug("%s: found clockevent timer\n", __func__);
add_clockevent(timer);
break;
case 1:
pr_debug("%s: found clocksource timer\n", __func__);
add_clocksource(timer);
init_sched_clock();
#ifdef CONFIG_ARM
dw_apb_delay_timer.freq = sched_rate;
register_current_timer_delay(&dw_apb_delay_timer);
#endif
break;
default:
break;
}
num_called++;
}
