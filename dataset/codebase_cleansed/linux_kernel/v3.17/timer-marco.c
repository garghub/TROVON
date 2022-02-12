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
int cpu = smp_processor_id();
struct irqaction *action;
if (cpu == 0)
action = &sirfsoc_timer_irq;
else
action = &sirfsoc_timer1_irq;
ce->irq = action->irq;
ce->name = "local_timer";
ce->features = CLOCK_EVT_FEAT_ONESHOT;
ce->rating = 200;
ce->set_mode = sirfsoc_timer_set_mode;
ce->set_next_event = sirfsoc_timer_set_next_event;
clockevents_calc_mult_shift(ce, MARCO_CLOCK_FREQ, 60);
ce->max_delta_ns = clockevent_delta2ns(-2, ce);
ce->min_delta_ns = clockevent_delta2ns(2, ce);
ce->cpumask = cpumask_of(cpu);
action->dev_id = ce;
BUG_ON(setup_irq(ce->irq, action));
irq_force_affinity(action->irq, cpumask_of(cpu));
clockevents_register_device(ce);
return 0;
}
static void sirfsoc_local_timer_stop(struct clock_event_device *ce)
{
int cpu = smp_processor_id();
sirfsoc_timer_count_disable(1);
if (cpu == 0)
remove_irq(sirfsoc_timer_irq.irq, &sirfsoc_timer_irq);
else
remove_irq(sirfsoc_timer1_irq.irq, &sirfsoc_timer1_irq);
}
static int sirfsoc_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_STARTING:
sirfsoc_local_timer_setup(this_cpu_ptr(sirfsoc_clockevent));
break;
case CPU_DYING:
sirfsoc_local_timer_stop(this_cpu_ptr(sirfsoc_clockevent));
break;
}
return NOTIFY_OK;
}
static void __init sirfsoc_clockevent_init(void)
{
sirfsoc_clockevent = alloc_percpu(struct clock_event_device);
BUG_ON(!sirfsoc_clockevent);
BUG_ON(register_cpu_notifier(&sirfsoc_cpu_nb));
sirfsoc_local_timer_setup(this_cpu_ptr(sirfsoc_clockevent));
}
static void __init sirfsoc_marco_timer_init(struct device_node *np)
{
unsigned long rate;
u32 timer_div;
struct clk *clk;
clk = of_clk_get(np, 0);
BUG_ON(IS_ERR(clk));
BUG_ON(clk_prepare_enable(clk));
rate = clk_get_rate(clk);
BUG_ON(rate < MARCO_CLOCK_FREQ);
BUG_ON(rate % MARCO_CLOCK_FREQ);
timer_div = rate / MARCO_CLOCK_FREQ - 1;
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
BUG_ON(clocksource_register_hz(&sirfsoc_clocksource, MARCO_CLOCK_FREQ));
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
sirfsoc_timer1_irq.irq = irq_of_parse_and_map(np, 1);
if (!sirfsoc_timer1_irq.irq)
panic("No irq passed for timer1 via DT\n");
sirfsoc_marco_timer_init(np);
}
