static void sa1100_update_dram_timings(int current_speed, int new_speed)
{
struct sa1100_dram_regs *settings = sa1100_dram_settings;
while (settings->speed != 0) {
if (new_speed == settings->speed)
break;
settings++;
}
if (settings->speed == 0) {
panic("%s: couldn't find dram setting for speed %d\n",
__func__, new_speed);
}
if (new_speed > current_speed) {
MDCNFG |= MDCNFG_CDB2;
MDCAS2 = settings->mdcas2;
MDCAS1 = settings->mdcas1;
MDCAS0 = settings->mdcas0;
MDCNFG = settings->mdcnfg;
} else {
MDCNFG |= MDCNFG_CDB2;
MDCAS0 = settings->mdcas0;
MDCAS1 = settings->mdcas1;
MDCAS2 = settings->mdcas2;
MDCNFG = settings->mdcnfg;
}
}
static int sa1100_target(struct cpufreq_policy *policy, unsigned int ppcr)
{
unsigned int cur = sa11x0_getspeed(0);
unsigned int new_freq;
new_freq = sa11x0_freq_table[ppcr].frequency;
if (new_freq > cur)
sa1100_update_dram_timings(cur, new_freq);
PPCR = ppcr;
if (new_freq < cur)
sa1100_update_dram_timings(cur, new_freq);
return 0;
}
static int __init sa1100_cpu_init(struct cpufreq_policy *policy)
{
return cpufreq_generic_init(policy, sa11x0_freq_table, 0);
}
static int __init sa1100_dram_init(void)
{
if (cpu_is_sa1100())
return cpufreq_register_driver(&sa1100_driver);
else
return -ENODEV;
}
