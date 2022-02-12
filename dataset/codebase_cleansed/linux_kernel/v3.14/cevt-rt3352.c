static int systick_next_event(unsigned long delta,
struct clock_event_device *evt)
{
struct systick_device *sdev;
u32 count;
sdev = container_of(evt, struct systick_device, dev);
count = ioread32(sdev->membase + SYSTICK_COUNT);
count = (count + delta) % SYSTICK_FREQ;
iowrite32(count + delta, sdev->membase + SYSTICK_COMPARE);
return 0;
}
static void systick_event_handler(struct clock_event_device *dev)
{
}
static irqreturn_t systick_interrupt(int irq, void *dev_id)
{
struct clock_event_device *dev = (struct clock_event_device *) dev_id;
dev->event_handler(dev);
return IRQ_HANDLED;
}
static void systick_set_clock_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
struct systick_device *sdev;
sdev = container_of(evt, struct systick_device, dev);
switch (mode) {
case CLOCK_EVT_MODE_ONESHOT:
if (!sdev->irq_requested)
setup_irq(systick.dev.irq, &systick_irqaction);
sdev->irq_requested = 1;
iowrite32(CFG_EXT_STK_EN | CFG_CNT_EN,
systick.membase + SYSTICK_CONFIG);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
if (sdev->irq_requested)
free_irq(systick.dev.irq, &systick_irqaction);
sdev->irq_requested = 0;
iowrite32(0, systick.membase + SYSTICK_CONFIG);
break;
default:
pr_err("%s: Unhandeled mips clock_mode\n", systick.dev.name);
break;
}
}
static void __init ralink_systick_init(struct device_node *np)
{
systick.membase = of_iomap(np, 0);
if (!systick.membase)
return;
systick_irqaction.name = np->name;
systick.dev.name = np->name;
clockevents_calc_mult_shift(&systick.dev, SYSTICK_FREQ, 60);
systick.dev.max_delta_ns = clockevent_delta2ns(0x7fff, &systick.dev);
systick.dev.min_delta_ns = clockevent_delta2ns(0x3, &systick.dev);
systick.dev.irq = irq_of_parse_and_map(np, 0);
if (!systick.dev.irq) {
pr_err("%s: request_irq failed", np->name);
return;
}
clocksource_mmio_init(systick.membase + SYSTICK_COUNT, np->name,
SYSTICK_FREQ, 301, 16, clocksource_mmio_readl_up);
clockevents_register_device(&systick.dev);
pr_info("%s: running - mult: %d, shift: %d\n",
np->name, systick.dev.mult, systick.dev.shift);
}
