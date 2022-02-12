static bool fsl_ssi_is_ac97(struct fsl_ssi_private *ssi_private)
{
return (ssi_private->dai_fmt & SND_SOC_DAIFMT_FORMAT_MASK) ==
SND_SOC_DAIFMT_AC97;
}
static bool fsl_ssi_is_i2s_master(struct fsl_ssi_private *ssi_private)
{
return (ssi_private->dai_fmt & SND_SOC_DAIFMT_MASTER_MASK) ==
SND_SOC_DAIFMT_CBS_CFS;
}
static bool fsl_ssi_is_i2s_cbm_cfs(struct fsl_ssi_private *ssi_private)
{
return (ssi_private->dai_fmt & SND_SOC_DAIFMT_MASTER_MASK) ==
SND_SOC_DAIFMT_CBM_CFS;
}
static irqreturn_t fsl_ssi_isr(int irq, void *dev_id)
{
struct fsl_ssi_private *ssi_private = dev_id;
struct regmap *regs = ssi_private->regs;
__be32 sisr;
__be32 sisr2;
regmap_read(regs, CCSR_SSI_SISR, &sisr);
sisr2 = sisr & ssi_private->soc->sisr_write_mask;
if (sisr2)
regmap_write(regs, CCSR_SSI_SISR, sisr2);
fsl_ssi_dbg_isr(&ssi_private->dbg_stats, sisr);
return IRQ_HANDLED;
}
static void fsl_ssi_rxtx_config(struct fsl_ssi_private *ssi_private,
bool enable)
{
struct regmap *regs = ssi_private->regs;
struct fsl_ssi_rxtx_reg_val *vals = &ssi_private->rxtx_reg_val;
if (enable) {
regmap_update_bits(regs, CCSR_SSI_SIER,
vals->rx.sier | vals->tx.sier,
vals->rx.sier | vals->tx.sier);
regmap_update_bits(regs, CCSR_SSI_SRCR,
vals->rx.srcr | vals->tx.srcr,
vals->rx.srcr | vals->tx.srcr);
regmap_update_bits(regs, CCSR_SSI_STCR,
vals->rx.stcr | vals->tx.stcr,
vals->rx.stcr | vals->tx.stcr);
} else {
regmap_update_bits(regs, CCSR_SSI_SRCR,
vals->rx.srcr | vals->tx.srcr, 0);
regmap_update_bits(regs, CCSR_SSI_STCR,
vals->rx.stcr | vals->tx.stcr, 0);
regmap_update_bits(regs, CCSR_SSI_SIER,
vals->rx.sier | vals->tx.sier, 0);
}
}
static void fsl_ssi_config(struct fsl_ssi_private *ssi_private, bool enable,
struct fsl_ssi_reg_val *vals)
{
struct regmap *regs = ssi_private->regs;
struct fsl_ssi_reg_val *avals;
int nr_active_streams;
u32 scr_val;
int keep_active;
regmap_read(regs, CCSR_SSI_SCR, &scr_val);
nr_active_streams = !!(scr_val & CCSR_SSI_SCR_TE) +
!!(scr_val & CCSR_SSI_SCR_RE);
if (nr_active_streams - 1 > 0)
keep_active = 1;
else
keep_active = 0;
if (&ssi_private->rxtx_reg_val.rx == vals)
avals = &ssi_private->rxtx_reg_val.tx;
else
avals = &ssi_private->rxtx_reg_val.rx;
if (!enable) {
u32 scr = fsl_ssi_disable_val(vals->scr, avals->scr,
keep_active);
regmap_update_bits(regs, CCSR_SSI_SCR, scr, 0);
}
if (ssi_private->soc->offline_config) {
if ((enable && !nr_active_streams) ||
(!enable && !keep_active))
fsl_ssi_rxtx_config(ssi_private, enable);
goto config_done;
}
if (enable) {
regmap_update_bits(regs, CCSR_SSI_SIER, vals->sier, vals->sier);
regmap_update_bits(regs, CCSR_SSI_SRCR, vals->srcr, vals->srcr);
regmap_update_bits(regs, CCSR_SSI_STCR, vals->stcr, vals->stcr);
} else {
u32 sier;
u32 srcr;
u32 stcr;
sier = fsl_ssi_disable_val(vals->sier, avals->sier,
keep_active);
srcr = fsl_ssi_disable_val(vals->srcr, avals->srcr,
keep_active);
stcr = fsl_ssi_disable_val(vals->stcr, avals->stcr,
keep_active);
regmap_update_bits(regs, CCSR_SSI_SRCR, srcr, 0);
regmap_update_bits(regs, CCSR_SSI_STCR, stcr, 0);
regmap_update_bits(regs, CCSR_SSI_SIER, sier, 0);
}
config_done:
if (enable)
regmap_update_bits(regs, CCSR_SSI_SCR, vals->scr, vals->scr);
}
static void fsl_ssi_rx_config(struct fsl_ssi_private *ssi_private, bool enable)
{
fsl_ssi_config(ssi_private, enable, &ssi_private->rxtx_reg_val.rx);
}
static void fsl_ssi_tx_config(struct fsl_ssi_private *ssi_private, bool enable)
{
fsl_ssi_config(ssi_private, enable, &ssi_private->rxtx_reg_val.tx);
}
static void fsl_ssi_setup_reg_vals(struct fsl_ssi_private *ssi_private)
{
struct fsl_ssi_rxtx_reg_val *reg = &ssi_private->rxtx_reg_val;
reg->rx.sier = CCSR_SSI_SIER_RFF0_EN;
reg->rx.srcr = CCSR_SSI_SRCR_RFEN0;
reg->rx.scr = 0;
reg->tx.sier = CCSR_SSI_SIER_TFE0_EN;
reg->tx.stcr = CCSR_SSI_STCR_TFEN0;
reg->tx.scr = 0;
if (!fsl_ssi_is_ac97(ssi_private)) {
reg->rx.scr = CCSR_SSI_SCR_SSIEN | CCSR_SSI_SCR_RE;
reg->rx.sier |= CCSR_SSI_SIER_RFF0_EN;
reg->tx.scr = CCSR_SSI_SCR_SSIEN | CCSR_SSI_SCR_TE;
reg->tx.sier |= CCSR_SSI_SIER_TFE0_EN;
}
if (ssi_private->use_dma) {
reg->rx.sier |= CCSR_SSI_SIER_RDMAE;
reg->tx.sier |= CCSR_SSI_SIER_TDMAE;
} else {
reg->rx.sier |= CCSR_SSI_SIER_RIE;
reg->tx.sier |= CCSR_SSI_SIER_TIE;
}
reg->rx.sier |= FSLSSI_SIER_DBG_RX_FLAGS;
reg->tx.sier |= FSLSSI_SIER_DBG_TX_FLAGS;
}
static void fsl_ssi_setup_ac97(struct fsl_ssi_private *ssi_private)
{
struct regmap *regs = ssi_private->regs;
regmap_write(regs, CCSR_SSI_STCCR,
CCSR_SSI_SxCCR_WL(17) | CCSR_SSI_SxCCR_DC(13));
regmap_write(regs, CCSR_SSI_SRCCR,
CCSR_SSI_SxCCR_WL(17) | CCSR_SSI_SxCCR_DC(13));
regmap_write(regs, CCSR_SSI_SACNT,
CCSR_SSI_SACNT_AC97EN | CCSR_SSI_SACNT_FV);
regmap_write(regs, CCSR_SSI_SACCDIS, 0xff);
regmap_write(regs, CCSR_SSI_SACCEN, 0x300);
regmap_update_bits(regs, CCSR_SSI_SCR,
CCSR_SSI_SCR_SSIEN | CCSR_SSI_SCR_TE | CCSR_SSI_SCR_RE,
CCSR_SSI_SCR_SSIEN | CCSR_SSI_SCR_TE | CCSR_SSI_SCR_RE);
regmap_write(regs, CCSR_SSI_SOR, CCSR_SSI_SOR_WAIT(3));
}
static int fsl_ssi_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private =
snd_soc_dai_get_drvdata(rtd->cpu_dai);
int ret;
ret = clk_prepare_enable(ssi_private->clk);
if (ret)
return ret;
if (ssi_private->use_dual_fifo)
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE, 2);
return 0;
}
static void fsl_ssi_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private =
snd_soc_dai_get_drvdata(rtd->cpu_dai);
clk_disable_unprepare(ssi_private->clk);
}
static int fsl_ssi_set_bclk(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai,
struct snd_pcm_hw_params *hw_params)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct regmap *regs = ssi_private->regs;
int synchronous = ssi_private->cpu_dai_drv.symmetric_rates, ret;
u32 pm = 999, div2, psr, stccr, mask, afreq, factor, i;
unsigned long clkrate, baudrate, tmprate;
u64 sub, savesub = 100000;
unsigned int freq;
bool baudclk_is_used;
if (ssi_private->bitclk_freq)
freq = ssi_private->bitclk_freq;
else
freq = params_channels(hw_params) * 32 * params_rate(hw_params);
if (IS_ERR(ssi_private->baudclk))
return -EINVAL;
baudclk_is_used = ssi_private->baudclk_streams & ~(BIT(substream->stream));
psr = 0;
div2 = 0;
factor = (div2 + 1) * (7 * psr + 1) * 2;
for (i = 0; i < 255; i++) {
tmprate = freq * factor * (i + 1);
if (baudclk_is_used)
clkrate = clk_get_rate(ssi_private->baudclk);
else
clkrate = clk_round_rate(ssi_private->baudclk, tmprate);
if (clkrate * 5 > clk_get_rate(ssi_private->clk))
continue;
clkrate /= factor;
afreq = clkrate / (i + 1);
if (freq == afreq)
sub = 0;
else if (freq / afreq == 1)
sub = freq - afreq;
else if (afreq / freq == 1)
sub = afreq - freq;
else
continue;
sub *= 100000;
do_div(sub, freq);
if (sub < savesub && !(i == 0 && psr == 0 && div2 == 0)) {
baudrate = tmprate;
savesub = sub;
pm = i;
}
if (savesub == 0)
break;
}
if (pm == 999) {
dev_err(cpu_dai->dev, "failed to handle the required sysclk\n");
return -EINVAL;
}
stccr = CCSR_SSI_SxCCR_PM(pm + 1) | (div2 ? CCSR_SSI_SxCCR_DIV2 : 0) |
(psr ? CCSR_SSI_SxCCR_PSR : 0);
mask = CCSR_SSI_SxCCR_PM_MASK | CCSR_SSI_SxCCR_DIV2 |
CCSR_SSI_SxCCR_PSR;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK || synchronous)
regmap_update_bits(regs, CCSR_SSI_STCCR, mask, stccr);
else
regmap_update_bits(regs, CCSR_SSI_SRCCR, mask, stccr);
if (!baudclk_is_used) {
ret = clk_set_rate(ssi_private->baudclk, baudrate);
if (ret) {
dev_err(cpu_dai->dev, "failed to set baudclk rate\n");
return -EINVAL;
}
}
return 0;
}
static int fsl_ssi_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
ssi_private->bitclk_freq = freq;
return 0;
}
static int fsl_ssi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params, struct snd_soc_dai *cpu_dai)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct regmap *regs = ssi_private->regs;
unsigned int channels = params_channels(hw_params);
unsigned int sample_size =
snd_pcm_format_width(params_format(hw_params));
u32 wl = CCSR_SSI_SxCCR_WL(sample_size);
int ret;
u32 scr_val;
int enabled;
regmap_read(regs, CCSR_SSI_SCR, &scr_val);
enabled = scr_val & CCSR_SSI_SCR_SSIEN;
if (enabled && ssi_private->cpu_dai_drv.symmetric_rates)
return 0;
if (fsl_ssi_is_i2s_master(ssi_private)) {
ret = fsl_ssi_set_bclk(substream, cpu_dai, hw_params);
if (ret)
return ret;
if (!(ssi_private->baudclk_streams & BIT(substream->stream))) {
ret = clk_prepare_enable(ssi_private->baudclk);
if (ret)
return ret;
ssi_private->baudclk_streams |= BIT(substream->stream);
}
}
if (!fsl_ssi_is_ac97(ssi_private)) {
u8 i2smode;
if (fsl_ssi_is_i2s_cbm_cfs(ssi_private) && sample_size == 16)
i2smode = CCSR_SSI_SCR_I2S_MODE_NORMAL |
CCSR_SSI_SCR_NET;
else
i2smode = ssi_private->i2s_mode;
regmap_update_bits(regs, CCSR_SSI_SCR,
CCSR_SSI_SCR_NET | CCSR_SSI_SCR_I2S_MODE_MASK,
channels == 1 ? 0 : i2smode);
}
if ((substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ||
ssi_private->cpu_dai_drv.symmetric_rates)
regmap_update_bits(regs, CCSR_SSI_STCCR, CCSR_SSI_SxCCR_WL_MASK,
wl);
else
regmap_update_bits(regs, CCSR_SSI_SRCCR, CCSR_SSI_SxCCR_WL_MASK,
wl);
return 0;
}
static int fsl_ssi_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private =
snd_soc_dai_get_drvdata(rtd->cpu_dai);
if (fsl_ssi_is_i2s_master(ssi_private) &&
ssi_private->baudclk_streams & BIT(substream->stream)) {
clk_disable_unprepare(ssi_private->baudclk);
ssi_private->baudclk_streams &= ~BIT(substream->stream);
}
return 0;
}
static int _fsl_ssi_set_dai_fmt(struct device *dev,
struct fsl_ssi_private *ssi_private,
unsigned int fmt)
{
struct regmap *regs = ssi_private->regs;
u32 strcr = 0, stcr, srcr, scr, mask;
u8 wm;
ssi_private->dai_fmt = fmt;
if (fsl_ssi_is_i2s_master(ssi_private) && IS_ERR(ssi_private->baudclk)) {
dev_err(dev, "baudclk is missing which is necessary for master mode\n");
return -EINVAL;
}
fsl_ssi_setup_reg_vals(ssi_private);
regmap_read(regs, CCSR_SSI_SCR, &scr);
scr &= ~(CCSR_SSI_SCR_SYN | CCSR_SSI_SCR_I2S_MODE_MASK);
scr |= CCSR_SSI_SCR_SYNC_TX_FS;
mask = CCSR_SSI_STCR_TXBIT0 | CCSR_SSI_STCR_TFDIR | CCSR_SSI_STCR_TXDIR |
CCSR_SSI_STCR_TSCKP | CCSR_SSI_STCR_TFSI | CCSR_SSI_STCR_TFSL |
CCSR_SSI_STCR_TEFS;
regmap_read(regs, CCSR_SSI_STCR, &stcr);
regmap_read(regs, CCSR_SSI_SRCR, &srcr);
stcr &= ~mask;
srcr &= ~mask;
ssi_private->i2s_mode = CCSR_SSI_SCR_NET;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFS:
case SND_SOC_DAIFMT_CBS_CFS:
ssi_private->i2s_mode |= CCSR_SSI_SCR_I2S_MODE_MASTER;
regmap_update_bits(regs, CCSR_SSI_STCCR,
CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(2));
regmap_update_bits(regs, CCSR_SSI_SRCCR,
CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(2));
break;
case SND_SOC_DAIFMT_CBM_CFM:
ssi_private->i2s_mode |= CCSR_SSI_SCR_I2S_MODE_SLAVE;
break;
default:
return -EINVAL;
}
strcr |= CCSR_SSI_STCR_TFSI | CCSR_SSI_STCR_TSCKP |
CCSR_SSI_STCR_TXBIT0 | CCSR_SSI_STCR_TEFS;
break;
case SND_SOC_DAIFMT_LEFT_J:
strcr |= CCSR_SSI_STCR_TXBIT0 | CCSR_SSI_STCR_TSCKP;
break;
case SND_SOC_DAIFMT_DSP_A:
strcr |= CCSR_SSI_STCR_TFSL | CCSR_SSI_STCR_TSCKP |
CCSR_SSI_STCR_TXBIT0 | CCSR_SSI_STCR_TEFS;
break;
case SND_SOC_DAIFMT_DSP_B:
strcr |= CCSR_SSI_STCR_TFSL | CCSR_SSI_STCR_TSCKP |
CCSR_SSI_STCR_TXBIT0;
break;
case SND_SOC_DAIFMT_AC97:
ssi_private->i2s_mode |= CCSR_SSI_SCR_I2S_MODE_NORMAL;
break;
default:
return -EINVAL;
}
scr |= ssi_private->i2s_mode;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
strcr ^= CCSR_SSI_STCR_TSCKP;
break;
case SND_SOC_DAIFMT_NB_IF:
strcr ^= CCSR_SSI_STCR_TFSI;
break;
case SND_SOC_DAIFMT_IB_IF:
strcr ^= CCSR_SSI_STCR_TSCKP;
strcr ^= CCSR_SSI_STCR_TFSI;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
strcr |= CCSR_SSI_STCR_TFDIR | CCSR_SSI_STCR_TXDIR;
scr |= CCSR_SSI_SCR_SYS_CLK_EN;
break;
case SND_SOC_DAIFMT_CBM_CFM:
scr &= ~CCSR_SSI_SCR_SYS_CLK_EN;
break;
case SND_SOC_DAIFMT_CBM_CFS:
strcr &= ~CCSR_SSI_STCR_TXDIR;
strcr |= CCSR_SSI_STCR_TFDIR;
scr &= ~CCSR_SSI_SCR_SYS_CLK_EN;
break;
default:
if (!fsl_ssi_is_ac97(ssi_private))
return -EINVAL;
}
stcr |= strcr;
srcr |= strcr;
if (ssi_private->cpu_dai_drv.symmetric_rates
|| fsl_ssi_is_ac97(ssi_private)) {
srcr &= ~CCSR_SSI_SRCR_RXDIR;
scr |= CCSR_SSI_SCR_SYN;
}
regmap_write(regs, CCSR_SSI_STCR, stcr);
regmap_write(regs, CCSR_SSI_SRCR, srcr);
regmap_write(regs, CCSR_SSI_SCR, scr);
if (ssi_private->use_dma)
wm = ssi_private->fifo_depth - 2;
else
wm = ssi_private->fifo_depth;
regmap_write(regs, CCSR_SSI_SFCSR,
CCSR_SSI_SFCSR_TFWM0(wm) | CCSR_SSI_SFCSR_RFWM0(wm) |
CCSR_SSI_SFCSR_TFWM1(wm) | CCSR_SSI_SFCSR_RFWM1(wm));
if (ssi_private->use_dual_fifo) {
regmap_update_bits(regs, CCSR_SSI_SRCR, CCSR_SSI_SRCR_RFEN1,
CCSR_SSI_SRCR_RFEN1);
regmap_update_bits(regs, CCSR_SSI_STCR, CCSR_SSI_STCR_TFEN1,
CCSR_SSI_STCR_TFEN1);
regmap_update_bits(regs, CCSR_SSI_SCR, CCSR_SSI_SCR_TCH_EN,
CCSR_SSI_SCR_TCH_EN);
}
if ((fmt & SND_SOC_DAIFMT_FORMAT_MASK) == SND_SOC_DAIFMT_AC97)
fsl_ssi_setup_ac97(ssi_private);
return 0;
}
static int fsl_ssi_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
return _fsl_ssi_set_dai_fmt(cpu_dai->dev, ssi_private, fmt);
}
static int fsl_ssi_set_dai_tdm_slot(struct snd_soc_dai *cpu_dai, u32 tx_mask,
u32 rx_mask, int slots, int slot_width)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct regmap *regs = ssi_private->regs;
u32 val;
regmap_read(regs, CCSR_SSI_SCR, &val);
val &= CCSR_SSI_SCR_I2S_MODE_MASK | CCSR_SSI_SCR_NET;
if (val && slots < 2) {
dev_err(cpu_dai->dev, "slot number should be >= 2 in I2S or NET\n");
return -EINVAL;
}
regmap_update_bits(regs, CCSR_SSI_STCCR, CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(slots));
regmap_update_bits(regs, CCSR_SSI_SRCCR, CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(slots));
regmap_read(regs, CCSR_SSI_SCR, &val);
val &= CCSR_SSI_SCR_SSIEN;
regmap_update_bits(regs, CCSR_SSI_SCR, CCSR_SSI_SCR_SSIEN,
CCSR_SSI_SCR_SSIEN);
regmap_write(regs, CCSR_SSI_STMSK, ~tx_mask);
regmap_write(regs, CCSR_SSI_SRMSK, ~rx_mask);
regmap_update_bits(regs, CCSR_SSI_SCR, CCSR_SSI_SCR_SSIEN, val);
return 0;
}
static int fsl_ssi_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(rtd->cpu_dai);
struct regmap *regs = ssi_private->regs;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fsl_ssi_tx_config(ssi_private, true);
else
fsl_ssi_rx_config(ssi_private, true);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fsl_ssi_tx_config(ssi_private, false);
else
fsl_ssi_rx_config(ssi_private, false);
break;
default:
return -EINVAL;
}
if (fsl_ssi_is_ac97(ssi_private)) {
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
regmap_write(regs, CCSR_SSI_SOR, CCSR_SSI_SOR_TX_CLR);
else
regmap_write(regs, CCSR_SSI_SOR, CCSR_SSI_SOR_RX_CLR);
}
return 0;
}
static int fsl_ssi_dai_probe(struct snd_soc_dai *dai)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(dai);
if (ssi_private->soc->imx && ssi_private->use_dma) {
dai->playback_dma_data = &ssi_private->dma_params_tx;
dai->capture_dma_data = &ssi_private->dma_params_rx;
}
return 0;
}
static void fsl_ssi_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct regmap *regs = fsl_ac97_data->regs;
unsigned int lreg;
unsigned int lval;
int ret;
if (reg > 0x7f)
return;
ret = clk_prepare_enable(fsl_ac97_data->clk);
if (ret) {
pr_err("ac97 write clk_prepare_enable failed: %d\n",
ret);
return;
}
lreg = reg << 12;
regmap_write(regs, CCSR_SSI_SACADD, lreg);
lval = val << 4;
regmap_write(regs, CCSR_SSI_SACDAT, lval);
regmap_update_bits(regs, CCSR_SSI_SACNT, CCSR_SSI_SACNT_RDWR_MASK,
CCSR_SSI_SACNT_WR);
udelay(100);
clk_disable_unprepare(fsl_ac97_data->clk);
}
static unsigned short fsl_ssi_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct regmap *regs = fsl_ac97_data->regs;
unsigned short val = -1;
u32 reg_val;
unsigned int lreg;
int ret;
ret = clk_prepare_enable(fsl_ac97_data->clk);
if (ret) {
pr_err("ac97 read clk_prepare_enable failed: %d\n",
ret);
return -1;
}
lreg = (reg & 0x7f) << 12;
regmap_write(regs, CCSR_SSI_SACADD, lreg);
regmap_update_bits(regs, CCSR_SSI_SACNT, CCSR_SSI_SACNT_RDWR_MASK,
CCSR_SSI_SACNT_RD);
udelay(100);
regmap_read(regs, CCSR_SSI_SACDAT, &reg_val);
val = (reg_val >> 4) & 0xffff;
clk_disable_unprepare(fsl_ac97_data->clk);
return val;
}
static void make_lowercase(char *s)
{
char *p = s;
char c;
while ((c = *p)) {
if ((c >= 'A') && (c <= 'Z'))
*p = c + ('a' - 'A');
p++;
}
}
static int fsl_ssi_imx_probe(struct platform_device *pdev,
struct fsl_ssi_private *ssi_private, void __iomem *iomem)
{
struct device_node *np = pdev->dev.of_node;
u32 dmas[4];
int ret;
if (ssi_private->has_ipg_clk_name)
ssi_private->clk = devm_clk_get(&pdev->dev, "ipg");
else
ssi_private->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(ssi_private->clk)) {
ret = PTR_ERR(ssi_private->clk);
dev_err(&pdev->dev, "could not get clock: %d\n", ret);
return ret;
}
if (!ssi_private->has_ipg_clk_name) {
ret = clk_prepare_enable(ssi_private->clk);
if (ret) {
dev_err(&pdev->dev, "clk_prepare_enable failed: %d\n", ret);
return ret;
}
}
ssi_private->baudclk = devm_clk_get(&pdev->dev, "baud");
if (IS_ERR(ssi_private->baudclk))
dev_dbg(&pdev->dev, "could not get baud clock: %ld\n",
PTR_ERR(ssi_private->baudclk));
ssi_private->dma_params_tx.maxburst = ssi_private->fifo_depth - 2;
ssi_private->dma_params_rx.maxburst = ssi_private->fifo_depth - 2;
ssi_private->dma_params_tx.addr = ssi_private->ssi_phys + CCSR_SSI_STX0;
ssi_private->dma_params_rx.addr = ssi_private->ssi_phys + CCSR_SSI_SRX0;
ret = of_property_read_u32_array(np, "dmas", dmas, 4);
if (ssi_private->use_dma && !ret && dmas[2] == IMX_DMATYPE_SSI_DUAL) {
ssi_private->use_dual_fifo = true;
ssi_private->dma_params_tx.maxburst &= ~0x1;
ssi_private->dma_params_rx.maxburst &= ~0x1;
}
if (!ssi_private->use_dma) {
ssi_private->fiq_params.irq = ssi_private->irq;
ssi_private->fiq_params.base = iomem;
ssi_private->fiq_params.dma_params_rx =
&ssi_private->dma_params_rx;
ssi_private->fiq_params.dma_params_tx =
&ssi_private->dma_params_tx;
ret = imx_pcm_fiq_init(pdev, &ssi_private->fiq_params);
if (ret)
goto error_pcm;
} else {
ret = imx_pcm_dma_init(pdev, IMX_SSI_DMABUF_SIZE);
if (ret)
goto error_pcm;
}
return 0;
error_pcm:
if (!ssi_private->has_ipg_clk_name)
clk_disable_unprepare(ssi_private->clk);
return ret;
}
static void fsl_ssi_imx_clean(struct platform_device *pdev,
struct fsl_ssi_private *ssi_private)
{
if (!ssi_private->use_dma)
imx_pcm_fiq_exit(pdev);
if (!ssi_private->has_ipg_clk_name)
clk_disable_unprepare(ssi_private->clk);
}
static int fsl_ssi_probe(struct platform_device *pdev)
{
struct fsl_ssi_private *ssi_private;
int ret = 0;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id;
const char *p, *sprop;
const uint32_t *iprop;
struct resource *res;
void __iomem *iomem;
char name[64];
of_id = of_match_device(fsl_ssi_ids, &pdev->dev);
if (!of_id || !of_id->data)
return -EINVAL;
ssi_private = devm_kzalloc(&pdev->dev, sizeof(*ssi_private),
GFP_KERNEL);
if (!ssi_private) {
dev_err(&pdev->dev, "could not allocate DAI object\n");
return -ENOMEM;
}
ssi_private->soc = of_id->data;
sprop = of_get_property(np, "fsl,mode", NULL);
if (sprop) {
if (!strcmp(sprop, "ac97-slave"))
ssi_private->dai_fmt = SND_SOC_DAIFMT_AC97;
}
ssi_private->use_dma = !of_property_read_bool(np,
"fsl,fiq-stream-filter");
if (fsl_ssi_is_ac97(ssi_private)) {
memcpy(&ssi_private->cpu_dai_drv, &fsl_ssi_ac97_dai,
sizeof(fsl_ssi_ac97_dai));
fsl_ac97_data = ssi_private;
ret = snd_soc_set_ac97_ops_of_reset(&fsl_ssi_ac97_ops, pdev);
if (ret) {
dev_err(&pdev->dev, "could not set AC'97 ops\n");
return ret;
}
} else {
memcpy(&ssi_private->cpu_dai_drv, &fsl_ssi_dai_template,
sizeof(fsl_ssi_dai_template));
}
ssi_private->cpu_dai_drv.name = dev_name(&pdev->dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iomem = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(iomem))
return PTR_ERR(iomem);
ssi_private->ssi_phys = res->start;
ret = of_property_match_string(np, "clock-names", "ipg");
if (ret < 0) {
ssi_private->has_ipg_clk_name = false;
ssi_private->regs = devm_regmap_init_mmio(&pdev->dev, iomem,
&fsl_ssi_regconfig);
} else {
ssi_private->has_ipg_clk_name = true;
ssi_private->regs = devm_regmap_init_mmio_clk(&pdev->dev,
"ipg", iomem, &fsl_ssi_regconfig);
}
if (IS_ERR(ssi_private->regs)) {
dev_err(&pdev->dev, "Failed to init register map\n");
return PTR_ERR(ssi_private->regs);
}
ssi_private->irq = platform_get_irq(pdev, 0);
if (ssi_private->irq < 0) {
dev_err(&pdev->dev, "no irq for node %s\n", pdev->name);
return ssi_private->irq;
}
if (!of_find_property(np, "fsl,ssi-asynchronous", NULL)) {
if (!fsl_ssi_is_ac97(ssi_private))
ssi_private->cpu_dai_drv.symmetric_rates = 1;
ssi_private->cpu_dai_drv.symmetric_channels = 1;
ssi_private->cpu_dai_drv.symmetric_samplebits = 1;
}
iprop = of_get_property(np, "fsl,fifo-depth", NULL);
if (iprop)
ssi_private->fifo_depth = be32_to_cpup(iprop);
else
ssi_private->fifo_depth = 8;
dev_set_drvdata(&pdev->dev, ssi_private);
if (ssi_private->soc->imx) {
ret = fsl_ssi_imx_probe(pdev, ssi_private, iomem);
if (ret)
return ret;
}
ret = devm_snd_soc_register_component(&pdev->dev, &fsl_ssi_component,
&ssi_private->cpu_dai_drv, 1);
if (ret) {
dev_err(&pdev->dev, "failed to register DAI: %d\n", ret);
goto error_asoc_register;
}
if (ssi_private->use_dma) {
ret = devm_request_irq(&pdev->dev, ssi_private->irq,
fsl_ssi_isr, 0, dev_name(&pdev->dev),
ssi_private);
if (ret < 0) {
dev_err(&pdev->dev, "could not claim irq %u\n",
ssi_private->irq);
goto error_asoc_register;
}
}
ret = fsl_ssi_debugfs_create(&ssi_private->dbg_stats, &pdev->dev);
if (ret)
goto error_asoc_register;
if (!of_get_property(np, "codec-handle", NULL))
goto done;
sprop = of_get_property(of_find_node_by_path("/"), "compatible", NULL);
p = strrchr(sprop, ',');
if (p)
sprop = p + 1;
snprintf(name, sizeof(name), "snd-soc-%s", sprop);
make_lowercase(name);
ssi_private->pdev =
platform_device_register_data(&pdev->dev, name, 0, NULL, 0);
if (IS_ERR(ssi_private->pdev)) {
ret = PTR_ERR(ssi_private->pdev);
dev_err(&pdev->dev, "failed to register platform: %d\n", ret);
goto error_sound_card;
}
done:
if (ssi_private->dai_fmt)
_fsl_ssi_set_dai_fmt(&pdev->dev, ssi_private,
ssi_private->dai_fmt);
if (fsl_ssi_is_ac97(ssi_private)) {
u32 ssi_idx;
ret = of_property_read_u32(np, "cell-index", &ssi_idx);
if (ret) {
dev_err(&pdev->dev, "cannot get SSI index property\n");
goto error_sound_card;
}
ssi_private->pdev =
platform_device_register_data(NULL,
"ac97-codec", ssi_idx, NULL, 0);
if (IS_ERR(ssi_private->pdev)) {
ret = PTR_ERR(ssi_private->pdev);
dev_err(&pdev->dev,
"failed to register AC97 codec platform: %d\n",
ret);
goto error_sound_card;
}
}
return 0;
error_sound_card:
fsl_ssi_debugfs_remove(&ssi_private->dbg_stats);
error_asoc_register:
if (ssi_private->soc->imx)
fsl_ssi_imx_clean(pdev, ssi_private);
return ret;
}
static int fsl_ssi_remove(struct platform_device *pdev)
{
struct fsl_ssi_private *ssi_private = dev_get_drvdata(&pdev->dev);
fsl_ssi_debugfs_remove(&ssi_private->dbg_stats);
if (ssi_private->pdev)
platform_device_unregister(ssi_private->pdev);
if (ssi_private->soc->imx)
fsl_ssi_imx_clean(pdev, ssi_private);
if (fsl_ssi_is_ac97(ssi_private))
snd_soc_set_ac97_ops(NULL);
return 0;
}
