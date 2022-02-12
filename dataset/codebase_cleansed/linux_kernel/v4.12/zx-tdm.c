static inline u32 zx_tdm_readl(struct zx_tdm_info *tdm, u16 reg)
{
return readl_relaxed(tdm->regbase + reg);
}
static inline void zx_tdm_writel(struct zx_tdm_info *tdm, u16 reg, u32 val)
{
writel_relaxed(val, tdm->regbase + reg);
}
static void zx_tdm_tx_en(struct zx_tdm_info *tdm, bool on)
{
unsigned long val;
val = zx_tdm_readl(tdm, REG_PROCESS_CTRL);
if (on)
val |= PROCESS_TX_EN | PROCESS_TDM_EN;
else
val &= ~(PROCESS_TX_EN | PROCESS_TDM_EN);
zx_tdm_writel(tdm, REG_PROCESS_CTRL, val);
}
static void zx_tdm_rx_en(struct zx_tdm_info *tdm, bool on)
{
unsigned long val;
val = zx_tdm_readl(tdm, REG_PROCESS_CTRL);
if (on)
val |= PROCESS_RX_EN | PROCESS_TDM_EN;
else
val &= ~(PROCESS_RX_EN | PROCESS_TDM_EN);
zx_tdm_writel(tdm, REG_PROCESS_CTRL, val);
}
static void zx_tdm_tx_dma_en(struct zx_tdm_info *tdm, bool on)
{
unsigned long val;
val = zx_tdm_readl(tdm, REG_TX_FIFO_CTRL);
val |= FIFO_CTRL_TX_RST | DEAGULT_FIFO_THRES;
if (on)
val |= FIFO_CTRL_TX_DMA_EN;
else
val &= ~FIFO_CTRL_TX_DMA_EN;
zx_tdm_writel(tdm, REG_TX_FIFO_CTRL, val);
}
static void zx_tdm_rx_dma_en(struct zx_tdm_info *tdm, bool on)
{
unsigned long val;
val = zx_tdm_readl(tdm, REG_RX_FIFO_CTRL);
val |= FIFO_CTRL_RX_RST | DEAGULT_FIFO_THRES;
if (on)
val |= FIFO_CTRL_RX_DMA_EN;
else
val &= ~FIFO_CTRL_RX_DMA_EN;
zx_tdm_writel(tdm, REG_RX_FIFO_CTRL, val);
}
static int zx_tdm_dai_probe(struct snd_soc_dai *dai)
{
struct zx_tdm_info *zx_tdm = dev_get_drvdata(dai->dev);
snd_soc_dai_set_drvdata(dai, zx_tdm);
zx_tdm->dma_playback.addr = zx_tdm->phy_addr + REG_DATABUF;
zx_tdm->dma_playback.maxburst = 16;
zx_tdm->dma_capture.addr = zx_tdm->phy_addr + REG_DATABUF;
zx_tdm->dma_capture.maxburst = 16;
snd_soc_dai_init_dma_data(dai, &zx_tdm->dma_playback,
&zx_tdm->dma_capture);
return 0;
}
static int zx_tdm_set_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct zx_tdm_info *tdm = snd_soc_dai_get_drvdata(cpu_dai);
unsigned long val;
val = zx_tdm_readl(tdm, REG_TIMING_CTRL);
val &= ~(TIMING_SYNC_WIDTH_MASK | TIMING_MS_MASK);
val |= TIMING_DEFAULT_WIDTH << TIMING_WIDTH_SHIFT;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
tdm->master = 1;
val |= TIMING_MASTER_MODE;
break;
case SND_SOC_DAIFMT_CBS_CFS:
tdm->master = 0;
val &= ~TIMING_MASTER_MODE;
break;
default:
dev_err(cpu_dai->dev, "Unknown master/slave format\n");
return -EINVAL;
}
zx_tdm_writel(tdm, REG_TIMING_CTRL, val);
return 0;
}
static int zx_tdm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *socdai)
{
struct zx_tdm_info *tdm = snd_soc_dai_get_drvdata(socdai);
struct snd_dmaengine_dai_dma_data *dma_data;
unsigned int ts_width = TIMING_DEFAULT_WIDTH;
unsigned int ch_num = 32;
unsigned int mask = 0;
unsigned int ret = 0;
unsigned long val;
dma_data = snd_soc_dai_get_dma_data(socdai, substream);
dma_data->addr_width = ch_num >> 3;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_MU_LAW:
case SNDRV_PCM_FORMAT_A_LAW:
case SNDRV_PCM_FORMAT_S16_LE:
ts_width = 1;
break;
default:
ts_width = 0;
dev_err(socdai->dev, "Unknown data format\n");
return -EINVAL;
}
val = zx_tdm_readl(tdm, REG_TIMING_CTRL);
val |= TIMING_TS_WIDTH(ts_width) | TIMING_TS_NUM(1);
zx_tdm_writel(tdm, REG_TIMING_CTRL, val);
zx_tdm_writel(tdm, REG_TS_MASK0, mask);
if (tdm->master)
ret = clk_set_rate(tdm->dai_wclk,
params_rate(params) * TIMING_WIDTH_FACTOR * ch_num);
return ret;
}
static int zx_tdm_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
int capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
struct zx_tdm_info *zx_tdm = dev_get_drvdata(dai->dev);
unsigned int val;
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
if (capture) {
val = zx_tdm_readl(zx_tdm, REG_RX_FIFO_CTRL);
val |= FIFOCTRL_RX_FIFO_RST;
zx_tdm_writel(zx_tdm, REG_RX_FIFO_CTRL, val);
zx_tdm_rx_dma_en(zx_tdm, true);
} else {
val = zx_tdm_readl(zx_tdm, REG_TX_FIFO_CTRL);
val |= FIFOCTRL_TX_FIFO_RST;
zx_tdm_writel(zx_tdm, REG_TX_FIFO_CTRL, val);
zx_tdm_tx_dma_en(zx_tdm, true);
}
break;
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (capture)
zx_tdm_rx_en(zx_tdm, true);
else
zx_tdm_tx_en(zx_tdm, true);
break;
case SNDRV_PCM_TRIGGER_STOP:
if (capture)
zx_tdm_rx_dma_en(zx_tdm, false);
else
zx_tdm_tx_dma_en(zx_tdm, false);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (capture)
zx_tdm_rx_en(zx_tdm, false);
else
zx_tdm_tx_en(zx_tdm, false);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int zx_tdm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct zx_tdm_info *zx_tdm = dev_get_drvdata(dai->dev);
int ret;
ret = clk_prepare_enable(zx_tdm->dai_wclk);
if (ret)
return ret;
ret = clk_prepare_enable(zx_tdm->dai_pclk);
if (ret) {
clk_disable_unprepare(zx_tdm->dai_wclk);
return ret;
}
return 0;
}
static void zx_tdm_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct zx_tdm_info *zx_tdm = dev_get_drvdata(dai->dev);
clk_disable_unprepare(zx_tdm->dai_pclk);
clk_disable_unprepare(zx_tdm->dai_wclk);
}
static void zx_tdm_init_state(struct zx_tdm_info *tdm)
{
unsigned int val;
zx_tdm_writel(tdm, REG_PROCESS_CTRL, PROCESS_DISABLE_ALL);
val = zx_tdm_readl(tdm, REG_TIMING_CTRL);
val |= TIMING_LSB_FIRST;
val &= ~TIMING_CLK_SEL_MASK;
val |= TIMING_CLK_SEL_DEF;
zx_tdm_writel(tdm, REG_TIMING_CTRL, val);
zx_tdm_writel(tdm, REG_INT_EN, INT_DISABLE_ALL);
zx_tdm_writel(tdm, REG_INT_STATUS, INT_STATUS_MASK);
zx_tdm_writel(tdm, REG_RX_FIFO_CTRL, FIFOCTRL_RX_FIFO_RST);
zx_tdm_writel(tdm, REG_TX_FIFO_CTRL, FIFOCTRL_TX_FIFO_RST);
val = zx_tdm_readl(tdm, REG_RX_FIFO_CTRL);
val &= ~(RXTH_MASK | RX_FIFO_RST_MASK);
val |= FIFOCTRL_THRESHOLD(8);
zx_tdm_writel(tdm, REG_RX_FIFO_CTRL, val);
val = zx_tdm_readl(tdm, REG_TX_FIFO_CTRL);
val &= ~(TXTH_MASK | TX_FIFO_RST_MASK);
val |= FIFOCTRL_THRESHOLD(8);
zx_tdm_writel(tdm, REG_TX_FIFO_CTRL, val);
}
static int zx_tdm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct of_phandle_args out_args;
unsigned int dma_reg_offset;
struct zx_tdm_info *zx_tdm;
unsigned int dma_mask;
struct resource *res;
struct regmap *regmap_sysctrl;
int ret;
zx_tdm = devm_kzalloc(&pdev->dev, sizeof(*zx_tdm), GFP_KERNEL);
if (!zx_tdm)
return -ENOMEM;
zx_tdm->dev = dev;
zx_tdm->dai_wclk = devm_clk_get(&pdev->dev, "wclk");
if (IS_ERR(zx_tdm->dai_wclk)) {
dev_err(&pdev->dev, "Fail to get wclk\n");
return PTR_ERR(zx_tdm->dai_wclk);
}
zx_tdm->dai_pclk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(zx_tdm->dai_pclk)) {
dev_err(&pdev->dev, "Fail to get pclk\n");
return PTR_ERR(zx_tdm->dai_pclk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
zx_tdm->phy_addr = res->start;
zx_tdm->regbase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(zx_tdm->regbase))
return PTR_ERR(zx_tdm->regbase);
ret = of_parse_phandle_with_fixed_args(pdev->dev.of_node,
"zte,tdm-dma-sysctrl", 2, 0, &out_args);
if (ret) {
dev_err(&pdev->dev, "Fail to get zte,tdm-dma-sysctrl\n");
return ret;
}
dma_reg_offset = out_args.args[0];
dma_mask = out_args.args[1];
regmap_sysctrl = syscon_node_to_regmap(out_args.np);
if (IS_ERR(regmap_sysctrl)) {
of_node_put(out_args.np);
return PTR_ERR(regmap_sysctrl);
}
regmap_update_bits(regmap_sysctrl, dma_reg_offset, dma_mask, dma_mask);
of_node_put(out_args.np);
zx_tdm_init_state(zx_tdm);
platform_set_drvdata(pdev, zx_tdm);
ret = devm_snd_soc_register_component(&pdev->dev, &zx_tdm_component,
&zx_tdm_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Register DAI failed: %d\n", ret);
return ret;
}
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret)
dev_err(&pdev->dev, "Register platform PCM failed: %d\n", ret);
return ret;
}
