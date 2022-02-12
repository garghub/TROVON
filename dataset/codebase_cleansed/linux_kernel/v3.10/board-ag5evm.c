static int sh_mipi_set_dot_clock(struct platform_device *pdev,
void __iomem *base,
int enable)
{
struct clk *pck, *phy;
int ret;
pck = clk_get(&pdev->dev, "dsip_clk");
if (IS_ERR(pck)) {
ret = PTR_ERR(pck);
goto sh_mipi_set_dot_clock_pck_err;
}
phy = clk_get(&pdev->dev, "dsiphy_clk");
if (IS_ERR(phy)) {
ret = PTR_ERR(phy);
goto sh_mipi_set_dot_clock_phy_err;
}
if (enable) {
clk_set_rate(pck, clk_round_rate(pck, 24000000));
clk_set_rate(phy, clk_round_rate(pck, 510000000));
clk_enable(pck);
clk_enable(phy);
} else {
clk_disable(pck);
clk_disable(phy);
}
ret = 0;
clk_put(phy);
sh_mipi_set_dot_clock_phy_err:
clk_put(pck);
sh_mipi_set_dot_clock_pck_err:
return ret;
}
static int lcd_backlight_set_brightness(int brightness)
{
struct i2c_adapter *adap;
struct i2c_msg msg;
unsigned int i;
int ret;
if (brightness == 0) {
gpio_set_value(235, 0);
mdelay(24);
gpio_set_value(235, 1);
return 0;
}
adap = i2c_get_adapter(1);
if (adap == NULL)
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(lcd_backlight_seq); i++) {
msg.addr = 0x6d;
msg.buf = &lcd_backlight_seq[i][0];
msg.len = 2;
msg.flags = 0;
ret = i2c_transfer(adap, &msg, 1);
if (ret < 0)
break;
}
i2c_put_adapter(adap);
return ret < 0 ? ret : 0;
}
static void ag5evm_sdhi1_set_pwr(struct platform_device *pdev, int state)
{
static int power_gpio = -EINVAL;
if (power_gpio < 0) {
int ret = gpio_request_one(114, GPIOF_OUT_INIT_LOW,
"sdhi1_power");
if (!ret)
power_gpio = 114;
}
gpio_set_value(114, state);
}
static void __init ag5evm_init(void)
{
regulator_register_always_on(0, "fixed-1.8V", fixed1v8_power_consumers,
ARRAY_SIZE(fixed1v8_power_consumers), 1800000);
regulator_register_always_on(1, "fixed-2.8V", fixed2v8_power_consumers,
ARRAY_SIZE(fixed2v8_power_consumers), 3300000);
regulator_register_fixed(3, dummy_supplies, ARRAY_SIZE(dummy_supplies));
pinctrl_register_mappings(ag5evm_pinctrl_map,
ARRAY_SIZE(ag5evm_pinctrl_map));
sh73a0_pinmux_init();
gpio_request_one(208, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(144, GPIOF_IN, NULL);
gpio_request_one(145, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(217, GPIOF_OUT_INIT_LOW, NULL);
mdelay(1);
gpio_set_value(217, 1);
mdelay(100);
gpio_request_one(235, GPIOF_OUT_INIT_LOW, NULL);
lcd_backlight_set_brightness(0);
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x00460000, 0xc2000fff);
#endif
sh73a0_add_standard_devices();
platform_add_devices(ag5evm_devices, ARRAY_SIZE(ag5evm_devices));
}
