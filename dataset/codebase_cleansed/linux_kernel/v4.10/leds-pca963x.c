static int pca963x_brightness(struct pca963x_led *pca963x,
enum led_brightness brightness)
{
u8 ledout_addr = pca963x->chip->chipdef->ledout_base
+ (pca963x->led_num / 4);
u8 ledout;
int shift = 2 * (pca963x->led_num % 4);
u8 mask = 0x3 << shift;
int ret;
ledout = i2c_smbus_read_byte_data(pca963x->chip->client, ledout_addr);
switch (brightness) {
case LED_FULL:
ret = i2c_smbus_write_byte_data(pca963x->chip->client,
ledout_addr,
(ledout & ~mask) | (PCA963X_LED_ON << shift));
break;
case LED_OFF:
ret = i2c_smbus_write_byte_data(pca963x->chip->client,
ledout_addr, ledout & ~mask);
break;
default:
ret = i2c_smbus_write_byte_data(pca963x->chip->client,
PCA963X_PWM_BASE + pca963x->led_num,
brightness);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(pca963x->chip->client,
ledout_addr,
(ledout & ~mask) | (PCA963X_LED_PWM << shift));
break;
}
return ret;
}
static void pca963x_blink(struct pca963x_led *pca963x)
{
u8 ledout_addr = pca963x->chip->chipdef->ledout_base +
(pca963x->led_num / 4);
u8 ledout;
u8 mode2 = i2c_smbus_read_byte_data(pca963x->chip->client,
PCA963X_MODE2);
int shift = 2 * (pca963x->led_num % 4);
u8 mask = 0x3 << shift;
i2c_smbus_write_byte_data(pca963x->chip->client,
pca963x->chip->chipdef->grppwm, pca963x->gdc);
i2c_smbus_write_byte_data(pca963x->chip->client,
pca963x->chip->chipdef->grpfreq, pca963x->gfrq);
if (!(mode2 & PCA963X_MODE2_DMBLNK))
i2c_smbus_write_byte_data(pca963x->chip->client, PCA963X_MODE2,
mode2 | PCA963X_MODE2_DMBLNK);
mutex_lock(&pca963x->chip->mutex);
ledout = i2c_smbus_read_byte_data(pca963x->chip->client, ledout_addr);
if ((ledout & mask) != (PCA963X_LED_GRP_PWM << shift))
i2c_smbus_write_byte_data(pca963x->chip->client, ledout_addr,
(ledout & ~mask) | (PCA963X_LED_GRP_PWM << shift));
mutex_unlock(&pca963x->chip->mutex);
}
static int pca963x_power_state(struct pca963x_led *pca963x)
{
unsigned long *leds_on = &pca963x->chip->leds_on;
unsigned long cached_leds = pca963x->chip->leds_on;
if (pca963x->led_cdev.brightness)
set_bit(pca963x->led_num, leds_on);
else
clear_bit(pca963x->led_num, leds_on);
if (!(*leds_on) != !cached_leds)
return i2c_smbus_write_byte_data(pca963x->chip->client,
PCA963X_MODE1, *leds_on ? 0 : BIT(4));
return 0;
}
static int pca963x_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct pca963x_led *pca963x;
int ret;
pca963x = container_of(led_cdev, struct pca963x_led, led_cdev);
mutex_lock(&pca963x->chip->mutex);
ret = pca963x_brightness(pca963x, value);
if (ret < 0)
goto unlock;
ret = pca963x_power_state(pca963x);
unlock:
mutex_unlock(&pca963x->chip->mutex);
return ret;
}
static unsigned int pca963x_period_scale(struct pca963x_led *pca963x,
unsigned int val)
{
unsigned int scaling = pca963x->chip->chipdef->scaling;
return scaling ? DIV_ROUND_CLOSEST(val * scaling, 1000) : val;
}
static int pca963x_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on, unsigned long *delay_off)
{
struct pca963x_led *pca963x;
unsigned long time_on, time_off, period;
u8 gdc, gfrq;
pca963x = container_of(led_cdev, struct pca963x_led, led_cdev);
time_on = *delay_on;
time_off = *delay_off;
if (!time_on && !time_off) {
time_on = 500;
time_off = 500;
}
period = pca963x_period_scale(pca963x, time_on + time_off);
if ((period < PCA963X_BLINK_PERIOD_MIN) ||
(period > PCA963X_BLINK_PERIOD_MAX)) {
time_on = 500;
time_off = 500;
period = pca963x_period_scale(pca963x, 1000);
}
gdc = (pca963x_period_scale(pca963x, time_on) * 256) / period;
gfrq = (period * 24 / 1000) - 1;
pca963x->gdc = gdc;
pca963x->gfrq = gfrq;
pca963x_blink(pca963x);
*delay_on = time_on;
*delay_off = time_off;
return 0;
}
static struct pca963x_platform_data *
pca963x_dt_init(struct i2c_client *client, struct pca963x_chipdef *chip)
{
struct device_node *np = client->dev.of_node, *child;
struct pca963x_platform_data *pdata;
struct led_info *pca963x_leds;
int count;
count = of_get_child_count(np);
if (!count || count > chip->n_leds)
return ERR_PTR(-ENODEV);
pca963x_leds = devm_kzalloc(&client->dev,
sizeof(struct led_info) * chip->n_leds, GFP_KERNEL);
if (!pca963x_leds)
return ERR_PTR(-ENOMEM);
for_each_child_of_node(np, child) {
struct led_info led = {};
u32 reg;
int res;
res = of_property_read_u32(child, "reg", &reg);
if ((res != 0) || (reg >= chip->n_leds))
continue;
led.name =
of_get_property(child, "label", NULL) ? : child->name;
led.default_trigger =
of_get_property(child, "linux,default-trigger", NULL);
pca963x_leds[reg] = led;
}
pdata = devm_kzalloc(&client->dev,
sizeof(struct pca963x_platform_data), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->leds.leds = pca963x_leds;
pdata->leds.num_leds = chip->n_leds;
if (of_property_read_bool(np, "nxp,totem-pole"))
pdata->outdrv = PCA963X_TOTEM_POLE;
else
pdata->outdrv = PCA963X_OPEN_DRAIN;
if (of_property_read_bool(np, "nxp,hw-blink"))
pdata->blink_type = PCA963X_HW_BLINK;
else
pdata->blink_type = PCA963X_SW_BLINK;
if (of_property_read_u32(np, "nxp,period-scale", &chip->scaling))
chip->scaling = 1000;
return pdata;
}
static struct pca963x_platform_data *
pca963x_dt_init(struct i2c_client *client, struct pca963x_chipdef *chip)
{
return ERR_PTR(-ENODEV);
}
static int pca963x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pca963x *pca963x_chip;
struct pca963x_led *pca963x;
struct pca963x_platform_data *pdata;
struct pca963x_chipdef *chip;
int i, err;
if (id) {
chip = &pca963x_chipdefs[id->driver_data];
} else {
const struct acpi_device_id *acpi_id;
acpi_id = acpi_match_device(pca963x_acpi_ids, &client->dev);
if (!acpi_id)
return -ENODEV;
chip = &pca963x_chipdefs[acpi_id->driver_data];
}
pdata = dev_get_platdata(&client->dev);
if (!pdata) {
pdata = pca963x_dt_init(client, chip);
if (IS_ERR(pdata)) {
dev_warn(&client->dev, "could not parse configuration\n");
pdata = NULL;
}
}
if (pdata && (pdata->leds.num_leds < 1 ||
pdata->leds.num_leds > chip->n_leds)) {
dev_err(&client->dev, "board info must claim 1-%d LEDs",
chip->n_leds);
return -EINVAL;
}
pca963x_chip = devm_kzalloc(&client->dev, sizeof(*pca963x_chip),
GFP_KERNEL);
if (!pca963x_chip)
return -ENOMEM;
pca963x = devm_kzalloc(&client->dev, chip->n_leds * sizeof(*pca963x),
GFP_KERNEL);
if (!pca963x)
return -ENOMEM;
i2c_set_clientdata(client, pca963x_chip);
mutex_init(&pca963x_chip->mutex);
pca963x_chip->chipdef = chip;
pca963x_chip->client = client;
pca963x_chip->leds = pca963x;
for (i = 0; i < chip->n_leds / 4; i++)
i2c_smbus_write_byte_data(client, chip->ledout_base + i, 0x00);
for (i = 0; i < chip->n_leds; i++) {
pca963x[i].led_num = i;
pca963x[i].chip = pca963x_chip;
if (pdata && i < pdata->leds.num_leds) {
if (pdata->leds.leds[i].name)
snprintf(pca963x[i].name,
sizeof(pca963x[i].name), "pca963x:%s",
pdata->leds.leds[i].name);
if (pdata->leds.leds[i].default_trigger)
pca963x[i].led_cdev.default_trigger =
pdata->leds.leds[i].default_trigger;
}
if (!pdata || i >= pdata->leds.num_leds ||
!pdata->leds.leds[i].name)
snprintf(pca963x[i].name, sizeof(pca963x[i].name),
"pca963x:%d:%.2x:%d", client->adapter->nr,
client->addr, i);
pca963x[i].led_cdev.name = pca963x[i].name;
pca963x[i].led_cdev.brightness_set_blocking = pca963x_led_set;
if (pdata && pdata->blink_type == PCA963X_HW_BLINK)
pca963x[i].led_cdev.blink_set = pca963x_blink_set;
err = led_classdev_register(&client->dev, &pca963x[i].led_cdev);
if (err < 0)
goto exit;
}
i2c_smbus_write_byte_data(client, PCA963X_MODE1, BIT(4));
if (pdata) {
if (pdata->outdrv == PCA963X_OPEN_DRAIN)
i2c_smbus_write_byte_data(client, PCA963X_MODE2, 0x01);
else
i2c_smbus_write_byte_data(client, PCA963X_MODE2, 0x05);
}
return 0;
exit:
while (i--)
led_classdev_unregister(&pca963x[i].led_cdev);
return err;
}
static int pca963x_remove(struct i2c_client *client)
{
struct pca963x *pca963x = i2c_get_clientdata(client);
int i;
for (i = 0; i < pca963x->chipdef->n_leds; i++)
led_classdev_unregister(&pca963x->leds[i].led_cdev);
return 0;
}
