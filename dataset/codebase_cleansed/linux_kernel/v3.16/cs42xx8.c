static int cs42xx8_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42xx8_priv *cs42xx8 = snd_soc_codec_get_drvdata(codec);
cs42xx8->sysclk = freq;
return 0;
}
static int cs42xx8_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int format)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs42xx8_priv *cs42xx8 = snd_soc_codec_get_drvdata(codec);
u32 val;
switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_LEFT_J:
val = CS42XX8_INTF_DAC_DIF_LEFTJ | CS42XX8_INTF_ADC_DIF_LEFTJ;
break;
case SND_SOC_DAIFMT_I2S:
val = CS42XX8_INTF_DAC_DIF_I2S | CS42XX8_INTF_ADC_DIF_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
val = CS42XX8_INTF_DAC_DIF_RIGHTJ | CS42XX8_INTF_ADC_DIF_RIGHTJ;
break;
default:
dev_err(codec->dev, "unsupported dai format\n");
return -EINVAL;
}
regmap_update_bits(cs42xx8->regmap, CS42XX8_INTF,
CS42XX8_INTF_DAC_DIF_MASK |
CS42XX8_INTF_ADC_DIF_MASK, val);
switch (format & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
cs42xx8->slave_mode = true;
break;
case SND_SOC_DAIFMT_CBM_CFM:
cs42xx8->slave_mode = false;
break;
default:
dev_err(codec->dev, "unsupported master/slave mode\n");
return -EINVAL;
}
return 0;
}
static int cs42xx8_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42xx8_priv *cs42xx8 = snd_soc_codec_get_drvdata(codec);
bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
u32 ratio = cs42xx8->sysclk / params_rate(params);
u32 i, fm, val, mask;
for (i = 0; i < ARRAY_SIZE(cs42xx8_ratios); i++) {
if (cs42xx8_ratios[i].ratio == ratio)
break;
}
if (i == ARRAY_SIZE(cs42xx8_ratios)) {
dev_err(codec->dev, "unsupported sysclk ratio\n");
return -EINVAL;
}
mask = CS42XX8_FUNCMOD_MFREQ_MASK;
val = cs42xx8_ratios[i].mclk;
fm = cs42xx8->slave_mode ? CS42XX8_FM_AUTO : cs42xx8_ratios[i].speed;
regmap_update_bits(cs42xx8->regmap, CS42XX8_FUNCMOD,
CS42XX8_FUNCMOD_xC_FM_MASK(tx) | mask,
CS42XX8_FUNCMOD_xC_FM(tx, fm) | val);
return 0;
}
static int cs42xx8_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
struct cs42xx8_priv *cs42xx8 = snd_soc_codec_get_drvdata(codec);
regmap_update_bits(cs42xx8->regmap, CS42XX8_DACMUTE,
CS42XX8_DACMUTE_ALL, mute ? CS42XX8_DACMUTE_ALL : 0);
return 0;
}
static bool cs42xx8_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42XX8_STATUS:
return true;
default:
return false;
}
}
static bool cs42xx8_writeable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS42XX8_CHIPID:
case CS42XX8_STATUS:
return false;
default:
return true;
}
}
static int cs42xx8_codec_probe(struct snd_soc_codec *codec)
{
struct cs42xx8_priv *cs42xx8 = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
switch (cs42xx8->drvdata->num_adcs) {
case 3:
snd_soc_add_codec_controls(codec, cs42xx8_adc3_snd_controls,
ARRAY_SIZE(cs42xx8_adc3_snd_controls));
snd_soc_dapm_new_controls(dapm, cs42xx8_adc3_dapm_widgets,
ARRAY_SIZE(cs42xx8_adc3_dapm_widgets));
snd_soc_dapm_add_routes(dapm, cs42xx8_adc3_dapm_routes,
ARRAY_SIZE(cs42xx8_adc3_dapm_routes));
break;
default:
break;
}
regmap_write(cs42xx8->regmap, CS42XX8_DACMUTE, CS42XX8_DACMUTE_ALL);
return 0;
}
int cs42xx8_probe(struct device *dev, struct regmap *regmap)
{
const struct of_device_id *of_id = of_match_device(cs42xx8_of_match, dev);
struct cs42xx8_priv *cs42xx8;
int ret, val, i;
cs42xx8 = devm_kzalloc(dev, sizeof(*cs42xx8), GFP_KERNEL);
if (cs42xx8 == NULL)
return -ENOMEM;
dev_set_drvdata(dev, cs42xx8);
if (of_id)
cs42xx8->drvdata = of_id->data;
if (!cs42xx8->drvdata) {
dev_err(dev, "failed to find driver data\n");
return -EINVAL;
}
cs42xx8->clk = devm_clk_get(dev, "mclk");
if (IS_ERR(cs42xx8->clk)) {
dev_err(dev, "failed to get the clock: %ld\n",
PTR_ERR(cs42xx8->clk));
return -EINVAL;
}
cs42xx8->sysclk = clk_get_rate(cs42xx8->clk);
for (i = 0; i < ARRAY_SIZE(cs42xx8->supplies); i++)
cs42xx8->supplies[i].supply = cs42xx8_supply_names[i];
ret = devm_regulator_bulk_get(dev,
ARRAY_SIZE(cs42xx8->supplies), cs42xx8->supplies);
if (ret) {
dev_err(dev, "failed to request supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(cs42xx8->supplies),
cs42xx8->supplies);
if (ret) {
dev_err(dev, "failed to enable supplies: %d\n", ret);
return ret;
}
msleep(5);
cs42xx8->regmap = regmap;
if (IS_ERR(cs42xx8->regmap)) {
ret = PTR_ERR(cs42xx8->regmap);
dev_err(dev, "failed to allocate regmap: %d\n", ret);
goto err_enable;
}
regcache_cache_bypass(cs42xx8->regmap, true);
ret = regmap_read(cs42xx8->regmap, CS42XX8_CHIPID, &val);
if (ret < 0) {
dev_err(dev, "failed to get device ID, ret = %d", ret);
goto err_enable;
}
if (((val & CS42XX8_CHIPID_CHIP_ID_MASK) >> 4) != 0x00) {
dev_err(dev, "unmatched chip ID: %d\n",
(val & CS42XX8_CHIPID_CHIP_ID_MASK) >> 4);
ret = -EINVAL;
goto err_enable;
}
dev_info(dev, "found device, revision %X\n",
val & CS42XX8_CHIPID_REV_ID_MASK);
regcache_cache_bypass(cs42xx8->regmap, false);
cs42xx8_dai.name = cs42xx8->drvdata->name;
cs42xx8_dai.capture.channels_max = cs42xx8->drvdata->num_adcs * 2;
ret = snd_soc_register_codec(dev, &cs42xx8_driver, &cs42xx8_dai, 1);
if (ret) {
dev_err(dev, "failed to register codec:%d\n", ret);
goto err_enable;
}
regcache_cache_only(cs42xx8->regmap, true);
err_enable:
regulator_bulk_disable(ARRAY_SIZE(cs42xx8->supplies),
cs42xx8->supplies);
return ret;
}
static int cs42xx8_runtime_resume(struct device *dev)
{
struct cs42xx8_priv *cs42xx8 = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(cs42xx8->clk);
if (ret) {
dev_err(dev, "failed to enable mclk: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(cs42xx8->supplies),
cs42xx8->supplies);
if (ret) {
dev_err(dev, "failed to enable supplies: %d\n", ret);
goto err_clk;
}
msleep(5);
regcache_cache_only(cs42xx8->regmap, false);
ret = regcache_sync(cs42xx8->regmap);
if (ret) {
dev_err(dev, "failed to sync regmap: %d\n", ret);
goto err_bulk;
}
return 0;
err_bulk:
regulator_bulk_disable(ARRAY_SIZE(cs42xx8->supplies),
cs42xx8->supplies);
err_clk:
clk_disable_unprepare(cs42xx8->clk);
return ret;
}
static int cs42xx8_runtime_suspend(struct device *dev)
{
struct cs42xx8_priv *cs42xx8 = dev_get_drvdata(dev);
regcache_cache_only(cs42xx8->regmap, true);
regulator_bulk_disable(ARRAY_SIZE(cs42xx8->supplies),
cs42xx8->supplies);
clk_disable_unprepare(cs42xx8->clk);
return 0;
}
