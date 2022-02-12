static inline void sirfsoc_timer_count_disable(int idx)
{
writel_relaxed(readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_32COUNTER_0_CTRL + 4 * idx) & ~0x7,
sirfsoc_timer_base + SIRFSOC_TIMER_32COUNTER_0_CTRL + 4 * idx);
}
static inline void sirfsoc_timer_count_enable(int idx)
{
writel_relaxed(readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_32COUNTER_0_CTRL + 4 * idx) | 0x7,
sirfsoc_timer_base + SIRFSOC_TIMER_32COUNTER_0_CTRL + 4 * idx);
}
static irqreturn_t sirfsoc_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *ce = dev_id;
int cpu = smp_processor_id();
writel_relaxed(BIT(cpu), sirfsoc_timer_base + SIRFSOC_TIMER_INTR_STATUS);
if (ce->mode == CLOCK_EVT_MODE_ONESHOT)
sirfsoc_timer_count_disable(cpu);
ce->event_handler(ce);
return IRQ_HANDLED;
}
static cycle_t sirfsoc_timer_read(struct clocksource *cs)
{
u64 cycles;
writel_relaxed((readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_CTRL) |
BIT(0)) & ~BIT(1), sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_CTRL);
cycles = readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_RLATCHED_HI);
cycles = (cycles << 32) | readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_RLATCHED_LO);
return cycles;
}
static int sirfsoc_timer_set_next_event(unsigned long delta,
struct clock_event_device *ce)
{
int cpu = smp_processor_id();
writel_relaxed(0, sirfsoc_timer_base + SIRFSOC_TIMER_COUNTER_0 +
4 * cpu);
writel_relaxed(delta, sirfsoc_timer_base + SIRFSOC_TIMER_MATCH_0 +
4 * cpu);
sirfsoc_timer_count_enable(cpu);
return 0;
}
static void sirfsoc_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *ce)
{
switch (mode) {
case CLOCK_EVT_MODE_ONESHOT:
break;
default:
break;
}
sirfsoc_timer_count_disable(smp_processor_id());
}
static void sirfsoc_clocksource_suspend(struct clocksource *cs)
{
int i;
for (i = 0; i < SIRFSOC_TIMER_REG_CNT; i++)
sirfsoc_timer_reg_val[i] = readl_relaxed(sirfsoc_timer_base + sirfsoc_timer_reg_list[i]);
}
static void sirfsoc_clocksource_resume(struct clocksource *cs)
{
int i;
for (i = 0; i < SIRFSOC_TIMER_REG_CNT - 2; i++)
writel_relaxed(sirfsoc_timer_reg_val[i], sirfsoc_timer_base + sirfsoc_timer_reg_list[i]);
writel_relaxed(sirfsoc_timer_reg_val[SIRFSOC_TIMER_REG_CNT - 2],
sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_LOAD_LO);
writel_relaxed(sirfsoc_timer_reg_val[SIRFSOC_TIMER_REG_CNT - 1],
sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_LOAD_HI);
writel_relaxed(readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_CTRL) |
BIT(1) | BIT(0), sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_CTRL);
}
static int sirfsoc_local_timer_setup(struct clock_event_device *ce)
{
if (!smp_processor_id())
return 0;
ce->irq = sirfsoc_timer1_irq.irq;
ce->name = "local_timer";
ce->features = sirfsoc_clockevent.features;
ce->rating = sirfsoc_clockevent.rating;
ce->set_mode = sirfsoc_timer_set_mode;
ce->set_next_event = sirfsoc_timer_set_next_event;
ce->shift = sirfsoc_clockevent.shift;
ce->mult = sirfsoc_clockevent.mult;
ce->max_delta_ns = sirfsoc_clockevent.max_delta_ns;
ce->min_delta_ns = sirfsoc_clockevent.min_delta_ns;
sirfsoc_timer1_irq.dev_id = ce;
BUG_ON(setup_irq(ce->irq, &sirfsoc_timer1_irq));
irq_set_affinity(sirfsoc_timer1_irq.irq, cpumask_of(1));
clockevents_register_device(ce);
return 0;
}
static void sirfsoc_local_timer_stop(struct clock_event_device *ce)
{
sirfsoc_timer_count_disable(1);
remove_irq(sirfsoc_timer1_irq.irq, &sirfsoc_timer1_irq);
}
static void __init sirfsoc_clockevent_init(void)
{
clockevents_calc_mult_shift(&sirfsoc_clockevent, CLOCK_TICK_RATE, 60);
sirfsoc_clockevent.max_delta_ns =
clockevent_delta2ns(-2, &sirfsoc_clockevent);
sirfsoc_clockevent.min_delta_ns =
clockevent_delta2ns(2, &sirfsoc_clockevent);
sirfsoc_clockevent.cpumask = cpumask_of(0);
clockevents_register_device(&sirfsoc_clockevent);
#ifdef CONFIG_LOCAL_TIMERS
local_timer_register(&sirfsoc_local_timer_ops);
#endif
}
static void __init sirfsoc_marco_timer_init(void)
{
unsigned long rate;
u32 timer_div;
struct clk *clk;
clk = clk_get_sys("io", NULL);
BUG_ON(IS_ERR(clk));
rate = clk_get_rate(clk);
BUG_ON(rate < CLOCK_TICK_RATE);
BUG_ON(rate % CLOCK_TICK_RATE);
timer_div = rate / CLOCK_TICK_RATE - 1;
writel_relaxed(timer_div << 16, sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_CTRL);
writel_relaxed(timer_div << 16, sirfsoc_timer_base + SIRFSOC_TIMER_32COUNTER_0_CTRL);
writel_relaxed(timer_div << 16, sirfsoc_timer_base + SIRFSOC_TIMER_32COUNTER_1_CTRL);
writel_relaxed(0, sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_LOAD_LO);
writel_relaxed(0, sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_LOAD_HI);
writel_relaxed(readl_relaxed(sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_CTRL) |
BIT(1) | BIT(0), sirfsoc_timer_base + SIRFSOC_TIMER_64COUNTER_CTRL);
writel_relaxed(0, sirfsoc_timer_base + SIRFSOC_TIMER_COUNTER_0);
writel_relaxed(0, sirfsoc_timer_base + SIRFSOC_TIMER_COUNTER_1);
writel_relaxed(0xFFFF, sirfsoc_timer_base + SIRFSOC_TIMER_INTR_STATUS);
BUG_ON(clocksource_register_hz(&sirfsoc_clocksource, CLOCK_TICK_RATE));
BUG_ON(setup_irq(sirfsoc_timer_irq.irq, &sirfsoc_timer_irq));
sirfsoc_clockevent_init();
}
static void __init sirfsoc_of_timer_init(struct device_node *np)
{
sirfsoc_timer_base = of_iomap(np, 0);
if (!sirfsoc_timer_base)
panic("unable to map timer cpu registers\n");
sirfsoc_timer_irq.irq = irq_of_parse_and_map(np, 0);
if (!sirfsoc_timer_irq.irq)
panic("No irq passed for timer0 via DT\n");
#ifdef CONFIG_LOCAL_TIMERS
sirfsoc_timer1_irq.irq = irq_of_parse_and_map(np, 1);
if (!sirfsoc_timer1_irq.irq)
panic("No irq passed for timer1 via DT\n");
#endif
sirfsoc_marco_timer_init();
}
