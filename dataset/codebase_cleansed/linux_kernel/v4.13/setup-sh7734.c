void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7734_early_devices,
ARRAY_SIZE(sh7734_early_devices));
}
void __init plat_irq_setup(void)
{
__raw_writel(0xF0000000, INTC_INTMSK0);
__raw_writel(0x80000000, INTC_INTMSK1);
__raw_writel(__raw_readl(INTC_ICR0) & ~0x00800000, INTC_ICR0);
__raw_writel(__raw_readl(INTC_ICR0) | 0x00200000, INTC_ICR0);
register_intc_controller(&intc_desc);
}
void __init plat_irq_setup_pins(int mode)
{
switch (mode) {
case IRQ_MODE_IRQ3210:
__raw_writel(__raw_readl(INTC_ICR0) | 0x00800000, INTC_ICR0);
register_intc_controller(&intc_desc_irq3210);
break;
case IRQ_MODE_IRL3210:
__raw_writel(0x80000000, INTC_INTMSKCLR1);
__raw_writel(0xf0000000, INTC_INTMSKCLR0);
break;
case IRQ_MODE_IRL3210_MASK:
__raw_writel(0x80000000, INTC_INTMSKCLR0);
register_intc_controller(&intc_desc_irl3210);
break;
default:
BUG();
}
}
