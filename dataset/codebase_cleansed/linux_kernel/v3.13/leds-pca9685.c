static void pca9685_write_msg(struct i2c_client *client, u8 *buf, u8 len)
{
struct i2c_msg msg = {
.addr = client->addr,
.flags = 0x00,
.len = len,
.buf = buf
};
i2c_transfer(client->adapter, &msg, 1);
}
static void pca9685_all_off(struct i2c_client *client)
{
u8 i2c_buffer[5] = {PCA9685_ALL_LED_ON_L, 0x00, 0x00, 0x00, 0x10};
pca9685_write_msg(client, i2c_buffer, 5);
}
static void pca9685_led_work(struct work_struct *work)
{
struct pca9685_led *pca9685;
u8 i2c_buffer[5];
pca9685 = container_of(work, struct pca9685_led, work);
i2c_buffer[0] = PCA9685_LED0_ON_L + 4 * pca9685->led_num;
if (pca9685->brightness == 4095)
*((__le16 *)(i2c_buffer+1)) = cpu_to_le16(0x1000);
else
*((__le16 *)(i2c_buffer+1)) = 0x0000;
if (pca9685->brightness == 0)
*((__le16 *)(i2c_buffer+3)) = cpu_to_le16(0x1000);
else if (pca9685->brightness == 4095)
*((__le16 *)(i2c_buffer+3)) = 0x0000;
else
*((__le16 *)(i2c_buffer+3)) = cpu_to_le16(pca9685->brightness);
pca9685_write_msg(pca9685->client, i2c_buffer, 5);
}
static void pca9685_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct pca9685_led *pca9685;
pca9685 = container_of(led_cdev, struct pca9685_led, led_cdev);
pca9685->brightness = value;
schedule_work(&pca9685->work);
}
static int pca9685_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pca9685_led *pca9685;
struct pca9685_platform_data *pdata;
int err;
u8 i;
pdata = dev_get_platdata(&client->dev);
if (pdata) {
if (pdata->leds.num_leds < 1 || pdata->leds.num_leds > 15) {
dev_err(&client->dev, "board info must claim 1-16 LEDs");
return -EINVAL;
}
}
pca9685 = devm_kzalloc(&client->dev, 16 * sizeof(*pca9685), GFP_KERNEL);
if (!pca9685)
return -ENOMEM;
i2c_set_clientdata(client, pca9685);
pca9685_all_off(client);
for (i = 0; i < 16; i++) {
pca9685[i].client = client;
pca9685[i].led_num = i;
pca9685[i].name[0] = '\0';
if (pdata && i < pdata->leds.num_leds) {
if (pdata->leds.leds[i].name)
strncpy(pca9685[i].name,
pdata->leds.leds[i].name,
sizeof(pca9685[i].name)-1);
if (pdata->leds.leds[i].default_trigger)
pca9685[i].led_cdev.default_trigger =
pdata->leds.leds[i].default_trigger;
}
if (strlen(pca9685[i].name) == 0) {
snprintf(pca9685[i].name, sizeof(pca9685[i].name),
"pca9685:%d:x%.2x:%d",
client->adapter->nr, client->addr, i);
}
pca9685[i].led_cdev.name = pca9685[i].name;
pca9685[i].led_cdev.max_brightness = 0xfff;
pca9685[i].led_cdev.brightness_set = pca9685_led_set;
INIT_WORK(&pca9685[i].work, pca9685_led_work);
err = led_classdev_register(&client->dev, &pca9685[i].led_cdev);
if (err < 0)
goto exit;
}
if (pdata)
i2c_smbus_write_byte_data(client, PCA9685_MODE2,
pdata->outdrv << PCA9685_OUTDRV |
pdata->inverted << PCA9685_INVRT);
else
i2c_smbus_write_byte_data(client, PCA9685_MODE2,
PCA9685_TOTEM_POLE << PCA9685_OUTDRV);
i2c_smbus_write_byte_data(client, PCA9685_MODE1, BIT(PCA9685_AI));
return 0;
exit:
while (i--) {
led_classdev_unregister(&pca9685[i].led_cdev);
cancel_work_sync(&pca9685[i].work);
}
return err;
}
static int pca9685_remove(struct i2c_client *client)
{
struct pca9685_led *pca9685 = i2c_get_clientdata(client);
u8 i;
for (i = 0; i < 16; i++) {
led_classdev_unregister(&pca9685[i].led_cdev);
cancel_work_sync(&pca9685[i].work);
}
pca9685_all_off(client);
return 0;
}
