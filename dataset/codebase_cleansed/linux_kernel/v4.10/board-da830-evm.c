static int da830_evm_usb_set_power(unsigned port, int on)
{
gpio_set_value(ON_BD_USB_DRV, on);
return 0;
}
static int da830_evm_usb_get_power(unsigned port)
{
return gpio_get_value(ON_BD_USB_DRV);
}
static int da830_evm_usb_get_oci(unsigned port)
{
return !gpio_get_value(ON_BD_USB_OVC);
}
static int da830_evm_usb_ocic_notify(da8xx_ocic_handler_t handler)
{
int irq = gpio_to_irq(ON_BD_USB_OVC);
int error = 0;
if (handler != NULL) {
da830_evm_usb_ocic_handler = handler;
error = request_irq(irq, da830_evm_usb_ocic_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"OHCI over-current indicator", NULL);
if (error)
pr_err("%s: could not request IRQ to watch over-current indicator changes\n",
__func__);
} else
free_irq(irq, NULL);
return error;
}
static irqreturn_t da830_evm_usb_ocic_irq(int irq, void *dev_id)
{
da830_evm_usb_ocic_handler(&da830_evm_usb11_pdata, 1);
return IRQ_HANDLED;
}
static __init void da830_evm_usb_init(void)
{
int ret;
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
ret = davinci_cfg_reg(DA830_USB0_DRVVBUS);
if (ret)
pr_warn("%s: USB 2.0 PinMux setup failed: %d\n", __func__, ret);
else {
ret = da8xx_register_usb20(1000, 3);
if (ret)
pr_warn("%s: USB 2.0 registration failed: %d\n",
__func__, ret);
}
ret = davinci_cfg_reg_list(da830_evm_usb11_pins);
if (ret) {
pr_warn("%s: USB 1.1 PinMux setup failed: %d\n", __func__, ret);
return;
}
ret = gpio_request(ON_BD_USB_DRV, "ON_BD_USB_DRV");
if (ret) {
pr_err("%s: failed to request GPIO for USB 1.1 port power control: %d\n",
__func__, ret);
return;
}
gpio_direction_output(ON_BD_USB_DRV, 0);
ret = gpio_request(ON_BD_USB_OVC, "ON_BD_USB_OVC");
if (ret) {
pr_err("%s: failed to request GPIO for USB 1.1 port over-current indicator: %d\n",
__func__, ret);
return;
}
gpio_direction_input(ON_BD_USB_OVC);
ret = da8xx_register_usb11(&da830_evm_usb11_pdata);
if (ret)
pr_warn("%s: USB 1.1 registration failed: %d\n", __func__, ret);
}
static inline void da830_evm_init_mmc(void)
{
int ret;
ret = davinci_cfg_reg_list(da830_evm_mmc_sd_pins);
if (ret) {
pr_warn("%s: mmc/sd mux setup failed: %d\n", __func__, ret);
return;
}
gpiod_add_lookup_table(&mmc_gpios_table);
ret = da8xx_register_mmcsd0(&da830_evm_mmc_config);
if (ret) {
pr_warn("%s: mmc/sd registration failed: %d\n", __func__, ret);
gpiod_remove_lookup_table(&mmc_gpios_table);
}
}
static inline void da830_evm_init_nand(int mux_mode)
{
int ret;
if (HAS_MMC) {
pr_warn("WARNING: both MMC/SD and NAND are enabled, but they share AEMIF pins\n"
"\tDisable MMC/SD for NAND support\n");
return;
}
ret = davinci_cfg_reg_list(da830_evm_emif25_pins);
if (ret)
pr_warn("%s: emif25 mux setup failed: %d\n", __func__, ret);
ret = platform_device_register(&da830_evm_nand_device);
if (ret)
pr_warn("%s: NAND device not registered\n", __func__);
if (davinci_aemif_setup(&da830_evm_nand_device))
pr_warn("%s: Cannot configure AEMIF\n", __func__);
gpio_direction_output(mux_mode, 1);
}
static inline void da830_evm_init_nand(int mux_mode) { }
static inline void da830_evm_init_lcdc(int mux_mode)
{
int ret;
ret = davinci_cfg_reg_list(da830_lcdcntl_pins);
if (ret)
pr_warn("%s: lcdcntl mux setup failed: %d\n", __func__, ret);
ret = da8xx_register_lcdc(&sharp_lcd035q3dg01_pdata);
if (ret)
pr_warn("%s: lcd setup failed: %d\n", __func__, ret);
gpio_direction_output(mux_mode, 0);
}
static inline void da830_evm_init_lcdc(int mux_mode) { }
static int __init da830_evm_ui_expander_setup(struct i2c_client *client,
int gpio, unsigned ngpio, void *context)
{
gpio_request(gpio + 6, "UI MUX_MODE");
gpio_direction_output(gpio + 6, 0);
da830_evm_init_lcdc(gpio + 6);
da830_evm_init_nand(gpio + 6);
return 0;
}
static int da830_evm_ui_expander_teardown(struct i2c_client *client, int gpio,
unsigned ngpio, void *context)
{
gpio_free(gpio + 6);
return 0;
}
static __init void da830_evm_init(void)
{
struct davinci_soc_info *soc_info = &davinci_soc_info;
int ret;
ret = da8xx_register_cfgchip();
if (ret)
pr_warn("%s: CFGCHIP registration failed: %d\n", __func__, ret);
ret = da830_register_gpio();
if (ret)
pr_warn("%s: GPIO init failed: %d\n", __func__, ret);
ret = da830_register_edma(da830_edma_rsv);
if (ret)
pr_warn("%s: edma registration failed: %d\n", __func__, ret);
ret = davinci_cfg_reg_list(da830_i2c0_pins);
if (ret)
pr_warn("%s: i2c0 mux setup failed: %d\n", __func__, ret);
ret = da8xx_register_i2c(0, &da830_evm_i2c_0_pdata);
if (ret)
pr_warn("%s: i2c0 registration failed: %d\n", __func__, ret);
da830_evm_usb_init();
soc_info->emac_pdata->rmii_en = 1;
soc_info->emac_pdata->phy_id = DA830_EVM_PHY_ID;
ret = davinci_cfg_reg_list(da830_cpgmac_pins);
if (ret)
pr_warn("%s: cpgmac mux setup failed: %d\n", __func__, ret);
ret = da8xx_register_emac();
if (ret)
pr_warn("%s: emac registration failed: %d\n", __func__, ret);
ret = da8xx_register_watchdog();
if (ret)
pr_warn("%s: watchdog registration failed: %d\n",
__func__, ret);
davinci_serial_init(da8xx_serial_device);
i2c_register_board_info(1, da830_evm_i2c_devices,
ARRAY_SIZE(da830_evm_i2c_devices));
ret = davinci_cfg_reg_list(da830_evm_mcasp1_pins);
if (ret)
pr_warn("%s: mcasp1 mux setup failed: %d\n", __func__, ret);
da8xx_register_mcasp(1, &da830_evm_snd_data);
da830_evm_init_mmc();
ret = da8xx_register_rtc();
if (ret)
pr_warn("%s: rtc setup failed: %d\n", __func__, ret);
ret = spi_register_board_info(da830evm_spi_info,
ARRAY_SIZE(da830evm_spi_info));
if (ret)
pr_warn("%s: spi info registration failed: %d\n",
__func__, ret);
ret = da8xx_register_spi_bus(0, ARRAY_SIZE(da830evm_spi_info));
if (ret)
pr_warn("%s: spi 0 registration failed: %d\n", __func__, ret);
regulator_has_full_constraints();
}
static int __init da830_evm_console_init(void)
{
if (!machine_is_davinci_da830_evm())
return 0;
return add_preferred_console("ttyS", 2, "115200");
}
static void __init da830_evm_map_io(void)
{
da830_init();
}
