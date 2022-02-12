static inline unsigned int vpe_shift(void)
{
if (num_possible_cpus() > 1)
return 1;
return 0;
}
static inline unsigned int vpe_shift(void)
{
return 0;
}
static inline unsigned int
counters_total_to_per_cpu(unsigned int counters)
{
return counters >> vpe_shift();
}
static inline unsigned int
counters_per_cpu_to_total(unsigned int counters)
{
return counters << vpe_shift();
}
static inline int __n_counters(void)
{
if (!(read_c0_config1() & M_CONFIG1_PC))
return 0;
if (!(read_c0_perfctrl0() & M_PERFCTL_MORE))
return 1;
if (!(read_c0_perfctrl1() & M_PERFCTL_MORE))
return 2;
if (!(read_c0_perfctrl2() & M_PERFCTL_MORE))
return 3;
return 4;
}
static inline int n_counters(void)
{
int counters;
switch (current_cpu_type()) {
case CPU_R10000:
counters = 2;
break;
case CPU_R12000:
case CPU_R14000:
counters = 4;
break;
default:
counters = __n_counters();
}
return counters;
}
static void reset_counters(void *arg)
{
int counters = (int)(long)arg;
switch (counters) {
case 4:
w_c0_perfctrl3(0);
w_c0_perfcntr3(0);
case 3:
w_c0_perfctrl2(0);
w_c0_perfcntr2(0);
case 2:
w_c0_perfctrl1(0);
w_c0_perfcntr1(0);
case 1:
w_c0_perfctrl0(0);
w_c0_perfcntr0(0);
}
}
static inline u64
mipsxx_pmu_read_counter(unsigned int idx)
{
switch (idx) {
case 0:
return r_c0_perfcntr0();
case 1:
return r_c0_perfcntr1();
case 2:
return r_c0_perfcntr2();
case 3:
return r_c0_perfcntr3();
default:
WARN_ONCE(1, "Invalid performance counter number (%d)\n", idx);
return 0;
}
}
static inline void
mipsxx_pmu_write_counter(unsigned int idx, u64 val)
{
switch (idx) {
case 0:
w_c0_perfcntr0(val);
return;
case 1:
w_c0_perfcntr1(val);
return;
case 2:
w_c0_perfcntr2(val);
return;
case 3:
w_c0_perfcntr3(val);
return;
}
}
static inline unsigned int
mipsxx_pmu_read_control(unsigned int idx)
{
switch (idx) {
case 0:
return r_c0_perfctrl0();
case 1:
return r_c0_perfctrl1();
case 2:
return r_c0_perfctrl2();
case 3:
return r_c0_perfctrl3();
default:
WARN_ONCE(1, "Invalid performance counter number (%d)\n", idx);
return 0;
}
}
static inline void
mipsxx_pmu_write_control(unsigned int idx, unsigned int val)
{
switch (idx) {
case 0:
w_c0_perfctrl0(val);
return;
case 1:
w_c0_perfctrl1(val);
return;
case 2:
w_c0_perfctrl2(val);
return;
case 3:
w_c0_perfctrl3(val);
return;
}
}
static void
check_and_calc_range(struct perf_event *event,
const struct mips_perf_event *pev)
{
struct hw_perf_event *hwc = &event->hw;
if (event->cpu >= 0) {
if (pev->range > V) {
hwc->config_base |= M_TC_EN_ALL;
} else {
hwc->config_base |= M_PERFCTL_VPEID(event->cpu);
hwc->config_base |= M_TC_EN_VPE;
}
} else
hwc->config_base |= M_TC_EN_ALL;
}
static void
check_and_calc_range(struct perf_event *event,
const struct mips_perf_event *pev)
{
}
static int __hw_perf_event_init(struct perf_event *event)
{
struct perf_event_attr *attr = &event->attr;
struct hw_perf_event *hwc = &event->hw;
const struct mips_perf_event *pev;
int err;
if (PERF_TYPE_HARDWARE == event->attr.type) {
if (event->attr.config >= PERF_COUNT_HW_MAX)
return -EINVAL;
pev = mipspmu_map_general_event(event->attr.config);
} else if (PERF_TYPE_HW_CACHE == event->attr.type) {
pev = mipspmu_map_cache_event(event->attr.config);
} else if (PERF_TYPE_RAW == event->attr.type) {
mutex_lock(&raw_event_mutex);
pev = mipspmu->map_raw_event(event->attr.config);
} else {
return -EOPNOTSUPP;
}
if (IS_ERR(pev)) {
if (PERF_TYPE_RAW == event->attr.type)
mutex_unlock(&raw_event_mutex);
return PTR_ERR(pev);
}
hwc->config_base = M_PERFCTL_INTERRUPT_ENABLE;
if (num_possible_cpus() > 1)
check_and_calc_range(event, pev);
hwc->event_base = mipspmu_perf_event_encode(pev);
if (PERF_TYPE_RAW == event->attr.type)
mutex_unlock(&raw_event_mutex);
if (!attr->exclude_user)
hwc->config_base |= M_PERFCTL_USER;
if (!attr->exclude_kernel) {
hwc->config_base |= M_PERFCTL_KERNEL;
hwc->config_base |= M_PERFCTL_EXL;
}
if (!attr->exclude_hv)
hwc->config_base |= M_PERFCTL_SUPERVISOR;
hwc->config_base &= M_PERFCTL_CONFIG_MASK;
hwc->idx = -1;
hwc->config = 0;
if (!hwc->sample_period) {
hwc->sample_period = MAX_PERIOD;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
}
err = 0;
if (event->group_leader != event) {
err = validate_group(event);
if (err)
return -EINVAL;
}
event->destroy = hw_perf_event_destroy;
return err;
}
static void pause_local_counters(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
int counters = mipspmu->num_counters;
unsigned long flags;
local_irq_save(flags);
switch (counters) {
case 4:
cpuc->saved_ctrl[3] = r_c0_perfctrl3();
w_c0_perfctrl3(cpuc->saved_ctrl[3] &
~M_PERFCTL_COUNT_EVENT_WHENEVER);
case 3:
cpuc->saved_ctrl[2] = r_c0_perfctrl2();
w_c0_perfctrl2(cpuc->saved_ctrl[2] &
~M_PERFCTL_COUNT_EVENT_WHENEVER);
case 2:
cpuc->saved_ctrl[1] = r_c0_perfctrl1();
w_c0_perfctrl1(cpuc->saved_ctrl[1] &
~M_PERFCTL_COUNT_EVENT_WHENEVER);
case 1:
cpuc->saved_ctrl[0] = r_c0_perfctrl0();
w_c0_perfctrl0(cpuc->saved_ctrl[0] &
~M_PERFCTL_COUNT_EVENT_WHENEVER);
}
local_irq_restore(flags);
}
static void resume_local_counters(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
int counters = mipspmu->num_counters;
unsigned long flags;
local_irq_save(flags);
switch (counters) {
case 4:
w_c0_perfctrl3(cpuc->saved_ctrl[3]);
case 3:
w_c0_perfctrl2(cpuc->saved_ctrl[2]);
case 2:
w_c0_perfctrl1(cpuc->saved_ctrl[1]);
case 1:
w_c0_perfctrl0(cpuc->saved_ctrl[0]);
}
local_irq_restore(flags);
}
static int mipsxx_pmu_handle_shared_irq(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct perf_sample_data data;
unsigned int counters = mipspmu->num_counters;
unsigned int counter;
int handled = IRQ_NONE;
struct pt_regs *regs;
if (cpu_has_mips_r2 && !(read_c0_cause() & (1 << 26)))
return handled;
pause_local_counters();
#ifdef CONFIG_MIPS_MT_SMP
read_lock(&pmuint_rwlock);
#endif
regs = get_irq_regs();
perf_sample_data_init(&data, 0);
switch (counters) {
#define HANDLE_COUNTER(n) \
case n + 1: \
if (test_bit(n, cpuc->used_mask)) { \
counter = r_c0_perfcntr ## n(); \
if (counter & M_COUNTER_OVERFLOW) { \
w_c0_perfcntr ## n(counter & \
VALID_COUNT); \
if (test_and_change_bit(n, cpuc->msbs)) \
handle_associated_event(cpuc, \
n, &data, regs); \
handled = IRQ_HANDLED; \
} \
}
HANDLE_COUNTER(3)
HANDLE_COUNTER(2)
HANDLE_COUNTER(1)
HANDLE_COUNTER(0)
}
if (handled == IRQ_HANDLED)
irq_work_run();
#ifdef CONFIG_MIPS_MT_SMP
read_unlock(&pmuint_rwlock);
#endif
resume_local_counters();
return handled;
}
static irqreturn_t
mipsxx_pmu_handle_irq(int irq, void *dev)
{
return mipsxx_pmu_handle_shared_irq();
}
static void mipsxx_pmu_start(void)
{
#ifdef CONFIG_MIPS_MT_SMP
write_unlock(&pmuint_rwlock);
#endif
resume_local_counters();
}
static void mipsxx_pmu_stop(void)
{
pause_local_counters();
#ifdef CONFIG_MIPS_MT_SMP
write_lock(&pmuint_rwlock);
#endif
}
static int
mipsxx_pmu_alloc_counter(struct cpu_hw_events *cpuc,
struct hw_perf_event *hwc)
{
int i;
unsigned long cntr_mask = (hwc->event_base >> 8) & 0xffff;
for (i = mipspmu->num_counters - 1; i >= 0; i--) {
if (test_bit(i, &cntr_mask) &&
!test_and_set_bit(i, cpuc->used_mask))
return i;
}
return -EAGAIN;
}
static void
mipsxx_pmu_enable_event(struct hw_perf_event *evt, int idx)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
unsigned long flags;
WARN_ON(idx < 0 || idx >= mipspmu->num_counters);
local_irq_save(flags);
cpuc->saved_ctrl[idx] = M_PERFCTL_EVENT(evt->event_base & 0xff) |
(evt->config_base & M_PERFCTL_CONFIG_MASK) |
M_PERFCTL_INTERRUPT_ENABLE;
local_irq_restore(flags);
}
static void
mipsxx_pmu_disable_event(int idx)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
unsigned long flags;
WARN_ON(idx < 0 || idx >= mipspmu->num_counters);
local_irq_save(flags);
cpuc->saved_ctrl[idx] = mipsxx_pmu_read_control(idx) &
~M_PERFCTL_COUNT_EVENT_WHENEVER;
mipsxx_pmu_write_control(idx, cpuc->saved_ctrl[idx]);
local_irq_restore(flags);
}
static const struct mips_perf_event *
mipsxx_pmu_map_raw_event(u64 config)
{
unsigned int raw_id = config & 0xff;
unsigned int base_id = raw_id & 0x7f;
switch (current_cpu_type()) {
case CPU_24K:
if (IS_UNSUPPORTED_24K_EVENT(raw_id, base_id))
return ERR_PTR(-EOPNOTSUPP);
raw_event.event_id = base_id;
if (IS_BOTH_COUNTERS_24K_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
raw_event.range = P;
#endif
break;
case CPU_34K:
if (IS_UNSUPPORTED_34K_EVENT(raw_id, base_id))
return ERR_PTR(-EOPNOTSUPP);
raw_event.event_id = base_id;
if (IS_BOTH_COUNTERS_34K_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
if (IS_RANGE_P_34K_EVENT(raw_id, base_id))
raw_event.range = P;
else if (unlikely(IS_RANGE_V_34K_EVENT(raw_id)))
raw_event.range = V;
else
raw_event.range = T;
#endif
break;
case CPU_74K:
if (IS_UNSUPPORTED_74K_EVENT(raw_id, base_id))
return ERR_PTR(-EOPNOTSUPP);
raw_event.event_id = base_id;
if (IS_BOTH_COUNTERS_74K_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
raw_event.range = P;
#endif
break;
case CPU_1004K:
if (IS_UNSUPPORTED_1004K_EVENT(raw_id, base_id))
return ERR_PTR(-EOPNOTSUPP);
raw_event.event_id = base_id;
if (IS_BOTH_COUNTERS_1004K_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
if (IS_RANGE_P_1004K_EVENT(raw_id, base_id))
raw_event.range = P;
else if (unlikely(IS_RANGE_V_1004K_EVENT(raw_id)))
raw_event.range = V;
else
raw_event.range = T;
#endif
break;
}
return &raw_event;
}
static int __init
init_hw_perf_events(void)
{
int counters, irq;
pr_info("Performance counters: ");
counters = n_counters();
if (counters == 0) {
pr_cont("No available PMU.\n");
return -ENODEV;
}
#ifdef CONFIG_MIPS_MT_SMP
cpu_has_mipsmt_pertccounters = read_c0_config7() & (1<<19);
if (!cpu_has_mipsmt_pertccounters)
counters = counters_total_to_per_cpu(counters);
#endif
#ifdef MSC01E_INT_BASE
if (cpu_has_veic) {
irq = MSC01E_INT_BASE + MSC01E_INT_PERFCTR;
} else {
#endif
if (cp0_perfcount_irq >= 0)
irq = MIPS_CPU_IRQ_BASE + cp0_perfcount_irq;
else
irq = -1;
#ifdef MSC01E_INT_BASE
}
#endif
on_each_cpu(reset_counters, (void *)(long)counters, 1);
switch (current_cpu_type()) {
case CPU_24K:
mipsxxcore_pmu.name = "mips/24K";
mipsxxcore_pmu.num_counters = counters;
mipsxxcore_pmu.irq = irq;
mipspmu = &mipsxxcore_pmu;
break;
case CPU_34K:
mipsxxcore_pmu.name = "mips/34K";
mipsxxcore_pmu.num_counters = counters;
mipsxxcore_pmu.irq = irq;
mipspmu = &mipsxxcore_pmu;
break;
case CPU_74K:
mipsxx74Kcore_pmu.name = "mips/74K";
mipsxx74Kcore_pmu.num_counters = counters;
mipsxx74Kcore_pmu.irq = irq;
mipspmu = &mipsxx74Kcore_pmu;
break;
case CPU_1004K:
mipsxxcore_pmu.name = "mips/1004K";
mipsxxcore_pmu.num_counters = counters;
mipsxxcore_pmu.irq = irq;
mipspmu = &mipsxxcore_pmu;
break;
default:
pr_cont("Either hardware does not support performance "
"counters, or not yet implemented.\n");
return -ENODEV;
}
if (mipspmu)
pr_cont("%s PMU enabled, %d counters available to each "
"CPU, irq %d%s\n", mipspmu->name, counters, irq,
irq < 0 ? " (share with timer interrupt)" : "");
perf_pmu_register(&pmu, "cpu", PERF_TYPE_RAW);
return 0;
}
