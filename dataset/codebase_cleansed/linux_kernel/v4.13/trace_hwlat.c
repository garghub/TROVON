static void trace_hwlat_sample(struct hwlat_sample *sample)
{
struct trace_array *tr = hwlat_trace;
struct trace_event_call *call = &event_hwlat;
struct ring_buffer *buffer = tr->trace_buffer.buffer;
struct ring_buffer_event *event;
struct hwlat_entry *entry;
unsigned long flags;
int pc;
pc = preempt_count();
local_save_flags(flags);
event = trace_buffer_lock_reserve(buffer, TRACE_HWLAT, sizeof(*entry),
flags, pc);
if (!event)
return;
entry = ring_buffer_event_data(event);
entry->seqnum = sample->seqnum;
entry->duration = sample->duration;
entry->outer_duration = sample->outer_duration;
entry->timestamp = sample->timestamp;
entry->nmi_total_ts = sample->nmi_total_ts;
entry->nmi_count = sample->nmi_count;
if (!call_filter_check_discard(call, entry, buffer, event))
trace_buffer_unlock_commit_nostack(buffer, event);
}
void trace_hwlat_callback(bool enter)
{
if (smp_processor_id() != nmi_cpu)
return;
if (!IS_ENABLED(CONFIG_GENERIC_SCHED_CLOCK)) {
if (enter)
nmi_ts_start = time_get();
else
nmi_total_ts = time_get() - nmi_ts_start;
}
if (enter)
nmi_count++;
}
static int get_sample(void)
{
struct trace_array *tr = hwlat_trace;
time_type start, t1, t2, last_t2;
s64 diff, total, last_total = 0;
u64 sample = 0;
u64 thresh = tracing_thresh;
u64 outer_sample = 0;
int ret = -1;
do_div(thresh, NSEC_PER_USEC);
nmi_cpu = smp_processor_id();
nmi_total_ts = 0;
nmi_count = 0;
barrier();
trace_hwlat_callback_enabled = true;
init_time(last_t2, 0);
start = time_get();
do {
t1 = time_get();
t2 = time_get();
if (time_u64(last_t2)) {
diff = time_to_us(time_sub(t1, last_t2));
if (diff < 0) {
pr_err(BANNER "time running backwards\n");
goto out;
}
if (diff > outer_sample)
outer_sample = diff;
}
last_t2 = t2;
total = time_to_us(time_sub(t2, start));
if (total < last_total) {
pr_err("Time total overflowed\n");
break;
}
last_total = total;
diff = time_to_us(time_sub(t2, t1));
if (diff < 0) {
pr_err(BANNER "time running backwards\n");
goto out;
}
if (diff > sample)
sample = diff;
} while (total <= hwlat_data.sample_width);
barrier();
trace_hwlat_callback_enabled = false;
barrier();
ret = 0;
if (sample > thresh || outer_sample > thresh) {
struct hwlat_sample s;
ret = 1;
if (nmi_total_ts)
do_div(nmi_total_ts, NSEC_PER_USEC);
hwlat_data.count++;
s.seqnum = hwlat_data.count;
s.duration = sample;
s.outer_duration = outer_sample;
ktime_get_real_ts64(&s.timestamp);
s.nmi_total_ts = nmi_total_ts;
s.nmi_count = nmi_count;
trace_hwlat_sample(&s);
if (sample > tr->max_latency)
tr->max_latency = sample;
}
out:
return ret;
}
static void move_to_next_cpu(void)
{
struct cpumask *current_mask = &save_cpumask;
int next_cpu;
if (disable_migrate)
return;
if (!cpumask_equal(current_mask, &current->cpus_allowed))
goto disable;
get_online_cpus();
cpumask_and(current_mask, cpu_online_mask, tracing_buffer_mask);
next_cpu = cpumask_next(smp_processor_id(), current_mask);
put_online_cpus();
if (next_cpu >= nr_cpu_ids)
next_cpu = cpumask_first(current_mask);
if (next_cpu >= nr_cpu_ids)
goto disable;
cpumask_clear(current_mask);
cpumask_set_cpu(next_cpu, current_mask);
sched_setaffinity(0, current_mask);
return;
disable:
disable_migrate = true;
}
static int kthread_fn(void *data)
{
u64 interval;
while (!kthread_should_stop()) {
move_to_next_cpu();
local_irq_disable();
get_sample();
local_irq_enable();
mutex_lock(&hwlat_data.lock);
interval = hwlat_data.sample_window - hwlat_data.sample_width;
mutex_unlock(&hwlat_data.lock);
do_div(interval, USEC_PER_MSEC);
if (interval < 1)
interval = 1;
if (msleep_interruptible(interval))
break;
}
return 0;
}
static int start_kthread(struct trace_array *tr)
{
struct cpumask *current_mask = &save_cpumask;
struct task_struct *kthread;
int next_cpu;
current_mask = &save_cpumask;
get_online_cpus();
cpumask_and(current_mask, cpu_online_mask, tracing_buffer_mask);
put_online_cpus();
next_cpu = cpumask_first(current_mask);
kthread = kthread_create(kthread_fn, NULL, "hwlatd");
if (IS_ERR(kthread)) {
pr_err(BANNER "could not start sampling thread\n");
return -ENOMEM;
}
cpumask_clear(current_mask);
cpumask_set_cpu(next_cpu, current_mask);
sched_setaffinity(kthread->pid, current_mask);
hwlat_kthread = kthread;
wake_up_process(kthread);
return 0;
}
static void stop_kthread(void)
{
if (!hwlat_kthread)
return;
kthread_stop(hwlat_kthread);
hwlat_kthread = NULL;
}
static ssize_t hwlat_read(struct file *filp, char __user *ubuf,
size_t cnt, loff_t *ppos)
{
char buf[U64STR_SIZE];
u64 *entry = filp->private_data;
u64 val;
int len;
if (!entry)
return -EFAULT;
if (cnt > sizeof(buf))
cnt = sizeof(buf);
val = *entry;
len = snprintf(buf, sizeof(buf), "%llu\n", val);
return simple_read_from_buffer(ubuf, cnt, ppos, buf, len);
}
static ssize_t
hwlat_width_write(struct file *filp, const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
u64 val;
int err;
err = kstrtoull_from_user(ubuf, cnt, 10, &val);
if (err)
return err;
mutex_lock(&hwlat_data.lock);
if (val < hwlat_data.sample_window)
hwlat_data.sample_width = val;
else
err = -EINVAL;
mutex_unlock(&hwlat_data.lock);
if (err)
return err;
return cnt;
}
static ssize_t
hwlat_window_write(struct file *filp, const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
u64 val;
int err;
err = kstrtoull_from_user(ubuf, cnt, 10, &val);
if (err)
return err;
mutex_lock(&hwlat_data.lock);
if (hwlat_data.sample_width < val)
hwlat_data.sample_window = val;
else
err = -EINVAL;
mutex_unlock(&hwlat_data.lock);
if (err)
return err;
return cnt;
}
static int init_tracefs(void)
{
struct dentry *d_tracer;
struct dentry *top_dir;
d_tracer = tracing_init_dentry();
if (IS_ERR(d_tracer))
return -ENOMEM;
top_dir = tracefs_create_dir("hwlat_detector", d_tracer);
if (!top_dir)
return -ENOMEM;
hwlat_sample_window = tracefs_create_file("window", 0640,
top_dir,
&hwlat_data.sample_window,
&window_fops);
if (!hwlat_sample_window)
goto err;
hwlat_sample_width = tracefs_create_file("width", 0644,
top_dir,
&hwlat_data.sample_width,
&width_fops);
if (!hwlat_sample_width)
goto err;
return 0;
err:
tracefs_remove_recursive(top_dir);
return -ENOMEM;
}
static void hwlat_tracer_start(struct trace_array *tr)
{
int err;
err = start_kthread(tr);
if (err)
pr_err(BANNER "Cannot start hwlat kthread\n");
}
static void hwlat_tracer_stop(struct trace_array *tr)
{
stop_kthread();
}
static int hwlat_tracer_init(struct trace_array *tr)
{
if (hwlat_busy)
return -EBUSY;
hwlat_trace = tr;
disable_migrate = false;
hwlat_data.count = 0;
tr->max_latency = 0;
save_tracing_thresh = tracing_thresh;
if (!tracing_thresh)
tracing_thresh = last_tracing_thresh;
if (tracer_tracing_is_on(tr))
hwlat_tracer_start(tr);
hwlat_busy = true;
return 0;
}
static void hwlat_tracer_reset(struct trace_array *tr)
{
stop_kthread();
last_tracing_thresh = tracing_thresh;
tracing_thresh = save_tracing_thresh;
hwlat_busy = false;
}
__init static int init_hwlat_tracer(void)
{
int ret;
mutex_init(&hwlat_data.lock);
ret = register_tracer(&hwlat_tracer);
if (ret)
return ret;
init_tracefs();
return 0;
}
