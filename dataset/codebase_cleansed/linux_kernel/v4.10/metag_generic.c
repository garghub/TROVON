static int metag_timer_set_next_event(unsigned long delta,
struct clock_event_device *dev)
{
__core_reg_set(TXTIMERI, -delta);
return 0;
}
static u64 metag_clocksource_read(struct clocksource *cs)
{
return __core_reg_get(TXTIMER);
}
static irqreturn_t metag_timer_interrupt(int irq, void *dummy)
{
struct clock_event_device *evt = this_cpu_ptr(&local_clockevent);
evt->event_handler(evt);
return IRQ_HANDLED;
}
unsigned long long sched_clock(void)
{
unsigned long long ticks = __core_reg_get(TXTIMER);
return ticks << HARDWARE_TO_NS_SHIFT;
}
static int arch_timer_starting_cpu(unsigned int cpu)
{
unsigned int txdivtime;
struct clock_event_device *clk = &per_cpu(local_clockevent, cpu);
char *name = per_cpu(local_clockevent_name, cpu);
txdivtime = __core_reg_get(TXDIVTIME);
txdivtime &= ~TXDIVTIME_DIV_BITS;
txdivtime |= (HARDWARE_DIV & TXDIVTIME_DIV_BITS);
__core_reg_set(TXDIVTIME, txdivtime);
sprintf(name, "META %d", cpu);
clk->name = name;
clk->features = CLOCK_EVT_FEAT_ONESHOT,
clk->rating = 200,
clk->shift = 12,
clk->irq = tbisig_map(TBID_SIGNUM_TRT),
clk->set_next_event = metag_timer_set_next_event,
clk->mult = div_sc(hwtimer_freq, NSEC_PER_SEC, clk->shift);
clk->max_delta_ns = clockevent_delta2ns(0x7fffffff, clk);
clk->min_delta_ns = clockevent_delta2ns(0xf, clk);
clk->cpumask = cpumask_of(cpu);
clockevents_register_device(clk);
if (cpu) {
unsigned int thread0 = cpu_2_hwthread_id[0];
unsigned long val;
val = core_reg_read(TXUCT_ID, TXTIMER_REGNUM, thread0);
__core_reg_set(TXTIMER, val);
}
return 0;
}
int __init metag_generic_timer_init(void)
{
#ifdef CONFIG_METAG_META21
hwtimer_freq = get_coreclock() / (metag_in32(EXPAND_TIMER_DIV) + 1);
#endif
pr_info("Timer frequency: %u Hz\n", hwtimer_freq);
clocksource_register_hz(&clocksource_metag, hwtimer_freq);
setup_irq(tbisig_map(TBID_SIGNUM_TRT), &metag_timer_irq);
return cpuhp_setup_state(CPUHP_AP_METAG_TIMER_STARTING,
"clockevents/metag:starting",
arch_timer_starting_cpu, NULL);
}
