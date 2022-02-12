static inline int32_t mul_fp(int32_t x, int32_t y)
{
return ((int64_t)x * (int64_t)y) >> FRAC_BITS;
}
static inline int32_t div_fp(s64 x, s64 y)
{
return div64_s64((int64_t)x << FRAC_BITS, y);
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
static inline u64 mul_ext_fp(u64 x, u64 y)
{
return (x * y) >> EXT_FRAC_BITS;
}
static inline u64 div_ext_fp(u64 x, u64 y)
{
return div64_u64(x << EXT_FRAC_BITS, y);
}
static bool intel_pstate_get_ppc_enable_status(void)
{
if (acpi_gbl_FADT.preferred_profile == PM_ENTERPRISE_SERVER ||
acpi_gbl_FADT.preferred_profile == PM_PERFORMANCE_SERVER)
return true;
return acpi_ppc;
}
static void intel_pstate_init_acpi_perf_limits(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
int ret;
int i;
if (hwp_active)
return;
if (!intel_pstate_get_ppc_enable_status())
return;
cpu = all_cpu_data[policy->cpu];
ret = acpi_processor_register_performance(&cpu->acpi_perf_data,
policy->cpu);
if (ret)
return;
if (cpu->acpi_perf_data.control_register.space_id !=
ACPI_ADR_SPACE_FIXED_HARDWARE)
goto err;
if (cpu->acpi_perf_data.state_count < 2)
goto err;
pr_debug("CPU%u - ACPI _PSS perf data\n", policy->cpu);
for (i = 0; i < cpu->acpi_perf_data.state_count; i++) {
pr_debug(" %cP%d: %u MHz, %u mW, 0x%x\n",
(i == cpu->acpi_perf_data.state ? '*' : ' '), i,
(u32) cpu->acpi_perf_data.states[i].core_frequency,
(u32) cpu->acpi_perf_data.states[i].power,
(u32) cpu->acpi_perf_data.states[i].control);
}
if (!limits->turbo_disabled)
cpu->acpi_perf_data.states[0].core_frequency =
policy->cpuinfo.max_freq / 1000;
cpu->valid_pss_table = true;
pr_debug("_PPC limits will be enforced\n");
return;
err:
cpu->valid_pss_table = false;
acpi_processor_unregister_performance(policy->cpu);
}
static void intel_pstate_exit_perf_limits(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
cpu = all_cpu_data[policy->cpu];
if (!cpu->valid_pss_table)
return;
acpi_processor_unregister_performance(policy->cpu);
}
static void intel_pstate_init_acpi_perf_limits(struct cpufreq_policy *policy)
{
}
static void intel_pstate_exit_perf_limits(struct cpufreq_policy *policy)
{
}
static inline void pid_reset(struct _pid *pid, int setpoint, int busy,
int deadband, int integral) {
pid->setpoint = int_tofp(setpoint);
pid->deadband = int_tofp(deadband);
pid->integral = int_tofp(integral);
pid->last_err = int_tofp(setpoint) - int_tofp(busy);
}
static inline void pid_p_gain_set(struct _pid *pid, int percent)
{
pid->p_gain = div_fp(percent, 100);
}
static inline void pid_i_gain_set(struct _pid *pid, int percent)
{
pid->i_gain = div_fp(percent, 100);
}
static inline void pid_d_gain_set(struct _pid *pid, int percent)
{
pid->d_gain = div_fp(percent, 100);
}
static signed int pid_calc(struct _pid *pid, int32_t busy)
{
signed int result;
int32_t pterm, dterm, fp_error;
int32_t integral_limit;
fp_error = pid->setpoint - busy;
if (abs(fp_error) <= pid->deadband)
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
limits->turbo_disabled =
(misc_en & MSR_IA32_MISC_ENABLE_TURBO_DISABLE ||
cpu->pstate.max_pstate == cpu->pstate.turbo_pstate);
}
static void intel_pstate_hwp_set(const struct cpumask *cpumask)
{
int min, hw_min, max, hw_max, cpu, range, adj_range;
u64 value, cap;
rdmsrl(MSR_HWP_CAPABILITIES, cap);
hw_min = HWP_LOWEST_PERF(cap);
hw_max = HWP_HIGHEST_PERF(cap);
range = hw_max - hw_min;
for_each_cpu(cpu, cpumask) {
rdmsrl_on_cpu(cpu, MSR_HWP_REQUEST, &value);
adj_range = limits->min_perf_pct * range / 100;
min = hw_min + adj_range;
value &= ~HWP_MIN_PERF(~0L);
value |= HWP_MIN_PERF(min);
adj_range = limits->max_perf_pct * range / 100;
max = hw_min + adj_range;
if (limits->no_turbo) {
hw_max = HWP_GUARANTEED_PERF(cap);
if (hw_max < max)
max = hw_max;
}
value &= ~HWP_MAX_PERF(~0L);
value |= HWP_MAX_PERF(max);
wrmsrl_on_cpu(cpu, MSR_HWP_REQUEST, value);
}
}
static int intel_pstate_hwp_set_policy(struct cpufreq_policy *policy)
{
if (hwp_active)
intel_pstate_hwp_set(policy->cpus);
return 0;
}
static void intel_pstate_hwp_set_online_cpus(void)
{
get_online_cpus();
intel_pstate_hwp_set(cpu_online_mask);
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
static ssize_t show_turbo_pct(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct cpudata *cpu;
int total, no_turbo, turbo_pct;
uint32_t turbo_fp;
cpu = all_cpu_data[0];
total = cpu->pstate.turbo_pstate - cpu->pstate.min_pstate + 1;
no_turbo = cpu->pstate.max_pstate - cpu->pstate.min_pstate + 1;
turbo_fp = div_fp(no_turbo, total);
turbo_pct = 100 - fp_toint(mul_fp(turbo_fp, int_tofp(100)));
return sprintf(buf, "%u\n", turbo_pct);
}
static ssize_t show_num_pstates(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct cpudata *cpu;
int total;
cpu = all_cpu_data[0];
total = cpu->pstate.turbo_pstate - cpu->pstate.min_pstate + 1;
return sprintf(buf, "%u\n", total);
}
static ssize_t show_no_turbo(struct kobject *kobj,
struct attribute *attr, char *buf)
{
ssize_t ret;
update_turbo_state();
if (limits->turbo_disabled)
ret = sprintf(buf, "%u\n", limits->turbo_disabled);
else
ret = sprintf(buf, "%u\n", limits->no_turbo);
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
if (limits->turbo_disabled) {
pr_warn("Turbo disabled by BIOS or unavailable on processor\n");
return -EPERM;
}
limits->no_turbo = clamp_t(int, input, 0, 1);
if (hwp_active)
intel_pstate_hwp_set_online_cpus();
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
limits->max_sysfs_pct = clamp_t(int, input, 0 , 100);
limits->max_perf_pct = min(limits->max_policy_pct,
limits->max_sysfs_pct);
limits->max_perf_pct = max(limits->min_policy_pct,
limits->max_perf_pct);
limits->max_perf_pct = max(limits->min_perf_pct,
limits->max_perf_pct);
limits->max_perf = div_fp(limits->max_perf_pct, 100);
if (hwp_active)
intel_pstate_hwp_set_online_cpus();
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
limits->min_sysfs_pct = clamp_t(int, input, 0 , 100);
limits->min_perf_pct = max(limits->min_policy_pct,
limits->min_sysfs_pct);
limits->min_perf_pct = min(limits->max_policy_pct,
limits->min_perf_pct);
limits->min_perf_pct = min(limits->max_perf_pct,
limits->min_perf_pct);
limits->min_perf = div_fp(limits->min_perf_pct, 100);
if (hwp_active)
intel_pstate_hwp_set_online_cpus();
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
static void intel_pstate_hwp_enable(struct cpudata *cpudata)
{
if (static_cpu_has(X86_FEATURE_HWP_NOTIFY))
wrmsrl_on_cpu(cpudata->cpu, MSR_HWP_INTERRUPT, 0x00);
wrmsrl_on_cpu(cpudata->cpu, MSR_PM_ENABLE, 0x1);
}
static int atom_get_min_pstate(void)
{
u64 value;
rdmsrl(ATOM_RATIOS, value);
return (value >> 8) & 0x7F;
}
static int atom_get_max_pstate(void)
{
u64 value;
rdmsrl(ATOM_RATIOS, value);
return (value >> 16) & 0x7F;
}
static int atom_get_turbo_pstate(void)
{
u64 value;
rdmsrl(ATOM_TURBO_RATIOS, value);
return value & 0x7F;
}
static u64 atom_get_val(struct cpudata *cpudata, int pstate)
{
u64 val;
int32_t vid_fp;
u32 vid;
val = (u64)pstate << 8;
if (limits->no_turbo && !limits->turbo_disabled)
val |= (u64)1 << 32;
vid_fp = cpudata->vid.min + mul_fp(
int_tofp(pstate - cpudata->pstate.min_pstate),
cpudata->vid.ratio);
vid_fp = clamp_t(int32_t, vid_fp, cpudata->vid.min, cpudata->vid.max);
vid = ceiling_fp(vid_fp);
if (pstate > cpudata->pstate.max_pstate)
vid = cpudata->vid.turbo;
return val | vid;
}
static int silvermont_get_scaling(void)
{
u64 value;
int i;
static int silvermont_freq_table[] = {
83300, 100000, 133300, 116700, 80000};
rdmsrl(MSR_FSB_FREQ, value);
i = value & 0x7;
WARN_ON(i > 4);
return silvermont_freq_table[i];
}
static int airmont_get_scaling(void)
{
u64 value;
int i;
static int airmont_freq_table[] = {
83300, 100000, 133300, 116700, 80000,
93300, 90000, 88900, 87500};
rdmsrl(MSR_FSB_FREQ, value);
i = value & 0xF;
WARN_ON(i > 8);
return airmont_freq_table[i];
}
static void atom_get_vid(struct cpudata *cpudata)
{
u64 value;
rdmsrl(ATOM_VIDS, value);
cpudata->vid.min = int_tofp((value >> 8) & 0x7f);
cpudata->vid.max = int_tofp((value >> 16) & 0x7f);
cpudata->vid.ratio = div_fp(
cpudata->vid.max - cpudata->vid.min,
int_tofp(cpudata->pstate.max_pstate -
cpudata->pstate.min_pstate));
rdmsrl(ATOM_TURBO_VIDS, value);
cpudata->vid.turbo = value & 0x7f;
}
static int core_get_min_pstate(void)
{
u64 value;
rdmsrl(MSR_PLATFORM_INFO, value);
return (value >> 40) & 0xFF;
}
static int core_get_max_pstate_physical(void)
{
u64 value;
rdmsrl(MSR_PLATFORM_INFO, value);
return (value >> 8) & 0xFF;
}
static int core_get_max_pstate(void)
{
u64 tar;
u64 plat_info;
int max_pstate;
int err;
rdmsrl(MSR_PLATFORM_INFO, plat_info);
max_pstate = (plat_info >> 8) & 0xFF;
err = rdmsrl_safe(MSR_TURBO_ACTIVATION_RATIO, &tar);
if (!err) {
if (plat_info & 0x600000000) {
u64 tdp_ctrl;
u64 tdp_ratio;
int tdp_msr;
err = rdmsrl_safe(MSR_CONFIG_TDP_CONTROL, &tdp_ctrl);
if (err)
goto skip_tar;
tdp_msr = MSR_CONFIG_TDP_NOMINAL + (tdp_ctrl & 0x3);
err = rdmsrl_safe(tdp_msr, &tdp_ratio);
if (err)
goto skip_tar;
if (tdp_ctrl)
tdp_ratio >>= 16;
tdp_ratio &= 0xff;
if (tdp_ratio - 1 == tar) {
max_pstate = tar;
pr_debug("max_pstate=TAC %x\n", max_pstate);
} else {
goto skip_tar;
}
}
}
skip_tar:
return max_pstate;
}
static int core_get_turbo_pstate(void)
{
u64 value;
int nont, ret;
rdmsrl(MSR_TURBO_RATIO_LIMIT, value);
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
static u64 core_get_val(struct cpudata *cpudata, int pstate)
{
u64 val;
val = (u64)pstate << 8;
if (limits->no_turbo && !limits->turbo_disabled)
val |= (u64)1 << 32;
return val;
}
static int knl_get_turbo_pstate(void)
{
u64 value;
int nont, ret;
rdmsrl(MSR_TURBO_RATIO_LIMIT, value);
nont = core_get_max_pstate();
ret = (((value) >> 8) & 0xFF);
if (ret <= nont)
ret = nont;
return ret;
}
static void intel_pstate_get_min_max(struct cpudata *cpu, int *min, int *max)
{
int max_perf = cpu->pstate.turbo_pstate;
int max_perf_adj;
int min_perf;
if (limits->no_turbo || limits->turbo_disabled)
max_perf = cpu->pstate.max_pstate;
max_perf_adj = fp_toint(max_perf * limits->max_perf);
*max = clamp_t(int, max_perf_adj,
cpu->pstate.min_pstate, cpu->pstate.turbo_pstate);
min_perf = fp_toint(max_perf * limits->min_perf);
*min = clamp_t(int, min_perf, cpu->pstate.min_pstate, max_perf);
}
static void intel_pstate_set_min_pstate(struct cpudata *cpu)
{
int pstate = cpu->pstate.min_pstate;
trace_cpu_frequency(pstate * cpu->pstate.scaling, cpu->cpu);
cpu->pstate.current_pstate = pstate;
wrmsrl_on_cpu(cpu->cpu, MSR_IA32_PERF_CTL,
pstate_funcs.get_val(cpu, pstate));
}
static void intel_pstate_get_cpu_pstates(struct cpudata *cpu)
{
cpu->pstate.min_pstate = pstate_funcs.get_min();
cpu->pstate.max_pstate = pstate_funcs.get_max();
cpu->pstate.max_pstate_physical = pstate_funcs.get_max_physical();
cpu->pstate.turbo_pstate = pstate_funcs.get_turbo();
cpu->pstate.scaling = pstate_funcs.get_scaling();
if (pstate_funcs.get_vid)
pstate_funcs.get_vid(cpu);
intel_pstate_set_min_pstate(cpu);
}
static inline void intel_pstate_calc_avg_perf(struct cpudata *cpu)
{
struct sample *sample = &cpu->sample;
sample->core_avg_perf = div_ext_fp(sample->aperf, sample->mperf);
}
static inline bool intel_pstate_sample(struct cpudata *cpu, u64 time)
{
u64 aperf, mperf;
unsigned long flags;
u64 tsc;
local_irq_save(flags);
rdmsrl(MSR_IA32_APERF, aperf);
rdmsrl(MSR_IA32_MPERF, mperf);
tsc = rdtsc();
if (cpu->prev_mperf == mperf || cpu->prev_tsc == tsc) {
local_irq_restore(flags);
return false;
}
local_irq_restore(flags);
cpu->last_sample_time = cpu->sample.time;
cpu->sample.time = time;
cpu->sample.aperf = aperf;
cpu->sample.mperf = mperf;
cpu->sample.tsc = tsc;
cpu->sample.aperf -= cpu->prev_aperf;
cpu->sample.mperf -= cpu->prev_mperf;
cpu->sample.tsc -= cpu->prev_tsc;
cpu->prev_aperf = aperf;
cpu->prev_mperf = mperf;
cpu->prev_tsc = tsc;
return !!cpu->last_sample_time;
}
static inline int32_t get_avg_frequency(struct cpudata *cpu)
{
return mul_ext_fp(cpu->sample.core_avg_perf,
cpu->pstate.max_pstate_physical * cpu->pstate.scaling);
}
static inline int32_t get_avg_pstate(struct cpudata *cpu)
{
return mul_ext_fp(cpu->pstate.max_pstate_physical,
cpu->sample.core_avg_perf);
}
static inline int32_t get_target_pstate_use_cpu_load(struct cpudata *cpu)
{
struct sample *sample = &cpu->sample;
u64 cummulative_iowait, delta_iowait_us;
u64 delta_iowait_mperf;
u64 mperf, now;
int32_t cpu_load;
cummulative_iowait = get_cpu_iowait_time_us(cpu->cpu, &now);
delta_iowait_us = cummulative_iowait - cpu->prev_cummulative_iowait;
delta_iowait_mperf = div64_u64(delta_iowait_us * cpu->pstate.scaling *
cpu->pstate.max_pstate, MSEC_PER_SEC);
mperf = cpu->sample.mperf + delta_iowait_mperf;
cpu->prev_cummulative_iowait = cummulative_iowait;
cpu_load = div64_u64(int_tofp(100) * mperf, sample->tsc);
cpu->sample.busy_scaled = cpu_load;
return get_avg_pstate(cpu) - pid_calc(&cpu->pid, cpu_load);
}
static inline int32_t get_target_pstate_use_performance(struct cpudata *cpu)
{
int32_t perf_scaled, max_pstate, current_pstate, sample_ratio;
u64 duration_ns;
max_pstate = cpu->pstate.max_pstate_physical;
current_pstate = cpu->pstate.current_pstate;
perf_scaled = mul_ext_fp(cpu->sample.core_avg_perf,
div_fp(100 * max_pstate, current_pstate));
duration_ns = cpu->sample.time - cpu->last_sample_time;
if ((s64)duration_ns > pid_params.sample_rate_ns * 3) {
sample_ratio = div_fp(pid_params.sample_rate_ns, duration_ns);
perf_scaled = mul_fp(perf_scaled, sample_ratio);
} else {
sample_ratio = div_fp(100 * cpu->sample.mperf, cpu->sample.tsc);
if (sample_ratio < int_tofp(1))
perf_scaled = 0;
}
cpu->sample.busy_scaled = perf_scaled;
return cpu->pstate.current_pstate - pid_calc(&cpu->pid, perf_scaled);
}
static inline void intel_pstate_update_pstate(struct cpudata *cpu, int pstate)
{
int max_perf, min_perf;
update_turbo_state();
intel_pstate_get_min_max(cpu, &min_perf, &max_perf);
pstate = clamp_t(int, pstate, min_perf, max_perf);
trace_cpu_frequency(pstate * cpu->pstate.scaling, cpu->cpu);
if (pstate == cpu->pstate.current_pstate)
return;
cpu->pstate.current_pstate = pstate;
wrmsrl(MSR_IA32_PERF_CTL, pstate_funcs.get_val(cpu, pstate));
}
static inline void intel_pstate_adjust_busy_pstate(struct cpudata *cpu)
{
int from, target_pstate;
struct sample *sample;
from = cpu->pstate.current_pstate;
target_pstate = pstate_funcs.get_target_pstate(cpu);
intel_pstate_update_pstate(cpu, target_pstate);
sample = &cpu->sample;
trace_pstate_sample(mul_ext_fp(100, sample->core_avg_perf),
fp_toint(sample->busy_scaled),
from,
cpu->pstate.current_pstate,
sample->mperf,
sample->aperf,
sample->tsc,
get_avg_frequency(cpu));
}
static void intel_pstate_update_util(struct update_util_data *data, u64 time,
unsigned long util, unsigned long max)
{
struct cpudata *cpu = container_of(data, struct cpudata, update_util);
u64 delta_ns = time - cpu->sample.time;
if ((s64)delta_ns >= pid_params.sample_rate_ns) {
bool sample_taken = intel_pstate_sample(cpu, time);
if (sample_taken) {
intel_pstate_calc_avg_perf(cpu);
if (!hwp_active)
intel_pstate_adjust_busy_pstate(cpu);
}
}
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
if (hwp_active) {
intel_pstate_hwp_enable(cpu);
pid_params.sample_rate_ms = 50;
pid_params.sample_rate_ns = 50 * NSEC_PER_MSEC;
}
intel_pstate_get_cpu_pstates(cpu);
intel_pstate_busy_pid_reset(cpu);
pr_debug("controlling: cpu %d\n", cpunum);
return 0;
}
static unsigned int intel_pstate_get(unsigned int cpu_num)
{
struct cpudata *cpu = all_cpu_data[cpu_num];
return cpu ? get_avg_frequency(cpu) : 0;
}
static void intel_pstate_set_update_util_hook(unsigned int cpu_num)
{
struct cpudata *cpu = all_cpu_data[cpu_num];
if (cpu->update_util_set)
return;
cpu->sample.time = 0;
cpufreq_add_update_util_hook(cpu_num, &cpu->update_util,
intel_pstate_update_util);
cpu->update_util_set = true;
}
static void intel_pstate_clear_update_util_hook(unsigned int cpu)
{
struct cpudata *cpu_data = all_cpu_data[cpu];
if (!cpu_data->update_util_set)
return;
cpufreq_remove_update_util_hook(cpu);
cpu_data->update_util_set = false;
synchronize_sched();
}
static void intel_pstate_set_performance_limits(struct perf_limits *limits)
{
limits->no_turbo = 0;
limits->turbo_disabled = 0;
limits->max_perf_pct = 100;
limits->max_perf = int_tofp(1);
limits->min_perf_pct = 100;
limits->min_perf = int_tofp(1);
limits->max_policy_pct = 100;
limits->max_sysfs_pct = 100;
limits->min_policy_pct = 0;
limits->min_sysfs_pct = 0;
}
static int intel_pstate_set_policy(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
if (!policy->cpuinfo.max_freq)
return -ENODEV;
pr_debug("set_policy cpuinfo.max %u policy->max %u\n",
policy->cpuinfo.max_freq, policy->max);
cpu = all_cpu_data[0];
if (cpu->pstate.max_pstate_physical > cpu->pstate.max_pstate &&
policy->max < policy->cpuinfo.max_freq &&
policy->max > cpu->pstate.max_pstate * cpu->pstate.scaling) {
pr_debug("policy->max > max non turbo frequency\n");
policy->max = policy->cpuinfo.max_freq;
}
if (policy->policy == CPUFREQ_POLICY_PERFORMANCE) {
limits = &performance_limits;
if (policy->max >= policy->cpuinfo.max_freq) {
pr_debug("set performance\n");
intel_pstate_set_performance_limits(limits);
goto out;
}
} else {
pr_debug("set powersave\n");
limits = &powersave_limits;
}
limits->min_policy_pct = (policy->min * 100) / policy->cpuinfo.max_freq;
limits->min_policy_pct = clamp_t(int, limits->min_policy_pct, 0 , 100);
limits->max_policy_pct = DIV_ROUND_UP(policy->max * 100,
policy->cpuinfo.max_freq);
limits->max_policy_pct = clamp_t(int, limits->max_policy_pct, 0 , 100);
limits->min_perf_pct = max(limits->min_policy_pct,
limits->min_sysfs_pct);
limits->min_perf_pct = min(limits->max_policy_pct,
limits->min_perf_pct);
limits->max_perf_pct = min(limits->max_policy_pct,
limits->max_sysfs_pct);
limits->max_perf_pct = max(limits->min_policy_pct,
limits->max_perf_pct);
limits->min_perf_pct = min(limits->max_perf_pct, limits->min_perf_pct);
limits->min_perf = div_fp(limits->min_perf_pct, 100);
limits->max_perf = div_fp(limits->max_perf_pct, 100);
limits->max_perf = round_up(limits->max_perf, FRAC_BITS);
out:
intel_pstate_set_update_util_hook(policy->cpu);
intel_pstate_hwp_set_policy(policy);
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
pr_debug("CPU %d exiting\n", cpu_num);
intel_pstate_clear_update_util_hook(cpu_num);
if (hwp_active)
return;
intel_pstate_set_min_pstate(cpu);
}
static int intel_pstate_cpu_init(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
int rc;
rc = intel_pstate_init_cpu(policy->cpu);
if (rc)
return rc;
cpu = all_cpu_data[policy->cpu];
if (limits->min_perf_pct == 100 && limits->max_perf_pct == 100)
policy->policy = CPUFREQ_POLICY_PERFORMANCE;
else
policy->policy = CPUFREQ_POLICY_POWERSAVE;
policy->min = cpu->pstate.min_pstate * cpu->pstate.scaling;
policy->max = cpu->pstate.turbo_pstate * cpu->pstate.scaling;
policy->cpuinfo.min_freq = cpu->pstate.min_pstate * cpu->pstate.scaling;
update_turbo_state();
policy->cpuinfo.max_freq = limits->turbo_disabled ?
cpu->pstate.max_pstate : cpu->pstate.turbo_pstate;
policy->cpuinfo.max_freq *= cpu->pstate.scaling;
intel_pstate_init_acpi_perf_limits(policy);
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
cpumask_set_cpu(policy->cpu, policy->cpus);
return 0;
}
static int intel_pstate_cpu_exit(struct cpufreq_policy *policy)
{
intel_pstate_exit_perf_limits(policy);
return 0;
}
static int __init intel_pstate_msrs_not_valid(void)
{
if (!pstate_funcs.get_max() ||
!pstate_funcs.get_min() ||
!pstate_funcs.get_turbo())
return -ENODEV;
return 0;
}
static void __init copy_pid_params(struct pstate_adjust_policy *policy)
{
pid_params.sample_rate_ms = policy->sample_rate_ms;
pid_params.sample_rate_ns = pid_params.sample_rate_ms * NSEC_PER_MSEC;
pid_params.p_gain_pct = policy->p_gain_pct;
pid_params.i_gain_pct = policy->i_gain_pct;
pid_params.d_gain_pct = policy->d_gain_pct;
pid_params.deadband = policy->deadband;
pid_params.setpoint = policy->setpoint;
}
static void __init copy_cpu_funcs(struct pstate_funcs *funcs)
{
pstate_funcs.get_max = funcs->get_max;
pstate_funcs.get_max_physical = funcs->get_max_physical;
pstate_funcs.get_min = funcs->get_min;
pstate_funcs.get_turbo = funcs->get_turbo;
pstate_funcs.get_scaling = funcs->get_scaling;
pstate_funcs.get_val = funcs->get_val;
pstate_funcs.get_vid = funcs->get_vid;
pstate_funcs.get_target_pstate = funcs->get_target_pstate;
}
static bool __init intel_pstate_no_acpi_pss(void)
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
static bool __init intel_pstate_has_acpi_ppc(void)
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
static bool __init intel_pstate_platform_pwr_mgmt_exists(void)
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
struct cpu_defaults *cpu_def;
if (no_load)
return -ENODEV;
if (x86_match_cpu(hwp_support_ids) && !no_hwp) {
copy_cpu_funcs(&core_params.funcs);
hwp_active++;
goto hwp_cpu_matched;
}
id = x86_match_cpu(intel_pstate_cpu_ids);
if (!id)
return -ENODEV;
cpu_def = (struct cpu_defaults *)id->driver_data;
copy_pid_params(&cpu_def->pid_policy);
copy_cpu_funcs(&cpu_def->funcs);
if (intel_pstate_msrs_not_valid())
return -ENODEV;
hwp_cpu_matched:
if (intel_pstate_platform_pwr_mgmt_exists())
return -ENODEV;
pr_info("Intel P-state driver initializing\n");
all_cpu_data = vzalloc(sizeof(void *) * num_possible_cpus());
if (!all_cpu_data)
return -ENOMEM;
if (!hwp_active && hwp_only)
goto out;
rc = cpufreq_register_driver(&intel_pstate_driver);
if (rc)
goto out;
intel_pstate_debug_expose_params();
intel_pstate_sysfs_expose_params();
if (hwp_active)
pr_info("HWP enabled\n");
return rc;
out:
get_online_cpus();
for_each_online_cpu(cpu) {
if (all_cpu_data[cpu]) {
intel_pstate_clear_update_util_hook(cpu);
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
if (!strcmp(str, "no_hwp")) {
pr_info("HWP disabled\n");
no_hwp = 1;
}
if (!strcmp(str, "force"))
force_load = 1;
if (!strcmp(str, "hwp_only"))
hwp_only = 1;
#ifdef CONFIG_ACPI
if (!strcmp(str, "support_acpi_ppc"))
acpi_ppc = true;
#endif
return 0;
}
