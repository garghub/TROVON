static unsigned int imx6q_get_speed(unsigned int cpu)
{
return clk_get_rate(arm_clk) / 1000;
}
static int imx6q_set_target(struct cpufreq_policy *policy, unsigned int index)
{
struct dev_pm_opp *opp;
unsigned long freq_hz, volt, volt_old;
unsigned int old_freq, new_freq;
int ret;
new_freq = freq_table[index].frequency;
freq_hz = new_freq * 1000;
old_freq = clk_get_rate(arm_clk) / 1000;
rcu_read_lock();
opp = dev_pm_opp_find_freq_ceil(cpu_dev, &freq_hz);
if (IS_ERR(opp)) {
rcu_read_unlock();
dev_err(cpu_dev, "failed to find OPP for %ld\n", freq_hz);
return PTR_ERR(opp);
}
volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
volt_old = regulator_get_voltage(arm_reg);
dev_dbg(cpu_dev, "%u MHz, %ld mV --> %u MHz, %ld mV\n",
old_freq / 1000, volt_old / 1000,
new_freq / 1000, volt / 1000);
if (new_freq > old_freq) {
ret = regulator_set_voltage_tol(arm_reg, volt, 0);
if (ret) {
dev_err(cpu_dev,
"failed to scale vddarm up: %d\n", ret);
return ret;
}
if (new_freq == FREQ_1P2_GHZ / 1000) {
regulator_set_voltage_tol(pu_reg,
PU_SOC_VOLTAGE_HIGH, 0);
regulator_set_voltage_tol(soc_reg,
PU_SOC_VOLTAGE_HIGH, 0);
}
}
clk_set_parent(step_clk, pll2_pfd2_396m_clk);
clk_set_parent(pll1_sw_clk, step_clk);
if (freq_hz > clk_get_rate(pll2_pfd2_396m_clk)) {
clk_set_rate(pll1_sys_clk, new_freq * 1000);
clk_set_parent(pll1_sw_clk, pll1_sys_clk);
}
ret = clk_set_rate(arm_clk, new_freq * 1000);
if (ret) {
dev_err(cpu_dev, "failed to set clock rate: %d\n", ret);
regulator_set_voltage_tol(arm_reg, volt_old, 0);
return ret;
}
if (new_freq < old_freq) {
ret = regulator_set_voltage_tol(arm_reg, volt, 0);
if (ret) {
dev_warn(cpu_dev,
"failed to scale vddarm down: %d\n", ret);
ret = 0;
}
if (old_freq == FREQ_1P2_GHZ / 1000) {
regulator_set_voltage_tol(pu_reg,
PU_SOC_VOLTAGE_NORMAL, 0);
regulator_set_voltage_tol(soc_reg,
PU_SOC_VOLTAGE_NORMAL, 0);
}
}
return 0;
}
static int imx6q_cpufreq_init(struct cpufreq_policy *policy)
{
return cpufreq_generic_init(policy, freq_table, transition_latency);
}
static int imx6q_cpufreq_probe(struct platform_device *pdev)
{
struct device_node *np;
struct dev_pm_opp *opp;
unsigned long min_volt, max_volt;
int num, ret;
cpu_dev = get_cpu_device(0);
if (!cpu_dev) {
pr_err("failed to get cpu0 device\n");
return -ENODEV;
}
np = of_node_get(cpu_dev->of_node);
if (!np) {
dev_err(cpu_dev, "failed to find cpu0 node\n");
return -ENOENT;
}
arm_clk = devm_clk_get(cpu_dev, "arm");
pll1_sys_clk = devm_clk_get(cpu_dev, "pll1_sys");
pll1_sw_clk = devm_clk_get(cpu_dev, "pll1_sw");
step_clk = devm_clk_get(cpu_dev, "step");
pll2_pfd2_396m_clk = devm_clk_get(cpu_dev, "pll2_pfd2_396m");
if (IS_ERR(arm_clk) || IS_ERR(pll1_sys_clk) || IS_ERR(pll1_sw_clk) ||
IS_ERR(step_clk) || IS_ERR(pll2_pfd2_396m_clk)) {
dev_err(cpu_dev, "failed to get clocks\n");
ret = -ENOENT;
goto put_node;
}
arm_reg = devm_regulator_get(cpu_dev, "arm");
pu_reg = devm_regulator_get(cpu_dev, "pu");
soc_reg = devm_regulator_get(cpu_dev, "soc");
if (IS_ERR(arm_reg) || IS_ERR(pu_reg) || IS_ERR(soc_reg)) {
dev_err(cpu_dev, "failed to get regulators\n");
ret = -ENOENT;
goto put_node;
}
num = dev_pm_opp_get_opp_count(cpu_dev);
if (num < 0) {
ret = num;
dev_err(cpu_dev, "no OPP table is found: %d\n", ret);
goto put_node;
}
ret = dev_pm_opp_init_cpufreq_table(cpu_dev, &freq_table);
if (ret) {
dev_err(cpu_dev, "failed to init cpufreq table: %d\n", ret);
goto put_node;
}
if (of_property_read_u32(np, "clock-latency", &transition_latency))
transition_latency = CPUFREQ_ETERNAL;
rcu_read_lock();
opp = dev_pm_opp_find_freq_exact(cpu_dev,
freq_table[0].frequency * 1000, true);
min_volt = dev_pm_opp_get_voltage(opp);
opp = dev_pm_opp_find_freq_exact(cpu_dev,
freq_table[--num].frequency * 1000, true);
max_volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
ret = regulator_set_voltage_time(arm_reg, min_volt, max_volt);
if (ret > 0)
transition_latency += ret * 1000;
if (freq_table[num].frequency == FREQ_1P2_GHZ / 1000) {
ret = regulator_set_voltage_time(pu_reg, PU_SOC_VOLTAGE_NORMAL,
PU_SOC_VOLTAGE_HIGH);
if (ret > 0)
transition_latency += ret * 1000;
ret = regulator_set_voltage_time(soc_reg, PU_SOC_VOLTAGE_NORMAL,
PU_SOC_VOLTAGE_HIGH);
if (ret > 0)
transition_latency += ret * 1000;
}
ret = cpufreq_register_driver(&imx6q_cpufreq_driver);
if (ret) {
dev_err(cpu_dev, "failed register driver: %d\n", ret);
goto free_freq_table;
}
of_node_put(np);
return 0;
free_freq_table:
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
put_node:
of_node_put(np);
return ret;
}
static int imx6q_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_unregister_driver(&imx6q_cpufreq_driver);
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
return 0;
}
