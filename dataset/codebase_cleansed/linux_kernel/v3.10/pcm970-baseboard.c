static int pcm970_sdhc2_get_ro(struct device *dev)
{
return gpio_get_value(GPIO_PORTC + 28);
}
static int pcm970_sdhc2_init(struct device *dev, irq_handler_t detect_irq, void *data)
{
int ret;
ret = request_irq(gpio_to_irq(IMX_GPIO_NR(3, 29)), detect_irq,
IRQF_TRIGGER_FALLING, "imx-mmc-detect", data);
if (ret)
return ret;
ret = gpio_request(GPIO_PORTC + 28, "imx-mmc-ro");
if (ret) {
free_irq(gpio_to_irq(IMX_GPIO_NR(3, 29)), data);
return ret;
}
gpio_direction_input(GPIO_PORTC + 28);
return 0;
}
static void pcm970_sdhc2_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(IMX_GPIO_NR(3, 29)), data);
gpio_free(GPIO_PORTC + 28);
}
void __init pcm970_baseboard_init(void)
{
mxc_gpio_setup_multiple_pins(pcm970_pins, ARRAY_SIZE(pcm970_pins),
"PCM970");
imx27_add_imx_fb(&pcm038_fb_data);
mxc_gpio_mode(GPIO_PORTC | 28 | GPIO_GPIO | GPIO_IN);
imx27_add_mxc_mmc(1, &sdhc_pdata);
pcm970_sja1000_resources[1].start = gpio_to_irq(IMX_GPIO_NR(5, 19));
pcm970_sja1000_resources[1].end = gpio_to_irq(IMX_GPIO_NR(5, 19));
platform_device_register(&pcm970_sja1000);
}
