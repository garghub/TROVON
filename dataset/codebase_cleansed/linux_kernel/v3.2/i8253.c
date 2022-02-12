static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
i8253_clockevent.event_handler(&i8253_clockevent);
return IRQ_HANDLED;
}
void __init setup_pit_timer(void)
{
clockevent_i8253_init(true);
setup_irq(0, &irq0);
}
static int __init init_pit_clocksource(void)
{
if (num_possible_cpus() > 1)
return 0;
return clocksource_i8253_init();
}
