static inline void epit_irq_disable(void)
{
u32 val;
val = __raw_readl(timer_base + EPITCR);
val &= ~EPITCR_OCIEN;
__raw_writel(val, timer_base + EPITCR);
}
static inline void epit_irq_enable(void)
{
u32 val;
val = __raw_readl(timer_base + EPITCR);
val |= EPITCR_OCIEN;
__raw_writel(val, timer_base + EPITCR);
}
static void epit_irq_acknowledge(void)
{
__raw_writel(EPITSR_OCIF, timer_base + EPITSR);
}
static int __init epit_clocksource_init(struct clk *timer_clk)
{
unsigned int c = clk_get_rate(timer_clk);
return clocksource_mmio_init(timer_base + EPITCNR, "epit", c, 200, 32,
clocksource_mmio_readl_down);
}
static int epit_set_next_event(unsigned long evt,
struct clock_event_device *unused)
{
unsigned long tcmp;
tcmp = __raw_readl(timer_base + EPITCNR);
__raw_writel(tcmp - evt, timer_base + EPITCMPR);
return 0;
}
static void epit_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
unsigned long flags;
local_irq_save(flags);
epit_irq_disable();
if (mode != clockevent_mode) {
epit_irq_acknowledge();
}
clockevent_mode = mode;
local_irq_restore(flags);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
printk(KERN_ERR "epit_set_mode: Periodic mode is not "
"supported for i.MX EPIT\n");
break;
case CLOCK_EVT_MODE_ONESHOT:
local_irq_save(flags);
epit_irq_enable();
local_irq_restore(flags);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static irqreturn_t epit_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = &clockevent_epit;
epit_irq_acknowledge();
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init epit_clockevent_init(struct clk *timer_clk)
{
unsigned int c = clk_get_rate(timer_clk);
clockevent_epit.mult = div_sc(c, NSEC_PER_SEC,
clockevent_epit.shift);
clockevent_epit.max_delta_ns =
clockevent_delta2ns(0xfffffffe, &clockevent_epit);
clockevent_epit.min_delta_ns =
clockevent_delta2ns(0x800, &clockevent_epit);
clockevent_epit.cpumask = cpumask_of(0);
clockevents_register_device(&clockevent_epit);
return 0;
}
void __init epit_timer_init(struct clk *timer_clk, void __iomem *base, int irq)
{
clk_prepare_enable(timer_clk);
timer_base = base;
__raw_writel(0x0, timer_base + EPITCR);
__raw_writel(0xffffffff, timer_base + EPITLR);
__raw_writel(EPITCR_EN | EPITCR_CLKSRC_REF_HIGH | EPITCR_WAITEN,
timer_base + EPITCR);
epit_clocksource_init(timer_clk);
epit_clockevent_init(timer_clk);
setup_irq(irq, &epit_timer_irq);
}
