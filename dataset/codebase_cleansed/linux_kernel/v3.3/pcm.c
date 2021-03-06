static void s3c_pcm_snd_txctrl(struct s3c_pcm_info *pcm, int on)
{
void __iomem *regs = pcm->regs;
u32 ctl, clkctl;
clkctl = readl(regs + S3C_PCM_CLKCTL);
ctl = readl(regs + S3C_PCM_CTL);
ctl &= ~(S3C_PCM_CTL_TXDIPSTICK_MASK
<< S3C_PCM_CTL_TXDIPSTICK_SHIFT);
if (on) {
ctl |= S3C_PCM_CTL_TXDMA_EN;
ctl |= S3C_PCM_CTL_TXFIFO_EN;
ctl |= S3C_PCM_CTL_ENABLE;
ctl |= (0x4<<S3C_PCM_CTL_TXDIPSTICK_SHIFT);
clkctl |= S3C_PCM_CLKCTL_SERCLK_EN;
} else {
ctl &= ~S3C_PCM_CTL_TXDMA_EN;
ctl &= ~S3C_PCM_CTL_TXFIFO_EN;
if (!(ctl & S3C_PCM_CTL_RXFIFO_EN)) {
ctl &= ~S3C_PCM_CTL_ENABLE;
if (!pcm->idleclk)
clkctl |= S3C_PCM_CLKCTL_SERCLK_EN;
}
}
writel(clkctl, regs + S3C_PCM_CLKCTL);
writel(ctl, regs + S3C_PCM_CTL);
}
static void s3c_pcm_snd_rxctrl(struct s3c_pcm_info *pcm, int on)
{
void __iomem *regs = pcm->regs;
u32 ctl, clkctl;
ctl = readl(regs + S3C_PCM_CTL);
clkctl = readl(regs + S3C_PCM_CLKCTL);
ctl &= ~(S3C_PCM_CTL_RXDIPSTICK_MASK
<< S3C_PCM_CTL_RXDIPSTICK_SHIFT);
if (on) {
ctl |= S3C_PCM_CTL_RXDMA_EN;
ctl |= S3C_PCM_CTL_RXFIFO_EN;
ctl |= S3C_PCM_CTL_ENABLE;
ctl |= (0x20<<S3C_PCM_CTL_RXDIPSTICK_SHIFT);
clkctl |= S3C_PCM_CLKCTL_SERCLK_EN;
} else {
ctl &= ~S3C_PCM_CTL_RXDMA_EN;
ctl &= ~S3C_PCM_CTL_RXFIFO_EN;
if (!(ctl & S3C_PCM_CTL_TXFIFO_EN)) {
ctl &= ~S3C_PCM_CTL_ENABLE;
if (!pcm->idleclk)
clkctl |= S3C_PCM_CLKCTL_SERCLK_EN;
}
}
writel(clkctl, regs + S3C_PCM_CLKCTL);
writel(ctl, regs + S3C_PCM_CTL);
}
static int s3c_pcm_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct s3c_pcm_info *pcm = snd_soc_dai_get_drvdata(rtd->cpu_dai);
unsigned long flags;
dev_dbg(pcm->dev, "Entered %s\n", __func__);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
spin_lock_irqsave(&pcm->lock, flags);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
s3c_pcm_snd_rxctrl(pcm, 1);
else
s3c_pcm_snd_txctrl(pcm, 1);
spin_unlock_irqrestore(&pcm->lock, flags);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
spin_lock_irqsave(&pcm->lock, flags);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
s3c_pcm_snd_rxctrl(pcm, 0);
else
s3c_pcm_snd_txctrl(pcm, 0);
spin_unlock_irqrestore(&pcm->lock, flags);
break;
default:
return -EINVAL;
}
return 0;
}
static int s3c_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *socdai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct s3c_pcm_info *pcm = snd_soc_dai_get_drvdata(rtd->cpu_dai);
struct s3c_dma_params *dma_data;
void __iomem *regs = pcm->regs;
struct clk *clk;
int sclk_div, sync_div;
unsigned long flags;
u32 clkctl;
dev_dbg(pcm->dev, "Entered %s\n", __func__);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = pcm->dma_playback;
else
dma_data = pcm->dma_capture;
snd_soc_dai_set_dma_data(rtd->cpu_dai, substream, dma_data);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&pcm->lock, flags);
clkctl = readl(regs + S3C_PCM_CLKCTL);
if (clkctl & S3C_PCM_CLKCTL_SERCLKSEL_PCLK)
clk = pcm->pclk;
else
clk = pcm->cclk;
sclk_div = clk_get_rate(clk) / pcm->sclk_per_fs /
params_rate(params) / 2 - 1;
clkctl &= ~(S3C_PCM_CLKCTL_SCLKDIV_MASK
<< S3C_PCM_CLKCTL_SCLKDIV_SHIFT);
clkctl |= ((sclk_div & S3C_PCM_CLKCTL_SCLKDIV_MASK)
<< S3C_PCM_CLKCTL_SCLKDIV_SHIFT);
sync_div = pcm->sclk_per_fs - 1;
clkctl &= ~(S3C_PCM_CLKCTL_SYNCDIV_MASK
<< S3C_PCM_CLKCTL_SYNCDIV_SHIFT);
clkctl |= ((sync_div & S3C_PCM_CLKCTL_SYNCDIV_MASK)
<< S3C_PCM_CLKCTL_SYNCDIV_SHIFT);
writel(clkctl, regs + S3C_PCM_CLKCTL);
spin_unlock_irqrestore(&pcm->lock, flags);
dev_dbg(pcm->dev, "PCMSOURCE_CLK-%lu SCLK=%ufs SCLK_DIV=%d SYNC_DIV=%d\n",
clk_get_rate(clk), pcm->sclk_per_fs,
sclk_div, sync_div);
return 0;
}
static int s3c_pcm_set_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct s3c_pcm_info *pcm = snd_soc_dai_get_drvdata(cpu_dai);
void __iomem *regs = pcm->regs;
unsigned long flags;
int ret = 0;
u32 ctl;
dev_dbg(pcm->dev, "Entered %s\n", __func__);
spin_lock_irqsave(&pcm->lock, flags);
ctl = readl(regs + S3C_PCM_CTL);
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_NF:
break;
default:
dev_err(pcm->dev, "Unsupported clock inversion!\n");
ret = -EINVAL;
goto exit;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
dev_err(pcm->dev, "Unsupported master/slave format!\n");
ret = -EINVAL;
goto exit;
}
switch (fmt & SND_SOC_DAIFMT_CLOCK_MASK) {
case SND_SOC_DAIFMT_CONT:
pcm->idleclk = 1;
break;
case SND_SOC_DAIFMT_GATED:
pcm->idleclk = 0;
break;
default:
dev_err(pcm->dev, "Invalid Clock gating request!\n");
ret = -EINVAL;
goto exit;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
ctl |= S3C_PCM_CTL_TXMSB_AFTER_FSYNC;
ctl |= S3C_PCM_CTL_RXMSB_AFTER_FSYNC;
break;
case SND_SOC_DAIFMT_DSP_B:
ctl &= ~S3C_PCM_CTL_TXMSB_AFTER_FSYNC;
ctl &= ~S3C_PCM_CTL_RXMSB_AFTER_FSYNC;
break;
default:
dev_err(pcm->dev, "Unsupported data format!\n");
ret = -EINVAL;
goto exit;
}
writel(ctl, regs + S3C_PCM_CTL);
exit:
spin_unlock_irqrestore(&pcm->lock, flags);
return ret;
}
static int s3c_pcm_set_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct s3c_pcm_info *pcm = snd_soc_dai_get_drvdata(cpu_dai);
switch (div_id) {
case S3C_PCM_SCLK_PER_FS:
pcm->sclk_per_fs = div;
break;
default:
return -EINVAL;
}
return 0;
}
static int s3c_pcm_set_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct s3c_pcm_info *pcm = snd_soc_dai_get_drvdata(cpu_dai);
void __iomem *regs = pcm->regs;
u32 clkctl = readl(regs + S3C_PCM_CLKCTL);
switch (clk_id) {
case S3C_PCM_CLKSRC_PCLK:
clkctl |= S3C_PCM_CLKCTL_SERCLKSEL_PCLK;
break;
case S3C_PCM_CLKSRC_MUX:
clkctl &= ~S3C_PCM_CLKCTL_SERCLKSEL_PCLK;
if (clk_get_rate(pcm->cclk) != freq)
clk_set_rate(pcm->cclk, freq);
break;
default:
return -EINVAL;
}
writel(clkctl, regs + S3C_PCM_CLKCTL);
return 0;
}
static __devinit int s3c_pcm_dev_probe(struct platform_device *pdev)
{
struct s3c_pcm_info *pcm;
struct resource *mem_res, *dmatx_res, *dmarx_res;
struct s3c_audio_pdata *pcm_pdata;
int ret;
if ((pdev->id < 0) || pdev->id >= ARRAY_SIZE(s3c_pcm)) {
dev_err(&pdev->dev, "id %d out of range\n", pdev->id);
return -EINVAL;
}
pcm_pdata = pdev->dev.platform_data;
dmatx_res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmatx_res) {
dev_err(&pdev->dev, "Unable to get PCM-TX dma resource\n");
return -ENXIO;
}
dmarx_res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!dmarx_res) {
dev_err(&pdev->dev, "Unable to get PCM-RX dma resource\n");
return -ENXIO;
}
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_res) {
dev_err(&pdev->dev, "Unable to get register resource\n");
return -ENXIO;
}
if (pcm_pdata && pcm_pdata->cfg_gpio && pcm_pdata->cfg_gpio(pdev)) {
dev_err(&pdev->dev, "Unable to configure gpio\n");
return -EINVAL;
}
pcm = &s3c_pcm[pdev->id];
pcm->dev = &pdev->dev;
spin_lock_init(&pcm->lock);
pcm->sclk_per_fs = 128;
pcm->cclk = clk_get(&pdev->dev, "audio-bus");
if (IS_ERR(pcm->cclk)) {
dev_err(&pdev->dev, "failed to get audio-bus\n");
ret = PTR_ERR(pcm->cclk);
goto err1;
}
clk_enable(pcm->cclk);
dev_set_drvdata(&pdev->dev, pcm);
if (!request_mem_region(mem_res->start,
resource_size(mem_res), "samsung-pcm")) {
dev_err(&pdev->dev, "Unable to request register region\n");
ret = -EBUSY;
goto err2;
}
pcm->regs = ioremap(mem_res->start, 0x100);
if (pcm->regs == NULL) {
dev_err(&pdev->dev, "cannot ioremap registers\n");
ret = -ENXIO;
goto err3;
}
pcm->pclk = clk_get(&pdev->dev, "pcm");
if (IS_ERR(pcm->pclk)) {
dev_err(&pdev->dev, "failed to get pcm_clock\n");
ret = -ENOENT;
goto err4;
}
clk_enable(pcm->pclk);
s3c_pcm_stereo_in[pdev->id].dma_addr = mem_res->start
+ S3C_PCM_RXFIFO;
s3c_pcm_stereo_out[pdev->id].dma_addr = mem_res->start
+ S3C_PCM_TXFIFO;
s3c_pcm_stereo_in[pdev->id].channel = dmarx_res->start;
s3c_pcm_stereo_out[pdev->id].channel = dmatx_res->start;
pcm->dma_capture = &s3c_pcm_stereo_in[pdev->id];
pcm->dma_playback = &s3c_pcm_stereo_out[pdev->id];
pm_runtime_enable(&pdev->dev);
ret = snd_soc_register_dai(&pdev->dev, &s3c_pcm_dai[pdev->id]);
if (ret != 0) {
dev_err(&pdev->dev, "failed to get register DAI: %d\n", ret);
goto err5;
}
return 0;
err5:
clk_disable(pcm->pclk);
clk_put(pcm->pclk);
err4:
iounmap(pcm->regs);
err3:
release_mem_region(mem_res->start, resource_size(mem_res));
err2:
clk_disable(pcm->cclk);
clk_put(pcm->cclk);
err1:
return ret;
}
static __devexit int s3c_pcm_dev_remove(struct platform_device *pdev)
{
struct s3c_pcm_info *pcm = &s3c_pcm[pdev->id];
struct resource *mem_res;
snd_soc_unregister_dai(&pdev->dev);
pm_runtime_disable(&pdev->dev);
iounmap(pcm->regs);
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem_res->start, resource_size(mem_res));
clk_disable(pcm->cclk);
clk_disable(pcm->pclk);
clk_put(pcm->pclk);
clk_put(pcm->cclk);
return 0;
}
