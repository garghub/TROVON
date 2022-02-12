static u64 notrace pxa_read_sched_clock(void)
{
return timer_readl(OSCR);
}
static irqreturn_t
pxa_ost0_interrupt(int irq, void *dev_id)
{
struct clock_event_device *c = dev_id;
timer_writel(timer_readl(OIER) & ~OIER_E0, OIER);
timer_writel(OSSR_M0, OSSR);
c->event_handler(c);
return IRQ_HANDLED;
}
static int
pxa_osmr0_set_next_event(unsigned long delta, struct clock_event_device *dev)
{
unsigned long next, oscr;
timer_writel(timer_readl(OIER) | OIER_E0, OIER);
next = timer_readl(OSCR) + delta;
timer_writel(next, OSMR0);
oscr = timer_readl(OSCR);
return (signed)(next - oscr) <= MIN_OSCR_DELTA ? -ETIME : 0;
}
static int pxa_osmr0_shutdown(struct clock_event_device *evt)
{
timer_writel(timer_readl(OIER) & ~OIER_E0, OIER);
timer_writel(OSSR_M0, OSSR);
return 0;
}
static void pxa_timer_suspend(struct clock_event_device *cedev)
{
osmr[0] = timer_readl(OSMR0);
osmr[1] = timer_readl(OSMR1);
osmr[2] = timer_readl(OSMR2);
osmr[3] = timer_readl(OSMR3);
oier = timer_readl(OIER);
oscr = timer_readl(OSCR);
}
static void pxa_timer_resume(struct clock_event_device *cedev)
{
if (osmr[0] - oscr < MIN_OSCR_DELTA)
osmr[0] += MIN_OSCR_DELTA;
timer_writel(osmr[0], OSMR0);
timer_writel(osmr[1], OSMR1);
timer_writel(osmr[2], OSMR2);
timer_writel(osmr[3], OSMR3);
timer_writel(oier, OIER);
timer_writel(oscr, OSCR);
}
static int __init pxa_timer_common_init(int irq, unsigned long clock_tick_rate)
{
int ret;
timer_writel(0, OIER);
timer_writel(OSSR_M0 | OSSR_M1 | OSSR_M2 | OSSR_M3, OSSR);
sched_clock_register(pxa_read_sched_clock, 32, clock_tick_rate);
ckevt_pxa_osmr0.cpumask = cpumask_of(0);
ret = setup_irq(irq, &pxa_ost0_irq);
if (ret) {
pr_err("Failed to setup irq");
return ret;
}
ret = clocksource_mmio_init(timer_base + OSCR, "oscr0", clock_tick_rate, 200,
32, clocksource_mmio_readl_up);
if (ret) {
pr_err("Failed to init clocksource");
return ret;
}
clockevents_config_and_register(&ckevt_pxa_osmr0, clock_tick_rate,
MIN_OSCR_DELTA * 2, 0x7fffffff);
return 0;
}
static int __init pxa_timer_dt_init(struct device_node *np)
{
struct clk *clk;
int irq, ret;
timer_base = of_iomap(np, 0);
if (!timer_base) {
pr_err("%s: unable to map resource\n", np->name);
return -ENXIO;
}
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_crit("%s: unable to get clk\n", np->name);
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_crit("Failed to prepare clock");
return ret;
}
irq = irq_of_parse_and_map(np, 0);
if (irq <= 0) {
pr_crit("%s: unable to parse OS-timer0 irq\n", np->name);
return -EINVAL;
}
return pxa_timer_common_init(irq, clk_get_rate(clk));
}
void __init pxa_timer_nodt_init(int irq, void __iomem *base,
unsigned long clock_tick_rate)
{
struct clk *clk;
timer_base = base;
clk = clk_get(NULL, "OSTIMER0");
if (clk && !IS_ERR(clk))
clk_prepare_enable(clk);
else
pr_crit("%s: unable to get clk\n", __func__);
pxa_timer_common_init(irq, clock_tick_rate);
}
