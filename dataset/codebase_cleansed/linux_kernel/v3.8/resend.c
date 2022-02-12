static void resend_irqs(unsigned long arg)
{
struct irq_desc *desc;
int irq;
while (!bitmap_empty(irqs_resend, nr_irqs)) {
irq = find_first_bit(irqs_resend, nr_irqs);
clear_bit(irq, irqs_resend);
desc = irq_to_desc(irq);
local_irq_disable();
desc->handle_irq(irq, desc);
local_irq_enable();
}
}
void check_irq_resend(struct irq_desc *desc, unsigned int irq)
{
if (irq_settings_is_level(desc)) {
desc->istate &= ~IRQS_PENDING;
return;
}
if (desc->istate & IRQS_REPLAY)
return;
if (desc->istate & IRQS_PENDING) {
desc->istate &= ~IRQS_PENDING;
desc->istate |= IRQS_REPLAY;
if (!desc->irq_data.chip->irq_retrigger ||
!desc->irq_data.chip->irq_retrigger(&desc->irq_data)) {
#ifdef CONFIG_HARDIRQS_SW_RESEND
if (desc->parent_irq &&
irq_settings_is_nested_thread(desc))
irq = desc->parent_irq;
set_bit(irq, irqs_resend);
tasklet_schedule(&resend_tasklet);
#endif
}
}
}
