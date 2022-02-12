static void
menf21bmc_led_set(struct led_classdev *led_cdev, enum led_brightness value)
{
int led_val;
struct menf21bmc_led *led = container_of(led_cdev,
struct menf21bmc_led, cdev);
mutex_lock(&led_lock);
led_val = i2c_smbus_read_byte_data(led->i2c_client,
BMC_CMD_LED_GET_SET);
if (led_val < 0)
goto err_out;
if (value == LED_OFF)
led_val &= ~led->led_bit;
else
led_val |= led->led_bit;
i2c_smbus_write_byte_data(led->i2c_client,
BMC_CMD_LED_GET_SET, led_val);
err_out:
mutex_unlock(&led_lock);
}
static int menf21bmc_led_probe(struct platform_device *pdev)
{
int i;
int ret;
struct i2c_client *i2c_client = to_i2c_client(pdev->dev.parent);
for (i = 0; i < ARRAY_SIZE(leds); i++) {
leds[i].cdev.name = leds[i].name;
leds[i].cdev.brightness_set = menf21bmc_led_set;
leds[i].i2c_client = i2c_client;
ret = devm_led_classdev_register(&pdev->dev, &leds[i].cdev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register LED device\n");
return ret;
}
}
dev_info(&pdev->dev, "MEN 140F21P00 BMC LED device enabled\n");
return 0;
}
