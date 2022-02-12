static int __init sh7763_devices_setup(void)
{
return platform_add_devices(sh7763_devices,
ARRAY_SIZE(sh7763_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7763_early_devices,
ARRAY_SIZE(sh7763_early_devices));
}
void __init plat_irq_setup(void)
{
__raw_writel(0xff000000, INTC_INTMSK0);
__raw_writel(0xc0000000, INTC_INTMSK1);
__raw_writel(0xfffefffe, INTC_INTMSK2);
register_intc_controller(&intc_desc);
}
void __init plat_irq_setup_pins(int mode)
{
switch (mode) {
case IRQ_MODE_IRQ:
__raw_writel(__raw_readl(INTC_ICR0) | 0x00c00000, INTC_ICR0);
register_intc_controller(&intc_irq_desc);
break;
case IRQ_MODE_IRL7654:
__raw_writel(0x40000000, INTC_INTMSKCLR1);
__raw_writel(0x0000fffe, INTC_INTMSKCLR2);
break;
case IRQ_MODE_IRL3210:
__raw_writel(0x80000000, INTC_INTMSKCLR1);
__raw_writel(0xfffe0000, INTC_INTMSKCLR2);
break;
case IRQ_MODE_IRL7654_MASK:
__raw_writel(0x40000000, INTC_INTMSKCLR1);
register_intc_controller(&intc_irl7654_desc);
break;
case IRQ_MODE_IRL3210_MASK:
__raw_writel(0x80000000, INTC_INTMSKCLR1);
register_intc_controller(&intc_irl3210_desc);
break;
default:
BUG();
}
}
