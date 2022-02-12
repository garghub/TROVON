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
static __init void tzic_init_gc(unsigned int irq_start)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
int idx = irq_start >> 5;
gc = irq_alloc_generic_chip("tzic", 1, irq_start, tzic_base,
handle_level_irq);
gc->private = tzic_set_irq_fiq;
gc->wake_enabled = IRQ_MSK(32);
wakeup_intr[idx] = &gc->wake_active;
ct = gc->chip_types;
ct->chip.irq_mask = irq_gc_mask_disable_reg;
ct->chip.irq_unmask = irq_gc_unmask_enable_reg;
ct->chip.irq_set_wake = irq_gc_set_wake;
ct->regs.disable = TZIC_ENCLEAR0(idx);
ct->regs.enable = TZIC_ENSET0(idx);
irq_setup_generic_chip(gc, IRQ_MSK(32), 0, IRQ_NOREQUEST, 0);
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
for (i = 0; i < TZIC_NUM_IRQS; i += 32)
tzic_init_gc(i);
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
*wakeup_intr[i];
__raw_writel(v, tzic_base + TZIC_WAKEUP0(i));
}
return 0;
}
