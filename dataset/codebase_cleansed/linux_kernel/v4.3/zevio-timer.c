static int zevio_timer_set_event(unsigned long delta,
struct clock_event_device *dev)
{
struct zevio_timer *timer = container_of(dev, struct zevio_timer,
clkevt);
writel(delta, timer->timer1 + IO_CURRENT_VAL);
writel(CNTL_RUN_TIMER | CNTL_DEC | CNTL_MATCH(TIMER_MATCH),
timer->timer1 + IO_CONTROL);
return 0;
}
static int zevio_timer_shutdown(struct clock_event_device *dev)
{
struct zevio_timer *timer = container_of(dev, struct zevio_timer,
clkevt);
writel(0, timer->interrupt_regs + IO_INTR_MSK);
writel(TIMER_INTR_ALL, timer->interrupt_regs + IO_INTR_ACK);
writel(CNTL_STOP_TIMER, timer->timer1 + IO_CONTROL);
return 0;
}
static int zevio_timer_set_oneshot(struct clock_event_device *dev)
{
struct zevio_timer *timer = container_of(dev, struct zevio_timer,
clkevt);
writel(TIMER_INTR_MSK, timer->interrupt_regs + IO_INTR_MSK);
writel(TIMER_INTR_ALL, timer->interrupt_regs + IO_INTR_ACK);
return 0;
}
static irqreturn_t zevio_timer_interrupt(int irq, void *dev_id)
{
struct zevio_timer *timer = dev_id;
u32 intr;
intr = readl(timer->interrupt_regs + IO_INTR_ACK);
if (!(intr & TIMER_INTR_MSK))
return IRQ_NONE;
writel(TIMER_INTR_MSK, timer->interrupt_regs + IO_INTR_ACK);
writel(CNTL_STOP_TIMER, timer->timer1 + IO_CONTROL);
if (timer->clkevt.event_handler)
timer->clkevt.event_handler(&timer->clkevt);
return IRQ_HANDLED;
}
static int __init zevio_timer_add(struct device_node *node)
{
struct zevio_timer *timer;
struct resource res;
int irqnr, ret;
timer = kzalloc(sizeof(*timer), GFP_KERNEL);
if (!timer)
return -ENOMEM;
timer->base = of_iomap(node, 0);
if (!timer->base) {
ret = -EINVAL;
goto error_free;
}
timer->timer1 = timer->base + IO_TIMER1;
timer->timer2 = timer->base + IO_TIMER2;
timer->clk = of_clk_get(node, 0);
if (IS_ERR(timer->clk)) {
ret = PTR_ERR(timer->clk);
pr_err("Timer clock not found! (error %d)\n", ret);
goto error_unmap;
}
timer->interrupt_regs = of_iomap(node, 1);
irqnr = irq_of_parse_and_map(node, 0);
of_address_to_resource(node, 0, &res);
scnprintf(timer->clocksource_name, sizeof(timer->clocksource_name),
"%llx.%s_clocksource",
(unsigned long long)res.start, node->name);
scnprintf(timer->clockevent_name, sizeof(timer->clockevent_name),
"%llx.%s_clockevent",
(unsigned long long)res.start, node->name);
if (timer->interrupt_regs && irqnr) {
timer->clkevt.name = timer->clockevent_name;
timer->clkevt.set_next_event = zevio_timer_set_event;
timer->clkevt.set_state_shutdown = zevio_timer_shutdown;
timer->clkevt.set_state_oneshot = zevio_timer_set_oneshot;
timer->clkevt.tick_resume = zevio_timer_set_oneshot;
timer->clkevt.rating = 200;
timer->clkevt.cpumask = cpu_all_mask;
timer->clkevt.features = CLOCK_EVT_FEAT_ONESHOT;
timer->clkevt.irq = irqnr;
writel(CNTL_STOP_TIMER, timer->timer1 + IO_CONTROL);
writel(0, timer->timer1 + IO_DIVIDER);
writel(0, timer->interrupt_regs + IO_INTR_MSK);
writel(TIMER_INTR_ALL, timer->interrupt_regs + IO_INTR_ACK);
writel(0, timer->base + IO_MATCH(TIMER_MATCH));
timer->clkevt_irq.name = timer->clockevent_name;
timer->clkevt_irq.handler = zevio_timer_interrupt;
timer->clkevt_irq.dev_id = timer;
timer->clkevt_irq.flags = IRQF_TIMER | IRQF_IRQPOLL;
setup_irq(irqnr, &timer->clkevt_irq);
clockevents_config_and_register(&timer->clkevt,
clk_get_rate(timer->clk), 0x0001, 0xffff);
pr_info("Added %s as clockevent\n", timer->clockevent_name);
}
writel(CNTL_STOP_TIMER, timer->timer2 + IO_CONTROL);
writel(0, timer->timer2 + IO_CURRENT_VAL);
writel(0, timer->timer2 + IO_DIVIDER);
writel(CNTL_RUN_TIMER | CNTL_FOREVER | CNTL_INC,
timer->timer2 + IO_CONTROL);
clocksource_mmio_init(timer->timer2 + IO_CURRENT_VAL,
timer->clocksource_name,
clk_get_rate(timer->clk),
200, 16,
clocksource_mmio_readw_up);
pr_info("Added %s as clocksource\n", timer->clocksource_name);
return 0;
error_unmap:
iounmap(timer->base);
error_free:
kfree(timer);
return ret;
}
static void __init zevio_timer_init(struct device_node *node)
{
BUG_ON(zevio_timer_add(node));
}
