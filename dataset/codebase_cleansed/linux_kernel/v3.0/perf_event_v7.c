static inline unsigned long armv7_pmnc_read(void)
{
u32 val;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r"(val));
return val;
}
static inline void armv7_pmnc_write(unsigned long val)
{
val &= ARMV7_PMNC_MASK;
isb();
asm volatile("mcr p15, 0, %0, c9, c12, 0" : : "r"(val));
}
static inline int armv7_pmnc_has_overflowed(unsigned long pmnc)
{
return pmnc & ARMV7_OVERFLOWED_MASK;
}
static inline int armv7_pmnc_counter_has_overflowed(unsigned long pmnc,
enum armv7_counters counter)
{
int ret = 0;
if (counter == ARMV7_CYCLE_COUNTER)
ret = pmnc & ARMV7_FLAG_C;
else if ((counter >= ARMV7_COUNTER0) && (counter <= ARMV7_COUNTER_LAST))
ret = pmnc & ARMV7_FLAG_P(counter);
else
pr_err("CPU%u checking wrong counter %d overflow status\n",
smp_processor_id(), counter);
return ret;
}
static inline int armv7_pmnc_select_counter(unsigned int idx)
{
u32 val;
if ((idx < ARMV7_COUNTER0) || (idx > ARMV7_COUNTER_LAST)) {
pr_err("CPU%u selecting wrong PMNC counter"
" %d\n", smp_processor_id(), idx);
return -1;
}
val = (idx - ARMV7_EVENT_CNT_TO_CNTx) & ARMV7_SELECT_MASK;
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (val));
isb();
return idx;
}
static inline u32 armv7pmu_read_counter(int idx)
{
unsigned long value = 0;
if (idx == ARMV7_CYCLE_COUNTER)
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
else if ((idx >= ARMV7_COUNTER0) && (idx <= ARMV7_COUNTER_LAST)) {
if (armv7_pmnc_select_counter(idx) == idx)
asm volatile("mrc p15, 0, %0, c9, c13, 2"
: "=r" (value));
} else
pr_err("CPU%u reading wrong counter %d\n",
smp_processor_id(), idx);
return value;
}
static inline void armv7pmu_write_counter(int idx, u32 value)
{
if (idx == ARMV7_CYCLE_COUNTER)
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
else if ((idx >= ARMV7_COUNTER0) && (idx <= ARMV7_COUNTER_LAST)) {
if (armv7_pmnc_select_counter(idx) == idx)
asm volatile("mcr p15, 0, %0, c9, c13, 2"
: : "r" (value));
} else
pr_err("CPU%u writing wrong counter %d\n",
smp_processor_id(), idx);
}
static inline void armv7_pmnc_write_evtsel(unsigned int idx, u32 val)
{
if (armv7_pmnc_select_counter(idx) == idx) {
val &= ARMV7_EVTSEL_MASK;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
}
static inline u32 armv7_pmnc_enable_counter(unsigned int idx)
{
u32 val;
if ((idx != ARMV7_CYCLE_COUNTER) &&
((idx < ARMV7_COUNTER0) || (idx > ARMV7_COUNTER_LAST))) {
pr_err("CPU%u enabling wrong PMNC counter"
" %d\n", smp_processor_id(), idx);
return -1;
}
if (idx == ARMV7_CYCLE_COUNTER)
val = ARMV7_CNTENS_C;
else
val = ARMV7_CNTENS_P(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (val));
return idx;
}
static inline u32 armv7_pmnc_disable_counter(unsigned int idx)
{
u32 val;
if ((idx != ARMV7_CYCLE_COUNTER) &&
((idx < ARMV7_COUNTER0) || (idx > ARMV7_COUNTER_LAST))) {
pr_err("CPU%u disabling wrong PMNC counter"
" %d\n", smp_processor_id(), idx);
return -1;
}
if (idx == ARMV7_CYCLE_COUNTER)
val = ARMV7_CNTENC_C;
else
val = ARMV7_CNTENC_P(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (val));
return idx;
}
static inline u32 armv7_pmnc_enable_intens(unsigned int idx)
{
u32 val;
if ((idx != ARMV7_CYCLE_COUNTER) &&
((idx < ARMV7_COUNTER0) || (idx > ARMV7_COUNTER_LAST))) {
pr_err("CPU%u enabling wrong PMNC counter"
" interrupt enable %d\n", smp_processor_id(), idx);
return -1;
}
if (idx == ARMV7_CYCLE_COUNTER)
val = ARMV7_INTENS_C;
else
val = ARMV7_INTENS_P(idx);
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (val));
return idx;
}
static inline u32 armv7_pmnc_disable_intens(unsigned int idx)
{
u32 val;
if ((idx != ARMV7_CYCLE_COUNTER) &&
((idx < ARMV7_COUNTER0) || (idx > ARMV7_COUNTER_LAST))) {
pr_err("CPU%u disabling wrong PMNC counter"
" interrupt enable %d\n", smp_processor_id(), idx);
return -1;
}
if (idx == ARMV7_CYCLE_COUNTER)
val = ARMV7_INTENC_C;
else
val = ARMV7_INTENC_P(idx);
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (val));
return idx;
}
static inline u32 armv7_pmnc_getreset_flags(void)
{
u32 val;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
val &= ARMV7_FLAG_MASK;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (val));
return val;
}
static void armv7_pmnc_dump_regs(void)
{
u32 val;
unsigned int cnt;
printk(KERN_INFO "PMNC registers dump:\n");
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r" (val));
printk(KERN_INFO "PMNC =0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r" (val));
printk(KERN_INFO "CNTENS=0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c14, 1" : "=r" (val));
printk(KERN_INFO "INTENS=0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
printk(KERN_INFO "FLAGS =0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c12, 5" : "=r" (val));
printk(KERN_INFO "SELECT=0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (val));
printk(KERN_INFO "CCNT =0x%08x\n", val);
for (cnt = ARMV7_COUNTER0; cnt < ARMV7_COUNTER_LAST; cnt++) {
armv7_pmnc_select_counter(cnt);
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
printk(KERN_INFO "CNT[%d] count =0x%08x\n",
cnt-ARMV7_EVENT_CNT_TO_CNTx, val);
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
printk(KERN_INFO "CNT[%d] evtsel=0x%08x\n",
cnt-ARMV7_EVENT_CNT_TO_CNTx, val);
}
}
static void armv7pmu_enable_event(struct hw_perf_event *hwc, int idx)
{
unsigned long flags;
raw_spin_lock_irqsave(&pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
if (idx != ARMV7_CYCLE_COUNTER)
armv7_pmnc_write_evtsel(idx, hwc->config_base);
armv7_pmnc_enable_intens(idx);
armv7_pmnc_enable_counter(idx);
raw_spin_unlock_irqrestore(&pmu_lock, flags);
}
static void armv7pmu_disable_event(struct hw_perf_event *hwc, int idx)
{
unsigned long flags;
raw_spin_lock_irqsave(&pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
armv7_pmnc_disable_intens(idx);
raw_spin_unlock_irqrestore(&pmu_lock, flags);
}
static irqreturn_t armv7pmu_handle_irq(int irq_num, void *dev)
{
unsigned long pmnc;
struct perf_sample_data data;
struct cpu_hw_events *cpuc;
struct pt_regs *regs;
int idx;
pmnc = armv7_pmnc_getreset_flags();
if (!armv7_pmnc_has_overflowed(pmnc))
return IRQ_NONE;
regs = get_irq_regs();
perf_sample_data_init(&data, 0);
cpuc = &__get_cpu_var(cpu_hw_events);
for (idx = 0; idx <= armpmu->num_events; ++idx) {
struct perf_event *event = cpuc->events[idx];
struct hw_perf_event *hwc;
if (!test_bit(idx, cpuc->active_mask))
continue;
if (!armv7_pmnc_counter_has_overflowed(pmnc, idx))
continue;
hwc = &event->hw;
armpmu_event_update(event, hwc, idx, 1);
data.period = event->hw.last_period;
if (!armpmu_event_set_period(event, hwc, idx))
continue;
if (perf_event_overflow(event, 0, &data, regs))
armpmu->disable(hwc, idx);
}
irq_work_run();
return IRQ_HANDLED;
}
static void armv7pmu_start(void)
{
unsigned long flags;
raw_spin_lock_irqsave(&pmu_lock, flags);
armv7_pmnc_write(armv7_pmnc_read() | ARMV7_PMNC_E);
raw_spin_unlock_irqrestore(&pmu_lock, flags);
}
static void armv7pmu_stop(void)
{
unsigned long flags;
raw_spin_lock_irqsave(&pmu_lock, flags);
armv7_pmnc_write(armv7_pmnc_read() & ~ARMV7_PMNC_E);
raw_spin_unlock_irqrestore(&pmu_lock, flags);
}
static int armv7pmu_get_event_idx(struct cpu_hw_events *cpuc,
struct hw_perf_event *event)
{
int idx;
if (event->config_base == ARMV7_PERFCTR_CPU_CYCLES) {
if (test_and_set_bit(ARMV7_CYCLE_COUNTER, cpuc->used_mask))
return -EAGAIN;
return ARMV7_CYCLE_COUNTER;
} else {
for (idx = ARMV7_COUNTER0; idx <= armpmu->num_events; ++idx) {
if (!test_and_set_bit(idx, cpuc->used_mask))
return idx;
}
return -EAGAIN;
}
}
static void armv7pmu_reset(void *info)
{
u32 idx, nb_cnt = armpmu->num_events;
for (idx = 1; idx < nb_cnt; ++idx)
armv7pmu_disable_event(NULL, idx);
armv7_pmnc_write(ARMV7_PMNC_P | ARMV7_PMNC_C);
}
static u32 __init armv7_read_num_pmnc_events(void)
{
u32 nb_cnt;
nb_cnt = (armv7_pmnc_read() >> ARMV7_PMNC_N_SHIFT) & ARMV7_PMNC_N_MASK;
return nb_cnt + 1;
}
static const struct arm_pmu *__init armv7_a8_pmu_init(void)
{
armv7pmu.id = ARM_PERF_PMU_ID_CA8;
armv7pmu.name = "ARMv7 Cortex-A8";
armv7pmu.cache_map = &armv7_a8_perf_cache_map;
armv7pmu.event_map = &armv7_a8_perf_map;
armv7pmu.num_events = armv7_read_num_pmnc_events();
return &armv7pmu;
}
static const struct arm_pmu *__init armv7_a9_pmu_init(void)
{
armv7pmu.id = ARM_PERF_PMU_ID_CA9;
armv7pmu.name = "ARMv7 Cortex-A9";
armv7pmu.cache_map = &armv7_a9_perf_cache_map;
armv7pmu.event_map = &armv7_a9_perf_map;
armv7pmu.num_events = armv7_read_num_pmnc_events();
return &armv7pmu;
}
static const struct arm_pmu *__init armv7_a8_pmu_init(void)
{
return NULL;
}
static const struct arm_pmu *__init armv7_a9_pmu_init(void)
{
return NULL;
}
