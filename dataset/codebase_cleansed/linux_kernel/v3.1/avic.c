static int avic_irq_set_priority(unsigned char irq, unsigned char prio)
{
unsigned int temp;
unsigned int mask = 0x0F << irq % 8 * 4;
if (irq >= AVIC_NUM_IRQS)
return -EINVAL;;
temp = __raw_readl(avic_base + AVIC_NIPRIORITY(irq / 8));
temp &= ~mask;
temp |= prio & mask;
__raw_writel(temp, avic_base + AVIC_NIPRIORITY(irq / 8));
return 0;
}
static int avic_set_irq_fiq(unsigned int irq, unsigned int type)
{
unsigned int irqt;
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
static void mxc_mask_irq(struct irq_data *d)
{
__raw_writel(d->irq, avic_base + AVIC_INTDISNUM);
}
static void mxc_unmask_irq(struct irq_data *d)
{
__raw_writel(d->irq, avic_base + AVIC_INTENNUM);
}
void __init mxc_init_irq(void __iomem *irqbase)
{
int i;
avic_base = irqbase;
__raw_writel(0, avic_base + AVIC_INTCNTL);
__raw_writel(0x1f, avic_base + AVIC_NIMASK);
__raw_writel(0, avic_base + AVIC_INTENABLEH);
__raw_writel(0, avic_base + AVIC_INTENABLEL);
__raw_writel(0, avic_base + AVIC_INTTYPEH);
__raw_writel(0, avic_base + AVIC_INTTYPEL);
for (i = 0; i < AVIC_NUM_IRQS; i++) {
irq_set_chip_and_handler(i, &mxc_avic_chip.base,
handle_level_irq);
set_irq_flags(i, IRQF_VALID);
}
for (i = 0; i < 8; i++)
__raw_writel(0, avic_base + AVIC_NIPRIORITY(i));
#ifdef CONFIG_FIQ
init_FIQ();
#endif
printk(KERN_INFO "MXC IRQ initialized\n");
}
