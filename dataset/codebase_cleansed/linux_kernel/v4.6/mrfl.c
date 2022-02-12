static unsigned long __init tangier_calibrate_tsc(void)
{
unsigned long fast_calibrate;
u32 lo, hi, ratio, fsb, bus_freq;
rdmsr(MSR_PLATFORM_INFO, lo, hi);
pr_debug("IA32 PLATFORM_INFO is 0x%x : %x\n", hi, lo);
ratio = (lo >> 8) & 0xFF;
pr_debug("ratio is %d\n", ratio);
if (!ratio) {
pr_err("Read a zero ratio, force tsc ratio to 4 ...\n");
ratio = 4;
}
rdmsr(MSR_FSB_FREQ, lo, hi);
pr_debug("Actual FSB frequency detected by SOC 0x%x : %x\n",
hi, lo);
bus_freq = lo & 0x7;
pr_debug("bus_freq = 0x%x\n", bus_freq);
if (bus_freq == 0)
fsb = FSB_FREQ_100SKU;
else if (bus_freq == 1)
fsb = FSB_FREQ_100SKU;
else if (bus_freq == 2)
fsb = FSB_FREQ_133SKU;
else if (bus_freq == 3)
fsb = FSB_FREQ_167SKU;
else if (bus_freq == 4)
fsb = FSB_FREQ_83SKU;
else if (bus_freq == 5)
fsb = FSB_FREQ_400SKU;
else if (bus_freq == 6)
fsb = FSB_FREQ_267SKU;
else if (bus_freq == 7)
fsb = FSB_FREQ_333SKU;
else {
BUG();
pr_err("Invalid bus_freq! Setting to minimal value!\n");
fsb = FSB_FREQ_100SKU;
}
fast_calibrate = ratio * fsb;
pr_debug("calculate tangier tsc %lu KHz\n", fast_calibrate);
lapic_timer_frequency = (fsb * 1000) / HZ;
pr_debug("Setting lapic_timer_frequency = %d\n",
lapic_timer_frequency);
set_cpu_cap(&boot_cpu_data, X86_FEATURE_TSC_RELIABLE);
return fast_calibrate;
}
static void __init tangier_arch_setup(void)
{
x86_platform.calibrate_tsc = tangier_calibrate_tsc;
}
void *get_tangier_ops(void)
{
return &tangier_ops;
}
