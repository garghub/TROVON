static bool rt298_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0 ... 0xff:
case RT298_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID):
case RT298_GET_HP_SENSE:
case RT298_GET_MIC1_SENSE:
case RT298_PROC_COEF:
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT298_MIC1, 0):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT298_SPK_OUT, 0):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT298_HP_OUT, 0):
return true;
default:
return true;
}
}
static bool rt298_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0 ... 0xff:
case RT298_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID):
case RT298_GET_HP_SENSE:
case RT298_GET_MIC1_SENSE:
case RT298_SET_AUDIO_POWER:
case RT298_SET_HPO_POWER:
case RT298_SET_SPK_POWER:
case RT298_SET_DMIC1_POWER:
case RT298_SPK_MUX:
case RT298_HPO_MUX:
case RT298_ADC0_MUX:
case RT298_ADC1_MUX:
case RT298_SET_MIC1:
case RT298_SET_PIN_HPO:
case RT298_SET_PIN_SPK:
case RT298_SET_PIN_DMIC1:
case RT298_SPK_EAPD:
case RT298_SET_AMP_GAIN_HPO:
case RT298_SET_DMIC2_DEFAULT:
case RT298_DACL_GAIN:
case RT298_DACR_GAIN:
case RT298_ADCL_GAIN:
case RT298_ADCR_GAIN:
case RT298_MIC_GAIN:
case RT298_SPOL_GAIN:
case RT298_SPOR_GAIN:
case RT298_HPOL_GAIN:
case RT298_HPOR_GAIN:
case RT298_F_DAC_SWITCH:
case RT298_F_RECMIX_SWITCH:
case RT298_REC_MIC_SWITCH:
case RT298_REC_I2S_SWITCH:
case RT298_REC_LINE_SWITCH:
case RT298_REC_BEEP_SWITCH:
case RT298_DAC_FORMAT:
case RT298_ADC_FORMAT:
case RT298_COEF_INDEX:
case RT298_PROC_COEF:
case RT298_SET_AMP_GAIN_ADC_IN1:
case RT298_SET_AMP_GAIN_ADC_IN2:
case RT298_SET_POWER(RT298_DAC_OUT1):
case RT298_SET_POWER(RT298_DAC_OUT2):
case RT298_SET_POWER(RT298_ADC_IN1):
case RT298_SET_POWER(RT298_ADC_IN2):
case RT298_SET_POWER(RT298_DMIC2):
case RT298_SET_POWER(RT298_MIC1):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT298_MIC1, 0):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT298_SPK_OUT, 0):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT298_HP_OUT, 0):
return true;
default:
return false;
}
}
static void rt298_index_sync(struct snd_soc_codec *codec)
{
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 0; i < INDEX_CACHE_SIZE; i++) {
snd_soc_write(codec, rt298->index_cache[i].reg,
rt298->index_cache[i].def);
}
}
static int rt298_jack_detect(struct rt298_priv *rt298, bool *hp, bool *mic)
{
struct snd_soc_dapm_context *dapm;
unsigned int val, buf;
*hp = false;
*mic = false;
if (!rt298->codec)
return -EINVAL;
dapm = snd_soc_codec_get_dapm(rt298->codec);
if (rt298->pdata.cbj_en) {
regmap_read(rt298->regmap, RT298_GET_HP_SENSE, &buf);
*hp = buf & 0x80000000;
if (*hp == rt298->is_hp_in)
return -1;
rt298->is_hp_in = *hp;
if (*hp) {
regmap_update_bits(rt298->regmap,
RT298_DC_GAIN, 0x200, 0x200);
snd_soc_dapm_force_enable_pin(dapm, "HV");
snd_soc_dapm_force_enable_pin(dapm, "VREF");
snd_soc_dapm_force_enable_pin(dapm, "LDO1");
snd_soc_dapm_sync(dapm);
regmap_write(rt298->regmap, RT298_SET_MIC1, 0x24);
msleep(50);
regmap_update_bits(rt298->regmap,
RT298_CBJ_CTRL1, 0xfcc0, 0xd400);
msleep(300);
regmap_read(rt298->regmap, RT298_CBJ_CTRL2, &val);
if (0x0070 == (val & 0x0070)) {
*mic = true;
} else {
regmap_update_bits(rt298->regmap,
RT298_CBJ_CTRL1, 0xfcc0, 0xe400);
msleep(300);
regmap_read(rt298->regmap,
RT298_CBJ_CTRL2, &val);
if (0x0070 == (val & 0x0070))
*mic = true;
else
*mic = false;
}
regmap_update_bits(rt298->regmap,
RT298_DC_GAIN, 0x200, 0x0);
} else {
*mic = false;
regmap_write(rt298->regmap, RT298_SET_MIC1, 0x20);
}
} else {
regmap_read(rt298->regmap, RT298_GET_HP_SENSE, &buf);
*hp = buf & 0x80000000;
regmap_read(rt298->regmap, RT298_GET_MIC1_SENSE, &buf);
*mic = buf & 0x80000000;
}
snd_soc_dapm_disable_pin(dapm, "HV");
snd_soc_dapm_disable_pin(dapm, "VREF");
if (!*hp)
snd_soc_dapm_disable_pin(dapm, "LDO1");
snd_soc_dapm_sync(dapm);
pr_debug("*hp = %d *mic = %d\n", *hp, *mic);
return 0;
}
static void rt298_jack_detect_work(struct work_struct *work)
{
struct rt298_priv *rt298 =
container_of(work, struct rt298_priv, jack_detect_work.work);
int status = 0;
bool hp = false;
bool mic = false;
if (rt298_jack_detect(rt298, &hp, &mic) < 0)
return;
if (hp == true)
status |= SND_JACK_HEADPHONE;
if (mic == true)
status |= SND_JACK_MICROPHONE;
snd_soc_jack_report(rt298->jack, status,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
}
int rt298_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack)
{
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
rt298->jack = jack;
snd_soc_jack_report(rt298->jack, 0,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
return 0;
}
static int is_mclk_mode(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
if (rt298->clk_id == RT298_SCLK_S_MCLK)
return 1;
else
return 0;
}
static int rt298_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_write(codec,
RT298_SPK_EAPD, RT298_SET_EAPD_HIGH);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_write(codec,
RT298_SPK_EAPD, RT298_SET_EAPD_LOW);
break;
default:
return 0;
}
return 0;
}
static int rt298_set_dmic1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_write(codec, RT298_SET_PIN_DMIC1, 0x20);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_write(codec, RT298_SET_PIN_DMIC1, 0);
break;
default:
return 0;
}
return 0;
}
static int rt298_adc_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int nid;
nid = (w->reg >> 20) & 0xff;
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec,
VERB_CMD(AC_VERB_SET_AMP_GAIN_MUTE, nid, 0),
0x7080, 0x7000);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec,
VERB_CMD(AC_VERB_SET_AMP_GAIN_MUTE, nid, 0),
0x7080, 0x7080);
break;
default:
return 0;
}
return 0;
}
static int rt298_mic1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec,
RT298_A_BIAS_CTRL3, 0xc000, 0x8000);
snd_soc_update_bits(codec,
RT298_A_BIAS_CTRL2, 0xc000, 0x8000);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec,
RT298_A_BIAS_CTRL3, 0xc000, 0x0000);
snd_soc_update_bits(codec,
RT298_A_BIAS_CTRL2, 0xc000, 0x0000);
break;
default:
return 0;
}
return 0;
}
static int rt298_vref_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec,
RT298_CBJ_CTRL1, 0x0400, 0x0000);
mdelay(50);
break;
default:
return 0;
}
return 0;
}
static int rt298_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0;
int d_len_code;
switch (params_rate(params)) {
case 44100:
case 48000:
break;
default:
dev_err(codec->dev, "Unsupported sample rate %d\n",
params_rate(params));
return -EINVAL;
}
switch (rt298->sys_clk) {
case 12288000:
case 24576000:
if (params_rate(params) != 48000) {
dev_err(codec->dev, "Sys_clk is not matched (%d %d)\n",
params_rate(params), rt298->sys_clk);
return -EINVAL;
}
break;
case 11289600:
case 22579200:
if (params_rate(params) != 44100) {
dev_err(codec->dev, "Sys_clk is not matched (%d %d)\n",
params_rate(params), rt298->sys_clk);
return -EINVAL;
}
break;
}
if (params_channels(params) <= 16) {
val |= (params_channels(params) - 1);
} else {
dev_err(codec->dev, "Unsupported channels %d\n",
params_channels(params));
return -EINVAL;
}
d_len_code = 0;
switch (params_width(params)) {
case 16:
d_len_code = 0;
val |= (0x1 << 4);
break;
case 32:
d_len_code = 2;
val |= (0x4 << 4);
break;
case 20:
d_len_code = 1;
val |= (0x2 << 4);
break;
case 24:
d_len_code = 2;
val |= (0x3 << 4);
break;
case 8:
d_len_code = 3;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x0018, d_len_code << 3);
dev_dbg(codec->dev, "format val = 0x%x\n", val);
snd_soc_update_bits(codec, RT298_DAC_FORMAT, 0x407f, val);
snd_soc_update_bits(codec, RT298_ADC_FORMAT, 0x407f, val);
return 0;
}
static int rt298_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x800, 0x800);
break;
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x800, 0x0);
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x300, 0x0);
break;
case SND_SOC_DAIFMT_LEFT_J:
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x300, 0x1 << 8);
break;
case SND_SOC_DAIFMT_DSP_A:
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x300, 0x2 << 8);
break;
case SND_SOC_DAIFMT_DSP_B:
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x300, 0x3 << 8);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT298_DAC_FORMAT, 0x8000, 0);
snd_soc_update_bits(codec, RT298_ADC_FORMAT, 0x8000, 0);
return 0;
}
static int rt298_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "%s freq=%d\n", __func__, freq);
if (RT298_SCLK_S_MCLK == clk_id) {
snd_soc_update_bits(codec,
RT298_I2S_CTRL2, 0x0100, 0x0);
snd_soc_update_bits(codec,
RT298_PLL_CTRL1, 0x20, 0x20);
} else {
snd_soc_update_bits(codec,
RT298_I2S_CTRL2, 0x0100, 0x0100);
snd_soc_update_bits(codec,
RT298_PLL_CTRL, 0x4, 0x4);
snd_soc_update_bits(codec,
RT298_PLL_CTRL1, 0x20, 0x0);
}
switch (freq) {
case 19200000:
if (RT298_SCLK_S_MCLK == clk_id) {
dev_err(codec->dev, "Should not use MCLK\n");
return -EINVAL;
}
snd_soc_update_bits(codec,
RT298_I2S_CTRL2, 0x40, 0x40);
break;
case 24000000:
if (RT298_SCLK_S_MCLK == clk_id) {
dev_err(codec->dev, "Should not use MCLK\n");
return -EINVAL;
}
snd_soc_update_bits(codec,
RT298_I2S_CTRL2, 0x40, 0x0);
break;
case 12288000:
case 11289600:
snd_soc_update_bits(codec,
RT298_I2S_CTRL2, 0x8, 0x0);
snd_soc_update_bits(codec,
RT298_CLK_DIV, 0xfc1e, 0x0004);
break;
case 24576000:
case 22579200:
snd_soc_update_bits(codec,
RT298_I2S_CTRL2, 0x8, 0x8);
snd_soc_update_bits(codec,
RT298_CLK_DIV, 0xfc1e, 0x5406);
break;
default:
dev_err(codec->dev, "Unsupported system clock\n");
return -EINVAL;
}
rt298->sys_clk = freq;
rt298->clk_id = clk_id;
return 0;
}
static int rt298_set_bclk_ratio(struct snd_soc_dai *dai, unsigned int ratio)
{
struct snd_soc_codec *codec = dai->codec;
dev_dbg(codec->dev, "%s ratio=%d\n", __func__, ratio);
if (50 == ratio)
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x1000, 0x1000);
else
snd_soc_update_bits(codec,
RT298_I2S_CTRL1, 0x1000, 0x0);
return 0;
}
static int rt298_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (SND_SOC_BIAS_STANDBY ==
snd_soc_codec_get_bias_level(codec)) {
snd_soc_write(codec,
RT298_SET_AUDIO_POWER, AC_PWRST_D0);
snd_soc_update_bits(codec, 0x0d, 0x200, 0x200);
snd_soc_update_bits(codec, 0x52, 0x80, 0x0);
mdelay(20);
snd_soc_update_bits(codec, 0x0d, 0x200, 0x0);
snd_soc_update_bits(codec, 0x52, 0x80, 0x80);
}
break;
case SND_SOC_BIAS_ON:
mdelay(30);
snd_soc_update_bits(codec,
RT298_CBJ_CTRL1, 0x0400, 0x0400);
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec,
RT298_SET_AUDIO_POWER, AC_PWRST_D3);
snd_soc_update_bits(codec,
RT298_CBJ_CTRL1, 0x0400, 0x0000);
break;
default:
break;
}
return 0;
}
static irqreturn_t rt298_irq(int irq, void *data)
{
struct rt298_priv *rt298 = data;
bool hp = false;
bool mic = false;
int ret, status = 0;
ret = rt298_jack_detect(rt298, &hp, &mic);
regmap_update_bits(rt298->regmap, RT298_IRQ_CTRL, 0x1, 0x1);
if (ret == 0) {
if (hp == true)
status |= SND_JACK_HEADPHONE;
if (mic == true)
status |= SND_JACK_MICROPHONE;
snd_soc_jack_report(rt298->jack, status,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
pm_wakeup_event(&rt298->i2c->dev, 300);
}
return IRQ_HANDLED;
}
static int rt298_probe(struct snd_soc_codec *codec)
{
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
rt298->codec = codec;
if (rt298->i2c->irq) {
regmap_update_bits(rt298->regmap,
RT298_IRQ_CTRL, 0x2, 0x2);
INIT_DELAYED_WORK(&rt298->jack_detect_work,
rt298_jack_detect_work);
schedule_delayed_work(&rt298->jack_detect_work,
msecs_to_jiffies(1250));
}
return 0;
}
static int rt298_remove(struct snd_soc_codec *codec)
{
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
cancel_delayed_work_sync(&rt298->jack_detect_work);
return 0;
}
static int rt298_suspend(struct snd_soc_codec *codec)
{
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
rt298->is_hp_in = -1;
regcache_cache_only(rt298->regmap, true);
regcache_mark_dirty(rt298->regmap);
return 0;
}
static int rt298_resume(struct snd_soc_codec *codec)
{
struct rt298_priv *rt298 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt298->regmap, false);
rt298_index_sync(codec);
regcache_sync(rt298->regmap);
return 0;
}
static int rt298_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt298_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt298_priv *rt298;
struct device *dev = &i2c->dev;
const struct acpi_device_id *acpiid;
int i, ret;
rt298 = devm_kzalloc(&i2c->dev, sizeof(*rt298),
GFP_KERNEL);
if (NULL == rt298)
return -ENOMEM;
rt298->regmap = devm_regmap_init(&i2c->dev, NULL, i2c, &rt298_regmap);
if (IS_ERR(rt298->regmap)) {
ret = PTR_ERR(rt298->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt298->regmap,
RT298_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID), &ret);
if (ret != RT298_VENDOR_ID) {
dev_err(&i2c->dev,
"Device with ID register %#x is not rt298\n", ret);
return -ENODEV;
}
rt298->index_cache = rt298_index_def;
rt298->index_cache_size = INDEX_CACHE_SIZE;
rt298->i2c = i2c;
i2c_set_clientdata(i2c, rt298);
for (i = 0; i < INDEX_CACHE_SIZE; i++)
regmap_write(rt298->regmap, rt298->index_cache[i].reg,
rt298->index_cache[i].def);
for (i = 0; i < ARRAY_SIZE(rt298_reg); i++)
regmap_write(rt298->regmap, rt298_reg[i].reg,
rt298_reg[i].def);
if (pdata)
rt298->pdata = *pdata;
acpiid = acpi_match_device(dev->driver->acpi_match_table, dev);
if (acpiid) {
rt298->pdata = *(struct rt298_platform_data *)
acpiid->driver_data;
}
regmap_update_bits(rt298->regmap, 0x04, 0x80, 0x80);
regmap_update_bits(rt298->regmap, 0x1b, 0x860, 0x860);
regmap_update_bits(rt298->regmap, 0x08, 0x20, 0x20);
regmap_write(rt298->regmap, RT298_SET_AUDIO_POWER, AC_PWRST_D3);
for (i = 0; i < RT298_POWER_REG_LEN; i++)
regmap_write(rt298->regmap,
RT298_SET_POWER(rt298_support_power_controls[i]),
AC_PWRST_D1);
if (!rt298->pdata.cbj_en) {
regmap_write(rt298->regmap, RT298_CBJ_CTRL2, 0x0000);
regmap_write(rt298->regmap, RT298_MIC1_DET_CTRL, 0x0816);
regmap_update_bits(rt298->regmap,
RT298_CBJ_CTRL1, 0xf000, 0xb000);
} else {
regmap_update_bits(rt298->regmap,
RT298_CBJ_CTRL1, 0xf000, 0x5000);
}
mdelay(10);
if (!rt298->pdata.gpio2_en)
regmap_write(rt298->regmap, RT298_SET_DMIC2_DEFAULT, 0x40);
else
regmap_write(rt298->regmap, RT298_SET_DMIC2_DEFAULT, 0);
mdelay(10);
regmap_write(rt298->regmap, RT298_MISC_CTRL1, 0x0000);
regmap_update_bits(rt298->regmap,
RT298_WIND_FILTER_CTRL, 0x0082, 0x0082);
regmap_update_bits(rt298->regmap, RT298_IRQ_CTRL, 0x2, 0x2);
rt298->is_hp_in = -1;
if (rt298->i2c->irq) {
ret = request_threaded_irq(rt298->i2c->irq, NULL, rt298_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT, "rt298", rt298);
if (ret != 0) {
dev_err(&i2c->dev,
"Failed to reguest IRQ: %d\n", ret);
return ret;
}
}
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt298,
rt298_dai, ARRAY_SIZE(rt298_dai));
return ret;
}
static int rt298_i2c_remove(struct i2c_client *i2c)
{
struct rt298_priv *rt298 = i2c_get_clientdata(i2c);
if (i2c->irq)
free_irq(i2c->irq, rt298);
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
