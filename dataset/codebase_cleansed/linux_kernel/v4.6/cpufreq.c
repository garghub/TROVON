void cpufreq_set_update_util_data(int cpu, struct update_util_data *data)
{
if (WARN_ON(data && !data->func))
return;
rcu_assign_pointer(per_cpu(cpufreq_update_util_data, cpu), data);
}
