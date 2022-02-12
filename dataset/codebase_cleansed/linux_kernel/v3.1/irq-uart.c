static void s3c_irq_demux_uart(unsigned int irq, struct irq_desc *desc)
{
struct s3c_uart_irq *uirq = desc->irq_data.handler_data;
struct irq_chip *chip = irq_get_chip(irq);
u32 pend = __raw_readl(uirq->regs + S3C64XX_UINTP);
int base = uirq->base_irq;
chained_irq_enter(chip, desc);
if (pend & (1 << 0))
generic_handle_irq(base);
if (pend & (1 << 1))
generic_handle_irq(base + 1);
if (pend & (1 << 2))
generic_handle_irq(base + 2);
if (pend & (1 << 3))
generic_handle_irq(base + 3);
chained_irq_exit(chip, desc);
}
static void __init s3c_init_uart_irq(struct s3c_uart_irq *uirq)
{
void __iomem *reg_base = uirq->regs;
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
__raw_writel(0xf, reg_base + S3C64XX_UINTM);
gc = irq_alloc_generic_chip("s3c-uart", 1, uirq->base_irq, reg_base,
handle_level_irq);
if (!gc) {
pr_err("%s: irq_alloc_generic_chip for IRQ %u failed\n",
__func__, uirq->base_irq);
return;
}
ct = gc->chip_types;
ct->chip.irq_ack = irq_gc_ack_set_bit;
ct->chip.irq_mask = irq_gc_mask_set_bit;
ct->chip.irq_unmask = irq_gc_mask_clr_bit;
ct->regs.ack = S3C64XX_UINTP;
ct->regs.mask = S3C64XX_UINTM;
irq_setup_generic_chip(gc, IRQ_MSK(4), IRQ_GC_INIT_MASK_CACHE,
IRQ_NOREQUEST | IRQ_NOPROBE, 0);
irq_set_handler_data(uirq->parent_irq, uirq);
irq_set_chained_handler(uirq->parent_irq, s3c_irq_demux_uart);
}
void __init s3c_init_uart_irqs(struct s3c_uart_irq *irq, unsigned int nr_irqs)
{
for (; nr_irqs > 0; nr_irqs--, irq++)
s3c_init_uart_irq(irq);
}
