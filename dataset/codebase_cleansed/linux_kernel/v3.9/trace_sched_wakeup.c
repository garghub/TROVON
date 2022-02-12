static int
func_prolog_preempt_disable(struct trace_array *tr,
struct trace_array_cpu **data,
int *pc)
{
long disabled;
int cpu;
if (likely(!wakeup_task))
return 0;
*pc = preempt_count();
preempt_disable_notrace();
cpu = raw_smp_processor_id();
if (cpu != wakeup_current_cpu)
goto out_enable;
*data = tr->data[cpu];
disabled = atomic_inc_return(&(*data)->disabled);
if (unlikely(disabled != 1))
goto out;
return 1;
out:
atomic_dec(&(*data)->disabled);
out_enable:
preempt_enable_notrace();
return 0;
}
static void
wakeup_tracer_call(unsigned long ip, unsigned long parent_ip,
struct ftrace_ops *op, struct pt_regs *pt_regs)
{
struct trace_array *tr = wakeup_trace;
struct trace_array_cpu *data;
unsigned long flags;
int pc;
if (!func_prolog_preempt_disable(tr, &data, &pc))
return;
local_irq_save(flags);
trace_function(tr, ip, parent_ip, flags, pc);
local_irq_restore(flags);
atomic_dec(&data->disabled);
preempt_enable_notrace();
}
static int start_func_tracer(int graph)
{
int ret;
if (!graph)
ret = register_ftrace_function(&trace_ops);
else
ret = register_ftrace_graph(&wakeup_graph_return,
&wakeup_graph_entry);
if (!ret && tracing_is_enabled())
tracer_enabled = 1;
else
tracer_enabled = 0;
return ret;
}
static void stop_func_tracer(int graph)
{
tracer_enabled = 0;
if (!graph)
unregister_ftrace_function(&trace_ops);
else
unregister_ftrace_graph();
}
static int wakeup_set_flag(u32 old_flags, u32 bit, int set)
{
if (!(bit & TRACE_DISPLAY_GRAPH))
return -EINVAL;
if (!(is_graph() ^ set))
return 0;
stop_func_tracer(!set);
wakeup_reset(wakeup_trace);
tracing_max_latency = 0;
return start_func_tracer(set);
}
static int wakeup_graph_entry(struct ftrace_graph_ent *trace)
{
struct trace_array *tr = wakeup_trace;
struct trace_array_cpu *data;
unsigned long flags;
int pc, ret = 0;
if (!func_prolog_preempt_disable(tr, &data, &pc))
return 0;
local_save_flags(flags);
ret = __trace_graph_entry(tr, trace, flags, pc);
atomic_dec(&data->disabled);
preempt_enable_notrace();
return ret;
}
static void wakeup_graph_return(struct ftrace_graph_ret *trace)
{
struct trace_array *tr = wakeup_trace;
struct trace_array_cpu *data;
unsigned long flags;
int pc;
if (!func_prolog_preempt_disable(tr, &data, &pc))
return;
local_save_flags(flags);
__trace_graph_return(tr, trace, flags, pc);
atomic_dec(&data->disabled);
preempt_enable_notrace();
return;
}
static void wakeup_trace_open(struct trace_iterator *iter)
{
if (is_graph())
graph_trace_open(iter);
}
static void wakeup_trace_close(struct trace_iterator *iter)
{
if (iter->private)
graph_trace_close(iter);
}
static enum print_line_t wakeup_print_line(struct trace_iterator *iter)
{
if (is_graph())
return print_graph_function_flags(iter, GRAPH_TRACER_FLAGS);
return TRACE_TYPE_UNHANDLED;
}
static void wakeup_print_header(struct seq_file *s)
{
if (is_graph())
print_graph_headers_flags(s, GRAPH_TRACER_FLAGS);
else
trace_default_header(s);
}
static void
__trace_function(struct trace_array *tr,
unsigned long ip, unsigned long parent_ip,
unsigned long flags, int pc)
{
if (is_graph())
trace_graph_function(tr, ip, parent_ip, flags, pc);
else
trace_function(tr, ip, parent_ip, flags, pc);
}
static int wakeup_set_flag(u32 old_flags, u32 bit, int set)
{
return -EINVAL;
}
static int wakeup_graph_entry(struct ftrace_graph_ent *trace)
{
return -1;
}
static enum print_line_t wakeup_print_line(struct trace_iterator *iter)
{
return TRACE_TYPE_UNHANDLED;
}
static void wakeup_graph_return(struct ftrace_graph_ret *trace) { }
static void wakeup_trace_open(struct trace_iterator *iter) { }
static void wakeup_trace_close(struct trace_iterator *iter) { }
static void wakeup_print_header(struct seq_file *s)
{
trace_default_header(s);
}
static void wakeup_print_header(struct seq_file *s)
{
trace_latency_header(s);
}
static int report_latency(cycle_t delta)
{
if (tracing_thresh) {
if (delta < tracing_thresh)
return 0;
} else {
if (delta <= tracing_max_latency)
return 0;
}
return 1;
}
static void
probe_wakeup_migrate_task(void *ignore, struct task_struct *task, int cpu)
{
if (task != wakeup_task)
return;
wakeup_current_cpu = cpu;
}
static void notrace
probe_wakeup_sched_switch(void *ignore,
struct task_struct *prev, struct task_struct *next)
{
struct trace_array_cpu *data;
cycle_t T0, T1, delta;
unsigned long flags;
long disabled;
int cpu;
int pc;
tracing_record_cmdline(prev);
if (unlikely(!tracer_enabled))
return;
smp_rmb();
if (next != wakeup_task)
return;
pc = preempt_count();
cpu = raw_smp_processor_id();
disabled = atomic_inc_return(&wakeup_trace->data[cpu]->disabled);
if (likely(disabled != 1))
goto out;
local_irq_save(flags);
arch_spin_lock(&wakeup_lock);
if (unlikely(!tracer_enabled || next != wakeup_task))
goto out_unlock;
data = wakeup_trace->data[wakeup_cpu];
__trace_function(wakeup_trace, CALLER_ADDR0, CALLER_ADDR1, flags, pc);
tracing_sched_switch_trace(wakeup_trace, prev, next, flags, pc);
T0 = data->preempt_timestamp;
T1 = ftrace_now(cpu);
delta = T1-T0;
if (!report_latency(delta))
goto out_unlock;
if (likely(!is_tracing_stopped())) {
tracing_max_latency = delta;
update_max_tr(wakeup_trace, wakeup_task, wakeup_cpu);
}
out_unlock:
__wakeup_reset(wakeup_trace);
arch_spin_unlock(&wakeup_lock);
local_irq_restore(flags);
out:
atomic_dec(&wakeup_trace->data[cpu]->disabled);
}
static void __wakeup_reset(struct trace_array *tr)
{
wakeup_cpu = -1;
wakeup_prio = -1;
if (wakeup_task)
put_task_struct(wakeup_task);
wakeup_task = NULL;
}
static void wakeup_reset(struct trace_array *tr)
{
unsigned long flags;
tracing_reset_online_cpus(tr);
local_irq_save(flags);
arch_spin_lock(&wakeup_lock);
__wakeup_reset(tr);
arch_spin_unlock(&wakeup_lock);
local_irq_restore(flags);
}
static void
probe_wakeup(void *ignore, struct task_struct *p, int success)
{
struct trace_array_cpu *data;
int cpu = smp_processor_id();
unsigned long flags;
long disabled;
int pc;
if (likely(!tracer_enabled))
return;
tracing_record_cmdline(p);
tracing_record_cmdline(current);
if ((wakeup_rt && !rt_task(p)) ||
p->prio >= wakeup_prio ||
p->prio >= current->prio)
return;
pc = preempt_count();
disabled = atomic_inc_return(&wakeup_trace->data[cpu]->disabled);
if (unlikely(disabled != 1))
goto out;
arch_spin_lock(&wakeup_lock);
if (!tracer_enabled || p->prio >= wakeup_prio)
goto out_locked;
__wakeup_reset(wakeup_trace);
wakeup_cpu = task_cpu(p);
wakeup_current_cpu = wakeup_cpu;
wakeup_prio = p->prio;
wakeup_task = p;
get_task_struct(wakeup_task);
local_save_flags(flags);
data = wakeup_trace->data[wakeup_cpu];
data->preempt_timestamp = ftrace_now(cpu);
tracing_sched_wakeup_trace(wakeup_trace, p, current, flags, pc);
__trace_function(wakeup_trace, CALLER_ADDR1, CALLER_ADDR2, flags, pc);
out_locked:
arch_spin_unlock(&wakeup_lock);
out:
atomic_dec(&wakeup_trace->data[cpu]->disabled);
}
static void start_wakeup_tracer(struct trace_array *tr)
{
int ret;
ret = register_trace_sched_wakeup(probe_wakeup, NULL);
if (ret) {
pr_info("wakeup trace: Couldn't activate tracepoint"
" probe to kernel_sched_wakeup\n");
return;
}
ret = register_trace_sched_wakeup_new(probe_wakeup, NULL);
if (ret) {
pr_info("wakeup trace: Couldn't activate tracepoint"
" probe to kernel_sched_wakeup_new\n");
goto fail_deprobe;
}
ret = register_trace_sched_switch(probe_wakeup_sched_switch, NULL);
if (ret) {
pr_info("sched trace: Couldn't activate tracepoint"
" probe to kernel_sched_switch\n");
goto fail_deprobe_wake_new;
}
ret = register_trace_sched_migrate_task(probe_wakeup_migrate_task, NULL);
if (ret) {
pr_info("wakeup trace: Couldn't activate tracepoint"
" probe to kernel_sched_migrate_task\n");
return;
}
wakeup_reset(tr);
smp_wmb();
if (start_func_tracer(is_graph()))
printk(KERN_ERR "failed to start wakeup tracer\n");
return;
fail_deprobe_wake_new:
unregister_trace_sched_wakeup_new(probe_wakeup, NULL);
fail_deprobe:
unregister_trace_sched_wakeup(probe_wakeup, NULL);
}
static void stop_wakeup_tracer(struct trace_array *tr)
{
tracer_enabled = 0;
stop_func_tracer(is_graph());
unregister_trace_sched_switch(probe_wakeup_sched_switch, NULL);
unregister_trace_sched_wakeup_new(probe_wakeup, NULL);
unregister_trace_sched_wakeup(probe_wakeup, NULL);
unregister_trace_sched_migrate_task(probe_wakeup_migrate_task, NULL);
}
static int __wakeup_tracer_init(struct trace_array *tr)
{
save_flags = trace_flags;
set_tracer_flag(TRACE_ITER_OVERWRITE, 1);
set_tracer_flag(TRACE_ITER_LATENCY_FMT, 1);
tracing_max_latency = 0;
wakeup_trace = tr;
start_wakeup_tracer(tr);
return 0;
}
static int wakeup_tracer_init(struct trace_array *tr)
{
wakeup_rt = 0;
return __wakeup_tracer_init(tr);
}
static int wakeup_rt_tracer_init(struct trace_array *tr)
{
wakeup_rt = 1;
return __wakeup_tracer_init(tr);
}
static void wakeup_tracer_reset(struct trace_array *tr)
{
int lat_flag = save_flags & TRACE_ITER_LATENCY_FMT;
int overwrite_flag = save_flags & TRACE_ITER_OVERWRITE;
stop_wakeup_tracer(tr);
wakeup_reset(tr);
set_tracer_flag(TRACE_ITER_LATENCY_FMT, lat_flag);
set_tracer_flag(TRACE_ITER_OVERWRITE, overwrite_flag);
}
static void wakeup_tracer_start(struct trace_array *tr)
{
wakeup_reset(tr);
tracer_enabled = 1;
}
static void wakeup_tracer_stop(struct trace_array *tr)
{
tracer_enabled = 0;
}
__init static int init_wakeup_tracer(void)
{
int ret;
ret = register_tracer(&wakeup_tracer);
if (ret)
return ret;
ret = register_tracer(&wakeup_rt_tracer);
if (ret)
return ret;
return 0;
}
