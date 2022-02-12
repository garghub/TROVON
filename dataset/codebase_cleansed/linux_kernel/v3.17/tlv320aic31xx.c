static bool aic31xx_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case AIC31XX_PAGECTL:
case AIC31XX_RESET:
case AIC31XX_OT_FLAG:
case AIC31XX_ADCFLAG:
case AIC31XX_DACFLAG1:
case AIC31XX_DACFLAG2:
case AIC31XX_OFFLAG:
case AIC31XX_INTRDACFLAG:
case AIC31XX_INTRADCFLAG:
case AIC31XX_INTRDACFLAG2:
case AIC31XX_INTRADCFLAG2:
return true;
}
return false;
}
static bool aic31xx_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case AIC31XX_OT_FLAG:
case AIC31XX_ADCFLAG:
case AIC31XX_DACFLAG1:
case AIC31XX_DACFLAG2:
case AIC31XX_OFFLAG:
case AIC31XX_INTRDACFLAG:
case AIC31XX_INTRADCFLAG:
case AIC31XX_INTRDACFLAG2:
case AIC31XX_INTRADCFLAG2:
return false;
}
return true;
}
static int aic31xx_wait_bits(struct aic31xx_priv *aic31xx, unsigned int reg,
unsigned int mask, unsigned int wbits, int sleep,
int count)
{
unsigned int bits;
int counter = count;
int ret = regmap_read(aic31xx->regmap, reg, &bits);
while ((bits & mask) != wbits && counter && !ret) {
usleep_range(sleep, sleep * 2);
ret = regmap_read(aic31xx->regmap, reg, &bits);
counter--;
}
if ((bits & mask) != wbits) {
dev_err(aic31xx->dev,
"%s: Failed! 0x%x was 0x%x expected 0x%x (%d, 0x%x, %d us)\n",
__func__, reg, bits, wbits, ret, mask,
(count - counter) * sleep);
ret = -1;
}
return ret;
}
static int aic31xx_dapm_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(w->codec);
unsigned int reg = AIC31XX_DACFLAG1;
unsigned int mask;
switch (WIDGET_BIT(w->reg, w->shift)) {
case WIDGET_BIT(AIC31XX_DACSETUP, 7):
mask = AIC31XX_LDACPWRSTATUS_MASK;
break;
case WIDGET_BIT(AIC31XX_DACSETUP, 6):
mask = AIC31XX_RDACPWRSTATUS_MASK;
break;
case WIDGET_BIT(AIC31XX_HPDRIVER, 7):
mask = AIC31XX_HPLDRVPWRSTATUS_MASK;
break;
case WIDGET_BIT(AIC31XX_HPDRIVER, 6):
mask = AIC31XX_HPRDRVPWRSTATUS_MASK;
break;
case WIDGET_BIT(AIC31XX_SPKAMP, 7):
mask = AIC31XX_SPLDRVPWRSTATUS_MASK;
break;
case WIDGET_BIT(AIC31XX_SPKAMP, 6):
mask = AIC31XX_SPRDRVPWRSTATUS_MASK;
break;
case WIDGET_BIT(AIC31XX_ADCSETUP, 7):
mask = AIC31XX_ADCPWRSTATUS_MASK;
reg = AIC31XX_ADCFLAG;
break;
default:
dev_err(w->codec->dev, "Unknown widget '%s' calling %s\n",
w->name, __func__);
return -EINVAL;
}
switch (event) {
case SND_SOC_DAPM_POST_PMU:
return aic31xx_wait_bits(aic31xx, reg, mask, mask, 5000, 100);
case SND_SOC_DAPM_POST_PMD:
return aic31xx_wait_bits(aic31xx, reg, mask, 0, 5000, 100);
default:
dev_dbg(w->codec->dev,
"Unhandled dapm widget event %d from %s\n",
event, w->name);
}
return 0;
}
static int mic_bias_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, AIC31XX_MICBIAS,
AIC31XX_MICBIAS_MASK,
aic31xx->pdata.micbias_vg <<
AIC31XX_MICBIAS_SHIFT);
dev_dbg(codec->dev, "%s: turned on\n", __func__);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, AIC31XX_MICBIAS,
AIC31XX_MICBIAS_MASK, 0);
dev_dbg(codec->dev, "%s: turned off\n", __func__);
break;
}
return 0;
}
static int aic31xx_add_controls(struct snd_soc_codec *codec)
{
int ret = 0;
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
if (aic31xx->pdata.codec_type & AIC31XX_STEREO_CLASS_D_BIT)
ret = snd_soc_add_codec_controls(
codec, aic311x_snd_controls,
ARRAY_SIZE(aic311x_snd_controls));
else
ret = snd_soc_add_codec_controls(
codec, aic310x_snd_controls,
ARRAY_SIZE(aic310x_snd_controls));
return ret;
}
static int aic31xx_add_widgets(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
int ret = 0;
if (aic31xx->pdata.codec_type & AIC31XX_STEREO_CLASS_D_BIT) {
ret = snd_soc_dapm_new_controls(
dapm, aic311x_dapm_widgets,
ARRAY_SIZE(aic311x_dapm_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(dapm, aic311x_audio_map,
ARRAY_SIZE(aic311x_audio_map));
if (ret)
return ret;
} else {
ret = snd_soc_dapm_new_controls(
dapm, aic310x_dapm_widgets,
ARRAY_SIZE(aic310x_dapm_widgets));
if (ret)
return ret;
ret = snd_soc_dapm_add_routes(dapm, aic310x_audio_map,
ARRAY_SIZE(aic310x_audio_map));
if (ret)
return ret;
}
return 0;
}
static int aic31xx_setup_pll(struct snd_soc_codec *codec,
struct snd_pcm_hw_params *params)
{
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
int bclk_score = snd_soc_params_to_frame_size(params);
int bclk_n = 0;
int match = -1;
int i;
snd_soc_update_bits(codec, AIC31XX_CLKMUX,
AIC31XX_CODEC_CLKIN_MASK, AIC31XX_CODEC_CLKIN_PLL);
snd_soc_update_bits(codec, AIC31XX_IFACE2,
AIC31XX_BDIVCLK_MASK, AIC31XX_DAC2BCLK);
for (i = 0; i < ARRAY_SIZE(aic31xx_divs); i++) {
if (aic31xx_divs[i].rate == params_rate(params) &&
aic31xx_divs[i].mclk == aic31xx->sysclk) {
int s = (aic31xx_divs[i].dosr * aic31xx_divs[i].mdac) %
snd_soc_params_to_frame_size(params);
int bn = (aic31xx_divs[i].dosr * aic31xx_divs[i].mdac) /
snd_soc_params_to_frame_size(params);
if (s < bclk_score && bn > 0) {
match = i;
bclk_n = bn;
bclk_score = s;
}
}
}
if (match == -1) {
dev_err(codec->dev,
"%s: Sample rate (%u) and format not supported\n",
__func__, params_rate(params));
return -EINVAL;
}
if (bclk_score != 0) {
dev_warn(codec->dev, "Can not produce exact bitclock");
}
i = match;
snd_soc_update_bits(codec, AIC31XX_PLLPR, AIC31XX_PLL_MASK,
(aic31xx_divs[i].p_val << 4) | 0x01);
snd_soc_write(codec, AIC31XX_PLLJ, aic31xx_divs[i].pll_j);
snd_soc_write(codec, AIC31XX_PLLDMSB,
aic31xx_divs[i].pll_d >> 8);
snd_soc_write(codec, AIC31XX_PLLDLSB,
aic31xx_divs[i].pll_d & 0xff);
snd_soc_update_bits(codec, AIC31XX_NDAC, AIC31XX_PLL_MASK,
aic31xx_divs[i].ndac);
snd_soc_update_bits(codec, AIC31XX_MDAC, AIC31XX_PLL_MASK,
aic31xx_divs[i].mdac);
snd_soc_write(codec, AIC31XX_DOSRMSB, aic31xx_divs[i].dosr >> 8);
snd_soc_write(codec, AIC31XX_DOSRLSB, aic31xx_divs[i].dosr & 0xff);
snd_soc_update_bits(codec, AIC31XX_NADC, AIC31XX_PLL_MASK,
aic31xx_divs[i].nadc ? aic31xx_divs[i].nadc : 1);
snd_soc_update_bits(codec, AIC31XX_MADC, AIC31XX_PLL_MASK,
aic31xx_divs[i].madc ? aic31xx_divs[i].madc : 1);
snd_soc_write(codec, AIC31XX_AOSR, aic31xx_divs[i].aosr);
snd_soc_update_bits(codec, AIC31XX_BCLKN,
AIC31XX_PLL_MASK, bclk_n);
aic31xx->rate_div_line = i;
dev_dbg(codec->dev,
"pll %d.%04d/%d dosr %d n %d m %d aosr %d n %d m %d bclk_n %d\n",
aic31xx_divs[i].pll_j, aic31xx_divs[i].pll_d,
aic31xx_divs[i].p_val, aic31xx_divs[i].dosr,
aic31xx_divs[i].ndac, aic31xx_divs[i].mdac,
aic31xx_divs[i].aosr, aic31xx_divs[i].nadc,
aic31xx_divs[i].madc, bclk_n);
return 0;
}
static int aic31xx_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u8 data = 0;
dev_dbg(codec->dev, "## %s: width %d rate %d\n",
__func__, params_width(params),
params_rate(params));
switch (params_width(params)) {
case 16:
break;
case 20:
data = (AIC31XX_WORD_LEN_20BITS <<
AIC31XX_IFACE1_DATALEN_SHIFT);
break;
case 24:
data = (AIC31XX_WORD_LEN_24BITS <<
AIC31XX_IFACE1_DATALEN_SHIFT);
break;
case 32:
data = (AIC31XX_WORD_LEN_32BITS <<
AIC31XX_IFACE1_DATALEN_SHIFT);
break;
default:
dev_err(codec->dev, "%s: Unsupported width %d\n",
__func__, params_width(params));
return -EINVAL;
}
snd_soc_update_bits(codec, AIC31XX_IFACE1,
AIC31XX_IFACE1_DATALEN_MASK,
data);
return aic31xx_setup_pll(codec, params);
}
static int aic31xx_dac_mute(struct snd_soc_dai *codec_dai, int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
if (mute) {
snd_soc_update_bits(codec, AIC31XX_DACMUTE,
AIC31XX_DACMUTE_MASK,
AIC31XX_DACMUTE_MASK);
} else {
snd_soc_update_bits(codec, AIC31XX_DACMUTE,
AIC31XX_DACMUTE_MASK, 0x0);
}
return 0;
}
static int aic31xx_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
u8 iface_reg1 = 0;
u8 iface_reg3 = 0;
u8 dsp_a_val = 0;
dev_dbg(codec->dev, "## %s: fmt = 0x%x\n", __func__, fmt);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
iface_reg1 |= AIC31XX_BCLK_MASTER | AIC31XX_WCLK_MASTER;
break;
default:
dev_alert(codec->dev, "Invalid DAI master/slave interface\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_DSP_A:
dsp_a_val = 0x1;
case SND_SOC_DAIFMT_DSP_B:
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
iface_reg3 |= AIC31XX_BCLKINV_MASK;
break;
case SND_SOC_DAIFMT_IB_NF:
break;
default:
return -EINVAL;
}
iface_reg1 |= (AIC31XX_DSP_MODE <<
AIC31XX_IFACE1_DATATYPE_SHIFT);
break;
case SND_SOC_DAIFMT_RIGHT_J:
iface_reg1 |= (AIC31XX_RIGHT_JUSTIFIED_MODE <<
AIC31XX_IFACE1_DATATYPE_SHIFT);
break;
case SND_SOC_DAIFMT_LEFT_J:
iface_reg1 |= (AIC31XX_LEFT_JUSTIFIED_MODE <<
AIC31XX_IFACE1_DATATYPE_SHIFT);
break;
default:
dev_err(codec->dev, "Invalid DAI interface format\n");
return -EINVAL;
}
snd_soc_update_bits(codec, AIC31XX_IFACE1,
AIC31XX_IFACE1_DATATYPE_MASK |
AIC31XX_IFACE1_MASTER_MASK,
iface_reg1);
snd_soc_update_bits(codec, AIC31XX_DATA_OFFSET,
AIC31XX_DATA_OFFSET_MASK,
dsp_a_val);
snd_soc_update_bits(codec, AIC31XX_IFACE2,
AIC31XX_BCLKINV_MASK,
iface_reg3);
return 0;
}
static int aic31xx_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
int i;
dev_dbg(codec->dev, "## %s: clk_id = %d, freq = %d, dir = %d\n",
__func__, clk_id, freq, dir);
for (i = 0; aic31xx_divs[i].mclk != freq; i++) {
if (i == ARRAY_SIZE(aic31xx_divs)) {
dev_err(aic31xx->dev, "%s: Unsupported frequency %d\n",
__func__, freq);
return -EINVAL;
}
}
snd_soc_update_bits(codec, AIC31XX_CLKMUX, AIC31XX_PLL_CLKIN_MASK,
clk_id << AIC31XX_PLL_CLKIN_SHIFT);
aic31xx->sysclk = freq;
return 0;
}
static int aic31xx_regulator_event(struct notifier_block *nb,
unsigned long event, void *data)
{
struct aic31xx_disable_nb *disable_nb =
container_of(nb, struct aic31xx_disable_nb, nb);
struct aic31xx_priv *aic31xx = disable_nb->aic31xx;
if (event & REGULATOR_EVENT_DISABLE) {
if (gpio_is_valid(aic31xx->pdata.gpio_reset))
gpio_set_value(aic31xx->pdata.gpio_reset, 0);
regcache_mark_dirty(aic31xx->regmap);
dev_dbg(aic31xx->dev, "## %s: DISABLE received\n", __func__);
}
return 0;
}
static void aic31xx_clk_on(struct snd_soc_codec *codec)
{
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
u8 mask = AIC31XX_PM_MASK;
u8 on = AIC31XX_PM_MASK;
dev_dbg(codec->dev, "codec clock -> on (rate %d)\n",
aic31xx_divs[aic31xx->rate_div_line].rate);
snd_soc_update_bits(codec, AIC31XX_PLLPR, mask, on);
mdelay(10);
snd_soc_update_bits(codec, AIC31XX_NDAC, mask, on);
snd_soc_update_bits(codec, AIC31XX_MDAC, mask, on);
if (aic31xx_divs[aic31xx->rate_div_line].nadc)
snd_soc_update_bits(codec, AIC31XX_NADC, mask, on);
if (aic31xx_divs[aic31xx->rate_div_line].madc)
snd_soc_update_bits(codec, AIC31XX_MADC, mask, on);
snd_soc_update_bits(codec, AIC31XX_BCLKN, mask, on);
}
static void aic31xx_clk_off(struct snd_soc_codec *codec)
{
u8 mask = AIC31XX_PM_MASK;
u8 off = 0;
dev_dbg(codec->dev, "codec clock -> off\n");
snd_soc_update_bits(codec, AIC31XX_BCLKN, mask, off);
snd_soc_update_bits(codec, AIC31XX_MADC, mask, off);
snd_soc_update_bits(codec, AIC31XX_NADC, mask, off);
snd_soc_update_bits(codec, AIC31XX_MDAC, mask, off);
snd_soc_update_bits(codec, AIC31XX_NDAC, mask, off);
snd_soc_update_bits(codec, AIC31XX_PLLPR, mask, off);
}
static int aic31xx_power_on(struct snd_soc_codec *codec)
{
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
int ret = 0;
ret = regulator_bulk_enable(ARRAY_SIZE(aic31xx->supplies),
aic31xx->supplies);
if (ret)
return ret;
if (gpio_is_valid(aic31xx->pdata.gpio_reset)) {
gpio_set_value(aic31xx->pdata.gpio_reset, 1);
udelay(100);
}
regcache_cache_only(aic31xx->regmap, false);
ret = regcache_sync(aic31xx->regmap);
if (ret != 0) {
dev_err(codec->dev,
"Failed to restore cache: %d\n", ret);
regcache_cache_only(aic31xx->regmap, true);
regulator_bulk_disable(ARRAY_SIZE(aic31xx->supplies),
aic31xx->supplies);
return ret;
}
return 0;
}
static int aic31xx_power_off(struct snd_soc_codec *codec)
{
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
int ret = 0;
regcache_cache_only(aic31xx->regmap, true);
ret = regulator_bulk_disable(ARRAY_SIZE(aic31xx->supplies),
aic31xx->supplies);
return ret;
}
static int aic31xx_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
dev_dbg(codec->dev, "## %s: %d -> %d\n", __func__,
codec->dapm.bias_level, level);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY)
aic31xx_clk_on(codec);
break;
case SND_SOC_BIAS_STANDBY:
switch (codec->dapm.bias_level) {
case SND_SOC_BIAS_OFF:
aic31xx_power_on(codec);
break;
case SND_SOC_BIAS_PREPARE:
aic31xx_clk_off(codec);
break;
default:
BUG();
}
break;
case SND_SOC_BIAS_OFF:
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY)
aic31xx_power_off(codec);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int aic31xx_suspend(struct snd_soc_codec *codec)
{
aic31xx_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int aic31xx_resume(struct snd_soc_codec *codec)
{
aic31xx_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int aic31xx_codec_probe(struct snd_soc_codec *codec)
{
int ret = 0;
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
int i;
dev_dbg(aic31xx->dev, "## %s\n", __func__);
aic31xx = snd_soc_codec_get_drvdata(codec);
aic31xx->codec = codec;
for (i = 0; i < ARRAY_SIZE(aic31xx->supplies); i++) {
aic31xx->disable_nb[i].nb.notifier_call =
aic31xx_regulator_event;
aic31xx->disable_nb[i].aic31xx = aic31xx;
ret = regulator_register_notifier(aic31xx->supplies[i].consumer,
&aic31xx->disable_nb[i].nb);
if (ret) {
dev_err(codec->dev,
"Failed to request regulator notifier: %d\n",
ret);
return ret;
}
}
regcache_cache_only(aic31xx->regmap, true);
regcache_mark_dirty(aic31xx->regmap);
ret = aic31xx_add_controls(codec);
if (ret)
return ret;
ret = aic31xx_add_widgets(codec);
return ret;
}
static int aic31xx_codec_remove(struct snd_soc_codec *codec)
{
struct aic31xx_priv *aic31xx = snd_soc_codec_get_drvdata(codec);
int i;
aic31xx_set_bias_level(codec, SND_SOC_BIAS_OFF);
for (i = 0; i < ARRAY_SIZE(aic31xx->supplies); i++)
regulator_unregister_notifier(aic31xx->supplies[i].consumer,
&aic31xx->disable_nb[i].nb);
return 0;
}
static void aic31xx_pdata_from_of(struct aic31xx_priv *aic31xx)
{
struct device_node *np = aic31xx->dev->of_node;
unsigned int value = MICBIAS_2_0V;
int ret;
of_property_read_u32(np, "ai31xx-micbias-vg", &value);
switch (value) {
case MICBIAS_2_0V:
case MICBIAS_2_5V:
case MICBIAS_AVDDV:
aic31xx->pdata.micbias_vg = value;
break;
default:
dev_err(aic31xx->dev,
"Bad ai31xx-micbias-vg value %d DT\n",
value);
aic31xx->pdata.micbias_vg = MICBIAS_2_0V;
}
ret = of_get_named_gpio(np, "gpio-reset", 0);
if (ret > 0)
aic31xx->pdata.gpio_reset = ret;
}
static void aic31xx_pdata_from_of(struct aic31xx_priv *aic31xx)
{
}
static int aic31xx_device_init(struct aic31xx_priv *aic31xx)
{
int ret, i;
dev_set_drvdata(aic31xx->dev, aic31xx);
if (dev_get_platdata(aic31xx->dev))
memcpy(&aic31xx->pdata, dev_get_platdata(aic31xx->dev),
sizeof(aic31xx->pdata));
else if (aic31xx->dev->of_node)
aic31xx_pdata_from_of(aic31xx);
if (aic31xx->pdata.gpio_reset) {
ret = devm_gpio_request_one(aic31xx->dev,
aic31xx->pdata.gpio_reset,
GPIOF_OUT_INIT_HIGH,
"aic31xx-reset-pin");
if (ret < 0) {
dev_err(aic31xx->dev, "not able to acquire gpio\n");
return ret;
}
}
for (i = 0; i < ARRAY_SIZE(aic31xx->supplies); i++)
aic31xx->supplies[i].supply = aic31xx_supply_names[i];
ret = devm_regulator_bulk_get(aic31xx->dev,
ARRAY_SIZE(aic31xx->supplies),
aic31xx->supplies);
if (ret != 0)
dev_err(aic31xx->dev, "Failed to request supplies: %d\n", ret);
return ret;
}
static int aic31xx_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct aic31xx_priv *aic31xx;
int ret;
const struct regmap_config *regmap_config;
dev_dbg(&i2c->dev, "## %s: %s codec_type = %d\n", __func__,
id->name, (int) id->driver_data);
regmap_config = &aic31xx_i2c_regmap;
aic31xx = devm_kzalloc(&i2c->dev, sizeof(*aic31xx), GFP_KERNEL);
if (aic31xx == NULL)
return -ENOMEM;
aic31xx->regmap = devm_regmap_init_i2c(i2c, regmap_config);
if (IS_ERR(aic31xx->regmap)) {
ret = PTR_ERR(aic31xx->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
aic31xx->dev = &i2c->dev;
aic31xx->pdata.codec_type = id->driver_data;
ret = aic31xx_device_init(aic31xx);
if (ret)
return ret;
return snd_soc_register_codec(&i2c->dev, &soc_codec_driver_aic31xx,
aic31xx_dai_driver,
ARRAY_SIZE(aic31xx_dai_driver));
}
static int aic31xx_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
