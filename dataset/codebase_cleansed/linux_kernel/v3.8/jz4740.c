static int jz4740_codec_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct jz4740_codec *jz4740_codec = snd_soc_codec_get_drvdata(dai->codec);
uint32_t val;
switch (params_rate(params)) {
case 8000:
val = 0;
break;
case 11025:
val = 1;
break;
case 12000:
val = 2;
break;
case 16000:
val = 3;
break;
case 22050:
val = 4;
break;
case 24000:
val = 5;
break;
case 32000:
val = 6;
break;
case 44100:
val = 7;
break;
case 48000:
val = 8;
break;
default:
return -EINVAL;
}
val <<= JZ4740_CODEC_2_SAMPLE_RATE_OFFSET;
regmap_update_bits(jz4740_codec->regmap, JZ4740_REG_CODEC_2,
JZ4740_CODEC_2_SAMPLE_RATE_MASK, val);
return 0;
}
static void jz4740_codec_wakeup(struct regmap *regmap)
{
regmap_update_bits(regmap, JZ4740_REG_CODEC_1,
JZ4740_CODEC_1_RESET, JZ4740_CODEC_1_RESET);
udelay(2);
regmap_update_bits(regmap, JZ4740_REG_CODEC_1,
JZ4740_CODEC_1_SUSPEND | JZ4740_CODEC_1_RESET, 0);
regcache_sync(regmap);
}
static int jz4740_codec_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct jz4740_codec *jz4740_codec = snd_soc_codec_get_drvdata(codec);
struct regmap *regmap = jz4740_codec->regmap;
unsigned int mask;
unsigned int value;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
mask = JZ4740_CODEC_1_VREF_DISABLE |
JZ4740_CODEC_1_VREF_AMP_DISABLE |
JZ4740_CODEC_1_HEADPHONE_POWERDOWN_M;
value = 0;
regmap_update_bits(regmap, JZ4740_REG_CODEC_1, mask, value);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
jz4740_codec_wakeup(regmap);
mask = JZ4740_CODEC_1_VREF_DISABLE |
JZ4740_CODEC_1_VREF_AMP_DISABLE |
JZ4740_CODEC_1_HEADPHONE_POWERDOWN_M;
value = JZ4740_CODEC_1_VREF_DISABLE |
JZ4740_CODEC_1_VREF_AMP_DISABLE |
JZ4740_CODEC_1_HEADPHONE_POWERDOWN_M;
regmap_update_bits(regmap, JZ4740_REG_CODEC_1, mask, value);
break;
case SND_SOC_BIAS_OFF:
mask = JZ4740_CODEC_1_SUSPEND;
value = JZ4740_CODEC_1_SUSPEND;
regmap_update_bits(regmap, JZ4740_REG_CODEC_1, mask, value);
regcache_mark_dirty(regmap);
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int jz4740_codec_dev_probe(struct snd_soc_codec *codec)
{
struct jz4740_codec *jz4740_codec = snd_soc_codec_get_drvdata(codec);
regmap_update_bits(jz4740_codec->regmap, JZ4740_REG_CODEC_1,
JZ4740_CODEC_1_SW2_ENABLE, JZ4740_CODEC_1_SW2_ENABLE);
jz4740_codec_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int jz4740_codec_dev_remove(struct snd_soc_codec *codec)
{
jz4740_codec_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int jz4740_codec_suspend(struct snd_soc_codec *codec)
{
return jz4740_codec_set_bias_level(codec, SND_SOC_BIAS_OFF);
}
static int jz4740_codec_resume(struct snd_soc_codec *codec)
{
return jz4740_codec_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
}
static int jz4740_codec_probe(struct platform_device *pdev)
{
int ret;
struct jz4740_codec *jz4740_codec;
struct resource *mem;
void __iomem *base;
jz4740_codec = devm_kzalloc(&pdev->dev, sizeof(*jz4740_codec),
GFP_KERNEL);
if (!jz4740_codec)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_request_and_ioremap(&pdev->dev, mem);
if (!base)
return -EBUSY;
jz4740_codec->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&jz4740_codec_regmap_config);
if (IS_ERR(jz4740_codec->regmap))
return PTR_ERR(jz4740_codec->regmap);
platform_set_drvdata(pdev, jz4740_codec);
ret = snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_jz4740_codec, &jz4740_codec_dai, 1);
if (ret)
dev_err(&pdev->dev, "Failed to register codec\n");
return ret;
}
static int jz4740_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
platform_set_drvdata(pdev, NULL);
return 0;
}
