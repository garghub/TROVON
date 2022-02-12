static int mxs_saif_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct mxs_saif *saif = snd_soc_dai_get_drvdata(cpu_dai);
switch (clk_id) {
case MXS_SAIF_MCLK:
saif->mclk = freq;
break;
default:
return -EINVAL;
}
return 0;
}
static inline struct mxs_saif *mxs_saif_get_master(struct mxs_saif * saif)
{
return mxs_saif[saif->master_id];
}
static int mxs_saif_set_clk(struct mxs_saif *saif,
unsigned int mclk,
unsigned int rate)
{
u32 scr;
int ret;
struct mxs_saif *master_saif;
dev_dbg(saif->dev, "mclk %d rate %d\n", mclk, rate);
master_saif = mxs_saif_get_master(saif);
if (!master_saif)
return -EINVAL;
dev_dbg(saif->dev, "master saif%d\n", master_saif->id);
if (master_saif->ongoing && rate != master_saif->cur_rate) {
dev_err(saif->dev,
"can not change clock, master saif%d(rate %d) is ongoing\n",
master_saif->id, master_saif->cur_rate);
return -EINVAL;
}
scr = __raw_readl(master_saif->base + SAIF_CTRL);
scr &= ~BM_SAIF_CTRL_BITCLK_MULT_RATE;
scr &= ~BM_SAIF_CTRL_BITCLK_BASE_RATE;
clk_prepare_enable(master_saif->clk);
if (master_saif->mclk_in_use) {
if (mclk % 32 == 0) {
scr &= ~BM_SAIF_CTRL_BITCLK_BASE_RATE;
ret = clk_set_rate(master_saif->clk, 512 * rate);
} else if (mclk % 48 == 0) {
scr |= BM_SAIF_CTRL_BITCLK_BASE_RATE;
ret = clk_set_rate(master_saif->clk, 384 * rate);
} else {
clk_disable_unprepare(master_saif->clk);
return -EINVAL;
}
} else {
ret = clk_set_rate(master_saif->clk, 512 * rate);
scr &= ~BM_SAIF_CTRL_BITCLK_BASE_RATE;
}
clk_disable_unprepare(master_saif->clk);
if (ret)
return ret;
master_saif->cur_rate = rate;
if (!master_saif->mclk_in_use) {
__raw_writel(scr, master_saif->base + SAIF_CTRL);
return 0;
}
switch (mclk / rate) {
case 32:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(4);
break;
case 64:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(3);
break;
case 128:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(2);
break;
case 256:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(1);
break;
case 512:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(0);
break;
case 48:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(3);
break;
case 96:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(2);
break;
case 192:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(1);
break;
case 384:
scr |= BF_SAIF_CTRL_BITCLK_MULT_RATE(0);
break;
default:
return -EINVAL;
}
__raw_writel(scr, master_saif->base + SAIF_CTRL);
return 0;
}
int mxs_saif_put_mclk(unsigned int saif_id)
{
struct mxs_saif *saif = mxs_saif[saif_id];
u32 stat;
if (!saif)
return -EINVAL;
stat = __raw_readl(saif->base + SAIF_STAT);
if (stat & BM_SAIF_STAT_BUSY) {
dev_err(saif->dev, "error: busy\n");
return -EBUSY;
}
clk_disable_unprepare(saif->clk);
__raw_writel(BM_SAIF_CTRL_CLKGATE,
saif->base + SAIF_CTRL + MXS_SET_ADDR);
__raw_writel(BM_SAIF_CTRL_RUN,
saif->base + SAIF_CTRL + MXS_CLR_ADDR);
saif->mclk_in_use = 0;
return 0;
}
int mxs_saif_get_mclk(unsigned int saif_id, unsigned int mclk,
unsigned int rate)
{
struct mxs_saif *saif = mxs_saif[saif_id];
u32 stat;
int ret;
struct mxs_saif *master_saif;
if (!saif)
return -EINVAL;
__raw_writel(BM_SAIF_CTRL_SFTRST,
saif->base + SAIF_CTRL + MXS_CLR_ADDR);
__raw_writel(BM_SAIF_CTRL_CLKGATE,
saif->base + SAIF_CTRL + MXS_CLR_ADDR);
master_saif = mxs_saif_get_master(saif);
if (saif != master_saif) {
dev_err(saif->dev, "can not get mclk from a non-master saif\n");
return -EINVAL;
}
stat = __raw_readl(saif->base + SAIF_STAT);
if (stat & BM_SAIF_STAT_BUSY) {
dev_err(saif->dev, "error: busy\n");
return -EBUSY;
}
saif->mclk_in_use = 1;
ret = mxs_saif_set_clk(saif, mclk, rate);
if (ret)
return ret;
ret = clk_prepare_enable(saif->clk);
if (ret)
return ret;
__raw_writel(BM_SAIF_CTRL_RUN,
saif->base + SAIF_CTRL + MXS_SET_ADDR);
return 0;
}
static int mxs_saif_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
u32 scr, stat;
u32 scr0;
struct mxs_saif *saif = snd_soc_dai_get_drvdata(cpu_dai);
stat = __raw_readl(saif->base + SAIF_STAT);
if (stat & BM_SAIF_STAT_BUSY) {
dev_err(cpu_dai->dev, "error: busy\n");
return -EBUSY;
}
scr0 = __raw_readl(saif->base + SAIF_CTRL);
scr0 = scr0 & ~BM_SAIF_CTRL_BITCLK_EDGE & ~BM_SAIF_CTRL_LRCLK_POLARITY \
& ~BM_SAIF_CTRL_JUSTIFY & ~BM_SAIF_CTRL_DELAY;
scr = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
scr |= BM_SAIF_CTRL_DELAY;
scr &= ~BM_SAIF_CTRL_LRCLK_POLARITY;
break;
case SND_SOC_DAIFMT_LEFT_J:
scr &= ~BM_SAIF_CTRL_DELAY;
scr &= ~BM_SAIF_CTRL_LRCLK_POLARITY;
scr &= ~BM_SAIF_CTRL_JUSTIFY;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
scr |= BM_SAIF_CTRL_BITCLK_EDGE;
scr |= BM_SAIF_CTRL_LRCLK_POLARITY;
break;
case SND_SOC_DAIFMT_IB_NF:
scr |= BM_SAIF_CTRL_BITCLK_EDGE;
scr &= ~BM_SAIF_CTRL_LRCLK_POLARITY;
break;
case SND_SOC_DAIFMT_NB_IF:
scr &= ~BM_SAIF_CTRL_BITCLK_EDGE;
scr |= BM_SAIF_CTRL_LRCLK_POLARITY;
break;
case SND_SOC_DAIFMT_NB_NF:
scr &= ~BM_SAIF_CTRL_BITCLK_EDGE;
scr &= ~BM_SAIF_CTRL_LRCLK_POLARITY;
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
if (saif->id == saif->master_id)
scr &= ~BM_SAIF_CTRL_SLAVE_MODE;
else
scr |= BM_SAIF_CTRL_SLAVE_MODE;
__raw_writel(scr | scr0, saif->base + SAIF_CTRL);
break;
default:
return -EINVAL;
}
return 0;
}
static int mxs_saif_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct mxs_saif *saif = snd_soc_dai_get_drvdata(cpu_dai);
snd_soc_dai_set_dma_data(cpu_dai, substream, &saif->dma_param);
saif->fifo_underrun = 0;
saif->fifo_overrun = 0;
__raw_writel(BM_SAIF_CTRL_SFTRST,
saif->base + SAIF_CTRL + MXS_CLR_ADDR);
__raw_writel(BM_SAIF_CTRL_CLKGATE,
saif->base + SAIF_CTRL + MXS_CLR_ADDR);
return 0;
}
static int mxs_saif_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct mxs_saif *saif = snd_soc_dai_get_drvdata(cpu_dai);
struct mxs_saif *master_saif;
u32 scr, stat;
int ret;
master_saif = mxs_saif_get_master(saif);
if (!master_saif)
return -EINVAL;
if (!saif->mclk && saif->mclk_in_use) {
dev_err(cpu_dai->dev, "set mclk first\n");
return -EINVAL;
}
stat = __raw_readl(saif->base + SAIF_STAT);
if (stat & BM_SAIF_STAT_BUSY) {
dev_err(cpu_dai->dev, "error: busy\n");
return -EBUSY;
}
ret = mxs_saif_set_clk(saif, saif->mclk, params_rate(params));
if (ret) {
dev_err(cpu_dai->dev, "unable to get proper clk\n");
return ret;
}
clk_prepare(saif->clk);
if (saif != master_saif) {
clk_enable(saif->clk);
ret = clk_set_rate(saif->clk, 24000000);
clk_disable(saif->clk);
if (ret)
return ret;
clk_prepare(master_saif->clk);
}
scr = __raw_readl(saif->base + SAIF_CTRL);
scr &= ~BM_SAIF_CTRL_WORD_LENGTH;
scr &= ~BM_SAIF_CTRL_BITCLK_48XFS_ENABLE;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
scr |= BF_SAIF_CTRL_WORD_LENGTH(0);
break;
case SNDRV_PCM_FORMAT_S20_3LE:
scr |= BF_SAIF_CTRL_WORD_LENGTH(4);
scr |= BM_SAIF_CTRL_BITCLK_48XFS_ENABLE;
break;
case SNDRV_PCM_FORMAT_S24_LE:
scr |= BF_SAIF_CTRL_WORD_LENGTH(8);
scr |= BM_SAIF_CTRL_BITCLK_48XFS_ENABLE;
break;
default:
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
scr &= ~BM_SAIF_CTRL_READ_MODE;
} else {
scr |= BM_SAIF_CTRL_READ_MODE;
}
__raw_writel(scr, saif->base + SAIF_CTRL);
return 0;
}
static int mxs_saif_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct mxs_saif *saif = snd_soc_dai_get_drvdata(cpu_dai);
__raw_writel(BM_SAIF_CTRL_FIFO_ERROR_IRQ_EN,
saif->base + SAIF_CTRL + MXS_SET_ADDR);
return 0;
}
static int mxs_saif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct mxs_saif *saif = snd_soc_dai_get_drvdata(cpu_dai);
struct mxs_saif *master_saif;
u32 delay;
master_saif = mxs_saif_get_master(saif);
if (!master_saif)
return -EINVAL;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
dev_dbg(cpu_dai->dev, "start\n");
clk_enable(master_saif->clk);
if (!master_saif->mclk_in_use)
__raw_writel(BM_SAIF_CTRL_RUN,
master_saif->base + SAIF_CTRL + MXS_SET_ADDR);
if (saif != master_saif) {
clk_enable(saif->clk);
__raw_writel(BM_SAIF_CTRL_RUN,
saif->base + SAIF_CTRL + MXS_SET_ADDR);
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
__raw_writel(0, saif->base + SAIF_DATA);
__raw_writel(0, saif->base + SAIF_DATA);
} else {
__raw_readl(saif->base + SAIF_DATA);
__raw_readl(saif->base + SAIF_DATA);
}
master_saif->ongoing = 1;
dev_dbg(saif->dev, "CTRL 0x%x STAT 0x%x\n",
__raw_readl(saif->base + SAIF_CTRL),
__raw_readl(saif->base + SAIF_STAT));
dev_dbg(master_saif->dev, "CTRL 0x%x STAT 0x%x\n",
__raw_readl(master_saif->base + SAIF_CTRL),
__raw_readl(master_saif->base + SAIF_STAT));
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
dev_dbg(cpu_dai->dev, "stop\n");
delay = USEC_PER_SEC / master_saif->cur_rate;
if (!master_saif->mclk_in_use) {
__raw_writel(BM_SAIF_CTRL_RUN,
master_saif->base + SAIF_CTRL + MXS_CLR_ADDR);
udelay(delay);
}
clk_disable(master_saif->clk);
if (saif != master_saif) {
__raw_writel(BM_SAIF_CTRL_RUN,
saif->base + SAIF_CTRL + MXS_CLR_ADDR);
udelay(delay);
clk_disable(saif->clk);
}
master_saif->ongoing = 0;
break;
default:
return -EINVAL;
}
return 0;
}
static int mxs_saif_dai_probe(struct snd_soc_dai *dai)
{
struct mxs_saif *saif = dev_get_drvdata(dai->dev);
snd_soc_dai_set_drvdata(dai, saif);
return 0;
}
static irqreturn_t mxs_saif_irq(int irq, void *dev_id)
{
struct mxs_saif *saif = dev_id;
unsigned int stat;
stat = __raw_readl(saif->base + SAIF_STAT);
if (!(stat & (BM_SAIF_STAT_FIFO_UNDERFLOW_IRQ |
BM_SAIF_STAT_FIFO_OVERFLOW_IRQ)))
return IRQ_NONE;
if (stat & BM_SAIF_STAT_FIFO_UNDERFLOW_IRQ) {
dev_dbg(saif->dev, "underrun!!! %d\n", ++saif->fifo_underrun);
__raw_writel(BM_SAIF_STAT_FIFO_UNDERFLOW_IRQ,
saif->base + SAIF_STAT + MXS_CLR_ADDR);
}
if (stat & BM_SAIF_STAT_FIFO_OVERFLOW_IRQ) {
dev_dbg(saif->dev, "overrun!!! %d\n", ++saif->fifo_overrun);
__raw_writel(BM_SAIF_STAT_FIFO_OVERFLOW_IRQ,
saif->base + SAIF_STAT + MXS_CLR_ADDR);
}
dev_dbg(saif->dev, "SAIF_CTRL %x SAIF_STAT %x\n",
__raw_readl(saif->base + SAIF_CTRL),
__raw_readl(saif->base + SAIF_STAT));
return IRQ_HANDLED;
}
static int mxs_saif_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *iores, *dmares;
struct mxs_saif *saif;
struct pinctrl *pinctrl;
int ret = 0;
struct device_node *master;
if (!np)
return -EINVAL;
saif = devm_kzalloc(&pdev->dev, sizeof(*saif), GFP_KERNEL);
if (!saif)
return -ENOMEM;
ret = of_alias_get_id(np, "saif");
if (ret < 0)
return ret;
else
saif->id = ret;
master = of_parse_phandle(np, "fsl,saif-master", 0);
if (!master) {
saif->master_id = saif->id;
} else {
ret = of_alias_get_id(master, "saif");
if (ret < 0)
return ret;
else
saif->master_id = ret;
}
if (saif->master_id >= ARRAY_SIZE(mxs_saif)) {
dev_err(&pdev->dev, "get wrong master id\n");
return -EINVAL;
}
mxs_saif[saif->id] = saif;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
ret = PTR_ERR(pinctrl);
return ret;
}
saif->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(saif->clk)) {
ret = PTR_ERR(saif->clk);
dev_err(&pdev->dev, "Cannot get the clock: %d\n",
ret);
return ret;
}
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
saif->base = devm_ioremap_resource(&pdev->dev, iores);
if (IS_ERR(saif->base))
return PTR_ERR(saif->base);
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmares) {
ret = of_property_read_u32(np, "fsl,saif-dma-channel",
&saif->dma_param.chan_num);
if (ret) {
dev_err(&pdev->dev, "failed to get dma channel\n");
return ret;
}
} else {
saif->dma_param.chan_num = dmares->start;
}
saif->irq = platform_get_irq(pdev, 0);
if (saif->irq < 0) {
ret = saif->irq;
dev_err(&pdev->dev, "failed to get irq resource: %d\n",
ret);
return ret;
}
saif->dev = &pdev->dev;
ret = devm_request_irq(&pdev->dev, saif->irq, mxs_saif_irq, 0,
"mxs-saif", saif);
if (ret) {
dev_err(&pdev->dev, "failed to request irq\n");
return ret;
}
saif->dma_param.chan_irq = platform_get_irq(pdev, 1);
if (saif->dma_param.chan_irq < 0) {
ret = saif->dma_param.chan_irq;
dev_err(&pdev->dev, "failed to get dma irq resource: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, saif);
ret = snd_soc_register_dai(&pdev->dev, &mxs_saif_dai);
if (ret) {
dev_err(&pdev->dev, "register DAI failed\n");
return ret;
}
ret = mxs_pcm_platform_register(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "register PCM failed: %d\n", ret);
goto failed_pdev_alloc;
}
return 0;
failed_pdev_alloc:
snd_soc_unregister_dai(&pdev->dev);
return ret;
}
static int mxs_saif_remove(struct platform_device *pdev)
{
mxs_pcm_platform_unregister(&pdev->dev);
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
