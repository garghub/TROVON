static irqreturn_t sirfsoc_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *ce = dev_id;
WARN_ON(!(readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_STATUS) &
BIT(0)));
writel_relaxed(BIT(0), sirfsoc_timer_base + SIRFSOC_TIMER_STATUS);
ce->event_handler(ce);
return IRQ_HANDLED;
}
static u64 notrace sirfsoc_timer_read(struct clocksource *cs)
{
u64 cycles;
writel_relaxed(SIRFSOC_TIMER_LATCH_BIT,
sirfsoc_timer_base + SIRFSOC_TIMER_LATCH);
cycles = readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_LATCHED_HI);
cycles = (cycles << 32) |
readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_LATCHED_LO);
return cycles;
}
static int sirfsoc_timer_set_next_event(unsigned long delta,
struct clock_event_device *ce)
{
unsigned long now, next;
writel_relaxed(SIRFSOC_TIMER_LATCH_BIT,
sirfsoc_timer_base + SIRFSOC_TIMER_LATCH);
now = readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_LATCHED_LO);
next = now + delta;
writel_relaxed(next, sirfsoc_timer_base + SIRFSOC_TIMER_MATCH_0);
writel_relaxed(SIRFSOC_TIMER_LATCH_BIT,
sirfsoc_timer_base + SIRFSOC_TIMER_LATCH);
now = readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_LATCHED_LO);
return next - now > delta ? -ETIME : 0;
}
static int sirfsoc_timer_shutdown(struct clock_event_device *evt)
{
u32 val = readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_INT_EN);
writel_relaxed(val & ~BIT(0),
sirfsoc_timer_base + SIRFSOC_TIMER_INT_EN);
return 0;
}
static int sirfsoc_timer_set_oneshot(struct clock_event_device *evt)
{
u32 val = readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_INT_EN);
writel_relaxed(val | BIT(0), sirfsoc_timer_base + SIRFSOC_TIMER_INT_EN);
return 0;
}
static void sirfsoc_clocksource_suspend(struct clocksource *cs)
{
int i;
writel_relaxed(SIRFSOC_TIMER_LATCH_BIT,
sirfsoc_timer_base + SIRFSOC_TIMER_LATCH);
for (i = 0; i < SIRFSOC_TIMER_REG_CNT; i++)
sirfsoc_timer_reg_val[i] =
readl_relaxed(sirfsoc_timer_base +
sirfsoc_timer_reg_list[i]);
}
static void sirfsoc_clocksource_resume(struct clocksource *cs)
{
int i;
for (i = 0; i < SIRFSOC_TIMER_REG_CNT - 2; i++)
writel_relaxed(sirfsoc_timer_reg_val[i],
sirfsoc_timer_base + sirfsoc_timer_reg_list[i]);
writel_relaxed(sirfsoc_timer_reg_val[SIRFSOC_TIMER_REG_CNT - 2],
sirfsoc_timer_base + SIRFSOC_TIMER_COUNTER_LO);
writel_relaxed(sirfsoc_timer_reg_val[SIRFSOC_TIMER_REG_CNT - 1],
sirfsoc_timer_base + SIRFSOC_TIMER_COUNTER_HI);
}
static u64 notrace sirfsoc_read_sched_clock(void)
{
return sirfsoc_timer_read(NULL);
}
static void __init sirfsoc_clockevent_init(void)
{
sirfsoc_clockevent.cpumask = cpumask_of(0);
clockevents_config_and_register(&sirfsoc_clockevent, PRIMA2_CLOCK_FREQ,
2, -2);
}
static int __init sirfsoc_prima2_timer_init(struct device_node *np)
{
unsigned long rate;
struct clk *clk;
int ret;
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_err("Failed to get clock\n");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("Failed to enable clock\n");
return ret;
}
rate = clk_get_rate(clk);
if (rate < PRIMA2_CLOCK_FREQ || rate % PRIMA2_CLOCK_FREQ) {
pr_err("Invalid clock rate\n");
return -EINVAL;
}
sirfsoc_timer_base = of_iomap(np, 0);
if (!sirfsoc_timer_base) {
pr_err("unable to map timer cpu registers\n");
return -ENXIO;
}
sirfsoc_timer_irq.irq = irq_of_parse_and_map(np, 0);
writel_relaxed(rate / PRIMA2_CLOCK_FREQ / 2 - 1,
sirfsoc_timer_base + SIRFSOC_TIMER_DIV);
writel_relaxed(0, sirfsoc_timer_base + SIRFSOC_TIMER_COUNTER_LO);
writel_relaxed(0, sirfsoc_timer_base + SIRFSOC_TIMER_COUNTER_HI);
writel_relaxed(BIT(0), sirfsoc_timer_base + SIRFSOC_TIMER_STATUS);
ret = clocksource_register_hz(&sirfsoc_clocksource, PRIMA2_CLOCK_FREQ);
if (ret) {
pr_err("Failed to register clocksource\n");
return ret;
}
sched_clock_register(sirfsoc_read_sched_clock, 64, PRIMA2_CLOCK_FREQ);
ret = setup_irq(sirfsoc_timer_irq.irq, &sirfsoc_timer_irq);
if (ret) {
pr_err("Failed to setup irq\n");
return ret;
}
sirfsoc_clockevent_init();
return 0;
}
