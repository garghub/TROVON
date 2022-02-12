static cycle_t cksrc_dc21285_read(struct clocksource *cs)
{
return cs->mask - *CSR_TIMER2_VALUE;
}
static int cksrc_dc21285_enable(struct clocksource *cs)
{
*CSR_TIMER2_LOAD = cs->mask;
*CSR_TIMER2_CLR = 0;
*CSR_TIMER2_CNTL = TIMER_CNTL_ENABLE | TIMER_CNTL_DIV16;
return 0;
}
static void cksrc_dc21285_disable(struct clocksource *cs)
{
*CSR_TIMER2_CNTL = 0;
}
static int ckevt_dc21285_set_next_event(unsigned long delta,
struct clock_event_device *c)
{
*CSR_TIMER1_CLR = 0;
*CSR_TIMER1_LOAD = delta;
*CSR_TIMER1_CNTL = TIMER_CNTL_ENABLE | TIMER_CNTL_DIV16;
return 0;
}
static void ckevt_dc21285_set_mode(enum clock_event_mode mode,
struct clock_event_device *c)
{
switch (mode) {
case CLOCK_EVT_MODE_RESUME:
case CLOCK_EVT_MODE_PERIODIC:
*CSR_TIMER1_CLR = 0;
*CSR_TIMER1_LOAD = (mem_fclk_21285 + 8 * HZ) / (16 * HZ);
*CSR_TIMER1_CNTL = TIMER_CNTL_ENABLE | TIMER_CNTL_AUTORELOAD |
TIMER_CNTL_DIV16;
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
*CSR_TIMER1_CNTL = 0;
break;
}
}
static irqreturn_t timer1_interrupt(int irq, void *dev_id)
{
struct clock_event_device *ce = dev_id;
*CSR_TIMER1_CLR = 0;
if (ce->mode == CLOCK_EVT_MODE_ONESHOT)
*CSR_TIMER1_CNTL = 0;
ce->event_handler(ce);
return IRQ_HANDLED;
}
void __init footbridge_timer_init(void)
{
struct clock_event_device *ce = &ckevt_dc21285;
unsigned rate = DIV_ROUND_CLOSEST(mem_fclk_21285, 16);
clocksource_register_hz(&cksrc_dc21285, rate);
setup_irq(ce->irq, &footbridge_timer_irq);
ce->cpumask = cpumask_of(smp_processor_id());
clockevents_config_and_register(ce, rate, 0x4, 0xffffff);
}
static u32 notrace footbridge_read_sched_clock(void)
{
return ~*CSR_TIMER3_VALUE;
}
void __init footbridge_sched_clock(void)
{
unsigned rate = DIV_ROUND_CLOSEST(mem_fclk_21285, 16);
*CSR_TIMER3_LOAD = 0;
*CSR_TIMER3_CLR = 0;
*CSR_TIMER3_CNTL = TIMER_CNTL_ENABLE | TIMER_CNTL_DIV16;
setup_sched_clock(footbridge_read_sched_clock, 24, rate);
}
