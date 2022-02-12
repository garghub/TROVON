static void pca9633_led_work(struct work_struct *work)
{
struct pca9633_led *pca9633 = container_of(work,
struct pca9633_led, work);
u8 ledout = i2c_smbus_read_byte_data(pca9633->client, PCA9633_LEDOUT);
int shift = 2 * pca9633->led_num;
u8 mask = 0x3 << shift;
switch (pca9633->brightness) {
case LED_FULL:
i2c_smbus_write_byte_data(pca9633->client, PCA9633_LEDOUT,
(ledout & ~mask) | (PCA9633_LED_ON << shift));
break;
case LED_OFF:
i2c_smbus_write_byte_data(pca9633->client, PCA9633_LEDOUT,
ledout & ~mask);
break;
default:
i2c_smbus_write_byte_data(pca9633->client,
PCA9633_PWM_BASE + pca9633->led_num,
pca9633->brightness);
i2c_smbus_write_byte_data(pca9633->client, PCA9633_LEDOUT,
(ledout & ~mask) | (PCA9633_LED_PWM << shift));
break;
}
}
static void pca9633_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct pca9633_led *pca9633;
pca9633 = container_of(led_cdev, struct pca9633_led, led_cdev);
pca9633->brightness = value;
schedule_work(&pca9633->work);
}
static int __devinit pca9633_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pca9633_led *pca9633;
struct pca9633_platform_data *pdata;
int i, err;
pdata = client->dev.platform_data;
if (pdata) {
if (pdata->leds.num_leds <= 0 || pdata->leds.num_leds > 4) {
dev_err(&client->dev, "board info must claim at most 4 LEDs");
return -EINVAL;
}
}
pca9633 = devm_kzalloc(&client->dev, 4 * sizeof(*pca9633), GFP_KERNEL);
if (!pca9633)
return -ENOMEM;
i2c_set_clientdata(client, pca9633);
for (i = 0; i < 4; i++) {
pca9633[i].client = client;
pca9633[i].led_num = i;
if (pdata && i < pdata->leds.num_leds) {
if (pdata->leds.leds[i].name)
snprintf(pca9633[i].name,
sizeof(pca9633[i].name), "pca9633:%s",
pdata->leds.leds[i].name);
if (pdata->leds.leds[i].default_trigger)
pca9633[i].led_cdev.default_trigger =
pdata->leds.leds[i].default_trigger;
} else {
snprintf(pca9633[i].name, sizeof(pca9633[i].name),
"pca9633:%d", i);
}
pca9633[i].led_cdev.name = pca9633[i].name;
pca9633[i].led_cdev.brightness_set = pca9633_led_set;
INIT_WORK(&pca9633[i].work, pca9633_led_work);
err = led_classdev_register(&client->dev, &pca9633[i].led_cdev);
if (err < 0)
goto exit;
}
i2c_smbus_write_byte_data(client, PCA9633_MODE1, 0x00);
if (pdata && pdata->outdrv == PCA9633_OPEN_DRAIN)
i2c_smbus_write_byte_data(client, PCA9633_MODE2, 0x01);
i2c_smbus_write_byte_data(client, PCA9633_LEDOUT, 0x00);
return 0;
exit:
while (i--) {
led_classdev_unregister(&pca9633[i].led_cdev);
cancel_work_sync(&pca9633[i].work);
}
return err;
}
static int __devexit pca9633_remove(struct i2c_client *client)
{
struct pca9633_led *pca9633 = i2c_get_clientdata(client);
int i;
for (i = 0; i < 4; i++) {
led_classdev_unregister(&pca9633[i].led_cdev);
cancel_work_sync(&pca9633[i].work);
}
return 0;
}
