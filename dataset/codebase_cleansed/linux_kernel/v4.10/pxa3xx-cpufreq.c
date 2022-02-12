static int setup_freqs_table(struct cpufreq_policy *policy,
struct pxa3xx_freq_info *freqs, int num)
{
struct cpufreq_frequency_table *table;
int i;
table = kzalloc((num + 1) * sizeof(*table), GFP_KERNEL);
if (table == NULL)
return -ENOMEM;
for (i = 0; i < num; i++) {
table[i].driver_data = i;
table[i].frequency = freqs[i].cpufreq_mhz * 1000;
}
table[num].driver_data = i;
table[num].frequency = CPUFREQ_TABLE_END;
pxa3xx_freqs = freqs;
pxa3xx_freqs_num = num;
pxa3xx_freqs_table = table;
return cpufreq_table_validate_and_show(policy, table);
}
static void __update_core_freq(struct pxa3xx_freq_info *info)
{
uint32_t mask = ACCR_XN_MASK | ACCR_XL_MASK;
uint32_t accr = ACCR;
uint32_t xclkcfg;
accr &= ~(ACCR_XN_MASK | ACCR_XL_MASK | ACCR_XSPCLK_MASK);
accr |= ACCR_XN(info->core_xn) | ACCR_XL(info->core_xl);
accr |= ACCR_XSPCLK(XSPCLK_NONE);
xclkcfg = (info->core_xn == 2) ? 0x3 : 0x2;
ACCR = accr;
__asm__("mcr p14, 0, %0, c6, c0, 0\n" : : "r"(xclkcfg));
while ((ACSR & mask) != (accr & mask))
cpu_relax();
}
static void __update_bus_freq(struct pxa3xx_freq_info *info)
{
uint32_t mask;
uint32_t accr = ACCR;
mask = ACCR_SMCFS_MASK | ACCR_SFLFS_MASK | ACCR_HSS_MASK |
ACCR_DMCFS_MASK;
accr &= ~mask;
accr |= ACCR_SMCFS(info->smcfs) | ACCR_SFLFS(info->sflfs) |
ACCR_HSS(info->hss) | ACCR_DMCFS(info->dmcfs);
ACCR = accr;
while ((ACSR & mask) != (accr & mask))
cpu_relax();
}
static unsigned int pxa3xx_cpufreq_get(unsigned int cpu)
{
return pxa3xx_get_clk_frequency_khz(0);
}
static int pxa3xx_cpufreq_set(struct cpufreq_policy *policy, unsigned int index)
{
struct pxa3xx_freq_info *next;
unsigned long flags;
if (policy->cpu != 0)
return -EINVAL;
next = &pxa3xx_freqs[index];
local_irq_save(flags);
__update_core_freq(next);
__update_bus_freq(next);
local_irq_restore(flags);
return 0;
}
static int pxa3xx_cpufreq_init(struct cpufreq_policy *policy)
{
int ret = -EINVAL;
policy->min = policy->cpuinfo.min_freq = 104000;
policy->max = policy->cpuinfo.max_freq =
(cpu_is_pxa320()) ? 806000 : 624000;
policy->cpuinfo.transition_latency = 1000;
if (cpu_is_pxa300() || cpu_is_pxa310())
ret = setup_freqs_table(policy, pxa300_freqs,
ARRAY_SIZE(pxa300_freqs));
if (cpu_is_pxa320())
ret = setup_freqs_table(policy, pxa320_freqs,
ARRAY_SIZE(pxa320_freqs));
if (ret) {
pr_err("failed to setup frequency table\n");
return ret;
}
pr_info("CPUFREQ support for PXA3xx initialized\n");
return 0;
}
static int __init cpufreq_init(void)
{
if (cpu_is_pxa3xx())
return cpufreq_register_driver(&pxa3xx_cpufreq_driver);
return 0;
}
static void __exit cpufreq_exit(void)
{
cpufreq_unregister_driver(&pxa3xx_cpufreq_driver);
}
