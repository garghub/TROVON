static int centrino_cpu_init_table(struct cpufreq_policy *policy)
{
struct cpuinfo_x86 *cpu = &cpu_data(policy->cpu);
struct cpu_model *model;
for(model = models; model->cpu_id != NULL; model++)
if (centrino_verify_cpu_id(cpu, model->cpu_id) &&
(model->model_name == NULL ||
strcmp(cpu->x86_model_id, model->model_name) == 0))
break;
if (model->cpu_id == NULL) {
pr_debug("no support for CPU model \"%s\": "
"send /proc/cpuinfo to " MAINTAINER "\n",
cpu->x86_model_id);
return -ENOENT;
}
if (model->op_points == NULL) {
pr_debug("no table support for CPU model \"%s\"\n",
cpu->x86_model_id);
pr_debug("try using the acpi-cpufreq driver\n");
return -ENOENT;
}
per_cpu(centrino_model, policy->cpu) = model;
pr_debug("found \"%s\": max frequency: %dkHz\n",
model->model_name, model->max_freq);
return 0;
}
static inline int centrino_cpu_init_table(struct cpufreq_policy *policy)
{
return -ENODEV;
}
static int centrino_verify_cpu_id(const struct cpuinfo_x86 *c,
const struct cpu_id *x)
{
if ((c->x86 == x->x86) &&
(c->x86_model == x->x86_model) &&
(c->x86_mask == x->x86_mask))
return 1;
return 0;
}
static unsigned extract_clock(unsigned msr, unsigned int cpu, int failsafe)
{
int i;
if ((per_cpu(centrino_cpu, cpu) == &cpu_ids[CPU_BANIAS]) ||
(per_cpu(centrino_cpu, cpu) == &cpu_ids[CPU_DOTHAN_A1]) ||
(per_cpu(centrino_cpu, cpu) == &cpu_ids[CPU_DOTHAN_B0])) {
msr = (msr >> 8) & 0xff;
return msr * 100000;
}
if ((!per_cpu(centrino_model, cpu)) ||
(!per_cpu(centrino_model, cpu)->op_points))
return 0;
msr &= 0xffff;
for (i = 0;
per_cpu(centrino_model, cpu)->op_points[i].frequency
!= CPUFREQ_TABLE_END;
i++) {
if (msr == per_cpu(centrino_model, cpu)->op_points[i].index)
return per_cpu(centrino_model, cpu)->
op_points[i].frequency;
}
if (failsafe)
return per_cpu(centrino_model, cpu)->op_points[i-1].frequency;
else
return 0;
}
static unsigned int get_cur_freq(unsigned int cpu)
{
unsigned l, h;
unsigned clock_freq;
rdmsr_on_cpu(cpu, MSR_IA32_PERF_STATUS, &l, &h);
clock_freq = extract_clock(l, cpu, 0);
if (unlikely(clock_freq == 0)) {
rdmsr_on_cpu(cpu, MSR_IA32_PERF_CTL, &l, &h);
clock_freq = extract_clock(l, cpu, 1);
}
return clock_freq;
}
static int centrino_cpu_init(struct cpufreq_policy *policy)
{
struct cpuinfo_x86 *cpu = &cpu_data(policy->cpu);
unsigned freq;
unsigned l, h;
int ret;
int i;
if (cpu->x86_vendor != X86_VENDOR_INTEL ||
!cpu_has(cpu, X86_FEATURE_EST))
return -ENODEV;
if (cpu_has(cpu, X86_FEATURE_CONSTANT_TSC))
centrino_driver.flags |= CPUFREQ_CONST_LOOPS;
if (policy->cpu != 0)
return -ENODEV;
for (i = 0; i < N_IDS; i++)
if (centrino_verify_cpu_id(cpu, &cpu_ids[i]))
break;
if (i != N_IDS)
per_cpu(centrino_cpu, policy->cpu) = &cpu_ids[i];
if (!per_cpu(centrino_cpu, policy->cpu)) {
pr_debug("found unsupported CPU with "
"Enhanced SpeedStep: send /proc/cpuinfo to "
MAINTAINER "\n");
return -ENODEV;
}
if (centrino_cpu_init_table(policy)) {
return -ENODEV;
}
rdmsr(MSR_IA32_MISC_ENABLE, l, h);
if (!(l & MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP)) {
l |= MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP;
pr_debug("trying to enable Enhanced SpeedStep (%x)\n", l);
wrmsr(MSR_IA32_MISC_ENABLE, l, h);
rdmsr(MSR_IA32_MISC_ENABLE, l, h);
if (!(l & MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP)) {
printk(KERN_INFO PFX
"couldn't enable Enhanced SpeedStep\n");
return -ENODEV;
}
}
freq = get_cur_freq(policy->cpu);
policy->cpuinfo.transition_latency = 10000;
policy->cur = freq;
pr_debug("centrino_cpu_init: cur=%dkHz\n", policy->cur);
ret = cpufreq_frequency_table_cpuinfo(policy,
per_cpu(centrino_model, policy->cpu)->op_points);
if (ret)
return (ret);
cpufreq_frequency_table_get_attr(
per_cpu(centrino_model, policy->cpu)->op_points, policy->cpu);
return 0;
}
static int centrino_cpu_exit(struct cpufreq_policy *policy)
{
unsigned int cpu = policy->cpu;
if (!per_cpu(centrino_model, cpu))
return -ENODEV;
cpufreq_frequency_table_put_attr(cpu);
per_cpu(centrino_model, cpu) = NULL;
return 0;
}
static int centrino_verify (struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy,
per_cpu(centrino_model, policy->cpu)->op_points);
}
static int centrino_target (struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int newstate = 0;
unsigned int msr, oldmsr = 0, h = 0, cpu = policy->cpu;
struct cpufreq_freqs freqs;
int retval = 0;
unsigned int j, k, first_cpu, tmp;
cpumask_var_t covered_cpus;
if (unlikely(!zalloc_cpumask_var(&covered_cpus, GFP_KERNEL)))
return -ENOMEM;
if (unlikely(per_cpu(centrino_model, cpu) == NULL)) {
retval = -ENODEV;
goto out;
}
if (unlikely(cpufreq_frequency_table_target(policy,
per_cpu(centrino_model, cpu)->op_points,
target_freq,
relation,
&newstate))) {
retval = -EINVAL;
goto out;
}
first_cpu = 1;
for_each_cpu(j, policy->cpus) {
int good_cpu;
if (!cpu_online(j))
continue;
if (policy->shared_type == CPUFREQ_SHARED_TYPE_ANY)
good_cpu = cpumask_any_and(policy->cpus,
cpu_online_mask);
else
good_cpu = j;
if (good_cpu >= nr_cpu_ids) {
pr_debug("couldn't limit to CPUs in this domain\n");
retval = -EAGAIN;
if (first_cpu) {
goto out;
}
break;
}
msr = per_cpu(centrino_model, cpu)->op_points[newstate].index;
if (first_cpu) {
rdmsr_on_cpu(good_cpu, MSR_IA32_PERF_CTL, &oldmsr, &h);
if (msr == (oldmsr & 0xffff)) {
pr_debug("no change needed - msr was and needs "
"to be %x\n", oldmsr);
retval = 0;
goto out;
}
freqs.old = extract_clock(oldmsr, cpu, 0);
freqs.new = extract_clock(msr, cpu, 0);
pr_debug("target=%dkHz old=%d new=%d msr=%04x\n",
target_freq, freqs.old, freqs.new, msr);
for_each_cpu(k, policy->cpus) {
if (!cpu_online(k))
continue;
freqs.cpu = k;
cpufreq_notify_transition(&freqs,
CPUFREQ_PRECHANGE);
}
first_cpu = 0;
oldmsr &= ~0xffff;
msr &= 0xffff;
oldmsr |= msr;
}
wrmsr_on_cpu(good_cpu, MSR_IA32_PERF_CTL, oldmsr, h);
if (policy->shared_type == CPUFREQ_SHARED_TYPE_ANY)
break;
cpumask_set_cpu(j, covered_cpus);
}
for_each_cpu(k, policy->cpus) {
if (!cpu_online(k))
continue;
freqs.cpu = k;
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
}
if (unlikely(retval)) {
for_each_cpu(j, covered_cpus)
wrmsr_on_cpu(j, MSR_IA32_PERF_CTL, oldmsr, h);
tmp = freqs.new;
freqs.new = freqs.old;
freqs.old = tmp;
for_each_cpu(j, policy->cpus) {
if (!cpu_online(j))
continue;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
}
}
retval = 0;
out:
free_cpumask_var(covered_cpus);
return retval;
}
static int __init centrino_init(void)
{
if (!x86_match_cpu(centrino_ids))
return -ENODEV;
return cpufreq_register_driver(&centrino_driver);
}
static void __exit centrino_exit(void)
{
cpufreq_unregister_driver(&centrino_driver);
}
