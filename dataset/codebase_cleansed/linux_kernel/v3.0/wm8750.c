static int wm8750_add_widgets(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, wm8750_dapm_widgets,
ARRAY_SIZE(wm8750_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
return 0;
}
static inline int get_coeff(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
return i;
}
printk(KERN_ERR "wm8750: could not get coeff for mclk %d @ rate %d\n",
mclk, rate);
return -EINVAL;
}
static int wm8750_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8750_priv *wm8750 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 11289600:
case 12000000:
case 12288000:
case 16934400:
case 18432000:
wm8750->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int wm8750_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface = 0x0040;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x0002;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x0001;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x0003;
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= 0x0013;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x0090;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x0080;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x0010;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8750_IFACE, iface);
return 0;
}
static int wm8750_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct wm8750_priv *wm8750 = snd_soc_codec_get_drvdata(codec);
u16 iface = snd_soc_read(codec, WM8750_IFACE) & 0x1f3;
u16 srate = snd_soc_read(codec, WM8750_SRATE) & 0x1c0;
int coeff = get_coeff(wm8750->sysclk, params_rate(params));
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= 0x0004;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= 0x0008;
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface |= 0x000c;
break;
}
snd_soc_write(codec, WM8750_IFACE, iface);
if (coeff >= 0)
snd_soc_write(codec, WM8750_SRATE, srate |
(coeff_div[coeff].sr << 1) | coeff_div[coeff].usb);
return 0;
}
static int wm8750_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8750_ADCDAC) & 0xfff7;
if (mute)
snd_soc_write(codec, WM8750_ADCDAC, mute_reg | 0x8);
else
snd_soc_write(codec, WM8750_ADCDAC, mute_reg);
return 0;
}
static int wm8750_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 pwr_reg = snd_soc_read(codec, WM8750_PWR1) & 0xfe3e;
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_write(codec, WM8750_PWR1, pwr_reg | 0x00c0);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
snd_soc_write(codec, WM8750_PWR1, pwr_reg | 0x01c1);
msleep(1000);
}
snd_soc_write(codec, WM8750_PWR1, pwr_reg | 0x0141);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8750_PWR1, 0x0001);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8750_suspend(struct snd_soc_codec *codec, pm_message_t state)
{
wm8750_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8750_resume(struct snd_soc_codec *codec)
{
int i;
u8 data[2];
u16 *cache = codec->reg_cache;
for (i = 0; i < ARRAY_SIZE(wm8750_reg); i++) {
if (i == WM8750_RESET)
continue;
data[0] = (i << 1) | ((cache[i] >> 8) & 0x0001);
data[1] = cache[i] & 0x00ff;
codec->hw_write(codec->control_data, data, 2);
}
wm8750_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8750_probe(struct snd_soc_codec *codec)
{
struct wm8750_priv *wm8750 = snd_soc_codec_get_drvdata(codec);
int reg, ret;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, wm8750->control_type);
if (ret < 0) {
printk(KERN_ERR "wm8750: failed to set cache I/O: %d\n", ret);
return ret;
}
ret = wm8750_reset(codec);
if (ret < 0) {
printk(KERN_ERR "wm8750: failed to reset: %d\n", ret);
return ret;
}
wm8750_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
reg = snd_soc_read(codec, WM8750_LDAC);
snd_soc_write(codec, WM8750_LDAC, reg | 0x0100);
reg = snd_soc_read(codec, WM8750_RDAC);
snd_soc_write(codec, WM8750_RDAC, reg | 0x0100);
reg = snd_soc_read(codec, WM8750_LOUT1V);
snd_soc_write(codec, WM8750_LOUT1V, reg | 0x0100);
reg = snd_soc_read(codec, WM8750_ROUT1V);
snd_soc_write(codec, WM8750_ROUT1V, reg | 0x0100);
reg = snd_soc_read(codec, WM8750_LOUT2V);
snd_soc_write(codec, WM8750_LOUT2V, reg | 0x0100);
reg = snd_soc_read(codec, WM8750_ROUT2V);
snd_soc_write(codec, WM8750_ROUT2V, reg | 0x0100);
reg = snd_soc_read(codec, WM8750_LINVOL);
snd_soc_write(codec, WM8750_LINVOL, reg | 0x0100);
reg = snd_soc_read(codec, WM8750_RINVOL);
snd_soc_write(codec, WM8750_RINVOL, reg | 0x0100);
snd_soc_add_controls(codec, wm8750_snd_controls,
ARRAY_SIZE(wm8750_snd_controls));
wm8750_add_widgets(codec);
return ret;
}
static int wm8750_remove(struct snd_soc_codec *codec)
{
wm8750_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int __devinit wm8750_spi_probe(struct spi_device *spi)
{
struct wm8750_priv *wm8750;
int ret;
wm8750 = kzalloc(sizeof(struct wm8750_priv), GFP_KERNEL);
if (wm8750 == NULL)
return -ENOMEM;
wm8750->control_type = SND_SOC_SPI;
spi_set_drvdata(spi, wm8750);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8750, &wm8750_dai, 1);
if (ret < 0)
kfree(wm8750);
return ret;
}
static int __devexit wm8750_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
kfree(spi_get_drvdata(spi));
return 0;
}
static __devinit int wm8750_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8750_priv *wm8750;
int ret;
wm8750 = kzalloc(sizeof(struct wm8750_priv), GFP_KERNEL);
if (wm8750 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8750);
wm8750->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8750, &wm8750_dai, 1);
if (ret < 0)
kfree(wm8750);
return ret;
}
static __devexit int wm8750_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
kfree(i2c_get_clientdata(client));
return 0;
}
static int __init wm8750_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&wm8750_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8750 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8750_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8750 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8750_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&wm8750_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8750_spi_driver);
#endif
}
