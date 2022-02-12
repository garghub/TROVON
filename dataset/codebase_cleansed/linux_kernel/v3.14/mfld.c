static void mfld_power_off(void)
{
}
static unsigned long __init mfld_calibrate_tsc(void)
{
unsigned long fast_calibrate;
u32 lo, hi, ratio, fsb;
rdmsr(MSR_IA32_PERF_STATUS, lo, hi);
pr_debug("IA32 perf status is 0x%x, 0x%0x\n", lo, hi);
ratio = (hi >> 8) & 0x1f;
pr_debug("ratio is %d\n", ratio);
if (!ratio) {
pr_err("read a zero ratio, should be incorrect!\n");
pr_err("force tsc ratio to 16 ...\n");
ratio = 16;
}
rdmsr(MSR_FSB_FREQ, lo, hi);
if ((lo & 0x7) == 0x7)
fsb = FSB_FREQ_83SKU;
else
fsb = FSB_FREQ_100SKU;
fast_calibrate = ratio * fsb;
pr_debug("read penwell tsc %lu khz\n", fast_calibrate);
lapic_timer_frequency = fsb * 1000 / HZ;
set_cpu_cap(&boot_cpu_data, X86_FEATURE_TSC_RELIABLE);
if (fast_calibrate)
return fast_calibrate;
return 0;
}
static void __init penwell_arch_setup(void)
{
x86_platform.calibrate_tsc = mfld_calibrate_tsc;
pm_power_off = mfld_power_off;
}
void *get_penwell_ops(void)
{
return &penwell_ops;
}
void *get_cloverview_ops(void)
{
return &penwell_ops;
}
