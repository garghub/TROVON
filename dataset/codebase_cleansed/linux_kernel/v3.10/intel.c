static void __cpuinit early_init_intel(struct cpuinfo_x86 *c)
{
u64 misc_enable;
if (c->x86 > 6 || (c->x86 == 6 && c->x86_model >= 0xd)) {
rdmsrl(MSR_IA32_MISC_ENABLE, misc_enable);
if (misc_enable & MSR_IA32_MISC_ENABLE_LIMIT_CPUID) {
misc_enable &= ~MSR_IA32_MISC_ENABLE_LIMIT_CPUID;
wrmsrl(MSR_IA32_MISC_ENABLE, misc_enable);
c->cpuid_level = cpuid_eax(0);
get_cpu_cap(c);
}
}
if ((c->x86 == 0xf && c->x86_model >= 0x03) ||
(c->x86 == 0x6 && c->x86_model >= 0x0e))
set_cpu_cap(c, X86_FEATURE_CONSTANT_TSC);
if (c->x86 >= 6 && !cpu_has(c, X86_FEATURE_IA64)) {
unsigned lower_word;
wrmsr(MSR_IA32_UCODE_REV, 0, 0);
sync_core();
rdmsr(MSR_IA32_UCODE_REV, lower_word, c->microcode);
}
if (c->x86 == 6 && c->x86_model == 0x1c && c->x86_mask <= 2 &&
c->microcode < 0x20e) {
printk(KERN_WARNING "Atom PSE erratum detected, BIOS microcode update recommended\n");
clear_cpu_cap(c, X86_FEATURE_PSE);
}
#ifdef CONFIG_X86_64
set_cpu_cap(c, X86_FEATURE_SYSENTER32);
#else
if (c->x86 == 15 && c->x86_cache_alignment == 64)
c->x86_cache_alignment = 128;
#endif
if (c->x86 == 0xF && c->x86_model == 0x3
&& (c->x86_mask == 0x3 || c->x86_mask == 0x4))
c->x86_phys_bits = 36;
if (c->x86_power & (1 << 8)) {
set_cpu_cap(c, X86_FEATURE_CONSTANT_TSC);
set_cpu_cap(c, X86_FEATURE_NONSTOP_TSC);
if (!check_tsc_unstable())
sched_clock_stable = 1;
}
if (c->x86 == 6) {
switch (c->x86_model) {
case 0x27:
case 0x35:
set_cpu_cap(c, X86_FEATURE_NONSTOP_TSC_S3);
break;
default:
break;
}
}
if (c->x86 == 6 && c->x86_model < 15)
clear_cpu_cap(c, X86_FEATURE_PAT);
#ifdef CONFIG_KMEMCHECK
if (c->x86 == 15) {
rdmsrl(MSR_IA32_MISC_ENABLE, misc_enable);
if (misc_enable & MSR_IA32_MISC_ENABLE_FAST_STRING) {
printk(KERN_INFO "kmemcheck: Disabling fast string operations\n");
misc_enable &= ~MSR_IA32_MISC_ENABLE_FAST_STRING;
wrmsrl(MSR_IA32_MISC_ENABLE, misc_enable);
}
}
#endif
if (c->x86 > 6 || (c->x86 == 6 && c->x86_model >= 0xd)) {
rdmsrl(MSR_IA32_MISC_ENABLE, misc_enable);
if (!(misc_enable & MSR_IA32_MISC_ENABLE_FAST_STRING)) {
printk(KERN_INFO "Disabled fast string operations\n");
setup_clear_cpu_cap(X86_FEATURE_REP_GOOD);
setup_clear_cpu_cap(X86_FEATURE_ERMS);
}
}
}
int __cpuinit ppro_with_ram_bug(void)
{
if (boot_cpu_data.x86_vendor == X86_VENDOR_INTEL &&
boot_cpu_data.x86 == 6 &&
boot_cpu_data.x86_model == 1 &&
boot_cpu_data.x86_mask < 8) {
printk(KERN_INFO "Pentium Pro with Errata#50 detected. Taking evasive action.\n");
return 1;
}
return 0;
}
static void __cpuinit intel_smp_check(struct cpuinfo_x86 *c)
{
if (!c->cpu_index)
return;
if (c->x86 == 5 &&
c->x86_mask >= 1 && c->x86_mask <= 4 &&
c->x86_model <= 3) {
WARN_ONCE(1, "WARNING: SMP operation may be unreliable"
"with B stepping processors.\n");
}
}
static void __cpuinit intel_workarounds(struct cpuinfo_x86 *c)
{
unsigned long lo, hi;
#ifdef CONFIG_X86_F00F_BUG
clear_cpu_bug(c, X86_BUG_F00F);
if (!paravirt_enabled() && c->x86 == 5) {
static int f00f_workaround_enabled;
set_cpu_bug(c, X86_BUG_F00F);
if (!f00f_workaround_enabled) {
printk(KERN_NOTICE "Intel Pentium with F0 0F bug - workaround enabled.\n");
f00f_workaround_enabled = 1;
}
}
#endif
if ((c->x86<<8 | c->x86_model<<4 | c->x86_mask) < 0x633)
clear_cpu_cap(c, X86_FEATURE_SEP);
if ((c->x86 == 15) && (c->x86_model == 1) && (c->x86_mask == 1)) {
rdmsr(MSR_IA32_MISC_ENABLE, lo, hi);
if ((lo & MSR_IA32_MISC_ENABLE_PREFETCH_DISABLE) == 0) {
printk (KERN_INFO "CPU: C0 stepping P4 Xeon detected.\n");
printk (KERN_INFO "CPU: Disabling hardware prefetching (Errata 037)\n");
lo |= MSR_IA32_MISC_ENABLE_PREFETCH_DISABLE;
wrmsr(MSR_IA32_MISC_ENABLE, lo, hi);
}
}
if (cpu_has_apic && (c->x86<<8 | c->x86_model<<4) == 0x520 &&
(c->x86_mask < 0x6 || c->x86_mask == 0xb))
set_cpu_cap(c, X86_FEATURE_11AP);
#ifdef CONFIG_X86_INTEL_USERCOPY
switch (c->x86) {
case 4:
break;
case 5:
break;
case 6:
movsl_mask.mask = 7;
break;
case 15:
movsl_mask.mask = 7;
break;
}
#endif
#ifdef CONFIG_X86_NUMAQ
numaq_tsc_disable();
#endif
intel_smp_check(c);
}
static void __cpuinit intel_workarounds(struct cpuinfo_x86 *c)
{
}
static void __cpuinit srat_detect_node(struct cpuinfo_x86 *c)
{
#ifdef CONFIG_NUMA
unsigned node;
int cpu = smp_processor_id();
node = numa_cpu_node(cpu);
if (node == NUMA_NO_NODE || !node_online(node)) {
node = cpu_to_node(cpu);
}
numa_set_node(cpu, node);
#endif
}
static int __cpuinit intel_num_cpu_cores(struct cpuinfo_x86 *c)
{
unsigned int eax, ebx, ecx, edx;
if (c->cpuid_level < 4)
return 1;
cpuid_count(4, 0, &eax, &ebx, &ecx, &edx);
if (eax & 0x1f)
return (eax >> 26) + 1;
else
return 1;
}
static void __cpuinit detect_vmx_virtcap(struct cpuinfo_x86 *c)
{
#define X86_VMX_FEATURE_PROC_CTLS_TPR_SHADOW 0x00200000
#define X86_VMX_FEATURE_PROC_CTLS_VNMI 0x00400000
#define X86_VMX_FEATURE_PROC_CTLS_2ND_CTLS 0x80000000
#define X86_VMX_FEATURE_PROC_CTLS2_VIRT_APIC 0x00000001
#define X86_VMX_FEATURE_PROC_CTLS2_EPT 0x00000002
#define X86_VMX_FEATURE_PROC_CTLS2_VPID 0x00000020
u32 vmx_msr_low, vmx_msr_high, msr_ctl, msr_ctl2;
clear_cpu_cap(c, X86_FEATURE_TPR_SHADOW);
clear_cpu_cap(c, X86_FEATURE_VNMI);
clear_cpu_cap(c, X86_FEATURE_FLEXPRIORITY);
clear_cpu_cap(c, X86_FEATURE_EPT);
clear_cpu_cap(c, X86_FEATURE_VPID);
rdmsr(MSR_IA32_VMX_PROCBASED_CTLS, vmx_msr_low, vmx_msr_high);
msr_ctl = vmx_msr_high | vmx_msr_low;
if (msr_ctl & X86_VMX_FEATURE_PROC_CTLS_TPR_SHADOW)
set_cpu_cap(c, X86_FEATURE_TPR_SHADOW);
if (msr_ctl & X86_VMX_FEATURE_PROC_CTLS_VNMI)
set_cpu_cap(c, X86_FEATURE_VNMI);
if (msr_ctl & X86_VMX_FEATURE_PROC_CTLS_2ND_CTLS) {
rdmsr(MSR_IA32_VMX_PROCBASED_CTLS2,
vmx_msr_low, vmx_msr_high);
msr_ctl2 = vmx_msr_high | vmx_msr_low;
if ((msr_ctl2 & X86_VMX_FEATURE_PROC_CTLS2_VIRT_APIC) &&
(msr_ctl & X86_VMX_FEATURE_PROC_CTLS_TPR_SHADOW))
set_cpu_cap(c, X86_FEATURE_FLEXPRIORITY);
if (msr_ctl2 & X86_VMX_FEATURE_PROC_CTLS2_EPT)
set_cpu_cap(c, X86_FEATURE_EPT);
if (msr_ctl2 & X86_VMX_FEATURE_PROC_CTLS2_VPID)
set_cpu_cap(c, X86_FEATURE_VPID);
}
}
static void __cpuinit init_intel(struct cpuinfo_x86 *c)
{
unsigned int l2 = 0;
early_init_intel(c);
intel_workarounds(c);
detect_extended_topology(c);
l2 = init_intel_cacheinfo(c);
if (c->cpuid_level > 9) {
unsigned eax = cpuid_eax(10);
if ((eax & 0xff) && (((eax>>8) & 0xff) > 1))
set_cpu_cap(c, X86_FEATURE_ARCH_PERFMON);
}
if (cpu_has_xmm2)
set_cpu_cap(c, X86_FEATURE_LFENCE_RDTSC);
if (cpu_has_ds) {
unsigned int l1;
rdmsr(MSR_IA32_MISC_ENABLE, l1, l2);
if (!(l1 & (1<<11)))
set_cpu_cap(c, X86_FEATURE_BTS);
if (!(l1 & (1<<12)))
set_cpu_cap(c, X86_FEATURE_PEBS);
}
if (c->x86 == 6 && c->x86_model == 29 && cpu_has_clflush)
set_cpu_cap(c, X86_FEATURE_CLFLUSH_MONITOR);
#ifdef CONFIG_X86_64
if (c->x86 == 15)
c->x86_cache_alignment = c->x86_clflush_size * 2;
if (c->x86 == 6)
set_cpu_cap(c, X86_FEATURE_REP_GOOD);
#else
if (c->x86 == 6) {
char *p = NULL;
switch (c->x86_model) {
case 5:
if (l2 == 0)
p = "Celeron (Covington)";
else if (l2 == 256)
p = "Mobile Pentium II (Dixon)";
break;
case 6:
if (l2 == 128)
p = "Celeron (Mendocino)";
else if (c->x86_mask == 0 || c->x86_mask == 5)
p = "Celeron-A";
break;
case 8:
if (l2 == 128)
p = "Celeron (Coppermine)";
break;
}
if (p)
strcpy(c->x86_model_id, p);
}
if (c->x86 == 15)
set_cpu_cap(c, X86_FEATURE_P4);
if (c->x86 == 6)
set_cpu_cap(c, X86_FEATURE_P3);
#endif
if (!cpu_has(c, X86_FEATURE_XTOPOLOGY)) {
c->x86_max_cores = intel_num_cpu_cores(c);
#ifdef CONFIG_X86_32
detect_ht(c);
#endif
}
srat_detect_node(c);
if (cpu_has(c, X86_FEATURE_VMX))
detect_vmx_virtcap(c);
if (cpu_has(c, X86_FEATURE_EPB)) {
u64 epb;
rdmsrl(MSR_IA32_ENERGY_PERF_BIAS, epb);
if ((epb & 0xF) == ENERGY_PERF_BIAS_PERFORMANCE) {
printk_once(KERN_WARNING "ENERGY_PERF_BIAS:"
" Set to 'normal', was 'performance'\n"
"ENERGY_PERF_BIAS: View and update with"
" x86_energy_perf_policy(8)\n");
epb = (epb & ~0xF) | ENERGY_PERF_BIAS_NORMAL;
wrmsrl(MSR_IA32_ENERGY_PERF_BIAS, epb);
}
}
}
static unsigned int __cpuinit intel_size_cache(struct cpuinfo_x86 *c, unsigned int size)
{
if ((c->x86 == 6) && (c->x86_model == 11) && (size == 0))
size = 256;
return size;
}
static void __cpuinit intel_tlb_lookup(const unsigned char desc)
{
unsigned char k;
if (desc == 0)
return;
for (k = 0; intel_tlb_table[k].descriptor != desc && \
intel_tlb_table[k].descriptor != 0; k++)
;
if (intel_tlb_table[k].tlb_type == 0)
return;
switch (intel_tlb_table[k].tlb_type) {
case STLB_4K:
if (tlb_lli_4k[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_4k[ENTRIES] = intel_tlb_table[k].entries;
if (tlb_lld_4k[ENTRIES] < intel_tlb_table[k].entries)
tlb_lld_4k[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_INST_ALL:
if (tlb_lli_4k[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_4k[ENTRIES] = intel_tlb_table[k].entries;
if (tlb_lli_2m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_2m[ENTRIES] = intel_tlb_table[k].entries;
if (tlb_lli_4m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_4m[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_INST_4K:
if (tlb_lli_4k[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_4k[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_INST_4M:
if (tlb_lli_4m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_4m[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_INST_2M_4M:
if (tlb_lli_2m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_2m[ENTRIES] = intel_tlb_table[k].entries;
if (tlb_lli_4m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lli_4m[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_DATA_4K:
case TLB_DATA0_4K:
if (tlb_lld_4k[ENTRIES] < intel_tlb_table[k].entries)
tlb_lld_4k[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_DATA_4M:
case TLB_DATA0_4M:
if (tlb_lld_4m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lld_4m[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_DATA_2M_4M:
case TLB_DATA0_2M_4M:
if (tlb_lld_2m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lld_2m[ENTRIES] = intel_tlb_table[k].entries;
if (tlb_lld_4m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lld_4m[ENTRIES] = intel_tlb_table[k].entries;
break;
case TLB_DATA_4K_4M:
if (tlb_lld_4k[ENTRIES] < intel_tlb_table[k].entries)
tlb_lld_4k[ENTRIES] = intel_tlb_table[k].entries;
if (tlb_lld_4m[ENTRIES] < intel_tlb_table[k].entries)
tlb_lld_4m[ENTRIES] = intel_tlb_table[k].entries;
break;
}
}
static void __cpuinit intel_tlb_flushall_shift_set(struct cpuinfo_x86 *c)
{
switch ((c->x86 << 8) + c->x86_model) {
case 0x60f:
case 0x616:
case 0x617:
case 0x61d:
tlb_flushall_shift = -1;
break;
case 0x61a:
case 0x61e:
case 0x625:
case 0x62c:
case 0x62e:
case 0x62f:
tlb_flushall_shift = 6;
break;
case 0x62a:
case 0x62d:
tlb_flushall_shift = 5;
break;
case 0x63a:
tlb_flushall_shift = 1;
break;
default:
tlb_flushall_shift = 6;
}
}
static void __cpuinit intel_detect_tlb(struct cpuinfo_x86 *c)
{
int i, j, n;
unsigned int regs[4];
unsigned char *desc = (unsigned char *)regs;
if (c->cpuid_level < 2)
return;
n = cpuid_eax(2) & 0xFF;
for (i = 0 ; i < n ; i++) {
cpuid(2, &regs[0], &regs[1], &regs[2], &regs[3]);
for (j = 0 ; j < 3 ; j++)
if (regs[j] & (1 << 31))
regs[j] = 0;
for (j = 1 ; j < 16 ; j++)
intel_tlb_lookup(desc[j]);
}
intel_tlb_flushall_shift_set(c);
}
