static int a780_camera_init(void)
{
int err;
err = gpio_request(GPIO50_nCAM_EN, "nCAM_EN");
if (err) {
pr_err("%s: Failed to request nCAM_EN\n", __func__);
goto fail;
}
err = gpio_request(GPIO19_GEN1_CAM_RST, "CAM_RST");
if (err) {
pr_err("%s: Failed to request CAM_RST\n", __func__);
goto fail_gpio_cam_rst;
}
gpio_direction_output(GPIO50_nCAM_EN, 1);
gpio_direction_output(GPIO19_GEN1_CAM_RST, 0);
return 0;
fail_gpio_cam_rst:
gpio_free(GPIO50_nCAM_EN);
fail:
return err;
}
static int a780_camera_power(struct device *dev, int on)
{
gpio_set_value(GPIO50_nCAM_EN, !on);
return 0;
}
static int a780_camera_reset(struct device *dev)
{
gpio_set_value(GPIO19_GEN1_CAM_RST, 0);
msleep(10);
gpio_set_value(GPIO19_GEN1_CAM_RST, 1);
return 0;
}
static void __init a780_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(ezx_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(gen1_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(a780_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
pxa_set_fb_info(NULL, &ezx_fb_info_1);
pxa_set_keypad_info(&a780_keypad_platform_data);
if (a780_camera_init() == 0) {
pxa_set_camera_info(&a780_pxacamera_platform_data);
platform_device_register(&a780_camera);
}
platform_add_devices(ARRAY_AND_SIZE(ezx_devices));
platform_add_devices(ARRAY_AND_SIZE(a780_devices));
}
static void __init e680_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(ezx_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(gen1_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(e680_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(e680_i2c_board_info));
pxa_set_fb_info(NULL, &ezx_fb_info_1);
pxa_set_keypad_info(&e680_keypad_platform_data);
platform_add_devices(ARRAY_AND_SIZE(ezx_devices));
platform_add_devices(ARRAY_AND_SIZE(e680_devices));
}
static void __init a1200_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(ezx_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(gen2_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(a1200_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(a1200_i2c_board_info));
pxa_set_fb_info(NULL, &ezx_fb_info_2);
pxa_set_keypad_info(&a1200_keypad_platform_data);
platform_add_devices(ARRAY_AND_SIZE(ezx_devices));
platform_add_devices(ARRAY_AND_SIZE(a1200_devices));
}
static int a910_camera_init(void)
{
int err;
err = gpio_request(GPIO50_nCAM_EN, "nCAM_EN");
if (err) {
pr_err("%s: Failed to request nCAM_EN\n", __func__);
goto fail;
}
err = gpio_request(GPIO28_GEN2_CAM_RST, "CAM_RST");
if (err) {
pr_err("%s: Failed to request CAM_RST\n", __func__);
goto fail_gpio_cam_rst;
}
gpio_direction_output(GPIO50_nCAM_EN, 1);
gpio_direction_output(GPIO28_GEN2_CAM_RST, 0);
return 0;
fail_gpio_cam_rst:
gpio_free(GPIO50_nCAM_EN);
fail:
return err;
}
static int a910_camera_power(struct device *dev, int on)
{
gpio_set_value(GPIO50_nCAM_EN, !on);
return 0;
}
static int a910_camera_reset(struct device *dev)
{
gpio_set_value(GPIO28_GEN2_CAM_RST, 0);
msleep(10);
gpio_set_value(GPIO28_GEN2_CAM_RST, 1);
return 0;
}
static void __init a910_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(ezx_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(gen2_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(a910_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(a910_i2c_board_info));
pxa_set_fb_info(NULL, &ezx_fb_info_2);
pxa_set_keypad_info(&a910_keypad_platform_data);
if (a910_camera_init() == 0) {
pxa_set_camera_info(&a910_pxacamera_platform_data);
platform_device_register(&a910_camera);
}
platform_add_devices(ARRAY_AND_SIZE(ezx_devices));
platform_add_devices(ARRAY_AND_SIZE(a910_devices));
}
static void __init e6_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(ezx_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(gen2_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(e6_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(e6_i2c_board_info));
pxa_set_fb_info(NULL, &ezx_fb_info_2);
pxa_set_keypad_info(&e6_keypad_platform_data);
platform_add_devices(ARRAY_AND_SIZE(ezx_devices));
platform_add_devices(ARRAY_AND_SIZE(e6_devices));
}
static void __init e2_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(ezx_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(gen2_pin_config));
pxa2xx_mfp_config(ARRAY_AND_SIZE(e2_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(e2_i2c_board_info));
pxa_set_fb_info(NULL, &ezx_fb_info_2);
pxa_set_keypad_info(&e2_keypad_platform_data);
platform_add_devices(ARRAY_AND_SIZE(ezx_devices));
platform_add_devices(ARRAY_AND_SIZE(e2_devices));
}
