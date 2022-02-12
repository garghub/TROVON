static int micro_leds_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct ipaq_micro *micro = dev_get_drvdata(led_cdev->dev->parent->parent);
struct ipaq_micro_msg msg = {
.id = MSG_NOTIFY_LED,
.tx_len = 4,
};
msg.tx_data[0] = LED_GREEN;
msg.tx_data[1] = 0;
if (value) {
msg.tx_data[2] = 0;
msg.tx_data[3] = 1;
} else {
msg.tx_data[2] = 1;
msg.tx_data[3] = 0;
}
return ipaq_micro_tx_msg_sync(micro, &msg);
}
static int micro_leds_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct ipaq_micro *micro = dev_get_drvdata(led_cdev->dev->parent->parent);
struct ipaq_micro_msg msg = {
.id = MSG_NOTIFY_LED,
.tx_len = 4,
};
msg.tx_data[0] = LED_GREEN;
if (*delay_on > IPAQ_LED_MAX_DUTY ||
*delay_off > IPAQ_LED_MAX_DUTY)
return -EINVAL;
if (*delay_on == 0 && *delay_off == 0) {
*delay_on = 100;
*delay_off = 100;
}
msg.tx_data[1] = 0;
if (*delay_on >= IPAQ_LED_MAX_DUTY)
msg.tx_data[2] = 0;
else
msg.tx_data[2] = (u8) DIV_ROUND_CLOSEST(*delay_on, 100);
if (*delay_off >= IPAQ_LED_MAX_DUTY)
msg.tx_data[3] = 0;
else
msg.tx_data[3] = (u8) DIV_ROUND_CLOSEST(*delay_off, 100);
return ipaq_micro_tx_msg_sync(micro, &msg);
}
static int micro_leds_probe(struct platform_device *pdev)
{
int ret;
ret = devm_led_classdev_register(&pdev->dev, &micro_led);
if (ret) {
dev_err(&pdev->dev, "registering led failed: %d\n", ret);
return ret;
}
dev_info(&pdev->dev, "iPAQ micro notification LED driver\n");
return 0;
}
