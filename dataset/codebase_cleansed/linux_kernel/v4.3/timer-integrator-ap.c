static u64 notrace integrator_read_sched_clock(void)
{
return -readl(sched_clk_base + TIMER_VALUE);
}
static void integrator_clocksource_init(unsigned long inrate,
void __iomem *base)
{
u32 ctrl = TIMER_CTRL_ENABLE | TIMER_CTRL_PERIODIC;
unsigned long rate = inrate;
if (rate >= 1500000) {
rate /= 16;
ctrl |= TIMER_CTRL_DIV16;
}
writel(0xffff, base + TIMER_LOAD);
writel(ctrl, base + TIMER_CTRL);
clocksource_mmio_init(base + TIMER_VALUE, "timer2",
rate, 200, 16, clocksource_mmio_readl_down);
sched_clk_base = base;
sched_clock_register(integrator_read_sched_clock, 16, rate);
}
static irqreturn_t integrator_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
writel(1, clkevt_base + TIMER_INTCLR);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int clkevt_shutdown(struct clock_event_device *evt)
{
u32 ctrl = readl(clkevt_base + TIMER_CTRL) & ~TIMER_CTRL_ENABLE;
writel(ctrl, clkevt_base + TIMER_CTRL);
return 0;
}
static int clkevt_set_oneshot(struct clock_event_device *evt)
{
u32 ctrl = readl(clkevt_base + TIMER_CTRL) &
~(TIMER_CTRL_ENABLE | TIMER_CTRL_PERIODIC);
writel(ctrl, clkevt_base + TIMER_CTRL);
return 0;
}
static int clkevt_set_periodic(struct clock_event_device *evt)
{
u32 ctrl = readl(clkevt_base + TIMER_CTRL) & ~TIMER_CTRL_ENABLE;
writel(ctrl, clkevt_base + TIMER_CTRL);
writel(timer_reload, clkevt_base + TIMER_LOAD);
ctrl |= TIMER_CTRL_PERIODIC | TIMER_CTRL_ENABLE;
writel(ctrl, clkevt_base + TIMER_CTRL);
return 0;
}
static int clkevt_set_next_event(unsigned long next, struct clock_event_device *evt)
{
unsigned long ctrl = readl(clkevt_base + TIMER_CTRL);
writel(ctrl & ~TIMER_CTRL_ENABLE, clkevt_base + TIMER_CTRL);
writel(next, clkevt_base + TIMER_LOAD);
writel(ctrl | TIMER_CTRL_ENABLE, clkevt_base + TIMER_CTRL);
return 0;
}
static void integrator_clockevent_init(unsigned long inrate,
void __iomem *base, int irq)
{
unsigned long rate = inrate;
unsigned int ctrl = 0;
clkevt_base = base;
if (rate > 0x100000 * HZ) {
rate /= 256;
ctrl |= TIMER_CTRL_DIV256;
} else if (rate > 0x10000 * HZ) {
rate /= 16;
ctrl |= TIMER_CTRL_DIV16;
}
timer_reload = rate / HZ;
writel(ctrl, clkevt_base + TIMER_CTRL);
setup_irq(irq, &integrator_timer_irq);
clockevents_config_and_register(&integrator_clockevent,
rate,
1,
0xffffU);
}
static void __init integrator_ap_timer_init_of(struct device_node *node)
{
const char *path;
void __iomem *base;
int err;
int irq;
struct clk *clk;
unsigned long rate;
struct device_node *pri_node;
struct device_node *sec_node;
base = of_io_request_and_map(node, 0, "integrator-timer");
if (IS_ERR(base))
return;
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_err("No clock for %s\n", node->name);
return;
}
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
writel(0, base + TIMER_CTRL);
err = of_property_read_string(of_aliases,
"arm,timer-primary", &path);
if (WARN_ON(err))
return;
pri_node = of_find_node_by_path(path);
err = of_property_read_string(of_aliases,
"arm,timer-secondary", &path);
if (WARN_ON(err))
return;
sec_node = of_find_node_by_path(path);
if (node == pri_node) {
integrator_clocksource_init(rate, base);
return;
}
if (node == sec_node) {
irq = irq_of_parse_and_map(node, 0);
integrator_clockevent_init(rate, base, irq);
return;
}
pr_info("Timer @%p unused\n", base);
clk_disable_unprepare(clk);
}
