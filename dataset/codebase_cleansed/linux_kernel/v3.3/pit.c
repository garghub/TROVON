static void init_cf_pit_timer(enum clock_event_mode mode,
struct clock_event_device *evt)
{
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
__raw_writew(MCFPIT_PCSR_DISABLE, TA(MCFPIT_PCSR));
__raw_writew(PIT_CYCLES_PER_JIFFY, TA(MCFPIT_PMR));
__raw_writew(MCFPIT_PCSR_EN | MCFPIT_PCSR_PIE | \
MCFPIT_PCSR_OVW | MCFPIT_PCSR_RLD | \
MCFPIT_PCSR_CLK64, TA(MCFPIT_PCSR));
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
__raw_writew(MCFPIT_PCSR_DISABLE, TA(MCFPIT_PCSR));
break;
case CLOCK_EVT_MODE_ONESHOT:
__raw_writew(MCFPIT_PCSR_DISABLE, TA(MCFPIT_PCSR));
__raw_writew(MCFPIT_PCSR_EN | MCFPIT_PCSR_PIE | \
MCFPIT_PCSR_OVW | MCFPIT_PCSR_CLK64, \
TA(MCFPIT_PCSR));
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static int cf_pit_next_event(unsigned long delta,
struct clock_event_device *evt)
{
__raw_writew(delta, TA(MCFPIT_PMR));
return 0;
}
static irqreturn_t pit_tick(int irq, void *dummy)
{
struct clock_event_device *evt = &cf_pit_clockevent;
u16 pcsr;
pcsr = __raw_readw(TA(MCFPIT_PCSR));
__raw_writew(pcsr | MCFPIT_PCSR_PIF, TA(MCFPIT_PCSR));
pit_cnt += PIT_CYCLES_PER_JIFFY;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static cycle_t pit_read_clk(struct clocksource *cs)
{
unsigned long flags;
u32 cycles;
u16 pcntr;
local_irq_save(flags);
pcntr = __raw_readw(TA(MCFPIT_PCNTR));
cycles = pit_cnt;
local_irq_restore(flags);
return cycles + PIT_CYCLES_PER_JIFFY - pcntr;
}
void hw_timer_init(void)
{
cf_pit_clockevent.cpumask = cpumask_of(smp_processor_id());
cf_pit_clockevent.mult = div_sc(FREQ, NSEC_PER_SEC, 32);
cf_pit_clockevent.max_delta_ns =
clockevent_delta2ns(0xFFFF, &cf_pit_clockevent);
cf_pit_clockevent.min_delta_ns =
clockevent_delta2ns(0x3f, &cf_pit_clockevent);
clockevents_register_device(&cf_pit_clockevent);
setup_irq(MCFINT_VECBASE + MCFINT_PIT1, &pit_irq);
clocksource_register_hz(&pit_clk, FREQ);
}
