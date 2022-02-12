int dev_pm_opp_init_cpufreq_table(struct device *dev,
struct cpufreq_frequency_table **table)
{
struct dev_pm_opp *opp;
struct cpufreq_frequency_table *freq_table = NULL;
int i, max_opps, ret = 0;
unsigned long rate;
rcu_read_lock();
max_opps = dev_pm_opp_get_opp_count(dev);
if (max_opps <= 0) {
ret = max_opps ? max_opps : -ENODATA;
goto out;
}
freq_table = kcalloc((max_opps + 1), sizeof(*freq_table), GFP_ATOMIC);
if (!freq_table) {
ret = -ENOMEM;
goto out;
}
for (i = 0, rate = 0; i < max_opps; i++, rate++) {
opp = dev_pm_opp_find_freq_ceil(dev, &rate);
if (IS_ERR(opp)) {
ret = PTR_ERR(opp);
goto out;
}
freq_table[i].driver_data = i;
freq_table[i].frequency = rate / 1000;
if (dev_pm_opp_is_turbo(opp))
freq_table[i].flags = CPUFREQ_BOOST_FREQ;
}
freq_table[i].driver_data = i;
freq_table[i].frequency = CPUFREQ_TABLE_END;
*table = &freq_table[0];
out:
rcu_read_unlock();
if (ret)
kfree(freq_table);
return ret;
}
void dev_pm_opp_free_cpufreq_table(struct device *dev,
struct cpufreq_frequency_table **table)
{
if (!table)
return;
kfree(*table);
*table = NULL;
}
