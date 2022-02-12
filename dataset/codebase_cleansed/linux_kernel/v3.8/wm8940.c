static int wm8940_volatile_register(struct snd_soc_codec *codec,
unsigned int reg)
{
switch (reg) {
case WM8940_SOFTRESET:
return 1;
default:
return 0;
}
}
static int wm8940_add_widgets(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
ret = snd_soc_dapm_new_controls(dapm, wm8940_dapm_widgets,
ARRAY_SIZE(wm8940_dapm_widgets));
if (ret)
goto error_ret;
ret = snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
error_ret:
return ret;
}
static int wm8940_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 iface = snd_soc_read(codec, WM8940_IFACE) & 0xFE67;
u16 clk = snd_soc_read(codec, WM8940_CLOCK) & 0x1fe;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
clk |= 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8940_CLOCK, clk);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= (2 << 3);
break;
case SND_SOC_DAIFMT_LEFT_J:
iface |= (1 << 3);
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_DSP_A:
iface |= (3 << 3);
break;
case SND_SOC_DAIFMT_DSP_B:
iface |= (3 << 3) | (1 << 7);
break;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
iface |= (1 << 7);
break;
case SND_SOC_DAIFMT_IB_NF:
iface |= (1 << 8);
break;
case SND_SOC_DAIFMT_IB_IF:
iface |= (1 << 8) | (1 << 7);
break;
}
snd_soc_write(codec, WM8940_IFACE, iface);
return 0;
}
static int wm8940_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 iface = snd_soc_read(codec, WM8940_IFACE) & 0xFD9F;
u16 addcntrl = snd_soc_read(codec, WM8940_ADDCNTRL) & 0xFFF1;
u16 companding = snd_soc_read(codec,
WM8940_COMPANDINGCTL) & 0xFFDF;
int ret;
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE
&& params_channels(params) == 2)
iface |= (1 << 9);
switch (params_rate(params)) {
case 8000:
addcntrl |= (0x5 << 1);
break;
case 11025:
addcntrl |= (0x4 << 1);
break;
case 16000:
addcntrl |= (0x3 << 1);
break;
case 22050:
addcntrl |= (0x2 << 1);
break;
case 32000:
addcntrl |= (0x1 << 1);
break;
case 44100:
case 48000:
break;
}
ret = snd_soc_write(codec, WM8940_ADDCNTRL, addcntrl);
if (ret)
goto error_ret;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
companding = companding | (1 << 5);
break;
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
iface |= (1 << 5);
break;
case SNDRV_PCM_FORMAT_S24_LE:
iface |= (2 << 5);
break;
case SNDRV_PCM_FORMAT_S32_LE:
iface |= (3 << 5);
break;
}
ret = snd_soc_write(codec, WM8940_COMPANDINGCTL, companding);
if (ret)
goto error_ret;
ret = snd_soc_write(codec, WM8940_IFACE, iface);
error_ret:
return ret;
}
static int wm8940_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8940_DAC) & 0xffbf;
if (mute)
mute_reg |= 0x40;
return snd_soc_write(codec, WM8940_DAC, mute_reg);
}
static int wm8940_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 val;
u16 pwr_reg = snd_soc_read(codec, WM8940_POWER1) & 0x1F0;
int ret = 0;
switch (level) {
case SND_SOC_BIAS_ON:
pwr_reg |= (1 << 2) | (1 << 3);
val = snd_soc_read(codec, WM8940_OUTPUTCTL);
ret = snd_soc_write(codec, WM8940_OUTPUTCTL, val | 0x2);
if (ret)
break;
ret = snd_soc_write(codec, WM8940_POWER1, pwr_reg | 0x1);
break;
case SND_SOC_BIAS_PREPARE:
pwr_reg |= (1 << 2) | (1 << 3);
ret = snd_soc_write(codec, WM8940_POWER1, pwr_reg | 0x1);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = snd_soc_cache_sync(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to sync cache: %d\n", ret);
return ret;
}
}
pwr_reg |= (1 << 2) | (1 << 3);
ret = snd_soc_write(codec, WM8940_POWER1, pwr_reg | 0x2);
break;
case SND_SOC_BIAS_OFF:
ret = snd_soc_write(codec, WM8940_POWER1, pwr_reg);
break;
}
codec->dapm.bias_level = level;
return ret;
}
static void pll_factors(unsigned int target, unsigned int source)
{
unsigned long long Kpart;
unsigned int K, Ndiv, Nmod;
Ndiv = target / source;
if (Ndiv > 12) {
source <<= 1;
pll_div.pre_scale = 0;
Ndiv = target / source;
} else if (Ndiv < 3) {
source >>= 2;
pll_div.pre_scale = 3;
Ndiv = target / source;
} else if (Ndiv < 6) {
source >>= 1;
pll_div.pre_scale = 2;
Ndiv = target / source;
} else
pll_div.pre_scale = 1;
if ((Ndiv < 6) || (Ndiv > 12))
printk(KERN_WARNING
"WM8940 N value %d outwith recommended range!d\n",
Ndiv);
pll_div.n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (long long)Nmod;
do_div(Kpart, source);
K = Kpart & 0xFFFFFFFF;
if ((K % 10) >= 5)
K += 5;
K /= 10;
pll_div.k = K;
}
static int wm8940_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
reg = snd_soc_read(codec, WM8940_POWER1);
snd_soc_write(codec, WM8940_POWER1, reg & 0x1df);
if (freq_in == 0 || freq_out == 0) {
reg = snd_soc_read(codec, WM8940_CLOCK);
snd_soc_write(codec, WM8940_CLOCK, reg & 0x0ff);
snd_soc_write(codec, WM8940_PLLN, (1 << 7));
return 0;
}
pll_factors(freq_out*4, freq_in);
if (pll_div.k)
snd_soc_write(codec, WM8940_PLLN,
(pll_div.pre_scale << 4) | pll_div.n | (1 << 6));
else
snd_soc_write(codec, WM8940_PLLN,
(pll_div.pre_scale << 4) | pll_div.n);
snd_soc_write(codec, WM8940_PLLK1, pll_div.k >> 18);
snd_soc_write(codec, WM8940_PLLK2, (pll_div.k >> 9) & 0x1ff);
snd_soc_write(codec, WM8940_PLLK3, pll_div.k & 0x1ff);
reg = snd_soc_read(codec, WM8940_POWER1);
snd_soc_write(codec, WM8940_POWER1, reg | 0x020);
reg = snd_soc_read(codec, WM8940_CLOCK);
snd_soc_write(codec, WM8940_CLOCK, reg | 0x100);
return 0;
}
static int wm8940_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8940_priv *wm8940 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 11289600:
case 12000000:
case 12288000:
case 16934400:
case 18432000:
wm8940->sysclk = freq;
return 0;
}
return -EINVAL;
}
static int wm8940_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
int ret = 0;
switch (div_id) {
case WM8940_BCLKDIV:
reg = snd_soc_read(codec, WM8940_CLOCK) & 0xFFE3;
ret = snd_soc_write(codec, WM8940_CLOCK, reg | (div << 2));
break;
case WM8940_MCLKDIV:
reg = snd_soc_read(codec, WM8940_CLOCK) & 0xFF1F;
ret = snd_soc_write(codec, WM8940_CLOCK, reg | (div << 5));
break;
case WM8940_OPCLKDIV:
reg = snd_soc_read(codec, WM8940_GPIO) & 0xFFCF;
ret = snd_soc_write(codec, WM8940_GPIO, reg | (div << 4));
break;
}
return ret;
}
static int wm8940_suspend(struct snd_soc_codec *codec)
{
return wm8940_set_bias_level(codec, SND_SOC_BIAS_OFF);
}
static int wm8940_resume(struct snd_soc_codec *codec)
{
wm8940_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8940_probe(struct snd_soc_codec *codec)
{
struct wm8940_priv *wm8940 = snd_soc_codec_get_drvdata(codec);
struct wm8940_setup_data *pdata = codec->dev->platform_data;
int ret;
u16 reg;
ret = snd_soc_codec_set_cache_io(codec, 8, 16, wm8940->control_type);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
ret = wm8940_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
return ret;
}
wm8940_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
ret = snd_soc_write(codec, WM8940_POWER1, 0x180);
if (ret < 0)
return ret;
if (!pdata)
dev_warn(codec->dev, "No platform data supplied\n");
else {
reg = snd_soc_read(codec, WM8940_OUTPUTCTL);
ret = snd_soc_write(codec, WM8940_OUTPUTCTL, reg | pdata->vroi);
if (ret < 0)
return ret;
}
ret = snd_soc_add_codec_controls(codec, wm8940_snd_controls,
ARRAY_SIZE(wm8940_snd_controls));
if (ret)
return ret;
ret = wm8940_add_widgets(codec);
return ret;
}
static int wm8940_remove(struct snd_soc_codec *codec)
{
wm8940_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8940_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8940_priv *wm8940;
int ret;
wm8940 = devm_kzalloc(&i2c->dev, sizeof(struct wm8940_priv),
GFP_KERNEL);
if (wm8940 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8940);
wm8940->control_type = SND_SOC_I2C;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8940, &wm8940_dai, 1);
return ret;
}
static int wm8940_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
