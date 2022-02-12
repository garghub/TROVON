static int txsrc_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec;
unsigned int src;
codec = snd_soc_kcontrol_codec(kcontrol);
src = snd_soc_read(codec, WM8804_SPDTX4);
if (src & 0x40)
ucontrol->value.integer.value[0] = 1;
else
ucontrol->value.integer.value[0] = 0;
return 0;
}
static int txsrc_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec;
unsigned int src, txpwr;
codec = snd_soc_kcontrol_codec(kcontrol);
if (ucontrol->value.integer.value[0] != 0
&& ucontrol->value.integer.value[0] != 1)
return -EINVAL;
src = snd_soc_read(codec, WM8804_SPDTX4);
switch ((src & 0x40) >> 6) {
case 0:
if (!ucontrol->value.integer.value[0])
return 0;
break;
case 1:
if (ucontrol->value.integer.value[1])
return 0;
break;
}
txpwr = snd_soc_read(codec, WM8804_PWRDN) & 0x4;
snd_soc_update_bits(codec, WM8804_PWRDN, 0x4, 0x4);
snd_soc_update_bits(codec, WM8804_SPDTX4, 0x40,
ucontrol->value.integer.value[0] << 6);
if (ucontrol->value.integer.value[0]) {
snd_soc_update_bits(codec, WM8804_PWRDN, 0x2, 0x2);
snd_soc_update_bits(codec, WM8804_PWRDN, 0x10, 0);
} else {
snd_soc_update_bits(codec, WM8804_PWRDN, 0x2, 0);
}
snd_soc_update_bits(codec, WM8804_PWRDN, 0x4, txpwr);
return 0;
}
static bool wm8804_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM8804_RST_DEVID1:
case WM8804_DEVID2:
case WM8804_DEVREV:
case WM8804_INTSTAT:
case WM8804_SPDSTAT:
case WM8804_RXCHAN1:
case WM8804_RXCHAN2:
case WM8804_RXCHAN3:
case WM8804_RXCHAN4:
case WM8804_RXCHAN5:
return true;
default:
return false;
}
}
static int wm8804_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8804_RST_DEVID1, 0x0);
}
static int wm8804_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
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
snd_soc_update_bits(codec, WM8804_AIFTX, 0x3, format);
snd_soc_update_bits(codec, WM8804_AIFRX, 0x3, format);
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
snd_soc_update_bits(codec, WM8804_AIFRX, 0x40, master << 6);
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
snd_soc_update_bits(codec, WM8804_AIFTX, 0x10 | 0x20,
(bcp << 4) | (lrp << 5));
snd_soc_update_bits(codec, WM8804_AIFRX, 0x10 | 0x20,
(bcp << 4) | (lrp << 5));
return 0;
}
static int wm8804_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec;
u16 blen;
codec = dai->codec;
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
default:
dev_err(dai->dev, "Unsupported word length: %u\n",
params_format(params));
return -EINVAL;
}
snd_soc_update_bits(codec, WM8804_AIFTX, 0xc, blen << 2);
snd_soc_update_bits(codec, WM8804_AIFRX, 0xc, blen << 2);
return 0;
}
static int pll_factors(struct pll_div *pll_div, unsigned int target,
unsigned int source, unsigned int mclk_div)
{
u64 Kpart;
unsigned long int K, Ndiv, Nmod, tmp;
int i;
for (i = 0; i < ARRAY_SIZE(post_table); i++) {
tmp = target * post_table[i].div;
if ((tmp >= 90000000 && tmp <= 100000000) &&
(mclk_div == post_table[i].mclkdiv)) {
pll_div->freqmode = post_table[i].freqmode;
pll_div->mclkdiv = post_table[i].mclkdiv;
target *= post_table[i].div;
break;
}
}
if (i == ARRAY_SIZE(post_table)) {
pr_err("%s: Unable to scale output frequency: %uHz\n",
__func__, target);
return -EINVAL;
}
pll_div->prescale = 0;
Ndiv = target / source;
if (Ndiv < 5) {
source >>= 1;
pll_div->prescale = 1;
Ndiv = target / source;
}
if (Ndiv < 5 || Ndiv > 13) {
pr_err("%s: WM8804 N value is not within the recommended range: %lu\n",
__func__, Ndiv);
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
static int wm8804_set_pll(struct snd_soc_dai *dai, int pll_id,
int source, unsigned int freq_in,
unsigned int freq_out)
{
struct snd_soc_codec *codec;
codec = dai->codec;
if (!freq_in || !freq_out) {
snd_soc_update_bits(codec, WM8804_PWRDN, 0x1, 0x1);
return 0;
} else {
int ret;
struct pll_div pll_div;
struct wm8804_priv *wm8804;
wm8804 = snd_soc_codec_get_drvdata(codec);
ret = pll_factors(&pll_div, freq_out, freq_in,
wm8804->mclk_div);
if (ret)
return ret;
snd_soc_update_bits(codec, WM8804_PWRDN, 0x1, 0x1);
snd_soc_update_bits(codec, WM8804_PLL4, 0xf | 0x10,
pll_div.n | (pll_div.prescale << 4));
snd_soc_update_bits(codec, WM8804_PLL5, 0x3 | 0x8,
pll_div.freqmode | (pll_div.mclkdiv << 3));
snd_soc_write(codec, WM8804_PLL1, pll_div.k & 0xff);
snd_soc_write(codec, WM8804_PLL2, (pll_div.k >> 8) & 0xff);
snd_soc_write(codec, WM8804_PLL3, pll_div.k >> 16);
snd_soc_update_bits(codec, WM8804_PWRDN, 0x1, 0);
}
return 0;
}
static int wm8804_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec;
codec = dai->codec;
switch (clk_id) {
case WM8804_TX_CLKSRC_MCLK:
if ((freq >= 10000000 && freq <= 14400000)
|| (freq >= 16280000 && freq <= 27000000))
snd_soc_update_bits(codec, WM8804_PLL6, 0x80, 0x80);
else {
dev_err(dai->dev, "OSCCLOCK is not within the "
"recommended range: %uHz\n", freq);
return -EINVAL;
}
break;
case WM8804_TX_CLKSRC_PLL:
snd_soc_update_bits(codec, WM8804_PLL6, 0x80, 0);
break;
case WM8804_CLKOUT_SRC_CLK1:
snd_soc_update_bits(codec, WM8804_PLL6, 0x8, 0);
break;
case WM8804_CLKOUT_SRC_OSCCLK:
snd_soc_update_bits(codec, WM8804_PLL6, 0x8, 0x8);
break;
default:
dev_err(dai->dev, "Unknown clock source: %d\n", clk_id);
return -EINVAL;
}
return 0;
}
static int wm8804_set_clkdiv(struct snd_soc_dai *dai,
int div_id, int div)
{
struct snd_soc_codec *codec;
struct wm8804_priv *wm8804;
codec = dai->codec;
switch (div_id) {
case WM8804_CLKOUT_DIV:
snd_soc_update_bits(codec, WM8804_PLL5, 0x30,
(div & 0x3) << 4);
break;
case WM8804_MCLK_DIV:
wm8804 = snd_soc_codec_get_drvdata(codec);
wm8804->mclk_div = div;
break;
default:
dev_err(dai->dev, "Unknown clock divider: %d\n", div_id);
return -EINVAL;
}
return 0;
}
static int wm8804_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
int ret;
struct wm8804_priv *wm8804;
wm8804 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
snd_soc_update_bits(codec, WM8804_PWRDN, 0x9, 0);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
ret = regulator_bulk_enable(ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
if (ret) {
dev_err(codec->dev,
"Failed to enable supplies: %d\n",
ret);
return ret;
}
regcache_sync(wm8804->regmap);
}
snd_soc_update_bits(codec, WM8804_PWRDN, 0x9, 0x9);
break;
case SND_SOC_BIAS_OFF:
snd_soc_update_bits(codec, WM8804_PWRDN, 0x9, 0x9);
regulator_bulk_disable(ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8804_suspend(struct snd_soc_codec *codec)
{
wm8804_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8804_resume(struct snd_soc_codec *codec)
{
wm8804_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int wm8804_remove(struct snd_soc_codec *codec)
{
struct wm8804_priv *wm8804;
int i;
wm8804 = snd_soc_codec_get_drvdata(codec);
wm8804_set_bias_level(codec, SND_SOC_BIAS_OFF);
for (i = 0; i < ARRAY_SIZE(wm8804->supplies); ++i)
regulator_unregister_notifier(wm8804->supplies[i].consumer,
&wm8804->disable_nb[i]);
return 0;
}
static int wm8804_probe(struct snd_soc_codec *codec)
{
struct wm8804_priv *wm8804;
int i, id1, id2, ret;
wm8804 = snd_soc_codec_get_drvdata(codec);
for (i = 0; i < ARRAY_SIZE(wm8804->supplies); i++)
wm8804->supplies[i].supply = wm8804_supply_names[i];
ret = devm_regulator_bulk_get(codec->dev, ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
if (ret) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
wm8804->disable_nb[0].notifier_call = wm8804_regulator_event_0;
wm8804->disable_nb[1].notifier_call = wm8804_regulator_event_1;
for (i = 0; i < ARRAY_SIZE(wm8804->supplies); i++) {
ret = regulator_register_notifier(wm8804->supplies[i].consumer,
&wm8804->disable_nb[i]);
if (ret != 0) {
dev_err(codec->dev,
"Failed to register regulator notifier: %d\n",
ret);
}
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm8804->supplies),
wm8804->supplies);
if (ret) {
dev_err(codec->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
id1 = snd_soc_read(codec, WM8804_RST_DEVID1);
if (id1 < 0) {
dev_err(codec->dev, "Failed to read device ID: %d\n", id1);
ret = id1;
goto err_reg_enable;
}
id2 = snd_soc_read(codec, WM8804_DEVID2);
if (id2 < 0) {
dev_err(codec->dev, "Failed to read device ID: %d\n", id2);
ret = id2;
goto err_reg_enable;
}
id2 = (id2 << 8) | id1;
if (id2 != 0x8805) {
dev_err(codec->dev, "Invalid device ID: %#x\n", id2);
ret = -EINVAL;
goto err_reg_enable;
}
ret = snd_soc_read(codec, WM8804_DEVREV);
if (ret < 0) {
dev_err(codec->dev, "Failed to read device revision: %d\n",
ret);
goto err_reg_enable;
}
dev_info(codec->dev, "revision %c\n", ret + 'A');
ret = wm8804_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset: %d\n", ret);
goto err_reg_enable;
}
wm8804_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
err_reg_enable:
regulator_bulk_disable(ARRAY_SIZE(wm8804->supplies), wm8804->supplies);
return ret;
}
static int wm8804_spi_probe(struct spi_device *spi)
{
struct wm8804_priv *wm8804;
int ret;
wm8804 = devm_kzalloc(&spi->dev, sizeof *wm8804, GFP_KERNEL);
if (!wm8804)
return -ENOMEM;
wm8804->regmap = devm_regmap_init_spi(spi, &wm8804_regmap_config);
if (IS_ERR(wm8804->regmap)) {
ret = PTR_ERR(wm8804->regmap);
return ret;
}
spi_set_drvdata(spi, wm8804);
ret = snd_soc_register_codec(&spi->dev,
&soc_codec_dev_wm8804, &wm8804_dai, 1);
return ret;
}
static int wm8804_spi_remove(struct spi_device *spi)
{
snd_soc_unregister_codec(&spi->dev);
return 0;
}
static int wm8804_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8804_priv *wm8804;
int ret;
wm8804 = devm_kzalloc(&i2c->dev, sizeof *wm8804, GFP_KERNEL);
if (!wm8804)
return -ENOMEM;
wm8804->regmap = devm_regmap_init_i2c(i2c, &wm8804_regmap_config);
if (IS_ERR(wm8804->regmap)) {
ret = PTR_ERR(wm8804->regmap);
return ret;
}
i2c_set_clientdata(i2c, wm8804);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8804, &wm8804_dai, 1);
return ret;
}
static int wm8804_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static int __init wm8804_modinit(void)
{
int ret = 0;
#if IS_ENABLED(CONFIG_I2C)
ret = i2c_add_driver(&wm8804_i2c_driver);
if (ret) {
printk(KERN_ERR "Failed to register wm8804 I2C driver: %d\n",
ret);
}
#endif
#if defined(CONFIG_SPI_MASTER)
ret = spi_register_driver(&wm8804_spi_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8804 SPI driver: %d\n",
ret);
}
#endif
return ret;
}
static void __exit wm8804_exit(void)
{
#if IS_ENABLED(CONFIG_I2C)
i2c_del_driver(&wm8804_i2c_driver);
#endif
#if defined(CONFIG_SPI_MASTER)
spi_unregister_driver(&wm8804_spi_driver);
#endif
}
