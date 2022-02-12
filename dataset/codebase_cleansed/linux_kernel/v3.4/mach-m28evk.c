static int __init m28evk_fec_get_mac(void)
{
int i;
u32 val;
const u32 *ocotp = mxs_get_ocotp();
if (!ocotp)
return -ETIMEDOUT;
for (i = 0; i < 2; i++) {
val = ocotp[i];
mx28_fec_pdata[i].mac[0] = 0xC0;
mx28_fec_pdata[i].mac[1] = 0xE5;
mx28_fec_pdata[i].mac[2] = 0x4E;
mx28_fec_pdata[i].mac[3] = (val >> 16) & 0xff;
mx28_fec_pdata[i].mac[4] = (val >> 8) & 0xff;
mx28_fec_pdata[i].mac[5] = (val >> 0) & 0xff;
}
return 0;
}
static void __init m28evk_init(void)
{
mxs_iomux_setup_multiple_pads(m28evk_pads, ARRAY_SIZE(m28evk_pads));
mx28_add_duart();
mx28_add_auart0();
mx28_add_auart3();
if (!m28evk_fec_get_mac()) {
mx28_add_fec(0, &mx28_fec_pdata[0]);
mx28_add_fec(1, &mx28_fec_pdata[1]);
}
mx28_add_flexcan(0, NULL);
mx28_add_flexcan(1, NULL);
mx28_add_mxsfb(&m28evk_mxsfb_pdata);
mx28_add_mxs_mmc(0, &m28evk_mmc_pdata[0]);
mx28_add_mxs_mmc(1, &m28evk_mmc_pdata[1]);
gpio_led_register_device(0, &m28evk_led_data);
mx28_add_mxs_i2c(0);
i2c_register_board_info(0, m28_stk5v3_i2c_boardinfo,
ARRAY_SIZE(m28_stk5v3_i2c_boardinfo));
}
static void __init m28evk_timer_init(void)
{
mx28_clocks_init();
}
