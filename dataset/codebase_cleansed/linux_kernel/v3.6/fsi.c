static void __fsi_reg_write(u32 __iomem *reg, u32 data)
{
data &= 0x00ffffff;
__raw_writel(data, reg);
}
static u32 __fsi_reg_read(u32 __iomem *reg)
{
return __raw_readl(reg);
}
static void __fsi_reg_mask_set(u32 __iomem *reg, u32 mask, u32 data)
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
ret = __fsi_reg_read(master->base + reg);
spin_unlock_irqrestore(&master->lock, flags);
return ret;
}
static void _fsi_master_mask_set(struct fsi_master *master,
u32 reg, u32 mask, u32 data)
{
unsigned long flags;
spin_lock_irqsave(&master->lock, flags);
__fsi_reg_mask_set(master->base + reg, mask, data);
spin_unlock_irqrestore(&master->lock, flags);
}
static int fsi_version(struct fsi_master *master)
{
return master->core->ver;
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
static int fsi_is_spdif(struct fsi_priv *fsi)
{
return fsi->spdif;
}
static int fsi_is_play(struct snd_pcm_substream *substream)
{
return substream->stream == SNDRV_PCM_STREAM_PLAYBACK;
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
static set_rate_func fsi_get_info_set_rate(struct fsi_priv *fsi)
{
if (!fsi->info)
return NULL;
return fsi->info->set_rate;
}
static u32 fsi_get_info_flags(struct fsi_priv *fsi)
{
if (!fsi->info)
return 0;
return fsi->info->flags;
}
static u32 fsi_get_port_shift(struct fsi_priv *fsi, struct fsi_stream *io)
{
int is_play = fsi_stream_is_play(fsi, io);
int is_porta = fsi_is_port_a(fsi);
u32 shift;
if (is_porta)
shift = is_play ? AO_SHIFT : AI_SHIFT;
else
shift = is_play ? BO_SHIFT : BI_SHIFT;
return shift;
}
static int fsi_frame2sample(struct fsi_priv *fsi, int frames)
{
return frames * fsi->chan_num;
}
static int fsi_sample2frame(struct fsi_priv *fsi, int samples)
{
return samples / fsi->chan_num;
}
static int fsi_get_current_fifo_samples(struct fsi_priv *fsi,
struct fsi_stream *io)
{
int is_play = fsi_stream_is_play(fsi, io);
u32 status;
int frames;
status = is_play ?
fsi_reg_read(fsi, DOFF_ST) :
fsi_reg_read(fsi, DIFF_ST);
frames = 0x1ff & (status >> 8);
return fsi_frame2sample(fsi, frames);
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
static inline int fsi_stream_is_play(struct fsi_priv *fsi,
struct fsi_stream *io)
{
return &fsi->playback == io;
}
static inline struct fsi_stream *fsi_stream_get(struct fsi_priv *fsi,
struct snd_pcm_substream *substream)
{
return fsi_is_play(substream) ? &fsi->playback : &fsi->capture;
}
static int fsi_stream_is_working(struct fsi_priv *fsi,
struct fsi_stream *io)
{
struct fsi_master *master = fsi_get_master(fsi);
unsigned long flags;
int ret;
spin_lock_irqsave(&master->lock, flags);
ret = !!(io->substream && io->substream->runtime);
spin_unlock_irqrestore(&master->lock, flags);
return ret;
}
static struct fsi_priv *fsi_stream_to_priv(struct fsi_stream *io)
{
return io->priv;
}
static void fsi_stream_init(struct fsi_priv *fsi,
struct fsi_stream *io,
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct fsi_master *master = fsi_get_master(fsi);
unsigned long flags;
spin_lock_irqsave(&master->lock, flags);
io->substream = substream;
io->buff_sample_capa = fsi_frame2sample(fsi, runtime->buffer_size);
io->buff_sample_pos = 0;
io->period_samples = fsi_frame2sample(fsi, runtime->period_size);
io->period_pos = 0;
io->sample_width = samples_to_bytes(runtime, 1);
io->bus_option = 0;
io->oerr_num = -1;
io->uerr_num = -1;
fsi_stream_handler_call(io, init, fsi, io);
spin_unlock_irqrestore(&master->lock, flags);
}
static void fsi_stream_quit(struct fsi_priv *fsi, struct fsi_stream *io)
{
struct snd_soc_dai *dai = fsi_get_dai(io->substream);
struct fsi_master *master = fsi_get_master(fsi);
unsigned long flags;
spin_lock_irqsave(&master->lock, flags);
if (io->oerr_num > 0)
dev_err(dai->dev, "over_run = %d\n", io->oerr_num);
if (io->uerr_num > 0)
dev_err(dai->dev, "under_run = %d\n", io->uerr_num);
fsi_stream_handler_call(io, quit, fsi, io);
io->substream = NULL;
io->buff_sample_capa = 0;
io->buff_sample_pos = 0;
io->period_samples = 0;
io->period_pos = 0;
io->sample_width = 0;
io->bus_option = 0;
io->oerr_num = 0;
io->uerr_num = 0;
spin_unlock_irqrestore(&master->lock, flags);
}
static int fsi_stream_transfer(struct fsi_stream *io)
{
struct fsi_priv *fsi = fsi_stream_to_priv(io);
if (!fsi)
return -EIO;
return fsi_stream_handler_call(io, transfer, fsi, io);
}
static int fsi_stream_probe(struct fsi_priv *fsi, struct device *dev)
{
struct fsi_stream *io;
int ret1, ret2;
io = &fsi->playback;
ret1 = fsi_stream_handler_call(io, probe, fsi, io, dev);
io = &fsi->capture;
ret2 = fsi_stream_handler_call(io, probe, fsi, io, dev);
if (ret1 < 0)
return ret1;
if (ret2 < 0)
return ret2;
return 0;
}
static int fsi_stream_remove(struct fsi_priv *fsi)
{
struct fsi_stream *io;
int ret1, ret2;
io = &fsi->playback;
ret1 = fsi_stream_handler_call(io, remove, fsi, io);
io = &fsi->capture;
ret2 = fsi_stream_handler_call(io, remove, fsi, io);
if (ret1 < 0)
return ret1;
if (ret2 < 0)
return ret2;
return 0;
}
static void fsi_format_bus_setup(struct fsi_priv *fsi, struct fsi_stream *io,
u32 bus, struct device *dev)
{
struct fsi_master *master = fsi_get_master(fsi);
int is_play = fsi_stream_is_play(fsi, io);
u32 fmt = fsi->fmt;
if (fsi_version(master) >= 2) {
u32 dma = 0;
switch (bus) {
case PACKAGE_24BITBUS_FRONT:
fmt |= CR_BWS_24;
dma |= VDMD_FRONT;
dev_dbg(dev, "24bit bus / package in front\n");
break;
case PACKAGE_16BITBUS_STREAM:
fmt |= CR_BWS_16;
dma |= VDMD_STREAM;
dev_dbg(dev, "16bit bus / stream mode\n");
break;
case PACKAGE_24BITBUS_BACK:
default:
fmt |= CR_BWS_24;
dma |= VDMD_BACK;
dev_dbg(dev, "24bit bus / package in back\n");
break;
}
if (is_play)
fsi_reg_write(fsi, OUT_DMAC, dma);
else
fsi_reg_write(fsi, IN_DMAC, dma);
}
if (is_play)
fsi_reg_write(fsi, DO_FMT, fmt);
else
fsi_reg_write(fsi, DI_FMT, fmt);
}
static void fsi_irq_enable(struct fsi_priv *fsi, struct fsi_stream *io)
{
u32 data = AB_IO(1, fsi_get_port_shift(fsi, io));
struct fsi_master *master = fsi_get_master(fsi);
fsi_core_mask_set(master, imsk, data, data);
fsi_core_mask_set(master, iemsk, data, data);
}
static void fsi_irq_disable(struct fsi_priv *fsi, struct fsi_stream *io)
{
u32 data = AB_IO(1, fsi_get_port_shift(fsi, io));
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
data |= AB_IO(1, fsi_get_port_shift(fsi, &fsi->playback));
data |= AB_IO(1, fsi_get_port_shift(fsi, &fsi->capture));
fsi_core_mask_set(master, int_st, data, 0);
}
static void fsi_spdif_clk_ctrl(struct fsi_priv *fsi, int enable)
{
struct fsi_master *master = fsi_get_master(fsi);
u32 mask, val;
mask = BP | SE;
val = enable ? mask : 0;
fsi_is_port_a(fsi) ?
fsi_core_mask_set(master, a_mclk, mask, val) :
fsi_core_mask_set(master, b_mclk, mask, val);
}
static int fsi_set_master_clk(struct device *dev, struct fsi_priv *fsi,
long rate, int enable)
{
set_rate_func set_rate = fsi_get_info_set_rate(fsi);
int ret;
if (!set_rate)
return 0;
ret = set_rate(dev, rate, enable);
if (ret < 0)
return ret;
if (!enable)
return 0;
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
data |= (0x7 << 8);
break;
}
fsi_reg_mask_set(fsi, CKG1, (ACKMD_MASK | BPFMD_MASK) , data);
udelay(10);
ret = 0;
}
return ret;
}
static void fsi_pio_push16(struct fsi_priv *fsi, u8 *_buf, int samples)
{
u32 enable_stream = fsi_get_info_flags(fsi) & SH_FSI_ENABLE_STREAM_MODE;
int i;
if (enable_stream) {
u32 *buf = (u32 *)_buf;
for (i = 0; i < samples / 2; i++)
fsi_reg_write(fsi, DODT, buf[i]);
} else {
u16 *buf = (u16 *)_buf;
for (i = 0; i < samples; i++)
fsi_reg_write(fsi, DODT, ((u32)*(buf + i) << 8));
}
}
static void fsi_pio_pop16(struct fsi_priv *fsi, u8 *_buf, int samples)
{
u16 *buf = (u16 *)_buf;
int i;
for (i = 0; i < samples; i++)
*(buf + i) = (u16)(fsi_reg_read(fsi, DIDT) >> 8);
}
static void fsi_pio_push32(struct fsi_priv *fsi, u8 *_buf, int samples)
{
u32 *buf = (u32 *)_buf;
int i;
for (i = 0; i < samples; i++)
fsi_reg_write(fsi, DODT, *(buf + i));
}
static void fsi_pio_pop32(struct fsi_priv *fsi, u8 *_buf, int samples)
{
u32 *buf = (u32 *)_buf;
int i;
for (i = 0; i < samples; i++)
*(buf + i) = fsi_reg_read(fsi, DIDT);
}
static u8 *fsi_pio_get_area(struct fsi_priv *fsi, struct fsi_stream *io)
{
struct snd_pcm_runtime *runtime = io->substream->runtime;
return runtime->dma_area +
samples_to_bytes(runtime, io->buff_sample_pos);
}
static int fsi_pio_transfer(struct fsi_priv *fsi, struct fsi_stream *io,
void (*run16)(struct fsi_priv *fsi, u8 *buf, int samples),
void (*run32)(struct fsi_priv *fsi, u8 *buf, int samples),
int samples)
{
struct snd_pcm_runtime *runtime;
struct snd_pcm_substream *substream;
u8 *buf;
int over_period;
if (!fsi_stream_is_working(fsi, io))
return -EINVAL;
over_period = 0;
substream = io->substream;
runtime = substream->runtime;
if (io->buff_sample_pos >=
io->period_samples * (io->period_pos + 1)) {
over_period = 1;
io->period_pos = (io->period_pos + 1) % runtime->periods;
if (0 == io->period_pos)
io->buff_sample_pos = 0;
}
buf = fsi_pio_get_area(fsi, io);
switch (io->sample_width) {
case 2:
run16(fsi, buf, samples);
break;
case 4:
run32(fsi, buf, samples);
break;
default:
return -EINVAL;
}
io->buff_sample_pos += samples;
if (over_period)
snd_pcm_period_elapsed(substream);
return 0;
}
static int fsi_pio_pop(struct fsi_priv *fsi, struct fsi_stream *io)
{
int sample_residues;
int sample_space;
int samples;
sample_residues = fsi_get_current_fifo_samples(fsi, io);
sample_space = io->buff_sample_capa - io->buff_sample_pos;
samples = min(sample_residues, sample_space);
return fsi_pio_transfer(fsi, io,
fsi_pio_pop16,
fsi_pio_pop32,
samples);
}
static int fsi_pio_push(struct fsi_priv *fsi, struct fsi_stream *io)
{
int sample_residues;
int sample_space;
int samples;
sample_residues = io->buff_sample_capa - io->buff_sample_pos;
sample_space = io->fifo_sample_capa -
fsi_get_current_fifo_samples(fsi, io);
samples = min(sample_residues, sample_space);
return fsi_pio_transfer(fsi, io,
fsi_pio_push16,
fsi_pio_push32,
samples);
}
static void fsi_pio_start_stop(struct fsi_priv *fsi, struct fsi_stream *io,
int enable)
{
struct fsi_master *master = fsi_get_master(fsi);
u32 clk = fsi_is_port_a(fsi) ? CRA : CRB;
if (enable)
fsi_irq_enable(fsi, io);
else
fsi_irq_disable(fsi, io);
if (fsi_is_clk_master(fsi))
fsi_master_mask_set(master, CLK_RST, clk, (enable) ? clk : 0);
}
static int fsi_pio_push_init(struct fsi_priv *fsi, struct fsi_stream *io)
{
u32 enable_stream = fsi_get_info_flags(fsi) & SH_FSI_ENABLE_STREAM_MODE;
if (enable_stream)
io->bus_option = BUSOP_SET(24, PACKAGE_24BITBUS_BACK) |
BUSOP_SET(16, PACKAGE_16BITBUS_STREAM);
else
io->bus_option = BUSOP_SET(24, PACKAGE_24BITBUS_BACK) |
BUSOP_SET(16, PACKAGE_24BITBUS_BACK);
return 0;
}
static int fsi_pio_pop_init(struct fsi_priv *fsi, struct fsi_stream *io)
{
io->bus_option = BUSOP_SET(24, PACKAGE_24BITBUS_BACK) |
BUSOP_SET(16, PACKAGE_24BITBUS_BACK);
return 0;
}
static irqreturn_t fsi_interrupt(int irq, void *data)
{
struct fsi_master *master = data;
u32 int_st = fsi_irq_get_status(master);
fsi_master_mask_set(master, SOFT_RST, IR, 0);
fsi_master_mask_set(master, SOFT_RST, IR, IR);
if (int_st & AB_IO(1, AO_SHIFT))
fsi_stream_transfer(&master->fsia.playback);
if (int_st & AB_IO(1, BO_SHIFT))
fsi_stream_transfer(&master->fsib.playback);
if (int_st & AB_IO(1, AI_SHIFT))
fsi_stream_transfer(&master->fsia.capture);
if (int_st & AB_IO(1, BI_SHIFT))
fsi_stream_transfer(&master->fsib.capture);
fsi_count_fifo_err(&master->fsia);
fsi_count_fifo_err(&master->fsib);
fsi_irq_clear_status(&master->fsia);
fsi_irq_clear_status(&master->fsib);
return IRQ_HANDLED;
}
static int fsi_dma_init(struct fsi_priv *fsi, struct fsi_stream *io)
{
struct snd_pcm_runtime *runtime = io->substream->runtime;
struct snd_soc_dai *dai = fsi_get_dai(io->substream);
enum dma_data_direction dir = fsi_stream_is_play(fsi, io) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE;
io->bus_option = BUSOP_SET(24, PACKAGE_24BITBUS_BACK) |
BUSOP_SET(16, PACKAGE_16BITBUS_STREAM);
io->dma = dma_map_single(dai->dev, runtime->dma_area,
snd_pcm_lib_buffer_bytes(io->substream), dir);
return 0;
}
static int fsi_dma_quit(struct fsi_priv *fsi, struct fsi_stream *io)
{
struct snd_soc_dai *dai = fsi_get_dai(io->substream);
enum dma_data_direction dir = fsi_stream_is_play(fsi, io) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE;
dma_unmap_single(dai->dev, io->dma,
snd_pcm_lib_buffer_bytes(io->substream), dir);
return 0;
}
static dma_addr_t fsi_dma_get_area(struct fsi_stream *io)
{
struct snd_pcm_runtime *runtime = io->substream->runtime;
return io->dma + samples_to_bytes(runtime, io->buff_sample_pos);
}
static void fsi_dma_complete(void *data)
{
struct fsi_stream *io = (struct fsi_stream *)data;
struct fsi_priv *fsi = fsi_stream_to_priv(io);
struct snd_pcm_runtime *runtime = io->substream->runtime;
struct snd_soc_dai *dai = fsi_get_dai(io->substream);
enum dma_data_direction dir = fsi_stream_is_play(fsi, io) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE;
dma_sync_single_for_cpu(dai->dev, fsi_dma_get_area(io),
samples_to_bytes(runtime, io->period_samples), dir);
io->buff_sample_pos += io->period_samples;
io->period_pos++;
if (io->period_pos >= runtime->periods) {
io->period_pos = 0;
io->buff_sample_pos = 0;
}
fsi_count_fifo_err(fsi);
fsi_stream_transfer(io);
snd_pcm_period_elapsed(io->substream);
}
static void fsi_dma_do_tasklet(unsigned long data)
{
struct fsi_stream *io = (struct fsi_stream *)data;
struct fsi_priv *fsi = fsi_stream_to_priv(io);
struct snd_soc_dai *dai;
struct dma_async_tx_descriptor *desc;
struct snd_pcm_runtime *runtime;
enum dma_data_direction dir;
int is_play = fsi_stream_is_play(fsi, io);
int len;
dma_addr_t buf;
if (!fsi_stream_is_working(fsi, io))
return;
dai = fsi_get_dai(io->substream);
runtime = io->substream->runtime;
dir = is_play ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
len = samples_to_bytes(runtime, io->period_samples);
buf = fsi_dma_get_area(io);
dma_sync_single_for_device(dai->dev, buf, len, dir);
desc = dmaengine_prep_slave_single(io->chan, buf, len, dir,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(dai->dev, "dmaengine_prep_slave_sg() fail\n");
return;
}
desc->callback = fsi_dma_complete;
desc->callback_param = io;
if (dmaengine_submit(desc) < 0) {
dev_err(dai->dev, "tx_submit() fail\n");
return;
}
dma_async_issue_pending(io->chan);
if (!is_play) {
if (ERR_OVER & fsi_reg_read(fsi, DIFF_ST)) {
fsi_reg_mask_set(fsi, DIFF_CTL, FIFO_CLR, FIFO_CLR);
fsi_reg_write(fsi, DIFF_ST, 0);
}
}
}
static bool fsi_dma_filter(struct dma_chan *chan, void *param)
{
struct sh_dmae_slave *slave = param;
chan->private = slave;
return true;
}
static int fsi_dma_transfer(struct fsi_priv *fsi, struct fsi_stream *io)
{
tasklet_schedule(&io->tasklet);
return 0;
}
static void fsi_dma_push_start_stop(struct fsi_priv *fsi, struct fsi_stream *io,
int start)
{
struct fsi_master *master = fsi_get_master(fsi);
u32 clk = fsi_is_port_a(fsi) ? CRA : CRB;
u32 enable = start ? DMA_ON : 0;
fsi_reg_mask_set(fsi, OUT_DMAC, DMA_ON, enable);
dmaengine_terminate_all(io->chan);
if (fsi_is_clk_master(fsi))
fsi_master_mask_set(master, CLK_RST, clk, (enable) ? clk : 0);
}
static int fsi_dma_probe(struct fsi_priv *fsi, struct fsi_stream *io, struct device *dev)
{
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
io->chan = dma_request_channel(mask, fsi_dma_filter, &io->slave);
if (!io->chan) {
if (fsi_stream_is_play(fsi, io))
fsi->playback.handler = &fsi_pio_push_handler;
else
fsi->capture.handler = &fsi_pio_pop_handler;
dev_info(dev, "switch handler (dma => pio)\n");
return fsi_stream_probe(fsi, dev);
}
tasklet_init(&io->tasklet, fsi_dma_do_tasklet, (unsigned long)io);
return 0;
}
static int fsi_dma_remove(struct fsi_priv *fsi, struct fsi_stream *io)
{
tasklet_kill(&io->tasklet);
fsi_stream_stop(fsi, io);
if (io->chan)
dma_release_channel(io->chan);
io->chan = NULL;
return 0;
}
static void fsi_fifo_init(struct fsi_priv *fsi,
struct fsi_stream *io,
struct device *dev)
{
struct fsi_master *master = fsi_get_master(fsi);
int is_play = fsi_stream_is_play(fsi, io);
u32 shift, i;
int frame_capa;
shift = fsi_master_read(master, FIFO_SZ);
shift >>= fsi_get_port_shift(fsi, io);
shift &= FIFO_SZ_MASK;
frame_capa = 256 << shift;
dev_dbg(dev, "fifo = %d words\n", frame_capa);
for (i = 1; i < fsi->chan_num; i <<= 1)
frame_capa >>= 1;
dev_dbg(dev, "%d channel %d store\n",
fsi->chan_num, frame_capa);
io->fifo_sample_capa = fsi_frame2sample(fsi, frame_capa);
if (is_play) {
fsi_reg_write(fsi, DOFF_CTL, IRQ_HALF);
fsi_reg_mask_set(fsi, DOFF_CTL, FIFO_CLR, FIFO_CLR);
} else {
fsi_reg_write(fsi, DIFF_CTL, IRQ_HALF);
fsi_reg_mask_set(fsi, DIFF_CTL, FIFO_CLR, FIFO_CLR);
}
}
static int fsi_hw_startup(struct fsi_priv *fsi,
struct fsi_stream *io,
struct device *dev)
{
u32 flags = fsi_get_info_flags(fsi);
u32 data = 0;
if (fsi_is_clk_master(fsi))
data = DIMD | DOMD;
fsi_reg_mask_set(fsi, CKG1, (DIMD | DOMD), data);
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
if (fsi_is_spdif(fsi)) {
fsi_spdif_clk_ctrl(fsi, 1);
fsi_reg_mask_set(fsi, OUT_SEL, DMMD, DMMD);
}
data = 0;
switch (io->sample_width) {
case 2:
data = BUSOP_GET(16, io->bus_option);
break;
case 4:
data = BUSOP_GET(24, io->bus_option);
break;
}
fsi_format_bus_setup(fsi, io, data, dev);
fsi_irq_disable(fsi, io);
fsi_irq_clear_status(fsi);
fsi_fifo_init(fsi, io, dev);
return 0;
}
static void fsi_hw_shutdown(struct fsi_priv *fsi,
struct device *dev)
{
if (fsi_is_clk_master(fsi))
fsi_set_master_clk(dev, fsi, fsi->rate, 0);
}
static int fsi_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
fsi->rate = 0;
return 0;
}
static void fsi_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
fsi->rate = 0;
}
static int fsi_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
struct fsi_stream *io = fsi_stream_get(fsi, substream);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
fsi_stream_init(fsi, io, substream);
fsi_hw_startup(fsi, io, dai->dev);
ret = fsi_stream_transfer(io);
if (0 == ret)
fsi_stream_start(fsi, io);
break;
case SNDRV_PCM_TRIGGER_STOP:
fsi_hw_shutdown(fsi, dai->dev);
fsi_stream_stop(fsi, io);
fsi_stream_quit(fsi, io);
break;
}
return ret;
}
static int fsi_set_fmt_dai(struct fsi_priv *fsi, unsigned int fmt)
{
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
fsi->fmt = CR_I2S;
fsi->chan_num = 2;
break;
case SND_SOC_DAIFMT_LEFT_J:
fsi->fmt = CR_PCM;
fsi->chan_num = 2;
break;
default:
return -EINVAL;
}
return 0;
}
static int fsi_set_fmt_spdif(struct fsi_priv *fsi)
{
struct fsi_master *master = fsi_get_master(fsi);
if (fsi_version(master) < 2)
return -EINVAL;
fsi->fmt = CR_DTMD_SPDIF_PCM | CR_PCM;
fsi->chan_num = 2;
fsi->spdif = 1;
return 0;
}
static int fsi_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct fsi_priv *fsi = fsi_get_priv_frm_dai(dai);
set_rate_func set_rate = fsi_get_info_set_rate(fsi);
u32 flags = fsi_get_info_flags(fsi);
int ret;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
fsi->clk_master = 1;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
if (fsi_is_clk_master(fsi) && !set_rate) {
dev_err(dai->dev, "platform doesn't have set_rate\n");
return -EINVAL;
}
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
return ret;
}
static int fsi_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
long rate = params_rate(params);
int ret;
if (!fsi_is_clk_master(fsi))
return 0;
ret = fsi_set_master_clk(dai->dev, fsi, rate, 1);
if (ret < 0)
return ret;
fsi->rate = rate;
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
struct fsi_priv *fsi = fsi_get_priv(substream);
struct fsi_stream *io = fsi_stream_get(fsi, substream);
return fsi_sample2frame(fsi, io->buff_sample_pos);
}
static void fsi_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int fsi_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_pcm *pcm = rtd->pcm;
return snd_pcm_lib_preallocate_pages_for_all(
pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
PREALLOC_BUFFER, PREALLOC_BUFFER_MAX);
}
static void fsi_handler_init(struct fsi_priv *fsi)
{
fsi->playback.handler = &fsi_pio_push_handler;
fsi->playback.priv = fsi;
fsi->capture.handler = &fsi_pio_pop_handler;
fsi->capture.priv = fsi;
if (fsi->info->tx_id) {
fsi->playback.slave.shdma_slave.slave_id = fsi->info->tx_id;
fsi->playback.handler = &fsi_dma_push_handler;
}
}
static int fsi_probe(struct platform_device *pdev)
{
struct fsi_master *master;
const struct platform_device_id *id_entry;
struct sh_fsi_platform_info *info = pdev->dev.platform_data;
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
master->core = (struct fsi_core *)id_entry->driver_data;
spin_lock_init(&master->lock);
master->fsia.base = master->base;
master->fsia.master = master;
master->fsia.info = &info->port_a;
fsi_handler_init(&master->fsia);
ret = fsi_stream_probe(&master->fsia, &pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "FSIA stream probe failed\n");
goto exit_iounmap;
}
master->fsib.base = master->base + 0x40;
master->fsib.master = master;
master->fsib.info = &info->port_b;
fsi_handler_init(&master->fsib);
ret = fsi_stream_probe(&master->fsib, &pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "FSIB stream probe failed\n");
goto exit_fsia;
}
pm_runtime_enable(&pdev->dev);
dev_set_drvdata(&pdev->dev, master);
ret = request_irq(irq, &fsi_interrupt, 0,
id_entry->name, master);
if (ret) {
dev_err(&pdev->dev, "irq request err\n");
goto exit_fsib;
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
exit_fsib:
fsi_stream_remove(&master->fsib);
exit_fsia:
fsi_stream_remove(&master->fsia);
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
free_irq(master->irq, master);
pm_runtime_disable(&pdev->dev);
snd_soc_unregister_dais(&pdev->dev, ARRAY_SIZE(fsi_soc_dai));
snd_soc_unregister_platform(&pdev->dev);
fsi_stream_remove(&master->fsia);
fsi_stream_remove(&master->fsib);
iounmap(master->base);
kfree(master);
return 0;
}
static void __fsi_suspend(struct fsi_priv *fsi,
struct fsi_stream *io,
struct device *dev)
{
if (!fsi_stream_is_working(fsi, io))
return;
fsi_stream_stop(fsi, io);
fsi_hw_shutdown(fsi, dev);
}
static void __fsi_resume(struct fsi_priv *fsi,
struct fsi_stream *io,
struct device *dev)
{
if (!fsi_stream_is_working(fsi, io))
return;
fsi_hw_startup(fsi, io, dev);
if (fsi_is_clk_master(fsi) && fsi->rate)
fsi_set_master_clk(dev, fsi, fsi->rate, 1);
fsi_stream_start(fsi, io);
}
static int fsi_suspend(struct device *dev)
{
struct fsi_master *master = dev_get_drvdata(dev);
struct fsi_priv *fsia = &master->fsia;
struct fsi_priv *fsib = &master->fsib;
__fsi_suspend(fsia, &fsia->playback, dev);
__fsi_suspend(fsia, &fsia->capture, dev);
__fsi_suspend(fsib, &fsib->playback, dev);
__fsi_suspend(fsib, &fsib->capture, dev);
return 0;
}
static int fsi_resume(struct device *dev)
{
struct fsi_master *master = dev_get_drvdata(dev);
struct fsi_priv *fsia = &master->fsia;
struct fsi_priv *fsib = &master->fsib;
__fsi_resume(fsia, &fsia->playback, dev);
__fsi_resume(fsia, &fsia->capture, dev);
__fsi_resume(fsib, &fsib->playback, dev);
__fsi_resume(fsib, &fsib->capture, dev);
return 0;
}
