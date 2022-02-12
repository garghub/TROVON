static int htp_freq_to_cpu_freq(unsigned int clk_mult)
{
return mips_hpt_frequency * clk_mult / 1000;
}
static struct cpufreq_frequency_table *
bmips_cpufreq_get_freq_table(const struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *table;
unsigned long cpu_freq;
int i;
cpu_freq = htp_freq_to_cpu_freq(priv->clk_mult);
table = kmalloc((priv->max_freqs + 1) * sizeof(*table), GFP_KERNEL);
if (!table)
return ERR_PTR(-ENOMEM);
for (i = 0; i < priv->max_freqs; i++) {
table[i].frequency = cpu_freq / (1 << i);
table[i].driver_data = i;
}
table[i].frequency = CPUFREQ_TABLE_END;
return table;
}
static unsigned int bmips_cpufreq_get(unsigned int cpu)
{
unsigned int div;
uint32_t mode;
switch (priv->bmips_type) {
case BMIPS5200:
case BMIPS5000:
mode = read_c0_brcm_mode();
div = ((mode >> BMIPS5_CLK_DIV_SHIFT) & BMIPS5_CLK_DIV_MASK);
break;
default:
div = 0;
}
return htp_freq_to_cpu_freq(priv->clk_mult) / (1 << div);
}
static int bmips_cpufreq_target_index(struct cpufreq_policy *policy,
unsigned int index)
{
unsigned int div = policy->freq_table[index].driver_data;
switch (priv->bmips_type) {
case BMIPS5200:
case BMIPS5000:
change_c0_brcm_mode(BMIPS5_CLK_DIV_MASK << BMIPS5_CLK_DIV_SHIFT,
(1 << BMIPS5_CLK_DIV_SET_SHIFT) |
(div << BMIPS5_CLK_DIV_SHIFT));
break;
default:
return -ENOTSUPP;
}
return 0;
}
static int bmips_cpufreq_exit(struct cpufreq_policy *policy)
{
kfree(policy->freq_table);
return 0;
}
static int bmips_cpufreq_init(struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *freq_table;
int ret;
freq_table = bmips_cpufreq_get_freq_table(policy);
if (IS_ERR(freq_table)) {
ret = PTR_ERR(freq_table);
pr_err("%s: couldn't determine frequency table (%d).\n",
BMIPS_CPUFREQ_NAME, ret);
return ret;
}
ret = cpufreq_generic_init(policy, freq_table, TRANSITION_LATENCY);
if (ret)
bmips_cpufreq_exit(policy);
else
pr_info("%s: registered\n", BMIPS_CPUFREQ_NAME);
return ret;
}
static int __init bmips_cpufreq_probe(void)
{
struct cpufreq_compat *cc;
struct device_node *np;
for (cc = bmips_cpufreq_compat; cc->compatible; cc++) {
np = of_find_compatible_node(NULL, "cpu", cc->compatible);
if (np) {
of_node_put(np);
priv = cc;
break;
}
}
if (!cc->compatible)
return -ENODEV;
return cpufreq_register_driver(&bmips_cpufreq_driver);
}
