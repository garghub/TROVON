static int get_coeff(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
return i;
}
return -EINVAL;
}
static int wm8971_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8971_priv *wm8971 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 11289600:
case 12000000:
case 12288000:
case 16934400:
case 18432000:
wm8971->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int wm8971_set_dai_fmt(struct snd_soc_dai *codec_dai,
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
snd_soc_write(codec, WM8971_IFACE, iface);
return 0;
}
static int wm8971_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8971_priv *wm8971 = snd_soc_codec_get_drvdata(codec);
u16 iface = snd_soc_read(codec, WM8971_IFACE) & 0x1f3;
u16 srate = snd_soc_read(codec, WM8971_SRATE) & 0x1c0;
int coeff = get_coeff(wm8971->sysclk, params_rate(params));
switch (params_width(params)) {
case 16:
break;
case 20:
iface |= 0x0004;
break;
case 24:
iface |= 0x0008;
break;
case 32:
iface |= 0x000c;
break;
}
snd_soc_write(codec, WM8971_IFACE, iface);
if (coeff >= 0)
snd_soc_write(codec, WM8971_SRATE, srate |
(coeff_div[coeff].sr << 1) | coeff_div[coeff].usb);
return 0;
}
static int wm8971_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8971_ADCDAC) & 0xfff7;
if (mute)
snd_soc_write(codec, WM8971_ADCDAC, mute_reg | 0x8);
else
snd_soc_write(codec, WM8971_ADCDAC, mute_reg);
return 0;
}
static int wm8971_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 pwr_reg = snd_soc_read(codec, WM8971_PWR1) & 0xfe3e;
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_write(codec, WM8971_PWR1, pwr_reg | 0x00c1);
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
snd_soc_cache_sync(codec);
snd_soc_write(codec, WM8971_PWR1, pwr_reg | 0x0140);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8971_PWR1, 0x0001);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static void wm8971_work(struct work_struct *work)
{
struct snd_soc_dapm_context *dapm =
container_of(work, struct snd_soc_dapm_context,
delayed_work.work);
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(dapm);
wm8971_set_bias_level(codec, codec->dapm.bias_level);
}
static int wm8971_suspend(struct snd_soc_codec *codec)
{
wm8971_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8971_resume(struct snd_soc_codec *codec)
{
u16 reg;
wm8971_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (codec->dapm.suspend_bias_level == SND_SOC_BIAS_ON) {
reg = snd_soc_read(codec, WM8971_PWR1) & 0xfe3e;
snd_soc_write(codec, WM8971_PWR1, reg | 0x01c0);
codec->dapm.bias_level = SND_SOC_BIAS_ON;
queue_delayed_work(wm8971_workq, &codec->dapm.delayed_work,
msecs_to_jiffies(1000));
}
return 0;
}
static int wm8971_probe(struct snd_soc_codec *codec)
{
int ret = 0;
u16 reg;
INIT_DELAYED_WORK(&codec->dapm.delayed_work, wm8971_work);
wm8971_workq = create_workqueue("wm8971");
if (wm8971_workq == NULL)
return -ENOMEM;
wm8971_reset(codec);
reg = snd_soc_read(codec, WM8971_PWR1) & 0xfe3e;
snd_soc_write(codec, WM8971_PWR1, reg | 0x01c0);
codec->dapm.bias_level = SND_SOC_BIAS_STANDBY;
queue_delayed_work(wm8971_workq, &codec->dapm.delayed_work,
msecs_to_jiffies(1000));
snd_soc_update_bits(codec, WM8971_LDAC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8971_RDAC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8971_LOUT1V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8971_ROUT1V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8971_LOUT2V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8971_ROUT2V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8971_LINVOL, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8971_RINVOL, 0x0100, 0x0100);
return ret;
}
static int wm8971_remove(struct snd_soc_codec *codec)
{
wm8971_set_bias_level(codec, SND_SOC_BIAS_OFF);
if (wm8971_workq)
destroy_workqueue(wm8971_workq);
return 0;
}
static int wm8971_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8971_priv *wm8971;
struct regmap *regmap;
int ret;
wm8971 = devm_kzalloc(&i2c->dev, sizeof(struct wm8971_priv),
GFP_KERNEL);
if (wm8971 == NULL)
return -ENOMEM;
regmap = devm_regmap_init_i2c(i2c, &wm8971_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
i2c_set_clientdata(i2c, wm8971);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8971, &wm8971_dai, 1);
return ret;
}
static int wm8971_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
