static int gic_next_event(unsigned long delta, struct clock_event_device *evt)
{
u64 cnt;
int res;
cnt = gic_read_count();
cnt += (u64)delta;
gic_write_cpu_compare(cnt, cpumask_first(evt->cpumask));
res = ((int)(gic_read_count() - cnt) >= 0) ? -ETIME : 0;
return res;
}
static irqreturn_t gic_compare_interrupt(int irq, void *dev_id)
{
struct clock_event_device *cd = dev_id;
gic_write_compare(gic_read_compare());
cd->event_handler(cd);
return IRQ_HANDLED;
}
static void gic_clockevent_cpu_init(unsigned int cpu,
struct clock_event_device *cd)
{
cd->name = "MIPS GIC";
cd->features = CLOCK_EVT_FEAT_ONESHOT |
CLOCK_EVT_FEAT_C3STOP;
cd->rating = 350;
cd->irq = gic_timer_irq;
cd->cpumask = cpumask_of(cpu);
cd->set_next_event = gic_next_event;
clockevents_config_and_register(cd, gic_frequency, 0x300, 0x7fffffff);
enable_percpu_irq(gic_timer_irq, IRQ_TYPE_NONE);
}
static void gic_clockevent_cpu_exit(struct clock_event_device *cd)
{
disable_percpu_irq(gic_timer_irq);
}
static void gic_update_frequency(void *data)
{
unsigned long rate = (unsigned long)data;
clockevents_update_freq(this_cpu_ptr(&gic_clockevent_device), rate);
}
static int gic_starting_cpu(unsigned int cpu)
{
gic_clockevent_cpu_init(cpu, this_cpu_ptr(&gic_clockevent_device));
return 0;
}
static int gic_clk_notifier(struct notifier_block *nb, unsigned long action,
void *data)
{
struct clk_notifier_data *cnd = data;
if (action == POST_RATE_CHANGE)
on_each_cpu(gic_update_frequency, (void *)cnd->new_rate, 1);
return NOTIFY_OK;
}
static int gic_dying_cpu(unsigned int cpu)
{
gic_clockevent_cpu_exit(this_cpu_ptr(&gic_clockevent_device));
return 0;
}
static int gic_clockevent_init(void)
{
int ret;
if (!gic_frequency)
return -ENXIO;
ret = setup_percpu_irq(gic_timer_irq, &gic_compare_irqaction);
if (ret < 0) {
pr_err("GIC timer IRQ %d setup failed: %d\n",
gic_timer_irq, ret);
return ret;
}
cpuhp_setup_state(CPUHP_AP_MIPS_GIC_TIMER_STARTING,
"clockevents/mips/gic/timer:starting",
gic_starting_cpu, gic_dying_cpu);
return 0;
}
static u64 gic_hpt_read(struct clocksource *cs)
{
return gic_read_count();
}
static int __init __gic_clocksource_init(void)
{
int ret;
gic_clocksource.mask = CLOCKSOURCE_MASK(gic_get_count_width());
gic_clocksource.rating = 200 + gic_frequency / 10000000;
ret = clocksource_register_hz(&gic_clocksource, gic_frequency);
if (ret < 0)
pr_warn("GIC: Unable to register clocksource\n");
return ret;
}
static int __init gic_clocksource_of_init(struct device_node *node)
{
struct clk *clk;
int ret;
if (!gic_present || !node->parent ||
!of_device_is_compatible(node->parent, "mti,gic")) {
pr_warn("No DT definition for the mips gic driver\n");
return -ENXIO;
}
clk = of_clk_get(node, 0);
if (!IS_ERR(clk)) {
ret = clk_prepare_enable(clk);
if (ret < 0) {
pr_err("GIC failed to enable clock\n");
clk_put(clk);
return ret;
}
gic_frequency = clk_get_rate(clk);
} else if (of_property_read_u32(node, "clock-frequency",
&gic_frequency)) {
pr_err("GIC frequency not specified.\n");
return -EINVAL;;
}
gic_timer_irq = irq_of_parse_and_map(node, 0);
if (!gic_timer_irq) {
pr_err("GIC timer IRQ not specified.\n");
return -EINVAL;;
}
ret = __gic_clocksource_init();
if (ret)
return ret;
ret = gic_clockevent_init();
if (!ret && !IS_ERR(clk)) {
if (clk_notifier_register(clk, &gic_clk_nb) < 0)
pr_warn("GIC: Unable to register clock notifier\n");
}
gic_start_count();
return 0;
}
