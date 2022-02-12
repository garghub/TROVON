__weak int hw_breakpoint_weight(struct perf_event *bp)
{
return 1;
}
static inline enum bp_type_idx find_slot_idx(struct perf_event *bp)
{
if (bp->attr.bp_type & HW_BREAKPOINT_RW)
return TYPE_DATA;
return TYPE_INST;
}
static unsigned int max_task_bp_pinned(int cpu, enum bp_type_idx type)
{
int i;
unsigned int *tsk_pinned = per_cpu(nr_task_bp_pinned[type], cpu);
for (i = nr_slots[type] - 1; i >= 0; i--) {
if (tsk_pinned[i] > 0)
return i + 1;
}
return 0;
}
static int task_bp_pinned(struct perf_event *bp, enum bp_type_idx type)
{
struct task_struct *tsk = bp->hw.bp_target;
struct perf_event *iter;
int count = 0;
list_for_each_entry(iter, &bp_task_head, hw.bp_list) {
if (iter->hw.bp_target == tsk && find_slot_idx(iter) == type)
count += hw_breakpoint_weight(iter);
}
return count;
}
static void
fetch_bp_busy_slots(struct bp_busy_slots *slots, struct perf_event *bp,
enum bp_type_idx type)
{
int cpu = bp->cpu;
struct task_struct *tsk = bp->hw.bp_target;
if (cpu >= 0) {
slots->pinned = per_cpu(nr_cpu_bp_pinned[type], cpu);
if (!tsk)
slots->pinned += max_task_bp_pinned(cpu, type);
else
slots->pinned += task_bp_pinned(bp, type);
slots->flexible = per_cpu(nr_bp_flexible[type], cpu);
return;
}
for_each_online_cpu(cpu) {
unsigned int nr;
nr = per_cpu(nr_cpu_bp_pinned[type], cpu);
if (!tsk)
nr += max_task_bp_pinned(cpu, type);
else
nr += task_bp_pinned(bp, type);
if (nr > slots->pinned)
slots->pinned = nr;
nr = per_cpu(nr_bp_flexible[type], cpu);
if (nr > slots->flexible)
slots->flexible = nr;
}
}
static void
fetch_this_slot(struct bp_busy_slots *slots, int weight)
{
slots->pinned += weight;
}
static void toggle_bp_task_slot(struct perf_event *bp, int cpu, bool enable,
enum bp_type_idx type, int weight)
{
unsigned int *tsk_pinned;
int old_count = 0;
int old_idx = 0;
int idx = 0;
old_count = task_bp_pinned(bp, type);
old_idx = old_count - 1;
idx = old_idx + weight;
tsk_pinned = per_cpu(nr_task_bp_pinned[type], cpu);
if (enable) {
tsk_pinned[idx]++;
if (old_count > 0)
tsk_pinned[old_idx]--;
} else {
tsk_pinned[idx]--;
if (old_count > 0)
tsk_pinned[old_idx]++;
}
}
static void
toggle_bp_slot(struct perf_event *bp, bool enable, enum bp_type_idx type,
int weight)
{
int cpu = bp->cpu;
struct task_struct *tsk = bp->hw.bp_target;
if (!tsk) {
if (enable)
per_cpu(nr_cpu_bp_pinned[type], bp->cpu) += weight;
else
per_cpu(nr_cpu_bp_pinned[type], bp->cpu) -= weight;
return;
}
if (!enable)
list_del(&bp->hw.bp_list);
if (cpu >= 0) {
toggle_bp_task_slot(bp, cpu, enable, type, weight);
} else {
for_each_online_cpu(cpu)
toggle_bp_task_slot(bp, cpu, enable, type, weight);
}
if (enable)
list_add_tail(&bp->hw.bp_list, &bp_task_head);
}
__weak void arch_unregister_hw_breakpoint(struct perf_event *bp)
{
}
static int __reserve_bp_slot(struct perf_event *bp)
{
struct bp_busy_slots slots = {0};
enum bp_type_idx type;
int weight;
if (!constraints_initialized)
return -ENOMEM;
if (bp->attr.bp_type == HW_BREAKPOINT_EMPTY ||
bp->attr.bp_type == HW_BREAKPOINT_INVALID)
return -EINVAL;
type = find_slot_idx(bp);
weight = hw_breakpoint_weight(bp);
fetch_bp_busy_slots(&slots, bp, type);
fetch_this_slot(&slots, weight);
if (slots.pinned + (!!slots.flexible) > nr_slots[type])
return -ENOSPC;
toggle_bp_slot(bp, true, type, weight);
return 0;
}
int reserve_bp_slot(struct perf_event *bp)
{
int ret;
mutex_lock(&nr_bp_mutex);
ret = __reserve_bp_slot(bp);
mutex_unlock(&nr_bp_mutex);
return ret;
}
static void __release_bp_slot(struct perf_event *bp)
{
enum bp_type_idx type;
int weight;
type = find_slot_idx(bp);
weight = hw_breakpoint_weight(bp);
toggle_bp_slot(bp, false, type, weight);
}
void release_bp_slot(struct perf_event *bp)
{
mutex_lock(&nr_bp_mutex);
arch_unregister_hw_breakpoint(bp);
__release_bp_slot(bp);
mutex_unlock(&nr_bp_mutex);
}
int dbg_reserve_bp_slot(struct perf_event *bp)
{
if (mutex_is_locked(&nr_bp_mutex))
return -1;
return __reserve_bp_slot(bp);
}
int dbg_release_bp_slot(struct perf_event *bp)
{
if (mutex_is_locked(&nr_bp_mutex))
return -1;
__release_bp_slot(bp);
return 0;
}
static int validate_hw_breakpoint(struct perf_event *bp)
{
int ret;
ret = arch_validate_hwbkpt_settings(bp);
if (ret)
return ret;
if (arch_check_bp_in_kernelspace(bp)) {
if (bp->attr.exclude_kernel)
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
}
return 0;
}
int register_perf_hw_breakpoint(struct perf_event *bp)
{
int ret;
ret = reserve_bp_slot(bp);
if (ret)
return ret;
ret = validate_hw_breakpoint(bp);
if (ret)
release_bp_slot(bp);
return ret;
}
struct perf_event *
register_user_hw_breakpoint(struct perf_event_attr *attr,
perf_overflow_handler_t triggered,
void *context,
struct task_struct *tsk)
{
return perf_event_create_kernel_counter(attr, -1, tsk, triggered,
context);
}
int modify_user_hw_breakpoint(struct perf_event *bp, struct perf_event_attr *attr)
{
u64 old_addr = bp->attr.bp_addr;
u64 old_len = bp->attr.bp_len;
int old_type = bp->attr.bp_type;
int err = 0;
perf_event_disable(bp);
bp->attr.bp_addr = attr->bp_addr;
bp->attr.bp_type = attr->bp_type;
bp->attr.bp_len = attr->bp_len;
if (attr->disabled)
goto end;
err = validate_hw_breakpoint(bp);
if (!err)
perf_event_enable(bp);
if (err) {
bp->attr.bp_addr = old_addr;
bp->attr.bp_type = old_type;
bp->attr.bp_len = old_len;
if (!bp->attr.disabled)
perf_event_enable(bp);
return err;
}
end:
bp->attr.disabled = attr->disabled;
return 0;
}
void unregister_hw_breakpoint(struct perf_event *bp)
{
if (!bp)
return;
perf_event_release_kernel(bp);
}
struct perf_event * __percpu *
register_wide_hw_breakpoint(struct perf_event_attr *attr,
perf_overflow_handler_t triggered,
void *context)
{
struct perf_event * __percpu *cpu_events, **pevent, *bp;
long err;
int cpu;
cpu_events = alloc_percpu(typeof(*cpu_events));
if (!cpu_events)
return (void __percpu __force *)ERR_PTR(-ENOMEM);
get_online_cpus();
for_each_online_cpu(cpu) {
pevent = per_cpu_ptr(cpu_events, cpu);
bp = perf_event_create_kernel_counter(attr, cpu, NULL,
triggered, context);
*pevent = bp;
if (IS_ERR(bp)) {
err = PTR_ERR(bp);
goto fail;
}
}
put_online_cpus();
return cpu_events;
fail:
for_each_online_cpu(cpu) {
pevent = per_cpu_ptr(cpu_events, cpu);
if (IS_ERR(*pevent))
break;
unregister_hw_breakpoint(*pevent);
}
put_online_cpus();
free_percpu(cpu_events);
return (void __percpu __force *)ERR_PTR(err);
}
void unregister_wide_hw_breakpoint(struct perf_event * __percpu *cpu_events)
{
int cpu;
struct perf_event **pevent;
for_each_possible_cpu(cpu) {
pevent = per_cpu_ptr(cpu_events, cpu);
unregister_hw_breakpoint(*pevent);
}
free_percpu(cpu_events);
}
static void bp_perf_event_destroy(struct perf_event *event)
{
release_bp_slot(event);
}
static int hw_breakpoint_event_init(struct perf_event *bp)
{
int err;
if (bp->attr.type != PERF_TYPE_BREAKPOINT)
return -ENOENT;
err = register_perf_hw_breakpoint(bp);
if (err)
return err;
bp->destroy = bp_perf_event_destroy;
return 0;
}
static int hw_breakpoint_add(struct perf_event *bp, int flags)
{
if (!(flags & PERF_EF_START))
bp->hw.state = PERF_HES_STOPPED;
return arch_install_hw_breakpoint(bp);
}
static void hw_breakpoint_del(struct perf_event *bp, int flags)
{
arch_uninstall_hw_breakpoint(bp);
}
static void hw_breakpoint_start(struct perf_event *bp, int flags)
{
bp->hw.state = 0;
}
static void hw_breakpoint_stop(struct perf_event *bp, int flags)
{
bp->hw.state = PERF_HES_STOPPED;
}
int __init init_hw_breakpoint(void)
{
unsigned int **task_bp_pinned;
int cpu, err_cpu;
int i;
for (i = 0; i < TYPE_MAX; i++)
nr_slots[i] = hw_breakpoint_slots(i);
for_each_possible_cpu(cpu) {
for (i = 0; i < TYPE_MAX; i++) {
task_bp_pinned = &per_cpu(nr_task_bp_pinned[i], cpu);
*task_bp_pinned = kzalloc(sizeof(int) * nr_slots[i],
GFP_KERNEL);
if (!*task_bp_pinned)
goto err_alloc;
}
}
constraints_initialized = 1;
perf_pmu_register(&perf_breakpoint, "breakpoint", PERF_TYPE_BREAKPOINT);
return register_die_notifier(&hw_breakpoint_exceptions_nb);
err_alloc:
for_each_possible_cpu(err_cpu) {
for (i = 0; i < TYPE_MAX; i++)
kfree(per_cpu(nr_task_bp_pinned[i], cpu));
if (err_cpu == cpu)
break;
}
return -ENOMEM;
}
