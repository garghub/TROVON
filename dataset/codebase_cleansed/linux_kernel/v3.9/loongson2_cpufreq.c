static int loongson2_cpu_freq_notifier(struct notifier_block *nb,
unsigned long val, void *data)
{
if (val == CPUFREQ_POSTCHANGE)
current_cpu_data.udelay_val = loops_per_jiffy;
return 0;
}
static unsigned int loongson2_cpufreq_get(unsigned int cpu)
{
return clk_get_rate(cpuclk);
}
static int loongson2_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
unsigned int cpu = policy->cpu;
unsigned int newstate = 0;
cpumask_t cpus_allowed;
struct cpufreq_freqs freqs;
unsigned int freq;
if (!cpu_online(cpu))
return -ENODEV;
cpus_allowed = current->cpus_allowed;
set_cpus_allowed_ptr(current, cpumask_of(cpu));
if (cpufreq_frequency_table_target
(policy, &loongson2_clockmod_table[0], target_freq, relation,
&newstate))
return -EINVAL;
freq =
((cpu_clock_freq / 1000) *
loongson2_clockmod_table[newstate].index) / 8;
if (freq < policy->min || freq > policy->max)
return -EINVAL;
pr_debug("cpufreq: requested frequency %u Hz\n", target_freq * 1000);
freqs.cpu = cpu;
freqs.old = loongson2_cpufreq_get(cpu);
freqs.new = freq;
freqs.flags = 0;
if (freqs.new == freqs.old)
return 0;
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
set_cpus_allowed_ptr(current, &cpus_allowed);
clk_set_rate(cpuclk, freq);
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
pr_debug("cpufreq: set frequency %u kHz\n", freq);
return 0;
}
static int loongson2_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
int i;
unsigned long rate;
int ret;
if (!cpu_online(policy->cpu))
return -ENODEV;
cpuclk = clk_get(NULL, "cpu_clk");
if (IS_ERR(cpuclk)) {
printk(KERN_ERR "cpufreq: couldn't get CPU clk\n");
return PTR_ERR(cpuclk);
}
rate = cpu_clock_freq / 1000;
if (!rate) {
clk_put(cpuclk);
return -EINVAL;
}
ret = clk_set_rate(cpuclk, rate);
if (ret) {
clk_put(cpuclk);
return ret;
}
for (i = 2;
(loongson2_clockmod_table[i].frequency != CPUFREQ_TABLE_END);
i++)
loongson2_clockmod_table[i].frequency = (rate * i) / 8;
policy->cur = loongson2_cpufreq_get(policy->cpu);
cpufreq_frequency_table_get_attr(&loongson2_clockmod_table[0],
policy->cpu);
return cpufreq_frequency_table_cpuinfo(policy,
&loongson2_clockmod_table[0]);
}
static int loongson2_cpufreq_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy,
&loongson2_clockmod_table[0]);
}
static int loongson2_cpufreq_exit(struct cpufreq_policy *policy)
{
clk_put(cpuclk);
return 0;
}
static void loongson2_cpu_wait(void)
{
unsigned long flags;
u32 cpu_freq;
spin_lock_irqsave(&loongson2_wait_lock, flags);
cpu_freq = LOONGSON_CHIPCFG0;
LOONGSON_CHIPCFG0 &= ~0x7;
LOONGSON_CHIPCFG0 = cpu_freq;
spin_unlock_irqrestore(&loongson2_wait_lock, flags);
}
static int __init cpufreq_init(void)
{
int ret;
ret = platform_driver_register(&platform_driver);
if (ret)
return ret;
pr_info("cpufreq: Loongson-2F CPU frequency driver.\n");
cpufreq_register_notifier(&loongson2_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
ret = cpufreq_register_driver(&loongson2_cpufreq_driver);
if (!ret && !nowait) {
saved_cpu_wait = cpu_wait;
cpu_wait = loongson2_cpu_wait;
}
return ret;
}
static void __exit cpufreq_exit(void)
{
if (!nowait && saved_cpu_wait)
cpu_wait = saved_cpu_wait;
cpufreq_unregister_driver(&loongson2_cpufreq_driver);
cpufreq_unregister_notifier(&loongson2_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
platform_driver_unregister(&platform_driver);
}
