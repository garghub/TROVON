static void __init mx28evk_fec_reset(void)
{
int ret;
struct clk *clk;
clk = clk_get_sys("pll2", NULL);
if (!IS_ERR(clk))
clk_prepare_enable(clk);
ret = gpio_request(MX28EVK_FEC_PHY_POWER, "fec-phy-power");
if (ret) {
pr_err("Failed to request gpio fec-phy-%s: %d\n", "power", ret);
return;
}
ret = gpio_direction_output(MX28EVK_FEC_PHY_POWER, 0);
if (ret) {
pr_err("Failed to drive gpio fec-phy-%s: %d\n", "power", ret);
return;
}
ret = gpio_request(MX28EVK_FEC_PHY_RESET, "fec-phy-reset");
if (ret) {
pr_err("Failed to request gpio fec-phy-%s: %d\n", "reset", ret);
return;
}
gpio_direction_output(MX28EVK_FEC_PHY_RESET, 0);
if (ret) {
pr_err("Failed to drive gpio fec-phy-%s: %d\n", "reset", ret);
return;
}
mdelay(1);
gpio_set_value(MX28EVK_FEC_PHY_RESET, 1);
}
static int __init mx28evk_fec_get_mac(void)
{
int i;
u32 val;
const u32 *ocotp = mxs_get_ocotp();
if (!ocotp)
goto error;
for (i = 0; i < 2; i++) {
val = ocotp[i * 4];
mx28_fec_pdata[i].mac[0] = 0x00;
mx28_fec_pdata[i].mac[1] = 0x04;
mx28_fec_pdata[i].mac[2] = 0x9f;
mx28_fec_pdata[i].mac[3] = (val >> 16) & 0xff;
mx28_fec_pdata[i].mac[4] = (val >> 8) & 0xff;
mx28_fec_pdata[i].mac[5] = (val >> 0) & 0xff;
}
return 0;
error:
pr_err("%s: timeout when reading fec mac from OCOTP\n", __func__);
return -ETIMEDOUT;
}
static void mx28evk_flexcan_switch(void)
{
if (flexcan0_en || flexcan1_en)
gpio_set_value(MX28EVK_FLEXCAN_SWITCH, 1);
else
gpio_set_value(MX28EVK_FLEXCAN_SWITCH, 0);
}
static void mx28evk_flexcan0_switch(int enable)
{
flexcan0_en = enable;
mx28evk_flexcan_switch();
}
static void mx28evk_flexcan1_switch(int enable)
{
flexcan1_en = enable;
mx28evk_flexcan_switch();
}
static void __init mx28evk_add_regulators(void)
{
platform_device_register(&mx28evk_voltage_regulator);
}
static void __init mx28evk_add_regulators(void) {}
static void __init mx28evk_init(void)
{
int ret;
mxs_iomux_setup_multiple_pads(mx28evk_pads, ARRAY_SIZE(mx28evk_pads));
mx28_add_duart();
mx28_add_auart0();
mx28_add_auart3();
if (mx28evk_fec_get_mac())
pr_warn("%s: failed on fec mac setup\n", __func__);
mx28evk_fec_reset();
mx28_add_fec(0, &mx28_fec_pdata[0]);
mx28_add_fec(1, &mx28_fec_pdata[1]);
ret = gpio_request_one(MX28EVK_FLEXCAN_SWITCH, GPIOF_DIR_OUT,
"flexcan-switch");
if (ret) {
pr_err("failed to request gpio flexcan-switch: %d\n", ret);
} else {
mx28_add_flexcan(0, &mx28evk_flexcan_pdata[0]);
mx28_add_flexcan(1, &mx28evk_flexcan_pdata[1]);
}
ret = gpio_request_array(mx28evk_lcd_gpios,
ARRAY_SIZE(mx28evk_lcd_gpios));
if (ret)
pr_warn("failed to request gpio pins for lcd: %d\n", ret);
else
mx28_add_mxsfb(&mx28evk_mxsfb_pdata);
mxs_saif_clkmux_select(MXS_DIGCTL_SAIF_CLKMUX_EXTMSTR0);
mx28_add_saif(0, &mx28evk_mxs_saif_pdata[0]);
mx28_add_saif(1, &mx28evk_mxs_saif_pdata[1]);
mx28_add_mxs_i2c(0);
i2c_register_board_info(0, mxs_i2c0_board_info,
ARRAY_SIZE(mxs_i2c0_board_info));
mx28evk_add_regulators();
mxs_add_platform_device("mxs-sgtl5000", 0, NULL, 0,
NULL, 0);
ret = gpio_request_one(MX28EVK_MMC0_SLOT_POWER, GPIOF_OUT_INIT_LOW,
"mmc0-slot-power");
if (ret)
pr_warn("failed to request gpio mmc0-slot-power: %d\n", ret);
else
mx28_add_mxs_mmc(0, &mx28evk_mmc_pdata[0]);
ret = gpio_request_one(MX28EVK_MMC1_SLOT_POWER, GPIOF_OUT_INIT_LOW,
"mmc1-slot-power");
if (ret)
pr_warn("failed to request gpio mmc1-slot-power: %d\n", ret);
else
mx28_add_mxs_mmc(1, &mx28evk_mmc_pdata[1]);
mx28_add_rtc_stmp3xxx();
gpio_led_register_device(0, &mx28evk_led_data);
}
static void __init mx28evk_timer_init(void)
{
mx28_clocks_init();
}
