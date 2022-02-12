static int sun8i_codec_runtime_resume(struct device *dev)
{
struct sun8i_codec *scodec = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(scodec->clk_module);
if (ret) {
dev_err(dev, "Failed to enable the module clock\n");
return ret;
}
ret = clk_prepare_enable(scodec->clk_bus);
if (ret) {
dev_err(dev, "Failed to enable the bus clock\n");
goto err_disable_modclk;
}
regcache_cache_only(scodec->regmap, false);
ret = regcache_sync(scodec->regmap);
if (ret) {
dev_err(dev, "Failed to sync regmap cache\n");
goto err_disable_clk;
}
return 0;
err_disable_clk:
clk_disable_unprepare(scodec->clk_bus);
err_disable_modclk:
clk_disable_unprepare(scodec->clk_module);
return ret;
}
static int sun8i_codec_runtime_suspend(struct device *dev)
{
struct sun8i_codec *scodec = dev_get_drvdata(dev);
regcache_cache_only(scodec->regmap, true);
regcache_mark_dirty(scodec->regmap);
clk_disable_unprepare(scodec->clk_module);
clk_disable_unprepare(scodec->clk_bus);
return 0;
}
static int sun8i_codec_get_hw_rate(struct snd_pcm_hw_params *params)
{
unsigned int rate = params_rate(params);
switch (rate) {
case 8000:
case 7350:
return 0x0;
case 11025:
return 0x1;
case 12000:
return 0x2;
case 16000:
return 0x3;
case 22050:
return 0x4;
case 24000:
return 0x5;
case 32000:
return 0x6;
case 44100:
return 0x7;
case 48000:
return 0x8;
case 96000:
return 0x9;
case 192000:
return 0xa;
default:
return -EINVAL;
}
}
static int sun8i_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct sun8i_codec *scodec = snd_soc_codec_get_drvdata(dai->codec);
u32 value;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
value = 0x0;
break;
case SND_SOC_DAIFMT_CBM_CFM:
value = 0x1;
break;
default:
return -EINVAL;
}
regmap_update_bits(scodec->regmap, SUN8I_AIF1CLK_CTRL,
BIT(SUN8I_AIF1CLK_CTRL_AIF1_MSTR_MOD),
value << SUN8I_AIF1CLK_CTRL_AIF1_MSTR_MOD);
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
value = 0x0;
break;
case SND_SOC_DAIFMT_IB_IF:
value = 0x1;
break;
default:
return -EINVAL;
}
regmap_update_bits(scodec->regmap, SUN8I_AIF1CLK_CTRL,
BIT(SUN8I_AIF1CLK_CTRL_AIF1_BCLK_INV),
value << SUN8I_AIF1CLK_CTRL_AIF1_BCLK_INV);
regmap_update_bits(scodec->regmap, SUN8I_AIF1CLK_CTRL,
BIT(SUN8I_AIF1CLK_CTRL_AIF1_LRCK_INV),
value << SUN8I_AIF1CLK_CTRL_AIF1_LRCK_INV);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
value = 0x0;
break;
case SND_SOC_DAIFMT_LEFT_J:
value = 0x1;
break;
case SND_SOC_DAIFMT_RIGHT_J:
value = 0x2;
break;
case SND_SOC_DAIFMT_DSP_A:
case SND_SOC_DAIFMT_DSP_B:
value = 0x3;
break;
default:
return -EINVAL;
}
regmap_update_bits(scodec->regmap, SUN8I_AIF1CLK_CTRL,
BIT(SUN8I_AIF1CLK_CTRL_AIF1_DATA_FMT),
value << SUN8I_AIF1CLK_CTRL_AIF1_DATA_FMT);
return 0;
}
static int sun8i_codec_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct sun8i_codec *scodec = snd_soc_codec_get_drvdata(dai->codec);
int sample_rate;
regmap_update_bits(scodec->regmap, SUN8I_AIF1CLK_CTRL,
SUN8I_AIF1CLK_CTRL_AIF1_WORD_SIZ_MASK,
SUN8I_AIF1CLK_CTRL_AIF1_WORD_SIZ_16);
regmap_update_bits(scodec->regmap, SUN8I_AIF1CLK_CTRL,
SUN8I_AIF1CLK_CTRL_AIF1_LRCK_DIV_MASK,
SUN8I_AIF1CLK_CTRL_AIF1_LRCK_DIV_16);
sample_rate = sun8i_codec_get_hw_rate(params);
if (sample_rate < 0)
return sample_rate;
regmap_update_bits(scodec->regmap, SUN8I_SYS_SR_CTRL,
SUN8I_SYS_SR_CTRL_AIF1_FS_MASK,
sample_rate << SUN8I_SYS_SR_CTRL_AIF1_FS);
regmap_update_bits(scodec->regmap, SUN8I_SYS_SR_CTRL,
SUN8I_SYS_SR_CTRL_AIF2_FS_MASK,
sample_rate << SUN8I_SYS_SR_CTRL_AIF2_FS);
return 0;
}
static int sun8i_codec_probe(struct platform_device *pdev)
{
struct resource *res_base;
struct sun8i_codec *scodec;
void __iomem *base;
int ret;
scodec = devm_kzalloc(&pdev->dev, sizeof(*scodec), GFP_KERNEL);
if (!scodec)
return -ENOMEM;
scodec->dev = &pdev->dev;
scodec->clk_module = devm_clk_get(&pdev->dev, "mod");
if (IS_ERR(scodec->clk_module)) {
dev_err(&pdev->dev, "Failed to get the module clock\n");
return PTR_ERR(scodec->clk_module);
}
scodec->clk_bus = devm_clk_get(&pdev->dev, "bus");
if (IS_ERR(scodec->clk_bus)) {
dev_err(&pdev->dev, "Failed to get the bus clock\n");
return PTR_ERR(scodec->clk_bus);
}
res_base = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res_base);
if (IS_ERR(base)) {
dev_err(&pdev->dev, "Failed to map the registers\n");
return PTR_ERR(base);
}
scodec->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&sun8i_codec_regmap_config);
if (IS_ERR(scodec->regmap)) {
dev_err(&pdev->dev, "Failed to create our regmap\n");
return PTR_ERR(scodec->regmap);
}
platform_set_drvdata(pdev, scodec);
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = sun8i_codec_runtime_resume(&pdev->dev);
if (ret)
goto err_pm_disable;
}
ret = snd_soc_register_codec(&pdev->dev, &sun8i_soc_codec,
&sun8i_codec_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Failed to register codec\n");
goto err_suspend;
}
return ret;
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
sun8i_codec_runtime_suspend(&pdev->dev);
err_pm_disable:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int sun8i_codec_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct sun8i_codec *scodec = snd_soc_card_get_drvdata(card);
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
sun8i_codec_runtime_suspend(&pdev->dev);
snd_soc_unregister_codec(&pdev->dev);
clk_disable_unprepare(scodec->clk_module);
clk_disable_unprepare(scodec->clk_bus);
return 0;
}
