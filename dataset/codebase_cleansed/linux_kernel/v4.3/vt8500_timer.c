static cycle_t vt8500_timer_read(struct clocksource *cs)
{
int loops = msecs_to_loops(10);
writel(3, regbase + TIMER_CTRL_VAL);
while ((readl((regbase + TIMER_AS_VAL)) & TIMER_COUNT_R_ACTIVE)
&& --loops)
cpu_relax();
return readl(regbase + TIMER_COUNT_VAL);
}
static int vt8500_timer_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
int loops = msecs_to_loops(10);
cycle_t alarm = clocksource.read(&clocksource) + cycles;
while ((readl(regbase + TIMER_AS_VAL) & TIMER_MATCH_W_ACTIVE)
&& --loops)
cpu_relax();
writel((unsigned long)alarm, regbase + TIMER_MATCH_VAL);
if ((signed)(alarm - clocksource.read(&clocksource)) <= 16)
return -ETIME;
writel(1, regbase + TIMER_IER_VAL);
return 0;
}
static int vt8500_shutdown(struct clock_event_device *evt)
{
writel(readl(regbase + TIMER_CTRL_VAL) | 1, regbase + TIMER_CTRL_VAL);
writel(0, regbase + TIMER_IER_VAL);
return 0;
}
static irqreturn_t vt8500_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
writel(0xf, regbase + TIMER_STATUS_VAL);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init vt8500_timer_init(struct device_node *np)
{
int timer_irq;
regbase = of_iomap(np, 0);
if (!regbase) {
pr_err("%s: Missing iobase description in Device Tree\n",
__func__);
return;
}
timer_irq = irq_of_parse_and_map(np, 0);
if (!timer_irq) {
pr_err("%s: Missing irq description in Device Tree\n",
__func__);
return;
}
writel(1, regbase + TIMER_CTRL_VAL);
writel(0xf, regbase + TIMER_STATUS_VAL);
writel(~0, regbase + TIMER_MATCH_VAL);
if (clocksource_register_hz(&clocksource, VT8500_TIMER_HZ))
pr_err("%s: vt8500_timer_init: clocksource_register failed for %s\n",
__func__, clocksource.name);
clockevent.cpumask = cpumask_of(0);
if (setup_irq(timer_irq, &irq))
pr_err("%s: setup_irq failed for %s\n", __func__,
clockevent.name);
clockevents_config_and_register(&clockevent, VT8500_TIMER_HZ,
4, 0xf0000000);
}
