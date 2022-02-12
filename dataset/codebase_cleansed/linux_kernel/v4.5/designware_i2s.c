static inline void i2s_write_reg(void __iomem *io_base, int reg, u32 val)
{
writel(val, io_base + reg);
}
static inline u32 i2s_read_reg(void __iomem *io_base, int reg)
{
return readl(io_base + reg);
}
static inline void i2s_disable_channels(struct dw_i2s_dev *dev, u32 stream)
{
u32 i = 0;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
for (i = 0; i < 4; i++)
i2s_write_reg(dev->i2s_base, TER(i), 0);
} else {
for (i = 0; i < 4; i++)
i2s_write_reg(dev->i2s_base, RER(i), 0);
}
}
static inline void i2s_clear_irqs(struct dw_i2s_dev *dev, u32 stream)
{
u32 i = 0;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
for (i = 0; i < 4; i++)
i2s_read_reg(dev->i2s_base, TOR(i));
} else {
for (i = 0; i < 4; i++)
i2s_read_reg(dev->i2s_base, ROR(i));
}
}
static void i2s_start(struct dw_i2s_dev *dev,
struct snd_pcm_substream *substream)
{
u32 i, irq;
i2s_write_reg(dev->i2s_base, IER, 1);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
for (i = 0; i < 4; i++) {
irq = i2s_read_reg(dev->i2s_base, IMR(i));
i2s_write_reg(dev->i2s_base, IMR(i), irq & ~0x30);
}
i2s_write_reg(dev->i2s_base, ITER, 1);
} else {
for (i = 0; i < 4; i++) {
irq = i2s_read_reg(dev->i2s_base, IMR(i));
i2s_write_reg(dev->i2s_base, IMR(i), irq & ~0x03);
}
i2s_write_reg(dev->i2s_base, IRER, 1);
}
i2s_write_reg(dev->i2s_base, CER, 1);
}
static void i2s_stop(struct dw_i2s_dev *dev,
struct snd_pcm_substream *substream)
{
u32 i = 0, irq;
i2s_clear_irqs(dev, substream->stream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
i2s_write_reg(dev->i2s_base, ITER, 0);
for (i = 0; i < 4; i++) {
irq = i2s_read_reg(dev->i2s_base, IMR(i));
i2s_write_reg(dev->i2s_base, IMR(i), irq | 0x30);
}
} else {
i2s_write_reg(dev->i2s_base, IRER, 0);
for (i = 0; i < 4; i++) {
irq = i2s_read_reg(dev->i2s_base, IMR(i));
i2s_write_reg(dev->i2s_base, IMR(i), irq | 0x03);
}
}
if (!dev->active) {
i2s_write_reg(dev->i2s_base, CER, 0);
i2s_write_reg(dev->i2s_base, IER, 0);
}
}
static int dw_i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
union dw_i2s_snd_dma_data *dma_data = NULL;
if (!(dev->capability & DWC_I2S_RECORD) &&
(substream->stream == SNDRV_PCM_STREAM_CAPTURE))
return -EINVAL;
if (!(dev->capability & DWC_I2S_PLAY) &&
(substream->stream == SNDRV_PCM_STREAM_PLAYBACK))
return -EINVAL;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
dma_data = &dev->play_dma_data;
else if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
dma_data = &dev->capture_dma_data;
snd_soc_dai_set_dma_data(cpu_dai, substream, (void *)dma_data);
return 0;
}
static void dw_i2s_config(struct dw_i2s_dev *dev, int stream)
{
u32 ch_reg, irq;
struct i2s_clk_config_data *config = &dev->config;
i2s_disable_channels(dev, stream);
for (ch_reg = 0; ch_reg < (config->chan_nr / 2); ch_reg++) {
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
i2s_write_reg(dev->i2s_base, TCR(ch_reg),
dev->xfer_resolution);
i2s_write_reg(dev->i2s_base, TFCR(ch_reg), 0x02);
irq = i2s_read_reg(dev->i2s_base, IMR(ch_reg));
i2s_write_reg(dev->i2s_base, IMR(ch_reg), irq & ~0x30);
i2s_write_reg(dev->i2s_base, TER(ch_reg), 1);
} else {
i2s_write_reg(dev->i2s_base, RCR(ch_reg),
dev->xfer_resolution);
i2s_write_reg(dev->i2s_base, RFCR(ch_reg), 0x07);
irq = i2s_read_reg(dev->i2s_base, IMR(ch_reg));
i2s_write_reg(dev->i2s_base, IMR(ch_reg), irq & ~0x03);
i2s_write_reg(dev->i2s_base, RER(ch_reg), 1);
}
}
}
static int dw_i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
struct i2s_clk_config_data *config = &dev->config;
int ret;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
config->data_width = 16;
dev->ccr = 0x00;
dev->xfer_resolution = 0x02;
break;
case SNDRV_PCM_FORMAT_S24_LE:
config->data_width = 24;
dev->ccr = 0x08;
dev->xfer_resolution = 0x04;
break;
case SNDRV_PCM_FORMAT_S32_LE:
config->data_width = 32;
dev->ccr = 0x10;
dev->xfer_resolution = 0x05;
break;
default:
dev_err(dev->dev, "designware-i2s: unsuppted PCM fmt");
return -EINVAL;
}
config->chan_nr = params_channels(params);
switch (config->chan_nr) {
case EIGHT_CHANNEL_SUPPORT:
case SIX_CHANNEL_SUPPORT:
case FOUR_CHANNEL_SUPPORT:
case TWO_CHANNEL_SUPPORT:
break;
default:
dev_err(dev->dev, "channel not supported\n");
return -EINVAL;
}
dw_i2s_config(dev, substream->stream);
i2s_write_reg(dev->i2s_base, CCR, dev->ccr);
config->sample_rate = params_rate(params);
if (dev->capability & DW_I2S_MASTER) {
if (dev->i2s_clk_cfg) {
ret = dev->i2s_clk_cfg(config);
if (ret < 0) {
dev_err(dev->dev, "runtime audio clk config fail\n");
return ret;
}
} else {
u32 bitclk = config->sample_rate *
config->data_width * 2;
ret = clk_set_rate(dev->clk, bitclk);
if (ret) {
dev_err(dev->dev, "Can't set I2S clock rate: %d\n",
ret);
return ret;
}
}
}
return 0;
}
static void dw_i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
snd_soc_dai_set_dma_data(dai, substream, NULL);
}
static int dw_i2s_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
i2s_write_reg(dev->i2s_base, TXFFR, 1);
else
i2s_write_reg(dev->i2s_base, RXFFR, 1);
return 0;
}
static int dw_i2s_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
dev->active++;
i2s_start(dev, substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
dev->active--;
i2s_stop(dev, substream);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int dw_i2s_set_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
int ret = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
if (dev->capability & DW_I2S_SLAVE)
ret = 0;
else
ret = -EINVAL;
break;
case SND_SOC_DAIFMT_CBS_CFS:
if (dev->capability & DW_I2S_MASTER)
ret = 0;
else
ret = -EINVAL;
break;
case SND_SOC_DAIFMT_CBM_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
ret = -EINVAL;
break;
default:
dev_dbg(dev->dev, "dwc : Invalid master/slave format\n");
ret = -EINVAL;
break;
}
return ret;
}
static int dw_i2s_runtime_suspend(struct device *dev)
{
struct dw_i2s_dev *dw_dev = dev_get_drvdata(dev);
if (dw_dev->capability & DW_I2S_MASTER)
clk_disable(dw_dev->clk);
return 0;
}
static int dw_i2s_runtime_resume(struct device *dev)
{
struct dw_i2s_dev *dw_dev = dev_get_drvdata(dev);
if (dw_dev->capability & DW_I2S_MASTER)
clk_enable(dw_dev->clk);
return 0;
}
static int dw_i2s_suspend(struct snd_soc_dai *dai)
{
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
if (dev->capability & DW_I2S_MASTER)
clk_disable(dev->clk);
return 0;
}
static int dw_i2s_resume(struct snd_soc_dai *dai)
{
struct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);
if (dev->capability & DW_I2S_MASTER)
clk_enable(dev->clk);
if (dai->playback_active)
dw_i2s_config(dev, SNDRV_PCM_STREAM_PLAYBACK);
if (dai->capture_active)
dw_i2s_config(dev, SNDRV_PCM_STREAM_CAPTURE);
return 0;
}
static int dw_configure_dai(struct dw_i2s_dev *dev,
struct snd_soc_dai_driver *dw_i2s_dai,
unsigned int rates)
{
u32 comp1 = i2s_read_reg(dev->i2s_base, dev->i2s_reg_comp1);
u32 comp2 = i2s_read_reg(dev->i2s_base, dev->i2s_reg_comp2);
u32 idx;
if (dev->capability & DWC_I2S_RECORD &&
dev->quirks & DW_I2S_QUIRK_COMP_PARAM1)
comp1 = comp1 & ~BIT(5);
if (COMP1_TX_ENABLED(comp1)) {
dev_dbg(dev->dev, " designware: play supported\n");
idx = COMP1_TX_WORDSIZE_0(comp1);
if (WARN_ON(idx >= ARRAY_SIZE(formats)))
return -EINVAL;
dw_i2s_dai->playback.channels_min = MIN_CHANNEL_NUM;
dw_i2s_dai->playback.channels_max =
1 << (COMP1_TX_CHANNELS(comp1) + 1);
dw_i2s_dai->playback.formats = formats[idx];
dw_i2s_dai->playback.rates = rates;
}
if (COMP1_RX_ENABLED(comp1)) {
dev_dbg(dev->dev, "designware: record supported\n");
idx = COMP2_RX_WORDSIZE_0(comp2);
if (WARN_ON(idx >= ARRAY_SIZE(formats)))
return -EINVAL;
dw_i2s_dai->capture.channels_min = MIN_CHANNEL_NUM;
dw_i2s_dai->capture.channels_max =
1 << (COMP1_RX_CHANNELS(comp1) + 1);
dw_i2s_dai->capture.formats = formats[idx];
dw_i2s_dai->capture.rates = rates;
}
if (COMP1_MODE_EN(comp1)) {
dev_dbg(dev->dev, "designware: i2s master mode supported\n");
dev->capability |= DW_I2S_MASTER;
} else {
dev_dbg(dev->dev, "designware: i2s slave mode supported\n");
dev->capability |= DW_I2S_SLAVE;
}
return 0;
}
static int dw_configure_dai_by_pd(struct dw_i2s_dev *dev,
struct snd_soc_dai_driver *dw_i2s_dai,
struct resource *res,
const struct i2s_platform_data *pdata)
{
u32 comp1 = i2s_read_reg(dev->i2s_base, dev->i2s_reg_comp1);
u32 idx = COMP1_APB_DATA_WIDTH(comp1);
int ret;
if (WARN_ON(idx >= ARRAY_SIZE(bus_widths)))
return -EINVAL;
ret = dw_configure_dai(dev, dw_i2s_dai, pdata->snd_rates);
if (ret < 0)
return ret;
dev->play_dma_data.pd.data = pdata->play_dma_data;
dev->capture_dma_data.pd.data = pdata->capture_dma_data;
dev->play_dma_data.pd.addr = res->start + I2S_TXDMA;
dev->capture_dma_data.pd.addr = res->start + I2S_RXDMA;
dev->play_dma_data.pd.max_burst = 16;
dev->capture_dma_data.pd.max_burst = 16;
dev->play_dma_data.pd.addr_width = bus_widths[idx];
dev->capture_dma_data.pd.addr_width = bus_widths[idx];
dev->play_dma_data.pd.filter = pdata->filter;
dev->capture_dma_data.pd.filter = pdata->filter;
return 0;
}
static int dw_configure_dai_by_dt(struct dw_i2s_dev *dev,
struct snd_soc_dai_driver *dw_i2s_dai,
struct resource *res)
{
u32 comp1 = i2s_read_reg(dev->i2s_base, I2S_COMP_PARAM_1);
u32 comp2 = i2s_read_reg(dev->i2s_base, I2S_COMP_PARAM_2);
u32 fifo_depth = 1 << (1 + COMP1_FIFO_DEPTH_GLOBAL(comp1));
u32 idx = COMP1_APB_DATA_WIDTH(comp1);
u32 idx2;
int ret;
if (WARN_ON(idx >= ARRAY_SIZE(bus_widths)))
return -EINVAL;
ret = dw_configure_dai(dev, dw_i2s_dai, SNDRV_PCM_RATE_8000_192000);
if (ret < 0)
return ret;
if (COMP1_TX_ENABLED(comp1)) {
idx2 = COMP1_TX_WORDSIZE_0(comp1);
dev->capability |= DWC_I2S_PLAY;
dev->play_dma_data.dt.addr = res->start + I2S_TXDMA;
dev->play_dma_data.dt.addr_width = bus_widths[idx];
dev->play_dma_data.dt.chan_name = "TX";
dev->play_dma_data.dt.fifo_size = fifo_depth *
(fifo_width[idx2]) >> 8;
dev->play_dma_data.dt.maxburst = 16;
}
if (COMP1_RX_ENABLED(comp1)) {
idx2 = COMP2_RX_WORDSIZE_0(comp2);
dev->capability |= DWC_I2S_RECORD;
dev->capture_dma_data.dt.addr = res->start + I2S_RXDMA;
dev->capture_dma_data.dt.addr_width = bus_widths[idx];
dev->capture_dma_data.dt.chan_name = "RX";
dev->capture_dma_data.dt.fifo_size = fifo_depth *
(fifo_width[idx2] >> 8);
dev->capture_dma_data.dt.maxburst = 16;
}
return 0;
}
static int dw_i2s_probe(struct platform_device *pdev)
{
const struct i2s_platform_data *pdata = pdev->dev.platform_data;
struct dw_i2s_dev *dev;
struct resource *res;
int ret;
struct snd_soc_dai_driver *dw_i2s_dai;
const char *clk_id;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev) {
dev_warn(&pdev->dev, "kzalloc fail\n");
return -ENOMEM;
}
dw_i2s_dai = devm_kzalloc(&pdev->dev, sizeof(*dw_i2s_dai), GFP_KERNEL);
if (!dw_i2s_dai)
return -ENOMEM;
dw_i2s_dai->ops = &dw_i2s_dai_ops;
dw_i2s_dai->suspend = dw_i2s_suspend;
dw_i2s_dai->resume = dw_i2s_resume;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->i2s_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dev->i2s_base))
return PTR_ERR(dev->i2s_base);
dev->dev = &pdev->dev;
dev->i2s_reg_comp1 = I2S_COMP_PARAM_1;
dev->i2s_reg_comp2 = I2S_COMP_PARAM_2;
if (pdata) {
dev->capability = pdata->cap;
clk_id = NULL;
dev->quirks = pdata->quirks;
if (dev->quirks & DW_I2S_QUIRK_COMP_REG_OFFSET) {
dev->i2s_reg_comp1 = pdata->i2s_reg_comp1;
dev->i2s_reg_comp2 = pdata->i2s_reg_comp2;
}
ret = dw_configure_dai_by_pd(dev, dw_i2s_dai, res, pdata);
} else {
clk_id = "i2sclk";
ret = dw_configure_dai_by_dt(dev, dw_i2s_dai, res);
}
if (ret < 0)
return ret;
if (dev->capability & DW_I2S_MASTER) {
if (pdata) {
dev->i2s_clk_cfg = pdata->i2s_clk_cfg;
if (!dev->i2s_clk_cfg) {
dev_err(&pdev->dev, "no clock configure method\n");
return -ENODEV;
}
}
dev->clk = devm_clk_get(&pdev->dev, clk_id);
if (IS_ERR(dev->clk))
return PTR_ERR(dev->clk);
ret = clk_prepare_enable(dev->clk);
if (ret < 0)
return ret;
}
dev_set_drvdata(&pdev->dev, dev);
ret = devm_snd_soc_register_component(&pdev->dev, &dw_i2s_component,
dw_i2s_dai, 1);
if (ret != 0) {
dev_err(&pdev->dev, "not able to register dai\n");
goto err_clk_disable;
}
if (!pdata) {
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret) {
dev_err(&pdev->dev,
"Could not register PCM: %d\n", ret);
goto err_clk_disable;
}
}
pm_runtime_enable(&pdev->dev);
return 0;
err_clk_disable:
if (dev->capability & DW_I2S_MASTER)
clk_disable_unprepare(dev->clk);
return ret;
}
static int dw_i2s_remove(struct platform_device *pdev)
{
struct dw_i2s_dev *dev = dev_get_drvdata(&pdev->dev);
if (dev->capability & DW_I2S_MASTER)
clk_disable_unprepare(dev->clk);
pm_runtime_disable(&pdev->dev);
return 0;
}
