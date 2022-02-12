static void __init amlm5900_map_io(void)
{
s3c24xx_init_io(amlm5900_iodesc, ARRAY_SIZE(amlm5900_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(amlm5900_uartcfgs, ARRAY_SIZE(amlm5900_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static irqreturn_t
amlm5900_wake_interrupt(int irq, void *ignored)
{
return IRQ_HANDLED;
}
static void amlm5900_init_pm(void)
{
int ret = 0;
ret = request_irq(IRQ_EINT9, &amlm5900_wake_interrupt,
IRQF_TRIGGER_RISING | IRQF_SHARED,
"amlm5900_wakeup", &amlm5900_wake_interrupt);
if (ret != 0) {
printk(KERN_ERR "AML-M5900: no wakeup irq, %d?\n", ret);
} else {
enable_irq_wake(IRQ_EINT9);
s3c_gpio_cfgpin(S3C2410_GPF(2), S3C2410_GPIO_OUTPUT);
s3c_gpio_setpull(S3C2410_GPF(2), S3C_GPIO_PULL_UP);
}
}
static void __init amlm5900_init(void)
{
amlm5900_init_pm();
#ifdef CONFIG_FB_S3C2410
s3c24xx_fb_set_platdata(&amlm5900_fb_info);
#endif
s3c_i2c0_set_platdata(NULL);
platform_add_devices(amlm5900_devices, ARRAY_SIZE(amlm5900_devices));
}
