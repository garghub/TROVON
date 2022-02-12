static u64 gt_counter_read(void)
{
u64 counter;
u32 lower;
u32 upper, old_upper;
upper = readl_relaxed(gt_base + GT_COUNTER1);
do {
old_upper = upper;
lower = readl_relaxed(gt_base + GT_COUNTER0);
upper = readl_relaxed(gt_base + GT_COUNTER1);
} while (upper != old_upper);
counter = upper;
counter <<= 32;
counter |= lower;
return counter;
}
static void gt_compare_set(unsigned long delta, int periodic)
{
u64 counter = gt_counter_read();
unsigned long ctrl;
counter += delta;
ctrl = GT_CONTROL_TIMER_ENABLE;
writel(ctrl, gt_base + GT_CONTROL);
writel(lower_32_bits(counter), gt_base + GT_COMP0);
writel(upper_32_bits(counter), gt_base + GT_COMP1);
if (periodic) {
writel(delta, gt_base + GT_AUTO_INC);
ctrl |= GT_CONTROL_AUTO_INC;
}
ctrl |= GT_CONTROL_COMP_ENABLE | GT_CONTROL_IRQ_ENABLE;
writel(ctrl, gt_base + GT_CONTROL);
}
static void gt_clockevent_set_mode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
unsigned long ctrl;
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
gt_compare_set(DIV_ROUND_CLOSEST(gt_clk_rate, HZ), 1);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
ctrl = readl(gt_base + GT_CONTROL);
ctrl &= ~(GT_CONTROL_COMP_ENABLE |
GT_CONTROL_IRQ_ENABLE | GT_CONTROL_AUTO_INC);
writel(ctrl, gt_base + GT_CONTROL);
break;
default:
break;
}
}
static int gt_clockevent_set_next_event(unsigned long evt,
struct clock_event_device *unused)
{
gt_compare_set(evt, 0);
return 0;
}
static irqreturn_t gt_clockevent_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
if (!(readl_relaxed(gt_base + GT_INT_STATUS) &
GT_INT_STATUS_EVENT_FLAG))
return IRQ_NONE;
if (evt->mode == CLOCK_EVT_MODE_ONESHOT)
gt_compare_set(ULONG_MAX, 0);
writel_relaxed(GT_INT_STATUS_EVENT_FLAG, gt_base + GT_INT_STATUS);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int gt_clockevents_init(struct clock_event_device *clk)
{
int cpu = smp_processor_id();
clk->name = "arm_global_timer";
clk->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT;
clk->set_mode = gt_clockevent_set_mode;
clk->set_next_event = gt_clockevent_set_next_event;
clk->cpumask = cpumask_of(cpu);
clk->rating = 300;
clk->irq = gt_ppi;
clockevents_config_and_register(clk, gt_clk_rate,
1, 0xffffffff);
enable_percpu_irq(clk->irq, IRQ_TYPE_NONE);
return 0;
}
static void gt_clockevents_stop(struct clock_event_device *clk)
{
gt_clockevent_set_mode(CLOCK_EVT_MODE_UNUSED, clk);
disable_percpu_irq(clk->irq);
}
static cycle_t gt_clocksource_read(struct clocksource *cs)
{
return gt_counter_read();
}
static u32 notrace gt_sched_clock_read(void)
{
return gt_counter_read();
}
static void __init gt_clocksource_init(void)
{
writel(0, gt_base + GT_CONTROL);
writel(0, gt_base + GT_COUNTER0);
writel(0, gt_base + GT_COUNTER1);
writel(GT_CONTROL_TIMER_ENABLE, gt_base + GT_CONTROL);
#ifdef CONFIG_CLKSRC_ARM_GLOBAL_TIMER_SCHED_CLOCK
setup_sched_clock(gt_sched_clock_read, 32, gt_clk_rate);
#endif
clocksource_register_hz(&gt_clocksource, gt_clk_rate);
}
static int gt_cpu_notify(struct notifier_block *self, unsigned long action,
void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_STARTING:
gt_clockevents_init(this_cpu_ptr(gt_evt));
break;
case CPU_DYING:
gt_clockevents_stop(this_cpu_ptr(gt_evt));
break;
}
return NOTIFY_OK;
}
static void __init global_timer_of_register(struct device_node *np)
{
struct clk *gt_clk;
int err = 0;
if ((read_cpuid_id() & 0xf0000f) < 0x200000) {
pr_warn("global-timer: non support for this cpu version.\n");
return;
}
gt_ppi = irq_of_parse_and_map(np, 0);
if (!gt_ppi) {
pr_warn("global-timer: unable to parse irq\n");
return;
}
gt_base = of_iomap(np, 0);
if (!gt_base) {
pr_warn("global-timer: invalid base address\n");
return;
}
gt_clk = of_clk_get(np, 0);
if (!IS_ERR(gt_clk)) {
err = clk_prepare_enable(gt_clk);
if (err)
goto out_unmap;
} else {
pr_warn("global-timer: clk not found\n");
err = -EINVAL;
goto out_unmap;
}
gt_clk_rate = clk_get_rate(gt_clk);
gt_evt = alloc_percpu(struct clock_event_device);
if (!gt_evt) {
pr_warn("global-timer: can't allocate memory\n");
err = -ENOMEM;
goto out_clk;
}
err = request_percpu_irq(gt_ppi, gt_clockevent_interrupt,
"gt", gt_evt);
if (err) {
pr_warn("global-timer: can't register interrupt %d (%d)\n",
gt_ppi, err);
goto out_free;
}
err = register_cpu_notifier(&gt_cpu_nb);
if (err) {
pr_warn("global-timer: unable to register cpu notifier.\n");
goto out_irq;
}
gt_clocksource_init();
gt_clockevents_init(this_cpu_ptr(gt_evt));
return;
out_irq:
free_percpu_irq(gt_ppi, gt_evt);
out_free:
free_percpu(gt_evt);
out_clk:
clk_disable_unprepare(gt_clk);
out_unmap:
iounmap(gt_base);
WARN(err, "ARM Global timer register failed (%d)\n", err);
}
