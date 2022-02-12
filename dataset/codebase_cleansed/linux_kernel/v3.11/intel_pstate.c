static inline int32_t mul_fp(int32_t x, int32_t y)
{
return ((int64_t)x * (int64_t)y) >> FRAC_BITS;
}
static inline int32_t div_fp(int32_t x, int32_t y)
{
return div_s64((int64_t)x << FRAC_BITS, (int64_t)y);
}
static inline void pid_reset(struct _pid *pid, int setpoint, int busy,
int deadband, int integral) {
pid->setpoint = setpoint;
pid->deadband = deadband;
pid->integral = int_tofp(integral);
pid->last_err = setpoint - busy;
}
static inline void pid_p_gain_set(struct _pid *pid, int percent)
{
pid->p_gain = div_fp(int_tofp(percent), int_tofp(100));
}
static inline void pid_i_gain_set(struct _pid *pid, int percent)
{
pid->i_gain = div_fp(int_tofp(percent), int_tofp(100));
}
static inline void pid_d_gain_set(struct _pid *pid, int percent)
{
pid->d_gain = div_fp(int_tofp(percent), int_tofp(100));
}
static signed int pid_calc(struct _pid *pid, int busy)
{
signed int err, result;
int32_t pterm, dterm, fp_error;
int32_t integral_limit;
err = pid->setpoint - busy;
fp_error = int_tofp(err);
if (abs(err) <= pid->deadband)
return 0;
pterm = mul_fp(pid->p_gain, fp_error);
pid->integral += fp_error;
integral_limit = int_tofp(30);
if (pid->integral > integral_limit)
pid->integral = integral_limit;
if (pid->integral < -integral_limit)
pid->integral = -integral_limit;
dterm = mul_fp(pid->d_gain, (err - pid->last_err));
pid->last_err = err;
result = pterm + mul_fp(pid->integral, pid->i_gain) + dterm;
return (signed int)fp_toint(result);
}
static inline void intel_pstate_busy_pid_reset(struct cpudata *cpu)
{
pid_p_gain_set(&cpu->pid, cpu->pstate_policy->p_gain_pct);
pid_d_gain_set(&cpu->pid, cpu->pstate_policy->d_gain_pct);
pid_i_gain_set(&cpu->pid, cpu->pstate_policy->i_gain_pct);
pid_reset(&cpu->pid,
cpu->pstate_policy->setpoint,
100,
cpu->pstate_policy->deadband,
0);
}
static inline void intel_pstate_reset_all_pid(void)
{
unsigned int cpu;
for_each_online_cpu(cpu) {
if (all_cpu_data[cpu])
intel_pstate_busy_pid_reset(all_cpu_data[cpu]);
}
}
static int pid_param_set(void *data, u64 val)
{
*(u32 *)data = val;
intel_pstate_reset_all_pid();
return 0;
}
static int pid_param_get(void *data, u64 *val)
{
*val = *(u32 *)data;
return 0;
}
static void intel_pstate_debug_expose_params(void)
{
int i = 0;
debugfs_parent = debugfs_create_dir("pstate_snb", NULL);
if (IS_ERR_OR_NULL(debugfs_parent))
return;
while (pid_files[i].name) {
debugfs_create_file(pid_files[i].name, 0660,
debugfs_parent, pid_files[i].value,
&fops_pid_param);
i++;
}
}
static ssize_t store_no_turbo(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
limits.no_turbo = clamp_t(int, input, 0 , 1);
return count;
}
static ssize_t store_max_perf_pct(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
limits.max_sysfs_pct = clamp_t(int, input, 0 , 100);
limits.max_perf_pct = min(limits.max_policy_pct, limits.max_sysfs_pct);
limits.max_perf = div_fp(int_tofp(limits.max_perf_pct), int_tofp(100));
return count;
}
static ssize_t store_min_perf_pct(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
limits.min_perf_pct = clamp_t(int, input, 0 , 100);
limits.min_perf = div_fp(int_tofp(limits.min_perf_pct), int_tofp(100));
return count;
}
static void intel_pstate_sysfs_expose_params(void)
{
int rc;
intel_pstate_kobject = kobject_create_and_add("intel_pstate",
&cpu_subsys.dev_root->kobj);
BUG_ON(!intel_pstate_kobject);
rc = sysfs_create_group(intel_pstate_kobject,
&intel_pstate_attr_group);
BUG_ON(rc);
}
static int intel_pstate_min_pstate(void)
{
u64 value;
rdmsrl(MSR_PLATFORM_INFO, value);
return (value >> 40) & 0xFF;
}
static int intel_pstate_max_pstate(void)
{
u64 value;
rdmsrl(MSR_PLATFORM_INFO, value);
return (value >> 8) & 0xFF;
}
static int intel_pstate_turbo_pstate(void)
{
u64 value;
int nont, ret;
rdmsrl(MSR_NHM_TURBO_RATIO_LIMIT, value);
nont = intel_pstate_max_pstate();
ret = ((value) & 255);
if (ret <= nont)
ret = nont;
return ret;
}
static void intel_pstate_get_min_max(struct cpudata *cpu, int *min, int *max)
{
int max_perf = cpu->pstate.turbo_pstate;
int min_perf;
if (limits.no_turbo)
max_perf = cpu->pstate.max_pstate;
max_perf = fp_toint(mul_fp(int_tofp(max_perf), limits.max_perf));
*max = clamp_t(int, max_perf,
cpu->pstate.min_pstate, cpu->pstate.turbo_pstate);
min_perf = fp_toint(mul_fp(int_tofp(max_perf), limits.min_perf));
*min = clamp_t(int, min_perf,
cpu->pstate.min_pstate, max_perf);
}
static void intel_pstate_set_pstate(struct cpudata *cpu, int pstate)
{
int max_perf, min_perf;
intel_pstate_get_min_max(cpu, &min_perf, &max_perf);
pstate = clamp_t(int, pstate, min_perf, max_perf);
if (pstate == cpu->pstate.current_pstate)
return;
trace_cpu_frequency(pstate * 100000, cpu->cpu);
cpu->pstate.current_pstate = pstate;
wrmsrl(MSR_IA32_PERF_CTL, pstate << 8);
}
static inline void intel_pstate_pstate_increase(struct cpudata *cpu, int steps)
{
int target;
target = cpu->pstate.current_pstate + steps;
intel_pstate_set_pstate(cpu, target);
}
static inline void intel_pstate_pstate_decrease(struct cpudata *cpu, int steps)
{
int target;
target = cpu->pstate.current_pstate - steps;
intel_pstate_set_pstate(cpu, target);
}
static void intel_pstate_get_cpu_pstates(struct cpudata *cpu)
{
sprintf(cpu->name, "Intel 2nd generation core");
cpu->pstate.min_pstate = intel_pstate_min_pstate();
cpu->pstate.max_pstate = intel_pstate_max_pstate();
cpu->pstate.turbo_pstate = intel_pstate_turbo_pstate();
intel_pstate_set_pstate(cpu, cpu->pstate.max_pstate);
}
static inline void intel_pstate_calc_busy(struct cpudata *cpu,
struct sample *sample)
{
u64 core_pct;
core_pct = div64_u64(sample->aperf * 100, sample->mperf);
sample->freq = cpu->pstate.max_pstate * core_pct * 1000;
sample->core_pct_busy = core_pct;
}
static inline void intel_pstate_sample(struct cpudata *cpu)
{
u64 aperf, mperf;
rdmsrl(MSR_IA32_APERF, aperf);
rdmsrl(MSR_IA32_MPERF, mperf);
cpu->sample_ptr = (cpu->sample_ptr + 1) % SAMPLE_COUNT;
cpu->samples[cpu->sample_ptr].aperf = aperf;
cpu->samples[cpu->sample_ptr].mperf = mperf;
cpu->samples[cpu->sample_ptr].aperf -= cpu->prev_aperf;
cpu->samples[cpu->sample_ptr].mperf -= cpu->prev_mperf;
intel_pstate_calc_busy(cpu, &cpu->samples[cpu->sample_ptr]);
cpu->prev_aperf = aperf;
cpu->prev_mperf = mperf;
}
static inline void intel_pstate_set_sample_time(struct cpudata *cpu)
{
int sample_time, delay;
sample_time = cpu->pstate_policy->sample_rate_ms;
delay = msecs_to_jiffies(sample_time);
mod_timer_pinned(&cpu->timer, jiffies + delay);
}
static inline int intel_pstate_get_scaled_busy(struct cpudata *cpu)
{
int32_t busy_scaled;
int32_t core_busy, max_pstate, current_pstate;
core_busy = int_tofp(cpu->samples[cpu->sample_ptr].core_pct_busy);
max_pstate = int_tofp(cpu->pstate.max_pstate);
current_pstate = int_tofp(cpu->pstate.current_pstate);
busy_scaled = mul_fp(core_busy, div_fp(max_pstate, current_pstate));
return fp_toint(busy_scaled);
}
static inline void intel_pstate_adjust_busy_pstate(struct cpudata *cpu)
{
int busy_scaled;
struct _pid *pid;
signed int ctl = 0;
int steps;
pid = &cpu->pid;
busy_scaled = intel_pstate_get_scaled_busy(cpu);
ctl = pid_calc(pid, busy_scaled);
steps = abs(ctl);
if (ctl < 0)
intel_pstate_pstate_increase(cpu, steps);
else
intel_pstate_pstate_decrease(cpu, steps);
}
static void intel_pstate_timer_func(unsigned long __data)
{
struct cpudata *cpu = (struct cpudata *) __data;
intel_pstate_sample(cpu);
intel_pstate_adjust_busy_pstate(cpu);
if (cpu->pstate.current_pstate == cpu->pstate.min_pstate) {
cpu->min_pstate_count++;
if (!(cpu->min_pstate_count % 5)) {
intel_pstate_set_pstate(cpu, cpu->pstate.max_pstate);
}
} else
cpu->min_pstate_count = 0;
intel_pstate_set_sample_time(cpu);
}
static int intel_pstate_init_cpu(unsigned int cpunum)
{
const struct x86_cpu_id *id;
struct cpudata *cpu;
id = x86_match_cpu(intel_pstate_cpu_ids);
if (!id)
return -ENODEV;
all_cpu_data[cpunum] = kzalloc(sizeof(struct cpudata), GFP_KERNEL);
if (!all_cpu_data[cpunum])
return -ENOMEM;
cpu = all_cpu_data[cpunum];
intel_pstate_get_cpu_pstates(cpu);
cpu->cpu = cpunum;
cpu->pstate_policy =
(struct pstate_adjust_policy *)id->driver_data;
init_timer_deferrable(&cpu->timer);
cpu->timer.function = intel_pstate_timer_func;
cpu->timer.data =
(unsigned long)cpu;
cpu->timer.expires = jiffies + HZ/100;
intel_pstate_busy_pid_reset(cpu);
intel_pstate_sample(cpu);
intel_pstate_set_pstate(cpu, cpu->pstate.max_pstate);
add_timer_on(&cpu->timer, cpunum);
pr_info("Intel pstate controlling: cpu %d\n", cpunum);
return 0;
}
static unsigned int intel_pstate_get(unsigned int cpu_num)
{
struct sample *sample;
struct cpudata *cpu;
cpu = all_cpu_data[cpu_num];
if (!cpu)
return 0;
sample = &cpu->samples[cpu->sample_ptr];
return sample->freq;
}
static int intel_pstate_set_policy(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
cpu = all_cpu_data[policy->cpu];
if (!policy->cpuinfo.max_freq)
return -ENODEV;
if (policy->policy == CPUFREQ_POLICY_PERFORMANCE) {
limits.min_perf_pct = 100;
limits.min_perf = int_tofp(1);
limits.max_perf_pct = 100;
limits.max_perf = int_tofp(1);
limits.no_turbo = 0;
return 0;
}
limits.min_perf_pct = (policy->min * 100) / policy->cpuinfo.max_freq;
limits.min_perf_pct = clamp_t(int, limits.min_perf_pct, 0 , 100);
limits.min_perf = div_fp(int_tofp(limits.min_perf_pct), int_tofp(100));
limits.max_policy_pct = policy->max * 100 / policy->cpuinfo.max_freq;
limits.max_policy_pct = clamp_t(int, limits.max_policy_pct, 0 , 100);
limits.max_perf_pct = min(limits.max_policy_pct, limits.max_sysfs_pct);
limits.max_perf = div_fp(int_tofp(limits.max_perf_pct), int_tofp(100));
return 0;
}
static int intel_pstate_verify_policy(struct cpufreq_policy *policy)
{
cpufreq_verify_within_limits(policy,
policy->cpuinfo.min_freq,
policy->cpuinfo.max_freq);
if ((policy->policy != CPUFREQ_POLICY_POWERSAVE) &&
(policy->policy != CPUFREQ_POLICY_PERFORMANCE))
return -EINVAL;
return 0;
}
static int intel_pstate_cpu_exit(struct cpufreq_policy *policy)
{
int cpu = policy->cpu;
del_timer(&all_cpu_data[cpu]->timer);
kfree(all_cpu_data[cpu]);
all_cpu_data[cpu] = NULL;
return 0;
}
static int intel_pstate_cpu_init(struct cpufreq_policy *policy)
{
int rc, min_pstate, max_pstate;
struct cpudata *cpu;
rc = intel_pstate_init_cpu(policy->cpu);
if (rc)
return rc;
cpu = all_cpu_data[policy->cpu];
if (!limits.no_turbo &&
limits.min_perf_pct == 100 && limits.max_perf_pct == 100)
policy->policy = CPUFREQ_POLICY_PERFORMANCE;
else
policy->policy = CPUFREQ_POLICY_POWERSAVE;
intel_pstate_get_min_max(cpu, &min_pstate, &max_pstate);
policy->min = min_pstate * 100000;
policy->max = max_pstate * 100000;
policy->cpuinfo.min_freq = cpu->pstate.min_pstate * 100000;
policy->cpuinfo.max_freq = cpu->pstate.turbo_pstate * 100000;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
cpumask_set_cpu(policy->cpu, policy->cpus);
return 0;
}
static int intel_pstate_msrs_not_valid(void)
{
u64 aperf, mperf, tmp;
rdmsrl(MSR_IA32_APERF, aperf);
rdmsrl(MSR_IA32_MPERF, mperf);
if (!intel_pstate_min_pstate() ||
!intel_pstate_max_pstate() ||
!intel_pstate_turbo_pstate())
return -ENODEV;
rdmsrl(MSR_IA32_APERF, tmp);
if (!(tmp - aperf))
return -ENODEV;
rdmsrl(MSR_IA32_MPERF, tmp);
if (!(tmp - mperf))
return -ENODEV;
return 0;
}
static int __init intel_pstate_init(void)
{
int cpu, rc = 0;
const struct x86_cpu_id *id;
if (no_load)
return -ENODEV;
id = x86_match_cpu(intel_pstate_cpu_ids);
if (!id)
return -ENODEV;
if (intel_pstate_msrs_not_valid())
return -ENODEV;
pr_info("Intel P-state driver initializing.\n");
all_cpu_data = vzalloc(sizeof(void *) * num_possible_cpus());
if (!all_cpu_data)
return -ENOMEM;
rc = cpufreq_register_driver(&intel_pstate_driver);
if (rc)
goto out;
intel_pstate_debug_expose_params();
intel_pstate_sysfs_expose_params();
return rc;
out:
get_online_cpus();
for_each_online_cpu(cpu) {
if (all_cpu_data[cpu]) {
del_timer_sync(&all_cpu_data[cpu]->timer);
kfree(all_cpu_data[cpu]);
}
}
put_online_cpus();
vfree(all_cpu_data);
return -ENODEV;
}
static int __init intel_pstate_setup(char *str)
{
if (!str)
return -EINVAL;
if (!strcmp(str, "disable"))
no_load = 1;
return 0;
}
