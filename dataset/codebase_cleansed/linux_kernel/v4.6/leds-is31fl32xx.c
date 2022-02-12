static int is31fl32xx_write(struct is31fl32xx_priv *priv, u8 reg, u8 val)
{
int ret;
dev_dbg(&priv->client->dev, "writing register 0x%02X=0x%02X", reg, val);
ret = i2c_smbus_write_byte_data(priv->client, reg, val);
if (ret) {
dev_err(&priv->client->dev,
"register write to 0x%02X failed (error %d)",
reg, ret);
}
return ret;
}
static int is31fl3216_reset(struct is31fl32xx_priv *priv)
{
unsigned int i;
int ret;
ret = is31fl32xx_write(priv, IS31FL3216_CONFIG_REG,
IS31FL3216_CONFIG_SSD_ENABLE);
if (ret)
return ret;
for (i = 0; i < priv->cdef->channels; i++) {
ret = is31fl32xx_write(priv, priv->cdef->pwm_register_base+i,
0x00);
if (ret)
return ret;
}
ret = is31fl32xx_write(priv, priv->cdef->pwm_update_reg, 0);
if (ret)
return ret;
ret = is31fl32xx_write(priv, IS31FL3216_LIGHTING_EFFECT_REG, 0x00);
if (ret)
return ret;
ret = is31fl32xx_write(priv, IS31FL3216_CHANNEL_CONFIG_REG, 0x00);
if (ret)
return ret;
return 0;
}
static int is31fl3216_software_shutdown(struct is31fl32xx_priv *priv,
bool enable)
{
u8 value = enable ? IS31FL3216_CONFIG_SSD_ENABLE :
IS31FL3216_CONFIG_SSD_DISABLE;
return is31fl32xx_write(priv, IS31FL3216_CONFIG_REG, value);
}
static int is31fl32xx_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
const struct is31fl32xx_led_data *led_data =
container_of(led_cdev, struct is31fl32xx_led_data, cdev);
const struct is31fl32xx_chipdef *cdef = led_data->priv->cdef;
u8 pwm_register_offset;
int ret;
dev_dbg(led_cdev->dev, "%s: %d\n", __func__, brightness);
if (cdef->pwm_registers_reversed)
pwm_register_offset = cdef->channels - led_data->channel;
else
pwm_register_offset = led_data->channel - 1;
ret = is31fl32xx_write(led_data->priv,
cdef->pwm_register_base + pwm_register_offset,
brightness);
if (ret)
return ret;
return is31fl32xx_write(led_data->priv, cdef->pwm_update_reg, 0);
}
static int is31fl32xx_reset_regs(struct is31fl32xx_priv *priv)
{
const struct is31fl32xx_chipdef *cdef = priv->cdef;
int ret;
if (cdef->reset_reg != IS31FL32XX_REG_NONE) {
ret = is31fl32xx_write(priv, cdef->reset_reg, 0);
if (ret)
return ret;
}
if (cdef->reset_func)
return cdef->reset_func(priv);
return 0;
}
static int is31fl32xx_software_shutdown(struct is31fl32xx_priv *priv,
bool enable)
{
const struct is31fl32xx_chipdef *cdef = priv->cdef;
int ret;
if (cdef->shutdown_reg != IS31FL32XX_REG_NONE) {
u8 value = enable ? IS31FL32XX_SHUTDOWN_SSD_ENABLE :
IS31FL32XX_SHUTDOWN_SSD_DISABLE;
ret = is31fl32xx_write(priv, cdef->shutdown_reg, value);
if (ret)
return ret;
}
if (cdef->sw_shutdown_func)
return cdef->sw_shutdown_func(priv, enable);
return 0;
}
static int is31fl32xx_init_regs(struct is31fl32xx_priv *priv)
{
const struct is31fl32xx_chipdef *cdef = priv->cdef;
int ret;
ret = is31fl32xx_reset_regs(priv);
if (ret)
return ret;
if (cdef->led_control_register_base != IS31FL32XX_REG_NONE) {
u8 value =
GENMASK(cdef->enable_bits_per_led_control_register-1, 0);
u8 num_regs = cdef->channels /
cdef->enable_bits_per_led_control_register;
int i;
for (i = 0; i < num_regs; i++) {
ret = is31fl32xx_write(priv,
cdef->led_control_register_base+i,
value);
if (ret)
return ret;
}
}
ret = is31fl32xx_software_shutdown(priv, false);
if (ret)
return ret;
if (cdef->global_control_reg != IS31FL32XX_REG_NONE) {
ret = is31fl32xx_write(priv, cdef->global_control_reg, 0x00);
if (ret)
return ret;
}
return 0;
}
static inline size_t sizeof_is31fl32xx_priv(int num_leds)
{
return sizeof(struct is31fl32xx_priv) +
(sizeof(struct is31fl32xx_led_data) * num_leds);
}
static int is31fl32xx_parse_child_dt(const struct device *dev,
const struct device_node *child,
struct is31fl32xx_led_data *led_data)
{
struct led_classdev *cdev = &led_data->cdev;
int ret = 0;
u32 reg;
if (of_property_read_string(child, "label", &cdev->name))
cdev->name = child->name;
ret = of_property_read_u32(child, "reg", &reg);
if (ret || reg < 1 || reg > led_data->priv->cdef->channels) {
dev_err(dev,
"Child node %s does not have a valid reg property\n",
child->full_name);
return -EINVAL;
}
led_data->channel = reg;
of_property_read_string(child, "linux,default-trigger",
&cdev->default_trigger);
cdev->brightness_set_blocking = is31fl32xx_brightness_set;
return 0;
}
static struct is31fl32xx_led_data *is31fl32xx_find_led_data(
struct is31fl32xx_priv *priv,
u8 channel)
{
size_t i;
for (i = 0; i < priv->num_leds; i++) {
if (priv->leds[i].channel == channel)
return &priv->leds[i];
}
return NULL;
}
static int is31fl32xx_parse_dt(struct device *dev,
struct is31fl32xx_priv *priv)
{
struct device_node *child;
int ret = 0;
for_each_child_of_node(dev->of_node, child) {
struct is31fl32xx_led_data *led_data =
&priv->leds[priv->num_leds];
const struct is31fl32xx_led_data *other_led_data;
led_data->priv = priv;
ret = is31fl32xx_parse_child_dt(dev, child, led_data);
if (ret)
goto err;
other_led_data = is31fl32xx_find_led_data(priv,
led_data->channel);
if (other_led_data) {
dev_err(dev,
"%s and %s both attempting to use channel %d\n",
led_data->cdev.name,
other_led_data->cdev.name,
led_data->channel);
goto err;
}
ret = devm_led_classdev_register(dev, &led_data->cdev);
if (ret) {
dev_err(dev, "failed to register PWM led for %s: %d\n",
led_data->cdev.name, ret);
goto err;
}
priv->num_leds++;
}
return 0;
err:
of_node_put(child);
return ret;
}
static int is31fl32xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct is31fl32xx_chipdef *cdef;
const struct of_device_id *of_dev_id;
struct device *dev = &client->dev;
struct is31fl32xx_priv *priv;
int count;
int ret = 0;
of_dev_id = of_match_device(of_is31fl31xx_match, dev);
if (!of_dev_id)
return -EINVAL;
cdef = of_dev_id->data;
count = of_get_child_count(dev->of_node);
if (!count)
return -EINVAL;
priv = devm_kzalloc(dev, sizeof_is31fl32xx_priv(count),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->client = client;
priv->cdef = cdef;
i2c_set_clientdata(client, priv);
ret = is31fl32xx_init_regs(priv);
if (ret)
return ret;
ret = is31fl32xx_parse_dt(dev, priv);
if (ret)
return ret;
return 0;
}
static int is31fl32xx_remove(struct i2c_client *client)
{
struct is31fl32xx_priv *priv = i2c_get_clientdata(client);
return is31fl32xx_reset_regs(priv);
}
