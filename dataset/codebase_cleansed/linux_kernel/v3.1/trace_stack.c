static inline void check_stack(void)
{
unsigned long this_size, flags;
unsigned long *p, *top, *start;
int i;
this_size = ((unsigned long)&this_size) & (THREAD_SIZE-1);
this_size = THREAD_SIZE - this_size;
if (this_size <= max_stack_size)
return;
if (!object_is_on_stack(&this_size))
return;
local_irq_save(flags);
arch_spin_lock(&max_stack_lock);
if (this_size <= max_stack_size)
goto out;
max_stack_size = this_size;
max_stack_trace.nr_entries = 0;
max_stack_trace.skip = 3;
save_stack_trace(&max_stack_trace);
i = 0;
start = &this_size;
top = (unsigned long *)
(((unsigned long)start & ~(THREAD_SIZE-1)) + THREAD_SIZE);
while (i < max_stack_trace.nr_entries) {
int found = 0;
stack_dump_index[i] = this_size;
p = start;
for (; p < top && i < max_stack_trace.nr_entries; p++) {
if (*p == stack_dump_trace[i]) {
this_size = stack_dump_index[i++] =
(top - p) * sizeof(unsigned long);
found = 1;
start = p + 1;
}
}
if (!found)
i++;
}
out:
arch_spin_unlock(&max_stack_lock);
local_irq_restore(flags);
}
static void
stack_trace_call(unsigned long ip, unsigned long parent_ip)
{
int cpu;
if (unlikely(!ftrace_enabled || stack_trace_disabled))
return;
preempt_disable_notrace();
cpu = raw_smp_processor_id();
if (per_cpu(trace_active, cpu)++ != 0)
goto out;
check_stack();
out:
per_cpu(trace_active, cpu)--;
preempt_enable_notrace();
}
static ssize_t
stack_max_size_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *ppos)
{
unsigned long *ptr = filp->private_data;
char buf[64];
int r;
r = snprintf(buf, sizeof(buf), "%ld\n", *ptr);
if (r > sizeof(buf))
r = sizeof(buf);
return simple_read_from_buffer(ubuf, count, ppos, buf, r);
}
static ssize_t
stack_max_size_write(struct file *filp, const char __user *ubuf,
size_t count, loff_t *ppos)
{
long *ptr = filp->private_data;
unsigned long val, flags;
int ret;
int cpu;
ret = kstrtoul_from_user(ubuf, count, 10, &val);
if (ret)
return ret;
local_irq_save(flags);
cpu = smp_processor_id();
per_cpu(trace_active, cpu)++;
arch_spin_lock(&max_stack_lock);
*ptr = val;
arch_spin_unlock(&max_stack_lock);
per_cpu(trace_active, cpu)--;
local_irq_restore(flags);
return count;
}
static void *
__next(struct seq_file *m, loff_t *pos)
{
long n = *pos - 1;
if (n >= max_stack_trace.nr_entries || stack_dump_trace[n] == ULONG_MAX)
return NULL;
m->private = (void *)n;
return &m->private;
}
static void *
t_next(struct seq_file *m, void *v, loff_t *pos)
{
(*pos)++;
return __next(m, pos);
}
static void *t_start(struct seq_file *m, loff_t *pos)
{
int cpu;
local_irq_disable();
cpu = smp_processor_id();
per_cpu(trace_active, cpu)++;
arch_spin_lock(&max_stack_lock);
if (*pos == 0)
return SEQ_START_TOKEN;
return __next(m, pos);
}
static void t_stop(struct seq_file *m, void *p)
{
int cpu;
arch_spin_unlock(&max_stack_lock);
cpu = smp_processor_id();
per_cpu(trace_active, cpu)--;
local_irq_enable();
}
static int trace_lookup_stack(struct seq_file *m, long i)
{
unsigned long addr = stack_dump_trace[i];
return seq_printf(m, "%pS\n", (void *)addr);
}
static void print_disabled(struct seq_file *m)
{
seq_puts(m, "#\n"
"# Stack tracer disabled\n"
"#\n"
"# To enable the stack tracer, either add 'stacktrace' to the\n"
"# kernel command line\n"
"# or 'echo 1 > /proc/sys/kernel/stack_tracer_enabled'\n"
"#\n");
}
static int t_show(struct seq_file *m, void *v)
{
long i;
int size;
if (v == SEQ_START_TOKEN) {
seq_printf(m, " Depth Size Location"
" (%d entries)\n"
" ----- ---- --------\n",
max_stack_trace.nr_entries - 1);
if (!stack_tracer_enabled && !max_stack_size)
print_disabled(m);
return 0;
}
i = *(long *)v;
if (i >= max_stack_trace.nr_entries ||
stack_dump_trace[i] == ULONG_MAX)
return 0;
if (i+1 == max_stack_trace.nr_entries ||
stack_dump_trace[i+1] == ULONG_MAX)
size = stack_dump_index[i];
else
size = stack_dump_index[i] - stack_dump_index[i+1];
seq_printf(m, "%3ld) %8d %5d ", i, stack_dump_index[i], size);
trace_lookup_stack(m, i);
return 0;
}
static int stack_trace_open(struct inode *inode, struct file *file)
{
return seq_open(file, &stack_trace_seq_ops);
}
int
stack_trace_sysctl(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int ret;
mutex_lock(&stack_sysctl_mutex);
ret = proc_dointvec(table, write, buffer, lenp, ppos);
if (ret || !write ||
(last_stack_tracer_enabled == !!stack_tracer_enabled))
goto out;
last_stack_tracer_enabled = !!stack_tracer_enabled;
if (stack_tracer_enabled)
register_ftrace_function(&trace_ops);
else
unregister_ftrace_function(&trace_ops);
out:
mutex_unlock(&stack_sysctl_mutex);
return ret;
}
static __init int enable_stacktrace(char *str)
{
stack_tracer_enabled = 1;
last_stack_tracer_enabled = 1;
return 1;
}
static __init int stack_trace_init(void)
{
struct dentry *d_tracer;
d_tracer = tracing_init_dentry();
trace_create_file("stack_max_size", 0644, d_tracer,
&max_stack_size, &stack_max_size_fops);
trace_create_file("stack_trace", 0444, d_tracer,
NULL, &stack_trace_fops);
if (stack_tracer_enabled)
register_ftrace_function(&trace_ops);
return 0;
}
