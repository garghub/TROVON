static u32 icoll_intr_bitshift(struct irq_data *d, u32 bit)
{
return bit << ((d->hwirq & 3) << 3);
}
static void __iomem *icoll_intr_reg(struct irq_data *d)
{
return icoll_priv.intr + ((d->hwirq >> 2) * 0x10);
}
static void icoll_ack_irq(struct irq_data *d)
{
__raw_writel(BV_ICOLL_LEVELACK_IRQLEVELACK__LEVEL0,
icoll_priv.levelack);
}
static void icoll_mask_irq(struct irq_data *d)
{
__raw_writel(BM_ICOLL_INTR_ENABLE,
icoll_priv.intr + CLR_REG + HW_ICOLL_INTERRUPTn(d->hwirq));
}
static void icoll_unmask_irq(struct irq_data *d)
{
__raw_writel(BM_ICOLL_INTR_ENABLE,
icoll_priv.intr + SET_REG + HW_ICOLL_INTERRUPTn(d->hwirq));
}
static void asm9260_mask_irq(struct irq_data *d)
{
__raw_writel(icoll_intr_bitshift(d, BM_ICOLL_INTR_ENABLE),
icoll_intr_reg(d) + CLR_REG);
}
static void asm9260_unmask_irq(struct irq_data *d)
{
__raw_writel(ASM9260_BM_CLEAR_BIT(d->hwirq),
icoll_priv.clear +
ASM9260_HW_ICOLL_CLEARn(d->hwirq));
__raw_writel(icoll_intr_bitshift(d, BM_ICOLL_INTR_ENABLE),
icoll_intr_reg(d) + SET_REG);
}
asmlinkage void __exception_irq_entry icoll_handle_irq(struct pt_regs *regs)
{
u32 irqnr;
irqnr = __raw_readl(icoll_priv.stat);
__raw_writel(irqnr, icoll_priv.vector);
handle_domain_irq(icoll_domain, irqnr, regs);
}
static int icoll_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
struct irq_chip *chip;
if (icoll_priv.type == ICOLL)
chip = &mxs_icoll_chip;
else
chip = &asm9260_icoll_chip;
irq_set_chip_and_handler(virq, chip, handle_level_irq);
return 0;
}
static void __init icoll_add_domain(struct device_node *np,
int num)
{
icoll_domain = irq_domain_add_linear(np, num,
&icoll_irq_domain_ops, NULL);
if (!icoll_domain)
panic("%s: unable to create irq domain", np->full_name);
}
static void __iomem * __init icoll_init_iobase(struct device_node *np)
{
void __iomem *icoll_base;
icoll_base = of_io_request_and_map(np, 0, np->name);
if (IS_ERR(icoll_base))
panic("%s: unable to map resource", np->full_name);
return icoll_base;
}
static int __init icoll_of_init(struct device_node *np,
struct device_node *interrupt_parent)
{
void __iomem *icoll_base;
icoll_priv.type = ICOLL;
icoll_base = icoll_init_iobase(np);
icoll_priv.vector = icoll_base + HW_ICOLL_VECTOR;
icoll_priv.levelack = icoll_base + HW_ICOLL_LEVELACK;
icoll_priv.ctrl = icoll_base + HW_ICOLL_CTRL;
icoll_priv.stat = icoll_base + HW_ICOLL_STAT_OFFSET;
icoll_priv.intr = icoll_base + HW_ICOLL_INTERRUPT0;
icoll_priv.clear = NULL;
stmp_reset_block(icoll_priv.ctrl);
icoll_add_domain(np, ICOLL_NUM_IRQS);
return 0;
}
static int __init asm9260_of_init(struct device_node *np,
struct device_node *interrupt_parent)
{
void __iomem *icoll_base;
int i;
icoll_priv.type = ASM9260_ICOLL;
icoll_base = icoll_init_iobase(np);
icoll_priv.vector = icoll_base + ASM9260_HW_ICOLL_VECTOR;
icoll_priv.levelack = icoll_base + ASM9260_HW_ICOLL_LEVELACK;
icoll_priv.ctrl = icoll_base + ASM9260_HW_ICOLL_CTRL;
icoll_priv.stat = icoll_base + ASM9260_HW_ICOLL_STAT_OFFSET;
icoll_priv.intr = icoll_base + ASM9260_HW_ICOLL_INTERRUPT0;
icoll_priv.clear = icoll_base + ASM9260_HW_ICOLL_CLEAR0;
writel_relaxed(ASM9260_BM_CTRL_IRQ_ENABLE,
icoll_priv.ctrl);
for (i = 0; i < 16 * 0x10; i += 0x10)
writel(0, icoll_priv.intr + i);
icoll_add_domain(np, ASM9260_NUM_IRQS);
set_handle_irq(icoll_handle_irq);
return 0;
}
