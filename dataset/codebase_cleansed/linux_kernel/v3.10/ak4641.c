static int ak4641_set_deemph(struct snd_soc_codec *codec)
{
struct ak4641_priv *ak4641 = snd_soc_codec_get_drvdata(codec);
int i, best = 0;
for (i = 0 ; i < ARRAY_SIZE(deemph_settings); i++) {
if (ak4641->deemph && deemph_settings[i] != 0 &&
abs(deemph_settings[i] - ak4641->playback_fs) <
abs(deemph_settings[best] - ak4641->playback_fs))
best = i;
if (!ak4641->deemph && deemph_settings[i] == 0)
best = i;
}
dev_dbg(codec->dev, "Set deemphasis %d\n", best);
return snd_soc_update_bits(codec, AK4641_DAC, 0x3, best);
}
static int ak4641_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct ak4641_priv *ak4641 = snd_soc_codec_get_drvdata(codec);
int deemph = ucontrol->value.enumerated.item[0];
if (deemph > 1)
return -EINVAL;
ak4641->deemph = deemph;
return ak4641_set_deemph(codec);
}
static int ak4641_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct ak4641_priv *ak4641 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = ak4641->deemph;
return 0;
}
static int ak4641_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct ak4641_priv *ak4641 = snd_soc_codec_get_drvdata(codec);
ak4641->sysclk = freq;
return 0;
}
static int ak4641_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct ak4641_priv *ak4641 = snd_soc_codec_get_drvdata(codec);
int rate = params_rate(params), fs = 256;
u8 mode2;
if (rate)
fs = ak4641->sysclk / rate;
else
return -EINVAL;
switch (fs) {
case 1024:
mode2 = (0x2 << 5);
break;
case 512:
mode2 = (0x1 << 5);
break;
case 256:
mode2 = (0x0 << 5);
break;
default:
dev_err(codec->dev, "Error: unsupported fs=%d\n", fs);
return -EINVAL;
}
snd_soc_update_bits(codec, AK4641_MODE2, (0x3 << 5), mode2);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
ak4641->playback_fs = rate;
ak4641_set_deemph(codec);
};
return 0;
}
static int ak4641_pcm_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 btif;
int ret;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
btif = (0x3 << 5);
break;
case SND_SOC_DAIFMT_LEFT_J:
btif = (0x2 << 5);
break;
case SND_SOC_DAIFMT_DSP_A:
btif = (0x0 << 5);
break;
case SND_SOC_DAIFMT_DSP_B:
btif = (0x1 << 5);
break;
default:
return -EINVAL;
}
ret = snd_soc_update_bits(codec, AK4641_BTIF, (0x3 << 5), btif);
if (ret < 0)
return ret;
return 0;
}
static int ak4641_i2s_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 mode1 = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
mode1 = 0x02;
break;
case SND_SOC_DAIFMT_LEFT_J:
mode1 = 0x01;
break;
default:
return -EINVAL;
}
return snd_soc_write(codec, AK4641_MODE1, mode1);
}
static int ak4641_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
return snd_soc_update_bits(codec, AK4641_DAC, 0x20, mute ? 0x20 : 0);
}
static int ak4641_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct ak4641_platform_data *pdata = codec->dev->platform_data;
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_update_bits(codec, AK4641_DAC, 0x20, 0);
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, AK4641_DAC, 0x20, 0x20);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
if (pdata && gpio_is_valid(pdata->gpio_power))
gpio_set_value(pdata->gpio_power, 1);
mdelay(1);
if (pdata && gpio_is_valid(pdata->gpio_npdn))
gpio_set_value(pdata->gpio_npdn, 1);
mdelay(1);
ret = snd_soc_cache_sync(codec);
if (ret) {
dev_err(codec->dev,
"Failed to sync cache: %d\n", ret);
return ret;
}
}
snd_soc_update_bits(codec, AK4641_PM1, 0x80, 0x80);
snd_soc_update_bits(codec, AK4641_PM2, 0x80, 0);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, AK4641_PM1, 0x80, 0);
if (pdata && gpio_is_valid(pdata->gpio_npdn))
gpio_set_value(pdata->gpio_npdn, 0);
if (pdata && gpio_is_valid(pdata->gpio_power))
gpio_set_value(pdata->gpio_power, 0);
codec->cache_sync = 1;
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int ak4641_suspend(struct snd_soc_codec *codec)
{
ak4641_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int ak4641_resume(struct snd_soc_codec *codec)
{
ak4641_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ak4641_probe(struct snd_soc_codec *codec)
{
int ret;
ret = snd_soc_codec_set_cache_io(codec, 8, 8, SND_SOC_I2C);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
ak4641_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int ak4641_remove(struct snd_soc_codec *codec)
{
ak4641_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int ak4641_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ak4641_platform_data *pdata = i2c->dev.platform_data;
struct ak4641_priv *ak4641;
int ret;
ak4641 = devm_kzalloc(&i2c->dev, sizeof(struct ak4641_priv),
GFP_KERNEL);
if (!ak4641)
return -ENOMEM;
if (pdata) {
if (gpio_is_valid(pdata->gpio_power)) {
ret = gpio_request_one(pdata->gpio_power,
GPIOF_OUT_INIT_LOW, "ak4641 power");
if (ret)
goto err_out;
}
if (gpio_is_valid(pdata->gpio_npdn)) {
ret = gpio_request_one(pdata->gpio_npdn,
GPIOF_OUT_INIT_LOW, "ak4641 npdn");
if (ret)
goto err_gpio;
udelay(1);
gpio_set_value(pdata->gpio_npdn, 1);
}
}
i2c_set_clientdata(i2c, ak4641);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_ak4641,
ak4641_dai, ARRAY_SIZE(ak4641_dai));
if (ret != 0)
goto err_gpio2;
return 0;
err_gpio2:
if (pdata) {
if (gpio_is_valid(pdata->gpio_power))
gpio_set_value(pdata->gpio_power, 0);
if (gpio_is_valid(pdata->gpio_npdn))
gpio_free(pdata->gpio_npdn);
}
err_gpio:
if (pdata && gpio_is_valid(pdata->gpio_power))
gpio_free(pdata->gpio_power);
err_out:
return ret;
}
static int ak4641_i2c_remove(struct i2c_client *i2c)
{
struct ak4641_platform_data *pdata = i2c->dev.platform_data;
snd_soc_unregister_codec(&i2c->dev);
if (pdata) {
if (gpio_is_valid(pdata->gpio_power)) {
gpio_set_value(pdata->gpio_power, 0);
gpio_free(pdata->gpio_power);
}
if (gpio_is_valid(pdata->gpio_npdn))
gpio_free(pdata->gpio_npdn);
}
return 0;
}
