static void __fsi_reg_write(u32 reg, u32 data)
{
data &= 0x00ffffff;
__raw_writel(data, reg);
}
static u32 __fsi_reg_read(u32 reg)
{
return __raw_readl(reg);
}
static void __fsi_reg_mask_set(u32 reg, u32 mask, u32 data)
{
u32 val = __fsi_reg_read(reg);
val &= ~mask;
val |= data & mask;
__fsi_reg_write(reg, val);
}
static u32 _fsi_master_read(struct fsi_master *master, u32 reg)
{
u32 ret;
unsigned long flags;
spin_lock_irqsave(&master->lock, flags);
ret = __fsi_reg_read((u32)(master->base + reg));
spin_unlock_irqrestore(&master->lock, flags);
return ret;
}
static void _fsi_master_mask_set(struct fsi_master *master,
u32 reg, u32 mask, u32 data)
{
unsigned long flags;
spin_lock_irqsave(&master->lock, flags);
__fsi_reg_mask_set((u32)(master->base + reg), mask, data);
spin_unlock_irqrestore(&master->lock, flags);
}
static struct fsi_master *fsi_get_master(struct fsi_priv *fsi)
{
return fsi->master;
}
static int fsi_is_clk_master(struct fsi_priv *fsi)
{
return fsi->clk_master;
}
static int fsi_is_port_a(struct fsi_priv *fsi)
{
return fsi->master->base == fsi->base;
}
static struct snd_soc_dai *fsi_get_dai(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
return rtd->cpu_dai;
}
static struct fsi_priv *fsi_get_priv_frm_dai(struct snd_soc_dai *dai)
{
struct fsi_master *master = snd_soc_dai_get_drvdata(dai);
if (dai->id == 0)
return &master->fsia;
else
return &master->fsib;
}
static struct fsi_priv *fsi_get_priv(struct snd_pcm_substream *substream)
{
return fsi_get_priv_frm_dai(fsi_get_dai(substream));
}
static set_rate_func fsi_get_info_set_rate(struct fsi_master *master)
{
if (!master->info)
return NULL;
return master->info->set_rate;
}
static u32 fsi_get_info_flags(struct fsi_priv *fsi)
{
int is_porta = fsi_is_port_a(fsi);
struct fsi_master *master = fsi_get_master(fsi);
if (!master->info)
return 0;
return is_porta ? master->info->porta_flags :
master->info->portb_flags;
}
static inline int fsi_stream_is_play(int stream)
{
return stream == SNDRV_PCM_STREAM_PLAYBACK;
}
static inline int fsi_is_play(struct snd_pcm_substream *substream)
{
return fsi_stream_is_play(substream->stream);
}
static inline struct fsi_stream *fsi_get_stream(struct fsi_priv *fsi,
int is_play)
{
return is_play ? &fsi->playback : &fsi->capture;
}
static u32 fsi_get_port_shift(struct fsi_priv *fsi, int is_play)
{
int is_porta = fsi_is_port_a(fsi);
u32 shift;
if (is_porta)
shift = is_play ? AO_SHIFT : AI_SHIFT;
else
shift = is_play ? BO_SHIFT : BI_SHIFT;
return shift;
}
static void fsi_stream_push(struct fsi_priv *fsi,
int is_play,
struct snd_pcm_substream *substream,
u32 buffer_len,
u32 period_len)
{
struct fsi_stream *io = fsi_get_stream(fsi, is_play);
io->substream = substream;
io->buff_len = buffer_len;
io->buff_offset = 0;
io->period_len = period_len;
io->period_num = 0;
io->oerr_num = -1;
io->uerr_num = -1;
}
static void fsi_stream_pop(struct fsi_priv *fsi, int is_play)
{
struct fsi_stream *io = fsi_get_stream(fsi, is_play);
struct snd_soc_dai *dai = fsi_get_dai(io->substream);
if (io->oerr_num > 0)
dev_err(dai->dev, "over_run = %d\n", io->oerr_num);
if (io->uerr_num > 0)
dev_err(dai->dev, "under_run = %d\n", io->uerr_num);
io->substream = NULL;
io->buff_len = 0;
io->buff_offset = 0;
io->period_len = 0;
io->period_num = 0;
io->oerr_num = 0;
io->uerr_num = 0;
}
static int fsi_get_fifo_data_num(struct fsi_priv *fsi, int is_play)
{
u32 status;
int data_num;
status = is_play ?
fsi_reg_read(fsi, DOFF_ST) :
fsi_reg_read(fsi, DIFF_ST);
data_num = 0x1ff & (status >> 8);
data_num *= fsi->chan_num;
return data_num;
}
static int fsi_len2num(int len, int width)
{
return len / width;
}
static int fsi_num2len(int num, int width)
{
return num * width;
}
static int fsi_get_frame_width(struct fsi_priv *fsi, int is_play)
{
struct fsi_stream *io = fsi_get_stream(fsi, is_play);
struct snd_pcm_substream *substream = io->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
return frames_to_bytes(runtime, 1) / fsi->chan_num;
}
static void fsi_count_fifo_err(struct fsi_priv *fsi)
{
u32 ostatus = fsi_reg_read(fsi, DOFF_ST);
u32 istatus = fsi_reg_read(fsi, DIFF_ST);
if (ostatus & ERR_OVER)
fsi->playback.oerr_num++;
if (ostatus & ERR_UNDER)
fsi->playback.uerr_num++;
if (istatus & ERR_OVER)
fsi->capture.oerr_num++;
if (istatus & ERR_UNDER)
fsi->capture.uerr_num++;
fsi_reg_write(fsi, DOFF_ST, 0);
fsi_reg_write(fsi, DIFF_ST, 0);
}
static u8 *fsi_dma_get_area(struct fsi_priv *fsi, int stream)
{
int is_play = fsi_stream_is_play(stream);
struct fsi_stream *io = fsi_get_stream(fsi, is_play);
return io->substream->runtime->dma_area + io->buff_offset;
}
static void fsi_dma_soft_push16(struct fsi_priv *fsi, int num)
{
u16 *start;
int i;
start = (u16 *)fsi_dma_get_area(fsi, SNDRV_PCM_STREAM_PLAYBACK);
for (i = 0; i < num; i++)
fsi_reg_write(fsi, DODT, ((u32)*(start + i) << 8));
}
static void fsi_dma_soft_pop16(struct fsi_priv *fsi, int num)
{
u16 *start;
int i;
start = (u16 *)fsi_dma_get_area(fsi, SNDRV_PCM_STREAM_CAPTURE);
for (i = 0; i < num; i++)
*(start + i) = (u16)(fsi_reg_read(fsi, DIDT) >> 8);
}
static void fsi_dma_soft_push32(struct fsi_priv *fsi, int num)
{
u32 *start;
int i;
start = (u32 *)fsi_dma_get_area(fsi, SNDRV_PCM_STREAM_PLAYBACK);
for (i = 0; i < num; i++)
fsi_reg_write(fsi, DODT, *(start + i));
}
static void fsi_dma_soft_pop32(struct fsi_priv *fsi, int num)
{
u32 *start;
int i;
start = (u32 *)fsi_dma_get_area(fsi, SNDRV_PCM_STREAM_CAPTURE);
for (i = 0; i < num; i++)
*(start + i) = fsi_reg_read(fsi, DIDT);
}
static void fsi_irq_enable(struct fsi_priv *fsi, int is_play)
{
u32 data = AB_IO(1, fsi_get_port_shift(fsi, is_play));
struct fsi_master *master = fsi_get_master(fsi);
fsi_core_mask_set(master, imsk, data, data);
fsi_core_mask_set(master, iemsk, data, data);
}
static void fsi_irq_disable(struct fsi_priv *fsi, int is_play)
{
u32 data = AB_IO(1, fsi_get_port_shift(fsi, is_play));
struct fsi_master *master = fsi_get_master(fsi);
fsi_core_mask_set(master, imsk, data, 0);
fsi_core_mask_set(master, iemsk, data, 0);
}
static u32 fsi_irq_get_status(struct fsi_master *master)
{
return fsi_core_read(master, int_st);
}
static void fsi_irq_clear_status(struct fsi_priv *fsi)
{
u32 data = 0;
struct fsi_master *master = fsi_get_master(fsi);
data |= AB_IO(1, fsi_get_port_shift(fsi, 0));
data |= AB_IO(1, fsi_get_port_shift(fsi, 1));
fsi_core_mask_set(master, int_st, data, 0);
}
static void fsi_spdif_clk_ctrl(struct fsi_priv *fsi, int enable)
{
struct fsi_master *master = fsi_get_master(fsi);
u32 mask, val;
if (master->core->ver < 2) {
pr_err("fsi: register access err (%s)\n", __func__);
return;
}
mask = BP | SE;
val = enable ? mask : 0;
fsi_is_port_a(fsi) ?
fsi_core_mask_set(master, a_mclk, mask, val) :
fsi_core_mask_set(master, b_mclk, mask, val);
}
static void __fsi_module_clk_ctrl(struct fsi_master *master,
struct device *dev,
int enable)
{
pm_runtime_get_sync(dev);
if (enable) {
fsi_master_mask_set(master, SOFT_RST, FSISR, FSISR);
fsi_master_mask_set(master, SOFT_RST, PASR | PBSR, 0);
} else {
fsi_master_mask_set(master, SOFT_RST, FSISR, 0);
}
pm_runtime_put_sync(dev);
}
static void __fsi_port_clk_ctrl(struct fsi_priv *fsi, int enable)
{
struct fsi_master *master = fsi_get_master(fsi);
u32 soft = fsi_is_port_a(fsi) ? PASR : PBSR;
u32 clk = fsi_is_port_a(fsi) ? CRA : CRB;
int is_master = fsi_is_clk_master(fsi);
fsi_master_mask_set(master, SOFT_RST, soft, (enable) ? soft : 0);
if (is_master)
fsi_master_mask_set(master, CLK_RST, clk, (enable) ? clk : 0);
}
static void fsi_fifo_init(struct fsi_priv *fsi,
int is_play,
struct snd_soc_dai *dai)
{
struct fsi_master *master = fsi_get_master(fsi);
struct fsi_stream *io = fsi_get_stream(fsi, is_play);
u32 shift, i;
shift = fsi_master_read(master, FIFO_SZ);
shift >>= fsi_get_port_shift(fsi, is_play);
shift &= FIFO_SZ_MASK;
io->fifo_max_num = 256 << shift;
dev_dbg(dai->dev, "fifo = %d words\n", io->fifo_max_num);
for (i = 1; i < fsi->chan_num; i <<= 1)
io->fifo_max_num >>= 1;
dev_dbg(dai->dev, "%d channel %d store\n",
fsi->chan_num, io->fifo_max_num);
if (is_play) {
fsi_reg_write(fsi, DOFF_CTL, IRQ_HALF);
fsi_reg_mask_set(fsi, DOFF_CTL, FIFO_CLR, FIFO_CLR);
} else {
fsi_reg_write(fsi, DIFF_CTL, IRQ_HALF);
fsi_reg_mask_set(fsi, DIFF_CTL, FIFO_CLR, FIFO_CLR);
}
}
static int fsi_fifo_data_ctrl(struct fsi_priv *fsi, int stream)
{
struct snd_pcm_runtime *runtime;
struct snd_pcm_substream *substream = NULL;
int is_play = fsi_stream_is_play(stream);
struct fsi_stream *io = fsi_get_stream(fsi, is_play);
int data_residue_num;
int data_num;
int data_num_max;
int ch_width;
int over_period;
void (*fn)(struct fsi_priv *fsi, int size);
if (!fsi ||
!io->substream ||
!io->substream->runtime)
return -EINVAL;
over_period = 0;
substream = io->substream;
runtime = substream->runtime;
if (io->buff_offset >=
fsi_num2offset(io->period_num + 1, io->period_len)) {
over_period = 1;
io->period_num = (io->period_num + 1) % runtime->periods;
if (0 == io->period_num)
io->buff_offset = 0;
}
ch_width = fsi_get_frame_width(fsi, is_play);
data_residue_num = fsi_len2num(io->buff_len - io->buff_offset,
ch_width);
if (is_play) {
data_num_max = io->fifo_max_num * fsi->chan_num;
data_num_max -= fsi_get_fifo_data_num(fsi, is_play);
data_num = data_residue_num;
switch (ch_width) {
case 2:
fn = fsi_dma_soft_push16;
break;
case 4:
fn = fsi_dma_soft_push32;
break;
default:
return -EINVAL;
}
} else {
data_num_max = data_residue_num;
data_num = fsi_get_fifo_data_num(fsi, is_play);
switch (ch_width) {
case 2:
fn = fsi_dma_soft_pop16;
break;
case 4:
fn = fsi_dma_soft_pop32;
break;
default:
return -EINVAL;
}
}
data_num = min(data_num, data_num_max);
fn(fsi, data_num);
io->buff_offset += fsi_num2offset(data_num, ch_width);
if (over_period)
snd_pcm_period_elapsed(substream);
return 0;
}
static int fsi_data_pop(struct fsi_priv *fsi)
{
return fsi_fifo_data_ctrl(fsi, SNDRV_PCM_STREAM_CAPTURE);
}
static int fsi_data_push(struct fsi_priv *fsi)
{
return fsi_fifo_data_ctrl(fsi, SNDRV_PCM_STREAM_PLAYBACK);
}
static irqreturn_t fsi_interrupt(int irq, void *data)
{
struct fsi_master *master = data;
u32 int_st = fsi_irq_get_status(master);
fsi_master_mask_set(master, SOFT_RST, IR, 0);
fsi_master_mask_set(master, SOFT_RST, IR, IR);
if (int_st & AB_IO(1, AO_SHIFT))
fsi_data_push(&master->fsia);
if (int_st & AB_IO(1, BO_SHIFT))
fsi_data_push(&master->fsib);
if (int_st & AB_IO(1, AI_SHIFT))
fsi_data_pop(&master->fsia);
if (int_st & AB_IO(1, BI_SHIFT))
fsi_data_pop(&master->fsib);
fsi_count_fifo_err(&master->fsia);
fsi_count_fifo_err(&master->fsib);
fsi_irq_clear_status(&master->fsia);
fsi_irq_clear_status(&master->fsib);
return IRQ_HANDLED;
}
static int fsi_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
u32 flags = fsi_get_info_flags(fsi);
u32 data;
int is_play = fsi_is_play(substream);
pm_runtime_get_sync(dai->dev);
data = 0;
if (SH_FSI_LRM_INV & flags)
data |= 1 << 12;
if (SH_FSI_BRM_INV & flags)
data |= 1 << 8;
if (SH_FSI_LRS_INV & flags)
data |= 1 << 4;
if (SH_FSI_BRS_INV & flags)
data |= 1 << 0;
fsi_reg_write(fsi, CKG2, data);
fsi_irq_disable(fsi, is_play);
fsi_irq_clear_status(fsi);
fsi_fifo_init(fsi, is_play, dai);
return 0;
}
static void fsi_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
int is_play = fsi_is_play(substream);
struct fsi_master *master = fsi_get_master(fsi);
set_rate_func set_rate = fsi_get_info_set_rate(master);
fsi_irq_disable(fsi, is_play);
if (fsi_is_clk_master(fsi))
set_rate(dai->dev, fsi_is_port_a(fsi), fsi->rate, 0);
fsi->rate = 0;
pm_runtime_put_sync(dai->dev);
}
static int fsi_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int is_play = fsi_is_play(substream);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
fsi_stream_push(fsi, is_play, substream,
frames_to_bytes(runtime, runtime->buffer_size),
frames_to_bytes(runtime, runtime->period_size));
ret = is_play ? fsi_data_push(fsi) : fsi_data_pop(fsi);
fsi_irq_enable(fsi, is_play);
fsi_port_start(fsi);
break;
case SNDRV_PCM_TRIGGER_STOP:
fsi_port_stop(fsi);
fsi_irq_disable(fsi, is_play);
fsi_stream_pop(fsi, is_play);
break;
}
return ret;
}
static int fsi_set_fmt_dai(struct fsi_priv *fsi, unsigned int fmt)
{
u32 data = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
data = CR_I2S;
fsi->chan_num = 2;
break;
case SND_SOC_DAIFMT_LEFT_J:
data = CR_PCM;
fsi->chan_num = 2;
break;
default:
return -EINVAL;
}
fsi_reg_write(fsi, DO_FMT, data);
fsi_reg_write(fsi, DI_FMT, data);
return 0;
}
static int fsi_set_fmt_spdif(struct fsi_priv *fsi)
{
struct fsi_master *master = fsi_get_master(fsi);
u32 data = 0;
if (master->core->ver < 2)
return -EINVAL;
data = CR_BWS_16 | CR_DTMD_SPDIF_PCM | CR_PCM;
fsi->chan_num = 2;
fsi_spdif_clk_ctrl(fsi, 1);
fsi_reg_mask_set(fsi, OUT_SEL, DMMD, DMMD);
fsi_reg_write(fsi, DO_FMT, data);
fsi_reg_write(fsi, DI_FMT, data);
return 0;
}
static int fsi_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct fsi_priv *fsi = fsi_get_priv_frm_dai(dai);
struct fsi_master *master = fsi_get_master(fsi);
set_rate_func set_rate = fsi_get_info_set_rate(master);
u32 flags = fsi_get_info_flags(fsi);
u32 data = 0;
int ret;
pm_runtime_get_sync(dai->dev);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
data = DIMD | DOMD;
fsi->clk_master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
ret = -EINVAL;
goto set_fmt_exit;
}
if (fsi_is_clk_master(fsi) && !set_rate) {
dev_err(dai->dev, "platform doesn't have set_rate\n");
ret = -EINVAL;
goto set_fmt_exit;
}
fsi_reg_mask_set(fsi, CKG1, (DIMD | DOMD), data);
switch (flags & SH_FSI_FMT_MASK) {
case SH_FSI_FMT_DAI:
ret = fsi_set_fmt_dai(fsi, fmt & SND_SOC_DAIFMT_FORMAT_MASK);
break;
case SH_FSI_FMT_SPDIF:
ret = fsi_set_fmt_spdif(fsi);
break;
default:
ret = -EINVAL;
}
set_fmt_exit:
pm_runtime_put_sync(dai->dev);
return ret;
}
static int fsi_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
struct fsi_master *master = fsi_get_master(fsi);
set_rate_func set_rate = fsi_get_info_set_rate(master);
int fsi_ver = master->core->ver;
long rate = params_rate(params);
int ret;
if (!fsi_is_clk_master(fsi))
return 0;
ret = set_rate(dai->dev, fsi_is_port_a(fsi), rate, 1);
if (ret < 0)
return ret;
fsi->rate = rate;
if (ret > 0) {
u32 data = 0;
switch (ret & SH_FSI_ACKMD_MASK) {
default:
case SH_FSI_ACKMD_512:
data |= (0x0 << 12);
break;
case SH_FSI_ACKMD_256:
data |= (0x1 << 12);
break;
case SH_FSI_ACKMD_128:
data |= (0x2 << 12);
break;
case SH_FSI_ACKMD_64:
data |= (0x3 << 12);
break;
case SH_FSI_ACKMD_32:
if (fsi_ver < 2)
dev_err(dai->dev, "unsupported ACKMD\n");
else
data |= (0x4 << 12);
break;
}
switch (ret & SH_FSI_BPFMD_MASK) {
default:
case SH_FSI_BPFMD_32:
data |= (0x0 << 8);
break;
case SH_FSI_BPFMD_64:
data |= (0x1 << 8);
break;
case SH_FSI_BPFMD_128:
data |= (0x2 << 8);
break;
case SH_FSI_BPFMD_256:
data |= (0x3 << 8);
break;
case SH_FSI_BPFMD_512:
data |= (0x4 << 8);
break;
case SH_FSI_BPFMD_16:
if (fsi_ver < 2)
dev_err(dai->dev, "unsupported ACKMD\n");
else
data |= (0x7 << 8);
break;
}
fsi_reg_mask_set(fsi, CKG1, (ACKMD_MASK | BPFMD_MASK) , data);
udelay(10);
ret = 0;
}
return ret;
}
static int fsi_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
int ret = 0;
snd_soc_set_runtime_hwparams(substream, &fsi_pcm_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
return ret;
}
static int fsi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int fsi_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static snd_pcm_uframes_t fsi_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct fsi_priv *fsi = fsi_get_priv(substream);
struct fsi_stream *io = fsi_get_stream(fsi, fsi_is_play(substream));
long location;
location = (io->buff_offset - 1);
if (location < 0)
location = 0;
return bytes_to_frames(runtime, location);
}
static void fsi_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int fsi_pcm_new(struct snd_card *card,
struct snd_soc_dai *dai,
struct snd_pcm *pcm)
{
return snd_pcm_lib_preallocate_pages_for_all(
pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
PREALLOC_BUFFER, PREALLOC_BUFFER_MAX);
}
static int fsi_probe(struct platform_device *pdev)
{
struct fsi_master *master;
const struct platform_device_id *id_entry;
struct resource *res;
unsigned int irq;
int ret;
id_entry = pdev->id_entry;
if (!id_entry) {
dev_err(&pdev->dev, "unknown fsi device\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || (int)irq <= 0) {
dev_err(&pdev->dev, "Not enough FSI platform resources.\n");
ret = -ENODEV;
goto exit;
}
master = kzalloc(sizeof(*master), GFP_KERNEL);
if (!master) {
dev_err(&pdev->dev, "Could not allocate master\n");
ret = -ENOMEM;
goto exit;
}
master->base = ioremap_nocache(res->start, resource_size(res));
if (!master->base) {
ret = -ENXIO;
dev_err(&pdev->dev, "Unable to ioremap FSI registers.\n");
goto exit_kfree;
}
master->irq = irq;
master->info = pdev->dev.platform_data;
master->core = (struct fsi_core *)id_entry->driver_data;
spin_lock_init(&master->lock);
master->fsia.base = master->base;
master->fsia.master = master;
master->fsib.base = master->base + 0x40;
master->fsib.master = master;
pm_runtime_enable(&pdev->dev);
dev_set_drvdata(&pdev->dev, master);
fsi_module_init(master, &pdev->dev);
ret = request_irq(irq, &fsi_interrupt, IRQF_DISABLED,
id_entry->name, master);
if (ret) {
dev_err(&pdev->dev, "irq request err\n");
goto exit_iounmap;
}
ret = snd_soc_register_platform(&pdev->dev, &fsi_soc_platform);
if (ret < 0) {
dev_err(&pdev->dev, "cannot snd soc register\n");
goto exit_free_irq;
}
ret = snd_soc_register_dais(&pdev->dev, fsi_soc_dai,
ARRAY_SIZE(fsi_soc_dai));
if (ret < 0) {
dev_err(&pdev->dev, "cannot snd dai register\n");
goto exit_snd_soc;
}
return ret;
exit_snd_soc:
snd_soc_unregister_platform(&pdev->dev);
exit_free_irq:
free_irq(irq, master);
exit_iounmap:
iounmap(master->base);
pm_runtime_disable(&pdev->dev);
exit_kfree:
kfree(master);
master = NULL;
exit:
return ret;
}
static int fsi_remove(struct platform_device *pdev)
{
struct fsi_master *master;
master = dev_get_drvdata(&pdev->dev);
fsi_module_kill(master, &pdev->dev);
free_irq(master->irq, master);
pm_runtime_disable(&pdev->dev);
snd_soc_unregister_dais(&pdev->dev, ARRAY_SIZE(fsi_soc_dai));
snd_soc_unregister_platform(&pdev->dev);
iounmap(master->base);
kfree(master);
return 0;
}
static void __fsi_suspend(struct fsi_priv *fsi,
struct device *dev,
set_rate_func set_rate)
{
fsi->saved_do_fmt = fsi_reg_read(fsi, DO_FMT);
fsi->saved_di_fmt = fsi_reg_read(fsi, DI_FMT);
fsi->saved_ckg1 = fsi_reg_read(fsi, CKG1);
fsi->saved_ckg2 = fsi_reg_read(fsi, CKG2);
fsi->saved_out_sel = fsi_reg_read(fsi, OUT_SEL);
if (fsi_is_clk_master(fsi))
set_rate(dev, fsi_is_port_a(fsi), fsi->rate, 0);
}
static void __fsi_resume(struct fsi_priv *fsi,
struct device *dev,
set_rate_func set_rate)
{
fsi_reg_write(fsi, DO_FMT, fsi->saved_do_fmt);
fsi_reg_write(fsi, DI_FMT, fsi->saved_di_fmt);
fsi_reg_write(fsi, CKG1, fsi->saved_ckg1);
fsi_reg_write(fsi, CKG2, fsi->saved_ckg2);
fsi_reg_write(fsi, OUT_SEL, fsi->saved_out_sel);
if (fsi_is_clk_master(fsi))
set_rate(dev, fsi_is_port_a(fsi), fsi->rate, 1);
}
static int fsi_suspend(struct device *dev)
{
struct fsi_master *master = dev_get_drvdata(dev);
set_rate_func set_rate = fsi_get_info_set_rate(master);
pm_runtime_get_sync(dev);
__fsi_suspend(&master->fsia, dev, set_rate);
__fsi_suspend(&master->fsib, dev, set_rate);
master->saved_a_mclk = fsi_core_read(master, a_mclk);
master->saved_b_mclk = fsi_core_read(master, b_mclk);
master->saved_iemsk = fsi_core_read(master, iemsk);
master->saved_imsk = fsi_core_read(master, imsk);
master->saved_clk_rst = fsi_master_read(master, CLK_RST);
master->saved_soft_rst = fsi_master_read(master, SOFT_RST);
fsi_module_kill(master, dev);
pm_runtime_put_sync(dev);
return 0;
}
static int fsi_resume(struct device *dev)
{
struct fsi_master *master = dev_get_drvdata(dev);
set_rate_func set_rate = fsi_get_info_set_rate(master);
pm_runtime_get_sync(dev);
fsi_module_init(master, dev);
fsi_master_mask_set(master, SOFT_RST, 0xffff, master->saved_soft_rst);
fsi_master_mask_set(master, CLK_RST, 0xffff, master->saved_clk_rst);
fsi_core_mask_set(master, a_mclk, 0xffff, master->saved_a_mclk);
fsi_core_mask_set(master, b_mclk, 0xffff, master->saved_b_mclk);
fsi_core_mask_set(master, iemsk, 0xffff, master->saved_iemsk);
fsi_core_mask_set(master, imsk, 0xffff, master->saved_imsk);
__fsi_resume(&master->fsia, dev, set_rate);
__fsi_resume(&master->fsib, dev, set_rate);
pm_runtime_put_sync(dev);
return 0;
}
static int fsi_runtime_nop(struct device *dev)
{
return 0;
}
static int __init fsi_mobile_init(void)
{
return platform_driver_register(&fsi_driver);
}
static void __exit fsi_mobile_exit(void)
{
platform_driver_unregister(&fsi_driver);
}
