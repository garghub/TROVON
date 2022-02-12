static void sun4i_spdif_configure(struct sun4i_spdif_dev *host)
{
regmap_write(host->regmap, SUN4I_SPDIF_CTL, SUN4I_SPDIF_CTL_RESET);
regmap_update_bits(host->regmap, SUN4I_SPDIF_FCTL,
SUN4I_SPDIF_FCTL_FTX, SUN4I_SPDIF_FCTL_FTX);
regmap_write(host->regmap, SUN4I_SPDIF_TXCNT, 0);
}
static void sun4i_snd_txctrl_on(struct snd_pcm_substream *substream,
struct sun4i_spdif_dev *host)
{
if (substream->runtime->channels == 1)
regmap_update_bits(host->regmap, SUN4I_SPDIF_TXCFG,
SUN4I_SPDIF_TXCFG_SINGLEMOD,
SUN4I_SPDIF_TXCFG_SINGLEMOD);
regmap_update_bits(host->regmap, SUN4I_SPDIF_TXCFG,
SUN4I_SPDIF_TXCFG_TXEN, SUN4I_SPDIF_TXCFG_TXEN);
regmap_update_bits(host->regmap, SUN4I_SPDIF_INT,
SUN4I_SPDIF_INT_TXDRQEN, SUN4I_SPDIF_INT_TXDRQEN);
regmap_update_bits(host->regmap, SUN4I_SPDIF_CTL,
SUN4I_SPDIF_CTL_GEN, SUN4I_SPDIF_CTL_GEN);
}
static void sun4i_snd_txctrl_off(struct snd_pcm_substream *substream,
struct sun4i_spdif_dev *host)
{
regmap_update_bits(host->regmap, SUN4I_SPDIF_TXCFG,
SUN4I_SPDIF_TXCFG_TXEN, 0);
regmap_update_bits(host->regmap, SUN4I_SPDIF_INT,
SUN4I_SPDIF_INT_TXDRQEN, 0);
regmap_update_bits(host->regmap, SUN4I_SPDIF_CTL,
SUN4I_SPDIF_CTL_GEN, 0);
}
static int sun4i_spdif_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sun4i_spdif_dev *host = snd_soc_dai_get_drvdata(rtd->cpu_dai);
if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK)
return -EINVAL;
sun4i_spdif_configure(host);
return 0;
}
static int sun4i_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
int ret = 0;
int fmt;
unsigned long rate = params_rate(params);
u32 mclk_div = 0;
unsigned int mclk = 0;
u32 reg_val;
struct sun4i_spdif_dev *host = snd_soc_dai_get_drvdata(cpu_dai);
struct platform_device *pdev = host->pdev;
switch (params_channels(params)) {
case 1:
case 2:
fmt = 0;
break;
case 4:
fmt = SUN4I_SPDIF_TXCFG_NONAUDIO;
break;
default:
return -EINVAL;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
fmt |= SUN4I_SPDIF_TXCFG_FMT16BIT;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
fmt |= SUN4I_SPDIF_TXCFG_FMT20BIT;
break;
case SNDRV_PCM_FORMAT_S24_LE:
fmt |= SUN4I_SPDIF_TXCFG_FMT24BIT;
break;
default:
return -EINVAL;
}
switch (rate) {
case 22050:
case 44100:
case 88200:
case 176400:
mclk = 22579200;
break;
case 24000:
case 32000:
case 48000:
case 96000:
case 192000:
mclk = 24576000;
break;
default:
return -EINVAL;
}
ret = clk_set_rate(host->spdif_clk, mclk);
if (ret < 0) {
dev_err(&pdev->dev,
"Setting SPDIF clock rate for %d Hz failed!\n", mclk);
return ret;
}
regmap_update_bits(host->regmap, SUN4I_SPDIF_FCTL,
SUN4I_SPDIF_FCTL_TXIM, SUN4I_SPDIF_FCTL_TXIM);
switch (rate) {
case 22050:
case 24000:
mclk_div = 8;
break;
case 32000:
mclk_div = 6;
break;
case 44100:
case 48000:
mclk_div = 4;
break;
case 88200:
case 96000:
mclk_div = 2;
break;
case 176400:
case 192000:
mclk_div = 1;
break;
default:
return -EINVAL;
}
reg_val = 0;
reg_val |= SUN4I_SPDIF_TXCFG_ASS;
reg_val |= fmt;
reg_val |= SUN4I_SPDIF_TXCFG_CHSTMODE;
reg_val |= SUN4I_SPDIF_TXCFG_TXRATIO(mclk_div - 1);
regmap_write(host->regmap, SUN4I_SPDIF_TXCFG, reg_val);
return 0;
}
static int sun4i_spdif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
int ret = 0;
struct sun4i_spdif_dev *host = snd_soc_dai_get_drvdata(dai);
if (substream->stream != SNDRV_PCM_STREAM_PLAYBACK)
return -EINVAL;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
sun4i_snd_txctrl_on(substream, host);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
sun4i_snd_txctrl_off(substream, host);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int sun4i_spdif_soc_dai_probe(struct snd_soc_dai *dai)
{
struct sun4i_spdif_dev *host = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai, &host->dma_params_tx, NULL);
return 0;
}
static int sun4i_spdif_runtime_suspend(struct device *dev)
{
struct sun4i_spdif_dev *host = dev_get_drvdata(dev);
clk_disable_unprepare(host->spdif_clk);
clk_disable_unprepare(host->apb_clk);
return 0;
}
static int sun4i_spdif_runtime_resume(struct device *dev)
{
struct sun4i_spdif_dev *host = dev_get_drvdata(dev);
clk_prepare_enable(host->spdif_clk);
clk_prepare_enable(host->apb_clk);
return 0;
}
static int sun4i_spdif_probe(struct platform_device *pdev)
{
struct sun4i_spdif_dev *host;
struct resource *res;
int ret;
void __iomem *base;
dev_dbg(&pdev->dev, "Entered %s\n", __func__);
host = devm_kzalloc(&pdev->dev, sizeof(*host), GFP_KERNEL);
if (!host)
return -ENOMEM;
host->pdev = pdev;
memcpy(&host->cpu_dai_drv, &sun4i_spdif_dai, sizeof(sun4i_spdif_dai));
host->cpu_dai_drv.name = dev_name(&pdev->dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
host->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&sun4i_spdif_regmap_config);
host->apb_clk = devm_clk_get(&pdev->dev, "apb");
if (IS_ERR(host->apb_clk)) {
dev_err(&pdev->dev, "failed to get a apb clock.\n");
return PTR_ERR(host->apb_clk);
}
host->spdif_clk = devm_clk_get(&pdev->dev, "spdif");
if (IS_ERR(host->spdif_clk)) {
dev_err(&pdev->dev, "failed to get a spdif clock.\n");
ret = PTR_ERR(host->spdif_clk);
goto err_disable_apb_clk;
}
host->dma_params_tx.addr = res->start + SUN4I_SPDIF_TXFIFO;
host->dma_params_tx.maxburst = 4;
host->dma_params_tx.addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
platform_set_drvdata(pdev, host);
ret = devm_snd_soc_register_component(&pdev->dev,
&sun4i_spdif_component, &sun4i_spdif_dai, 1);
if (ret)
goto err_disable_apb_clk;
pm_runtime_enable(&pdev->dev);
if (!pm_runtime_enabled(&pdev->dev)) {
ret = sun4i_spdif_runtime_resume(&pdev->dev);
if (ret)
goto err_unregister;
}
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret)
goto err_suspend;
return 0;
err_suspend:
if (!pm_runtime_status_suspended(&pdev->dev))
sun4i_spdif_runtime_suspend(&pdev->dev);
err_unregister:
pm_runtime_disable(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
err_disable_apb_clk:
clk_disable_unprepare(host->apb_clk);
return ret;
}
static int sun4i_spdif_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
if (!pm_runtime_status_suspended(&pdev->dev))
sun4i_spdif_runtime_suspend(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
return 0;
}
