static void __init omap2420_n8x0_legacy_init(void)
{
omap_auxdata_lookup[0].platform_data = n8x0_legacy_init();
}
static void __init omap3_gpio126_127_129(void)
{
u32 reg;
reg = omap_ctrl_readl(OMAP343X_CONTROL_PBIAS_LITE);
reg &= ~OMAP343X_PBIASLITEVMODE1;
reg |= OMAP343X_PBIASLITEPWRDNZ1;
omap_ctrl_writel(reg, OMAP343X_CONTROL_PBIAS_LITE);
if (cpu_is_omap3630()) {
reg = omap_ctrl_readl(OMAP34XX_CONTROL_WKUP_CTRL);
reg |= OMAP36XX_GPIO_IO_PWRDNZ;
omap_ctrl_writel(reg, OMAP34XX_CONTROL_WKUP_CTRL);
}
}
static void __init hsmmc2_internal_input_clk(void)
{
u32 reg;
reg = omap_ctrl_readl(OMAP343X_CONTROL_DEVCONF1);
reg |= OMAP2_MMCSDIO2ADPCLKISEL;
omap_ctrl_writel(reg, OMAP343X_CONTROL_DEVCONF1);
}
static int omap3_sbc_t3730_twl_callback(struct device *dev,
unsigned gpio,
unsigned ngpio)
{
int res;
res = gpio_request_one(gpio + 2, GPIOF_OUT_INIT_HIGH,
"wlan pwr");
if (res)
return res;
gpio_export(gpio, 0);
return 0;
}
static void __init omap3_sbc_t3x_usb_hub_init(int gpio, char *hub_name)
{
int err = gpio_request_one(gpio, GPIOF_OUT_INIT_LOW, hub_name);
if (err) {
pr_err("SBC-T3x: %s reset gpio request failed: %d\n",
hub_name, err);
return;
}
gpio_export(gpio, 0);
udelay(10);
gpio_set_value(gpio, 1);
msleep(1);
}
static void __init omap3_sbc_t3730_twl_init(void)
{
twl_gpio_auxdata.setup = omap3_sbc_t3730_twl_callback;
}
static void __init omap3_sbc_t3730_legacy_init(void)
{
omap3_sbc_t3x_usb_hub_init(167, "sb-t35 usb hub");
}
static void __init omap3_sbc_t3530_legacy_init(void)
{
omap3_sbc_t3x_usb_hub_init(167, "sb-t35 usb hub");
}
static void __init omap3_igep0020_rev_f_legacy_init(void)
{
platform_device_register(&wl18xx_device);
platform_device_register(&btwilink_device);
}
static void __init omap3_igep0030_rev_g_legacy_init(void)
{
platform_device_register(&wl18xx_device);
platform_device_register(&btwilink_device);
}
static void __init omap3_evm_legacy_init(void)
{
hsmmc2_internal_input_clk();
}
static void am35xx_enable_emac_int(void)
{
u32 v;
v = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
v |= (AM35XX_CPGMAC_C0_RX_PULSE_CLR | AM35XX_CPGMAC_C0_TX_PULSE_CLR |
AM35XX_CPGMAC_C0_MISC_PULSE_CLR | AM35XX_CPGMAC_C0_RX_THRESH_CLR);
omap_ctrl_writel(v, AM35XX_CONTROL_LVL_INTR_CLEAR);
omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
static void am35xx_disable_emac_int(void)
{
u32 v;
v = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
v |= (AM35XX_CPGMAC_C0_RX_PULSE_CLR | AM35XX_CPGMAC_C0_TX_PULSE_CLR);
omap_ctrl_writel(v, AM35XX_CONTROL_LVL_INTR_CLEAR);
omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
static void __init am35xx_emac_reset(void)
{
u32 v;
v = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
v &= ~AM35XX_CPGMACSS_SW_RST;
omap_ctrl_writel(v, AM35XX_CONTROL_IP_SW_RESET);
omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
}
static void __init omap3_sbc_t3517_wifi_init(void)
{
int err = gpio_request_array(cm_t3517_wlan_gpios,
ARRAY_SIZE(cm_t3517_wlan_gpios));
if (err) {
pr_err("SBC-T3517: wl12xx gpios request failed: %d\n", err);
return;
}
gpio_export(cm_t3517_wlan_gpios[0].gpio, 0);
gpio_export(cm_t3517_wlan_gpios[1].gpio, 0);
msleep(100);
gpio_set_value(cm_t3517_wlan_gpios[1].gpio, 0);
}
static void __init omap3_sbc_t3517_legacy_init(void)
{
omap3_sbc_t3x_usb_hub_init(152, "cm-t3517 usb hub");
omap3_sbc_t3x_usb_hub_init(98, "sb-t35 usb hub");
am35xx_emac_reset();
hsmmc2_internal_input_clk();
omap3_sbc_t3517_wifi_init();
}
static void __init am3517_evm_legacy_init(void)
{
am35xx_emac_reset();
}
static void __init nokia_n900_legacy_init(void)
{
hsmmc2_internal_input_clk();
mmc_pdata[0].name = "external";
mmc_pdata[1].name = "internal";
if (omap_type() == OMAP2_DEVICE_TYPE_SEC) {
if (IS_ENABLED(CONFIG_ARM_ERRATA_430973)) {
pr_info("RX-51: Enabling ARM errata 430973 workaround\n");
rx51_secure_update_aux_cr(BIT(6), 0);
} else {
pr_warn("RX-51: Not enabling ARM errata 430973 workaround\n");
pr_warn("Thumb binaries may crash randomly without this workaround\n");
}
pr_info("RX-51: Registering OMAP3 HWRNG device\n");
platform_device_register(&omap3_rom_rng_device);
}
platform_device_register(&rx51_lirc_device);
}
static void __init omap3_tao3530_legacy_init(void)
{
hsmmc2_internal_input_clk();
}
static void __init omap3_logicpd_torpedo_init(void)
{
omap3_gpio126_127_129();
platform_device_register(&wl128x_device);
platform_device_register(&btwilink_device);
}
static void pandora_wl1251_init_card(struct mmc_card *card)
{
if (card->type == MMC_TYPE_SDIO || card->type == MMC_TYPE_SD_COMBO) {
card->quirks |= MMC_QUIRK_NONSTD_SDIO;
card->cccr.wide_bus = 1;
card->cis.vendor = 0x104c;
card->cis.device = 0x9066;
card->cis.blksize = 512;
card->cis.max_dtr = 24000000;
card->ocr = 0x80;
}
}
static void __init pandora_wl1251_init(void)
{
struct wl1251_platform_data pandora_wl1251_pdata;
int ret;
memset(&pandora_wl1251_pdata, 0, sizeof(pandora_wl1251_pdata));
pandora_wl1251_pdata.power_gpio = -1;
ret = gpio_request_one(PANDORA_WIFI_IRQ_GPIO, GPIOF_IN, "wl1251 irq");
if (ret < 0)
goto fail;
pandora_wl1251_pdata.irq = gpio_to_irq(PANDORA_WIFI_IRQ_GPIO);
if (pandora_wl1251_pdata.irq < 0)
goto fail_irq;
pandora_wl1251_pdata.use_eeprom = true;
ret = wl1251_set_platform_data(&pandora_wl1251_pdata);
if (ret < 0)
goto fail_irq;
return;
fail_irq:
gpio_free(PANDORA_WIFI_IRQ_GPIO);
fail:
pr_err("wl1251 board initialisation failed\n");
}
static void __init omap3_pandora_legacy_init(void)
{
platform_device_register(&pandora_backlight);
platform_device_register(&pandora_vwlan_device);
omap_hsmmc_init(pandora_mmc3);
omap_hsmmc_late_init(pandora_mmc3);
pandora_wl1251_init();
}
static void __init omap5_uevm_legacy_init(void)
{
}
void omap_pcs_legacy_init(int irq, void (*rearm)(void))
{
pcs_pdata.irq = irq;
pcs_pdata.rearm = rearm;
}
void omap_auxdata_legacy_init(struct device *dev)
{
if (dev->platform_data)
return;
if (strcmp("twl4030-gpio", dev_name(dev)))
return;
dev->platform_data = &twl_gpio_auxdata;
}
static void pdata_quirks_check(struct pdata_init *quirks)
{
while (quirks->compatible) {
if (of_machine_is_compatible(quirks->compatible)) {
if (quirks->fn)
quirks->fn();
break;
}
quirks++;
}
}
void __init pdata_quirks_init(const struct of_device_id *omap_dt_match_table)
{
if (of_machine_is_compatible("ti,omap2420") ||
of_machine_is_compatible("ti,omap3"))
omap_sdrc_init(NULL, NULL);
pdata_quirks_check(auxdata_quirks);
of_platform_populate(NULL, omap_dt_match_table,
omap_auxdata_lookup, NULL);
pdata_quirks_check(pdata_quirks);
}
