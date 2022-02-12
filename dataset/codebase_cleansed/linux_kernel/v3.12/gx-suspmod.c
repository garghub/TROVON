static void gx_write_byte(int reg, int value)
{
pci_write_config_byte(gx_params->cs55x0, reg, value);
}
static struct pci_dev * __init gx_detect_chipset(void)
{
struct pci_dev *gx_pci = NULL;
for_each_pci_dev(gx_pci) {
if ((pci_match_id(gx_chipset_tbl, gx_pci)) != NULL)
return gx_pci;
}
pr_debug("error: no supported chipset found!\n");
return NULL;
}
static unsigned int gx_get_cpuspeed(unsigned int cpu)
{
if ((gx_params->pci_suscfg & SUSMOD) == 0)
return stock_freq;
return (stock_freq * gx_params->off_duration)
/ (gx_params->on_duration + gx_params->off_duration);
}
static unsigned int gx_validate_speed(unsigned int khz, u8 *on_duration,
u8 *off_duration)
{
unsigned int i;
u8 tmp_on, tmp_off;
int old_tmp_freq = stock_freq;
int tmp_freq;
*off_duration = 1;
*on_duration = 0;
for (i = max_duration; i > 0; i--) {
tmp_off = ((khz * i) / stock_freq) & 0xff;
tmp_on = i - tmp_off;
tmp_freq = (stock_freq * tmp_off) / i;
if (abs(tmp_freq - khz) <= abs(old_tmp_freq - khz)) {
*on_duration = tmp_on;
*off_duration = tmp_off;
old_tmp_freq = tmp_freq;
}
}
return old_tmp_freq;
}
static void gx_set_cpuspeed(struct cpufreq_policy *policy, unsigned int khz)
{
u8 suscfg, pmer1;
unsigned int new_khz;
unsigned long flags;
struct cpufreq_freqs freqs;
freqs.old = gx_get_cpuspeed(0);
new_khz = gx_validate_speed(khz, &gx_params->on_duration,
&gx_params->off_duration);
freqs.new = new_khz;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
local_irq_save(flags);
if (new_khz != stock_freq) {
switch (gx_params->cs55x0->device) {
case PCI_DEVICE_ID_CYRIX_5530_LEGACY:
pmer1 = gx_params->pci_pmer1 | IRQ_SPDUP | VID_SPDUP;
gx_write_byte(PCI_IRQTC, 4);
gx_write_byte(PCI_VIDTC, 100);
gx_write_byte(PCI_PMER1, pmer1);
if (gx_params->cs55x0->revision < 0x10) {
suscfg = gx_params->pci_suscfg|SUSMOD;
} else {
suscfg = gx_params->pci_suscfg|SUSMOD|PWRSVE;
}
break;
case PCI_DEVICE_ID_CYRIX_5520:
case PCI_DEVICE_ID_CYRIX_5510:
suscfg = gx_params->pci_suscfg | SUSMOD;
break;
default:
local_irq_restore(flags);
pr_debug("fatal: try to set unknown chipset.\n");
return;
}
} else {
suscfg = gx_params->pci_suscfg & ~(SUSMOD);
gx_params->off_duration = 0;
gx_params->on_duration = 0;
pr_debug("suspend modulation disabled: cpu runs 100%% speed.\n");
}
gx_write_byte(PCI_MODOFF, gx_params->off_duration);
gx_write_byte(PCI_MODON, gx_params->on_duration);
gx_write_byte(PCI_SUSCFG, suscfg);
pci_read_config_byte(gx_params->cs55x0, PCI_SUSCFG, &suscfg);
local_irq_restore(flags);
gx_params->pci_suscfg = suscfg;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
pr_debug("suspend modulation w/ duration of ON:%d us, OFF:%d us\n",
gx_params->on_duration * 32, gx_params->off_duration * 32);
pr_debug("suspend modulation w/ clock speed: %d kHz.\n", freqs.new);
}
static int cpufreq_gx_verify(struct cpufreq_policy *policy)
{
unsigned int tmp_freq = 0;
u8 tmp1, tmp2;
if (!stock_freq || !policy)
return -EINVAL;
policy->cpu = 0;
cpufreq_verify_within_limits(policy, (stock_freq / max_duration),
stock_freq);
tmp_freq = gx_validate_speed(policy->min, &tmp1, &tmp2);
if (tmp_freq < policy->min)
tmp_freq += stock_freq / max_duration;
policy->min = tmp_freq;
if (policy->min > policy->max)
policy->max = tmp_freq;
tmp_freq = gx_validate_speed(policy->max, &tmp1, &tmp2);
if (tmp_freq > policy->max)
tmp_freq -= stock_freq / max_duration;
policy->max = tmp_freq;
if (policy->max < policy->min)
policy->max = policy->min;
cpufreq_verify_within_limits(policy, (stock_freq / max_duration),
stock_freq);
return 0;
}
static int cpufreq_gx_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
u8 tmp1, tmp2;
unsigned int tmp_freq;
if (!stock_freq || !policy)
return -EINVAL;
policy->cpu = 0;
tmp_freq = gx_validate_speed(target_freq, &tmp1, &tmp2);
while (tmp_freq < policy->min) {
tmp_freq += stock_freq / max_duration;
tmp_freq = gx_validate_speed(tmp_freq, &tmp1, &tmp2);
}
while (tmp_freq > policy->max) {
tmp_freq -= stock_freq / max_duration;
tmp_freq = gx_validate_speed(tmp_freq, &tmp1, &tmp2);
}
gx_set_cpuspeed(policy, tmp_freq);
return 0;
}
static int cpufreq_gx_cpu_init(struct cpufreq_policy *policy)
{
unsigned int maxfreq, curfreq;
if (!policy || policy->cpu != 0)
return -ENODEV;
if (pci_busclk)
maxfreq = pci_busclk * gx_freq_mult[getCx86(CX86_DIR1) & 0x0f];
else if (cpu_khz)
maxfreq = cpu_khz;
else
maxfreq = 30000 * gx_freq_mult[getCx86(CX86_DIR1) & 0x0f];
stock_freq = maxfreq;
curfreq = gx_get_cpuspeed(0);
pr_debug("cpu max frequency is %d.\n", maxfreq);
pr_debug("cpu current frequency is %dkHz.\n", curfreq);
policy->cpu = 0;
if (max_duration < POLICY_MIN_DIV)
policy->min = maxfreq / max_duration;
else
policy->min = maxfreq / POLICY_MIN_DIV;
policy->max = maxfreq;
policy->cur = curfreq;
policy->cpuinfo.min_freq = maxfreq / max_duration;
policy->cpuinfo.max_freq = maxfreq;
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
return 0;
}
static int __init cpufreq_gx_init(void)
{
int ret;
struct gxfreq_params *params;
struct pci_dev *gx_pci;
gx_pci = gx_detect_chipset();
if (gx_pci == NULL)
return -ENODEV;
if (max_duration > 0xff)
max_duration = 0xff;
pr_debug("geode suspend modulation available.\n");
params = kzalloc(sizeof(*params), GFP_KERNEL);
if (params == NULL)
return -ENOMEM;
params->cs55x0 = gx_pci;
gx_params = params;
pci_read_config_byte(params->cs55x0, PCI_SUSCFG, &(params->pci_suscfg));
pci_read_config_byte(params->cs55x0, PCI_PMER1, &(params->pci_pmer1));
pci_read_config_byte(params->cs55x0, PCI_PMER2, &(params->pci_pmer2));
pci_read_config_byte(params->cs55x0, PCI_MODON, &(params->on_duration));
pci_read_config_byte(params->cs55x0, PCI_MODOFF,
&(params->off_duration));
ret = cpufreq_register_driver(&gx_suspmod_driver);
if (ret) {
kfree(params);
return ret;
}
return 0;
}
static void __exit cpufreq_gx_exit(void)
{
cpufreq_unregister_driver(&gx_suspmod_driver);
pci_dev_put(gx_params->cs55x0);
kfree(gx_params);
}
