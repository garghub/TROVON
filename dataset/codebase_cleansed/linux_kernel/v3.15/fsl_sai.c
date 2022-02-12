static irqreturn_t fsl_sai_isr(int irq, void *devid)
{
struct fsl_sai *sai = (struct fsl_sai *)devid;
struct device *dev = &sai->pdev->dev;
u32 xcsr, mask;
mask = (FSL_SAI_FLAGS >> FSL_SAI_CSR_xIE_SHIFT) << FSL_SAI_CSR_xF_SHIFT;
regmap_read(sai->regmap, FSL_SAI_TCSR, &xcsr);
xcsr &= mask;
if (xcsr & FSL_SAI_CSR_WSF)
dev_dbg(dev, "isr: Start of Tx word detected\n");
if (xcsr & FSL_SAI_CSR_SEF)
dev_warn(dev, "isr: Tx Frame sync error detected\n");
if (xcsr & FSL_SAI_CSR_FEF) {
dev_warn(dev, "isr: Transmit underrun detected\n");
xcsr |= FSL_SAI_CSR_FR;
}
if (xcsr & FSL_SAI_CSR_FWF)
dev_dbg(dev, "isr: Enabled transmit FIFO is empty\n");
if (xcsr & FSL_SAI_CSR_FRF)
dev_dbg(dev, "isr: Transmit FIFO watermark has been reached\n");
regmap_update_bits(sai->regmap, FSL_SAI_TCSR,
FSL_SAI_CSR_xF_W_MASK | FSL_SAI_CSR_FR, xcsr);
regmap_read(sai->regmap, FSL_SAI_RCSR, &xcsr);
xcsr &= mask;
if (xcsr & FSL_SAI_CSR_WSF)
dev_dbg(dev, "isr: Start of Rx word detected\n");
if (xcsr & FSL_SAI_CSR_SEF)
dev_warn(dev, "isr: Rx Frame sync error detected\n");
if (xcsr & FSL_SAI_CSR_FEF) {
dev_warn(dev, "isr: Receive overflow detected\n");
xcsr |= FSL_SAI_CSR_FR;
}
if (xcsr & FSL_SAI_CSR_FWF)
dev_dbg(dev, "isr: Enabled receive FIFO is full\n");
if (xcsr & FSL_SAI_CSR_FRF)
dev_dbg(dev, "isr: Receive FIFO watermark has been reached\n");
regmap_update_bits(sai->regmap, FSL_SAI_RCSR,
FSL_SAI_CSR_xF_W_MASK | FSL_SAI_CSR_FR, xcsr);
return IRQ_HANDLED;
}
static int fsl_sai_set_dai_sysclk_tr(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int fsl_dir)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
u32 val_cr2, reg_cr2;
if (fsl_dir == FSL_FMT_TRANSMITTER)
reg_cr2 = FSL_SAI_TCR2;
else
reg_cr2 = FSL_SAI_RCR2;
regmap_read(sai->regmap, reg_cr2, &val_cr2);
val_cr2 &= ~FSL_SAI_CR2_MSEL_MASK;
switch (clk_id) {
case FSL_SAI_CLK_BUS:
val_cr2 |= FSL_SAI_CR2_MSEL_BUS;
break;
case FSL_SAI_CLK_MAST1:
val_cr2 |= FSL_SAI_CR2_MSEL_MCLK1;
break;
case FSL_SAI_CLK_MAST2:
val_cr2 |= FSL_SAI_CR2_MSEL_MCLK2;
break;
case FSL_SAI_CLK_MAST3:
val_cr2 |= FSL_SAI_CR2_MSEL_MCLK3;
break;
default:
return -EINVAL;
}
regmap_write(sai->regmap, reg_cr2, val_cr2);
return 0;
}
static int fsl_sai_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
int ret;
if (dir == SND_SOC_CLOCK_IN)
return 0;
ret = fsl_sai_set_dai_sysclk_tr(cpu_dai, clk_id, freq,
FSL_FMT_TRANSMITTER);
if (ret) {
dev_err(cpu_dai->dev, "Cannot set tx sysclk: %d\n", ret);
return ret;
}
ret = fsl_sai_set_dai_sysclk_tr(cpu_dai, clk_id, freq,
FSL_FMT_RECEIVER);
if (ret)
dev_err(cpu_dai->dev, "Cannot set rx sysclk: %d\n", ret);
return ret;
}
static int fsl_sai_set_dai_fmt_tr(struct snd_soc_dai *cpu_dai,
unsigned int fmt, int fsl_dir)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
u32 val_cr2, val_cr4, reg_cr2, reg_cr4;
if (fsl_dir == FSL_FMT_TRANSMITTER) {
reg_cr2 = FSL_SAI_TCR2;
reg_cr4 = FSL_SAI_TCR4;
} else {
reg_cr2 = FSL_SAI_RCR2;
reg_cr4 = FSL_SAI_RCR4;
}
regmap_read(sai->regmap, reg_cr2, &val_cr2);
regmap_read(sai->regmap, reg_cr4, &val_cr4);
if (sai->big_endian_data)
val_cr4 &= ~FSL_SAI_CR4_MF;
else
val_cr4 |= FSL_SAI_CR4_MF;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
val_cr2 |= FSL_SAI_CR2_BCP;
val_cr4 |= FSL_SAI_CR4_FSE | FSL_SAI_CR4_FSP;
break;
case SND_SOC_DAIFMT_LEFT_J:
val_cr2 |= FSL_SAI_CR2_BCP;
val_cr4 &= ~(FSL_SAI_CR4_FSE | FSL_SAI_CR4_FSP);
break;
case SND_SOC_DAIFMT_DSP_A:
val_cr2 |= FSL_SAI_CR2_BCP;
val_cr4 &= ~FSL_SAI_CR4_FSP;
val_cr4 |= FSL_SAI_CR4_FSE;
sai->is_dsp_mode = true;
break;
case SND_SOC_DAIFMT_DSP_B:
val_cr2 |= FSL_SAI_CR2_BCP;
val_cr4 &= ~(FSL_SAI_CR4_FSE | FSL_SAI_CR4_FSP);
sai->is_dsp_mode = true;
break;
case SND_SOC_DAIFMT_RIGHT_J:
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_IF:
val_cr2 ^= FSL_SAI_CR2_BCP;
val_cr4 ^= FSL_SAI_CR4_FSP;
break;
case SND_SOC_DAIFMT_IB_NF:
val_cr2 ^= FSL_SAI_CR2_BCP;
break;
case SND_SOC_DAIFMT_NB_IF:
val_cr4 ^= FSL_SAI_CR4_FSP;
break;
case SND_SOC_DAIFMT_NB_NF:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
val_cr2 |= FSL_SAI_CR2_BCD_MSTR;
val_cr4 |= FSL_SAI_CR4_FSD_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
val_cr2 &= ~FSL_SAI_CR2_BCD_MSTR;
val_cr4 &= ~FSL_SAI_CR4_FSD_MSTR;
break;
case SND_SOC_DAIFMT_CBS_CFM:
val_cr2 |= FSL_SAI_CR2_BCD_MSTR;
val_cr4 &= ~FSL_SAI_CR4_FSD_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
val_cr2 &= ~FSL_SAI_CR2_BCD_MSTR;
val_cr4 |= FSL_SAI_CR4_FSD_MSTR;
break;
default:
return -EINVAL;
}
regmap_write(sai->regmap, reg_cr2, val_cr2);
regmap_write(sai->regmap, reg_cr4, val_cr4);
return 0;
}
static int fsl_sai_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
int ret;
ret = fsl_sai_set_dai_fmt_tr(cpu_dai, fmt, FSL_FMT_TRANSMITTER);
if (ret) {
dev_err(cpu_dai->dev, "Cannot set tx format: %d\n", ret);
return ret;
}
ret = fsl_sai_set_dai_fmt_tr(cpu_dai, fmt, FSL_FMT_RECEIVER);
if (ret)
dev_err(cpu_dai->dev, "Cannot set rx format: %d\n", ret);
return ret;
}
static int fsl_sai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
u32 val_cr4, val_cr5, val_mr, reg_cr4, reg_cr5, reg_mr;
unsigned int channels = params_channels(params);
u32 word_width = snd_pcm_format_width(params_format(params));
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
reg_cr4 = FSL_SAI_TCR4;
reg_cr5 = FSL_SAI_TCR5;
reg_mr = FSL_SAI_TMR;
} else {
reg_cr4 = FSL_SAI_RCR4;
reg_cr5 = FSL_SAI_RCR5;
reg_mr = FSL_SAI_RMR;
}
regmap_read(sai->regmap, reg_cr4, &val_cr4);
regmap_read(sai->regmap, reg_cr4, &val_cr5);
val_cr4 &= ~FSL_SAI_CR4_SYWD_MASK;
val_cr4 &= ~FSL_SAI_CR4_FRSZ_MASK;
val_cr5 &= ~FSL_SAI_CR5_WNW_MASK;
val_cr5 &= ~FSL_SAI_CR5_W0W_MASK;
val_cr5 &= ~FSL_SAI_CR5_FBT_MASK;
if (!sai->is_dsp_mode)
val_cr4 |= FSL_SAI_CR4_SYWD(word_width);
val_cr5 |= FSL_SAI_CR5_WNW(word_width);
val_cr5 |= FSL_SAI_CR5_W0W(word_width);
val_cr5 &= ~FSL_SAI_CR5_FBT_MASK;
if (sai->big_endian_data)
val_cr5 |= FSL_SAI_CR5_FBT(0);
else
val_cr5 |= FSL_SAI_CR5_FBT(word_width - 1);
val_cr4 |= FSL_SAI_CR4_FRSZ(channels);
val_mr = ~0UL - ((1 << channels) - 1);
regmap_write(sai->regmap, reg_cr4, val_cr4);
regmap_write(sai->regmap, reg_cr5, val_cr5);
regmap_write(sai->regmap, reg_mr, val_mr);
return 0;
}
static int fsl_sai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
u32 tcsr, rcsr;
regmap_update_bits(sai->regmap, FSL_SAI_TCR2, FSL_SAI_CR2_SYNC,
~FSL_SAI_CR2_SYNC);
regmap_update_bits(sai->regmap, FSL_SAI_RCR2, FSL_SAI_CR2_SYNC,
FSL_SAI_CR2_SYNC);
regmap_read(sai->regmap, FSL_SAI_TCSR, &tcsr);
regmap_read(sai->regmap, FSL_SAI_RCSR, &rcsr);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
tcsr |= FSL_SAI_CSR_FRDE;
rcsr &= ~FSL_SAI_CSR_FRDE;
} else {
rcsr |= FSL_SAI_CSR_FRDE;
tcsr &= ~FSL_SAI_CSR_FRDE;
}
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
tcsr |= FSL_SAI_CSR_TERE;
rcsr |= FSL_SAI_CSR_TERE;
regmap_write(sai->regmap, FSL_SAI_RCSR, rcsr);
regmap_write(sai->regmap, FSL_SAI_TCSR, tcsr);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (!(cpu_dai->playback_active || cpu_dai->capture_active)) {
tcsr &= ~FSL_SAI_CSR_TERE;
rcsr &= ~FSL_SAI_CSR_TERE;
}
regmap_write(sai->regmap, FSL_SAI_TCSR, tcsr);
regmap_write(sai->regmap, FSL_SAI_RCSR, rcsr);
break;
default:
return -EINVAL;
}
return 0;
}
static int fsl_sai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
u32 reg;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = FSL_SAI_TCR3;
else
reg = FSL_SAI_RCR3;
regmap_update_bits(sai->regmap, reg, FSL_SAI_CR3_TRCE,
FSL_SAI_CR3_TRCE);
return 0;
}
static void fsl_sai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
u32 reg;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = FSL_SAI_TCR3;
else
reg = FSL_SAI_RCR3;
regmap_update_bits(sai->regmap, reg, FSL_SAI_CR3_TRCE,
~FSL_SAI_CR3_TRCE);
}
static int fsl_sai_dai_probe(struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = dev_get_drvdata(cpu_dai->dev);
regmap_update_bits(sai->regmap, FSL_SAI_TCSR, 0xffffffff, FSL_SAI_FLAGS);
regmap_update_bits(sai->regmap, FSL_SAI_RCSR, 0xffffffff, FSL_SAI_FLAGS);
regmap_update_bits(sai->regmap, FSL_SAI_TCR1, FSL_SAI_CR1_RFW_MASK,
FSL_SAI_MAXBURST_TX * 2);
regmap_update_bits(sai->regmap, FSL_SAI_RCR1, FSL_SAI_CR1_RFW_MASK,
FSL_SAI_MAXBURST_RX - 1);
snd_soc_dai_init_dma_data(cpu_dai, &sai->dma_params_tx,
&sai->dma_params_rx);
snd_soc_dai_set_drvdata(cpu_dai, sai);
return 0;
}
static bool fsl_sai_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case FSL_SAI_TCSR:
case FSL_SAI_TCR1:
case FSL_SAI_TCR2:
case FSL_SAI_TCR3:
case FSL_SAI_TCR4:
case FSL_SAI_TCR5:
case FSL_SAI_TFR:
case FSL_SAI_TMR:
case FSL_SAI_RCSR:
case FSL_SAI_RCR1:
case FSL_SAI_RCR2:
case FSL_SAI_RCR3:
case FSL_SAI_RCR4:
case FSL_SAI_RCR5:
case FSL_SAI_RDR:
case FSL_SAI_RFR:
case FSL_SAI_RMR:
return true;
default:
return false;
}
}
static bool fsl_sai_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case FSL_SAI_TFR:
case FSL_SAI_RFR:
case FSL_SAI_TDR:
case FSL_SAI_RDR:
return true;
default:
return false;
}
}
static bool fsl_sai_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case FSL_SAI_TCSR:
case FSL_SAI_TCR1:
case FSL_SAI_TCR2:
case FSL_SAI_TCR3:
case FSL_SAI_TCR4:
case FSL_SAI_TCR5:
case FSL_SAI_TDR:
case FSL_SAI_TMR:
case FSL_SAI_RCSR:
case FSL_SAI_RCR1:
case FSL_SAI_RCR2:
case FSL_SAI_RCR3:
case FSL_SAI_RCR4:
case FSL_SAI_RCR5:
case FSL_SAI_RMR:
return true;
default:
return false;
}
}
static int fsl_sai_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct fsl_sai *sai;
struct resource *res;
void __iomem *base;
int irq, ret;
sai = devm_kzalloc(&pdev->dev, sizeof(*sai), GFP_KERNEL);
if (!sai)
return -ENOMEM;
sai->pdev = pdev;
sai->big_endian_regs = of_property_read_bool(np, "big-endian-regs");
if (sai->big_endian_regs)
fsl_sai_regmap_config.val_format_endian = REGMAP_ENDIAN_BIG;
sai->big_endian_data = of_property_read_bool(np, "big-endian-data");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
sai->regmap = devm_regmap_init_mmio_clk(&pdev->dev,
"sai", base, &fsl_sai_regmap_config);
if (IS_ERR(sai->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
return PTR_ERR(sai->regmap);
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq for node %s\n", np->full_name);
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, fsl_sai_isr, 0, np->name, sai);
if (ret) {
dev_err(&pdev->dev, "failed to claim irq %u\n", irq);
return ret;
}
sai->dma_params_rx.addr = res->start + FSL_SAI_RDR;
sai->dma_params_tx.addr = res->start + FSL_SAI_TDR;
sai->dma_params_rx.maxburst = FSL_SAI_MAXBURST_RX;
sai->dma_params_tx.maxburst = FSL_SAI_MAXBURST_TX;
platform_set_drvdata(pdev, sai);
ret = devm_snd_soc_register_component(&pdev->dev, &fsl_component,
&fsl_sai_dai, 1);
if (ret)
return ret;
return devm_snd_dmaengine_pcm_register(&pdev->dev, NULL,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE);
}
