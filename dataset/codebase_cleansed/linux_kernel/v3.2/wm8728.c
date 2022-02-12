static int wm8728_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8728_DACCTL);
if (mute)
snd_soc_write(codec, WM8728_DACCTL, mute_reg | 1);
else
snd_soc_write(codec, WM8728_DACCTL, mute_reg & ~1);
return 0;
}
static int wm8728_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
u16 dac = snd_soc_read(codec, WM8728_DACCTL);
dac &= ~0x18;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
dac |= 0x10;
break;
case SNDRV_PCM_FORMAT_S24_LE:
dac |= 0x08;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8728_DACCTL, dac);
return 0;
}
static int wm8728_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = snd_soc_read(codec, WM8728_IFCTL);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
iface &= ~0x22;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x20;
iface &= ~0x02;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x02;
iface &= ~0x20;
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x22;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8728_IFCTL, iface);
return 0;
}
static int wm8728_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 reg;
int i;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
reg = snd_soc_read(codec, WM8728_DACCTL);
snd_soc_write(codec, WM8728_DACCTL, reg & ~0x4);
for (i = 0; i < ARRAY_SIZE(wm8728_reg_defaults); i++)
snd_soc_write(codec, i,
snd_soc_read(codec, i));
}
break;
case SND_SOC_BIAS_OFF:
reg = snd_soc_read(codec, WM8728_DACCTL);
snd_soc_write(codec, WM8728_DACCTL, reg | 0x4);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8728_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
wm8728_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8728_resume(struct snd_soc_codec *codec)
{
wm8728_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8728_probe(struct snd_soc_codec *codec)
{
struct wm8728_priv *wm8728 = snd_soc_codec_get_drvdata(codec);
int ret;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, wm8728->control_type);
if (ret < 0) {
printk(KERN_ERR "wm8728: failed to configure cache I/O: %d\n",
ret);
return ret;
}
wm8728_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_add_controls(codec, wm8728_snd_controls,
ARRAY_SIZE(wm8728_snd_controls));
return ret;
}
static int wm8728_remove(struct snd_soc_codec *codec)
{
wm8728_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int __devinit wm8728_spi_probe(struct spi_device *spi)
{
struct wm8728_priv *wm8728;
int ret;
wm8728 = kzalloc(sizeof(struct wm8728_priv), GFP_KERNEL);
if (wm8728 == NULL)
return -ENOMEM;
wm8728->control_type = SND_SOC_SPI;
spi_set_drvdata(spi, wm8728);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8728, &wm8728_dai, 1);
if (ret < 0)
kfree(wm8728);
return ret;
}
static int __devexit wm8728_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
kfree(spi_get_drvdata(spi));
return 0;
}
static __devinit int wm8728_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8728_priv *wm8728;
int ret;
wm8728 = kzalloc(sizeof(struct wm8728_priv), GFP_KERNEL);
if (wm8728 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8728);
wm8728->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8728, &wm8728_dai, 1);
if (ret < 0)
kfree(wm8728);
return ret;
}
static __devexit int wm8728_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init wm8728_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8728_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8728 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8728_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8728 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8728_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8728_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8728_spi_driver);
#endif
}
