static unsigned int vpe_shift(void)
{
if (num_possible_cpus() > 1)
return 1;
return 0;
}
static unsigned int counters_total_to_per_cpu(unsigned int counters)
{
return counters >> vpe_shift();
}
static unsigned int mipsxx_pmu_swizzle_perf_idx(unsigned int idx)
{
if (vpe_id() == 1)
idx = (idx + 2) & 3;
return idx;
}
static u64 mipsxx_pmu_read_counter(unsigned int idx)
{
idx = mipsxx_pmu_swizzle_perf_idx(idx);
switch (idx) {
case 0:
return (u32)read_c0_perfcntr0();
case 1:
return (u32)read_c0_perfcntr1();
case 2:
return (u32)read_c0_perfcntr2();
case 3:
return (u32)read_c0_perfcntr3();
default:
WARN_ONCE(1, "Invalid performance counter number (%d)\n", idx);
return 0;
}
}
static u64 mipsxx_pmu_read_counter_64(unsigned int idx)
{
idx = mipsxx_pmu_swizzle_perf_idx(idx);
switch (idx) {
case 0:
return read_c0_perfcntr0_64();
case 1:
return read_c0_perfcntr1_64();
case 2:
return read_c0_perfcntr2_64();
case 3:
return read_c0_perfcntr3_64();
default:
WARN_ONCE(1, "Invalid performance counter number (%d)\n", idx);
return 0;
}
}
static void mipsxx_pmu_write_counter(unsigned int idx, u64 val)
{
idx = mipsxx_pmu_swizzle_perf_idx(idx);
switch (idx) {
case 0:
write_c0_perfcntr0(val);
return;
case 1:
write_c0_perfcntr1(val);
return;
case 2:
write_c0_perfcntr2(val);
return;
case 3:
write_c0_perfcntr3(val);
return;
}
}
static void mipsxx_pmu_write_counter_64(unsigned int idx, u64 val)
{
idx = mipsxx_pmu_swizzle_perf_idx(idx);
switch (idx) {
case 0:
write_c0_perfcntr0_64(val);
return;
case 1:
write_c0_perfcntr1_64(val);
return;
case 2:
write_c0_perfcntr2_64(val);
return;
case 3:
write_c0_perfcntr3_64(val);
return;
}
}
static unsigned int mipsxx_pmu_read_control(unsigned int idx)
{
idx = mipsxx_pmu_swizzle_perf_idx(idx);
switch (idx) {
case 0:
return read_c0_perfctrl0();
case 1:
return read_c0_perfctrl1();
case 2:
return read_c0_perfctrl2();
case 3:
return read_c0_perfctrl3();
default:
WARN_ONCE(1, "Invalid performance counter number (%d)\n", idx);
return 0;
}
}
static void mipsxx_pmu_write_control(unsigned int idx, unsigned int val)
{
idx = mipsxx_pmu_swizzle_perf_idx(idx);
switch (idx) {
case 0:
write_c0_perfctrl0(val);
return;
case 1:
write_c0_perfctrl1(val);
return;
case 2:
write_c0_perfctrl2(val);
return;
case 3:
write_c0_perfctrl3(val);
return;
}
}
static int mipsxx_pmu_alloc_counter(struct cpu_hw_events *cpuc,
struct hw_perf_event *hwc)
{
int i;
unsigned long cntr_mask = (hwc->event_base >> 8) & 0xffff;
for (i = mipspmu.num_counters - 1; i >= 0; i--) {
if (test_bit(i, &cntr_mask) &&
!test_and_set_bit(i, cpuc->used_mask))
return i;
}
return -EAGAIN;
}
static void mipsxx_pmu_enable_event(struct hw_perf_event *evt, int idx)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
WARN_ON(idx < 0 || idx >= mipspmu.num_counters);
cpuc->saved_ctrl[idx] = M_PERFCTL_EVENT(evt->event_base & 0xff) |
(evt->config_base & M_PERFCTL_CONFIG_MASK) |
M_PERFCTL_INTERRUPT_ENABLE;
if (IS_ENABLED(CONFIG_CPU_BMIPS5000))
cpuc->saved_ctrl[idx] |=
(1 << (12 + vpe_id())) | M_PERFCTL_TC;
}
static void mipsxx_pmu_disable_event(int idx)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
unsigned long flags;
WARN_ON(idx < 0 || idx >= mipspmu.num_counters);
local_irq_save(flags);
cpuc->saved_ctrl[idx] = mipsxx_pmu_read_control(idx) &
~M_PERFCTL_COUNT_EVENT_WHENEVER;
mipsxx_pmu_write_control(idx, cpuc->saved_ctrl[idx]);
local_irq_restore(flags);
}
static int mipspmu_event_set_period(struct perf_event *event,
struct hw_perf_event *hwc,
int idx)
{
u64 left = local64_read(&hwc->period_left);
u64 period = hwc->sample_period;
int ret = 0;
if (unlikely((left + period) & (1ULL << 63))) {
left = period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
ret = 1;
} else if (unlikely((left + period) <= period)) {
left += period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
ret = 1;
}
if (left > mipspmu.max_period) {
left = mipspmu.max_period;
local64_set(&hwc->period_left, left);
}
local64_set(&hwc->prev_count, mipspmu.overflow - left);
mipspmu.write_counter(idx, mipspmu.overflow - left);
perf_event_update_userpage(event);
return ret;
}
static void mipspmu_event_update(struct perf_event *event,
struct hw_perf_event *hwc,
int idx)
{
u64 prev_raw_count, new_raw_count;
u64 delta;
again:
prev_raw_count = local64_read(&hwc->prev_count);
new_raw_count = mipspmu.read_counter(idx);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count)
goto again;
delta = new_raw_count - prev_raw_count;
local64_add(delta, &event->count);
local64_sub(delta, &hwc->period_left);
}
static void mipspmu_start(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
if (flags & PERF_EF_RELOAD)
WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));
hwc->state = 0;
mipspmu_event_set_period(event, hwc, hwc->idx);
mipsxx_pmu_enable_event(hwc, hwc->idx);
}
static void mipspmu_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
if (!(hwc->state & PERF_HES_STOPPED)) {
mipsxx_pmu_disable_event(hwc->idx);
barrier();
mipspmu_event_update(event, hwc, hwc->idx);
hwc->state |= PERF_HES_STOPPED | PERF_HES_UPTODATE;
}
}
static int mipspmu_add(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
int idx;
int err = 0;
perf_pmu_disable(event->pmu);
idx = mipsxx_pmu_alloc_counter(cpuc, hwc);
if (idx < 0) {
err = idx;
goto out;
}
event->hw.idx = idx;
mipsxx_pmu_disable_event(idx);
cpuc->events[idx] = event;
hwc->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
if (flags & PERF_EF_START)
mipspmu_start(event, PERF_EF_RELOAD);
perf_event_update_userpage(event);
out:
perf_pmu_enable(event->pmu);
return err;
}
static void mipspmu_del(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
WARN_ON(idx < 0 || idx >= mipspmu.num_counters);
mipspmu_stop(event, PERF_EF_UPDATE);
cpuc->events[idx] = NULL;
clear_bit(idx, cpuc->used_mask);
perf_event_update_userpage(event);
}
static void mipspmu_read(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (hwc->idx < 0)
return;
mipspmu_event_update(event, hwc, hwc->idx);
}
static void mipspmu_enable(struct pmu *pmu)
{
#ifdef CONFIG_MIPS_PERF_SHARED_TC_COUNTERS
write_unlock(&pmuint_rwlock);
#endif
resume_local_counters();
}
static void mipspmu_disable(struct pmu *pmu)
{
pause_local_counters();
#ifdef CONFIG_MIPS_PERF_SHARED_TC_COUNTERS
write_lock(&pmuint_rwlock);
#endif
}
static int mipspmu_get_irq(void)
{
int err;
if (mipspmu.irq >= 0) {
err = request_irq(mipspmu.irq, mipsxx_pmu_handle_irq,
IRQF_PERCPU | IRQF_NOBALANCING | IRQF_NO_THREAD,
"mips_perf_pmu", NULL);
if (err) {
pr_warn("Unable to request IRQ%d for MIPS performance counters!\n",
mipspmu.irq);
}
} else if (cp0_perfcount_irq < 0) {
save_perf_irq = perf_irq;
perf_irq = mipsxx_pmu_handle_shared_irq;
err = 0;
} else {
pr_warn("The platform hasn't properly defined its interrupt controller\n");
err = -ENOENT;
}
return err;
}
static void mipspmu_free_irq(void)
{
if (mipspmu.irq >= 0)
free_irq(mipspmu.irq, NULL);
else if (cp0_perfcount_irq < 0)
perf_irq = save_perf_irq;
}
static void hw_perf_event_destroy(struct perf_event *event)
{
if (atomic_dec_and_mutex_lock(&active_events,
&pmu_reserve_mutex)) {
on_each_cpu(reset_counters,
(void *)(long)mipspmu.num_counters, 1);
mipspmu_free_irq();
mutex_unlock(&pmu_reserve_mutex);
}
}
static int mipspmu_event_init(struct perf_event *event)
{
int err = 0;
if (has_branch_stack(event))
return -EOPNOTSUPP;
switch (event->attr.type) {
case PERF_TYPE_RAW:
case PERF_TYPE_HARDWARE:
case PERF_TYPE_HW_CACHE:
break;
default:
return -ENOENT;
}
if (event->cpu >= nr_cpumask_bits ||
(event->cpu >= 0 && !cpu_online(event->cpu)))
return -ENODEV;
if (!atomic_inc_not_zero(&active_events)) {
mutex_lock(&pmu_reserve_mutex);
if (atomic_read(&active_events) == 0)
err = mipspmu_get_irq();
if (!err)
atomic_inc(&active_events);
mutex_unlock(&pmu_reserve_mutex);
}
if (err)
return err;
return __hw_perf_event_init(event);
}
static unsigned int mipspmu_perf_event_encode(const struct mips_perf_event *pev)
{
#ifdef CONFIG_MIPS_MT_SMP
return ((unsigned int)pev->range << 24) |
(pev->cntr_mask & 0xffff00) |
(pev->event_id & 0xff);
#else
return (pev->cntr_mask & 0xffff00) |
(pev->event_id & 0xff);
#endif
}
static const struct mips_perf_event *mipspmu_map_general_event(int idx)
{
if ((*mipspmu.general_event_map)[idx].cntr_mask == 0)
return ERR_PTR(-EOPNOTSUPP);
return &(*mipspmu.general_event_map)[idx];
}
static const struct mips_perf_event *mipspmu_map_cache_event(u64 config)
{
unsigned int cache_type, cache_op, cache_result;
const struct mips_perf_event *pev;
cache_type = (config >> 0) & 0xff;
if (cache_type >= PERF_COUNT_HW_CACHE_MAX)
return ERR_PTR(-EINVAL);
cache_op = (config >> 8) & 0xff;
if (cache_op >= PERF_COUNT_HW_CACHE_OP_MAX)
return ERR_PTR(-EINVAL);
cache_result = (config >> 16) & 0xff;
if (cache_result >= PERF_COUNT_HW_CACHE_RESULT_MAX)
return ERR_PTR(-EINVAL);
pev = &((*mipspmu.cache_event_map)
[cache_type]
[cache_op]
[cache_result]);
if (pev->cntr_mask == 0)
return ERR_PTR(-EOPNOTSUPP);
return pev;
}
static int validate_group(struct perf_event *event)
{
struct perf_event *sibling, *leader = event->group_leader;
struct cpu_hw_events fake_cpuc;
memset(&fake_cpuc, 0, sizeof(fake_cpuc));
if (mipsxx_pmu_alloc_counter(&fake_cpuc, &leader->hw) < 0)
return -EINVAL;
list_for_each_entry(sibling, &leader->sibling_list, group_entry) {
if (mipsxx_pmu_alloc_counter(&fake_cpuc, &sibling->hw) < 0)
return -EINVAL;
}
if (mipsxx_pmu_alloc_counter(&fake_cpuc, &event->hw) < 0)
return -EINVAL;
return 0;
}
static void handle_associated_event(struct cpu_hw_events *cpuc,
int idx, struct perf_sample_data *data,
struct pt_regs *regs)
{
struct perf_event *event = cpuc->events[idx];
struct hw_perf_event *hwc = &event->hw;
mipspmu_event_update(event, hwc, idx);
data->period = event->hw.last_period;
if (!mipspmu_event_set_period(event, hwc, idx))
return;
if (perf_event_overflow(event, data, regs))
mipsxx_pmu_disable_event(idx);
}
static int __n_counters(void)
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
static int n_counters(void)
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
mipsxx_pmu_write_control(3, 0);
mipspmu.write_counter(3, 0);
case 3:
mipsxx_pmu_write_control(2, 0);
mipspmu.write_counter(2, 0);
case 2:
mipsxx_pmu_write_control(1, 0);
mipspmu.write_counter(1, 0);
case 1:
mipsxx_pmu_write_control(0, 0);
mipspmu.write_counter(0, 0);
}
}
static void check_and_calc_range(struct perf_event *event,
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
static void check_and_calc_range(struct perf_event *event,
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
pev = mipspmu.map_raw_event(event->attr.config);
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
hwc->sample_period = mipspmu.max_period;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
}
err = 0;
if (event->group_leader != event)
err = validate_group(event);
event->destroy = hw_perf_event_destroy;
if (err)
event->destroy(event);
return err;
}
static void pause_local_counters(void)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int ctr = mipspmu.num_counters;
unsigned long flags;
local_irq_save(flags);
do {
ctr--;
cpuc->saved_ctrl[ctr] = mipsxx_pmu_read_control(ctr);
mipsxx_pmu_write_control(ctr, cpuc->saved_ctrl[ctr] &
~M_PERFCTL_COUNT_EVENT_WHENEVER);
} while (ctr > 0);
local_irq_restore(flags);
}
static void resume_local_counters(void)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int ctr = mipspmu.num_counters;
do {
ctr--;
mipsxx_pmu_write_control(ctr, cpuc->saved_ctrl[ctr]);
} while (ctr > 0);
}
static int mipsxx_pmu_handle_shared_irq(void)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct perf_sample_data data;
unsigned int counters = mipspmu.num_counters;
u64 counter;
int handled = IRQ_NONE;
struct pt_regs *regs;
if (cpu_has_perf_cntr_intr_bit && !(read_c0_cause() & CAUSEF_PCI))
return handled;
pause_local_counters();
#ifdef CONFIG_MIPS_PERF_SHARED_TC_COUNTERS
read_lock(&pmuint_rwlock);
#endif
regs = get_irq_regs();
perf_sample_data_init(&data, 0, 0);
switch (counters) {
#define HANDLE_COUNTER(n) \
case n + 1: \
if (test_bit(n, cpuc->used_mask)) { \
counter = mipspmu.read_counter(n); \
if (counter & mipspmu.overflow) { \
handle_associated_event(cpuc, n, &data, regs); \
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
#ifdef CONFIG_MIPS_PERF_SHARED_TC_COUNTERS
read_unlock(&pmuint_rwlock);
#endif
resume_local_counters();
return handled;
}
static irqreturn_t mipsxx_pmu_handle_irq(int irq, void *dev)
{
return mipsxx_pmu_handle_shared_irq();
}
static const struct mips_perf_event *mipsxx_pmu_map_raw_event(u64 config)
{
unsigned int raw_id = config & 0xff;
unsigned int base_id = raw_id & 0x7f;
switch (current_cpu_type()) {
case CPU_24K:
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
case CPU_1074K:
if (IS_BOTH_COUNTERS_74K_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
raw_event.range = P;
#endif
break;
case CPU_PROAPTIV:
if (IS_BOTH_COUNTERS_PROAPTIV_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
raw_event.range = P;
#endif
break;
case CPU_P5600:
raw_id = config & 0x1ff;
base_id = raw_id & 0xff;
if (IS_BOTH_COUNTERS_P5600_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 255 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
raw_event.range = P;
#endif
break;
case CPU_1004K:
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
case CPU_INTERAPTIV:
if (IS_BOTH_COUNTERS_INTERAPTIV_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
#ifdef CONFIG_MIPS_MT_SMP
if (IS_RANGE_P_INTERAPTIV_EVENT(raw_id, base_id))
raw_event.range = P;
else if (unlikely(IS_RANGE_V_INTERAPTIV_EVENT(raw_id)))
raw_event.range = V;
else
raw_event.range = T;
#endif
break;
case CPU_BMIPS5000:
if (IS_BOTH_COUNTERS_BMIPS5000_EVENT(base_id))
raw_event.cntr_mask = CNTR_EVEN | CNTR_ODD;
else
raw_event.cntr_mask =
raw_id > 127 ? CNTR_ODD : CNTR_EVEN;
}
raw_event.event_id = base_id;
return &raw_event;
}
static const struct mips_perf_event *octeon_pmu_map_raw_event(u64 config)
{
unsigned int raw_id = config & 0xff;
unsigned int base_id = raw_id & 0x7f;
raw_event.cntr_mask = CNTR_ALL;
raw_event.event_id = base_id;
if (current_cpu_type() == CPU_CAVIUM_OCTEON2) {
if (base_id > 0x42)
return ERR_PTR(-EOPNOTSUPP);
} else {
if (base_id > 0x3a)
return ERR_PTR(-EOPNOTSUPP);
}
switch (base_id) {
case 0x00:
case 0x0f:
case 0x1e:
case 0x1f:
case 0x2f:
case 0x34:
case 0x3b ... 0x3f:
return ERR_PTR(-EOPNOTSUPP);
default:
break;
}
return &raw_event;
}
static const struct mips_perf_event *xlp_pmu_map_raw_event(u64 config)
{
unsigned int raw_id = config & 0xff;
if ((raw_id < 0x01) || (raw_id > 0x3f))
return ERR_PTR(-EOPNOTSUPP);
raw_event.cntr_mask = CNTR_ALL;
raw_event.event_id = raw_id;
return &raw_event;
}
static int __init
init_hw_perf_events(void)
{
int counters, irq;
int counter_bits;
pr_info("Performance counters: ");
counters = n_counters();
if (counters == 0) {
pr_cont("No available PMU.\n");
return -ENODEV;
}
#ifdef CONFIG_MIPS_PERF_SHARED_TC_COUNTERS
cpu_has_mipsmt_pertccounters = read_c0_config7() & (1<<19);
if (!cpu_has_mipsmt_pertccounters)
counters = counters_total_to_per_cpu(counters);
#endif
if (get_c0_perfcount_int)
irq = get_c0_perfcount_int();
else if ((cp0_perfcount_irq >= 0) &&
(cp0_compare_irq != cp0_perfcount_irq))
irq = MIPS_CPU_IRQ_BASE + cp0_perfcount_irq;
else
irq = -1;
mipspmu.map_raw_event = mipsxx_pmu_map_raw_event;
switch (current_cpu_type()) {
case CPU_24K:
mipspmu.name = "mips/24K";
mipspmu.general_event_map = &mipsxxcore_event_map;
mipspmu.cache_event_map = &mipsxxcore_cache_map;
break;
case CPU_34K:
mipspmu.name = "mips/34K";
mipspmu.general_event_map = &mipsxxcore_event_map;
mipspmu.cache_event_map = &mipsxxcore_cache_map;
break;
case CPU_74K:
mipspmu.name = "mips/74K";
mipspmu.general_event_map = &mipsxxcore_event_map2;
mipspmu.cache_event_map = &mipsxxcore_cache_map2;
break;
case CPU_PROAPTIV:
mipspmu.name = "mips/proAptiv";
mipspmu.general_event_map = &mipsxxcore_event_map2;
mipspmu.cache_event_map = &mipsxxcore_cache_map2;
break;
case CPU_P5600:
mipspmu.name = "mips/P5600";
mipspmu.general_event_map = &mipsxxcore_event_map2;
mipspmu.cache_event_map = &mipsxxcore_cache_map2;
break;
case CPU_1004K:
mipspmu.name = "mips/1004K";
mipspmu.general_event_map = &mipsxxcore_event_map;
mipspmu.cache_event_map = &mipsxxcore_cache_map;
break;
case CPU_1074K:
mipspmu.name = "mips/1074K";
mipspmu.general_event_map = &mipsxxcore_event_map;
mipspmu.cache_event_map = &mipsxxcore_cache_map;
break;
case CPU_INTERAPTIV:
mipspmu.name = "mips/interAptiv";
mipspmu.general_event_map = &mipsxxcore_event_map;
mipspmu.cache_event_map = &mipsxxcore_cache_map;
break;
case CPU_LOONGSON1:
mipspmu.name = "mips/loongson1";
mipspmu.general_event_map = &mipsxxcore_event_map;
mipspmu.cache_event_map = &mipsxxcore_cache_map;
break;
case CPU_CAVIUM_OCTEON:
case CPU_CAVIUM_OCTEON_PLUS:
case CPU_CAVIUM_OCTEON2:
mipspmu.name = "octeon";
mipspmu.general_event_map = &octeon_event_map;
mipspmu.cache_event_map = &octeon_cache_map;
mipspmu.map_raw_event = octeon_pmu_map_raw_event;
break;
case CPU_BMIPS5000:
mipspmu.name = "BMIPS5000";
mipspmu.general_event_map = &bmips5000_event_map;
mipspmu.cache_event_map = &bmips5000_cache_map;
break;
case CPU_XLP:
mipspmu.name = "xlp";
mipspmu.general_event_map = &xlp_event_map;
mipspmu.cache_event_map = &xlp_cache_map;
mipspmu.map_raw_event = xlp_pmu_map_raw_event;
break;
default:
pr_cont("Either hardware does not support performance "
"counters, or not yet implemented.\n");
return -ENODEV;
}
mipspmu.num_counters = counters;
mipspmu.irq = irq;
if (read_c0_perfctrl0() & M_PERFCTL_WIDE) {
mipspmu.max_period = (1ULL << 63) - 1;
mipspmu.valid_count = (1ULL << 63) - 1;
mipspmu.overflow = 1ULL << 63;
mipspmu.read_counter = mipsxx_pmu_read_counter_64;
mipspmu.write_counter = mipsxx_pmu_write_counter_64;
counter_bits = 64;
} else {
mipspmu.max_period = (1ULL << 31) - 1;
mipspmu.valid_count = (1ULL << 31) - 1;
mipspmu.overflow = 1ULL << 31;
mipspmu.read_counter = mipsxx_pmu_read_counter;
mipspmu.write_counter = mipsxx_pmu_write_counter;
counter_bits = 32;
}
on_each_cpu(reset_counters, (void *)(long)counters, 1);
pr_cont("%s PMU enabled, %d %d-bit counters available to each "
"CPU, irq %d%s\n", mipspmu.name, counters, counter_bits, irq,
irq < 0 ? " (share with timer interrupt)" : "");
perf_pmu_register(&pmu, "cpu", PERF_TYPE_RAW);
return 0;
}
