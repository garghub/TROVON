static int zx_spdif_dai_probe(struct snd_soc_dai *dai)
{
struct zx_spdif_info *zx_spdif = dev_get_drvdata(dai->dev);
snd_soc_dai_set_drvdata(dai, zx_spdif);
zx_spdif->dma_data.addr = zx_spdif->mapbase + ZX_DATA;
zx_spdif->dma_data.maxburst = 8;
snd_soc_dai_init_dma_data(dai, &zx_spdif->dma_data, NULL);
return 0;
}
static int zx_spdif_chanstats(void __iomem *base, unsigned int rate)
{
u32 cstas1;
switch (rate) {
case 22050:
cstas1 = IEC958_AES3_CON_FS_22050;
break;
case 24000:
cstas1 = IEC958_AES3_CON_FS_24000;
break;
case 32000:
cstas1 = IEC958_AES3_CON_FS_32000;
break;
case 44100:
cstas1 = IEC958_AES3_CON_FS_44100;
break;
case 48000:
cstas1 = IEC958_AES3_CON_FS_48000;
break;
case 88200:
cstas1 = IEC958_AES3_CON_FS_88200;
break;
case 96000:
cstas1 = IEC958_AES3_CON_FS_96000;
break;
case 176400:
cstas1 = IEC958_AES3_CON_FS_176400;
break;
case 192000:
cstas1 = IEC958_AES3_CON_FS_192000;
break;
default:
return -EINVAL;
}
cstas1 = cstas1 << 24;
cstas1 |= IEC958_AES0_CON_NOT_COPYRIGHT;
writel_relaxed(cstas1, base + ZX_CH_STA_1);
return 0;
}
static int zx_spdif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *socdai)
{
struct zx_spdif_info *zx_spdif = dev_get_drvdata(socdai->dev);
struct zx_spdif_info *spdif = snd_soc_dai_get_drvdata(socdai);
struct snd_dmaengine_dai_dma_data *dma_data = &zx_spdif->dma_data;
u32 val, ch_num, rate;
int ret;
dma_data = snd_soc_dai_get_dma_data(socdai, substream);
dma_data->addr_width = params_width(params) >> 3;
val = readl_relaxed(zx_spdif->reg_base + ZX_CTRL);
val &= ~ZX_CTRL_MODA_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
val |= ZX_CTRL_MODA_16;
break;
case SNDRV_PCM_FORMAT_S18_3LE:
val |= ZX_CTRL_MODA_18;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
val |= ZX_CTRL_MODA_20;
break;
case SNDRV_PCM_FORMAT_S24_LE:
val |= ZX_CTRL_MODA_24;
break;
default:
dev_err(socdai->dev, "Format not support!\n");
return -EINVAL;
}
ch_num = params_channels(params);
if (ch_num == 2)
val |= ZX_CTRL_DOUBLE_TRACK;
else
val |= ZX_CTRL_LEFT_TRACK;
writel_relaxed(val, zx_spdif->reg_base + ZX_CTRL);
val = readl_relaxed(zx_spdif->reg_base + ZX_VALID_BIT);
val &= ~ZX_VALID_TRACK_MASK;
if (ch_num == 2)
val |= ZX_VALID_DOUBLE_TRACK;
else
val |= ZX_VALID_RIGHT_TRACK;
writel_relaxed(val, zx_spdif->reg_base + ZX_VALID_BIT);
rate = params_rate(params);
ret = zx_spdif_chanstats(zx_spdif->reg_base, rate);
if (ret)
return ret;
return clk_set_rate(spdif->dai_clk, rate * ch_num * ZX_SPDIF_CLK_RAT);
}
static void zx_spdif_cfg_tx(void __iomem *base, int on)
{
u32 val;
val = readl_relaxed(base + ZX_CTRL);
val &= ~(ZX_CTRL_ENB_MASK | ZX_CTRL_TX_MASK);
val |= on ? ZX_CTRL_OPEN : ZX_CTRL_CLOSE;
writel_relaxed(val, base + ZX_CTRL);
val = readl_relaxed(base + ZX_FIFOCTRL);
val &= ~ZX_FIFOCTRL_TX_DMA_EN_MASK;
if (on)
val |= ZX_FIFOCTRL_TX_DMA_EN;
writel_relaxed(val, base + ZX_FIFOCTRL);
}
static int zx_spdif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
u32 val;
struct zx_spdif_info *zx_spdif = dev_get_drvdata(dai->dev);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
val = readl_relaxed(zx_spdif->reg_base + ZX_FIFOCTRL);
val |= ZX_FIFOCTRL_TX_FIFO_RST;
writel_relaxed(val, zx_spdif->reg_base + ZX_FIFOCTRL);
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
zx_spdif_cfg_tx(zx_spdif->reg_base, true);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
zx_spdif_cfg_tx(zx_spdif->reg_base, false);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int zx_spdif_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct zx_spdif_info *zx_spdif = dev_get_drvdata(dai->dev);
return clk_prepare_enable(zx_spdif->dai_clk);
}
static void zx_spdif_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct zx_spdif_info *zx_spdif = dev_get_drvdata(dai->dev);
clk_disable_unprepare(zx_spdif->dai_clk);
}
static void zx_spdif_dev_init(void __iomem *base)
{
u32 val;
writel_relaxed(0, base + ZX_CTRL);
writel_relaxed(0, base + ZX_INT_MASK);
writel_relaxed(0xf, base + ZX_INT_STATUS);
writel_relaxed(0x1, base + ZX_FIFOCTRL);
val = readl_relaxed(base + ZX_FIFOCTRL);
val &= ~(ZX_FIFOCTRL_TXTH_MASK | ZX_FIFOCTRL_TX_FIFO_RST_MASK);
val |= ZX_FIFOCTRL_TXTH(8);
writel_relaxed(val, base + ZX_FIFOCTRL);
}
static int zx_spdif_probe(struct platform_device *pdev)
{
struct resource *res;
struct zx_spdif_info *zx_spdif;
int ret;
zx_spdif = devm_kzalloc(&pdev->dev, sizeof(*zx_spdif), GFP_KERNEL);
if (!zx_spdif)
return -ENOMEM;
zx_spdif->dai_clk = devm_clk_get(&pdev->dev, "tx");
if (IS_ERR(zx_spdif->dai_clk)) {
dev_err(&pdev->dev, "Fail to get clk\n");
return PTR_ERR(zx_spdif->dai_clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
zx_spdif->mapbase = res->start;
zx_spdif->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(zx_spdif->reg_base)) {
dev_err(&pdev->dev, "ioremap failed!\n");
return PTR_ERR(zx_spdif->reg_base);
}
zx_spdif_dev_init(zx_spdif->reg_base);
platform_set_drvdata(pdev, zx_spdif);
ret = devm_snd_soc_register_component(&pdev->dev, &zx_spdif_component,
&zx_spdif_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Register DAI failed: %d\n", ret);
return ret;
}
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret)
dev_err(&pdev->dev, "Register platform PCM failed: %d\n", ret);
return ret;
}
