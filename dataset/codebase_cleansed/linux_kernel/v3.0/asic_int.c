static inline int get_int(void)
{
unsigned long flags;
int irq;
raw_spin_lock_irqsave(&asic_irq_lock, flags);
irq = (asic_read(int_int_scan) >> 4) - 1;
if (irq == 0 || irq >= NR_IRQS)
irq = -1;
raw_spin_unlock_irqrestore(&asic_irq_lock, flags);
return irq;
}
static void asic_irqdispatch(void)
{
int irq;
irq = get_int();
if (irq < 0)
return;
do_IRQ(irq);
}
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
return fls(pending) - 1 + CAUSEB_IP;
}
asmlinkage void plat_irq_dispatch(void)
{
unsigned int pending = read_c0_cause() & read_c0_status() & ST0_IM;
int irq;
irq = irq_ffs(pending);
if (irq == CAUSEF_IP3)
asic_irqdispatch();
else if (irq >= 0)
do_IRQ(irq);
else
spurious_interrupt();
}
void __init arch_init_irq(void)
{
int i;
asic_irq_init();
if (cpu_has_veic || cpu_has_vint) {
int nvec = cpu_has_veic ? 64 : 8;
for (i = 0; i < nvec; i++)
set_vi_handler(i, asic_irqdispatch);
}
}
