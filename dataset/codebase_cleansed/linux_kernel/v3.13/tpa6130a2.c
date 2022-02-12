static int tpa6130a2_i2c_read(int reg)
{
struct tpa6130a2_data *data;
int val;
if (WARN_ON(!tpa6130a2_client))
return -EINVAL;
data = i2c_get_clientdata(tpa6130a2_client);
if (data->power_state) {
val = i2c_smbus_read_byte_data(tpa6130a2_client, reg);
if (val < 0)
dev_err(&tpa6130a2_client->dev, "Read failed\n");
else
data->regs[reg] = val;
} else {
val = data->regs[reg];
}
return val;
}
static int tpa6130a2_i2c_write(int reg, u8 value)
{
struct tpa6130a2_data *data;
int val = 0;
if (WARN_ON(!tpa6130a2_client))
return -EINVAL;
data = i2c_get_clientdata(tpa6130a2_client);
if (data->power_state) {
val = i2c_smbus_write_byte_data(tpa6130a2_client, reg, value);
if (val < 0) {
dev_err(&tpa6130a2_client->dev, "Write failed\n");
return val;
}
}
data->regs[reg] = value;
return val;
}
static u8 tpa6130a2_read(int reg)
{
struct tpa6130a2_data *data;
if (WARN_ON(!tpa6130a2_client))
return 0;
data = i2c_get_clientdata(tpa6130a2_client);
return data->regs[reg];
}
static int tpa6130a2_initialize(void)
{
struct tpa6130a2_data *data;
int i, ret = 0;
if (WARN_ON(!tpa6130a2_client))
return -EINVAL;
data = i2c_get_clientdata(tpa6130a2_client);
for (i = 1; i < TPA6130A2_REG_VERSION; i++) {
ret = tpa6130a2_i2c_write(i, data->regs[i]);
if (ret < 0)
break;
}
return ret;
}
static int tpa6130a2_power(u8 power)
{
struct tpa6130a2_data *data;
u8 val;
int ret = 0;
if (WARN_ON(!tpa6130a2_client))
return -EINVAL;
data = i2c_get_clientdata(tpa6130a2_client);
mutex_lock(&data->mutex);
if (power == data->power_state)
goto exit;
if (power) {
ret = regulator_enable(data->supply);
if (ret != 0) {
dev_err(&tpa6130a2_client->dev,
"Failed to enable supply: %d\n", ret);
goto exit;
}
if (data->power_gpio >= 0)
gpio_set_value(data->power_gpio, 1);
data->power_state = 1;
ret = tpa6130a2_initialize();
if (ret < 0) {
dev_err(&tpa6130a2_client->dev,
"Failed to initialize chip\n");
if (data->power_gpio >= 0)
gpio_set_value(data->power_gpio, 0);
regulator_disable(data->supply);
data->power_state = 0;
goto exit;
}
} else {
val = tpa6130a2_read(TPA6130A2_REG_CONTROL);
val |= TPA6130A2_SWS;
tpa6130a2_i2c_write(TPA6130A2_REG_CONTROL, val);
if (data->power_gpio >= 0)
gpio_set_value(data->power_gpio, 0);
ret = regulator_disable(data->supply);
if (ret != 0) {
dev_err(&tpa6130a2_client->dev,
"Failed to disable supply: %d\n", ret);
goto exit;
}
data->power_state = 0;
}
exit:
mutex_unlock(&data->mutex);
return ret;
}
static int tpa6130a2_get_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct tpa6130a2_data *data;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
if (WARN_ON(!tpa6130a2_client))
return -EINVAL;
data = i2c_get_clientdata(tpa6130a2_client);
mutex_lock(&data->mutex);
ucontrol->value.integer.value[0] =
(tpa6130a2_read(reg) >> shift) & mask;
if (invert)
ucontrol->value.integer.value[0] =
max - ucontrol->value.integer.value[0];
mutex_unlock(&data->mutex);
return 0;
}
static int tpa6130a2_put_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct tpa6130a2_data *data;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
unsigned int val = (ucontrol->value.integer.value[0] & mask);
unsigned int val_reg;
if (WARN_ON(!tpa6130a2_client))
return -EINVAL;
data = i2c_get_clientdata(tpa6130a2_client);
if (invert)
val = max - val;
mutex_lock(&data->mutex);
val_reg = tpa6130a2_read(reg);
if (((val_reg >> shift) & mask) == val) {
mutex_unlock(&data->mutex);
return 0;
}
val_reg &= ~(mask << shift);
val_reg |= val << shift;
tpa6130a2_i2c_write(reg, val_reg);
mutex_unlock(&data->mutex);
return 1;
}
static void tpa6130a2_channel_enable(u8 channel, int enable)
{
u8 val;
if (enable) {
val = tpa6130a2_read(TPA6130A2_REG_CONTROL);
val |= channel;
val &= ~TPA6130A2_SWS;
tpa6130a2_i2c_write(TPA6130A2_REG_CONTROL, val);
val = tpa6130a2_read(TPA6130A2_REG_VOL_MUTE);
val &= ~channel;
tpa6130a2_i2c_write(TPA6130A2_REG_VOL_MUTE, val);
} else {
val = tpa6130a2_read(TPA6130A2_REG_VOL_MUTE);
val |= channel;
tpa6130a2_i2c_write(TPA6130A2_REG_VOL_MUTE, val);
val = tpa6130a2_read(TPA6130A2_REG_CONTROL);
val &= ~channel;
tpa6130a2_i2c_write(TPA6130A2_REG_CONTROL, val);
}
}
int tpa6130a2_stereo_enable(struct snd_soc_codec *codec, int enable)
{
int ret = 0;
if (enable) {
ret = tpa6130a2_power(1);
if (ret < 0)
return ret;
tpa6130a2_channel_enable(TPA6130A2_HP_EN_R | TPA6130A2_HP_EN_L,
1);
} else {
tpa6130a2_channel_enable(TPA6130A2_HP_EN_R | TPA6130A2_HP_EN_L,
0);
ret = tpa6130a2_power(0);
}
return ret;
}
int tpa6130a2_add_controls(struct snd_soc_codec *codec)
{
struct tpa6130a2_data *data;
if (tpa6130a2_client == NULL)
return -ENODEV;
data = i2c_get_clientdata(tpa6130a2_client);
if (data->id == TPA6140A2)
return snd_soc_add_codec_controls(codec, tpa6140a2_controls,
ARRAY_SIZE(tpa6140a2_controls));
else
return snd_soc_add_codec_controls(codec, tpa6130a2_controls,
ARRAY_SIZE(tpa6130a2_controls));
}
static int tpa6130a2_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev;
struct tpa6130a2_data *data;
struct tpa6130a2_platform_data *pdata = client->dev.platform_data;
struct device_node *np = client->dev.of_node;
const char *regulator;
int ret;
dev = &client->dev;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (data == NULL) {
dev_err(dev, "Can not allocate memory\n");
return -ENOMEM;
}
if (pdata) {
data->power_gpio = pdata->power_gpio;
} else if (np) {
data->power_gpio = of_get_named_gpio(np, "power-gpio", 0);
} else {
dev_err(dev, "Platform data not set\n");
dump_stack();
return -ENODEV;
}
tpa6130a2_client = client;
i2c_set_clientdata(tpa6130a2_client, data);
data->id = id->driver_data;
mutex_init(&data->mutex);
data->regs[TPA6130A2_REG_CONTROL] = TPA6130A2_SWS;
data->regs[TPA6130A2_REG_VOL_MUTE] = TPA6130A2_MUTE_R |
TPA6130A2_MUTE_L;
if (data->power_gpio >= 0) {
ret = devm_gpio_request(dev, data->power_gpio,
"tpa6130a2 enable");
if (ret < 0) {
dev_err(dev, "Failed to request power GPIO (%d)\n",
data->power_gpio);
goto err_gpio;
}
gpio_direction_output(data->power_gpio, 0);
}
switch (data->id) {
default:
dev_warn(dev, "Unknown TPA model (%d). Assuming 6130A2\n",
data->id);
case TPA6130A2:
regulator = "Vdd";
break;
case TPA6140A2:
regulator = "AVdd";
break;
}
data->supply = devm_regulator_get(dev, regulator);
if (IS_ERR(data->supply)) {
ret = PTR_ERR(data->supply);
dev_err(dev, "Failed to request supply: %d\n", ret);
goto err_gpio;
}
ret = tpa6130a2_power(1);
if (ret != 0)
goto err_gpio;
ret = tpa6130a2_i2c_read(TPA6130A2_REG_VERSION) &
TPA6130A2_VERSION_MASK;
if ((ret != 1) && (ret != 2))
dev_warn(dev, "UNTESTED version detected (%d)\n", ret);
ret = tpa6130a2_power(0);
if (ret != 0)
goto err_gpio;
return 0;
err_gpio:
tpa6130a2_client = NULL;
return ret;
}
static int tpa6130a2_remove(struct i2c_client *client)
{
tpa6130a2_power(0);
tpa6130a2_client = NULL;
return 0;
}
