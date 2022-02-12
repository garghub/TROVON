void __init sh7786_usb_use_exclock(void)
{
u32 val = __raw_readl(USBCTL0) & CLOCK_MODE_MASK;
__raw_writel(val | EXT_CLOCK_MODE, USBCTL0);
}
static void __init sh7786_usb_setup(void)
{
int i = 1000000;
__raw_writel(USBINITVAL1, USBINITREG1);
__raw_writel(USBINITVAL2, USBINITREG2);
__raw_writel(PHY_ENB | PLL_ENB, USBPCTL1);
while (i--) {
if (ACT_PLL_STATUS == (__raw_readl(USBST) & ACT_PLL_STATUS)) {
__raw_writel(PHY_ENB | PLL_ENB | PHY_RST, USBPCTL1);
printk(KERN_INFO "sh7786 usb setup done\n");
break;
}
cpu_relax();
}
}
void __init plat_irq_setup(void)
{
__raw_writel(0xff000000, INTC_INTMSK0);
__raw_writel(0xc0000000, INTC_INTMSK1);
__raw_writel(0xfffefffe, INTC_INTMSK2);
__raw_writel(__raw_readl(INTC_ICR0) & ~0x00c00000, INTC_ICR0);
register_intc_controller(&sh7786_intc_desc);
}
void __init plat_irq_setup_pins(int mode)
{
switch (mode) {
case IRQ_MODE_IRQ7654:
__raw_writel(__raw_readl(INTC_ICR0) | 0x00400000, INTC_ICR0);
register_intc_controller(&intc_desc_irq4567);
break;
case IRQ_MODE_IRQ3210:
__raw_writel(__raw_readl(INTC_ICR0) | 0x00800000, INTC_ICR0);
register_intc_controller(&intc_desc_irq0123);
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
register_intc_controller(&intc_desc_irl4567);
break;
case IRQ_MODE_IRL3210_MASK:
__raw_writel(0x80000000, INTC_INTMSKCLR1);
register_intc_controller(&intc_desc_irl0123);
break;
default:
BUG();
}
}
void __init plat_mem_setup(void)
{
}
static int __init sh7786_devices_setup(void)
{
int ret, irq;
sh7786_usb_setup();
irq = intc_irq_lookup(sh7786_intc_desc.name, TXI1);
if (irq > 0) {
scif1_demux_resources[1].start =
intc_irq_lookup(sh7786_intc_desc.name, ERI1);
scif1_demux_resources[2].start =
intc_irq_lookup(sh7786_intc_desc.name, RXI1);
scif1_demux_resources[3].start = irq;
scif1_demux_resources[4].start =
intc_irq_lookup(sh7786_intc_desc.name, BRI1);
scif1_device.resource = scif1_demux_resources;
scif1_device.num_resources = ARRAY_SIZE(scif1_demux_resources);
}
ret = platform_add_devices(sh7786_early_devices,
ARRAY_SIZE(sh7786_early_devices));
if (unlikely(ret != 0))
return ret;
return platform_add_devices(sh7786_devices,
ARRAY_SIZE(sh7786_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7786_early_devices,
ARRAY_SIZE(sh7786_early_devices));
}
