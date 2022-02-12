static int mxc_mmc1_get_ro(struct device *dev)
{
return gpio_get_value(IOMUX_TO_GPIO(MX31_PIN_LCS0));
}
static int mxc_mmc1_init(struct device *dev,
irq_handler_t detect_irq, void *data)
{
int ret;
gpio_det = IOMUX_TO_GPIO(MX31_PIN_GPIO1_1);
gpio_wp = IOMUX_TO_GPIO(MX31_PIN_LCS0);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA0, MMC_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA1, MMC_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA2, MMC_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SD1_DATA3, MMC_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SD1_CLK, MMC_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SD1_CMD, MMC_PAD_CFG);
ret = gpio_request(gpio_det, "MMC detect");
if (ret)
return ret;
ret = gpio_request(gpio_wp, "MMC w/p");
if (ret)
goto exit_free_det;
gpio_direction_input(gpio_det);
gpio_direction_input(gpio_wp);
ret = request_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO1_1)),
detect_irq, IRQF_TRIGGER_FALLING,
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
free_irq(gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO1_1)), data);
}
static void __init mx31lilly_init_fb(void)
{
if (gpio_request(LCD_VCC_EN_GPIO, "LCD enable") != 0) {
printk(KERN_WARNING "unable to request LCD_VCC_EN pin.\n");
return;
}
imx31_add_ipu_core();
imx31_add_mx3_sdc_fb(&fb_pdata);
gpio_direction_output(LCD_VCC_EN_GPIO, 1);
}
void __init mx31lilly_db_init(void)
{
mxc_iomux_setup_multiple_pins(lilly_db_board_pins,
ARRAY_SIZE(lilly_db_board_pins),
"development board pins");
imx31_add_imx_uart0(&uart_pdata);
imx31_add_imx_uart1(&uart_pdata);
imx31_add_imx_uart2(&uart_pdata);
imx31_add_mxc_mmc(0, &mmc_pdata);
mx31lilly_init_fb();
}
