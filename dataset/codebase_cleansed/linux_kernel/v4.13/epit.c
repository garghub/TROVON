static inline void epit_irq_disable(void)
{
u32 val;
val = imx_readl(timer_base + EPITCR);
val &= ~EPITCR_OCIEN;
imx_writel(val, timer_base + EPITCR);
}
static inline void epit_irq_enable(void)
{
u32 val;
val = imx_readl(timer_base + EPITCR);
val |= EPITCR_OCIEN;
imx_writel(val, timer_base + EPITCR);
}
static void epit_irq_acknowledge(void)
{
imx_writel(EPITSR_OCIF, timer_base + EPITSR);
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
tcmp = imx_readl(timer_base + EPITCNR);
imx_writel(tcmp - evt, timer_base + EPITCMPR);
return 0;
}
static int epit_shutdown(struct clock_event_device *evt)
{
unsigned long flags;
local_irq_save(flags);
epit_irq_disable();
epit_irq_acknowledge();
local_irq_restore(flags);
return 0;
}
static int epit_set_oneshot(struct clock_event_device *evt)
{
unsigned long flags;
local_irq_save(flags);
epit_irq_disable();
if (!clockevent_state_oneshot(evt))
epit_irq_acknowledge();
epit_irq_enable();
local_irq_restore(flags);
return 0;
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
clockevent_epit.cpumask = cpumask_of(0);
clockevents_config_and_register(&clockevent_epit,
clk_get_rate(timer_clk),
0x800, 0xfffffffe);
return 0;
}
void __init epit_timer_init(void __iomem *base, int irq)
{
struct clk *timer_clk;
timer_clk = clk_get_sys("imx-epit.0", NULL);
if (IS_ERR(timer_clk)) {
pr_err("i.MX epit: unable to get clk\n");
return;
}
clk_prepare_enable(timer_clk);
timer_base = base;
imx_writel(0x0, timer_base + EPITCR);
imx_writel(0xffffffff, timer_base + EPITLR);
imx_writel(EPITCR_EN | EPITCR_CLKSRC_REF_HIGH | EPITCR_WAITEN,
timer_base + EPITCR);
epit_clocksource_init(timer_clk);
epit_clockevent_init(timer_clk);
setup_irq(irq, &epit_timer_irq);
}
