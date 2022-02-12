void cpufreq_add_update_util_hook(int cpu, struct update_util_data *data,
void (*func)(struct update_util_data *data, u64 time,
unsigned int flags))
{
if (WARN_ON(!data || !func))
return;
if (WARN_ON(per_cpu(cpufreq_update_util_data, cpu)))
return;
data->func = func;
rcu_assign_pointer(per_cpu(cpufreq_update_util_data, cpu), data);
}
void cpufreq_remove_update_util_hook(int cpu)
{
rcu_assign_pointer(per_cpu(cpufreq_update_util_data, cpu), NULL);
}
