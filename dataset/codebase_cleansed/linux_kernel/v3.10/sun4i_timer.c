static void sun4i_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
u32 u = readl(timer_base + TIMER_CTL_REG(0));
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
u &= ~(TIMER_CTL_ONESHOT);
writel(u | TIMER_CTL_ENABLE, timer_base + TIMER_CTL_REG(0));
break;
case CLOCK_EVT_MODE_ONESHOT:
writel(u | TIMER_CTL_ONESHOT, timer_base + TIMER_CTL_REG(0));
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
default:
writel(u & ~(TIMER_CTL_ENABLE), timer_base + TIMER_CTL_REG(0));
break;
}
}
static int sun4i_clkevt_next_event(unsigned long evt,
struct clock_event_device *unused)
{
u32 u = readl(timer_base + TIMER_CTL_REG(0));
writel(evt, timer_base + TIMER_CNTVAL_REG(0));
writel(u | TIMER_CTL_ENABLE | TIMER_CTL_AUTORELOAD,
timer_base + TIMER_CTL_REG(0));
return 0;
}
static irqreturn_t sun4i_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = (struct clock_event_device *)dev_id;
writel(0x1, timer_base + TIMER_IRQ_ST_REG);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init sun4i_timer_init(struct device_node *node)
{
unsigned long rate = 0;
struct clk *clk;
int ret, irq;
u32 val;
timer_base = of_iomap(node, 0);
if (!timer_base)
panic("Can't map registers");
irq = irq_of_parse_and_map(node, 0);
if (irq <= 0)
panic("Can't parse IRQ");
clk = of_clk_get(node, 0);
if (IS_ERR(clk))
panic("Can't get timer clock");
rate = clk_get_rate(clk);
writel(rate / (TIMER_SCAL * HZ),
timer_base + TIMER_INTVAL_REG(0));
val = readl(timer_base + TIMER_CTL_REG(0));
val &= ~(0x07 << 4);
val &= ~(0x03 << 2);
val |= (4 << 4) | (1 << 2);
writel(val, timer_base + TIMER_CTL_REG(0));
val = readl(timer_base + TIMER_CTL_REG(0));
writel(val | TIMER_CTL_AUTORELOAD, timer_base + TIMER_CTL_REG(0));
ret = setup_irq(irq, &sun4i_timer_irq);
if (ret)
pr_warn("failed to setup irq %d\n", irq);
val = readl(timer_base + TIMER_IRQ_EN_REG);
writel(val | TIMER_IRQ_EN(0), timer_base + TIMER_IRQ_EN_REG);
sun4i_clockevent.cpumask = cpumask_of(0);
clockevents_config_and_register(&sun4i_clockevent, rate / TIMER_SCAL,
0x1, 0xff);
}
