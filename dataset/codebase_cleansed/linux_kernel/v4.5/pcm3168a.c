static int pcm3168a_reset(struct pcm3168a_priv *pcm3168a)
{
int ret;
ret = regmap_write(pcm3168a->regmap, PCM3168A_RST_SMODE, 0);
if (ret)
return ret;
msleep(DIV_ROUND_UP(3846 * 1000, pcm3168a->sysclk));
return regmap_write(pcm3168a->regmap, PCM3168A_RST_SMODE,
PCM3168A_MRST_MASK | PCM3168A_SRST_MASK);
}
static int pcm3168a_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm3168a_priv *pcm3168a = snd_soc_codec_get_drvdata(codec);
regmap_write(pcm3168a->regmap, PCM3168A_DAC_MUTE, mute ? 0xff : 0);
return 0;
}
static int pcm3168a_set_dai_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct pcm3168a_priv *pcm3168a = snd_soc_codec_get_drvdata(dai->codec);
if (freq > PCM1368A_MAX_SYSCLK)
return -EINVAL;
pcm3168a->sysclk = freq;
return 0;
}
static int pcm3168a_set_dai_fmt(struct snd_soc_dai *dai,
unsigned int format, bool dac)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm3168a_priv *pcm3168a = snd_soc_codec_get_drvdata(codec);
u32 fmt, reg, mask, shift;
bool master_mode;
switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
fmt = PCM3168A_FMT_LEFT_J;
break;
case SND_SOC_DAIFMT_I2S:
fmt = PCM3168A_FMT_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
fmt = PCM3168A_FMT_RIGHT_J;
break;
case SND_SOC_DAIFMT_DSP_A:
fmt = PCM3168A_FMT_DSP_A;
break;
case SND_SOC_DAIFMT_DSP_B:
fmt = PCM3168A_FMT_DSP_B;
break;
default:
dev_err(codec->dev, "unsupported dai format\n");
return -EINVAL;
}
switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
master_mode = false;
break;
case SND_SOC_DAIFMT_CBM_CFM:
master_mode = true;
break;
default:
dev_err(codec->dev, "unsupported master/slave mode\n");
return -EINVAL;
}
switch (format & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
default:
return -EINVAL;
}
if (dac) {
reg = PCM3168A_DAC_PWR_MST_FMT;
mask = PCM3168A_DAC_FMT_MASK;
shift = PCM3168A_DAC_FMT_SHIFT;
pcm3168a->dac_master_mode = master_mode;
pcm3168a->dac_fmt = fmt;
} else {
reg = PCM3168A_ADC_MST_FMT;
mask = PCM3168A_ADC_FMTAD_MASK;
shift = PCM3168A_ADC_FMTAD_SHIFT;
pcm3168a->adc_master_mode = master_mode;
pcm3168a->adc_fmt = fmt;
}
regmap_update_bits(pcm3168a->regmap, reg, mask, fmt << shift);
return 0;
}
static int pcm3168a_set_dai_fmt_dac(struct snd_soc_dai *dai,
unsigned int format)
{
return pcm3168a_set_dai_fmt(dai, format, true);
}
static int pcm3168a_set_dai_fmt_adc(struct snd_soc_dai *dai,
unsigned int format)
{
return pcm3168a_set_dai_fmt(dai, format, false);
}
static int pcm3168a_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct pcm3168a_priv *pcm3168a = snd_soc_codec_get_drvdata(codec);
bool tx, master_mode;
u32 val, mask, shift, reg;
unsigned int rate, channels, fmt, ratio, max_ratio;
int i, min_frame_size;
snd_pcm_format_t format;
rate = params_rate(params);
format = params_format(params);
channels = params_channels(params);
ratio = pcm3168a->sysclk / rate;
tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
if (tx) {
max_ratio = PCM3168A_NUM_SCKI_RATIOS_DAC;
reg = PCM3168A_DAC_PWR_MST_FMT;
mask = PCM3168A_DAC_MSDA_MASK;
shift = PCM3168A_DAC_MSDA_SHIFT;
master_mode = pcm3168a->dac_master_mode;
fmt = pcm3168a->dac_fmt;
} else {
max_ratio = PCM3168A_NUM_SCKI_RATIOS_ADC;
reg = PCM3168A_ADC_MST_FMT;
mask = PCM3168A_ADC_MSAD_MASK;
shift = PCM3168A_ADC_MSAD_SHIFT;
master_mode = pcm3168a->adc_master_mode;
fmt = pcm3168a->adc_fmt;
}
for (i = 0; i < max_ratio; i++) {
if (pcm3168a_scki_ratios[i] == ratio)
break;
}
if (i == max_ratio) {
dev_err(codec->dev, "unsupported sysclk ratio\n");
return -EINVAL;
}
min_frame_size = params_width(params) * 2;
switch (min_frame_size) {
case 32:
if (master_mode || (fmt != PCM3168A_FMT_RIGHT_J)) {
dev_err(codec->dev, "32-bit frames are supported only for slave mode using right justified\n");
return -EINVAL;
}
fmt = PCM3168A_FMT_RIGHT_J_16;
break;
case 48:
if (master_mode || (fmt & PCM3168A_FMT_DSP_MASK)) {
dev_err(codec->dev, "48-bit frames not supported in master mode, or slave mode using DSP\n");
return -EINVAL;
}
break;
case 64:
break;
default:
dev_err(codec->dev, "unsupported frame size: %d\n", min_frame_size);
return -EINVAL;
}
if (master_mode)
val = ((i + 1) << shift);
else
val = 0;
regmap_update_bits(pcm3168a->regmap, reg, mask, val);
if (tx) {
mask = PCM3168A_DAC_FMT_MASK;
shift = PCM3168A_DAC_FMT_SHIFT;
} else {
mask = PCM3168A_ADC_FMTAD_MASK;
shift = PCM3168A_ADC_FMTAD_SHIFT;
}
regmap_update_bits(pcm3168a->regmap, reg, mask, fmt << shift);
return 0;
}
static bool pcm3168a_readable_register(struct device *dev, unsigned int reg)
{
if (reg >= PCM3168A_RST_SMODE)
return true;
else
return false;
}
static bool pcm3168a_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case PCM3168A_DAC_ZERO:
case PCM3168A_ADC_OV:
return true;
default:
return false;
}
}
static bool pcm3168a_writeable_register(struct device *dev, unsigned int reg)
{
if (reg < PCM3168A_RST_SMODE)
return false;
switch (reg) {
case PCM3168A_DAC_ZERO:
case PCM3168A_ADC_OV:
return false;
default:
return true;
}
}
int pcm3168a_probe(struct device *dev, struct regmap *regmap)
{
struct pcm3168a_priv *pcm3168a;
int ret, i;
pcm3168a = devm_kzalloc(dev, sizeof(*pcm3168a), GFP_KERNEL);
if (pcm3168a == NULL)
return -ENOMEM;
dev_set_drvdata(dev, pcm3168a);
pcm3168a->scki = devm_clk_get(dev, "scki");
if (IS_ERR(pcm3168a->scki)) {
ret = PTR_ERR(pcm3168a->scki);
if (ret != -EPROBE_DEFER)
dev_err(dev, "failed to acquire clock 'scki': %d\n", ret);
return ret;
}
ret = clk_prepare_enable(pcm3168a->scki);
if (ret) {
dev_err(dev, "Failed to enable mclk: %d\n", ret);
return ret;
}
pcm3168a->sysclk = clk_get_rate(pcm3168a->scki);
for (i = 0; i < ARRAY_SIZE(pcm3168a->supplies); i++)
pcm3168a->supplies[i].supply = pcm3168a_supply_names[i];
ret = devm_regulator_bulk_get(dev,
ARRAY_SIZE(pcm3168a->supplies), pcm3168a->supplies);
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "failed to request supplies: %d\n", ret);
goto err_clk;
}
ret = regulator_bulk_enable(ARRAY_SIZE(pcm3168a->supplies),
pcm3168a->supplies);
if (ret) {
dev_err(dev, "failed to enable supplies: %d\n", ret);
goto err_clk;
}
pcm3168a->regmap = regmap;
if (IS_ERR(pcm3168a->regmap)) {
ret = PTR_ERR(pcm3168a->regmap);
dev_err(dev, "failed to allocate regmap: %d\n", ret);
goto err_regulator;
}
ret = pcm3168a_reset(pcm3168a);
if (ret) {
dev_err(dev, "Failed to reset device: %d\n", ret);
goto err_regulator;
}
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
pm_runtime_idle(dev);
ret = snd_soc_register_codec(dev, &pcm3168a_driver, pcm3168a_dais,
ARRAY_SIZE(pcm3168a_dais));
if (ret) {
dev_err(dev, "failed to register codec: %d\n", ret);
goto err_regulator;
}
return 0;
err_regulator:
regulator_bulk_disable(ARRAY_SIZE(pcm3168a->supplies),
pcm3168a->supplies);
err_clk:
clk_disable_unprepare(pcm3168a->scki);
return ret;
}
void pcm3168a_remove(struct device *dev)
{
struct pcm3168a_priv *pcm3168a = dev_get_drvdata(dev);
snd_soc_unregister_codec(dev);
pm_runtime_disable(dev);
regulator_bulk_disable(ARRAY_SIZE(pcm3168a->supplies),
pcm3168a->supplies);
clk_disable_unprepare(pcm3168a->scki);
}
static int pcm3168a_rt_resume(struct device *dev)
{
struct pcm3168a_priv *pcm3168a = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(pcm3168a->scki);
if (ret) {
dev_err(dev, "Failed to enable mclk: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(pcm3168a->supplies),
pcm3168a->supplies);
if (ret) {
dev_err(dev, "Failed to enable supplies: %d\n", ret);
goto err_clk;
}
ret = pcm3168a_reset(pcm3168a);
if (ret) {
dev_err(dev, "Failed to reset device: %d\n", ret);
goto err_regulator;
}
regcache_cache_only(pcm3168a->regmap, false);
regcache_mark_dirty(pcm3168a->regmap);
ret = regcache_sync(pcm3168a->regmap);
if (ret) {
dev_err(dev, "Failed to sync regmap: %d\n", ret);
goto err_regulator;
}
return 0;
err_regulator:
regulator_bulk_disable(ARRAY_SIZE(pcm3168a->supplies),
pcm3168a->supplies);
err_clk:
clk_disable_unprepare(pcm3168a->scki);
return ret;
}
static int pcm3168a_rt_suspend(struct device *dev)
{
struct pcm3168a_priv *pcm3168a = dev_get_drvdata(dev);
regcache_cache_only(pcm3168a->regmap, true);
regulator_bulk_disable(ARRAY_SIZE(pcm3168a->supplies),
pcm3168a->supplies);
clk_disable_unprepare(pcm3168a->scki);
return 0;
}
