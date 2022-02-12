static inline void tpm_timer_disable(void)
{
unsigned int val;
val = readl(timer_base + TPM_C0SC);
val &= ~(TPM_C0SC_MODE_MASK | TPM_C0SC_CHIE);
writel(val, timer_base + TPM_C0SC);
}
static inline void tpm_timer_enable(void)
{
unsigned int val;
val = readl(timer_base + TPM_C0SC);
val |= (TPM_C0SC_MODE_SW_COMPARE << TPM_C0SC_MODE_SHIFT) |
TPM_C0SC_CHIE;
writel(val, timer_base + TPM_C0SC);
}
static inline void tpm_irq_acknowledge(void)
{
writel(TPM_STATUS_CH0F, timer_base + TPM_STATUS);
}
static inline unsigned long tpm_read_counter(void)
{
return readl(timer_base + TPM_CNT);
}
static unsigned long tpm_read_current_timer(void)
{
return tpm_read_counter();
}
static u64 notrace tpm_read_sched_clock(void)
{
return tpm_read_counter();
}
static int __init tpm_clocksource_init(unsigned long rate)
{
tpm_delay_timer.read_current_timer = &tpm_read_current_timer;
tpm_delay_timer.freq = rate;
register_current_timer_delay(&tpm_delay_timer);
sched_clock_register(tpm_read_sched_clock, 32, rate);
return clocksource_mmio_init(timer_base + TPM_CNT, "imx-tpm",
rate, 200, 32, clocksource_mmio_readl_up);
}
static int tpm_set_next_event(unsigned long delta,
struct clock_event_device *evt)
{
unsigned long next, now;
next = tpm_read_counter();
next += delta;
writel(next, timer_base + TPM_C0V);
now = tpm_read_counter();
return (int)((next - now) <= 0) ? -ETIME : 0;
}
static int tpm_set_state_oneshot(struct clock_event_device *evt)
{
tpm_timer_enable();
return 0;
}
static int tpm_set_state_shutdown(struct clock_event_device *evt)
{
tpm_timer_disable();
return 0;
}
static irqreturn_t tpm_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
tpm_irq_acknowledge();
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init tpm_clockevent_init(unsigned long rate, int irq)
{
int ret;
ret = request_irq(irq, tpm_timer_interrupt, IRQF_TIMER | IRQF_IRQPOLL,
"i.MX7ULP TPM Timer", &clockevent_tpm);
clockevent_tpm.cpumask = cpumask_of(0);
clockevent_tpm.irq = irq;
clockevents_config_and_register(&clockevent_tpm,
rate, 300, 0xfffffffe);
return ret;
}
static int __init tpm_timer_init(struct device_node *np)
{
struct clk *ipg, *per;
int irq, ret;
u32 rate;
timer_base = of_iomap(np, 0);
if (!timer_base) {
pr_err("tpm: failed to get base address\n");
return -ENXIO;
}
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
pr_err("tpm: failed to get irq\n");
ret = -ENOENT;
goto err_iomap;
}
ipg = of_clk_get_by_name(np, "ipg");
per = of_clk_get_by_name(np, "per");
if (IS_ERR(ipg) || IS_ERR(per)) {
pr_err("tpm: failed to get igp or per clk\n");
ret = -ENODEV;
goto err_clk_get;
}
ret = clk_prepare_enable(ipg);
if (ret) {
pr_err("tpm: ipg clock enable failed (%d)\n", ret);
goto err_clk_get;
}
ret = clk_prepare_enable(per);
if (ret) {
pr_err("tpm: per clock enable failed (%d)\n", ret);
goto err_per_clk_enable;
}
writel(0, timer_base + TPM_SC);
writel(0, timer_base + TPM_CNT);
writel(0, timer_base + TPM_C0SC);
writel(TPM_SC_CMOD_INC_PER_CNT | TPM_SC_CMOD_DIV_DEFAULT,
timer_base + TPM_SC);
writel(0xffffffff, timer_base + TPM_MOD);
rate = clk_get_rate(per) >> 3;
ret = tpm_clocksource_init(rate);
if (ret)
goto err_per_clk_enable;
ret = tpm_clockevent_init(rate, irq);
if (ret)
goto err_per_clk_enable;
return 0;
err_per_clk_enable:
clk_disable_unprepare(ipg);
err_clk_get:
clk_put(per);
clk_put(ipg);
err_iomap:
iounmap(timer_base);
return ret;
}
