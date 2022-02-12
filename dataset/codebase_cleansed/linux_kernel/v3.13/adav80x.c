static int adav80x_dapm_sysclk_check(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = source->codec;
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
const char *clk;
switch (adav80x->clk_src) {
case ADAV80X_CLK_PLL1:
clk = "PLL1";
break;
case ADAV80X_CLK_PLL2:
clk = "PLL2";
break;
case ADAV80X_CLK_XTAL:
clk = "OSC";
break;
default:
return 0;
}
return strcmp(source->name, clk) == 0;
}
static int adav80x_dapm_pll_check(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = source->codec;
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
return adav80x->pll_src == ADAV80X_PLL_SRC_XTAL;
}
static int adav80x_set_deemph(struct snd_soc_codec *codec)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int val;
if (adav80x->deemph) {
switch (adav80x->rate) {
case 32000:
val = ADAV80X_DAC_CTRL2_DEEMPH_32;
break;
case 44100:
val = ADAV80X_DAC_CTRL2_DEEMPH_44;
break;
case 48000:
case 64000:
case 88200:
case 96000:
val = ADAV80X_DAC_CTRL2_DEEMPH_48;
break;
default:
val = ADAV80X_DAC_CTRL2_DEEMPH_NONE;
break;
}
} else {
val = ADAV80X_DAC_CTRL2_DEEMPH_NONE;
}
return regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL2,
ADAV80X_DAC_CTRL2_DEEMPH_MASK, val);
}
static int adav80x_put_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int deemph = ucontrol->value.enumerated.item[0];
if (deemph > 1)
return -EINVAL;
adav80x->deemph = deemph;
return adav80x_set_deemph(codec);
}
static int adav80x_get_deemph(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
ucontrol->value.enumerated.item[0] = adav80x->deemph;
return 0;
}
static int adav80x_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int capture = 0x00;
unsigned int playback = 0x00;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
capture |= ADAV80X_CAPTURE_MODE_MASTER;
playback |= ADAV80X_PLAYBACK_MODE_MASTER;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
capture |= ADAV80X_CAPTURE_MODE_I2S;
playback |= ADAV80X_PLAYBACK_MODE_I2S;
break;
case SND_SOC_DAIFMT_LEFT_J:
capture |= ADAV80X_CAPTURE_MODE_LEFT_J;
playback |= ADAV80X_PLAYBACK_MODE_LEFT_J;
break;
case SND_SOC_DAIFMT_RIGHT_J:
capture |= ADAV80X_CAPTURE_MODE_RIGHT_J;
playback |= ADAV80X_PLAYBACK_MODE_RIGHT_J_24;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
default:
return -EINVAL;
}
regmap_update_bits(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][0],
ADAV80X_CAPTURE_MODE_MASK | ADAV80X_CAPTURE_MODE_MASTER,
capture);
regmap_write(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][1],
playback);
adav80x->dai_fmt[dai->id] = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
return 0;
}
static int adav80x_set_adc_clock(struct snd_soc_codec *codec,
unsigned int sample_rate)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int val;
if (sample_rate <= 48000)
val = ADAV80X_ADC_CTRL1_MODULATOR_128FS;
else
val = ADAV80X_ADC_CTRL1_MODULATOR_64FS;
regmap_update_bits(adav80x->regmap, ADAV80X_ADC_CTRL1,
ADAV80X_ADC_CTRL1_MODULATOR_MASK, val);
return 0;
}
static int adav80x_set_dac_clock(struct snd_soc_codec *codec,
unsigned int sample_rate)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int val;
if (sample_rate <= 48000)
val = ADAV80X_DAC_CTRL2_DIV1 | ADAV80X_DAC_CTRL2_INTERPOL_256FS;
else
val = ADAV80X_DAC_CTRL2_DIV2 | ADAV80X_DAC_CTRL2_INTERPOL_128FS;
regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL2,
ADAV80X_DAC_CTRL2_DIV_MASK | ADAV80X_DAC_CTRL2_INTERPOL_MASK,
val);
return 0;
}
static int adav80x_set_capture_pcm_format(struct snd_soc_codec *codec,
struct snd_soc_dai *dai, snd_pcm_format_t format)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int val;
switch (format) {
case SNDRV_PCM_FORMAT_S16_LE:
val = ADAV80X_CAPTURE_WORD_LEN16;
break;
case SNDRV_PCM_FORMAT_S18_3LE:
val = ADAV80X_CAPTRUE_WORD_LEN18;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val = ADAV80X_CAPTURE_WORD_LEN20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
val = ADAV80X_CAPTURE_WORD_LEN24;
break;
default:
return -EINVAL;
}
regmap_update_bits(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][0],
ADAV80X_CAPTURE_WORD_LEN_MASK, val);
return 0;
}
static int adav80x_set_playback_pcm_format(struct snd_soc_codec *codec,
struct snd_soc_dai *dai, snd_pcm_format_t format)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int val;
if (adav80x->dai_fmt[dai->id] != SND_SOC_DAIFMT_RIGHT_J)
return 0;
switch (format) {
case SNDRV_PCM_FORMAT_S16_LE:
val = ADAV80X_PLAYBACK_MODE_RIGHT_J_16;
break;
case SNDRV_PCM_FORMAT_S18_3LE:
val = ADAV80X_PLAYBACK_MODE_RIGHT_J_18;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val = ADAV80X_PLAYBACK_MODE_RIGHT_J_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
val = ADAV80X_PLAYBACK_MODE_RIGHT_J_24;
break;
default:
return -EINVAL;
}
regmap_update_bits(adav80x->regmap, adav80x_port_ctrl_regs[dai->id][1],
ADAV80X_PLAYBACK_MODE_MASK, val);
return 0;
}
static int adav80x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int rate = params_rate(params);
if (rate * 256 != adav80x->sysclk)
return -EINVAL;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
adav80x_set_playback_pcm_format(codec, dai,
params_format(params));
adav80x_set_dac_clock(codec, rate);
} else {
adav80x_set_capture_pcm_format(codec, dai,
params_format(params));
adav80x_set_adc_clock(codec, rate);
}
adav80x->rate = rate;
adav80x_set_deemph(codec);
return 0;
}
static int adav80x_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source,
unsigned int freq, int dir)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
if (dir == SND_SOC_CLOCK_IN) {
switch (clk_id) {
case ADAV80X_CLK_XIN:
case ADAV80X_CLK_XTAL:
case ADAV80X_CLK_MCLKI:
case ADAV80X_CLK_PLL1:
case ADAV80X_CLK_PLL2:
break;
default:
return -EINVAL;
}
adav80x->sysclk = freq;
if (adav80x->clk_src != clk_id) {
unsigned int iclk_ctrl1, iclk_ctrl2;
adav80x->clk_src = clk_id;
if (clk_id == ADAV80X_CLK_XTAL)
clk_id = ADAV80X_CLK_XIN;
iclk_ctrl1 = ADAV80X_ICLK_CTRL1_DAC_SRC(clk_id) |
ADAV80X_ICLK_CTRL1_ADC_SRC(clk_id) |
ADAV80X_ICLK_CTRL1_ICLK2_SRC(clk_id);
iclk_ctrl2 = ADAV80X_ICLK_CTRL2_ICLK1_SRC(clk_id);
regmap_write(adav80x->regmap, ADAV80X_ICLK_CTRL1,
iclk_ctrl1);
regmap_write(adav80x->regmap, ADAV80X_ICLK_CTRL2,
iclk_ctrl2);
snd_soc_dapm_sync(&codec->dapm);
}
} else {
unsigned int mask;
switch (clk_id) {
case ADAV80X_CLK_SYSCLK1:
case ADAV80X_CLK_SYSCLK2:
case ADAV80X_CLK_SYSCLK3:
break;
default:
return -EINVAL;
}
clk_id -= ADAV80X_CLK_SYSCLK1;
mask = ADAV80X_PLL_OUTE_SYSCLKPD(clk_id);
if (freq == 0) {
regmap_update_bits(adav80x->regmap, ADAV80X_PLL_OUTE,
mask, mask);
adav80x->sysclk_pd[clk_id] = true;
} else {
regmap_update_bits(adav80x->regmap, ADAV80X_PLL_OUTE,
mask, 0);
adav80x->sysclk_pd[clk_id] = false;
}
if (adav80x->sysclk_pd[0])
snd_soc_dapm_disable_pin(&codec->dapm, "PLL1");
else
snd_soc_dapm_force_enable_pin(&codec->dapm, "PLL1");
if (adav80x->sysclk_pd[1] || adav80x->sysclk_pd[2])
snd_soc_dapm_disable_pin(&codec->dapm, "PLL2");
else
snd_soc_dapm_force_enable_pin(&codec->dapm, "PLL2");
snd_soc_dapm_sync(&codec->dapm);
}
return 0;
}
static int adav80x_set_pll(struct snd_soc_codec *codec, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int pll_ctrl1 = 0;
unsigned int pll_ctrl2 = 0;
unsigned int pll_src;
switch (source) {
case ADAV80X_PLL_SRC_XTAL:
case ADAV80X_PLL_SRC_XIN:
case ADAV80X_PLL_SRC_MCLKI:
break;
default:
return -EINVAL;
}
if (!freq_out)
return 0;
switch (freq_in) {
case 27000000:
break;
case 54000000:
if (source == ADAV80X_PLL_SRC_XIN) {
pll_ctrl1 |= ADAV80X_PLL_CTRL1_PLLDIV;
break;
}
default:
return -EINVAL;
}
if (freq_out > 12288000) {
pll_ctrl2 |= ADAV80X_PLL_CTRL2_DOUB(pll_id);
freq_out /= 2;
}
switch (freq_out) {
case 8192000:
pll_ctrl2 |= ADAV80X_PLL_CTRL2_FS_32(pll_id);
break;
case 11289600:
pll_ctrl2 |= ADAV80X_PLL_CTRL2_FS_44(pll_id);
break;
case 12288000:
pll_ctrl2 |= ADAV80X_PLL_CTRL2_FS_48(pll_id);
break;
default:
return -EINVAL;
}
regmap_update_bits(adav80x->regmap, ADAV80X_PLL_CTRL1,
ADAV80X_PLL_CTRL1_PLLDIV, pll_ctrl1);
regmap_update_bits(adav80x->regmap, ADAV80X_PLL_CTRL2,
ADAV80X_PLL_CTRL2_PLL_MASK(pll_id), pll_ctrl2);
if (source != adav80x->pll_src) {
if (source == ADAV80X_PLL_SRC_MCLKI)
pll_src = ADAV80X_PLL_CLK_SRC_PLL_MCLKI(pll_id);
else
pll_src = ADAV80X_PLL_CLK_SRC_PLL_XIN(pll_id);
regmap_update_bits(adav80x->regmap, ADAV80X_PLL_CLK_SRC,
ADAV80X_PLL_CLK_SRC_PLL_MASK(pll_id), pll_src);
adav80x->pll_src = source;
snd_soc_dapm_sync(&codec->dapm);
}
return 0;
}
static int adav80x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
unsigned int mask = ADAV80X_DAC_CTRL1_PD;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL1, mask,
0x00);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(adav80x->regmap, ADAV80X_DAC_CTRL1, mask,
mask);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int adav80x_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
if (!codec->active || !adav80x->rate)
return 0;
return snd_pcm_hw_constraint_minmax(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE, adav80x->rate, adav80x->rate);
}
static void adav80x_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
if (!codec->active)
adav80x->rate = 0;
}
static int adav80x_probe(struct snd_soc_codec *codec)
{
int ret;
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
ret = snd_soc_codec_set_cache_io(codec, 0, 0, SND_SOC_REGMAP);
if (ret) {
dev_err(codec->dev, "failed to set cache I/O: %d\n", ret);
return ret;
}
snd_soc_dapm_force_enable_pin(&codec->dapm, "PLL1");
snd_soc_dapm_force_enable_pin(&codec->dapm, "PLL2");
regmap_write(adav80x->regmap, ADAV80X_PLL_OUTE, 0x20);
regmap_write(adav80x->regmap, ADAV80X_DAC_CTRL3, 0x6);
return adav80x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
}
static int adav80x_suspend(struct snd_soc_codec *codec)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
int ret;
ret = adav80x_set_bias_level(codec, SND_SOC_BIAS_OFF);
regcache_cache_only(adav80x->regmap, true);
return ret;
}
static int adav80x_resume(struct snd_soc_codec *codec)
{
struct adav80x *adav80x = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(adav80x->regmap, false);
adav80x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
regcache_sync(adav80x->regmap);
return 0;
}
static int adav80x_remove(struct snd_soc_codec *codec)
{
return adav80x_set_bias_level(codec, SND_SOC_BIAS_OFF);
}
static int adav80x_bus_probe(struct device *dev, struct regmap *regmap)
{
struct adav80x *adav80x;
int ret;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
adav80x = kzalloc(sizeof(*adav80x), GFP_KERNEL);
if (!adav80x)
return -ENOMEM;
dev_set_drvdata(dev, adav80x);
adav80x->regmap = regmap;
ret = snd_soc_register_codec(dev, &adav80x_codec_driver,
adav80x_dais, ARRAY_SIZE(adav80x_dais));
if (ret)
kfree(adav80x);
return ret;
}
static int adav80x_bus_remove(struct device *dev)
{
snd_soc_unregister_codec(dev);
kfree(dev_get_drvdata(dev));
return 0;
}
static int adav80x_spi_probe(struct spi_device *spi)
{
return adav80x_bus_probe(&spi->dev,
devm_regmap_init_spi(spi, &adav80x_spi_regmap_config));
}
static int adav80x_spi_remove(struct spi_device *spi)
{
return adav80x_bus_remove(&spi->dev);
}
static int adav80x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return adav80x_bus_probe(&client->dev,
devm_regmap_init_i2c(client, &adav80x_i2c_regmap_config));
}
static int adav80x_i2c_remove(struct i2c_client *client)
{
return adav80x_bus_remove(&client->dev);
}
static int __init adav80x_init(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&adav80x_i2c_driver);
if (ret)
return ret;
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&adav80x_spi_driver);
#endif
return ret;
}
static void __exit adav80x_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&adav80x_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&adav80x_spi_driver);
#endif
}
