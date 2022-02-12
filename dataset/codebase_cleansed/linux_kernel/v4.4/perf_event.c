static unsigned long perf_event_encode(const struct perf_event_map *pmap)
{
return ((unsigned long) pmap->encoding << 16) | pmap->pic_mask;
}
static u8 perf_event_get_msk(unsigned long val)
{
return val & 0xff;
}
static u64 perf_event_get_enc(unsigned long val)
{
return val >> 16;
}
static u32 sparc_default_read_pmc(int idx)
{
u64 val;
val = pcr_ops->read_pic(0);
if (idx == PIC_UPPER_INDEX)
val >>= 32;
return val & 0xffffffff;
}
static void sparc_default_write_pmc(int idx, u64 val)
{
u64 shift, mask, pic;
shift = 0;
if (idx == PIC_UPPER_INDEX)
shift = 32;
mask = ((u64) 0xffffffff) << shift;
val <<= shift;
pic = pcr_ops->read_pic(0);
pic &= ~mask;
pic |= val;
pcr_ops->write_pic(0, pic);
}
static const struct perf_event_map *ultra3_event_map(int event_id)
{
return &ultra3_perfmon_event_map[event_id];
}
static const struct perf_event_map *niagara1_event_map(int event_id)
{
return &niagara1_perfmon_event_map[event_id];
}
static const struct perf_event_map *niagara2_event_map(int event_id)
{
return &niagara2_perfmon_event_map[event_id];
}
static const struct perf_event_map *niagara4_event_map(int event_id)
{
return &niagara4_perfmon_event_map[event_id];
}
static u32 sparc_vt_read_pmc(int idx)
{
u64 val = pcr_ops->read_pic(idx);
return val & 0xffffffff;
}
static void sparc_vt_write_pmc(int idx, u64 val)
{
u64 pcr;
pcr = pcr_ops->read_pcr(idx);
pcr &= ~(PCR_N4_OV | PCR_N4_NTC);
pcr_ops->write_pic(idx, val & 0xffffffff);
pcr_ops->write_pcr(idx, pcr);
}
static u64 event_encoding(u64 event_id, int idx)
{
if (idx == PIC_UPPER_INDEX)
event_id <<= sparc_pmu->upper_shift;
else
event_id <<= sparc_pmu->lower_shift;
return event_id;
}
static u64 mask_for_index(int idx)
{
return event_encoding(sparc_pmu->event_mask, idx);
}
static u64 nop_for_index(int idx)
{
return event_encoding(idx == PIC_UPPER_INDEX ?
sparc_pmu->upper_nop :
sparc_pmu->lower_nop, idx);
}
static inline void sparc_pmu_enable_event(struct cpu_hw_events *cpuc, struct hw_perf_event *hwc, int idx)
{
u64 enc, val, mask = mask_for_index(idx);
int pcr_index = 0;
if (sparc_pmu->num_pcrs > 1)
pcr_index = idx;
enc = perf_event_get_enc(cpuc->events[idx]);
val = cpuc->pcr[pcr_index];
val &= ~mask;
val |= event_encoding(enc, idx);
cpuc->pcr[pcr_index] = val;
pcr_ops->write_pcr(pcr_index, cpuc->pcr[pcr_index]);
}
static inline void sparc_pmu_disable_event(struct cpu_hw_events *cpuc, struct hw_perf_event *hwc, int idx)
{
u64 mask = mask_for_index(idx);
u64 nop = nop_for_index(idx);
int pcr_index = 0;
u64 val;
if (sparc_pmu->num_pcrs > 1)
pcr_index = idx;
val = cpuc->pcr[pcr_index];
val &= ~mask;
val |= nop;
cpuc->pcr[pcr_index] = val;
pcr_ops->write_pcr(pcr_index, cpuc->pcr[pcr_index]);
}
static u64 sparc_perf_event_update(struct perf_event *event,
struct hw_perf_event *hwc, int idx)
{
int shift = 64 - 32;
u64 prev_raw_count, new_raw_count;
s64 delta;
again:
prev_raw_count = local64_read(&hwc->prev_count);
new_raw_count = sparc_pmu->read_pmc(idx);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count)
goto again;
delta = (new_raw_count << shift) - (prev_raw_count << shift);
delta >>= shift;
local64_add(delta, &event->count);
local64_sub(delta, &hwc->period_left);
return new_raw_count;
}
static int sparc_perf_event_set_period(struct perf_event *event,
struct hw_perf_event *hwc, int idx)
{
s64 left = local64_read(&hwc->period_left);
s64 period = hwc->sample_period;
int ret = 0;
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
if (left > MAX_PERIOD)
left = MAX_PERIOD;
local64_set(&hwc->prev_count, (u64)-left);
sparc_pmu->write_pmc(idx, (u64)(-left) & 0xffffffff);
perf_event_update_userpage(event);
return ret;
}
static void read_in_all_counters(struct cpu_hw_events *cpuc)
{
int i;
for (i = 0; i < cpuc->n_events; i++) {
struct perf_event *cp = cpuc->event[i];
if (cpuc->current_idx[i] != PIC_NO_INDEX &&
cpuc->current_idx[i] != cp->hw.idx) {
sparc_perf_event_update(cp, &cp->hw,
cpuc->current_idx[i]);
cpuc->current_idx[i] = PIC_NO_INDEX;
}
}
}
static void calculate_single_pcr(struct cpu_hw_events *cpuc)
{
int i;
if (!cpuc->n_added)
goto out;
for (i = 0; i < cpuc->n_events; i++) {
struct perf_event *cp = cpuc->event[i];
struct hw_perf_event *hwc = &cp->hw;
int idx = hwc->idx;
u64 enc;
if (cpuc->current_idx[i] != PIC_NO_INDEX)
continue;
sparc_perf_event_set_period(cp, hwc, idx);
cpuc->current_idx[i] = idx;
enc = perf_event_get_enc(cpuc->events[i]);
cpuc->pcr[0] &= ~mask_for_index(idx);
if (hwc->state & PERF_HES_STOPPED)
cpuc->pcr[0] |= nop_for_index(idx);
else
cpuc->pcr[0] |= event_encoding(enc, idx);
}
out:
cpuc->pcr[0] |= cpuc->event[0]->hw.config_base;
}
static void calculate_multiple_pcrs(struct cpu_hw_events *cpuc)
{
int i;
if (!cpuc->n_added)
goto out;
for (i = 0; i < cpuc->n_events; i++) {
struct perf_event *cp = cpuc->event[i];
struct hw_perf_event *hwc = &cp->hw;
int idx = hwc->idx;
if (cpuc->current_idx[i] != PIC_NO_INDEX)
continue;
cpuc->current_idx[i] = idx;
sparc_pmu_start(cp, PERF_EF_RELOAD);
}
out:
for (i = 0; i < cpuc->n_events; i++) {
struct perf_event *cp = cpuc->event[i];
int idx = cp->hw.idx;
cpuc->pcr[idx] |= cp->hw.config_base;
}
}
static void update_pcrs_for_enable(struct cpu_hw_events *cpuc)
{
if (cpuc->n_added)
read_in_all_counters(cpuc);
if (sparc_pmu->num_pcrs == 1) {
calculate_single_pcr(cpuc);
} else {
calculate_multiple_pcrs(cpuc);
}
}
static void sparc_pmu_enable(struct pmu *pmu)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int i;
if (cpuc->enabled)
return;
cpuc->enabled = 1;
barrier();
if (cpuc->n_events)
update_pcrs_for_enable(cpuc);
for (i = 0; i < sparc_pmu->num_pcrs; i++)
pcr_ops->write_pcr(i, cpuc->pcr[i]);
}
static void sparc_pmu_disable(struct pmu *pmu)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int i;
if (!cpuc->enabled)
return;
cpuc->enabled = 0;
cpuc->n_added = 0;
for (i = 0; i < sparc_pmu->num_pcrs; i++) {
u64 val = cpuc->pcr[i];
val &= ~(sparc_pmu->user_bit | sparc_pmu->priv_bit |
sparc_pmu->hv_bit | sparc_pmu->irq_bit);
cpuc->pcr[i] = val;
pcr_ops->write_pcr(i, cpuc->pcr[i]);
}
}
static int active_event_index(struct cpu_hw_events *cpuc,
struct perf_event *event)
{
int i;
for (i = 0; i < cpuc->n_events; i++) {
if (cpuc->event[i] == event)
break;
}
BUG_ON(i == cpuc->n_events);
return cpuc->current_idx[i];
}
static void sparc_pmu_start(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int idx = active_event_index(cpuc, event);
if (flags & PERF_EF_RELOAD) {
WARN_ON_ONCE(!(event->hw.state & PERF_HES_UPTODATE));
sparc_perf_event_set_period(event, &event->hw, idx);
}
event->hw.state = 0;
sparc_pmu_enable_event(cpuc, &event->hw, idx);
}
static void sparc_pmu_stop(struct perf_event *event, int flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int idx = active_event_index(cpuc, event);
if (!(event->hw.state & PERF_HES_STOPPED)) {
sparc_pmu_disable_event(cpuc, &event->hw, idx);
event->hw.state |= PERF_HES_STOPPED;
}
if (!(event->hw.state & PERF_HES_UPTODATE) && (flags & PERF_EF_UPDATE)) {
sparc_perf_event_update(event, &event->hw, idx);
event->hw.state |= PERF_HES_UPTODATE;
}
}
static void sparc_pmu_del(struct perf_event *event, int _flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
unsigned long flags;
int i;
local_irq_save(flags);
for (i = 0; i < cpuc->n_events; i++) {
if (event == cpuc->event[i]) {
sparc_pmu_stop(event, PERF_EF_UPDATE);
while (++i < cpuc->n_events) {
cpuc->event[i - 1] = cpuc->event[i];
cpuc->events[i - 1] = cpuc->events[i];
cpuc->current_idx[i - 1] =
cpuc->current_idx[i];
}
perf_event_update_userpage(event);
cpuc->n_events--;
break;
}
}
local_irq_restore(flags);
}
static void sparc_pmu_read(struct perf_event *event)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int idx = active_event_index(cpuc, event);
struct hw_perf_event *hwc = &event->hw;
sparc_perf_event_update(event, hwc, idx);
}
static void perf_stop_nmi_watchdog(void *unused)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int i;
stop_nmi_watchdog(NULL);
for (i = 0; i < sparc_pmu->num_pcrs; i++)
cpuc->pcr[i] = pcr_ops->read_pcr(i);
}
static void perf_event_grab_pmc(void)
{
if (atomic_inc_not_zero(&active_events))
return;
mutex_lock(&pmc_grab_mutex);
if (atomic_read(&active_events) == 0) {
if (atomic_read(&nmi_active) > 0) {
on_each_cpu(perf_stop_nmi_watchdog, NULL, 1);
BUG_ON(atomic_read(&nmi_active) != 0);
}
atomic_inc(&active_events);
}
mutex_unlock(&pmc_grab_mutex);
}
static void perf_event_release_pmc(void)
{
if (atomic_dec_and_mutex_lock(&active_events, &pmc_grab_mutex)) {
if (atomic_read(&nmi_active) == 0)
on_each_cpu(start_nmi_watchdog, NULL, 1);
mutex_unlock(&pmc_grab_mutex);
}
}
static const struct perf_event_map *sparc_map_cache_event(u64 config)
{
unsigned int cache_type, cache_op, cache_result;
const struct perf_event_map *pmap;
if (!sparc_pmu->cache_map)
return ERR_PTR(-ENOENT);
cache_type = (config >> 0) & 0xff;
if (cache_type >= PERF_COUNT_HW_CACHE_MAX)
return ERR_PTR(-EINVAL);
cache_op = (config >> 8) & 0xff;
if (cache_op >= PERF_COUNT_HW_CACHE_OP_MAX)
return ERR_PTR(-EINVAL);
cache_result = (config >> 16) & 0xff;
if (cache_result >= PERF_COUNT_HW_CACHE_RESULT_MAX)
return ERR_PTR(-EINVAL);
pmap = &((*sparc_pmu->cache_map)[cache_type][cache_op][cache_result]);
if (pmap->encoding == CACHE_OP_UNSUPPORTED)
return ERR_PTR(-ENOENT);
if (pmap->encoding == CACHE_OP_NONSENSE)
return ERR_PTR(-EINVAL);
return pmap;
}
static void hw_perf_event_destroy(struct perf_event *event)
{
perf_event_release_pmc();
}
static int sparc_check_constraints(struct perf_event **evts,
unsigned long *events, int n_ev)
{
u8 msk0 = 0, msk1 = 0;
int idx0 = 0;
if (!n_ev)
return 0;
if (n_ev > sparc_pmu->max_hw_events)
return -1;
if (!(sparc_pmu->flags & SPARC_PMU_HAS_CONFLICTS)) {
int i;
for (i = 0; i < n_ev; i++)
evts[i]->hw.idx = i;
return 0;
}
msk0 = perf_event_get_msk(events[0]);
if (n_ev == 1) {
if (msk0 & PIC_LOWER)
idx0 = 1;
goto success;
}
BUG_ON(n_ev != 2);
msk1 = perf_event_get_msk(events[1]);
if (msk0 == (PIC_UPPER | PIC_LOWER) &&
msk1 == (PIC_UPPER | PIC_LOWER))
goto success;
if ((msk0 == PIC_UPPER || msk0 == PIC_LOWER) &&
msk1 == (PIC_UPPER | PIC_LOWER)) {
if (msk0 & PIC_LOWER)
idx0 = 1;
goto success;
}
if ((msk1 == PIC_UPPER || msk1 == PIC_LOWER) &&
msk0 == (PIC_UPPER | PIC_LOWER)) {
if (msk1 & PIC_UPPER)
idx0 = 1;
goto success;
}
if ((msk0 == PIC_UPPER && msk1 == PIC_LOWER) ||
(msk0 == PIC_LOWER && msk1 == PIC_UPPER)) {
if (msk0 & PIC_LOWER)
idx0 = 1;
goto success;
}
return -1;
success:
evts[0]->hw.idx = idx0;
if (n_ev == 2)
evts[1]->hw.idx = idx0 ^ 1;
return 0;
}
static int check_excludes(struct perf_event **evts, int n_prev, int n_new)
{
int eu = 0, ek = 0, eh = 0;
struct perf_event *event;
int i, n, first;
if (!(sparc_pmu->flags & SPARC_PMU_ALL_EXCLUDES_SAME))
return 0;
n = n_prev + n_new;
if (n <= 1)
return 0;
first = 1;
for (i = 0; i < n; i++) {
event = evts[i];
if (first) {
eu = event->attr.exclude_user;
ek = event->attr.exclude_kernel;
eh = event->attr.exclude_hv;
first = 0;
} else if (event->attr.exclude_user != eu ||
event->attr.exclude_kernel != ek ||
event->attr.exclude_hv != eh) {
return -EAGAIN;
}
}
return 0;
}
static int collect_events(struct perf_event *group, int max_count,
struct perf_event *evts[], unsigned long *events,
int *current_idx)
{
struct perf_event *event;
int n = 0;
if (!is_software_event(group)) {
if (n >= max_count)
return -1;
evts[n] = group;
events[n] = group->hw.event_base;
current_idx[n++] = PIC_NO_INDEX;
}
list_for_each_entry(event, &group->sibling_list, group_entry) {
if (!is_software_event(event) &&
event->state != PERF_EVENT_STATE_OFF) {
if (n >= max_count)
return -1;
evts[n] = event;
events[n] = event->hw.event_base;
current_idx[n++] = PIC_NO_INDEX;
}
}
return n;
}
static int sparc_pmu_add(struct perf_event *event, int ef_flags)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int n0, ret = -EAGAIN;
unsigned long flags;
local_irq_save(flags);
n0 = cpuc->n_events;
if (n0 >= sparc_pmu->max_hw_events)
goto out;
cpuc->event[n0] = event;
cpuc->events[n0] = event->hw.event_base;
cpuc->current_idx[n0] = PIC_NO_INDEX;
event->hw.state = PERF_HES_UPTODATE;
if (!(ef_flags & PERF_EF_START))
event->hw.state |= PERF_HES_STOPPED;
if (cpuc->txn_flags & PERF_PMU_TXN_ADD)
goto nocheck;
if (check_excludes(cpuc->event, n0, 1))
goto out;
if (sparc_check_constraints(cpuc->event, cpuc->events, n0 + 1))
goto out;
nocheck:
cpuc->n_events++;
cpuc->n_added++;
ret = 0;
out:
local_irq_restore(flags);
return ret;
}
static int sparc_pmu_event_init(struct perf_event *event)
{
struct perf_event_attr *attr = &event->attr;
struct perf_event *evts[MAX_HWEVENTS];
struct hw_perf_event *hwc = &event->hw;
unsigned long events[MAX_HWEVENTS];
int current_idx_dmy[MAX_HWEVENTS];
const struct perf_event_map *pmap;
int n;
if (atomic_read(&nmi_active) < 0)
return -ENODEV;
if (has_branch_stack(event))
return -EOPNOTSUPP;
switch (attr->type) {
case PERF_TYPE_HARDWARE:
if (attr->config >= sparc_pmu->max_events)
return -EINVAL;
pmap = sparc_pmu->event_map(attr->config);
break;
case PERF_TYPE_HW_CACHE:
pmap = sparc_map_cache_event(attr->config);
if (IS_ERR(pmap))
return PTR_ERR(pmap);
break;
case PERF_TYPE_RAW:
pmap = NULL;
break;
default:
return -ENOENT;
}
if (pmap) {
hwc->event_base = perf_event_encode(pmap);
} else {
hwc->event_base = attr->config;
}
hwc->config_base = sparc_pmu->irq_bit;
if (!attr->exclude_user)
hwc->config_base |= sparc_pmu->user_bit;
if (!attr->exclude_kernel)
hwc->config_base |= sparc_pmu->priv_bit;
if (!attr->exclude_hv)
hwc->config_base |= sparc_pmu->hv_bit;
n = 0;
if (event->group_leader != event) {
n = collect_events(event->group_leader,
sparc_pmu->max_hw_events - 1,
evts, events, current_idx_dmy);
if (n < 0)
return -EINVAL;
}
events[n] = hwc->event_base;
evts[n] = event;
if (check_excludes(evts, n, 1))
return -EINVAL;
if (sparc_check_constraints(evts, events, n + 1))
return -EINVAL;
hwc->idx = PIC_NO_INDEX;
perf_event_grab_pmc();
event->destroy = hw_perf_event_destroy;
if (!hwc->sample_period) {
hwc->sample_period = MAX_PERIOD;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
}
return 0;
}
static void sparc_pmu_start_txn(struct pmu *pmu, unsigned int txn_flags)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
WARN_ON_ONCE(cpuhw->txn_flags);
cpuhw->txn_flags = txn_flags;
if (txn_flags & ~PERF_PMU_TXN_ADD)
return;
perf_pmu_disable(pmu);
}
static void sparc_pmu_cancel_txn(struct pmu *pmu)
{
struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
unsigned int txn_flags;
WARN_ON_ONCE(!cpuhw->txn_flags);
txn_flags = cpuhw->txn_flags;
cpuhw->txn_flags = 0;
if (txn_flags & ~PERF_PMU_TXN_ADD)
return;
perf_pmu_enable(pmu);
}
static int sparc_pmu_commit_txn(struct pmu *pmu)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int n;
if (!sparc_pmu)
return -EINVAL;
WARN_ON_ONCE(!cpuc->txn_flags);
if (cpuc->txn_flags & ~PERF_PMU_TXN_ADD) {
cpuc->txn_flags = 0;
return 0;
}
n = cpuc->n_events;
if (check_excludes(cpuc->event, 0, n))
return -EINVAL;
if (sparc_check_constraints(cpuc->event, cpuc->events, n))
return -EAGAIN;
cpuc->txn_flags = 0;
perf_pmu_enable(pmu);
return 0;
}
void perf_event_print_debug(void)
{
unsigned long flags;
int cpu, i;
if (!sparc_pmu)
return;
local_irq_save(flags);
cpu = smp_processor_id();
pr_info("\n");
for (i = 0; i < sparc_pmu->num_pcrs; i++)
pr_info("CPU#%d: PCR%d[%016llx]\n",
cpu, i, pcr_ops->read_pcr(i));
for (i = 0; i < sparc_pmu->num_pic_regs; i++)
pr_info("CPU#%d: PIC%d[%016llx]\n",
cpu, i, pcr_ops->read_pic(i));
local_irq_restore(flags);
}
static int __kprobes perf_event_nmi_handler(struct notifier_block *self,
unsigned long cmd, void *__args)
{
struct die_args *args = __args;
struct perf_sample_data data;
struct cpu_hw_events *cpuc;
struct pt_regs *regs;
int i;
if (!atomic_read(&active_events))
return NOTIFY_DONE;
switch (cmd) {
case DIE_NMI:
break;
default:
return NOTIFY_DONE;
}
regs = args->regs;
cpuc = this_cpu_ptr(&cpu_hw_events);
if (sparc_pmu->irq_bit &&
sparc_pmu->num_pcrs == 1)
pcr_ops->write_pcr(0, cpuc->pcr[0]);
for (i = 0; i < cpuc->n_events; i++) {
struct perf_event *event = cpuc->event[i];
int idx = cpuc->current_idx[i];
struct hw_perf_event *hwc;
u64 val;
if (sparc_pmu->irq_bit &&
sparc_pmu->num_pcrs > 1)
pcr_ops->write_pcr(idx, cpuc->pcr[idx]);
hwc = &event->hw;
val = sparc_perf_event_update(event, hwc, idx);
if (val & (1ULL << 31))
continue;
perf_sample_data_init(&data, 0, hwc->last_period);
if (!sparc_perf_event_set_period(event, hwc, idx))
continue;
if (perf_event_overflow(event, &data, regs))
sparc_pmu_stop(event, 0);
}
return NOTIFY_STOP;
}
static bool __init supported_pmu(void)
{
if (!strcmp(sparc_pmu_type, "ultra3") ||
!strcmp(sparc_pmu_type, "ultra3+") ||
!strcmp(sparc_pmu_type, "ultra3i") ||
!strcmp(sparc_pmu_type, "ultra4+")) {
sparc_pmu = &ultra3_pmu;
return true;
}
if (!strcmp(sparc_pmu_type, "niagara")) {
sparc_pmu = &niagara1_pmu;
return true;
}
if (!strcmp(sparc_pmu_type, "niagara2") ||
!strcmp(sparc_pmu_type, "niagara3")) {
sparc_pmu = &niagara2_pmu;
return true;
}
if (!strcmp(sparc_pmu_type, "niagara4") ||
!strcmp(sparc_pmu_type, "niagara5")) {
sparc_pmu = &niagara4_pmu;
return true;
}
if (!strcmp(sparc_pmu_type, "sparc-m7")) {
sparc_pmu = &sparc_m7_pmu;
return true;
}
return false;
}
static int __init init_hw_perf_events(void)
{
int err;
pr_info("Performance events: ");
err = pcr_arch_init();
if (err || !supported_pmu()) {
pr_cont("No support for PMU type '%s'\n", sparc_pmu_type);
return 0;
}
pr_cont("Supported PMU type is '%s'\n", sparc_pmu_type);
perf_pmu_register(&pmu, "cpu", PERF_TYPE_RAW);
register_die_notifier(&perf_event_nmi_notifier);
return 0;
}
void perf_callchain_kernel(struct perf_callchain_entry *entry,
struct pt_regs *regs)
{
unsigned long ksp, fp;
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
int graph = 0;
#endif
stack_trace_flush();
perf_callchain_store(entry, regs->tpc);
ksp = regs->u_regs[UREG_I6];
fp = ksp + STACK_BIAS;
do {
struct sparc_stackf *sf;
struct pt_regs *regs;
unsigned long pc;
if (!kstack_valid(current_thread_info(), fp))
break;
sf = (struct sparc_stackf *) fp;
regs = (struct pt_regs *) (sf + 1);
if (kstack_is_trap_frame(current_thread_info(), regs)) {
if (user_mode(regs))
break;
pc = regs->tpc;
fp = regs->u_regs[UREG_I6] + STACK_BIAS;
} else {
pc = sf->callers_pc;
fp = (unsigned long)sf->fp + STACK_BIAS;
}
perf_callchain_store(entry, pc);
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
if ((pc + 8UL) == (unsigned long) &return_to_handler) {
int index = current->curr_ret_stack;
if (current->ret_stack && index >= graph) {
pc = current->ret_stack[index - graph].ret;
perf_callchain_store(entry, pc);
graph++;
}
}
#endif
} while (entry->nr < PERF_MAX_STACK_DEPTH);
}
static inline int
valid_user_frame(const void __user *fp, unsigned long size)
{
if (((unsigned long) fp) & 3)
return 0;
return (__range_not_ok(fp, size, TASK_SIZE) == 0);
}
static void perf_callchain_user_64(struct perf_callchain_entry *entry,
struct pt_regs *regs)
{
unsigned long ufp;
ufp = regs->u_regs[UREG_FP] + STACK_BIAS;
do {
struct sparc_stackf __user *usf;
struct sparc_stackf sf;
unsigned long pc;
usf = (struct sparc_stackf __user *)ufp;
if (!valid_user_frame(usf, sizeof(sf)))
break;
if (__copy_from_user_inatomic(&sf, usf, sizeof(sf)))
break;
pc = sf.callers_pc;
ufp = (unsigned long)sf.fp + STACK_BIAS;
perf_callchain_store(entry, pc);
} while (entry->nr < PERF_MAX_STACK_DEPTH);
}
static void perf_callchain_user_32(struct perf_callchain_entry *entry,
struct pt_regs *regs)
{
unsigned long ufp;
ufp = regs->u_regs[UREG_FP] & 0xffffffffUL;
do {
unsigned long pc;
if (thread32_stack_is_64bit(ufp)) {
struct sparc_stackf __user *usf;
struct sparc_stackf sf;
ufp += STACK_BIAS;
usf = (struct sparc_stackf __user *)ufp;
if (__copy_from_user_inatomic(&sf, usf, sizeof(sf)))
break;
pc = sf.callers_pc & 0xffffffff;
ufp = ((unsigned long) sf.fp) & 0xffffffff;
} else {
struct sparc_stackf32 __user *usf;
struct sparc_stackf32 sf;
usf = (struct sparc_stackf32 __user *)ufp;
if (__copy_from_user_inatomic(&sf, usf, sizeof(sf)))
break;
pc = sf.callers_pc;
ufp = (unsigned long)sf.fp;
}
perf_callchain_store(entry, pc);
} while (entry->nr < PERF_MAX_STACK_DEPTH);
}
void
perf_callchain_user(struct perf_callchain_entry *entry, struct pt_regs *regs)
{
u64 saved_fault_address = current_thread_info()->fault_address;
u8 saved_fault_code = get_thread_fault_code();
mm_segment_t old_fs;
perf_callchain_store(entry, regs->tpc);
if (!current->mm)
return;
old_fs = get_fs();
set_fs(USER_DS);
flushw_user();
pagefault_disable();
if (test_thread_flag(TIF_32BIT))
perf_callchain_user_32(entry, regs);
else
perf_callchain_user_64(entry, regs);
pagefault_enable();
set_fs(old_fs);
set_thread_fault_code(saved_fault_code);
current_thread_info()->fault_address = saved_fault_address;
}
