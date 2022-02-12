static void n30_sdi_set_power(unsigned char power_mode, unsigned short vdd)
{
switch (power_mode) {
case MMC_POWER_ON:
case MMC_POWER_UP:
gpio_set_value(S3C2410_GPG(4), 1);
break;
case MMC_POWER_OFF:
default:
gpio_set_value(S3C2410_GPG(4), 0);
break;
}
}
static void __init n30_hwinit(void)
{
if (machine_is_n30())
__raw_writel(0x007fffff, S3C2410_GPACON);
if (machine_is_n35())
__raw_writel(0x007fefff, S3C2410_GPACON);
__raw_writel(0x00000000, S3C2410_GPADAT);
__raw_writel(0x00154556, S3C2410_GPBCON);
__raw_writel(0x00000750, S3C2410_GPBDAT);
__raw_writel(0x00000073, S3C2410_GPBUP);
__raw_writel(0xaaa80618, S3C2410_GPCCON);
__raw_writel(0x0000014c, S3C2410_GPCDAT);
__raw_writel(0x0000fef2, S3C2410_GPCUP);
__raw_writel(0xaa95aaa4, S3C2410_GPDCON);
__raw_writel(0x00000601, S3C2410_GPDDAT);
__raw_writel(0x0000fbfe, S3C2410_GPDUP);
__raw_writel(0xa56aaaaa, S3C2410_GPECON);
__raw_writel(0x0000efc5, S3C2410_GPEDAT);
__raw_writel(0x0000f81f, S3C2410_GPEUP);
__raw_writel(0x0000aaaa, S3C2410_GPFCON);
__raw_writel(0x00000000, S3C2410_GPFDAT);
__raw_writel(0x000000ff, S3C2410_GPFUP);
if (machine_is_n30())
__raw_writel(0xff0a956a, S3C2410_GPGCON);
if (machine_is_n35())
__raw_writel(0xff4aa92a, S3C2410_GPGCON);
__raw_writel(0x0000e800, S3C2410_GPGDAT);
__raw_writel(0x0000f86f, S3C2410_GPGUP);
__raw_writel(0x0028aaaa, S3C2410_GPHCON);
__raw_writel(0x000005ef, S3C2410_GPHDAT);
__raw_writel(0x0000063f, S3C2410_GPHUP);
}
static void __init n30_map_io(void)
{
s3c24xx_init_io(n30_iodesc, ARRAY_SIZE(n30_iodesc));
n30_hwinit();
s3c24xx_init_uarts(n30_uartcfgs, ARRAY_SIZE(n30_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init n30_init_time(void)
{
s3c2410_init_clocks(12000000);
samsung_timer_init();
}
static void __init n30_init(void)
{
WARN_ON(gpio_request(S3C2410_GPG(4), "mmc power"));
s3c24xx_fb_set_platdata(&n30_fb_info);
s3c24xx_udc_set_platdata(&n30_udc_cfg);
s3c24xx_mci_set_platdata(&n30_mci_cfg);
s3c_i2c0_set_platdata(&n30_i2ccfg);
s3c2410_modify_misccr(S3C2410_MISCCR_USBHOST |
S3C2410_MISCCR_USBSUSPND0 |
S3C2410_MISCCR_USBSUSPND1, 0x0);
if (machine_is_n30()) {
s3c2410_modify_misccr(S3C2410_MISCCR_USBHOST |
S3C2410_MISCCR_USBSUSPND0 |
S3C2410_MISCCR_USBSUSPND1, 0x0);
platform_add_devices(n30_devices, ARRAY_SIZE(n30_devices));
}
if (machine_is_n35()) {
s3c2410_modify_misccr(S3C2410_MISCCR_USBHOST |
S3C2410_MISCCR_USBSUSPND0 |
S3C2410_MISCCR_USBSUSPND1,
S3C2410_MISCCR_USBSUSPND0);
platform_add_devices(n35_devices, ARRAY_SIZE(n35_devices));
}
}
