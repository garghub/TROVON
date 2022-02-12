int allocate_irqno(void)
{
int irq;
again:
irq = find_first_zero_bit(irq_map, NR_IRQS);
if (irq >= NR_IRQS)
return -ENOSPC;
if (test_and_set_bit(irq, irq_map))
goto again;
return irq;
}
void __init alloc_legacy_irqno(void)
{
int i;
for (i = 0; i <= 16; i++)
BUG_ON(test_and_set_bit(i, irq_map));
}
void free_irqno(unsigned int irq)
{
smp_mb__before_atomic();
clear_bit(irq, irq_map);
smp_mb__after_atomic();
}
