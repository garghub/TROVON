static void pll_factors(struct pll_ *pll_div,
unsigned int target, unsigned int source)
{
unsigned long long Kpart;
unsigned int K, Ndiv, Nmod;
target *= 4;
Ndiv = target / source;
if (Ndiv < 6) {
source /= 2;
pll_div->pre_div = 1;
Ndiv = target / source;
} else
pll_div->pre_div = 0;
if ((Ndiv < 6) || (Ndiv > 12))
printk(KERN_WARNING
"WM8974 N value %u outwith recommended range!\n",
Ndiv);
pll_div->n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (long long)Nmod;
do_div(Kpart, source);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
K /= 10;
pll_div->k = K;
}
static int wm8974_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct pll_ pll_div;
u16 reg;
if (freq_in == 0 || freq_out == 0) {
reg = snd_soc_read(codec, WM8974_CLOCK);
snd_soc_write(codec, WM8974_CLOCK, reg & 0x0ff);
reg = snd_soc_read(codec, WM8974_POWER1);
snd_soc_write(codec, WM8974_POWER1, reg & 0x1df);
return 0;
}
pll_factors(&pll_div, freq_out, freq_in);
snd_soc_write(codec, WM8974_PLLN, (pll_div.pre_div << 4) | pll_div.n);
snd_soc_write(codec, WM8974_PLLK1, pll_div.k >> 18);
snd_soc_write(codec, WM8974_PLLK2, (pll_div.k >> 9) & 0x1ff);
snd_soc_write(codec, WM8974_PLLK3, pll_div.k & 0x1ff);
reg = snd_soc_read(codec, WM8974_POWER1);
snd_soc_write(codec, WM8974_POWER1, reg | 0x020);
reg = snd_soc_read(codec, WM8974_CLOCK);
snd_soc_write(codec, WM8974_CLOCK, reg | 0x100);
return 0;
}
static int wm8974_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
switch (div_id) {
case WM8974_OPCLKDIV:
reg = snd_soc_read(codec, WM8974_GPIO) & 0x1cf;
snd_soc_write(codec, WM8974_GPIO, reg | div);
break;
case WM8974_MCLKDIV:
reg = snd_soc_read(codec, WM8974_CLOCK) & 0x11f;
snd_soc_write(codec, WM8974_CLOCK, reg | div);
break;
case WM8974_BCLKDIV:
reg = snd_soc_read(codec, WM8974_CLOCK) & 0x1e3;
snd_soc_write(codec, WM8974_CLOCK, reg | div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8974_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = 0;
u16 clk = snd_soc_read(codec, WM8974_CLOCK) & 0x1fe;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
clk |= 0x0001;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= 0x0010;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= 0x0008;
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= 0x00018;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= 0x0180;
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= 0x0100;
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= 0x0080;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8974_IFACE, iface);
snd_soc_write(codec, WM8974_CLOCK, clk);
return 0;
}
static int wm8974_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 iface = snd_soc_read(codec, WM8974_IFACE) & 0x19f;
u16 adn = snd_soc_read(codec, WM8974_ADD) & 0x1f1;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= 0x0020;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= 0x0040;
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface |= 0x0060;
break;
}
switch (params_rate(params)) {
case 8000:
adn |= 0x5 << 1;
break;
case 11025:
adn |= 0x4 << 1;
break;
case 16000:
adn |= 0x3 << 1;
break;
case 22050:
adn |= 0x2 << 1;
break;
case 32000:
adn |= 0x1 << 1;
break;
case 44100:
case 48000:
break;
}
snd_soc_write(codec, WM8974_IFACE, iface);
snd_soc_write(codec, WM8974_ADD, adn);
return 0;
}
static int wm8974_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8974_DAC) & 0xffbf;
if (mute)
snd_soc_write(codec, WM8974_DAC, mute_reg | 0x40);
else
snd_soc_write(codec, WM8974_DAC, mute_reg);
return 0;
}
static int wm8974_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 power1 = snd_soc_read(codec, WM8974_POWER1) & ~0x3;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
power1 |= 0x1;
snd_soc_write(codec, WM8974_POWER1, power1);
break;
case SND_SOC_BIAS_STANDBY:
power1 |= WM8974_POWER1_BIASEN | WM8974_POWER1_BUFIOEN;
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
regcache_sync(dev_get_regmap(codec->dev, NULL));
snd_soc_write(codec, WM8974_POWER1, power1 | 0x3);
mdelay(100);
}
power1 |= 0x2;
snd_soc_write(codec, WM8974_POWER1, power1);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8974_POWER1, 0);
snd_soc_write(codec, WM8974_POWER2, 0);
snd_soc_write(codec, WM8974_POWER3, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8974_suspend(struct snd_soc_codec *codec)
{
wm8974_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8974_resume(struct snd_soc_codec *codec)
{
wm8974_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8974_probe(struct snd_soc_codec *codec)
{
int ret = 0;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
ret = wm8974_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
return ret;
}
wm8974_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return ret;
}
static int wm8974_remove(struct snd_soc_codec *codec)
{
wm8974_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8974_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *regmap;
int ret;
regmap = devm_regmap_init_i2c(i2c, &wm8974_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8974, &wm8974_dai, 1);
return ret;
}
static int wm8974_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
