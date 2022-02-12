static void __init apx4devkit_add_regulators(void)
{
platform_device_register(&apx4devkit_voltage_regulator);
}
static void __init apx4devkit_add_regulators(void) {}
static int apx4devkit_phy_fixup(struct phy_device *phy)
{
phy->dev_flags |= MICREL_PHY_50MHZ_CLK;
return 0;
}
static void __init apx4devkit_fec_phy_clk_enable(void)
{
struct clk *clk;
clk = clk_get_sys("enet_out", NULL);
if (!IS_ERR(clk))
clk_prepare_enable(clk);
}
static void __init apx4devkit_init(void)
{
mx28_soc_init();
mxs_iomux_setup_multiple_pads(apx4devkit_pads,
ARRAY_SIZE(apx4devkit_pads));
mx28_add_duart();
mx28_add_auart0();
mx28_add_auart1();
mx28_add_auart2();
mx28_add_auart3();
phy_register_fixup_for_uid(PHY_ID_KS8051, MICREL_PHY_ID_MASK,
apx4devkit_phy_fixup);
apx4devkit_fec_phy_clk_enable();
mx28_add_fec(0, &mx28_fec_pdata);
mx28_add_mxs_mmc(0, &apx4devkit_mmc_pdata);
gpio_led_register_device(0, &apx4devkit_led_data);
mxs_saif_clkmux_select(MXS_DIGCTL_SAIF_CLKMUX_EXTMSTR0);
mx28_add_saif(0, &apx4devkit_mxs_saif_pdata[0]);
mx28_add_saif(1, &apx4devkit_mxs_saif_pdata[1]);
apx4devkit_add_regulators();
mx28_add_mxs_i2c(0);
i2c_register_board_info(0, apx4devkit_i2c_boardinfo,
ARRAY_SIZE(apx4devkit_i2c_boardinfo));
mxs_add_platform_device("mxs-sgtl5000", 0, NULL, 0, NULL, 0);
}
static void __init apx4devkit_timer_init(void)
{
mx28_clocks_init();
}
