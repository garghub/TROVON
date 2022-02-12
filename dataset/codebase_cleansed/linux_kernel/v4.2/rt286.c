static bool rt286_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0 ... 0xff:
case RT286_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID):
case RT286_GET_HP_SENSE:
case RT286_GET_MIC1_SENSE:
case RT286_PROC_COEF:
return true;
default:
return false;
}
}
static bool rt286_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0 ... 0xff:
case RT286_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID):
case RT286_GET_HP_SENSE:
case RT286_GET_MIC1_SENSE:
case RT286_SET_AUDIO_POWER:
case RT286_SET_HPO_POWER:
case RT286_SET_SPK_POWER:
case RT286_SET_DMIC1_POWER:
case RT286_SPK_MUX:
case RT286_HPO_MUX:
case RT286_ADC0_MUX:
case RT286_ADC1_MUX:
case RT286_SET_MIC1:
case RT286_SET_PIN_HPO:
case RT286_SET_PIN_SPK:
case RT286_SET_PIN_DMIC1:
case RT286_SPK_EAPD:
case RT286_SET_AMP_GAIN_HPO:
case RT286_SET_DMIC2_DEFAULT:
case RT286_DACL_GAIN:
case RT286_DACR_GAIN:
case RT286_ADCL_GAIN:
case RT286_ADCR_GAIN:
case RT286_MIC_GAIN:
case RT286_SPOL_GAIN:
case RT286_SPOR_GAIN:
case RT286_HPOL_GAIN:
case RT286_HPOR_GAIN:
case RT286_F_DAC_SWITCH:
case RT286_F_RECMIX_SWITCH:
case RT286_REC_MIC_SWITCH:
case RT286_REC_I2S_SWITCH:
case RT286_REC_LINE_SWITCH:
case RT286_REC_BEEP_SWITCH:
case RT286_DAC_FORMAT:
case RT286_ADC_FORMAT:
case RT286_COEF_INDEX:
case RT286_PROC_COEF:
case RT286_SET_AMP_GAIN_ADC_IN1:
case RT286_SET_AMP_GAIN_ADC_IN2:
case RT286_SET_POWER(RT286_DAC_OUT1):
case RT286_SET_POWER(RT286_DAC_OUT2):
case RT286_SET_POWER(RT286_ADC_IN1):
case RT286_SET_POWER(RT286_ADC_IN2):
case RT286_SET_POWER(RT286_DMIC2):
case RT286_SET_POWER(RT286_MIC1):
return true;
default:
return false;
}
}
static void rt286_index_sync(struct snd_soc_codec *codec)
{
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 0; i < INDEX_CACHE_SIZE; i++) {
snd_soc_write(codec, rt286->index_cache[i].reg,
rt286->index_cache[i].def);
}
}
static int rt286_jack_detect(struct rt286_priv *rt286, bool *hp, bool *mic)
{
struct snd_soc_dapm_context *dapm;
unsigned int val, buf;
*hp = false;
*mic = false;
if (!rt286->codec)
return -EINVAL;
dapm = snd_soc_codec_get_dapm(rt286->codec);
if (rt286->pdata.cbj_en) {
regmap_read(rt286->regmap, RT286_GET_HP_SENSE, &buf);
*hp = buf & 0x80000000;
if (*hp) {
regmap_update_bits(rt286->regmap,
RT286_DC_GAIN, 0x200, 0x200);
snd_soc_dapm_force_enable_pin(dapm, "HV");
snd_soc_dapm_force_enable_pin(dapm, "VREF");
snd_soc_dapm_force_enable_pin(dapm, "LDO1");
snd_soc_dapm_sync(dapm);
regmap_write(rt286->regmap, RT286_SET_MIC1, 0x24);
msleep(50);
regmap_update_bits(rt286->regmap,
RT286_CBJ_CTRL1, 0xfcc0, 0xd400);
msleep(300);
regmap_read(rt286->regmap, RT286_CBJ_CTRL2, &val);
if (0x0070 == (val & 0x0070)) {
*mic = true;
} else {
regmap_update_bits(rt286->regmap,
RT286_CBJ_CTRL1, 0xfcc0, 0xe400);
msleep(300);
regmap_read(rt286->regmap,
RT286_CBJ_CTRL2, &val);
if (0x0070 == (val & 0x0070))
*mic = true;
else
*mic = false;
}
regmap_update_bits(rt286->regmap,
RT286_DC_GAIN, 0x200, 0x0);
} else {
*mic = false;
regmap_write(rt286->regmap, RT286_SET_MIC1, 0x20);
}
} else {
regmap_read(rt286->regmap, RT286_GET_HP_SENSE, &buf);
*hp = buf & 0x80000000;
regmap_read(rt286->regmap, RT286_GET_MIC1_SENSE, &buf);
*mic = buf & 0x80000000;
}
snd_soc_dapm_disable_pin(dapm, "HV");
snd_soc_dapm_disable_pin(dapm, "VREF");
if (!*hp)
snd_soc_dapm_disable_pin(dapm, "LDO1");
snd_soc_dapm_sync(dapm);
return 0;
}
static void rt286_jack_detect_work(struct work_struct *work)
{
struct rt286_priv *rt286 =
container_of(work, struct rt286_priv, jack_detect_work.work);
int status = 0;
bool hp = false;
bool mic = false;
rt286_jack_detect(rt286, &hp, &mic);
if (hp == true)
status |= SND_JACK_HEADPHONE;
if (mic == true)
status |= SND_JACK_MICROPHONE;
snd_soc_jack_report(rt286->jack, status,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
}
int rt286_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack)
{
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
rt286->jack = jack;
if (jack) {
if (rt286->jack->status & SND_JACK_HEADPHONE)
snd_soc_dapm_force_enable_pin(dapm, "LDO1");
regmap_update_bits(rt286->regmap, RT286_IRQ_CTRL, 0x2, 0x2);
snd_soc_jack_report(rt286->jack, rt286->jack->status,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
} else {
regmap_update_bits(rt286->regmap, RT286_IRQ_CTRL, 0x2, 0x0);
snd_soc_dapm_disable_pin(dapm, "LDO1");
}
snd_soc_dapm_sync(dapm);
return 0;
}
static int is_mclk_mode(struct snd_soc_dapm_widget *source,
struct snd_soc_dapm_widget *sink)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(source->dapm);
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
if (rt286->clk_id == RT286_SCLK_S_MCLK)
return 1;
else
return 0;
}
static int rt286_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_write(codec,
RT286_SPK_EAPD, RT286_SET_EAPD_HIGH);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_write(codec,
RT286_SPK_EAPD, RT286_SET_EAPD_LOW);
break;
default:
return 0;
}
return 0;
}
static int rt286_set_dmic1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_write(codec, RT286_SET_PIN_DMIC1, 0x20);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_write(codec, RT286_SET_PIN_DMIC1, 0);
break;
default:
return 0;
}
return 0;
}
static int rt286_vref_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec,
RT286_CBJ_CTRL1, 0x0400, 0x0000);
mdelay(50);
break;
default:
return 0;
}
return 0;
}
static int rt286_ldo2_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, RT286_POWER_CTRL2, 0x38, 0x08);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, RT286_POWER_CTRL2, 0x38, 0x30);
break;
default:
return 0;
}
return 0;
}
static int rt286_mic1_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec,
RT286_A_BIAS_CTRL3, 0xc000, 0x8000);
snd_soc_update_bits(codec,
RT286_A_BIAS_CTRL2, 0xc000, 0x8000);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec,
RT286_A_BIAS_CTRL3, 0xc000, 0x0000);
snd_soc_update_bits(codec,
RT286_A_BIAS_CTRL2, 0xc000, 0x0000);
break;
default:
return 0;
}
return 0;
}
static int rt286_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0;
int d_len_code;
switch (params_rate(params)) {
case 44100:
val |= 0x4000;
break;
case 48000:
break;
default:
dev_err(codec->dev, "Unsupported sample rate %d\n",
params_rate(params));
return -EINVAL;
}
switch (rt286->sys_clk) {
case 12288000:
case 24576000:
if (params_rate(params) != 48000) {
dev_err(codec->dev, "Sys_clk is not matched (%d %d)\n",
params_rate(params), rt286->sys_clk);
return -EINVAL;
}
break;
case 11289600:
case 22579200:
if (params_rate(params) != 44100) {
dev_err(codec->dev, "Sys_clk is not matched (%d %d)\n",
params_rate(params), rt286->sys_clk);
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
RT286_I2S_CTRL1, 0x0018, d_len_code << 3);
dev_dbg(codec->dev, "format val = 0x%x\n", val);
snd_soc_update_bits(codec, RT286_DAC_FORMAT, 0x407f, val);
snd_soc_update_bits(codec, RT286_ADC_FORMAT, 0x407f, val);
return 0;
}
static int rt286_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x800, 0x800);
break;
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x800, 0x0);
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x300, 0x0);
break;
case SND_SOC_DAIFMT_LEFT_J:
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x300, 0x1 << 8);
break;
case SND_SOC_DAIFMT_DSP_A:
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x300, 0x2 << 8);
break;
case SND_SOC_DAIFMT_DSP_B:
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x300, 0x3 << 8);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT286_DAC_FORMAT, 0x8000, 0);
snd_soc_update_bits(codec, RT286_ADC_FORMAT, 0x8000, 0);
return 0;
}
static int rt286_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "%s freq=%d\n", __func__, freq);
if (RT286_SCLK_S_MCLK == clk_id) {
snd_soc_update_bits(codec,
RT286_I2S_CTRL2, 0x0100, 0x0);
snd_soc_update_bits(codec,
RT286_PLL_CTRL1, 0x20, 0x20);
} else {
snd_soc_update_bits(codec,
RT286_I2S_CTRL2, 0x0100, 0x0100);
snd_soc_update_bits(codec,
RT286_PLL_CTRL, 0x4, 0x4);
snd_soc_update_bits(codec,
RT286_PLL_CTRL1, 0x20, 0x0);
}
switch (freq) {
case 19200000:
if (RT286_SCLK_S_MCLK == clk_id) {
dev_err(codec->dev, "Should not use MCLK\n");
return -EINVAL;
}
snd_soc_update_bits(codec,
RT286_I2S_CTRL2, 0x40, 0x40);
break;
case 24000000:
if (RT286_SCLK_S_MCLK == clk_id) {
dev_err(codec->dev, "Should not use MCLK\n");
return -EINVAL;
}
snd_soc_update_bits(codec,
RT286_I2S_CTRL2, 0x40, 0x0);
break;
case 12288000:
case 11289600:
snd_soc_update_bits(codec,
RT286_I2S_CTRL2, 0x8, 0x0);
snd_soc_update_bits(codec,
RT286_CLK_DIV, 0xfc1e, 0x0004);
break;
case 24576000:
case 22579200:
snd_soc_update_bits(codec,
RT286_I2S_CTRL2, 0x8, 0x8);
snd_soc_update_bits(codec,
RT286_CLK_DIV, 0xfc1e, 0x5406);
break;
default:
dev_err(codec->dev, "Unsupported system clock\n");
return -EINVAL;
}
rt286->sys_clk = freq;
rt286->clk_id = clk_id;
return 0;
}
static int rt286_set_bclk_ratio(struct snd_soc_dai *dai, unsigned int ratio)
{
struct snd_soc_codec *codec = dai->codec;
dev_dbg(codec->dev, "%s ratio=%d\n", __func__, ratio);
if (50 == ratio)
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x1000, 0x1000);
else
snd_soc_update_bits(codec,
RT286_I2S_CTRL1, 0x1000, 0x0);
return 0;
}
static int rt286_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (SND_SOC_BIAS_STANDBY == snd_soc_codec_get_bias_level(codec)) {
snd_soc_write(codec,
RT286_SET_AUDIO_POWER, AC_PWRST_D0);
snd_soc_update_bits(codec,
RT286_DC_GAIN, 0x200, 0x200);
}
break;
case SND_SOC_BIAS_ON:
mdelay(10);
snd_soc_update_bits(codec,
RT286_CBJ_CTRL1, 0x0400, 0x0400);
snd_soc_update_bits(codec,
RT286_DC_GAIN, 0x200, 0x0);
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec,
RT286_SET_AUDIO_POWER, AC_PWRST_D3);
snd_soc_update_bits(codec,
RT286_CBJ_CTRL1, 0x0400, 0x0000);
break;
default:
break;
}
return 0;
}
static irqreturn_t rt286_irq(int irq, void *data)
{
struct rt286_priv *rt286 = data;
bool hp = false;
bool mic = false;
int status = 0;
rt286_jack_detect(rt286, &hp, &mic);
regmap_update_bits(rt286->regmap, RT286_IRQ_CTRL, 0x1, 0x1);
if (hp == true)
status |= SND_JACK_HEADPHONE;
if (mic == true)
status |= SND_JACK_MICROPHONE;
snd_soc_jack_report(rt286->jack, status,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
pm_wakeup_event(&rt286->i2c->dev, 300);
return IRQ_HANDLED;
}
static int rt286_probe(struct snd_soc_codec *codec)
{
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
rt286->codec = codec;
if (rt286->i2c->irq) {
regmap_update_bits(rt286->regmap,
RT286_IRQ_CTRL, 0x2, 0x2);
INIT_DELAYED_WORK(&rt286->jack_detect_work,
rt286_jack_detect_work);
schedule_delayed_work(&rt286->jack_detect_work,
msecs_to_jiffies(1250));
}
return 0;
}
static int rt286_remove(struct snd_soc_codec *codec)
{
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
cancel_delayed_work_sync(&rt286->jack_detect_work);
return 0;
}
static int rt286_suspend(struct snd_soc_codec *codec)
{
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt286->regmap, true);
regcache_mark_dirty(rt286->regmap);
return 0;
}
static int rt286_resume(struct snd_soc_codec *codec)
{
struct rt286_priv *rt286 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt286->regmap, false);
rt286_index_sync(codec);
regcache_sync(rt286->regmap);
return 0;
}
static int rt286_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt286_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct rt286_priv *rt286;
int i, ret, val;
rt286 = devm_kzalloc(&i2c->dev, sizeof(*rt286),
GFP_KERNEL);
if (NULL == rt286)
return -ENOMEM;
rt286->regmap = devm_regmap_init(&i2c->dev, NULL, i2c, &rt286_regmap);
if (IS_ERR(rt286->regmap)) {
ret = PTR_ERR(rt286->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = regmap_read(rt286->regmap,
RT286_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID), &val);
if (ret != 0) {
dev_err(&i2c->dev, "I2C error %d\n", ret);
return ret;
}
if (val != RT286_VENDOR_ID && val != RT288_VENDOR_ID) {
dev_err(&i2c->dev,
"Device with ID register %x is not rt286\n", val);
return -ENODEV;
}
rt286->index_cache = rt286_index_def;
rt286->index_cache_size = INDEX_CACHE_SIZE;
rt286->i2c = i2c;
i2c_set_clientdata(i2c, rt286);
for (i = 0; i < INDEX_CACHE_SIZE; i++)
regmap_write(rt286->regmap, rt286->index_cache[i].reg,
rt286->index_cache[i].def);
for (i = 0; i < ARRAY_SIZE(rt286_reg); i++)
regmap_write(rt286->regmap, rt286_reg[i].reg,
rt286_reg[i].def);
if (pdata)
rt286->pdata = *pdata;
if (dmi_check_system(force_combo_jack_table) ||
dmi_check_system(dmi_dell_dino))
rt286->pdata.cbj_en = true;
regmap_write(rt286->regmap, RT286_SET_AUDIO_POWER, AC_PWRST_D3);
for (i = 0; i < RT286_POWER_REG_LEN; i++)
regmap_write(rt286->regmap,
RT286_SET_POWER(rt286_support_power_controls[i]),
AC_PWRST_D1);
if (!rt286->pdata.cbj_en) {
regmap_write(rt286->regmap, RT286_CBJ_CTRL2, 0x0000);
regmap_write(rt286->regmap, RT286_MIC1_DET_CTRL, 0x0816);
regmap_update_bits(rt286->regmap,
RT286_CBJ_CTRL1, 0xf000, 0xb000);
} else {
regmap_update_bits(rt286->regmap,
RT286_CBJ_CTRL1, 0xf000, 0x5000);
}
mdelay(10);
if (!rt286->pdata.gpio2_en)
regmap_write(rt286->regmap, RT286_SET_DMIC2_DEFAULT, 0x4000);
else
regmap_write(rt286->regmap, RT286_SET_DMIC2_DEFAULT, 0);
mdelay(10);
regmap_write(rt286->regmap, RT286_MISC_CTRL1, 0x0000);
regmap_update_bits(rt286->regmap, RT286_POWER_CTRL2, 0xc, 0x0);
regmap_update_bits(rt286->regmap, RT286_POWER_CTRL1, 0x1001, 0x1001);
regmap_update_bits(rt286->regmap, RT286_DEPOP_CTRL2, 0x403a, 0x401a);
regmap_update_bits(rt286->regmap, RT286_DEPOP_CTRL3, 0xf777, 0x4737);
regmap_update_bits(rt286->regmap, RT286_DEPOP_CTRL4, 0x00ff, 0x003f);
if (dmi_check_system(dmi_dell_dino)) {
regmap_update_bits(rt286->regmap,
RT286_SET_GPIO_MASK, 0x40, 0x40);
regmap_update_bits(rt286->regmap,
RT286_SET_GPIO_DIRECTION, 0x40, 0x40);
regmap_update_bits(rt286->regmap,
RT286_SET_GPIO_DATA, 0x40, 0x40);
regmap_update_bits(rt286->regmap,
RT286_GPIO_CTRL, 0xc, 0x8);
}
if (rt286->i2c->irq) {
ret = request_threaded_irq(rt286->i2c->irq, NULL, rt286_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT, "rt286", rt286);
if (ret != 0) {
dev_err(&i2c->dev,
"Failed to reguest IRQ: %d\n", ret);
return ret;
}
}
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt286,
rt286_dai, ARRAY_SIZE(rt286_dai));
return ret;
}
static int rt286_i2c_remove(struct i2c_client *i2c)
{
struct rt286_priv *rt286 = i2c_get_clientdata(i2c);
if (i2c->irq)
free_irq(i2c->irq, rt286);
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
