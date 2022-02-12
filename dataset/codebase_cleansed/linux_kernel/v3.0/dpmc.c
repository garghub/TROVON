static void bfin_set_vlev(unsigned int vlev)
{
unsigned pll_lcnt;
pll_lcnt = bfin_read_PLL_LOCKCNT();
bfin_write_PLL_LOCKCNT(1);
bfin_write_VR_CTL((bfin_read_VR_CTL() & ~VLEV) | vlev);
bfin_write_PLL_LOCKCNT(pll_lcnt);
}
static unsigned int bfin_get_vlev(unsigned int freq)
{
int i;
if (!pdata)
goto err_out;
freq >>= 16;
for (i = 0; i < pdata->tabsize; i++)
if (freq <= (pdata->tuple_tab[i] & 0xFFFF))
return pdata->tuple_tab[i] >> 16;
err_out:
printk(KERN_WARNING "DPMC: No suitable CCLK VDDINT voltage pair found\n");
return VLEV_120;
}
static void bfin_idle_this_cpu(void *info)
{
unsigned long flags = 0;
unsigned long iwr0, iwr1, iwr2;
unsigned int cpu = smp_processor_id();
local_irq_save_hw(flags);
bfin_iwr_set_sup0(&iwr0, &iwr1, &iwr2);
platform_clear_ipi(cpu, IRQ_SUPPLE_0);
SSYNC();
asm("IDLE;");
bfin_iwr_restore(iwr0, iwr1, iwr2);
local_irq_restore_hw(flags);
}
static void bfin_idle_cpu(void)
{
smp_call_function(bfin_idle_this_cpu, NULL, 0);
}
static void bfin_wakeup_cpu(void)
{
unsigned int cpu;
unsigned int this_cpu = smp_processor_id();
cpumask_t mask;
cpumask_copy(&mask, cpu_online_mask);
cpumask_clear_cpu(this_cpu, &mask);
for_each_cpu(cpu, &mask)
platform_send_ipi_cpu(cpu, IRQ_SUPPLE_0);
}
static void bfin_idle_cpu(void) {}
static void bfin_wakeup_cpu(void) {}
static int
vreg_cpufreq_notifier(struct notifier_block *nb, unsigned long val, void *data)
{
struct cpufreq_freqs *freq = data;
if (freq->cpu != CPUFREQ_CPU)
return 0;
if (val == CPUFREQ_PRECHANGE && freq->old < freq->new) {
bfin_idle_cpu();
bfin_set_vlev(bfin_get_vlev(freq->new));
udelay(pdata->vr_settling_time);
bfin_wakeup_cpu();
} else if (val == CPUFREQ_POSTCHANGE && freq->old > freq->new) {
bfin_idle_cpu();
bfin_set_vlev(bfin_get_vlev(freq->new));
bfin_wakeup_cpu();
}
return 0;
}
static int __devinit bfin_dpmc_probe(struct platform_device *pdev)
{
if (pdev->dev.platform_data)
pdata = pdev->dev.platform_data;
else
return -EINVAL;
return cpufreq_register_notifier(&vreg_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
static int __devexit bfin_dpmc_remove(struct platform_device *pdev)
{
pdata = NULL;
return cpufreq_unregister_notifier(&vreg_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
static int __init bfin_dpmc_init(void)
{
return platform_driver_register(&bfin_dpmc_device_driver);
}
static void __exit bfin_dpmc_exit(void)
{
platform_driver_unregister(&bfin_dpmc_device_driver);
}
