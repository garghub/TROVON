static int r8a7779_set_wake(struct irq_data *data, unsigned int on)
{
return 0;
}
void __init r8a7779_init_irq(void)
{
void __iomem *gic_dist_base = IOMEM(0xf0001000);
void __iomem *gic_cpu_base = IOMEM(0xf0000100);
gic_init(0, 29, gic_dist_base, gic_cpu_base);
gic_arch_extn.irq_set_wake = r8a7779_set_wake;
__raw_writel(0xfffffff0, INT2SMSKCR0);
__raw_writel(0xfff7ffff, INT2SMSKCR1);
__raw_writel(0xfffbffdf, INT2SMSKCR2);
__raw_writel(0xbffffffc, INT2SMSKCR3);
__raw_writel(0x003fee3f, INT2SMSKCR4);
}
