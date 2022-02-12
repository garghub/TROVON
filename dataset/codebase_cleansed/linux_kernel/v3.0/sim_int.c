static inline int clz(unsigned long x)
{
__asm__(
" .set push \n"
" .set mips32 \n"
" clz %0, %1 \n"
" .set pop \n"
: "=r" (x)
: "r" (x));
return x;
}
static inline unsigned int irq_ffs(unsigned int pending)
{
#if defined(CONFIG_CPU_MIPS32) || defined(CONFIG_CPU_MIPS64)
return -clz(pending) + 31 - CAUSEB_IP;
#else
unsigned int a0 = 7;
unsigned int t0;
t0 = s0 & 0xf000;
t0 = t0 < 1;
t0 = t0 << 2;
a0 = a0 - t0;
s0 = s0 << t0;
t0 = s0 & 0xc000;
t0 = t0 < 1;
t0 = t0 << 1;
a0 = a0 - t0;
s0 = s0 << t0;
t0 = s0 & 0x8000;
t0 = t0 < 1;
a0 = a0 - t0;
return a0;
#endif
}
asmlinkage void plat_irq_dispatch(void)
{
unsigned int pending = read_c0_cause() & read_c0_status() & ST0_IM;
int irq;
irq = irq_ffs(pending);
if (irq > 0)
do_IRQ(MIPS_CPU_IRQ_BASE + irq);
else
spurious_interrupt();
}
void __init arch_init_irq(void)
{
mips_cpu_irq_init();
}
