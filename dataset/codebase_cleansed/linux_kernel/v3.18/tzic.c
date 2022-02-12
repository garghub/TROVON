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
static void tzic_irq_suspend(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
int idx = d->hwirq >> 5;
__raw_writel(gc->wake_active, tzic_base + TZIC_WAKEUP0(idx));
}
static void tzic_irq_resume(struct irq_data *d)
{
int idx = d->hwirq >> 5;
__raw_writel(__raw_readl(tzic_base + TZIC_ENSET0(idx)),
tzic_base + TZIC_WAKEUP0(idx));
}
static __init void tzic_init_gc(int idx, unsigned int irq_start)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("tzic", 1, irq_start, tzic_base,
handle_level_irq);
gc->private = &tzic_extra_irq;
gc->wake_enabled = IRQ_MSK(32);
ct = gc->chip_types;
ct->chip.irq_mask = irq_gc_mask_disable_reg;
ct->chip.irq_unmask = irq_gc_unmask_enable_reg;
ct->chip.irq_set_wake = irq_gc_set_wake;
ct->chip.irq_suspend = tzic_irq_suspend;
ct->chip.irq_resume = tzic_irq_resume;
ct->regs.disable = TZIC_ENCLEAR0(idx);
ct->regs.enable = TZIC_ENSET0(idx);
irq_setup_generic_chip(gc, IRQ_MSK(32), 0, IRQ_NOREQUEST, 0);
}
static void __exception_irq_entry tzic_handle_irq(struct pt_regs *regs)
{
u32 stat;
int i, irqofs, handled;
do {
handled = 0;
for (i = 0; i < 4; i++) {
stat = __raw_readl(tzic_base + TZIC_HIPND(i)) &
__raw_readl(tzic_base + TZIC_INTSEC0(i));
while (stat) {
handled = 1;
irqofs = fls(stat) - 1;
handle_domain_irq(domain, irqofs + i * 32, regs);
stat &= ~(1 << irqofs);
}
}
} while (handled);
}
void __init tzic_init_irq(void)
{
struct device_node *np;
int irq_base;
int i;
np = of_find_compatible_node(NULL, NULL, "fsl,tzic");
tzic_base = of_iomap(np, 0);
WARN_ON(!tzic_base);
i = __raw_readl(tzic_base + TZIC_INTCNTL);
__raw_writel(0x80010001, tzic_base + TZIC_INTCNTL);
__raw_writel(0x1f, tzic_base + TZIC_PRIOMASK);
__raw_writel(0x02, tzic_base + TZIC_SYNCCTRL);
for (i = 0; i < 4; i++)
__raw_writel(0xFFFFFFFF, tzic_base + TZIC_INTSEC0(i));
for (i = 0; i < 4; i++)
__raw_writel(0xFFFFFFFF, tzic_base + TZIC_ENCLEAR0(i));
irq_base = irq_alloc_descs(-1, 0, TZIC_NUM_IRQS, numa_node_id());
WARN_ON(irq_base < 0);
domain = irq_domain_add_legacy(np, TZIC_NUM_IRQS, irq_base, 0,
&irq_domain_simple_ops, NULL);
WARN_ON(!domain);
for (i = 0; i < 4; i++, irq_base += 32)
tzic_init_gc(i, irq_base);
set_handle_irq(tzic_handle_irq);
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
pr_info("TrustZone Interrupt Controller (TZIC) initialized\n");
}
int tzic_enable_wake(void)
{
unsigned int i;
__raw_writel(1, tzic_base + TZIC_DSMINT);
if (unlikely(__raw_readl(tzic_base + TZIC_DSMINT) == 0))
return -EAGAIN;
for (i = 0; i < 4; i++)
__raw_writel(__raw_readl(tzic_base + TZIC_ENSET0(i)),
tzic_base + TZIC_WAKEUP0(i));
return 0;
}
