static int
tlc591xx_set_mode(struct regmap *regmap, u8 mode)
{
int err;
u8 val;
err = regmap_write(regmap, TLC591XX_REG_MODE1, MODE1_NORMAL_MODE);
if (err)
return err;
val = MODE2_OCH_STOP | mode;
return regmap_write(regmap, TLC591XX_REG_MODE2, val);
}
static int
tlc591xx_set_ledout(struct tlc591xx_priv *priv, struct tlc591xx_led *led,
u8 val)
{
unsigned int i = (led->led_no % 4) * 2;
unsigned int mask = LEDOUT_MASK << i;
unsigned int addr = priv->reg_ledout_offset + (led->led_no >> 2);
val = val << i;
return regmap_update_bits(priv->regmap, addr, mask, val);
}
static int
tlc591xx_set_pwm(struct tlc591xx_priv *priv, struct tlc591xx_led *led,
u8 brightness)
{
u8 pwm = TLC591XX_REG_PWM(led->led_no);
return regmap_write(priv->regmap, pwm, brightness);
}
static void
tlc591xx_led_work(struct work_struct *work)
{
struct tlc591xx_led *led = work_to_led(work);
struct tlc591xx_priv *priv = led->priv;
enum led_brightness brightness = led->ldev.brightness;
int err;
switch (brightness) {
case 0:
err = tlc591xx_set_ledout(priv, led, LEDOUT_OFF);
break;
case LED_FULL:
err = tlc591xx_set_ledout(priv, led, LEDOUT_ON);
break;
default:
err = tlc591xx_set_ledout(priv, led, LEDOUT_DIM);
if (!err)
err = tlc591xx_set_pwm(priv, led, brightness);
}
if (err)
dev_err(led->ldev.dev, "Failed setting brightness\n");
}
static void
tlc591xx_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct tlc591xx_led *led = ldev_to_led(led_cdev);
led->ldev.brightness = brightness;
schedule_work(&led->work);
}
static void
tlc591xx_destroy_devices(struct tlc591xx_priv *priv, unsigned int j)
{
int i = j;
while (--i >= 0) {
if (priv->leds[i].active) {
led_classdev_unregister(&priv->leds[i].ldev);
cancel_work_sync(&priv->leds[i].work);
}
}
}
static int
tlc591xx_configure(struct device *dev,
struct tlc591xx_priv *priv,
const struct tlc591xx *tlc591xx)
{
unsigned int i;
int err = 0;
tlc591xx_set_mode(priv->regmap, MODE2_DIM);
for (i = 0; i < TLC591XX_MAX_LEDS; i++) {
struct tlc591xx_led *led = &priv->leds[i];
if (!led->active)
continue;
led->priv = priv;
led->led_no = i;
led->ldev.brightness_set = tlc591xx_brightness_set;
led->ldev.max_brightness = LED_FULL;
INIT_WORK(&led->work, tlc591xx_led_work);
err = led_classdev_register(dev, &led->ldev);
if (err < 0) {
dev_err(dev, "couldn't register LED %s\n",
led->ldev.name);
goto exit;
}
}
return 0;
exit:
tlc591xx_destroy_devices(priv, i);
return err;
}
static int
tlc591xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *np = client->dev.of_node, *child;
struct device *dev = &client->dev;
const struct of_device_id *match;
const struct tlc591xx *tlc591xx;
struct tlc591xx_priv *priv;
int err, count, reg;
match = of_match_device(of_tlc591xx_leds_match, dev);
if (!match)
return -ENODEV;
tlc591xx = match->data;
if (!np)
return -ENODEV;
count = of_get_child_count(np);
if (!count || count > tlc591xx->max_leds)
return -EINVAL;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->regmap = devm_regmap_init_i2c(client, &tlc591xx_regmap);
if (IS_ERR(priv->regmap)) {
err = PTR_ERR(priv->regmap);
dev_err(dev, "Failed to allocate register map: %d\n", err);
return err;
}
priv->reg_ledout_offset = tlc591xx->reg_ledout_offset;
i2c_set_clientdata(client, priv);
for_each_child_of_node(np, child) {
err = of_property_read_u32(child, "reg", &reg);
if (err)
return err;
if (reg < 0 || reg >= tlc591xx->max_leds)
return -EINVAL;
if (priv->leds[reg].active)
return -EINVAL;
priv->leds[reg].active = true;
priv->leds[reg].ldev.name =
of_get_property(child, "label", NULL) ? : child->name;
priv->leds[reg].ldev.default_trigger =
of_get_property(child, "linux,default-trigger", NULL);
}
return tlc591xx_configure(dev, priv, tlc591xx);
}
static int
tlc591xx_remove(struct i2c_client *client)
{
struct tlc591xx_priv *priv = i2c_get_clientdata(client);
tlc591xx_destroy_devices(priv, TLC591XX_MAX_LEDS);
return 0;
}
