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
twd_calibrate_rate();
clk->name = "local_timer";
clk->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT |
CLOCK_EVT_FEAT_C3STOP;
clk->rating = 350;
clk->set_mode = twd_set_mode;
clk->set_next_event = twd_set_next_event;
clk->shift = 20;
clk->mult = div_sc(twd_timer_rate, NSEC_PER_SEC, clk->shift);
clk->max_delta_ns = clockevent_delta2ns(0xffffffff, clk);
clk->min_delta_ns = clockevent_delta2ns(0xf, clk);
this_cpu_clk = __this_cpu_ptr(twd_evt);
*this_cpu_clk = clk;
clockevents_register_device(clk);
enable_percpu_irq(clk->irq, 0);
}
