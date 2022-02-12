static int pxa_cpufreq_change_voltage(pxa_freqs_t *pxa_freq)
{
int ret = 0;
int vmin, vmax;
if (!cpu_is_pxa27x())
return 0;
vmin = pxa_freq->vmin;
vmax = pxa_freq->vmax;
if ((vmin == -1) || (vmax == -1))
return 0;
ret = regulator_set_voltage(vcc_core, vmin, vmax);
if (ret)
pr_err("cpufreq: Failed to set vcc_core in [%dmV..%dmV]\n",
vmin, vmax);
return ret;
}
static void __init pxa_cpufreq_init_voltages(void)
{
vcc_core = regulator_get(NULL, "vcc_core");
if (IS_ERR(vcc_core)) {
pr_info("cpufreq: Didn't find vcc_core regulator\n");
vcc_core = NULL;
} else {
pr_info("cpufreq: Found vcc_core regulator\n");
}
}
static int pxa_cpufreq_change_voltage(pxa_freqs_t *pxa_freq)
{
return 0;
}
static void __init pxa_cpufreq_init_voltages(void) { }
static void find_freq_tables(struct cpufreq_frequency_table **freq_table,
pxa_freqs_t **pxa_freqs)
{
if (cpu_is_pxa25x()) {
if (!pxa255_turbo_table) {
*pxa_freqs = pxa255_run_freqs;
*freq_table = pxa255_run_freq_table;
} else {
*pxa_freqs = pxa255_turbo_freqs;
*freq_table = pxa255_turbo_freq_table;
}
} else if (cpu_is_pxa27x()) {
*pxa_freqs = pxa27x_freqs;
*freq_table = pxa27x_freq_table;
} else {
BUG();
}
}
static void pxa27x_guess_max_freq(void)
{
if (!pxa27x_maxfreq) {
pxa27x_maxfreq = 416000;
printk(KERN_INFO "PXA CPU 27x max frequency not defined "
"(pxa27x_maxfreq), assuming pxa271 with %dkHz maxfreq\n",
pxa27x_maxfreq);
} else {
pxa27x_maxfreq *= 1000;
}
}
static void init_sdram_rows(void)
{
uint32_t mdcnfg = __raw_readl(MDCNFG);
unsigned int drac2 = 0, drac0 = 0;
if (mdcnfg & (MDCNFG_DE2 | MDCNFG_DE3))
drac2 = MDCNFG_DRAC2(mdcnfg);
if (mdcnfg & (MDCNFG_DE0 | MDCNFG_DE1))
drac0 = MDCNFG_DRAC0(mdcnfg);
sdram_rows = 1 << (11 + max(drac0, drac2));
}
static u32 mdrefr_dri(unsigned int freq)
{
u32 interval = freq * SDRAM_TREF / sdram_rows;
return (interval - (cpu_is_pxa27x() ? 31 : 0)) / 32;
}
static int pxa_verify_policy(struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *pxa_freqs_table;
pxa_freqs_t *pxa_freqs;
int ret;
find_freq_tables(&pxa_freqs_table, &pxa_freqs);
ret = cpufreq_frequency_table_verify(policy, pxa_freqs_table);
if (freq_debug)
pr_debug("Verified CPU policy: %dKhz min to %dKhz max\n",
policy->min, policy->max);
return ret;
}
static unsigned int pxa_cpufreq_get(unsigned int cpu)
{
return get_clk_frequency_khz(0);
}
static int pxa_set_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_frequency_table *pxa_freqs_table;
pxa_freqs_t *pxa_freq_settings;
struct cpufreq_freqs freqs;
unsigned int idx;
unsigned long flags;
unsigned int new_freq_cpu, new_freq_mem;
unsigned int unused, preset_mdrefr, postset_mdrefr, cclkcfg;
int ret = 0;
find_freq_tables(&pxa_freqs_table, &pxa_freq_settings);
if (cpufreq_frequency_table_target(policy, pxa_freqs_table,
target_freq, relation, &idx)) {
return -EINVAL;
}
new_freq_cpu = pxa_freq_settings[idx].khz;
new_freq_mem = pxa_freq_settings[idx].membus;
freqs.old = policy->cur;
freqs.new = new_freq_cpu;
if (freq_debug)
pr_debug("Changing CPU frequency to %d Mhz, (SDRAM %d Mhz)\n",
freqs.new / 1000, (pxa_freq_settings[idx].div2) ?
(new_freq_mem / 2000) : (new_freq_mem / 1000));
if (vcc_core && freqs.new > freqs.old)
ret = pxa_cpufreq_change_voltage(&pxa_freq_settings[idx]);
if (ret)
return ret;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
preset_mdrefr = postset_mdrefr = __raw_readl(MDREFR);
if ((preset_mdrefr & MDREFR_DRI_MASK) > mdrefr_dri(new_freq_mem)) {
preset_mdrefr = (preset_mdrefr & ~MDREFR_DRI_MASK);
preset_mdrefr |= mdrefr_dri(new_freq_mem);
}
postset_mdrefr =
(postset_mdrefr & ~MDREFR_DRI_MASK) | mdrefr_dri(new_freq_mem);
if (pxa_freq_settings[idx].div2) {
preset_mdrefr |= MDREFR_DB2_MASK;
postset_mdrefr |= MDREFR_DB2_MASK;
} else {
postset_mdrefr &= ~MDREFR_DB2_MASK;
}
local_irq_save(flags);
CCCR = pxa_freq_settings[idx].cccr;
cclkcfg = pxa_freq_settings[idx].cclkcfg;
asm volatile(" \n\
ldr r4, [%1] /* load MDREFR */ \n\
b 2f \n\
.align 5 \n\
1: \n\
str %3, [%1] /* preset the MDREFR */ \n\
mcr p14, 0, %2, c6, c0, 0 /* set CCLKCFG[FCS] */ \n\
str %4, [%1] /* postset the MDREFR */ \n\
\n\
b 3f \n\
2: b 1b \n\
3: nop \n\
"
: "=&r" (unused)
: "r" (MDREFR), "r" (cclkcfg),
"r" (preset_mdrefr), "r" (postset_mdrefr)
: "r4", "r5");
local_irq_restore(flags);
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
if (vcc_core && freqs.new < freqs.old)
ret = pxa_cpufreq_change_voltage(&pxa_freq_settings[idx]);
return 0;
}
static int pxa_cpufreq_init(struct cpufreq_policy *policy)
{
int i;
unsigned int freq;
struct cpufreq_frequency_table *pxa255_freq_table;
pxa_freqs_t *pxa255_freqs;
if (cpu_is_pxa27x())
pxa27x_guess_max_freq();
pxa_cpufreq_init_voltages();
init_sdram_rows();
policy->cpuinfo.transition_latency = 1000;
policy->cur = get_clk_frequency_khz(0);
policy->min = policy->max = policy->cur;
for (i = 0; i < NUM_PXA25x_RUN_FREQS; i++) {
pxa255_run_freq_table[i].frequency = pxa255_run_freqs[i].khz;
pxa255_run_freq_table[i].driver_data = i;
}
pxa255_run_freq_table[i].frequency = CPUFREQ_TABLE_END;
for (i = 0; i < NUM_PXA25x_TURBO_FREQS; i++) {
pxa255_turbo_freq_table[i].frequency =
pxa255_turbo_freqs[i].khz;
pxa255_turbo_freq_table[i].driver_data = i;
}
pxa255_turbo_freq_table[i].frequency = CPUFREQ_TABLE_END;
pxa255_turbo_table = !!pxa255_turbo_table;
for (i = 0; i < NUM_PXA27x_FREQS; i++) {
freq = pxa27x_freqs[i].khz;
if (freq > pxa27x_maxfreq)
break;
pxa27x_freq_table[i].frequency = freq;
pxa27x_freq_table[i].driver_data = i;
}
pxa27x_freq_table[i].driver_data = i;
pxa27x_freq_table[i].frequency = CPUFREQ_TABLE_END;
if (cpu_is_pxa25x()) {
find_freq_tables(&pxa255_freq_table, &pxa255_freqs);
pr_info("PXA255 cpufreq using %s frequency table\n",
pxa255_turbo_table ? "turbo" : "run");
cpufreq_frequency_table_cpuinfo(policy, pxa255_freq_table);
}
else if (cpu_is_pxa27x())
cpufreq_frequency_table_cpuinfo(policy, pxa27x_freq_table);
printk(KERN_INFO "PXA CPU frequency change support initialized\n");
return 0;
}
static int __init pxa_cpu_init(void)
{
int ret = -ENODEV;
if (cpu_is_pxa25x() || cpu_is_pxa27x())
ret = cpufreq_register_driver(&pxa_cpufreq_driver);
return ret;
}
static void __exit pxa_cpu_exit(void)
{
cpufreq_unregister_driver(&pxa_cpufreq_driver);
}
