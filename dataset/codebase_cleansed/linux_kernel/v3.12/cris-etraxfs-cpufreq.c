static unsigned int cris_freq_get_cpu_frequency(unsigned int cpu)
{
reg_config_rw_clk_ctrl clk_ctrl;
clk_ctrl = REG_RD(config, regi_config, rw_clk_ctrl);
return clk_ctrl.pll ? 200000 : 6000;
}
static void cris_freq_set_cpu_state(struct cpufreq_policy *policy,
unsigned int state)
{
struct cpufreq_freqs freqs;
reg_config_rw_clk_ctrl clk_ctrl;
clk_ctrl = REG_RD(config, regi_config, rw_clk_ctrl);
freqs.old = cris_freq_get_cpu_frequency(policy->cpu);
freqs.new = cris_freq_table[state].frequency;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
local_irq_disable();
if (cris_freq_table[state].frequency == 200000)
clk_ctrl.pll = 1;
else
clk_ctrl.pll = 0;
REG_WR(config, regi_config, rw_clk_ctrl, clk_ctrl);
local_irq_enable();
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
}
static int cris_freq_verify(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, &cris_freq_table[0]);
}
static int cris_freq_target(struct cpufreq_policy *policy,
unsigned int target_freq, unsigned int relation)
{
unsigned int newstate = 0;
if (cpufreq_frequency_table_target
(policy, cris_freq_table, target_freq, relation, &newstate))
return -EINVAL;
cris_freq_set_cpu_state(policy, newstate);
return 0;
}
static int cris_freq_cpu_init(struct cpufreq_policy *policy)
{
int result;
policy->cpuinfo.transition_latency = 1000000;
policy->cur = cris_freq_get_cpu_frequency(0);
result = cpufreq_frequency_table_cpuinfo(policy, cris_freq_table);
if (result)
return (result);
cpufreq_frequency_table_get_attr(cris_freq_table, policy->cpu);
return 0;
}
static int cris_freq_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
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
