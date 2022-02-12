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
static int intel_cqm_setup_rmid_cache(void)
{
struct cqm_rmid_entry *entry;
unsigned int nr_rmids;
int r = 0;
nr_rmids = cqm_max_rmid + 1;
cqm_rmid_ptrs = kmalloc(sizeof(struct cqm_rmid_entry *) *
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
while (r--)
kfree(cqm_rmid_ptrs[r]);
kfree(cqm_rmid_ptrs);
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
if (a->hw.target == b->hw.target)
return true;
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
static u32 intel_cqm_xchg_rmid(struct perf_event *group, u32 rmid)
{
struct perf_event *event;
struct list_head *head = &group->hw.cqm_group_entry;
u32 old_rmid = group->hw.cqm_rmid;
lockdep_assert_held(&cache_mutex);
if (__rmid_valid(old_rmid) && !__rmid_valid(rmid)) {
struct rmid_read rr = {
.value = ATOMIC64_INIT(0),
.rmid = old_rmid,
};
on_each_cpu_mask(&cqm_cpumask, __intel_cqm_event_count,
&rr, 1);
local64_set(&group->count, atomic64_read(&rr.value));
}
raw_spin_lock_irq(&cache_lock);
group->hw.cqm_rmid = rmid;
list_for_each_entry(event, head, hw.cqm_group_entry)
event->hw.cqm_rmid = rmid;
raw_spin_unlock_irq(&cache_lock);
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
static void intel_cqm_setup_event(struct perf_event *event,
struct perf_event **group)
{
struct perf_event *iter;
bool conflict = false;
u32 rmid;
list_for_each_entry(iter, &cache_groups, hw.cqm_groups_entry) {
rmid = iter->hw.cqm_rmid;
if (__match_event(iter, event)) {
event->hw.cqm_rmid = rmid;
*group = iter;
return;
}
if (__conflict_event(iter, event) && __rmid_valid(rmid))
conflict = true;
}
if (conflict)
rmid = INVALID_RMID;
else
rmid = __get_rmid();
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
static u64 intel_cqm_event_count(struct perf_event *event)
{
unsigned long flags;
struct rmid_read rr = {
.value = ATOMIC64_INIT(0),
};
if (event->cpu != -1)
return __perf_event_count(event);
if (!cqm_group_leader(event))
return 0;
if (unlikely(in_interrupt()))
goto out;
rr.rmid = ACCESS_ONCE(event->hw.cqm_rmid);
if (!__rmid_valid(rr.rmid))
goto out;
on_each_cpu_mask(&cqm_cpumask, __intel_cqm_event_count, &rr, 1);
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
mutex_lock(&cache_mutex);
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
mutex_unlock(&cache_mutex);
}
static int intel_cqm_event_init(struct perf_event *event)
{
struct perf_event *group = NULL;
bool rotate = false;
if (event->attr.type != intel_cqm_pmu.type)
return -ENOENT;
if (event->attr.config & ~QOS_EVENT_MASK)
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
intel_cqm_setup_event(event, &group);
if (group) {
list_add_tail(&event->hw.cqm_group_entry,
&group->hw.cqm_group_entry);
} else {
list_add_tail(&event->hw.cqm_groups_entry,
&cache_groups);
if (!__rmid_valid(event->hw.cqm_rmid))
rotate = true;
}
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
int phys_id = topology_physical_package_id(cpu);
int i;
for_each_cpu(i, &cqm_cpumask) {
if (phys_id == topology_physical_package_id(i))
return;
}
cpumask_set_cpu(cpu, &cqm_cpumask);
}
static void intel_cqm_cpu_starting(unsigned int cpu)
{
struct intel_pqr_state *state = &per_cpu(pqr_state, cpu);
struct cpuinfo_x86 *c = &cpu_data(cpu);
state->rmid = 0;
state->closid = 0;
state->rmid_usecnt = 0;
WARN_ON(c->x86_cache_max_rmid != cqm_max_rmid);
WARN_ON(c->x86_cache_occ_scale != cqm_l3_scale);
}
static void intel_cqm_cpu_exit(unsigned int cpu)
{
int phys_id = topology_physical_package_id(cpu);
int i;
if (!cpumask_test_and_clear_cpu(cpu, &cqm_cpumask))
return;
for_each_online_cpu(i) {
if (i == cpu)
continue;
if (phys_id == topology_physical_package_id(i)) {
cpumask_set_cpu(i, &cqm_cpumask);
break;
}
}
}
static int intel_cqm_cpu_notifier(struct notifier_block *nb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
intel_cqm_cpu_exit(cpu);
break;
case CPU_STARTING:
intel_cqm_cpu_starting(cpu);
cqm_pick_event_reader(cpu);
break;
}
return NOTIFY_OK;
}
static int __init intel_cqm_init(void)
{
char *str, scale[20];
int i, cpu, ret;
if (!x86_match_cpu(intel_cqm_match))
return -ENODEV;
cqm_l3_scale = boot_cpu_data.x86_cache_occ_scale;
cpu_notifier_register_begin();
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
for_each_online_cpu(i) {
intel_cqm_cpu_starting(i);
cqm_pick_event_reader(i);
}
__perf_cpu_notifier(intel_cqm_cpu_notifier);
ret = perf_pmu_register(&intel_cqm_pmu, "intel_cqm", -1);
if (ret)
pr_err("Intel CQM perf registration failed: %d\n", ret);
else
pr_info("Intel CQM monitoring enabled\n");
out:
cpu_notifier_register_done();
return ret;
}
