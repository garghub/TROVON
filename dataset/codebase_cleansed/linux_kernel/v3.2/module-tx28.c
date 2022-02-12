int __init tx28_add_fec0(void)
{
int i, ret;
pr_debug("%s: Switching FEC PHY power off\n", __func__);
ret = mxs_iomux_setup_multiple_pads(tx28_fec_gpio_pads,
ARRAY_SIZE(tx28_fec_gpio_pads));
for (i = 0; i < ARRAY_SIZE(tx28_fec_gpio_pads); i++) {
unsigned int gpio = MXS_GPIO_NR(PAD_BANK(tx28_fec_gpio_pads[i]),
PAD_PIN(tx28_fec_gpio_pads[i]));
ret = gpio_request(gpio, "FEC");
if (ret) {
pr_err("Failed to request GPIO_%d_%d: %d\n",
PAD_BANK(tx28_fec_gpio_pads[i]),
PAD_PIN(tx28_fec_gpio_pads[i]), ret);
goto free_gpios;
}
ret = gpio_direction_output(gpio, 0);
if (ret) {
pr_err("Failed to set direction of GPIO_%d_%d to output: %d\n",
gpio / 32 + 1, gpio % 32, ret);
goto free_gpios;
}
}
pr_debug("%s: Switching FEC PHY power on\n", __func__);
ret = gpio_direction_output(TX28_FEC_PHY_POWER, 1);
if (ret) {
pr_err("Failed to power on PHY: %d\n", ret);
goto free_gpios;
}
mdelay(26);
gpio_direction_input(MXS_GPIO_NR(4, 5));
gpio_direction_output(MXS_GPIO_NR(4, 2), 1);
gpio_direction_output(MXS_GPIO_NR(4, 3), 1);
gpio_direction_output(MXS_GPIO_NR(4, 4), 1);
udelay(100);
pr_debug("%s: Deasserting FEC PHY RESET\n", __func__);
gpio_set_value(TX28_FEC_PHY_RESET, 1);
ret = mxs_iomux_setup_multiple_pads(tx28_fec0_pads,
ARRAY_SIZE(tx28_fec0_pads));
if (ret) {
pr_debug("%s: mxs_iomux_setup_multiple_pads() failed with rc: %d\n",
__func__, ret);
goto free_gpios;
}
pr_debug("%s: Registering FEC0 device\n", __func__);
mx28_add_fec(0, &tx28_fec0_data);
return 0;
free_gpios:
while (--i >= 0) {
unsigned int gpio = MXS_GPIO_NR(PAD_BANK(tx28_fec_gpio_pads[i]),
PAD_PIN(tx28_fec_gpio_pads[i]));
gpio_free(gpio);
}
return ret;
}
int __init tx28_add_fec1(void)
{
int ret;
ret = mxs_iomux_setup_multiple_pads(tx28_fec1_pads,
ARRAY_SIZE(tx28_fec1_pads));
if (ret) {
pr_debug("%s: mxs_iomux_setup_multiple_pads() failed with rc: %d\n",
__func__, ret);
return ret;
}
pr_debug("%s: Registering FEC1 device\n", __func__);
mx28_add_fec(1, &tx28_fec1_data);
return 0;
}
