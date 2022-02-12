static void fsg_led_wlan_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value) {
latch_value &= ~(1 << FSG_LED_WLAN_BIT);
*latch_address = latch_value;
} else {
latch_value |= (1 << FSG_LED_WLAN_BIT);
*latch_address = latch_value;
}
}
static void fsg_led_wan_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value) {
latch_value &= ~(1 << FSG_LED_WAN_BIT);
*latch_address = latch_value;
} else {
latch_value |= (1 << FSG_LED_WAN_BIT);
*latch_address = latch_value;
}
}
static void fsg_led_sata_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value) {
latch_value &= ~(1 << FSG_LED_SATA_BIT);
*latch_address = latch_value;
} else {
latch_value |= (1 << FSG_LED_SATA_BIT);
*latch_address = latch_value;
}
}
static void fsg_led_usb_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value) {
latch_value &= ~(1 << FSG_LED_USB_BIT);
*latch_address = latch_value;
} else {
latch_value |= (1 << FSG_LED_USB_BIT);
*latch_address = latch_value;
}
}
static void fsg_led_sync_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value) {
latch_value &= ~(1 << FSG_LED_SYNC_BIT);
*latch_address = latch_value;
} else {
latch_value |= (1 << FSG_LED_SYNC_BIT);
*latch_address = latch_value;
}
}
static void fsg_led_ring_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value) {
latch_value &= ~(1 << FSG_LED_RING_BIT);
*latch_address = latch_value;
} else {
latch_value |= (1 << FSG_LED_RING_BIT);
*latch_address = latch_value;
}
}
static int fsg_led_probe(struct platform_device *pdev)
{
int ret;
latch_address = (unsigned short *) devm_ioremap(&pdev->dev,
IXP4XX_EXP_BUS_BASE(2), 512);
if (!latch_address)
return -ENOMEM;
latch_value = 0xffff;
*latch_address = latch_value;
ret = devm_led_classdev_register(&pdev->dev, &fsg_wlan_led);
if (ret < 0)
return ret;
ret = devm_led_classdev_register(&pdev->dev, &fsg_wan_led);
if (ret < 0)
return ret;
ret = devm_led_classdev_register(&pdev->dev, &fsg_sata_led);
if (ret < 0)
return ret;
ret = devm_led_classdev_register(&pdev->dev, &fsg_usb_led);
if (ret < 0)
return ret;
ret = devm_led_classdev_register(&pdev->dev, &fsg_sync_led);
if (ret < 0)
return ret;
ret = devm_led_classdev_register(&pdev->dev, &fsg_ring_led);
if (ret < 0)
return ret;
return ret;
}
