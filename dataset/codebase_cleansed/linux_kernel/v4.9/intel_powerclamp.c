static int duration_set(const char *arg, const struct kernel_param *kp)
{
int ret = 0;
unsigned long new_duration;
ret = kstrtoul(arg, 10, &new_duration);
if (ret)
goto exit;
if (new_duration > 25 || new_duration < 6) {
pr_err("Out of recommended range %lu, between 6-25ms\n",
new_duration);
ret = -EINVAL;
}
duration = clamp(new_duration, 6ul, 25ul);
smp_mb();
exit:
return ret;
}
static int window_size_set(const char *arg, const struct kernel_param *kp)
{
int ret = 0;
unsigned long new_window_size;
ret = kstrtoul(arg, 10, &new_window_size);
if (ret)
goto exit_win;
if (new_window_size > 10 || new_window_size < 2) {
pr_err("Out of recommended window size %lu, between 2-10\n",
new_window_size);
ret = -EINVAL;
}
window_size = clamp(new_window_size, 2ul, 10ul);
smp_mb();
exit_win:
return ret;
}
static void find_target_mwait(void)
{
unsigned int eax, ebx, ecx, edx;
unsigned int highest_cstate = 0;
unsigned int highest_subcstate = 0;
int i;
if (boot_cpu_data.cpuid_level < CPUID_MWAIT_LEAF)
return;
cpuid(CPUID_MWAIT_LEAF, &eax, &ebx, &ecx, &edx);
if (!(ecx & CPUID5_ECX_EXTENSIONS_SUPPORTED) ||
!(ecx & CPUID5_ECX_INTERRUPT_BREAK))
return;
edx >>= MWAIT_SUBSTATE_SIZE;
for (i = 0; i < 7 && edx; i++, edx >>= MWAIT_SUBSTATE_SIZE) {
if (edx & MWAIT_SUBSTATE_MASK) {
highest_cstate = i;
highest_subcstate = edx & MWAIT_SUBSTATE_MASK;
}
}
target_mwait = (highest_cstate << MWAIT_SUBSTATE_SIZE) |
(highest_subcstate - 1);
}
static bool has_pkg_state_counter(void)
{
u64 val;
struct pkg_cstate_info *info = pkg_cstates;
while (info->msr_index) {
if (!rdmsrl_safe(info->msr_index, &val))
return true;
info++;
}
return false;
}
static u64 pkg_state_counter(void)
{
u64 val;
u64 count = 0;
struct pkg_cstate_info *info = pkg_cstates;
while (info->msr_index) {
if (!info->skip) {
if (!rdmsrl_safe(info->msr_index, &val))
count += val;
else
info->skip = true;
}
info++;
}
return count;
}
static void noop_timer(unsigned long foo)
{
}
static unsigned int get_compensation(int ratio)
{
unsigned int comp = 0;
if (ratio == 1 &&
cal_data[ratio].confidence >= CONFIDENCE_OK &&
cal_data[ratio + 1].confidence >= CONFIDENCE_OK &&
cal_data[ratio + 2].confidence >= CONFIDENCE_OK) {
comp = (cal_data[ratio].steady_comp +
cal_data[ratio + 1].steady_comp +
cal_data[ratio + 2].steady_comp) / 3;
} else if (ratio == MAX_TARGET_RATIO - 1 &&
cal_data[ratio].confidence >= CONFIDENCE_OK &&
cal_data[ratio - 1].confidence >= CONFIDENCE_OK &&
cal_data[ratio - 2].confidence >= CONFIDENCE_OK) {
comp = (cal_data[ratio].steady_comp +
cal_data[ratio - 1].steady_comp +
cal_data[ratio - 2].steady_comp) / 3;
} else if (cal_data[ratio].confidence >= CONFIDENCE_OK &&
cal_data[ratio - 1].confidence >= CONFIDENCE_OK &&
cal_data[ratio + 1].confidence >= CONFIDENCE_OK) {
comp = (cal_data[ratio].steady_comp +
cal_data[ratio - 1].steady_comp +
cal_data[ratio + 1].steady_comp) / 3;
}
if (reduce_irq)
comp = ratio;
if (comp + ratio >= MAX_TARGET_RATIO)
comp = MAX_TARGET_RATIO - ratio - 1;
return comp;
}
static void adjust_compensation(int target_ratio, unsigned int win)
{
int delta;
struct powerclamp_calibration_data *d = &cal_data[target_ratio];
if (d->confidence >= CONFIDENCE_OK ||
atomic_read(&idle_wakeup_counter) >
win * num_online_cpus())
return;
delta = set_target_ratio - current_ratio;
if (delta >= 0 && delta <= (1+target_ratio/10)) {
if (d->steady_comp)
d->steady_comp =
roundup(delta+d->steady_comp, 2)/2;
else
d->steady_comp = delta;
d->confidence++;
}
}
static bool powerclamp_adjust_controls(unsigned int target_ratio,
unsigned int guard, unsigned int win)
{
static u64 msr_last, tsc_last;
u64 msr_now, tsc_now;
u64 val64;
msr_now = pkg_state_counter();
tsc_now = rdtsc();
if (!msr_last || !tsc_last)
current_ratio = 1;
else if (tsc_now-tsc_last) {
val64 = 100*(msr_now-msr_last);
do_div(val64, (tsc_now-tsc_last));
current_ratio = val64;
}
msr_last = msr_now;
tsc_last = tsc_now;
adjust_compensation(target_ratio, win);
reduce_irq = atomic_read(&idle_wakeup_counter) >=
2 * win * num_online_cpus();
atomic_set(&idle_wakeup_counter, 0);
return set_target_ratio + guard <= current_ratio;
}
static int clamp_thread(void *arg)
{
int cpunr = (unsigned long)arg;
DEFINE_TIMER(wakeup_timer, noop_timer, 0, 0);
static const struct sched_param param = {
.sched_priority = MAX_USER_RT_PRIO/2,
};
unsigned int count = 0;
unsigned int target_ratio;
set_bit(cpunr, cpu_clamping_mask);
set_freezable();
init_timer_on_stack(&wakeup_timer);
sched_setscheduler(current, SCHED_FIFO, &param);
while (true == clamping && !kthread_should_stop() &&
cpu_online(cpunr)) {
int sleeptime;
unsigned long target_jiffies;
unsigned int guard;
unsigned int compensated_ratio;
int interval;
unsigned int duration_jiffies = msecs_to_jiffies(duration);
unsigned int window_size_now;
try_to_freeze();
target_ratio = set_target_ratio;
guard = 1 + target_ratio/20;
window_size_now = window_size;
count++;
compensated_ratio = target_ratio +
get_compensation(target_ratio);
if (compensated_ratio <= 0)
compensated_ratio = 1;
interval = duration_jiffies * 100 / compensated_ratio;
target_jiffies = roundup(jiffies, interval);
sleeptime = target_jiffies - jiffies;
if (sleeptime <= 0)
sleeptime = 1;
schedule_timeout_interruptible(sleeptime);
if (cpunr == control_cpu && !(count%window_size_now)) {
should_skip =
powerclamp_adjust_controls(target_ratio,
guard, window_size_now);
smp_mb();
}
if (should_skip)
continue;
target_jiffies = jiffies + duration_jiffies;
mod_timer(&wakeup_timer, target_jiffies);
if (unlikely(local_softirq_pending()))
continue;
preempt_disable();
while (time_before(jiffies, target_jiffies)) {
unsigned long ecx = 1;
unsigned long eax = target_mwait;
local_touch_nmi();
stop_critical_timings();
mwait_idle_with_hints(eax, ecx);
start_critical_timings();
atomic_inc(&idle_wakeup_counter);
}
preempt_enable();
}
del_timer_sync(&wakeup_timer);
clear_bit(cpunr, cpu_clamping_mask);
return 0;
}
static void poll_pkg_cstate(struct work_struct *dummy)
{
static u64 msr_last;
static u64 tsc_last;
static unsigned long jiffies_last;
u64 msr_now;
unsigned long jiffies_now;
u64 tsc_now;
u64 val64;
msr_now = pkg_state_counter();
tsc_now = rdtsc();
jiffies_now = jiffies;
if (!msr_last || !tsc_last)
pkg_cstate_ratio_cur = 1;
else {
if (tsc_now - tsc_last) {
val64 = 100 * (msr_now - msr_last);
do_div(val64, (tsc_now - tsc_last));
pkg_cstate_ratio_cur = val64;
}
}
msr_last = msr_now;
jiffies_last = jiffies_now;
tsc_last = tsc_now;
if (true == clamping)
schedule_delayed_work(&poll_pkg_cstate_work, HZ);
}
static int start_power_clamp(void)
{
unsigned long cpu;
struct task_struct *thread;
set_target_ratio = clamp(set_target_ratio, 0U, MAX_TARGET_RATIO - 1);
get_online_cpus();
control_cpu = 0;
if (!cpu_online(control_cpu))
control_cpu = smp_processor_id();
clamping = true;
schedule_delayed_work(&poll_pkg_cstate_work, 0);
for_each_online_cpu(cpu) {
struct task_struct **p =
per_cpu_ptr(powerclamp_thread, cpu);
thread = kthread_create_on_node(clamp_thread,
(void *) cpu,
cpu_to_node(cpu),
"kidle_inject/%ld", cpu);
if (likely(!IS_ERR(thread))) {
kthread_bind(thread, cpu);
wake_up_process(thread);
*p = thread;
}
}
put_online_cpus();
return 0;
}
static void end_power_clamp(void)
{
int i;
struct task_struct *thread;
clamping = false;
smp_mb();
msleep(20);
if (bitmap_weight(cpu_clamping_mask, num_possible_cpus())) {
for_each_set_bit(i, cpu_clamping_mask, num_possible_cpus()) {
pr_debug("clamping thread for cpu %d alive, kill\n", i);
thread = *per_cpu_ptr(powerclamp_thread, i);
kthread_stop(thread);
}
}
}
static int powerclamp_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned long cpu = (unsigned long)hcpu;
struct task_struct *thread;
struct task_struct **percpu_thread =
per_cpu_ptr(powerclamp_thread, cpu);
if (false == clamping)
goto exit_ok;
switch (action) {
case CPU_ONLINE:
thread = kthread_create_on_node(clamp_thread,
(void *) cpu,
cpu_to_node(cpu),
"kidle_inject/%lu", cpu);
if (likely(!IS_ERR(thread))) {
kthread_bind(thread, cpu);
wake_up_process(thread);
*percpu_thread = thread;
}
if (cpu == 0) {
control_cpu = 0;
smp_mb();
}
break;
case CPU_DEAD:
if (test_bit(cpu, cpu_clamping_mask)) {
pr_err("cpu %lu dead but powerclamping thread is not\n",
cpu);
kthread_stop(*percpu_thread);
}
if (cpu == control_cpu) {
control_cpu = smp_processor_id();
smp_mb();
}
}
exit_ok:
return NOTIFY_OK;
}
static int powerclamp_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
*state = MAX_TARGET_RATIO;
return 0;
}
static int powerclamp_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
if (true == clamping)
*state = pkg_cstate_ratio_cur;
else
*state = -1;
return 0;
}
static int powerclamp_set_cur_state(struct thermal_cooling_device *cdev,
unsigned long new_target_ratio)
{
int ret = 0;
new_target_ratio = clamp(new_target_ratio, 0UL,
(unsigned long) (MAX_TARGET_RATIO-1));
if (set_target_ratio == 0 && new_target_ratio > 0) {
pr_info("Start idle injection to reduce power\n");
set_target_ratio = new_target_ratio;
ret = start_power_clamp();
goto exit_set;
} else if (set_target_ratio > 0 && new_target_ratio == 0) {
pr_info("Stop forced idle injection\n");
end_power_clamp();
set_target_ratio = 0;
} else {
set_target_ratio = new_target_ratio;
smp_mb();
}
exit_set:
return ret;
}
static int __init powerclamp_probe(void)
{
if (!x86_match_cpu(intel_powerclamp_ids)) {
pr_err("CPU does not support MWAIT");
return -ENODEV;
}
if (!has_pkg_state_counter()) {
pr_info("No package C-state available");
return -ENODEV;
}
find_target_mwait();
return 0;
}
static int powerclamp_debug_show(struct seq_file *m, void *unused)
{
int i = 0;
seq_printf(m, "controlling cpu: %d\n", control_cpu);
seq_printf(m, "pct confidence steady dynamic (compensation)\n");
for (i = 0; i < MAX_TARGET_RATIO; i++) {
seq_printf(m, "%d\t%lu\t%lu\t%lu\n",
i,
cal_data[i].confidence,
cal_data[i].steady_comp,
cal_data[i].dynamic_comp);
}
return 0;
}
static int powerclamp_debug_open(struct inode *inode,
struct file *file)
{
return single_open(file, powerclamp_debug_show, inode->i_private);
}
static inline void powerclamp_create_debug_files(void)
{
debug_dir = debugfs_create_dir("intel_powerclamp", NULL);
if (!debug_dir)
return;
if (!debugfs_create_file("powerclamp_calib", S_IRUGO, debug_dir,
cal_data, &powerclamp_debug_fops))
goto file_error;
return;
file_error:
debugfs_remove_recursive(debug_dir);
}
static int __init powerclamp_init(void)
{
int retval;
int bitmap_size;
bitmap_size = BITS_TO_LONGS(num_possible_cpus()) * sizeof(long);
cpu_clamping_mask = kzalloc(bitmap_size, GFP_KERNEL);
if (!cpu_clamping_mask)
return -ENOMEM;
retval = powerclamp_probe();
if (retval)
goto exit_free;
window_size = 2;
register_hotcpu_notifier(&powerclamp_cpu_notifier);
powerclamp_thread = alloc_percpu(struct task_struct *);
if (!powerclamp_thread) {
retval = -ENOMEM;
goto exit_unregister;
}
cooling_dev = thermal_cooling_device_register("intel_powerclamp", NULL,
&powerclamp_cooling_ops);
if (IS_ERR(cooling_dev)) {
retval = -ENODEV;
goto exit_free_thread;
}
if (!duration)
duration = jiffies_to_msecs(DEFAULT_DURATION_JIFFIES);
powerclamp_create_debug_files();
return 0;
exit_free_thread:
free_percpu(powerclamp_thread);
exit_unregister:
unregister_hotcpu_notifier(&powerclamp_cpu_notifier);
exit_free:
kfree(cpu_clamping_mask);
return retval;
}
static void __exit powerclamp_exit(void)
{
unregister_hotcpu_notifier(&powerclamp_cpu_notifier);
end_power_clamp();
free_percpu(powerclamp_thread);
thermal_cooling_device_unregister(cooling_dev);
kfree(cpu_clamping_mask);
cancel_delayed_work_sync(&poll_pkg_cstate_work);
debugfs_remove_recursive(debug_dir);
}
