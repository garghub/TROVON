void disable_mfgpt0_counter(void)
{
outw(inw(MFGPT0_SETUP) & 0x7fff, MFGPT0_SETUP);
}
void enable_mfgpt0_counter(void)
{
outw(0xe310, MFGPT0_SETUP);
}
static int mfgpt_timer_set_periodic(struct clock_event_device *evt)
{
raw_spin_lock(&mfgpt_lock);
outw(COMPARE, MFGPT0_CMP2);
outw(0, MFGPT0_CNT);
enable_mfgpt0_counter();
raw_spin_unlock(&mfgpt_lock);
return 0;
}
static int mfgpt_timer_shutdown(struct clock_event_device *evt)
{
if (clockevent_state_periodic(evt) || clockevent_state_oneshot(evt)) {
raw_spin_lock(&mfgpt_lock);
disable_mfgpt0_counter();
raw_spin_unlock(&mfgpt_lock);
}
return 0;
}
static irqreturn_t timer_interrupt(int irq, void *dev_id)
{
u32 basehi;
_rdmsr(DIVIL_MSR_REG(DIVIL_LBAR_MFGPT), &basehi, &mfgpt_base);
outw(inw(MFGPT0_SETUP) | 0x4000, MFGPT0_SETUP);
mfgpt_clockevent.event_handler(&mfgpt_clockevent);
return IRQ_HANDLED;
}
void __init setup_mfgpt0_timer(void)
{
u32 basehi;
struct clock_event_device *cd = &mfgpt_clockevent;
unsigned int cpu = smp_processor_id();
cd->cpumask = cpumask_of(cpu);
clockevent_set_clock(cd, MFGPT_TICK_RATE);
cd->max_delta_ns = clockevent_delta2ns(0xffff, cd);
cd->min_delta_ns = clockevent_delta2ns(0xf, cd);
_wrmsr(DIVIL_MSR_REG(MFGPT_IRQ), 0, 0x100);
_wrmsr(DIVIL_MSR_REG(PIC_ZSEL_LOW), 0, 0x50000);
_rdmsr(DIVIL_MSR_REG(DIVIL_LBAR_MFGPT), &basehi, &mfgpt_base);
clockevents_register_device(cd);
setup_irq(CS5536_MFGPT_INTR, &irq5);
}
static cycle_t mfgpt_read(struct clocksource *cs)
{
unsigned long flags;
int count;
u32 jifs;
static int old_count;
static u32 old_jifs;
raw_spin_lock_irqsave(&mfgpt_lock, flags);
jifs = jiffies;
count = inw(MFGPT0_CNT);
if (count < old_count && jifs == old_jifs)
count = old_count;
old_count = count;
old_jifs = jifs;
raw_spin_unlock_irqrestore(&mfgpt_lock, flags);
return (cycle_t) (jifs * COMPARE) + count;
}
int __init init_mfgpt_clocksource(void)
{
if (num_possible_cpus() > 1)
return 0;
return clocksource_register_hz(&clocksource_mfgpt, MFGPT_TICK_RATE);
}
