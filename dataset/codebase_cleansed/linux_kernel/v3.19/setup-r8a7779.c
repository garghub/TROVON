void __init r8a7779_map_io(void)
{
debug_ll_io_init();
iotable_init(r8a7779_io_desc, ARRAY_SIZE(r8a7779_io_desc));
}
void __init r8a7779_init_irq_extpin_dt(int irlm)
{
void __iomem *icr0 = ioremap_nocache(0xfe780000, PAGE_SIZE);
u32 tmp;
if (!icr0) {
pr_warn("r8a7779: unable to setup external irq pin mode\n");
return;
}
tmp = ioread32(icr0);
if (irlm)
tmp |= 1 << 23;
else
tmp &= ~(1 << 23);
tmp |= (1 << 21);
iowrite32(tmp, icr0);
iounmap(icr0);
}
void __init r8a7779_init_irq_extpin(int irlm)
{
r8a7779_init_irq_extpin_dt(irlm);
if (irlm)
platform_device_register_resndata(
NULL, "renesas_intc_irqpin", -1,
irqpin0_resources, ARRAY_SIZE(irqpin0_resources),
&irqpin0_platform_data, sizeof(irqpin0_platform_data));
}
void __init r8a7779_pinmux_init(void)
{
platform_add_devices(r8a7779_pinctrl_devices,
ARRAY_SIZE(r8a7779_pinctrl_devices));
}
static int usb_power_on(struct platform_device *pdev)
{
if (IS_ERR(phy))
return PTR_ERR(phy);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
usb_phy_init(phy);
return 0;
}
static void usb_power_off(struct platform_device *pdev)
{
if (IS_ERR(phy))
return;
usb_phy_shutdown(phy);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
}
static int ehci_init_internal_buffer(struct usb_hcd *hcd)
{
iowrite32(0x00ff0040, hcd->regs + 0x0094);
iowrite32(0x00000001, hcd->regs + 0x009C);
return 0;
}
static void __init r8a7779_register_hpb_dmae(void)
{
platform_device_register_resndata(NULL, "hpb-dma-engine",
-1, hpb_dmae_resources,
ARRAY_SIZE(hpb_dmae_resources),
&dma_platform_data,
sizeof(dma_platform_data));
}
void __init r8a7779_add_standard_devices(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x00400000, 0xc20f0fff);
#endif
r8a7779_pm_init();
r8a7779_init_pm_domains();
platform_add_devices(r8a7779_early_devices,
ARRAY_SIZE(r8a7779_early_devices));
platform_add_devices(r8a7779_standard_devices,
ARRAY_SIZE(r8a7779_standard_devices));
r8a7779_register_hpb_dmae();
}
void __init r8a7779_add_early_devices(void)
{
early_platform_add_devices(r8a7779_early_devices,
ARRAY_SIZE(r8a7779_early_devices));
}
void __init r8a7779_init_late(void)
{
phy = usb_get_phy(USB_PHY_TYPE_USB2);
shmobile_init_late();
platform_add_devices(r8a7779_late_devices,
ARRAY_SIZE(r8a7779_late_devices));
}
static int r8a7779_set_wake(struct irq_data *data, unsigned int on)
{
return 0;
}
void __init r8a7779_init_irq_dt(void)
{
#ifdef CONFIG_ARCH_SHMOBILE_LEGACY
void __iomem *gic_dist_base = ioremap_nocache(0xf0001000, 0x1000);
void __iomem *gic_cpu_base = ioremap_nocache(0xf0000100, 0x1000);
#endif
gic_arch_extn.irq_set_wake = r8a7779_set_wake;
#ifdef CONFIG_ARCH_SHMOBILE_LEGACY
gic_init(0, 29, gic_dist_base, gic_cpu_base);
#else
irqchip_init();
#endif
__raw_writel(0xffffffff, INT2NTSR0);
__raw_writel(0x3fffffff, INT2NTSR1);
__raw_writel(0xfffffff0, INT2SMSKCR0);
__raw_writel(0xfff7ffff, INT2SMSKCR1);
__raw_writel(0xfffbffdf, INT2SMSKCR2);
__raw_writel(0xbffffffc, INT2SMSKCR3);
__raw_writel(0x003fee3f, INT2SMSKCR4);
}
u32 __init r8a7779_read_mode_pins(void)
{
static u32 mode;
static bool mode_valid;
if (!mode_valid) {
void __iomem *modemr = ioremap_nocache(MODEMR, PAGE_SIZE);
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
mode_valid = true;
}
return mode;
}
