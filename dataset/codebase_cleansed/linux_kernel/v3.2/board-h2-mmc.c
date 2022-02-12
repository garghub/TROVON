static int mmc_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
gpio_set_value(H2_TPS_GPIO_MMC_PWR_EN, power_on);
return 0;
}
static int mmc_late_init(struct device *dev)
{
int ret = gpio_request(H2_TPS_GPIO_MMC_PWR_EN, "MMC power");
if (ret < 0)
return ret;
gpio_direction_output(H2_TPS_GPIO_MMC_PWR_EN, 0);
return ret;
}
static void mmc_cleanup(struct device *dev)
{
gpio_free(H2_TPS_GPIO_MMC_PWR_EN);
}
void __init h2_mmc_init(void)
{
mmc_data[0] = &mmc1_data;
omap1_init_mmc(mmc_data, OMAP16XX_NR_MMC);
}
void __init h2_mmc_init(void)
{
}
