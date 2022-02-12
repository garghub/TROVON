static u64 notrace meson6_timer_sched_read(void)
{
return (u64)readl(timer_base + TIMER_ISA_VAL(CSD_ID));
}
static void meson6_clkevt_time_stop(unsigned char timer)
{
u32 val = readl(timer_base + TIMER_ISA_MUX);
writel(val & ~TIMER_ENABLE_BIT(timer), timer_base + TIMER_ISA_MUX);
}
static void meson6_clkevt_time_setup(unsigned char timer, unsigned long delay)
{
writel(delay, timer_base + TIMER_ISA_VAL(timer));
}
static void meson6_clkevt_time_start(unsigned char timer, bool periodic)
{
u32 val = readl(timer_base + TIMER_ISA_MUX);
if (periodic)
val |= TIMER_PERIODIC_BIT(timer);
else
val &= ~TIMER_PERIODIC_BIT(timer);
writel(val | TIMER_ENABLE_BIT(timer), timer_base + TIMER_ISA_MUX);
}
static void meson6_clkevt_mode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
meson6_clkevt_time_stop(CED_ID);
meson6_clkevt_time_setup(CED_ID, USEC_PER_SEC/HZ - 1);
meson6_clkevt_time_start(CED_ID, true);
break;
case CLOCK_EVT_MODE_ONESHOT:
meson6_clkevt_time_stop(CED_ID);
meson6_clkevt_time_start(CED_ID, false);
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
default:
meson6_clkevt_time_stop(CED_ID);
break;
}
}
static int meson6_clkevt_next_event(unsigned long evt,
struct clock_event_device *unused)
{
meson6_clkevt_time_stop(CED_ID);
meson6_clkevt_time_setup(CED_ID, evt);
meson6_clkevt_time_start(CED_ID, false);
return 0;
}
static irqreturn_t meson6_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = (struct clock_event_device *)dev_id;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init meson6_timer_init(struct device_node *node)
{
u32 val;
int ret, irq;
timer_base = of_io_request_and_map(node, 0, "meson6-timer");
if (IS_ERR(timer_base))
panic("Can't map registers");
irq = irq_of_parse_and_map(node, 0);
if (irq <= 0)
panic("Can't parse IRQ");
val = readl(timer_base + TIMER_ISA_MUX);
val &= ~TIMER_CSD_INPUT_MASK;
val |= TIMER_CSD_UNIT_1US << TIMER_INPUT_BIT(CSD_ID);
writel(val, timer_base + TIMER_ISA_MUX);
sched_clock_register(meson6_timer_sched_read, 32, USEC_PER_SEC);
clocksource_mmio_init(timer_base + TIMER_ISA_VAL(CSD_ID), node->name,
1000 * 1000, 300, 32, clocksource_mmio_readl_up);
val &= ~TIMER_CED_INPUT_MASK;
val |= TIMER_CED_UNIT_1US << TIMER_INPUT_BIT(CED_ID);
writel(val, timer_base + TIMER_ISA_MUX);
meson6_clkevt_time_stop(CED_ID);
ret = setup_irq(irq, &meson6_timer_irq);
if (ret)
pr_warn("failed to setup irq %d\n", irq);
meson6_clockevent.cpumask = cpu_possible_mask;
meson6_clockevent.irq = irq;
clockevents_config_and_register(&meson6_clockevent, USEC_PER_SEC,
1, 0xfffe);
}
