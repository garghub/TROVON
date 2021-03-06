static inline void mcasp_set_bits(struct davinci_mcasp *mcasp, u32 offset,
u32 val)
{
void __iomem *reg = mcasp->base + offset;
__raw_writel(__raw_readl(reg) | val, reg);
}
static inline void mcasp_clr_bits(struct davinci_mcasp *mcasp, u32 offset,
u32 val)
{
void __iomem *reg = mcasp->base + offset;
__raw_writel((__raw_readl(reg) & ~(val)), reg);
}
static inline void mcasp_mod_bits(struct davinci_mcasp *mcasp, u32 offset,
u32 val, u32 mask)
{
void __iomem *reg = mcasp->base + offset;
__raw_writel((__raw_readl(reg) & ~mask) | val, reg);
}
static inline void mcasp_set_reg(struct davinci_mcasp *mcasp, u32 offset,
u32 val)
{
__raw_writel(val, mcasp->base + offset);
}
static inline u32 mcasp_get_reg(struct davinci_mcasp *mcasp, u32 offset)
{
return (u32)__raw_readl(mcasp->base + offset);
}
static void mcasp_set_ctl_reg(struct davinci_mcasp *mcasp, u32 ctl_reg, u32 val)
{
int i = 0;
mcasp_set_bits(mcasp, ctl_reg, val);
for (i = 0; i < 1000; i++) {
if ((mcasp_get_reg(mcasp, ctl_reg) & val) == val)
break;
}
if (i == 1000 && ((mcasp_get_reg(mcasp, ctl_reg) & val) != val))
printk(KERN_ERR "GBLCTL write error\n");
}
static bool mcasp_is_synchronous(struct davinci_mcasp *mcasp)
{
u32 rxfmctl = mcasp_get_reg(mcasp, DAVINCI_MCASP_RXFMCTL_REG);
u32 aclkxctl = mcasp_get_reg(mcasp, DAVINCI_MCASP_ACLKXCTL_REG);
return !(aclkxctl & TX_ASYNC) && rxfmctl & AFSRE;
}
static void mcasp_start_rx(struct davinci_mcasp *mcasp)
{
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, RXHCLKRST);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, RXCLKRST);
if (mcasp_is_synchronous(mcasp)) {
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXHCLKRST);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXCLKRST);
}
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, RXSERCLR);
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXBUF_REG, 0);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, RXSMRST);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, RXFSRST);
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXBUF_REG, 0);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, RXSMRST);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, RXFSRST);
if (mcasp_is_synchronous(mcasp))
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXFSRST);
}
static void mcasp_start_tx(struct davinci_mcasp *mcasp)
{
u8 offset = 0, i;
u32 cnt;
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXHCLKRST);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXCLKRST);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXSERCLR);
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXBUF_REG, 0);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXSMRST);
mcasp_set_ctl_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, TXFSRST);
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXBUF_REG, 0);
for (i = 0; i < mcasp->num_serializer; i++) {
if (mcasp->serial_dir[i] == TX_MODE) {
offset = i;
break;
}
}
cnt = 0;
while (!(mcasp_get_reg(mcasp, DAVINCI_MCASP_XRSRCTL_REG(offset)) &
TXSTATE) && (cnt < 100000))
cnt++;
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXBUF_REG, 0);
}
static void davinci_mcasp_start(struct davinci_mcasp *mcasp, int stream)
{
u32 reg;
mcasp->streams++;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (mcasp->txnumevt) {
reg = mcasp->fifo_base + MCASP_WFIFOCTL_OFFSET;
mcasp_clr_bits(mcasp, reg, FIFO_ENABLE);
mcasp_set_bits(mcasp, reg, FIFO_ENABLE);
}
mcasp_start_tx(mcasp);
} else {
if (mcasp->rxnumevt) {
reg = mcasp->fifo_base + MCASP_RFIFOCTL_OFFSET;
mcasp_clr_bits(mcasp, reg, FIFO_ENABLE);
mcasp_set_bits(mcasp, reg, FIFO_ENABLE);
}
mcasp_start_rx(mcasp);
}
}
static void mcasp_stop_rx(struct davinci_mcasp *mcasp)
{
if (mcasp_is_synchronous(mcasp) && !mcasp->streams)
mcasp_set_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, 0);
mcasp_set_reg(mcasp, DAVINCI_MCASP_GBLCTLR_REG, 0);
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXSTAT_REG, 0xFFFFFFFF);
}
static void mcasp_stop_tx(struct davinci_mcasp *mcasp)
{
u32 val = 0;
if (mcasp_is_synchronous(mcasp) && mcasp->streams)
val = TXHCLKRST | TXCLKRST | TXFSRST;
mcasp_set_reg(mcasp, DAVINCI_MCASP_GBLCTLX_REG, val);
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXSTAT_REG, 0xFFFFFFFF);
}
static void davinci_mcasp_stop(struct davinci_mcasp *mcasp, int stream)
{
u32 reg;
mcasp->streams--;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (mcasp->txnumevt) {
reg = mcasp->fifo_base + MCASP_WFIFOCTL_OFFSET;
mcasp_clr_bits(mcasp, reg, FIFO_ENABLE);
}
mcasp_stop_tx(mcasp);
} else {
if (mcasp->rxnumevt) {
reg = mcasp->fifo_base + MCASP_RFIFOCTL_OFFSET;
mcasp_clr_bits(mcasp, reg, FIFO_ENABLE);
}
mcasp_stop_rx(mcasp);
}
}
static int davinci_mcasp_set_dai_fmt(struct snd_soc_dai *cpu_dai,
unsigned int fmt)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(cpu_dai);
int ret = 0;
pm_runtime_get_sync(mcasp->dev);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_B:
case SND_SOC_DAIFMT_AC97:
mcasp_clr_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, FSXDUR);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, FSRDUR);
break;
default:
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, FSXDUR);
mcasp_set_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, FSRDUR);
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMT_REG, FSXDLY(1));
mcasp_set_bits(mcasp, DAVINCI_MCASP_RXFMT_REG, FSRDLY(1));
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
mcasp_set_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, AFSXE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, ACLKRE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, AFSRE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_PDIR_REG, ACLKX | ACLKR);
mcasp_set_bits(mcasp, DAVINCI_MCASP_PDIR_REG, AFSX | AFSR);
mcasp->bclk_master = 1;
break;
case SND_SOC_DAIFMT_CBM_CFS:
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, AFSXE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, ACLKRE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, AFSRE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_PDIR_REG, ACLKX | ACLKR);
mcasp_set_bits(mcasp, DAVINCI_MCASP_PDIR_REG, AFSX | AFSR);
mcasp->bclk_master = 0;
break;
case SND_SOC_DAIFMT_CBM_CFM:
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, AFSXE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, ACLKRE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, AFSRE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_PDIR_REG,
ACLKX | AHCLKX | AFSX | ACLKR | AHCLKR | AFSR);
mcasp->bclk_master = 0;
break;
default:
ret = -EINVAL;
goto out;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_IB_NF:
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
case SND_SOC_DAIFMT_NB_IF:
mcasp_set_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_set_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_set_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
case SND_SOC_DAIFMT_IB_IF:
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_set_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
case SND_SOC_DAIFMT_NB_NF:
mcasp_set_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXPOL);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG, FSXPOL);
mcasp_set_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, ACLKRPOL);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG, FSRPOL);
break;
default:
ret = -EINVAL;
break;
}
out:
pm_runtime_put_sync(mcasp->dev);
return ret;
}
static int davinci_mcasp_set_clkdiv(struct snd_soc_dai *dai, int div_id, int div)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(dai);
switch (div_id) {
case 0:
mcasp_mod_bits(mcasp, DAVINCI_MCASP_AHCLKXCTL_REG,
AHCLKXDIV(div - 1), AHCLKXDIV_MASK);
mcasp_mod_bits(mcasp, DAVINCI_MCASP_AHCLKRCTL_REG,
AHCLKRDIV(div - 1), AHCLKRDIV_MASK);
break;
case 1:
mcasp_mod_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG,
ACLKXDIV(div - 1), ACLKXDIV_MASK);
mcasp_mod_bits(mcasp, DAVINCI_MCASP_ACLKRCTL_REG,
ACLKRDIV(div - 1), ACLKRDIV_MASK);
break;
case 2:
mcasp->bclk_lrclk_ratio = div;
break;
default:
return -EINVAL;
}
return 0;
}
static int davinci_mcasp_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(dai);
if (dir == SND_SOC_CLOCK_OUT) {
mcasp_set_bits(mcasp, DAVINCI_MCASP_AHCLKXCTL_REG, AHCLKXE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_AHCLKRCTL_REG, AHCLKRE);
mcasp_set_bits(mcasp, DAVINCI_MCASP_PDIR_REG, AHCLKX);
} else {
mcasp_clr_bits(mcasp, DAVINCI_MCASP_AHCLKXCTL_REG, AHCLKXE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_AHCLKRCTL_REG, AHCLKRE);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_PDIR_REG, AHCLKX);
}
mcasp->sysclk_freq = freq;
return 0;
}
static int davinci_config_channel_size(struct davinci_mcasp *mcasp,
int word_length)
{
u32 fmt;
u32 tx_rotate = (word_length / 4) & 0x7;
u32 rx_rotate = (32 - word_length) / 4;
u32 mask = (1ULL << word_length) - 1;
if (mcasp->bclk_lrclk_ratio)
word_length = mcasp->bclk_lrclk_ratio / mcasp->tdm_slots;
fmt = (word_length >> 1) - 1;
if (mcasp->op_mode != DAVINCI_MCASP_DIT_MODE) {
mcasp_mod_bits(mcasp, DAVINCI_MCASP_RXFMT_REG, RXSSZ(fmt),
RXSSZ(0x0F));
mcasp_mod_bits(mcasp, DAVINCI_MCASP_TXFMT_REG, TXSSZ(fmt),
TXSSZ(0x0F));
mcasp_mod_bits(mcasp, DAVINCI_MCASP_TXFMT_REG, TXROT(tx_rotate),
TXROT(7));
mcasp_mod_bits(mcasp, DAVINCI_MCASP_RXFMT_REG, RXROT(rx_rotate),
RXROT(7));
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXMASK_REG, mask);
}
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXMASK_REG, mask);
return 0;
}
static int mcasp_common_hw_param(struct davinci_mcasp *mcasp, int stream,
int channels)
{
int i;
u8 tx_ser = 0;
u8 rx_ser = 0;
u8 ser;
u8 slots = mcasp->tdm_slots;
u8 max_active_serializers = (channels + slots - 1) / slots;
u32 reg;
if (mcasp->version != MCASP_VERSION_4)
mcasp_set_bits(mcasp, DAVINCI_MCASP_PWREMUMGT_REG, MCASP_SOFT);
mcasp_set_reg(mcasp, DAVINCI_MCASP_PFUNC_REG, 0x00000000);
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXSTAT_REG, 0xFFFFFFFF);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_XEVTCTL_REG, TXDATADMADIS);
} else {
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXSTAT_REG, 0xFFFFFFFF);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_REVTCTL_REG, RXDATADMADIS);
}
for (i = 0; i < mcasp->num_serializer; i++) {
mcasp_set_bits(mcasp, DAVINCI_MCASP_XRSRCTL_REG(i),
mcasp->serial_dir[i]);
if (mcasp->serial_dir[i] == TX_MODE &&
tx_ser < max_active_serializers) {
mcasp_set_bits(mcasp, DAVINCI_MCASP_PDIR_REG, AXR(i));
tx_ser++;
} else if (mcasp->serial_dir[i] == RX_MODE &&
rx_ser < max_active_serializers) {
mcasp_clr_bits(mcasp, DAVINCI_MCASP_PDIR_REG, AXR(i));
rx_ser++;
} else {
mcasp_mod_bits(mcasp, DAVINCI_MCASP_XRSRCTL_REG(i),
SRMOD_INACTIVE, SRMOD_MASK);
}
}
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
ser = tx_ser;
else
ser = rx_ser;
if (ser < max_active_serializers) {
dev_warn(mcasp->dev, "stream has more channels (%d) than are "
"enabled in mcasp (%d)\n", channels, ser * slots);
return -EINVAL;
}
if (mcasp->txnumevt && stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (mcasp->txnumevt * tx_ser > 64)
mcasp->txnumevt = 1;
reg = mcasp->fifo_base + MCASP_WFIFOCTL_OFFSET;
mcasp_mod_bits(mcasp, reg, tx_ser, NUMDMA_MASK);
mcasp_mod_bits(mcasp, reg, ((mcasp->txnumevt * tx_ser) << 8),
NUMEVT_MASK);
}
if (mcasp->rxnumevt && stream == SNDRV_PCM_STREAM_CAPTURE) {
if (mcasp->rxnumevt * rx_ser > 64)
mcasp->rxnumevt = 1;
reg = mcasp->fifo_base + MCASP_RFIFOCTL_OFFSET;
mcasp_mod_bits(mcasp, reg, rx_ser, NUMDMA_MASK);
mcasp_mod_bits(mcasp, reg, ((mcasp->rxnumevt * rx_ser) << 8),
NUMEVT_MASK);
}
return 0;
}
static int mcasp_i2s_hw_param(struct davinci_mcasp *mcasp, int stream)
{
int i, active_slots;
u32 mask = 0;
u32 busel = 0;
if ((mcasp->tdm_slots < 2) || (mcasp->tdm_slots > 32)) {
dev_err(mcasp->dev, "tdm slot %d not supported\n",
mcasp->tdm_slots);
return -EINVAL;
}
active_slots = (mcasp->tdm_slots > 31) ? 32 : mcasp->tdm_slots;
for (i = 0; i < active_slots; i++)
mask |= (1 << i);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, TX_ASYNC);
if (!mcasp->dat_port)
busel = TXSEL;
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXTDM_REG, mask);
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMT_REG, busel | TXORD);
mcasp_mod_bits(mcasp, DAVINCI_MCASP_TXFMCTL_REG,
FSXMOD(mcasp->tdm_slots), FSXMOD(0x1FF));
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXTDM_REG, mask);
mcasp_set_bits(mcasp, DAVINCI_MCASP_RXFMT_REG, busel | RXORD);
mcasp_mod_bits(mcasp, DAVINCI_MCASP_RXFMCTL_REG,
FSRMOD(mcasp->tdm_slots), FSRMOD(0x1FF));
return 0;
}
static int mcasp_dit_hw_param(struct davinci_mcasp *mcasp)
{
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXFMT_REG, TXROT(6) | TXSSZ(15));
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXFMCTL_REG, AFSXE | FSXMOD(0x180));
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXTDM_REG, 0xFFFFFFFF);
mcasp_set_bits(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, ACLKXE | TX_ASYNC);
mcasp_clr_bits(mcasp, DAVINCI_MCASP_XEVTCTL_REG, TXDATADMADIS);
mcasp_set_bits(mcasp, DAVINCI_MCASP_AHCLKXCTL_REG, AHCLKXDIV(3));
mcasp_set_bits(mcasp, DAVINCI_MCASP_TXDITCTL_REG, DITEN);
return 0;
}
static int davinci_mcasp_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(cpu_dai);
struct davinci_pcm_dma_params *dma_params =
&mcasp->dma_params[substream->stream];
struct snd_dmaengine_dai_dma_data *dma_data =
&mcasp->dma_data[substream->stream];
int word_length;
u8 fifo_level;
u8 slots = mcasp->tdm_slots;
u8 active_serializers;
int channels = params_channels(params);
int ret;
if (mcasp->bclk_master) {
unsigned int bclk_freq = snd_soc_params_to_bclk(params);
if (mcasp->sysclk_freq % bclk_freq != 0) {
dev_err(mcasp->dev, "Can't produce requred BCLK\n");
return -EINVAL;
}
davinci_mcasp_set_clkdiv(
cpu_dai, 1, mcasp->sysclk_freq / bclk_freq);
}
ret = mcasp_common_hw_param(mcasp, substream->stream, channels);
if (ret)
return ret;
if (mcasp->op_mode == DAVINCI_MCASP_DIT_MODE)
ret = mcasp_dit_hw_param(mcasp);
else
ret = mcasp_i2s_hw_param(mcasp, substream->stream);
if (ret)
return ret;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_U8:
case SNDRV_PCM_FORMAT_S8:
dma_params->data_type = 1;
word_length = 8;
break;
case SNDRV_PCM_FORMAT_U16_LE:
case SNDRV_PCM_FORMAT_S16_LE:
dma_params->data_type = 2;
word_length = 16;
break;
case SNDRV_PCM_FORMAT_U24_3LE:
case SNDRV_PCM_FORMAT_S24_3LE:
dma_params->data_type = 3;
word_length = 24;
break;
case SNDRV_PCM_FORMAT_U24_LE:
case SNDRV_PCM_FORMAT_S24_LE:
case SNDRV_PCM_FORMAT_U32_LE:
case SNDRV_PCM_FORMAT_S32_LE:
dma_params->data_type = 4;
word_length = 32;
break;
default:
printk(KERN_WARNING "davinci-mcasp: unsupported PCM format");
return -EINVAL;
}
active_serializers = (channels + slots - 1) / slots;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fifo_level = mcasp->txnumevt * active_serializers;
else
fifo_level = mcasp->rxnumevt * active_serializers;
if (mcasp->version == MCASP_VERSION_2 && !fifo_level)
dma_params->acnt = 4;
else
dma_params->acnt = dma_params->data_type;
dma_params->fifo_level = fifo_level;
dma_data->maxburst = fifo_level;
davinci_config_channel_size(mcasp, word_length);
return 0;
}
static int davinci_mcasp_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *cpu_dai)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(cpu_dai);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
davinci_mcasp_start(mcasp, substream->stream);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
davinci_mcasp_stop(mcasp, substream->stream);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int davinci_mcasp_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(dai);
if (mcasp->version == MCASP_VERSION_4)
snd_soc_dai_set_dma_data(dai, substream,
&mcasp->dma_data[substream->stream]);
else
snd_soc_dai_set_dma_data(dai, substream, mcasp->dma_params);
return 0;
}
static int davinci_mcasp_suspend(struct snd_soc_dai *dai)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(dai);
struct davinci_mcasp_context *context = &mcasp->context;
context->txfmtctl = mcasp_get_reg(mcasp, DAVINCI_MCASP_TXFMCTL_REG);
context->rxfmtctl = mcasp_get_reg(mcasp, DAVINCI_MCASP_RXFMCTL_REG);
context->txfmt = mcasp_get_reg(mcasp, DAVINCI_MCASP_TXFMT_REG);
context->rxfmt = mcasp_get_reg(mcasp, DAVINCI_MCASP_RXFMT_REG);
context->aclkxctl = mcasp_get_reg(mcasp, DAVINCI_MCASP_ACLKXCTL_REG);
context->aclkrctl = mcasp_get_reg(mcasp, DAVINCI_MCASP_ACLKRCTL_REG);
context->pdir = mcasp_get_reg(mcasp, DAVINCI_MCASP_PDIR_REG);
return 0;
}
static int davinci_mcasp_resume(struct snd_soc_dai *dai)
{
struct davinci_mcasp *mcasp = snd_soc_dai_get_drvdata(dai);
struct davinci_mcasp_context *context = &mcasp->context;
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXFMCTL_REG, context->txfmtctl);
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXFMCTL_REG, context->rxfmtctl);
mcasp_set_reg(mcasp, DAVINCI_MCASP_TXFMT_REG, context->txfmt);
mcasp_set_reg(mcasp, DAVINCI_MCASP_RXFMT_REG, context->rxfmt);
mcasp_set_reg(mcasp, DAVINCI_MCASP_ACLKXCTL_REG, context->aclkxctl);
mcasp_set_reg(mcasp, DAVINCI_MCASP_ACLKRCTL_REG, context->aclkrctl);
mcasp_set_reg(mcasp, DAVINCI_MCASP_PDIR_REG, context->pdir);
return 0;
}
static int mcasp_reparent_fck(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct clk *gfclk, *parent_clk;
const char *parent_name;
int ret;
if (!node)
return 0;
parent_name = of_get_property(node, "fck_parent", NULL);
if (!parent_name)
return 0;
gfclk = clk_get(&pdev->dev, "fck");
if (IS_ERR(gfclk)) {
dev_err(&pdev->dev, "failed to get fck\n");
return PTR_ERR(gfclk);
}
parent_clk = clk_get(NULL, parent_name);
if (IS_ERR(parent_clk)) {
dev_err(&pdev->dev, "failed to get parent clock\n");
ret = PTR_ERR(parent_clk);
goto err1;
}
ret = clk_set_parent(gfclk, parent_clk);
if (ret) {
dev_err(&pdev->dev, "failed to reparent fck\n");
goto err2;
}
err2:
clk_put(parent_clk);
err1:
clk_put(gfclk);
return ret;
}
static struct davinci_mcasp_pdata *davinci_mcasp_set_pdata_from_of(
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct davinci_mcasp_pdata *pdata = NULL;
const struct of_device_id *match =
of_match_device(mcasp_dt_ids, &pdev->dev);
struct of_phandle_args dma_spec;
const u32 *of_serial_dir32;
u32 val;
int i, ret = 0;
if (pdev->dev.platform_data) {
pdata = pdev->dev.platform_data;
return pdata;
} else if (match) {
pdata = (struct davinci_mcasp_pdata*) match->data;
} else {
ret = -EINVAL;
goto nodata;
}
ret = of_property_read_u32(np, "op-mode", &val);
if (ret >= 0)
pdata->op_mode = val;
ret = of_property_read_u32(np, "tdm-slots", &val);
if (ret >= 0) {
if (val < 2 || val > 32) {
dev_err(&pdev->dev,
"tdm-slots must be in rage [2-32]\n");
ret = -EINVAL;
goto nodata;
}
pdata->tdm_slots = val;
}
of_serial_dir32 = of_get_property(np, "serial-dir", &val);
val /= sizeof(u32);
if (of_serial_dir32) {
u8 *of_serial_dir = devm_kzalloc(&pdev->dev,
(sizeof(*of_serial_dir) * val),
GFP_KERNEL);
if (!of_serial_dir) {
ret = -ENOMEM;
goto nodata;
}
for (i = 0; i < val; i++)
of_serial_dir[i] = be32_to_cpup(&of_serial_dir32[i]);
pdata->num_serializer = val;
pdata->serial_dir = of_serial_dir;
}
ret = of_property_match_string(np, "dma-names", "tx");
if (ret < 0)
goto nodata;
ret = of_parse_phandle_with_args(np, "dmas", "#dma-cells", ret,
&dma_spec);
if (ret < 0)
goto nodata;
pdata->tx_dma_channel = dma_spec.args[0];
ret = of_property_match_string(np, "dma-names", "rx");
if (ret < 0)
goto nodata;
ret = of_parse_phandle_with_args(np, "dmas", "#dma-cells", ret,
&dma_spec);
if (ret < 0)
goto nodata;
pdata->rx_dma_channel = dma_spec.args[0];
ret = of_property_read_u32(np, "tx-num-evt", &val);
if (ret >= 0)
pdata->txnumevt = val;
ret = of_property_read_u32(np, "rx-num-evt", &val);
if (ret >= 0)
pdata->rxnumevt = val;
ret = of_property_read_u32(np, "sram-size-playback", &val);
if (ret >= 0)
pdata->sram_size_playback = val;
ret = of_property_read_u32(np, "sram-size-capture", &val);
if (ret >= 0)
pdata->sram_size_capture = val;
return pdata;
nodata:
if (ret < 0) {
dev_err(&pdev->dev, "Error populating platform data, err %d\n",
ret);
pdata = NULL;
}
return pdata;
}
static int davinci_mcasp_probe(struct platform_device *pdev)
{
struct davinci_pcm_dma_params *dma_params;
struct snd_dmaengine_dai_dma_data *dma_data;
struct resource *mem, *ioarea, *res, *dat;
struct davinci_mcasp_pdata *pdata;
struct davinci_mcasp *mcasp;
int ret;
if (!pdev->dev.platform_data && !pdev->dev.of_node) {
dev_err(&pdev->dev, "No platform data supplied\n");
return -EINVAL;
}
mcasp = devm_kzalloc(&pdev->dev, sizeof(struct davinci_mcasp),
GFP_KERNEL);
if (!mcasp)
return -ENOMEM;
pdata = davinci_mcasp_set_pdata_from_of(pdev);
if (!pdata) {
dev_err(&pdev->dev, "no platform data\n");
return -EINVAL;
}
mem = platform_get_resource_byname(pdev, IORESOURCE_MEM, "mpu");
if (!mem) {
dev_warn(mcasp->dev,
"\"mpu\" mem resource not found, using index 0\n");
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -ENODEV;
}
}
ioarea = devm_request_mem_region(&pdev->dev, mem->start,
resource_size(mem), pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "Audio region already claimed\n");
return -EBUSY;
}
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (IS_ERR_VALUE(ret)) {
dev_err(&pdev->dev, "pm_runtime_get_sync() failed\n");
return ret;
}
mcasp->base = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (!mcasp->base) {
dev_err(&pdev->dev, "ioremap failed\n");
ret = -ENOMEM;
goto err_release_clk;
}
mcasp->op_mode = pdata->op_mode;
mcasp->tdm_slots = pdata->tdm_slots;
mcasp->num_serializer = pdata->num_serializer;
mcasp->serial_dir = pdata->serial_dir;
mcasp->version = pdata->version;
mcasp->txnumevt = pdata->txnumevt;
mcasp->rxnumevt = pdata->rxnumevt;
mcasp->dev = &pdev->dev;
dat = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dat");
if (dat)
mcasp->dat_port = true;
dma_params = &mcasp->dma_params[SNDRV_PCM_STREAM_PLAYBACK];
dma_data = &mcasp->dma_data[SNDRV_PCM_STREAM_PLAYBACK];
dma_params->asp_chan_q = pdata->asp_chan_q;
dma_params->ram_chan_q = pdata->ram_chan_q;
dma_params->sram_pool = pdata->sram_pool;
dma_params->sram_size = pdata->sram_size_playback;
if (dat)
dma_params->dma_addr = dat->start;
else
dma_params->dma_addr = mem->start + pdata->tx_dma_offset;
dma_data->addr = dma_params->dma_addr;
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (res)
dma_params->channel = res->start;
else
dma_params->channel = pdata->tx_dma_channel;
if (pdev->dev.of_node)
dma_data->filter_data = "tx";
else
dma_data->filter_data = &dma_params->channel;
dma_params = &mcasp->dma_params[SNDRV_PCM_STREAM_CAPTURE];
dma_data = &mcasp->dma_data[SNDRV_PCM_STREAM_CAPTURE];
dma_params->asp_chan_q = pdata->asp_chan_q;
dma_params->ram_chan_q = pdata->ram_chan_q;
dma_params->sram_pool = pdata->sram_pool;
dma_params->sram_size = pdata->sram_size_capture;
if (dat)
dma_params->dma_addr = dat->start;
else
dma_params->dma_addr = mem->start + pdata->rx_dma_offset;
dma_data->addr = dma_params->dma_addr;
if (mcasp->version < MCASP_VERSION_3) {
mcasp->fifo_base = DAVINCI_MCASP_V2_AFIFO_BASE;
mcasp->dat_port = true;
} else {
mcasp->fifo_base = DAVINCI_MCASP_V3_AFIFO_BASE;
}
res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (res)
dma_params->channel = res->start;
else
dma_params->channel = pdata->rx_dma_channel;
if (pdev->dev.of_node)
dma_data->filter_data = "rx";
else
dma_data->filter_data = &dma_params->channel;
dev_set_drvdata(&pdev->dev, mcasp);
mcasp_reparent_fck(pdev);
ret = snd_soc_register_component(&pdev->dev, &davinci_mcasp_component,
&davinci_mcasp_dai[pdata->op_mode], 1);
if (ret != 0)
goto err_release_clk;
if (mcasp->version != MCASP_VERSION_4) {
ret = davinci_soc_platform_register(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "register PCM failed: %d\n", ret);
goto err_unregister_component;
}
}
return 0;
err_unregister_component:
snd_soc_unregister_component(&pdev->dev);
err_release_clk:
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int davinci_mcasp_remove(struct platform_device *pdev)
{
struct davinci_mcasp *mcasp = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
if (mcasp->version != MCASP_VERSION_4)
davinci_soc_platform_unregister(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
