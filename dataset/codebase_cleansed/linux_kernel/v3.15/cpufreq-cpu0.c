static int cpu0_set_target(struct cpufreq_policy *policy, unsigned int index)
{
struct dev_pm_opp *opp;
unsigned long volt = 0, volt_old = 0, tol = 0;
unsigned int old_freq, new_freq;
long freq_Hz, freq_exact;
int ret;
freq_Hz = clk_round_rate(cpu_clk, freq_table[index].frequency * 1000);
if (freq_Hz <= 0)
freq_Hz = freq_table[index].frequency * 1000;
freq_exact = freq_Hz;
new_freq = freq_Hz / 1000;
old_freq = clk_get_rate(cpu_clk) / 1000;
if (!IS_ERR(cpu_reg)) {
rcu_read_lock();
opp = dev_pm_opp_find_freq_ceil(cpu_dev, &freq_Hz);
if (IS_ERR(opp)) {
rcu_read_unlock();
pr_err("failed to find OPP for %ld\n", freq_Hz);
return PTR_ERR(opp);
}
volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
tol = volt * voltage_tolerance / 100;
volt_old = regulator_get_voltage(cpu_reg);
}
pr_debug("%u MHz, %ld mV --> %u MHz, %ld mV\n",
old_freq / 1000, volt_old ? volt_old / 1000 : -1,
new_freq / 1000, volt ? volt / 1000 : -1);
if (!IS_ERR(cpu_reg) && new_freq > old_freq) {
ret = regulator_set_voltage_tol(cpu_reg, volt, tol);
if (ret) {
pr_err("failed to scale voltage up: %d\n", ret);
return ret;
}
}
ret = clk_set_rate(cpu_clk, freq_exact);
if (ret) {
pr_err("failed to set clock rate: %d\n", ret);
if (!IS_ERR(cpu_reg))
regulator_set_voltage_tol(cpu_reg, volt_old, tol);
return ret;
}
if (!IS_ERR(cpu_reg) && new_freq < old_freq) {
ret = regulator_set_voltage_tol(cpu_reg, volt, tol);
if (ret) {
pr_err("failed to scale voltage down: %d\n", ret);
clk_set_rate(cpu_clk, old_freq * 1000);
}
}
return ret;
}
static int cpu0_cpufreq_init(struct cpufreq_policy *policy)
{
policy->clk = cpu_clk;
return cpufreq_generic_init(policy, freq_table, transition_latency);
}
static int cpu0_cpufreq_probe(struct platform_device *pdev)
{
struct device_node *np;
int ret;
cpu_dev = get_cpu_device(0);
if (!cpu_dev) {
pr_err("failed to get cpu0 device\n");
return -ENODEV;
}
np = of_node_get(cpu_dev->of_node);
if (!np) {
pr_err("failed to find cpu0 node\n");
return -ENOENT;
}
cpu_reg = regulator_get_optional(cpu_dev, "cpu0");
if (IS_ERR(cpu_reg)) {
if (PTR_ERR(cpu_reg) == -EPROBE_DEFER) {
dev_err(cpu_dev, "cpu0 regulator not ready, retry\n");
ret = -EPROBE_DEFER;
goto out_put_node;
}
pr_warn("failed to get cpu0 regulator: %ld\n",
PTR_ERR(cpu_reg));
}
cpu_clk = clk_get(cpu_dev, NULL);
if (IS_ERR(cpu_clk)) {
ret = PTR_ERR(cpu_clk);
pr_err("failed to get cpu0 clock: %d\n", ret);
goto out_put_reg;
}
ret = of_init_opp_table(cpu_dev);
if (ret) {
pr_err("failed to init OPP table: %d\n", ret);
goto out_put_clk;
}
ret = dev_pm_opp_init_cpufreq_table(cpu_dev, &freq_table);
if (ret) {
pr_err("failed to init cpufreq table: %d\n", ret);
goto out_put_clk;
}
of_property_read_u32(np, "voltage-tolerance", &voltage_tolerance);
if (of_property_read_u32(np, "clock-latency", &transition_latency))
transition_latency = CPUFREQ_ETERNAL;
if (!IS_ERR(cpu_reg)) {
struct dev_pm_opp *opp;
unsigned long min_uV, max_uV;
int i;
for (i = 0; freq_table[i].frequency != CPUFREQ_TABLE_END; i++)
;
rcu_read_lock();
opp = dev_pm_opp_find_freq_exact(cpu_dev,
freq_table[0].frequency * 1000, true);
min_uV = dev_pm_opp_get_voltage(opp);
opp = dev_pm_opp_find_freq_exact(cpu_dev,
freq_table[i-1].frequency * 1000, true);
max_uV = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
ret = regulator_set_voltage_time(cpu_reg, min_uV, max_uV);
if (ret > 0)
transition_latency += ret * 1000;
}
ret = cpufreq_register_driver(&cpu0_cpufreq_driver);
if (ret) {
pr_err("failed register driver: %d\n", ret);
goto out_free_table;
}
if (of_find_property(np, "#cooling-cells", NULL)) {
cdev = of_cpufreq_cooling_register(np, cpu_present_mask);
if (IS_ERR(cdev))
pr_err("running cpufreq without cooling device: %ld\n",
PTR_ERR(cdev));
}
of_node_put(np);
return 0;
out_free_table:
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
out_put_clk:
if (!IS_ERR(cpu_clk))
clk_put(cpu_clk);
out_put_reg:
if (!IS_ERR(cpu_reg))
regulator_put(cpu_reg);
out_put_node:
of_node_put(np);
return ret;
}
static int cpu0_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_cooling_unregister(cdev);
cpufreq_unregister_driver(&cpu0_cpufreq_driver);
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
return 0;
}
