void __init r8a7779_map_io(void)
{
iotable_init(r8a7779_io_desc, ARRAY_SIZE(r8a7779_io_desc));
}
void __init r8a7779_init_irq_extpin(int irlm)
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
if (irlm)
platform_device_register_resndata(
&platform_bus, "renesas_intc_irqpin", -1,
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
void __init r8a7779_add_standard_devices(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x40470000, 0x82000fff);
#endif
r8a7779_pm_init();
r8a7779_init_pm_domains();
platform_add_devices(r8a7779_devices_dt,
ARRAY_SIZE(r8a7779_devices_dt));
platform_add_devices(r8a7779_standard_devices,
ARRAY_SIZE(r8a7779_standard_devices));
}
void __init r8a7779_add_ether_device(struct sh_eth_plat_data *pdata)
{
platform_device_register_resndata(&platform_bus, "r8a777x-ether", -1,
ether_resources,
ARRAY_SIZE(ether_resources),
pdata, sizeof(*pdata));
}
void __init r8a7779_add_vin_device(int id, struct rcar_vin_platform_data *pdata)
{
BUG_ON(id < 0 || id > 3);
vin_info_table[id]->data = pdata;
vin_info_table[id]->size_data = sizeof(*pdata);
platform_device_register_full(vin_info_table[id]);
}
void __init __weak r8a7779_register_twd(void) { }
void __init r8a7779_earlytimer_init(void)
{
r8a7779_clock_init();
r8a7779_register_twd();
shmobile_earlytimer_init();
}
void __init r8a7779_add_early_devices(void)
{
early_platform_add_devices(r8a7779_devices_dt,
ARRAY_SIZE(r8a7779_devices_dt));
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
gic_arch_extn.irq_set_wake = r8a7779_set_wake;
irqchip_init();
__raw_writel(0xffffffff, INT2NTSR0);
__raw_writel(0x3fffffff, INT2NTSR1);
__raw_writel(0xfffffff0, INT2SMSKCR0);
__raw_writel(0xfff7ffff, INT2SMSKCR1);
__raw_writel(0xfffbffdf, INT2SMSKCR2);
__raw_writel(0xbffffffc, INT2SMSKCR3);
__raw_writel(0x003fee3f, INT2SMSKCR4);
}
void __init r8a7779_init_delay(void)
{
shmobile_setup_delay(1000, 2, 4);
}
void __init r8a7779_add_standard_devices_dt(void)
{
r8a7779_clock_init();
platform_add_devices(r8a7779_devices_dt,
ARRAY_SIZE(r8a7779_devices_dt));
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
