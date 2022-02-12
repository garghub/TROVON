static int moxart_shutdown(struct clock_event_device *evt)
{
writel(TIMER1_DISABLE, base + TIMER_CR);
return 0;
}
static int moxart_set_oneshot(struct clock_event_device *evt)
{
writel(TIMER1_DISABLE, base + TIMER_CR);
writel(~0, base + TIMER1_BASE + REG_LOAD);
return 0;
}
static int moxart_set_periodic(struct clock_event_device *evt)
{
writel(clock_count_per_tick, base + TIMER1_BASE + REG_LOAD);
writel(TIMER1_ENABLE, base + TIMER_CR);
return 0;
}
static int moxart_clkevt_next_event(unsigned long cycles,
struct clock_event_device *unused)
{
u32 u;
writel(TIMER1_DISABLE, base + TIMER_CR);
u = readl(base + TIMER1_BASE + REG_COUNT) - cycles;
writel(u, base + TIMER1_BASE + REG_MATCH1);
writel(TIMER1_ENABLE, base + TIMER_CR);
return 0;
}
static irqreturn_t moxart_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init moxart_timer_init(struct device_node *node)
{
int ret, irq;
unsigned long pclk;
struct clk *clk;
base = of_iomap(node, 0);
if (!base) {
pr_err("%s: of_iomap failed\n", node->full_name);
return -ENXIO;
}
irq = irq_of_parse_and_map(node, 0);
if (irq <= 0) {
pr_err("%s: irq_of_parse_and_map failed\n", node->full_name);
return -EINVAL;
}
ret = setup_irq(irq, &moxart_timer_irq);
if (ret) {
pr_err("%s: setup_irq failed\n", node->full_name);
return ret;
}
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_err("%s: of_clk_get failed\n", node->full_name);
return PTR_ERR(clk);
}
pclk = clk_get_rate(clk);
ret = clocksource_mmio_init(base + TIMER2_BASE + REG_COUNT,
"moxart_timer", pclk, 200, 32,
clocksource_mmio_readl_down);
if (ret) {
pr_err("%s: clocksource_mmio_init failed\n", node->full_name);
return ret;
}
clock_count_per_tick = DIV_ROUND_CLOSEST(pclk, HZ);
writel(~0, base + TIMER2_BASE + REG_LOAD);
writel(TIMEREG_CR_2_ENABLE, base + TIMER_CR);
moxart_clockevent.cpumask = cpumask_of(0);
moxart_clockevent.irq = irq;
clockevents_config_and_register(&moxart_clockevent, pclk,
0x4, 0xfffffffe);
return 0;
}
