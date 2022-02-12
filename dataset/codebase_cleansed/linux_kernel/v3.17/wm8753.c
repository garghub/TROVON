static bool wm8753_volatile(struct device *dev, unsigned int reg)
{
return reg == WM8753_RESET;
}
static bool wm8753_writeable(struct device *dev, unsigned int reg)
{
return reg <= WM8753_ADCTL2;
}
static int wm8753_get_dai(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
ucontrol->value.integer.value[0] = wm8753->dai_func;
return 0;
}
static int wm8753_set_dai(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
u16 ioctl;
if (wm8753->dai_func == ucontrol->value.integer.value[0])
return 0;
if (snd_soc_codec_is_active(codec))
return -EBUSY;
ioctl = snd_soc_read(codec, WM8753_IOCTL);
wm8753->dai_func = ucontrol->value.integer.value[0];
if (((ioctl >> 2) & 0x3) == wm8753->dai_func)
return 1;
ioctl = (ioctl & 0x1f3) | (wm8753->dai_func << 2);
snd_soc_write(codec, WM8753_IOCTL, ioctl);
wm8753_hifi_write_dai_fmt(codec, wm8753->hifi_fmt);
wm8753_voice_write_dai_fmt(codec, wm8753->voice_fmt);
return 1;
}
static void pll_factors(struct _pll_div *pll_div, unsigned int target,
unsigned int source)
{
u64 Kpart;
unsigned int K, Ndiv, Nmod;
Ndiv = target / source;
if (Ndiv < 6) {
source >>= 1;
pll_div->div2 = 1;
Ndiv = target / source;
} else
pll_div->div2 = 0;
if ((Ndiv < 6) || (Ndiv > 12))
printk(KERN_WARNING
"wm8753: unsupported N = %u\n", Ndiv);
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
static int wm8753_set_dai_pll(struct snd_soc_dai *codec_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
u16 reg, enable;
int offset;
struct snd_soc_codec *codec = codec_dai->codec;
if (pll_id < WM8753_PLL1 || pll_id > WM8753_PLL2)
return -ENODEV;
if (pll_id == WM8753_PLL1) {
offset = 0;
enable = 0x10;
reg = snd_soc_read(codec, WM8753_CLOCK) & 0xffef;
} else {
offset = 4;
enable = 0x8;
reg = snd_soc_read(codec, WM8753_CLOCK) & 0xfff7;
}
if (!freq_in || !freq_out) {
snd_soc_write(codec, WM8753_PLL1CTL1 + offset, 0x0026);
snd_soc_write(codec, WM8753_CLOCK, reg);
return 0;
} else {
u16 value = 0;
struct _pll_div pll_div;
pll_factors(&pll_div, freq_out * 8, freq_in);
value = (pll_div.n << 5) + ((pll_div.k & 0x3c0000) >> 18);
snd_soc_write(codec, WM8753_PLL1CTL2 + offset, value);
value = (pll_div.k & 0x03fe00) >> 9;
snd_soc_write(codec, WM8753_PLL1CTL3 + offset, value);
value = pll_div.k & 0x0001ff;
snd_soc_write(codec, WM8753_PLL1CTL4 + offset, value);
snd_soc_write(codec, WM8753_PLL1CTL1 + offset, 0x0027 |
(pll_div.div2 << 3));
snd_soc_write(codec, WM8753_CLOCK, reg | enable);
}
return 0;
}
static int get_coeff(int mclk, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(coeff_div); i++) {
if (coeff_div[i].rate == rate && coeff_div[i].mclk == mclk)
return i;
}
return -EINVAL;
}
static int wm8753_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
switch (freq) {
case 11289600:
case 12000000:
case 12288000:
case 16934400:
case 18432000:
if (clk_id == WM8753_MCLK) {
wm8753->sysclk = freq;
return 0;
} else if (clk_id == WM8753_PCMCLK) {
wm8753->pcmclk = freq;
return 0;
}
break;
}
return -EINVAL;
}
static int wm8753_vdac_adc_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
u16 voice = snd_soc_read(codec, WM8753_PCM) & 0x01ec;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
voice |= 0x0002;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
voice |= 0x0001;
break;
case SND_SOC_DAIFMT_DSP_A:
voice |= 0x0003;
break;
case SND_SOC_DAIFMT_DSP_B:
voice |= 0x0013;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8753_PCM, voice);
return 0;
}
static int wm8753_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
u16 voice = snd_soc_read(codec, WM8753_PCM) & 0x01f3;
u16 srate = snd_soc_read(codec, WM8753_SRATE1) & 0x017f;
switch (params_width(params)) {
case 16:
break;
case 20:
voice |= 0x0004;
break;
case 24:
voice |= 0x0008;
break;
case 32:
voice |= 0x000c;
break;
}
if (params_rate(params) * 384 == wm8753->pcmclk)
srate |= 0x80;
snd_soc_write(codec, WM8753_SRATE1, srate);
snd_soc_write(codec, WM8753_PCM, voice);
return 0;
}
static int wm8753_pcm_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
u16 voice, ioctl;
voice = snd_soc_read(codec, WM8753_PCM) & 0x011f;
ioctl = snd_soc_read(codec, WM8753_IOCTL) & 0x015d;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBM_CFM:
ioctl |= 0x2;
case SND_SOC_DAIFMT_CBM_CFS:
voice |= 0x0040;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
voice |= 0x0080;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
voice &= ~0x0010;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
voice |= 0x0090;
break;
case SND_SOC_DAIFMT_IB_NF:
voice |= 0x0080;
break;
case SND_SOC_DAIFMT_NB_IF:
voice |= 0x0010;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8753_PCM, voice);
snd_soc_write(codec, WM8753_IOCTL, ioctl);
return 0;
}
static int wm8753_set_dai_clkdiv(struct snd_soc_dai *codec_dai,
int div_id, int div)
{
struct snd_soc_codec *codec = codec_dai->codec;
u16 reg;
switch (div_id) {
case WM8753_PCMDIV:
reg = snd_soc_read(codec, WM8753_CLOCK) & 0x003f;
snd_soc_write(codec, WM8753_CLOCK, reg | div);
break;
case WM8753_BCLKDIV:
reg = snd_soc_read(codec, WM8753_SRATE2) & 0x01c7;
snd_soc_write(codec, WM8753_SRATE2, reg | div);
break;
case WM8753_VXCLKDIV:
reg = snd_soc_read(codec, WM8753_SRATE2) & 0x003f;
snd_soc_write(codec, WM8753_SRATE2, reg | div);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8753_hdac_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
u16 hifi = snd_soc_read(codec, WM8753_HIFI) & 0x01e0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
hifi |= 0x0002;
break;
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
hifi |= 0x0001;
break;
case SND_SOC_DAIFMT_DSP_A:
hifi |= 0x0003;
break;
case SND_SOC_DAIFMT_DSP_B:
hifi |= 0x0013;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8753_HIFI, hifi);
return 0;
}
static int wm8753_i2s_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
u16 ioctl, hifi;
hifi = snd_soc_read(codec, WM8753_HIFI) & 0x011f;
ioctl = snd_soc_read(codec, WM8753_IOCTL) & 0x00ae;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBM_CFM:
ioctl |= 0x1;
case SND_SOC_DAIFMT_CBM_CFS:
hifi |= 0x0040;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
hifi |= 0x0080;
break;
default:
return -EINVAL;
}
break;
case SND_SOC_DAIFMT_I2S:
case SND_SOC_DAIFMT_RIGHT_J:
case SND_SOC_DAIFMT_LEFT_J:
hifi &= ~0x0010;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
hifi |= 0x0090;
break;
case SND_SOC_DAIFMT_IB_NF:
hifi |= 0x0080;
break;
case SND_SOC_DAIFMT_NB_IF:
hifi |= 0x0010;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8753_HIFI, hifi);
snd_soc_write(codec, WM8753_IOCTL, ioctl);
return 0;
}
static int wm8753_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
u16 srate = snd_soc_read(codec, WM8753_SRATE1) & 0x01c0;
u16 hifi = snd_soc_read(codec, WM8753_HIFI) & 0x01f3;
int coeff;
coeff = get_coeff(wm8753->sysclk, params_rate(params));
if (coeff < 0) {
printk(KERN_ERR "wm8753 invalid MCLK or rate\n");
return coeff;
}
snd_soc_write(codec, WM8753_SRATE1, srate | (coeff_div[coeff].sr << 1) |
coeff_div[coeff].usb);
switch (params_width(params)) {
case 16:
break;
case 20:
hifi |= 0x0004;
break;
case 24:
hifi |= 0x0008;
break;
case 32:
hifi |= 0x000c;
break;
}
snd_soc_write(codec, WM8753_HIFI, hifi);
return 0;
}
static int wm8753_mode1v_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
u16 clock;
clock = snd_soc_read(codec, WM8753_CLOCK) & 0xfffb;
snd_soc_write(codec, WM8753_CLOCK, clock);
return wm8753_vdac_adc_set_dai_fmt(codec, fmt);
}
static int wm8753_mode1h_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
return wm8753_hdac_set_dai_fmt(codec, fmt);
}
static int wm8753_mode2_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
u16 clock;
clock = snd_soc_read(codec, WM8753_CLOCK) & 0xfffb;
snd_soc_write(codec, WM8753_CLOCK, clock);
return wm8753_vdac_adc_set_dai_fmt(codec, fmt);
}
static int wm8753_mode3_4_set_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
u16 clock;
clock = snd_soc_read(codec, WM8753_CLOCK) & 0xfffb;
snd_soc_write(codec, WM8753_CLOCK, clock | 0x4);
if (wm8753_hdac_set_dai_fmt(codec, fmt) < 0)
return -EINVAL;
return wm8753_vdac_adc_set_dai_fmt(codec, fmt);
}
static int wm8753_hifi_write_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
switch (wm8753->dai_func) {
case 0:
ret = wm8753_mode1h_set_dai_fmt(codec, fmt);
break;
case 1:
ret = wm8753_mode2_set_dai_fmt(codec, fmt);
break;
case 2:
case 3:
ret = wm8753_mode3_4_set_dai_fmt(codec, fmt);
break;
default:
break;
}
if (ret)
return ret;
return wm8753_i2s_set_dai_fmt(codec, fmt);
}
static int wm8753_hifi_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
wm8753->hifi_fmt = fmt;
return wm8753_hifi_write_dai_fmt(codec, fmt);
}
static int wm8753_voice_write_dai_fmt(struct snd_soc_codec *codec,
unsigned int fmt)
{
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
if (wm8753->dai_func != 0)
return 0;
ret = wm8753_mode1v_set_dai_fmt(codec, fmt);
if (ret)
return ret;
ret = wm8753_pcm_set_dai_fmt(codec, fmt);
if (ret)
return ret;
return 0;
}
static int wm8753_voice_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
wm8753->voice_fmt = fmt;
return wm8753_voice_write_dai_fmt(codec, fmt);
}
static int wm8753_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 mute_reg = snd_soc_read(codec, WM8753_DAC) & 0xfff7;
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
if (mute && wm8753->dai_func == 1) {
if (!snd_soc_codec_is_active(codec))
snd_soc_write(codec, WM8753_DAC, mute_reg | 0x8);
} else {
if (mute)
snd_soc_write(codec, WM8753_DAC, mute_reg | 0x8);
else
snd_soc_write(codec, WM8753_DAC, mute_reg);
}
return 0;
}
static int wm8753_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 pwr_reg = snd_soc_read(codec, WM8753_PWR1) & 0xfe3e;
switch (level) {
case SND_SOC_BIAS_ON:
snd_soc_write(codec, WM8753_PWR1, pwr_reg | 0x00c0);
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_write(codec, WM8753_PWR1, pwr_reg | 0x01c1);
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec, WM8753_PWR1, pwr_reg | 0x0141);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, WM8753_PWR1, 0x0001);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static void wm8753_work(struct work_struct *work)
{
struct snd_soc_dapm_context *dapm =
container_of(work, struct snd_soc_dapm_context,
delayed_work.work);
struct snd_soc_codec *codec = dapm->codec;
wm8753_set_bias_level(codec, dapm->bias_level);
}
static int wm8753_suspend(struct snd_soc_codec *codec)
{
wm8753_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8753_resume(struct snd_soc_codec *codec)
{
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
regcache_sync(wm8753->regmap);
wm8753_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
if (codec->dapm.suspend_bias_level == SND_SOC_BIAS_ON) {
wm8753_set_bias_level(codec, SND_SOC_BIAS_PREPARE);
codec->dapm.bias_level = SND_SOC_BIAS_ON;
queue_delayed_work(system_power_efficient_wq,
&codec->dapm.delayed_work,
msecs_to_jiffies(caps_charge));
}
return 0;
}
static int wm8753_probe(struct snd_soc_codec *codec)
{
struct wm8753_priv *wm8753 = snd_soc_codec_get_drvdata(codec);
int ret;
INIT_DELAYED_WORK(&codec->dapm.delayed_work, wm8753_work);
ret = wm8753_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
return ret;
}
wm8753_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
wm8753->dai_func = 0;
wm8753_set_bias_level(codec, SND_SOC_BIAS_PREPARE);
schedule_delayed_work(&codec->dapm.delayed_work,
msecs_to_jiffies(caps_charge));
snd_soc_update_bits(codec, WM8753_LDAC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_RDAC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_LADC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_RADC, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_LOUT1V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_ROUT1V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_LOUT2V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_ROUT2V, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_LINVOL, 0x0100, 0x0100);
snd_soc_update_bits(codec, WM8753_RINVOL, 0x0100, 0x0100);
return 0;
}
static int wm8753_remove(struct snd_soc_codec *codec)
{
flush_delayed_work(&codec->dapm.delayed_work);
wm8753_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8753_spi_probe(struct spi_device *spi)
{
struct wm8753_priv *wm8753;
int ret;
wm8753 = devm_kzalloc(&spi->dev, sizeof(struct wm8753_priv),
GFP_KERNEL);
if (wm8753 == NULL)
return -ENOMEM;
spi_set_drvdata(spi, wm8753);
wm8753->regmap = devm_regmap_init_spi(spi, &wm8753_regmap);
if (IS_ERR(wm8753->regmap)) {
ret = PTR_ERR(wm8753->regmap);
dev_err(&spi->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = snd_soc_register_codec(&spi->dev, &soc_codec_dev_wm8753,
wm8753_dai, ARRAY_SIZE(wm8753_dai));
if (ret != 0)
dev_err(&spi->dev, "Failed to register CODEC: %d\n", ret);
return ret;
}
static int wm8753_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8753_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8753_priv *wm8753;
int ret;
wm8753 = devm_kzalloc(&i2c->dev, sizeof(struct wm8753_priv),
GFP_KERNEL);
if (wm8753 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8753);
wm8753->regmap = devm_regmap_init_i2c(i2c, &wm8753_regmap);
if (IS_ERR(wm8753->regmap)) {
ret = PTR_ERR(wm8753->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_wm8753,
wm8753_dai, ARRAY_SIZE(wm8753_dai));
if (ret != 0)
dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);
return ret;
}
static int wm8753_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8753_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8753_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8753 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8753_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8753 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8753_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8753_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8753_spi_driver);
#endif
}
