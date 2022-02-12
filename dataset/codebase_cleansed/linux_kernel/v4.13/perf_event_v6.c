static inline unsigned long
armv6_pmcr_read(void)
{
u32 val;
asm volatile("mrc p15, 0, %0, c15, c12, 0" : "=r"(val));
return val;
}
static inline void
armv6_pmcr_write(unsigned long val)
{
asm volatile("mcr p15, 0, %0, c15, c12, 0" : : "r"(val));
}
static inline int
armv6_pmcr_has_overflowed(unsigned long pmcr)
{
return pmcr & ARMV6_PMCR_OVERFLOWED_MASK;
}
static inline int
armv6_pmcr_counter_has_overflowed(unsigned long pmcr,
enum armv6_counters counter)
{
int ret = 0;
if (ARMV6_CYCLE_COUNTER == counter)
ret = pmcr & ARMV6_PMCR_CCOUNT_OVERFLOW;
else if (ARMV6_COUNTER0 == counter)
ret = pmcr & ARMV6_PMCR_COUNT0_OVERFLOW;
else if (ARMV6_COUNTER1 == counter)
ret = pmcr & ARMV6_PMCR_COUNT1_OVERFLOW;
else
WARN_ONCE(1, "invalid counter number (%d)\n", counter);
return ret;
}
static inline u32 armv6pmu_read_counter(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
int counter = hwc->idx;
unsigned long value = 0;
if (ARMV6_CYCLE_COUNTER == counter)
asm volatile("mrc p15, 0, %0, c15, c12, 1" : "=r"(value));
else if (ARMV6_COUNTER0 == counter)
asm volatile("mrc p15, 0, %0, c15, c12, 2" : "=r"(value));
else if (ARMV6_COUNTER1 == counter)
asm volatile("mrc p15, 0, %0, c15, c12, 3" : "=r"(value));
else
WARN_ONCE(1, "invalid counter number (%d)\n", counter);
return value;
}
static inline void armv6pmu_write_counter(struct perf_event *event, u32 value)
{
struct hw_perf_event *hwc = &event->hw;
int counter = hwc->idx;
if (ARMV6_CYCLE_COUNTER == counter)
asm volatile("mcr p15, 0, %0, c15, c12, 1" : : "r"(value));
else if (ARMV6_COUNTER0 == counter)
asm volatile("mcr p15, 0, %0, c15, c12, 2" : : "r"(value));
else if (ARMV6_COUNTER1 == counter)
asm volatile("mcr p15, 0, %0, c15, c12, 3" : : "r"(value));
else
WARN_ONCE(1, "invalid counter number (%d)\n", counter);
}
static void armv6pmu_enable_event(struct perf_event *event)
{
unsigned long val, mask, evt, flags;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
int idx = hwc->idx;
if (ARMV6_CYCLE_COUNTER == idx) {
mask = 0;
evt = ARMV6_PMCR_CCOUNT_IEN;
} else if (ARMV6_COUNTER0 == idx) {
mask = ARMV6_PMCR_EVT_COUNT0_MASK;
evt = (hwc->config_base << ARMV6_PMCR_EVT_COUNT0_SHIFT) |
ARMV6_PMCR_COUNT0_IEN;
} else if (ARMV6_COUNTER1 == idx) {
mask = ARMV6_PMCR_EVT_COUNT1_MASK;
evt = (hwc->config_base << ARMV6_PMCR_EVT_COUNT1_SHIFT) |
ARMV6_PMCR_COUNT1_IEN;
} else {
WARN_ONCE(1, "invalid counter number (%d)\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = armv6_pmcr_read();
val &= ~mask;
val |= evt;
armv6_pmcr_write(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static irqreturn_t
armv6pmu_handle_irq(int irq_num,
void *dev)
{
unsigned long pmcr = armv6_pmcr_read();
struct perf_sample_data data;
struct arm_pmu *cpu_pmu = (struct arm_pmu *)dev;
struct pmu_hw_events *cpuc = this_cpu_ptr(cpu_pmu->hw_events);
struct pt_regs *regs;
int idx;
if (!armv6_pmcr_has_overflowed(pmcr))
return IRQ_NONE;
regs = get_irq_regs();
armv6_pmcr_write(pmcr);
for (idx = 0; idx < cpu_pmu->num_events; ++idx) {
struct perf_event *event = cpuc->events[idx];
struct hw_perf_event *hwc;
if (!event)
continue;
if (!armv6_pmcr_counter_has_overflowed(pmcr, idx))
continue;
hwc = &event->hw;
armpmu_event_update(event);
perf_sample_data_init(&data, 0, hwc->last_period);
if (!armpmu_event_set_period(event))
continue;
if (perf_event_overflow(event, &data, regs))
cpu_pmu->disable(event);
}
irq_work_run();
return IRQ_HANDLED;
}
static void armv6pmu_start(struct arm_pmu *cpu_pmu)
{
unsigned long flags, val;
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = armv6_pmcr_read();
val |= ARMV6_PMCR_ENABLE;
armv6_pmcr_write(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void armv6pmu_stop(struct arm_pmu *cpu_pmu)
{
unsigned long flags, val;
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = armv6_pmcr_read();
val &= ~ARMV6_PMCR_ENABLE;
armv6_pmcr_write(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static int
armv6pmu_get_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (ARMV6_PERFCTR_CPU_CYCLES == hwc->config_base) {
if (test_and_set_bit(ARMV6_CYCLE_COUNTER, cpuc->used_mask))
return -EAGAIN;
return ARMV6_CYCLE_COUNTER;
} else {
if (!test_and_set_bit(ARMV6_COUNTER1, cpuc->used_mask))
return ARMV6_COUNTER1;
if (!test_and_set_bit(ARMV6_COUNTER0, cpuc->used_mask))
return ARMV6_COUNTER0;
return -EAGAIN;
}
}
static void armv6pmu_disable_event(struct perf_event *event)
{
unsigned long val, mask, evt, flags;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
int idx = hwc->idx;
if (ARMV6_CYCLE_COUNTER == idx) {
mask = ARMV6_PMCR_CCOUNT_IEN;
evt = 0;
} else if (ARMV6_COUNTER0 == idx) {
mask = ARMV6_PMCR_COUNT0_IEN | ARMV6_PMCR_EVT_COUNT0_MASK;
evt = ARMV6_PERFCTR_NOP << ARMV6_PMCR_EVT_COUNT0_SHIFT;
} else if (ARMV6_COUNTER1 == idx) {
mask = ARMV6_PMCR_COUNT1_IEN | ARMV6_PMCR_EVT_COUNT1_MASK;
evt = ARMV6_PERFCTR_NOP << ARMV6_PMCR_EVT_COUNT1_SHIFT;
} else {
WARN_ONCE(1, "invalid counter number (%d)\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = armv6_pmcr_read();
val &= ~mask;
val |= evt;
armv6_pmcr_write(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void armv6mpcore_pmu_disable_event(struct perf_event *event)
{
unsigned long val, mask, flags, evt = 0;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
int idx = hwc->idx;
if (ARMV6_CYCLE_COUNTER == idx) {
mask = ARMV6_PMCR_CCOUNT_IEN;
} else if (ARMV6_COUNTER0 == idx) {
mask = ARMV6_PMCR_COUNT0_IEN;
} else if (ARMV6_COUNTER1 == idx) {
mask = ARMV6_PMCR_COUNT1_IEN;
} else {
WARN_ONCE(1, "invalid counter number (%d)\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = armv6_pmcr_read();
val &= ~mask;
val |= evt;
armv6_pmcr_write(val);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static int armv6_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv6_perf_map,
&armv6_perf_cache_map, 0xFF);
}
static void armv6pmu_init(struct arm_pmu *cpu_pmu)
{
cpu_pmu->handle_irq = armv6pmu_handle_irq;
cpu_pmu->enable = armv6pmu_enable_event;
cpu_pmu->disable = armv6pmu_disable_event;
cpu_pmu->read_counter = armv6pmu_read_counter;
cpu_pmu->write_counter = armv6pmu_write_counter;
cpu_pmu->get_event_idx = armv6pmu_get_event_idx;
cpu_pmu->start = armv6pmu_start;
cpu_pmu->stop = armv6pmu_stop;
cpu_pmu->map_event = armv6_map_event;
cpu_pmu->num_events = 3;
cpu_pmu->max_period = (1LLU << 32) - 1;
}
static int armv6_1136_pmu_init(struct arm_pmu *cpu_pmu)
{
armv6pmu_init(cpu_pmu);
cpu_pmu->name = "armv6_1136";
return 0;
}
static int armv6_1156_pmu_init(struct arm_pmu *cpu_pmu)
{
armv6pmu_init(cpu_pmu);
cpu_pmu->name = "armv6_1156";
return 0;
}
static int armv6_1176_pmu_init(struct arm_pmu *cpu_pmu)
{
armv6pmu_init(cpu_pmu);
cpu_pmu->name = "armv6_1176";
return 0;
}
static int armv6mpcore_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv6mpcore_perf_map,
&armv6mpcore_perf_cache_map, 0xFF);
}
static int armv6mpcore_pmu_init(struct arm_pmu *cpu_pmu)
{
cpu_pmu->name = "armv6_11mpcore";
cpu_pmu->handle_irq = armv6pmu_handle_irq;
cpu_pmu->enable = armv6pmu_enable_event;
cpu_pmu->disable = armv6mpcore_pmu_disable_event;
cpu_pmu->read_counter = armv6pmu_read_counter;
cpu_pmu->write_counter = armv6pmu_write_counter;
cpu_pmu->get_event_idx = armv6pmu_get_event_idx;
cpu_pmu->start = armv6pmu_start;
cpu_pmu->stop = armv6pmu_stop;
cpu_pmu->map_event = armv6mpcore_map_event;
cpu_pmu->num_events = 3;
cpu_pmu->max_period = (1LLU << 32) - 1;
return 0;
}
static int armv6_pmu_device_probe(struct platform_device *pdev)
{
return arm_pmu_device_probe(pdev, armv6_pmu_of_device_ids,
armv6_pmu_probe_table);
}
