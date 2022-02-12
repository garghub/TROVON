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
static inline int armv7_pmnc_counter_valid(struct arm_pmu *cpu_pmu, int idx)
{
return idx >= ARMV7_IDX_CYCLE_COUNTER &&
idx <= ARMV7_IDX_COUNTER_LAST(cpu_pmu);
}
static inline int armv7_pmnc_counter_has_overflowed(u32 pmnc, int idx)
{
return pmnc & BIT(ARMV7_IDX_TO_COUNTER(idx));
}
static inline void armv7_pmnc_select_counter(int idx)
{
u32 counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (counter));
isb();
}
static inline u32 armv7pmu_read_counter(struct perf_event *event)
{
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
u32 value = 0;
if (!armv7_pmnc_counter_valid(cpu_pmu, idx)) {
pr_err("CPU%u reading wrong counter %d\n",
smp_processor_id(), idx);
} else if (idx == ARMV7_IDX_CYCLE_COUNTER) {
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
} else {
armv7_pmnc_select_counter(idx);
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (value));
}
return value;
}
static inline void armv7pmu_write_counter(struct perf_event *event, u32 value)
{
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
if (!armv7_pmnc_counter_valid(cpu_pmu, idx)) {
pr_err("CPU%u writing wrong counter %d\n",
smp_processor_id(), idx);
} else if (idx == ARMV7_IDX_CYCLE_COUNTER) {
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
} else {
armv7_pmnc_select_counter(idx);
asm volatile("mcr p15, 0, %0, c9, c13, 2" : : "r" (value));
}
}
static inline void armv7_pmnc_write_evtsel(int idx, u32 val)
{
armv7_pmnc_select_counter(idx);
val &= ARMV7_EVTYPE_MASK;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
static inline void armv7_pmnc_enable_counter(int idx)
{
u32 counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (BIT(counter)));
}
static inline void armv7_pmnc_disable_counter(int idx)
{
u32 counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (BIT(counter)));
}
static inline void armv7_pmnc_enable_intens(int idx)
{
u32 counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (BIT(counter)));
}
static inline void armv7_pmnc_disable_intens(int idx)
{
u32 counter = ARMV7_IDX_TO_COUNTER(idx);
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (BIT(counter)));
isb();
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (BIT(counter)));
isb();
}
static inline u32 armv7_pmnc_getreset_flags(void)
{
u32 val;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
val &= ARMV7_FLAG_MASK;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (val));
return val;
}
static void armv7_pmnc_dump_regs(struct arm_pmu *cpu_pmu)
{
u32 val;
unsigned int cnt;
pr_info("PMNC registers dump:\n");
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r" (val));
pr_info("PMNC =0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r" (val));
pr_info("CNTENS=0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c14, 1" : "=r" (val));
pr_info("INTENS=0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
pr_info("FLAGS =0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c12, 5" : "=r" (val));
pr_info("SELECT=0x%08x\n", val);
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (val));
pr_info("CCNT =0x%08x\n", val);
for (cnt = ARMV7_IDX_COUNTER0;
cnt <= ARMV7_IDX_COUNTER_LAST(cpu_pmu); cnt++) {
armv7_pmnc_select_counter(cnt);
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
pr_info("CNT[%d] count =0x%08x\n",
ARMV7_IDX_TO_COUNTER(cnt), val);
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
pr_info("CNT[%d] evtsel=0x%08x\n",
ARMV7_IDX_TO_COUNTER(cnt), val);
}
}
static void armv7pmu_enable_event(struct perf_event *event)
{
unsigned long flags;
struct hw_perf_event *hwc = &event->hw;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
int idx = hwc->idx;
if (!armv7_pmnc_counter_valid(cpu_pmu, idx)) {
pr_err("CPU%u enabling wrong PMNC counter IRQ enable %d\n",
smp_processor_id(), idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
if (cpu_pmu->set_event_filter || idx != ARMV7_IDX_CYCLE_COUNTER)
armv7_pmnc_write_evtsel(idx, hwc->config_base);
armv7_pmnc_enable_intens(idx);
armv7_pmnc_enable_counter(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void armv7pmu_disable_event(struct perf_event *event)
{
unsigned long flags;
struct hw_perf_event *hwc = &event->hw;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
int idx = hwc->idx;
if (!armv7_pmnc_counter_valid(cpu_pmu, idx)) {
pr_err("CPU%u disabling wrong PMNC counter IRQ enable %d\n",
smp_processor_id(), idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
armv7_pmnc_disable_intens(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static irqreturn_t armv7pmu_handle_irq(int irq_num, void *dev)
{
u32 pmnc;
struct perf_sample_data data;
struct arm_pmu *cpu_pmu = (struct arm_pmu *)dev;
struct pmu_hw_events *cpuc = this_cpu_ptr(cpu_pmu->hw_events);
struct pt_regs *regs;
int idx;
pmnc = armv7_pmnc_getreset_flags();
if (!armv7_pmnc_has_overflowed(pmnc))
return IRQ_NONE;
regs = get_irq_regs();
for (idx = 0; idx < cpu_pmu->num_events; ++idx) {
struct perf_event *event = cpuc->events[idx];
struct hw_perf_event *hwc;
if (!event)
continue;
if (!armv7_pmnc_counter_has_overflowed(pmnc, idx))
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
static void armv7pmu_start(struct arm_pmu *cpu_pmu)
{
unsigned long flags;
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_write(armv7_pmnc_read() | ARMV7_PMNC_E);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void armv7pmu_stop(struct arm_pmu *cpu_pmu)
{
unsigned long flags;
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_write(armv7_pmnc_read() & ~ARMV7_PMNC_E);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static int armv7pmu_get_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
int idx;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
unsigned long evtype = hwc->config_base & ARMV7_EVTYPE_EVENT;
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
struct arm_pmu *cpu_pmu = (struct arm_pmu *)info;
u32 idx, nb_cnt = cpu_pmu->num_events, val;
if (cpu_pmu->secure_access) {
asm volatile("mrc p15, 0, %0, c1, c1, 1" : "=r" (val));
val |= ARMV7_SDER_SUNIDEN;
asm volatile("mcr p15, 0, %0, c1, c1, 1" : : "r" (val));
}
for (idx = ARMV7_IDX_CYCLE_COUNTER; idx < nb_cnt; ++idx) {
armv7_pmnc_disable_counter(idx);
armv7_pmnc_disable_intens(idx);
}
armv7_pmnc_write(ARMV7_PMNC_P | ARMV7_PMNC_C);
}
static int armv7_a8_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv7_a8_perf_map,
&armv7_a8_perf_cache_map, 0xFF);
}
static int armv7_a9_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv7_a9_perf_map,
&armv7_a9_perf_cache_map, 0xFF);
}
static int armv7_a5_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv7_a5_perf_map,
&armv7_a5_perf_cache_map, 0xFF);
}
static int armv7_a15_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv7_a15_perf_map,
&armv7_a15_perf_cache_map, 0xFF);
}
static int armv7_a7_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv7_a7_perf_map,
&armv7_a7_perf_cache_map, 0xFF);
}
static int armv7_a12_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &armv7_a12_perf_map,
&armv7_a12_perf_cache_map, 0xFF);
}
static int krait_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &krait_perf_map,
&krait_perf_cache_map, 0xFFFFF);
}
static int krait_map_event_no_branch(struct perf_event *event)
{
return armpmu_map_event(event, &krait_perf_map_no_branch,
&krait_perf_cache_map, 0xFFFFF);
}
static int scorpion_map_event(struct perf_event *event)
{
return armpmu_map_event(event, &scorpion_perf_map,
&scorpion_perf_cache_map, 0xFFFFF);
}
static void armv7pmu_init(struct arm_pmu *cpu_pmu)
{
cpu_pmu->handle_irq = armv7pmu_handle_irq;
cpu_pmu->enable = armv7pmu_enable_event;
cpu_pmu->disable = armv7pmu_disable_event;
cpu_pmu->read_counter = armv7pmu_read_counter;
cpu_pmu->write_counter = armv7pmu_write_counter;
cpu_pmu->get_event_idx = armv7pmu_get_event_idx;
cpu_pmu->start = armv7pmu_start;
cpu_pmu->stop = armv7pmu_stop;
cpu_pmu->reset = armv7pmu_reset;
cpu_pmu->max_period = (1LLU << 32) - 1;
}
static void armv7_read_num_pmnc_events(void *info)
{
int *nb_cnt = info;
*nb_cnt = (armv7_pmnc_read() >> ARMV7_PMNC_N_SHIFT) & ARMV7_PMNC_N_MASK;
*nb_cnt += 1;
}
static int armv7_probe_num_events(struct arm_pmu *arm_pmu)
{
return smp_call_function_any(&arm_pmu->supported_cpus,
armv7_read_num_pmnc_events,
&arm_pmu->num_events, 1);
}
static int armv7_a8_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_cortex_a8";
cpu_pmu->map_event = armv7_a8_map_event;
cpu_pmu->pmu.attr_groups = armv7_pmuv1_attr_groups;
return armv7_probe_num_events(cpu_pmu);
}
static int armv7_a9_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_cortex_a9";
cpu_pmu->map_event = armv7_a9_map_event;
cpu_pmu->pmu.attr_groups = armv7_pmuv1_attr_groups;
return armv7_probe_num_events(cpu_pmu);
}
static int armv7_a5_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_cortex_a5";
cpu_pmu->map_event = armv7_a5_map_event;
cpu_pmu->pmu.attr_groups = armv7_pmuv1_attr_groups;
return armv7_probe_num_events(cpu_pmu);
}
static int armv7_a15_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_cortex_a15";
cpu_pmu->map_event = armv7_a15_map_event;
cpu_pmu->set_event_filter = armv7pmu_set_event_filter;
cpu_pmu->pmu.attr_groups = armv7_pmuv2_attr_groups;
return armv7_probe_num_events(cpu_pmu);
}
static int armv7_a7_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_cortex_a7";
cpu_pmu->map_event = armv7_a7_map_event;
cpu_pmu->set_event_filter = armv7pmu_set_event_filter;
cpu_pmu->pmu.attr_groups = armv7_pmuv2_attr_groups;
return armv7_probe_num_events(cpu_pmu);
}
static int armv7_a12_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_cortex_a12";
cpu_pmu->map_event = armv7_a12_map_event;
cpu_pmu->set_event_filter = armv7pmu_set_event_filter;
cpu_pmu->pmu.attr_groups = armv7_pmuv2_attr_groups;
return armv7_probe_num_events(cpu_pmu);
}
static int armv7_a17_pmu_init(struct arm_pmu *cpu_pmu)
{
int ret = armv7_a12_pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_cortex_a17";
cpu_pmu->pmu.attr_groups = armv7_pmuv2_attr_groups;
return ret;
}
static u32 krait_read_pmresrn(int n)
{
u32 val;
switch (n) {
case 0:
asm volatile("mrc p15, 1, %0, c9, c15, 0" : "=r" (val));
break;
case 1:
asm volatile("mrc p15, 1, %0, c9, c15, 1" : "=r" (val));
break;
case 2:
asm volatile("mrc p15, 1, %0, c9, c15, 2" : "=r" (val));
break;
default:
BUG();
}
return val;
}
static void krait_write_pmresrn(int n, u32 val)
{
switch (n) {
case 0:
asm volatile("mcr p15, 1, %0, c9, c15, 0" : : "r" (val));
break;
case 1:
asm volatile("mcr p15, 1, %0, c9, c15, 1" : : "r" (val));
break;
case 2:
asm volatile("mcr p15, 1, %0, c9, c15, 2" : : "r" (val));
break;
default:
BUG();
}
}
static u32 venum_read_pmresr(void)
{
u32 val;
asm volatile("mrc p10, 7, %0, c11, c0, 0" : "=r" (val));
return val;
}
static void venum_write_pmresr(u32 val)
{
asm volatile("mcr p10, 7, %0, c11, c0, 0" : : "r" (val));
}
static void venum_pre_pmresr(u32 *venum_orig_val, u32 *fp_orig_val)
{
u32 venum_new_val;
u32 fp_new_val;
BUG_ON(preemptible());
*venum_orig_val = get_copro_access();
venum_new_val = *venum_orig_val | CPACC_SVC(10) | CPACC_SVC(11);
set_copro_access(venum_new_val);
*fp_orig_val = fmrx(FPEXC);
fp_new_val = *fp_orig_val | FPEXC_EN;
fmxr(FPEXC, fp_new_val);
}
static void venum_post_pmresr(u32 venum_orig_val, u32 fp_orig_val)
{
BUG_ON(preemptible());
fmxr(FPEXC, fp_orig_val);
isb();
set_copro_access(venum_orig_val);
}
static u32 krait_get_pmresrn_event(unsigned int region)
{
static const u32 pmresrn_table[] = { KRAIT_PMRESR0_GROUP0,
KRAIT_PMRESR1_GROUP0,
KRAIT_PMRESR2_GROUP0 };
return pmresrn_table[region];
}
static void krait_evt_setup(int idx, u32 config_base)
{
u32 val;
u32 mask;
u32 vval, fval;
unsigned int region = EVENT_REGION(config_base);
unsigned int group = EVENT_GROUP(config_base);
unsigned int code = EVENT_CODE(config_base);
unsigned int group_shift;
bool venum_event = EVENT_VENUM(config_base);
group_shift = group * 8;
mask = 0xff << group_shift;
if (venum_event)
val = KRAIT_VPMRESR0_GROUP0;
else
val = krait_get_pmresrn_event(region);
val += group;
val |= config_base & (ARMV7_EXCLUDE_USER | ARMV7_EXCLUDE_PL1);
armv7_pmnc_write_evtsel(idx, val);
if (venum_event) {
venum_pre_pmresr(&vval, &fval);
val = venum_read_pmresr();
val &= ~mask;
val |= code << group_shift;
val |= PMRESRn_EN;
venum_write_pmresr(val);
venum_post_pmresr(vval, fval);
} else {
val = krait_read_pmresrn(region);
val &= ~mask;
val |= code << group_shift;
val |= PMRESRn_EN;
krait_write_pmresrn(region, val);
}
}
static u32 clear_pmresrn_group(u32 val, int group)
{
u32 mask;
int group_shift;
group_shift = group * 8;
mask = 0xff << group_shift;
val &= ~mask;
if (val & ~PMRESRn_EN)
return val |= PMRESRn_EN;
return 0;
}
static void krait_clearpmu(u32 config_base)
{
u32 val;
u32 vval, fval;
unsigned int region = EVENT_REGION(config_base);
unsigned int group = EVENT_GROUP(config_base);
bool venum_event = EVENT_VENUM(config_base);
if (venum_event) {
venum_pre_pmresr(&vval, &fval);
val = venum_read_pmresr();
val = clear_pmresrn_group(val, group);
venum_write_pmresr(val);
venum_post_pmresr(vval, fval);
} else {
val = krait_read_pmresrn(region);
val = clear_pmresrn_group(val, group);
krait_write_pmresrn(region, val);
}
}
static void krait_pmu_disable_event(struct perf_event *event)
{
unsigned long flags;
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
if (hwc->config_base & KRAIT_EVENT_MASK)
krait_clearpmu(hwc->config_base);
armv7_pmnc_disable_intens(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void krait_pmu_enable_event(struct perf_event *event)
{
unsigned long flags;
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
if (hwc->config_base & KRAIT_EVENT_MASK)
krait_evt_setup(idx, hwc->config_base);
else
armv7_pmnc_write_evtsel(idx, hwc->config_base);
armv7_pmnc_enable_intens(idx);
armv7_pmnc_enable_counter(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void krait_pmu_reset(void *info)
{
u32 vval, fval;
struct arm_pmu *cpu_pmu = info;
u32 idx, nb_cnt = cpu_pmu->num_events;
armv7pmu_reset(info);
krait_write_pmresrn(0, 0);
krait_write_pmresrn(1, 0);
krait_write_pmresrn(2, 0);
venum_pre_pmresr(&vval, &fval);
venum_write_pmresr(0);
venum_post_pmresr(vval, fval);
for (idx = ARMV7_IDX_CYCLE_COUNTER; idx < nb_cnt; ++idx) {
armv7_pmnc_select_counter(idx);
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
}
}
static int krait_event_to_bit(struct perf_event *event, unsigned int region,
unsigned int group)
{
int bit;
struct hw_perf_event *hwc = &event->hw;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
if (hwc->config_base & VENUM_EVENT)
bit = KRAIT_VPMRESR0_GROUP0;
else
bit = krait_get_pmresrn_event(region);
bit -= krait_get_pmresrn_event(0);
bit += group;
bit += ARMV7_IDX_COUNTER_LAST(cpu_pmu) + 1;
return bit;
}
static int krait_pmu_get_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
int idx;
int bit = -1;
struct hw_perf_event *hwc = &event->hw;
unsigned int region = EVENT_REGION(hwc->config_base);
unsigned int code = EVENT_CODE(hwc->config_base);
unsigned int group = EVENT_GROUP(hwc->config_base);
bool venum_event = EVENT_VENUM(hwc->config_base);
bool krait_event = EVENT_CPU(hwc->config_base);
if (venum_event || krait_event) {
if (group > 3 || region > 2)
return -EINVAL;
if (venum_event && (code & 0xe0))
return -EINVAL;
bit = krait_event_to_bit(event, region, group);
if (test_and_set_bit(bit, cpuc->used_mask))
return -EAGAIN;
}
idx = armv7pmu_get_event_idx(cpuc, event);
if (idx < 0 && bit >= 0)
clear_bit(bit, cpuc->used_mask);
return idx;
}
static void krait_pmu_clear_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
int bit;
struct hw_perf_event *hwc = &event->hw;
unsigned int region = EVENT_REGION(hwc->config_base);
unsigned int group = EVENT_GROUP(hwc->config_base);
bool venum_event = EVENT_VENUM(hwc->config_base);
bool krait_event = EVENT_CPU(hwc->config_base);
if (venum_event || krait_event) {
bit = krait_event_to_bit(event, region, group);
clear_bit(bit, cpuc->used_mask);
}
}
static int krait_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_krait";
if (of_property_read_bool(cpu_pmu->plat_device->dev.of_node,
"qcom,no-pc-write"))
cpu_pmu->map_event = krait_map_event_no_branch;
else
cpu_pmu->map_event = krait_map_event;
cpu_pmu->set_event_filter = armv7pmu_set_event_filter;
cpu_pmu->reset = krait_pmu_reset;
cpu_pmu->enable = krait_pmu_enable_event;
cpu_pmu->disable = krait_pmu_disable_event;
cpu_pmu->get_event_idx = krait_pmu_get_event_idx;
cpu_pmu->clear_event_idx = krait_pmu_clear_event_idx;
return armv7_probe_num_events(cpu_pmu);
}
static u32 scorpion_read_pmresrn(int n)
{
u32 val;
switch (n) {
case 0:
asm volatile("mrc p15, 0, %0, c15, c0, 0" : "=r" (val));
break;
case 1:
asm volatile("mrc p15, 1, %0, c15, c0, 0" : "=r" (val));
break;
case 2:
asm volatile("mrc p15, 2, %0, c15, c0, 0" : "=r" (val));
break;
case 3:
asm volatile("mrc p15, 3, %0, c15, c2, 0" : "=r" (val));
break;
default:
BUG();
}
return val;
}
static void scorpion_write_pmresrn(int n, u32 val)
{
switch (n) {
case 0:
asm volatile("mcr p15, 0, %0, c15, c0, 0" : : "r" (val));
break;
case 1:
asm volatile("mcr p15, 1, %0, c15, c0, 0" : : "r" (val));
break;
case 2:
asm volatile("mcr p15, 2, %0, c15, c0, 0" : : "r" (val));
break;
case 3:
asm volatile("mcr p15, 3, %0, c15, c2, 0" : : "r" (val));
break;
default:
BUG();
}
}
static u32 scorpion_get_pmresrn_event(unsigned int region)
{
static const u32 pmresrn_table[] = { SCORPION_LPM0_GROUP0,
SCORPION_LPM1_GROUP0,
SCORPION_LPM2_GROUP0,
SCORPION_L2LPM_GROUP0 };
return pmresrn_table[region];
}
static void scorpion_evt_setup(int idx, u32 config_base)
{
u32 val;
u32 mask;
u32 vval, fval;
unsigned int region = EVENT_REGION(config_base);
unsigned int group = EVENT_GROUP(config_base);
unsigned int code = EVENT_CODE(config_base);
unsigned int group_shift;
bool venum_event = EVENT_VENUM(config_base);
group_shift = group * 8;
mask = 0xff << group_shift;
if (venum_event)
val = SCORPION_VLPM_GROUP0;
else
val = scorpion_get_pmresrn_event(region);
val += group;
val |= config_base & (ARMV7_EXCLUDE_USER | ARMV7_EXCLUDE_PL1);
armv7_pmnc_write_evtsel(idx, val);
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
if (venum_event) {
venum_pre_pmresr(&vval, &fval);
val = venum_read_pmresr();
val &= ~mask;
val |= code << group_shift;
val |= PMRESRn_EN;
venum_write_pmresr(val);
venum_post_pmresr(vval, fval);
} else {
val = scorpion_read_pmresrn(region);
val &= ~mask;
val |= code << group_shift;
val |= PMRESRn_EN;
scorpion_write_pmresrn(region, val);
}
}
static void scorpion_clearpmu(u32 config_base)
{
u32 val;
u32 vval, fval;
unsigned int region = EVENT_REGION(config_base);
unsigned int group = EVENT_GROUP(config_base);
bool venum_event = EVENT_VENUM(config_base);
if (venum_event) {
venum_pre_pmresr(&vval, &fval);
val = venum_read_pmresr();
val = clear_pmresrn_group(val, group);
venum_write_pmresr(val);
venum_post_pmresr(vval, fval);
} else {
val = scorpion_read_pmresrn(region);
val = clear_pmresrn_group(val, group);
scorpion_write_pmresrn(region, val);
}
}
static void scorpion_pmu_disable_event(struct perf_event *event)
{
unsigned long flags;
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
if (hwc->config_base & KRAIT_EVENT_MASK)
scorpion_clearpmu(hwc->config_base);
armv7_pmnc_disable_intens(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void scorpion_pmu_enable_event(struct perf_event *event)
{
unsigned long flags;
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *events = this_cpu_ptr(cpu_pmu->hw_events);
raw_spin_lock_irqsave(&events->pmu_lock, flags);
armv7_pmnc_disable_counter(idx);
if (hwc->config_base & KRAIT_EVENT_MASK)
scorpion_evt_setup(idx, hwc->config_base);
else if (idx != ARMV7_IDX_CYCLE_COUNTER)
armv7_pmnc_write_evtsel(idx, hwc->config_base);
armv7_pmnc_enable_intens(idx);
armv7_pmnc_enable_counter(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void scorpion_pmu_reset(void *info)
{
u32 vval, fval;
struct arm_pmu *cpu_pmu = info;
u32 idx, nb_cnt = cpu_pmu->num_events;
armv7pmu_reset(info);
scorpion_write_pmresrn(0, 0);
scorpion_write_pmresrn(1, 0);
scorpion_write_pmresrn(2, 0);
scorpion_write_pmresrn(3, 0);
venum_pre_pmresr(&vval, &fval);
venum_write_pmresr(0);
venum_post_pmresr(vval, fval);
for (idx = ARMV7_IDX_CYCLE_COUNTER; idx < nb_cnt; ++idx) {
armv7_pmnc_select_counter(idx);
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
}
}
static int scorpion_event_to_bit(struct perf_event *event, unsigned int region,
unsigned int group)
{
int bit;
struct hw_perf_event *hwc = &event->hw;
struct arm_pmu *cpu_pmu = to_arm_pmu(event->pmu);
if (hwc->config_base & VENUM_EVENT)
bit = SCORPION_VLPM_GROUP0;
else
bit = scorpion_get_pmresrn_event(region);
bit -= scorpion_get_pmresrn_event(0);
bit += group;
bit += ARMV7_IDX_COUNTER_LAST(cpu_pmu) + 1;
return bit;
}
static int scorpion_pmu_get_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
int idx;
int bit = -1;
struct hw_perf_event *hwc = &event->hw;
unsigned int region = EVENT_REGION(hwc->config_base);
unsigned int group = EVENT_GROUP(hwc->config_base);
bool venum_event = EVENT_VENUM(hwc->config_base);
bool scorpion_event = EVENT_CPU(hwc->config_base);
if (venum_event || scorpion_event) {
if (group > 3 || region > 3)
return -EINVAL;
bit = scorpion_event_to_bit(event, region, group);
if (test_and_set_bit(bit, cpuc->used_mask))
return -EAGAIN;
}
idx = armv7pmu_get_event_idx(cpuc, event);
if (idx < 0 && bit >= 0)
clear_bit(bit, cpuc->used_mask);
return idx;
}
static void scorpion_pmu_clear_event_idx(struct pmu_hw_events *cpuc,
struct perf_event *event)
{
int bit;
struct hw_perf_event *hwc = &event->hw;
unsigned int region = EVENT_REGION(hwc->config_base);
unsigned int group = EVENT_GROUP(hwc->config_base);
bool venum_event = EVENT_VENUM(hwc->config_base);
bool scorpion_event = EVENT_CPU(hwc->config_base);
if (venum_event || scorpion_event) {
bit = scorpion_event_to_bit(event, region, group);
clear_bit(bit, cpuc->used_mask);
}
}
static int scorpion_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_scorpion";
cpu_pmu->map_event = scorpion_map_event;
cpu_pmu->reset = scorpion_pmu_reset;
cpu_pmu->enable = scorpion_pmu_enable_event;
cpu_pmu->disable = scorpion_pmu_disable_event;
cpu_pmu->get_event_idx = scorpion_pmu_get_event_idx;
cpu_pmu->clear_event_idx = scorpion_pmu_clear_event_idx;
return armv7_probe_num_events(cpu_pmu);
}
static int scorpion_mp_pmu_init(struct arm_pmu *cpu_pmu)
{
armv7pmu_init(cpu_pmu);
cpu_pmu->name = "armv7_scorpion_mp";
cpu_pmu->map_event = scorpion_map_event;
cpu_pmu->reset = scorpion_pmu_reset;
cpu_pmu->enable = scorpion_pmu_enable_event;
cpu_pmu->disable = scorpion_pmu_disable_event;
cpu_pmu->get_event_idx = scorpion_pmu_get_event_idx;
cpu_pmu->clear_event_idx = scorpion_pmu_clear_event_idx;
return armv7_probe_num_events(cpu_pmu);
}
static int armv7_pmu_device_probe(struct platform_device *pdev)
{
return arm_pmu_device_probe(pdev, armv7_pmu_of_device_ids,
armv7_pmu_probe_table);
}
static int __init register_armv7_pmu_driver(void)
{
return platform_driver_register(&armv7_pmu_driver);
}
