static void timer64_config(unsigned long period)
{
u32 tcr = soc_readl(&timer->tcr) & ~TCR_ENAMODELO_MASK;
soc_writel(tcr, &timer->tcr);
soc_writel(period - 1, &timer->prdlo);
soc_writel(0, &timer->cntlo);
tcr |= timer64_mode;
soc_writel(tcr, &timer->tcr);
}
static void timer64_enable(void)
{
u32 val;
if (timer64_devstate_id >= 0)
dscr_set_devstate(timer64_devstate_id, DSCR_DEVSTATE_ENABLED);
soc_writel(soc_readl(&timer->tcr) & ~TCR_ENAMODELO_MASK, &timer->tcr);
soc_writel(0, &timer->prdlo);
val = soc_readl(&timer->tcr);
soc_writel(val & ~(TCR_CLKSRCLO | TCR_PWIDLO_MASK), &timer->tcr);
val = soc_readl(&timer->tgcr) & ~TGCR_TIMMODE_MASK;
soc_writel(val, &timer->tgcr);
soc_writel(val | (TGCR_TIMLORS | TGCR_TIMMODE_UD32), &timer->tgcr);
}
static void timer64_disable(void)
{
soc_writel(soc_readl(&timer->tcr) & ~TCR_ENAMODELO_MASK, &timer->tcr);
soc_writel(0, &timer->prdlo);
if (timer64_devstate_id >= 0)
dscr_set_devstate(timer64_devstate_id, DSCR_DEVSTATE_DISABLED);
}
static int next_event(unsigned long delta,
struct clock_event_device *evt)
{
timer64_config(delta);
return 0;
}
static void set_clock_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
timer64_enable();
timer64_mode = TIMER64_MODE_PERIODIC;
timer64_config(TIMER64_RATE / HZ);
break;
case CLOCK_EVT_MODE_ONESHOT:
timer64_enable();
timer64_mode = TIMER64_MODE_ONE_SHOT;
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
timer64_mode = TIMER64_MODE_DISABLED;
timer64_disable();
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *cd = &t64_clockevent_device;
cd->event_handler(cd);
return IRQ_HANDLED;
}
void __init timer64_init(void)
{
struct clock_event_device *cd = &t64_clockevent_device;
struct device_node *np, *first = NULL;
u32 val;
int err, found = 0;
for_each_compatible_node(np, NULL, "ti,c64x+timer64") {
err = of_property_read_u32(np, "ti,core-mask", &val);
if (!err) {
if (val & (1 << get_coreid())) {
found = 1;
break;
}
} else if (!first)
first = np;
}
if (!found) {
if (first)
np = of_node_get(first);
else {
pr_debug("Cannot find ti,c64x+timer64 timer.\n");
return;
}
}
timer = of_iomap(np, 0);
if (!timer) {
pr_debug("%s: Cannot map timer registers.\n", np->full_name);
goto out;
}
pr_debug("%s: Timer registers=%p.\n", np->full_name, timer);
cd->irq = irq_of_parse_and_map(np, 0);
if (cd->irq == NO_IRQ) {
pr_debug("%s: Cannot find interrupt.\n", np->full_name);
iounmap(timer);
goto out;
}
err = of_property_read_u32(np, "ti,dscr-dev-enable", &val);
if (!err) {
timer64_devstate_id = val;
dscr_set_devstate(timer64_devstate_id, DSCR_DEVSTATE_ENABLED);
}
pr_debug("%s: Timer irq=%d.\n", np->full_name, cd->irq);
clockevents_calc_mult_shift(cd, c6x_core_freq / TIMER_DIVISOR, 5);
cd->max_delta_ns = clockevent_delta2ns(0x7fffffff, cd);
cd->min_delta_ns = clockevent_delta2ns(250, cd);
cd->cpumask = cpumask_of(smp_processor_id());
clockevents_register_device(cd);
setup_irq(cd->irq, &timer_iact);
out:
of_node_put(np);
return;
}
