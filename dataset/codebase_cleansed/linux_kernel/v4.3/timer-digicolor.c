struct digicolor_timer *dc_timer(struct clock_event_device *ce)
{
return container_of(ce, struct digicolor_timer, ce);
}
static inline void dc_timer_disable(struct clock_event_device *ce)
{
struct digicolor_timer *dt = dc_timer(ce);
writeb(CONTROL_DISABLE, dt->base + CONTROL(dt->timer_id));
}
static inline void dc_timer_enable(struct clock_event_device *ce, u32 mode)
{
struct digicolor_timer *dt = dc_timer(ce);
writeb(CONTROL_ENABLE | mode, dt->base + CONTROL(dt->timer_id));
}
static inline void dc_timer_set_count(struct clock_event_device *ce,
unsigned long count)
{
struct digicolor_timer *dt = dc_timer(ce);
writel(count, dt->base + COUNT(dt->timer_id));
}
static int digicolor_clkevt_shutdown(struct clock_event_device *ce)
{
dc_timer_disable(ce);
return 0;
}
static int digicolor_clkevt_set_oneshot(struct clock_event_device *ce)
{
dc_timer_disable(ce);
dc_timer_enable(ce, CONTROL_MODE_ONESHOT);
return 0;
}
static int digicolor_clkevt_set_periodic(struct clock_event_device *ce)
{
struct digicolor_timer *dt = dc_timer(ce);
dc_timer_disable(ce);
dc_timer_set_count(ce, dt->ticks_per_jiffy);
dc_timer_enable(ce, CONTROL_MODE_PERIODIC);
return 0;
}
static int digicolor_clkevt_next_event(unsigned long evt,
struct clock_event_device *ce)
{
dc_timer_disable(ce);
dc_timer_set_count(ce, evt);
dc_timer_enable(ce, CONTROL_MODE_ONESHOT);
return 0;
}
static irqreturn_t digicolor_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static u64 notrace digicolor_timer_sched_read(void)
{
return ~readl(dc_timer_dev.base + COUNT(TIMER_B));
}
static void __init digicolor_timer_init(struct device_node *node)
{
unsigned long rate;
struct clk *clk;
int ret, irq;
dc_timer_dev.base = of_iomap(node, 0);
if (!dc_timer_dev.base) {
pr_err("Can't map registers");
return;
}
irq = irq_of_parse_and_map(node, dc_timer_dev.timer_id);
if (irq <= 0) {
pr_err("Can't parse IRQ");
return;
}
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_err("Can't get timer clock");
return;
}
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
dc_timer_dev.ticks_per_jiffy = DIV_ROUND_UP(rate, HZ);
writeb(CONTROL_DISABLE, dc_timer_dev.base + CONTROL(TIMER_B));
writel(UINT_MAX, dc_timer_dev.base + COUNT(TIMER_B));
writeb(CONTROL_ENABLE, dc_timer_dev.base + CONTROL(TIMER_B));
sched_clock_register(digicolor_timer_sched_read, 32, rate);
clocksource_mmio_init(dc_timer_dev.base + COUNT(TIMER_B), node->name,
rate, 340, 32, clocksource_mmio_readl_down);
ret = request_irq(irq, digicolor_timer_interrupt,
IRQF_TIMER | IRQF_IRQPOLL, "digicolor_timerC",
&dc_timer_dev.ce);
if (ret)
pr_warn("request of timer irq %d failed (%d)\n", irq, ret);
dc_timer_dev.ce.cpumask = cpu_possible_mask;
dc_timer_dev.ce.irq = irq;
clockevents_config_and_register(&dc_timer_dev.ce, rate, 0, 0xffffffff);
}
