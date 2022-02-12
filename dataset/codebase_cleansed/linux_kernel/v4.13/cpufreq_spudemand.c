static int calc_freq(struct spu_gov_info_struct *info)
{
int cpu;
int busy_spus;
cpu = info->policy->cpu;
busy_spus = atomic_read(&cbe_spu_info[cpu_to_node(cpu)].busy_spus);
CALC_LOAD(info->busy_spus, EXP, busy_spus * FIXED_1);
pr_debug("cpu %d: busy_spus=%d, info->busy_spus=%ld\n",
cpu, busy_spus, info->busy_spus);
return info->policy->max * info->busy_spus / FIXED_1;
}
static void spu_gov_work(struct work_struct *work)
{
struct spu_gov_info_struct *info;
int delay;
unsigned long target_freq;
info = container_of(work, struct spu_gov_info_struct, work.work);
BUG_ON(info->policy == NULL);
target_freq = calc_freq(info);
__cpufreq_driver_target(info->policy, target_freq, CPUFREQ_RELATION_H);
delay = usecs_to_jiffies(info->poll_int);
schedule_delayed_work_on(info->policy->cpu, &info->work, delay);
}
static void spu_gov_init_work(struct spu_gov_info_struct *info)
{
int delay = usecs_to_jiffies(info->poll_int);
INIT_DEFERRABLE_WORK(&info->work, spu_gov_work);
schedule_delayed_work_on(info->policy->cpu, &info->work, delay);
}
static void spu_gov_cancel_work(struct spu_gov_info_struct *info)
{
cancel_delayed_work_sync(&info->work);
}
static int spu_gov_start(struct cpufreq_policy *policy)
{
unsigned int cpu = policy->cpu;
struct spu_gov_info_struct *info = &per_cpu(spu_gov_info, cpu);
struct spu_gov_info_struct *affected_info;
int i;
if (!cpu_online(cpu)) {
printk(KERN_ERR "cpu %d is not online\n", cpu);
return -EINVAL;
}
if (!policy->cur) {
printk(KERN_ERR "no cpu specified in policy\n");
return -EINVAL;
}
for_each_cpu(i, policy->cpus) {
affected_info = &per_cpu(spu_gov_info, i);
affected_info->policy = policy;
}
info->poll_int = POLL_TIME;
spu_gov_init_work(info);
return 0;
}
static void spu_gov_stop(struct cpufreq_policy *policy)
{
unsigned int cpu = policy->cpu;
struct spu_gov_info_struct *info = &per_cpu(spu_gov_info, cpu);
int i;
spu_gov_cancel_work(info);
for_each_cpu (i, policy->cpus) {
info = &per_cpu(spu_gov_info, i);
info->policy = NULL;
}
}
static int __init spu_gov_init(void)
{
int ret;
ret = cpufreq_register_governor(&spu_governor);
if (ret)
printk(KERN_ERR "registration of governor failed\n");
return ret;
}
static void __exit spu_gov_exit(void)
{
cpufreq_unregister_governor(&spu_governor);
}
