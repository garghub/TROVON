static int eqmode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int reg;
reg = snd_soc_read(codec, WM8983_EQ1_LOW_SHELF);
if (reg & WM8983_EQ3DMODE)
ucontrol->value.integer.value[0] = 1;
else
ucontrol->value.integer.value[0] = 0;
return 0;
}
static int eqmode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int regpwr2, regpwr3;
unsigned int reg_eq;
if (ucontrol->value.integer.value[0] != 0
&& ucontrol->value.integer.value[0] != 1)
return -EINVAL;
reg_eq = snd_soc_read(codec, WM8983_EQ1_LOW_SHELF);
switch ((reg_eq & WM8983_EQ3DMODE) >> WM8983_EQ3DMODE_SHIFT) {
case 0:
if (!ucontrol->value.integer.value[0])
return 0;
break;
case 1:
if (ucontrol->value.integer.value[0])
return 0;
break;
}
regpwr2 = snd_soc_read(codec, WM8983_POWER_MANAGEMENT_2);
regpwr3 = snd_soc_read(codec, WM8983_POWER_MANAGEMENT_3);
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_2,
WM8983_ADCENR_MASK | WM8983_ADCENL_MASK, 0);
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_3,
WM8983_DACENR_MASK | WM8983_DACENL_MASK, 0);
snd_soc_update_bits(codec, WM8983_EQ1_LOW_SHELF,
WM8983_EQ3DMODE_MASK,
ucontrol->value.integer.value[0]
<< WM8983_EQ3DMODE_SHIFT);
snd_soc_write(codec, WM8983_POWER_MANAGEMENT_2, regpwr2);
snd_soc_write(codec, WM8983_POWER_MANAGEMENT_3, regpwr3);
return 0;
}
static bool wm8983_readable(struct device *dev, unsigned int reg)
{
if (reg > WM8983_MAX_REGISTER)
return 0;
return wm8983_access_masks[reg].read != 0;
}
static int wm8983_dac_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
return snd_soc_update_bits(codec, WM8983_DAC_CONTROL,
WM8983_SOFTMUTE_MASK,
!!mute << WM8983_SOFTMUTE_SHIFT);
}
static int wm8983_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u16 format, master, bcp, lrp;
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
snd_soc_update_bits(codec, WM8983_AUDIO_INTERFACE,
WM8983_FMT_MASK, format << WM8983_FMT_SHIFT);
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
snd_soc_update_bits(codec, WM8983_CLOCK_GEN_CONTROL,
WM8983_MS_MASK, master << WM8983_MS_SHIFT);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
dev_err(dai->dev, "DSP A/B modes are not supported\n");
return -EINVAL;
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
snd_soc_update_bits(codec, WM8983_AUDIO_INTERFACE,
WM8983_LRCP_MASK, lrp << WM8983_LRCP_SHIFT);
snd_soc_update_bits(codec, WM8983_AUDIO_INTERFACE,
WM8983_BCP_MASK, bcp << WM8983_BCP_SHIFT);
return 0;
}
static int wm8983_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
int i;
struct snd_soc_codec *codec = dai->codec;
struct wm8983_priv *wm8983 = snd_soc_codec_get_drvdata(codec);
u16 blen, srate_idx;
u32 tmp;
int srate_best;
int ret;
ret = snd_soc_params_to_bclk(params);
if (ret < 0) {
dev_err(codec->dev, "Failed to convert params to bclk: %d\n", ret);
return ret;
}
wm8983->bclk = ret;
switch (params_width(params)) {
case 16:
blen = 0x0;
break;
case 20:
blen = 0x1;
break;
case 24:
blen = 0x2;
break;
case 32:
blen = 0x3;
break;
default:
dev_err(dai->dev, "Unsupported word length %u\n",
params_width(params));
return -EINVAL;
}
snd_soc_update_bits(codec, WM8983_AUDIO_INTERFACE,
WM8983_WL_MASK, blen << WM8983_WL_SHIFT);
srate_idx = 0;
srate_best = abs(srates[0] - params_rate(params));
for (i = 1; i < ARRAY_SIZE(srates); ++i) {
if (abs(srates[i] - params_rate(params)) >= srate_best)
continue;
srate_idx = i;
srate_best = abs(srates[i] - params_rate(params));
}
dev_dbg(dai->dev, "Selected SRATE = %d\n", srates[srate_idx]);
snd_soc_update_bits(codec, WM8983_ADDITIONAL_CONTROL,
WM8983_SR_MASK, srate_idx << WM8983_SR_SHIFT);
dev_dbg(dai->dev, "Target BCLK = %uHz\n", wm8983->bclk);
dev_dbg(dai->dev, "SYSCLK = %uHz\n", wm8983->sysclk);
for (i = 0; i < ARRAY_SIZE(fs_ratios); ++i) {
if (wm8983->sysclk / params_rate(params)
== fs_ratios[i].ratio)
break;
}
if (i == ARRAY_SIZE(fs_ratios)) {
dev_err(dai->dev, "Unable to configure MCLK ratio %u/%u\n",
wm8983->sysclk, params_rate(params));
return -EINVAL;
}
dev_dbg(dai->dev, "MCLK ratio = %dfs\n", fs_ratios[i].ratio);
snd_soc_update_bits(codec, WM8983_CLOCK_GEN_CONTROL,
WM8983_MCLKDIV_MASK, i << WM8983_MCLKDIV_SHIFT);
tmp = (wm8983->sysclk / fs_ratios[i].div) * 10;
for (i = 0; i < ARRAY_SIZE(bclk_divs); ++i) {
if (wm8983->bclk == tmp / bclk_divs[i])
break;
}
if (i == ARRAY_SIZE(bclk_divs)) {
dev_err(dai->dev, "No matching BCLK divider found\n");
return -EINVAL;
}
dev_dbg(dai->dev, "BCLK div = %d\n", i);
snd_soc_update_bits(codec, WM8983_CLOCK_GEN_CONTROL,
WM8983_BCLKDIV_MASK, i << WM8983_BCLKDIV_SHIFT);
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
printk(KERN_ERR "%s: WM8983 N value is not within"
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
static int wm8983_set_pll(struct snd_soc_dai *dai, int pll_id,
int source, unsigned int freq_in,
unsigned int freq_out)
{
int ret;
struct snd_soc_codec *codec;
struct pll_div pll_div;
codec = dai->codec;
if (!freq_in || !freq_out) {
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_PLLEN_MASK, 0);
return 0;
} else {
ret = pll_factors(&pll_div, freq_out * 4 * 2, freq_in);
if (ret)
return ret;
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_PLLEN_MASK, 0);
snd_soc_write(codec, WM8983_PLL_N,
(pll_div.div2 << WM8983_PLL_PRESCALE_SHIFT)
| pll_div.n);
snd_soc_write(codec, WM8983_PLL_K_3, pll_div.k & 0x1ff);
snd_soc_write(codec, WM8983_PLL_K_2, (pll_div.k >> 9) & 0x1ff);
snd_soc_write(codec, WM8983_PLL_K_1, (pll_div.k >> 18));
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_PLLEN_MASK, WM8983_PLLEN);
}
return 0;
}
static int wm8983_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8983_priv *wm8983 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case WM8983_CLKSRC_MCLK:
snd_soc_update_bits(codec, WM8983_CLOCK_GEN_CONTROL,
WM8983_CLKSEL_MASK, 0);
break;
case WM8983_CLKSRC_PLL:
snd_soc_update_bits(codec, WM8983_CLOCK_GEN_CONTROL,
WM8983_CLKSEL_MASK, WM8983_CLKSEL);
break;
default:
dev_err(dai->dev, "Unknown clock source: %d\n", clk_id);
return -EINVAL;
}
wm8983->sysclk = freq;
return 0;
}
static int wm8983_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct wm8983_priv *wm8983 = snd_soc_codec_get_drvdata(codec);
int ret;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_VMIDSEL_MASK,
1 << WM8983_VMIDSEL_SHIFT);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regcache_sync(wm8983->regmap);
if (ret < 0) {
dev_err(codec->dev, "Failed to sync cache: %d\n", ret);
return ret;
}
snd_soc_update_bits(codec, WM8983_OUT4_TO_ADC,
WM8983_POBCTRL_MASK | WM8983_DELEN_MASK,
WM8983_POBCTRL | WM8983_DELEN);
snd_soc_update_bits(codec, WM8983_OUTPUT_CTRL,
WM8983_TSDEN_MASK, WM8983_TSDEN);
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_BIASEN_MASK, WM8983_BIASEN);
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_VMIDSEL_MASK,
1 << WM8983_VMIDSEL_SHIFT);
msleep(250);
snd_soc_update_bits(codec, WM8983_OUT4_TO_ADC,
WM8983_POBCTRL_MASK |
WM8983_DELEN_MASK, 0);
}
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_VMIDSEL_MASK,
2 << WM8983_VMIDSEL_SHIFT);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8983_OUTPUT_CTRL,
WM8983_TSDEN_MASK, 0);
snd_soc_update_bits(codec, WM8983_POWER_MANAGEMENT_1,
WM8983_VMIDSEL_MASK | WM8983_BIASEN_MASK,
0);
msleep(100);
snd_soc_write(codec, WM8983_POWER_MANAGEMENT_1, 0);
snd_soc_write(codec, WM8983_POWER_MANAGEMENT_2, 0);
snd_soc_write(codec, WM8983_POWER_MANAGEMENT_3, 0);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8983_suspend(struct snd_soc_codec *codec)
{
wm8983_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8983_resume(struct snd_soc_codec *codec)
{
wm8983_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8983_remove(struct snd_soc_codec *codec)
{
wm8983_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8983_probe(struct snd_soc_codec *codec)
{
int ret;
int i;
ret = snd_soc_write(codec, WM8983_SOFTWARE_RESET, 0);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(vol_update_regs); ++i)
snd_soc_update_bits(codec, vol_update_regs[i],
0x100, 0x100);
for (i = WM8983_LOUT1_HP_VOLUME_CTRL;
i <= WM8983_OUT4_MONO_MIX_CTRL; ++i)
snd_soc_update_bits(codec, i, 0x40, 0x40);
snd_soc_update_bits(codec, WM8983_DAC_CONTROL,
WM8983_SOFTMUTE_MASK,
WM8983_SOFTMUTE);
snd_soc_update_bits(codec, WM8983_BIAS_CTRL,
WM8983_BIASCUT, WM8983_BIASCUT);
return 0;
}
static int wm8983_spi_probe(struct spi_device *spi)
{
struct wm8983_priv *wm8983;
int ret;
wm8983 = devm_kzalloc(&spi->dev, sizeof *wm8983, GFP_KERNEL);
if (!wm8983)
return -ENOMEM;
wm8983->regmap = devm_regmap_init_spi(spi, &wm8983_regmap);
if (IS_ERR(wm8983->regmap)) {
ret = PTR_ERR(wm8983->regmap);
dev_err(&spi->dev, "Failed to init regmap: %d\n", ret);
return ret;
}
spi_set_drvdata(spi, wm8983);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8983, &wm8983_dai, 1);
return ret;
}
static int wm8983_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8983_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8983_priv *wm8983;
int ret;
wm8983 = devm_kzalloc(&i2c->dev, sizeof *wm8983, GFP_KERNEL);
if (!wm8983)
return -ENOMEM;
wm8983->regmap = devm_regmap_init_i2c(i2c, &wm8983_regmap);
if (IS_ERR(wm8983->regmap)) {
ret = PTR_ERR(wm8983->regmap);
dev_err(&i2c->dev, "Failed to init regmap: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, wm8983);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8983, &wm8983_dai, 1);
return ret;
}
static int wm8983_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8983_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8983_i2c_driver);
if (ret) {
printk(KERN_ERR "Failed to register wm8983 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8983_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8983 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8983_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8983_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8983_spi_driver);
#endif
}
