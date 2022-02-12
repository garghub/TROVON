const char *perf_pmu_name(void)
{
if (!metag_pmu)
return NULL;
return metag_pmu->name;
}
int perf_num_counters(void)
{
if (metag_pmu)
return metag_pmu->max_events;
return 0;
}
static inline int metag_pmu_initialised(void)
{
return !!metag_pmu;
}
static void release_pmu_hardware(void)
{
int irq;
unsigned int version = (metag_pmu->version &
(METAC_ID_MINOR_BITS | METAC_ID_REV_BITS)) >>
METAC_ID_REV_S;
if (version < 0x0104)
return;
irq = internal_irq_map(17);
if (irq >= 0)
free_irq(irq, (void *)1);
irq = internal_irq_map(16);
if (irq >= 0)
free_irq(irq, (void *)0);
}
static int reserve_pmu_hardware(void)
{
int err = 0, irq[2];
unsigned int version = (metag_pmu->version &
(METAC_ID_MINOR_BITS | METAC_ID_REV_BITS)) >>
METAC_ID_REV_S;
if (version < 0x0104)
goto out;
irq[0] = internal_irq_map(16);
if (irq[0] < 0) {
pr_err("unable to map internal IRQ %d\n", 16);
goto out;
}
err = request_irq(irq[0], metag_pmu->handle_irq, IRQF_NOBALANCING,
"metagpmu0", (void *)0);
if (err) {
pr_err("unable to request IRQ%d for metag PMU counters\n",
irq[0]);
goto out;
}
irq[1] = internal_irq_map(17);
if (irq[1] < 0) {
pr_err("unable to map internal IRQ %d\n", 17);
goto out_irq1;
}
err = request_irq(irq[1], metag_pmu->handle_irq, IRQF_NOBALANCING,
"metagpmu1", (void *)1);
if (err) {
pr_err("unable to request IRQ%d for metag PMU counters\n",
irq[1]);
goto out_irq1;
}
return 0;
out_irq1:
free_irq(irq[0], (void *)0);
out:
return err;
}
static void metag_pmu_enable(struct pmu *pmu)
{
}
static void metag_pmu_disable(struct pmu *pmu)
{
}
static int metag_pmu_event_init(struct perf_event *event)
{
int err = 0;
atomic_t *active_events = &metag_pmu->active_events;
if (!metag_pmu_initialised()) {
err = -ENODEV;
goto out;
}
if (has_branch_stack(event))
return -EOPNOTSUPP;
event->destroy = _hw_perf_event_destroy;
if (!atomic_inc_not_zero(active_events)) {
mutex_lock(&metag_pmu->reserve_mutex);
if (atomic_read(active_events) == 0)
err = reserve_pmu_hardware();
if (!err)
atomic_inc(active_events);
mutex_unlock(&metag_pmu->reserve_mutex);
}
switch (event->attr.type) {
case PERF_TYPE_HARDWARE:
case PERF_TYPE_HW_CACHE:
case PERF_TYPE_RAW:
err = _hw_perf_event_init(event);
break;
default:
return -ENOENT;
}
if (err)
event->destroy(event);
out:
return err;
}
void metag_pmu_event_update(struct perf_event *event,
struct hw_perf_event *hwc, int idx)
{
u64 prev_raw_count, new_raw_count;
s64 delta;
again:
prev_raw_count = local64_read(&hwc->prev_count);
new_raw_count = metag_pmu->read(idx);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count)
goto again;
delta = (new_raw_count - prev_raw_count) & MAX_PERIOD;
local64_add(delta, &event->count);
local64_sub(delta, &hwc->period_left);
}
int metag_pmu_event_set_period(struct perf_event *event,
struct hw_perf_event *hwc, int idx)
{
s64 left = local64_read(&hwc->period_left);
s64 period = hwc->sample_period;
int ret = 0;
if (unlikely(period != hwc->last_period))
left += period - hwc->last_period;
if (unlikely(left <= -period)) {
left = period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
ret = 1;
}
if (unlikely(left <= 0)) {
left += period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
ret = 1;
}
if (left > (s64)metag_pmu->max_period)
left = metag_pmu->max_period;
if (metag_pmu->write) {
local64_set(&hwc->prev_count, -(s32)left);
metag_pmu->write(idx, -left & MAX_PERIOD);
}
perf_event_update_userpage(event);
return ret;
}
static void metag_pmu_start(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
if (WARN_ON_ONCE(idx == -1))
return;
if (flags & PERF_EF_RELOAD)
WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));
hwc->state = 0;
if (metag_pmu->max_period)
metag_pmu_event_set_period(event, hwc, hwc->idx);
cpuc->events[idx] = event;
metag_pmu->enable(hwc, idx);
}
static void metag_pmu_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
if (!(hwc->state & PERF_HES_STOPPED)) {
metag_pmu_event_update(event, hwc, hwc->idx);
metag_pmu->disable(hwc, hwc->idx);
hwc->state |= PERF_HES_STOPPED | PERF_HES_UPTODATE;
}
}
static int metag_pmu_add(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
int idx = 0, ret = 0;
perf_pmu_disable(event->pmu);
if (hwc->config == 0x100) {
if (__test_and_set_bit(METAG_INST_COUNTER,
cpuc->used_mask)) {
ret = -EAGAIN;
goto out;
}
idx = METAG_INST_COUNTER;
} else {
idx = find_first_zero_bit(cpuc->used_mask,
atomic_read(&metag_pmu->active_events));
if (idx >= METAG_INST_COUNTER) {
ret = -EAGAIN;
goto out;
}
__set_bit(idx, cpuc->used_mask);
}
hwc->idx = idx;
metag_pmu->disable(hwc, idx);
hwc->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
if (flags & PERF_EF_START)
metag_pmu_start(event, PERF_EF_RELOAD);
perf_event_update_userpage(event);
out:
perf_pmu_enable(event->pmu);
return ret;
}
static void metag_pmu_del(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
WARN_ON(idx < 0);
metag_pmu_stop(event, PERF_EF_UPDATE);
cpuc->events[idx] = NULL;
__clear_bit(idx, cpuc->used_mask);
perf_event_update_userpage(event);
}
static void metag_pmu_read(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (hwc->idx < 0)
return;
metag_pmu_event_update(event, hwc, hwc->idx);
}
static void _hw_perf_event_destroy(struct perf_event *event)
{
atomic_t *active_events = &metag_pmu->active_events;
struct mutex *pmu_mutex = &metag_pmu->reserve_mutex;
if (atomic_dec_and_mutex_lock(active_events, pmu_mutex)) {
release_pmu_hardware();
mutex_unlock(pmu_mutex);
}
}
static int _hw_perf_cache_event(int config, int *evp)
{
unsigned long type, op, result;
int ev;
if (!metag_pmu->cache_events)
return -EINVAL;
type = config & 0xff;
op = (config >> 8) & 0xff;
result = (config >> 16) & 0xff;
if (type >= PERF_COUNT_HW_CACHE_MAX ||
op >= PERF_COUNT_HW_CACHE_OP_MAX ||
result >= PERF_COUNT_HW_CACHE_RESULT_MAX)
return -EINVAL;
ev = (*metag_pmu->cache_events)[type][op][result];
if (ev == 0)
return -EOPNOTSUPP;
if (ev == -1)
return -EINVAL;
*evp = ev;
return 0;
}
static int _hw_perf_event_init(struct perf_event *event)
{
struct perf_event_attr *attr = &event->attr;
struct hw_perf_event *hwc = &event->hw;
int mapping = 0, err;
switch (attr->type) {
case PERF_TYPE_HARDWARE:
if (attr->config >= PERF_COUNT_HW_MAX)
return -EINVAL;
mapping = metag_pmu->event_map(attr->config);
break;
case PERF_TYPE_HW_CACHE:
err = _hw_perf_cache_event(attr->config, &mapping);
if (err)
return err;
break;
case PERF_TYPE_RAW:
mapping = attr->config;
break;
}
if (mapping == -1)
return -EINVAL;
hwc->idx = -1;
hwc->config |= (unsigned long)mapping;
if (metag_pmu->max_period) {
if (!hwc->sample_period) {
hwc->sample_period = metag_pmu->max_period >> 1;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
}
}
return 0;
}
static void metag_pmu_enable_counter(struct hw_perf_event *event, int idx)
{
struct cpu_hw_events *events = this_cpu_ptr(&cpu_hw_events);
unsigned int config = event->config;
unsigned int tmp = config & 0xf0;
unsigned long flags;
raw_spin_lock_irqsave(&events->pmu_lock, flags);
if (METAG_INST_COUNTER == idx) {
WARN_ONCE((config != 0x100),
"invalid configuration (%d) for counter (%d)\n",
config, idx);
local64_set(&event->prev_count, __core_reg_get(TXTACTCYC));
goto unlock;
}
if (tmp) {
#ifdef METAC_2_1
void *perf_addr;
switch (tmp) {
case 0xd0:
perf_addr = (void *)PERF_ICORE(idx);
break;
case 0xf0:
perf_addr = (void *)PERF_CHAN(idx);
break;
default:
perf_addr = NULL;
break;
}
if (perf_addr)
metag_out32((config & 0x0f), perf_addr);
#endif
config = tmp >> 4;
}
tmp = ((config & 0xf) << 28) |
((1 << 24) << hard_processor_id());
if (metag_pmu->max_period)
tmp |= metag_in32(PERF_COUNT(idx)) & 0x00ffffff;
else
local64_set(&event->prev_count, 0);
metag_out32(tmp, PERF_COUNT(idx));
unlock:
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void metag_pmu_disable_counter(struct hw_perf_event *event, int idx)
{
struct cpu_hw_events *events = this_cpu_ptr(&cpu_hw_events);
unsigned int tmp = 0;
unsigned long flags;
if (METAG_INST_COUNTER == idx)
return;
raw_spin_lock_irqsave(&events->pmu_lock, flags);
tmp = metag_in32(PERF_COUNT(idx));
tmp &= 0x00ffffff;
metag_out32(tmp, PERF_COUNT(idx));
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static u64 metag_pmu_read_counter(int idx)
{
u32 tmp = 0;
if (METAG_INST_COUNTER == idx) {
tmp = __core_reg_get(TXTACTCYC);
goto out;
}
tmp = metag_in32(PERF_COUNT(idx)) & 0x00ffffff;
out:
return tmp;
}
static void metag_pmu_write_counter(int idx, u32 val)
{
struct cpu_hw_events *events = this_cpu_ptr(&cpu_hw_events);
u32 tmp = 0;
unsigned long flags;
if (METAG_INST_COUNTER == idx)
return;
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val &= 0x00ffffff;
tmp = metag_in32(PERF_COUNT(idx)) & 0xff000000;
val |= tmp;
metag_out32(val, PERF_COUNT(idx));
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static int metag_pmu_event_map(int idx)
{
return metag_general_events[idx];
}
static irqreturn_t metag_pmu_counter_overflow(int irq, void *dev)
{
int idx = (int)dev;
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
struct perf_event *event = cpuhw->events[idx];
struct hw_perf_event *hwc = &event->hw;
struct pt_regs *regs = get_irq_regs();
struct perf_sample_data sampledata;
unsigned long flags;
u32 counter = 0;
__global_lock2(flags);
counter = metag_in32(PERF_COUNT(idx));
metag_out32((counter & 0x00ffffff), PERF_COUNT(idx));
__global_unlock2(flags);
metag_pmu_event_update(event, hwc, idx);
perf_sample_data_init(&sampledata, 0, hwc->last_period);
metag_pmu_event_set_period(event, hwc, idx);
if (!perf_event_overflow(event, &sampledata, regs)) {
__global_lock2(flags);
counter = (counter & 0xff000000) |
(metag_in32(PERF_COUNT(idx)) & 0x00ffffff);
metag_out32(counter, PERF_COUNT(idx));
__global_unlock2(flags);
}
return IRQ_HANDLED;
}
static int metag_pmu_starting_cpu(unsigned int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
memset(cpuc, 0, sizeof(struct cpu_hw_events));
raw_spin_lock_init(&cpuc->pmu_lock);
return 0;
}
static int __init init_hw_perf_events(void)
{
int ret = 0, cpu;
u32 version = *(u32 *)METAC_ID;
int major = (version & METAC_ID_MAJOR_BITS) >> METAC_ID_MAJOR_S;
int min_rev = (version & (METAC_ID_MINOR_BITS | METAC_ID_REV_BITS))
>> METAC_ID_REV_S;
if (0x02 > major) {
pr_info("no hardware counter support available\n");
goto out;
} else if (0x02 == major) {
metag_pmu = &_metag_pmu;
if (min_rev < 0x0104) {
metag_pmu->handle_irq = NULL;
metag_pmu->write = NULL;
metag_pmu->max_period = 0;
}
metag_pmu->name = "meta2";
metag_pmu->version = version;
metag_pmu->pmu = pmu;
}
pr_info("enabled with %s PMU driver, %d counters available\n",
metag_pmu->name, metag_pmu->max_events);
if (metag_pmu->max_period == 0) {
metag_pmu->pmu.capabilities |= PERF_PMU_CAP_NO_INTERRUPT;
}
atomic_set(&metag_pmu->active_events, 0);
mutex_init(&metag_pmu->reserve_mutex);
metag_out32(0, PERF_COUNT(0));
metag_out32(0, PERF_COUNT(1));
cpuhp_setup_state(CPUHP_AP_PERF_METAG_STARTING,
"perf/metag:starting", metag_pmu_starting_cpu,
NULL);
ret = perf_pmu_register(&pmu, metag_pmu->name, PERF_TYPE_RAW);
if (ret)
cpuhp_remove_state_nocalls(CPUHP_AP_PERF_METAG_STARTING);
return ret;
}
