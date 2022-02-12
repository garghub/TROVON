static int set_target(struct cpufreq_policy *policy, unsigned int index)
{
struct dev_pm_opp *opp;
struct cpufreq_frequency_table *freq_table = policy->freq_table;
struct clk *cpu_clk = policy->clk;
struct private_data *priv = policy->driver_data;
struct device *cpu_dev = priv->cpu_dev;
struct regulator *cpu_reg = priv->cpu_reg;
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
unsigned long opp_freq;
rcu_read_lock();
opp = dev_pm_opp_find_freq_ceil(cpu_dev, &freq_Hz);
if (IS_ERR(opp)) {
rcu_read_unlock();
dev_err(cpu_dev, "failed to find OPP for %ld\n",
freq_Hz);
return PTR_ERR(opp);
}
volt = dev_pm_opp_get_voltage(opp);
opp_freq = dev_pm_opp_get_freq(opp);
rcu_read_unlock();
tol = volt * priv->voltage_tolerance / 100;
volt_old = regulator_get_voltage(cpu_reg);
dev_dbg(cpu_dev, "Found OPP: %ld kHz, %ld uV\n",
opp_freq / 1000, volt);
}
dev_dbg(cpu_dev, "%u MHz, %ld mV --> %u MHz, %ld mV\n",
old_freq / 1000, (volt_old > 0) ? volt_old / 1000 : -1,
new_freq / 1000, volt ? volt / 1000 : -1);
if (!IS_ERR(cpu_reg) && new_freq > old_freq) {
ret = regulator_set_voltage_tol(cpu_reg, volt, tol);
if (ret) {
dev_err(cpu_dev, "failed to scale voltage up: %d\n",
ret);
return ret;
}
}
ret = clk_set_rate(cpu_clk, freq_exact);
if (ret) {
dev_err(cpu_dev, "failed to set clock rate: %d\n", ret);
if (!IS_ERR(cpu_reg) && volt_old > 0)
regulator_set_voltage_tol(cpu_reg, volt_old, tol);
return ret;
}
if (!IS_ERR(cpu_reg) && new_freq < old_freq) {
ret = regulator_set_voltage_tol(cpu_reg, volt, tol);
if (ret) {
dev_err(cpu_dev, "failed to scale voltage down: %d\n",
ret);
clk_set_rate(cpu_clk, old_freq * 1000);
}
}
return ret;
}
static int allocate_resources(int cpu, struct device **cdev,
struct regulator **creg, struct clk **cclk)
{
struct device *cpu_dev;
struct regulator *cpu_reg;
struct clk *cpu_clk;
int ret = 0;
char *reg_cpu0 = "cpu0", *reg_cpu = "cpu", *reg;
cpu_dev = get_cpu_device(cpu);
if (!cpu_dev) {
pr_err("failed to get cpu%d device\n", cpu);
return -ENODEV;
}
if (!cpu)
reg = reg_cpu0;
else
reg = reg_cpu;
try_again:
cpu_reg = regulator_get_optional(cpu_dev, reg);
if (IS_ERR(cpu_reg)) {
if (PTR_ERR(cpu_reg) == -EPROBE_DEFER) {
dev_dbg(cpu_dev, "cpu%d regulator not ready, retry\n",
cpu);
return -EPROBE_DEFER;
}
if (reg == reg_cpu0) {
reg = reg_cpu;
goto try_again;
}
dev_dbg(cpu_dev, "no regulator for cpu%d: %ld\n",
cpu, PTR_ERR(cpu_reg));
}
cpu_clk = clk_get(cpu_dev, NULL);
if (IS_ERR(cpu_clk)) {
if (!IS_ERR(cpu_reg))
regulator_put(cpu_reg);
ret = PTR_ERR(cpu_clk);
if (ret == -EPROBE_DEFER)
dev_dbg(cpu_dev, "cpu%d clock not ready, retry\n", cpu);
else
dev_err(cpu_dev, "failed to get cpu%d clock: %d\n", cpu,
ret);
} else {
*cdev = cpu_dev;
*creg = cpu_reg;
*cclk = cpu_clk;
}
return ret;
}
static int cpufreq_init(struct cpufreq_policy *policy)
{
struct cpufreq_dt_platform_data *pd;
struct cpufreq_frequency_table *freq_table;
struct device_node *np;
struct private_data *priv;
struct device *cpu_dev;
struct regulator *cpu_reg;
struct clk *cpu_clk;
unsigned long min_uV = ~0, max_uV = 0;
unsigned int transition_latency;
int ret;
ret = allocate_resources(policy->cpu, &cpu_dev, &cpu_reg, &cpu_clk);
if (ret) {
pr_err("%s: Failed to allocate resources: %d\n", __func__, ret);
return ret;
}
np = of_node_get(cpu_dev->of_node);
if (!np) {
dev_err(cpu_dev, "failed to find cpu%d node\n", policy->cpu);
ret = -ENOENT;
goto out_put_reg_clk;
}
of_init_opp_table(cpu_dev);
ret = dev_pm_opp_get_opp_count(cpu_dev);
if (ret <= 0) {
pr_debug("OPP table is not ready, deferring probe\n");
ret = -EPROBE_DEFER;
goto out_free_opp;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto out_free_opp;
}
of_property_read_u32(np, "voltage-tolerance", &priv->voltage_tolerance);
if (of_property_read_u32(np, "clock-latency", &transition_latency))
transition_latency = CPUFREQ_ETERNAL;
if (!IS_ERR(cpu_reg)) {
unsigned long opp_freq = 0;
while (1) {
struct dev_pm_opp *opp;
unsigned long opp_uV, tol_uV;
rcu_read_lock();
opp = dev_pm_opp_find_freq_ceil(cpu_dev, &opp_freq);
if (IS_ERR(opp)) {
rcu_read_unlock();
break;
}
opp_uV = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
tol_uV = opp_uV * priv->voltage_tolerance / 100;
if (regulator_is_supported_voltage(cpu_reg, opp_uV,
opp_uV + tol_uV)) {
if (opp_uV < min_uV)
min_uV = opp_uV;
if (opp_uV > max_uV)
max_uV = opp_uV;
} else {
dev_pm_opp_disable(cpu_dev, opp_freq);
}
opp_freq++;
}
ret = regulator_set_voltage_time(cpu_reg, min_uV, max_uV);
if (ret > 0)
transition_latency += ret * 1000;
}
ret = dev_pm_opp_init_cpufreq_table(cpu_dev, &freq_table);
if (ret) {
pr_err("failed to init cpufreq table: %d\n", ret);
goto out_free_priv;
}
priv->cpu_dev = cpu_dev;
priv->cpu_reg = cpu_reg;
policy->driver_data = priv;
policy->clk = cpu_clk;
ret = cpufreq_table_validate_and_show(policy, freq_table);
if (ret) {
dev_err(cpu_dev, "%s: invalid frequency table: %d\n", __func__,
ret);
goto out_free_cpufreq_table;
}
policy->cpuinfo.transition_latency = transition_latency;
pd = cpufreq_get_driver_data();
if (!pd || !pd->independent_clocks)
cpumask_setall(policy->cpus);
of_node_put(np);
return 0;
out_free_cpufreq_table:
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
out_free_priv:
kfree(priv);
out_free_opp:
of_free_opp_table(cpu_dev);
of_node_put(np);
out_put_reg_clk:
clk_put(cpu_clk);
if (!IS_ERR(cpu_reg))
regulator_put(cpu_reg);
return ret;
}
static int cpufreq_exit(struct cpufreq_policy *policy)
{
struct private_data *priv = policy->driver_data;
if (priv->cdev)
cpufreq_cooling_unregister(priv->cdev);
dev_pm_opp_free_cpufreq_table(priv->cpu_dev, &policy->freq_table);
of_free_opp_table(priv->cpu_dev);
clk_put(policy->clk);
if (!IS_ERR(priv->cpu_reg))
regulator_put(priv->cpu_reg);
kfree(priv);
return 0;
}
static void cpufreq_ready(struct cpufreq_policy *policy)
{
struct private_data *priv = policy->driver_data;
struct device_node *np = of_node_get(priv->cpu_dev->of_node);
if (WARN_ON(!np))
return;
if (of_find_property(np, "#cooling-cells", NULL)) {
priv->cdev = of_cpufreq_cooling_register(np,
policy->related_cpus);
if (IS_ERR(priv->cdev)) {
dev_err(priv->cpu_dev,
"running cpufreq without cooling device: %ld\n",
PTR_ERR(priv->cdev));
priv->cdev = NULL;
}
}
of_node_put(np);
}
static int dt_cpufreq_probe(struct platform_device *pdev)
{
struct device *cpu_dev;
struct regulator *cpu_reg;
struct clk *cpu_clk;
int ret;
ret = allocate_resources(0, &cpu_dev, &cpu_reg, &cpu_clk);
if (ret)
return ret;
clk_put(cpu_clk);
if (!IS_ERR(cpu_reg))
regulator_put(cpu_reg);
dt_cpufreq_driver.driver_data = dev_get_platdata(&pdev->dev);
ret = cpufreq_register_driver(&dt_cpufreq_driver);
if (ret)
dev_err(cpu_dev, "failed register driver: %d\n", ret);
return ret;
}
static int dt_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_unregister_driver(&dt_cpufreq_driver);
return 0;
}
