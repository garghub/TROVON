static int mips_next_event(unsigned long delta,
struct clock_event_device *evt)
{
unsigned int cnt;
int res;
cnt = read_c0_count();
cnt += delta;
write_c0_compare(cnt);
res = ((int)(read_c0_count() - cnt) >= 0) ? -ETIME : 0;
return res;
}
void mips_set_clock_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
}
irqreturn_t c0_compare_interrupt(int irq, void *dev_id)
{
const int r2 = cpu_has_mips_r2;
struct clock_event_device *cd;
int cpu = smp_processor_id();
if (handle_perf_irq(r2))
goto out;
if (!r2 || (read_c0_cause() & (1 << 30))) {
write_c0_compare(read_c0_compare());
cd = &per_cpu(mips_clockevent_device, cpu);
cd->event_handler(cd);
}
out:
return IRQ_HANDLED;
}
void mips_event_handler(struct clock_event_device *dev)
{
}
static int c0_compare_int_pending(void)
{
return (read_c0_cause() >> cp0_compare_irq_shift) & (1ul << CAUSEB_IP);
}
int c0_compare_int_usable(void)
{
unsigned int delta;
unsigned int cnt;
if (c0_compare_int_pending()) {
write_c0_compare(read_c0_count());
compare_change_hazard();
if (c0_compare_int_pending())
return 0;
}
for (delta = 0x10; delta <= 0x400000; delta <<= 1) {
cnt = read_c0_count();
cnt += delta;
write_c0_compare(cnt);
compare_change_hazard();
if ((int)(read_c0_count() - cnt) < 0)
break;
}
while ((int)(read_c0_count() - cnt) <= 0)
;
compare_change_hazard();
if (!c0_compare_int_pending())
return 0;
write_c0_compare(read_c0_count());
compare_change_hazard();
if (c0_compare_int_pending())
return 0;
return 1;
}
int __cpuinit r4k_clockevent_init(void)
{
unsigned int cpu = smp_processor_id();
struct clock_event_device *cd;
unsigned int irq;
if (!cpu_has_counter || !mips_hpt_frequency)
return -ENXIO;
if (!c0_compare_int_usable())
return -ENXIO;
irq = MIPS_CPU_IRQ_BASE + cp0_compare_irq;
if (get_c0_compare_int)
irq = get_c0_compare_int();
cd = &per_cpu(mips_clockevent_device, cpu);
cd->name = "MIPS";
cd->features = CLOCK_EVT_FEAT_ONESHOT;
clockevent_set_clock(cd, mips_hpt_frequency);
cd->max_delta_ns = clockevent_delta2ns(0x7fffffff, cd);
cd->min_delta_ns = clockevent_delta2ns(0x300, cd);
cd->rating = 300;
cd->irq = irq;
cd->cpumask = cpumask_of(cpu);
cd->set_next_event = mips_next_event;
cd->set_mode = mips_set_clock_mode;
cd->event_handler = mips_event_handler;
clockevents_register_device(cd);
if (cp0_timer_irq_installed)
return 0;
cp0_timer_irq_installed = 1;
setup_irq(irq, &c0_compare_irqaction);
return 0;
}
