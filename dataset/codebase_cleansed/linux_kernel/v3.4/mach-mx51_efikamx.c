static void __init mx51_efikamx_board_id(void)
{
int id;
msleep(150);
gpio_request(EFIKAMX_PCBID0, "pcbid0");
gpio_direction_input(EFIKAMX_PCBID0);
gpio_request(EFIKAMX_PCBID1, "pcbid1");
gpio_direction_input(EFIKAMX_PCBID1);
gpio_request(EFIKAMX_PCBID2, "pcbid2");
gpio_direction_input(EFIKAMX_PCBID2);
id = gpio_get_value(EFIKAMX_PCBID0) ? 1 : 0;
id |= (gpio_get_value(EFIKAMX_PCBID1) ? 1 : 0) << 1;
id |= (gpio_get_value(EFIKAMX_PCBID2) ? 1 : 0) << 2;
switch (id) {
case 7:
system_rev = 0x11;
break;
case 6:
system_rev = 0x12;
break;
case 5:
system_rev = 0x13;
break;
case 4:
system_rev = 0x14;
break;
default:
system_rev = 0x10;
break;
}
if ((system_rev == 0x10)
|| (system_rev == 0x12)
|| (system_rev == 0x14)) {
printk(KERN_WARNING
"EfikaMX: Unsupported board revision 1.%u!\n",
system_rev & 0xf);
}
}
static void mx51_efikamx_restart(char mode, const char *cmd)
{
if (system_rev == 0x11)
gpio_direction_output(EFIKAMX_RESET1_1, 0);
else
gpio_direction_output(EFIKAMX_RESET, 0);
}
static void mx51_efikamx_power_off(void)
{
if (!IS_ERR(coincell))
regulator_disable(coincell);
if (!IS_ERR(pwgt1) && !IS_ERR(pwgt2)) {
regulator_disable(pwgt2);
regulator_disable(pwgt1);
}
gpio_direction_output(EFIKAMX_POWEROFF, 1);
}
static int __init mx51_efikamx_power_init(void)
{
if (machine_is_mx51_efikamx()) {
pwgt1 = regulator_get(NULL, "pwgt1");
pwgt2 = regulator_get(NULL, "pwgt2");
if (!IS_ERR(pwgt1) && !IS_ERR(pwgt2)) {
regulator_enable(pwgt1);
regulator_enable(pwgt2);
}
gpio_request(EFIKAMX_POWEROFF, "poweroff");
pm_power_off = mx51_efikamx_power_off;
coincell = regulator_get(NULL, "coincell");
if (!IS_ERR(coincell)) {
regulator_set_voltage(coincell, 3000000, 3000000);
regulator_enable(coincell);
}
regulator_has_full_constraints();
}
return 0;
}
static void __init mx51_efikamx_init(void)
{
imx51_soc_init();
mxc_iomux_v3_setup_multiple_pads(mx51efikamx_pads,
ARRAY_SIZE(mx51efikamx_pads));
efika_board_common_init();
mx51_efikamx_board_id();
if (system_rev < 0x12) {
imx51_add_sdhci_esdhc_imx(0, NULL);
imx51_add_sdhci_esdhc_imx(1, &sd_pdata);
mx51_efikamx_leds[2].default_trigger = "mmc1";
} else
imx51_add_sdhci_esdhc_imx(0, &sd_pdata);
gpio_led_register_device(-1, &mx51_efikamx_leds_data);
imx_add_gpio_keys(&mx51_efikamx_powerkey_data);
if (system_rev == 0x11) {
gpio_request(EFIKAMX_RESET1_1, "reset");
gpio_direction_output(EFIKAMX_RESET1_1, 1);
} else {
gpio_request(EFIKAMX_RESET, "reset");
gpio_direction_output(EFIKAMX_RESET, 1);
}
gpio_request(EFIKA_WLAN_EN, "wlan_en");
gpio_direction_output(EFIKA_WLAN_EN, 0);
msleep(10);
gpio_request(EFIKA_WLAN_RESET, "wlan_rst");
gpio_direction_output(EFIKA_WLAN_RESET, 0);
msleep(10);
gpio_set_value(EFIKA_WLAN_RESET, 1);
}
static void __init mx51_efikamx_timer_init(void)
{
mx51_clocks_init(32768, 24000000, 22579200, 24576000);
}
