static bool rt274_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0 ... 0xff:
case RT274_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID):
case RT274_GET_HP_SENSE:
case RT274_GET_MIC_SENSE:
case RT274_PROC_COEF:
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_DAC_OUT0, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_DAC_OUT1, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_ADC_IN1, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_ADC_IN2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DAC_OUT0, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DAC_OUT1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_ADC_IN1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_ADC_IN2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DMIC1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DMIC2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_LINE1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_LINE2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_CONNECT_SEL, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_CONNECT_SEL, RT274_MIXER_IN1, 0):
case VERB_CMD(AC_VERB_GET_CONNECT_SEL, RT274_MIXER_IN2, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_DMIC1, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_DMIC2, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_LINE1, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_LINE2, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_UNSOLICITED_RESPONSE, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_UNSOLICITED_RESPONSE, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_UNSOLICITED_RESPONSE, RT274_INLINE_CMD, 0):
return true;
default:
return false;
}
}
static bool rt274_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0 ... 0xff:
case RT274_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID):
case RT274_GET_HP_SENSE:
case RT274_GET_MIC_SENSE:
case RT274_SET_AUDIO_POWER:
case RT274_SET_HPO_POWER:
case RT274_SET_DMIC1_POWER:
case RT274_LOUT_MUX:
case RT274_HPO_MUX:
case RT274_ADC0_MUX:
case RT274_ADC1_MUX:
case RT274_SET_MIC:
case RT274_SET_PIN_HPO:
case RT274_SET_PIN_LOUT3:
case RT274_SET_PIN_DMIC1:
case RT274_SET_AMP_GAIN_HPO:
case RT274_SET_DMIC2_DEFAULT:
case RT274_DAC0L_GAIN:
case RT274_DAC0R_GAIN:
case RT274_DAC1L_GAIN:
case RT274_DAC1R_GAIN:
case RT274_ADCL_GAIN:
case RT274_ADCR_GAIN:
case RT274_MIC_GAIN:
case RT274_HPOL_GAIN:
case RT274_HPOR_GAIN:
case RT274_LOUTL_GAIN:
case RT274_LOUTR_GAIN:
case RT274_DAC_FORMAT:
case RT274_ADC_FORMAT:
case RT274_COEF_INDEX:
case RT274_PROC_COEF:
case RT274_SET_AMP_GAIN_ADC_IN1:
case RT274_SET_AMP_GAIN_ADC_IN2:
case RT274_SET_POWER(RT274_DAC_OUT0):
case RT274_SET_POWER(RT274_DAC_OUT1):
case RT274_SET_POWER(RT274_ADC_IN1):
case RT274_SET_POWER(RT274_ADC_IN2):
case RT274_SET_POWER(RT274_DMIC2):
case RT274_SET_POWER(RT274_MIC):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_EAPD_BTLENABLE, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_DAC_OUT0, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_DAC_OUT1, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_ADC_IN1, 0):
case VERB_CMD(AC_VERB_GET_STREAM_FORMAT, RT274_ADC_IN2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DAC_OUT0, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DAC_OUT1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_ADC_IN1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_ADC_IN2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DMIC1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_DMIC2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_LINE1, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_LINE2, 0):
case VERB_CMD(AC_VERB_GET_AMP_GAIN_MUTE, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_CONNECT_SEL, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_CONNECT_SEL, RT274_MIXER_IN1, 0):
case VERB_CMD(AC_VERB_GET_CONNECT_SEL, RT274_MIXER_IN2, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_DMIC1, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_DMIC2, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_LINE1, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_LINE2, 0):
case VERB_CMD(AC_VERB_GET_PIN_WIDGET_CONTROL, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_UNSOLICITED_RESPONSE, RT274_HP_OUT, 0):
case VERB_CMD(AC_VERB_GET_UNSOLICITED_RESPONSE, RT274_MIC, 0):
case VERB_CMD(AC_VERB_GET_UNSOLICITED_RESPONSE, RT274_INLINE_CMD, 0):
return true;
default:
return false;
}
}
static void rt274_index_sync(struct snd_soc_codec *codec)
{
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
int i;
for (i = 0; i < INDEX_CACHE_SIZE; i++) {
snd_soc_write(codec, rt274->index_cache[i].reg,
rt274->index_cache[i].def);
}
}
static int rt274_jack_detect(struct rt274_priv *rt274, bool *hp, bool *mic)
{
unsigned int buf;
*hp = false;
*mic = false;
if (!rt274->codec)
return -EINVAL;
regmap_read(rt274->regmap, RT274_GET_HP_SENSE, &buf);
*hp = buf & 0x80000000;
regmap_read(rt274->regmap, RT274_GET_MIC_SENSE, &buf);
*mic = buf & 0x80000000;
pr_debug("*hp = %d *mic = %d\n", *hp, *mic);
return 0;
}
static void rt274_jack_detect_work(struct work_struct *work)
{
struct rt274_priv *rt274 =
container_of(work, struct rt274_priv, jack_detect_work.work);
int status = 0;
bool hp = false;
bool mic = false;
if (rt274_jack_detect(rt274, &hp, &mic) < 0)
return;
if (hp == true)
status |= SND_JACK_HEADPHONE;
if (mic == true)
status |= SND_JACK_MICROPHONE;
snd_soc_jack_report(rt274->jack, status,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
}
static int rt274_mic_detect(struct snd_soc_codec *codec,
struct snd_soc_jack *jack, void *data)
{
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
if (jack == NULL) {
regmap_update_bits(rt274->regmap, RT274_EAPD_GPIO_IRQ_CTRL,
RT274_IRQ_EN, RT274_IRQ_DIS);
return 0;
}
rt274->jack = jack;
regmap_update_bits(rt274->regmap, RT274_EAPD_GPIO_IRQ_CTRL,
RT274_IRQ_EN, RT274_IRQ_EN);
rt274_irq(0, rt274);
return 0;
}
static int rt274_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
unsigned int val = 0;
int d_len_code = 0, c_len_code = 0;
switch (params_rate(params)) {
case 44100:
case 48000:
break;
default:
dev_err(codec->dev, "Unsupported sample rate %d\n",
params_rate(params));
return -EINVAL;
}
switch (rt274->sys_clk) {
case 12288000:
case 24576000:
if (params_rate(params) != 48000) {
dev_err(codec->dev, "Sys_clk is not matched (%d %d)\n",
params_rate(params), rt274->sys_clk);
return -EINVAL;
}
break;
case 11289600:
case 22579200:
if (params_rate(params) != 44100) {
dev_err(codec->dev, "Sys_clk is not matched (%d %d)\n",
params_rate(params), rt274->sys_clk);
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
switch (params_width(params)) {
case 16:
d_len_code = 0;
c_len_code = 0;
val |= (0x1 << 4);
break;
case 32:
d_len_code = 2;
c_len_code = 3;
val |= (0x4 << 4);
break;
case 20:
d_len_code = 1;
c_len_code = 1;
val |= (0x2 << 4);
break;
case 24:
d_len_code = 2;
c_len_code = 2;
val |= (0x3 << 4);
break;
case 8:
d_len_code = 3;
c_len_code = 0;
break;
default:
return -EINVAL;
}
if (rt274->master)
c_len_code = 0x3;
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, 0xc018, d_len_code << 3 | c_len_code << 14);
dev_dbg(codec->dev, "format val = 0x%x\n", val);
snd_soc_update_bits(codec, RT274_DAC_FORMAT, 0x407f, val);
snd_soc_update_bits(codec, RT274_ADC_FORMAT, 0x407f, val);
return 0;
}
static int rt274_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, RT274_I2S_MODE_MASK, RT274_I2S_MODE_M);
rt274->master = true;
break;
case SND_SOC_DAIFMT_CBS_CFS:
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, RT274_I2S_MODE_MASK, RT274_I2S_MODE_S);
rt274->master = false;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
snd_soc_update_bits(codec, RT274_I2S_CTRL1,
RT274_I2S_FMT_MASK, RT274_I2S_FMT_I2S);
break;
case SND_SOC_DAIFMT_LEFT_J:
snd_soc_update_bits(codec, RT274_I2S_CTRL1,
RT274_I2S_FMT_MASK, RT274_I2S_FMT_LJ);
break;
case SND_SOC_DAIFMT_DSP_A:
snd_soc_update_bits(codec, RT274_I2S_CTRL1,
RT274_I2S_FMT_MASK, RT274_I2S_FMT_PCMA);
break;
case SND_SOC_DAIFMT_DSP_B:
snd_soc_update_bits(codec, RT274_I2S_CTRL1,
RT274_I2S_FMT_MASK, RT274_I2S_FMT_PCMB);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, RT274_DAC_FORMAT, 0x8000, 0);
snd_soc_update_bits(codec, RT274_ADC_FORMAT, 0x8000, 0);
return 0;
}
static int rt274_set_dai_pll(struct snd_soc_dai *dai, int pll_id, int source,
unsigned int freq_in, unsigned int freq_out)
{
struct snd_soc_codec *codec = dai->codec;
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
switch (source) {
case RT274_PLL2_S_MCLK:
snd_soc_update_bits(codec, RT274_PLL2_CTRL,
RT274_PLL2_SRC_MASK, RT274_PLL2_SRC_MCLK);
break;
default:
dev_warn(codec->dev, "invalid pll source, use BCLK\n");
case RT274_PLL2_S_BCLK:
snd_soc_update_bits(codec, RT274_PLL2_CTRL,
RT274_PLL2_SRC_MASK, RT274_PLL2_SRC_BCLK);
break;
}
if (source == RT274_PLL2_S_BCLK) {
snd_soc_update_bits(codec, RT274_MCLK_CTRL,
(0x3 << 12), (0x3 << 12));
switch (rt274->fs) {
case 50:
snd_soc_write(codec, 0x7a, 0xaab6);
snd_soc_write(codec, 0x7b, 0x0301);
snd_soc_write(codec, 0x7c, 0x04fe);
break;
case 64:
snd_soc_write(codec, 0x7a, 0xaa96);
snd_soc_write(codec, 0x7b, 0x8003);
snd_soc_write(codec, 0x7c, 0x081e);
break;
case 128:
snd_soc_write(codec, 0x7a, 0xaa96);
snd_soc_write(codec, 0x7b, 0x8003);
snd_soc_write(codec, 0x7c, 0x080e);
break;
default:
dev_warn(codec->dev, "invalid freq_in, assume 4.8M\n");
case 100:
snd_soc_write(codec, 0x7a, 0xaab6);
snd_soc_write(codec, 0x7b, 0x0301);
snd_soc_write(codec, 0x7c, 0x047e);
break;
}
}
return 0;
}
static int rt274_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
unsigned int clk_src, mclk_en;
dev_dbg(codec->dev, "%s freq=%d\n", __func__, freq);
switch (clk_id) {
case RT274_SCLK_S_MCLK:
mclk_en = RT274_MCLK_MODE_EN;
clk_src = RT274_CLK_SRC_MCLK;
break;
case RT274_SCLK_S_PLL1:
mclk_en = RT274_MCLK_MODE_DIS;
clk_src = RT274_CLK_SRC_MCLK;
break;
case RT274_SCLK_S_PLL2:
mclk_en = RT274_MCLK_MODE_EN;
clk_src = RT274_CLK_SRC_PLL2;
break;
default:
mclk_en = RT274_MCLK_MODE_DIS;
clk_src = RT274_CLK_SRC_MCLK;
dev_warn(codec->dev, "invalid sysclk source, use PLL1\n");
break;
}
snd_soc_update_bits(codec, RT274_MCLK_CTRL,
RT274_MCLK_MODE_MASK, mclk_en);
snd_soc_update_bits(codec, RT274_CLK_CTRL,
RT274_CLK_SRC_MASK, clk_src);
switch (freq) {
case 19200000:
if (clk_id == RT274_SCLK_S_MCLK) {
dev_err(codec->dev, "Should not use MCLK\n");
return -EINVAL;
}
snd_soc_update_bits(codec,
RT274_I2S_CTRL2, 0x40, 0x40);
break;
case 24000000:
if (clk_id == RT274_SCLK_S_MCLK) {
dev_err(codec->dev, "Should not use MCLK\n");
return -EINVAL;
}
snd_soc_update_bits(codec,
RT274_I2S_CTRL2, 0x40, 0x0);
break;
case 12288000:
case 11289600:
snd_soc_update_bits(codec,
RT274_MCLK_CTRL, 0x1fcf, 0x0008);
break;
case 24576000:
case 22579200:
snd_soc_update_bits(codec,
RT274_MCLK_CTRL, 0x1fcf, 0x1543);
break;
default:
dev_err(codec->dev, "Unsupported system clock\n");
return -EINVAL;
}
rt274->sys_clk = freq;
rt274->clk_id = clk_id;
return 0;
}
static int rt274_set_bclk_ratio(struct snd_soc_dai *dai, unsigned int ratio)
{
struct snd_soc_codec *codec = dai->codec;
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
dev_dbg(codec->dev, "%s ratio=%d\n", __func__, ratio);
rt274->fs = ratio;
if ((ratio / 50) == 0)
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, 0x1000, 0x1000);
else
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, 0x1000, 0x0);
return 0;
}
static int rt274_set_tdm_slot(struct snd_soc_dai *dai, unsigned int tx_mask,
unsigned int rx_mask, int slots, int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
if (rx_mask || tx_mask) {
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, RT274_TDM_EN, RT274_TDM_EN);
} else {
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, RT274_TDM_EN, RT274_TDM_DIS);
return 0;
}
switch (slots) {
case 4:
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, RT274_TDM_CH_NUM, RT274_TDM_4CH);
break;
case 2:
snd_soc_update_bits(codec,
RT274_I2S_CTRL1, RT274_TDM_CH_NUM, RT274_TDM_2CH);
break;
default:
dev_err(codec->dev,
"Support 2 or 4 slots TDM only\n");
return -EINVAL;
}
return 0;
}
static int rt274_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (SND_SOC_BIAS_STANDBY ==
snd_soc_codec_get_bias_level(codec)) {
snd_soc_write(codec,
RT274_SET_AUDIO_POWER, AC_PWRST_D0);
}
break;
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec,
RT274_SET_AUDIO_POWER, AC_PWRST_D3);
break;
default:
break;
}
return 0;
}
static irqreturn_t rt274_irq(int irq, void *data)
{
struct rt274_priv *rt274 = data;
bool hp = false;
bool mic = false;
int ret, status = 0;
regmap_update_bits(rt274->regmap, RT274_EAPD_GPIO_IRQ_CTRL,
RT274_IRQ_CLR, RT274_IRQ_CLR);
ret = rt274_jack_detect(rt274, &hp, &mic);
if (ret == 0) {
if (hp == true)
status |= SND_JACK_HEADPHONE;
if (mic == true)
status |= SND_JACK_MICROPHONE;
snd_soc_jack_report(rt274->jack, status,
SND_JACK_MICROPHONE | SND_JACK_HEADPHONE);
pm_wakeup_event(&rt274->i2c->dev, 300);
}
return IRQ_HANDLED;
}
static int rt274_probe(struct snd_soc_codec *codec)
{
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
rt274->codec = codec;
if (rt274->i2c->irq) {
INIT_DELAYED_WORK(&rt274->jack_detect_work,
rt274_jack_detect_work);
schedule_delayed_work(&rt274->jack_detect_work,
msecs_to_jiffies(1250));
}
return 0;
}
static int rt274_remove(struct snd_soc_codec *codec)
{
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
cancel_delayed_work_sync(&rt274->jack_detect_work);
return 0;
}
static int rt274_suspend(struct snd_soc_codec *codec)
{
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt274->regmap, true);
regcache_mark_dirty(rt274->regmap);
return 0;
}
static int rt274_resume(struct snd_soc_codec *codec)
{
struct rt274_priv *rt274 = snd_soc_codec_get_drvdata(codec);
regcache_cache_only(rt274->regmap, false);
rt274_index_sync(codec);
regcache_sync(rt274->regmap);
return 0;
}
static int rt274_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rt274_priv *rt274;
int ret;
unsigned int val;
rt274 = devm_kzalloc(&i2c->dev, sizeof(*rt274),
GFP_KERNEL);
if (rt274 == NULL)
return -ENOMEM;
rt274->regmap = devm_regmap_init(&i2c->dev, NULL, i2c, &rt274_regmap);
if (IS_ERR(rt274->regmap)) {
ret = PTR_ERR(rt274->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
regmap_read(rt274->regmap,
RT274_GET_PARAM(AC_NODE_ROOT, AC_PAR_VENDOR_ID), &val);
if (val != RT274_VENDOR_ID) {
dev_err(&i2c->dev,
"Device with ID register %#x is not rt274\n", val);
return -ENODEV;
}
rt274->index_cache = devm_kmemdup(&i2c->dev, rt274_index_def,
sizeof(rt274_index_def), GFP_KERNEL);
if (!rt274->index_cache)
return -ENOMEM;
rt274->index_cache_size = INDEX_CACHE_SIZE;
rt274->i2c = i2c;
i2c_set_clientdata(i2c, rt274);
regmap_write(rt274->regmap, RT274_RESET, 0);
regmap_update_bits(rt274->regmap, 0x1a, 0x4000, 0x4000);
regmap_update_bits(rt274->regmap, RT274_PAD_CTRL12, 0x3, 0x0);
regmap_write(rt274->regmap, RT274_COEF5b_INDEX, 0x01);
regmap_write(rt274->regmap, RT274_COEF5b_COEF, 0x8540);
regmap_update_bits(rt274->regmap, 0x6f, 0x0100, 0x0100);
regmap_write(rt274->regmap, 0x4a, 0x201b);
regmap_update_bits(rt274->regmap, 0x6f, 0x3000, 0x2000);
regmap_update_bits(rt274->regmap, 0x6f, 0xf, 0x0);
regmap_write(rt274->regmap, RT274_COEF58_INDEX, 0x00);
regmap_write(rt274->regmap, RT274_COEF58_COEF, 0xb888);
msleep(500);
regmap_update_bits(rt274->regmap, 0x6f, 0xf, 0xb);
regmap_write(rt274->regmap, RT274_COEF58_INDEX, 0x00);
regmap_write(rt274->regmap, RT274_COEF58_COEF, 0x3888);
regmap_write(rt274->regmap, RT274_SET_PIN_HPO, 0x40);
regmap_write(rt274->regmap, RT274_SET_PIN_LOUT3, 0x40);
regmap_write(rt274->regmap, RT274_SET_MIC, 0x20);
regmap_write(rt274->regmap, RT274_SET_PIN_DMIC1, 0x20);
regmap_update_bits(rt274->regmap, RT274_I2S_CTRL2, 0xc004, 0x4004);
regmap_update_bits(rt274->regmap, RT274_EAPD_GPIO_IRQ_CTRL,
RT274_GPI2_SEL_MASK, RT274_GPI2_SEL_DMIC_CLK);
regmap_write(rt274->regmap, RT274_UNSOLICITED_HP_OUT, 0x81);
regmap_write(rt274->regmap, RT274_UNSOLICITED_MIC, 0x82);
if (rt274->i2c->irq) {
ret = request_threaded_irq(rt274->i2c->irq, NULL, rt274_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT, "rt274", rt274);
if (ret != 0) {
dev_err(&i2c->dev,
"Failed to reguest IRQ: %d\n", ret);
return ret;
}
}
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_rt274,
rt274_dai, ARRAY_SIZE(rt274_dai));
return ret;
}
static int rt274_i2c_remove(struct i2c_client *i2c)
{
struct rt274_priv *rt274 = i2c_get_clientdata(i2c);
if (i2c->irq)
free_irq(i2c->irq, rt274);
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
