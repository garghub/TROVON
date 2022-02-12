static inline void write_ssi_mask(u32 __iomem *addr, u32 clear, u32 set)
{
u32 val = readl(addr);
val = (val & ~clear) | set;
writel(val, addr);
}
static irqreturn_t fsl_ssi_isr(int irq, void *dev_id)
{
struct fsl_ssi_private *ssi_private = dev_id;
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
irqreturn_t ret = IRQ_NONE;
__be32 sisr;
__be32 sisr2;
__be32 sisr_write_mask = 0;
switch (ssi_private->hw_type) {
case FSL_SSI_MX21:
sisr_write_mask = 0;
break;
case FSL_SSI_MCP8610:
case FSL_SSI_MX35:
sisr_write_mask = CCSR_SSI_SISR_RFRC | CCSR_SSI_SISR_TFRC |
CCSR_SSI_SISR_ROE0 | CCSR_SSI_SISR_ROE1 |
CCSR_SSI_SISR_TUE0 | CCSR_SSI_SISR_TUE1;
break;
case FSL_SSI_MX51:
sisr_write_mask = CCSR_SSI_SISR_ROE0 | CCSR_SSI_SISR_ROE1 |
CCSR_SSI_SISR_TUE0 | CCSR_SSI_SISR_TUE1;
break;
}
sisr = read_ssi(&ssi->sisr) & FSLSSI_SISR_MASK;
if (sisr & CCSR_SSI_SISR_RFRC) {
ssi_private->stats.rfrc++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFRC) {
ssi_private->stats.tfrc++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_CMDAU) {
ssi_private->stats.cmdau++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_CMDDU) {
ssi_private->stats.cmddu++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RXT) {
ssi_private->stats.rxt++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RDR1) {
ssi_private->stats.rdr1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RDR0) {
ssi_private->stats.rdr0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TDE1) {
ssi_private->stats.tde1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TDE0) {
ssi_private->stats.tde0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_ROE1) {
ssi_private->stats.roe1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_ROE0) {
ssi_private->stats.roe0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TUE1) {
ssi_private->stats.tue1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TUE0) {
ssi_private->stats.tue0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFS) {
ssi_private->stats.tfs++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RFS) {
ssi_private->stats.rfs++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TLS) {
ssi_private->stats.tls++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RLS) {
ssi_private->stats.rls++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RFF1) {
ssi_private->stats.rff1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_RFF0) {
ssi_private->stats.rff0++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFE1) {
ssi_private->stats.tfe1++;
ret = IRQ_HANDLED;
}
if (sisr & CCSR_SSI_SISR_TFE0) {
ssi_private->stats.tfe0++;
ret = IRQ_HANDLED;
}
sisr2 = sisr & sisr_write_mask;
if (sisr2)
write_ssi(sisr2, &ssi->sisr);
return ret;
}
static int fsl_ssi_stats_show(struct seq_file *s, void *unused)
{
struct fsl_ssi_private *ssi_private = s->private;
SIER_SHOW(RFRC_EN, rfrc);
SIER_SHOW(TFRC_EN, tfrc);
SIER_SHOW(CMDAU_EN, cmdau);
SIER_SHOW(CMDDU_EN, cmddu);
SIER_SHOW(RXT_EN, rxt);
SIER_SHOW(RDR1_EN, rdr1);
SIER_SHOW(RDR0_EN, rdr0);
SIER_SHOW(TDE1_EN, tde1);
SIER_SHOW(TDE0_EN, tde0);
SIER_SHOW(ROE1_EN, roe1);
SIER_SHOW(ROE0_EN, roe0);
SIER_SHOW(TUE1_EN, tue1);
SIER_SHOW(TUE0_EN, tue0);
SIER_SHOW(TFS_EN, tfs);
SIER_SHOW(RFS_EN, rfs);
SIER_SHOW(TLS_EN, tls);
SIER_SHOW(RLS_EN, rls);
SIER_SHOW(RFF1_EN, rff1);
SIER_SHOW(RFF0_EN, rff0);
SIER_SHOW(TFE1_EN, tfe1);
SIER_SHOW(TFE0_EN, tfe0);
return 0;
}
static int fsl_ssi_stats_open(struct inode *inode, struct file *file)
{
return single_open(file, fsl_ssi_stats_show, inode->i_private);
}
static int fsl_ssi_debugfs_create(struct fsl_ssi_private *ssi_private,
struct device *dev)
{
ssi_private->dbg_dir = debugfs_create_dir(dev_name(dev), NULL);
if (!ssi_private->dbg_dir)
return -ENOMEM;
ssi_private->dbg_stats = debugfs_create_file("stats", S_IRUGO,
ssi_private->dbg_dir, ssi_private, &fsl_ssi_stats_ops);
if (!ssi_private->dbg_stats) {
debugfs_remove(ssi_private->dbg_dir);
return -ENOMEM;
}
return 0;
}
static void fsl_ssi_debugfs_remove(struct fsl_ssi_private *ssi_private)
{
debugfs_remove(ssi_private->dbg_stats);
debugfs_remove(ssi_private->dbg_dir);
}
static int fsl_ssi_debugfs_create(struct fsl_ssi_private *ssi_private,
struct device *dev)
{
return 0;
}
static void fsl_ssi_debugfs_remove(struct fsl_ssi_private *ssi_private)
{
}
static void fsl_ssi_rxtx_config(struct fsl_ssi_private *ssi_private,
bool enable)
{
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
struct fsl_ssi_rxtx_reg_val *vals = &ssi_private->rxtx_reg_val;
if (enable) {
write_ssi_mask(&ssi->sier, 0, vals->rx.sier | vals->tx.sier);
write_ssi_mask(&ssi->srcr, 0, vals->rx.srcr | vals->tx.srcr);
write_ssi_mask(&ssi->stcr, 0, vals->rx.stcr | vals->tx.stcr);
} else {
write_ssi_mask(&ssi->srcr, vals->rx.srcr | vals->tx.srcr, 0);
write_ssi_mask(&ssi->stcr, vals->rx.stcr | vals->tx.stcr, 0);
write_ssi_mask(&ssi->sier, vals->rx.sier | vals->tx.sier, 0);
}
}
static void fsl_ssi_config(struct fsl_ssi_private *ssi_private, bool enable,
struct fsl_ssi_reg_val *vals)
{
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
struct fsl_ssi_reg_val *avals;
u32 scr_val = read_ssi(&ssi->scr);
int nr_active_streams = !!(scr_val & CCSR_SSI_SCR_TE) +
!!(scr_val & CCSR_SSI_SCR_RE);
if (&ssi_private->rxtx_reg_val.rx == vals)
avals = &ssi_private->rxtx_reg_val.tx;
else
avals = &ssi_private->rxtx_reg_val.rx;
if (!enable) {
u32 scr = vals->scr & (vals->scr ^ avals->scr);
write_ssi_mask(&ssi->scr, scr, 0);
}
if (ssi_private->offline_config) {
if ((enable && !nr_active_streams) ||
(!enable && nr_active_streams == 1))
fsl_ssi_rxtx_config(ssi_private, enable);
goto config_done;
}
if (enable) {
write_ssi_mask(&ssi->sier, 0, vals->sier);
write_ssi_mask(&ssi->srcr, 0, vals->srcr);
write_ssi_mask(&ssi->stcr, 0, vals->stcr);
} else {
u32 sier;
u32 srcr;
u32 stcr;
sier = vals->sier & (vals->sier ^ avals->sier);
srcr = vals->srcr & (vals->srcr ^ avals->srcr);
stcr = vals->stcr & (vals->stcr ^ avals->stcr);
write_ssi_mask(&ssi->srcr, srcr, 0);
write_ssi_mask(&ssi->stcr, stcr, 0);
write_ssi_mask(&ssi->sier, sier, 0);
}
config_done:
if (enable)
write_ssi_mask(&ssi->scr, 0, vals->scr);
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
if (!ssi_private->imx_ac97) {
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
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
write_ssi(CCSR_SSI_SxCCR_WL(17) | CCSR_SSI_SxCCR_DC(13),
&ssi->stccr);
write_ssi(CCSR_SSI_SxCCR_WL(17) | CCSR_SSI_SxCCR_DC(13),
&ssi->srccr);
write_ssi(CCSR_SSI_SACNT_AC97EN | CCSR_SSI_SACNT_FV,
&ssi->sacnt);
write_ssi(0xff, &ssi->saccdis);
write_ssi(0x300, &ssi->saccen);
write_ssi_mask(&ssi->scr, 0, CCSR_SSI_SCR_SSIEN |
CCSR_SSI_SCR_TE | CCSR_SSI_SCR_RE);
write_ssi(CCSR_SSI_SOR_WAIT(3), &ssi->sor);
}
static int fsl_ssi_setup(struct fsl_ssi_private *ssi_private)
{
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
u8 wm;
int synchronous = ssi_private->cpu_dai_drv.symmetric_rates;
fsl_ssi_setup_reg_vals(ssi_private);
if (ssi_private->imx_ac97)
ssi_private->i2s_mode = CCSR_SSI_SCR_I2S_MODE_NORMAL | CCSR_SSI_SCR_NET;
else
ssi_private->i2s_mode = CCSR_SSI_SCR_I2S_MODE_SLAVE;
write_ssi_mask(&ssi->scr, CCSR_SSI_SCR_SSIEN, 0);
write_ssi_mask(&ssi->scr,
CCSR_SSI_SCR_I2S_MODE_MASK | CCSR_SSI_SCR_SYN,
CCSR_SSI_SCR_TFR_CLK_DIS |
ssi_private->i2s_mode |
(synchronous ? CCSR_SSI_SCR_SYN : 0));
write_ssi(CCSR_SSI_STCR_TXBIT0 | CCSR_SSI_STCR_TFSI |
CCSR_SSI_STCR_TEFS | CCSR_SSI_STCR_TSCKP, &ssi->stcr);
write_ssi(CCSR_SSI_SRCR_RXBIT0 | CCSR_SSI_SRCR_RFSI |
CCSR_SSI_SRCR_REFS | CCSR_SSI_SRCR_RSCKP, &ssi->srcr);
if (ssi_private->use_dma)
wm = ssi_private->fifo_depth - 2;
else
wm = ssi_private->fifo_depth;
write_ssi(CCSR_SSI_SFCSR_TFWM0(wm) | CCSR_SSI_SFCSR_RFWM0(wm) |
CCSR_SSI_SFCSR_TFWM1(wm) | CCSR_SSI_SFCSR_RFWM1(wm),
&ssi->sfcsr);
if (ssi_private->imx_ac97)
fsl_ssi_setup_ac97(ssi_private);
if (!ssi_private->imx_ac97) {
write_ssi_mask(&ssi->stccr, CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(2));
write_ssi_mask(&ssi->srccr, CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(2));
}
if (ssi_private->use_dual_fifo) {
write_ssi_mask(&ssi->srcr, 0, CCSR_SSI_SRCR_RFEN1);
write_ssi_mask(&ssi->stcr, 0, CCSR_SSI_STCR_TFEN1);
write_ssi_mask(&ssi->scr, 0, CCSR_SSI_SCR_TCH_EN);
}
return 0;
}
static int fsl_ssi_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private =
snd_soc_dai_get_drvdata(rtd->cpu_dai);
unsigned long flags;
if (!dai->active && !ssi_private->imx_ac97) {
fsl_ssi_setup(ssi_private);
spin_lock_irqsave(&ssi_private->baudclk_lock, flags);
ssi_private->baudclk_locked = false;
spin_unlock_irqrestore(&ssi_private->baudclk_lock, flags);
}
if (ssi_private->use_dual_fifo)
snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE, 2);
return 0;
}
static int fsl_ssi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params, struct snd_soc_dai *cpu_dai)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
unsigned int channels = params_channels(hw_params);
unsigned int sample_size =
snd_pcm_format_width(params_format(hw_params));
u32 wl = CCSR_SSI_SxCCR_WL(sample_size);
int enabled = read_ssi(&ssi->scr) & CCSR_SSI_SCR_SSIEN;
if (enabled && ssi_private->cpu_dai_drv.symmetric_rates)
return 0;
if ((substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ||
ssi_private->cpu_dai_drv.symmetric_rates)
write_ssi_mask(&ssi->stccr, CCSR_SSI_SxCCR_WL_MASK, wl);
else
write_ssi_mask(&ssi->srccr, CCSR_SSI_SxCCR_WL_MASK, wl);
if (!ssi_private->imx_ac97)
write_ssi_mask(&ssi->scr,
CCSR_SSI_SCR_NET | CCSR_SSI_SCR_I2S_MODE_MASK,
channels == 1 ? 0 : ssi_private->i2s_mode);
return 0;
}
static int fsl_ssi_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
u32 strcr = 0, stcr, srcr, scr, mask;
scr = read_ssi(&ssi->scr) & ~(CCSR_SSI_SCR_SYN | CCSR_SSI_SCR_I2S_MODE_MASK);
scr |= CCSR_SSI_SCR_NET;
mask = CCSR_SSI_STCR_TXBIT0 | CCSR_SSI_STCR_TFDIR | CCSR_SSI_STCR_TXDIR |
CCSR_SSI_STCR_TSCKP | CCSR_SSI_STCR_TFSI | CCSR_SSI_STCR_TFSL |
CCSR_SSI_STCR_TEFS;
stcr = read_ssi(&ssi->stcr) & ~mask;
srcr = read_ssi(&ssi->srcr) & ~mask;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
ssi_private->i2s_mode = CCSR_SSI_SCR_I2S_MODE_MASTER;
break;
case SND_SOC_DAIFMT_CBM_CFM:
ssi_private->i2s_mode = CCSR_SSI_SCR_I2S_MODE_SLAVE;
break;
default:
return -EINVAL;
}
scr |= ssi_private->i2s_mode;
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
default:
return -EINVAL;
}
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
default:
return -EINVAL;
}
stcr |= strcr;
srcr |= strcr;
if (ssi_private->cpu_dai_drv.symmetric_rates) {
srcr &= ~CCSR_SSI_SRCR_RXDIR;
scr |= CCSR_SSI_SCR_SYN;
}
write_ssi(stcr, &ssi->stcr);
write_ssi(srcr, &ssi->srcr);
write_ssi(scr, &ssi->scr);
return 0;
}
static int fsl_ssi_set_dai_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
int synchronous = ssi_private->cpu_dai_drv.symmetric_rates, ret;
u32 pm = 999, div2, psr, stccr, mask, afreq, factor, i;
unsigned long flags, clkrate, baudrate, tmprate;
u64 sub, savesub = 100000;
if (IS_ERR(ssi_private->baudclk))
return -EINVAL;
psr = 0;
div2 = 0;
factor = (div2 + 1) * (7 * psr + 1) * 2;
for (i = 0; i < 255; i++) {
if (factor * (i + 1) < 5)
continue;
tmprate = freq * factor * (i + 2);
clkrate = clk_round_rate(ssi_private->baudclk, tmprate);
do_div(clkrate, factor);
afreq = (u32)clkrate / (i + 1);
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
if (sub < savesub) {
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
mask = CCSR_SSI_SxCCR_PM_MASK | CCSR_SSI_SxCCR_DIV2 | CCSR_SSI_SxCCR_PSR;
if (dir == SND_SOC_CLOCK_OUT || synchronous)
write_ssi_mask(&ssi->stccr, mask, stccr);
else
write_ssi_mask(&ssi->srccr, mask, stccr);
spin_lock_irqsave(&ssi_private->baudclk_lock, flags);
if (!ssi_private->baudclk_locked) {
ret = clk_set_rate(ssi_private->baudclk, baudrate);
if (ret) {
spin_unlock_irqrestore(&ssi_private->baudclk_lock, flags);
dev_err(cpu_dai->dev, "failed to set baudclk rate\n");
return -EINVAL;
}
ssi_private->baudclk_locked = true;
}
spin_unlock_irqrestore(&ssi_private->baudclk_lock, flags);
return 0;
}
static int fsl_ssi_set_dai_tdm_slot(struct snd_soc_dai *cpu_dai, u32 tx_mask,
u32 rx_mask, int slots, int slot_width)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(cpu_dai);
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
u32 val;
val = read_ssi(&ssi->scr) & (CCSR_SSI_SCR_I2S_MODE_MASK | CCSR_SSI_SCR_NET);
if (val && slots < 2) {
dev_err(cpu_dai->dev, "slot number should be >= 2 in I2S or NET\n");
return -EINVAL;
}
write_ssi_mask(&ssi->stccr, CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(slots));
write_ssi_mask(&ssi->srccr, CCSR_SSI_SxCCR_DC_MASK,
CCSR_SSI_SxCCR_DC(slots));
val = read_ssi(&ssi->scr) & CCSR_SSI_SCR_SSIEN;
write_ssi_mask(&ssi->scr, 0, CCSR_SSI_SCR_SSIEN);
write_ssi(tx_mask, &ssi->stmsk);
write_ssi(rx_mask, &ssi->srmsk);
write_ssi_mask(&ssi->scr, CCSR_SSI_SCR_SSIEN, val);
return 0;
}
static int fsl_ssi_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(rtd->cpu_dai);
struct ccsr_ssi __iomem *ssi = ssi_private->ssi;
unsigned long flags;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fsl_ssi_tx_config(ssi_private, true);
else
fsl_ssi_rx_config(ssi_private, true);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
fsl_ssi_tx_config(ssi_private, false);
else
fsl_ssi_rx_config(ssi_private, false);
if (!ssi_private->imx_ac97 && (read_ssi(&ssi->scr) &
(CCSR_SSI_SCR_TE | CCSR_SSI_SCR_RE)) == 0) {
spin_lock_irqsave(&ssi_private->baudclk_lock, flags);
ssi_private->baudclk_locked = false;
spin_unlock_irqrestore(&ssi_private->baudclk_lock, flags);
}
break;
default:
return -EINVAL;
}
if (ssi_private->imx_ac97) {
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
write_ssi(CCSR_SSI_SOR_TX_CLR, &ssi->sor);
else
write_ssi(CCSR_SSI_SOR_RX_CLR, &ssi->sor);
}
return 0;
}
static int fsl_ssi_dai_probe(struct snd_soc_dai *dai)
{
struct fsl_ssi_private *ssi_private = snd_soc_dai_get_drvdata(dai);
if (ssi_private->ssi_on_imx && ssi_private->use_dma) {
dai->playback_dma_data = &ssi_private->dma_params_tx;
dai->capture_dma_data = &ssi_private->dma_params_rx;
}
return 0;
}
static void fsl_ssi_ac97_init(void)
{
fsl_ssi_setup(fsl_ac97_data);
}
static void fsl_ssi_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct ccsr_ssi *ssi = fsl_ac97_data->ssi;
unsigned int lreg;
unsigned int lval;
if (reg > 0x7f)
return;
lreg = reg << 12;
write_ssi(lreg, &ssi->sacadd);
lval = val << 4;
write_ssi(lval , &ssi->sacdat);
write_ssi_mask(&ssi->sacnt, CCSR_SSI_SACNT_RDWR_MASK,
CCSR_SSI_SACNT_WR);
udelay(100);
}
static unsigned short fsl_ssi_ac97_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct ccsr_ssi *ssi = fsl_ac97_data->ssi;
unsigned short val = -1;
unsigned int lreg;
lreg = (reg & 0x7f) << 12;
write_ssi(lreg, &ssi->sacadd);
write_ssi_mask(&ssi->sacnt, CCSR_SSI_SACNT_RDWR_MASK,
CCSR_SSI_SACNT_RD);
udelay(100);
val = (read_ssi(&ssi->sacdat) >> 4) & 0xffff;
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
static int fsl_ssi_probe(struct platform_device *pdev)
{
struct fsl_ssi_private *ssi_private;
int ret = 0;
struct device_attribute *dev_attr = NULL;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id;
enum fsl_ssi_type hw_type;
const char *p, *sprop;
const uint32_t *iprop;
struct resource res;
char name[64];
bool shared;
bool ac97 = false;
if (!of_device_is_available(np))
return -ENODEV;
of_id = of_match_device(fsl_ssi_ids, &pdev->dev);
if (!of_id)
return -EINVAL;
hw_type = (enum fsl_ssi_type) of_id->data;
sprop = of_get_property(np, "fsl,mode", NULL);
if (!sprop) {
dev_err(&pdev->dev, "fsl,mode property is necessary\n");
return -EINVAL;
}
if (!strcmp(sprop, "ac97-slave"))
ac97 = true;
p = strrchr(np->full_name, '/') + 1;
ssi_private = devm_kzalloc(&pdev->dev, sizeof(*ssi_private) + strlen(p),
GFP_KERNEL);
if (!ssi_private) {
dev_err(&pdev->dev, "could not allocate DAI object\n");
return -ENOMEM;
}
strcpy(ssi_private->name, p);
ssi_private->use_dma = !of_property_read_bool(np,
"fsl,fiq-stream-filter");
ssi_private->hw_type = hw_type;
if (ac97) {
memcpy(&ssi_private->cpu_dai_drv, &fsl_ssi_ac97_dai,
sizeof(fsl_ssi_ac97_dai));
fsl_ac97_data = ssi_private;
ssi_private->imx_ac97 = true;
snd_soc_set_ac97_ops_of_reset(&fsl_ssi_ac97_ops, pdev);
} else {
memcpy(&ssi_private->cpu_dai_drv, &fsl_ssi_dai_template,
sizeof(fsl_ssi_dai_template));
}
ssi_private->cpu_dai_drv.name = ssi_private->name;
ret = of_address_to_resource(np, 0, &res);
if (ret) {
dev_err(&pdev->dev, "could not determine device resources\n");
return ret;
}
ssi_private->ssi = of_iomap(np, 0);
if (!ssi_private->ssi) {
dev_err(&pdev->dev, "could not map device resources\n");
return -ENOMEM;
}
ssi_private->ssi_phys = res.start;
ssi_private->irq = irq_of_parse_and_map(np, 0);
if (!ssi_private->irq) {
dev_err(&pdev->dev, "no irq for node %s\n", np->full_name);
return -ENXIO;
}
if (!of_find_property(np, "fsl,ssi-asynchronous", NULL)) {
ssi_private->cpu_dai_drv.symmetric_rates = 1;
ssi_private->cpu_dai_drv.symmetric_channels = 1;
ssi_private->cpu_dai_drv.symmetric_samplebits = 1;
}
iprop = of_get_property(np, "fsl,fifo-depth", NULL);
if (iprop)
ssi_private->fifo_depth = be32_to_cpup(iprop);
else
ssi_private->fifo_depth = 8;
ssi_private->baudclk_locked = false;
spin_lock_init(&ssi_private->baudclk_lock);
switch (hw_type) {
case FSL_SSI_MCP8610:
case FSL_SSI_MX21:
case FSL_SSI_MX35:
ssi_private->offline_config = true;
break;
case FSL_SSI_MX51:
ssi_private->offline_config = false;
break;
}
if (hw_type == FSL_SSI_MX21 || hw_type == FSL_SSI_MX51 ||
hw_type == FSL_SSI_MX35) {
u32 dma_events[2], dmas[4];
ssi_private->ssi_on_imx = true;
ssi_private->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(ssi_private->clk)) {
ret = PTR_ERR(ssi_private->clk);
dev_err(&pdev->dev, "could not get clock: %d\n", ret);
goto error_irqmap;
}
ret = clk_prepare_enable(ssi_private->clk);
if (ret) {
dev_err(&pdev->dev, "clk_prepare_enable failed: %d\n",
ret);
goto error_irqmap;
}
ssi_private->baudclk = devm_clk_get(&pdev->dev, "baud");
if (IS_ERR(ssi_private->baudclk))
dev_dbg(&pdev->dev, "could not get baud clock: %ld\n",
PTR_ERR(ssi_private->baudclk));
else
clk_prepare_enable(ssi_private->baudclk);
ssi_private->dma_params_tx.maxburst =
ssi_private->fifo_depth - 2;
ssi_private->dma_params_rx.maxburst =
ssi_private->fifo_depth - 2;
ssi_private->dma_params_tx.addr =
ssi_private->ssi_phys + offsetof(struct ccsr_ssi, stx0);
ssi_private->dma_params_rx.addr =
ssi_private->ssi_phys + offsetof(struct ccsr_ssi, srx0);
ssi_private->dma_params_tx.filter_data =
&ssi_private->filter_data_tx;
ssi_private->dma_params_rx.filter_data =
&ssi_private->filter_data_rx;
if (!of_property_read_bool(pdev->dev.of_node, "dmas") &&
ssi_private->use_dma) {
ret = of_property_read_u32_array(pdev->dev.of_node,
"fsl,ssi-dma-events", dma_events, 2);
if (ret && ssi_private->use_dma) {
dev_err(&pdev->dev, "could not get dma events but fsl-ssi is configured to use DMA\n");
goto error_clk;
}
}
if (!of_property_read_u32_array(pdev->dev.of_node, "dmas", dmas, 4)
&& dmas[2] == IMX_DMATYPE_SSI_DUAL) {
ssi_private->use_dual_fifo = true;
ssi_private->dma_params_tx.maxburst &= ~0x1;
ssi_private->dma_params_rx.maxburst &= ~0x1;
}
shared = of_device_is_compatible(of_get_parent(np),
"fsl,spba-bus");
imx_pcm_dma_params_init_data(&ssi_private->filter_data_tx,
dma_events[0], shared ? IMX_DMATYPE_SSI_SP : IMX_DMATYPE_SSI);
imx_pcm_dma_params_init_data(&ssi_private->filter_data_rx,
dma_events[1], shared ? IMX_DMATYPE_SSI_SP : IMX_DMATYPE_SSI);
}
if (ssi_private->use_dma) {
ret = devm_request_irq(&pdev->dev, ssi_private->irq,
fsl_ssi_isr, 0, ssi_private->name,
ssi_private);
ssi_private->irq_stats = true;
if (ret < 0) {
dev_err(&pdev->dev, "could not claim irq %u\n",
ssi_private->irq);
goto error_clk;
}
}
dev_set_drvdata(&pdev->dev, ssi_private);
ret = snd_soc_register_component(&pdev->dev, &fsl_ssi_component,
&ssi_private->cpu_dai_drv, 1);
if (ret) {
dev_err(&pdev->dev, "failed to register DAI: %d\n", ret);
goto error_dev;
}
ret = fsl_ssi_debugfs_create(ssi_private, &pdev->dev);
if (ret)
goto error_dbgfs;
if (ssi_private->ssi_on_imx) {
if (!ssi_private->use_dma) {
ssi_private->fiq_params.irq = ssi_private->irq;
ssi_private->fiq_params.base = ssi_private->ssi;
ssi_private->fiq_params.dma_params_rx =
&ssi_private->dma_params_rx;
ssi_private->fiq_params.dma_params_tx =
&ssi_private->dma_params_tx;
ret = imx_pcm_fiq_init(pdev, &ssi_private->fiq_params);
if (ret)
goto error_pcm;
} else {
ret = imx_pcm_dma_init(pdev);
if (ret)
goto error_pcm;
}
}
if (!of_get_property(np, "codec-handle", NULL)) {
ssi_private->new_binding = true;
goto done;
}
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
goto error_dai;
}
done:
if (ssi_private->imx_ac97)
fsl_ssi_ac97_init();
return 0;
error_dai:
if (ssi_private->ssi_on_imx && !ssi_private->use_dma)
imx_pcm_fiq_exit(pdev);
error_pcm:
fsl_ssi_debugfs_remove(ssi_private);
error_dbgfs:
snd_soc_unregister_component(&pdev->dev);
error_dev:
device_remove_file(&pdev->dev, dev_attr);
error_clk:
if (ssi_private->ssi_on_imx) {
if (!IS_ERR(ssi_private->baudclk))
clk_disable_unprepare(ssi_private->baudclk);
clk_disable_unprepare(ssi_private->clk);
}
error_irqmap:
if (ssi_private->irq_stats)
irq_dispose_mapping(ssi_private->irq);
return ret;
}
static int fsl_ssi_remove(struct platform_device *pdev)
{
struct fsl_ssi_private *ssi_private = dev_get_drvdata(&pdev->dev);
fsl_ssi_debugfs_remove(ssi_private);
if (!ssi_private->new_binding)
platform_device_unregister(ssi_private->pdev);
snd_soc_unregister_component(&pdev->dev);
if (ssi_private->ssi_on_imx) {
if (!IS_ERR(ssi_private->baudclk))
clk_disable_unprepare(ssi_private->baudclk);
clk_disable_unprepare(ssi_private->clk);
}
if (ssi_private->irq_stats)
irq_dispose_mapping(ssi_private->irq);
return 0;
}
