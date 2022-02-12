static void __init lager_add_du_device(void)
{
struct platform_device_info info = {
.name = "rcar-du-r8a7790",
.id = -1,
.res = du_resources,
.num_res = ARRAY_SIZE(du_resources),
.data = &lager_du_pdata,
.size_data = sizeof(lager_du_pdata),
.dma_mask = DMA_BIT_MASK(32),
};
platform_device_register_full(&info);
}
static void __init lager_add_vin_device(unsigned idx,
struct rcar_vin_platform_data *pdata)
{
struct platform_device_info vin_info = {
.name = "r8a7790-vin",
.id = idx,
.res = &vin_resources[idx * 2],
.num_res = 2,
.dma_mask = DMA_BIT_MASK(32),
.data = pdata,
.size_data = sizeof(*pdata),
};
BUG_ON(idx > 1);
platform_device_register_full(&vin_info);
}
static void __init lager_add_camera1_device(void)
{
platform_device_register_data(NULL, "soc-camera-pdrv", 1,
&cam1_link, sizeof(cam1_link));
lager_add_vin_device(1, &vin1_pdata);
}
static int usbhs_power_ctrl(struct platform_device *pdev,
void __iomem *base, int enable)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
if (!priv->phy)
return -ENODEV;
if (enable) {
int retval = usb_phy_init(priv->phy);
if (!retval)
retval = usb_phy_set_suspend(priv->phy, 0);
return retval;
}
usb_phy_set_suspend(priv->phy, 1);
usb_phy_shutdown(priv->phy);
return 0;
}
static int usbhs_hardware_init(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
struct usb_phy *phy;
int ret;
gpio_request_one(RCAR_GP_PIN(5, 18), GPIOF_IN, NULL);
if (!gpio_get_value(RCAR_GP_PIN(5, 18))) {
pr_warn("Error: USB Function not selected - check SW5 + SW6\n");
ret = -ENOTSUPP;
goto error;
}
phy = usb_get_phy_dev(&pdev->dev, 0);
if (IS_ERR(phy)) {
ret = PTR_ERR(phy);
goto error;
}
priv->phy = phy;
return 0;
error:
gpio_free(RCAR_GP_PIN(5, 18));
return ret;
}
static int usbhs_hardware_exit(struct platform_device *pdev)
{
struct usbhs_private *priv = usbhs_get_priv(pdev);
if (!priv->phy)
return 0;
usb_put_phy(priv->phy);
priv->phy = NULL;
gpio_free(RCAR_GP_PIN(5, 18));
return 0;
}
static int usbhs_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
static void __init lager_register_usbhs(void)
{
usb_bind_phy("renesas_usbhs", 0, "usb_phy_rcar_gen2");
platform_device_register_resndata(NULL,
"renesas_usbhs", -1,
usbhs_resources,
ARRAY_SIZE(usbhs_resources),
&usbhs_priv.info,
sizeof(usbhs_priv.info));
}
static void __init lager_add_rsnd_device(void)
{
struct platform_device_info cardinfo = {
.name = "asoc-simple-card",
.id = -1,
.data = &rsnd_card_info,
.size_data = sizeof(struct asoc_simple_card_info),
.dma_mask = DMA_BIT_MASK(32),
};
i2c_register_board_info(2, i2c2_devices,
ARRAY_SIZE(i2c2_devices));
platform_device_register_resndata(
NULL, "rcar_sound", -1,
rsnd_resources, ARRAY_SIZE(rsnd_resources),
&rsnd_info, sizeof(rsnd_info));
platform_device_register_full(&cardinfo);
}
static void __init lager_add_usb1_device(void)
{
platform_device_register_full(&pci1_info);
}
static void __init lager_add_usb2_device(void)
{
platform_device_register_full(&pci2_info);
}
static void __init lager_add_standard_devices(void)
{
int fixed_regulator_idx = 0;
int gpio_regulator_idx = 0;
r8a7790_clock_init();
pinctrl_register_mappings(lager_pinctrl_map,
ARRAY_SIZE(lager_pinctrl_map));
r8a7790_pinmux_init();
r8a7790_add_standard_devices();
platform_device_register_data(NULL, "leds-gpio", -1,
&lager_leds_pdata,
sizeof(lager_leds_pdata));
platform_device_register_data(NULL, "gpio-keys", -1,
&lager_keys_pdata,
sizeof(lager_keys_pdata));
regulator_register_always_on(fixed_regulator_idx++,
"fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
platform_device_register_resndata(NULL, "sh_mmcif", 1,
mmcif1_resources, ARRAY_SIZE(mmcif1_resources),
&mmcif1_pdata, sizeof(mmcif1_pdata));
platform_device_register_full(&ether_info);
lager_add_du_device();
platform_device_register_resndata(NULL, "qspi", 0,
qspi_resources,
ARRAY_SIZE(qspi_resources),
&qspi_pdata, sizeof(qspi_pdata));
spi_register_board_info(spi_info, ARRAY_SIZE(spi_info));
platform_device_register_data(NULL, "reg-fixed-voltage", fixed_regulator_idx++,
&vcc_sdhi0_info, sizeof(struct fixed_voltage_config));
platform_device_register_data(NULL, "reg-fixed-voltage", fixed_regulator_idx++,
&vcc_sdhi2_info, sizeof(struct fixed_voltage_config));
platform_device_register_data(NULL, "gpio-regulator", gpio_regulator_idx++,
&vccq_sdhi0_info, sizeof(struct gpio_regulator_config));
platform_device_register_data(NULL, "gpio-regulator", gpio_regulator_idx++,
&vccq_sdhi2_info, sizeof(struct gpio_regulator_config));
lager_add_camera1_device();
platform_device_register_full(&sata1_info);
platform_device_register_resndata(NULL, "usb_phy_rcar_gen2",
-1, usbhs_phy_resources,
ARRAY_SIZE(usbhs_phy_resources),
&usbhs_phy_pdata,
sizeof(usbhs_phy_pdata));
lager_register_usbhs();
lager_add_usb1_device();
lager_add_usb2_device();
lager_add_rsnd_device();
platform_device_register_resndata(NULL, "sh_mobile_sdhi", 0,
sdhi0_resources, ARRAY_SIZE(sdhi0_resources),
&sdhi0_info, sizeof(struct sh_mobile_sdhi_info));
platform_device_register_resndata(NULL, "sh_mobile_sdhi", 2,
sdhi2_resources, ARRAY_SIZE(sdhi2_resources),
&sdhi2_info, sizeof(struct sh_mobile_sdhi_info));
}
static int lager_ksz8041_fixup(struct phy_device *phydev)
{
u16 phyctrl1 = phy_read(phydev, 0x1e);
phyctrl1 &= ~0xc000;
phyctrl1 |= 0x4000;
return phy_write(phydev, 0x1e, phyctrl1);
}
static void __init lager_init(void)
{
lager_add_standard_devices();
irq_set_irq_type(irq_pin(0), IRQ_TYPE_LEVEL_LOW);
if (IS_ENABLED(CONFIG_PHYLIB))
phy_register_fixup_for_id("r8a7790-ether-ff:01",
lager_ksz8041_fixup);
}
