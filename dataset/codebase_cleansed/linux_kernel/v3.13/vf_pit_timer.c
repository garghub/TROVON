static inline void pit_timer_enable(void)
{
__raw_writel(PITTCTRL_TEN | PITTCTRL_TIE, clkevt_base + PITTCTRL);
}
static inline void pit_timer_disable(void)
{
__raw_writel(0, clkevt_base + PITTCTRL);
}
static inline void pit_irq_acknowledge(void)
{
__raw_writel(PITTFLG_TIF, clkevt_base + PITTFLG);
}
static u64 pit_read_sched_clock(void)
{
return __raw_readl(clksrc_base + PITCVAL);
}
static int __init pit_clocksource_init(unsigned long rate)
{
__raw_writel(0, clksrc_base + PITTCTRL);
__raw_writel(~0UL, clksrc_base + PITLDVAL);
__raw_writel(PITTCTRL_TEN, clksrc_base + PITTCTRL);
sched_clock_register(pit_read_sched_clock, 32, rate);
return clocksource_mmio_init(clksrc_base + PITCVAL, "vf-pit", rate,
300, 32, clocksource_mmio_readl_down);
}
static int pit_set_next_event(unsigned long delta,
struct clock_event_device *unused)
{
pit_timer_disable();
__raw_writel(delta - 1, clkevt_base + PITLDVAL);
pit_timer_enable();
return 0;
}
static void pit_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
pit_set_next_event(cycle_per_jiffy, evt);
break;
default:
break;
}
}
static irqreturn_t pit_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
pit_irq_acknowledge();
if (likely(evt->mode == CLOCK_EVT_MODE_ONESHOT))
pit_timer_disable();
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init pit_clockevent_init(unsigned long rate, int irq)
{
__raw_writel(0, clkevt_base + PITTCTRL);
__raw_writel(PITTFLG_TIF, clkevt_base + PITTFLG);
BUG_ON(setup_irq(irq, &pit_timer_irq));
clockevent_pit.cpumask = cpumask_of(0);
clockevent_pit.irq = irq;
clockevents_config_and_register(&clockevent_pit, rate, 2, 0xffffffff);
return 0;
}
static void __init pit_timer_init(struct device_node *np)
{
struct clk *pit_clk;
void __iomem *timer_base;
unsigned long clk_rate;
int irq;
timer_base = of_iomap(np, 0);
BUG_ON(!timer_base);
clksrc_base = timer_base + PITn_OFFSET(2);
clkevt_base = timer_base + PITn_OFFSET(3);
irq = irq_of_parse_and_map(np, 0);
BUG_ON(irq <= 0);
pit_clk = of_clk_get(np, 0);
BUG_ON(IS_ERR(pit_clk));
BUG_ON(clk_prepare_enable(pit_clk));
clk_rate = clk_get_rate(pit_clk);
cycle_per_jiffy = clk_rate / (HZ);
__raw_writel(~PITMCR_MDIS, timer_base + PITMCR);
BUG_ON(pit_clocksource_init(clk_rate));
pit_clockevent_init(clk_rate, irq);
}
