static int x86_vendor(void)
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
static int x86_family(void)
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
static bool __init check_loader_disabled_bsp(void)
{
#ifdef CONFIG_X86_32
const char *cmdline = (const char *)__pa_nodebug(boot_command_line);
const char *opt = "dis_ucode_ldr";
const char *option = (const char *)__pa_nodebug(opt);
bool *res = (bool *)__pa_nodebug(&dis_ucode_ldr);
#else
const char *cmdline = boot_command_line;
const char *option = "dis_ucode_ldr";
bool *res = &dis_ucode_ldr;
#endif
if (cmdline_find_option_bool(cmdline, option))
*res = true;
return *res;
}
void __init load_ucode_bsp(void)
{
int vendor, x86;
if (check_loader_disabled_bsp())
return;
if (!have_cpuid_p())
return;
vendor = x86_vendor();
x86 = x86_family();
switch (vendor) {
case X86_VENDOR_INTEL:
if (x86 >= 6)
load_ucode_intel_bsp();
break;
case X86_VENDOR_AMD:
if (x86 >= 0x10)
load_ucode_amd_bsp();
break;
default:
break;
}
}
static bool check_loader_disabled_ap(void)
{
#ifdef CONFIG_X86_32
return *((bool *)__pa_nodebug(&dis_ucode_ldr));
#else
return dis_ucode_ldr;
#endif
}
void load_ucode_ap(void)
{
int vendor, x86;
if (check_loader_disabled_ap())
return;
if (!have_cpuid_p())
return;
vendor = x86_vendor();
x86 = x86_family();
switch (vendor) {
case X86_VENDOR_INTEL:
if (x86 >= 6)
load_ucode_intel_ap();
break;
case X86_VENDOR_AMD:
if (x86 >= 0x10)
load_ucode_amd_ap();
break;
default:
break;
}
}
int __init save_microcode_in_initrd(void)
{
struct cpuinfo_x86 *c = &boot_cpu_data;
switch (c->x86_vendor) {
case X86_VENDOR_INTEL:
if (c->x86 >= 6)
save_microcode_in_initrd_intel();
break;
case X86_VENDOR_AMD:
if (c->x86 >= 0x10)
save_microcode_in_initrd_amd();
break;
default:
break;
}
return 0;
}
void reload_early_microcode(void)
{
int vendor, x86;
vendor = x86_vendor();
x86 = x86_family();
switch (vendor) {
case X86_VENDOR_INTEL:
if (x86 >= 6)
reload_ucode_intel();
break;
case X86_VENDOR_AMD:
if (x86 >= 0x10)
reload_ucode_amd();
break;
default:
break;
}
}
