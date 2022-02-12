static bool wm8985_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8985_SOFTWARE_RESET:
case WM8985_POWER_MANAGEMENT_1:
case WM8985_POWER_MANAGEMENT_2:
case WM8985_POWER_MANAGEMENT_3:
case WM8985_AUDIO_INTERFACE:
case WM8985_COMPANDING_CONTROL:
case WM8985_CLOCK_GEN_CONTROL:
case WM8985_ADDITIONAL_CONTROL:
case WM8985_GPIO_CONTROL:
case WM8985_JACK_DETECT_CONTROL_1:
case WM8985_DAC_CONTROL:
case WM8985_LEFT_DAC_DIGITAL_VOL:
case WM8985_RIGHT_DAC_DIGITAL_VOL:
case WM8985_JACK_DETECT_CONTROL_2:
case WM8985_ADC_CONTROL:
case WM8985_LEFT_ADC_DIGITAL_VOL:
case WM8985_RIGHT_ADC_DIGITAL_VOL:
case WM8985_EQ1_LOW_SHELF:
case WM8985_EQ2_PEAK_1:
case WM8985_EQ3_PEAK_2:
case WM8985_EQ4_PEAK_3:
case WM8985_EQ5_HIGH_SHELF:
case WM8985_DAC_LIMITER_1:
case WM8985_DAC_LIMITER_2:
case WM8985_NOTCH_FILTER_1:
case WM8985_NOTCH_FILTER_2:
case WM8985_NOTCH_FILTER_3:
case WM8985_NOTCH_FILTER_4:
case WM8985_ALC_CONTROL_1:
case WM8985_ALC_CONTROL_2:
case WM8985_ALC_CONTROL_3:
case WM8985_NOISE_GATE:
case WM8985_PLL_N:
case WM8985_PLL_K_1:
case WM8985_PLL_K_2:
case WM8985_PLL_K_3:
case WM8985_3D_CONTROL:
case WM8985_OUT4_TO_ADC:
case WM8985_BEEP_CONTROL:
case WM8985_INPUT_CTRL:
case WM8985_LEFT_INP_PGA_GAIN_CTRL:
case WM8985_RIGHT_INP_PGA_GAIN_CTRL:
case WM8985_LEFT_ADC_BOOST_CTRL:
case WM8985_RIGHT_ADC_BOOST_CTRL:
case WM8985_OUTPUT_CTRL0:
case WM8985_LEFT_MIXER_CTRL:
case WM8985_RIGHT_MIXER_CTRL:
case WM8985_LOUT1_HP_VOLUME_CTRL:
case WM8985_ROUT1_HP_VOLUME_CTRL:
case WM8985_LOUT2_SPK_VOLUME_CTRL:
case WM8985_ROUT2_SPK_VOLUME_CTRL:
case WM8985_OUT3_MIXER_CTRL:
case WM8985_OUT4_MONO_MIX_CTRL:
case WM8985_OUTPUT_CTRL1:
case WM8985_BIAS_CTRL:
return true;
default:
return false;
}
}
static int eqmode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int reg;
reg = snd_soc_read(codec, WM8985_EQ1_LOW_SHELF);
if (reg & WM8985_EQ3DMODE)
ucontrol->value.integer.value[0] = 1;
else
ucontrol->value.integer.value[0] = 0;
return 0;
}
static int eqmode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int regpwr2, regpwr3;
unsigned int reg_eq;
if (ucontrol->value.integer.value[0] != 0
&& ucontrol->value.integer.value[0] != 1)
return -EINVAL;
reg_eq = snd_soc_read(codec, WM8985_EQ1_LOW_SHELF);
switch ((reg_eq & WM8985_EQ3DMODE) >> WM8985_EQ3DMODE_SHIFT) {
case 0:
if (!ucontrol->value.integer.value[0])
return 0;
break;
case 1:
if (ucontrol->value.integer.value[0])
return 0;
break;
}
regpwr2 = snd_soc_read(codec, WM8985_POWER_MANAGEMENT_2);
regpwr3 = snd_soc_read(codec, WM8985_POWER_MANAGEMENT_3);
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_2,
WM8985_ADCENR_MASK | WM8985_ADCENL_MASK, 0);
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_3,
WM8985_DACENR_MASK | WM8985_DACENL_MASK, 0);
snd_soc_update_bits(codec, WM8985_ADDITIONAL_CONTROL,
WM8985_M128ENB_MASK, WM8985_M128ENB);
snd_soc_update_bits(codec, WM8985_EQ1_LOW_SHELF,
WM8985_EQ3DMODE_MASK,
ucontrol->value.integer.value[0]
<< WM8985_EQ3DMODE_SHIFT);
snd_soc_write(codec, WM8985_POWER_MANAGEMENT_2, regpwr2);
snd_soc_write(codec, WM8985_POWER_MANAGEMENT_3, regpwr3);
return 0;
}
static int wm8985_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8985_SOFTWARE_RESET, 0x0);
}
static int wm8985_dac_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
return snd_soc_update_bits(codec, WM8985_DAC_CONTROL,
WM8985_SOFTMUTE_MASK,
!!mute << WM8985_SOFTMUTE_SHIFT);
}
static int wm8985_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec;
u16 format, master, bcp, lrp;
codec = dai->codec;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
format = 0x2;
break;
case SND_SOC_DAIFMT_RIGHT_J:
format = 0x0;
break;
case SND_SOC_DAIFMT_LEFT_J:
format = 0x1;
break;
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
format = 0x3;
break;
default:
dev_err(dai->dev, "Unknown dai format\n");
return -EINVAL;
}
snd_soc_update_bits(codec, WM8985_AUDIO_INTERFACE,
WM8985_FMT_MASK, format << WM8985_FMT_SHIFT);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
master = 0;
break;
default:
dev_err(dai->dev, "Unknown master/slave configuration\n");
return -EINVAL;
}
snd_soc_update_bits(codec, WM8985_CLOCK_GEN_CONTROL,
WM8985_MS_MASK, master << WM8985_MS_SHIFT);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
case SND_SOC_DAIFMT_NB_IF:
return -EINVAL;
default:
break;
}
break;
default:
break;
}
bcp = lrp = 0;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
bcp = lrp = 1;
break;
case SND_SOC_DAIFMT_IB_NF:
bcp = 1;
break;
case SND_SOC_DAIFMT_NB_IF:
lrp = 1;
break;
default:
dev_err(dai->dev, "Unknown polarity configuration\n");
return -EINVAL;
}
snd_soc_update_bits(codec, WM8985_AUDIO_INTERFACE,
WM8985_LRP_MASK, lrp << WM8985_LRP_SHIFT);
snd_soc_update_bits(codec, WM8985_AUDIO_INTERFACE,
WM8985_BCP_MASK, bcp << WM8985_BCP_SHIFT);
return 0;
}
static int wm8985_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
int i;
struct snd_soc_codec *codec;
struct wm8985_priv *wm8985;
u16 blen, srate_idx;
unsigned int tmp;
int srate_best;
codec = dai->codec;
wm8985 = snd_soc_codec_get_drvdata(codec);
wm8985->bclk = snd_soc_params_to_bclk(params);
if ((int)wm8985->bclk < 0)
return wm8985->bclk;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
blen = 0x0;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
blen = 0x1;
break;
case SNDRV_PCM_FORMAT_S24_LE:
blen = 0x2;
break;
case SNDRV_PCM_FORMAT_S32_LE:
blen = 0x3;
break;
default:
dev_err(dai->dev, "Unsupported word length %u\n",
params_format(params));
return -EINVAL;
}
snd_soc_update_bits(codec, WM8985_AUDIO_INTERFACE,
WM8985_WL_MASK, blen << WM8985_WL_SHIFT);
srate_idx = 0;
srate_best = abs(srates[0] - params_rate(params));
for (i = 1; i < ARRAY_SIZE(srates); ++i) {
if (abs(srates[i] - params_rate(params)) >= srate_best)
continue;
srate_idx = i;
srate_best = abs(srates[i] - params_rate(params));
}
dev_dbg(dai->dev, "Selected SRATE = %d\n", srates[srate_idx]);
snd_soc_update_bits(codec, WM8985_ADDITIONAL_CONTROL,
WM8985_SR_MASK, srate_idx << WM8985_SR_SHIFT);
dev_dbg(dai->dev, "Target BCLK = %uHz\n", wm8985->bclk);
dev_dbg(dai->dev, "SYSCLK = %uHz\n", wm8985->sysclk);
for (i = 0; i < ARRAY_SIZE(fs_ratios); ++i) {
if (wm8985->sysclk / params_rate(params)
== fs_ratios[i].ratio)
break;
}
if (i == ARRAY_SIZE(fs_ratios)) {
dev_err(dai->dev, "Unable to configure MCLK ratio %u/%u\n",
wm8985->sysclk, params_rate(params));
return -EINVAL;
}
dev_dbg(dai->dev, "MCLK ratio = %dfs\n", fs_ratios[i].ratio);
snd_soc_update_bits(codec, WM8985_CLOCK_GEN_CONTROL,
WM8985_MCLKDIV_MASK, i << WM8985_MCLKDIV_SHIFT);
tmp = (wm8985->sysclk / fs_ratios[i].div) * 10;
for (i = 0; i < ARRAY_SIZE(bclk_divs); ++i) {
if (wm8985->bclk == tmp / bclk_divs[i])
break;
}
if (i == ARRAY_SIZE(bclk_divs)) {
dev_err(dai->dev, "No matching BCLK divider found\n");
return -EINVAL;
}
dev_dbg(dai->dev, "BCLK div = %d\n", i);
snd_soc_update_bits(codec, WM8985_CLOCK_GEN_CONTROL,
WM8985_BCLKDIV_MASK, i << WM8985_BCLKDIV_SHIFT);
return 0;
}
static int pll_factors(struct pll_div *pll_div, unsigned int target,
unsigned int source)
{
u64 Kpart;
unsigned long int K, Ndiv, Nmod;
pll_div->div2 = 0;
Ndiv = target / source;
if (Ndiv < 6) {
source >>= 1;
pll_div->div2 = 1;
Ndiv = target / source;
}
if (Ndiv < 6 || Ndiv > 12) {
printk(KERN_ERR "%s: WM8985 N value is not within"
" the recommended range: %lu\n", __func__, Ndiv);
return -EINVAL;
}
pll_div->n = Ndiv;
Nmod = target % source;
Kpart = FIXED_PLL_SIZE * (u64)Nmod;
do_div(Kpart, source);
K = Kpart & 0xffffffff;
if ((K % 10) >= 5)
K += 5;
K /= 10;
pll_div->k = K;
return 0;
}
static int wm8985_set_pll(struct snd_soc_dai *dai, int pll_id,
int source, unsigned int freq_in,
unsigned int freq_out)
{
int ret;
struct snd_soc_codec *codec;
struct pll_div pll_div;
codec = dai->codec;
if (!freq_in || !freq_out) {
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_PLLEN_MASK, 0);
} else {
ret = pll_factors(&pll_div, freq_out * 4 * 2, freq_in);
if (ret)
return ret;
snd_soc_write(codec, WM8985_PLL_N,
(pll_div.div2 << WM8985_PLL_PRESCALE_SHIFT)
| pll_div.n);
snd_soc_write(codec, WM8985_PLL_K_3, pll_div.k & 0x1ff);
snd_soc_write(codec, WM8985_PLL_K_2, (pll_div.k >> 9) & 0x1ff);
snd_soc_write(codec, WM8985_PLL_K_1, (pll_div.k >> 18));
snd_soc_update_bits(codec, WM8985_CLOCK_GEN_CONTROL,
WM8985_CLKSEL_MASK, WM8985_CLKSEL);
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_PLLEN_MASK, WM8985_PLLEN);
}
return 0;
}
static int wm8985_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec;
struct wm8985_priv *wm8985;
codec = dai->codec;
wm8985 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case WM8985_CLKSRC_MCLK:
snd_soc_update_bits(codec, WM8985_CLOCK_GEN_CONTROL,
WM8985_CLKSEL_MASK, 0);
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_PLLEN_MASK, 0);
break;
case WM8985_CLKSRC_PLL:
snd_soc_update_bits(codec, WM8985_CLOCK_GEN_CONTROL,
WM8985_CLKSEL_MASK, WM8985_CLKSEL);
break;
default:
dev_err(dai->dev, "Unknown clock source %d\n", clk_id);
return -EINVAL;
}
wm8985->sysclk = freq;
return 0;
}
static int wm8985_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
int ret;
struct wm8985_priv *wm8985;
wm8985 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_VMIDSEL_MASK,
1 << WM8985_VMIDSEL_SHIFT);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8985->supplies),
wm8985->supplies);
if (ret) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
regcache_sync(wm8985->regmap);
snd_soc_update_bits(codec, WM8985_OUT4_TO_ADC,
WM8985_POBCTRL_MASK,
WM8985_POBCTRL);
snd_soc_update_bits(codec, WM8985_OUTPUT_CTRL0,
WM8985_TSDEN_MASK, WM8985_TSDEN);
snd_soc_update_bits(codec, WM8985_OUTPUT_CTRL0,
WM8985_TSOPCTRL_MASK,
WM8985_TSOPCTRL);
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_BIASEN_MASK, WM8985_BIASEN);
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_VMIDSEL_MASK,
1 << WM8985_VMIDSEL_SHIFT);
msleep(500);
snd_soc_update_bits(codec, WM8985_OUT4_TO_ADC,
WM8985_POBCTRL_MASK, 0);
}
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_VMIDSEL_MASK,
2 << WM8985_VMIDSEL_SHIFT);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8985_OUTPUT_CTRL0,
WM8985_TSOPCTRL_MASK, 0);
snd_soc_update_bits(codec, WM8985_OUTPUT_CTRL0,
WM8985_TSDEN_MASK, 0);
snd_soc_update_bits(codec, WM8985_POWER_MANAGEMENT_1,
WM8985_VMIDSEL_MASK | WM8985_BIASEN_MASK,
0);
snd_soc_write(codec, WM8985_POWER_MANAGEMENT_1, 0);
snd_soc_write(codec, WM8985_POWER_MANAGEMENT_2, 0);
snd_soc_write(codec, WM8985_POWER_MANAGEMENT_3, 0);
regcache_mark_dirty(wm8985->regmap);
regulator_bulk_disable(ARRAY_SIZE(wm8985->supplies),
wm8985->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8985_suspend(struct snd_soc_codec *codec)
{
wm8985_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8985_resume(struct snd_soc_codec *codec)
{
wm8985_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8985_remove(struct snd_soc_codec *codec)
{
struct wm8985_priv *wm8985;
wm8985 = snd_soc_codec_get_drvdata(codec);
wm8985_set_bias_level(codec, SND_SOC_BIAS_OFF);
regulator_bulk_free(ARRAY_SIZE(wm8985->supplies), wm8985->supplies);
return 0;
}
static int wm8985_probe(struct snd_soc_codec *codec)
{
size_t i;
struct wm8985_priv *wm8985;
int ret;
wm8985 = snd_soc_codec_get_drvdata(codec);
codec->control_data = wm8985->regmap;
ret = snd_soc_codec_set_cache_io(codec, 7, 9, SND_SOC_REGMAP);
if (ret < 0) {
dev_err(codec->dev, "Failed to set cache i/o: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(wm8985->supplies); i++)
wm8985->supplies[i].supply = wm8985_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8985->supplies),
wm8985->supplies);
if (ret) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8985->supplies),
wm8985->supplies);
if (ret) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
goto err_reg_get;
}
ret = wm8985_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
goto err_reg_enable;
}
for (i = 0; i < ARRAY_SIZE(volume_update_regs); ++i)
snd_soc_update_bits(codec, volume_update_regs[i],
0x100, 0x100);
snd_soc_update_bits(codec, WM8985_BIAS_CTRL, WM8985_BIASCUT,
WM8985_BIASCUT);
wm8985_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
err_reg_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8985->supplies), wm8985->supplies);
err_reg_get:
regulator_bulk_free(ARRAY_SIZE(wm8985->supplies), wm8985->supplies);
return ret;
}
static int wm8985_spi_probe(struct spi_device *spi)
{
struct wm8985_priv *wm8985;
int ret;
wm8985 = devm_kzalloc(&spi->dev, sizeof *wm8985, GFP_KERNEL);
if (!wm8985)
return -ENOMEM;
spi_set_drvdata(spi, wm8985);
wm8985->regmap = devm_regmap_init_spi(spi, &wm8985_regmap);
if (IS_ERR(wm8985->regmap)) {
ret = PTR_ERR(wm8985->regmap);
dev_err(&spi->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8985, &wm8985_dai, 1);
return ret;
}
static int wm8985_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8985_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8985_priv *wm8985;
int ret;
wm8985 = devm_kzalloc(&i2c->dev, sizeof *wm8985, GFP_KERNEL);
if (!wm8985)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8985);
wm8985->regmap = devm_regmap_init_i2c(i2c, &wm8985_regmap);
if (IS_ERR(wm8985->regmap)) {
ret = PTR_ERR(wm8985->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8985, &wm8985_dai, 1);
return ret;
}
static int wm8985_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static int __init wm8985_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8985_i2c_driver);
if (ret) {
printk(KERN_ERR "Failed to register wm8985 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8985_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8985 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8985_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8985_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8985_spi_driver);
#endif
}
