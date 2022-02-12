static __init void sirfsoc_alloc_gc(void __iomem *base)
{
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
unsigned int set = IRQ_LEVEL;
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
int i;
irq_alloc_domain_generic_chips(sirfsoc_irqdomain, 32, 1, "irq_sirfsoc",
handle_level_irq, clr, set,
IRQ_GC_INIT_MASK_CACHE);
for (i = 0; i < SIRFSOC_NUM_BANKS; i++) {
gc = irq_get_domain_generic_chip(sirfsoc_irqdomain, i * 32);
gc->reg_base = base + i * SIRFSOC_INT_BASE_OFFSET;
ct = gc->chip_types;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->regs.mask = SIRFSOC_INT_RISC_MASK0;
}
}
static void __exception_irq_entry sirfsoc_handle_irq(struct pt_regs *regs)
{
void __iomem *base = sirfsoc_irqdomain->host_data;
u32 irqstat;
irqstat = readl_relaxed(base + SIRFSOC_INIT_IRQ_ID);
handle_domain_irq(sirfsoc_irqdomain, irqstat & 0xff, regs);
}
static int __init sirfsoc_irq_init(struct device_node *np,
struct device_node *parent)
{
void __iomem *base = of_iomap(np, 0);
if (!base)
panic("unable to map intc cpu registers\n");
sirfsoc_irqdomain = irq_domain_add_linear(np, SIRFSOC_NUM_IRQS,
&irq_generic_chip_ops, base);
sirfsoc_alloc_gc(base);
writel_relaxed(0, base + SIRFSOC_INT_RISC_LEVEL0);
writel_relaxed(0, base + SIRFSOC_INT_RISC_LEVEL1);
writel_relaxed(0, base + SIRFSOC_INT_RISC_MASK0);
writel_relaxed(0, base + SIRFSOC_INT_RISC_MASK1);
set_handle_irq(sirfsoc_handle_irq);
return 0;
}
static int sirfsoc_irq_suspend(void)
{
void __iomem *base = sirfsoc_irqdomain->host_data;
sirfsoc_irq_st.mask0 = readl_relaxed(base + SIRFSOC_INT_RISC_MASK0);
sirfsoc_irq_st.mask1 = readl_relaxed(base + SIRFSOC_INT_RISC_MASK1);
sirfsoc_irq_st.level0 = readl_relaxed(base + SIRFSOC_INT_RISC_LEVEL0);
sirfsoc_irq_st.level1 = readl_relaxed(base + SIRFSOC_INT_RISC_LEVEL1);
return 0;
}
static void sirfsoc_irq_resume(void)
{
void __iomem *base = sirfsoc_irqdomain->host_data;
writel_relaxed(sirfsoc_irq_st.mask0, base + SIRFSOC_INT_RISC_MASK0);
writel_relaxed(sirfsoc_irq_st.mask1, base + SIRFSOC_INT_RISC_MASK1);
writel_relaxed(sirfsoc_irq_st.level0, base + SIRFSOC_INT_RISC_LEVEL0);
writel_relaxed(sirfsoc_irq_st.level1, base + SIRFSOC_INT_RISC_LEVEL1);
}
static int __init sirfsoc_irq_pm_init(void)
{
if (!sirfsoc_irqdomain)
return 0;
register_syscore_ops(&sirfsoc_irq_syscore_ops);
return 0;
}
