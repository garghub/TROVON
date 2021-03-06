static int perf_trace_event_perm(struct ftrace_event_call *tp_event,
struct perf_event *p_event)
{
if (!(p_event->attr.sample_type & PERF_SAMPLE_RAW))
return 0;
if (p_event->attach_state == PERF_ATTACH_TASK) {
if (tp_event->flags & TRACE_EVENT_FL_CAP_ANY)
return 0;
}
if (perf_paranoid_tracepoint_raw() && !capable(CAP_SYS_ADMIN))
return -EPERM;
return 0;
}
static int perf_trace_event_init(struct ftrace_event_call *tp_event,
struct perf_event *p_event)
{
struct hlist_head __percpu *list;
int ret;
int cpu;
ret = perf_trace_event_perm(tp_event, p_event);
if (ret)
return ret;
p_event->tp_event = tp_event;
if (tp_event->perf_refcount++ > 0)
return 0;
ret = -ENOMEM;
list = alloc_percpu(struct hlist_head);
if (!list)
goto fail;
for_each_possible_cpu(cpu)
INIT_HLIST_HEAD(per_cpu_ptr(list, cpu));
tp_event->perf_events = list;
if (!total_ref_count) {
char __percpu *buf;
int i;
for (i = 0; i < PERF_NR_CONTEXTS; i++) {
buf = (char __percpu *)alloc_percpu(perf_trace_t);
if (!buf)
goto fail;
perf_trace_buf[i] = buf;
}
}
ret = tp_event->class->reg(tp_event, TRACE_REG_PERF_REGISTER);
if (ret)
goto fail;
total_ref_count++;
return 0;
fail:
if (!total_ref_count) {
int i;
for (i = 0; i < PERF_NR_CONTEXTS; i++) {
free_percpu(perf_trace_buf[i]);
perf_trace_buf[i] = NULL;
}
}
if (!--tp_event->perf_refcount) {
free_percpu(tp_event->perf_events);
tp_event->perf_events = NULL;
}
return ret;
}
int perf_trace_init(struct perf_event *p_event)
{
struct ftrace_event_call *tp_event;
int event_id = p_event->attr.config;
int ret = -EINVAL;
mutex_lock(&event_mutex);
list_for_each_entry(tp_event, &ftrace_events, list) {
if (tp_event->event.type == event_id &&
tp_event->class && tp_event->class->reg &&
try_module_get(tp_event->mod)) {
ret = perf_trace_event_init(tp_event, p_event);
if (ret)
module_put(tp_event->mod);
break;
}
}
mutex_unlock(&event_mutex);
return ret;
}
int perf_trace_add(struct perf_event *p_event, int flags)
{
struct ftrace_event_call *tp_event = p_event->tp_event;
struct hlist_head __percpu *pcpu_list;
struct hlist_head *list;
pcpu_list = tp_event->perf_events;
if (WARN_ON_ONCE(!pcpu_list))
return -EINVAL;
if (!(flags & PERF_EF_START))
p_event->hw.state = PERF_HES_STOPPED;
list = this_cpu_ptr(pcpu_list);
hlist_add_head_rcu(&p_event->hlist_entry, list);
return 0;
}
void perf_trace_del(struct perf_event *p_event, int flags)
{
hlist_del_rcu(&p_event->hlist_entry);
}
void perf_trace_destroy(struct perf_event *p_event)
{
struct ftrace_event_call *tp_event = p_event->tp_event;
int i;
mutex_lock(&event_mutex);
if (--tp_event->perf_refcount > 0)
goto out;
tp_event->class->reg(tp_event, TRACE_REG_PERF_UNREGISTER);
tracepoint_synchronize_unregister();
free_percpu(tp_event->perf_events);
tp_event->perf_events = NULL;
if (!--total_ref_count) {
for (i = 0; i < PERF_NR_CONTEXTS; i++) {
free_percpu(perf_trace_buf[i]);
perf_trace_buf[i] = NULL;
}
}
out:
module_put(tp_event->mod);
mutex_unlock(&event_mutex);
}
__kprobes void *perf_trace_buf_prepare(int size, unsigned short type,
struct pt_regs *regs, int *rctxp)
{
struct trace_entry *entry;
unsigned long flags;
char *raw_data;
int pc;
BUILD_BUG_ON(PERF_MAX_TRACE_SIZE % sizeof(unsigned long));
pc = preempt_count();
*rctxp = perf_swevent_get_recursion_context();
if (*rctxp < 0)
return NULL;
raw_data = this_cpu_ptr(perf_trace_buf[*rctxp]);
memset(&raw_data[size - sizeof(u64)], 0, sizeof(u64));
entry = (struct trace_entry *)raw_data;
local_save_flags(flags);
tracing_generic_entry_update(entry, flags, pc);
entry->type = type;
return raw_data;
}
