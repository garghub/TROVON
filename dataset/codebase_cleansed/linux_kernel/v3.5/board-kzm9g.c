static int __init as3711_enable_lcdc_backlight(void)
{
struct i2c_adapter *a = i2c_get_adapter(0);
struct i2c_msg msg;
int i, ret;
__u8 magic[] = {
0x40, 0x2a,
0x43, 0x3c,
0x44, 0x3c,
0x45, 0x3c,
0x54, 0x03,
0x51, 0x00,
0x51, 0x01,
0xff, 0x00,
0x43, 0xf0,
0x44, 0xf0,
0x45, 0xf0,
};
if (!machine_is_kzm9g())
return 0;
if (!a)
return 0;
msg.addr = 0x40;
msg.len = 2;
msg.flags = 0;
for (i = 0; i < ARRAY_SIZE(magic); i += 2) {
msg.buf = magic + i;
if (0xff == msg.buf[0]) {
udelay(500);
continue;
}
ret = i2c_transfer(a, &msg, 1);
if (ret < 0) {
pr_err("i2c transfer fail\n");
break;
}
}
return 0;
}
static void __init kzm_init(void)
{
sh73a0_pinmux_init();
gpio_request(GPIO_FN_SCIFA4_TXD, NULL);
gpio_request(GPIO_FN_SCIFA4_RXD, NULL);
gpio_request(GPIO_FN_SCIFA4_RTS_, NULL);
gpio_request(GPIO_FN_SCIFA4_CTS_, NULL);
gpio_request(GPIO_FN_CS4_, NULL);
gpio_request(GPIO_PORT224, NULL);
gpio_direction_input(GPIO_PORT224);
gpio_request(GPIO_FN_LCDD23, NULL);
gpio_request(GPIO_FN_LCDD22, NULL);
gpio_request(GPIO_FN_LCDD21, NULL);
gpio_request(GPIO_FN_LCDD20, NULL);
gpio_request(GPIO_FN_LCDD19, NULL);
gpio_request(GPIO_FN_LCDD18, NULL);
gpio_request(GPIO_FN_LCDD17, NULL);
gpio_request(GPIO_FN_LCDD16, NULL);
gpio_request(GPIO_FN_LCDD15, NULL);
gpio_request(GPIO_FN_LCDD14, NULL);
gpio_request(GPIO_FN_LCDD13, NULL);
gpio_request(GPIO_FN_LCDD12, NULL);
gpio_request(GPIO_FN_LCDD11, NULL);
gpio_request(GPIO_FN_LCDD10, NULL);
gpio_request(GPIO_FN_LCDD9, NULL);
gpio_request(GPIO_FN_LCDD8, NULL);
gpio_request(GPIO_FN_LCDD7, NULL);
gpio_request(GPIO_FN_LCDD6, NULL);
gpio_request(GPIO_FN_LCDD5, NULL);
gpio_request(GPIO_FN_LCDD4, NULL);
gpio_request(GPIO_FN_LCDD3, NULL);
gpio_request(GPIO_FN_LCDD2, NULL);
gpio_request(GPIO_FN_LCDD1, NULL);
gpio_request(GPIO_FN_LCDD0, NULL);
gpio_request(GPIO_FN_LCDDISP, NULL);
gpio_request(GPIO_FN_LCDDCK, NULL);
gpio_request(GPIO_PORT222, NULL);
gpio_request(GPIO_PORT226, NULL);
gpio_direction_output(GPIO_PORT222, 1);
gpio_direction_output(GPIO_PORT226, 1);
gpio_request(GPIO_PORT223, NULL);
gpio_direction_input(GPIO_PORT223);
gpio_request(GPIO_FN_MMCCLK0, NULL);
gpio_request(GPIO_FN_MMCCMD0_PU, NULL);
gpio_request(GPIO_FN_MMCD0_0_PU, NULL);
gpio_request(GPIO_FN_MMCD0_1_PU, NULL);
gpio_request(GPIO_FN_MMCD0_2_PU, NULL);
gpio_request(GPIO_FN_MMCD0_3_PU, NULL);
gpio_request(GPIO_FN_MMCD0_4_PU, NULL);
gpio_request(GPIO_FN_MMCD0_5_PU, NULL);
gpio_request(GPIO_FN_MMCD0_6_PU, NULL);
gpio_request(GPIO_FN_MMCD0_7_PU, NULL);
gpio_request(GPIO_FN_SDHIWP0, NULL);
gpio_request(GPIO_FN_SDHICD0, NULL);
gpio_request(GPIO_FN_SDHICMD0, NULL);
gpio_request(GPIO_FN_SDHICLK0, NULL);
gpio_request(GPIO_FN_SDHID0_3, NULL);
gpio_request(GPIO_FN_SDHID0_2, NULL);
gpio_request(GPIO_FN_SDHID0_1, NULL);
gpio_request(GPIO_FN_SDHID0_0, NULL);
gpio_request(GPIO_FN_SDHI0_VCCQ_MC0_ON, NULL);
gpio_request(GPIO_PORT15, NULL);
gpio_direction_output(GPIO_PORT15, 1);
gpio_request(GPIO_FN_PORT27_I2C_SCL3, NULL);
gpio_request(GPIO_FN_PORT28_I2C_SDA3, NULL);
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x40460000, 0x82000fff);
#endif
i2c_register_board_info(1, i2c1_devices, ARRAY_SIZE(i2c1_devices));
i2c_register_board_info(3, i2c3_devices, ARRAY_SIZE(i2c3_devices));
sh73a0_add_standard_devices();
platform_add_devices(kzm_devices, ARRAY_SIZE(kzm_devices));
}
