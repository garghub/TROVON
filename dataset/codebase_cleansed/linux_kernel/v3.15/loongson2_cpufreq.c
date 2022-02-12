static int loongson2_cpu_freq_notifier(struct notifier_block *nb,
unsigned long val, void *data)
{
if (val == CPUFREQ_POSTCHANGE)
current_cpu_data.udelay_val = loops_per_jiffy;
return 0;
}
static int loongson2_cpufreq_target(struct cpufreq_policy *policy,
unsigned int index)
{
unsigned int cpu = policy->cpu;
cpumask_t cpus_allowed;
unsigned int freq;
cpus_allowed = current->cpus_allowed;
set_cpus_allowed_ptr(current, cpumask_of(cpu));
freq =
((cpu_clock_freq / 1000) *
loongson2_clockmod_table[index].driver_data) / 8;
set_cpus_allowed_ptr(current, &cpus_allowed);
clk_set_rate(policy->clk, freq * 1000);
return 0;
}
static int loongson2_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
struct clk *cpuclk;
int i;
unsigned long rate;
int ret;
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
for (i = 2;
(loongson2_clockmod_table[i].frequency != CPUFREQ_TABLE_END);
i++)
loongson2_clockmod_table[i].frequency = (rate * i) / 8;
ret = clk_set_rate(cpuclk, rate * 1000);
if (ret) {
clk_put(cpuclk);
return ret;
}
policy->clk = cpuclk;
return cpufreq_generic_init(policy, &loongson2_clockmod_table[0], 0);
}
static int loongson2_cpufreq_exit(struct cpufreq_policy *policy)
{
clk_put(policy->clk);
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
local_irq_enable();
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
