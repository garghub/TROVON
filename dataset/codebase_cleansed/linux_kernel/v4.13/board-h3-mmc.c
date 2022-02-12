static int mmc_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
gpio_set_value(H3_TPS_GPIO_MMC_PWR_EN, power_on);
return 0;
}
void __init h3_mmc_init(void)
{
int ret;
ret = gpio_request(H3_TPS_GPIO_MMC_PWR_EN, "MMC power");
if (ret < 0)
return;
gpio_direction_output(H3_TPS_GPIO_MMC_PWR_EN, 0);
mmc_data[0] = &mmc1_data;
omap1_init_mmc(mmc_data, OMAP16XX_NR_MMC);
}
void __init h3_mmc_init(void)
{
}
