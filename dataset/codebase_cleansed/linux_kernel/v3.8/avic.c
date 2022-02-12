static int avic_irq_set_priority(unsigned char irq, unsigned char prio)
{
struct irq_data *d = irq_get_irq_data(irq);
unsigned int temp;
unsigned int mask = 0x0F << irq % 8 * 4;
irq = d->hwirq;
if (irq >= AVIC_NUM_IRQS)
return -EINVAL;
temp = __raw_readl(avic_base + AVIC_NIPRIORITY(irq / 8));
temp &= ~mask;
temp |= prio & mask;
__raw_writel(temp, avic_base + AVIC_NIPRIORITY(irq / 8));
return 0;
}
static int avic_set_irq_fiq(unsigned int irq, unsigned int type)
{
struct irq_data *d = irq_get_irq_data(irq);
unsigned int irqt;
irq = d->hwirq;
if (irq >= AVIC_NUM_IRQS)
return -EINVAL;
if (irq < AVIC_NUM_IRQS / 2) {
irqt = __raw_readl(avic_base + AVIC_INTTYPEL) & ~(1 << irq);
__raw_writel(irqt | (!!type << irq), avic_base + AVIC_INTTYPEL);
} else {
irq -= AVIC_NUM_IRQS / 2;
irqt = __raw_readl(avic_base + AVIC_INTTYPEH) & ~(1 << irq);
__raw_writel(irqt | (!!type << irq), avic_base + AVIC_INTTYPEH);
}
return 0;
}
static void avic_irq_suspend(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct irq_chip_type *ct = gc->chip_types;
int idx = d->hwirq >> 5;
avic_saved_mask_reg[idx] = __raw_readl(avic_base + ct->regs.mask);
__raw_writel(gc->wake_active, avic_base + ct->regs.mask);
}
static void avic_irq_resume(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct irq_chip_type *ct = gc->chip_types;
int idx = d->hwirq >> 5;
__raw_writel(avic_saved_mask_reg[idx], avic_base + ct->regs.mask);
}
static __init void avic_init_gc(int idx, unsigned int irq_start)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("mxc-avic", 1, irq_start, avic_base,
handle_level_irq);
gc->private = &avic_extra_irq;
gc->wake_enabled = IRQ_MSK(32);
ct = gc->chip_types;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->chip.irq_ack = irq_gc_mask_clr_bit;
ct->chip.irq_set_wake = irq_gc_set_wake;
ct->chip.irq_suspend = avic_irq_suspend;
ct->chip.irq_resume = avic_irq_resume;
ct->regs.mask = !idx ? AVIC_INTENABLEL : AVIC_INTENABLEH;
ct->regs.ack = ct->regs.mask;
irq_setup_generic_chip(gc, IRQ_MSK(32), 0, IRQ_NOREQUEST, 0);
}
asmlinkage void __exception_irq_entry avic_handle_irq(struct pt_regs *regs)
{
u32 nivector;
do {
nivector = __raw_readl(avic_base + AVIC_NIVECSR) >> 16;
if (nivector == 0xffff)
break;
handle_IRQ(irq_find_mapping(domain, nivector), regs);
} while (1);
}
void __init mxc_init_irq(void __iomem *irqbase)
{
struct device_node *np;
int irq_base;
int i;
avic_base = irqbase;
__raw_writel(0, avic_base + AVIC_INTCNTL);
__raw_writel(0x1f, avic_base + AVIC_NIMASK);
__raw_writel(0, avic_base + AVIC_INTENABLEH);
__raw_writel(0, avic_base + AVIC_INTENABLEL);
__raw_writel(0, avic_base + AVIC_INTTYPEH);
__raw_writel(0, avic_base + AVIC_INTTYPEL);
irq_base = irq_alloc_descs(-1, 0, AVIC_NUM_IRQS, numa_node_id());
WARN_ON(irq_base < 0);
np = of_find_compatible_node(NULL, NULL, "fsl,avic");
domain = irq_domain_add_legacy(np, AVIC_NUM_IRQS, irq_base, 0,
&irq_domain_simple_ops, NULL);
WARN_ON(!domain);
for (i = 0; i < AVIC_NUM_IRQS / 32; i++, irq_base += 32)
avic_init_gc(i, irq_base);
for (i = 0; i < 8; i++)
__raw_writel(0, avic_base + AVIC_NIPRIORITY(i));
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
printk(KERN_INFO "MXC IRQ initialized\n");
}
