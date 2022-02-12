static void pit_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
unsigned long flags;
raw_local_irq_save(flags);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
outb_p(0x34, PIT_MODE);
outb_p(PIT_LATCH & 0xff, PIT_CH0);
outb_p(PIT_LATCH >> 8, PIT_CH0);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
outb_p(0x30, PIT_MODE);
outb_p(0, PIT_CH0);
outb_p(0, PIT_CH0);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_RESUME:
break;
}
local_irq_restore(flags);
}
static int pit_set_next_event(unsigned long delta,
struct clock_event_device *evt)
{
return 0;
}
static irqreturn_t pit_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *ce = dev_id;
ce->event_handler(ce);
return IRQ_HANDLED;
}
static void __init isa_timer_init(void)
{
pit_ce.cpumask = cpumask_of(smp_processor_id());
pit_ce.mult = div_sc(PIT_TICK_RATE, NSEC_PER_SEC, pit_ce.shift);
pit_ce.max_delta_ns = clockevent_delta2ns(0x7fff, &pit_ce);
pit_ce.min_delta_ns = clockevent_delta2ns(0x000f, &pit_ce);
clocksource_i8253_init();
setup_irq(pit_ce.irq, &pit_timer_irq);
clockevents_register_device(&pit_ce);
}
