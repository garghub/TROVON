static int jornada_bl_get_brightness(struct backlight_device *bd)
{
int ret;
if (!(PPSR & PPC_LDD1))
return 0;
jornada_ssp_start();
ret = jornada_ssp_byte(GETBRIGHTNESS);
if (jornada_ssp_byte(GETBRIGHTNESS) != TXDUMMY) {
pr_err("get brightness timeout\n");
jornada_ssp_end();
return -ETIMEDOUT;
} else
ret = jornada_ssp_byte(TXDUMMY);
jornada_ssp_end();
return (BL_MAX_BRIGHT - ret);
}
static int jornada_bl_update_status(struct backlight_device *bd)
{
int ret = 0;
jornada_ssp_start();
if ((bd->props.power != FB_BLANK_UNBLANK) || (bd->props.fb_blank != FB_BLANK_UNBLANK)) {
ret = jornada_ssp_byte(BRIGHTNESSOFF);
if (ret != TXDUMMY) {
pr_info("brightness off timeout\n");
PPSR &= ~PPC_LDD1;
PPDR |= PPC_LDD1;
ret = -ETIMEDOUT;
}
} else
PPSR |= PPC_LDD1;
if (jornada_ssp_byte(SETBRIGHTNESS) != TXDUMMY) {
pr_info("failed to set brightness\n");
ret = -ETIMEDOUT;
goto out;
}
if (jornada_ssp_byte(BL_MAX_BRIGHT - bd->props.brightness) != TXDUMMY) {
pr_err("set brightness failed\n");
ret = -ETIMEDOUT;
}
out:
jornada_ssp_end();
return ret;
}
static int jornada_bl_probe(struct platform_device *pdev)
{
struct backlight_properties props;
int ret;
struct backlight_device *bd;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = BL_MAX_BRIGHT;
bd = backlight_device_register(S1D_DEVICENAME, &pdev->dev, NULL,
&jornada_bl_ops, &props);
if (IS_ERR(bd)) {
ret = PTR_ERR(bd);
pr_err("failed to register device, err=%x\n", ret);
return ret;
}
bd->props.power = FB_BLANK_UNBLANK;
bd->props.brightness = BL_DEF_BRIGHT;
jornada_bl_update_status(bd);
platform_set_drvdata(pdev, bd);
pr_info("HP Jornada 700 series backlight driver\n");
return 0;
}
static int jornada_bl_remove(struct platform_device *pdev)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
backlight_device_unregister(bd);
return 0;
}
