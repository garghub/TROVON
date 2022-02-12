static int twd_shutdown(struct clock_event_device *clk)
{
writel_relaxed(0, twd_base + TWD_TIMER_CONTROL);
return 0;
}
static int twd_set_oneshot(struct clock_event_device *clk)
{
writel_relaxed(TWD_TIMER_CONTROL_IT_ENABLE | TWD_TIMER_CONTROL_ONESHOT,
twd_base + TWD_TIMER_CONTROL);
return 0;
}
static int twd_set_periodic(struct clock_event_device *clk)
{
unsigned long ctrl = TWD_TIMER_CONTROL_ENABLE |
TWD_TIMER_CONTROL_IT_ENABLE |
TWD_TIMER_CONTROL_PERIODIC;
writel_relaxed(DIV_ROUND_CLOSEST(twd_timer_rate, HZ),
twd_base + TWD_TIMER_LOAD);
writel_relaxed(ctrl, twd_base + TWD_TIMER_CONTROL);
return 0;
}
static int twd_set_next_event(unsigned long evt,
struct clock_event_device *unused)
{
unsigned long ctrl = readl_relaxed(twd_base + TWD_TIMER_CONTROL);
ctrl |= TWD_TIMER_CONTROL_ENABLE;
writel_relaxed(evt, twd_base + TWD_TIMER_COUNTER);
writel_relaxed(ctrl, twd_base + TWD_TIMER_CONTROL);
return 0;
}
static int twd_timer_ack(void)
{
if (readl_relaxed(twd_base + TWD_TIMER_INTSTAT)) {
writel_relaxed(1, twd_base + TWD_TIMER_INTSTAT);
return 1;
}
return 0;
}
static void twd_timer_stop(void)
{
struct clock_event_device *clk = raw_cpu_ptr(twd_evt);
twd_shutdown(clk);
disable_percpu_irq(clk->irq);
}
static void twd_update_frequency(void *new_rate)
{
twd_timer_rate = *((unsigned long *) new_rate);
clockevents_update_freq(raw_cpu_ptr(twd_evt), twd_timer_rate);
}
static int twd_rate_change(struct notifier_block *nb,
unsigned long flags, void *data)
{
struct clk_notifier_data *cnd = data;
if (flags == POST_RATE_CHANGE)
on_each_cpu(twd_update_frequency,
(void *)&cnd->new_rate, 1);
return NOTIFY_OK;
}
static int twd_clk_init(void)
{
if (twd_evt && raw_cpu_ptr(twd_evt) && !IS_ERR(twd_clk))
return clk_notifier_register(twd_clk, &twd_clk_nb);
return 0;
}
static void twd_update_frequency(void *data)
{
twd_timer_rate = clk_get_rate(twd_clk);
clockevents_update_freq(raw_cpu_ptr(twd_evt), twd_timer_rate);
}
static int twd_cpufreq_transition(struct notifier_block *nb,
unsigned long state, void *data)
{
struct cpufreq_freqs *freqs = data;
if (state == CPUFREQ_POSTCHANGE)
smp_call_function_single(freqs->cpu, twd_update_frequency,
NULL, 1);
return NOTIFY_OK;
}
static int twd_cpufreq_init(void)
{
if (twd_evt && raw_cpu_ptr(twd_evt) && !IS_ERR(twd_clk))
return cpufreq_register_notifier(&twd_cpufreq_nb,
CPUFREQ_TRANSITION_NOTIFIER);
return 0;
}
static void twd_calibrate_rate(void)
{
unsigned long count;
u64 waitjiffies;
if (twd_timer_rate == 0) {
pr_info("Calibrating local timer... ");
waitjiffies = get_jiffies_64() + 1;
while (get_jiffies_64() < waitjiffies)
udelay(10);
waitjiffies += 5;
writel_relaxed(0x1, twd_base + TWD_TIMER_CONTROL);
writel_relaxed(0xFFFFFFFFU, twd_base + TWD_TIMER_COUNTER);
while (get_jiffies_64() < waitjiffies)
udelay(10);
count = readl_relaxed(twd_base + TWD_TIMER_COUNTER);
twd_timer_rate = (0xFFFFFFFFU - count) * (HZ / 5);
pr_cont("%lu.%02luMHz.\n", twd_timer_rate / 1000000,
(twd_timer_rate / 10000) % 100);
}
}
static irqreturn_t twd_handler(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
if (twd_timer_ack()) {
evt->event_handler(evt);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void twd_get_clock(struct device_node *np)
{
int err;
if (np)
twd_clk = of_clk_get(np, 0);
else
twd_clk = clk_get_sys("smp_twd", NULL);
if (IS_ERR(twd_clk)) {
pr_err("smp_twd: clock not found %d\n", (int) PTR_ERR(twd_clk));
return;
}
err = clk_prepare_enable(twd_clk);
if (err) {
pr_err("smp_twd: clock failed to prepare+enable: %d\n", err);
clk_put(twd_clk);
return;
}
twd_timer_rate = clk_get_rate(twd_clk);
}
static void twd_timer_setup(void)
{
struct clock_event_device *clk = raw_cpu_ptr(twd_evt);
int cpu = smp_processor_id();
if (per_cpu(percpu_setup_called, cpu)) {
writel_relaxed(0, twd_base + TWD_TIMER_CONTROL);
clockevents_register_device(clk);
enable_percpu_irq(clk->irq, 0);
return;
}
per_cpu(percpu_setup_called, cpu) = true;
twd_calibrate_rate();
writel_relaxed(0, twd_base + TWD_TIMER_CONTROL);
clk->name = "local_timer";
clk->features = twd_features;
clk->rating = 350;
clk->set_state_shutdown = twd_shutdown;
clk->set_state_periodic = twd_set_periodic;
clk->set_state_oneshot = twd_set_oneshot;
clk->tick_resume = twd_shutdown;
clk->set_next_event = twd_set_next_event;
clk->irq = twd_ppi;
clk->cpumask = cpumask_of(cpu);
clockevents_config_and_register(clk, twd_timer_rate,
0xf, 0xffffffff);
enable_percpu_irq(clk->irq, 0);
}
static int twd_timer_starting_cpu(unsigned int cpu)
{
twd_timer_setup();
return 0;
}
static int twd_timer_dying_cpu(unsigned int cpu)
{
twd_timer_stop();
return 0;
}
static int __init twd_local_timer_common_register(struct device_node *np)
{
int err;
twd_evt = alloc_percpu(struct clock_event_device);
if (!twd_evt) {
err = -ENOMEM;
goto out_free;
}
err = request_percpu_irq(twd_ppi, twd_handler, "twd", twd_evt);
if (err) {
pr_err("twd: can't register interrupt %d (%d)\n", twd_ppi, err);
goto out_free;
}
cpuhp_setup_state_nocalls(CPUHP_AP_ARM_TWD_STARTING,
"arm/timer/twd:starting",
twd_timer_starting_cpu, twd_timer_dying_cpu);
twd_get_clock(np);
if (!of_property_read_bool(np, "always-on"))
twd_features |= CLOCK_EVT_FEAT_C3STOP;
if (twd_timer_rate)
twd_timer_setup();
else
late_time_init = twd_timer_setup;
return 0;
out_free:
iounmap(twd_base);
twd_base = NULL;
free_percpu(twd_evt);
return err;
}
int __init twd_local_timer_register(struct twd_local_timer *tlt)
{
if (twd_base || twd_evt)
return -EBUSY;
twd_ppi = tlt->res[1].start;
twd_base = ioremap(tlt->res[0].start, resource_size(&tlt->res[0]));
if (!twd_base)
return -ENOMEM;
return twd_local_timer_common_register(NULL);
}
static int __init twd_local_timer_of_register(struct device_node *np)
{
int err;
twd_ppi = irq_of_parse_and_map(np, 0);
if (!twd_ppi) {
err = -EINVAL;
goto out;
}
twd_base = of_iomap(np, 0);
if (!twd_base) {
err = -ENOMEM;
goto out;
}
err = twd_local_timer_common_register(np);
out:
WARN(err, "twd_local_timer_of_register failed (%d)\n", err);
return err;
}
