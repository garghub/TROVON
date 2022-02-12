static int jornada_lcd_get_power(struct lcd_device *ld)
{
return PPSR & PPC_LDD2 ? FB_BLANK_UNBLANK : FB_BLANK_POWERDOWN;
}
static int jornada_lcd_get_contrast(struct lcd_device *ld)
{
int ret;
if (jornada_lcd_get_power(ld) != FB_BLANK_UNBLANK)
return 0;
jornada_ssp_start();
if (jornada_ssp_byte(GETCONTRAST) == TXDUMMY) {
ret = jornada_ssp_byte(TXDUMMY);
goto success;
}
dev_err(&ld->dev, "failed to set contrast\n");
ret = -ETIMEDOUT;
success:
jornada_ssp_end();
return ret;
}
static int jornada_lcd_set_contrast(struct lcd_device *ld, int value)
{
int ret = 0;
jornada_ssp_start();
if (jornada_ssp_byte(SETCONTRAST) == TXDUMMY) {
if (jornada_ssp_byte(value) == TXDUMMY)
goto success;
}
dev_err(&ld->dev, "failed to set contrast\n");
ret = -ETIMEDOUT;
success:
jornada_ssp_end();
return ret;
}
static int jornada_lcd_set_power(struct lcd_device *ld, int power)
{
if (power != FB_BLANK_UNBLANK) {
PPSR &= ~PPC_LDD2;
PPDR |= PPC_LDD2;
} else {
PPSR |= PPC_LDD2;
}
return 0;
}
static int jornada_lcd_probe(struct platform_device *pdev)
{
struct lcd_device *lcd_device;
int ret;
lcd_device = devm_lcd_device_register(&pdev->dev, S1D_DEVICENAME,
&pdev->dev, NULL, &jornada_lcd_props);
if (IS_ERR(lcd_device)) {
ret = PTR_ERR(lcd_device);
dev_err(&pdev->dev, "failed to register device\n");
return ret;
}
platform_set_drvdata(pdev, lcd_device);
jornada_lcd_set_contrast(lcd_device, LCD_DEF_CONTRAST);
jornada_lcd_set_power(lcd_device, FB_BLANK_UNBLANK);
msleep(100);
return 0;
}
