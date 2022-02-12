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
static inline int32_t percent_fp(int percent)
{
return div_fp(percent, 100);
}
static inline u64 mul_ext_fp(u64 x, u64 y)
{
return (x * y) >> EXT_FRAC_BITS;
}
static inline u64 div_ext_fp(u64 x, u64 y)
{
return div64_u64(x << EXT_FRAC_BITS, y);
}
static inline int32_t percent_ext_fp(int percent)
{
return div_ext_fp(percent, 100);
}
static bool intel_pstate_get_ppc_enable_status(void)
{
if (acpi_gbl_FADT.preferred_profile == PM_ENTERPRISE_SERVER ||
acpi_gbl_FADT.preferred_profile == PM_PERFORMANCE_SERVER)
return true;
return acpi_ppc;
}
static void intel_pstste_sched_itmt_work_fn(struct work_struct *work)
{
sched_set_itmt_support();
}
static void intel_pstate_set_itmt_prio(int cpu)
{
struct cppc_perf_caps cppc_perf;
static u32 max_highest_perf = 0, min_highest_perf = U32_MAX;
int ret;
ret = cppc_get_perf_caps(cpu, &cppc_perf);
if (ret)
return;
sched_set_itmt_core_prio(cppc_perf.highest_perf, cpu);
if (max_highest_perf <= min_highest_perf) {
if (cppc_perf.highest_perf > max_highest_perf)
max_highest_perf = cppc_perf.highest_perf;
if (cppc_perf.highest_perf < min_highest_perf)
min_highest_perf = cppc_perf.highest_perf;
if (max_highest_perf > min_highest_perf) {
schedule_work(&sched_itmt_work);
}
}
}
static void intel_pstate_set_itmt_prio(int cpu)
{
}
static void intel_pstate_init_acpi_perf_limits(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
int ret;
int i;
if (hwp_active) {
intel_pstate_set_itmt_prio(policy->cpu);
return;
}
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
if (!global.turbo_disabled)
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
static inline void intel_pstate_init_acpi_perf_limits(struct cpufreq_policy *policy)
{
}
static inline void intel_pstate_exit_perf_limits(struct cpufreq_policy *policy)
{
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
static inline void intel_pstate_pid_reset(struct cpudata *cpu)
{
struct _pid *pid = &cpu->pid;
pid->p_gain = percent_fp(pid_params.p_gain_pct);
pid->d_gain = percent_fp(pid_params.d_gain_pct);
pid->i_gain = percent_fp(pid_params.i_gain_pct);
pid->setpoint = int_tofp(pid_params.setpoint);
pid->last_err = pid->setpoint - int_tofp(100);
pid->deadband = int_tofp(pid_params.deadband);
pid->integral = 0;
}
static inline void update_turbo_state(void)
{
u64 misc_en;
struct cpudata *cpu;
cpu = all_cpu_data[0];
rdmsrl(MSR_IA32_MISC_ENABLE, misc_en);
global.turbo_disabled =
(misc_en & MSR_IA32_MISC_ENABLE_TURBO_DISABLE ||
cpu->pstate.max_pstate == cpu->pstate.turbo_pstate);
}
static int min_perf_pct_min(void)
{
struct cpudata *cpu = all_cpu_data[0];
int turbo_pstate = cpu->pstate.turbo_pstate;
return turbo_pstate ?
DIV_ROUND_UP(cpu->pstate.min_pstate * 100, turbo_pstate) : 0;
}
static s16 intel_pstate_get_epb(struct cpudata *cpu_data)
{
u64 epb;
int ret;
if (!static_cpu_has(X86_FEATURE_EPB))
return -ENXIO;
ret = rdmsrl_on_cpu(cpu_data->cpu, MSR_IA32_ENERGY_PERF_BIAS, &epb);
if (ret)
return (s16)ret;
return (s16)(epb & 0x0f);
}
static s16 intel_pstate_get_epp(struct cpudata *cpu_data, u64 hwp_req_data)
{
s16 epp;
if (static_cpu_has(X86_FEATURE_HWP_EPP)) {
if (!hwp_req_data) {
epp = rdmsrl_on_cpu(cpu_data->cpu, MSR_HWP_REQUEST,
&hwp_req_data);
if (epp)
return epp;
}
epp = (hwp_req_data >> 24) & 0xff;
} else {
epp = intel_pstate_get_epb(cpu_data);
}
return epp;
}
static int intel_pstate_set_epb(int cpu, s16 pref)
{
u64 epb;
int ret;
if (!static_cpu_has(X86_FEATURE_EPB))
return -ENXIO;
ret = rdmsrl_on_cpu(cpu, MSR_IA32_ENERGY_PERF_BIAS, &epb);
if (ret)
return ret;
epb = (epb & ~0x0f) | pref;
wrmsrl_on_cpu(cpu, MSR_IA32_ENERGY_PERF_BIAS, epb);
return 0;
}
static int intel_pstate_get_energy_pref_index(struct cpudata *cpu_data)
{
s16 epp;
int index = -EINVAL;
epp = intel_pstate_get_epp(cpu_data, 0);
if (epp < 0)
return epp;
if (static_cpu_has(X86_FEATURE_HWP_EPP)) {
index = (epp >> 6) + 1;
} else if (static_cpu_has(X86_FEATURE_EPB)) {
index = (epp >> 2) + 1;
}
return index;
}
static int intel_pstate_set_energy_pref_index(struct cpudata *cpu_data,
int pref_index)
{
int epp = -EINVAL;
int ret;
if (!pref_index)
epp = cpu_data->epp_default;
mutex_lock(&intel_pstate_limits_lock);
if (static_cpu_has(X86_FEATURE_HWP_EPP)) {
u64 value;
ret = rdmsrl_on_cpu(cpu_data->cpu, MSR_HWP_REQUEST, &value);
if (ret)
goto return_pref;
value &= ~GENMASK_ULL(31, 24);
if (epp == -EINVAL)
epp = (pref_index - 1) << 6;
value |= (u64)epp << 24;
ret = wrmsrl_on_cpu(cpu_data->cpu, MSR_HWP_REQUEST, value);
} else {
if (epp == -EINVAL)
epp = (pref_index - 1) << 2;
ret = intel_pstate_set_epb(cpu_data->cpu, epp);
}
return_pref:
mutex_unlock(&intel_pstate_limits_lock);
return ret;
}
static ssize_t show_energy_performance_available_preferences(
struct cpufreq_policy *policy, char *buf)
{
int i = 0;
int ret = 0;
while (energy_perf_strings[i] != NULL)
ret += sprintf(&buf[ret], "%s ", energy_perf_strings[i++]);
ret += sprintf(&buf[ret], "\n");
return ret;
}
static ssize_t store_energy_performance_preference(
struct cpufreq_policy *policy, const char *buf, size_t count)
{
struct cpudata *cpu_data = all_cpu_data[policy->cpu];
char str_preference[21];
int ret, i = 0;
ret = sscanf(buf, "%20s", str_preference);
if (ret != 1)
return -EINVAL;
while (energy_perf_strings[i] != NULL) {
if (!strcmp(str_preference, energy_perf_strings[i])) {
intel_pstate_set_energy_pref_index(cpu_data, i);
return count;
}
++i;
}
return -EINVAL;
}
static ssize_t show_energy_performance_preference(
struct cpufreq_policy *policy, char *buf)
{
struct cpudata *cpu_data = all_cpu_data[policy->cpu];
int preference;
preference = intel_pstate_get_energy_pref_index(cpu_data);
if (preference < 0)
return preference;
return sprintf(buf, "%s\n", energy_perf_strings[preference]);
}
static void intel_pstate_hwp_set(unsigned int cpu)
{
struct cpudata *cpu_data = all_cpu_data[cpu];
int min, hw_min, max, hw_max;
u64 value, cap;
s16 epp;
rdmsrl_on_cpu(cpu, MSR_HWP_CAPABILITIES, &cap);
hw_min = HWP_LOWEST_PERF(cap);
if (global.no_turbo)
hw_max = HWP_GUARANTEED_PERF(cap);
else
hw_max = HWP_HIGHEST_PERF(cap);
max = fp_ext_toint(hw_max * cpu_data->max_perf);
if (cpu_data->policy == CPUFREQ_POLICY_PERFORMANCE)
min = max;
else
min = fp_ext_toint(hw_max * cpu_data->min_perf);
rdmsrl_on_cpu(cpu, MSR_HWP_REQUEST, &value);
value &= ~HWP_MIN_PERF(~0L);
value |= HWP_MIN_PERF(min);
value &= ~HWP_MAX_PERF(~0L);
value |= HWP_MAX_PERF(max);
if (cpu_data->epp_policy == cpu_data->policy)
goto skip_epp;
cpu_data->epp_policy = cpu_data->policy;
if (cpu_data->epp_saved >= 0) {
epp = cpu_data->epp_saved;
cpu_data->epp_saved = -EINVAL;
goto update_epp;
}
if (cpu_data->policy == CPUFREQ_POLICY_PERFORMANCE) {
epp = intel_pstate_get_epp(cpu_data, value);
cpu_data->epp_powersave = epp;
if (epp < 0)
goto skip_epp;
epp = 0;
} else {
if (cpu_data->epp_powersave < 0)
goto skip_epp;
epp = intel_pstate_get_epp(cpu_data, value);
if (epp)
goto skip_epp;
epp = cpu_data->epp_powersave;
}
update_epp:
if (static_cpu_has(X86_FEATURE_HWP_EPP)) {
value &= ~GENMASK_ULL(31, 24);
value |= (u64)epp << 24;
} else {
intel_pstate_set_epb(cpu, epp);
}
skip_epp:
wrmsrl_on_cpu(cpu, MSR_HWP_REQUEST, value);
}
static int intel_pstate_hwp_save_state(struct cpufreq_policy *policy)
{
struct cpudata *cpu_data = all_cpu_data[policy->cpu];
if (!hwp_active)
return 0;
cpu_data->epp_saved = intel_pstate_get_epp(cpu_data, 0);
return 0;
}
static int intel_pstate_resume(struct cpufreq_policy *policy)
{
if (!hwp_active)
return 0;
mutex_lock(&intel_pstate_limits_lock);
all_cpu_data[policy->cpu]->epp_policy = 0;
intel_pstate_hwp_set(policy->cpu);
mutex_unlock(&intel_pstate_limits_lock);
return 0;
}
static void intel_pstate_update_policies(void)
{
int cpu;
for_each_possible_cpu(cpu)
cpufreq_update_policy(cpu);
}
static int pid_param_set(void *data, u64 val)
{
unsigned int cpu;
*(u32 *)data = val;
pid_params.sample_rate_ns = pid_params.sample_rate_ms * NSEC_PER_MSEC;
for_each_possible_cpu(cpu)
if (all_cpu_data[cpu])
intel_pstate_pid_reset(all_cpu_data[cpu]);
return 0;
}
static int pid_param_get(void *data, u64 *val)
{
*val = *(u32 *)data;
return 0;
}
static void intel_pstate_debug_expose_params(void)
{
int i;
debugfs_parent = debugfs_create_dir("pstate_snb", NULL);
if (IS_ERR_OR_NULL(debugfs_parent))
return;
for (i = 0; pid_files[i].name; i++) {
struct dentry *dentry;
dentry = debugfs_create_file(pid_files[i].name, 0660,
debugfs_parent, pid_files[i].value,
&fops_pid_param);
if (!IS_ERR(dentry))
pid_files[i].dentry = dentry;
}
}
static void intel_pstate_debug_hide_params(void)
{
int i;
if (IS_ERR_OR_NULL(debugfs_parent))
return;
for (i = 0; pid_files[i].name; i++) {
debugfs_remove(pid_files[i].dentry);
pid_files[i].dentry = NULL;
}
debugfs_remove(debugfs_parent);
debugfs_parent = NULL;
}
static ssize_t show_status(struct kobject *kobj,
struct attribute *attr, char *buf)
{
ssize_t ret;
mutex_lock(&intel_pstate_driver_lock);
ret = intel_pstate_show_status(buf);
mutex_unlock(&intel_pstate_driver_lock);
return ret;
}
static ssize_t store_status(struct kobject *a, struct attribute *b,
const char *buf, size_t count)
{
char *p = memchr(buf, '\n', count);
int ret;
mutex_lock(&intel_pstate_driver_lock);
ret = intel_pstate_update_status(buf, p ? p - buf : count);
mutex_unlock(&intel_pstate_driver_lock);
return ret < 0 ? ret : count;
}
static ssize_t show_turbo_pct(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct cpudata *cpu;
int total, no_turbo, turbo_pct;
uint32_t turbo_fp;
mutex_lock(&intel_pstate_driver_lock);
if (!intel_pstate_driver) {
mutex_unlock(&intel_pstate_driver_lock);
return -EAGAIN;
}
cpu = all_cpu_data[0];
total = cpu->pstate.turbo_pstate - cpu->pstate.min_pstate + 1;
no_turbo = cpu->pstate.max_pstate - cpu->pstate.min_pstate + 1;
turbo_fp = div_fp(no_turbo, total);
turbo_pct = 100 - fp_toint(mul_fp(turbo_fp, int_tofp(100)));
mutex_unlock(&intel_pstate_driver_lock);
return sprintf(buf, "%u\n", turbo_pct);
}
static ssize_t show_num_pstates(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct cpudata *cpu;
int total;
mutex_lock(&intel_pstate_driver_lock);
if (!intel_pstate_driver) {
mutex_unlock(&intel_pstate_driver_lock);
return -EAGAIN;
}
cpu = all_cpu_data[0];
total = cpu->pstate.turbo_pstate - cpu->pstate.min_pstate + 1;
mutex_unlock(&intel_pstate_driver_lock);
return sprintf(buf, "%u\n", total);
}
static ssize_t show_no_turbo(struct kobject *kobj,
struct attribute *attr, char *buf)
{
ssize_t ret;
mutex_lock(&intel_pstate_driver_lock);
if (!intel_pstate_driver) {
mutex_unlock(&intel_pstate_driver_lock);
return -EAGAIN;
}
update_turbo_state();
if (global.turbo_disabled)
ret = sprintf(buf, "%u\n", global.turbo_disabled);
else
ret = sprintf(buf, "%u\n", global.no_turbo);
mutex_unlock(&intel_pstate_driver_lock);
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
mutex_lock(&intel_pstate_driver_lock);
if (!intel_pstate_driver) {
mutex_unlock(&intel_pstate_driver_lock);
return -EAGAIN;
}
mutex_lock(&intel_pstate_limits_lock);
update_turbo_state();
if (global.turbo_disabled) {
pr_warn("Turbo disabled by BIOS or unavailable on processor\n");
mutex_unlock(&intel_pstate_limits_lock);
mutex_unlock(&intel_pstate_driver_lock);
return -EPERM;
}
global.no_turbo = clamp_t(int, input, 0, 1);
if (global.no_turbo) {
struct cpudata *cpu = all_cpu_data[0];
int pct = cpu->pstate.max_pstate * 100 / cpu->pstate.turbo_pstate;
if (global.min_perf_pct > pct)
global.min_perf_pct = pct;
}
mutex_unlock(&intel_pstate_limits_lock);
intel_pstate_update_policies();
mutex_unlock(&intel_pstate_driver_lock);
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
mutex_lock(&intel_pstate_driver_lock);
if (!intel_pstate_driver) {
mutex_unlock(&intel_pstate_driver_lock);
return -EAGAIN;
}
mutex_lock(&intel_pstate_limits_lock);
global.max_perf_pct = clamp_t(int, input, global.min_perf_pct, 100);
mutex_unlock(&intel_pstate_limits_lock);
intel_pstate_update_policies();
mutex_unlock(&intel_pstate_driver_lock);
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
mutex_lock(&intel_pstate_driver_lock);
if (!intel_pstate_driver) {
mutex_unlock(&intel_pstate_driver_lock);
return -EAGAIN;
}
mutex_lock(&intel_pstate_limits_lock);
global.min_perf_pct = clamp_t(int, input,
min_perf_pct_min(), global.max_perf_pct);
mutex_unlock(&intel_pstate_limits_lock);
intel_pstate_update_policies();
mutex_unlock(&intel_pstate_driver_lock);
return count;
}
static void __init intel_pstate_sysfs_expose_params(void)
{
struct kobject *intel_pstate_kobject;
int rc;
intel_pstate_kobject = kobject_create_and_add("intel_pstate",
&cpu_subsys.dev_root->kobj);
if (WARN_ON(!intel_pstate_kobject))
return;
rc = sysfs_create_group(intel_pstate_kobject, &intel_pstate_attr_group);
if (WARN_ON(rc))
return;
if (per_cpu_limits)
return;
rc = sysfs_create_file(intel_pstate_kobject, &max_perf_pct.attr);
WARN_ON(rc);
rc = sysfs_create_file(intel_pstate_kobject, &min_perf_pct.attr);
WARN_ON(rc);
}
static void intel_pstate_hwp_enable(struct cpudata *cpudata)
{
if (static_cpu_has(X86_FEATURE_HWP_NOTIFY))
wrmsrl_on_cpu(cpudata->cpu, MSR_HWP_INTERRUPT, 0x00);
wrmsrl_on_cpu(cpudata->cpu, MSR_PM_ENABLE, 0x1);
cpudata->epp_policy = 0;
if (cpudata->epp_default == -EINVAL)
cpudata->epp_default = intel_pstate_get_epp(cpudata, 0);
}
static void intel_pstate_disable_ee(int cpu)
{
u64 power_ctl;
int ret;
ret = rdmsrl_on_cpu(cpu, MSR_IA32_POWER_CTL, &power_ctl);
if (ret)
return;
if (!(power_ctl & BIT(MSR_IA32_POWER_CTL_BIT_EE))) {
pr_info("Disabling energy efficiency optimization\n");
power_ctl |= BIT(MSR_IA32_POWER_CTL_BIT_EE);
wrmsrl_on_cpu(cpu, MSR_IA32_POWER_CTL, power_ctl);
}
}
static int atom_get_min_pstate(void)
{
u64 value;
rdmsrl(MSR_ATOM_CORE_RATIOS, value);
return (value >> 8) & 0x7F;
}
static int atom_get_max_pstate(void)
{
u64 value;
rdmsrl(MSR_ATOM_CORE_RATIOS, value);
return (value >> 16) & 0x7F;
}
static int atom_get_turbo_pstate(void)
{
u64 value;
rdmsrl(MSR_ATOM_CORE_TURBO_RATIOS, value);
return value & 0x7F;
}
static u64 atom_get_val(struct cpudata *cpudata, int pstate)
{
u64 val;
int32_t vid_fp;
u32 vid;
val = (u64)pstate << 8;
if (global.no_turbo && !global.turbo_disabled)
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
rdmsrl(MSR_ATOM_CORE_VIDS, value);
cpudata->vid.min = int_tofp((value >> 8) & 0x7f);
cpudata->vid.max = int_tofp((value >> 16) & 0x7f);
cpudata->vid.ratio = div_fp(
cpudata->vid.max - cpudata->vid.min,
int_tofp(cpudata->pstate.max_pstate -
cpudata->pstate.min_pstate));
rdmsrl(MSR_ATOM_CORE_TURBO_VIDS, value);
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
static int core_get_tdp_ratio(u64 plat_info)
{
if (plat_info & 0x600000000) {
u64 tdp_ctrl;
u64 tdp_ratio;
int tdp_msr;
int err;
err = rdmsrl_safe(MSR_CONFIG_TDP_CONTROL, &tdp_ctrl);
if (err)
return err;
tdp_msr = MSR_CONFIG_TDP_NOMINAL + (tdp_ctrl & 0x03);
err = rdmsrl_safe(tdp_msr, &tdp_ratio);
if (err)
return err;
if (tdp_ctrl & 0x03)
tdp_ratio >>= 16;
tdp_ratio &= 0xff;
pr_debug("tdp_ratio %x\n", (int)tdp_ratio);
return (int)tdp_ratio;
}
return -ENXIO;
}
static int core_get_max_pstate(void)
{
u64 tar;
u64 plat_info;
int max_pstate;
int tdp_ratio;
int err;
rdmsrl(MSR_PLATFORM_INFO, plat_info);
max_pstate = (plat_info >> 8) & 0xFF;
tdp_ratio = core_get_tdp_ratio(plat_info);
if (tdp_ratio <= 0)
return max_pstate;
if (hwp_active) {
return tdp_ratio;
}
err = rdmsrl_safe(MSR_TURBO_ACTIVATION_RATIO, &tar);
if (!err) {
int tar_levels;
tar_levels = tar & 0xff;
if (tdp_ratio - 1 == tar_levels) {
max_pstate = tar_levels;
pr_debug("max_pstate=TAC %x\n", max_pstate);
}
}
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
if (global.no_turbo && !global.turbo_disabled)
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
static int intel_pstate_get_base_pstate(struct cpudata *cpu)
{
return global.no_turbo || global.turbo_disabled ?
cpu->pstate.max_pstate : cpu->pstate.turbo_pstate;
}
static void intel_pstate_set_pstate(struct cpudata *cpu, int pstate)
{
trace_cpu_frequency(pstate * cpu->pstate.scaling, cpu->cpu);
cpu->pstate.current_pstate = pstate;
wrmsrl_on_cpu(cpu->cpu, MSR_IA32_PERF_CTL,
pstate_funcs.get_val(cpu, pstate));
}
static void intel_pstate_set_min_pstate(struct cpudata *cpu)
{
intel_pstate_set_pstate(cpu, cpu->pstate.min_pstate);
}
static void intel_pstate_max_within_limits(struct cpudata *cpu)
{
int pstate;
update_turbo_state();
pstate = intel_pstate_get_base_pstate(cpu);
pstate = max(cpu->pstate.min_pstate,
fp_ext_toint(pstate * cpu->max_perf));
intel_pstate_set_pstate(cpu, pstate);
}
static void intel_pstate_get_cpu_pstates(struct cpudata *cpu)
{
cpu->pstate.min_pstate = pstate_funcs.get_min();
cpu->pstate.max_pstate = pstate_funcs.get_max();
cpu->pstate.max_pstate_physical = pstate_funcs.get_max_physical();
cpu->pstate.turbo_pstate = pstate_funcs.get_turbo();
cpu->pstate.scaling = pstate_funcs.get_scaling();
cpu->pstate.max_freq = cpu->pstate.max_pstate * cpu->pstate.scaling;
cpu->pstate.turbo_freq = cpu->pstate.turbo_pstate * cpu->pstate.scaling;
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
if (cpu->last_sample_time) {
intel_pstate_calc_avg_perf(cpu);
return true;
}
return false;
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
int32_t busy_frac, boost;
int target, avg_pstate;
if (cpu->policy == CPUFREQ_POLICY_PERFORMANCE)
return cpu->pstate.turbo_pstate;
busy_frac = div_fp(sample->mperf, sample->tsc);
boost = cpu->iowait_boost;
cpu->iowait_boost >>= 1;
if (busy_frac < boost)
busy_frac = boost;
sample->busy_scaled = busy_frac * 100;
target = global.no_turbo || global.turbo_disabled ?
cpu->pstate.max_pstate : cpu->pstate.turbo_pstate;
target += target >> 2;
target = mul_fp(target, busy_frac);
if (target < cpu->pstate.min_pstate)
target = cpu->pstate.min_pstate;
avg_pstate = get_avg_pstate(cpu);
if (avg_pstate > target)
target += (avg_pstate - target) >> 1;
return target;
}
static inline int32_t get_target_pstate_use_performance(struct cpudata *cpu)
{
int32_t perf_scaled, max_pstate, current_pstate, sample_ratio;
u64 duration_ns;
if (cpu->policy == CPUFREQ_POLICY_PERFORMANCE)
return cpu->pstate.turbo_pstate;
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
static int intel_pstate_prepare_request(struct cpudata *cpu, int pstate)
{
int max_pstate = intel_pstate_get_base_pstate(cpu);
int min_pstate;
min_pstate = max(cpu->pstate.min_pstate,
fp_ext_toint(max_pstate * cpu->min_perf));
max_pstate = max(min_pstate, fp_ext_toint(max_pstate * cpu->max_perf));
return clamp_t(int, pstate, min_pstate, max_pstate);
}
static void intel_pstate_update_pstate(struct cpudata *cpu, int pstate)
{
if (pstate == cpu->pstate.current_pstate)
return;
cpu->pstate.current_pstate = pstate;
wrmsrl(MSR_IA32_PERF_CTL, pstate_funcs.get_val(cpu, pstate));
}
static void intel_pstate_adjust_pstate(struct cpudata *cpu, int target_pstate)
{
int from = cpu->pstate.current_pstate;
struct sample *sample;
update_turbo_state();
target_pstate = intel_pstate_prepare_request(cpu, target_pstate);
trace_cpu_frequency(target_pstate * cpu->pstate.scaling, cpu->cpu);
intel_pstate_update_pstate(cpu, target_pstate);
sample = &cpu->sample;
trace_pstate_sample(mul_ext_fp(100, sample->core_avg_perf),
fp_toint(sample->busy_scaled),
from,
cpu->pstate.current_pstate,
sample->mperf,
sample->aperf,
sample->tsc,
get_avg_frequency(cpu),
fp_toint(cpu->iowait_boost * 100));
}
static void intel_pstate_update_util_hwp(struct update_util_data *data,
u64 time, unsigned int flags)
{
struct cpudata *cpu = container_of(data, struct cpudata, update_util);
u64 delta_ns = time - cpu->sample.time;
if ((s64)delta_ns >= INTEL_PSTATE_HWP_SAMPLING_INTERVAL)
intel_pstate_sample(cpu, time);
}
static void intel_pstate_update_util_pid(struct update_util_data *data,
u64 time, unsigned int flags)
{
struct cpudata *cpu = container_of(data, struct cpudata, update_util);
u64 delta_ns = time - cpu->sample.time;
if ((s64)delta_ns < pid_params.sample_rate_ns)
return;
if (intel_pstate_sample(cpu, time)) {
int target_pstate;
target_pstate = get_target_pstate_use_performance(cpu);
intel_pstate_adjust_pstate(cpu, target_pstate);
}
}
static void intel_pstate_update_util(struct update_util_data *data, u64 time,
unsigned int flags)
{
struct cpudata *cpu = container_of(data, struct cpudata, update_util);
u64 delta_ns;
if (flags & SCHED_CPUFREQ_IOWAIT) {
cpu->iowait_boost = int_tofp(1);
} else if (cpu->iowait_boost) {
delta_ns = time - cpu->last_update;
if (delta_ns > TICK_NSEC)
cpu->iowait_boost = 0;
}
cpu->last_update = time;
delta_ns = time - cpu->sample.time;
if ((s64)delta_ns < INTEL_PSTATE_DEFAULT_SAMPLING_INTERVAL)
return;
if (intel_pstate_sample(cpu, time)) {
int target_pstate;
target_pstate = get_target_pstate_use_cpu_load(cpu);
intel_pstate_adjust_pstate(cpu, target_pstate);
}
}
static int intel_pstate_init_cpu(unsigned int cpunum)
{
struct cpudata *cpu;
cpu = all_cpu_data[cpunum];
if (!cpu) {
cpu = kzalloc(sizeof(*cpu), GFP_KERNEL);
if (!cpu)
return -ENOMEM;
all_cpu_data[cpunum] = cpu;
cpu->epp_default = -EINVAL;
cpu->epp_powersave = -EINVAL;
cpu->epp_saved = -EINVAL;
}
cpu = all_cpu_data[cpunum];
cpu->cpu = cpunum;
if (hwp_active) {
const struct x86_cpu_id *id;
id = x86_match_cpu(intel_pstate_cpu_ee_disable_ids);
if (id)
intel_pstate_disable_ee(cpunum);
intel_pstate_hwp_enable(cpu);
} else if (pid_in_use()) {
intel_pstate_pid_reset(cpu);
}
intel_pstate_get_cpu_pstates(cpu);
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
pstate_funcs.update_util);
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
static int intel_pstate_get_max_freq(struct cpudata *cpu)
{
return global.turbo_disabled || global.no_turbo ?
cpu->pstate.max_freq : cpu->pstate.turbo_freq;
}
static void intel_pstate_update_perf_limits(struct cpufreq_policy *policy,
struct cpudata *cpu)
{
int max_freq = intel_pstate_get_max_freq(cpu);
int32_t max_policy_perf, min_policy_perf;
max_policy_perf = div_ext_fp(policy->max, max_freq);
max_policy_perf = clamp_t(int32_t, max_policy_perf, 0, int_ext_tofp(1));
if (policy->max == policy->min) {
min_policy_perf = max_policy_perf;
} else {
min_policy_perf = div_ext_fp(policy->min, max_freq);
min_policy_perf = clamp_t(int32_t, min_policy_perf,
0, max_policy_perf);
}
if (per_cpu_limits) {
cpu->min_perf = min_policy_perf;
cpu->max_perf = max_policy_perf;
} else {
int32_t global_min, global_max;
global_max = percent_ext_fp(global.max_perf_pct);
global_min = percent_ext_fp(global.min_perf_pct);
if (max_freq != cpu->pstate.turbo_freq) {
int32_t turbo_factor;
turbo_factor = div_ext_fp(cpu->pstate.turbo_pstate,
cpu->pstate.max_pstate);
global_min = mul_ext_fp(global_min, turbo_factor);
global_max = mul_ext_fp(global_max, turbo_factor);
}
global_min = clamp_t(int32_t, global_min, 0, global_max);
cpu->min_perf = max(min_policy_perf, global_min);
cpu->min_perf = min(cpu->min_perf, max_policy_perf);
cpu->max_perf = min(max_policy_perf, global_max);
cpu->max_perf = max(min_policy_perf, cpu->max_perf);
cpu->min_perf = min(cpu->min_perf, cpu->max_perf);
}
cpu->max_perf = round_up(cpu->max_perf, EXT_FRAC_BITS);
cpu->min_perf = round_up(cpu->min_perf, EXT_FRAC_BITS);
pr_debug("cpu:%d max_perf_pct:%d min_perf_pct:%d\n", policy->cpu,
fp_ext_toint(cpu->max_perf * 100),
fp_ext_toint(cpu->min_perf * 100));
}
static int intel_pstate_set_policy(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
if (!policy->cpuinfo.max_freq)
return -ENODEV;
pr_debug("set_policy cpuinfo.max %u policy->max %u\n",
policy->cpuinfo.max_freq, policy->max);
cpu = all_cpu_data[policy->cpu];
cpu->policy = policy->policy;
mutex_lock(&intel_pstate_limits_lock);
intel_pstate_update_perf_limits(policy, cpu);
if (cpu->policy == CPUFREQ_POLICY_PERFORMANCE) {
intel_pstate_clear_update_util_hook(policy->cpu);
intel_pstate_max_within_limits(cpu);
}
intel_pstate_set_update_util_hook(policy->cpu);
if (hwp_active)
intel_pstate_hwp_set(policy->cpu);
mutex_unlock(&intel_pstate_limits_lock);
return 0;
}
static void intel_pstate_adjust_policy_max(struct cpufreq_policy *policy,
struct cpudata *cpu)
{
if (cpu->pstate.max_pstate_physical > cpu->pstate.max_pstate &&
policy->max < policy->cpuinfo.max_freq &&
policy->max > cpu->pstate.max_freq) {
pr_debug("policy->max > max non turbo frequency\n");
policy->max = policy->cpuinfo.max_freq;
}
}
static int intel_pstate_verify_policy(struct cpufreq_policy *policy)
{
struct cpudata *cpu = all_cpu_data[policy->cpu];
update_turbo_state();
cpufreq_verify_within_limits(policy, policy->cpuinfo.min_freq,
intel_pstate_get_max_freq(cpu));
if (policy->policy != CPUFREQ_POLICY_POWERSAVE &&
policy->policy != CPUFREQ_POLICY_PERFORMANCE)
return -EINVAL;
intel_pstate_adjust_policy_max(policy, cpu);
return 0;
}
static void intel_cpufreq_stop_cpu(struct cpufreq_policy *policy)
{
intel_pstate_set_min_pstate(all_cpu_data[policy->cpu]);
}
static void intel_pstate_stop_cpu(struct cpufreq_policy *policy)
{
pr_debug("CPU %d exiting\n", policy->cpu);
intel_pstate_clear_update_util_hook(policy->cpu);
if (hwp_active)
intel_pstate_hwp_save_state(policy);
else
intel_cpufreq_stop_cpu(policy);
}
static int intel_pstate_cpu_exit(struct cpufreq_policy *policy)
{
intel_pstate_exit_perf_limits(policy);
policy->fast_switch_possible = false;
return 0;
}
static int __intel_pstate_cpu_init(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
int rc;
rc = intel_pstate_init_cpu(policy->cpu);
if (rc)
return rc;
cpu = all_cpu_data[policy->cpu];
cpu->max_perf = int_ext_tofp(1);
cpu->min_perf = 0;
policy->min = cpu->pstate.min_pstate * cpu->pstate.scaling;
policy->max = cpu->pstate.turbo_pstate * cpu->pstate.scaling;
policy->cpuinfo.min_freq = cpu->pstate.min_pstate * cpu->pstate.scaling;
update_turbo_state();
policy->cpuinfo.max_freq = global.turbo_disabled ?
cpu->pstate.max_pstate : cpu->pstate.turbo_pstate;
policy->cpuinfo.max_freq *= cpu->pstate.scaling;
intel_pstate_init_acpi_perf_limits(policy);
cpumask_set_cpu(policy->cpu, policy->cpus);
policy->fast_switch_possible = true;
return 0;
}
static int intel_pstate_cpu_init(struct cpufreq_policy *policy)
{
int ret = __intel_pstate_cpu_init(policy);
if (ret)
return ret;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
if (IS_ENABLED(CONFIG_CPU_FREQ_DEFAULT_GOV_PERFORMANCE))
policy->policy = CPUFREQ_POLICY_PERFORMANCE;
else
policy->policy = CPUFREQ_POLICY_POWERSAVE;
return 0;
}
static int intel_cpufreq_verify_policy(struct cpufreq_policy *policy)
{
struct cpudata *cpu = all_cpu_data[policy->cpu];
update_turbo_state();
cpufreq_verify_within_limits(policy, policy->cpuinfo.min_freq,
intel_pstate_get_max_freq(cpu));
intel_pstate_adjust_policy_max(policy, cpu);
intel_pstate_update_perf_limits(policy, cpu);
return 0;
}
static int intel_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpudata *cpu = all_cpu_data[policy->cpu];
struct cpufreq_freqs freqs;
int target_pstate;
update_turbo_state();
freqs.old = policy->cur;
freqs.new = target_freq;
cpufreq_freq_transition_begin(policy, &freqs);
switch (relation) {
case CPUFREQ_RELATION_L:
target_pstate = DIV_ROUND_UP(freqs.new, cpu->pstate.scaling);
break;
case CPUFREQ_RELATION_H:
target_pstate = freqs.new / cpu->pstate.scaling;
break;
default:
target_pstate = DIV_ROUND_CLOSEST(freqs.new, cpu->pstate.scaling);
break;
}
target_pstate = intel_pstate_prepare_request(cpu, target_pstate);
if (target_pstate != cpu->pstate.current_pstate) {
cpu->pstate.current_pstate = target_pstate;
wrmsrl_on_cpu(policy->cpu, MSR_IA32_PERF_CTL,
pstate_funcs.get_val(cpu, target_pstate));
}
freqs.new = target_pstate * cpu->pstate.scaling;
cpufreq_freq_transition_end(policy, &freqs, false);
return 0;
}
static unsigned int intel_cpufreq_fast_switch(struct cpufreq_policy *policy,
unsigned int target_freq)
{
struct cpudata *cpu = all_cpu_data[policy->cpu];
int target_pstate;
update_turbo_state();
target_pstate = DIV_ROUND_UP(target_freq, cpu->pstate.scaling);
target_pstate = intel_pstate_prepare_request(cpu, target_pstate);
intel_pstate_update_pstate(cpu, target_pstate);
return target_pstate * cpu->pstate.scaling;
}
static int intel_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
int ret = __intel_pstate_cpu_init(policy);
if (ret)
return ret;
policy->cpuinfo.transition_latency = INTEL_CPUFREQ_TRANSITION_LATENCY;
policy->transition_delay_us = INTEL_CPUFREQ_TRANSITION_DELAY;
policy->cur = policy->cpuinfo.min_freq;
return 0;
}
static bool pid_in_use(void)
{
return intel_pstate_driver == &intel_pstate &&
pstate_funcs.update_util == intel_pstate_update_util_pid;
}
static void intel_pstate_driver_cleanup(void)
{
unsigned int cpu;
get_online_cpus();
for_each_online_cpu(cpu) {
if (all_cpu_data[cpu]) {
if (intel_pstate_driver == &intel_pstate)
intel_pstate_clear_update_util_hook(cpu);
kfree(all_cpu_data[cpu]);
all_cpu_data[cpu] = NULL;
}
}
put_online_cpus();
intel_pstate_driver = NULL;
}
static int intel_pstate_register_driver(struct cpufreq_driver *driver)
{
int ret;
memset(&global, 0, sizeof(global));
global.max_perf_pct = 100;
intel_pstate_driver = driver;
ret = cpufreq_register_driver(intel_pstate_driver);
if (ret) {
intel_pstate_driver_cleanup();
return ret;
}
global.min_perf_pct = min_perf_pct_min();
if (pid_in_use())
intel_pstate_debug_expose_params();
return 0;
}
static int intel_pstate_unregister_driver(void)
{
if (hwp_active)
return -EBUSY;
if (pid_in_use())
intel_pstate_debug_hide_params();
cpufreq_unregister_driver(intel_pstate_driver);
intel_pstate_driver_cleanup();
return 0;
}
static ssize_t intel_pstate_show_status(char *buf)
{
if (!intel_pstate_driver)
return sprintf(buf, "off\n");
return sprintf(buf, "%s\n", intel_pstate_driver == &intel_pstate ?
"active" : "passive");
}
static int intel_pstate_update_status(const char *buf, size_t size)
{
int ret;
if (size == 3 && !strncmp(buf, "off", size))
return intel_pstate_driver ?
intel_pstate_unregister_driver() : -EINVAL;
if (size == 6 && !strncmp(buf, "active", size)) {
if (intel_pstate_driver) {
if (intel_pstate_driver == &intel_pstate)
return 0;
ret = intel_pstate_unregister_driver();
if (ret)
return ret;
}
return intel_pstate_register_driver(&intel_pstate);
}
if (size == 7 && !strncmp(buf, "passive", size)) {
if (intel_pstate_driver) {
if (intel_pstate_driver == &intel_cpufreq)
return 0;
ret = intel_pstate_unregister_driver();
if (ret)
return ret;
}
return intel_pstate_register_driver(&intel_cpufreq);
}
return -EINVAL;
}
static int __init intel_pstate_msrs_not_valid(void)
{
if (!pstate_funcs.get_max() ||
!pstate_funcs.get_min() ||
!pstate_funcs.get_turbo())
return -ENODEV;
return 0;
}
static void intel_pstate_use_acpi_profile(void)
{
switch (acpi_gbl_FADT.preferred_profile) {
case PM_MOBILE:
case PM_TABLET:
case PM_APPLIANCE_PC:
case PM_DESKTOP:
case PM_WORKSTATION:
pstate_funcs.update_util = intel_pstate_update_util;
}
}
static void intel_pstate_use_acpi_profile(void)
{
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
pstate_funcs.update_util = funcs->update_util;
intel_pstate_use_acpi_profile();
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
static void intel_pstate_request_control_from_smm(void)
{
if (acpi_ppc)
acpi_processor_pstate_control();
}
static inline bool intel_pstate_platform_pwr_mgmt_exists(void) { return false; }
static inline bool intel_pstate_has_acpi_ppc(void) { return false; }
static inline void intel_pstate_request_control_from_smm(void) {}
static int __init intel_pstate_init(void)
{
int rc;
if (no_load)
return -ENODEV;
if (x86_match_cpu(hwp_support_ids)) {
copy_cpu_funcs(&core_funcs);
if (no_hwp) {
pstate_funcs.update_util = intel_pstate_update_util;
} else {
hwp_active++;
intel_pstate.attr = hwp_cpufreq_attrs;
pstate_funcs.update_util = intel_pstate_update_util_hwp;
goto hwp_cpu_matched;
}
} else {
const struct x86_cpu_id *id;
id = x86_match_cpu(intel_pstate_cpu_ids);
if (!id)
return -ENODEV;
copy_cpu_funcs((struct pstate_funcs *)id->driver_data);
}
if (intel_pstate_msrs_not_valid())
return -ENODEV;
hwp_cpu_matched:
if (intel_pstate_platform_pwr_mgmt_exists())
return -ENODEV;
if (!hwp_active && hwp_only)
return -ENOTSUPP;
pr_info("Intel P-state driver initializing\n");
all_cpu_data = vzalloc(sizeof(void *) * num_possible_cpus());
if (!all_cpu_data)
return -ENOMEM;
intel_pstate_request_control_from_smm();
intel_pstate_sysfs_expose_params();
mutex_lock(&intel_pstate_driver_lock);
rc = intel_pstate_register_driver(default_driver);
mutex_unlock(&intel_pstate_driver_lock);
if (rc)
return rc;
if (hwp_active)
pr_info("HWP enabled\n");
return 0;
}
static int __init intel_pstate_setup(char *str)
{
if (!str)
return -EINVAL;
if (!strcmp(str, "disable")) {
no_load = 1;
} else if (!strcmp(str, "passive")) {
pr_info("Passive mode enabled\n");
default_driver = &intel_cpufreq;
no_hwp = 1;
}
if (!strcmp(str, "no_hwp")) {
pr_info("HWP disabled\n");
no_hwp = 1;
}
if (!strcmp(str, "force"))
force_load = 1;
if (!strcmp(str, "hwp_only"))
hwp_only = 1;
if (!strcmp(str, "per_cpu_perf_limits"))
per_cpu_limits = true;
#ifdef CONFIG_ACPI
if (!strcmp(str, "support_acpi_ppc"))
acpi_ppc = true;
#endif
return 0;
}
