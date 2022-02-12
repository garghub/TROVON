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
void __init r8a7778_add_ether_device(struct sh_eth_plat_data *pdata)
{
platform_device_register_resndata(&platform_bus, "r8a777x-ether", -1,
ether_resources,
ARRAY_SIZE(ether_resources),
pdata, sizeof(*pdata));
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
void __init r8a7778_register_hspi(int id)
{
BUG_ON(id < 0 || id > 2);
platform_device_register_simple(
"sh-hspi", id,
hspi_resources + (2 * id), 2);
}
void __init r8a7778_add_vin_device(int id, struct rcar_vin_platform_data *pdata)
{
BUG_ON(id < 0 || id > 1);
vin_info_table[id]->data = pdata;
vin_info_table[id]->size_data = sizeof(*pdata);
platform_device_register_full(vin_info_table[id]);
}
void __init r8a7778_add_dt_devices(void)
{
int i;
#ifdef CONFIG_CACHE_L2X0
void __iomem *base = ioremap_nocache(0xf0100000, 0x1000);
if (base) {
l2x0_init(base, 0x40470000, 0x82000fff);
}
#endif
for (i = 0; i < ARRAY_SIZE(scif_platform_data); i++)
platform_device_register_data(&platform_bus, "sh-sci", i,
&scif_platform_data[i],
sizeof(struct plat_sci_port));
r8a7778_register_tmu(0);
r8a7778_register_tmu(1);
}
void __init r8a7778_add_standard_devices(void)
{
r8a7778_add_dt_devices();
r8a7778_register_i2c(0);
r8a7778_register_i2c(1);
r8a7778_register_i2c(2);
r8a7778_register_i2c(3);
r8a7778_register_hspi(0);
r8a7778_register_hspi(1);
r8a7778_register_hspi(2);
}
void __init r8a7778_init_late(void)
{
phy = usb_get_phy(USB_PHY_TYPE_USB2);
platform_device_register_full(&ehci_info);
platform_device_register_full(&ohci_info);
}
void __init r8a7778_init_irq_extpin(int irlm)
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
if (irlm)
platform_device_register_resndata(
&platform_bus, "renesas_intc_irqpin", -1,
irqpin_resources, ARRAY_SIZE(irqpin_resources),
&irqpin_platform_data, sizeof(irqpin_platform_data));
}
void __init r8a7778_init_delay(void)
{
shmobile_setup_delay(800, 1, 3);
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
