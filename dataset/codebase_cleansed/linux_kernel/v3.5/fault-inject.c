int setup_fault_attr(struct fault_attr *attr, char *str)
{
unsigned long probability;
unsigned long interval;
int times;
int space;
if (sscanf(str, "%lu,%lu,%d,%d",
&interval, &probability, &space, &times) < 4) {
printk(KERN_WARNING
"FAULT_INJECTION: failed to parse arguments\n");
return 0;
}
attr->probability = probability;
attr->interval = interval;
atomic_set(&attr->times, times);
atomic_set(&attr->space, space);
return 1;
}
static void fail_dump(struct fault_attr *attr)
{
if (attr->verbose > 0)
printk(KERN_NOTICE "FAULT_INJECTION: forcing a failure\n");
if (attr->verbose > 1)
dump_stack();
}
static bool fail_task(struct fault_attr *attr, struct task_struct *task)
{
return !in_interrupt() && task->make_it_fail;
}
static bool fail_stacktrace(struct fault_attr *attr)
{
struct stack_trace trace;
int depth = attr->stacktrace_depth;
unsigned long entries[MAX_STACK_TRACE_DEPTH];
int n;
bool found = (attr->require_start == 0 && attr->require_end == ULONG_MAX);
if (depth == 0)
return found;
trace.nr_entries = 0;
trace.entries = entries;
trace.max_entries = depth;
trace.skip = 1;
save_stack_trace(&trace);
for (n = 0; n < trace.nr_entries; n++) {
if (attr->reject_start <= entries[n] &&
entries[n] < attr->reject_end)
return false;
if (attr->require_start <= entries[n] &&
entries[n] < attr->require_end)
found = true;
}
return found;
}
static inline bool fail_stacktrace(struct fault_attr *attr)
{
return true;
}
bool should_fail(struct fault_attr *attr, ssize_t size)
{
if (attr->probability == 0)
return false;
if (attr->task_filter && !fail_task(attr, current))
return false;
if (atomic_read(&attr->times) == 0)
return false;
if (atomic_read(&attr->space) > size) {
atomic_sub(size, &attr->space);
return false;
}
if (attr->interval > 1) {
attr->count++;
if (attr->count % attr->interval)
return false;
}
if (attr->probability <= random32() % 100)
return false;
if (!fail_stacktrace(attr))
return false;
fail_dump(attr);
if (atomic_read(&attr->times) != -1)
atomic_dec_not_zero(&attr->times);
return true;
}
static int debugfs_ul_set(void *data, u64 val)
{
*(unsigned long *)data = val;
return 0;
}
static int debugfs_ul_get(void *data, u64 *val)
{
*val = *(unsigned long *)data;
return 0;
}
static struct dentry *debugfs_create_ul(const char *name, umode_t mode,
struct dentry *parent, unsigned long *value)
{
return debugfs_create_file(name, mode, parent, value, &fops_ul);
}
static int debugfs_stacktrace_depth_set(void *data, u64 val)
{
*(unsigned long *)data =
min_t(unsigned long, val, MAX_STACK_TRACE_DEPTH);
return 0;
}
static struct dentry *debugfs_create_stacktrace_depth(
const char *name, umode_t mode,
struct dentry *parent, unsigned long *value)
{
return debugfs_create_file(name, mode, parent, value,
&fops_stacktrace_depth);
}
static int debugfs_atomic_t_set(void *data, u64 val)
{
atomic_set((atomic_t *)data, val);
return 0;
}
static int debugfs_atomic_t_get(void *data, u64 *val)
{
*val = atomic_read((atomic_t *)data);
return 0;
}
static struct dentry *debugfs_create_atomic_t(const char *name, umode_t mode,
struct dentry *parent, atomic_t *value)
{
return debugfs_create_file(name, mode, parent, value, &fops_atomic_t);
}
struct dentry *fault_create_debugfs_attr(const char *name,
struct dentry *parent, struct fault_attr *attr)
{
umode_t mode = S_IFREG | S_IRUSR | S_IWUSR;
struct dentry *dir;
dir = debugfs_create_dir(name, parent);
if (!dir)
return ERR_PTR(-ENOMEM);
if (!debugfs_create_ul("probability", mode, dir, &attr->probability))
goto fail;
if (!debugfs_create_ul("interval", mode, dir, &attr->interval))
goto fail;
if (!debugfs_create_atomic_t("times", mode, dir, &attr->times))
goto fail;
if (!debugfs_create_atomic_t("space", mode, dir, &attr->space))
goto fail;
if (!debugfs_create_ul("verbose", mode, dir, &attr->verbose))
goto fail;
if (!debugfs_create_bool("task-filter", mode, dir, &attr->task_filter))
goto fail;
#ifdef CONFIG_FAULT_INJECTION_STACKTRACE_FILTER
if (!debugfs_create_stacktrace_depth("stacktrace-depth", mode, dir,
&attr->stacktrace_depth))
goto fail;
if (!debugfs_create_ul("require-start", mode, dir,
&attr->require_start))
goto fail;
if (!debugfs_create_ul("require-end", mode, dir, &attr->require_end))
goto fail;
if (!debugfs_create_ul("reject-start", mode, dir, &attr->reject_start))
goto fail;
if (!debugfs_create_ul("reject-end", mode, dir, &attr->reject_end))
goto fail;
#endif
return dir;
fail:
debugfs_remove_recursive(dir);
return ERR_PTR(-ENOMEM);
}
