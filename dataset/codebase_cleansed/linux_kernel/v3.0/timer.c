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
static void vt8500_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
switch (mode) {
case CLOCK_EVT_MODE_RESUME:
case CLOCK_EVT_MODE_PERIODIC:
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
writel(readl(regbase + TIMER_CTRL_VAL) | 1,
regbase + TIMER_CTRL_VAL);
writel(0, regbase + TIMER_IER_VAL);
break;
}
}
static irqreturn_t vt8500_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
writel(0xf, regbase + TIMER_STATUS_VAL);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init vt8500_timer_init(void)
{
regbase = ioremap(wmt_pmc_base + VT8500_TIMER_OFFSET, 0x28);
if (!regbase)
printk(KERN_ERR "vt8500_timer_init: failed to map MMIO registers\n");
writel(1, regbase + TIMER_CTRL_VAL);
writel(0xf, regbase + TIMER_STATUS_VAL);
writel(~0, regbase + TIMER_MATCH_VAL);
if (clocksource_register_hz(&clocksource, VT8500_TIMER_HZ))
printk(KERN_ERR "vt8500_timer_init: clocksource_register failed for %s\n",
clocksource.name);
clockevents_calc_mult_shift(&clockevent, VT8500_TIMER_HZ, 4);
clockevent.max_delta_ns =
clockevent_delta2ns(0xf0000000, &clockevent);
clockevent.min_delta_ns = clockevent_delta2ns(4, &clockevent);
clockevent.cpumask = cpumask_of(0);
if (setup_irq(wmt_timer_irq, &irq))
printk(KERN_ERR "vt8500_timer_init: setup_irq failed for %s\n",
clockevent.name);
clockevents_register_device(&clockevent);
}
