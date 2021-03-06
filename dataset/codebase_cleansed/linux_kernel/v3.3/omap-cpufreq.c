static int omap_verify_speed(struct cpufreq_policy *policy)
{
if (!freq_table)
return -EINVAL;
return cpufreq_frequency_table_verify(policy, freq_table);
}
static unsigned int omap_getspeed(unsigned int cpu)
{
unsigned long rate;
if (cpu >= NR_CPUS)
return 0;
rate = clk_get_rate(mpu_clk) / 1000;
return rate;
}
static int omap_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int i;
int ret = 0;
struct cpufreq_freqs freqs;
if (!freq_table) {
dev_err(mpu_dev, "%s: cpu%d: no freq table!\n", __func__,
policy->cpu);
return -EINVAL;
}
ret = cpufreq_frequency_table_target(policy, freq_table, target_freq,
relation, &i);
if (ret) {
dev_dbg(mpu_dev, "%s: cpu%d: no freq match for %d(ret=%d)\n",
__func__, policy->cpu, target_freq, ret);
return ret;
}
freqs.new = freq_table[i].frequency;
if (!freqs.new) {
dev_err(mpu_dev, "%s: cpu%d: no match for freq %d\n", __func__,
policy->cpu, target_freq);
return -EINVAL;
}
freqs.old = omap_getspeed(policy->cpu);
freqs.cpu = policy->cpu;
if (freqs.old == freqs.new && policy->cur == freqs.new)
return ret;
for_each_cpu(i, policy->cpus) {
freqs.cpu = i;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
}
#ifdef CONFIG_CPU_FREQ_DEBUG
pr_info("cpufreq-omap: transition: %u --> %u\n", freqs.old, freqs.new);
#endif
ret = clk_set_rate(mpu_clk, freqs.new * 1000);
freqs.new = omap_getspeed(policy->cpu);
#ifdef CONFIG_SMP
for_each_cpu(i, policy->cpus) {
struct lpj_info *lpj = &per_cpu(lpj_ref, i);
if (!lpj->freq) {
lpj->ref = per_cpu(cpu_data, i).loops_per_jiffy;
lpj->freq = freqs.old;
}
per_cpu(cpu_data, i).loops_per_jiffy =
cpufreq_scale(lpj->ref, lpj->freq, freqs.new);
}
if (!global_lpj_ref.freq) {
global_lpj_ref.ref = loops_per_jiffy;
global_lpj_ref.freq = freqs.old;
}
loops_per_jiffy = cpufreq_scale(global_lpj_ref.ref, global_lpj_ref.freq,
freqs.new);
#endif
for_each_cpu(i, policy->cpus) {
freqs.cpu = i;
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
}
return ret;
}
static inline void freq_table_free(void)
{
if (atomic_dec_and_test(&freq_table_users))
opp_free_cpufreq_table(mpu_dev, &freq_table);
}
static int __cpuinit omap_cpu_init(struct cpufreq_policy *policy)
{
int result = 0;
mpu_clk = clk_get(NULL, mpu_clk_name);
if (IS_ERR(mpu_clk))
return PTR_ERR(mpu_clk);
if (policy->cpu >= NR_CPUS) {
result = -EINVAL;
goto fail_ck;
}
policy->cur = policy->min = policy->max = omap_getspeed(policy->cpu);
if (atomic_inc_return(&freq_table_users) == 1)
result = opp_init_cpufreq_table(mpu_dev, &freq_table);
if (result) {
dev_err(mpu_dev, "%s: cpu%d: failed creating freq table[%d]\n",
__func__, policy->cpu, result);
goto fail_ck;
}
result = cpufreq_frequency_table_cpuinfo(policy, freq_table);
if (result)
goto fail_table;
cpufreq_frequency_table_get_attr(freq_table, policy->cpu);
policy->min = policy->cpuinfo.min_freq;
policy->max = policy->cpuinfo.max_freq;
policy->cur = omap_getspeed(policy->cpu);
if (is_smp()) {
policy->shared_type = CPUFREQ_SHARED_TYPE_ANY;
cpumask_setall(policy->cpus);
}
policy->cpuinfo.transition_latency = 300 * 1000;
return 0;
fail_table:
freq_table_free();
fail_ck:
clk_put(mpu_clk);
return result;
}
static int omap_cpu_exit(struct cpufreq_policy *policy)
{
freq_table_free();
clk_put(mpu_clk);
return 0;
}
static int __init omap_cpufreq_init(void)
{
if (cpu_is_omap24xx())
mpu_clk_name = "virt_prcm_set";
else if (cpu_is_omap34xx())
mpu_clk_name = "dpll1_ck";
else if (cpu_is_omap44xx())
mpu_clk_name = "dpll_mpu_ck";
if (!mpu_clk_name) {
pr_err("%s: unsupported Silicon?\n", __func__);
return -EINVAL;
}
mpu_dev = omap_device_get_by_hwmod_name("mpu");
if (!mpu_dev) {
pr_warning("%s: unable to get the mpu device\n", __func__);
return -EINVAL;
}
return cpufreq_register_driver(&omap_driver);
}
static void __exit omap_cpufreq_exit(void)
{
cpufreq_unregister_driver(&omap_driver);
}
