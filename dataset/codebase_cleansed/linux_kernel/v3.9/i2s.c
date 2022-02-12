static inline bool is_secondary(struct i2s_dai *i2s)
{
return i2s->pri_dai ? true : false;
}
static inline bool is_slave(struct i2s_dai *i2s)
{
return (readl(i2s->addr + I2SMOD) & MOD_SLAVE) ? true : false;
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
static inline bool other_tx_active(struct i2s_dai *i2s)
{
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
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
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
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
u32 rfs = (readl(i2s->addr + I2SMOD) >> 3) & 0x3;
switch (rfs) {
case 3: return 768;
case 2: return 384;
case 1: return 512;
default: return 256;
}
}
static inline void set_rfs(struct i2s_dai *i2s, unsigned rfs)
{
u32 mod = readl(i2s->addr + I2SMOD);
mod &= ~MOD_RCLK_MASK;
switch (rfs) {
case 768:
mod |= MOD_RCLK_768FS;
break;
case 512:
mod |= MOD_RCLK_512FS;
break;
case 384:
mod |= MOD_RCLK_384FS;
break;
default:
mod |= MOD_RCLK_256FS;
break;
}
writel(mod, i2s->addr + I2SMOD);
}
static inline unsigned get_bfs(struct i2s_dai *i2s)
{
u32 bfs = (readl(i2s->addr + I2SMOD) >> 1) & 0x3;
switch (bfs) {
case 3: return 24;
case 2: return 16;
case 1: return 48;
default: return 32;
}
}
static inline void set_bfs(struct i2s_dai *i2s, unsigned bfs)
{
u32 mod = readl(i2s->addr + I2SMOD);
mod &= ~MOD_BCLK_MASK;
switch (bfs) {
case 48:
mod |= MOD_BCLK_48FS;
break;
case 32:
mod |= MOD_BCLK_32FS;
break;
case 24:
mod |= MOD_BCLK_24FS;
break;
case 16:
mod |= MOD_BCLK_16FS;
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
u32 con = readl(addr + I2SCON);
u32 mod = readl(addr + I2SMOD) & ~MOD_MASK;
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
mod |= MOD_TXRX;
else
mod |= MOD_TXONLY;
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
mod |= MOD_RXONLY;
else
con &= ~CON_ACTIVE;
}
writel(mod, addr + I2SMOD);
writel(con, addr + I2SCON);
}
static void i2s_rxctrl(struct i2s_dai *i2s, int on)
{
void __iomem *addr = i2s->addr;
u32 con = readl(addr + I2SCON);
u32 mod = readl(addr + I2SMOD) & ~MOD_MASK;
if (on) {
con |= CON_RXDMA_ACTIVE | CON_ACTIVE;
con &= ~(CON_RXDMA_PAUSE | CON_RXCH_PAUSE);
if (any_tx_active(i2s))
mod |= MOD_TXRX;
else
mod |= MOD_RXONLY;
} else {
con |= CON_RXDMA_PAUSE | CON_RXCH_PAUSE;
con &= ~CON_RXDMA_ACTIVE;
if (any_tx_active(i2s))
mod |= MOD_TXONLY;
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
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
u32 mod = readl(i2s->addr + I2SMOD);
switch (clk_id) {
case SAMSUNG_I2S_CDCLK:
if (dir == SND_SOC_CLOCK_IN)
rfs = 0;
if ((rfs && other->rfs && (other->rfs != rfs)) ||
(any_active(i2s) &&
(((dir == SND_SOC_CLOCK_IN)
&& !(mod & MOD_CDCLKCON)) ||
((dir == SND_SOC_CLOCK_OUT)
&& (mod & MOD_CDCLKCON))))) {
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
}
if (dir == SND_SOC_CLOCK_IN)
mod |= MOD_CDCLKCON;
else
mod &= ~MOD_CDCLKCON;
i2s->rfs = rfs;
break;
case SAMSUNG_I2S_RCLKSRC_0:
case SAMSUNG_I2S_RCLKSRC_1:
if ((i2s->quirks & QUIRK_NO_MUXPSR)
|| (clk_id == SAMSUNG_I2S_RCLKSRC_0))
clk_id = 0;
else
clk_id = 1;
if (!any_active(i2s)) {
if (i2s->op_clk) {
if ((clk_id && !(mod & MOD_IMS_SYSMUX)) ||
(!clk_id && (mod & MOD_IMS_SYSMUX))) {
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
clk_prepare_enable(i2s->op_clk);
i2s->rclk_srcrate = clk_get_rate(i2s->op_clk);
if (other) {
other->op_clk = i2s->op_clk;
other->rclk_srcrate = i2s->rclk_srcrate;
}
} else if ((!clk_id && (mod & MOD_IMS_SYSMUX))
|| (clk_id && !(mod & MOD_IMS_SYSMUX))) {
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
} else {
i2s->op_clk = other->op_clk;
i2s->rclk_srcrate = other->rclk_srcrate;
return 0;
}
if (clk_id == 0)
mod &= ~MOD_IMS_SYSMUX;
else
mod |= MOD_IMS_SYSMUX;
break;
default:
dev_err(&i2s->pdev->dev, "We don't serve that!\n");
return -EINVAL;
}
writel(mod, i2s->addr + I2SMOD);
return 0;
}
static int i2s_set_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
struct i2s_dai *i2s = to_info(dai);
u32 mod = readl(i2s->addr + I2SMOD);
u32 tmp = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
tmp |= MOD_LR_RLOW;
tmp |= MOD_SDF_MSB;
break;
case SND_SOC_DAIFMT_LEFT_J:
tmp |= MOD_LR_RLOW;
tmp |= MOD_SDF_LSB;
break;
case SND_SOC_DAIFMT_I2S:
tmp |= MOD_SDF_IIS;
break;
default:
dev_err(&i2s->pdev->dev, "Format not supported\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
if (tmp & MOD_LR_RLOW)
tmp &= ~MOD_LR_RLOW;
else
tmp |= MOD_LR_RLOW;
break;
default:
dev_err(&i2s->pdev->dev, "Polarity not supported\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
tmp |= MOD_SLAVE;
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
if (any_active(i2s) &&
((mod & (MOD_SDF_MASK | MOD_LR_RLOW
| MOD_SLAVE)) != tmp)) {
dev_err(&i2s->pdev->dev,
"%s:%d Other DAI busy\n", __func__, __LINE__);
return -EAGAIN;
}
mod &= ~(MOD_SDF_MASK | MOD_LR_RLOW | MOD_SLAVE);
mod |= tmp;
writel(mod, i2s->addr + I2SMOD);
return 0;
}
static int i2s_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
u32 mod = readl(i2s->addr + I2SMOD);
if (!is_secondary(i2s))
mod &= ~(MOD_DC2_EN | MOD_DC1_EN);
switch (params_channels(params)) {
case 6:
mod |= MOD_DC2_EN;
case 4:
mod |= MOD_DC1_EN;
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
mod &= ~MOD_BLCS_MASK;
else
mod &= ~MOD_BLCP_MASK;
if (is_manager(i2s))
mod &= ~MOD_BLC_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
if (is_secondary(i2s))
mod |= MOD_BLCS_8BIT;
else
mod |= MOD_BLCP_8BIT;
if (is_manager(i2s))
mod |= MOD_BLC_8BIT;
break;
case SNDRV_PCM_FORMAT_S16_LE:
if (is_secondary(i2s))
mod |= MOD_BLCS_16BIT;
else
mod |= MOD_BLCP_16BIT;
if (is_manager(i2s))
mod |= MOD_BLC_16BIT;
break;
case SNDRV_PCM_FORMAT_S24_LE:
if (is_secondary(i2s))
mod |= MOD_BLCS_24BIT;
else
mod |= MOD_BLCP_24BIT;
if (is_manager(i2s))
mod |= MOD_BLC_24BIT;
break;
default:
dev_err(&i2s->pdev->dev, "Format(%d) not supported\n",
params_format(params));
return -EINVAL;
}
writel(mod, i2s->addr + I2SMOD);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
snd_soc_dai_set_dma_data(dai, substream,
(void *)&i2s->dma_playback);
else
snd_soc_dai_set_dma_data(dai, substream,
(void *)&i2s->dma_capture);
i2s->frmclk = params_rate(params);
return 0;
}
static int i2s_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
unsigned long flags;
spin_lock_irqsave(&lock, flags);
i2s->mode |= DAI_OPENED;
if (is_manager(other))
i2s->mode &= ~DAI_MANAGER;
else
i2s->mode |= DAI_MANAGER;
i2s->rclk_srcrate = 0;
if (!any_active(i2s) && (i2s->quirks & QUIRK_NEED_RSTCLR))
writel(CON_RSTCLR, i2s->addr + I2SCON);
spin_unlock_irqrestore(&lock, flags);
return 0;
}
static void i2s_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
unsigned long flags;
spin_lock_irqsave(&lock, flags);
i2s->mode &= ~DAI_OPENED;
i2s->mode &= ~DAI_MANAGER;
if (is_opened(other))
other->mode |= DAI_MANAGER;
i2s->rfs = 0;
i2s->bfs = 0;
spin_unlock_irqrestore(&lock, flags);
if (!is_opened(other))
i2s_set_sysclk(dai, SAMSUNG_I2S_CDCLK,
0, SND_SOC_CLOCK_IN);
}
static int config_setup(struct i2s_dai *i2s)
{
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
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
if (is_slave(i2s))
return 0;
set_bfs(i2s, bfs);
set_rfs(i2s, rfs);
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
local_irq_save(flags);
if (config_setup(i2s)) {
local_irq_restore(flags);
return -EINVAL;
}
if (capture)
i2s_rxctrl(i2s, 1);
else
i2s_txctrl(i2s, 1);
local_irq_restore(flags);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
local_irq_save(flags);
if (capture) {
i2s_rxctrl(i2s, 0);
i2s_fifo(i2s, FIC_RXFLUSH);
} else {
i2s_txctrl(i2s, 0);
i2s_fifo(i2s, FIC_TXFLUSH);
}
local_irq_restore(flags);
break;
}
return 0;
}
static int i2s_set_clkdiv(struct snd_soc_dai *dai,
int div_id, int div)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
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
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
delay = FIC_RXCOUNT(reg);
else if (is_secondary(i2s))
delay = FICS_TXCOUNT(readl(i2s->addr + I2SFICS));
else
delay = FIC_TXCOUNT(reg);
return delay;
}
static int i2s_suspend(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
if (dai->active) {
i2s->suspend_i2smod = readl(i2s->addr + I2SMOD);
i2s->suspend_i2scon = readl(i2s->addr + I2SCON);
i2s->suspend_i2spsr = readl(i2s->addr + I2SPSR);
}
return 0;
}
static int i2s_resume(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
if (dai->active) {
writel(i2s->suspend_i2scon, i2s->addr + I2SCON);
writel(i2s->suspend_i2smod, i2s->addr + I2SMOD);
writel(i2s->suspend_i2spsr, i2s->addr + I2SPSR);
}
return 0;
}
static int samsung_i2s_dai_probe(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = to_info(dai);
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
if (other && other->clk)
goto probe_exit;
i2s->addr = ioremap(i2s->base, 0x100);
if (i2s->addr == NULL) {
dev_err(&i2s->pdev->dev, "cannot ioremap registers\n");
return -ENXIO;
}
i2s->clk = clk_get(&i2s->pdev->dev, "iis");
if (IS_ERR(i2s->clk)) {
dev_err(&i2s->pdev->dev, "failed to get i2s_clock\n");
iounmap(i2s->addr);
return -ENOENT;
}
clk_prepare_enable(i2s->clk);
if (other) {
other->addr = i2s->addr;
other->clk = i2s->clk;
}
if (i2s->quirks & QUIRK_NEED_RSTCLR)
writel(CON_RSTCLR, i2s->addr + I2SCON);
if (i2s->quirks & QUIRK_SEC_DAI)
idma_reg_addr_init(i2s->addr,
i2s->sec_dai->idma_playback.dma_addr);
probe_exit:
i2s->rfs = 0;
i2s->bfs = 0;
i2s_txctrl(i2s, 0);
i2s_rxctrl(i2s, 0);
i2s_fifo(i2s, FIC_TXFLUSH);
i2s_fifo(other, FIC_TXFLUSH);
i2s_fifo(i2s, FIC_RXFLUSH);
if (!is_opened(other))
i2s_set_sysclk(dai, SAMSUNG_I2S_CDCLK,
0, SND_SOC_CLOCK_IN);
return 0;
}
static int samsung_i2s_dai_remove(struct snd_soc_dai *dai)
{
struct i2s_dai *i2s = snd_soc_dai_get_drvdata(dai);
struct i2s_dai *other = i2s->pri_dai ? : i2s->sec_dai;
if (!other || !other->clk) {
if (i2s->quirks & QUIRK_NEED_RSTCLR)
writel(0, i2s->addr + I2SCON);
clk_disable_unprepare(i2s->clk);
clk_put(i2s->clk);
iounmap(i2s->addr);
}
i2s->clk = NULL;
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
i2s->i2s_dai_drv.playback.channels_min = 2;
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
if (IS_ERR(i2s->pdev))
return NULL;
platform_set_drvdata(i2s->pdev, i2s);
ret = platform_device_add(i2s->pdev);
if (ret < 0)
return NULL;
}
return i2s;
}
static int samsung_i2s_parse_dt_gpio(struct i2s_dai *i2s)
{
struct device *dev = &i2s->pdev->dev;
int index, gpio, ret;
for (index = 0; index < 7; index++) {
gpio = of_get_gpio(dev->of_node, index);
if (!gpio_is_valid(gpio)) {
dev_err(dev, "invalid gpio[%d]: %d\n", index, gpio);
goto free_gpio;
}
ret = gpio_request(gpio, dev_name(dev));
if (ret) {
dev_err(dev, "gpio [%d] request failed\n", gpio);
goto free_gpio;
}
i2s->gpios[index] = gpio;
}
return 0;
free_gpio:
while (--index >= 0)
gpio_free(i2s->gpios[index]);
return -EINVAL;
}
static void samsung_i2s_dt_gpio_free(struct i2s_dai *i2s)
{
unsigned int index;
for (index = 0; index < 7; index++)
gpio_free(i2s->gpios[index]);
}
static int samsung_i2s_parse_dt_gpio(struct i2s_dai *dai)
{
return -EINVAL;
}
static void samsung_i2s_dt_gpio_free(struct i2s_dai *dai)
{
}
static inline int samsung_i2s_get_driver_data(struct platform_device *pdev)
{
#ifdef CONFIG_OF
struct samsung_i2s_dai_data *data;
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(exynos_i2s_match, pdev->dev.of_node);
data = (struct samsung_i2s_dai_data *) match->data;
return data->dai_type;
} else
#endif
return platform_get_device_id(pdev)->driver_data;
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
static int samsung_i2s_probe(struct platform_device *pdev)
{
struct i2s_dai *pri_dai, *sec_dai = NULL;
struct s3c_audio_pdata *i2s_pdata = pdev->dev.platform_data;
struct samsung_i2s *i2s_cfg = NULL;
struct resource *res;
u32 regs_base, quirks = 0, idma_addr = 0;
struct device_node *np = pdev->dev.of_node;
enum samsung_dai_type samsung_dai_type;
int ret = 0;
samsung_dai_type = samsung_i2s_get_driver_data(pdev);
if (samsung_dai_type == TYPE_SEC) {
sec_dai = dev_get_drvdata(&pdev->dev);
if (!sec_dai) {
dev_err(&pdev->dev, "Unable to get drvdata\n");
return -EFAULT;
}
snd_soc_register_dai(&sec_dai->pdev->dev,
&sec_dai->i2s_dai_drv);
asoc_dma_platform_register(&pdev->dev);
return 0;
}
pri_dai = i2s_alloc_dai(pdev, false);
if (!pri_dai) {
dev_err(&pdev->dev, "Unable to alloc I2S_pri\n");
return -ENOMEM;
}
if (!np) {
res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!res) {
dev_err(&pdev->dev,
"Unable to get I2S-TX dma resource\n");
return -ENXIO;
}
pri_dai->dma_playback.channel = res->start;
res = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!res) {
dev_err(&pdev->dev,
"Unable to get I2S-RX dma resource\n");
return -ENXIO;
}
pri_dai->dma_capture.channel = res->start;
if (i2s_pdata == NULL) {
dev_err(&pdev->dev, "Can't work without s3c_audio_pdata\n");
return -EINVAL;
}
if (&i2s_pdata->type)
i2s_cfg = &i2s_pdata->type.i2s;
if (i2s_cfg) {
quirks = i2s_cfg->quirks;
idma_addr = i2s_cfg->idma_addr;
}
} else {
if (of_find_property(np, "samsung,supports-6ch", NULL))
quirks |= QUIRK_PRI_6CHAN;
if (of_find_property(np, "samsung,supports-secdai", NULL))
quirks |= QUIRK_SEC_DAI;
if (of_find_property(np, "samsung,supports-rstclr", NULL))
quirks |= QUIRK_NEED_RSTCLR;
if (of_property_read_u32(np, "samsung,idma-addr",
&idma_addr)) {
if (quirks & QUIRK_SEC_DAI) {
dev_err(&pdev->dev, "idma address is not"\
"specified");
return -EINVAL;
}
}
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Unable to get I2S SFR address\n");
return -ENXIO;
}
if (!request_mem_region(res->start, resource_size(res),
"samsung-i2s")) {
dev_err(&pdev->dev, "Unable to request SFR region\n");
return -EBUSY;
}
regs_base = res->start;
pri_dai->dma_playback.dma_addr = regs_base + I2STXD;
pri_dai->dma_capture.dma_addr = regs_base + I2SRXD;
pri_dai->dma_playback.client =
(struct s3c2410_dma_client *)&pri_dai->dma_playback;
pri_dai->dma_playback.ch_name = "tx";
pri_dai->dma_capture.client =
(struct s3c2410_dma_client *)&pri_dai->dma_capture;
pri_dai->dma_capture.ch_name = "rx";
pri_dai->dma_playback.dma_size = 4;
pri_dai->dma_capture.dma_size = 4;
pri_dai->base = regs_base;
pri_dai->quirks = quirks;
if (quirks & QUIRK_PRI_6CHAN)
pri_dai->i2s_dai_drv.playback.channels_max = 6;
if (quirks & QUIRK_SEC_DAI) {
sec_dai = i2s_alloc_dai(pdev, true);
if (!sec_dai) {
dev_err(&pdev->dev, "Unable to alloc I2S_sec\n");
ret = -ENOMEM;
goto err;
}
sec_dai->dma_playback.dma_addr = regs_base + I2STXDS;
sec_dai->dma_playback.client =
(struct s3c2410_dma_client *)&sec_dai->dma_playback;
sec_dai->dma_playback.ch_name = "tx-sec";
if (!np) {
res = platform_get_resource(pdev, IORESOURCE_DMA, 2);
if (res)
sec_dai->dma_playback.channel = res->start;
}
sec_dai->dma_playback.dma_size = 4;
sec_dai->base = regs_base;
sec_dai->quirks = quirks;
sec_dai->idma_playback.dma_addr = idma_addr;
sec_dai->pri_dai = pri_dai;
pri_dai->sec_dai = sec_dai;
}
if (np) {
if (samsung_i2s_parse_dt_gpio(pri_dai)) {
dev_err(&pdev->dev, "Unable to configure gpio\n");
ret = -EINVAL;
goto err;
}
} else {
if (i2s_pdata->cfg_gpio && i2s_pdata->cfg_gpio(pdev)) {
dev_err(&pdev->dev, "Unable to configure gpio\n");
ret = -EINVAL;
goto err;
}
}
snd_soc_register_dai(&pri_dai->pdev->dev, &pri_dai->i2s_dai_drv);
pm_runtime_enable(&pdev->dev);
asoc_dma_platform_register(&pdev->dev);
return 0;
err:
release_mem_region(regs_base, resource_size(res));
return ret;
}
static int samsung_i2s_remove(struct platform_device *pdev)
{
struct i2s_dai *i2s, *other;
struct resource *res;
struct s3c_audio_pdata *i2s_pdata = pdev->dev.platform_data;
i2s = dev_get_drvdata(&pdev->dev);
other = i2s->pri_dai ? : i2s->sec_dai;
if (!i2s_pdata->cfg_gpio && pdev->dev.of_node)
samsung_i2s_dt_gpio_free(i2s->pri_dai);
if (other) {
other->pri_dai = NULL;
other->sec_dai = NULL;
} else {
pm_runtime_disable(&pdev->dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res)
release_mem_region(res->start, resource_size(res));
}
i2s->pri_dai = NULL;
i2s->sec_dai = NULL;
asoc_dma_platform_unregister(&pdev->dev);
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
