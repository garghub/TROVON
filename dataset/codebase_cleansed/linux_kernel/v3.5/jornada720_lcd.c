static int jornada_lcd_get_power(struct lcd_device *dev)
{
if (PPSR & PPC_LDD2)
return FB_BLANK_UNBLANK;
else
return FB_BLANK_POWERDOWN;
}
static int jornada_lcd_get_contrast(struct lcd_device *dev)
{
int ret;
if (jornada_lcd_get_power(dev) != FB_BLANK_UNBLANK)
return 0;
jornada_ssp_start();
if (jornada_ssp_byte(GETCONTRAST) != TXDUMMY) {
pr_err("get contrast failed\n");
jornada_ssp_end();
return -ETIMEDOUT;
} else {
ret = jornada_ssp_byte(TXDUMMY);
jornada_ssp_end();
return ret;
}
}
static int jornada_lcd_set_contrast(struct lcd_device *dev, int value)
{
int ret;
jornada_ssp_start();
ret = jornada_ssp_byte(SETCONTRAST);
if (jornada_ssp_byte(value) != TXDUMMY) {
pr_err("set contrast failed\n");
jornada_ssp_end();
return -ETIMEDOUT;
}
jornada_ssp_end();
return 0;
}
static int jornada_lcd_set_power(struct lcd_device *dev, int power)
{
if (power != FB_BLANK_UNBLANK) {
PPSR &= ~PPC_LDD2;
PPDR |= PPC_LDD2;
} else
PPSR |= PPC_LDD2;
return 0;
}
static int jornada_lcd_probe(struct platform_device *pdev)
{
struct lcd_device *lcd_device;
int ret;
lcd_device = lcd_device_register(S1D_DEVICENAME, &pdev->dev, NULL, &jornada_lcd_props);
if (IS_ERR(lcd_device)) {
ret = PTR_ERR(lcd_device);
pr_err("failed to register device\n");
return ret;
}
platform_set_drvdata(pdev, lcd_device);
jornada_lcd_set_contrast(lcd_device, LCD_DEF_CONTRAST);
jornada_lcd_set_power(lcd_device, FB_BLANK_UNBLANK);
msleep(100);
return 0;
}
static int jornada_lcd_remove(struct platform_device *pdev)
{
struct lcd_device *lcd_device = platform_get_drvdata(pdev);
lcd_device_unregister(lcd_device);
return 0;
}
