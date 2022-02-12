static unsigned int cris_freq_get_cpu_frequency(unsigned int cpu)
{
reg_config_rw_clk_ctrl clk_ctrl;
clk_ctrl = REG_RD(config, regi_config, rw_clk_ctrl);
return clk_ctrl.pll ? 200000 : 6000;
}
static int cris_freq_target(struct cpufreq_policy *policy, unsigned int state)
{
reg_config_rw_clk_ctrl clk_ctrl;
clk_ctrl = REG_RD(config, regi_config, rw_clk_ctrl);
local_irq_disable();
if (cris_freq_table[state].frequency == 200000)
clk_ctrl.pll = 1;
else
clk_ctrl.pll = 0;
REG_WR(config, regi_config, rw_clk_ctrl, clk_ctrl);
local_irq_enable();
return 0;
}
static int cris_freq_cpu_init(struct cpufreq_policy *policy)
{
return cpufreq_generic_init(policy, cris_freq_table, 1000000);
}
static int __init cris_freq_init(void)
{
int ret;
ret = cpufreq_register_driver(&cris_freq_driver);
cpufreq_register_notifier(&cris_sdram_freq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
return ret;
}
static int
cris_sdram_freq_notifier(struct notifier_block *nb, unsigned long val,
void *data)
{
int i;
struct cpufreq_freqs *freqs = data;
if (val == CPUFREQ_PRECHANGE) {
reg_bif_core_rw_sdram_timing timing =
REG_RD(bif_core, regi_bif_core, rw_sdram_timing);
timing.cpd = (freqs->new == 200000 ? 0 : 1);
if (freqs->new == 200000)
for (i = 0; i < 50000; i++) ;
REG_WR(bif_core, regi_bif_core, rw_sdram_timing, timing);
}
return 0;
}
