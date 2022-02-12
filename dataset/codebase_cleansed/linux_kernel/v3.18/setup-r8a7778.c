int r8a7778_usb_phy_power(bool enable)
{
static struct usb_phy *phy = NULL;
int ret = 0;
if (!phy)
phy = usb_get_phy(USB_PHY_TYPE_USB2);
if (IS_ERR(phy)) {
pr_err("kernel doesn't have usb phy driver\n");
return PTR_ERR(phy);
}
if (enable)
ret = usb_phy_init(phy);
else
usb_phy_shutdown(phy);
return ret;
}
static int usb_power_on(struct platform_device *pdev)
{
int ret = r8a7778_usb_phy_power(true);
if (ret)
return ret;
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
return 0;
}
static void usb_power_off(struct platform_device *pdev)
{
if (r8a7778_usb_phy_power(false))
return;
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
}
static int ehci_init_internal_buffer(struct usb_hcd *hcd)
{
iowrite32(0x00ff0040, hcd->regs + 0x0094);
iowrite32(0x00000001, hcd->regs + 0x009C);
return 0;
}
void __init r8a7778_pinmux_init(void)
{
platform_device_register_simple(
"pfc-r8a7778", -1,
pfc_resources,
ARRAY_SIZE(pfc_resources));
r8a7778_register_gpio(0);
r8a7778_register_gpio(1);
r8a7778_register_gpio(2);
r8a7778_register_gpio(3);
r8a7778_register_gpio(4);
}
static void __init r8a7778_register_i2c(int id)
{
BUG_ON(id < 0 || id > 3);
platform_device_register_simple(
"i2c-rcar", id,
i2c_resources + (2 * id), 2);
}
static void __init r8a7778_register_hspi(int id)
{
BUG_ON(id < 0 || id > 2);
platform_device_register_simple(
"sh-hspi", id,
hspi_resources + (2 * id), 2);
}
void __init r8a7778_add_dt_devices(void)
{
#ifdef CONFIG_CACHE_L2X0
void __iomem *base = ioremap_nocache(0xf0100000, 0x1000);
if (base) {
l2x0_init(base, 0x00400000, 0xc20f0fff);
}
#endif
r8a7778_register_tmu(0);
}
static void __init r8a7778_register_hpb_dmae(void)
{
platform_device_register_resndata(NULL, "hpb-dma-engine",
-1, hpb_dmae_resources,
ARRAY_SIZE(hpb_dmae_resources),
&dma_platform_data,
sizeof(dma_platform_data));
}
void __init r8a7778_add_standard_devices(void)
{
r8a7778_add_dt_devices();
r8a7778_register_scif(0);
r8a7778_register_scif(1);
r8a7778_register_scif(2);
r8a7778_register_scif(3);
r8a7778_register_scif(4);
r8a7778_register_scif(5);
r8a7778_register_i2c(0);
r8a7778_register_i2c(1);
r8a7778_register_i2c(2);
r8a7778_register_i2c(3);
r8a7778_register_hspi(0);
r8a7778_register_hspi(1);
r8a7778_register_hspi(2);
r8a7778_register_hpb_dmae();
}
void __init r8a7778_init_late(void)
{
shmobile_init_late();
platform_device_register_full(&ehci_info);
platform_device_register_full(&ohci_info);
}
void __init r8a7778_init_irq_extpin_dt(int irlm)
{
void __iomem *icr0 = ioremap_nocache(0xfe780000, PAGE_SIZE);
unsigned long tmp;
if (!icr0) {
pr_warn("r8a7778: unable to setup external irq pin mode\n");
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
void __init r8a7778_init_irq_extpin(int irlm)
{
r8a7778_init_irq_extpin_dt(irlm);
if (irlm)
platform_device_register_resndata(
NULL, "renesas_intc_irqpin", -1,
irqpin_resources, ARRAY_SIZE(irqpin_resources),
&irqpin_platform_data, sizeof(irqpin_platform_data));
}
void __init r8a7778_init_delay(void)
{
shmobile_init_delay();
}
void __init r8a7778_init_irq_dt(void)
{
void __iomem *base = ioremap_nocache(0xfe700000, 0x00100000);
BUG_ON(!base);
irqchip_init();
__raw_writel(0x73ffffff, base + INT2NTSR0);
__raw_writel(0xffffffff, base + INT2NTSR1);
__raw_writel(0x08330773, base + INT2SMSKCR0);
__raw_writel(0x00311110, base + INT2SMSKCR1);
iounmap(base);
}
