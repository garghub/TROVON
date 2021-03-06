static int function_trace_init(struct trace_array *tr)
{
func_trace = tr;
tr->cpu = get_cpu();
put_cpu();
tracing_start_cmdline_record();
tracing_start_function_trace();
return 0;
}
static void function_trace_reset(struct trace_array *tr)
{
tracing_stop_function_trace();
tracing_stop_cmdline_record();
}
static void function_trace_start(struct trace_array *tr)
{
tracing_reset_online_cpus(tr);
}
static void
function_trace_call_preempt_only(unsigned long ip, unsigned long parent_ip)
{
struct trace_array *tr = func_trace;
struct trace_array_cpu *data;
unsigned long flags;
long disabled;
int cpu;
int pc;
if (unlikely(!ftrace_function_enabled))
return;
pc = preempt_count();
preempt_disable_notrace();
local_save_flags(flags);
cpu = raw_smp_processor_id();
data = tr->data[cpu];
disabled = atomic_inc_return(&data->disabled);
if (likely(disabled == 1))
trace_function(tr, ip, parent_ip, flags, pc);
atomic_dec(&data->disabled);
preempt_enable_notrace();
}
static void
function_trace_call(unsigned long ip, unsigned long parent_ip)
{
struct trace_array *tr = func_trace;
struct trace_array_cpu *data;
unsigned long flags;
long disabled;
int cpu;
int pc;
if (unlikely(!ftrace_function_enabled))
return;
local_irq_save(flags);
cpu = raw_smp_processor_id();
data = tr->data[cpu];
disabled = atomic_inc_return(&data->disabled);
if (likely(disabled == 1)) {
if (unlikely(func_flags.val & TRACE_FUNC_OPT_PSTORE))
pstore_ftrace_call(ip, parent_ip);
pc = preempt_count();
trace_function(tr, ip, parent_ip, flags, pc);
}
atomic_dec(&data->disabled);
local_irq_restore(flags);
}
static void
function_stack_trace_call(unsigned long ip, unsigned long parent_ip)
{
struct trace_array *tr = func_trace;
struct trace_array_cpu *data;
unsigned long flags;
long disabled;
int cpu;
int pc;
if (unlikely(!ftrace_function_enabled))
return;
local_irq_save(flags);
cpu = raw_smp_processor_id();
data = tr->data[cpu];
disabled = atomic_inc_return(&data->disabled);
if (likely(disabled == 1)) {
pc = preempt_count();
trace_function(tr, ip, parent_ip, flags, pc);
__trace_stack(tr, flags, 5, pc);
}
atomic_dec(&data->disabled);
local_irq_restore(flags);
}
static void tracing_start_function_trace(void)
{
ftrace_function_enabled = 0;
if (trace_flags & TRACE_ITER_PREEMPTONLY)
trace_ops.func = function_trace_call_preempt_only;
else
trace_ops.func = function_trace_call;
if (func_flags.val & TRACE_FUNC_OPT_STACK)
register_ftrace_function(&trace_stack_ops);
else
register_ftrace_function(&trace_ops);
ftrace_function_enabled = 1;
}
static void tracing_stop_function_trace(void)
{
ftrace_function_enabled = 0;
if (func_flags.val & TRACE_FUNC_OPT_STACK)
unregister_ftrace_function(&trace_stack_ops);
else
unregister_ftrace_function(&trace_ops);
}
static int func_set_flag(u32 old_flags, u32 bit, int set)
{
switch (bit) {
case TRACE_FUNC_OPT_STACK:
if (!!set == !!(func_flags.val & TRACE_FUNC_OPT_STACK))
break;
if (set) {
unregister_ftrace_function(&trace_ops);
register_ftrace_function(&trace_stack_ops);
} else {
unregister_ftrace_function(&trace_stack_ops);
register_ftrace_function(&trace_ops);
}
break;
case TRACE_FUNC_OPT_PSTORE:
break;
default:
return -EINVAL;
}
return 0;
}
static void
ftrace_traceon(unsigned long ip, unsigned long parent_ip, void **data)
{
long *count = (long *)data;
if (tracing_is_on())
return;
if (!*count)
return;
if (*count != -1)
(*count)--;
tracing_on();
}
static void
ftrace_traceoff(unsigned long ip, unsigned long parent_ip, void **data)
{
long *count = (long *)data;
if (!tracing_is_on())
return;
if (!*count)
return;
if (*count != -1)
(*count)--;
tracing_off();
}
static int
ftrace_trace_onoff_print(struct seq_file *m, unsigned long ip,
struct ftrace_probe_ops *ops, void *data)
{
long count = (long)data;
seq_printf(m, "%ps:", (void *)ip);
if (ops == &traceon_probe_ops)
seq_printf(m, "traceon");
else
seq_printf(m, "traceoff");
if (count == -1)
seq_printf(m, ":unlimited\n");
else
seq_printf(m, ":count=%ld\n", count);
return 0;
}
static int
ftrace_trace_onoff_unreg(char *glob, char *cmd, char *param)
{
struct ftrace_probe_ops *ops;
if (strcmp(cmd, "traceon") == 0)
ops = &traceon_probe_ops;
else
ops = &traceoff_probe_ops;
unregister_ftrace_function_probe_func(glob, ops);
return 0;
}
static int
ftrace_trace_onoff_callback(struct ftrace_hash *hash,
char *glob, char *cmd, char *param, int enable)
{
struct ftrace_probe_ops *ops;
void *count = (void *)-1;
char *number;
int ret;
if (!enable)
return -EINVAL;
if (glob[0] == '!')
return ftrace_trace_onoff_unreg(glob+1, cmd, param);
if (strcmp(cmd, "traceon") == 0)
ops = &traceon_probe_ops;
else
ops = &traceoff_probe_ops;
if (!param)
goto out_reg;
number = strsep(&param, ":");
if (!strlen(number))
goto out_reg;
ret = strict_strtoul(number, 0, (unsigned long *)&count);
if (ret)
return ret;
out_reg:
ret = register_ftrace_function_probe(glob, ops, count);
return ret < 0 ? ret : 0;
}
static int __init init_func_cmd_traceon(void)
{
int ret;
ret = register_ftrace_command(&ftrace_traceoff_cmd);
if (ret)
return ret;
ret = register_ftrace_command(&ftrace_traceon_cmd);
if (ret)
unregister_ftrace_command(&ftrace_traceoff_cmd);
return ret;
}
static inline int init_func_cmd_traceon(void)
{
return 0;
}
static __init int init_function_trace(void)
{
init_func_cmd_traceon();
return register_tracer(&function_trace);
}
