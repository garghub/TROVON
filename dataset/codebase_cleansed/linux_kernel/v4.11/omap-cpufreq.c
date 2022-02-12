static int omap_target(struct cpufreq_policy *policy, unsigned int index)
{
int r, ret;
struct dev_pm_opp *opp;
unsigned long freq, volt = 0, volt_old = 0, tol = 0;
unsigned int old_freq, new_freq;
old_freq = policy->cur;
new_freq = freq_table[index].frequency;
freq = new_freq * 1000;
ret = clk_round_rate(policy->clk, freq);
if (ret < 0) {
dev_warn(mpu_dev,
"CPUfreq: Cannot find matching frequency for %lu\n",
freq);
return ret;
}
freq = ret;
if (mpu_reg) {
opp = dev_pm_opp_find_freq_ceil(mpu_dev, &freq);
if (IS_ERR(opp)) {
dev_err(mpu_dev, "%s: unable to find MPU OPP for %d\n",
__func__, new_freq);
return -EINVAL;
}
volt = dev_pm_opp_get_voltage(opp);
dev_pm_opp_put(opp);
tol = volt * OPP_TOLERANCE / 100;
volt_old = regulator_get_voltage(mpu_reg);
}
dev_dbg(mpu_dev, "cpufreq-omap: %u MHz, %ld mV --> %u MHz, %ld mV\n",
old_freq / 1000, volt_old ? volt_old / 1000 : -1,
new_freq / 1000, volt ? volt / 1000 : -1);
if (mpu_reg && (new_freq > old_freq)) {
r = regulator_set_voltage(mpu_reg, volt - tol, volt + tol);
if (r < 0) {
dev_warn(mpu_dev, "%s: unable to scale voltage up.\n",
__func__);
return r;
}
}
ret = clk_set_rate(policy->clk, new_freq * 1000);
if (mpu_reg && (new_freq < old_freq)) {
r = regulator_set_voltage(mpu_reg, volt - tol, volt + tol);
if (r < 0) {
dev_warn(mpu_dev, "%s: unable to scale voltage down.\n",
__func__);
clk_set_rate(policy->clk, old_freq * 1000);
return r;
}
}
return ret;
}
static inline void freq_table_free(void)
{
if (atomic_dec_and_test(&freq_table_users))
dev_pm_opp_free_cpufreq_table(mpu_dev, &freq_table);
}
static int omap_cpu_init(struct cpufreq_policy *policy)
{
int result;
policy->clk = clk_get(NULL, "cpufreq_ck");
if (IS_ERR(policy->clk))
return PTR_ERR(policy->clk);
if (!freq_table) {
result = dev_pm_opp_init_cpufreq_table(mpu_dev, &freq_table);
if (result) {
dev_err(mpu_dev,
"%s: cpu%d: failed creating freq table[%d]\n",
__func__, policy->cpu, result);
goto fail;
}
}
atomic_inc_return(&freq_table_users);
result = cpufreq_generic_init(policy, freq_table, 300 * 1000);
if (!result)
return 0;
freq_table_free();
fail:
clk_put(policy->clk);
return result;
}
static int omap_cpu_exit(struct cpufreq_policy *policy)
{
freq_table_free();
clk_put(policy->clk);
return 0;
}
static int omap_cpufreq_probe(struct platform_device *pdev)
{
mpu_dev = get_cpu_device(0);
if (!mpu_dev) {
pr_warn("%s: unable to get the MPU device\n", __func__);
return -EINVAL;
}
mpu_reg = regulator_get(mpu_dev, "vcc");
if (IS_ERR(mpu_reg)) {
pr_warn("%s: unable to get MPU regulator\n", __func__);
mpu_reg = NULL;
} else {
if (regulator_get_voltage(mpu_reg) < 0) {
pr_warn("%s: physical regulator not present for MPU\n",
__func__);
regulator_put(mpu_reg);
mpu_reg = NULL;
}
}
return cpufreq_register_driver(&omap_driver);
}
static int omap_cpufreq_remove(struct platform_device *pdev)
{
return cpufreq_unregister_driver(&omap_driver);
}
