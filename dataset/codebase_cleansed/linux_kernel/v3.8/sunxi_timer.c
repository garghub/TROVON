static void sunxi_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
u32 u = readl(timer_base + TIMER0_CTL_REG);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
u &= ~(TIMER0_CTL_ONESHOT);
writel(u | TIMER0_CTL_ENABLE, timer_base + TIMER0_CTL_REG);
break;
case CLOCK_EVT_MODE_ONESHOT:
writel(u | TIMER0_CTL_ONESHOT, timer_base + TIMER0_CTL_REG);
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
default:
writel(u & ~(TIMER0_CTL_ENABLE), timer_base + TIMER0_CTL_REG);
break;
}
}
static int sunxi_clkevt_next_event(unsigned long evt,
struct clock_event_device *unused)
{
u32 u = readl(timer_base + TIMER0_CTL_REG);
writel(evt, timer_base + TIMER0_CNTVAL_REG);
writel(u | TIMER0_CTL_ENABLE | TIMER0_CTL_AUTORELOAD,
timer_base + TIMER0_CTL_REG);
return 0;
}
static irqreturn_t sunxi_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = (struct clock_event_device *)dev_id;
writel(0x1, timer_base + TIMER_IRQ_ST_REG);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init sunxi_timer_init(void)
{
struct device_node *node;
unsigned long rate = 0;
struct clk *clk;
int ret, irq;
u32 val;
node = of_find_matching_node(NULL, sunxi_timer_dt_ids);
if (!node)
panic("No sunxi timer node");
timer_base = of_iomap(node, 0);
if (!timer_base)
panic("Can't map registers");
irq = irq_of_parse_and_map(node, 0);
if (irq <= 0)
panic("Can't parse IRQ");
sunxi_init_clocks();
clk = of_clk_get(node, 0);
if (IS_ERR(clk))
panic("Can't get timer clock");
rate = clk_get_rate(clk);
writel(rate / (TIMER_SCAL * HZ),
timer_base + TIMER0_INTVAL_REG);
val = readl(timer_base + TIMER0_CTL_REG);
val &= ~(0x07 << 4);
val &= ~(0x03 << 2);
val |= (4 << 4) | (1 << 2);
writel(val, timer_base + TIMER0_CTL_REG);
val = readl(timer_base + TIMER0_CTL_REG);
writel(val | TIMER0_CTL_AUTORELOAD, timer_base + TIMER0_CTL_REG);
ret = setup_irq(irq, &sunxi_timer_irq);
if (ret)
pr_warn("failed to setup irq %d\n", irq);
val = readl(timer_base + TIMER_CTL_REG);
writel(val | TIMER_CTL_ENABLE, timer_base + TIMER_CTL_REG);
sunxi_clockevent.mult = div_sc(rate / TIMER_SCAL,
NSEC_PER_SEC,
sunxi_clockevent.shift);
sunxi_clockevent.max_delta_ns = clockevent_delta2ns(0xff,
&sunxi_clockevent);
sunxi_clockevent.min_delta_ns = clockevent_delta2ns(0x1,
&sunxi_clockevent);
sunxi_clockevent.cpumask = cpumask_of(0);
clockevents_register_device(&sunxi_clockevent);
}
