static int adc_enable_delay_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
switch (event) {
case SND_SOC_DAPM_POST_PMU:
msleep(200);
break;
default:
break;
}
return 0;
}
static void enable_and_reset_codec(struct regmap *regmap,
u32 codec_enable_bits, u32 codec_reset_bits)
{
regmap_update_bits(regmap, AUDIO_IC_CODEC_CTRL1,
codec_enable_bits | codec_reset_bits,
codec_enable_bits | ~codec_reset_bits);
msleep(20);
regmap_update_bits(regmap, AUDIO_IC_CODEC_CTRL1,
codec_reset_bits, codec_reset_bits);
}
static int atlas6_codec_enable_and_reset_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
#define ATLAS6_CODEC_ENABLE_BITS (1 << 29)
#define ATLAS6_CODEC_RESET_BITS (1 << 28)
struct sirf_audio_codec *sirf_audio_codec = dev_get_drvdata(w->codec->dev);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
enable_and_reset_codec(sirf_audio_codec->regmap,
ATLAS6_CODEC_ENABLE_BITS, ATLAS6_CODEC_RESET_BITS);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(sirf_audio_codec->regmap,
AUDIO_IC_CODEC_CTRL1, ATLAS6_CODEC_ENABLE_BITS,
~ATLAS6_CODEC_ENABLE_BITS);
break;
default:
break;
}
return 0;
}
static int prima2_codec_enable_and_reset_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
#define PRIMA2_CODEC_ENABLE_BITS (1 << 27)
#define PRIMA2_CODEC_RESET_BITS (1 << 26)
struct sirf_audio_codec *sirf_audio_codec = dev_get_drvdata(w->codec->dev);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
enable_and_reset_codec(sirf_audio_codec->regmap,
PRIMA2_CODEC_ENABLE_BITS, PRIMA2_CODEC_RESET_BITS);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(sirf_audio_codec->regmap,
AUDIO_IC_CODEC_CTRL1, PRIMA2_CODEC_ENABLE_BITS,
~PRIMA2_CODEC_ENABLE_BITS);
break;
default:
break;
}
return 0;
}
static int sirf_audio_codec_trigger(struct snd_pcm_substream *substream,
int cmd,
struct snd_soc_dai *dai)
{
int playback = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct snd_soc_codec *codec = dai->codec;
u32 val = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
break;
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (playback)
val = IC_HSLEN | IC_HSREN;
break;
default:
return -EINVAL;
}
if (playback)
snd_soc_update_bits(codec, AUDIO_IC_CODEC_CTRL0,
IC_HSLEN | IC_HSREN, val);
return 0;
}
static int sirf_audio_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
pm_runtime_enable(codec->dev);
if (of_device_is_compatible(codec->dev->of_node, "sirf,prima2-audio-codec")) {
snd_soc_dapm_new_controls(dapm,
prima2_output_driver_dapm_widgets,
ARRAY_SIZE(prima2_output_driver_dapm_widgets));
snd_soc_dapm_new_controls(dapm,
&prima2_codec_clock_dapm_widget, 1);
return snd_soc_add_codec_controls(codec,
volume_controls_prima2,
ARRAY_SIZE(volume_controls_prima2));
}
if (of_device_is_compatible(codec->dev->of_node, "sirf,atlas6-audio-codec")) {
snd_soc_dapm_new_controls(dapm,
atlas6_output_driver_dapm_widgets,
ARRAY_SIZE(atlas6_output_driver_dapm_widgets));
snd_soc_dapm_new_controls(dapm,
&atlas6_codec_clock_dapm_widget, 1);
return snd_soc_add_codec_controls(codec,
volume_controls_atlas6,
ARRAY_SIZE(volume_controls_atlas6));
}
return -EINVAL;
}
static int sirf_audio_codec_remove(struct snd_soc_codec *codec)
{
pm_runtime_disable(codec->dev);
return 0;
}
static int sirf_audio_codec_driver_probe(struct platform_device *pdev)
{
int ret;
struct sirf_audio_codec *sirf_audio_codec;
void __iomem *base;
struct resource *mem_res;
const struct of_device_id *match;
match = of_match_node(sirf_audio_codec_of_match, pdev->dev.of_node);
sirf_audio_codec = devm_kzalloc(&pdev->dev,
sizeof(struct sirf_audio_codec), GFP_KERNEL);
if (!sirf_audio_codec)
return -ENOMEM;
platform_set_drvdata(pdev, sirf_audio_codec);
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, mem_res);
if (base == NULL)
return -ENOMEM;
sirf_audio_codec->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&sirf_audio_codec_regmap_config);
if (IS_ERR(sirf_audio_codec->regmap))
return PTR_ERR(sirf_audio_codec->regmap);
sirf_audio_codec->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(sirf_audio_codec->clk)) {
dev_err(&pdev->dev, "Get clock failed.\n");
return PTR_ERR(sirf_audio_codec->clk);
}
ret = clk_prepare_enable(sirf_audio_codec->clk);
if (ret) {
dev_err(&pdev->dev, "Enable clock failed.\n");
return ret;
}
ret = snd_soc_register_codec(&(pdev->dev),
&soc_codec_device_sirf_audio_codec,
&sirf_audio_codec_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Register Audio Codec dai failed.\n");
goto err_clk_put;
}
regmap_update_bits(sirf_audio_codec->regmap, AUDIO_IC_CODEC_CTRL0,
IC_CPFREQ, IC_CPFREQ);
if (of_device_is_compatible(pdev->dev.of_node, "sirf,atlas6-audio-codec"))
regmap_update_bits(sirf_audio_codec->regmap,
AUDIO_IC_CODEC_CTRL0, IC_CPEN, IC_CPEN);
return 0;
err_clk_put:
clk_disable_unprepare(sirf_audio_codec->clk);
return ret;
}
static int sirf_audio_codec_driver_remove(struct platform_device *pdev)
{
struct sirf_audio_codec *sirf_audio_codec = platform_get_drvdata(pdev);
clk_disable_unprepare(sirf_audio_codec->clk);
snd_soc_unregister_codec(&(pdev->dev));
return 0;
}
static int sirf_audio_codec_suspend(struct device *dev)
{
struct sirf_audio_codec *sirf_audio_codec = dev_get_drvdata(dev);
regmap_read(sirf_audio_codec->regmap, AUDIO_IC_CODEC_CTRL0,
&sirf_audio_codec->reg_ctrl0);
regmap_read(sirf_audio_codec->regmap, AUDIO_IC_CODEC_CTRL1,
&sirf_audio_codec->reg_ctrl1);
clk_disable_unprepare(sirf_audio_codec->clk);
return 0;
}
static int sirf_audio_codec_resume(struct device *dev)
{
struct sirf_audio_codec *sirf_audio_codec = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(sirf_audio_codec->clk);
if (ret)
return ret;
regmap_write(sirf_audio_codec->regmap, AUDIO_IC_CODEC_CTRL0,
sirf_audio_codec->reg_ctrl0);
regmap_write(sirf_audio_codec->regmap, AUDIO_IC_CODEC_CTRL1,
sirf_audio_codec->reg_ctrl1);
return 0;
}
