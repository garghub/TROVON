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
static unsigned int calculate_min_delta(void)
{
unsigned int cnt, i, j, k, l;
unsigned int buf1[4], buf2[3];
unsigned int min_delta;
for (i = 0; i < 5; ++i) {
for (j = 0; j < 5; ++j) {
cnt = read_c0_count();
write_c0_compare(cnt);
cnt = read_c0_count() - cnt;
for (k = 0; k < j; ++k) {
if (cnt < buf1[k]) {
l = min_t(unsigned int,
j, ARRAY_SIZE(buf1) - 1);
for (; l > k; --l)
buf1[l] = buf1[l - 1];
break;
}
}
if (k < ARRAY_SIZE(buf1))
buf1[k] = cnt;
}
for (k = 0; k < i; ++k) {
if (buf1[ARRAY_SIZE(buf1) - 1] < buf2[k]) {
l = min_t(unsigned int,
i, ARRAY_SIZE(buf2) - 1);
for (; l > k; --l)
buf2[l] = buf2[l - 1];
break;
}
}
if (k < ARRAY_SIZE(buf2))
buf2[k] = buf1[ARRAY_SIZE(buf1) - 1];
}
min_delta = buf2[ARRAY_SIZE(buf2) - 1] * 2;
if (min_delta < 0x300)
min_delta = 0x300;
pr_debug("%s: median 75th percentile=%#x, min_delta=%#x\n",
__func__, buf2[ARRAY_SIZE(buf2) - 1], min_delta);
return min_delta;
}
static inline int handle_perf_irq(int r2)
{
return (cp0_perfcount_irq < 0) &&
perf_irq() == IRQ_HANDLED &&
!r2;
}
irqreturn_t c0_compare_interrupt(int irq, void *dev_id)
{
const int r2 = cpu_has_mips_r2_r6;
struct clock_event_device *cd;
int cpu = smp_processor_id();
if (handle_perf_irq(r2))
return IRQ_HANDLED;
if (!r2 || (read_c0_cause() & CAUSEF_TI)) {
write_c0_compare(read_c0_compare());
cd = &per_cpu(mips_clockevent_device, cpu);
cd->event_handler(cd);
return IRQ_HANDLED;
}
return IRQ_NONE;
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
#ifdef CONFIG_KVM_GUEST
return 1;
#endif
if (c0_compare_int_pending()) {
cnt = read_c0_count();
write_c0_compare(cnt);
back_to_back_c0_hazard();
while (read_c0_count() < (cnt + COMPARE_INT_SEEN_TICKS))
if (!c0_compare_int_pending())
break;
if (c0_compare_int_pending())
return 0;
}
for (delta = 0x10; delta <= 0x400000; delta <<= 1) {
cnt = read_c0_count();
cnt += delta;
write_c0_compare(cnt);
back_to_back_c0_hazard();
if ((int)(read_c0_count() - cnt) < 0)
break;
}
while ((int)(read_c0_count() - cnt) <= 0)
;
while (read_c0_count() < (cnt + COMPARE_INT_SEEN_TICKS))
if (c0_compare_int_pending())
break;
if (!c0_compare_int_pending())
return 0;
cnt = read_c0_count();
write_c0_compare(cnt);
back_to_back_c0_hazard();
while (read_c0_count() < (cnt + COMPARE_INT_SEEN_TICKS))
if (!c0_compare_int_pending())
break;
if (c0_compare_int_pending())
return 0;
return 1;
}
unsigned int __weak get_c0_compare_int(void)
{
return MIPS_CPU_IRQ_BASE + cp0_compare_irq;
}
int r4k_clockevent_init(void)
{
unsigned int cpu = smp_processor_id();
struct clock_event_device *cd;
unsigned int irq, min_delta;
if (!cpu_has_counter || !mips_hpt_frequency)
return -ENXIO;
if (!c0_compare_int_usable())
return -ENXIO;
irq = get_c0_compare_int();
cd = &per_cpu(mips_clockevent_device, cpu);
cd->name = "MIPS";
cd->features = CLOCK_EVT_FEAT_ONESHOT |
CLOCK_EVT_FEAT_C3STOP |
CLOCK_EVT_FEAT_PERCPU;
min_delta = calculate_min_delta();
cd->rating = 300;
cd->irq = irq;
cd->cpumask = cpumask_of(cpu);
cd->set_next_event = mips_next_event;
cd->event_handler = mips_event_handler;
clockevents_config_and_register(cd, mips_hpt_frequency, min_delta, 0x7fffffff);
if (cp0_timer_irq_installed)
return 0;
cp0_timer_irq_installed = 1;
setup_irq(irq, &c0_compare_irqaction);
return 0;
}
