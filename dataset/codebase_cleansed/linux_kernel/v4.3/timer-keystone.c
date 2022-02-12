static inline u32 keystone_timer_readl(unsigned long rg)
{
return readl_relaxed(timer.base + rg);
}
static inline void keystone_timer_writel(u32 val, unsigned long rg)
{
writel_relaxed(val, timer.base + rg);
}
static inline void keystone_timer_barrier(void)
{
__iowmb();
}
static int keystone_timer_config(u64 period, int mask)
{
u32 tcr;
u32 off;
tcr = keystone_timer_readl(TCR);
off = tcr & ~(TCR_ENAMODE_MASK);
tcr |= mask;
keystone_timer_writel(off, TCR);
keystone_timer_barrier();
keystone_timer_writel(0, TIM12);
keystone_timer_writel(0, TIM34);
keystone_timer_writel(period & 0xffffffff, PRD12);
keystone_timer_writel(period >> 32, PRD34);
keystone_timer_barrier();
keystone_timer_writel(tcr, TCR);
return 0;
}
static void keystone_timer_disable(void)
{
u32 tcr;
tcr = keystone_timer_readl(TCR);
tcr &= ~(TCR_ENAMODE_MASK);
keystone_timer_writel(tcr, TCR);
}
static irqreturn_t keystone_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int keystone_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
return keystone_timer_config(cycles, TCR_ENAMODE_ONESHOT_MASK);
}
static int keystone_shutdown(struct clock_event_device *evt)
{
keystone_timer_disable();
return 0;
}
static int keystone_set_periodic(struct clock_event_device *evt)
{
keystone_timer_config(timer.hz_period, TCR_ENAMODE_PERIODIC_MASK);
return 0;
}
static void __init keystone_timer_init(struct device_node *np)
{
struct clock_event_device *event_dev = &timer.event_dev;
unsigned long rate;
struct clk *clk;
int irq, error;
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
pr_err("%s: failed to map interrupts\n", __func__);
return;
}
timer.base = of_iomap(np, 0);
if (!timer.base) {
pr_err("%s: failed to map registers\n", __func__);
return;
}
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_err("%s: failed to get clock\n", __func__);
iounmap(timer.base);
return;
}
error = clk_prepare_enable(clk);
if (error) {
pr_err("%s: failed to enable clock\n", __func__);
goto err;
}
rate = clk_get_rate(clk);
keystone_timer_writel(0, TCR);
keystone_timer_barrier();
keystone_timer_writel(0, TGCR);
keystone_timer_writel(TGCR_TIM_UNRESET_MASK, TGCR);
keystone_timer_writel(0, TIM12);
keystone_timer_writel(0, TIM34);
timer.hz_period = DIV_ROUND_UP(rate, HZ);
keystone_timer_writel(INTCTLSTAT_ENINT_MASK, INTCTLSTAT);
error = request_irq(irq, keystone_timer_interrupt, IRQF_TIMER,
TIMER_NAME, event_dev);
if (error) {
pr_err("%s: failed to setup irq\n", __func__);
goto err;
}
event_dev->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT;
event_dev->set_next_event = keystone_set_next_event;
event_dev->set_state_shutdown = keystone_shutdown;
event_dev->set_state_periodic = keystone_set_periodic;
event_dev->set_state_oneshot = keystone_shutdown;
event_dev->cpumask = cpu_all_mask;
event_dev->owner = THIS_MODULE;
event_dev->name = TIMER_NAME;
event_dev->irq = irq;
clockevents_config_and_register(event_dev, rate, 1, ULONG_MAX);
pr_info("keystone timer clock @%lu Hz\n", rate);
return;
err:
clk_put(clk);
iounmap(timer.base);
}
