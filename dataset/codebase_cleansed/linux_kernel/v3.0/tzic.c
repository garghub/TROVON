static int tzic_set_irq_fiq(unsigned int irq, unsigned int type)
{
unsigned int index, mask, value;
index = irq >> 5;
if (unlikely(index >= 4))
return -EINVAL;
mask = 1U << (irq & 0x1F);
value = __raw_readl(tzic_base + TZIC_INTSEC0(index)) | mask;
if (type)
value &= ~mask;
__raw_writel(value, tzic_base + TZIC_INTSEC0(index));
return 0;
}
static void tzic_mask_irq(struct irq_data *d)
{
int index, off;
index = d->irq >> 5;
off = d->irq & 0x1F;
__raw_writel(1 << off, tzic_base + TZIC_ENCLEAR0(index));
}
static void tzic_unmask_irq(struct irq_data *d)
{
int index, off;
index = d->irq >> 5;
off = d->irq & 0x1F;
__raw_writel(1 << off, tzic_base + TZIC_ENSET0(index));
}
static int tzic_set_wake_irq(struct irq_data *d, unsigned int enable)
{
unsigned int index, off;
index = d->irq >> 5;
off = d->irq & 0x1F;
if (index > 3)
return -EINVAL;
if (enable)
wakeup_intr[index] |= (1 << off);
else
wakeup_intr[index] &= ~(1 << off);
return 0;
}
void __init tzic_init_irq(void __iomem *irqbase)
{
int i;
tzic_base = irqbase;
i = __raw_readl(tzic_base + TZIC_INTCNTL);
__raw_writel(0x80010001, tzic_base + TZIC_INTCNTL);
__raw_writel(0x1f, tzic_base + TZIC_PRIOMASK);
__raw_writel(0x02, tzic_base + TZIC_SYNCCTRL);
for (i = 0; i < 4; i++)
__raw_writel(0xFFFFFFFF, tzic_base + TZIC_INTSEC0(i));
for (i = 0; i < 4; i++)
__raw_writel(0xFFFFFFFF, tzic_base + TZIC_ENCLEAR0(i));
for (i = 0; i < MXC_INTERNAL_IRQS; i++) {
irq_set_chip_and_handler(i, &mxc_tzic_chip.base,
handle_level_irq);
set_irq_flags(i, IRQF_VALID);
}
#ifdef CONFIG_FIQ
init_FIQ();
#endif
pr_info("TrustZone Interrupt Controller (TZIC) initialized\n");
}
int tzic_enable_wake(int is_idle)
{
unsigned int i, v;
__raw_writel(1, tzic_base + TZIC_DSMINT);
if (unlikely(__raw_readl(tzic_base + TZIC_DSMINT) == 0))
return -EAGAIN;
for (i = 0; i < 4; i++) {
v = is_idle ? __raw_readl(tzic_base + TZIC_ENSET0(i)) :
wakeup_intr[i];
__raw_writel(v, tzic_base + TZIC_WAKEUP0(i));
}
return 0;
}
