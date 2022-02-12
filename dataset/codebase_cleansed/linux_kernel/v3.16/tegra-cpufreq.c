static unsigned int tegra_get_intermediate(struct cpufreq_policy *policy,
unsigned int index)
{
unsigned int ifreq = clk_get_rate(pll_p_clk) / 1000;
if ((freq_table[index].frequency == ifreq) || (policy->cur == ifreq))
return 0;
return ifreq;
}
static int tegra_target_intermediate(struct cpufreq_policy *policy,
unsigned int index)
{
int ret;
clk_prepare_enable(pll_x_clk);
ret = clk_set_parent(cpu_clk, pll_p_clk);
if (ret)
clk_disable_unprepare(pll_x_clk);
else
pll_x_prepared = true;
return ret;
}
static int tegra_target(struct cpufreq_policy *policy, unsigned int index)
{
unsigned long rate = freq_table[index].frequency;
unsigned int ifreq = clk_get_rate(pll_p_clk) / 1000;
int ret = 0;
if (rate >= 816000)
clk_set_rate(emc_clk, 600000000);
else if (rate >= 456000)
clk_set_rate(emc_clk, 300000000);
else
clk_set_rate(emc_clk, 100000000);
if (rate == ifreq)
return clk_set_parent(cpu_clk, pll_p_clk);
ret = clk_set_rate(pll_x_clk, rate * 1000);
if (ret)
pr_err("Failed to change pll_x to %lu\n", rate);
ret = clk_set_parent(cpu_clk, pll_x_clk);
WARN_ON(ret);
if (pll_x_prepared) {
clk_disable_unprepare(pll_x_clk);
pll_x_prepared = false;
}
return ret;
}
static int tegra_cpu_init(struct cpufreq_policy *policy)
{
int ret;
if (policy->cpu >= NUM_CPUS)
return -EINVAL;
clk_prepare_enable(emc_clk);
clk_prepare_enable(cpu_clk);
ret = cpufreq_generic_init(policy, freq_table, 300 * 1000);
if (ret) {
clk_disable_unprepare(cpu_clk);
clk_disable_unprepare(emc_clk);
return ret;
}
policy->clk = cpu_clk;
policy->suspend_freq = freq_table[0].frequency;
return 0;
}
static int tegra_cpu_exit(struct cpufreq_policy *policy)
{
clk_disable_unprepare(cpu_clk);
clk_disable_unprepare(emc_clk);
return 0;
}
static int __init tegra_cpufreq_init(void)
{
cpu_clk = clk_get_sys(NULL, "cclk");
if (IS_ERR(cpu_clk))
return PTR_ERR(cpu_clk);
pll_x_clk = clk_get_sys(NULL, "pll_x");
if (IS_ERR(pll_x_clk))
return PTR_ERR(pll_x_clk);
pll_p_clk = clk_get_sys(NULL, "pll_p");
if (IS_ERR(pll_p_clk))
return PTR_ERR(pll_p_clk);
emc_clk = clk_get_sys("cpu", "emc");
if (IS_ERR(emc_clk)) {
clk_put(cpu_clk);
return PTR_ERR(emc_clk);
}
return cpufreq_register_driver(&tegra_cpufreq_driver);
}
static void __exit tegra_cpufreq_exit(void)
{
cpufreq_unregister_driver(&tegra_cpufreq_driver);
clk_put(emc_clk);
clk_put(cpu_clk);
}
