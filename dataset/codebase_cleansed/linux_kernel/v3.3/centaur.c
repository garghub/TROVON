static u32 __cpuinit power2(u32 x)
{
u32 s = 1;
while (s <= x)
s <<= 1;
return s >>= 1;
}
static void __cpuinit centaur_mcr_insert(int reg, u32 base, u32 size, int key)
{
u32 lo, hi;
hi = base & ~0xFFF;
lo = ~(size-1);
lo &= ~0xFFF;
lo |= key;
wrmsr(reg+MSR_IDT_MCR0, lo, hi);
mtrr_centaur_report_mcr(reg, lo, hi);
}
static u32 __cpuinit ramtop(void)
{
u32 clip = 0xFFFFFFFFUL;
u32 top = 0;
int i;
for (i = 0; i < e820.nr_map; i++) {
unsigned long start, end;
if (e820.map[i].addr > 0xFFFFFFFFUL)
continue;
if (e820.map[i].type == E820_RESERVED) {
if (e820.map[i].addr >= 0x100000UL &&
e820.map[i].addr < clip)
clip = e820.map[i].addr;
continue;
}
start = e820.map[i].addr;
end = e820.map[i].addr + e820.map[i].size;
if (start >= end)
continue;
if (end > top)
top = end;
}
if (top > clip)
top = clip;
return top;
}
static int __cpuinit centaur_mcr_compute(int nr, int key)
{
u32 mem = ramtop();
u32 root = power2(mem);
u32 base = root;
u32 top = root;
u32 floor = 0;
int ct = 0;
while (ct < nr) {
u32 fspace = 0;
u32 high;
u32 low;
high = power2(mem-top);
low = base/2;
if (base <= 1024*1024)
low = 0;
if (floor == 0)
fspace = 512*1024;
else if (floor == 512*1024)
fspace = 128*1024;
if (fspace > high && fspace > low) {
centaur_mcr_insert(ct, floor, fspace, key);
floor += fspace;
} else if (high > low) {
centaur_mcr_insert(ct, top, high, key);
top += high;
} else if (low > 0) {
base -= low;
centaur_mcr_insert(ct, base, low, key);
} else
break;
ct++;
}
return ct;
}
static void __cpuinit centaur_create_optimal_mcr(void)
{
int used;
int i;
used = centaur_mcr_compute(6, 31);
for (i = used; i < 8; i++)
wrmsr(MSR_IDT_MCR0+i, 0, 0);
}
static void __cpuinit winchip2_create_optimal_mcr(void)
{
u32 lo, hi;
int used;
int i;
used = centaur_mcr_compute(6, 25);
rdmsr(MSR_IDT_MCR_CTRL, lo, hi);
for (i = 0; i < used; i++)
lo |= 1<<(9+i);
wrmsr(MSR_IDT_MCR_CTRL, lo, hi);
for (i = used; i < 8; i++)
wrmsr(MSR_IDT_MCR0+i, 0, 0);
}
static void __cpuinit winchip2_unprotect_mcr(void)
{
u32 lo, hi;
u32 key;
rdmsr(MSR_IDT_MCR_CTRL, lo, hi);
lo &= ~0x1C0;
key = (lo>>17) & 7;
lo |= key<<6;
wrmsr(MSR_IDT_MCR_CTRL, lo, hi);
}
static void __cpuinit winchip2_protect_mcr(void)
{
u32 lo, hi;
rdmsr(MSR_IDT_MCR_CTRL, lo, hi);
lo &= ~0x1C0;
wrmsr(MSR_IDT_MCR_CTRL, lo, hi);
}
static void __cpuinit init_c3(struct cpuinfo_x86 *c)
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
static void __cpuinit early_init_centaur(struct cpuinfo_x86 *c)
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
static void __cpuinit init_centaur(struct cpuinfo_x86 *c)
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
#ifdef CONFIG_X86_OOSTORE
centaur_create_optimal_mcr();
wrmsr(MSR_IDT_MCR_CTRL, 0x01F0001F, 0);
#endif
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
#ifdef CONFIG_X86_OOSTORE
winchip2_unprotect_mcr();
winchip2_create_optimal_mcr();
rdmsr(MSR_IDT_MCR_CTRL, lo, hi);
lo |= 31;
wrmsr(MSR_IDT_MCR_CTRL, lo, hi);
winchip2_protect_mcr();
#endif
break;
case 9:
name = "3";
fcr_set = ECX8|DSMC|DTLOCK|EMMX|EBRPRED|ERETSTK|
E2MMX|EAMD3D;
fcr_clr = DPDC;
#ifdef CONFIG_X86_OOSTORE
winchip2_unprotect_mcr();
winchip2_create_optimal_mcr();
rdmsr(MSR_IDT_MCR_CTRL, lo, hi);
lo |= 31;
wrmsr(MSR_IDT_MCR_CTRL, lo, hi);
winchip2_protect_mcr();
#endif
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
static unsigned int __cpuinit
centaur_size_cache(struct cpuinfo_x86 *c, unsigned int size)
{
#ifdef CONFIG_X86_32
if ((c->x86 == 6) && ((c->x86_model == 7) || (c->x86_model == 8)))
size >>= 8;
if ((c->x86 == 6) && (c->x86_model == 9) &&
(c->x86_mask == 1) && (size == 65))
size -= 1;
#endif
return size;
}
