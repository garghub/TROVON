static int pandora_backlight_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
u8 r;
if (bl->props.power != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.state & BL_CORE_FBBLANK)
brightness = 0;
if (bl->props.state & BL_CORE_SUSPENDED)
brightness = 0;
if ((unsigned int)brightness > MAX_USER_VALUE)
brightness = MAX_USER_VALUE;
if (brightness == 0) {
if (bl->props.state & PANDORABL_WAS_OFF)
goto done;
twl_i2c_read_u8(TWL4030_MODULE_INTBR, &r, TWL_INTBR_GPBR1);
r &= ~PWM0_ENABLE;
twl_i2c_write_u8(TWL4030_MODULE_INTBR, r, TWL_INTBR_GPBR1);
r &= ~PWM0_CLK_ENABLE;
twl_i2c_write_u8(TWL4030_MODULE_INTBR, r, TWL_INTBR_GPBR1);
goto done;
}
if (bl->props.state & PANDORABL_WAS_OFF) {
twl_i2c_write_u8(TWL4030_MODULE_PWM0, MAX_VALUE,
TWL_PWM0_OFF);
twl_i2c_read_u8(TWL4030_MODULE_INTBR, &r, TWL_INTBR_GPBR1);
r &= ~PWM0_ENABLE;
r |= PWM0_CLK_ENABLE;
twl_i2c_write_u8(TWL4030_MODULE_INTBR, r, TWL_INTBR_GPBR1);
r |= PWM0_ENABLE;
twl_i2c_write_u8(TWL4030_MODULE_INTBR, r, TWL_INTBR_GPBR1);
usleep_range(2000, 10000);
}
twl_i2c_write_u8(TWL4030_MODULE_PWM0, MIN_VALUE + brightness,
TWL_PWM0_OFF);
done:
if (brightness != 0)
bl->props.state &= ~PANDORABL_WAS_OFF;
else
bl->props.state |= PANDORABL_WAS_OFF;
return 0;
}
static int pandora_backlight_get_brightness(struct backlight_device *bl)
{
return bl->props.brightness;
}
static int pandora_backlight_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct backlight_device *bl;
u8 r;
memset(&props, 0, sizeof(props));
props.max_brightness = MAX_USER_VALUE;
props.type = BACKLIGHT_RAW;
bl = backlight_device_register(pdev->name, &pdev->dev,
NULL, &pandora_backlight_ops, &props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "failed to register backlight\n");
return PTR_ERR(bl);
}
platform_set_drvdata(pdev, bl);
twl_i2c_write_u8(TWL4030_MODULE_PWM0, 0x80, TWL_PWM0_ON);
bl->props.state |= PANDORABL_WAS_OFF;
bl->props.brightness = MAX_USER_VALUE;
backlight_update_status(bl);
twl_i2c_read_u8(TWL4030_MODULE_INTBR, &r, TWL_INTBR_PMBR1);
r &= ~TWL_PMBR1_PWM0_MUXMASK;
r |= TWL_PMBR1_PWM0;
twl_i2c_write_u8(TWL4030_MODULE_INTBR, r, TWL_INTBR_PMBR1);
return 0;
}
static int pandora_backlight_remove(struct platform_device *pdev)
{
struct backlight_device *bl = platform_get_drvdata(pdev);
backlight_device_unregister(bl);
return 0;
}
