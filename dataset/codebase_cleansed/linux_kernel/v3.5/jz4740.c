static unsigned int jz4740_codec_read(struct snd_soc_codec *codec,
unsigned int reg)
{
struct jz4740_codec *jz4740_codec = snd_soc_codec_get_drvdata(codec);
return readl(jz4740_codec->base + (reg << 2));
}
static int jz4740_codec_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int val)
{
struct jz4740_codec *jz4740_codec = snd_soc_codec_get_drvdata(codec);
u32 *cache = codec->reg_cache;
cache[reg] = val;
writel(val, jz4740_codec->base + (reg << 2));
return 0;
}
static int jz4740_codec_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
uint32_t val;
struct snd_soc_codec *codec = dai->codec;
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
snd_soc_update_bits(codec, JZ4740_REG_CODEC_2,
JZ4740_CODEC_2_SAMPLE_RATE_MASK, val);
return 0;
}
static void jz4740_codec_wakeup(struct snd_soc_codec *codec)
{
int i;
uint32_t *cache = codec->reg_cache;
snd_soc_update_bits(codec, JZ4740_REG_CODEC_1,
JZ4740_CODEC_1_RESET, JZ4740_CODEC_1_RESET);
udelay(2);
snd_soc_update_bits(codec, JZ4740_REG_CODEC_1,
JZ4740_CODEC_1_SUSPEND | JZ4740_CODEC_1_RESET, 0);
for (i = 0; i < ARRAY_SIZE(jz4740_codec_regs); ++i)
jz4740_codec_write(codec, i, cache[i]);
}
static int jz4740_codec_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
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
snd_soc_update_bits(codec, JZ4740_REG_CODEC_1, mask, value);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF)
jz4740_codec_wakeup(codec);
mask = JZ4740_CODEC_1_VREF_DISABLE |
JZ4740_CODEC_1_VREF_AMP_DISABLE |
JZ4740_CODEC_1_HEADPHONE_POWERDOWN_M;
value = JZ4740_CODEC_1_VREF_DISABLE |
JZ4740_CODEC_1_VREF_AMP_DISABLE |
JZ4740_CODEC_1_HEADPHONE_POWERDOWN_M;
snd_soc_update_bits(codec, JZ4740_REG_CODEC_1, mask, value);
break;
case SND_SOC_BIAS_OFF:
mask = JZ4740_CODEC_1_SUSPEND;
value = JZ4740_CODEC_1_SUSPEND;
snd_soc_update_bits(codec, JZ4740_REG_CODEC_1, mask, value);
break;
default:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int jz4740_codec_dev_probe(struct snd_soc_codec *codec)
{
snd_soc_update_bits(codec, JZ4740_REG_CODEC_1,
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
static int __devinit jz4740_codec_probe(struct platform_device *pdev)
{
int ret;
struct jz4740_codec *jz4740_codec;
struct resource *mem;
jz4740_codec = devm_kzalloc(&pdev->dev, sizeof(*jz4740_codec),
GFP_KERNEL);
if (!jz4740_codec)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "Failed to get mmio memory resource\n");
ret = -ENOENT;
goto err_out;
}
mem = request_mem_region(mem->start, resource_size(mem), pdev->name);
if (!mem) {
dev_err(&pdev->dev, "Failed to request mmio memory region\n");
ret = -EBUSY;
goto err_out;
}
jz4740_codec->base = ioremap(mem->start, resource_size(mem));
if (!jz4740_codec->base) {
dev_err(&pdev->dev, "Failed to ioremap mmio memory\n");
ret = -EBUSY;
goto err_release_mem_region;
}
jz4740_codec->mem = mem;
platform_set_drvdata(pdev, jz4740_codec);
ret = snd_soc_register_codec(&pdev->dev,
&soc_codec_dev_jz4740_codec, &jz4740_codec_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Failed to register codec\n");
goto err_iounmap;
}
return 0;
err_iounmap:
iounmap(jz4740_codec->base);
err_release_mem_region:
release_mem_region(mem->start, resource_size(mem));
err_out:
return ret;
}
static int __devexit jz4740_codec_remove(struct platform_device *pdev)
{
struct jz4740_codec *jz4740_codec = platform_get_drvdata(pdev);
struct resource *mem = jz4740_codec->mem;
snd_soc_unregister_codec(&pdev->dev);
iounmap(jz4740_codec->base);
release_mem_region(mem->start, resource_size(mem));
platform_set_drvdata(pdev, NULL);
return 0;
}
