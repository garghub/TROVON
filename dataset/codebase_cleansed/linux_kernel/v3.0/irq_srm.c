static inline void
srm_enable_irq(struct irq_data *d)
{
spin_lock(&srm_irq_lock);
cserve_ena(d->irq - 16);
spin_unlock(&srm_irq_lock);
}
static void
srm_disable_irq(struct irq_data *d)
{
spin_lock(&srm_irq_lock);
cserve_dis(d->irq - 16);
spin_unlock(&srm_irq_lock);
}
void __init
init_srm_irqs(long max, unsigned long ignore_mask)
{
long i;
if (NR_IRQS <= 16)
return;
for (i = 16; i < max; ++i) {
if (i < 64 && ((ignore_mask >> i) & 1))
continue;
irq_set_chip_and_handler(i, &srm_irq_type, handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
}
void
srm_device_interrupt(unsigned long vector)
{
int irq = (vector - 0x800) >> 4;
handle_irq(irq);
}
