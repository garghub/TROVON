static void __init palmz72_kpc_init(void)
{
pxa_set_keypad_info(&palmz72_keypad_platform_data);
}
static inline void palmz72_kpc_init(void) {}
static void __init palmz72_leds_init(void)
{
platform_device_register(&palmz72_leds);
}
static inline void palmz72_leds_init(void) {}
static int palmz72_pm_suspend(void)
{
palmz72_resume_info.resume_addr = (u32) cpu_resume;
store_ptr = *PALMZ72_SAVE_DWORD;
PSPR = virt_to_phys(&palmz72_resume_info);
return 0;
}
static void palmz72_pm_resume(void)
{
*PALMZ72_SAVE_DWORD = store_ptr;
}
static int __init palmz72_pm_init(void)
{
if (machine_is_palmz72()) {
register_syscore_ops(&palmz72_pm_syscore_ops);
return 0;
}
return -ENODEV;
}
static int palmz72_camera_power(struct device *dev, int power)
{
gpio_set_value(GPIO_NR_PALMZ72_CAM_PWDN, !power);
mdelay(50);
return 0;
}
static int palmz72_camera_reset(struct device *dev)
{
gpio_set_value(GPIO_NR_PALMZ72_CAM_RESET, 1);
mdelay(50);
gpio_set_value(GPIO_NR_PALMZ72_CAM_RESET, 0);
mdelay(50);
return 0;
}
static inline void __init palmz72_cam_gpio_init(void)
{
int ret;
ret = gpio_request_array(ARRAY_AND_SIZE(palmz72_camera_gpios));
if (!ret)
gpio_free_array(ARRAY_AND_SIZE(palmz72_camera_gpios));
else
printk(KERN_ERR "Camera GPIO init failed!\n");
return;
}
static void __init palmz72_camera_init(void)
{
palmz72_cam_gpio_init();
pxa_set_camera_info(&palmz72_pxacamera_platform_data);
platform_device_register(&palmz72_i2c_bus_device);
platform_device_register(&palmz72_camera);
}
static inline void palmz72_camera_init(void) {}
static void __init palmz72_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(palmz72_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
palm27x_mmc_init(GPIO_NR_PALMZ72_SD_DETECT_N, GPIO_NR_PALMZ72_SD_RO,
GPIO_NR_PALMZ72_SD_POWER_N, 1);
palm27x_lcd_init(-1, &palm_320x320_lcd_mode);
palm27x_udc_init(GPIO_NR_PALMZ72_USB_DETECT_N,
GPIO_NR_PALMZ72_USB_PULLUP, 0);
palm27x_irda_init(GPIO_NR_PALMZ72_IR_DISABLE);
palm27x_ac97_init(PALMZ72_BAT_MIN_VOLTAGE, PALMZ72_BAT_MAX_VOLTAGE,
-1, 113);
palm27x_pwm_init(-1, -1);
palm27x_power_init(-1, -1);
palm27x_pmic_init();
palmz72_kpc_init();
palmz72_leds_init();
palmz72_camera_init();
}
