static void ack_gt641xx_irq(struct irq_data *d)
{
unsigned long flags;
u32 cause;
raw_spin_lock_irqsave(&gt641xx_irq_lock, flags);
cause = GT_READ(GT_INTRCAUSE_OFS);
cause &= ~GT641XX_IRQ_TO_BIT(d->irq);
GT_WRITE(GT_INTRCAUSE_OFS, cause);
raw_spin_unlock_irqrestore(&gt641xx_irq_lock, flags);
}
static void mask_gt641xx_irq(struct irq_data *d)
{
unsigned long flags;
u32 mask;
raw_spin_lock_irqsave(&gt641xx_irq_lock, flags);
mask = GT_READ(GT_INTRMASK_OFS);
mask &= ~GT641XX_IRQ_TO_BIT(d->irq);
GT_WRITE(GT_INTRMASK_OFS, mask);
raw_spin_unlock_irqrestore(&gt641xx_irq_lock, flags);
}
static void mask_ack_gt641xx_irq(struct irq_data *d)
{
unsigned long flags;
u32 cause, mask;
raw_spin_lock_irqsave(&gt641xx_irq_lock, flags);
mask = GT_READ(GT_INTRMASK_OFS);
mask &= ~GT641XX_IRQ_TO_BIT(d->irq);
GT_WRITE(GT_INTRMASK_OFS, mask);
cause = GT_READ(GT_INTRCAUSE_OFS);
cause &= ~GT641XX_IRQ_TO_BIT(d->irq);
GT_WRITE(GT_INTRCAUSE_OFS, cause);
raw_spin_unlock_irqrestore(&gt641xx_irq_lock, flags);
}
static void unmask_gt641xx_irq(struct irq_data *d)
{
unsigned long flags;
u32 mask;
raw_spin_lock_irqsave(&gt641xx_irq_lock, flags);
mask = GT_READ(GT_INTRMASK_OFS);
mask |= GT641XX_IRQ_TO_BIT(d->irq);
GT_WRITE(GT_INTRMASK_OFS, mask);
raw_spin_unlock_irqrestore(&gt641xx_irq_lock, flags);
}
void gt641xx_irq_dispatch(void)
{
u32 cause, mask;
int i;
cause = GT_READ(GT_INTRCAUSE_OFS);
mask = GT_READ(GT_INTRMASK_OFS);
cause &= mask;
for (i = 1; i < 30; i++) {
if (cause & (1U << i)) {
do_IRQ(GT641XX_IRQ_BASE + i);
return;
}
}
atomic_inc(&irq_err_count);
}
void __init gt641xx_irq_init(void)
{
int i;
GT_WRITE(GT_INTRMASK_OFS, 0);
GT_WRITE(GT_INTRCAUSE_OFS, 0);
for (i = 1; i < 30; i++)
irq_set_chip_and_handler(GT641XX_IRQ_BASE + i,
&gt641xx_irq_chip, handle_level_irq);
}
