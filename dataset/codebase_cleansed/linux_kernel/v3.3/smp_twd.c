static void twd_set_mode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
unsigned long ctrl;
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
ctrl = TWD_TIMER_CONTROL_ENABLE | TWD_TIMER_CONTROL_IT_ENABLE
| TWD_TIMER_CONTROL_PERIODIC;
__raw_writel(twd_timer_rate / HZ, twd_base + TWD_TIMER_LOAD);
break;
case CLOCK_EVT_MODE_ONESHOT:
ctrl = TWD_TIMER_CONTROL_IT_ENABLE | TWD_TIMER_CONTROL_ONESHOT;
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
default:
ctrl = 0;
}
__raw_writel(ctrl, twd_base + TWD_TIMER_CONTROL);
}
static int twd_set_next_event(unsigned long evt,
struct clock_event_device *unused)
{
unsigned long ctrl = __raw_readl(twd_base + TWD_TIMER_CONTROL);
ctrl |= TWD_TIMER_CONTROL_ENABLE;
__raw_writel(evt, twd_base + TWD_TIMER_COUNTER);
__raw_writel(ctrl, twd_base + TWD_TIMER_CONTROL);
return 0;
}
int twd_timer_ack(void)
{
if (__raw_readl(twd_base + TWD_TIMER_INTSTAT)) {
__raw_writel(1, twd_base + TWD_TIMER_INTSTAT);
return 1;
}
return 0;
}
void twd_timer_stop(struct clock_event_device *clk)
{
twd_set_mode(CLOCK_EVT_MODE_UNUSED, clk);
disable_percpu_irq(clk->irq);
}
static void twd_update_frequency(void *data)
{
twd_timer_rate = clk_get_rate(twd_clk);
clockevents_update_freq(*__this_cpu_ptr(twd_evt), twd_timer_rate);
}
static int twd_cpufreq_transition(struct notifier_block *nb,
unsigned long state, void *data)
{
struct cpufreq_freqs *freqs = data;
if (state == CPUFREQ_POSTCHANGE || state == CPUFREQ_RESUMECHANGE)
smp_call_function_single(freqs->cpu, twd_update_frequency,
NULL, 1);
return NOTIFY_OK;
}
static int twd_cpufreq_init(void)
{
if (twd_evt && *__this_cpu_ptr(twd_evt) && !IS_ERR(twd_clk))
return cpufreq_register_notifier(&twd_cpufreq_nb,
CPUFREQ_TRANSITION_NOTIFIER);
return 0;
}
static void __cpuinit twd_calibrate_rate(void)
{
unsigned long count;
u64 waitjiffies;
if (twd_timer_rate == 0) {
printk(KERN_INFO "Calibrating local timer... ");
waitjiffies = get_jiffies_64() + 1;
while (get_jiffies_64() < waitjiffies)
udelay(10);
waitjiffies += 5;
__raw_writel(0x1, twd_base + TWD_TIMER_CONTROL);
__raw_writel(0xFFFFFFFFU, twd_base + TWD_TIMER_COUNTER);
while (get_jiffies_64() < waitjiffies)
udelay(10);
count = __raw_readl(twd_base + TWD_TIMER_COUNTER);
twd_timer_rate = (0xFFFFFFFFU - count) * (HZ / 5);
printk("%lu.%02luMHz.\n", twd_timer_rate / 1000000,
(twd_timer_rate / 10000) % 100);
}
}
static irqreturn_t twd_handler(int irq, void *dev_id)
{
struct clock_event_device *evt = *(struct clock_event_device **)dev_id;
if (twd_timer_ack()) {
evt->event_handler(evt);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static struct clk *twd_get_clock(void)
{
struct clk *clk;
int err;
clk = clk_get_sys("smp_twd", NULL);
if (IS_ERR(clk)) {
pr_err("smp_twd: clock not found: %d\n", (int)PTR_ERR(clk));
return clk;
}
err = clk_prepare(clk);
if (err) {
pr_err("smp_twd: clock failed to prepare: %d\n", err);
clk_put(clk);
return ERR_PTR(err);
}
err = clk_enable(clk);
if (err) {
pr_err("smp_twd: clock failed to enable: %d\n", err);
clk_unprepare(clk);
clk_put(clk);
return ERR_PTR(err);
}
return clk;
}
void __cpuinit twd_timer_setup(struct clock_event_device *clk)
{
struct clock_event_device **this_cpu_clk;
if (!twd_evt) {
int err;
twd_evt = alloc_percpu(struct clock_event_device *);
if (!twd_evt) {
pr_err("twd: can't allocate memory\n");
return;
}
err = request_percpu_irq(clk->irq, twd_handler,
"twd", twd_evt);
if (err) {
pr_err("twd: can't register interrupt %d (%d)\n",
clk->irq, err);
return;
}
}
if (!twd_clk)
twd_clk = twd_get_clock();
if (!IS_ERR_OR_NULL(twd_clk))
twd_timer_rate = clk_get_rate(twd_clk);
else
twd_calibrate_rate();
__raw_writel(0, twd_base + TWD_TIMER_CONTROL);
clk->name = "local_timer";
clk->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT |
CLOCK_EVT_FEAT_C3STOP;
clk->rating = 350;
clk->set_mode = twd_set_mode;
clk->set_next_event = twd_set_next_event;
this_cpu_clk = __this_cpu_ptr(twd_evt);
*this_cpu_clk = clk;
clockevents_config_and_register(clk, twd_timer_rate,
0xf, 0xffffffff);
enable_percpu_irq(clk->irq, 0);
}
