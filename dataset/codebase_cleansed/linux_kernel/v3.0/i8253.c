static void init_pit_timer(enum clock_event_mode mode,
struct clock_event_device *evt)
{
raw_spin_lock(&i8253_lock);
switch(mode) {
case CLOCK_EVT_MODE_PERIODIC:
outb_p(0x34, PIT_MODE);
outb_p(LATCH & 0xff , PIT_CH0);
outb(LATCH >> 8 , PIT_CH0);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
if (evt->mode == CLOCK_EVT_MODE_PERIODIC ||
evt->mode == CLOCK_EVT_MODE_ONESHOT) {
outb_p(0x30, PIT_MODE);
outb_p(0, PIT_CH0);
outb_p(0, PIT_CH0);
}
break;
case CLOCK_EVT_MODE_ONESHOT:
outb_p(0x38, PIT_MODE);
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
raw_spin_unlock(&i8253_lock);
}
static int pit_next_event(unsigned long delta, struct clock_event_device *evt)
{
raw_spin_lock(&i8253_lock);
outb_p(delta & 0xff , PIT_CH0);
outb(delta >> 8 , PIT_CH0);
raw_spin_unlock(&i8253_lock);
return 0;
}
static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
pit_clockevent.event_handler(&pit_clockevent);
return IRQ_HANDLED;
}
void __init setup_pit_timer(void)
{
struct clock_event_device *cd = &pit_clockevent;
unsigned int cpu = smp_processor_id();
cd->cpumask = cpumask_of(cpu);
clockevent_set_clock(cd, CLOCK_TICK_RATE);
cd->max_delta_ns = clockevent_delta2ns(0x7FFF, cd);
cd->min_delta_ns = clockevent_delta2ns(0xF, cd);
clockevents_register_device(cd);
setup_irq(0, &irq0);
}
static int __init init_pit_clocksource(void)
{
if (num_possible_cpus() > 1)
return 0;
return clocksource_i8253_init();
}
