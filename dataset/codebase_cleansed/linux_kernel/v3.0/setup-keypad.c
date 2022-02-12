void samsung_keypad_cfg_gpio(unsigned int rows, unsigned int cols)
{
s3c_gpio_cfgrange_nopull(S5PC100_GPH3(0), rows, S3C_GPIO_SFN(3));
s3c_gpio_cfgrange_nopull(S5PC100_GPH2(0), cols, S3C_GPIO_SFN(3));
}
