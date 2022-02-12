static void intel_mid_power_off(void)
{
intel_mid_pwr_power_off();
intel_scu_ipc_simple_command(IPCMSG_COLD_OFF, 1);
}
static void intel_mid_reboot(void)
{
intel_scu_ipc_simple_command(IPCMSG_COLD_BOOT, 0);
}
static unsigned long __init intel_mid_calibrate_tsc(void)
{
return 0;
}
static void __init intel_mid_setup_bp_timer(void)
{
apbt_time_init();
setup_boot_APIC_clock();
}
static void __init intel_mid_time_init(void)
{
sfi_table_parse(SFI_SIG_MTMR, NULL, NULL, sfi_parse_mtmr);
switch (intel_mid_timer_options) {
case INTEL_MID_TIMER_APBT_ONLY:
break;
case INTEL_MID_TIMER_LAPIC_APBT:
x86_init.timers.setup_percpu_clockev = intel_mid_setup_bp_timer;
x86_cpuinit.setup_percpu_clockev = setup_secondary_APIC_clock;
return;
default:
if (!boot_cpu_has(X86_FEATURE_ARAT))
break;
x86_init.timers.setup_percpu_clockev = setup_boot_APIC_clock;
x86_cpuinit.setup_percpu_clockev = setup_secondary_APIC_clock;
return;
}
x86_init.timers.setup_percpu_clockev = apbt_time_init;
}
static void intel_mid_arch_setup(void)
{
if (boot_cpu_data.x86 != 6) {
pr_err("Unknown Intel MID CPU (%d:%d), default to Penwell\n",
boot_cpu_data.x86, boot_cpu_data.x86_model);
__intel_mid_cpu_chip = INTEL_MID_CPU_CHIP_PENWELL;
goto out;
}
switch (boot_cpu_data.x86_model) {
case 0x35:
__intel_mid_cpu_chip = INTEL_MID_CPU_CHIP_CLOVERVIEW;
break;
case 0x3C:
case 0x4A:
__intel_mid_cpu_chip = INTEL_MID_CPU_CHIP_TANGIER;
break;
case 0x27:
default:
__intel_mid_cpu_chip = INTEL_MID_CPU_CHIP_PENWELL;
break;
}
if (__intel_mid_cpu_chip < MAX_CPU_OPS(get_intel_mid_ops))
intel_mid_ops = get_intel_mid_ops[__intel_mid_cpu_chip]();
else {
intel_mid_ops = get_intel_mid_ops[INTEL_MID_CPU_CHIP_PENWELL]();
pr_info("ARCH: Unknown SoC, assuming Penwell!\n");
}
out:
if (intel_mid_ops->arch_setup)
intel_mid_ops->arch_setup();
regulator_has_full_constraints();
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
pr_warn("X86 INTEL_MID timer option %s not recognised use x86_intel_mid_timer=apbt_only or lapic_and_apbt\n",
arg);
return -EINVAL;
}
return 0;
}
