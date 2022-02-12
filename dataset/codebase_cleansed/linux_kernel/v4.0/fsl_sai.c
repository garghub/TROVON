static irqreturn_t fsl_sai_isr(int irq, void *devid)
{
struct fsl_sai *sai = (struct fsl_sai *)devid;
struct device *dev = &sai->pdev->dev;
u32 flags, xcsr, mask;
bool irq_none = true;
mask = (FSL_SAI_FLAGS >> FSL_SAI_CSR_xIE_SHIFT) << FSL_SAI_CSR_xF_SHIFT;
regmap_read(sai->regmap, FSL_SAI_TCSR, &xcsr);
flags = xcsr & mask;
if (flags)
irq_none = false;
else
goto irq_rx;
if (flags & FSL_SAI_CSR_WSF)
dev_dbg(dev, "isr: Start of Tx word detected\n");
if (flags & FSL_SAI_CSR_SEF)
dev_warn(dev, "isr: Tx Frame sync error detected\n");
if (flags & FSL_SAI_CSR_FEF) {
dev_warn(dev, "isr: Transmit underrun detected\n");
xcsr |= FSL_SAI_CSR_FR;
}
if (flags & FSL_SAI_CSR_FWF)
dev_dbg(dev, "isr: Enabled transmit FIFO is empty\n");
if (flags & FSL_SAI_CSR_FRF)
dev_dbg(dev, "isr: Transmit FIFO watermark has been reached\n");
flags &= FSL_SAI_CSR_xF_W_MASK;
xcsr &= ~FSL_SAI_CSR_xF_MASK;
if (flags)
regmap_write(sai->regmap, FSL_SAI_TCSR, flags | xcsr);
irq_rx:
regmap_read(sai->regmap, FSL_SAI_RCSR, &xcsr);
flags = xcsr & mask;
if (flags)
irq_none = false;
else
goto out;
if (flags & FSL_SAI_CSR_WSF)
dev_dbg(dev, "isr: Start of Rx word detected\n");
if (flags & FSL_SAI_CSR_SEF)
dev_warn(dev, "isr: Rx Frame sync error detected\n");
if (flags & FSL_SAI_CSR_FEF) {
dev_warn(dev, "isr: Receive overflow detected\n");
xcsr |= FSL_SAI_CSR_FR;
}
if (flags & FSL_SAI_CSR_FWF)
dev_dbg(dev, "isr: Enabled receive FIFO is full\n");
if (flags & FSL_SAI_CSR_FRF)
dev_dbg(dev, "isr: Receive FIFO watermark has been reached\n");
flags &= FSL_SAI_CSR_xF_W_MASK;
xcsr &= ~FSL_SAI_CSR_xF_MASK;
if (flags)
regmap_write(sai->regmap, FSL_SAI_RCSR, flags | xcsr);
out:
if (irq_none)
return IRQ_NONE;
else
return IRQ_HANDLED;
}
static int fsl_sai_set_dai_sysclk_tr(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int fsl_dir)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
bool tx = fsl_dir == FSL_FMT_TRANSMITTER;
u32 val_cr2 = 0;
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
regmap_update_bits(sai->regmap, FSL_SAI_xCR2(tx),
FSL_SAI_CR2_MSEL_MASK, val_cr2);
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
bool tx = fsl_dir == FSL_FMT_TRANSMITTER;
u32 val_cr2 = 0, val_cr4 = 0;
if (!sai->is_lsb_first)
val_cr4 |= FSL_SAI_CR4_MF;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
val_cr2 |= FSL_SAI_CR2_BCP;
val_cr4 |= FSL_SAI_CR4_FSE | FSL_SAI_CR4_FSP;
break;
case SND_SOC_DAIFMT_LEFT_J:
val_cr2 |= FSL_SAI_CR2_BCP;
break;
case SND_SOC_DAIFMT_DSP_A:
val_cr2 |= FSL_SAI_CR2_BCP;
val_cr4 |= FSL_SAI_CR4_FSE;
sai->is_dsp_mode = true;
break;
case SND_SOC_DAIFMT_DSP_B:
val_cr2 |= FSL_SAI_CR2_BCP;
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
break;
case SND_SOC_DAIFMT_CBS_CFM:
val_cr2 |= FSL_SAI_CR2_BCD_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
val_cr4 |= FSL_SAI_CR4_FSD_MSTR;
break;
default:
return -EINVAL;
}
regmap_update_bits(sai->regmap, FSL_SAI_xCR2(tx),
FSL_SAI_CR2_BCP | FSL_SAI_CR2_BCD_MSTR, val_cr2);
regmap_update_bits(sai->regmap, FSL_SAI_xCR4(tx),
FSL_SAI_CR4_MF | FSL_SAI_CR4_FSE |
FSL_SAI_CR4_FSP | FSL_SAI_CR4_FSD_MSTR, val_cr4);
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
bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
unsigned int channels = params_channels(params);
u32 word_width = snd_pcm_format_width(params_format(params));
u32 val_cr4 = 0, val_cr5 = 0;
if (!sai->is_dsp_mode)
val_cr4 |= FSL_SAI_CR4_SYWD(word_width);
val_cr5 |= FSL_SAI_CR5_WNW(word_width);
val_cr5 |= FSL_SAI_CR5_W0W(word_width);
if (sai->is_lsb_first)
val_cr5 |= FSL_SAI_CR5_FBT(0);
else
val_cr5 |= FSL_SAI_CR5_FBT(word_width - 1);
val_cr4 |= FSL_SAI_CR4_FRSZ(channels);
regmap_update_bits(sai->regmap, FSL_SAI_xCR4(tx),
FSL_SAI_CR4_SYWD_MASK | FSL_SAI_CR4_FRSZ_MASK,
val_cr4);
regmap_update_bits(sai->regmap, FSL_SAI_xCR5(tx),
FSL_SAI_CR5_WNW_MASK | FSL_SAI_CR5_W0W_MASK |
FSL_SAI_CR5_FBT_MASK, val_cr5);
regmap_write(sai->regmap, FSL_SAI_xMR(tx), ~0UL - ((1 << channels) - 1));
return 0;
}
static int fsl_sai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
u32 xcsr, count = 100;
regmap_update_bits(sai->regmap, FSL_SAI_TCR2, FSL_SAI_CR2_SYNC, 0);
regmap_update_bits(sai->regmap, FSL_SAI_RCR2, FSL_SAI_CR2_SYNC,
sai->synchronous[RX] ? FSL_SAI_CR2_SYNC : 0);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
regmap_update_bits(sai->regmap, FSL_SAI_xCSR(tx),
FSL_SAI_CSR_FRDE, FSL_SAI_CSR_FRDE);
regmap_update_bits(sai->regmap, FSL_SAI_RCSR,
FSL_SAI_CSR_TERE, FSL_SAI_CSR_TERE);
regmap_update_bits(sai->regmap, FSL_SAI_TCSR,
FSL_SAI_CSR_TERE, FSL_SAI_CSR_TERE);
regmap_update_bits(sai->regmap, FSL_SAI_xCSR(tx),
FSL_SAI_CSR_xIE_MASK, FSL_SAI_FLAGS);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
regmap_update_bits(sai->regmap, FSL_SAI_xCSR(tx),
FSL_SAI_CSR_FRDE, 0);
regmap_update_bits(sai->regmap, FSL_SAI_xCSR(tx),
FSL_SAI_CSR_xIE_MASK, 0);
regmap_read(sai->regmap, FSL_SAI_xCSR(!tx), &xcsr);
if (!(xcsr & FSL_SAI_CSR_FRDE)) {
regmap_update_bits(sai->regmap, FSL_SAI_TCSR,
FSL_SAI_CSR_TERE, 0);
regmap_update_bits(sai->regmap, FSL_SAI_RCSR,
FSL_SAI_CSR_TERE, 0);
do {
udelay(10);
regmap_read(sai->regmap, FSL_SAI_xCSR(tx), &xcsr);
} while (--count && xcsr & FSL_SAI_CSR_TERE);
regmap_update_bits(sai->regmap, FSL_SAI_TCSR,
FSL_SAI_CSR_FR, FSL_SAI_CSR_FR);
regmap_update_bits(sai->regmap, FSL_SAI_RCSR,
FSL_SAI_CSR_FR, FSL_SAI_CSR_FR);
}
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
bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
struct device *dev = &sai->pdev->dev;
int ret;
ret = clk_prepare_enable(sai->bus_clk);
if (ret) {
dev_err(dev, "failed to enable bus clock: %d\n", ret);
return ret;
}
regmap_update_bits(sai->regmap, FSL_SAI_xCR3(tx), FSL_SAI_CR3_TRCE,
FSL_SAI_CR3_TRCE);
return 0;
}
static void fsl_sai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = snd_soc_dai_get_drvdata(cpu_dai);
bool tx = substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
regmap_update_bits(sai->regmap, FSL_SAI_xCR3(tx), FSL_SAI_CR3_TRCE, 0);
clk_disable_unprepare(sai->bus_clk);
}
static int fsl_sai_dai_probe(struct snd_soc_dai *cpu_dai)
{
struct fsl_sai *sai = dev_get_drvdata(cpu_dai->dev);
regmap_write(sai->regmap, FSL_SAI_TCSR, FSL_SAI_CSR_SR);
regmap_write(sai->regmap, FSL_SAI_RCSR, FSL_SAI_CSR_SR);
regmap_write(sai->regmap, FSL_SAI_TCSR, 0);
regmap_write(sai->regmap, FSL_SAI_RCSR, 0);
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
char tmp[8];
int irq, ret, i;
sai = devm_kzalloc(&pdev->dev, sizeof(*sai), GFP_KERNEL);
if (!sai)
return -ENOMEM;
sai->pdev = pdev;
if (of_device_is_compatible(pdev->dev.of_node, "fsl,imx6sx-sai"))
sai->sai_on_imx = true;
sai->is_lsb_first = of_property_read_bool(np, "lsb-first");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
sai->regmap = devm_regmap_init_mmio_clk(&pdev->dev,
"bus", base, &fsl_sai_regmap_config);
if (IS_ERR(sai->regmap))
sai->regmap = devm_regmap_init_mmio_clk(&pdev->dev,
"sai", base, &fsl_sai_regmap_config);
if (IS_ERR(sai->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
return PTR_ERR(sai->regmap);
}
sai->bus_clk = devm_clk_get(&pdev->dev, "bus");
if (IS_ERR(sai->bus_clk)) {
dev_err(&pdev->dev, "failed to get bus clock: %ld\n",
PTR_ERR(sai->bus_clk));
sai->bus_clk = NULL;
}
for (i = 0; i < FSL_SAI_MCLK_MAX; i++) {
sprintf(tmp, "mclk%d", i + 1);
sai->mclk_clk[i] = devm_clk_get(&pdev->dev, tmp);
if (IS_ERR(sai->mclk_clk[i])) {
dev_err(&pdev->dev, "failed to get mclk%d clock: %ld\n",
i + 1, PTR_ERR(sai->mclk_clk[i]));
sai->mclk_clk[i] = NULL;
}
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq for node %s\n", pdev->name);
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, fsl_sai_isr, 0, np->name, sai);
if (ret) {
dev_err(&pdev->dev, "failed to claim irq %u\n", irq);
return ret;
}
sai->synchronous[RX] = true;
sai->synchronous[TX] = false;
fsl_sai_dai.symmetric_rates = 1;
fsl_sai_dai.symmetric_channels = 1;
fsl_sai_dai.symmetric_samplebits = 1;
if (of_find_property(np, "fsl,sai-synchronous-rx", NULL) &&
of_find_property(np, "fsl,sai-asynchronous", NULL)) {
dev_err(&pdev->dev, "invalid binding for synchronous mode\n");
return -EINVAL;
}
if (of_find_property(np, "fsl,sai-synchronous-rx", NULL)) {
sai->synchronous[RX] = false;
sai->synchronous[TX] = true;
} else if (of_find_property(np, "fsl,sai-asynchronous", NULL)) {
sai->synchronous[RX] = false;
sai->synchronous[TX] = false;
fsl_sai_dai.symmetric_rates = 0;
fsl_sai_dai.symmetric_channels = 0;
fsl_sai_dai.symmetric_samplebits = 0;
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
if (sai->sai_on_imx)
return imx_pcm_dma_init(pdev);
else
return devm_snd_dmaengine_pcm_register(&pdev->dev, NULL,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE);
}
