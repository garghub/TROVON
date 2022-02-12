static int set_target(struct cpufreq_policy *policy, unsigned int index)
{
struct private_data *priv = policy->driver_data;
return dev_pm_opp_set_rate(priv->cpu_dev,
policy->freq_table[index].frequency * 1000);
}
static const char *find_supply_name(struct device *dev)
{
struct device_node *np;
struct property *pp;
int cpu = dev->id;
const char *name = NULL;
np = of_node_get(dev->of_node);
if (WARN_ON(!np))
return NULL;
if (!cpu) {
pp = of_find_property(np, "cpu0-supply", NULL);
if (pp) {
name = "cpu0";
goto node_put;
}
}
pp = of_find_property(np, "cpu-supply", NULL);
if (pp) {
name = "cpu";
goto node_put;
}
dev_dbg(dev, "no regulator for cpu%d\n", cpu);
node_put:
of_node_put(np);
return name;
}
static int resources_available(void)
{
struct device *cpu_dev;
struct regulator *cpu_reg;
struct clk *cpu_clk;
int ret = 0;
const char *name;
cpu_dev = get_cpu_device(0);
if (!cpu_dev) {
pr_err("failed to get cpu0 device\n");
return -ENODEV;
}
cpu_clk = clk_get(cpu_dev, NULL);
ret = PTR_ERR_OR_ZERO(cpu_clk);
if (ret) {
if (ret == -EPROBE_DEFER)
dev_dbg(cpu_dev, "clock not ready, retry\n");
else
dev_err(cpu_dev, "failed to get clock: %d\n", ret);
return ret;
}
clk_put(cpu_clk);
name = find_supply_name(cpu_dev);
if (!name)
return 0;
cpu_reg = regulator_get_optional(cpu_dev, name);
ret = PTR_ERR_OR_ZERO(cpu_reg);
if (ret) {
if (ret == -EPROBE_DEFER)
dev_dbg(cpu_dev, "cpu0 regulator not ready, retry\n");
else
dev_dbg(cpu_dev, "no regulator for cpu0: %d\n", ret);
return ret;
}
regulator_put(cpu_reg);
return 0;
}
static int cpufreq_init(struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *freq_table;
struct private_data *priv;
struct device *cpu_dev;
struct clk *cpu_clk;
struct dev_pm_opp *suspend_opp;
unsigned int transition_latency;
bool fallback = false;
const char *name;
int ret;
cpu_dev = get_cpu_device(policy->cpu);
if (!cpu_dev) {
pr_err("failed to get cpu%d device\n", policy->cpu);
return -ENODEV;
}
cpu_clk = clk_get(cpu_dev, NULL);
if (IS_ERR(cpu_clk)) {
ret = PTR_ERR(cpu_clk);
dev_err(cpu_dev, "%s: failed to get clk: %d\n", __func__, ret);
return ret;
}
ret = dev_pm_opp_of_get_sharing_cpus(cpu_dev, policy->cpus);
if (ret) {
if (ret != -ENOENT)
goto out_put_clk;
if (dev_pm_opp_get_sharing_cpus(cpu_dev, policy->cpus))
fallback = true;
}
name = find_supply_name(cpu_dev);
if (name) {
ret = dev_pm_opp_set_regulator(cpu_dev, name);
if (ret) {
dev_err(cpu_dev, "Failed to set regulator for cpu%d: %d\n",
policy->cpu, ret);
goto out_put_clk;
}
}
dev_pm_opp_of_cpumask_add_table(policy->cpus);
ret = dev_pm_opp_get_opp_count(cpu_dev);
if (ret <= 0) {
dev_dbg(cpu_dev, "OPP table is not ready, deferring probe\n");
ret = -EPROBE_DEFER;
goto out_free_opp;
}
if (fallback) {
cpumask_setall(policy->cpus);
ret = dev_pm_opp_set_sharing_cpus(cpu_dev, policy->cpus);
if (ret)
dev_err(cpu_dev, "%s: failed to mark OPPs as shared: %d\n",
__func__, ret);
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto out_free_opp;
}
priv->reg_name = name;
ret = dev_pm_opp_init_cpufreq_table(cpu_dev, &freq_table);
if (ret) {
dev_err(cpu_dev, "failed to init cpufreq table: %d\n", ret);
goto out_free_priv;
}
priv->cpu_dev = cpu_dev;
policy->driver_data = priv;
policy->clk = cpu_clk;
rcu_read_lock();
suspend_opp = dev_pm_opp_get_suspend_opp(cpu_dev);
if (suspend_opp)
policy->suspend_freq = dev_pm_opp_get_freq(suspend_opp) / 1000;
rcu_read_unlock();
ret = cpufreq_table_validate_and_show(policy, freq_table);
if (ret) {
dev_err(cpu_dev, "%s: invalid frequency table: %d\n", __func__,
ret);
goto out_free_cpufreq_table;
}
if (policy_has_boost_freq(policy)) {
ret = cpufreq_enable_boost_support();
if (ret)
goto out_free_cpufreq_table;
cpufreq_dt_attr[1] = &cpufreq_freq_attr_scaling_boost_freqs;
}
transition_latency = dev_pm_opp_get_max_transition_latency(cpu_dev);
if (!transition_latency)
transition_latency = CPUFREQ_ETERNAL;
policy->cpuinfo.transition_latency = transition_latency;
return 0;
out_free_cpufreq_table:
dev_pm_opp_free_cpufreq_table(cpu_dev, &freq_table);
out_free_priv:
kfree(priv);
out_free_opp:
dev_pm_opp_of_cpumask_remove_table(policy->cpus);
if (name)
dev_pm_opp_put_regulator(cpu_dev);
out_put_clk:
clk_put(cpu_clk);
return ret;
}
static int cpufreq_exit(struct cpufreq_policy *policy)
{
struct private_data *priv = policy->driver_data;
cpufreq_cooling_unregister(priv->cdev);
dev_pm_opp_free_cpufreq_table(priv->cpu_dev, &policy->freq_table);
dev_pm_opp_of_cpumask_remove_table(policy->related_cpus);
if (priv->reg_name)
dev_pm_opp_put_regulator(priv->cpu_dev);
clk_put(policy->clk);
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
u32 power_coefficient = 0;
of_property_read_u32(np, "dynamic-power-coefficient",
&power_coefficient);
priv->cdev = of_cpufreq_power_cooling_register(np,
policy->related_cpus, power_coefficient, NULL);
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
int ret;
ret = resources_available();
if (ret)
return ret;
dt_cpufreq_driver.driver_data = dev_get_platdata(&pdev->dev);
ret = cpufreq_register_driver(&dt_cpufreq_driver);
if (ret)
dev_err(&pdev->dev, "failed register driver: %d\n", ret);
return ret;
}
static int dt_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_unregister_driver(&dt_cpufreq_driver);
return 0;
}
