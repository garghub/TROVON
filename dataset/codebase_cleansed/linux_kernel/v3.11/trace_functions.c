static int function_trace_init(struct trace_array *tr)
{
func_trace = tr;
tr->trace_buffer.cpu = get_cpu();
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
tracing_reset_online_cpus(&tr->trace_buffer);
}
static void
function_trace_call(unsigned long ip, unsigned long parent_ip,
struct ftrace_ops *op, struct pt_regs *pt_regs)
{
struct trace_array *tr = func_trace;
struct trace_array_cpu *data;
unsigned long flags;
int bit;
int cpu;
int pc;
if (unlikely(!ftrace_function_enabled))
return;
pc = preempt_count();
preempt_disable_notrace();
bit = trace_test_and_set_recursion(TRACE_FTRACE_START, TRACE_FTRACE_MAX);
if (bit < 0)
goto out;
cpu = smp_processor_id();
data = per_cpu_ptr(tr->trace_buffer.data, cpu);
if (!atomic_read(&data->disabled)) {
local_save_flags(flags);
trace_function(tr, ip, parent_ip, flags, pc);
}
trace_clear_recursion(bit);
out:
preempt_enable_notrace();
}
static void
function_stack_trace_call(unsigned long ip, unsigned long parent_ip,
struct ftrace_ops *op, struct pt_regs *pt_regs)
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
data = per_cpu_ptr(tr->trace_buffer.data, cpu);
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
default:
return -EINVAL;
}
return 0;
}
static int update_count(void **data)
{
unsigned long *count = (long *)data;
if (!*count)
return 0;
if (*count != -1)
(*count)--;
return 1;
}
static void
ftrace_traceon_count(unsigned long ip, unsigned long parent_ip, void **data)
{
if (tracing_is_on())
return;
if (update_count(data))
tracing_on();
}
static void
ftrace_traceoff_count(unsigned long ip, unsigned long parent_ip, void **data)
{
if (!tracing_is_on())
return;
if (update_count(data))
tracing_off();
}
static void
ftrace_traceon(unsigned long ip, unsigned long parent_ip, void **data)
{
if (tracing_is_on())
return;
tracing_on();
}
static void
ftrace_traceoff(unsigned long ip, unsigned long parent_ip, void **data)
{
if (!tracing_is_on())
return;
tracing_off();
}
static void
ftrace_stacktrace(unsigned long ip, unsigned long parent_ip, void **data)
{
trace_dump_stack(STACK_SKIP);
}
static void
ftrace_stacktrace_count(unsigned long ip, unsigned long parent_ip, void **data)
{
if (!tracing_is_on())
return;
if (update_count(data))
trace_dump_stack(STACK_SKIP);
}
static void
ftrace_dump_probe(unsigned long ip, unsigned long parent_ip, void **data)
{
if (update_count(data))
ftrace_dump(DUMP_ALL);
}
static void
ftrace_cpudump_probe(unsigned long ip, unsigned long parent_ip, void **data)
{
if (update_count(data))
ftrace_dump(DUMP_ORIG);
}
static int
ftrace_probe_print(const char *name, struct seq_file *m,
unsigned long ip, void *data)
{
long count = (long)data;
seq_printf(m, "%ps:%s", (void *)ip, name);
if (count == -1)
seq_printf(m, ":unlimited\n");
else
seq_printf(m, ":count=%ld\n", count);
return 0;
}
static int
ftrace_traceon_print(struct seq_file *m, unsigned long ip,
struct ftrace_probe_ops *ops, void *data)
{
return ftrace_probe_print("traceon", m, ip, data);
}
static int
ftrace_traceoff_print(struct seq_file *m, unsigned long ip,
struct ftrace_probe_ops *ops, void *data)
{
return ftrace_probe_print("traceoff", m, ip, data);
}
static int
ftrace_stacktrace_print(struct seq_file *m, unsigned long ip,
struct ftrace_probe_ops *ops, void *data)
{
return ftrace_probe_print("stacktrace", m, ip, data);
}
static int
ftrace_dump_print(struct seq_file *m, unsigned long ip,
struct ftrace_probe_ops *ops, void *data)
{
return ftrace_probe_print("dump", m, ip, data);
}
static int
ftrace_cpudump_print(struct seq_file *m, unsigned long ip,
struct ftrace_probe_ops *ops, void *data)
{
return ftrace_probe_print("cpudump", m, ip, data);
}
static int
ftrace_trace_probe_callback(struct ftrace_probe_ops *ops,
struct ftrace_hash *hash, char *glob,
char *cmd, char *param, int enable)
{
void *count = (void *)-1;
char *number;
int ret;
if (!enable)
return -EINVAL;
if (glob[0] == '!') {
unregister_ftrace_function_probe_func(glob+1, ops);
return 0;
}
if (!param)
goto out_reg;
number = strsep(&param, ":");
if (!strlen(number))
goto out_reg;
ret = kstrtoul(number, 0, (unsigned long *)&count);
if (ret)
return ret;
out_reg:
ret = register_ftrace_function_probe(glob, ops, count);
return ret < 0 ? ret : 0;
}
static int
ftrace_trace_onoff_callback(struct ftrace_hash *hash,
char *glob, char *cmd, char *param, int enable)
{
struct ftrace_probe_ops *ops;
if (strcmp(cmd, "traceon") == 0)
ops = param ? &traceon_count_probe_ops : &traceon_probe_ops;
else
ops = param ? &traceoff_count_probe_ops : &traceoff_probe_ops;
return ftrace_trace_probe_callback(ops, hash, glob, cmd,
param, enable);
}
static int
ftrace_stacktrace_callback(struct ftrace_hash *hash,
char *glob, char *cmd, char *param, int enable)
{
struct ftrace_probe_ops *ops;
ops = param ? &stacktrace_count_probe_ops : &stacktrace_probe_ops;
return ftrace_trace_probe_callback(ops, hash, glob, cmd,
param, enable);
}
static int
ftrace_dump_callback(struct ftrace_hash *hash,
char *glob, char *cmd, char *param, int enable)
{
struct ftrace_probe_ops *ops;
ops = &dump_probe_ops;
return ftrace_trace_probe_callback(ops, hash, glob, cmd,
"1", enable);
}
static int
ftrace_cpudump_callback(struct ftrace_hash *hash,
char *glob, char *cmd, char *param, int enable)
{
struct ftrace_probe_ops *ops;
ops = &cpudump_probe_ops;
return ftrace_trace_probe_callback(ops, hash, glob, cmd,
"1", enable);
}
static int __init init_func_cmd_traceon(void)
{
int ret;
ret = register_ftrace_command(&ftrace_traceoff_cmd);
if (ret)
return ret;
ret = register_ftrace_command(&ftrace_traceon_cmd);
if (ret)
goto out_free_traceoff;
ret = register_ftrace_command(&ftrace_stacktrace_cmd);
if (ret)
goto out_free_traceon;
ret = register_ftrace_command(&ftrace_dump_cmd);
if (ret)
goto out_free_stacktrace;
ret = register_ftrace_command(&ftrace_cpudump_cmd);
if (ret)
goto out_free_dump;
return 0;
out_free_dump:
unregister_ftrace_command(&ftrace_dump_cmd);
out_free_stacktrace:
unregister_ftrace_command(&ftrace_stacktrace_cmd);
out_free_traceon:
unregister_ftrace_command(&ftrace_traceon_cmd);
out_free_traceoff:
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
