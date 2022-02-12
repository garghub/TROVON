bool ftrace_graph_is_dead(void)
{
return kill_ftrace_graph;
}
void ftrace_graph_stop(void)
{
kill_ftrace_graph = true;
}
int
ftrace_push_return_trace(unsigned long ret, unsigned long func, int *depth,
unsigned long frame_pointer, unsigned long *retp)
{
unsigned long long calltime;
int index;
if (unlikely(ftrace_graph_is_dead()))
return -EBUSY;
if (!current->ret_stack)
return -EBUSY;
smp_rmb();
if (current->curr_ret_stack == FTRACE_RETFUNC_DEPTH - 1) {
atomic_inc(&current->trace_overrun);
return -EBUSY;
}
if (current->curr_ret_stack < -1)
return -EBUSY;
calltime = trace_clock_local();
index = ++current->curr_ret_stack;
if (ftrace_graph_notrace_addr(func))
current->curr_ret_stack -= FTRACE_NOTRACE_DEPTH;
barrier();
current->ret_stack[index].ret = ret;
current->ret_stack[index].func = func;
current->ret_stack[index].calltime = calltime;
#ifdef HAVE_FUNCTION_GRAPH_FP_TEST
current->ret_stack[index].fp = frame_pointer;
#endif
#ifdef HAVE_FUNCTION_GRAPH_RET_ADDR_PTR
current->ret_stack[index].retp = retp;
#endif
*depth = current->curr_ret_stack;
return 0;
}
static void
ftrace_pop_return_trace(struct ftrace_graph_ret *trace, unsigned long *ret,
unsigned long frame_pointer)
{
int index;
index = current->curr_ret_stack;
if (index < 0)
index += FTRACE_NOTRACE_DEPTH;
if (unlikely(index < 0 || index >= FTRACE_RETFUNC_DEPTH)) {
ftrace_graph_stop();
WARN_ON(1);
*ret = (unsigned long)panic;
return;
}
#ifdef HAVE_FUNCTION_GRAPH_FP_TEST
if (unlikely(current->ret_stack[index].fp != frame_pointer)) {
ftrace_graph_stop();
WARN(1, "Bad frame pointer: expected %lx, received %lx\n"
" from func %ps return to %lx\n",
current->ret_stack[index].fp,
frame_pointer,
(void *)current->ret_stack[index].func,
current->ret_stack[index].ret);
*ret = (unsigned long)panic;
return;
}
#endif
*ret = current->ret_stack[index].ret;
trace->func = current->ret_stack[index].func;
trace->calltime = current->ret_stack[index].calltime;
trace->overrun = atomic_read(&current->trace_overrun);
trace->depth = index;
}
unsigned long ftrace_return_to_handler(unsigned long frame_pointer)
{
struct ftrace_graph_ret trace;
unsigned long ret;
ftrace_pop_return_trace(&trace, &ret, frame_pointer);
trace.rettime = trace_clock_local();
barrier();
current->curr_ret_stack--;
if (current->curr_ret_stack < -1) {
current->curr_ret_stack += FTRACE_NOTRACE_DEPTH;
return ret;
}
ftrace_graph_return(&trace);
if (unlikely(!ret)) {
ftrace_graph_stop();
WARN_ON(1);
ret = (unsigned long)panic;
}
return ret;
}
unsigned long ftrace_graph_ret_addr(struct task_struct *task, int *idx,
unsigned long ret, unsigned long *retp)
{
int index = task->curr_ret_stack;
int i;
if (ret != (unsigned long)return_to_handler)
return ret;
if (index < -1)
index += FTRACE_NOTRACE_DEPTH;
if (index < 0)
return ret;
for (i = 0; i <= index; i++)
if (task->ret_stack[i].retp == retp)
return task->ret_stack[i].ret;
return ret;
}
unsigned long ftrace_graph_ret_addr(struct task_struct *task, int *idx,
unsigned long ret, unsigned long *retp)
{
int task_idx;
if (ret != (unsigned long)return_to_handler)
return ret;
task_idx = task->curr_ret_stack;
if (!task->ret_stack || task_idx < *idx)
return ret;
task_idx -= *idx;
(*idx)++;
return task->ret_stack[task_idx].ret;
}
int __trace_graph_entry(struct trace_array *tr,
struct ftrace_graph_ent *trace,
unsigned long flags,
int pc)
{
struct trace_event_call *call = &event_funcgraph_entry;
struct ring_buffer_event *event;
struct ring_buffer *buffer = tr->trace_buffer.buffer;
struct ftrace_graph_ent_entry *entry;
event = trace_buffer_lock_reserve(buffer, TRACE_GRAPH_ENT,
sizeof(*entry), flags, pc);
if (!event)
return 0;
entry = ring_buffer_event_data(event);
entry->graph_ent = *trace;
if (!call_filter_check_discard(call, entry, buffer, event))
__buffer_unlock_commit(buffer, event);
return 1;
}
static inline int ftrace_graph_ignore_irqs(void)
{
if (!ftrace_graph_skip_irqs || trace_recursion_test(TRACE_IRQ_BIT))
return 0;
return in_irq();
}
int trace_graph_entry(struct ftrace_graph_ent *trace)
{
struct trace_array *tr = graph_array;
struct trace_array_cpu *data;
unsigned long flags;
long disabled;
int ret;
int cpu;
int pc;
if (!ftrace_trace_task(tr))
return 0;
if ((!(trace->depth || ftrace_graph_addr(trace->func)) ||
ftrace_graph_ignore_irqs()) || (trace->depth < 0) ||
(max_depth && trace->depth >= max_depth))
return 0;
if (ftrace_graph_notrace_addr(trace->func))
return 1;
if (tracing_thresh)
return 1;
local_irq_save(flags);
cpu = raw_smp_processor_id();
data = per_cpu_ptr(tr->trace_buffer.data, cpu);
disabled = atomic_inc_return(&data->disabled);
if (likely(disabled == 1)) {
pc = preempt_count();
ret = __trace_graph_entry(tr, trace, flags, pc);
} else {
ret = 0;
}
atomic_dec(&data->disabled);
local_irq_restore(flags);
return ret;
}
static void
__trace_graph_function(struct trace_array *tr,
unsigned long ip, unsigned long flags, int pc)
{
u64 time = trace_clock_local();
struct ftrace_graph_ent ent = {
.func = ip,
.depth = 0,
};
struct ftrace_graph_ret ret = {
.func = ip,
.depth = 0,
.calltime = time,
.rettime = time,
};
__trace_graph_entry(tr, &ent, flags, pc);
__trace_graph_return(tr, &ret, flags, pc);
}
void
trace_graph_function(struct trace_array *tr,
unsigned long ip, unsigned long parent_ip,
unsigned long flags, int pc)
{
__trace_graph_function(tr, ip, flags, pc);
}
void __trace_graph_return(struct trace_array *tr,
struct ftrace_graph_ret *trace,
unsigned long flags,
int pc)
{
struct trace_event_call *call = &event_funcgraph_exit;
struct ring_buffer_event *event;
struct ring_buffer *buffer = tr->trace_buffer.buffer;
struct ftrace_graph_ret_entry *entry;
event = trace_buffer_lock_reserve(buffer, TRACE_GRAPH_RET,
sizeof(*entry), flags, pc);
if (!event)
return;
entry = ring_buffer_event_data(event);
entry->ret = *trace;
if (!call_filter_check_discard(call, entry, buffer, event))
__buffer_unlock_commit(buffer, event);
}
void trace_graph_return(struct ftrace_graph_ret *trace)
{
struct trace_array *tr = graph_array;
struct trace_array_cpu *data;
unsigned long flags;
long disabled;
int cpu;
int pc;
local_irq_save(flags);
cpu = raw_smp_processor_id();
data = per_cpu_ptr(tr->trace_buffer.data, cpu);
disabled = atomic_inc_return(&data->disabled);
if (likely(disabled == 1)) {
pc = preempt_count();
__trace_graph_return(tr, trace, flags, pc);
}
atomic_dec(&data->disabled);
local_irq_restore(flags);
}
void set_graph_array(struct trace_array *tr)
{
graph_array = tr;
smp_mb();
}
static void trace_graph_thresh_return(struct ftrace_graph_ret *trace)
{
if (tracing_thresh &&
(trace->rettime - trace->calltime < tracing_thresh))
return;
else
trace_graph_return(trace);
}
static int graph_trace_init(struct trace_array *tr)
{
int ret;
set_graph_array(tr);
if (tracing_thresh)
ret = register_ftrace_graph(&trace_graph_thresh_return,
&trace_graph_entry);
else
ret = register_ftrace_graph(&trace_graph_return,
&trace_graph_entry);
if (ret)
return ret;
tracing_start_cmdline_record();
return 0;
}
static void graph_trace_reset(struct trace_array *tr)
{
tracing_stop_cmdline_record();
unregister_ftrace_graph();
}
static int graph_trace_update_thresh(struct trace_array *tr)
{
graph_trace_reset(tr);
return graph_trace_init(tr);
}
static void print_graph_cpu(struct trace_seq *s, int cpu)
{
trace_seq_printf(s, " %*d) ", max_bytes_for_cpu, cpu);
}
static void print_graph_proc(struct trace_seq *s, pid_t pid)
{
char comm[TASK_COMM_LEN];
char pid_str[11];
int spaces = 0;
int len;
int i;
trace_find_cmdline(pid, comm);
comm[7] = '\0';
sprintf(pid_str, "%d", pid);
len = strlen(comm) + strlen(pid_str) + 1;
if (len < TRACE_GRAPH_PROCINFO_LENGTH)
spaces = TRACE_GRAPH_PROCINFO_LENGTH - len;
for (i = 0; i < spaces / 2; i++)
trace_seq_putc(s, ' ');
trace_seq_printf(s, "%s-%s", comm, pid_str);
for (i = 0; i < spaces - (spaces / 2); i++)
trace_seq_putc(s, ' ');
}
static void print_graph_lat_fmt(struct trace_seq *s, struct trace_entry *entry)
{
trace_seq_putc(s, ' ');
trace_print_lat_fmt(s, entry);
}
static void
verif_pid(struct trace_seq *s, pid_t pid, int cpu, struct fgraph_data *data)
{
pid_t prev_pid;
pid_t *last_pid;
if (!data)
return;
last_pid = &(per_cpu_ptr(data->cpu_data, cpu)->last_pid);
if (*last_pid == pid)
return;
prev_pid = *last_pid;
*last_pid = pid;
if (prev_pid == -1)
return;
trace_seq_puts(s, " ------------------------------------------\n");
print_graph_cpu(s, cpu);
print_graph_proc(s, prev_pid);
trace_seq_puts(s, " => ");
print_graph_proc(s, pid);
trace_seq_puts(s, "\n ------------------------------------------\n\n");
}
static struct ftrace_graph_ret_entry *
get_return_for_leaf(struct trace_iterator *iter,
struct ftrace_graph_ent_entry *curr)
{
struct fgraph_data *data = iter->private;
struct ring_buffer_iter *ring_iter = NULL;
struct ring_buffer_event *event;
struct ftrace_graph_ret_entry *next;
if (data && data->failed) {
curr = &data->ent;
next = &data->ret;
} else {
ring_iter = trace_buffer_iter(iter, iter->cpu);
if (ring_iter)
event = ring_buffer_iter_peek(ring_iter, NULL);
else {
ring_buffer_consume(iter->trace_buffer->buffer, iter->cpu,
NULL, NULL);
event = ring_buffer_peek(iter->trace_buffer->buffer, iter->cpu,
NULL, NULL);
}
if (!event)
return NULL;
next = ring_buffer_event_data(event);
if (data) {
data->ent = *curr;
if (next->ent.type == TRACE_GRAPH_RET)
data->ret = *next;
else
data->ret.ent.type = next->ent.type;
}
}
if (next->ent.type != TRACE_GRAPH_RET)
return NULL;
if (curr->ent.pid != next->ent.pid ||
curr->graph_ent.func != next->ret.func)
return NULL;
if (ring_iter)
ring_buffer_read(ring_iter, NULL);
return next;
}
static void print_graph_abs_time(u64 t, struct trace_seq *s)
{
unsigned long usecs_rem;
usecs_rem = do_div(t, NSEC_PER_SEC);
usecs_rem /= 1000;
trace_seq_printf(s, "%5lu.%06lu | ",
(unsigned long)t, usecs_rem);
}
static void
print_graph_irq(struct trace_iterator *iter, unsigned long addr,
enum trace_type type, int cpu, pid_t pid, u32 flags)
{
struct trace_array *tr = iter->tr;
struct trace_seq *s = &iter->seq;
struct trace_entry *ent = iter->ent;
if (addr < (unsigned long)__irqentry_text_start ||
addr >= (unsigned long)__irqentry_text_end)
return;
if (tr->trace_flags & TRACE_ITER_CONTEXT_INFO) {
if (flags & TRACE_GRAPH_PRINT_ABS_TIME)
print_graph_abs_time(iter->ts, s);
if (flags & TRACE_GRAPH_PRINT_CPU)
print_graph_cpu(s, cpu);
if (flags & TRACE_GRAPH_PRINT_PROC) {
print_graph_proc(s, pid);
trace_seq_puts(s, " | ");
}
if (tr->trace_flags & TRACE_ITER_LATENCY_FMT)
print_graph_lat_fmt(s, ent);
}
print_graph_duration(tr, 0, s, flags | FLAGS_FILL_START);
if (type == TRACE_GRAPH_ENT)
trace_seq_puts(s, "==========>");
else
trace_seq_puts(s, "<==========");
print_graph_duration(tr, 0, s, flags | FLAGS_FILL_END);
trace_seq_putc(s, '\n');
}
void
trace_print_graph_duration(unsigned long long duration, struct trace_seq *s)
{
unsigned long nsecs_rem = do_div(duration, 1000);
char usecs_str[21];
char nsecs_str[5];
int len;
int i;
sprintf(usecs_str, "%lu", (unsigned long) duration);
trace_seq_printf(s, "%s", usecs_str);
len = strlen(usecs_str);
if (len < 7) {
size_t slen = min_t(size_t, sizeof(nsecs_str), 8UL - len);
snprintf(nsecs_str, slen, "%03lu", nsecs_rem);
trace_seq_printf(s, ".%s", nsecs_str);
len += strlen(nsecs_str) + 1;
}
trace_seq_puts(s, " us ");
for (i = len; i < 8; i++)
trace_seq_putc(s, ' ');
}
static void
print_graph_duration(struct trace_array *tr, unsigned long long duration,
struct trace_seq *s, u32 flags)
{
if (!(flags & TRACE_GRAPH_PRINT_DURATION) ||
!(tr->trace_flags & TRACE_ITER_CONTEXT_INFO))
return;
switch (flags & TRACE_GRAPH_PRINT_FILL_MASK) {
case FLAGS_FILL_FULL:
trace_seq_puts(s, " | ");
return;
case FLAGS_FILL_START:
trace_seq_puts(s, " ");
return;
case FLAGS_FILL_END:
trace_seq_puts(s, " |");
return;
}
if (flags & TRACE_GRAPH_PRINT_OVERHEAD)
trace_seq_printf(s, "%c ", trace_find_mark(duration));
else
trace_seq_puts(s, " ");
trace_print_graph_duration(duration, s);
trace_seq_puts(s, "| ");
}
static enum print_line_t
print_graph_entry_leaf(struct trace_iterator *iter,
struct ftrace_graph_ent_entry *entry,
struct ftrace_graph_ret_entry *ret_entry,
struct trace_seq *s, u32 flags)
{
struct fgraph_data *data = iter->private;
struct trace_array *tr = iter->tr;
struct ftrace_graph_ret *graph_ret;
struct ftrace_graph_ent *call;
unsigned long long duration;
int i;
graph_ret = &ret_entry->ret;
call = &entry->graph_ent;
duration = graph_ret->rettime - graph_ret->calltime;
if (data) {
struct fgraph_cpu_data *cpu_data;
int cpu = iter->cpu;
cpu_data = per_cpu_ptr(data->cpu_data, cpu);
cpu_data->depth = call->depth - 1;
if (call->depth < FTRACE_RETFUNC_DEPTH)
cpu_data->enter_funcs[call->depth] = 0;
}
print_graph_duration(tr, duration, s, flags);
for (i = 0; i < call->depth * TRACE_GRAPH_INDENT; i++)
trace_seq_putc(s, ' ');
trace_seq_printf(s, "%ps();\n", (void *)call->func);
return trace_handle_return(s);
}
static enum print_line_t
print_graph_entry_nested(struct trace_iterator *iter,
struct ftrace_graph_ent_entry *entry,
struct trace_seq *s, int cpu, u32 flags)
{
struct ftrace_graph_ent *call = &entry->graph_ent;
struct fgraph_data *data = iter->private;
struct trace_array *tr = iter->tr;
int i;
if (data) {
struct fgraph_cpu_data *cpu_data;
int cpu = iter->cpu;
cpu_data = per_cpu_ptr(data->cpu_data, cpu);
cpu_data->depth = call->depth;
if (call->depth < FTRACE_RETFUNC_DEPTH)
cpu_data->enter_funcs[call->depth] = call->func;
}
print_graph_duration(tr, 0, s, flags | FLAGS_FILL_FULL);
for (i = 0; i < call->depth * TRACE_GRAPH_INDENT; i++)
trace_seq_putc(s, ' ');
trace_seq_printf(s, "%ps() {\n", (void *)call->func);
if (trace_seq_has_overflowed(s))
return TRACE_TYPE_PARTIAL_LINE;
return TRACE_TYPE_NO_CONSUME;
}
static void
print_graph_prologue(struct trace_iterator *iter, struct trace_seq *s,
int type, unsigned long addr, u32 flags)
{
struct fgraph_data *data = iter->private;
struct trace_entry *ent = iter->ent;
struct trace_array *tr = iter->tr;
int cpu = iter->cpu;
verif_pid(s, ent->pid, cpu, data);
if (type)
print_graph_irq(iter, addr, type, cpu, ent->pid, flags);
if (!(tr->trace_flags & TRACE_ITER_CONTEXT_INFO))
return;
if (flags & TRACE_GRAPH_PRINT_ABS_TIME)
print_graph_abs_time(iter->ts, s);
if (flags & TRACE_GRAPH_PRINT_CPU)
print_graph_cpu(s, cpu);
if (flags & TRACE_GRAPH_PRINT_PROC) {
print_graph_proc(s, ent->pid);
trace_seq_puts(s, " | ");
}
if (tr->trace_flags & TRACE_ITER_LATENCY_FMT)
print_graph_lat_fmt(s, ent);
return;
}
static int
check_irq_entry(struct trace_iterator *iter, u32 flags,
unsigned long addr, int depth)
{
int cpu = iter->cpu;
int *depth_irq;
struct fgraph_data *data = iter->private;
if ((flags & TRACE_GRAPH_PRINT_IRQS) ||
(!data))
return 0;
depth_irq = &(per_cpu_ptr(data->cpu_data, cpu)->depth_irq);
if (*depth_irq >= 0)
return 1;
if ((addr < (unsigned long)__irqentry_text_start) ||
(addr >= (unsigned long)__irqentry_text_end))
return 0;
*depth_irq = depth;
return 1;
}
static int
check_irq_return(struct trace_iterator *iter, u32 flags, int depth)
{
int cpu = iter->cpu;
int *depth_irq;
struct fgraph_data *data = iter->private;
if ((flags & TRACE_GRAPH_PRINT_IRQS) ||
(!data))
return 0;
depth_irq = &(per_cpu_ptr(data->cpu_data, cpu)->depth_irq);
if (*depth_irq == -1)
return 0;
if (*depth_irq >= depth) {
*depth_irq = -1;
return 1;
}
return 1;
}
static enum print_line_t
print_graph_entry(struct ftrace_graph_ent_entry *field, struct trace_seq *s,
struct trace_iterator *iter, u32 flags)
{
struct fgraph_data *data = iter->private;
struct ftrace_graph_ent *call = &field->graph_ent;
struct ftrace_graph_ret_entry *leaf_ret;
static enum print_line_t ret;
int cpu = iter->cpu;
if (check_irq_entry(iter, flags, call->func, call->depth))
return TRACE_TYPE_HANDLED;
print_graph_prologue(iter, s, TRACE_GRAPH_ENT, call->func, flags);
leaf_ret = get_return_for_leaf(iter, field);
if (leaf_ret)
ret = print_graph_entry_leaf(iter, field, leaf_ret, s, flags);
else
ret = print_graph_entry_nested(iter, field, s, cpu, flags);
if (data) {
if (s->full) {
data->failed = 1;
data->cpu = cpu;
} else
data->failed = 0;
}
return ret;
}
static enum print_line_t
print_graph_return(struct ftrace_graph_ret *trace, struct trace_seq *s,
struct trace_entry *ent, struct trace_iterator *iter,
u32 flags)
{
unsigned long long duration = trace->rettime - trace->calltime;
struct fgraph_data *data = iter->private;
struct trace_array *tr = iter->tr;
pid_t pid = ent->pid;
int cpu = iter->cpu;
int func_match = 1;
int i;
if (check_irq_return(iter, flags, trace->depth))
return TRACE_TYPE_HANDLED;
if (data) {
struct fgraph_cpu_data *cpu_data;
int cpu = iter->cpu;
cpu_data = per_cpu_ptr(data->cpu_data, cpu);
cpu_data->depth = trace->depth - 1;
if (trace->depth < FTRACE_RETFUNC_DEPTH) {
if (cpu_data->enter_funcs[trace->depth] != trace->func)
func_match = 0;
cpu_data->enter_funcs[trace->depth] = 0;
}
}
print_graph_prologue(iter, s, 0, 0, flags);
print_graph_duration(tr, duration, s, flags);
for (i = 0; i < trace->depth * TRACE_GRAPH_INDENT; i++)
trace_seq_putc(s, ' ');
if (func_match && !(flags & TRACE_GRAPH_PRINT_TAIL))
trace_seq_puts(s, "}\n");
else
trace_seq_printf(s, "} /* %ps */\n", (void *)trace->func);
if (flags & TRACE_GRAPH_PRINT_OVERRUN)
trace_seq_printf(s, " (Overruns: %lu)\n",
trace->overrun);
print_graph_irq(iter, trace->func, TRACE_GRAPH_RET,
cpu, pid, flags);
return trace_handle_return(s);
}
static enum print_line_t
print_graph_comment(struct trace_seq *s, struct trace_entry *ent,
struct trace_iterator *iter, u32 flags)
{
struct trace_array *tr = iter->tr;
unsigned long sym_flags = (tr->trace_flags & TRACE_ITER_SYM_MASK);
struct fgraph_data *data = iter->private;
struct trace_event *event;
int depth = 0;
int ret;
int i;
if (data)
depth = per_cpu_ptr(data->cpu_data, iter->cpu)->depth;
print_graph_prologue(iter, s, 0, 0, flags);
print_graph_duration(tr, 0, s, flags | FLAGS_FILL_FULL);
if (depth > 0)
for (i = 0; i < (depth + 1) * TRACE_GRAPH_INDENT; i++)
trace_seq_putc(s, ' ');
trace_seq_puts(s, "/* ");
switch (iter->ent->type) {
case TRACE_BPUTS:
ret = trace_print_bputs_msg_only(iter);
if (ret != TRACE_TYPE_HANDLED)
return ret;
break;
case TRACE_BPRINT:
ret = trace_print_bprintk_msg_only(iter);
if (ret != TRACE_TYPE_HANDLED)
return ret;
break;
case TRACE_PRINT:
ret = trace_print_printk_msg_only(iter);
if (ret != TRACE_TYPE_HANDLED)
return ret;
break;
default:
event = ftrace_find_event(ent->type);
if (!event)
return TRACE_TYPE_UNHANDLED;
ret = event->funcs->trace(iter, sym_flags, event);
if (ret != TRACE_TYPE_HANDLED)
return ret;
}
if (trace_seq_has_overflowed(s))
goto out;
if (s->buffer[s->seq.len - 1] == '\n') {
s->buffer[s->seq.len - 1] = '\0';
s->seq.len--;
}
trace_seq_puts(s, " */\n");
out:
return trace_handle_return(s);
}
enum print_line_t
print_graph_function_flags(struct trace_iterator *iter, u32 flags)
{
struct ftrace_graph_ent_entry *field;
struct fgraph_data *data = iter->private;
struct trace_entry *entry = iter->ent;
struct trace_seq *s = &iter->seq;
int cpu = iter->cpu;
int ret;
if (data && per_cpu_ptr(data->cpu_data, cpu)->ignore) {
per_cpu_ptr(data->cpu_data, cpu)->ignore = 0;
return TRACE_TYPE_HANDLED;
}
if (data && data->failed) {
field = &data->ent;
iter->cpu = data->cpu;
ret = print_graph_entry(field, s, iter, flags);
if (ret == TRACE_TYPE_HANDLED && iter->cpu != cpu) {
per_cpu_ptr(data->cpu_data, iter->cpu)->ignore = 1;
ret = TRACE_TYPE_NO_CONSUME;
}
iter->cpu = cpu;
return ret;
}
switch (entry->type) {
case TRACE_GRAPH_ENT: {
struct ftrace_graph_ent_entry saved;
trace_assign_type(field, entry);
saved = *field;
return print_graph_entry(&saved, s, iter, flags);
}
case TRACE_GRAPH_RET: {
struct ftrace_graph_ret_entry *field;
trace_assign_type(field, entry);
return print_graph_return(&field->ret, s, entry, iter, flags);
}
case TRACE_STACK:
case TRACE_FN:
return TRACE_TYPE_UNHANDLED;
default:
return print_graph_comment(s, entry, iter, flags);
}
return TRACE_TYPE_HANDLED;
}
static enum print_line_t
print_graph_function(struct trace_iterator *iter)
{
return print_graph_function_flags(iter, tracer_flags.val);
}
static enum print_line_t
print_graph_function_event(struct trace_iterator *iter, int flags,
struct trace_event *event)
{
return print_graph_function(iter);
}
static void print_lat_header(struct seq_file *s, u32 flags)
{
static const char spaces[] = " "
" "
" ";
int size = 0;
if (flags & TRACE_GRAPH_PRINT_ABS_TIME)
size += 16;
if (flags & TRACE_GRAPH_PRINT_CPU)
size += 4;
if (flags & TRACE_GRAPH_PRINT_PROC)
size += 17;
seq_printf(s, "#%.*s _-----=> irqs-off \n", size, spaces);
seq_printf(s, "#%.*s / _----=> need-resched \n", size, spaces);
seq_printf(s, "#%.*s| / _---=> hardirq/softirq \n", size, spaces);
seq_printf(s, "#%.*s|| / _--=> preempt-depth \n", size, spaces);
seq_printf(s, "#%.*s||| / \n", size, spaces);
}
static void __print_graph_headers_flags(struct trace_array *tr,
struct seq_file *s, u32 flags)
{
int lat = tr->trace_flags & TRACE_ITER_LATENCY_FMT;
if (lat)
print_lat_header(s, flags);
seq_putc(s, '#');
if (flags & TRACE_GRAPH_PRINT_ABS_TIME)
seq_puts(s, " TIME ");
if (flags & TRACE_GRAPH_PRINT_CPU)
seq_puts(s, " CPU");
if (flags & TRACE_GRAPH_PRINT_PROC)
seq_puts(s, " TASK/PID ");
if (lat)
seq_puts(s, "||||");
if (flags & TRACE_GRAPH_PRINT_DURATION)
seq_puts(s, " DURATION ");
seq_puts(s, " FUNCTION CALLS\n");
seq_putc(s, '#');
if (flags & TRACE_GRAPH_PRINT_ABS_TIME)
seq_puts(s, " | ");
if (flags & TRACE_GRAPH_PRINT_CPU)
seq_puts(s, " | ");
if (flags & TRACE_GRAPH_PRINT_PROC)
seq_puts(s, " | | ");
if (lat)
seq_puts(s, "||||");
if (flags & TRACE_GRAPH_PRINT_DURATION)
seq_puts(s, " | | ");
seq_puts(s, " | | | |\n");
}
static void print_graph_headers(struct seq_file *s)
{
print_graph_headers_flags(s, tracer_flags.val);
}
void print_graph_headers_flags(struct seq_file *s, u32 flags)
{
struct trace_iterator *iter = s->private;
struct trace_array *tr = iter->tr;
if (!(tr->trace_flags & TRACE_ITER_CONTEXT_INFO))
return;
if (tr->trace_flags & TRACE_ITER_LATENCY_FMT) {
if (trace_empty(iter))
return;
print_trace_header(s, iter);
}
__print_graph_headers_flags(tr, s, flags);
}
void graph_trace_open(struct trace_iterator *iter)
{
struct fgraph_data *data;
gfp_t gfpflags;
int cpu;
iter->private = NULL;
gfpflags = (in_atomic() || irqs_disabled()) ? GFP_ATOMIC : GFP_KERNEL;
data = kzalloc(sizeof(*data), gfpflags);
if (!data)
goto out_err;
data->cpu_data = alloc_percpu_gfp(struct fgraph_cpu_data, gfpflags);
if (!data->cpu_data)
goto out_err_free;
for_each_possible_cpu(cpu) {
pid_t *pid = &(per_cpu_ptr(data->cpu_data, cpu)->last_pid);
int *depth = &(per_cpu_ptr(data->cpu_data, cpu)->depth);
int *ignore = &(per_cpu_ptr(data->cpu_data, cpu)->ignore);
int *depth_irq = &(per_cpu_ptr(data->cpu_data, cpu)->depth_irq);
*pid = -1;
*depth = 0;
*ignore = 0;
*depth_irq = -1;
}
iter->private = data;
return;
out_err_free:
kfree(data);
out_err:
pr_warn("function graph tracer: not enough memory\n");
}
void graph_trace_close(struct trace_iterator *iter)
{
struct fgraph_data *data = iter->private;
if (data) {
free_percpu(data->cpu_data);
kfree(data);
}
}
static int
func_graph_set_flag(struct trace_array *tr, u32 old_flags, u32 bit, int set)
{
if (bit == TRACE_GRAPH_PRINT_IRQS)
ftrace_graph_skip_irqs = !set;
if (bit == TRACE_GRAPH_SLEEP_TIME)
ftrace_graph_sleep_time_control(set);
if (bit == TRACE_GRAPH_GRAPH_TIME)
ftrace_graph_graph_time_control(set);
return 0;
}
static ssize_t
graph_depth_write(struct file *filp, const char __user *ubuf, size_t cnt,
loff_t *ppos)
{
unsigned long val;
int ret;
ret = kstrtoul_from_user(ubuf, cnt, 10, &val);
if (ret)
return ret;
max_depth = val;
*ppos += cnt;
return cnt;
}
static ssize_t
graph_depth_read(struct file *filp, char __user *ubuf, size_t cnt,
loff_t *ppos)
{
char buf[15];
int n;
n = sprintf(buf, "%d\n", max_depth);
return simple_read_from_buffer(ubuf, cnt, ppos, buf, n);
}
static __init int init_graph_tracefs(void)
{
struct dentry *d_tracer;
d_tracer = tracing_init_dentry();
if (IS_ERR(d_tracer))
return 0;
trace_create_file("max_graph_depth", 0644, d_tracer,
NULL, &graph_depth_fops);
return 0;
}
static __init int init_graph_trace(void)
{
max_bytes_for_cpu = snprintf(NULL, 0, "%d", nr_cpu_ids - 1);
if (!register_trace_event(&graph_trace_entry_event)) {
pr_warn("Warning: could not register graph trace events\n");
return 1;
}
if (!register_trace_event(&graph_trace_ret_event)) {
pr_warn("Warning: could not register graph trace events\n");
return 1;
}
return register_tracer(&graph_trace);
}
