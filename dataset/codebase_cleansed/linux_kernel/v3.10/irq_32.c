unsigned long arch_local_irq_save(void)
{
unsigned long retval;
unsigned long tmp;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"or %0, %2, %1\n\t"
"wr %1, 0, %%psr\n\t"
"nop; nop; nop\n"
: "=&r" (retval), "=r" (tmp)
: "i" (PSR_PIL)
: "memory");
return retval;
}
void arch_local_irq_enable(void)
{
unsigned long tmp;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"andn %0, %1, %0\n\t"
"wr %0, 0, %%psr\n\t"
"nop; nop; nop\n"
: "=&r" (tmp)
: "i" (PSR_PIL)
: "memory");
}
void arch_local_irq_restore(unsigned long old_psr)
{
unsigned long tmp;
__asm__ __volatile__(
"rd %%psr, %0\n\t"
"and %2, %1, %2\n\t"
"andn %0, %1, %0\n\t"
"wr %0, %2, %%psr\n\t"
"nop; nop; nop\n"
: "=&r" (tmp)
: "i" (PSR_PIL), "r" (old_psr)
: "memory");
}
unsigned int irq_alloc(unsigned int real_irq, unsigned int pil)
{
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&irq_table_lock, flags);
for (i = 1; i < NR_IRQS; i++) {
if (irq_table[i].real_irq == real_irq && irq_table[i].pil == pil)
goto found;
}
for (i = 1; i < NR_IRQS; i++) {
if (!irq_table[i].irq)
break;
}
if (i < NR_IRQS) {
irq_table[i].real_irq = real_irq;
irq_table[i].irq = i;
irq_table[i].pil = pil;
} else {
printk(KERN_ERR "IRQ: Out of virtual IRQs.\n");
i = 0;
}
found:
spin_unlock_irqrestore(&irq_table_lock, flags);
return i;
}
void irq_link(unsigned int irq)
{
struct irq_bucket *p;
unsigned long flags;
unsigned int pil;
BUG_ON(irq >= NR_IRQS);
spin_lock_irqsave(&irq_map_lock, flags);
p = &irq_table[irq];
pil = p->pil;
BUG_ON(pil > SUN4D_MAX_IRQ);
p->next = irq_map[pil];
irq_map[pil] = p;
spin_unlock_irqrestore(&irq_map_lock, flags);
}
void irq_unlink(unsigned int irq)
{
struct irq_bucket *p, **pnext;
unsigned long flags;
BUG_ON(irq >= NR_IRQS);
spin_lock_irqsave(&irq_map_lock, flags);
p = &irq_table[irq];
BUG_ON(p->pil > SUN4D_MAX_IRQ);
pnext = &irq_map[p->pil];
while (*pnext != p)
pnext = &(*pnext)->next;
*pnext = p->next;
spin_unlock_irqrestore(&irq_map_lock, flags);
}
int arch_show_interrupts(struct seq_file *p, int prec)
{
int j;
#ifdef CONFIG_SMP
seq_printf(p, "RES: ");
for_each_online_cpu(j)
seq_printf(p, "%10u ", cpu_data(j).irq_resched_count);
seq_printf(p, " IPI rescheduling interrupts\n");
seq_printf(p, "CAL: ");
for_each_online_cpu(j)
seq_printf(p, "%10u ", cpu_data(j).irq_call_count);
seq_printf(p, " IPI function call interrupts\n");
#endif
seq_printf(p, "NMI: ");
for_each_online_cpu(j)
seq_printf(p, "%10u ", cpu_data(j).counter);
seq_printf(p, " Non-maskable interrupts\n");
return 0;
}
void handler_irq(unsigned int pil, struct pt_regs *regs)
{
struct pt_regs *old_regs;
struct irq_bucket *p;
BUG_ON(pil > 15);
old_regs = set_irq_regs(regs);
irq_enter();
p = irq_map[pil];
while (p) {
struct irq_bucket *next = p->next;
generic_handle_irq(p->irq);
p = next;
}
irq_exit();
set_irq_regs(old_regs);
}
int sparc_floppy_request_irq(unsigned int irq, irq_handler_t irq_handler)
{
unsigned int cpu_irq;
int err;
err = request_irq(irq, irq_handler, 0, "floppy", NULL);
if (err)
return -1;
floppy_irq = irq;
cpu_irq = (irq & (NR_IRQS - 1));
#define INSTANTIATE(table) \
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_one = SPARC_RD_PSR_L0; \
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_two = \
SPARC_BRANCH((unsigned long) floppy_hardint, \
(unsigned long) &table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_two);\
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_three = SPARC_RD_WIM_L3; \
table[SP_TRAP_IRQ1+(cpu_irq-1)].inst_four = SPARC_NOP;
INSTANTIATE(sparc_ttable)
#if defined CONFIG_SMP
if (sparc_cpu_model != sparc_leon) {
struct tt_entry *trap_table;
trap_table = &trapbase_cpu1;
INSTANTIATE(trap_table)
trap_table = &trapbase_cpu2;
INSTANTIATE(trap_table)
trap_table = &trapbase_cpu3;
INSTANTIATE(trap_table)
}
#endif
#undef INSTANTIATE
flush_cache_all();
return 0;
}
void sparc_floppy_irq(int irq, void *dev_id, struct pt_regs *regs)
{
struct pt_regs *old_regs;
old_regs = set_irq_regs(regs);
irq_enter();
generic_handle_irq(floppy_irq);
irq_exit();
set_irq_regs(old_regs);
}
void __init init_IRQ(void)
{
switch (sparc_cpu_model) {
case sun4m:
pcic_probe();
if (pcic_present())
sun4m_pci_init_IRQ();
else
sun4m_init_IRQ();
break;
case sun4d:
sun4d_init_IRQ();
break;
case sparc_leon:
leon_init_IRQ();
break;
default:
prom_printf("Cannot initialize IRQs on this Sun machine...");
break;
}
}
