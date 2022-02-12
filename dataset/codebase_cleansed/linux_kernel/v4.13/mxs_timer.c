static inline void timrot_irq_disable(void)
{
__raw_writel(BM_TIMROT_TIMCTRLn_IRQ_EN, mxs_timrot_base +
HW_TIMROT_TIMCTRLn(0) + STMP_OFFSET_REG_CLR);
}
static inline void timrot_irq_enable(void)
{
__raw_writel(BM_TIMROT_TIMCTRLn_IRQ_EN, mxs_timrot_base +
HW_TIMROT_TIMCTRLn(0) + STMP_OFFSET_REG_SET);
}
static void timrot_irq_acknowledge(void)
{
__raw_writel(BM_TIMROT_TIMCTRLn_IRQ, mxs_timrot_base +
HW_TIMROT_TIMCTRLn(0) + STMP_OFFSET_REG_CLR);
}
static u64 timrotv1_get_cycles(struct clocksource *cs)
{
return ~((__raw_readl(mxs_timrot_base + HW_TIMROT_TIMCOUNTn(1))
& 0xffff0000) >> 16);
}
static int timrotv1_set_next_event(unsigned long evt,
struct clock_event_device *dev)
{
__raw_writel(evt, mxs_timrot_base + HW_TIMROT_TIMCOUNTn(0));
return 0;
}
static int timrotv2_set_next_event(unsigned long evt,
struct clock_event_device *dev)
{
__raw_writel(evt, mxs_timrot_base + HW_TIMROT_FIXED_COUNTn(0));
return 0;
}
static irqreturn_t mxs_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
timrot_irq_acknowledge();
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void mxs_irq_clear(char *state)
{
timrot_irq_disable();
if (timrot_is_v1())
__raw_writel(0xffff, mxs_timrot_base + HW_TIMROT_TIMCOUNTn(1));
else
__raw_writel(0xffffffff,
mxs_timrot_base + HW_TIMROT_FIXED_COUNTn(1));
timrot_irq_acknowledge();
#ifdef DEBUG
pr_info("%s: changing mode to %s\n", __func__, state)
#endif
}
static int mxs_shutdown(struct clock_event_device *evt)
{
mxs_irq_clear("shutdown");
return 0;
}
static int mxs_set_oneshot(struct clock_event_device *evt)
{
if (clockevent_state_oneshot(evt))
mxs_irq_clear("oneshot");
timrot_irq_enable();
return 0;
}
static int __init mxs_clockevent_init(struct clk *timer_clk)
{
if (timrot_is_v1())
mxs_clockevent_device.set_next_event = timrotv1_set_next_event;
mxs_clockevent_device.cpumask = cpumask_of(0);
clockevents_config_and_register(&mxs_clockevent_device,
clk_get_rate(timer_clk),
timrot_is_v1() ? 0xf : 0x2,
timrot_is_v1() ? 0xfffe : 0xfffffffe);
return 0;
}
static u64 notrace mxs_read_sched_clock_v2(void)
{
return ~readl_relaxed(mxs_timrot_base + HW_TIMROT_RUNNING_COUNTn(1));
}
static int __init mxs_clocksource_init(struct clk *timer_clk)
{
unsigned int c = clk_get_rate(timer_clk);
if (timrot_is_v1())
clocksource_register_hz(&clocksource_mxs, c);
else {
clocksource_mmio_init(mxs_timrot_base + HW_TIMROT_RUNNING_COUNTn(1),
"mxs_timer", c, 200, 32, clocksource_mmio_readl_down);
sched_clock_register(mxs_read_sched_clock_v2, 32, c);
}
return 0;
}
static int __init mxs_timer_init(struct device_node *np)
{
struct clk *timer_clk;
int irq, ret;
mxs_timrot_base = of_iomap(np, 0);
WARN_ON(!mxs_timrot_base);
timer_clk = of_clk_get(np, 0);
if (IS_ERR(timer_clk)) {
pr_err("%s: failed to get clk\n", __func__);
return PTR_ERR(timer_clk);
}
ret = clk_prepare_enable(timer_clk);
if (ret)
return ret;
stmp_reset_block(mxs_timrot_base + HW_TIMROT_ROTCTRL);
timrot_major_version = __raw_readl(mxs_timrot_base +
(of_device_is_compatible(np, "fsl,imx23-timrot") ?
MX23_TIMROT_VERSION_OFFSET :
MX28_TIMROT_VERSION_OFFSET));
timrot_major_version >>= BP_TIMROT_MAJOR_VERSION;
__raw_writel((timrot_is_v1() ?
BV_TIMROTv1_TIMCTRLn_SELECT__32KHZ_XTAL :
BV_TIMROTv2_TIMCTRLn_SELECT__TICK_ALWAYS) |
BM_TIMROT_TIMCTRLn_UPDATE |
BM_TIMROT_TIMCTRLn_IRQ_EN,
mxs_timrot_base + HW_TIMROT_TIMCTRLn(0));
__raw_writel((timrot_is_v1() ?
BV_TIMROTv1_TIMCTRLn_SELECT__32KHZ_XTAL :
BV_TIMROTv2_TIMCTRLn_SELECT__TICK_ALWAYS) |
BM_TIMROT_TIMCTRLn_RELOAD,
mxs_timrot_base + HW_TIMROT_TIMCTRLn(1));
if (timrot_is_v1())
__raw_writel(0xffff,
mxs_timrot_base + HW_TIMROT_TIMCOUNTn(1));
else
__raw_writel(0xffffffff,
mxs_timrot_base + HW_TIMROT_FIXED_COUNTn(1));
ret = mxs_clocksource_init(timer_clk);
if (ret)
return ret;
ret = mxs_clockevent_init(timer_clk);
if (ret)
return ret;
irq = irq_of_parse_and_map(np, 0);
if (irq <= 0)
return -EINVAL;
return setup_irq(irq, &mxs_timer_irq);
}
