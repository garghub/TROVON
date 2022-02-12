static int lp8860_unlock_eeprom(struct lp8860_led *led, int lock)
{
int ret;
mutex_lock(&led->lock);
if (lock == LP8860_UNLOCK_EEPROM) {
ret = regmap_write(led->regmap,
LP8860_EEPROM_UNLOCK,
LP8860_EEPROM_CODE_1);
if (ret) {
dev_err(&led->client->dev, "EEPROM Unlock failed\n");
goto out;
}
ret = regmap_write(led->regmap,
LP8860_EEPROM_UNLOCK,
LP8860_EEPROM_CODE_2);
if (ret) {
dev_err(&led->client->dev, "EEPROM Unlock failed\n");
goto out;
}
ret = regmap_write(led->regmap,
LP8860_EEPROM_UNLOCK,
LP8860_EEPROM_CODE_3);
if (ret) {
dev_err(&led->client->dev, "EEPROM Unlock failed\n");
goto out;
}
} else {
ret = regmap_write(led->regmap,
LP8860_EEPROM_UNLOCK,
LP8860_LOCK_EEPROM);
}
out:
mutex_unlock(&led->lock);
return ret;
}
static int lp8860_fault_check(struct lp8860_led *led)
{
int ret, fault;
unsigned int read_buf;
ret = regmap_read(led->regmap, LP8860_LED_FAULT, &read_buf);
if (ret)
goto out;
fault = read_buf;
ret = regmap_read(led->regmap, LP8860_FAULT, &read_buf);
if (ret)
goto out;
fault |= read_buf;
if (fault)
ret = regmap_write(led->regmap, LP8860_FAULT_CLEAR,
LP8860_CLEAR_FAULTS);
out:
return ret;
}
static void lp8860_led_brightness_work(struct work_struct *work)
{
struct lp8860_led *led = container_of(work, struct lp8860_led, work);
int ret;
int disp_brightness = led->brightness * 255;
mutex_lock(&led->lock);
ret = lp8860_fault_check(led);
if (ret) {
dev_err(&led->client->dev, "Cannot read/clear faults\n");
goto out;
}
ret = regmap_write(led->regmap, LP8860_DISP_CL1_BRT_MSB,
(disp_brightness & 0xff00) >> 8);
if (ret) {
dev_err(&led->client->dev, "Cannot write CL1 MSB\n");
goto out;
}
ret = regmap_write(led->regmap, LP8860_DISP_CL1_BRT_LSB,
disp_brightness & 0xff);
if (ret) {
dev_err(&led->client->dev, "Cannot write CL1 LSB\n");
goto out;
}
out:
mutex_unlock(&led->lock);
}
static void lp8860_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brt_val)
{
struct lp8860_led *led =
container_of(led_cdev, struct lp8860_led, led_dev);
led->brightness = brt_val;
schedule_work(&led->work);
}
static int lp8860_init(struct lp8860_led *led)
{
unsigned int read_buf;
int ret, i, reg_count;
if (led->enable_gpio)
gpiod_direction_output(led->enable_gpio, 1);
ret = lp8860_fault_check(led);
if (ret)
goto out;
ret = regmap_read(led->regmap, LP8860_STATUS, &read_buf);
if (ret)
goto out;
ret = lp8860_unlock_eeprom(led, LP8860_UNLOCK_EEPROM);
if (ret) {
dev_err(&led->client->dev, "Failed unlocking EEPROM\n");
goto out;
}
reg_count = ARRAY_SIZE(lp8860_eeprom_disp_regs) / sizeof(lp8860_eeprom_disp_regs[0]);
for (i = 0; i < reg_count; i++) {
ret = regmap_write(led->eeprom_regmap,
lp8860_eeprom_disp_regs[i].reg,
lp8860_eeprom_disp_regs[i].value);
if (ret) {
dev_err(&led->client->dev, "Failed writing EEPROM\n");
goto out;
}
}
ret = lp8860_unlock_eeprom(led, LP8860_LOCK_EEPROM);
if (ret)
goto out;
ret = regmap_write(led->regmap,
LP8860_EEPROM_CNTRL,
LP8860_PROGRAM_EEPROM);
if (ret)
dev_err(&led->client->dev, "Failed programming EEPROM\n");
out:
if (ret)
if (led->enable_gpio)
gpiod_direction_output(led->enable_gpio, 0);
return ret;
}
static int lp8860_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct lp8860_led *led;
struct device_node *np = client->dev.of_node;
led = devm_kzalloc(&client->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->label = LP8860_DISP_LED_NAME;
if (client->dev.of_node) {
ret = of_property_read_string(np, "label", &led->label);
if (ret) {
dev_err(&client->dev, "Missing label in dt\n");
return -EINVAL;
}
}
led->enable_gpio = devm_gpiod_get(&client->dev, "enable");
if (IS_ERR(led->enable_gpio))
led->enable_gpio = NULL;
else
gpiod_direction_output(led->enable_gpio, 0);
led->regulator = devm_regulator_get(&client->dev, "vled");
if (IS_ERR(led->regulator))
led->regulator = NULL;
led->client = client;
led->led_dev.name = led->label;
led->led_dev.max_brightness = LED_FULL;
led->led_dev.brightness_set = lp8860_brightness_set;
mutex_init(&led->lock);
INIT_WORK(&led->work, lp8860_led_brightness_work);
i2c_set_clientdata(client, led);
led->regmap = devm_regmap_init_i2c(client, &lp8860_regmap_config);
if (IS_ERR(led->regmap)) {
ret = PTR_ERR(led->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
led->eeprom_regmap = devm_regmap_init_i2c(client, &lp8860_eeprom_regmap_config);
if (IS_ERR(led->eeprom_regmap)) {
ret = PTR_ERR(led->eeprom_regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = lp8860_init(led);
if (ret)
return ret;
ret = led_classdev_register(&client->dev, &led->led_dev);
if (ret) {
dev_err(&client->dev, "led register err: %d\n", ret);
return ret;
}
return 0;
}
static int lp8860_remove(struct i2c_client *client)
{
struct lp8860_led *led = i2c_get_clientdata(client);
int ret;
led_classdev_unregister(&led->led_dev);
cancel_work_sync(&led->work);
if (led->enable_gpio)
gpiod_direction_output(led->enable_gpio, 0);
if (led->regulator) {
ret = regulator_disable(led->regulator);
if (ret)
dev_err(&led->client->dev,
"Failed to disable regulator\n");
}
return 0;
}
