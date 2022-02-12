static inline bool __rmid_valid(u32 rmid)
{
if (!rmid || rmid == INVALID_RMID)
return false;
return true;
}
static u64 __rmid_read(u32 rmid)
{
u64 val;
wrmsr(MSR_IA32_QM_EVTSEL, QOS_L3_OCCUP_EVENT_ID, rmid);
rdmsrl(MSR_IA32_QM_CTR, val);
return val;
}
static inline struct cqm_rmid_entry *__rmid_entry(u32 rmid)
{
struct cqm_rmid_entry *entry;
entry = cqm_rmid_ptrs[rmid];
WARN_ON(entry->rmid != rmid);
return entry;
}
static u32 __get_rmid(void)
{
struct cqm_rmid_entry *entry;
lockdep_assert_held(&cache_mutex);
if (list_empty(&cqm_rmid_free_lru))
return INVALID_RMID;
entry = list_first_entry(&cqm_rmid_free_lru, struct cqm_rmid_entry, list);
list_del(&entry->list);
return entry->rmid;
}
static void __put_rmid(u32 rmid)
{
struct cqm_rmid_entry *entry;
lockdep_assert_held(&cache_mutex);
WARN_ON(!__rmid_valid(rmid));
entry = __rmid_entry(rmid);
entry->queue_time = jiffies;
entry->state = RMID_YOUNG;
list_add_tail(&entry->list, &cqm_rmid_limbo_lru);
}
static void cqm_cleanup(void)
{
int i;
if (!cqm_rmid_ptrs)
return;
for (i = 0; i < cqm_max_rmid; i++)
kfree(cqm_rmid_ptrs[i]);
kfree(cqm_rmid_ptrs);
cqm_rmid_ptrs = NULL;
cqm_enabled = false;
}
static int intel_cqm_setup_rmid_cache(void)
{
struct cqm_rmid_entry *entry;
unsigned int nr_rmids;
int r = 0;
nr_rmids = cqm_max_rmid + 1;
cqm_rmid_ptrs = kzalloc(sizeof(struct cqm_rmid_entry *) *
nr_rmids, GFP_KERNEL);
if (!cqm_rmid_ptrs)
return -ENOMEM;
for (; r <= cqm_max_rmid; r++) {
struct cqm_rmid_entry *entry;
entry = kmalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
goto fail;
INIT_LIST_HEAD(&entry->list);
entry->rmid = r;
cqm_rmid_ptrs[r] = entry;
list_add_tail(&entry->list, &cqm_rmid_free_lru);
}
entry = __rmid_entry(0);
list_del(&entry->list);
mutex_lock(&cache_mutex);
intel_cqm_rotation_rmid = __get_rmid();
mutex_unlock(&cache_mutex);
return 0;
fail:
cqm_cleanup();
return -ENOMEM;
}
static bool __match_event(struct perf_event *a, struct perf_event *b)
{
if ((a->attach_state & PERF_ATTACH_TASK) !=
(b->attach_state & PERF_ATTACH_TASK))
return false;
#ifdef CONFIG_CGROUP_PERF
if (a->cgrp != b->cgrp)
return false;
#endif
if (!(b->attach_state & PERF_ATTACH_TASK))
return true;
if (a->hw.target == b->hw.target) {
b->hw.is_group_event = true;
return true;
}
if (b->parent == a)
return true;
return false;
}
static inline struct perf_cgroup *event_to_cgroup(struct perf_event *event)
{
if (event->attach_state & PERF_ATTACH_TASK)
return perf_cgroup_from_task(event->hw.target, event->ctx);
return event->cgrp;
}
static bool __conflict_event(struct perf_event *a, struct perf_event *b)
{
#ifdef CONFIG_CGROUP_PERF
if (a->cgrp && b->cgrp) {
struct perf_cgroup *ac = a->cgrp;
struct perf_cgroup *bc = b->cgrp;
WARN_ON_ONCE(ac == bc);
if (cgroup_is_descendant(ac->css.cgroup, bc->css.cgroup) ||
cgroup_is_descendant(bc->css.cgroup, ac->css.cgroup))
return true;
return false;
}
if (a->cgrp || b->cgrp) {
struct perf_cgroup *ac, *bc;
if ((a->cgrp && !(b->attach_state & PERF_ATTACH_TASK)) ||
(b->cgrp && !(a->attach_state & PERF_ATTACH_TASK)))
return true;
ac = event_to_cgroup(a);
bc = event_to_cgroup(b);
if (ac == bc)
return true;
if (!ac || !bc)
return false;
if (cgroup_is_descendant(ac->css.cgroup, bc->css.cgroup) ||
cgroup_is_descendant(bc->css.cgroup, ac->css.cgroup))
return true;
return false;
}
#endif
if (!(a->attach_state & PERF_ATTACH_TASK) ||
!(b->attach_state & PERF_ATTACH_TASK))
return true;
return false;
}
static bool is_cqm_event(int e)
{
return (e == QOS_L3_OCCUP_EVENT_ID);
}
static bool is_mbm_event(int e)
{
return (e >= QOS_MBM_TOTAL_EVENT_ID && e <= QOS_MBM_LOCAL_EVENT_ID);
}
static void cqm_mask_call(struct rmid_read *rr)
{
if (is_mbm_event(rr->evt_type))
on_each_cpu_mask(&cqm_cpumask, __intel_mbm_event_count, rr, 1);
else
on_each_cpu_mask(&cqm_cpumask, __intel_cqm_event_count, rr, 1);
}
static u32 intel_cqm_xchg_rmid(struct perf_event *group, u32 rmid)
{
struct perf_event *event;
struct list_head *head = &group->hw.cqm_group_entry;
u32 old_rmid = group->hw.cqm_rmid;
lockdep_assert_held(&cache_mutex);
if (__rmid_valid(old_rmid) && !__rmid_valid(rmid)) {
struct rmid_read rr = {
.rmid = old_rmid,
.evt_type = group->attr.config,
.value = ATOMIC64_INIT(0),
};
cqm_mask_call(&rr);
local64_set(&group->count, atomic64_read(&rr.value));
}
raw_spin_lock_irq(&cache_lock);
group->hw.cqm_rmid = rmid;
list_for_each_entry(event, head, hw.cqm_group_entry)
event->hw.cqm_rmid = rmid;
raw_spin_unlock_irq(&cache_lock);
if (__rmid_valid(rmid)) {
event = group;
if (is_mbm_event(event->attr.config))
init_mbm_sample(rmid, event->attr.config);
list_for_each_entry(event, head, hw.cqm_group_entry) {
if (is_mbm_event(event->attr.config))
init_mbm_sample(rmid, event->attr.config);
}
}
return old_rmid;
}
static void intel_cqm_stable(void *arg)
{
struct cqm_rmid_entry *entry;
list_for_each_entry(entry, &cqm_rmid_limbo_lru, list) {
if (entry->state != RMID_AVAILABLE)
break;
if (__rmid_read(entry->rmid) > __intel_cqm_threshold)
entry->state = RMID_DIRTY;
}
}
static bool intel_cqm_sched_in_event(u32 rmid)
{
struct perf_event *leader, *event;
lockdep_assert_held(&cache_mutex);
leader = list_first_entry(&cache_groups, struct perf_event,
hw.cqm_groups_entry);
event = leader;
list_for_each_entry_continue(event, &cache_groups,
hw.cqm_groups_entry) {
if (__rmid_valid(event->hw.cqm_rmid))
continue;
if (__conflict_event(event, leader))
continue;
intel_cqm_xchg_rmid(event, rmid);
return true;
}
return false;
}
static bool intel_cqm_rmid_stabilize(unsigned int *available)
{
struct cqm_rmid_entry *entry, *tmp;
lockdep_assert_held(&cache_mutex);
*available = 0;
list_for_each_entry(entry, &cqm_rmid_limbo_lru, list) {
unsigned long min_queue_time;
unsigned long now = jiffies;
min_queue_time = entry->queue_time +
msecs_to_jiffies(__rmid_queue_time_ms);
if (time_after(min_queue_time, now))
break;
entry->state = RMID_AVAILABLE;
(*available)++;
}
if (!*available)
return false;
on_each_cpu_mask(&cqm_cpumask, intel_cqm_stable, NULL, true);
list_for_each_entry_safe(entry, tmp, &cqm_rmid_limbo_lru, list) {
if (entry->state == RMID_YOUNG)
break;
if (entry->state == RMID_DIRTY)
continue;
list_del(&entry->list);
if (!__rmid_valid(intel_cqm_rotation_rmid)) {
intel_cqm_rotation_rmid = entry->rmid;
continue;
}
if (intel_cqm_sched_in_event(entry->rmid))
continue;
list_add_tail(&entry->list, &cqm_rmid_free_lru);
}
return __rmid_valid(intel_cqm_rotation_rmid);
}
static void __intel_cqm_pick_and_rotate(struct perf_event *next)
{
struct perf_event *rotor;
u32 rmid;
lockdep_assert_held(&cache_mutex);
rotor = list_first_entry(&cache_groups, struct perf_event,
hw.cqm_groups_entry);
if (next == rotor)
return;
rmid = intel_cqm_xchg_rmid(rotor, INVALID_RMID);
__put_rmid(rmid);
list_rotate_left(&cache_groups);
}
static void intel_cqm_sched_out_conflicting_events(struct perf_event *event)
{
struct perf_event *group, *g;
u32 rmid;
lockdep_assert_held(&cache_mutex);
list_for_each_entry_safe(group, g, &cache_groups, hw.cqm_groups_entry) {
if (group == event)
continue;
rmid = group->hw.cqm_rmid;
if (!__rmid_valid(rmid))
continue;
if (!__conflict_event(group, event))
continue;
intel_cqm_xchg_rmid(group, INVALID_RMID);
__put_rmid(rmid);
}
}
static bool __intel_cqm_rmid_rotate(void)
{
struct perf_event *group, *start = NULL;
unsigned int threshold_limit;
unsigned int nr_needed = 0;
unsigned int nr_available;
bool rotated = false;
mutex_lock(&cache_mutex);
again:
if (list_empty(&cache_groups) && list_empty(&cqm_rmid_limbo_lru))
goto out;
list_for_each_entry(group, &cache_groups, hw.cqm_groups_entry) {
if (!__rmid_valid(group->hw.cqm_rmid)) {
if (!start)
start = group;
nr_needed++;
}
}
if (!nr_needed && list_empty(&cqm_rmid_limbo_lru))
goto out;
if (!nr_needed)
goto stabilize;
__intel_cqm_pick_and_rotate(start);
if (__rmid_valid(intel_cqm_rotation_rmid)) {
intel_cqm_xchg_rmid(start, intel_cqm_rotation_rmid);
intel_cqm_rotation_rmid = __get_rmid();
intel_cqm_sched_out_conflicting_events(start);
if (__intel_cqm_threshold)
__intel_cqm_threshold--;
}
rotated = true;
stabilize:
threshold_limit = __intel_cqm_max_threshold / cqm_l3_scale;
while (intel_cqm_rmid_stabilize(&nr_available) &&
__intel_cqm_threshold < threshold_limit) {
unsigned int steal_limit;
if (!nr_needed)
break;
steal_limit = (cqm_max_rmid + 1) / 4;
if (nr_available < steal_limit)
goto again;
__intel_cqm_threshold++;
}
out:
mutex_unlock(&cache_mutex);
return rotated;
}
static void intel_cqm_rmid_rotate(struct work_struct *work)
{
unsigned long delay;
__intel_cqm_rmid_rotate();
delay = msecs_to_jiffies(intel_cqm_pmu.hrtimer_interval_ms);
schedule_delayed_work(&intel_cqm_rmid_work, delay);
}
static u64 update_sample(unsigned int rmid, u32 evt_type, int first)
{
struct sample *mbm_current;
u32 vrmid = rmid_2_index(rmid);
u64 val, bytes, shift;
u32 eventid;
if (evt_type == QOS_MBM_LOCAL_EVENT_ID) {
mbm_current = &mbm_local[vrmid];
eventid = QOS_MBM_LOCAL_EVENT_ID;
} else {
mbm_current = &mbm_total[vrmid];
eventid = QOS_MBM_TOTAL_EVENT_ID;
}
wrmsr(MSR_IA32_QM_EVTSEL, eventid, rmid);
rdmsrl(MSR_IA32_QM_CTR, val);
if (val & (RMID_VAL_ERROR | RMID_VAL_UNAVAIL))
return mbm_current->total_bytes;
if (first) {
mbm_current->prev_msr = val;
mbm_current->total_bytes = 0;
return mbm_current->total_bytes;
}
shift = 64 - MBM_CNTR_WIDTH;
bytes = (val << shift) - (mbm_current->prev_msr << shift);
bytes >>= shift;
bytes *= cqm_l3_scale;
mbm_current->total_bytes += bytes;
mbm_current->prev_msr = val;
return mbm_current->total_bytes;
}
static u64 rmid_read_mbm(unsigned int rmid, u32 evt_type)
{
return update_sample(rmid, evt_type, 0);
}
static void __intel_mbm_event_init(void *info)
{
struct rmid_read *rr = info;
update_sample(rr->rmid, rr->evt_type, 1);
}
static void init_mbm_sample(u32 rmid, u32 evt_type)
{
struct rmid_read rr = {
.rmid = rmid,
.evt_type = evt_type,
.value = ATOMIC64_INIT(0),
};
on_each_cpu_mask(&cqm_cpumask, __intel_mbm_event_init, &rr, 1);
}
static void intel_cqm_setup_event(struct perf_event *event,
struct perf_event **group)
{
struct perf_event *iter;
bool conflict = false;
u32 rmid;
event->hw.is_group_event = false;
list_for_each_entry(iter, &cache_groups, hw.cqm_groups_entry) {
rmid = iter->hw.cqm_rmid;
if (__match_event(iter, event)) {
event->hw.cqm_rmid = rmid;
*group = iter;
if (is_mbm_event(event->attr.config) && __rmid_valid(rmid))
init_mbm_sample(rmid, event->attr.config);
return;
}
if (__conflict_event(iter, event) && __rmid_valid(rmid))
conflict = true;
}
if (conflict)
rmid = INVALID_RMID;
else
rmid = __get_rmid();
if (is_mbm_event(event->attr.config) && __rmid_valid(rmid))
init_mbm_sample(rmid, event->attr.config);
event->hw.cqm_rmid = rmid;
}
static void intel_cqm_event_read(struct perf_event *event)
{
unsigned long flags;
u32 rmid;
u64 val;
if (event->cpu == -1)
return;
raw_spin_lock_irqsave(&cache_lock, flags);
rmid = event->hw.cqm_rmid;
if (!__rmid_valid(rmid))
goto out;
if (is_mbm_event(event->attr.config))
val = rmid_read_mbm(rmid, event->attr.config);
else
val = __rmid_read(rmid);
if (val & (RMID_VAL_ERROR | RMID_VAL_UNAVAIL))
goto out;
local64_set(&event->count, val);
out:
raw_spin_unlock_irqrestore(&cache_lock, flags);
}
static void __intel_cqm_event_count(void *info)
{
struct rmid_read *rr = info;
u64 val;
val = __rmid_read(rr->rmid);
if (val & (RMID_VAL_ERROR | RMID_VAL_UNAVAIL))
return;
atomic64_add(val, &rr->value);
}
static inline bool cqm_group_leader(struct perf_event *event)
{
return !list_empty(&event->hw.cqm_groups_entry);
}
static void __intel_mbm_event_count(void *info)
{
struct rmid_read *rr = info;
u64 val;
val = rmid_read_mbm(rr->rmid, rr->evt_type);
if (val & (RMID_VAL_ERROR | RMID_VAL_UNAVAIL))
return;
atomic64_add(val, &rr->value);
}
static enum hrtimer_restart mbm_hrtimer_handle(struct hrtimer *hrtimer)
{
struct perf_event *iter, *iter1;
int ret = HRTIMER_RESTART;
struct list_head *head;
unsigned long flags;
u32 grp_rmid;
raw_spin_lock_irqsave(&cache_lock, flags);
if (list_empty(&cache_groups)) {
ret = HRTIMER_NORESTART;
goto out;
}
list_for_each_entry(iter, &cache_groups, hw.cqm_groups_entry) {
grp_rmid = iter->hw.cqm_rmid;
if (!__rmid_valid(grp_rmid))
continue;
if (is_mbm_event(iter->attr.config))
update_sample(grp_rmid, iter->attr.config, 0);
head = &iter->hw.cqm_group_entry;
if (list_empty(head))
continue;
list_for_each_entry(iter1, head, hw.cqm_group_entry) {
if (!iter1->hw.is_group_event)
break;
if (is_mbm_event(iter1->attr.config))
update_sample(iter1->hw.cqm_rmid,
iter1->attr.config, 0);
}
}
hrtimer_forward_now(hrtimer, ms_to_ktime(MBM_CTR_OVERFLOW_TIME));
out:
raw_spin_unlock_irqrestore(&cache_lock, flags);
return ret;
}
static void __mbm_start_timer(void *info)
{
hrtimer_start(&mbm_timers[pkg_id], ms_to_ktime(MBM_CTR_OVERFLOW_TIME),
HRTIMER_MODE_REL_PINNED);
}
static void __mbm_stop_timer(void *info)
{
hrtimer_cancel(&mbm_timers[pkg_id]);
}
static void mbm_start_timers(void)
{
on_each_cpu_mask(&cqm_cpumask, __mbm_start_timer, NULL, 1);
}
static void mbm_stop_timers(void)
{
on_each_cpu_mask(&cqm_cpumask, __mbm_stop_timer, NULL, 1);
}
static void mbm_hrtimer_init(void)
{
struct hrtimer *hr;
int i;
for (i = 0; i < mbm_socket_max; i++) {
hr = &mbm_timers[i];
hrtimer_init(hr, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
hr->function = mbm_hrtimer_handle;
}
}
static u64 intel_cqm_event_count(struct perf_event *event)
{
unsigned long flags;
struct rmid_read rr = {
.evt_type = event->attr.config,
.value = ATOMIC64_INIT(0),
};
if (event->cpu != -1)
return __perf_event_count(event);
if (!cqm_group_leader(event) && !event->hw.is_group_event)
return 0;
if (unlikely(in_interrupt()))
goto out;
rr.rmid = ACCESS_ONCE(event->hw.cqm_rmid);
if (!__rmid_valid(rr.rmid))
goto out;
cqm_mask_call(&rr);
raw_spin_lock_irqsave(&cache_lock, flags);
if (event->hw.cqm_rmid == rr.rmid)
local64_set(&event->count, atomic64_read(&rr.value));
raw_spin_unlock_irqrestore(&cache_lock, flags);
out:
return __perf_event_count(event);
}
static void intel_cqm_event_start(struct perf_event *event, int mode)
{
struct intel_pqr_state *state = this_cpu_ptr(&pqr_state);
u32 rmid = event->hw.cqm_rmid;
if (!(event->hw.cqm_state & PERF_HES_STOPPED))
return;
event->hw.cqm_state &= ~PERF_HES_STOPPED;
if (state->rmid_usecnt++) {
if (!WARN_ON_ONCE(state->rmid != rmid))
return;
} else {
WARN_ON_ONCE(state->rmid);
}
state->rmid = rmid;
wrmsr(MSR_IA32_PQR_ASSOC, rmid, state->closid);
}
static void intel_cqm_event_stop(struct perf_event *event, int mode)
{
struct intel_pqr_state *state = this_cpu_ptr(&pqr_state);
if (event->hw.cqm_state & PERF_HES_STOPPED)
return;
event->hw.cqm_state |= PERF_HES_STOPPED;
intel_cqm_event_read(event);
if (!--state->rmid_usecnt) {
state->rmid = 0;
wrmsr(MSR_IA32_PQR_ASSOC, 0, state->closid);
} else {
WARN_ON_ONCE(!state->rmid);
}
}
static int intel_cqm_event_add(struct perf_event *event, int mode)
{
unsigned long flags;
u32 rmid;
raw_spin_lock_irqsave(&cache_lock, flags);
event->hw.cqm_state = PERF_HES_STOPPED;
rmid = event->hw.cqm_rmid;
if (__rmid_valid(rmid) && (mode & PERF_EF_START))
intel_cqm_event_start(event, mode);
raw_spin_unlock_irqrestore(&cache_lock, flags);
return 0;
}
static void intel_cqm_event_destroy(struct perf_event *event)
{
struct perf_event *group_other = NULL;
unsigned long flags;
mutex_lock(&cache_mutex);
raw_spin_lock_irqsave(&cache_lock, flags);
if (!list_empty(&event->hw.cqm_group_entry)) {
group_other = list_first_entry(&event->hw.cqm_group_entry,
struct perf_event,
hw.cqm_group_entry);
list_del(&event->hw.cqm_group_entry);
}
if (cqm_group_leader(event)) {
if (group_other) {
list_replace(&event->hw.cqm_groups_entry,
&group_other->hw.cqm_groups_entry);
} else {
u32 rmid = event->hw.cqm_rmid;
if (__rmid_valid(rmid))
__put_rmid(rmid);
list_del(&event->hw.cqm_groups_entry);
}
}
raw_spin_unlock_irqrestore(&cache_lock, flags);
if (mbm_enabled && list_empty(&cache_groups))
mbm_stop_timers();
mutex_unlock(&cache_mutex);
}
static int intel_cqm_event_init(struct perf_event *event)
{
struct perf_event *group = NULL;
bool rotate = false;
unsigned long flags;
if (event->attr.type != intel_cqm_pmu.type)
return -ENOENT;
if ((event->attr.config < QOS_L3_OCCUP_EVENT_ID) ||
(event->attr.config > QOS_MBM_LOCAL_EVENT_ID))
return -EINVAL;
if ((is_cqm_event(event->attr.config) && !cqm_enabled) ||
(is_mbm_event(event->attr.config) && !mbm_enabled))
return -EINVAL;
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest ||
event->attr.sample_period)
return -EINVAL;
INIT_LIST_HEAD(&event->hw.cqm_group_entry);
INIT_LIST_HEAD(&event->hw.cqm_groups_entry);
event->destroy = intel_cqm_event_destroy;
mutex_lock(&cache_mutex);
if (mbm_enabled && list_empty(&cache_groups))
mbm_start_timers();
intel_cqm_setup_event(event, &group);
raw_spin_lock_irqsave(&cache_lock, flags);
if (group) {
list_add_tail(&event->hw.cqm_group_entry,
&group->hw.cqm_group_entry);
} else {
list_add_tail(&event->hw.cqm_groups_entry,
&cache_groups);
if (!__rmid_valid(event->hw.cqm_rmid))
rotate = true;
}
raw_spin_unlock_irqrestore(&cache_lock, flags);
mutex_unlock(&cache_mutex);
if (rotate)
schedule_delayed_work(&intel_cqm_rmid_work, 0);
return 0;
}
static ssize_t
max_recycle_threshold_show(struct device *dev, struct device_attribute *attr,
char *page)
{
ssize_t rv;
mutex_lock(&cache_mutex);
rv = snprintf(page, PAGE_SIZE-1, "%u\n", __intel_cqm_max_threshold);
mutex_unlock(&cache_mutex);
return rv;
}
static ssize_t
max_recycle_threshold_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned int bytes, cachelines;
int ret;
ret = kstrtouint(buf, 0, &bytes);
if (ret)
return ret;
mutex_lock(&cache_mutex);
__intel_cqm_max_threshold = bytes;
cachelines = bytes / cqm_l3_scale;
if (__intel_cqm_threshold > cachelines)
__intel_cqm_threshold = cachelines;
mutex_unlock(&cache_mutex);
return count;
}
static inline void cqm_pick_event_reader(int cpu)
{
int reader;
reader = cpumask_any_and(&cqm_cpumask, topology_core_cpumask(cpu));
if (reader >= nr_cpu_ids)
cpumask_set_cpu(cpu, &cqm_cpumask);
}
static int intel_cqm_cpu_starting(unsigned int cpu)
{
struct intel_pqr_state *state = &per_cpu(pqr_state, cpu);
struct cpuinfo_x86 *c = &cpu_data(cpu);
state->rmid = 0;
state->closid = 0;
state->rmid_usecnt = 0;
WARN_ON(c->x86_cache_max_rmid != cqm_max_rmid);
WARN_ON(c->x86_cache_occ_scale != cqm_l3_scale);
cqm_pick_event_reader(cpu);
return 0;
}
static int intel_cqm_cpu_exit(unsigned int cpu)
{
int target;
if (!cpumask_test_and_clear_cpu(cpu, &cqm_cpumask))
return 0;
target = cpumask_any_but(topology_core_cpumask(cpu), cpu);
if (target < nr_cpu_ids)
cpumask_set_cpu(target, &cqm_cpumask);
return 0;
}
static void mbm_cleanup(void)
{
if (!mbm_enabled)
return;
kfree(mbm_local);
kfree(mbm_total);
mbm_enabled = false;
}
static int intel_mbm_init(void)
{
int ret = 0, array_size, maxid = cqm_max_rmid + 1;
mbm_socket_max = topology_max_packages();
array_size = sizeof(struct sample) * maxid * mbm_socket_max;
mbm_local = kmalloc(array_size, GFP_KERNEL);
if (!mbm_local)
return -ENOMEM;
mbm_total = kmalloc(array_size, GFP_KERNEL);
if (!mbm_total) {
ret = -ENOMEM;
goto out;
}
array_size = sizeof(struct hrtimer) * mbm_socket_max;
mbm_timers = kmalloc(array_size, GFP_KERNEL);
if (!mbm_timers) {
ret = -ENOMEM;
goto out;
}
mbm_hrtimer_init();
out:
if (ret)
mbm_cleanup();
return ret;
}
static int __init intel_cqm_init(void)
{
char *str = NULL, scale[20];
int cpu, ret;
if (x86_match_cpu(intel_cqm_match))
cqm_enabled = true;
if (x86_match_cpu(intel_mbm_local_match) &&
x86_match_cpu(intel_mbm_total_match))
mbm_enabled = true;
if (!cqm_enabled && !mbm_enabled)
return -ENODEV;
cqm_l3_scale = boot_cpu_data.x86_cache_occ_scale;
cpus_read_lock();
for_each_online_cpu(cpu) {
struct cpuinfo_x86 *c = &cpu_data(cpu);
if (c->x86_cache_max_rmid < cqm_max_rmid)
cqm_max_rmid = c->x86_cache_max_rmid;
if (c->x86_cache_occ_scale != cqm_l3_scale) {
pr_err("Multiple LLC scale values, disabling\n");
ret = -EINVAL;
goto out;
}
}
__intel_cqm_max_threshold =
boot_cpu_data.x86_cache_size * 1024 / (cqm_max_rmid + 1);
snprintf(scale, sizeof(scale), "%u", cqm_l3_scale);
str = kstrdup(scale, GFP_KERNEL);
if (!str) {
ret = -ENOMEM;
goto out;
}
event_attr_intel_cqm_llc_scale.event_str = str;
ret = intel_cqm_setup_rmid_cache();
if (ret)
goto out;
if (mbm_enabled)
ret = intel_mbm_init();
if (ret && !cqm_enabled)
goto out;
if (cqm_enabled && mbm_enabled)
intel_cqm_events_group.attrs = intel_cmt_mbm_events_attr;
else if (!cqm_enabled && mbm_enabled)
intel_cqm_events_group.attrs = intel_mbm_events_attr;
else if (cqm_enabled && !mbm_enabled)
intel_cqm_events_group.attrs = intel_cqm_events_attr;
ret = perf_pmu_register(&intel_cqm_pmu, "intel_cqm", -1);
if (ret) {
pr_err("Intel CQM perf registration failed: %d\n", ret);
goto out;
}
if (cqm_enabled)
pr_info("Intel CQM monitoring enabled\n");
if (mbm_enabled)
pr_info("Intel MBM enabled\n");
cpuhp_setup_state_cpuslocked(CPUHP_AP_PERF_X86_CQM_STARTING,
"perf/x86/cqm:starting",
intel_cqm_cpu_starting, NULL);
cpuhp_setup_state_cpuslocked(CPUHP_AP_PERF_X86_CQM_ONLINE,
"perf/x86/cqm:online",
NULL, intel_cqm_cpu_exit);
out:
cpus_read_unlock();
if (ret) {
kfree(str);
cqm_cleanup();
mbm_cleanup();
}
return ret;
}
