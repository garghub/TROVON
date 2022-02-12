static int axi_spdif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct axi_spdif *spdif = snd_soc_dai_get_drvdata(dai);
unsigned int val;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
val = AXI_SPDIF_CTRL_TXDATA;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
val = 0;
break;
default:
return -EINVAL;
}
regmap_update_bits(spdif->regmap, AXI_SPDIF_REG_CTRL,
AXI_SPDIF_CTRL_TXDATA, val);
return 0;
}
static int axi_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct axi_spdif *spdif = snd_soc_dai_get_drvdata(dai);
unsigned int rate = params_rate(params);
unsigned int clkdiv, stat;
switch (params_rate(params)) {
case 32000:
stat = AXI_SPDIF_FREQ_32000;
break;
case 44100:
stat = AXI_SPDIF_FREQ_44100;
break;
case 48000:
stat = AXI_SPDIF_FREQ_48000;
break;
default:
stat = AXI_SPDIF_FREQ_NA;
break;
}
clkdiv = DIV_ROUND_CLOSEST(clk_get_rate(spdif->clk_ref),
rate * 64 * 2) - 1;
clkdiv <<= AXI_SPDIF_CTRL_CLKDIV_OFFSET;
regmap_write(spdif->regmap, AXI_SPDIF_REG_STAT, stat);
regmap_update_bits(spdif->regmap, AXI_SPDIF_REG_CTRL,
AXI_SPDIF_CTRL_CLKDIV_MASK, clkdiv);
return 0;
}
static int axi_spdif_dai_probe(struct snd_soc_dai *dai)
{
struct axi_spdif *spdif = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai, &spdif->dma_data, NULL);
return 0;
}
static int axi_spdif_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct axi_spdif *spdif = snd_soc_dai_get_drvdata(dai);
int ret;
ret = snd_pcm_hw_constraint_ratnums(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&spdif->rate_constraints);
if (ret)
return ret;
ret = clk_prepare_enable(spdif->clk_ref);
if (ret)
return ret;
regmap_update_bits(spdif->regmap, AXI_SPDIF_REG_CTRL,
AXI_SPDIF_CTRL_TXEN, AXI_SPDIF_CTRL_TXEN);
return 0;
}
static void axi_spdif_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct axi_spdif *spdif = snd_soc_dai_get_drvdata(dai);
regmap_update_bits(spdif->regmap, AXI_SPDIF_REG_CTRL,
AXI_SPDIF_CTRL_TXEN, 0);
clk_disable_unprepare(spdif->clk_ref);
}
static int axi_spdif_probe(struct platform_device *pdev)
{
struct axi_spdif *spdif;
struct resource *res;
void __iomem *base;
int ret;
spdif = devm_kzalloc(&pdev->dev, sizeof(*spdif), GFP_KERNEL);
if (!spdif)
return -ENOMEM;
platform_set_drvdata(pdev, spdif);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
spdif->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&axi_spdif_regmap_config);
if (IS_ERR(spdif->regmap))
return PTR_ERR(spdif->regmap);
spdif->clk = devm_clk_get(&pdev->dev, "axi");
if (IS_ERR(spdif->clk))
return PTR_ERR(spdif->clk);
spdif->clk_ref = devm_clk_get(&pdev->dev, "ref");
if (IS_ERR(spdif->clk_ref))
return PTR_ERR(spdif->clk_ref);
ret = clk_prepare_enable(spdif->clk);
if (ret)
return ret;
spdif->dma_data.addr = res->start + AXI_SPDIF_REG_TX_FIFO;
spdif->dma_data.addr_width = 4;
spdif->dma_data.maxburst = 1;
spdif->ratnum.num = clk_get_rate(spdif->clk_ref) / 128;
spdif->ratnum.den_step = 1;
spdif->ratnum.den_min = 1;
spdif->ratnum.den_max = 64;
spdif->rate_constraints.rats = &spdif->ratnum;
spdif->rate_constraints.nrats = 1;
ret = devm_snd_soc_register_component(&pdev->dev, &axi_spdif_component,
&axi_spdif_dai, 1);
if (ret)
goto err_clk_disable;
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret)
goto err_clk_disable;
return 0;
err_clk_disable:
clk_disable_unprepare(spdif->clk);
return ret;
}
static int axi_spdif_dev_remove(struct platform_device *pdev)
{
struct axi_spdif *spdif = platform_get_drvdata(pdev);
clk_disable_unprepare(spdif->clk);
return 0;
}
