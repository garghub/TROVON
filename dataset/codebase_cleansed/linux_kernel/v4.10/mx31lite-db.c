static int mxc_mmc1_get_ro(struct device *dev)
{
return gpio_get_value(IOMUX_TO_GPIO(MX31_PIN_GPIO1_6));
}
static int mxc_mmc1_init(struct device *dev,
irq_handler_t detect_irq, void *data)
{
int ret;
gpio_det = IOMUX_TO_GPIO(MX31_PIN_DCD_DCE1);
gpio_wp = IOMUX_TO_GPIO(MX31_PIN_GPIO1_6);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA0,
MMC_PAD_CFG | PAD_CTL_PUE_PUD | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA1,
MMC_PAD_CFG | PAD_CTL_PUE_PUD | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA2,
MMC_PAD_CFG | PAD_CTL_PUE_PUD | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA3,
MMC_PAD_CFG | PAD_CTL_PUE_PUD | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_SD1_CMD,
MMC_PAD_CFG | PAD_CTL_PUE_PUD | PAD_CTL_100K_PU);
mxc_iomux_set_pad(MX31_PIN_SD1_CLK, MMC_PAD_CFG);
ret = gpio_request(gpio_det, "MMC detect");
if (ret)
return ret;
ret = gpio_request(gpio_wp, "MMC w/p");
if (ret)
goto exit_free_det;
gpio_direction_input(gpio_det);
gpio_direction_input(gpio_wp);
ret = request_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_DCD_DCE1)),
detect_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"MMC detect", data);
if (ret)
goto exit_free_wp;
return 0;
exit_free_wp:
gpio_free(gpio_wp);
exit_free_det:
gpio_free(gpio_det);
return ret;
}
static void mxc_mmc1_exit(struct device *dev, void *data)
{
gpio_free(gpio_det);
gpio_free(gpio_wp);
free_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_DCD_DCE1)), data);
}
void __init mx31lite_db_init(void)
{
mxc_iomux_setup_multiple_pins(litekit_db_board_pins,
ARRAY_SIZE(litekit_db_board_pins),
"development board pins");
imx31_add_mxc_mmc(0, &mmc_pdata);
gpio_led_register_device(-1, &litekit_led_platform_data);
imx31_add_imx2_wdt();
imx31_add_mxc_rtc();
}
