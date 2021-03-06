static int tas571x_register_size(struct tas571x_private *priv, unsigned int reg)
{
switch (reg) {
case TAS571X_MVOL_REG:
case TAS571X_CH1_VOL_REG:
case TAS571X_CH2_VOL_REG:
return priv->chip->vol_reg_size;
case TAS571X_INPUT_MUX_REG:
case TAS571X_CH4_SRC_SELECT_REG:
case TAS571X_PWM_MUX_REG:
return 4;
default:
return 1;
}
}
static int tas571x_reg_write(void *context, unsigned int reg,
unsigned int value)
{
struct i2c_client *client = context;
struct tas571x_private *priv = i2c_get_clientdata(client);
unsigned int i, size;
uint8_t buf[5];
int ret;
size = tas571x_register_size(priv, reg);
buf[0] = reg;
for (i = size; i >= 1; --i) {
buf[i] = value;
value >>= 8;
}
ret = i2c_master_send(client, buf, size + 1);
if (ret == size + 1)
return 0;
else if (ret < 0)
return ret;
else
return -EIO;
}
static int tas571x_reg_read(void *context, unsigned int reg,
unsigned int *value)
{
struct i2c_client *client = context;
struct tas571x_private *priv = i2c_get_clientdata(client);
uint8_t send_buf, recv_buf[4];
struct i2c_msg msgs[2];
unsigned int size;
unsigned int i;
int ret;
size = tas571x_register_size(priv, reg);
send_buf = reg;
msgs[0].addr = client->addr;
msgs[0].len = sizeof(send_buf);
msgs[0].buf = &send_buf;
msgs[0].flags = 0;
msgs[1].addr = client->addr;
msgs[1].len = size;
msgs[1].buf = recv_buf;
msgs[1].flags = I2C_M_RD;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
return ret;
else if (ret != ARRAY_SIZE(msgs))
return -EIO;
*value = 0;
for (i = 0; i < size; i++) {
*value <<= 8;
*value |= recv_buf[i];
}
return 0;
}
static int tas571x_set_dai_fmt(struct snd_soc_dai *dai, unsigned int format)
{
struct tas571x_private *priv = snd_soc_codec_get_drvdata(dai->codec);
priv->format = format;
return 0;
}
static int tas571x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct tas571x_private *priv = snd_soc_codec_get_drvdata(dai->codec);
u32 val;
switch (priv->format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
val = 0x00;
break;
case SND_SOC_DAIFMT_I2S:
val = 0x03;
break;
case SND_SOC_DAIFMT_LEFT_J:
val = 0x06;
break;
default:
return -EINVAL;
}
if (params_width(params) >= 24)
val += 2;
else if (params_width(params) >= 20)
val += 1;
return regmap_update_bits(priv->regmap, TAS571X_SDI_REG,
TAS571X_SDI_FMT_MASK, val);
}
static int tas571x_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u8 sysctl2;
int ret;
sysctl2 = mute ? TAS571X_SYS_CTRL_2_SDN_MASK : 0;
ret = snd_soc_update_bits(codec,
TAS571X_SYS_CTRL_2_REG,
TAS571X_SYS_CTRL_2_SDN_MASK,
sysctl2);
usleep_range(1000, 2000);
return ret;
}
static int tas571x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct tas571x_private *priv = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_OFF) {
if (!IS_ERR(priv->mclk)) {
ret = clk_prepare_enable(priv->mclk);
if (ret) {
dev_err(codec->dev,
"Failed to enable master clock: %d\n",
ret);
return ret;
}
}
gpiod_set_value(priv->pdn_gpio, 0);
usleep_range(5000, 6000);
regcache_cache_only(priv->regmap, false);
ret = regcache_sync(priv->regmap);
if (ret)
return ret;
}
break;
case SND_SOC_BIAS_OFF:
regcache_cache_only(priv->regmap, true);
gpiod_set_value(priv->pdn_gpio, 1);
if (!IS_ERR(priv->mclk))
clk_disable_unprepare(priv->mclk);
break;
}
return 0;
}
static int tas571x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tas571x_private *priv;
struct device *dev = &client->dev;
const struct of_device_id *of_id;
int i, ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
i2c_set_clientdata(client, priv);
of_id = of_match_device(tas571x_of_match, dev);
if (of_id)
priv->chip = of_id->data;
else
priv->chip = (void *) id->driver_data;
priv->mclk = devm_clk_get(dev, "mclk");
if (IS_ERR(priv->mclk) && PTR_ERR(priv->mclk) != -ENOENT) {
dev_err(dev, "Failed to request mclk: %ld\n",
PTR_ERR(priv->mclk));
return PTR_ERR(priv->mclk);
}
BUG_ON(priv->chip->num_supply_names > TAS571X_MAX_SUPPLIES);
for (i = 0; i < priv->chip->num_supply_names; i++)
priv->supplies[i].supply = priv->chip->supply_names[i];
ret = devm_regulator_bulk_get(dev, priv->chip->num_supply_names,
priv->supplies);
if (ret) {
dev_err(dev, "Failed to get supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(priv->chip->num_supply_names,
priv->supplies);
if (ret) {
dev_err(dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
priv->regmap = devm_regmap_init(dev, NULL, client,
priv->chip->regmap_config);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
priv->pdn_gpio = devm_gpiod_get_optional(dev, "pdn", GPIOD_OUT_LOW);
if (IS_ERR(priv->pdn_gpio)) {
dev_err(dev, "error requesting pdn_gpio: %ld\n",
PTR_ERR(priv->pdn_gpio));
return PTR_ERR(priv->pdn_gpio);
}
priv->reset_gpio = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_HIGH);
if (IS_ERR(priv->reset_gpio)) {
dev_err(dev, "error requesting reset_gpio: %ld\n",
PTR_ERR(priv->reset_gpio));
return PTR_ERR(priv->reset_gpio);
} else if (priv->reset_gpio) {
usleep_range(100, 200);
gpiod_set_value(priv->reset_gpio, 0);
usleep_range(12000, 20000);
}
ret = regmap_write(priv->regmap, TAS571X_OSC_TRIM_REG, 0);
if (ret)
return ret;
memcpy(&priv->codec_driver, &tas571x_codec, sizeof(priv->codec_driver));
priv->codec_driver.controls = priv->chip->controls;
priv->codec_driver.num_controls = priv->chip->num_controls;
if (priv->chip->vol_reg_size == 2) {
ret = regmap_update_bits(priv->regmap, TAS571X_MVOL_REG, 1, 0);
if (ret)
return ret;
}
regcache_cache_only(priv->regmap, true);
gpiod_set_value(priv->pdn_gpio, 1);
return snd_soc_register_codec(&client->dev, &priv->codec_driver,
&tas571x_dai, 1);
}
static int tas571x_i2c_remove(struct i2c_client *client)
{
struct tas571x_private *priv = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
regulator_bulk_disable(priv->chip->num_supply_names, priv->supplies);
return 0;
}
