static inline bool is_secondary(struct i2s_dai *i2s)
{
return i2s->pri_dai ? true : false;
}
static inline bool is_slave(struct i2s_dai *i2s)
{
u32 mod = readl(i2s->addr + I2SMOD);
return (mod & (1 << i2s->variant_regs->mss_off)) ? true : false;
}
static inline bool tx_active(struct i2s_dai *i2s)
{
u32 active;
if (!i2s)
return false;
active = readl(i2s->addr + I2SCON);
if (is_secondary(i2s))
active &= CON_TXSDMA_ACTIVE;
else
active &= CON_TXDMA_ACTIVE;
return active ? true : false;
}
static inline struct i2s_dai *get_other_dai(struct i2s_dai *i2s)
{
return i2s->pri_dai ? : i2s->sec_dai;
}
static inline bool other_tx_active(struct i2s_dai *i2s)
{
struct i2s_dai *other = get_other_dai(i2s);
return tx_active(other);
}
static inline bool any_tx_active(struct i2s_dai *i2s)
{
return tx_active(i2s) || other_tx_active(i2s);
}
static inline bool rx_active(struct i2s_dai *i2s)
{
u32 active;
if (!i2s)
return false;
active = readl(i2s->addr + I2SCON) & CON_RXDMA_ACTIVE;
return active ? true : false;
}
static inline bool other_rx_active(struct i2s_dai *i2s)
{
struct i2s_dai *other = get_other_dai(i2s);
return rx_active(other);
}
static inline bool any_rx_active(struct i2s_dai *i2s)
{
return rx_active(i2s) || other_rx_active(i2s);
}
static inline bool other_active(struct i2s_dai *i2s)
{
return other_rx_active(i2s) || other_tx_active(i2s);
}
static inline bool this_active(struct i2s_dai *i2s)
{
return tx_active(i2s) || rx_active(i2s);
}
static inline bool any_active(struct i2s_dai *i2s)
{
return this_active(i2s) || other_active(i2s);
}
static inline struct i2s_dai *to_info(struct snd_soc_dai *dai)
{
return snd_soc_dai_get_drvdata(dai);
}
static inline bool is_opened(struct i2s_dai *i2s)
{
if (i2s && (i2s->mode & DAI_OPENED))
return true;
else
return false;
}
static inline bool is_manager(struct i2s_dai *i2s)
{
if (is_opened(i2s) && (i2s->mode & DAI_MANAGER))
return true;
else
return false;
}
static inline unsigned get_rfs(struct i2s_dai *i2s)
{
u32 rfs;
rfs = readl(i2s->addr + I2SMOD) >> i2s->variant_regs->rfs_off;
rfs &= i2s->variant_regs->rfs_mask;
switch (rfs) {
case 7: return 192;
case 6: return 96;
case 5: return 128;
case 4: return 64;
case 3: return 768;
case 2: return 384;
case 1: return 512;
default: return 256;
}
}
static inline void set_rfs(struct i2s_dai *i2s, unsigned rfs)
{
u32 mod = readl(i2s->addr + I2SMOD);
int rfs_shift = i2s->variant_regs->rfs_off;
mod &= ~(i2s->variant_regs->rfs_mask << rfs_shift);
switch (rfs) {
case 192:
mod |= (EXYNOS7_MOD_RCLK_192FS << rfs_shift);
break;
case 96:
mod |= (EXYNOS7_MOD_RCLK_96FS << rfs_shift);
break;
case 128:
mod |= (EXYNOS7_MOD_RCLK_128FS << rfs_shift);
break;
case 64:
mod |= (EXYNOS7_MOD_RCLK_64FS << rfs_shift);
break;
case 768:
mod |= (MOD_RCLK_768FS << rfs_shift);
break;
case 512:
mod |= (MOD_RCLK_512FS << rfs_shift);
break;
case 384:
mod |= (MOD_RCLK_384FS << rfs_shift);
break;
default:
mod |= (MOD_RCLK_256FS << rfs_shift);
break;
}
writel(mod, i2s->addr + I2SMOD);
}
static inline unsigned get_bfs(struct i2s_dai *i2s)
{
u32 bfs;
bfs = readl(i2s->addr + I2SMOD) >> i2s->variant_regs->bfs_off;
bfs &= i2s->variant_regs->bfs_mask;
switch (bfs) {
case 8: return 256;
case 7: return 192;
case 6: return 128;
case 5: return 96;
case 4: return 64;
case 3: return 24;
case 2: return 16;
case 1: return 48;
default: return 32;
}
}
static inline void set_bfs(struct i2s_dai *i2s, unsigned bfs)
{
u32 mod = readl(i2s->addr + I2SMOD);
int tdm = i2s->quirks & QUIRK_SUPPORTS_TDM;
int bfs_shift = i2s->variant_regs->bfs_off;
if (!tdm && bfs > 48) {
dev_err(&i2s->pdev->dev, "Unsupported BCLK divider\n");
return;
}
mod &= ~(i2s->variant_regs->bfs_mask << bfs_shift);
switch (bfs) {
case 48:
mod |= (MOD_BCLK_48FS << bfs_shift);
break;
case 32:
mod |= (MOD_BCLK_32FS << bfs_shift);
break;
case 24:
mod |= (MOD_BCLK_24FS << bfs_shift);
break;
case 16:
mod |= (MOD_BCLK_16FS << bfs_shift);
break;
case 64:
mod |= (EXYNOS5420_MOD_BCLK_64FS << bfs_shift);
break;
case 96:
mod |= (EXYNOS5420_MOD_BCLK_96FS << bfs_shift);
break;
case 128:
mod |= (EXYNOS5420_MOD_BCLK_128FS << bfs_shift);
break;
case 192:
mod |= (EXYNOS5420_MOD_BCLK_192FS << bfs_shift);
break;
case 256:
mod |= (EXYNOS5420_MOD_BCLK_256FS << bfs_shift);
break;
default:
dev_err(&i2s->pdev->dev, "Wrong BCLK Divider!\n");
return;
}
writel(mod, i2s->addr + I2SMOD);
}
static inline int get_blc(struct i2s_dai *i2s)
{
int blc = readl(i2s->addr + I2SMOD);
blc = (blc >> 13) & 0x3;
switch (blc) {
case 2: return 24;
case 1: return 8;
default: return 16;
}
}
static void i2s_txctrl(struct i2s_dai *i2s, int on)
{
void __iomem *addr = i2s->addr;
int txr_off = i2s->variant_regs->txr_off;
u32 con = readl(addr + I2SCON);
u32 mod = readl(addr + I2SMOD) & ~(3 << txr_off);
if (on) {
con |= CON_ACTIVE;
con &= ~CON_TXCH_PAUSE;
if (is_secondary(i2s)) {
con |= CON_TXSDMA_ACTIVE;
con &= ~CON_TXSDMA_PAUSE;
} else {
con |= CON_TXDMA_ACTIVE;
con &= ~CON_TXDMA_PAUSE;
}
if (any_rx_active(i2s))
mod |= 2 << txr_off;
else
mod |= 0 << txr_off;
} else {
if (is_secondary(i2s)) {
con |= CON_TXSDMA_PAUSE;
con &= ~CON_TXSDMA_ACTIVE;
} else {
con |= CON_TXDMA_PAUSE;
con &= ~CON_TXDMA_ACTIVE;
}
if (other_tx_active(i2s)) {
writel(con, addr + I2SCON);
return;
}
con |= CON_TXCH_PAUSE;
if (any_rx_active(i2s))
mod |= 1 << txr_off;
else
con &= ~CON_ACTIVE;
}
writel(mod, addr + I2SMOD);
writel(con, addr + I2SCON);
}
static void i2s_rxctrl(struct i2s_dai *i2s, int on)
{
void __iomem *addr = i2s->addr;
int txr_off = i2s->variant_regs->txr_off;
u32 con = readl(addr + I2SCON);
u32 mod = readl(addr + I2SMOD) & ~(3 << txr_off);
if (on) {
con |= CON_RXDMA_ACTIVE | CON_ACTIVE;
con &= ~(CON_RXDMA_PAUSE | CON_RXCH_PAUSE);
if (any_tx_active(i2s))
mod |= 2 << txr_off;
else
mod |= 1 << txr_off;
} else {
con |= CON_RXDMA_PAUSE | CON_RXCH_PAUSE;
con &= ~CON_RXDMA_ACTIVE;
if (any_tx_active(i2s))
mod |= 0 << txr_off;
else
con &= ~CON_ACTIVE;
}
writel(mod, addr + I2SMOD);
writel(con, addr + I2SCON);
}
static inline void i2s_fifo(struct i2s_dai *i2s, u32 flush)
{
void __iomem *fic;
u32 val;
if (!i2s)
return;
if (is_secondary(i2s))
fic = i2s->addr + I2SFICS;
else
fic = i2s->addr + I2SFIC;
writel(readl(fic) | flush, fic);
val = msecs_to_loops(1) / 1000;
while (--val)
cpu_relax();
writel(readl(fic) & ~flush, fic);
}
static int i2s_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int rfs, int dir)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = get_other_dai(i2s);
const struct samsung_i2s_variant_regs *i2s_regs = i2s->variant_regs;
unsigned int cdcon_mask = 1 << i2s_regs->cdclkcon_off;
unsigned int rsrc_mask = 1 << i2s_regs->rclksrc_off;
u32 mod, mask, val = 0;
unsigned long flags;
spin_lock_irqsave(i2s->lock, flags);
mod = readl(i2s->addr + I2SMOD);
spin_unlock_irqrestore(i2s->lock, flags);
switch (clk_id) {
case SAMSUNG_I2S_OPCLK:
mask = MOD_OPCLK_MASK;
val = dir;
break;
case SAMSUNG_I2S_CDCLK:
mask = 1 << i2s_regs->cdclkcon_off;
if (dir == SND_SOC_CLOCK_IN)
rfs = 0;
if ((rfs && other && other->rfs && (other->rfs != rfs)) ||
(any_active(i2s) &&
(((dir == SND_SOC_CLOCK_IN)
&& !(mod & cdcon_mask)) ||
((dir == SND_SOC_CLOCK_OUT)
&& (mod & cdcon_mask))))) {
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
}
if (dir == SND_SOC_CLOCK_IN)
val = 1 << i2s_regs->cdclkcon_off;
i2s->rfs = rfs;
break;
case SAMSUNG_I2S_RCLKSRC_0:
case SAMSUNG_I2S_RCLKSRC_1:
mask = 1 << i2s_regs->rclksrc_off;
if ((i2s->quirks & QUIRK_NO_MUXPSR)
|| (clk_id == SAMSUNG_I2S_RCLKSRC_0))
clk_id = 0;
else
clk_id = 1;
if (!any_active(i2s)) {
if (i2s->op_clk && !IS_ERR(i2s->op_clk)) {
if ((clk_id && !(mod & rsrc_mask)) ||
(!clk_id && (mod & rsrc_mask))) {
clk_disable_unprepare(i2s->op_clk);
clk_put(i2s->op_clk);
} else {
i2s->rclk_srcrate =
clk_get_rate(i2s->op_clk);
return 0;
}
}
if (clk_id)
i2s->op_clk = clk_get(&i2s->pdev->dev,
"i2s_opclk1");
else
i2s->op_clk = clk_get(&i2s->pdev->dev,
"i2s_opclk0");
if (WARN_ON(IS_ERR(i2s->op_clk)))
return PTR_ERR(i2s->op_clk);
clk_prepare_enable(i2s->op_clk);
i2s->rclk_srcrate = clk_get_rate(i2s->op_clk);
if (other) {
other->op_clk = i2s->op_clk;
other->rclk_srcrate = i2s->rclk_srcrate;
}
} else if ((!clk_id && (mod & rsrc_mask))
|| (clk_id && !(mod & rsrc_mask))) {
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
} else {
i2s->op_clk = other->op_clk;
i2s->rclk_srcrate = other->rclk_srcrate;
return 0;
}
if (clk_id == 1)
val = 1 << i2s_regs->rclksrc_off;
break;
default:
dev_err(&i2s->pdev->dev, "We don't serve that!\n");
return -EINVAL;
}
spin_lock_irqsave(i2s->lock, flags);
mod = readl(i2s->addr + I2SMOD);
mod = (mod & ~mask) | val;
writel(mod, i2s->addr + I2SMOD);
spin_unlock_irqrestore(i2s->lock, flags);
return 0;
}
static int i2s_set_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct i2s_dai *i2s = to_info(dai);
int lrp_shift, sdf_shift, sdf_mask, lrp_rlow, mod_slave;
u32 mod, tmp = 0;
unsigned long flags;
lrp_shift = i2s->variant_regs->lrp_off;
sdf_shift = i2s->variant_regs->sdf_off;
mod_slave = 1 << i2s->variant_regs->mss_off;
sdf_mask = MOD_SDF_MASK << sdf_shift;
lrp_rlow = MOD_LR_RLOW << lrp_shift;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
tmp |= lrp_rlow;
tmp |= (MOD_SDF_MSB << sdf_shift);
break;
case SND_SOC_DAIFMT_LEFT_J:
tmp |= lrp_rlow;
tmp |= (MOD_SDF_LSB << sdf_shift);
break;
case SND_SOC_DAIFMT_I2S:
tmp |= (MOD_SDF_IIS << sdf_shift);
break;
default:
dev_err(&i2s->pdev->dev, "Format not supported\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
if (tmp & lrp_rlow)
tmp &= ~lrp_rlow;
else
tmp |= lrp_rlow;
break;
default:
dev_err(&i2s->pdev->dev, "Polarity not supported\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
tmp |= mod_slave;
break;
case SND_SOC_DAIFMT_CBS_CFS:
if (i2s->rclk_srcrate == 0)
i2s_set_sysclk(dai, SAMSUNG_I2S_RCLKSRC_0,
0, SND_SOC_CLOCK_IN);
break;
default:
dev_err(&i2s->pdev->dev, "master/slave format not supported\n");
return -EINVAL;
}
spin_lock_irqsave(i2s->lock, flags);
mod = readl(i2s->addr + I2SMOD);
if (any_active(i2s) &&
((mod & (sdf_mask | lrp_rlow | mod_slave)) != tmp)) {
spin_unlock_irqrestore(i2s->lock, flags);
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
}
mod &= ~(sdf_mask | lrp_rlow | mod_slave);
mod |= tmp;
writel(mod, i2s->addr + I2SMOD);
spin_unlock_irqrestore(i2s->lock, flags);
return 0;
}
static int i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
u32 mod, mask = 0, val = 0;
unsigned long flags;
if (!is_secondary(i2s))
mask |= (MOD_DC2_EN | MOD_DC1_EN);
switch (params_channels(params)) {
case 6:
val |= MOD_DC2_EN;
case 4:
val |= MOD_DC1_EN;
break;
case 2:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
i2s->dma_playback.dma_size = 4;
else
i2s->dma_capture.dma_size = 4;
break;
case 1:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
i2s->dma_playback.dma_size = 2;
else
i2s->dma_capture.dma_size = 2;
break;
default:
dev_err(&i2s->pdev->dev, "%d channels not supported\n",
params_channels(params));
return -EINVAL;
}
if (is_secondary(i2s))
mask |= MOD_BLCS_MASK;
else
mask |= MOD_BLCP_MASK;
if (is_manager(i2s))
mask |= MOD_BLC_MASK;
switch (params_width(params)) {
case 8:
if (is_secondary(i2s))
val |= MOD_BLCS_8BIT;
else
val |= MOD_BLCP_8BIT;
if (is_manager(i2s))
val |= MOD_BLC_8BIT;
break;
case 16:
if (is_secondary(i2s))
val |= MOD_BLCS_16BIT;
else
val |= MOD_BLCP_16BIT;
if (is_manager(i2s))
val |= MOD_BLC_16BIT;
break;
case 24:
if (is_secondary(i2s))
val |= MOD_BLCS_24BIT;
else
val |= MOD_BLCP_24BIT;
if (is_manager(i2s))
val |= MOD_BLC_24BIT;
break;
default:
dev_err(&i2s->pdev->dev, "Format(%d) not supported\n",
params_format(params));
return -EINVAL;
}
spin_lock_irqsave(i2s->lock, flags);
mod = readl(i2s->addr + I2SMOD);
mod = (mod & ~mask) | val;
writel(mod, i2s->addr + I2SMOD);
spin_unlock_irqrestore(i2s->lock, flags);
samsung_asoc_init_dma_data(dai, &i2s->dma_playback, &i2s->dma_capture);
i2s->frmclk = params_rate(params);
return 0;
}
static int i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = get_other_dai(i2s);
unsigned long flags;
spin_lock_irqsave(&lock, flags);
i2s->mode |= DAI_OPENED;
if (is_manager(other))
i2s->mode &= ~DAI_MANAGER;
else
i2s->mode |= DAI_MANAGER;
if (!any_active(i2s) && (i2s->quirks & QUIRK_NEED_RSTCLR))
writel(CON_RSTCLR, i2s->addr + I2SCON);
spin_unlock_irqrestore(&lock, flags);
return 0;
}
static void i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = get_other_dai(i2s);
unsigned long flags;
spin_lock_irqsave(&lock, flags);
i2s->mode &= ~DAI_OPENED;
i2s->mode &= ~DAI_MANAGER;
if (is_opened(other))
other->mode |= DAI_MANAGER;
i2s->rfs = 0;
i2s->bfs = 0;
spin_unlock_irqrestore(&lock, flags);
}
static int config_setup(struct i2s_dai *i2s)
{
struct i2s_dai *other = get_other_dai(i2s);
unsigned rfs, bfs, blc;
u32 psr;
blc = get_blc(i2s);
bfs = i2s->bfs;
if (!bfs && other)
bfs = other->bfs;
if (!bfs)
bfs = blc * 2;
rfs = i2s->rfs;
if (!rfs && other)
rfs = other->rfs;
if ((rfs == 256 || rfs == 512) && (blc == 24)) {
dev_err(&i2s->pdev->dev,
"%d-RFS not supported for 24-blc\n", rfs);
return -EINVAL;
}
if (!rfs) {
if (bfs == 16 || bfs == 32)
rfs = 256;
else
rfs = 384;
}
if (any_active(i2s) && (get_rfs(i2s) != rfs || get_bfs(i2s) != bfs)) {
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
}
set_bfs(i2s, bfs);
set_rfs(i2s, rfs);
if (is_slave(i2s))
return 0;
if (!(i2s->quirks & QUIRK_NO_MUXPSR)) {
psr = i2s->rclk_srcrate / i2s->frmclk / rfs;
writel(((psr - 1) << 8) | PSR_PSREN, i2s->addr + I2SPSR);
dev_dbg(&i2s->pdev->dev,
"RCLK_SRC=%luHz PSR=%u, RCLK=%dfs, BCLK=%dfs\n",
i2s->rclk_srcrate, psr, rfs, bfs);
}
return 0;
}
static int i2s_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
int capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct i2s_dai *i2s = to_info(rtd->cpu_dai);
unsigned long flags;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
spin_lock_irqsave(i2s->lock, flags);
if (config_setup(i2s)) {
spin_unlock_irqrestore(i2s->lock, flags);
return -EINVAL;
}
if (capture)
i2s_rxctrl(i2s, 1);
else
i2s_txctrl(i2s, 1);
spin_unlock_irqrestore(i2s->lock, flags);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
spin_lock_irqsave(i2s->lock, flags);
if (capture) {
i2s_rxctrl(i2s, 0);
i2s_fifo(i2s, FIC_RXFLUSH);
} else {
i2s_txctrl(i2s, 0);
i2s_fifo(i2s, FIC_TXFLUSH);
}
spin_unlock_irqrestore(i2s->lock, flags);
break;
}
return 0;
}
static int i2s_set_clkdiv(struct snd_soc_dai *dai,
int div_id, int div)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = get_other_dai(i2s);
switch (div_id) {
case SAMSUNG_I2S_DIV_BCLK:
if ((any_active(i2s) && div && (get_bfs(i2s) != div))
|| (other && other->bfs && (other->bfs != div))) {
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
}
i2s->bfs = div;
break;
default:
dev_err(&i2s->pdev->dev,
"Invalid clock divider(%d)\n", div_id);
return -EINVAL;
}
return 0;
}
static snd_pcm_sframes_t
i2s_delay(struct snd_pcm_substream *substream, struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
u32 reg = readl(i2s->addr + I2SFIC);
snd_pcm_sframes_t delay;
const struct samsung_i2s_variant_regs *i2s_regs = i2s->variant_regs;
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
delay = FIC_RXCOUNT(reg);
else if (is_secondary(i2s))
delay = FICS_TXCOUNT(readl(i2s->addr + I2SFICS));
else
delay = (reg >> i2s_regs->ftx0cnt_off) & 0x7f;
return delay;
}
static int i2s_suspend(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
i2s->suspend_i2smod = readl(i2s->addr + I2SMOD);
i2s->suspend_i2scon = readl(i2s->addr + I2SCON);
i2s->suspend_i2spsr = readl(i2s->addr + I2SPSR);
return 0;
}
static int i2s_resume(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
writel(i2s->suspend_i2scon, i2s->addr + I2SCON);
writel(i2s->suspend_i2smod, i2s->addr + I2SMOD);
writel(i2s->suspend_i2spsr, i2s->addr + I2SPSR);
return 0;
}
static int samsung_i2s_dai_probe(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = get_other_dai(i2s);
unsigned long flags;
if (is_secondary(i2s)) {
samsung_asoc_init_dma_data(dai, &other->sec_dai->dma_playback,
NULL);
} else {
samsung_asoc_init_dma_data(dai, &i2s->dma_playback,
&i2s->dma_capture);
if (i2s->quirks & QUIRK_NEED_RSTCLR)
writel(CON_RSTCLR, i2s->addr + I2SCON);
if (i2s->quirks & QUIRK_SUPPORTS_IDMA)
idma_reg_addr_init(i2s->addr,
i2s->sec_dai->idma_playback.dma_addr);
}
i2s->rfs = 0;
i2s->bfs = 0;
i2s->rclk_srcrate = 0;
spin_lock_irqsave(i2s->lock, flags);
i2s_txctrl(i2s, 0);
i2s_rxctrl(i2s, 0);
i2s_fifo(i2s, FIC_TXFLUSH);
i2s_fifo(other, FIC_TXFLUSH);
i2s_fifo(i2s, FIC_RXFLUSH);
spin_unlock_irqrestore(i2s->lock, flags);
if (!is_opened(other))
i2s_set_sysclk(dai, SAMSUNG_I2S_CDCLK,
0, SND_SOC_CLOCK_IN);
return 0;
}
static int samsung_i2s_dai_remove(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = snd_soc_dai_get_drvdata(dai);
if (!is_secondary(i2s)) {
if (i2s->quirks & QUIRK_NEED_RSTCLR) {
spin_lock(i2s->lock);
writel(0, i2s->addr + I2SCON);
spin_unlock(i2s->lock);
}
}
return 0;
}
static struct i2s_dai *i2s_alloc_dai(struct platform_device *pdev, bool sec)
{
struct i2s_dai *i2s;
int ret;
i2s = devm_kzalloc(&pdev->dev, sizeof(struct i2s_dai), GFP_KERNEL);
if (i2s == NULL)
return NULL;
i2s->pdev = pdev;
i2s->pri_dai = NULL;
i2s->sec_dai = NULL;
i2s->i2s_dai_drv.symmetric_rates = 1;
i2s->i2s_dai_drv.probe = samsung_i2s_dai_probe;
i2s->i2s_dai_drv.remove = samsung_i2s_dai_remove;
i2s->i2s_dai_drv.ops = &samsung_i2s_dai_ops;
i2s->i2s_dai_drv.suspend = i2s_suspend;
i2s->i2s_dai_drv.resume = i2s_resume;
i2s->i2s_dai_drv.playback.channels_min = 1;
i2s->i2s_dai_drv.playback.channels_max = 2;
i2s->i2s_dai_drv.playback.rates = SAMSUNG_I2S_RATES;
i2s->i2s_dai_drv.playback.formats = SAMSUNG_I2S_FMTS;
if (!sec) {
i2s->i2s_dai_drv.capture.channels_min = 1;
i2s->i2s_dai_drv.capture.channels_max = 2;
i2s->i2s_dai_drv.capture.rates = SAMSUNG_I2S_RATES;
i2s->i2s_dai_drv.capture.formats = SAMSUNG_I2S_FMTS;
dev_set_drvdata(&i2s->pdev->dev, i2s);
} else {
i2s->pdev = platform_device_alloc("samsung-i2s-sec", -1);
if (!i2s->pdev)
return NULL;
i2s->pdev->dev.parent = &pdev->dev;
platform_set_drvdata(i2s->pdev, i2s);
ret = platform_device_add(i2s->pdev);
if (ret < 0)
return NULL;
}
return i2s;
}
static inline const struct samsung_i2s_dai_data *samsung_i2s_get_driver_data(
struct platform_device *pdev)
{
if (IS_ENABLED(CONFIG_OF) && pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(exynos_i2s_match, pdev->dev.of_node);
return match ? match->data : NULL;
} else {
return (struct samsung_i2s_dai_data *)
platform_get_device_id(pdev)->driver_data;
}
}
static int i2s_runtime_suspend(struct device *dev)
{
struct i2s_dai *i2s = dev_get_drvdata(dev);
clk_disable_unprepare(i2s->clk);
return 0;
}
static int i2s_runtime_resume(struct device *dev)
{
struct i2s_dai *i2s = dev_get_drvdata(dev);
clk_prepare_enable(i2s->clk);
return 0;
}
static void i2s_unregister_clocks(struct i2s_dai *i2s)
{
int i;
for (i = 0; i < i2s->clk_data.clk_num; i++) {
if (!IS_ERR(i2s->clk_table[i]))
clk_unregister(i2s->clk_table[i]);
}
}
static void i2s_unregister_clock_provider(struct platform_device *pdev)
{
struct i2s_dai *i2s = dev_get_drvdata(&pdev->dev);
of_clk_del_provider(pdev->dev.of_node);
i2s_unregister_clocks(i2s);
}
static int i2s_register_clock_provider(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct i2s_dai *i2s = dev_get_drvdata(dev);
const char *clk_name[2] = { "i2s_opclk0", "i2s_opclk1" };
const char *p_names[2] = { NULL };
const struct samsung_i2s_variant_regs *reg_info = i2s->variant_regs;
struct clk *rclksrc;
int ret, i;
if (!of_find_property(dev->of_node, "#clock-cells", NULL))
return 0;
for (i = 0; i < ARRAY_SIZE(p_names); i++) {
rclksrc = clk_get(dev, clk_name[i]);
if (IS_ERR(rclksrc))
continue;
p_names[i] = __clk_get_name(rclksrc);
clk_put(rclksrc);
}
if (!(i2s->quirks & QUIRK_NO_MUXPSR)) {
u32 val = readl(i2s->addr + I2SPSR);
writel(val | PSR_PSREN, i2s->addr + I2SPSR);
i2s->clk_table[CLK_I2S_RCLK_SRC] = clk_register_mux(NULL,
"i2s_rclksrc", p_names, ARRAY_SIZE(p_names),
CLK_SET_RATE_NO_REPARENT | CLK_SET_RATE_PARENT,
i2s->addr + I2SMOD, reg_info->rclksrc_off,
1, 0, i2s->lock);
i2s->clk_table[CLK_I2S_RCLK_PSR] = clk_register_divider(NULL,
"i2s_presc", "i2s_rclksrc",
CLK_SET_RATE_PARENT,
i2s->addr + I2SPSR, 8, 6, 0, i2s->lock);
p_names[0] = "i2s_presc";
i2s->clk_data.clk_num = 2;
}
of_property_read_string_index(dev->of_node,
"clock-output-names", 0, &clk_name[0]);
i2s->clk_table[CLK_I2S_CDCLK] = clk_register_gate(NULL, clk_name[0],
p_names[0], CLK_SET_RATE_PARENT,
i2s->addr + I2SMOD, reg_info->cdclkcon_off,
CLK_GATE_SET_TO_DISABLE, i2s->lock);
i2s->clk_data.clk_num += 1;
i2s->clk_data.clks = i2s->clk_table;
ret = of_clk_add_provider(dev->of_node, of_clk_src_onecell_get,
&i2s->clk_data);
if (ret < 0) {
dev_err(dev, "failed to add clock provider: %d\n", ret);
i2s_unregister_clocks(i2s);
}
return ret;
}
static int samsung_i2s_probe(struct platform_device *pdev)
{
struct i2s_dai *pri_dai, *sec_dai = NULL;
struct s3c_audio_pdata *i2s_pdata = pdev->dev.platform_data;
struct samsung_i2s *i2s_cfg = NULL;
struct resource *res;
u32 regs_base, quirks = 0, idma_addr = 0;
struct device_node *np = pdev->dev.of_node;
const struct samsung_i2s_dai_data *i2s_dai_data;
int ret;
i2s_dai_data = samsung_i2s_get_driver_data(pdev);
if (i2s_dai_data->dai_type == TYPE_SEC) {
sec_dai = dev_get_drvdata(&pdev->dev);
if (!sec_dai) {
dev_err(&pdev->dev, "Unable to get drvdata\n");
return -EFAULT;
}
ret = devm_snd_soc_register_component(&sec_dai->pdev->dev,
&samsung_i2s_component,
&sec_dai->i2s_dai_drv, 1);
if (ret != 0)
return ret;
return samsung_asoc_dma_platform_register(&pdev->dev,
sec_dai->filter);
}
pri_dai = i2s_alloc_dai(pdev, false);
if (!pri_dai) {
dev_err(&pdev->dev, "Unable to alloc I2S_pri\n");
return -ENOMEM;
}
spin_lock_init(&pri_dai->spinlock);
pri_dai->lock = &pri_dai->spinlock;
if (!np) {
if (i2s_pdata == NULL) {
dev_err(&pdev->dev, "Can't work without s3c_audio_pdata\n");
return -EINVAL;
}
pri_dai->dma_playback.slave = i2s_pdata->dma_playback;
pri_dai->dma_capture.slave = i2s_pdata->dma_capture;
pri_dai->filter = i2s_pdata->dma_filter;
if (&i2s_pdata->type)
i2s_cfg = &i2s_pdata->type.i2s;
if (i2s_cfg) {
quirks = i2s_cfg->quirks;
idma_addr = i2s_cfg->idma_addr;
}
} else {
quirks = i2s_dai_data->quirks;
if (of_property_read_u32(np, "samsung,idma-addr",
&idma_addr)) {
if (quirks & QUIRK_SUPPORTS_IDMA) {
dev_info(&pdev->dev, "idma address is not"\
"specified");
}
}
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pri_dai->addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pri_dai->addr))
return PTR_ERR(pri_dai->addr);
regs_base = res->start;
pri_dai->clk = devm_clk_get(&pdev->dev, "iis");
if (IS_ERR(pri_dai->clk)) {
dev_err(&pdev->dev, "Failed to get iis clock\n");
return PTR_ERR(pri_dai->clk);
}
ret = clk_prepare_enable(pri_dai->clk);
if (ret != 0) {
dev_err(&pdev->dev, "failed to enable clock: %d\n", ret);
return ret;
}
pri_dai->dma_playback.dma_addr = regs_base + I2STXD;
pri_dai->dma_capture.dma_addr = regs_base + I2SRXD;
pri_dai->dma_playback.ch_name = "tx";
pri_dai->dma_capture.ch_name = "rx";
pri_dai->dma_playback.dma_size = 4;
pri_dai->dma_capture.dma_size = 4;
pri_dai->quirks = quirks;
pri_dai->variant_regs = i2s_dai_data->i2s_variant_regs;
if (quirks & QUIRK_PRI_6CHAN)
pri_dai->i2s_dai_drv.playback.channels_max = 6;
if (quirks & QUIRK_SEC_DAI) {
sec_dai = i2s_alloc_dai(pdev, true);
if (!sec_dai) {
dev_err(&pdev->dev, "Unable to alloc I2S_sec\n");
return -ENOMEM;
}
sec_dai->lock = &pri_dai->spinlock;
sec_dai->variant_regs = pri_dai->variant_regs;
sec_dai->dma_playback.dma_addr = regs_base + I2STXDS;
sec_dai->dma_playback.ch_name = "tx-sec";
if (!np) {
sec_dai->dma_playback.slave = i2s_pdata->dma_play_sec;
sec_dai->filter = i2s_pdata->dma_filter;
}
sec_dai->dma_playback.dma_size = 4;
sec_dai->addr = pri_dai->addr;
sec_dai->clk = pri_dai->clk;
sec_dai->quirks = quirks;
sec_dai->idma_playback.dma_addr = idma_addr;
sec_dai->pri_dai = pri_dai;
pri_dai->sec_dai = sec_dai;
}
if (i2s_pdata && i2s_pdata->cfg_gpio && i2s_pdata->cfg_gpio(pdev)) {
dev_err(&pdev->dev, "Unable to configure gpio\n");
return -EINVAL;
}
devm_snd_soc_register_component(&pri_dai->pdev->dev,
&samsung_i2s_component,
&pri_dai->i2s_dai_drv, 1);
pm_runtime_enable(&pdev->dev);
ret = samsung_asoc_dma_platform_register(&pdev->dev, pri_dai->filter);
if (ret != 0)
return ret;
return i2s_register_clock_provider(pdev);
}
static int samsung_i2s_remove(struct platform_device *pdev)
{
struct i2s_dai *i2s, *other;
i2s = dev_get_drvdata(&pdev->dev);
other = get_other_dai(i2s);
if (other) {
other->pri_dai = NULL;
other->sec_dai = NULL;
} else {
pm_runtime_disable(&pdev->dev);
}
if (!is_secondary(i2s)) {
i2s_unregister_clock_provider(pdev);
clk_disable_unprepare(i2s->clk);
}
i2s->pri_dai = NULL;
i2s->sec_dai = NULL;
return 0;
}
