static bool __init ms_hyperv_platform(void)
{
u32 eax;
u32 hyp_signature[3];
if (!boot_cpu_has(X86_FEATURE_HYPERVISOR))
return false;
cpuid(HYPERV_CPUID_VENDOR_AND_MAX_FUNCTIONS,
&eax, &hyp_signature[0], &hyp_signature[1], &hyp_signature[2]);
return eax >= HYPERV_CPUID_MIN &&
eax <= HYPERV_CPUID_MAX &&
!memcmp("Microsoft Hv", hyp_signature, 12);
}
static void __init ms_hyperv_init_platform(void)
{
ms_hyperv.features = cpuid_eax(HYPERV_CPUID_FEATURES);
ms_hyperv.hints = cpuid_eax(HYPERV_CPUID_ENLIGHTMENT_INFO);
printk(KERN_INFO "HyperV: features 0x%x, hints 0x%x\n",
ms_hyperv.features, ms_hyperv.hints);
}
