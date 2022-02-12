static inline void davinci_irq_writel(unsigned long value, int offset)
{
__raw_writel(value, davinci_intc_base + offset);
}
static __init void
davinci_alloc_gc(void __iomem *base, unsigned int irq_start, unsigned int num)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("AINTC", 1, irq_start, base, handle_edge_irq);
if (!gc) {
pr_err("%s: irq_alloc_generic_chip for IRQ %u failed\n",
__func__, irq_start);
return;
}
ct = gc->chip_types;
ct->chip.irq_ack = irq_gc_ack_set_bit;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->regs.ack = IRQ_REG0_OFFSET;
ct->regs.mask = IRQ_ENT_REG0_OFFSET;
irq_setup_generic_chip(gc, IRQ_MSK(num), IRQ_GC_INIT_MASK_CACHE,
IRQ_NOREQUEST | IRQ_NOPROBE, 0);
}
void __init davinci_irq_init(void)
{
unsigned i, j;
const u8 *davinci_def_priorities = davinci_soc_info.intc_irq_prios;
davinci_intc_type = DAVINCI_INTC_TYPE_AINTC;
davinci_intc_base = ioremap(davinci_soc_info.intc_base, SZ_4K);
if (WARN_ON(!davinci_intc_base))
return;
davinci_irq_writel(~0x0, FIQ_REG0_OFFSET);
davinci_irq_writel(~0x0, FIQ_REG1_OFFSET);
davinci_irq_writel(~0x0, IRQ_REG0_OFFSET);
davinci_irq_writel(~0x0, IRQ_REG1_OFFSET);
davinci_irq_writel(0x0, IRQ_ENT_REG0_OFFSET);
davinci_irq_writel(0x0, IRQ_ENT_REG1_OFFSET);
davinci_irq_writel(0x0, IRQ_INCTL_REG_OFFSET);
davinci_irq_writel(0, IRQ_EABASE_REG_OFFSET);
davinci_irq_writel(~0x0, FIQ_REG0_OFFSET);
davinci_irq_writel(~0x0, FIQ_REG1_OFFSET);
davinci_irq_writel(~0x0, IRQ_REG0_OFFSET);
davinci_irq_writel(~0x0, IRQ_REG1_OFFSET);
for (i = IRQ_INTPRI0_REG_OFFSET; i <= IRQ_INTPRI7_REG_OFFSET; i += 4) {
u32 pri;
for (j = 0, pri = 0; j < 32; j += 4, davinci_def_priorities++)
pri |= (*davinci_def_priorities & 0x07) << j;
davinci_irq_writel(pri, i);
}
for (i = 0, j = 0; i < davinci_soc_info.intc_irq_num; i += 32, j += 0x04)
davinci_alloc_gc(davinci_intc_base + j, i, 32);
irq_set_handler(IRQ_TINT1_TINT34, handle_level_irq);
}
