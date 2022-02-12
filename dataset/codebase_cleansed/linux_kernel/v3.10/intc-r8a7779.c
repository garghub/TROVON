void __init r8a7779_init_irq_extpin(int irlm)
{
void __iomem *icr0 = ioremap_nocache(0xfe780000, PAGE_SIZE);
unsigned long tmp;
if (icr0) {
tmp = ioread32(icr0);
if (irlm)
tmp |= 1 << 23;
else
tmp &= ~(1 << 23);
tmp |= (1 << 21);
iowrite32(tmp, icr0);
iounmap(icr0);
if (irlm)
platform_device_register(&irqpin0_device);
} else
pr_warn("r8a7779: unable to setup external irq pin mode\n");
}
static int r8a7779_set_wake(struct irq_data *data, unsigned int on)
{
return 0;
}
static void __init r8a7779_init_irq_common(void)
{
gic_arch_extn.irq_set_wake = r8a7779_set_wake;
__raw_writel(0xffffffff, INT2NTSR0);
__raw_writel(0x3fffffff, INT2NTSR1);
__raw_writel(0xfffffff0, INT2SMSKCR0);
__raw_writel(0xfff7ffff, INT2SMSKCR1);
__raw_writel(0xfffbffdf, INT2SMSKCR2);
__raw_writel(0xbffffffc, INT2SMSKCR3);
__raw_writel(0x003fee3f, INT2SMSKCR4);
}
void __init r8a7779_init_irq(void)
{
void __iomem *gic_dist_base = IOMEM(0xf0001000);
void __iomem *gic_cpu_base = IOMEM(0xf0000100);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
r8a7779_init_irq_common();
}
void __init r8a7779_init_irq_dt(void)
{
irqchip_init();
r8a7779_init_irq_common();
}
