static void icoll_ack_irq(struct irq_data *d)
{
__raw_writel(BV_ICOLL_LEVELACK_IRQLEVELACK__LEVEL0,
icoll_base + HW_ICOLL_LEVELACK);
}
static void icoll_mask_irq(struct irq_data *d)
{
__raw_writel(BM_ICOLL_INTERRUPTn_ENABLE,
icoll_base + HW_ICOLL_INTERRUPTn_CLR(d->irq));
}
static void icoll_unmask_irq(struct irq_data *d)
{
__raw_writel(BM_ICOLL_INTERRUPTn_ENABLE,
icoll_base + HW_ICOLL_INTERRUPTn_SET(d->irq));
}
void __init icoll_init_irq(void)
{
int i;
mxs_reset_block(icoll_base + HW_ICOLL_CTRL);
for (i = 0; i < MXS_INTERNAL_IRQS; i++) {
irq_set_chip_and_handler(i, &mxs_icoll_chip, handle_level_irq);
set_irq_flags(i, IRQF_VALID);
}
}
