static void dump_registers(struct ssp_device *ssp)
{
dev_dbg(&ssp->pdev->dev, "SSCR0 0x%08x SSCR1 0x%08x SSTO 0x%08x\n",
pxa_ssp_read_reg(ssp, SSCR0), pxa_ssp_read_reg(ssp, SSCR1),
pxa_ssp_read_reg(ssp, SSTO));
dev_dbg(&ssp->pdev->dev, "SSPSP 0x%08x SSSR 0x%08x SSACD 0x%08x\n",
pxa_ssp_read_reg(ssp, SSPSP), pxa_ssp_read_reg(ssp, SSSR),
pxa_ssp_read_reg(ssp, SSACD));
}
static void pxa_ssp_enable(struct ssp_device *ssp)
{
uint32_t sscr0;
sscr0 = __raw_readl(ssp->mmio_base + SSCR0) | SSCR0_SSE;
__raw_writel(sscr0, ssp->mmio_base + SSCR0);
}
static void pxa_ssp_disable(struct ssp_device *ssp)
{
uint32_t sscr0;
sscr0 = __raw_readl(ssp->mmio_base + SSCR0) & ~SSCR0_SSE;
__raw_writel(sscr0, ssp->mmio_base + SSCR0);
}
static void pxa_ssp_set_dma_params(struct ssp_device *ssp, int width4,
int out, struct snd_dmaengine_dai_dma_data *dma)
{
dma->addr_width = width4 ? DMA_SLAVE_BUSWIDTH_4_BYTES :
DMA_SLAVE_BUSWIDTH_2_BYTES;
dma->maxburst = 16;
dma->addr = ssp->phys_base + SSDR;
}
static int pxa_ssp_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
struct snd_dmaengine_dai_dma_data *dma;
int ret = 0;
if (!cpu_dai->active) {
clk_enable(ssp->clk);
pxa_ssp_disable(ssp);
}
dma = kzalloc(sizeof(struct snd_dmaengine_dai_dma_data), GFP_KERNEL);
if (!dma)
return -ENOMEM;
dma->filter_data = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ?
&ssp->drcmr_tx : &ssp->drcmr_rx;
snd_soc_dai_set_dma_data(cpu_dai, substream, dma);
return ret;
}
static void pxa_ssp_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
if (!cpu_dai->active) {
pxa_ssp_disable(ssp);
clk_disable(ssp->clk);
}
kfree(snd_soc_dai_get_dma_data(cpu_dai, substream));
snd_soc_dai_set_dma_data(cpu_dai, substream, NULL);
}
static int pxa_ssp_suspend(struct snd_soc_dai *cpu_dai)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
if (!cpu_dai->active)
clk_enable(ssp->clk);
priv->cr0 = __raw_readl(ssp->mmio_base + SSCR0);
priv->cr1 = __raw_readl(ssp->mmio_base + SSCR1);
priv->to = __raw_readl(ssp->mmio_base + SSTO);
priv->psp = __raw_readl(ssp->mmio_base + SSPSP);
pxa_ssp_disable(ssp);
clk_disable(ssp->clk);
return 0;
}
static int pxa_ssp_resume(struct snd_soc_dai *cpu_dai)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
uint32_t sssr = SSSR_ROR | SSSR_TUR | SSSR_BCE;
clk_enable(ssp->clk);
__raw_writel(sssr, ssp->mmio_base + SSSR);
__raw_writel(priv->cr0 & ~SSCR0_SSE, ssp->mmio_base + SSCR0);
__raw_writel(priv->cr1, ssp->mmio_base + SSCR1);
__raw_writel(priv->to, ssp->mmio_base + SSTO);
__raw_writel(priv->psp, ssp->mmio_base + SSPSP);
if (cpu_dai->active)
pxa_ssp_enable(ssp);
else
clk_disable(ssp->clk);
return 0;
}
static void pxa_ssp_set_scr(struct ssp_device *ssp, u32 div)
{
u32 sscr0 = pxa_ssp_read_reg(ssp, SSCR0);
if (ssp->type == PXA25x_SSP) {
sscr0 &= ~0x0000ff00;
sscr0 |= ((div - 2)/2) << 8;
} else {
sscr0 &= ~0x000fff00;
sscr0 |= (div - 1) << 8;
}
pxa_ssp_write_reg(ssp, SSCR0, sscr0);
}
static u32 pxa_ssp_get_scr(struct ssp_device *ssp)
{
u32 sscr0 = pxa_ssp_read_reg(ssp, SSCR0);
u32 div;
if (ssp->type == PXA25x_SSP)
div = ((sscr0 >> 8) & 0xff) * 2 + 2;
else
div = ((sscr0 >> 8) & 0xfff) + 1;
return div;
}
static int pxa_ssp_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
int val;
u32 sscr0 = pxa_ssp_read_reg(ssp, SSCR0) &
~(SSCR0_ECS | SSCR0_NCS | SSCR0_MOD | SSCR0_ACS);
dev_dbg(&ssp->pdev->dev,
"pxa_ssp_set_dai_sysclk id: %d, clk_id %d, freq %u\n",
cpu_dai->id, clk_id, freq);
switch (clk_id) {
case PXA_SSP_CLK_NET_PLL:
sscr0 |= SSCR0_MOD;
break;
case PXA_SSP_CLK_PLL:
if (ssp->type == PXA25x_SSP)
priv->sysclk = 1843200;
else
priv->sysclk = 13000000;
break;
case PXA_SSP_CLK_EXT:
priv->sysclk = freq;
sscr0 |= SSCR0_ECS;
break;
case PXA_SSP_CLK_NET:
priv->sysclk = freq;
sscr0 |= SSCR0_NCS | SSCR0_MOD;
break;
case PXA_SSP_CLK_AUDIO:
priv->sysclk = 0;
pxa_ssp_set_scr(ssp, 1);
sscr0 |= SSCR0_ACS;
break;
default:
return -ENODEV;
}
if (ssp->type != PXA3xx_SSP)
clk_disable(ssp->clk);
val = pxa_ssp_read_reg(ssp, SSCR0) | sscr0;
pxa_ssp_write_reg(ssp, SSCR0, val);
if (ssp->type != PXA3xx_SSP)
clk_enable(ssp->clk);
return 0;
}
static int pxa_ssp_set_dai_clkdiv(struct snd_soc_dai *cpu_dai,
int div_id, int div)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
int val;
switch (div_id) {
case PXA_SSP_AUDIO_DIV_ACDS:
val = (pxa_ssp_read_reg(ssp, SSACD) & ~0x7) | SSACD_ACDS(div);
pxa_ssp_write_reg(ssp, SSACD, val);
break;
case PXA_SSP_AUDIO_DIV_SCDB:
val = pxa_ssp_read_reg(ssp, SSACD);
val &= ~SSACD_SCDB;
if (ssp->type == PXA3xx_SSP)
val &= ~SSACD_SCDX8;
switch (div) {
case PXA_SSP_CLK_SCDB_1:
val |= SSACD_SCDB;
break;
case PXA_SSP_CLK_SCDB_4:
break;
case PXA_SSP_CLK_SCDB_8:
if (ssp->type == PXA3xx_SSP)
val |= SSACD_SCDX8;
else
return -EINVAL;
break;
default:
return -EINVAL;
}
pxa_ssp_write_reg(ssp, SSACD, val);
break;
case PXA_SSP_DIV_SCR:
pxa_ssp_set_scr(ssp, div);
break;
default:
return -ENODEV;
}
return 0;
}
static int pxa_ssp_set_dai_pll(struct snd_soc_dai *cpu_dai, int pll_id,
int source, unsigned int freq_in, unsigned int freq_out)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
u32 ssacd = pxa_ssp_read_reg(ssp, SSACD) & ~0x70;
if (ssp->type == PXA3xx_SSP)
pxa_ssp_write_reg(ssp, SSACDD, 0);
switch (freq_out) {
case 5622000:
break;
case 11345000:
ssacd |= (0x1 << 4);
break;
case 12235000:
ssacd |= (0x2 << 4);
break;
case 14857000:
ssacd |= (0x3 << 4);
break;
case 32842000:
ssacd |= (0x4 << 4);
break;
case 48000000:
ssacd |= (0x5 << 4);
break;
case 0:
break;
default:
if (ssp->type == PXA3xx_SSP) {
u32 val;
u64 tmp = 19968;
tmp *= 1000000;
do_div(tmp, freq_out);
val = tmp;
val = (val << 16) | 64;
pxa_ssp_write_reg(ssp, SSACDD, val);
ssacd |= (0x6 << 4);
dev_dbg(&ssp->pdev->dev,
"Using SSACDD %x to supply %uHz\n",
val, freq_out);
break;
}
return -EINVAL;
}
pxa_ssp_write_reg(ssp, SSACD, ssacd);
return 0;
}
static int pxa_ssp_set_dai_tdm_slot(struct snd_soc_dai *cpu_dai,
unsigned int tx_mask, unsigned int rx_mask, int slots, int slot_width)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
u32 sscr0;
sscr0 = pxa_ssp_read_reg(ssp, SSCR0);
sscr0 &= ~(SSCR0_MOD | SSCR0_SlotsPerFrm(8) | SSCR0_EDSS | SSCR0_DSS);
if (slot_width > 16)
sscr0 |= SSCR0_EDSS | SSCR0_DataSize(slot_width - 16);
else
sscr0 |= SSCR0_DataSize(slot_width);
if (slots > 1) {
sscr0 |= SSCR0_MOD;
sscr0 |= SSCR0_SlotsPerFrm(slots);
pxa_ssp_write_reg(ssp, SSTSA, tx_mask);
pxa_ssp_write_reg(ssp, SSRSA, rx_mask);
}
pxa_ssp_write_reg(ssp, SSCR0, sscr0);
return 0;
}
static int pxa_ssp_set_dai_tristate(struct snd_soc_dai *cpu_dai,
int tristate)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
u32 sscr1;
sscr1 = pxa_ssp_read_reg(ssp, SSCR1);
if (tristate)
sscr1 &= ~SSCR1_TTE;
else
sscr1 |= SSCR1_TTE;
pxa_ssp_write_reg(ssp, SSCR1, sscr1);
return 0;
}
static int pxa_ssp_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
u32 sscr0, sscr1, sspsp, scfr;
if (priv->dai_fmt == fmt)
return 0;
if (pxa_ssp_read_reg(ssp, SSCR0) & SSCR0_SSE) {
dev_err(&ssp->pdev->dev,
"can't change hardware dai format: stream is in use");
return -EINVAL;
}
sscr0 = pxa_ssp_read_reg(ssp, SSCR0) &
~(SSCR0_ECS | SSCR0_NCS | SSCR0_MOD | SSCR0_ACS);
sscr1 = SSCR1_RxTresh(8) | SSCR1_TxTresh(7);
sspsp = 0;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
sscr1 |= SSCR1_SCLKDIR | SSCR1_SFRMDIR | SSCR1_SCFR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
sscr1 |= SSCR1_SCLKDIR | SSCR1_SCFR;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
sspsp |= SSPSP_SFRMP;
break;
case SND_SOC_DAIFMT_NB_IF:
break;
case SND_SOC_DAIFMT_IB_IF:
sspsp |= SSPSP_SCMODE(2);
break;
case SND_SOC_DAIFMT_IB_NF:
sspsp |= SSPSP_SCMODE(2) | SSPSP_SFRMP;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
sscr0 |= SSCR0_PSP;
sscr1 |= SSCR1_RWOT | SSCR1_TRAIL;
break;
case SND_SOC_DAIFMT_DSP_A:
sspsp |= SSPSP_FSRT;
case SND_SOC_DAIFMT_DSP_B:
sscr0 |= SSCR0_MOD | SSCR0_PSP;
sscr1 |= SSCR1_TRAIL | SSCR1_RWOT;
break;
default:
return -EINVAL;
}
pxa_ssp_write_reg(ssp, SSCR0, sscr0);
pxa_ssp_write_reg(ssp, SSCR1, sscr1);
pxa_ssp_write_reg(ssp, SSPSP, sspsp);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
case SND_SOC_DAIFMT_CBM_CFS:
scfr = pxa_ssp_read_reg(ssp, SSCR1) | SSCR1_SCFR;
pxa_ssp_write_reg(ssp, SSCR1, scfr);
while (pxa_ssp_read_reg(ssp, SSSR) & SSSR_BSY)
cpu_relax();
break;
}
dump_registers(ssp);
priv->dai_fmt = fmt;
return 0;
}
static int pxa_ssp_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
int chn = params_channels(params);
u32 sscr0;
u32 sspsp;
int width = snd_pcm_format_physical_width(params_format(params));
int ttsa = pxa_ssp_read_reg(ssp, SSTSA) & 0xf;
struct snd_dmaengine_dai_dma_data *dma_data;
dma_data = snd_soc_dai_get_dma_data(cpu_dai, substream);
pxa_ssp_set_dma_params(ssp,
((chn == 2) && (ttsa != 1)) || (width == 32),
substream->stream == SNDRV_PCM_STREAM_PLAYBACK, dma_data);
if (pxa_ssp_read_reg(ssp, SSCR0) & SSCR0_SSE)
return 0;
sscr0 = pxa_ssp_read_reg(ssp, SSCR0) & ~(SSCR0_DSS | SSCR0_EDSS);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
if (ssp->type == PXA3xx_SSP)
sscr0 |= SSCR0_FPCKE;
sscr0 |= SSCR0_DataSize(16);
break;
case SNDRV_PCM_FORMAT_S24_LE:
sscr0 |= (SSCR0_EDSS | SSCR0_DataSize(8));
break;
case SNDRV_PCM_FORMAT_S32_LE:
sscr0 |= (SSCR0_EDSS | SSCR0_DataSize(16));
break;
}
pxa_ssp_write_reg(ssp, SSCR0, sscr0);
switch (priv->dai_fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
sspsp = pxa_ssp_read_reg(ssp, SSPSP);
if ((pxa_ssp_get_scr(ssp) == 4) && (width == 16)) {
if (ssp->type != PXA3xx_SSP)
return -EINVAL;
sspsp |= SSPSP_SFRMWDTH(width * 2);
sspsp |= SSPSP_SFRMDLY(width * 4);
sspsp |= SSPSP_EDMYSTOP(3);
sspsp |= SSPSP_DMYSTOP(3);
sspsp |= SSPSP_DMYSTRT(1);
} else {
sspsp |= SSPSP_SFRMWDTH(width + 1);
sspsp |= SSPSP_SFRMDLY((width + 1) * 2);
sspsp |= SSPSP_DMYSTRT(1);
}
pxa_ssp_write_reg(ssp, SSPSP, sspsp);
break;
default:
break;
}
if ((sscr0 & SSCR0_MOD) && !ttsa) {
dev_err(&ssp->pdev->dev, "No TDM timeslot configured\n");
return -EINVAL;
}
dump_registers(ssp);
return 0;
}
static void pxa_ssp_set_running_bit(struct snd_pcm_substream *substream,
struct ssp_device *ssp, int value)
{
uint32_t sscr0 = pxa_ssp_read_reg(ssp, SSCR0);
uint32_t sscr1 = pxa_ssp_read_reg(ssp, SSCR1);
uint32_t sspsp = pxa_ssp_read_reg(ssp, SSPSP);
uint32_t sssr = pxa_ssp_read_reg(ssp, SSSR);
if (value && (sscr0 & SSCR0_SSE))
pxa_ssp_write_reg(ssp, SSCR0, sscr0 & ~SSCR0_SSE);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (value)
sscr1 |= SSCR1_TSRE;
else
sscr1 &= ~SSCR1_TSRE;
} else {
if (value)
sscr1 |= SSCR1_RSRE;
else
sscr1 &= ~SSCR1_RSRE;
}
pxa_ssp_write_reg(ssp, SSCR1, sscr1);
if (value) {
pxa_ssp_write_reg(ssp, SSSR, sssr);
pxa_ssp_write_reg(ssp, SSPSP, sspsp);
pxa_ssp_write_reg(ssp, SSCR0, sscr0 | SSCR0_SSE);
}
}
static int pxa_ssp_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
int ret = 0;
struct ssp_priv *priv = snd_soc_dai_get_drvdata(cpu_dai);
struct ssp_device *ssp = priv->ssp;
int val;
switch (cmd) {
case SNDRV_PCM_TRIGGER_RESUME:
pxa_ssp_enable(ssp);
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
pxa_ssp_set_running_bit(substream, ssp, 1);
val = pxa_ssp_read_reg(ssp, SSSR);
pxa_ssp_write_reg(ssp, SSSR, val);
break;
case SNDRV_PCM_TRIGGER_START:
pxa_ssp_set_running_bit(substream, ssp, 1);
break;
case SNDRV_PCM_TRIGGER_STOP:
pxa_ssp_set_running_bit(substream, ssp, 0);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
pxa_ssp_disable(ssp);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
pxa_ssp_set_running_bit(substream, ssp, 0);
break;
default:
ret = -EINVAL;
}
dump_registers(ssp);
return ret;
}
static int pxa_ssp_probe(struct snd_soc_dai *dai)
{
struct device *dev = dai->dev;
struct ssp_priv *priv;
int ret;
priv = kzalloc(sizeof(struct ssp_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (dev->of_node) {
struct device_node *ssp_handle;
ssp_handle = of_parse_phandle(dev->of_node, "port", 0);
if (!ssp_handle) {
dev_err(dev, "unable to get 'port' phandle\n");
return -ENODEV;
}
priv->ssp = pxa_ssp_request_of(ssp_handle, "SoC audio");
if (priv->ssp == NULL) {
ret = -ENODEV;
goto err_priv;
}
} else {
priv->ssp = pxa_ssp_request(dai->id + 1, "SoC audio");
if (priv->ssp == NULL) {
ret = -ENODEV;
goto err_priv;
}
}
priv->dai_fmt = (unsigned int) -1;
snd_soc_dai_set_drvdata(dai, priv);
return 0;
err_priv:
kfree(priv);
return ret;
}
static int pxa_ssp_remove(struct snd_soc_dai *dai)
{
struct ssp_priv *priv = snd_soc_dai_get_drvdata(dai);
pxa_ssp_free(priv->ssp);
kfree(priv);
return 0;
}
static int asoc_ssp_probe(struct platform_device *pdev)
{
return snd_soc_register_component(&pdev->dev, &pxa_ssp_component,
&pxa_ssp_dai, 1);
}
static int asoc_ssp_remove(struct platform_device *pdev)
{
snd_soc_unregister_component(&pdev->dev);
return 0;
}
