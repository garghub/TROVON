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
static void __init igep_flash_init(void)
{
u8 cs = 0;
u8 onenandcs = GPMC_CS_NUM + 1;
for (cs = 0; cs < GPMC_CS_NUM; cs++) {
u32 ret;
ret = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
if ((ret & 0xC00) == 0x800)
pr_err("IGEP: Unsupported NAND found\n");
else {
ret = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG7);
if ((ret & 0x3F) == (ONENAND_MAP >> 24))
onenandcs = cs;
}
}
if (onenandcs > GPMC_CS_NUM) {
pr_err("IGEP: Unable to find configuration in GPMC\n");
return;
}
igep_onenand_data.cs = onenandcs;
if (platform_device_register(&igep_onenand_device) < 0)
pr_err("IGEP: Unable to register OneNAND device\n");
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
omap2_hsmmc_init(mmc);
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
static int igep2_enable_dvi(struct omap_dss_device *dssdev)
{
gpio_direction_output(IGEP2_GPIO_DVI_PUP, 1);
return 0;
}
static void igep2_disable_dvi(struct omap_dss_device *dssdev)
{
gpio_direction_output(IGEP2_GPIO_DVI_PUP, 0);
}
static void __init igep2_display_init(void)
{
int err = gpio_request_one(IGEP2_GPIO_DVI_PUP, GPIOF_OUT_INIT_HIGH,
"GPIO_DVI_PUP");
if (err)
pr_err("IGEP v2: Could not obtain gpio GPIO_DVI_PUP\n");
}
static void __init igep_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(m65kxxxxam_sdrc_params,
m65kxxxxam_sdrc_params);
}
static void __init igep_i2c_init(void)
{
int ret;
omap3_pmic_get_config(&igep_twldata, TWL_COMMON_PDATA_USB, 0);
if (machine_is_igep0020()) {
ret = omap_register_i2c_bus(3, 100, igep2_i2c3_boardinfo,
ARRAY_SIZE(igep2_i2c3_boardinfo));
if (ret)
pr_warning("IGEP2: Could not register I2C3 bus (%d)\n", ret);
igep_twldata.keypad = &igep2_keypad_pdata;
omap3_pmic_get_config(&igep_twldata, TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VPLL2);
igep_twldata.vpll2->constraints.apply_uV = true;
igep_twldata.vpll2->constraints.name = "VDVI";
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
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
igep2_get_revision();
igep_i2c_init();
platform_add_devices(igep_devices, ARRAY_SIZE(igep_devices));
omap_serial_init();
usb_musb_init(NULL);
igep_flash_init();
igep_leds_init();
igep_wlan_bt_init();
if (machine_is_igep0020()) {
omap_display_init(&igep2_dss_data);
igep2_display_init();
igep2_init_smsc911x();
usbhs_init(&igep2_usbhs_bdata);
} else {
usbhs_init(&igep3_usbhs_bdata);
}
}
