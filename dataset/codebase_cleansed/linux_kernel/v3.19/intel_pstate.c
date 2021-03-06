static inline int32_t mul_fp(int32_t x, int32_t y)
{
return ((int64_t)x * (int64_t)y) >> FRAC_BITS;
}
static inline int32_t div_fp(int32_t x, int32_t y)
{
return div_s64((int64_t)x << FRAC_BITS, y);
}
static inline int ceiling_fp(int32_t x)
{
int mask, ret;
ret = fp_toint(x);
mask = (1 << FRAC_BITS) - 1;
if (x & mask)
ret += 1;
return ret;
}
static inline void pid_reset(struct _pid *pid, int setpoint, int busy,
int deadband, int integral) {
pid->setpoint = setpoint;
pid->deadband = deadband;
pid->integral = int_tofp(integral);
pid->last_err = int_tofp(setpoint) - int_tofp(busy);
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
static signed int pid_calc(struct _pid *pid, int32_t busy)
{
signed int result;
int32_t pterm, dterm, fp_error;
int32_t integral_limit;
fp_error = int_tofp(pid->setpoint) - busy;
if (abs(fp_error) <= int_tofp(pid->deadband))
return 0;
pterm = mul_fp(pid->p_gain, fp_error);
pid->integral += fp_error;
integral_limit = int_tofp(30);
if (pid->integral > integral_limit)
pid->integral = integral_limit;
if (pid->integral < -integral_limit)
pid->integral = -integral_limit;
dterm = mul_fp(pid->d_gain, fp_error - pid->last_err);
pid->last_err = fp_error;
result = pterm + mul_fp(pid->integral, pid->i_gain) + dterm;
result = result + (1 << (FRAC_BITS-1));
return (signed int)fp_toint(result);
}
static inline void intel_pstate_busy_pid_reset(struct cpudata *cpu)
{
pid_p_gain_set(&cpu->pid, pid_params.p_gain_pct);
pid_d_gain_set(&cpu->pid, pid_params.d_gain_pct);
pid_i_gain_set(&cpu->pid, pid_params.i_gain_pct);
pid_reset(&cpu->pid, pid_params.setpoint, 100, pid_params.deadband, 0);
}
static inline void intel_pstate_reset_all_pid(void)
{
unsigned int cpu;
for_each_online_cpu(cpu) {
if (all_cpu_data[cpu])
intel_pstate_busy_pid_reset(all_cpu_data[cpu]);
}
}
static inline void update_turbo_state(void)
{
u64 misc_en;
struct cpudata *cpu;
cpu = all_cpu_data[0];
rdmsrl(MSR_IA32_MISC_ENABLE, misc_en);
limits.turbo_disabled =
(misc_en & MSR_IA32_MISC_ENABLE_TURBO_DISABLE ||
cpu->pstate.max_pstate == cpu->pstate.turbo_pstate);
}
static void intel_pstate_hwp_set(void)
{
int min, max, cpu;
u64 value, freq;
get_online_cpus();
for_each_online_cpu(cpu) {
rdmsrl_on_cpu(cpu, MSR_HWP_REQUEST, &value);
min = PCT_TO_HWP(limits.min_perf_pct);
value &= ~HWP_MIN_PERF(~0L);
value |= HWP_MIN_PERF(min);
max = PCT_TO_HWP(limits.max_perf_pct);
if (limits.no_turbo) {
rdmsrl( MSR_HWP_CAPABILITIES, freq);
max = HWP_GUARANTEED_PERF(freq);
}
value &= ~HWP_MAX_PERF(~0L);
value |= HWP_MAX_PERF(max);
wrmsrl_on_cpu(cpu, MSR_HWP_REQUEST, value);
}
put_online_cpus();
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
static void __init intel_pstate_debug_expose_params(void)
{
struct dentry *debugfs_parent;
int i = 0;
if (hwp_active)
return;
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
static ssize_t show_no_turbo(struct kobject *kobj,
struct attribute *attr, char *buf)
{
ssize_t ret;
update_turbo_state();
if (limits.turbo_disabled)
ret = sprintf(buf, "%u\n", limits.turbo_disabled);
else
ret = sprintf(buf, "%u\n", limits.no_turbo);
return ret;
}
static ssize_t store_no_turbo(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
unsigned int input;
int ret;
ret = sscanf(buf, "%u", &input);
if (ret != 1)
return -EINVAL;
update_turbo_state();
if (limits.turbo_disabled) {
pr_warn("Turbo disabled by BIOS or unavailable on processor\n");
return -EPERM;
}
limits.no_turbo = clamp_t(int, input, 0, 1);
if (hwp_active)
intel_pstate_hwp_set();
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
if (hwp_active)
intel_pstate_hwp_set();
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
if (hwp_active)
intel_pstate_hwp_set();
return count;
}
static void __init intel_pstate_sysfs_expose_params(void)
{
struct kobject *intel_pstate_kobject;
int rc;
intel_pstate_kobject = kobject_create_and_add("intel_pstate",
&cpu_subsys.dev_root->kobj);
BUG_ON(!intel_pstate_kobject);
rc = sysfs_create_group(intel_pstate_kobject, &intel_pstate_attr_group);
BUG_ON(rc);
}
static void intel_pstate_hwp_enable(void)
{
hwp_active++;
pr_info("intel_pstate HWP enabled\n");
wrmsrl( MSR_PM_ENABLE, 0x1);
}
static int byt_get_min_pstate(void)
{
u64 value;
rdmsrl(BYT_RATIOS, value);
return (value >> 8) & 0x7F;
}
static int byt_get_max_pstate(void)
{
u64 value;
rdmsrl(BYT_RATIOS, value);
return (value >> 16) & 0x7F;
}
static int byt_get_turbo_pstate(void)
{
u64 value;
rdmsrl(BYT_TURBO_RATIOS, value);
return value & 0x7F;
}
static void byt_set_pstate(struct cpudata *cpudata, int pstate)
{
u64 val;
int32_t vid_fp;
u32 vid;
val = pstate << 8;
if (limits.no_turbo && !limits.turbo_disabled)
val |= (u64)1 << 32;
vid_fp = cpudata->vid.min + mul_fp(
int_tofp(pstate - cpudata->pstate.min_pstate),
cpudata->vid.ratio);
vid_fp = clamp_t(int32_t, vid_fp, cpudata->vid.min, cpudata->vid.max);
vid = ceiling_fp(vid_fp);
if (pstate > cpudata->pstate.max_pstate)
vid = cpudata->vid.turbo;
val |= vid;
wrmsrl(MSR_IA32_PERF_CTL, val);
}
static int byt_get_scaling(void)
{
u64 value;
int i;
rdmsrl(MSR_FSB_FREQ, value);
i = value & 0x3;
BUG_ON(i > BYT_BCLK_FREQS);
return byt_freq_table[i] * 100;
}
static void byt_get_vid(struct cpudata *cpudata)
{
u64 value;
rdmsrl(BYT_VIDS, value);
cpudata->vid.min = int_tofp((value >> 8) & 0x7f);
cpudata->vid.max = int_tofp((value >> 16) & 0x7f);
cpudata->vid.ratio = div_fp(
cpudata->vid.max - cpudata->vid.min,
int_tofp(cpudata->pstate.max_pstate -
cpudata->pstate.min_pstate));
rdmsrl(BYT_TURBO_VIDS, value);
cpudata->vid.turbo = value & 0x7f;
}
static int core_get_min_pstate(void)
{
u64 value;
rdmsrl(MSR_PLATFORM_INFO, value);
return (value >> 40) & 0xFF;
}
static int core_get_max_pstate(void)
{
u64 value;
rdmsrl(MSR_PLATFORM_INFO, value);
return (value >> 8) & 0xFF;
}
static int core_get_turbo_pstate(void)
{
u64 value;
int nont, ret;
rdmsrl(MSR_NHM_TURBO_RATIO_LIMIT, value);
nont = core_get_max_pstate();
ret = (value) & 255;
if (ret <= nont)
ret = nont;
return ret;
}
static inline int core_get_scaling(void)
{
return 100000;
}
static void core_set_pstate(struct cpudata *cpudata, int pstate)
{
u64 val;
val = pstate << 8;
if (limits.no_turbo && !limits.turbo_disabled)
val |= (u64)1 << 32;
wrmsrl_on_cpu(cpudata->cpu, MSR_IA32_PERF_CTL, val);
}
static void intel_pstate_get_min_max(struct cpudata *cpu, int *min, int *max)
{
int max_perf = cpu->pstate.turbo_pstate;
int max_perf_adj;
int min_perf;
if (limits.no_turbo || limits.turbo_disabled)
max_perf = cpu->pstate.max_pstate;
max_perf_adj = fp_toint(mul_fp(int_tofp(max_perf), limits.max_perf));
*max = clamp_t(int, max_perf_adj,
cpu->pstate.min_pstate, cpu->pstate.turbo_pstate);
min_perf = fp_toint(mul_fp(int_tofp(max_perf), limits.min_perf));
*min = clamp_t(int, min_perf, cpu->pstate.min_pstate, max_perf);
}
static void intel_pstate_set_pstate(struct cpudata *cpu, int pstate)
{
int max_perf, min_perf;
update_turbo_state();
intel_pstate_get_min_max(cpu, &min_perf, &max_perf);
pstate = clamp_t(int, pstate, min_perf, max_perf);
if (pstate == cpu->pstate.current_pstate)
return;
trace_cpu_frequency(pstate * cpu->pstate.scaling, cpu->cpu);
cpu->pstate.current_pstate = pstate;
pstate_funcs.set(cpu, pstate);
}
static void intel_pstate_get_cpu_pstates(struct cpudata *cpu)
{
cpu->pstate.min_pstate = pstate_funcs.get_min();
cpu->pstate.max_pstate = pstate_funcs.get_max();
cpu->pstate.turbo_pstate = pstate_funcs.get_turbo();
cpu->pstate.scaling = pstate_funcs.get_scaling();
if (pstate_funcs.get_vid)
pstate_funcs.get_vid(cpu);
intel_pstate_set_pstate(cpu, cpu->pstate.min_pstate);
}
static inline void intel_pstate_calc_busy(struct cpudata *cpu)
{
struct sample *sample = &cpu->sample;
int64_t core_pct;
core_pct = int_tofp(sample->aperf) * int_tofp(100);
core_pct = div64_u64(core_pct, int_tofp(sample->mperf));
sample->freq = fp_toint(
mul_fp(int_tofp(
cpu->pstate.max_pstate * cpu->pstate.scaling / 100),
core_pct));
sample->core_pct_busy = (int32_t)core_pct;
}
static inline void intel_pstate_sample(struct cpudata *cpu)
{
u64 aperf, mperf;
unsigned long flags;
local_irq_save(flags);
rdmsrl(MSR_IA32_APERF, aperf);
rdmsrl(MSR_IA32_MPERF, mperf);
local_irq_restore(flags);
cpu->last_sample_time = cpu->sample.time;
cpu->sample.time = ktime_get();
cpu->sample.aperf = aperf;
cpu->sample.mperf = mperf;
cpu->sample.aperf -= cpu->prev_aperf;
cpu->sample.mperf -= cpu->prev_mperf;
intel_pstate_calc_busy(cpu);
cpu->prev_aperf = aperf;
cpu->prev_mperf = mperf;
}
static inline void intel_hwp_set_sample_time(struct cpudata *cpu)
{
int delay;
delay = msecs_to_jiffies(50);
mod_timer_pinned(&cpu->timer, jiffies + delay);
}
static inline void intel_pstate_set_sample_time(struct cpudata *cpu)
{
int delay;
delay = msecs_to_jiffies(pid_params.sample_rate_ms);
mod_timer_pinned(&cpu->timer, jiffies + delay);
}
static inline int32_t intel_pstate_get_scaled_busy(struct cpudata *cpu)
{
int32_t core_busy, max_pstate, current_pstate, sample_ratio;
u32 duration_us;
u32 sample_time;
core_busy = cpu->sample.core_pct_busy;
max_pstate = int_tofp(cpu->pstate.max_pstate);
current_pstate = int_tofp(cpu->pstate.current_pstate);
core_busy = mul_fp(core_busy, div_fp(max_pstate, current_pstate));
sample_time = pid_params.sample_rate_ms * USEC_PER_MSEC;
duration_us = (u32) ktime_us_delta(cpu->sample.time,
cpu->last_sample_time);
if (duration_us > sample_time * 3) {
sample_ratio = div_fp(int_tofp(sample_time),
int_tofp(duration_us));
core_busy = mul_fp(core_busy, sample_ratio);
}
return core_busy;
}
static inline void intel_pstate_adjust_busy_pstate(struct cpudata *cpu)
{
int32_t busy_scaled;
struct _pid *pid;
signed int ctl;
pid = &cpu->pid;
busy_scaled = intel_pstate_get_scaled_busy(cpu);
ctl = pid_calc(pid, busy_scaled);
intel_pstate_set_pstate(cpu, cpu->pstate.current_pstate - ctl);
}
static void intel_hwp_timer_func(unsigned long __data)
{
struct cpudata *cpu = (struct cpudata *) __data;
intel_pstate_sample(cpu);
intel_hwp_set_sample_time(cpu);
}
static void intel_pstate_timer_func(unsigned long __data)
{
struct cpudata *cpu = (struct cpudata *) __data;
struct sample *sample;
intel_pstate_sample(cpu);
sample = &cpu->sample;
intel_pstate_adjust_busy_pstate(cpu);
trace_pstate_sample(fp_toint(sample->core_pct_busy),
fp_toint(intel_pstate_get_scaled_busy(cpu)),
cpu->pstate.current_pstate,
sample->mperf,
sample->aperf,
sample->freq);
intel_pstate_set_sample_time(cpu);
}
static int intel_pstate_init_cpu(unsigned int cpunum)
{
struct cpudata *cpu;
if (!all_cpu_data[cpunum])
all_cpu_data[cpunum] = kzalloc(sizeof(struct cpudata),
GFP_KERNEL);
if (!all_cpu_data[cpunum])
return -ENOMEM;
cpu = all_cpu_data[cpunum];
cpu->cpu = cpunum;
intel_pstate_get_cpu_pstates(cpu);
init_timer_deferrable(&cpu->timer);
cpu->timer.data = (unsigned long)cpu;
cpu->timer.expires = jiffies + HZ/100;
if (!hwp_active)
cpu->timer.function = intel_pstate_timer_func;
else
cpu->timer.function = intel_hwp_timer_func;
intel_pstate_busy_pid_reset(cpu);
intel_pstate_sample(cpu);
add_timer_on(&cpu->timer, cpunum);
pr_debug("Intel pstate controlling: cpu %d\n", cpunum);
return 0;
}
static unsigned int intel_pstate_get(unsigned int cpu_num)
{
struct sample *sample;
struct cpudata *cpu;
cpu = all_cpu_data[cpu_num];
if (!cpu)
return 0;
sample = &cpu->sample;
return sample->freq;
}
static int intel_pstate_set_policy(struct cpufreq_policy *policy)
{
if (!policy->cpuinfo.max_freq)
return -ENODEV;
if (policy->policy == CPUFREQ_POLICY_PERFORMANCE) {
limits.min_perf_pct = 100;
limits.min_perf = int_tofp(1);
limits.max_policy_pct = 100;
limits.max_perf_pct = 100;
limits.max_perf = int_tofp(1);
limits.no_turbo = 0;
return 0;
}
limits.min_perf_pct = (policy->min * 100) / policy->cpuinfo.max_freq;
limits.min_perf_pct = clamp_t(int, limits.min_perf_pct, 0 , 100);
limits.min_perf = div_fp(int_tofp(limits.min_perf_pct), int_tofp(100));
limits.max_policy_pct = (policy->max * 100) / policy->cpuinfo.max_freq;
limits.max_policy_pct = clamp_t(int, limits.max_policy_pct, 0 , 100);
limits.max_perf_pct = min(limits.max_policy_pct, limits.max_sysfs_pct);
limits.max_perf = div_fp(int_tofp(limits.max_perf_pct), int_tofp(100));
if (hwp_active)
intel_pstate_hwp_set();
return 0;
}
static int intel_pstate_verify_policy(struct cpufreq_policy *policy)
{
cpufreq_verify_within_cpu_limits(policy);
if (policy->policy != CPUFREQ_POLICY_POWERSAVE &&
policy->policy != CPUFREQ_POLICY_PERFORMANCE)
return -EINVAL;
return 0;
}
static void intel_pstate_stop_cpu(struct cpufreq_policy *policy)
{
int cpu_num = policy->cpu;
struct cpudata *cpu = all_cpu_data[cpu_num];
pr_info("intel_pstate CPU %d exiting\n", cpu_num);
del_timer_sync(&all_cpu_data[cpu_num]->timer);
if (hwp_active)
return;
intel_pstate_set_pstate(cpu, cpu->pstate.min_pstate);
}
static int intel_pstate_cpu_init(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
int rc;
rc = intel_pstate_init_cpu(policy->cpu);
if (rc)
return rc;
cpu = all_cpu_data[policy->cpu];
if (limits.min_perf_pct == 100 && limits.max_perf_pct == 100)
policy->policy = CPUFREQ_POLICY_PERFORMANCE;
else
policy->policy = CPUFREQ_POLICY_POWERSAVE;
policy->min = cpu->pstate.min_pstate * cpu->pstate.scaling;
policy->max = cpu->pstate.turbo_pstate * cpu->pstate.scaling;
policy->cpuinfo.min_freq = cpu->pstate.min_pstate * cpu->pstate.scaling;
policy->cpuinfo.max_freq =
cpu->pstate.turbo_pstate * cpu->pstate.scaling;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
cpumask_set_cpu(policy->cpu, policy->cpus);
return 0;
}
static int intel_pstate_msrs_not_valid(void)
{
u64 aperf, mperf, tmp;
rdmsrl(MSR_IA32_APERF, aperf);
rdmsrl(MSR_IA32_MPERF, mperf);
if (!pstate_funcs.get_max() ||
!pstate_funcs.get_min() ||
!pstate_funcs.get_turbo())
return -ENODEV;
rdmsrl(MSR_IA32_APERF, tmp);
if (!(tmp - aperf))
return -ENODEV;
rdmsrl(MSR_IA32_MPERF, tmp);
if (!(tmp - mperf))
return -ENODEV;
return 0;
}
static void copy_pid_params(struct pstate_adjust_policy *policy)
{
pid_params.sample_rate_ms = policy->sample_rate_ms;
pid_params.p_gain_pct = policy->p_gain_pct;
pid_params.i_gain_pct = policy->i_gain_pct;
pid_params.d_gain_pct = policy->d_gain_pct;
pid_params.deadband = policy->deadband;
pid_params.setpoint = policy->setpoint;
}
static void copy_cpu_funcs(struct pstate_funcs *funcs)
{
pstate_funcs.get_max = funcs->get_max;
pstate_funcs.get_min = funcs->get_min;
pstate_funcs.get_turbo = funcs->get_turbo;
pstate_funcs.get_scaling = funcs->get_scaling;
pstate_funcs.set = funcs->set;
pstate_funcs.get_vid = funcs->get_vid;
}
static bool intel_pstate_no_acpi_pss(void)
{
int i;
for_each_possible_cpu(i) {
acpi_status status;
union acpi_object *pss;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_processor *pr = per_cpu(processors, i);
if (!pr)
continue;
status = acpi_evaluate_object(pr->handle, "_PSS", NULL, &buffer);
if (ACPI_FAILURE(status))
continue;
pss = buffer.pointer;
if (pss && pss->type == ACPI_TYPE_PACKAGE) {
kfree(pss);
return false;
}
kfree(pss);
}
return true;
}
static bool intel_pstate_has_acpi_ppc(void)
{
int i;
for_each_possible_cpu(i) {
struct acpi_processor *pr = per_cpu(processors, i);
if (!pr)
continue;
if (acpi_has_method(pr->handle, "_PPC"))
return true;
}
return false;
}
static bool intel_pstate_platform_pwr_mgmt_exists(void)
{
struct acpi_table_header hdr;
struct hw_vendor_info *v_info;
const struct x86_cpu_id *id;
u64 misc_pwr;
id = x86_match_cpu(intel_pstate_cpu_oob_ids);
if (id) {
rdmsrl(MSR_MISC_PWR_MGMT, misc_pwr);
if ( misc_pwr & (1 << 8))
return true;
}
if (acpi_disabled ||
ACPI_FAILURE(acpi_get_table_header(ACPI_SIG_FADT, 0, &hdr)))
return false;
for (v_info = vendor_info; v_info->valid; v_info++) {
if (!strncmp(hdr.oem_id, v_info->oem_id, ACPI_OEM_ID_SIZE) &&
!strncmp(hdr.oem_table_id, v_info->oem_table_id,
ACPI_OEM_TABLE_ID_SIZE))
switch (v_info->oem_pwr_table) {
case PSS:
return intel_pstate_no_acpi_pss();
case PPC:
return intel_pstate_has_acpi_ppc() &&
(!force_load);
}
}
return false;
}
static inline bool intel_pstate_platform_pwr_mgmt_exists(void) { return false; }
static inline bool intel_pstate_has_acpi_ppc(void) { return false; }
static int __init intel_pstate_init(void)
{
int cpu, rc = 0;
const struct x86_cpu_id *id;
struct cpu_defaults *cpu_info;
struct cpuinfo_x86 *c = &boot_cpu_data;
if (no_load)
return -ENODEV;
id = x86_match_cpu(intel_pstate_cpu_ids);
if (!id)
return -ENODEV;
if (intel_pstate_platform_pwr_mgmt_exists())
return -ENODEV;
cpu_info = (struct cpu_defaults *)id->driver_data;
copy_pid_params(&cpu_info->pid_policy);
copy_cpu_funcs(&cpu_info->funcs);
if (intel_pstate_msrs_not_valid())
return -ENODEV;
pr_info("Intel P-state driver initializing.\n");
all_cpu_data = vzalloc(sizeof(void *) * num_possible_cpus());
if (!all_cpu_data)
return -ENOMEM;
if (cpu_has(c,X86_FEATURE_HWP) && !no_hwp)
intel_pstate_hwp_enable();
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
if (!strcmp(str, "no_hwp"))
no_hwp = 1;
if (!strcmp(str, "force"))
force_load = 1;
return 0;
}
