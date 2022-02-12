static int __init ts5500_check_signature(void)
{
void __iomem *bios;
int i, ret = -ENODEV;
bios = ioremap(0xf0000, 0x10000);
if (!bios)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(ts5500_signatures); i++) {
if (check_signature(bios + ts5500_signatures[i].offset,
ts5500_signatures[i].string,
strlen(ts5500_signatures[i].string))) {
ret = 0;
break;
}
}
iounmap(bios);
return ret;
}
static int __init ts5500_detect_config(struct ts5500_sbc *sbc)
{
u8 tmp;
int ret = 0;
if (!request_region(TS5500_PRODUCT_CODE_ADDR, 4, "ts5500"))
return -EBUSY;
sbc->id = inb(TS5500_PRODUCT_CODE_ADDR);
if (sbc->id == TS5500_PRODUCT_CODE) {
sbc->name = "TS-5500";
} else if (sbc->id == TS5400_PRODUCT_CODE) {
sbc->name = "TS-5400";
} else {
pr_err("ts5500: unknown product code 0x%x\n", sbc->id);
ret = -ENODEV;
goto cleanup;
}
tmp = inb(TS5500_SRAM_RS485_ADC_ADDR);
sbc->sram = tmp & TS5500_SRAM;
sbc->rs485 = tmp & TS5500_RS485;
sbc->adc = tmp & TS5500_ADC;
tmp = inb(TS5500_ERESET_ITR_ADDR);
sbc->ereset = tmp & TS5500_ERESET;
sbc->itr = tmp & TS5500_ITR;
tmp = inb(TS5500_LED_JP_ADDR);
sbc->jumpers = tmp & ~TS5500_LED;
cleanup:
release_region(TS5500_PRODUCT_CODE_ADDR, 4);
return ret;
}
static ssize_t name_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct ts5500_sbc *sbc = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", sbc->name);
}
static ssize_t id_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct ts5500_sbc *sbc = dev_get_drvdata(dev);
return sprintf(buf, "0x%.2x\n", sbc->id);
}
static ssize_t jumpers_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct ts5500_sbc *sbc = dev_get_drvdata(dev);
return sprintf(buf, "0x%.2x\n", sbc->jumpers >> 1);
}
static void ts5500_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
outb(!!brightness, TS5500_LED_JP_ADDR);
}
static enum led_brightness ts5500_led_get(struct led_classdev *led_cdev)
{
return (inb(TS5500_LED_JP_ADDR) & TS5500_LED) ? LED_FULL : LED_OFF;
}
static int ts5500_adc_convert(u8 ctrl)
{
u8 lsb, msb;
outb(ctrl & 0x1f, TS5500_ADC_CONV_INIT_LSB_ADDR);
udelay(TS5500_ADC_CONV_DELAY);
if (inb(TS5500_ADC_CONV_BUSY_ADDR) & TS5500_ADC_CONV_BUSY)
return -EBUSY;
lsb = inb(TS5500_ADC_CONV_INIT_LSB_ADDR);
msb = inb(TS5500_ADC_CONV_MSB_ADDR);
return (msb << 8) | lsb;
}
static int __init ts5500_init(void)
{
struct platform_device *pdev;
struct ts5500_sbc *sbc;
int err;
err = ts5500_check_signature();
if (err)
return err;
pdev = platform_device_register_simple("ts5500", -1, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
sbc = devm_kzalloc(&pdev->dev, sizeof(struct ts5500_sbc), GFP_KERNEL);
if (!sbc) {
err = -ENOMEM;
goto error;
}
err = ts5500_detect_config(sbc);
if (err)
goto error;
platform_set_drvdata(pdev, sbc);
err = sysfs_create_group(&pdev->dev.kobj, &ts5500_attr_group);
if (err)
goto error;
if (sbc->id == TS5500_PRODUCT_CODE) {
ts5500_dio1_pdev.dev.parent = &pdev->dev;
if (platform_device_register(&ts5500_dio1_pdev))
dev_warn(&pdev->dev, "DIO1 block registration failed\n");
ts5500_dio2_pdev.dev.parent = &pdev->dev;
if (platform_device_register(&ts5500_dio2_pdev))
dev_warn(&pdev->dev, "DIO2 block registration failed\n");
}
if (led_classdev_register(&pdev->dev, &ts5500_led_cdev))
dev_warn(&pdev->dev, "LED registration failed\n");
if (sbc->adc) {
ts5500_adc_pdev.dev.parent = &pdev->dev;
if (platform_device_register(&ts5500_adc_pdev))
dev_warn(&pdev->dev, "ADC registration failed\n");
}
return 0;
error:
platform_device_unregister(pdev);
return err;
}
