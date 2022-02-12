static unsigned int spear_cpufreq_get(unsigned int cpu)
{
return clk_get_rate(spear_cpufreq.clk) / 1000;
}
static struct clk *spear1340_cpu_get_possible_parent(unsigned long newfreq)
{
struct clk *sys_pclk;
int pclk;
const char *sys_clk_src[] = {
"sys_syn_clk",
"pll1_clk",
"pll2_clk",
"pll3_clk",
};
if (newfreq <= 300000000)
pclk = 0;
else if (newfreq > 300000000 && newfreq <= 500000000)
pclk = 3;
else if (newfreq == 600000000)
pclk = 1;
else
return ERR_PTR(-EINVAL);
sys_pclk = clk_get(NULL, sys_clk_src[pclk]);
if (IS_ERR(sys_pclk))
pr_err("Failed to get %s clock\n", sys_clk_src[pclk]);
return sys_pclk;
}
static int spear1340_set_cpu_rate(struct clk *sys_pclk, unsigned long newfreq)
{
struct clk *sys_clk;
int ret = 0;
sys_clk = clk_get_parent(spear_cpufreq.clk);
if (IS_ERR(sys_clk)) {
pr_err("failed to get cpu's parent (sys) clock\n");
return PTR_ERR(sys_clk);
}
ret = clk_set_rate(sys_pclk, newfreq);
if (ret) {
pr_err("Failed to set sys clk rate to %lu\n", newfreq);
return ret;
}
ret = clk_set_parent(sys_clk, sys_pclk);
if (ret) {
pr_err("Failed to set sys clk parent\n");
return ret;
}
return 0;
}
static int spear_cpufreq_target(struct cpufreq_policy *policy,
unsigned int index)
{
long newfreq;
struct clk *srcclk;
int ret, mult = 1;
newfreq = spear_cpufreq.freq_tbl[index].frequency * 1000;
if (of_machine_is_compatible("st,spear1340")) {
srcclk = spear1340_cpu_get_possible_parent(newfreq);
if (IS_ERR(srcclk)) {
pr_err("Failed to get src clk\n");
return PTR_ERR(srcclk);
}
mult = 2;
} else {
srcclk = spear_cpufreq.clk;
}
newfreq = clk_round_rate(srcclk, newfreq * mult);
if (newfreq < 0) {
pr_err("clk_round_rate failed for cpu src clock\n");
return newfreq;
}
if (mult == 2)
ret = spear1340_set_cpu_rate(srcclk, newfreq);
else
ret = clk_set_rate(spear_cpufreq.clk, newfreq);
if (ret)
pr_err("CPU Freq: cpu clk_set_rate failed: %d\n", ret);
return ret;
}
static int spear_cpufreq_init(struct cpufreq_policy *policy)
{
return cpufreq_generic_init(policy, spear_cpufreq.freq_tbl,
spear_cpufreq.transition_latency);
}
static int spear_cpufreq_driver_init(void)
{
struct device_node *np;
const struct property *prop;
struct cpufreq_frequency_table *freq_tbl;
const __be32 *val;
int cnt, i, ret;
np = of_cpu_device_node_get(0);
if (!np) {
pr_err("No cpu node found");
return -ENODEV;
}
if (of_property_read_u32(np, "clock-latency",
&spear_cpufreq.transition_latency))
spear_cpufreq.transition_latency = CPUFREQ_ETERNAL;
prop = of_find_property(np, "cpufreq_tbl", NULL);
if (!prop || !prop->value) {
pr_err("Invalid cpufreq_tbl");
ret = -ENODEV;
goto out_put_node;
}
cnt = prop->length / sizeof(u32);
val = prop->value;
freq_tbl = kmalloc(sizeof(*freq_tbl) * (cnt + 1), GFP_KERNEL);
if (!freq_tbl) {
ret = -ENOMEM;
goto out_put_node;
}
for (i = 0; i < cnt; i++) {
freq_tbl[i].driver_data = i;
freq_tbl[i].frequency = be32_to_cpup(val++);
}
freq_tbl[i].driver_data = i;
freq_tbl[i].frequency = CPUFREQ_TABLE_END;
spear_cpufreq.freq_tbl = freq_tbl;
of_node_put(np);
spear_cpufreq.clk = clk_get(NULL, "cpu_clk");
if (IS_ERR(spear_cpufreq.clk)) {
pr_err("Unable to get CPU clock\n");
ret = PTR_ERR(spear_cpufreq.clk);
goto out_put_mem;
}
ret = cpufreq_register_driver(&spear_cpufreq_driver);
if (!ret)
return 0;
pr_err("failed register driver: %d\n", ret);
clk_put(spear_cpufreq.clk);
out_put_mem:
kfree(freq_tbl);
return ret;
out_put_node:
of_node_put(np);
return ret;
}
