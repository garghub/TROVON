static inline void mcasp_set_bits(void __iomem *reg, u32 val)
{
__raw_writel(__raw_readl(reg) | val, reg);
}
static inline void mcasp_clr_bits(void __iomem *reg, u32 val)
{
__raw_writel((__raw_readl(reg) & ~(val)), reg);
}
static inline void mcasp_mod_bits(void __iomem *reg, u32 val, u32 mask)
{
__raw_writel((__raw_readl(reg) & ~mask) | val, reg);
}
static inline void mcasp_set_reg(void __iomem *reg, u32 val)
{
__raw_writel(val, reg);
}
static inline u32 mcasp_get_reg(void __iomem *reg)
{
return (unsigned int)__raw_readl(reg);
}
static inline void mcasp_set_ctl_reg(void __iomem *regs, u32 val)
{
int i = 0;
mcasp_set_bits(regs, val);
for (i = 0; i < 1000; i++) {
if ((mcasp_get_reg(regs) & val) == val)
break;
}
if (i == 1000 && ((mcasp_get_reg(regs) & val) != val))
printk(KERN_ERR "GBLCTL write error\n");
}
static void mcasp_start_rx(struct davinci_audio_dev *dev)
{
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, RXHCLKRST);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, RXCLKRST);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, RXSERCLR);
mcasp_set_reg(dev->base + DAVINCI_MCASP_RXBUF_REG, 0);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, RXSMRST);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, RXFSRST);
mcasp_set_reg(dev->base + DAVINCI_MCASP_RXBUF_REG, 0);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, RXSMRST);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, RXFSRST);
}
static void mcasp_start_tx(struct davinci_audio_dev *dev)
{
u8 offset = 0, i;
u32 cnt;
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLX_REG, TXHCLKRST);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLX_REG, TXCLKRST);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLX_REG, TXSERCLR);
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXBUF_REG, 0);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLX_REG, TXSMRST);
mcasp_set_ctl_reg(dev->base + DAVINCI_MCASP_GBLCTLX_REG, TXFSRST);
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXBUF_REG, 0);
for (i = 0; i < dev->num_serializer; i++) {
if (dev->serial_dir[i] == TX_MODE) {
offset = i;
break;
}
}
cnt = 0;
while (!(mcasp_get_reg(dev->base + DAVINCI_MCASP_XRSRCTL_REG(offset)) &
TXSTATE) && (cnt < 100000))
cnt++;
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXBUF_REG, 0);
}
static void davinci_mcasp_start(struct davinci_audio_dev *dev, int stream)
{
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (dev->txnumevt)
mcasp_set_bits(dev->base + DAVINCI_MCASP_WFIFOCTL,
FIFO_ENABLE);
mcasp_start_tx(dev);
} else {
if (dev->rxnumevt)
mcasp_set_bits(dev->base + DAVINCI_MCASP_RFIFOCTL,
FIFO_ENABLE);
mcasp_start_rx(dev);
}
}
static void mcasp_stop_rx(struct davinci_audio_dev *dev)
{
mcasp_set_reg(dev->base + DAVINCI_MCASP_GBLCTLR_REG, 0);
mcasp_set_reg(dev->base + DAVINCI_MCASP_RXSTAT_REG, 0xFFFFFFFF);
}
static void mcasp_stop_tx(struct davinci_audio_dev *dev)
{
mcasp_set_reg(dev->base + DAVINCI_MCASP_GBLCTLX_REG, 0);
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXSTAT_REG, 0xFFFFFFFF);
}
static void davinci_mcasp_stop(struct davinci_audio_dev *dev, int stream)
{
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (dev->txnumevt)
mcasp_clr_bits(dev->base + DAVINCI_MCASP_WFIFOCTL,
FIFO_ENABLE);
mcasp_stop_tx(dev);
} else {
if (dev->rxnumevt)
mcasp_clr_bits(dev->base + DAVINCI_MCASP_RFIFOCTL,
FIFO_ENABLE);
mcasp_stop_rx(dev);
}
}
static int davinci_mcasp_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct davinci_audio_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
void __iomem *base = dev->base;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
mcasp_set_bits(base + DAVINCI_MCASP_ACLKXCTL_REG, ACLKXE);
mcasp_set_bits(base + DAVINCI_MCASP_TXFMCTL_REG, AFSXE);
mcasp_set_bits(base + DAVINCI_MCASP_ACLKRCTL_REG, ACLKRE);
mcasp_set_bits(base + DAVINCI_MCASP_RXFMCTL_REG, AFSRE);
mcasp_set_bits(base + DAVINCI_MCASP_PDIR_REG,
ACLKX | AHCLKX | AFSX);
break;
case SND_SOC_DAIFMT_CBM_CFS:
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKXCTL_REG, ACLKXE);
mcasp_set_bits(base + DAVINCI_MCASP_TXFMCTL_REG, AFSXE);
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKRCTL_REG, ACLKRE);
mcasp_set_bits(base + DAVINCI_MCASP_RXFMCTL_REG, AFSRE);
mcasp_clr_bits(base + DAVINCI_MCASP_PDIR_REG,
ACLKX | ACLKR);
mcasp_set_bits(base + DAVINCI_MCASP_PDIR_REG,
AFSX | AFSR);
break;
case SND_SOC_DAIFMT_CBM_CFM:
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKXCTL_REG, ACLKXE);
mcasp_clr_bits(base + DAVINCI_MCASP_TXFMCTL_REG, AFSXE);
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKRCTL_REG, ACLKRE);
mcasp_clr_bits(base + DAVINCI_MCASP_RXFMCTL_REG, AFSRE);
mcasp_clr_bits(base + DAVINCI_MCASP_PDIR_REG,
ACLKX | AHCLKX | AFSX | ACLKR | AHCLKR | AFSR);
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_NF:
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_clr_bits(base + DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_set_bits(base + DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_clr_bits(base + DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
case SND_SOC_DAIFMT_NB_IF:
mcasp_set_bits(base + DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_set_bits(base + DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_set_bits(base + DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
case SND_SOC_DAIFMT_IB_IF:
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_set_bits(base + DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_set_bits(base + DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_set_bits(base + DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
case SND_SOC_DAIFMT_NB_NF:
mcasp_set_bits(base + DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_clr_bits(base + DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_clr_bits(base + DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_clr_bits(base + DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
default:
return -EINVAL;
}
return 0;
}
static int davinci_config_channel_size(struct davinci_audio_dev *dev,
int channel_size)
{
u32 fmt = 0;
u32 mask, rotate;
switch (channel_size) {
case DAVINCI_AUDIO_WORD_8:
fmt = 0x03;
rotate = 6;
mask = 0x000000ff;
break;
case DAVINCI_AUDIO_WORD_12:
fmt = 0x05;
rotate = 5;
mask = 0x00000fff;
break;
case DAVINCI_AUDIO_WORD_16:
fmt = 0x07;
rotate = 4;
mask = 0x0000ffff;
break;
case DAVINCI_AUDIO_WORD_20:
fmt = 0x09;
rotate = 3;
mask = 0x000fffff;
break;
case DAVINCI_AUDIO_WORD_24:
fmt = 0x0B;
rotate = 2;
mask = 0x00ffffff;
break;
case DAVINCI_AUDIO_WORD_28:
fmt = 0x0D;
rotate = 1;
mask = 0x0fffffff;
break;
case DAVINCI_AUDIO_WORD_32:
fmt = 0x0F;
rotate = 0;
mask = 0xffffffff;
break;
default:
return -EINVAL;
}
mcasp_mod_bits(dev->base + DAVINCI_MCASP_RXFMT_REG,
RXSSZ(fmt), RXSSZ(0x0F));
mcasp_mod_bits(dev->base + DAVINCI_MCASP_TXFMT_REG,
TXSSZ(fmt), TXSSZ(0x0F));
mcasp_mod_bits(dev->base + DAVINCI_MCASP_TXFMT_REG, TXROT(rotate),
TXROT(7));
mcasp_mod_bits(dev->base + DAVINCI_MCASP_RXFMT_REG, RXROT(rotate),
RXROT(7));
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXMASK_REG, mask);
mcasp_set_reg(dev->base + DAVINCI_MCASP_RXMASK_REG, mask);
return 0;
}
static void davinci_hw_common_param(struct davinci_audio_dev *dev, int stream)
{
int i;
u8 tx_ser = 0;
u8 rx_ser = 0;
mcasp_set_bits(dev->base + DAVINCI_MCASP_PWREMUMGT_REG, MCASP_SOFT);
mcasp_set_reg(dev->base + DAVINCI_MCASP_PFUNC_REG, 0x00000000);
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXSTAT_REG, 0xFFFFFFFF);
mcasp_clr_bits(dev->base + DAVINCI_MCASP_XEVTCTL_REG,
TXDATADMADIS);
} else {
mcasp_set_reg(dev->base + DAVINCI_MCASP_RXSTAT_REG, 0xFFFFFFFF);
mcasp_clr_bits(dev->base + DAVINCI_MCASP_REVTCTL_REG,
RXDATADMADIS);
}
for (i = 0; i < dev->num_serializer; i++) {
mcasp_set_bits(dev->base + DAVINCI_MCASP_XRSRCTL_REG(i),
dev->serial_dir[i]);
if (dev->serial_dir[i] == TX_MODE) {
mcasp_set_bits(dev->base + DAVINCI_MCASP_PDIR_REG,
AXR(i));
tx_ser++;
} else if (dev->serial_dir[i] == RX_MODE) {
mcasp_clr_bits(dev->base + DAVINCI_MCASP_PDIR_REG,
AXR(i));
rx_ser++;
}
}
if (dev->txnumevt && stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (dev->txnumevt * tx_ser > 64)
dev->txnumevt = 1;
mcasp_mod_bits(dev->base + DAVINCI_MCASP_WFIFOCTL, tx_ser,
NUMDMA_MASK);
mcasp_mod_bits(dev->base + DAVINCI_MCASP_WFIFOCTL,
((dev->txnumevt * tx_ser) << 8), NUMEVT_MASK);
}
if (dev->rxnumevt && stream == SNDRV_PCM_STREAM_CAPTURE) {
if (dev->rxnumevt * rx_ser > 64)
dev->rxnumevt = 1;
mcasp_mod_bits(dev->base + DAVINCI_MCASP_RFIFOCTL, rx_ser,
NUMDMA_MASK);
mcasp_mod_bits(dev->base + DAVINCI_MCASP_RFIFOCTL,
((dev->rxnumevt * rx_ser) << 8), NUMEVT_MASK);
}
}
static void davinci_hw_param(struct davinci_audio_dev *dev, int stream)
{
int i, active_slots;
u32 mask = 0;
active_slots = (dev->tdm_slots > 31) ? 32 : dev->tdm_slots;
for (i = 0; i < active_slots; i++)
mask |= (1 << i);
mcasp_clr_bits(dev->base + DAVINCI_MCASP_ACLKXCTL_REG, TX_ASYNC);
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
mcasp_set_bits(dev->base + DAVINCI_MCASP_AHCLKXCTL_REG,
AHCLKXE);
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXTDM_REG, mask);
mcasp_set_bits(dev->base + DAVINCI_MCASP_TXFMT_REG, TXORD);
if ((dev->tdm_slots >= 2) && (dev->tdm_slots <= 32))
mcasp_mod_bits(dev->base + DAVINCI_MCASP_TXFMCTL_REG,
FSXMOD(dev->tdm_slots), FSXMOD(0x1FF));
else
printk(KERN_ERR "playback tdm slot %d not supported\n",
dev->tdm_slots);
mcasp_clr_bits(dev->base + DAVINCI_MCASP_TXFMCTL_REG, FSXDUR);
} else {
mcasp_set_bits(dev->base + DAVINCI_MCASP_RXFMT_REG, RXORD);
mcasp_set_bits(dev->base + DAVINCI_MCASP_AHCLKRCTL_REG,
AHCLKRE);
mcasp_set_reg(dev->base + DAVINCI_MCASP_RXTDM_REG, mask);
if ((dev->tdm_slots >= 2) && (dev->tdm_slots <= 32))
mcasp_mod_bits(dev->base + DAVINCI_MCASP_RXFMCTL_REG,
FSRMOD(dev->tdm_slots), FSRMOD(0x1FF));
else
printk(KERN_ERR "capture tdm slot %d not supported\n",
dev->tdm_slots);
mcasp_clr_bits(dev->base + DAVINCI_MCASP_RXFMCTL_REG, FSRDUR);
}
}
static void davinci_hw_dit_param(struct davinci_audio_dev *dev)
{
mcasp_set_bits(dev->base + DAVINCI_MCASP_PDIR_REG, AFSX);
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXMASK_REG, 0x00FFFFFF);
mcasp_set_bits(dev->base + DAVINCI_MCASP_TXFMT_REG,
TXROT(6) | TXSSZ(15));
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXFMCTL_REG,
AFSXE | FSXMOD(0x180));
mcasp_set_reg(dev->base + DAVINCI_MCASP_TXTDM_REG, 0xFFFFFFFF);
mcasp_set_bits(dev->base + DAVINCI_MCASP_ACLKXCTL_REG,
ACLKXE | TX_ASYNC);
mcasp_clr_bits(dev->base + DAVINCI_MCASP_XEVTCTL_REG, TXDATADMADIS);
mcasp_set_bits(dev->base + DAVINCI_MCASP_AHCLKXCTL_REG, AHCLKXDIV(3));
mcasp_set_bits(dev->base + DAVINCI_MCASP_TXDITCTL_REG, DITEN);
}
static int davinci_mcasp_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct davinci_audio_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
struct davinci_pcm_dma_params *dma_params =
&dev->dma_params[substream->stream];
int word_length;
u8 fifo_level;
davinci_hw_common_param(dev, substream->stream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fifo_level = dev->txnumevt;
else
fifo_level = dev->rxnumevt;
if (dev->op_mode == DAVINCI_MCASP_DIT_MODE)
davinci_hw_dit_param(dev);
else
davinci_hw_param(dev, substream->stream);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_U8:
case SNDRV_PCM_FORMAT_S8:
dma_params->data_type = 1;
word_length = DAVINCI_AUDIO_WORD_8;
break;
case SNDRV_PCM_FORMAT_U16_LE:
case SNDRV_PCM_FORMAT_S16_LE:
dma_params->data_type = 2;
word_length = DAVINCI_AUDIO_WORD_16;
break;
case SNDRV_PCM_FORMAT_U32_LE:
case SNDRV_PCM_FORMAT_S32_LE:
dma_params->data_type = 4;
word_length = DAVINCI_AUDIO_WORD_32;
break;
default:
printk(KERN_WARNING "davinci-mcasp: unsupported PCM format");
return -EINVAL;
}
if (dev->version == MCASP_VERSION_2 && !fifo_level)
dma_params->acnt = 4;
else
dma_params->acnt = dma_params->data_type;
dma_params->fifo_level = fifo_level;
davinci_config_channel_size(dev, word_length);
return 0;
}
static int davinci_mcasp_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *cpu_dai)
{
struct davinci_audio_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (!dev->clk_active) {
clk_enable(dev->clk);
dev->clk_active = 1;
}
davinci_mcasp_start(dev, substream->stream);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
davinci_mcasp_stop(dev, substream->stream);
if (dev->clk_active) {
clk_disable(dev->clk);
dev->clk_active = 0;
}
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
davinci_mcasp_stop(dev, substream->stream);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int davinci_mcasp_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct davinci_audio_dev *dev = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_set_dma_data(dai, substream, dev->dma_params);
return 0;
}
static int davinci_mcasp_probe(struct platform_device *pdev)
{
struct davinci_pcm_dma_params *dma_data;
struct resource *mem, *ioarea, *res;
struct snd_platform_data *pdata;
struct davinci_audio_dev *dev;
int ret = 0;
dev = kzalloc(sizeof(struct davinci_audio_dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
ret = -ENODEV;
goto err_release_data;
}
ioarea = request_mem_region(mem->start,
resource_size(mem), pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "Audio region already claimed\n");
ret = -EBUSY;
goto err_release_data;
}
pdata = pdev->dev.platform_data;
dev->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk)) {
ret = -ENODEV;
goto err_release_region;
}
clk_enable(dev->clk);
dev->clk_active = 1;
dev->base = ioremap(mem->start, resource_size(mem));
if (!dev->base) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_release_clk;
}
dev->op_mode = pdata->op_mode;
dev->tdm_slots = pdata->tdm_slots;
dev->num_serializer = pdata->num_serializer;
dev->serial_dir = pdata->serial_dir;
dev->codec_fmt = pdata->codec_fmt;
dev->version = pdata->version;
dev->txnumevt = pdata->txnumevt;
dev->rxnumevt = pdata->rxnumevt;
dma_data = &dev->dma_params[SNDRV_PCM_STREAM_PLAYBACK];
dma_data->asp_chan_q = pdata->asp_chan_q;
dma_data->ram_chan_q = pdata->ram_chan_q;
dma_data->sram_size = pdata->sram_size_playback;
dma_data->dma_addr = (dma_addr_t) (pdata->tx_dma_offset +
mem->start);
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!res) {
dev_err(&pdev->dev, "no DMA resource\n");
ret = -ENODEV;
goto err_iounmap;
}
dma_data->channel = res->start;
dma_data = &dev->dma_params[SNDRV_PCM_STREAM_CAPTURE];
dma_data->asp_chan_q = pdata->asp_chan_q;
dma_data->ram_chan_q = pdata->ram_chan_q;
dma_data->sram_size = pdata->sram_size_capture;
dma_data->dma_addr = (dma_addr_t)(pdata->rx_dma_offset +
mem->start);
res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!res) {
dev_err(&pdev->dev, "no DMA resource\n");
ret = -ENODEV;
goto err_iounmap;
}
dma_data->channel = res->start;
dev_set_drvdata(&pdev->dev, dev);
ret = snd_soc_register_dai(&pdev->dev, &davinci_mcasp_dai[pdata->op_mode]);
if (ret != 0)
goto err_iounmap;
return 0;
err_iounmap:
iounmap(dev->base);
err_release_clk:
clk_disable(dev->clk);
clk_put(dev->clk);
err_release_region:
release_mem_region(mem->start, resource_size(mem));
err_release_data:
kfree(dev);
return ret;
}
static int davinci_mcasp_remove(struct platform_device *pdev)
{
struct davinci_audio_dev *dev = dev_get_drvdata(&pdev->dev);
struct resource *mem;
snd_soc_unregister_dai(&pdev->dev);
clk_disable(dev->clk);
clk_put(dev->clk);
dev->clk = NULL;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
kfree(dev);
return 0;
}
static int __init davinci_mcasp_init(void)
{
return platform_driver_register(&davinci_mcasp_driver);
}
static void __exit davinci_mcasp_exit(void)
{
platform_driver_unregister(&davinci_mcasp_driver);
}
