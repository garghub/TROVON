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
ret = led_classdev_register(&pdev->dev, &fsg_wlan_led);
if (ret < 0)
goto failwlan;
ret = led_classdev_register(&pdev->dev, &fsg_wan_led);
if (ret < 0)
goto failwan;
ret = led_classdev_register(&pdev->dev, &fsg_sata_led);
if (ret < 0)
goto failsata;
ret = led_classdev_register(&pdev->dev, &fsg_usb_led);
if (ret < 0)
goto failusb;
ret = led_classdev_register(&pdev->dev, &fsg_sync_led);
if (ret < 0)
goto failsync;
ret = led_classdev_register(&pdev->dev, &fsg_ring_led);
if (ret < 0)
goto failring;
return ret;
failring:
led_classdev_unregister(&fsg_sync_led);
failsync:
led_classdev_unregister(&fsg_usb_led);
failusb:
led_classdev_unregister(&fsg_sata_led);
failsata:
led_classdev_unregister(&fsg_wan_led);
failwan:
led_classdev_unregister(&fsg_wlan_led);
failwlan:
return ret;
}
static int fsg_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&fsg_wlan_led);
led_classdev_unregister(&fsg_wan_led);
led_classdev_unregister(&fsg_sata_led);
led_classdev_unregister(&fsg_usb_led);
led_classdev_unregister(&fsg_sync_led);
led_classdev_unregister(&fsg_ring_led);
return 0;
}
