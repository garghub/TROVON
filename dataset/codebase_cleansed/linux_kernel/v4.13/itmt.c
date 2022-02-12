static int sched_itmt_update_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
unsigned int old_sysctl;
int ret;
mutex_lock(&itmt_update_mutex);
if (!sched_itmt_capable) {
mutex_unlock(&itmt_update_mutex);
return -EINVAL;
}
old_sysctl = sysctl_sched_itmt_enabled;
ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (!ret && write && old_sysctl != sysctl_sched_itmt_enabled) {
x86_topology_update = true;
rebuild_sched_domains();
}
mutex_unlock(&itmt_update_mutex);
return ret;
}
int sched_set_itmt_support(void)
{
mutex_lock(&itmt_update_mutex);
if (sched_itmt_capable) {
mutex_unlock(&itmt_update_mutex);
return 0;
}
itmt_sysctl_header = register_sysctl_table(itmt_root_table);
if (!itmt_sysctl_header) {
mutex_unlock(&itmt_update_mutex);
return -ENOMEM;
}
sched_itmt_capable = true;
sysctl_sched_itmt_enabled = 1;
x86_topology_update = true;
rebuild_sched_domains();
mutex_unlock(&itmt_update_mutex);
return 0;
}
void sched_clear_itmt_support(void)
{
mutex_lock(&itmt_update_mutex);
if (!sched_itmt_capable) {
mutex_unlock(&itmt_update_mutex);
return;
}
sched_itmt_capable = false;
if (itmt_sysctl_header) {
unregister_sysctl_table(itmt_sysctl_header);
itmt_sysctl_header = NULL;
}
if (sysctl_sched_itmt_enabled) {
sysctl_sched_itmt_enabled = 0;
x86_topology_update = true;
rebuild_sched_domains();
}
mutex_unlock(&itmt_update_mutex);
}
int arch_asym_cpu_priority(int cpu)
{
return per_cpu(sched_core_priority, cpu);
}
void sched_set_itmt_core_prio(int prio, int core_cpu)
{
int cpu, i = 1;
for_each_cpu(cpu, topology_sibling_cpumask(core_cpu)) {
int smt_prio;
smt_prio = prio * smp_num_siblings / i;
per_cpu(sched_core_priority, cpu) = smt_prio;
i++;
}
}
