void irq_timings_enable(void)
{
static_branch_enable(&irq_timing_enabled);
}
void irq_timings_disable(void)
{
static_branch_disable(&irq_timing_enabled);
}
static void irqs_update(struct irqt_stat *irqs, u64 ts)
{
u64 old_ts = irqs->last_ts;
u64 variance = 0;
u64 interval;
s64 diff;
irqs->last_ts = ts;
interval = ts - old_ts;
if (interval >= NSEC_PER_SEC) {
memset(irqs, 0, sizeof(*irqs));
irqs->last_ts = ts;
return;
}
diff = interval - irqs->avg;
irqs->nr_samples++;
if (likely(irqs->nr_samples > 1))
variance = irqs->variance >> IRQ_TIMINGS_SHIFT;
if ((irqs->nr_samples >= 30) && ((diff * diff) > (9 * variance))) {
if (irqs->anomalies++ >= 3) {
memset(irqs, 0, sizeof(*irqs));
irqs->last_ts = ts;
return;
}
} else {
irqs->anomalies = 0;
}
irqs->valid = 1;
irqs->avg = irqs->avg + (diff >> IRQ_TIMINGS_SHIFT);
irqs->variance = irqs->variance + (diff * (interval - irqs->avg));
irqs->next_evt = ts + irqs->avg;
}
u64 irq_timings_next_event(u64 now)
{
struct irq_timings *irqts = this_cpu_ptr(&irq_timings);
struct irqt_stat *irqs;
struct irqt_stat __percpu *s;
u64 ts, next_evt = U64_MAX;
int i, irq = 0;
WARN_ON_ONCE(!irqs_disabled());
for (i = irqts->count & IRQ_TIMINGS_MASK,
irqts->count = min(IRQ_TIMINGS_SIZE, irqts->count);
irqts->count > 0; irqts->count--, i = (i + 1) & IRQ_TIMINGS_MASK) {
irq = irq_timing_decode(irqts->values[i], &ts);
s = idr_find(&irqt_stats, irq);
if (s) {
irqs = this_cpu_ptr(s);
irqs_update(irqs, ts);
}
}
idr_for_each_entry(&irqt_stats, s, i) {
irqs = this_cpu_ptr(s);
if (!irqs->valid)
continue;
if (irqs->next_evt <= now) {
irq = i;
next_evt = now;
irqs->valid = 0;
break;
}
if (irqs->next_evt < next_evt) {
irq = i;
next_evt = irqs->next_evt;
}
}
return next_evt;
}
void irq_timings_free(int irq)
{
struct irqt_stat __percpu *s;
s = idr_find(&irqt_stats, irq);
if (s) {
free_percpu(s);
idr_remove(&irqt_stats, irq);
}
}
int irq_timings_alloc(int irq)
{
struct irqt_stat __percpu *s;
int id;
s = idr_find(&irqt_stats, irq);
if (s)
return 0;
s = alloc_percpu(*s);
if (!s)
return -ENOMEM;
idr_preload(GFP_KERNEL);
id = idr_alloc(&irqt_stats, s, irq, irq + 1, GFP_NOWAIT);
idr_preload_end();
if (id < 0) {
free_percpu(s);
return id;
}
return 0;
}
