static int lp3944_reg_read(struct i2c_client *client, u8 reg, u8 *value)
{
int tmp;
tmp = i2c_smbus_read_byte_data(client, reg);
if (tmp < 0)
return tmp;
*value = tmp;
return 0;
}
static int lp3944_reg_write(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static int lp3944_dim_set_period(struct i2c_client *client, u8 dim, u16 period)
{
u8 psc_reg;
u8 psc_value;
int err;
if (dim == LP3944_DIM0)
psc_reg = LP3944_REG_PSC0;
else if (dim == LP3944_DIM1)
psc_reg = LP3944_REG_PSC1;
else
return -EINVAL;
if (period > LP3944_PERIOD_MAX)
return -EINVAL;
psc_value = (period * 255) / LP3944_PERIOD_MAX;
err = lp3944_reg_write(client, psc_reg, psc_value);
return err;
}
static int lp3944_dim_set_dutycycle(struct i2c_client *client, u8 dim,
u8 duty_cycle)
{
u8 pwm_reg;
u8 pwm_value;
int err;
if (dim == LP3944_DIM0)
pwm_reg = LP3944_REG_PWM0;
else if (dim == LP3944_DIM1)
pwm_reg = LP3944_REG_PWM1;
else
return -EINVAL;
if (duty_cycle > LP3944_DUTY_CYCLE_MAX)
return -EINVAL;
pwm_value = (duty_cycle * 255) / LP3944_DUTY_CYCLE_MAX;
err = lp3944_reg_write(client, pwm_reg, pwm_value);
return err;
}
static int lp3944_led_set(struct lp3944_led_data *led, u8 status)
{
struct lp3944_data *data = i2c_get_clientdata(led->client);
u8 id = led->id;
u8 reg;
u8 val = 0;
int err;
dev_dbg(&led->client->dev, "%s: %s, status before normalization:%d\n",
__func__, led->ldev.name, status);
switch (id) {
case LP3944_LED0:
case LP3944_LED1:
case LP3944_LED2:
case LP3944_LED3:
reg = LP3944_REG_LS0;
break;
case LP3944_LED4:
case LP3944_LED5:
case LP3944_LED6:
case LP3944_LED7:
id -= LP3944_LED4;
reg = LP3944_REG_LS1;
break;
default:
return -EINVAL;
}
if (status > LP3944_LED_STATUS_DIM1)
return -EINVAL;
if (led->type == LP3944_LED_TYPE_LED_INVERTED && status < 2)
status = 1 - status;
mutex_lock(&data->lock);
lp3944_reg_read(led->client, reg, &val);
val &= ~(LP3944_LED_STATUS_MASK << (id << 1));
val |= (status << (id << 1));
dev_dbg(&led->client->dev, "%s: %s, reg:%d id:%d status:%d val:%#x\n",
__func__, led->ldev.name, reg, id, status, val);
err = lp3944_reg_write(led->client, reg, val);
mutex_unlock(&data->lock);
return err;
}
static int lp3944_led_set_blink(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct lp3944_led_data *led = ldev_to_led(led_cdev);
u16 period;
u8 duty_cycle;
int err;
if (*delay_on + *delay_off > LP3944_PERIOD_MAX)
return -EINVAL;
if (*delay_on == 0 && *delay_off == 0) {
*delay_on = 500;
*delay_off = 500;
}
period = (*delay_on) + (*delay_off);
duty_cycle = 100 * (*delay_on) / period;
if (led->type == LP3944_LED_TYPE_LED_INVERTED)
duty_cycle = 100 - duty_cycle;
err = lp3944_dim_set_period(led->client, LP3944_DIM0, period);
if (err)
return err;
err = lp3944_dim_set_dutycycle(led->client, LP3944_DIM0, duty_cycle);
if (err)
return err;
dev_dbg(&led->client->dev, "%s: OK hardware accelerated blink!\n",
__func__);
lp3944_led_set(led, LP3944_LED_STATUS_DIM0);
return 0;
}
static int lp3944_led_set_brightness(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct lp3944_led_data *led = ldev_to_led(led_cdev);
dev_dbg(&led->client->dev, "%s: %s, %d\n",
__func__, led_cdev->name, brightness);
return lp3944_led_set(led, !!brightness);
}
static int lp3944_configure(struct i2c_client *client,
struct lp3944_data *data,
struct lp3944_platform_data *pdata)
{
int i, err = 0;
for (i = 0; i < pdata->leds_size; i++) {
struct lp3944_led *pled = &pdata->leds[i];
struct lp3944_led_data *led = &data->leds[i];
led->client = client;
led->id = i;
switch (pled->type) {
case LP3944_LED_TYPE_LED:
case LP3944_LED_TYPE_LED_INVERTED:
led->type = pled->type;
led->ldev.name = pled->name;
led->ldev.max_brightness = 1;
led->ldev.brightness_set_blocking =
lp3944_led_set_brightness;
led->ldev.blink_set = lp3944_led_set_blink;
led->ldev.flags = LED_CORE_SUSPENDRESUME;
err = led_classdev_register(&client->dev, &led->ldev);
if (err < 0) {
dev_err(&client->dev,
"couldn't register LED %s\n",
led->ldev.name);
goto exit;
}
led->ldev.brightness =
(enum led_brightness) pled->status;
err = lp3944_led_set(led, pled->status);
if (err < 0) {
dev_err(&client->dev,
"%s couldn't set STATUS %d\n",
led->ldev.name, pled->status);
goto exit;
}
break;
case LP3944_LED_TYPE_NONE:
default:
break;
}
}
return 0;
exit:
if (i > 0)
for (i = i - 1; i >= 0; i--)
switch (pdata->leds[i].type) {
case LP3944_LED_TYPE_LED:
case LP3944_LED_TYPE_LED_INVERTED:
led_classdev_unregister(&data->leds[i].ldev);
break;
case LP3944_LED_TYPE_NONE:
default:
break;
}
return err;
}
static int lp3944_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lp3944_platform_data *lp3944_pdata =
dev_get_platdata(&client->dev);
struct lp3944_data *data;
int err;
if (lp3944_pdata == NULL) {
dev_err(&client->dev, "no platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev, "insufficient functionality!\n");
return -ENODEV;
}
data = devm_kzalloc(&client->dev, sizeof(struct lp3944_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
err = lp3944_configure(client, data, lp3944_pdata);
if (err < 0)
return err;
dev_info(&client->dev, "lp3944 enabled\n");
return 0;
}
static int lp3944_remove(struct i2c_client *client)
{
struct lp3944_platform_data *pdata = dev_get_platdata(&client->dev);
struct lp3944_data *data = i2c_get_clientdata(client);
int i;
for (i = 0; i < pdata->leds_size; i++)
switch (data->leds[i].type) {
case LP3944_LED_TYPE_LED:
case LP3944_LED_TYPE_LED_INVERTED:
led_classdev_unregister(&data->leds[i].ldev);
break;
case LP3944_LED_TYPE_NONE:
default:
break;
}
return 0;
}
