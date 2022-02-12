static irqreturn_t pit_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *ce = dev_id;
ce->event_handler(ce);
return IRQ_HANDLED;
}
void __init isa_timer_init(void)
{
clocksource_i8253_init();
setup_irq(i8253_clockevent.irq, &pit_timer_irq);
clockevent_i8253_init(false);
}
