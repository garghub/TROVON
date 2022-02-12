static int asm9260_timer_set_next_event(unsigned long delta,
struct clock_event_device *evt)
{
writel_relaxed(delta, priv.base + HW_MR0);
writel_relaxed(BM_C0_EN, priv.base + HW_TCR + SET_REG);
return 0;
}
static inline void __asm9260_timer_shutdown(struct clock_event_device *evt)
{
writel_relaxed(BM_C0_EN, priv.base + HW_TCR + CLR_REG);
}
static int asm9260_timer_shutdown(struct clock_event_device *evt)
{
__asm9260_timer_shutdown(evt);
return 0;
}
static int asm9260_timer_set_oneshot(struct clock_event_device *evt)
{
__asm9260_timer_shutdown(evt);
writel_relaxed(BM_MCR_RES_EN(0) | BM_MCR_STOP_EN(0),
priv.base + HW_MCR + SET_REG);
return 0;
}
static int asm9260_timer_set_periodic(struct clock_event_device *evt)
{
__asm9260_timer_shutdown(evt);
writel_relaxed(BM_MCR_RES_EN(0) | BM_MCR_STOP_EN(0),
priv.base + HW_MCR + CLR_REG);
writel_relaxed(priv.ticks_per_jiffy, priv.base + HW_MR0);
writel_relaxed(BM_C0_EN, priv.base + HW_TCR + SET_REG);
return 0;
}
static irqreturn_t asm9260_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
evt->event_handler(evt);
writel_relaxed(BM_IR_MR0, priv.base + HW_IR);
return IRQ_HANDLED;
}
static int __init asm9260_timer_init(struct device_node *np)
{
int irq;
struct clk *clk;
int ret;
unsigned long rate;
priv.base = of_io_request_and_map(np, 0, np->name);
if (IS_ERR(priv.base)) {
pr_err("%s: unable to map resource\n", np->name);
return PTR_ERR(priv.base);
}
clk = of_clk_get(np, 0);
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("Failed to enable clk!\n");
return ret;
}
irq = irq_of_parse_and_map(np, 0);
ret = request_irq(irq, asm9260_timer_interrupt, IRQF_TIMER,
DRIVER_NAME, &event_dev);
if (ret) {
pr_err("Failed to setup irq!\n");
return ret;
}
writel_relaxed(BM_DIR_DEFAULT, priv.base + HW_DIR);
writel_relaxed(BM_PR_DISABLE, priv.base + HW_PR);
writel_relaxed(BM_CTCR_DEFAULT, priv.base + HW_CTCR);
writel_relaxed(BM_MCR_INT_EN(0) , priv.base + HW_MCR);
rate = clk_get_rate(clk);
clocksource_mmio_init(priv.base + HW_TC1, DRIVER_NAME, rate,
200, 32, clocksource_mmio_readl_up);
writel_relaxed(0xffffffff, priv.base + HW_MR1);
writel_relaxed(BM_C1_EN, priv.base + HW_TCR + SET_REG);
priv.ticks_per_jiffy = DIV_ROUND_CLOSEST(rate, HZ);
event_dev.cpumask = cpumask_of(0);
clockevents_config_and_register(&event_dev, rate, 0x2c00, 0xfffffffe);
return 0;
}
