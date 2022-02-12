static __init void omapl138_hawk_config_emac(void)
{
void __iomem *cfgchip3 = DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG);
int ret;
u32 val;
struct davinci_soc_info *soc_info = &davinci_soc_info;
val = __raw_readl(cfgchip3);
val &= ~BIT(8);
ret = davinci_cfg_reg_list(omapl138_hawk_mii_pins);
if (ret) {
pr_warn("%s: CPGMAC/MII mux setup failed: %d\n", __func__, ret);
return;
}
__raw_writel(val, cfgchip3);
pr_info("EMAC: MII PHY configured\n");
soc_info->emac_pdata->phy_id = HAWKBOARD_PHY_ID;
ret = da8xx_register_emac();
if (ret)
pr_warn("%s: EMAC registration failed: %d\n", __func__, ret);
}
static __init void omapl138_hawk_mmc_init(void)
{
int ret;
ret = davinci_cfg_reg_list(hawk_mmcsd0_pins);
if (ret) {
pr_warn("%s: MMC/SD0 mux setup failed: %d\n", __func__, ret);
return;
}
gpiod_add_lookup_table(&mmc_gpios_table);
ret = da8xx_register_mmcsd0(&da850_mmc_config);
if (ret) {
pr_warn("%s: MMC/SD0 registration failed: %d\n", __func__, ret);
goto mmc_setup_mmcsd_fail;
}
return;
mmc_setup_mmcsd_fail:
gpiod_remove_lookup_table(&mmc_gpios_table);
}
static int hawk_usb_set_power(unsigned port, int on)
{
gpio_set_value(DA850_USB1_VBUS_PIN, on);
return 0;
}
static int hawk_usb_get_power(unsigned port)
{
return gpio_get_value(DA850_USB1_VBUS_PIN);
}
static int hawk_usb_get_oci(unsigned port)
{
return !gpio_get_value(DA850_USB1_OC_PIN);
}
static int hawk_usb_ocic_notify(da8xx_ocic_handler_t handler)
{
int irq = gpio_to_irq(DA850_USB1_OC_PIN);
int error = 0;
if (handler != NULL) {
hawk_usb_ocic_handler = handler;
error = request_irq(irq, omapl138_hawk_usb_ocic_irq,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING,
"OHCI over-current indicator", NULL);
if (error)
pr_err("%s: could not request IRQ to watch "
"over-current indicator changes\n", __func__);
} else {
free_irq(irq, NULL);
}
return error;
}
static irqreturn_t omapl138_hawk_usb_ocic_irq(int irq, void *dev_id)
{
hawk_usb_ocic_handler(&omapl138_hawk_usb11_pdata, 1);
return IRQ_HANDLED;
}
static __init void omapl138_hawk_usb_init(void)
{
int ret;
ret = davinci_cfg_reg_list(da850_hawk_usb11_pins);
if (ret) {
pr_warn("%s: USB 1.1 PinMux setup failed: %d\n", __func__, ret);
return;
}
ret = da8xx_register_usb20_phy_clk(false);
if (ret)
pr_warn("%s: USB 2.0 PHY CLK registration failed: %d\n",
__func__, ret);
ret = da8xx_register_usb11_phy_clk(false);
if (ret)
pr_warn("%s: USB 1.1 PHY CLK registration failed: %d\n",
__func__, ret);
ret = da8xx_register_usb_phy();
if (ret)
pr_warn("%s: USB PHY registration failed: %d\n",
__func__, ret);
ret = gpio_request_one(DA850_USB1_VBUS_PIN,
GPIOF_DIR_OUT, "USB1 VBUS");
if (ret < 0) {
pr_err("%s: failed to request GPIO for USB 1.1 port "
"power control: %d\n", __func__, ret);
return;
}
ret = gpio_request_one(DA850_USB1_OC_PIN,
GPIOF_DIR_IN, "USB1 OC");
if (ret < 0) {
pr_err("%s: failed to request GPIO for USB 1.1 port "
"over-current indicator: %d\n", __func__, ret);
goto usb11_setup_oc_fail;
}
ret = da8xx_register_usb11(&omapl138_hawk_usb11_pdata);
if (ret) {
pr_warn("%s: USB 1.1 registration failed: %d\n", __func__, ret);
goto usb11_setup_fail;
}
return;
usb11_setup_fail:
gpio_free(DA850_USB1_OC_PIN);
usb11_setup_oc_fail:
gpio_free(DA850_USB1_VBUS_PIN);
}
static __init void omapl138_hawk_init(void)
{
int ret;
ret = da8xx_register_cfgchip();
if (ret)
pr_warn("%s: CFGCHIP registration failed: %d\n", __func__, ret);
ret = da850_register_gpio();
if (ret)
pr_warn("%s: GPIO init failed: %d\n", __func__, ret);
davinci_serial_init(da8xx_serial_device);
omapl138_hawk_config_emac();
ret = da850_register_edma(da850_edma_rsv);
if (ret)
pr_warn("%s: EDMA registration failed: %d\n", __func__, ret);
omapl138_hawk_mmc_init();
omapl138_hawk_usb_init();
ret = da8xx_register_watchdog();
if (ret)
pr_warn("%s: watchdog registration failed: %d\n",
__func__, ret);
ret = da8xx_register_rproc();
if (ret)
pr_warn("%s: dsp/rproc registration failed: %d\n",
__func__, ret);
regulator_has_full_constraints();
}
static int __init omapl138_hawk_console_init(void)
{
if (!machine_is_omapl138_hawkboard())
return 0;
return add_preferred_console("ttyS", 2, "115200");
}
static void __init omapl138_hawk_map_io(void)
{
da850_init();
}
