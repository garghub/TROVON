void samsung_keypad_cfg_gpio(unsigned int rows, unsigned int cols)
{
s3c_gpio_cfgrange_nopull(S3C64XX_GPK(8), rows, S3C_GPIO_SFN(3));
s3c_gpio_cfgrange_nopull(S3C64XX_GPL(0), cols, S3C_GPIO_SFN(3));
}
