static int cr_backlight_set_intensity(struct backlight_device *bd)
{
int intensity = bd->props.brightness;
u32 addr = gpio_bar + CRVML_PANEL_PORT;
u32 cur = inl(addr);
if (bd->props.power == FB_BLANK_UNBLANK)
intensity = FB_BLANK_UNBLANK;
if (bd->props.fb_blank == FB_BLANK_UNBLANK)
intensity = FB_BLANK_UNBLANK;
if (bd->props.power == FB_BLANK_POWERDOWN)
intensity = FB_BLANK_POWERDOWN;
if (bd->props.fb_blank == FB_BLANK_POWERDOWN)
intensity = FB_BLANK_POWERDOWN;
if (intensity == FB_BLANK_UNBLANK) {
cur &= ~CRVML_BACKLIGHT_OFF;
outl(cur, addr);
} else if (intensity == FB_BLANK_POWERDOWN) {
cur |= CRVML_BACKLIGHT_OFF;
outl(cur, addr);
}
return 0;
}
static int cr_backlight_get_intensity(struct backlight_device *bd)
{
u32 addr = gpio_bar + CRVML_PANEL_PORT;
u32 cur = inl(addr);
u8 intensity;
if (cur & CRVML_BACKLIGHT_OFF)
intensity = FB_BLANK_POWERDOWN;
else
intensity = FB_BLANK_UNBLANK;
return intensity;
}
static void cr_panel_on(void)
{
u32 addr = gpio_bar + CRVML_PANEL_PORT;
u32 cur = inl(addr);
if (!(cur & CRVML_PANEL_ON)) {
if (cur & 0x00000001) {
cur &= ~CRVML_LVDS_ON;
outl(cur, addr);
}
schedule_timeout(HZ / 10);
cur |= CRVML_PANEL_ON;
outl(cur, addr);
}
if (!(cur & CRVML_LVDS_ON)) {
schedule_timeout(HZ / 10);
outl(cur | CRVML_LVDS_ON, addr);
}
}
static void cr_panel_off(void)
{
u32 addr = gpio_bar + CRVML_PANEL_PORT;
u32 cur = inl(addr);
if (cur & CRVML_LVDS_ON) {
cur &= ~CRVML_LVDS_ON;
outl(cur, addr);
}
if (cur & CRVML_PANEL_ON) {
schedule_timeout(HZ / 10);
outl(cur & ~CRVML_PANEL_ON, addr);
}
}
static int cr_lcd_set_power(struct lcd_device *ld, int power)
{
if (power == FB_BLANK_UNBLANK)
cr_panel_on();
if (power == FB_BLANK_POWERDOWN)
cr_panel_off();
return 0;
}
static int cr_backlight_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct backlight_device *bdp;
struct lcd_device *ldp;
struct cr_panel *crp;
u8 dev_en;
lpc_dev = pci_get_device(PCI_VENDOR_ID_INTEL,
CRVML_DEVICE_LPC, NULL);
if (!lpc_dev) {
pr_err("INTEL CARILLO RANCH LPC not found.\n");
return -ENODEV;
}
pci_read_config_byte(lpc_dev, CRVML_REG_GPIOEN, &dev_en);
if (!(dev_en & CRVML_GPIOEN_BIT)) {
pr_err("Carillo Ranch GPIO device was not enabled.\n");
pci_dev_put(lpc_dev);
return -ENODEV;
}
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
bdp = devm_backlight_device_register(&pdev->dev, "cr-backlight",
&pdev->dev, NULL, &cr_backlight_ops,
&props);
if (IS_ERR(bdp)) {
pci_dev_put(lpc_dev);
return PTR_ERR(bdp);
}
ldp = devm_lcd_device_register(&pdev->dev, "cr-lcd", &pdev->dev, NULL,
&cr_lcd_ops);
if (IS_ERR(ldp)) {
pci_dev_put(lpc_dev);
return PTR_ERR(ldp);
}
pci_read_config_dword(lpc_dev, CRVML_REG_GPIOBAR,
&gpio_bar);
gpio_bar &= ~0x3F;
crp = devm_kzalloc(&pdev->dev, sizeof(*crp), GFP_KERNEL);
if (!crp) {
pci_dev_put(lpc_dev);
return -ENOMEM;
}
crp->cr_backlight_device = bdp;
crp->cr_lcd_device = ldp;
crp->cr_backlight_device->props.power = FB_BLANK_UNBLANK;
crp->cr_backlight_device->props.brightness = 0;
cr_backlight_set_intensity(crp->cr_backlight_device);
cr_lcd_set_power(crp->cr_lcd_device, FB_BLANK_UNBLANK);
platform_set_drvdata(pdev, crp);
return 0;
}
static int cr_backlight_remove(struct platform_device *pdev)
{
struct cr_panel *crp = platform_get_drvdata(pdev);
crp->cr_backlight_device->props.power = FB_BLANK_POWERDOWN;
crp->cr_backlight_device->props.brightness = 0;
crp->cr_backlight_device->props.max_brightness = 0;
cr_backlight_set_intensity(crp->cr_backlight_device);
cr_lcd_set_power(crp->cr_lcd_device, FB_BLANK_POWERDOWN);
pci_dev_put(lpc_dev);
return 0;
}
static int __init cr_backlight_init(void)
{
int ret = platform_driver_register(&cr_backlight_driver);
if (ret)
return ret;
crp = platform_device_register_simple("cr_backlight", -1, NULL, 0);
if (IS_ERR(crp)) {
platform_driver_unregister(&cr_backlight_driver);
return PTR_ERR(crp);
}
pr_info("Carillo Ranch Backlight Driver Initialized.\n");
return 0;
}
static void __exit cr_backlight_exit(void)
{
platform_device_unregister(crp);
platform_driver_unregister(&cr_backlight_driver);
}
