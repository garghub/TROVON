static void intel_mid_power_off(void)
{
}
static void intel_mid_reboot(void)
{
intel_scu_ipc_simple_command(IPCMSG_COLD_BOOT, 0);
}
static unsigned long __init intel_mid_calibrate_tsc(void)
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
fsb = PENWELL_FSB_FREQ_83SKU;
else
fsb = PENWELL_FSB_FREQ_100SKU;
fast_calibrate = ratio * fsb;
pr_debug("read penwell tsc %lu khz\n", fast_calibrate);
lapic_timer_frequency = fsb * 1000 / HZ;
set_cpu_cap(&boot_cpu_data, X86_FEATURE_TSC_RELIABLE);
if (fast_calibrate)
return fast_calibrate;
return 0;
}
static void __init intel_mid_time_init(void)
{
sfi_table_parse(SFI_SIG_MTMR, NULL, NULL, sfi_parse_mtmr);
switch (intel_mid_timer_options) {
case INTEL_MID_TIMER_APBT_ONLY:
break;
case INTEL_MID_TIMER_LAPIC_APBT:
x86_init.timers.setup_percpu_clockev = setup_boot_APIC_clock;
x86_cpuinit.setup_percpu_clockev = setup_secondary_APIC_clock;
break;
default:
if (!boot_cpu_has(X86_FEATURE_ARAT))
break;
x86_init.timers.setup_percpu_clockev = setup_boot_APIC_clock;
x86_cpuinit.setup_percpu_clockev = setup_secondary_APIC_clock;
return;
}
pre_init_apic_IRQ0();
apbt_time_init();
}
static void intel_mid_arch_setup(void)
{
if (boot_cpu_data.x86 == 6 && boot_cpu_data.x86_model == 0x27)
__intel_mid_cpu_chip = INTEL_MID_CPU_CHIP_PENWELL;
else {
pr_err("Unknown Intel MID CPU (%d:%d), default to Penwell\n",
boot_cpu_data.x86, boot_cpu_data.x86_model);
__intel_mid_cpu_chip = INTEL_MID_CPU_CHIP_PENWELL;
}
}
static int intel_mid_i8042_detect(void)
{
return 0;
}
static unsigned char intel_mid_get_nmi_reason(void)
{
return 0;
}
void __init x86_intel_mid_early_setup(void)
{
x86_init.resources.probe_roms = x86_init_noop;
x86_init.resources.reserve_resources = x86_init_noop;
x86_init.timers.timer_init = intel_mid_time_init;
x86_init.timers.setup_percpu_clockev = x86_init_noop;
x86_init.irqs.pre_vector_init = x86_init_noop;
x86_init.oem.arch_setup = intel_mid_arch_setup;
x86_cpuinit.setup_percpu_clockev = apbt_setup_secondary_clock;
x86_platform.calibrate_tsc = intel_mid_calibrate_tsc;
x86_platform.i8042_detect = intel_mid_i8042_detect;
x86_init.timers.wallclock_init = intel_mid_rtc_init;
x86_platform.get_nmi_reason = intel_mid_get_nmi_reason;
x86_init.pci.init = intel_mid_pci_init;
x86_init.pci.fixup_irqs = x86_init_noop;
legacy_pic = &null_legacy_pic;
pm_power_off = intel_mid_power_off;
machine_ops.emergency_restart = intel_mid_reboot;
x86_init.mpparse.find_smp_config = x86_init_noop;
x86_init.mpparse.get_smp_config = x86_init_uint_noop;
set_bit(MP_BUS_ISA, mp_bus_not_pci);
}
static inline int __init setup_x86_intel_mid_timer(char *arg)
{
if (!arg)
return -EINVAL;
if (strcmp("apbt_only", arg) == 0)
intel_mid_timer_options = INTEL_MID_TIMER_APBT_ONLY;
else if (strcmp("lapic_and_apbt", arg) == 0)
intel_mid_timer_options = INTEL_MID_TIMER_LAPIC_APBT;
else {
pr_warn("X86 INTEL_MID timer option %s not recognised"
" use x86_intel_mid_timer=apbt_only or lapic_and_apbt\n",
arg);
return -EINVAL;
}
return 0;
}
