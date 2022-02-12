static inline void per_wmb(void)
{
const volatile void __iomem *per_mem = PER_INT_MSK_REG;
volatile u32 dummy_read;
wmb();
dummy_read = __raw_readl(per_mem);
dummy_read++;
}
static inline void unmask_per_irq(struct irq_data *d)
{
#ifdef CONFIG_SMP
unsigned long flags;
spin_lock_irqsave(&per_lock, flags);
*PER_INT_MSK_REG |= (1 << (d->irq - MSP_PER_INTBASE));
spin_unlock_irqrestore(&per_lock, flags);
#else
*PER_INT_MSK_REG |= (1 << (d->irq - MSP_PER_INTBASE));
#endif
per_wmb();
}
static inline void mask_per_irq(struct irq_data *d)
{
#ifdef CONFIG_SMP
unsigned long flags;
spin_lock_irqsave(&per_lock, flags);
*PER_INT_MSK_REG &= ~(1 << (d->irq - MSP_PER_INTBASE));
spin_unlock_irqrestore(&per_lock, flags);
#else
*PER_INT_MSK_REG &= ~(1 << (d->irq - MSP_PER_INTBASE));
#endif
per_wmb();
}
static inline void msp_per_irq_ack(struct irq_data *d)
{
mask_per_irq(d);
*PER_INT_STS_REG = (1 << (d->irq - MSP_PER_INTBASE));
}
static int msp_per_irq_set_affinity(struct irq_data *d,
const struct cpumask *affinity, bool force)
{
unmask_per_irq(d);
return 0;
}
void __init msp_per_irq_init(void)
{
int i;
*PER_INT_MSK_REG = 0x00000000;
*PER_INT_STS_REG = 0xFFFFFFFF;
for (i = MSP_PER_INTBASE; i < MSP_PER_INTBASE + 32; i++) {
irq_set_chip(i, &msp_per_irq_controller);
#ifdef CONFIG_MIPS_MT_SMTC
irq_hwmask[i] = C_IRQ4;
#endif
}
}
void msp_per_irq_dispatch(void)
{
u32 per_mask = *PER_INT_MSK_REG;
u32 per_status = *PER_INT_STS_REG;
u32 pending;
pending = per_status & per_mask;
if (pending) {
do_IRQ(ffs(pending) + MSP_PER_INTBASE - 1);
} else {
spurious_interrupt();
}
}
