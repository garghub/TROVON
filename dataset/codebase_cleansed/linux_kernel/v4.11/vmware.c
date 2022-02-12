static inline int __vmware_platform(void)
{
uint32_t eax, ebx, ecx, edx;
VMWARE_PORT(GETVERSION, eax, ebx, ecx, edx);
return eax != (uint32_t)-1 && ebx == VMWARE_HYPERVISOR_MAGIC;
}
static unsigned long vmware_get_tsc_khz(void)
{
return vmware_tsc_khz;
}
static __init int setup_vmw_sched_clock(char *s)
{
vmw_sched_clock = 0;
return 0;
}
static unsigned long long vmware_sched_clock(void)
{
unsigned long long ns;
ns = mul_u64_u32_shr(rdtsc(), vmware_cyc2ns.cyc2ns_mul,
vmware_cyc2ns.cyc2ns_shift);
ns -= vmware_cyc2ns.cyc2ns_offset;
return ns;
}
static void __init vmware_sched_clock_setup(void)
{
struct cyc2ns_data *d = &vmware_cyc2ns;
unsigned long long tsc_now = rdtsc();
clocks_calc_mult_shift(&d->cyc2ns_mul, &d->cyc2ns_shift,
vmware_tsc_khz, NSEC_PER_MSEC, 0);
d->cyc2ns_offset = mul_u64_u32_shr(tsc_now, d->cyc2ns_mul,
d->cyc2ns_shift);
pv_time_ops.sched_clock = vmware_sched_clock;
pr_info("using sched offset of %llu ns\n", d->cyc2ns_offset);
}
static void __init vmware_paravirt_ops_setup(void)
{
pv_info.name = "VMware hypervisor";
pv_cpu_ops.io_delay = paravirt_nop;
if (vmware_tsc_khz && vmw_sched_clock)
vmware_sched_clock_setup();
}
static void __init vmware_platform_setup(void)
{
uint32_t eax, ebx, ecx, edx;
uint64_t lpj, tsc_khz;
VMWARE_PORT(GETHZ, eax, ebx, ecx, edx);
if (ebx != UINT_MAX) {
lpj = tsc_khz = eax | (((uint64_t)ebx) << 32);
do_div(tsc_khz, 1000);
WARN_ON(tsc_khz >> 32);
pr_info("TSC freq read from hypervisor : %lu.%03lu MHz\n",
(unsigned long) tsc_khz / 1000,
(unsigned long) tsc_khz % 1000);
if (!preset_lpj) {
do_div(lpj, HZ);
preset_lpj = lpj;
}
vmware_tsc_khz = tsc_khz;
x86_platform.calibrate_tsc = vmware_get_tsc_khz;
x86_platform.calibrate_cpu = vmware_get_tsc_khz;
#ifdef CONFIG_X86_LOCAL_APIC
lapic_timer_frequency = ecx / HZ;
pr_info("Host bus clock speed read from hypervisor : %u Hz\n",
ecx);
#endif
} else {
pr_warn("Failed to get TSC freq from the hypervisor\n");
}
vmware_paravirt_ops_setup();
#ifdef CONFIG_X86_IO_APIC
no_timer_check = 1;
#endif
}
static uint32_t __init vmware_platform(void)
{
if (boot_cpu_has(X86_FEATURE_HYPERVISOR)) {
unsigned int eax;
unsigned int hyper_vendor_id[3];
cpuid(CPUID_VMWARE_INFO_LEAF, &eax, &hyper_vendor_id[0],
&hyper_vendor_id[1], &hyper_vendor_id[2]);
if (!memcmp(hyper_vendor_id, "VMwareVMware", 12))
return CPUID_VMWARE_INFO_LEAF;
} else if (dmi_available && dmi_name_in_serial("VMware") &&
__vmware_platform())
return 1;
return 0;
}
static void vmware_set_cpu_features(struct cpuinfo_x86 *c)
{
set_cpu_cap(c, X86_FEATURE_CONSTANT_TSC);
set_cpu_cap(c, X86_FEATURE_TSC_RELIABLE);
}
static bool __init vmware_legacy_x2apic_available(void)
{
uint32_t eax, ebx, ecx, edx;
VMWARE_PORT(GETVCPU_INFO, eax, ebx, ecx, edx);
return (eax & (1 << VMWARE_PORT_CMD_VCPU_RESERVED)) == 0 &&
(eax & (1 << VMWARE_PORT_CMD_LEGACY_X2APIC)) != 0;
}
