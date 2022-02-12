static inline int __vmware_platform(void)
{
uint32_t eax, ebx, ecx, edx;
VMWARE_PORT(GETVERSION, eax, ebx, ecx, edx);
return eax != (uint32_t)-1 && ebx == VMWARE_HYPERVISOR_MAGIC;
}
static unsigned long vmware_get_tsc_khz(void)
{
uint64_t tsc_hz, lpj;
uint32_t eax, ebx, ecx, edx;
VMWARE_PORT(GETHZ, eax, ebx, ecx, edx);
tsc_hz = eax | (((uint64_t)ebx) << 32);
do_div(tsc_hz, 1000);
BUG_ON(tsc_hz >> 32);
printk(KERN_INFO "TSC freq read from hypervisor : %lu.%03lu MHz\n",
(unsigned long) tsc_hz / 1000,
(unsigned long) tsc_hz % 1000);
if (!preset_lpj) {
lpj = ((u64)tsc_hz * 1000);
do_div(lpj, HZ);
preset_lpj = lpj;
}
return tsc_hz;
}
static void __init vmware_platform_setup(void)
{
uint32_t eax, ebx, ecx, edx;
VMWARE_PORT(GETHZ, eax, ebx, ecx, edx);
if (ebx != UINT_MAX)
x86_platform.calibrate_tsc = vmware_get_tsc_khz;
else
printk(KERN_WARNING
"Failed to get TSC freq from the hypervisor\n");
}
static bool __init vmware_platform(void)
{
if (cpu_has_hypervisor) {
unsigned int eax;
unsigned int hyper_vendor_id[3];
cpuid(CPUID_VMWARE_INFO_LEAF, &eax, &hyper_vendor_id[0],
&hyper_vendor_id[1], &hyper_vendor_id[2]);
if (!memcmp(hyper_vendor_id, "VMwareVMware", 12))
return true;
} else if (dmi_available && dmi_name_in_serial("VMware") &&
__vmware_platform())
return true;
return false;
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
