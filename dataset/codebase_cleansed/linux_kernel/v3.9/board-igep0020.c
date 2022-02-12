static void __init igep2_get_revision(void)
{
u8 ret;
if (machine_is_igep0030()) {
hwrev = IGEP3_BOARD_HWREV;
return;
}
omap_mux_init_gpio(IGEP2_GPIO_LED1_RED, OMAP_PIN_INPUT);
if (gpio_request_one(IGEP2_GPIO_LED1_RED, GPIOF_IN, "GPIO_HW0_REV")) {
pr_warning("IGEP2: Could not obtain gpio GPIO_HW0_REV\n");
pr_err("IGEP2: Unknown Hardware Revision\n");
return;
}
ret = gpio_get_value(IGEP2_GPIO_LED1_RED);
if (ret == 0) {
pr_info("IGEP2: Hardware Revision C (B-NON compatible)\n");
hwrev = IGEP2_BOARD_HWREV_C;
} else if (ret == 1) {
pr_info("IGEP2: Hardware Revision B/C (B compatible)\n");
hwrev = IGEP2_BOARD_HWREV_B;
} else {
pr_err("IGEP2: Unknown Hardware Revision\n");
hwrev = -1;
}
gpio_free(IGEP2_GPIO_LED1_RED);
}
static inline u32 igep_get_sysboot_value(void)
{
return omap_ctrl_readl(OMAP343X_CONTROL_STATUS) & IGEP_SYSBOOT_MASK;
}
static void __init igep_flash_init(void)
{
u32 mux;
mux = igep_get_sysboot_value();
if (mux == IGEP_SYSBOOT_NAND) {
pr_info("IGEP: initializing NAND memory device\n");
board_nand_init(igep_flash_partitions,
ARRAY_SIZE(igep_flash_partitions),
0, NAND_BUSWIDTH_16, nand_default_timings);
} else if (mux == IGEP_SYSBOOT_ONENAND) {
pr_info("IGEP: initializing OneNAND memory device\n");
board_onenand_init(igep_flash_partitions,
ARRAY_SIZE(igep_flash_partitions), 0);
} else {
pr_err("IGEP: Flash: unsupported sysboot sequence found\n");
}
}
static void __init igep_flash_init(void) {}
static inline void __init igep2_init_smsc911x(void)
{
gpmc_smsc911x_init(&smsc911x_cfg);
}
static inline void __init igep2_init_smsc911x(void) { }
static void __init igep_leds_init(void)
{
if (machine_is_igep0020()) {
igep_gpio_leds[0].gpio = IGEP2_GPIO_LED0_RED;
igep_gpio_leds[1].gpio = IGEP2_GPIO_LED0_GREEN;
igep_gpio_leds[2].gpio = IGEP2_GPIO_LED1_RED;
} else {
igep_gpio_leds[0].gpio = IGEP3_GPIO_LED0_RED;
igep_gpio_leds[1].gpio = IGEP3_GPIO_LED0_GREEN;
igep_gpio_leds[2].gpio = IGEP3_GPIO_LED1_RED;
}
platform_device_register(&igep_led_device);
}
static inline void igep_leds_init(void)
{
int i;
if (machine_is_igep0020()) {
igep_gpio_leds[0].gpio = IGEP2_GPIO_LED0_RED;
igep_gpio_leds[1].gpio = IGEP2_GPIO_LED0_GREEN;
igep_gpio_leds[2].gpio = IGEP2_GPIO_LED1_RED;
} else {
igep_gpio_leds[0].gpio = IGEP3_GPIO_LED0_RED;
igep_gpio_leds[1].gpio = IGEP3_GPIO_LED0_GREEN;
igep_gpio_leds[2].gpio = IGEP3_GPIO_LED1_RED;
}
if (gpio_request_array(igep_gpio_leds, ARRAY_SIZE(igep_gpio_leds))) {
pr_warning("IGEP v2: Could not obtain leds gpios\n");
return;
}
for (i = 0; i < ARRAY_SIZE(igep_gpio_leds); i++)
gpio_export(igep_gpio_leds[i].gpio, 0);
}
static int igep_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
int ret;
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
#if !defined(CONFIG_LEDS_GPIO) && !defined(CONFIG_LEDS_GPIO_MODULE)
ret = gpio_request_one(gpio + TWL4030_GPIO_MAX + 1, GPIOF_OUT_INIT_HIGH,
"gpio-led:green:d1");
if (ret == 0)
gpio_export(gpio + TWL4030_GPIO_MAX + 1, 0);
else
pr_warning("IGEP: Could not obtain gpio GPIO_LED1_GREEN\n");
#else
igep_gpio_leds[3].gpio = gpio + TWL4030_GPIO_MAX + 1;
#endif
if (machine_is_igep0030())
return 0;
igep2_twl_gpios[0].gpio = gpio + 1;
igep2_twl_gpios[1].gpio = gpio + TWL4030_GPIO_MAX;
ret = gpio_request_array(igep2_twl_gpios, ARRAY_SIZE(igep2_twl_gpios));
if (ret < 0)
pr_err("IGEP2: Could not obtain gpio for USBH_CPEN");
return 0;
}
static void __init igep_i2c_init(void)
{
int ret;
omap3_pmic_get_config(&igep_twldata, TWL_COMMON_PDATA_USB,
TWL_COMMON_REGULATOR_VPLL2);
igep_twldata.vpll2->constraints.apply_uV = true;
igep_twldata.vpll2->constraints.name = "VDVI";
if (machine_is_igep0020()) {
ret = omap_register_i2c_bus(3, 100, igep2_i2c3_boardinfo,
ARRAY_SIZE(igep2_i2c3_boardinfo));
if (ret)
pr_warning("IGEP2: Could not register I2C3 bus (%d)\n", ret);
igep_twldata.keypad = &igep2_keypad_pdata;
omap3_pmic_get_config(&igep_twldata, TWL_COMMON_PDATA_AUDIO, 0);
}
omap3_pmic_init("twl4030", &igep_twldata);
}
static void __init igep_wlan_bt_init(void)
{
int err;
if (hwrev == IGEP2_BOARD_HWREV_B) {
igep_wlan_bt_gpios[0].gpio = IGEP2_RB_GPIO_WIFI_NPD;
igep_wlan_bt_gpios[1].gpio = IGEP2_RB_GPIO_WIFI_NRESET;
igep_wlan_bt_gpios[2].gpio = IGEP2_RB_GPIO_BT_NRESET;
} else if (hwrev == IGEP2_BOARD_HWREV_C || machine_is_igep0030()) {
igep_wlan_bt_gpios[0].gpio = IGEP2_RC_GPIO_WIFI_NPD;
igep_wlan_bt_gpios[1].gpio = IGEP2_RC_GPIO_WIFI_NRESET;
igep_wlan_bt_gpios[2].gpio = IGEP2_RC_GPIO_BT_NRESET;
} else
return;
omap_mux_init_gpio(igep_wlan_bt_gpios[0].gpio, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(igep_wlan_bt_gpios[1].gpio, OMAP_PIN_OUTPUT);
omap_mux_init_gpio(igep_wlan_bt_gpios[2].gpio, OMAP_PIN_OUTPUT);
err = gpio_request_array(igep_wlan_bt_gpios,
ARRAY_SIZE(igep_wlan_bt_gpios));
if (err) {
pr_warning("IGEP2: Could not obtain WIFI/BT gpios\n");
return;
}
gpio_export(igep_wlan_bt_gpios[0].gpio, 0);
gpio_export(igep_wlan_bt_gpios[1].gpio, 0);
gpio_export(igep_wlan_bt_gpios[2].gpio, 0);
gpio_set_value(igep_wlan_bt_gpios[1].gpio, 0);
udelay(10);
gpio_set_value(igep_wlan_bt_gpios[1].gpio, 1);
}
static inline void __init igep_wlan_bt_init(void) { }
static void __init igep_init(void)
{
regulator_register_fixed(1, dummy_supplies, ARRAY_SIZE(dummy_supplies));
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
igep2_get_revision();
omap_hsmmc_init(mmc);
igep_i2c_init();
platform_add_devices(igep_devices, ARRAY_SIZE(igep_devices));
omap_serial_init();
omap_sdrc_init(m65kxxxxam_sdrc_params,
m65kxxxxam_sdrc_params);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
igep_flash_init();
igep_leds_init();
omap_twl4030_audio_init("igep2", NULL);
igep_wlan_bt_init();
if (machine_is_igep0020()) {
omap_display_init(&igep2_dss_data);
igep2_init_smsc911x();
usbhs_init(&igep2_usbhs_bdata);
} else {
usbhs_init(&igep3_usbhs_bdata);
}
}
