static int __init jive_mtdset(char *options)
{
struct s3c2410_nand_set *nand = &jive_nand_sets[0];
unsigned long set;
if (options == NULL || options[0] == '\0')
return 0;
if (strict_strtoul(options, 10, &set)) {
printk(KERN_ERR "failed to parse mtdset=%s\n", options);
return 0;
}
switch (set) {
case 1:
nand->nr_partitions = ARRAY_SIZE(jive_imageB_nand_part);
nand->partitions = jive_imageB_nand_part;
case 0:
break;
default:
printk(KERN_ERR "Unknown mtd set %ld specified,"
"using default.", set);
}
return 0;
}
static void jive_lcm_reset(unsigned int set)
{
printk(KERN_DEBUG "%s(%d)\n", __func__, set);
gpio_set_value(S3C2410_GPG(13), set);
}
static void jive_lcd_spi_chipselect(struct s3c2410_spigpio_info *spi, int cs)
{
gpio_set_value(S3C2410_GPB(7), cs ? 0 : 1);
}
static void jive_wm8750_chipselect(struct s3c2410_spigpio_info *spi, int cs)
{
gpio_set_value(S3C2410_GPH(10), cs ? 0 : 1);
}
static int jive_pm_suspend(void)
{
__raw_writel(0x2BED, S3C2412_INFORM0);
__raw_writel(virt_to_phys(s3c_cpu_resume), S3C2412_INFORM1);
return 0;
}
static void jive_pm_resume(void)
{
__raw_writel(0x0, S3C2412_INFORM0);
}
static void __init jive_map_io(void)
{
s3c24xx_init_io(jive_iodesc, ARRAY_SIZE(jive_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(jive_uartcfgs, ARRAY_SIZE(jive_uartcfgs));
}
static void jive_power_off(void)
{
printk(KERN_INFO "powering system down...\n");
s3c2410_gpio_setpin(S3C2410_GPC(5), 1);
s3c_gpio_cfgpin(S3C2410_GPC(5), S3C2410_GPIO_OUTPUT);
}
static void __init jive_machine_init(void)
{
register_syscore_ops(&jive_pm_syscore_ops);
__raw_writel(S3C2412_SLPCON_IN(0) |
S3C2412_SLPCON_PULL(1) |
S3C2412_SLPCON_HIGH(2) |
S3C2412_SLPCON_PULL(3) |
S3C2412_SLPCON_PULL(4) |
S3C2412_SLPCON_PULL(5) |
S3C2412_SLPCON_PULL(6) |
S3C2412_SLPCON_HIGH(7) |
S3C2412_SLPCON_PULL(8) |
S3C2412_SLPCON_PULL(9) |
S3C2412_SLPCON_PULL(10), S3C2412_GPBSLPCON);
__raw_writel(S3C2412_SLPCON_PULL(0) |
S3C2412_SLPCON_PULL(1) |
S3C2412_SLPCON_PULL(2) |
S3C2412_SLPCON_PULL(3) |
S3C2412_SLPCON_PULL(4) |
S3C2412_SLPCON_PULL(5) |
S3C2412_SLPCON_LOW(6) |
S3C2412_SLPCON_PULL(6) |
S3C2412_SLPCON_PULL(7) |
S3C2412_SLPCON_PULL(8) |
S3C2412_SLPCON_PULL(9) |
S3C2412_SLPCON_PULL(10) |
S3C2412_SLPCON_PULL(11) |
S3C2412_SLPCON_PULL(12) |
S3C2412_SLPCON_PULL(13) |
S3C2412_SLPCON_PULL(14) |
S3C2412_SLPCON_PULL(15), S3C2412_GPCSLPCON);
__raw_writel(S3C2412_SLPCON_ALL_PULL, S3C2412_GPDSLPCON);
__raw_writel(S3C2412_SLPCON_LOW(0) |
S3C2412_SLPCON_LOW(1) |
S3C2412_SLPCON_LOW(2) |
S3C2412_SLPCON_EINT(3) |
S3C2412_SLPCON_EINT(4) |
S3C2412_SLPCON_EINT(5) |
S3C2412_SLPCON_EINT(6) |
S3C2412_SLPCON_EINT(7), S3C2412_GPFSLPCON);
__raw_writel(S3C2412_SLPCON_IN(0) |
S3C2412_SLPCON_IN(1) |
S3C2412_SLPCON_IN(2) |
S3C2412_SLPCON_IN(3) |
S3C2412_SLPCON_IN(4) |
S3C2412_SLPCON_IN(5) |
S3C2412_SLPCON_IN(6) |
S3C2412_SLPCON_IN(7) |
S3C2412_SLPCON_PULL(8) |
S3C2412_SLPCON_PULL(9) |
S3C2412_SLPCON_IN(10) |
S3C2412_SLPCON_PULL(11) |
S3C2412_SLPCON_PULL(12) |
S3C2412_SLPCON_PULL(13) |
S3C2412_SLPCON_IN(14) |
S3C2412_SLPCON_PULL(15), S3C2412_GPGSLPCON);
__raw_writel(S3C2412_SLPCON_PULL(0) |
S3C2412_SLPCON_PULL(1) |
S3C2412_SLPCON_PULL(2) |
S3C2412_SLPCON_PULL(3) |
S3C2412_SLPCON_PULL(4) |
S3C2412_SLPCON_PULL(5) |
S3C2412_SLPCON_PULL(6) |
S3C2412_SLPCON_IN(7) |
S3C2412_SLPCON_IN(8) |
S3C2412_SLPCON_PULL(9) |
S3C2412_SLPCON_IN(10), S3C2412_GPHSLPCON);
s3c_pm_init();
s3c_nand_set_platdata(&jive_nand_info);
gpio_request(S3C2410_GPG(13), "lcm reset");
gpio_direction_output(S3C2410_GPG(13), 0);
gpio_request(S3C2410_GPB(7), "jive spi");
gpio_direction_output(S3C2410_GPB(7), 1);
s3c2410_gpio_setpin(S3C2410_GPB(6), 0);
s3c_gpio_cfgpin(S3C2410_GPB(6), S3C2410_GPIO_OUTPUT);
s3c2410_gpio_setpin(S3C2410_GPG(8), 1);
s3c_gpio_cfgpin(S3C2410_GPG(8), S3C2410_GPIO_OUTPUT);
gpio_request(S3C2410_GPH(10), "jive wm8750 spi");
gpio_direction_output(S3C2410_GPH(10), 1);
s3c2410_modify_misccr(S3C2410_MISCCR_USBHOST |
S3C2410_MISCCR_USBSUSPND0 |
S3C2410_MISCCR_USBSUSPND1, 0x0);
s3c24xx_udc_set_platdata(&jive_udc_cfg);
s3c24xx_fb_set_platdata(&jive_lcd_config);
spi_register_board_info(jive_spi_devs, ARRAY_SIZE(jive_spi_devs));
s3c_i2c0_set_platdata(&jive_i2c_cfg);
i2c_register_board_info(0, jive_i2c_devs, ARRAY_SIZE(jive_i2c_devs));
pm_power_off = jive_power_off;
platform_add_devices(jive_devices, ARRAY_SIZE(jive_devices));
}
