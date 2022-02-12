static void lcd_backlight_on(void)
{
struct i2c_adapter *a;
struct i2c_msg msg;
int k;
a = i2c_get_adapter(1);
for (k = 0; a && k < 3; k++) {
msg.addr = 0x6d;
msg.buf = &lcd_backlight_seq[k][0];
msg.len = 2;
msg.flags = 0;
if (i2c_transfer(a, &msg, 1) != 1)
break;
}
}
static void lcd_backlight_reset(void)
{
gpio_set_value(GPIO_PORT235, 0);
mdelay(24);
gpio_set_value(GPIO_PORT235, 1);
}
static void lcd_on(void *board_data, struct fb_info *info)
{
lcd_backlight_on();
}
static void lcd_off(void *board_data)
{
lcd_backlight_reset();
}
void ag5evm_sdhi1_set_pwr(struct platform_device *pdev, int state)
{
gpio_set_value(GPIO_PORT114, state);
}
static void __init ag5evm_map_io(void)
{
iotable_init(ag5evm_io_desc, ARRAY_SIZE(ag5evm_io_desc));
sh73a0_add_early_devices();
shmobile_setup_console();
}
void __init ag5evm_init_irq(void)
{
sh73a0_init_irq();
__raw_writel(__raw_readl(PINTER0A) | (1<<29), PINTER0A);
__raw_writew(__raw_readw(PINTCR0A) | (2<<10), PINTCR0A);
}
static void __init ag5evm_init(void)
{
sh73a0_pinmux_init();
gpio_request(GPIO_FN_SCIFA2_TXD1, NULL);
gpio_request(GPIO_FN_SCIFA2_RXD1, NULL);
gpio_request(GPIO_FN_SCIFA2_RTS1_, NULL);
gpio_request(GPIO_FN_SCIFA2_CTS1_, NULL);
gpio_request(GPIO_FN_KEYIN0_PU, NULL);
gpio_request(GPIO_FN_KEYIN1_PU, NULL);
gpio_request(GPIO_FN_KEYIN2_PU, NULL);
gpio_request(GPIO_FN_KEYIN3_PU, NULL);
gpio_request(GPIO_FN_KEYIN4_PU, NULL);
gpio_request(GPIO_FN_KEYIN5_PU, NULL);
gpio_request(GPIO_FN_KEYIN6_PU, NULL);
gpio_request(GPIO_FN_KEYIN7_PU, NULL);
gpio_request(GPIO_FN_KEYOUT0, NULL);
gpio_request(GPIO_FN_KEYOUT1, NULL);
gpio_request(GPIO_FN_KEYOUT2, NULL);
gpio_request(GPIO_FN_KEYOUT3, NULL);
gpio_request(GPIO_FN_KEYOUT4, NULL);
gpio_request(GPIO_FN_KEYOUT5, NULL);
gpio_request(GPIO_FN_PORT59_KEYOUT6, NULL);
gpio_request(GPIO_FN_PORT58_KEYOUT7, NULL);
gpio_request(GPIO_FN_KEYOUT8, NULL);
gpio_request(GPIO_FN_PORT149_KEYOUT9, NULL);
gpio_request(GPIO_FN_PORT236_I2C_SDA2, NULL);
gpio_request(GPIO_FN_PORT237_I2C_SCL2, NULL);
gpio_request(GPIO_FN_PORT248_I2C_SCL3, NULL);
gpio_request(GPIO_FN_PORT249_I2C_SDA3, NULL);
gpio_request(GPIO_FN_MMCCLK0, NULL);
gpio_request(GPIO_FN_MMCCMD0_PU, NULL);
gpio_request(GPIO_FN_MMCD0_0, NULL);
gpio_request(GPIO_FN_MMCD0_1, NULL);
gpio_request(GPIO_FN_MMCD0_2, NULL);
gpio_request(GPIO_FN_MMCD0_3, NULL);
gpio_request(GPIO_FN_MMCD0_4, NULL);
gpio_request(GPIO_FN_MMCD0_5, NULL);
gpio_request(GPIO_FN_MMCD0_6, NULL);
gpio_request(GPIO_FN_MMCD0_7, NULL);
gpio_request(GPIO_PORT208, NULL);
gpio_direction_output(GPIO_PORT208, 1);
gpio_request(GPIO_PORT144, NULL);
gpio_direction_input(GPIO_PORT144);
gpio_request(GPIO_PORT145, NULL);
gpio_direction_output(GPIO_PORT145, 1);
gpio_request(GPIO_FN_FSIACK, NULL);
gpio_request(GPIO_FN_FSIAILR, NULL);
gpio_request(GPIO_FN_FSIAIBT, NULL);
gpio_request(GPIO_FN_FSIAISLD, NULL);
gpio_request(GPIO_FN_FSIAOSLD, NULL);
gpio_request(GPIO_FN_PORT241_IRDA_OUT, NULL);
gpio_request(GPIO_FN_PORT242_IRDA_IN, NULL);
gpio_request(GPIO_FN_PORT243_IRDA_FIRSEL, NULL);
gpio_request(GPIO_PORT217, NULL);
gpio_direction_output(GPIO_PORT217, 0);
mdelay(1);
gpio_set_value(GPIO_PORT217, 1);
mdelay(100);
gpio_request(GPIO_PORT235, NULL);
gpio_direction_output(GPIO_PORT235, 0);
lcd_backlight_reset();
__raw_writel(0x2a809010, DSI0PHYCR);
gpio_request(GPIO_FN_SDHICD0, NULL);
gpio_request(GPIO_FN_SDHIWP0, NULL);
gpio_request(GPIO_FN_SDHICMD0, NULL);
gpio_request(GPIO_FN_SDHICLK0, NULL);
gpio_request(GPIO_FN_SDHID0_3, NULL);
gpio_request(GPIO_FN_SDHID0_2, NULL);
gpio_request(GPIO_FN_SDHID0_1, NULL);
gpio_request(GPIO_FN_SDHID0_0, NULL);
gpio_request(GPIO_FN_SDHICLK1, NULL);
gpio_request(GPIO_FN_SDHICMD1_PU, NULL);
gpio_request(GPIO_FN_SDHID1_3_PU, NULL);
gpio_request(GPIO_FN_SDHID1_2_PU, NULL);
gpio_request(GPIO_FN_SDHID1_1_PU, NULL);
gpio_request(GPIO_FN_SDHID1_0_PU, NULL);
gpio_request(GPIO_PORT114, "sdhi1_power");
gpio_direction_output(GPIO_PORT114, 0);
#ifdef CONFIG_CACHE_L2X0
l2x0_init(__io(0xf0100000), 0x00460000, 0xc2000fff);
#endif
sh73a0_add_standard_devices();
platform_add_devices(ag5evm_devices, ARRAY_SIZE(ag5evm_devices));
}
static void __init ag5evm_timer_init(void)
{
sh73a0_clock_init();
shmobile_timer.init();
return;
}
