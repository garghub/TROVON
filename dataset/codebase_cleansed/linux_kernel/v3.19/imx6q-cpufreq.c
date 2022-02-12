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
if (!IS_ERR(pu_reg)) {
ret = regulator_set_voltage_tol(pu_reg, imx6_soc_volt[index], 0);
if (ret) {
dev_err(cpu_dev, "failed to scale vddpu up: %d\n", ret);
return ret;
}
}
ret = regulator_set_voltage_tol(soc_reg, imx6_soc_volt[index], 0);
if (ret) {
dev_err(cpu_dev, "failed to scale vddsoc up: %d\n", ret);
return ret;
}
ret = regulator_set_voltage_tol(arm_reg, volt, 0);
if (ret) {
dev_err(cpu_dev,
"failed to scale vddarm up: %d\n", ret);
return ret;
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
ret = regulator_set_voltage_tol(soc_reg, imx6_soc_volt[index], 0);
if (ret) {
dev_warn(cpu_dev, "failed to scale vddsoc down: %d\n", ret);
ret = 0;
}
if (!IS_ERR(pu_reg)) {
ret = regulator_set_voltage_tol(pu_reg, imx6_soc_volt[index], 0);
if (ret) {
dev_warn(cpu_dev, "failed to scale vddpu down: %d\n", ret);
ret = 0;
}
}
}
return 0;
}
static int imx6q_cpufreq_init(struct cpufreq_policy *policy)
{
policy->clk = arm_clk;
return cpufreq_generic_init(policy, freq_table, transition_latency);
}
static int imx6q_cpufreq_probe(struct platform_device *pdev)
{
struct device_node *np;
struct dev_pm_opp *opp;
unsigned long min_volt, max_volt;
int num, ret;
const struct property *prop;
const __be32 *val;
u32 nr, i, j;
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
arm_clk = clk_get(cpu_dev, "arm");
pll1_sys_clk = clk_get(cpu_dev, "pll1_sys");
pll1_sw_clk = clk_get(cpu_dev, "pll1_sw");
step_clk = clk_get(cpu_dev, "step");
pll2_pfd2_396m_clk = clk_get(cpu_dev, "pll2_pfd2_396m");
if (IS_ERR(arm_clk) || IS_ERR(pll1_sys_clk) || IS_ERR(pll1_sw_clk) ||
IS_ERR(step_clk) || IS_ERR(pll2_pfd2_396m_clk)) {
dev_err(cpu_dev, "failed to get clocks\n");
ret = -ENOENT;
goto put_clk;
}
arm_reg = regulator_get(cpu_dev, "arm");
pu_reg = regulator_get_optional(cpu_dev, "pu");
soc_reg = regulator_get(cpu_dev, "soc");
if (IS_ERR(arm_reg) || IS_ERR(soc_reg)) {
dev_err(cpu_dev, "failed to get regulators\n");
ret = -ENOENT;
goto put_reg;
}
num = dev_pm_opp_get_opp_count(cpu_dev);
if (num < 0) {
ret = of_init_opp_table(cpu_dev);
if (ret < 0) {
dev_err(cpu_dev, "failed to init OPP table: %d\n", ret);
goto put_reg;
}
free_opp = true;
num = dev_pm_opp_get_opp_count(cpu_dev);
if (num < 0) {
ret = num;
dev_err(cpu_dev, "no OPP table is found: %d\n", ret);
goto out_free_opp;
}
}
ret = dev_pm_opp_init_cpufreq_table(cpu_dev, &freq_table);
if (ret) {
dev_err(cpu_dev, "failed to init cpufreq table: %d\n", ret);
goto put_reg;
}
imx6_soc_volt = devm_kzalloc(cpu_dev, sizeof(*imx6_soc_volt) * num, GFP_KERNEL);
if (imx6_soc_volt == NULL) {
ret = -ENOMEM;
goto free_freq_table;
}
prop = of_find_property(np, "fsl,soc-operating-points", NULL);
if (!prop || !prop->value)
goto soc_opp_out;
nr = prop->length / sizeof(u32);
if (nr % 2 || (nr / 2) < num)
goto soc_opp_out;
for (j = 0; j < num; j++) {
val = prop->value;
for (i = 0; i < nr / 2; i++) {
unsigned long freq = be32_to_cpup(val++);
unsigned long volt = be32_to_cpup(val++);
if (freq_table[j].frequency == freq) {
imx6_soc_volt[soc_opp_count++] = volt;
break;
}
}
}
soc_opp_out:
if (soc_opp_count != num) {
dev_warn(cpu_dev, "can NOT find valid fsl,soc-operating-points property in dtb, use default value!\n");
for (j = 0; j < num; j++)
imx6_soc_volt[j] = PU_SOC_VOLTAGE_NORMAL;
if (freq_table[num - 1].frequency * 1000 == FREQ_1P2_GHZ)
imx6_soc_volt[num - 1] = PU_SOC_VOLTAGE_HIGH;
}
if (of_property_read_u32(np, "clock-latency", &transition_latency))
transition_latency = CPUFREQ_ETERNAL;
ret = regulator_set_voltage_time(soc_reg, imx6_soc_volt[0], imx6_soc_volt[num - 1]);
if (ret > 0)
transition_latency += ret * 1000;
if (!IS_ERR(pu_reg)) {
ret = regulator_set_voltage_time(pu_reg, imx6_soc_volt[0], imx6_soc_volt[num - 1]);
if (ret > 0)
transition_latency += ret * 1000;
}
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
ret = cpufreq_register_driver(&imx6q_cpufreq_driver);
if (ret) {
dev_err(cpu_dev, "failed register driver: %d\n", ret);
goto free_freq_table;
}
of_node_put(np);
return 0;
free_freq_table:
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
out_free_opp:
if (free_opp)
of_free_opp_table(cpu_dev);
put_reg:
if (!IS_ERR(arm_reg))
regulator_put(arm_reg);
if (!IS_ERR(pu_reg))
regulator_put(pu_reg);
if (!IS_ERR(soc_reg))
regulator_put(soc_reg);
put_clk:
if (!IS_ERR(arm_clk))
clk_put(arm_clk);
if (!IS_ERR(pll1_sys_clk))
clk_put(pll1_sys_clk);
if (!IS_ERR(pll1_sw_clk))
clk_put(pll1_sw_clk);
if (!IS_ERR(step_clk))
clk_put(step_clk);
if (!IS_ERR(pll2_pfd2_396m_clk))
clk_put(pll2_pfd2_396m_clk);
of_node_put(np);
return ret;
}
static int imx6q_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_unregister_driver(&imx6q_cpufreq_driver);
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
if (free_opp)
of_free_opp_table(cpu_dev);
regulator_put(arm_reg);
if (!IS_ERR(pu_reg))
regulator_put(pu_reg);
regulator_put(soc_reg);
clk_put(arm_clk);
clk_put(pll1_sys_clk);
clk_put(pll1_sw_clk);
clk_put(step_clk);
clk_put(pll2_pfd2_396m_clk);
return 0;
}
