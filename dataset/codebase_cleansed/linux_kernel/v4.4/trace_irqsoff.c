static inline int
preempt_trace(void)
{
return ((trace_type & TRACER_PREEMPT_OFF) && preempt_count());
}
static inline int
irq_trace(void)
{
return ((trace_type & TRACER_IRQS_OFF) &&
irqs_disabled());
}
static inline int irqsoff_display_graph(struct trace_array *tr, int set)
{
return -EINVAL;
}
static int func_prolog_dec(struct trace_array *tr,
struct trace_array_cpu **data,
unsigned long *flags)
{
long disabled;
int cpu;
cpu = raw_smp_processor_id();
if (likely(!per_cpu(tracing_cpu, cpu)))
return 0;
local_save_flags(*flags);
if (!irqs_disabled_flags(*flags))
return 0;
*data = per_cpu_ptr(tr->trace_buffer.data, cpu);
disabled = atomic_inc_return(&(*data)->disabled);
if (likely(disabled == 1))
return 1;
atomic_dec(&(*data)->disabled);
return 0;
}
static void
irqsoff_tracer_call(unsigned long ip, unsigned long parent_ip,
struct ftrace_ops *op, struct pt_regs *pt_regs)
{
struct trace_array *tr = irqsoff_trace;
struct trace_array_cpu *data;
unsigned long flags;
if (!func_prolog_dec(tr, &data, &flags))
return;
trace_function(tr, ip, parent_ip, flags, preempt_count());
atomic_dec(&data->disabled);
}
static int irqsoff_display_graph(struct trace_array *tr, int set)
{
int cpu;
if (!(is_graph(tr) ^ set))
return 0;
stop_irqsoff_tracer(irqsoff_trace, !set);
for_each_possible_cpu(cpu)
per_cpu(tracing_cpu, cpu) = 0;
tr->max_latency = 0;
tracing_reset_online_cpus(&irqsoff_trace->trace_buffer);
return start_irqsoff_tracer(irqsoff_trace, set);
}
static int irqsoff_graph_entry(struct ftrace_graph_ent *trace)
{
struct trace_array *tr = irqsoff_trace;
struct trace_array_cpu *data;
unsigned long flags;
int ret;
int pc;
if (!func_prolog_dec(tr, &data, &flags))
return 0;
pc = preempt_count();
ret = __trace_graph_entry(tr, trace, flags, pc);
atomic_dec(&data->disabled);
return ret;
}
static void irqsoff_graph_return(struct ftrace_graph_ret *trace)
{
struct trace_array *tr = irqsoff_trace;
struct trace_array_cpu *data;
unsigned long flags;
int pc;
if (!func_prolog_dec(tr, &data, &flags))
return;
pc = preempt_count();
__trace_graph_return(tr, trace, flags, pc);
atomic_dec(&data->disabled);
}
static void irqsoff_trace_open(struct trace_iterator *iter)
{
if (is_graph(iter->tr))
graph_trace_open(iter);
}
static void irqsoff_trace_close(struct trace_iterator *iter)
{
if (iter->private)
graph_trace_close(iter);
}
static enum print_line_t irqsoff_print_line(struct trace_iterator *iter)
{
if (is_graph(iter->tr))
return print_graph_function_flags(iter, GRAPH_TRACER_FLAGS);
return TRACE_TYPE_UNHANDLED;
}
static void irqsoff_print_header(struct seq_file *s)
{
struct trace_array *tr = irqsoff_trace;
if (is_graph(tr))
print_graph_headers_flags(s, GRAPH_TRACER_FLAGS);
else
trace_default_header(s);
}
static void
__trace_function(struct trace_array *tr,
unsigned long ip, unsigned long parent_ip,
unsigned long flags, int pc)
{
if (is_graph(tr))
trace_graph_function(tr, ip, parent_ip, flags, pc);
else
trace_function(tr, ip, parent_ip, flags, pc);
}
static int irqsoff_graph_entry(struct ftrace_graph_ent *trace)
{
return -1;
}
static enum print_line_t irqsoff_print_line(struct trace_iterator *iter)
{
return TRACE_TYPE_UNHANDLED;
}
static void irqsoff_trace_open(struct trace_iterator *iter) { }
static void irqsoff_trace_close(struct trace_iterator *iter) { }
static void irqsoff_graph_return(struct ftrace_graph_ret *trace) { }
static void irqsoff_print_header(struct seq_file *s)
{
trace_default_header(s);
}
static void irqsoff_print_header(struct seq_file *s)
{
trace_latency_header(s);
}
static bool report_latency(struct trace_array *tr, cycle_t delta)
{
if (tracing_thresh) {
if (delta < tracing_thresh)
return false;
} else {
if (delta <= tr->max_latency)
return false;
}
return true;
}
static void
check_critical_timing(struct trace_array *tr,
struct trace_array_cpu *data,
unsigned long parent_ip,
int cpu)
{
cycle_t T0, T1, delta;
unsigned long flags;
int pc;
T0 = data->preempt_timestamp;
T1 = ftrace_now(cpu);
delta = T1-T0;
local_save_flags(flags);
pc = preempt_count();
if (!report_latency(tr, delta))
goto out;
raw_spin_lock_irqsave(&max_trace_lock, flags);
if (!report_latency(tr, delta))
goto out_unlock;
__trace_function(tr, CALLER_ADDR0, parent_ip, flags, pc);
__trace_stack(tr, flags, 5, pc);
if (data->critical_sequence != max_sequence)
goto out_unlock;
data->critical_end = parent_ip;
if (likely(!is_tracing_stopped())) {
tr->max_latency = delta;
update_max_tr_single(tr, current, cpu);
}
max_sequence++;
out_unlock:
raw_spin_unlock_irqrestore(&max_trace_lock, flags);
out:
data->critical_sequence = max_sequence;
data->preempt_timestamp = ftrace_now(cpu);
__trace_function(tr, CALLER_ADDR0, parent_ip, flags, pc);
}
static inline void
start_critical_timing(unsigned long ip, unsigned long parent_ip)
{
int cpu;
struct trace_array *tr = irqsoff_trace;
struct trace_array_cpu *data;
unsigned long flags;
if (!tracer_enabled || !tracing_is_enabled())
return;
cpu = raw_smp_processor_id();
if (per_cpu(tracing_cpu, cpu))
return;
data = per_cpu_ptr(tr->trace_buffer.data, cpu);
if (unlikely(!data) || atomic_read(&data->disabled))
return;
atomic_inc(&data->disabled);
data->critical_sequence = max_sequence;
data->preempt_timestamp = ftrace_now(cpu);
data->critical_start = parent_ip ? : ip;
local_save_flags(flags);
__trace_function(tr, ip, parent_ip, flags, preempt_count());
per_cpu(tracing_cpu, cpu) = 1;
atomic_dec(&data->disabled);
}
static inline void
stop_critical_timing(unsigned long ip, unsigned long parent_ip)
{
int cpu;
struct trace_array *tr = irqsoff_trace;
struct trace_array_cpu *data;
unsigned long flags;
cpu = raw_smp_processor_id();
if (unlikely(per_cpu(tracing_cpu, cpu)))
per_cpu(tracing_cpu, cpu) = 0;
else
return;
if (!tracer_enabled || !tracing_is_enabled())
return;
data = per_cpu_ptr(tr->trace_buffer.data, cpu);
if (unlikely(!data) ||
!data->critical_start || atomic_read(&data->disabled))
return;
atomic_inc(&data->disabled);
local_save_flags(flags);
__trace_function(tr, ip, parent_ip, flags, preempt_count());
check_critical_timing(tr, data, parent_ip ? : ip, cpu);
data->critical_start = 0;
atomic_dec(&data->disabled);
}
void start_critical_timings(void)
{
if (preempt_trace() || irq_trace())
start_critical_timing(CALLER_ADDR0, CALLER_ADDR1);
}
void stop_critical_timings(void)
{
if (preempt_trace() || irq_trace())
stop_critical_timing(CALLER_ADDR0, CALLER_ADDR1);
}
void time_hardirqs_on(unsigned long a0, unsigned long a1)
{
if (!preempt_trace() && irq_trace())
stop_critical_timing(a0, a1);
}
void time_hardirqs_off(unsigned long a0, unsigned long a1)
{
if (!preempt_trace() && irq_trace())
start_critical_timing(a0, a1);
}
void trace_softirqs_on(unsigned long ip)
{
}
void trace_softirqs_off(unsigned long ip)
{
}
inline void print_irqtrace_events(struct task_struct *curr)
{
}
void trace_hardirqs_on(void)
{
if (!preempt_trace() && irq_trace())
stop_critical_timing(CALLER_ADDR0, CALLER_ADDR1);
}
void trace_hardirqs_off(void)
{
if (!preempt_trace() && irq_trace())
start_critical_timing(CALLER_ADDR0, CALLER_ADDR1);
}
__visible void trace_hardirqs_on_caller(unsigned long caller_addr)
{
if (!preempt_trace() && irq_trace())
stop_critical_timing(CALLER_ADDR0, caller_addr);
}
__visible void trace_hardirqs_off_caller(unsigned long caller_addr)
{
if (!preempt_trace() && irq_trace())
start_critical_timing(CALLER_ADDR0, caller_addr);
}
void trace_preempt_on(unsigned long a0, unsigned long a1)
{
if (preempt_trace() && !irq_trace())
stop_critical_timing(a0, a1);
}
void trace_preempt_off(unsigned long a0, unsigned long a1)
{
if (preempt_trace() && !irq_trace())
start_critical_timing(a0, a1);
}
static int register_irqsoff_function(struct trace_array *tr, int graph, int set)
{
int ret;
if (function_enabled || (!set && !(tr->trace_flags & TRACE_ITER_FUNCTION)))
return 0;
if (graph)
ret = register_ftrace_graph(&irqsoff_graph_return,
&irqsoff_graph_entry);
else
ret = register_ftrace_function(tr->ops);
if (!ret)
function_enabled = true;
return ret;
}
static void unregister_irqsoff_function(struct trace_array *tr, int graph)
{
if (!function_enabled)
return;
if (graph)
unregister_ftrace_graph();
else
unregister_ftrace_function(tr->ops);
function_enabled = false;
}
static int irqsoff_function_set(struct trace_array *tr, u32 mask, int set)
{
if (!(mask & TRACE_ITER_FUNCTION))
return 0;
if (set)
register_irqsoff_function(tr, is_graph(tr), 1);
else
unregister_irqsoff_function(tr, is_graph(tr));
return 1;
}
static int register_irqsoff_function(struct trace_array *tr, int graph, int set)
{
return 0;
}
static void unregister_irqsoff_function(struct trace_array *tr, int graph) { }
static inline int irqsoff_function_set(struct trace_array *tr, u32 mask, int set)
{
return 0;
}
static int irqsoff_flag_changed(struct trace_array *tr, u32 mask, int set)
{
struct tracer *tracer = tr->current_trace;
if (irqsoff_function_set(tr, mask, set))
return 0;
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
if (mask & TRACE_ITER_DISPLAY_GRAPH)
return irqsoff_display_graph(tr, set);
#endif
return trace_keep_overwrite(tracer, mask, set);
}
static int start_irqsoff_tracer(struct trace_array *tr, int graph)
{
int ret;
ret = register_irqsoff_function(tr, graph, 0);
if (!ret && tracing_is_enabled())
tracer_enabled = 1;
else
tracer_enabled = 0;
return ret;
}
static void stop_irqsoff_tracer(struct trace_array *tr, int graph)
{
tracer_enabled = 0;
unregister_irqsoff_function(tr, graph);
}
static int __irqsoff_tracer_init(struct trace_array *tr)
{
if (irqsoff_busy)
return -EBUSY;
save_flags = tr->trace_flags;
set_tracer_flag(tr, TRACE_ITER_OVERWRITE, 1);
set_tracer_flag(tr, TRACE_ITER_LATENCY_FMT, 1);
tr->max_latency = 0;
irqsoff_trace = tr;
smp_wmb();
tracing_reset_online_cpus(&tr->trace_buffer);
ftrace_init_array_ops(tr, irqsoff_tracer_call);
if (start_irqsoff_tracer(tr, (tr->flags & TRACE_ARRAY_FL_GLOBAL &&
is_graph(tr))))
printk(KERN_ERR "failed to start irqsoff tracer\n");
irqsoff_busy = true;
return 0;
}
static void irqsoff_tracer_reset(struct trace_array *tr)
{
int lat_flag = save_flags & TRACE_ITER_LATENCY_FMT;
int overwrite_flag = save_flags & TRACE_ITER_OVERWRITE;
stop_irqsoff_tracer(tr, is_graph(tr));
set_tracer_flag(tr, TRACE_ITER_LATENCY_FMT, lat_flag);
set_tracer_flag(tr, TRACE_ITER_OVERWRITE, overwrite_flag);
ftrace_reset_array_ops(tr);
irqsoff_busy = false;
}
static void irqsoff_tracer_start(struct trace_array *tr)
{
tracer_enabled = 1;
}
static void irqsoff_tracer_stop(struct trace_array *tr)
{
tracer_enabled = 0;
}
static int irqsoff_tracer_init(struct trace_array *tr)
{
trace_type = TRACER_IRQS_OFF;
return __irqsoff_tracer_init(tr);
}
static int preemptoff_tracer_init(struct trace_array *tr)
{
trace_type = TRACER_PREEMPT_OFF;
return __irqsoff_tracer_init(tr);
}
static int preemptirqsoff_tracer_init(struct trace_array *tr)
{
trace_type = TRACER_IRQS_OFF | TRACER_PREEMPT_OFF;
return __irqsoff_tracer_init(tr);
}
__init static int init_irqsoff_tracer(void)
{
register_irqsoff(irqsoff_tracer);
register_preemptoff(preemptoff_tracer);
register_preemptirqsoff(preemptirqsoff_tracer);
return 0;
}
