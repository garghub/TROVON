static void da850_evm_m25p80_notify_add(struct mtd_info *mtd)
{
char *mac_addr = davinci_soc_info.emac_pdata->mac_addr;
size_t retlen;
if (!strcmp(mtd->name, "MAC-Address")) {
mtd_read(mtd, 0, ETH_ALEN, &retlen, mac_addr);
if (retlen == ETH_ALEN)
pr_info("Read MAC addr from SPI Flash: %pM\n",
mac_addr);
}
}
static void da850_evm_setup_mac_addr(void)
{
register_mtd_user(&da850evm_spi_notifier);
}
static void da850_evm_setup_mac_addr(void) { }
static void __init da850_evm_init_nor(void)
{
void __iomem *aemif_addr;
aemif_addr = ioremap(DA8XX_AEMIF_CTL_BASE, SZ_32K);
writel(readl(aemif_addr + DA8XX_AEMIF_CE2CFG_OFFSET) |
DA8XX_AEMIF_ASIZE_16BIT,
aemif_addr + DA8XX_AEMIF_CE2CFG_OFFSET);
iounmap(aemif_addr);
}
static inline void da850_evm_setup_nor_nand(void)
{
int ret = 0;
if (!HAS_MMC) {
ret = davinci_cfg_reg_list(da850_evm_nand_pins);
if (ret)
pr_warn("%s: NAND mux setup failed: %d\n",
__func__, ret);
ret = davinci_cfg_reg_list(da850_evm_nor_pins);
if (ret)
pr_warn("%s: NOR mux setup failed: %d\n",
__func__, ret);
da850_evm_init_nor();
platform_add_devices(da850_evm_devices,
ARRAY_SIZE(da850_evm_devices));
if (davinci_aemif_setup(&da850_evm_nandflash_device))
pr_warn("%s: Cannot configure AEMIF.\n", __func__);
}
}
static inline void da850_evm_setup_emac_rmii(int rmii_sel)
{
struct davinci_soc_info *soc_info = &davinci_soc_info;
soc_info->emac_pdata->rmii_en = 1;
gpio_set_value_cansleep(rmii_sel, 0);
}
static inline void da850_evm_setup_emac_rmii(int rmii_sel) { }
static void da850_evm_ui_keys_init(unsigned gpio)
{
int i;
struct gpio_keys_button *button;
for (i = 0; i < DA850_N_UI_PB; i++) {
button = &da850_evm_ui_keys[i];
button->code = KEY_F8 - i;
button->desc = (char *)
da850_evm_ui_exp[DA850_EVM_UI_EXP_PB8 + i];
button->gpio = gpio + DA850_EVM_UI_EXP_PB8 + i;
}
}
static inline void da850_evm_setup_video_port(int video_sel)
{
gpio_set_value_cansleep(video_sel, 0);
}
static inline void da850_evm_setup_video_port(int video_sel) { }
static int da850_evm_ui_expander_setup(struct i2c_client *client, unsigned gpio,
unsigned ngpio, void *c)
{
int sel_a, sel_b, sel_c, ret;
sel_a = gpio + DA850_EVM_UI_EXP_SEL_A;
sel_b = gpio + DA850_EVM_UI_EXP_SEL_B;
sel_c = gpio + DA850_EVM_UI_EXP_SEL_C;
ret = gpio_request(sel_a, da850_evm_ui_exp[DA850_EVM_UI_EXP_SEL_A]);
if (ret) {
pr_warn("Cannot open UI expander pin %d\n", sel_a);
goto exp_setup_sela_fail;
}
ret = gpio_request(sel_b, da850_evm_ui_exp[DA850_EVM_UI_EXP_SEL_B]);
if (ret) {
pr_warn("Cannot open UI expander pin %d\n", sel_b);
goto exp_setup_selb_fail;
}
ret = gpio_request(sel_c, da850_evm_ui_exp[DA850_EVM_UI_EXP_SEL_C]);
if (ret) {
pr_warn("Cannot open UI expander pin %d\n", sel_c);
goto exp_setup_selc_fail;
}
gpio_direction_output(sel_a, 1);
gpio_direction_output(sel_b, 1);
gpio_direction_output(sel_c, 1);
da850_evm_ui_keys_init(gpio);
ret = platform_device_register(&da850_evm_ui_keys_device);
if (ret) {
pr_warn("Could not register UI GPIO expander push-buttons");
goto exp_setup_keys_fail;
}
pr_info("DA850/OMAP-L138 EVM UI card detected\n");
da850_evm_setup_nor_nand();
da850_evm_setup_emac_rmii(sel_a);
da850_evm_setup_video_port(sel_c);
return 0;
exp_setup_keys_fail:
gpio_free(sel_c);
exp_setup_selc_fail:
gpio_free(sel_b);
exp_setup_selb_fail:
gpio_free(sel_a);
exp_setup_sela_fail:
return ret;
}
static int da850_evm_ui_expander_teardown(struct i2c_client *client,
unsigned gpio, unsigned ngpio, void *c)
{
platform_device_unregister(&da850_evm_ui_keys_device);
gpio_set_value_cansleep(gpio + DA850_EVM_UI_EXP_SEL_C, 1);
gpio_set_value_cansleep(gpio + DA850_EVM_UI_EXP_SEL_B, 1);
gpio_set_value_cansleep(gpio + DA850_EVM_UI_EXP_SEL_A, 1);
gpio_free(gpio + DA850_EVM_UI_EXP_SEL_C);
gpio_free(gpio + DA850_EVM_UI_EXP_SEL_B);
gpio_free(gpio + DA850_EVM_UI_EXP_SEL_A);
return 0;
}
static void da850_evm_bb_keys_init(unsigned gpio)
{
int i;
struct gpio_keys_button *button;
button = &da850_evm_bb_keys[0];
button->desc = (char *)
da850_evm_bb_exp[DA850_EVM_BB_EXP_USER_PB1];
button->gpio = gpio + DA850_EVM_BB_EXP_USER_PB1;
for (i = 0; i < DA850_N_BB_USER_SW; i++) {
button = &da850_evm_bb_keys[i + 1];
button->code = SW_LID + i;
button->desc = (char *)
da850_evm_bb_exp[DA850_EVM_BB_EXP_USER_SW1 + i];
button->gpio = gpio + DA850_EVM_BB_EXP_USER_SW1 + i;
}
}
static void da850_evm_bb_leds_init(unsigned gpio)
{
int i;
struct gpio_led *led;
for (i = 0; i < DA850_N_BB_USER_LED; i++) {
led = &da850_evm_bb_leds[i];
led->gpio = gpio + DA850_EVM_BB_EXP_USER_LED2 + i;
led->name =
da850_evm_bb_exp[DA850_EVM_BB_EXP_USER_LED2 + i];
}
}
static int da850_evm_bb_expander_setup(struct i2c_client *client,
unsigned gpio, unsigned ngpio,
void *c)
{
int ret;
da850_evm_bb_keys_init(gpio);
ret = platform_device_register(&da850_evm_bb_keys_device);
if (ret) {
pr_warn("Could not register baseboard GPIO expander keys");
goto io_exp_setup_sw_fail;
}
da850_evm_bb_leds_init(gpio);
ret = platform_device_register(&da850_evm_bb_leds_device);
if (ret) {
pr_warn("Could not register baseboard GPIO expander LEDs");
goto io_exp_setup_leds_fail;
}
return 0;
io_exp_setup_leds_fail:
platform_device_unregister(&da850_evm_bb_keys_device);
io_exp_setup_sw_fail:
return ret;
}
static int da850_evm_bb_expander_teardown(struct i2c_client *client,
unsigned gpio, unsigned ngpio, void *c)
{
platform_device_unregister(&da850_evm_bb_leds_device);
platform_device_unregister(&da850_evm_bb_keys_device);
return 0;
}
static int da850_evm_mmc_get_ro(int index)
{
return gpio_get_value(DA850_MMCSD_WP_PIN);
}
static int da850_evm_mmc_get_cd(int index)
{
return !gpio_get_value(DA850_MMCSD_CD_PIN);
}
static void da850_panel_power_ctrl(int val)
{
gpio_set_value(DA850_LCD_BL_PIN, val);
gpio_set_value(DA850_LCD_PWR_PIN, val);
}
static int da850_lcd_hw_init(void)
{
int status;
status = gpio_request(DA850_LCD_BL_PIN, "lcd bl\n");
if (status < 0)
return status;
status = gpio_request(DA850_LCD_PWR_PIN, "lcd pwr\n");
if (status < 0) {
gpio_free(DA850_LCD_BL_PIN);
return status;
}
gpio_direction_output(DA850_LCD_BL_PIN, 0);
gpio_direction_output(DA850_LCD_PWR_PIN, 0);
da850_panel_power_ctrl(0);
da850_panel_power_ctrl(1);
return 0;
}
static int __init pmic_tps65070_init(void)
{
return i2c_register_board_info(1, da850_evm_tps65070_info,
ARRAY_SIZE(da850_evm_tps65070_info));
}
static int __init da850_evm_config_emac(void)
{
void __iomem *cfg_chip3_base;
int ret;
u32 val;
struct davinci_soc_info *soc_info = &davinci_soc_info;
u8 rmii_en = soc_info->emac_pdata->rmii_en;
if (!machine_is_davinci_da850_evm())
return 0;
cfg_chip3_base = DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG);
val = __raw_readl(cfg_chip3_base);
if (rmii_en) {
val |= BIT(8);
ret = davinci_cfg_reg_list(da850_evm_rmii_pins);
pr_info("EMAC: RMII PHY configured, MII PHY will not be"
" functional\n");
} else {
val &= ~BIT(8);
ret = davinci_cfg_reg_list(da850_evm_mii_pins);
pr_info("EMAC: MII PHY configured, RMII PHY will not be"
" functional\n");
}
if (ret)
pr_warn("%s: CPGMAC/RMII mux setup failed: %d\n",
__func__, ret);
__raw_writel(val, cfg_chip3_base);
ret = davinci_cfg_reg(DA850_GPIO2_6);
if (ret)
pr_warn("%s:GPIO(2,6) mux setup failed\n", __func__);
ret = gpio_request(DA850_MII_MDIO_CLKEN_PIN, "mdio_clk_en");
if (ret) {
pr_warn("Cannot open GPIO %d\n", DA850_MII_MDIO_CLKEN_PIN);
return ret;
}
gpio_direction_output(DA850_MII_MDIO_CLKEN_PIN, rmii_en);
soc_info->emac_pdata->phy_id = DA850_EVM_PHY_ID;
ret = da8xx_register_emac();
if (ret)
pr_warn("%s: EMAC registration failed: %d\n", __func__, ret);
return 0;
}
static __init int da850_evm_init_cpufreq(void)
{
switch (system_rev & 0xF) {
case 3:
da850_max_speed = 456000;
break;
case 2:
da850_max_speed = 408000;
break;
case 1:
da850_max_speed = 372000;
break;
}
return da850_register_cpufreq("pll0_sysclk3");
}
static __init int da850_evm_init_cpufreq(void) { return 0; }
static __init void da850_vpif_init(void)
{
int ret;
ret = da850_register_vpif();
if (ret)
pr_warn("da850_evm_init: VPIF setup failed: %d\n", ret);
ret = davinci_cfg_reg_list(da850_vpif_capture_pins);
if (ret)
pr_warn("da850_evm_init: VPIF capture mux setup failed: %d\n",
ret);
ret = da850_register_vpif_capture(&da850_vpif_capture_config);
if (ret)
pr_warn("da850_evm_init: VPIF capture setup failed: %d\n", ret);
ret = davinci_cfg_reg_list(da850_vpif_display_pins);
if (ret)
pr_warn("da850_evm_init: VPIF display mux setup failed: %d\n",
ret);
ret = da850_register_vpif_display(&da850_vpif_display_config);
if (ret)
pr_warn("da850_evm_init: VPIF display setup failed: %d\n", ret);
}
static __init void da850_vpif_init(void) {}
static void wl12xx_set_power(int index, bool power_on)
{
static bool power_state;
pr_debug("Powering %s wl12xx", power_on ? "on" : "off");
if (power_on == power_state)
return;
power_state = power_on;
if (power_on) {
gpio_set_value(DA850_WLAN_EN, 1);
usleep_range(15000, 15000);
gpio_set_value(DA850_WLAN_EN, 0);
usleep_range(1000, 1000);
gpio_set_value(DA850_WLAN_EN, 1);
msleep(70);
} else {
gpio_set_value(DA850_WLAN_EN, 0);
}
}
static __init int da850_wl12xx_init(void)
{
int ret;
ret = davinci_cfg_reg_list(da850_wl12xx_pins);
if (ret) {
pr_err("wl12xx/mmc mux setup failed: %d\n", ret);
goto exit;
}
ret = da850_register_mmcsd1(&da850_wl12xx_mmc_config);
if (ret) {
pr_err("wl12xx/mmc registration failed: %d\n", ret);
goto exit;
}
ret = gpio_request_one(DA850_WLAN_EN, GPIOF_OUT_INIT_LOW, "wl12xx_en");
if (ret) {
pr_err("Could not request wl12xx enable gpio: %d\n", ret);
goto exit;
}
ret = gpio_request_one(DA850_WLAN_IRQ, GPIOF_IN, "wl12xx_irq");
if (ret) {
pr_err("Could not request wl12xx irq gpio: %d\n", ret);
goto free_wlan_en;
}
da850_wl12xx_wlan_data.irq = gpio_to_irq(DA850_WLAN_IRQ);
ret = wl12xx_set_platform_data(&da850_wl12xx_wlan_data);
if (ret) {
pr_err("Could not set wl12xx data: %d\n", ret);
goto free_wlan_irq;
}
return 0;
free_wlan_irq:
gpio_free(DA850_WLAN_IRQ);
free_wlan_en:
gpio_free(DA850_WLAN_EN);
exit:
return ret;
}
static __init int da850_wl12xx_init(void)
{
return 0;
}
static __init void da850_evm_init(void)
{
int ret;
ret = da850_register_gpio();
if (ret)
pr_warn("%s: GPIO init failed: %d\n", __func__, ret);
regulator_register_fixed(0, fixed_supplies, ARRAY_SIZE(fixed_supplies));
ret = pmic_tps65070_init();
if (ret)
pr_warn("%s: TPS65070 PMIC init failed: %d\n", __func__, ret);
ret = da850_register_edma(da850_edma_rsv);
if (ret)
pr_warn("%s: EDMA registration failed: %d\n", __func__, ret);
ret = davinci_cfg_reg_list(da850_i2c0_pins);
if (ret)
pr_warn("%s: I2C0 mux setup failed: %d\n", __func__, ret);
ret = da8xx_register_i2c(0, &da850_evm_i2c_0_pdata);
if (ret)
pr_warn("%s: I2C0 registration failed: %d\n", __func__, ret);
ret = da8xx_register_watchdog();
if (ret)
pr_warn("%s: watchdog registration failed: %d\n",
__func__, ret);
if (HAS_MMC) {
ret = davinci_cfg_reg_list(da850_evm_mmcsd0_pins);
if (ret)
pr_warn("%s: MMCSD0 mux setup failed: %d\n",
__func__, ret);
ret = gpio_request(DA850_MMCSD_CD_PIN, "MMC CD\n");
if (ret)
pr_warn("%s: can not open GPIO %d\n",
__func__, DA850_MMCSD_CD_PIN);
gpio_direction_input(DA850_MMCSD_CD_PIN);
ret = gpio_request(DA850_MMCSD_WP_PIN, "MMC WP\n");
if (ret)
pr_warn("%s: can not open GPIO %d\n",
__func__, DA850_MMCSD_WP_PIN);
gpio_direction_input(DA850_MMCSD_WP_PIN);
ret = da8xx_register_mmcsd0(&da850_mmc_config);
if (ret)
pr_warn("%s: MMCSD0 registration failed: %d\n",
__func__, ret);
ret = da850_wl12xx_init();
if (ret)
pr_warn("%s: WL12xx initialization failed: %d\n",
__func__, ret);
}
davinci_serial_init(da8xx_serial_device);
i2c_register_board_info(1, da850_evm_i2c_devices,
ARRAY_SIZE(da850_evm_i2c_devices));
__raw_writel(0, IO_ADDRESS(DA8XX_UART1_BASE) + 0x30);
__raw_writel(0, IO_ADDRESS(DA8XX_UART0_BASE) + 0x30);
ret = davinci_cfg_reg_list(da850_evm_mcasp_pins);
if (ret)
pr_warn("%s: McASP mux setup failed: %d\n", __func__, ret);
da850_evm_snd_data.sram_pool = sram_get_gen_pool();
da8xx_register_mcasp(0, &da850_evm_snd_data);
ret = davinci_cfg_reg_list(da850_lcdcntl_pins);
if (ret)
pr_warn("%s: LCDC mux setup failed: %d\n", __func__, ret);
ret = da8xx_register_uio_pruss();
if (ret)
pr_warn("da850_evm_init: pruss initialization failed: %d\n",
ret);
ret = davinci_cfg_reg_list(da850_evm_lcdc_pins);
if (ret)
pr_warn("%s: EVM specific LCD mux setup failed: %d\n",
__func__, ret);
ret = da850_lcd_hw_init();
if (ret)
pr_warn("%s: LCD initialization failed: %d\n", __func__, ret);
sharp_lk043t1dg01_pdata.panel_power_ctrl = da850_panel_power_ctrl,
ret = da8xx_register_lcdc(&sharp_lk043t1dg01_pdata);
if (ret)
pr_warn("%s: LCDC registration failed: %d\n", __func__, ret);
ret = da8xx_register_rtc();
if (ret)
pr_warn("%s: RTC setup failed: %d\n", __func__, ret);
ret = da850_evm_init_cpufreq();
if (ret)
pr_warn("%s: cpufreq registration failed: %d\n", __func__, ret);
ret = da8xx_register_cpuidle();
if (ret)
pr_warn("%s: cpuidle registration failed: %d\n", __func__, ret);
ret = da850_register_pm(&da850_pm_device);
if (ret)
pr_warn("%s: suspend registration failed: %d\n", __func__, ret);
da850_vpif_init();
ret = spi_register_board_info(da850evm_spi_info,
ARRAY_SIZE(da850evm_spi_info));
if (ret)
pr_warn("%s: spi info registration failed: %d\n", __func__,
ret);
ret = da8xx_register_spi_bus(1, ARRAY_SIZE(da850evm_spi_info));
if (ret)
pr_warn("%s: SPI 1 registration failed: %d\n", __func__, ret);
ret = da850_register_sata(DA850EVM_SATA_REFCLKPN_RATE);
if (ret)
pr_warn("%s: SATA registration failed: %d\n", __func__, ret);
da850_evm_setup_mac_addr();
ret = da8xx_register_rproc();
if (ret)
pr_warn("%s: dsp/rproc registration failed: %d\n",
__func__, ret);
}
static int __init da850_evm_console_init(void)
{
if (!machine_is_davinci_da850_evm())
return 0;
return add_preferred_console("ttyS", 2, "115200");
}
static void __init da850_evm_map_io(void)
{
da850_init();
}
