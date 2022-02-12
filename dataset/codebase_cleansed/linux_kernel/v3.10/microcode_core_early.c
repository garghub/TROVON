static int __cpuinit x86_vendor(void)
{
u32 eax = 0x00000000;
u32 ebx, ecx = 0, edx;
native_cpuid(&eax, &ebx, &ecx, &edx);
if (CPUID_IS(CPUID_INTEL1, CPUID_INTEL2, CPUID_INTEL3, ebx, ecx, edx))
return X86_VENDOR_INTEL;
if (CPUID_IS(CPUID_AMD1, CPUID_AMD2, CPUID_AMD3, ebx, ecx, edx))
return X86_VENDOR_AMD;
return X86_VENDOR_UNKNOWN;
}
static int __cpuinit x86_family(void)
{
u32 eax = 0x00000001;
u32 ebx, ecx = 0, edx;
int x86;
native_cpuid(&eax, &ebx, &ecx, &edx);
x86 = (eax >> 8) & 0xf;
if (x86 == 15)
x86 += (eax >> 20) & 0xff;
return x86;
}
void __init load_ucode_bsp(void)
{
int vendor, x86;
if (!have_cpuid_p())
return;
vendor = x86_vendor();
x86 = x86_family();
if (vendor == X86_VENDOR_INTEL && x86 >= 6)
load_ucode_intel_bsp();
}
void __cpuinit load_ucode_ap(void)
{
int vendor, x86;
if (!have_cpuid_p())
return;
vendor = x86_vendor();
x86 = x86_family();
if (vendor == X86_VENDOR_INTEL && x86 >= 6)
load_ucode_intel_ap();
}
