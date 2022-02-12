static inline u32 armv7_pmnc_read(void)
{
u32 val;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r"(val));
return val;
}
static inline void armv7_pmnc_write(u32 val)
{
val &= ARMV7_PMNC_MASK;
isb();
asm volatile("mcr p15, 0, %0, c9, c12, 0" : : "r"(val));
}
static inline int armv7_pmnc_has_overflowed(u32 pmnc)
{
return pmnc & ARMV7_OVERFLOWED_MASK;
}
static inline int armv7_pmnc_counter_valid(int idx)
{
return idx >= ARMV7_IDX_CYCLE_COUNTER && idx <= ARMV7_IDX_COUNTER_LAST;
}
static inline int armv7_pmnc_counter_has_overflowed(u32 pmnc, int idx)
{
int ret = 0;
u32 counter;
if (!armv7_pmnc_counter_valid(idx)) {
pr_err("CPU%u checking wrong counter %d overflow status\n",
smp_processor_id(), idx);
} else {
counter = ARMV7_IDX_TO_COUNTER(idx);
ret = pmnc & BIT(counter);
}
return ret;
}
static inline int armv7_pmnc_select_counter(int idx)
{
u32 counter;
if (!armv7_pmnc_counter_valid(idx)) {
pr_err("CPU%u selecting wrong PMNC counter %d\n",
smp_processor_id(), idx);
return -EINVAL;
}
counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (counter));
isb();
return idx;
}
static inline u32 armv7pmu_read_counter(int idx)
{
u32 value = 0;
if (!armv7_pmnc_counter_valid(idx))
pr_err("CPU%u reading wrong counter %d\n",
smp_processor_id(), idx);
else if (idx == ARMV7_IDX_CYCLE_COUNTER)
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
else if (armv7_pmnc_select_counter(idx) == idx)
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (value));
return value;
}
static inline void armv7pmu_write_counter(int idx, u32 value)
{
if (!armv7_pmnc_counter_valid(idx))
pr_err("CPU%u writing wrong counter %d\n",
smp_processor_id(), idx);
else if (idx == ARMV7_IDX_CYCLE_COUNTER)
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
else if (armv7_pmnc_select_counter(idx) == idx)
asm volatile("mcr p15, 0, %0, c9, c13, 2" : : "r" (value));
}
static inline void armv7_pmnc_write_evtsel(int idx, u32 val)
{
if (armv7_pmnc_select_counter(idx) == idx) {
val &= ARMV7_EVTYPE_MASK;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
}
static inline int armv7_pmnc_enable_counter(int idx)
{
u32 counter;
if (!armv7_pmnc_counter_valid(idx)) {
pr_err("CPU%u enabling wrong PMNC counter %d\n",
smp_processor_id(), idx);
return -EINVAL;
}
counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (BIT(counter)));
return idx;
}
static inline int armv7_pmnc_disable_counter(int idx)
{
u32 counter;
if (!armv7_pmnc_counter_valid(idx)) {
pr_err("CPU%u disabling wrong PMNC counter %d\n",
smp_processor_id(), idx);
return -EINVAL;
}
counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (BIT(counter)));
return idx;
}
static inline int armv7_pmnc_enable_intens(int idx)
{
u32 counter;
if (!armv7_pmnc_counter_valid(idx)) {
pr_err("CPU%u enabling wrong PMNC counter IRQ enable %d\n",
smp_processor_id(), idx);
return -EINVAL;
}
counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (BIT(counter)));
return idx;
}
static inline int armv7_pmnc_disable_intens(int idx)
{
u32 counter;
if (!armv7_pmnc_counter_valid(idx)) {
pr_err("CPU%u disabling wrong PMNC counter IRQ enable %d\n",
smp_processor_id(), idx);
return -EINVAL;
}
counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (BIT(counter)));
isb();
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (BIT(counter)));
isb();
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
for (cnt = ARMV7_IDX_COUNTER0; cnt <= ARMV7_IDX_COUNTER_LAST; cnt++) {
armv7_pmnc_select_counter(cnt);
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
printk(KERN_INFO "CNT[%d] count =0x%08x\n",
ARMV7_IDX_TO_COUNTER(cnt), val);
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
printk(KERN_INFO "CNT[%d] evtsel=0x%08x\n",
ARMV7_IDX_TO_COUNTER(cnt), val);
}
}
static void armv7pmu_enable_event(struct hw_perf_event *hwc, int idx)
{
unsigned long flags;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
if (armv7pmu.set_event_filter || idx != ARMV7_IDX_CYCLE_COUNTER)
armv7_pmnc_write_evtsel(idx, hwc->config_base);
armv7_pmnc_enable_intens(idx);
armv7_pmnc_enable_counter(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void armv7pmu_disable_event(struct hw_perf_event *hwc, int idx)
{
unsigned long flags;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
armv7_pmnc_disable_intens(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static irqreturn_t armv7pmu_handle_irq(int irq_num, void *dev)
{
u32 pmnc;
struct perf_sample_data data;
struct pmu_hw_events *cpuc;
struct pt_regs *regs;
int idx;
pmnc = armv7_pmnc_getreset_flags();
if (!armv7_pmnc_has_overflowed(pmnc))
return IRQ_NONE;
regs = get_irq_regs();
perf_sample_data_init(&data, 0);
cpuc = &__get_cpu_var(cpu_hw_events);
for (idx = 0; idx < cpu_pmu->num_events; ++idx) {
struct perf_event *event = cpuc->events[idx];
struct hw_perf_event *hwc;
if (!event)
continue;
if (!armv7_pmnc_counter_has_overflowed(pmnc, idx))
continue;
hwc = &event->hw;
armpmu_event_update(event, hwc, idx);
data.period = event->hw.last_period;
if (!armpmu_event_set_period(event, hwc, idx))
continue;
if (perf_event_overflow(event, &data, regs))
cpu_pmu->disable(hwc, idx);
}
irq_work_run();
return IRQ_HANDLED;
}
static void armv7pmu_start(void)
{
unsigned long flags;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_write(armv7_pmnc_read() | ARMV7_PMNC_E);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void armv7pmu_stop(void)
{
unsigned long flags;
struct pmu_hw_events *events = cpu_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_write(armv7_pmnc_read() & ~ARMV7_PMNC_E);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static int armv7pmu_get_event_idx(struct pmu_hw_events *cpuc,
struct hw_perf_event *event)
{
int idx;
unsigned long evtype = event->config_base & ARMV7_EVTYPE_EVENT;
if (evtype == ARMV7_PERFCTR_CPU_CYCLES) {
if (test_and_set_bit(ARMV7_IDX_CYCLE_COUNTER, cpuc->used_mask))
return -EAGAIN;
return ARMV7_IDX_CYCLE_COUNTER;
}
for (idx = ARMV7_IDX_COUNTER0; idx < cpu_pmu->num_events; ++idx) {
if (!test_and_set_bit(idx, cpuc->used_mask))
return idx;
}
return -EAGAIN;
}
static int armv7pmu_set_event_filter(struct hw_perf_event *event,
struct perf_event_attr *attr)
{
unsigned long config_base = 0;
if (attr->exclude_idle)
return -EPERM;
if (attr->exclude_user)
config_base |= ARMV7_EXCLUDE_USER;
if (attr->exclude_kernel)
config_base |= ARMV7_EXCLUDE_PL1;
if (!attr->exclude_hv)
config_base |= ARMV7_INCLUDE_HYP;
event->config_base = config_base;
return 0;
}
static void armv7pmu_reset(void *info)
{
u32 idx, nb_cnt = cpu_pmu->num_events;
for (idx = ARMV7_IDX_CYCLE_COUNTER; idx < nb_cnt; ++idx)
armv7pmu_disable_event(NULL, idx);
armv7_pmnc_write(ARMV7_PMNC_P | ARMV7_PMNC_C);
}
static int armv7_a8_map_event(struct perf_event *event)
{
return map_cpu_event(event, &armv7_a8_perf_map,
&armv7_a8_perf_cache_map, 0xFF);
}
static int armv7_a9_map_event(struct perf_event *event)
{
return map_cpu_event(event, &armv7_a9_perf_map,
&armv7_a9_perf_cache_map, 0xFF);
}
static int armv7_a5_map_event(struct perf_event *event)
{
return map_cpu_event(event, &armv7_a5_perf_map,
&armv7_a5_perf_cache_map, 0xFF);
}
static int armv7_a15_map_event(struct perf_event *event)
{
return map_cpu_event(event, &armv7_a15_perf_map,
&armv7_a15_perf_cache_map, 0xFF);
}
static int armv7_a7_map_event(struct perf_event *event)
{
return map_cpu_event(event, &armv7_a7_perf_map,
&armv7_a7_perf_cache_map, 0xFF);
}
static u32 __init armv7_read_num_pmnc_events(void)
{
u32 nb_cnt;
nb_cnt = (armv7_pmnc_read() >> ARMV7_PMNC_N_SHIFT) & ARMV7_PMNC_N_MASK;
return nb_cnt + 1;
}
static struct arm_pmu *__init armv7_a8_pmu_init(void)
{
armv7pmu.id = ARM_PERF_PMU_ID_CA8;
armv7pmu.name = "ARMv7 Cortex-A8";
armv7pmu.map_event = armv7_a8_map_event;
armv7pmu.num_events = armv7_read_num_pmnc_events();
return &armv7pmu;
}
static struct arm_pmu *__init armv7_a9_pmu_init(void)
{
armv7pmu.id = ARM_PERF_PMU_ID_CA9;
armv7pmu.name = "ARMv7 Cortex-A9";
armv7pmu.map_event = armv7_a9_map_event;
armv7pmu.num_events = armv7_read_num_pmnc_events();
return &armv7pmu;
}
static struct arm_pmu *__init armv7_a5_pmu_init(void)
{
armv7pmu.id = ARM_PERF_PMU_ID_CA5;
armv7pmu.name = "ARMv7 Cortex-A5";
armv7pmu.map_event = armv7_a5_map_event;
armv7pmu.num_events = armv7_read_num_pmnc_events();
return &armv7pmu;
}
static struct arm_pmu *__init armv7_a15_pmu_init(void)
{
armv7pmu.id = ARM_PERF_PMU_ID_CA15;
armv7pmu.name = "ARMv7 Cortex-A15";
armv7pmu.map_event = armv7_a15_map_event;
armv7pmu.num_events = armv7_read_num_pmnc_events();
armv7pmu.set_event_filter = armv7pmu_set_event_filter;
return &armv7pmu;
}
static struct arm_pmu *__init armv7_a7_pmu_init(void)
{
armv7pmu.id = ARM_PERF_PMU_ID_CA7;
armv7pmu.name = "ARMv7 Cortex-A7";
armv7pmu.map_event = armv7_a7_map_event;
armv7pmu.num_events = armv7_read_num_pmnc_events();
armv7pmu.set_event_filter = armv7pmu_set_event_filter;
return &armv7pmu;
}
static struct arm_pmu *__init armv7_a8_pmu_init(void)
{
return NULL;
}
static struct arm_pmu *__init armv7_a9_pmu_init(void)
{
return NULL;
}
static struct arm_pmu *__init armv7_a5_pmu_init(void)
{
return NULL;
}
static struct arm_pmu *__init armv7_a15_pmu_init(void)
{
return NULL;
}
static struct arm_pmu *__init armv7_a7_pmu_init(void)
{
return NULL;
}
