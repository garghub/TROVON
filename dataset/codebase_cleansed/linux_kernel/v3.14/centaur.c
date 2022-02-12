static void init_c3(struct cpuinfo_x86 *c)
{
u32 lo, hi;
if (cpuid_eax(0xC0000000) >= 0xC0000001) {
u32 tmp = cpuid_edx(0xC0000001);
if ((tmp & (ACE_PRESENT | ACE_ENABLED)) == ACE_PRESENT) {
rdmsr(MSR_VIA_FCR, lo, hi);
lo |= ACE_FCR;
wrmsr(MSR_VIA_FCR, lo, hi);
printk(KERN_INFO "CPU: Enabled ACE h/w crypto\n");
}
if ((tmp & (RNG_PRESENT | RNG_ENABLED)) == RNG_PRESENT) {
rdmsr(MSR_VIA_RNG, lo, hi);
lo |= RNG_ENABLE;
wrmsr(MSR_VIA_RNG, lo, hi);
printk(KERN_INFO "CPU: Enabled h/w RNG\n");
}
c->x86_capability[5] = cpuid_edx(0xC0000001);
}
#ifdef CONFIG_X86_32
if (c->x86_model >= 6 && c->x86_model <= 13) {
rdmsr(MSR_VIA_FCR, lo, hi);
lo |= (1<<1 | 1<<7);
wrmsr(MSR_VIA_FCR, lo, hi);
set_cpu_cap(c, X86_FEATURE_CX8);
}
if (c->x86_model >= 6 && c->x86_model < 9)
set_cpu_cap(c, X86_FEATURE_3DNOW);
#endif
if (c->x86 == 0x6 && c->x86_model >= 0xf) {
c->x86_cache_alignment = c->x86_clflush_size * 2;
set_cpu_cap(c, X86_FEATURE_REP_GOOD);
}
cpu_detect_cache_sizes(c);
}
static void early_init_centaur(struct cpuinfo_x86 *c)
{
switch (c->x86) {
#ifdef CONFIG_X86_32
case 5:
set_cpu_cap(c, X86_FEATURE_CENTAUR_MCR);
break;
#endif
case 6:
if (c->x86_model >= 0xf)
set_cpu_cap(c, X86_FEATURE_CONSTANT_TSC);
break;
}
#ifdef CONFIG_X86_64
set_cpu_cap(c, X86_FEATURE_SYSENTER32);
#endif
}
static void init_centaur(struct cpuinfo_x86 *c)
{
#ifdef CONFIG_X86_32
char *name;
u32 fcr_set = 0;
u32 fcr_clr = 0;
u32 lo, hi, newlo;
u32 aa, bb, cc, dd;
clear_cpu_cap(c, 0*32+31);
#endif
early_init_centaur(c);
switch (c->x86) {
#ifdef CONFIG_X86_32
case 5:
switch (c->x86_model) {
case 4:
name = "C6";
fcr_set = ECX8|DSMC|EDCTLB|EMMX|ERETSTK;
fcr_clr = DPDC;
printk(KERN_NOTICE "Disabling bugged TSC.\n");
clear_cpu_cap(c, X86_FEATURE_TSC);
break;
case 8:
switch (c->x86_mask) {
default:
name = "2";
break;
case 7 ... 9:
name = "2A";
break;
case 10 ... 15:
name = "2B";
break;
}
fcr_set = ECX8|DSMC|DTLOCK|EMMX|EBRPRED|ERETSTK|
E2MMX|EAMD3D;
fcr_clr = DPDC;
break;
case 9:
name = "3";
fcr_set = ECX8|DSMC|DTLOCK|EMMX|EBRPRED|ERETSTK|
E2MMX|EAMD3D;
fcr_clr = DPDC;
break;
default:
name = "??";
}
rdmsr(MSR_IDT_FCR1, lo, hi);
newlo = (lo|fcr_set) & (~fcr_clr);
if (newlo != lo) {
printk(KERN_INFO "Centaur FCR was 0x%X now 0x%X\n",
lo, newlo);
wrmsr(MSR_IDT_FCR1, newlo, hi);
} else {
printk(KERN_INFO "Centaur FCR is 0x%X\n", lo);
}
set_cpu_cap(c, X86_FEATURE_CENTAUR_MCR);
set_cpu_cap(c, X86_FEATURE_CX8);
if (c->x86_model >= 8)
set_cpu_cap(c, X86_FEATURE_3DNOW);
if (cpuid_eax(0x80000000) >= 0x80000005) {
cpuid(0x80000005, &aa, &bb, &cc, &dd);
c->x86_cache_size = (cc>>24)+(dd>>24);
}
sprintf(c->x86_model_id, "WinChip %s", name);
break;
#endif
case 6:
init_c3(c);
break;
}
#ifdef CONFIG_X86_64
set_cpu_cap(c, X86_FEATURE_LFENCE_RDTSC);
#endif
}
static unsigned int
centaur_size_cache(struct cpuinfo_x86 *c, unsigned int size)
{
if ((c->x86 == 6) && ((c->x86_model == 7) || (c->x86_model == 8)))
size >>= 8;
if ((c->x86 == 6) && (c->x86_model == 9) &&
(c->x86_mask == 1) && (size == 65))
size -= 1;
return size;
}
