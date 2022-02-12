void local_timer_interrupt(void)
{
struct clock_event_device *clk = &__get_cpu_var(local_clockevent);
irq_enter();
clk->event_handler(clk);
irq_exit();
}
static void dummy_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
}
void local_timer_setup(unsigned int cpu)
{
struct clock_event_device *clk = &per_cpu(local_clockevent, cpu);
clk->name = "dummy_timer";
clk->features = CLOCK_EVT_FEAT_ONESHOT |
CLOCK_EVT_FEAT_PERIODIC |
CLOCK_EVT_FEAT_DUMMY;
clk->rating = 400;
clk->mult = 1;
clk->set_mode = dummy_timer_set_mode;
clk->broadcast = smp_timer_broadcast;
clk->cpumask = cpumask_of(cpu);
clockevents_register_device(clk);
}
void local_timer_stop(unsigned int cpu)
{
}
