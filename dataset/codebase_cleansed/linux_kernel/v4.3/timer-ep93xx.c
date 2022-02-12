static u64 notrace ep93xx_read_sched_clock(void)
{
u64 ret;
ret = readl(EP93XX_TIMER4_VALUE_LOW);
ret |= ((u64) (readl(EP93XX_TIMER4_VALUE_HIGH) & 0xff) << 32);
return ret;
}
cycle_t ep93xx_clocksource_read(struct clocksource *c)
{
u64 ret;
ret = readl(EP93XX_TIMER4_VALUE_LOW);
ret |= ((u64) (readl(EP93XX_TIMER4_VALUE_HIGH) & 0xff) << 32);
return (cycle_t) ret;
}
static int ep93xx_clkevt_set_next_event(unsigned long next,
struct clock_event_device *evt)
{
u32 tmode = EP93XX_TIMER123_CONTROL_MODE |
EP93XX_TIMER123_CONTROL_CLKSEL;
writel(tmode, EP93XX_TIMER3_CONTROL);
writel(next, EP93XX_TIMER3_LOAD);
writel(tmode | EP93XX_TIMER123_CONTROL_ENABLE,
EP93XX_TIMER3_CONTROL);
return 0;
}
static int ep93xx_clkevt_shutdown(struct clock_event_device *evt)
{
writel(0, EP93XX_TIMER3_CONTROL);
return 0;
}
static irqreturn_t ep93xx_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
writel(1, EP93XX_TIMER3_CLEAR);
evt->event_handler(evt);
return IRQ_HANDLED;
}
void __init ep93xx_timer_init(void)
{
writel(EP93XX_TIMER4_VALUE_HIGH_ENABLE,
EP93XX_TIMER4_VALUE_HIGH);
clocksource_mmio_init(NULL, "timer4",
EP93XX_TIMER4_RATE, 200, 40,
ep93xx_clocksource_read);
sched_clock_register(ep93xx_read_sched_clock, 40,
EP93XX_TIMER4_RATE);
setup_irq(IRQ_EP93XX_TIMER3, &ep93xx_timer_irq);
clockevents_config_and_register(&ep93xx_clockevent,
EP93XX_TIMER123_RATE,
1,
0xffffffffU);
}
