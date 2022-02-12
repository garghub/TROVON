static void nuc900_clockevent_setmode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
unsigned int val;
val = __raw_readl(REG_TCSR0);
val &= ~(0x03 << 27);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
__raw_writel(timer0_load, REG_TICR0);
val |= (PERIOD | COUNTEN | INTEN | PRESCALE);
break;
case CLOCK_EVT_MODE_ONESHOT:
val |= (ONESHOT | COUNTEN | INTEN | PRESCALE);
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_RESUME:
break;
}
__raw_writel(val, REG_TCSR0);
}
static int nuc900_clockevent_setnextevent(unsigned long evt,
struct clock_event_device *clk)
{
unsigned int val;
__raw_writel(evt, REG_TICR0);
val = __raw_readl(REG_TCSR0);
val |= (COUNTEN | INTEN | PRESCALE);
__raw_writel(val, REG_TCSR0);
return 0;
}
static irqreturn_t nuc900_timer0_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = &nuc900_clockevent_device;
__raw_writel(0x01, REG_TISR);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init nuc900_clockevents_init(void)
{
unsigned int rate;
struct clk *clk = clk_get(NULL, "timer0");
BUG_ON(IS_ERR(clk));
__raw_writel(0x00, REG_TCSR0);
clk_enable(clk);
rate = clk_get_rate(clk) / (PRESCALE + 1);
timer0_load = (rate / TICKS_PER_SEC);
__raw_writel(RESETINT, REG_TISR);
setup_irq(IRQ_TIMER0, &nuc900_timer0_irq);
nuc900_clockevent_device.cpumask = cpumask_of(0);
clockevents_config_and_register(&nuc900_clockevent_device, rate,
0xf, 0xffffffff);
}
static void __init nuc900_clocksource_init(void)
{
unsigned int val;
unsigned int rate;
struct clk *clk = clk_get(NULL, "timer1");
BUG_ON(IS_ERR(clk));
__raw_writel(0x00, REG_TCSR1);
clk_enable(clk);
rate = clk_get_rate(clk) / (PRESCALE + 1);
__raw_writel(0xffffffff, REG_TICR1);
val = __raw_readl(REG_TCSR1);
val |= (COUNTEN | PERIOD | PRESCALE);
__raw_writel(val, REG_TCSR1);
clocksource_mmio_init(REG_TDR1, "nuc900-timer1", rate, 200,
TDR_SHIFT, clocksource_mmio_readl_down);
}
void __init nuc900_timer_init(void)
{
nuc900_clocksource_init();
nuc900_clockevents_init();
}
