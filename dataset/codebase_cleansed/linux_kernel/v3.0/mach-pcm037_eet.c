static int __init eet_init_devices(void)
{
if (!machine_is_pcm037() || pcm037_variant() != PCM037_EET)
return 0;
mxc_iomux_setup_multiple_pins(pcm037_eet_pins,
ARRAY_SIZE(pcm037_eet_pins), "pcm037_eet");
spi_register_board_info(pcm037_spi_dev, ARRAY_SIZE(pcm037_spi_dev));
imx31_add_spi_imx0(&pcm037_spi1_pdata);
imx_add_gpio_keys(&pcm037_gpio_keys_platform_data);
return 0;
}
