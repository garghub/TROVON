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
static int fsi_is_enable_stream(struct fsi_priv *fsi)
{
return fsi->enable_stream;
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
static int fsi_clk_init(struct device *dev,
struct fsi_priv *fsi,
int xck,
int ick,
int div,
int (*set_rate)(struct device *dev,
struct fsi_priv *fsi))
{
struct fsi_clk *clock = &fsi->clock;
int is_porta = fsi_is_port_a(fsi);
clock->xck = NULL;
clock->ick = NULL;
clock->div = NULL;
clock->rate = 0;
clock->count = 0;
clock->set_rate = set_rate;
clock->own = devm_clk_get(dev, NULL);
if (IS_ERR(clock->own))
return -EINVAL;
if (xck) {
clock->xck = devm_clk_get(dev, is_porta ? "xcka" : "xckb");
if (IS_ERR(clock->xck)) {
dev_err(dev, "can't get xck clock\n");
return -EINVAL;
}
if (clock->xck == clock->own) {
dev_err(dev, "cpu doesn't support xck clock\n");
return -EINVAL;
}
}
if (ick) {
clock->ick = devm_clk_get(dev, is_porta ? "icka" : "ickb");
if (IS_ERR(clock->ick)) {
dev_err(dev, "can't get ick clock\n");
return -EINVAL;
}
if (clock->ick == clock->own) {
dev_err(dev, "cpu doesn't support ick clock\n");
return -EINVAL;
}
}
if (div) {
clock->div = devm_clk_get(dev, is_porta ? "diva" : "divb");
if (IS_ERR(clock->div)) {
dev_err(dev, "can't get div clock\n");
return -EINVAL;
}
if (clock->div == clock->own) {
dev_err(dev, "cpu doens't support div clock\n");
return -EINVAL;
}
}
return 0;
}
static void fsi_clk_valid(struct fsi_priv *fsi, unsigned long rate)
{
fsi->clock.rate = rate;
}
static int fsi_clk_is_valid(struct fsi_priv *fsi)
{
return fsi->clock.set_rate &&
fsi->clock.rate;
}
static int fsi_clk_enable(struct device *dev,
struct fsi_priv *fsi)
{
struct fsi_clk *clock = &fsi->clock;
int ret = -EINVAL;
if (!fsi_clk_is_valid(fsi))
return ret;
if (0 == clock->count) {
ret = clock->set_rate(dev, fsi);
if (ret < 0) {
fsi_clk_invalid(fsi);
return ret;
}
if (clock->xck)
clk_enable(clock->xck);
if (clock->ick)
clk_enable(clock->ick);
if (clock->div)
clk_enable(clock->div);
clock->count++;
}
return ret;
}
static int fsi_clk_disable(struct device *dev,
struct fsi_priv *fsi)
{
struct fsi_clk *clock = &fsi->clock;
if (!fsi_clk_is_valid(fsi))
return -EINVAL;
if (1 == clock->count--) {
clk_disable(clock->xck);
clk_disable(clock->ick);
clk_disable(clock->div);
}
return 0;
}
static int fsi_clk_set_ackbpf(struct device *dev,
struct fsi_priv *fsi,
int ackmd, int bpfmd)
{
u32 data = 0;
if (bpfmd > ackmd) {
dev_err(dev, "unsupported rate (%d/%d)\n", ackmd, bpfmd);
return -EINVAL;
}
switch (ackmd) {
case 512:
data |= (0x0 << 12);
break;
case 256:
data |= (0x1 << 12);
break;
case 128:
data |= (0x2 << 12);
break;
case 64:
data |= (0x3 << 12);
break;
case 32:
data |= (0x4 << 12);
break;
default:
dev_err(dev, "unsupported ackmd (%d)\n", ackmd);
return -EINVAL;
}
switch (bpfmd) {
case 32:
data |= (0x0 << 8);
break;
case 64:
data |= (0x1 << 8);
break;
case 128:
data |= (0x2 << 8);
break;
case 256:
data |= (0x3 << 8);
break;
case 512:
data |= (0x4 << 8);
break;
case 16:
data |= (0x7 << 8);
break;
default:
dev_err(dev, "unsupported bpfmd (%d)\n", bpfmd);
return -EINVAL;
}
dev_dbg(dev, "ACKMD/BPFMD = %d/%d\n", ackmd, bpfmd);
fsi_reg_mask_set(fsi, CKG1, (ACKMD_MASK | BPFMD_MASK) , data);
udelay(10);
return 0;
}
static int fsi_clk_set_rate_external(struct device *dev,
struct fsi_priv *fsi)
{
struct clk *xck = fsi->clock.xck;
struct clk *ick = fsi->clock.ick;
unsigned long rate = fsi->clock.rate;
unsigned long xrate;
int ackmd, bpfmd;
int ret = 0;
xrate = clk_get_rate(xck);
if (xrate % rate) {
dev_err(dev, "unsupported clock rate\n");
return -EINVAL;
}
clk_set_parent(ick, xck);
clk_set_rate(ick, xrate);
bpfmd = fsi->chan_num * 32;
ackmd = xrate / rate;
dev_dbg(dev, "external/rate = %ld/%ld\n", xrate, rate);
ret = fsi_clk_set_ackbpf(dev, fsi, ackmd, bpfmd);
if (ret < 0)
dev_err(dev, "%s failed", __func__);
return ret;
}
static int fsi_clk_set_rate_cpg(struct device *dev,
struct fsi_priv *fsi)
{
struct clk *ick = fsi->clock.ick;
struct clk *div = fsi->clock.div;
unsigned long rate = fsi->clock.rate;
unsigned long target = 0;
unsigned long actual, cout;
unsigned long diff, min;
unsigned long best_cout, best_act;
int adj;
int ackmd, bpfmd;
int ret = -EINVAL;
if (!(12288000 % rate))
target = 12288000;
if (!(11289600 % rate))
target = 11289600;
if (!target) {
dev_err(dev, "unsupported rate\n");
return ret;
}
bpfmd = fsi->chan_num * 32;
ackmd = target / rate;
ret = fsi_clk_set_ackbpf(dev, fsi, ackmd, bpfmd);
if (ret < 0) {
dev_err(dev, "%s failed", __func__);
return ret;
}
min = ~0;
best_cout = 0;
best_act = 0;
for (adj = 1; adj < 0xffff; adj++) {
cout = target * adj;
if (cout > 100000000)
break;
cout = clk_round_rate(ick, cout);
actual = cout / adj;
diff = abs(actual - target);
if (diff < min) {
min = diff;
best_cout = cout;
best_act = actual;
}
}
ret = clk_set_rate(ick, best_cout);
if (ret < 0) {
dev_err(dev, "ick clock failed\n");
return -EIO;
}
ret = clk_set_rate(div, clk_round_rate(div, best_act));
if (ret < 0) {
dev_err(dev, "div clock failed\n");
return -EIO;
}
dev_dbg(dev, "ick/div = %ld/%ld\n",
clk_get_rate(ick), clk_get_rate(div));
return ret;
}
static void fsi_pointer_update(struct fsi_stream *io, int size)
{
io->buff_sample_pos += size;
if (io->buff_sample_pos >=
io->period_samples * (io->period_pos + 1)) {
struct snd_pcm_substream *substream = io->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
io->period_pos++;
if (io->period_pos >= runtime->periods) {
io->buff_sample_pos = 0;
io->period_pos = 0;
}
snd_pcm_period_elapsed(substream);
}
}
static void fsi_pio_push16(struct fsi_priv *fsi, u8 *_buf, int samples)
{
int i;
if (fsi_is_enable_stream(fsi)) {
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
u8 *buf;
if (!fsi_stream_is_working(fsi, io))
return -EINVAL;
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
fsi_pointer_update(io, samples);
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
static int fsi_pio_start_stop(struct fsi_priv *fsi, struct fsi_stream *io,
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
return 0;
}
static int fsi_pio_push_init(struct fsi_priv *fsi, struct fsi_stream *io)
{
if (fsi_is_enable_stream(fsi))
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
io->bus_option = BUSOP_SET(24, PACKAGE_24BITBUS_BACK) |
BUSOP_SET(16, PACKAGE_16BITBUS_STREAM);
return 0;
}
static void fsi_dma_complete(void *data)
{
struct fsi_stream *io = (struct fsi_stream *)data;
struct fsi_priv *fsi = fsi_stream_to_priv(io);
fsi_pointer_update(io, io->period_samples);
fsi_count_fifo_err(fsi);
}
static int fsi_dma_transfer(struct fsi_priv *fsi, struct fsi_stream *io)
{
struct snd_soc_dai *dai = fsi_get_dai(io->substream);
struct snd_pcm_substream *substream = io->substream;
struct dma_async_tx_descriptor *desc;
int is_play = fsi_stream_is_play(fsi, io);
enum dma_transfer_direction dir;
int ret = -EIO;
if (is_play)
dir = DMA_MEM_TO_DEV;
else
dir = DMA_DEV_TO_MEM;
desc = dmaengine_prep_dma_cyclic(io->chan,
substream->runtime->dma_addr,
snd_pcm_lib_buffer_bytes(substream),
snd_pcm_lib_period_bytes(substream),
dir,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(dai->dev, "dmaengine_prep_dma_cyclic() fail\n");
goto fsi_dma_transfer_err;
}
desc->callback = fsi_dma_complete;
desc->callback_param = io;
if (dmaengine_submit(desc) < 0) {
dev_err(dai->dev, "tx_submit() fail\n");
goto fsi_dma_transfer_err;
}
dma_async_issue_pending(io->chan);
if (!is_play) {
if (ERR_OVER & fsi_reg_read(fsi, DIFF_ST)) {
fsi_reg_mask_set(fsi, DIFF_CTL, FIFO_CLR, FIFO_CLR);
fsi_reg_write(fsi, DIFF_ST, 0);
}
}
ret = 0;
fsi_dma_transfer_err:
return ret;
}
static int fsi_dma_push_start_stop(struct fsi_priv *fsi, struct fsi_stream *io,
int start)
{
struct fsi_master *master = fsi_get_master(fsi);
u32 clk = fsi_is_port_a(fsi) ? CRA : CRB;
u32 enable = start ? DMA_ON : 0;
fsi_reg_mask_set(fsi, OUT_DMAC, DMA_ON, enable);
dmaengine_terminate_all(io->chan);
if (fsi_is_clk_master(fsi))
fsi_master_mask_set(master, CLK_RST, clk, (enable) ? clk : 0);
return 0;
}
static int fsi_dma_probe(struct fsi_priv *fsi, struct fsi_stream *io, struct device *dev)
{
dma_cap_mask_t mask;
int is_play = fsi_stream_is_play(fsi, io);
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
io->chan = dma_request_slave_channel_compat(mask,
shdma_chan_filter, (void *)io->dma_id,
dev, is_play ? "tx" : "rx");
if (io->chan) {
struct dma_slave_config cfg;
int ret;
cfg.slave_id = io->dma_id;
cfg.dst_addr = 0;
cfg.src_addr = 0;
cfg.direction = is_play ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM;
ret = dmaengine_slave_config(io->chan, &cfg);
if (ret < 0) {
dma_release_channel(io->chan);
io->chan = NULL;
}
}
if (!io->chan) {
if (is_play)
fsi->playback.handler = &fsi_pio_push_handler;
else
fsi->capture.handler = &fsi_pio_pop_handler;
dev_info(dev, "switch handler (dma => pio)\n");
return fsi_stream_probe(fsi, dev);
}
return 0;
}
static int fsi_dma_remove(struct fsi_priv *fsi, struct fsi_stream *io)
{
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
u32 data = 0;
if (fsi_is_clk_master(fsi))
data = DIMD | DOMD;
fsi_reg_mask_set(fsi, CKG1, (DIMD | DOMD), data);
data = 0;
if (fsi->bit_clk_inv)
data |= (1 << 0);
if (fsi->lr_clk_inv)
data |= (1 << 4);
if (fsi_is_clk_master(fsi))
data <<= 8;
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
if (fsi_is_clk_master(fsi))
return fsi_clk_enable(dev, fsi);
return 0;
}
static int fsi_hw_shutdown(struct fsi_priv *fsi,
struct device *dev)
{
if (fsi_is_clk_master(fsi))
return fsi_clk_disable(dev, fsi);
return 0;
}
static int fsi_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
fsi_clk_invalid(fsi);
return 0;
}
static void fsi_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
fsi_clk_invalid(fsi);
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
if (!ret)
ret = fsi_hw_startup(fsi, io, dai->dev);
if (!ret)
ret = fsi_stream_start(fsi, io);
if (!ret)
ret = fsi_stream_transfer(io);
break;
case SNDRV_PCM_TRIGGER_STOP:
if (!ret)
ret = fsi_hw_shutdown(fsi, dai->dev);
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
return 0;
}
static int fsi_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct fsi_priv *fsi = fsi_get_priv_frm_dai(dai);
int ret;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
break;
case SND_SOC_DAIFMT_CBS_CFS:
fsi->clk_master = 1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_IF:
fsi->bit_clk_inv = 0;
fsi->lr_clk_inv = 1;
break;
case SND_SOC_DAIFMT_IB_NF:
fsi->bit_clk_inv = 1;
fsi->lr_clk_inv = 0;
break;
case SND_SOC_DAIFMT_IB_IF:
fsi->bit_clk_inv = 1;
fsi->lr_clk_inv = 1;
break;
case SND_SOC_DAIFMT_NB_NF:
default:
fsi->bit_clk_inv = 0;
fsi->lr_clk_inv = 0;
break;
}
if (fsi_is_clk_master(fsi)) {
if (fsi->clk_cpg)
fsi_clk_init(dai->dev, fsi, 0, 1, 1,
fsi_clk_set_rate_cpg);
else
fsi_clk_init(dai->dev, fsi, 1, 1, 0,
fsi_clk_set_rate_external);
}
if (fsi_is_spdif(fsi))
ret = fsi_set_fmt_spdif(fsi);
else
ret = fsi_set_fmt_dai(fsi, fmt & SND_SOC_DAIFMT_FORMAT_MASK);
return ret;
}
static int fsi_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct fsi_priv *fsi = fsi_get_priv(substream);
if (fsi_is_clk_master(fsi))
fsi_clk_valid(fsi, params_rate(params));
return 0;
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
return snd_pcm_lib_preallocate_pages_for_all(
rtd->pcm,
SNDRV_DMA_TYPE_DEV,
rtd->card->snd_card->dev,
PREALLOC_BUFFER, PREALLOC_BUFFER_MAX);
}
static void fsi_of_parse(char *name,
struct device_node *np,
struct sh_fsi_port_info *info,
struct device *dev)
{
int i;
char prop[128];
unsigned long flags = 0;
struct {
char *name;
unsigned int val;
} of_parse_property[] = {
{ "spdif-connection", SH_FSI_FMT_SPDIF },
{ "stream-mode-support", SH_FSI_ENABLE_STREAM_MODE },
{ "use-internal-clock", SH_FSI_CLK_CPG },
};
for (i = 0; i < ARRAY_SIZE(of_parse_property); i++) {
sprintf(prop, "%s,%s", name, of_parse_property[i].name);
if (of_get_property(np, prop, NULL))
flags |= of_parse_property[i].val;
}
info->flags = flags;
dev_dbg(dev, "%s flags : %lx\n", name, info->flags);
}
static void fsi_port_info_init(struct fsi_priv *fsi,
struct sh_fsi_port_info *info)
{
if (info->flags & SH_FSI_FMT_SPDIF)
fsi->spdif = 1;
if (info->flags & SH_FSI_CLK_CPG)
fsi->clk_cpg = 1;
if (info->flags & SH_FSI_ENABLE_STREAM_MODE)
fsi->enable_stream = 1;
}
static void fsi_handler_init(struct fsi_priv *fsi,
struct sh_fsi_port_info *info)
{
fsi->playback.handler = &fsi_pio_push_handler;
fsi->playback.priv = fsi;
fsi->capture.handler = &fsi_pio_pop_handler;
fsi->capture.priv = fsi;
if (info->tx_id) {
fsi->playback.dma_id = info->tx_id;
fsi->playback.handler = &fsi_dma_push_handler;
}
}
static int fsi_probe(struct platform_device *pdev)
{
struct fsi_master *master;
struct device_node *np = pdev->dev.of_node;
struct sh_fsi_platform_info info;
const struct fsi_core *core;
struct fsi_priv *fsi;
struct resource *res;
unsigned int irq;
int ret;
memset(&info, 0, sizeof(info));
core = NULL;
if (np) {
const struct of_device_id *of_id;
of_id = of_match_device(fsi_of_match, &pdev->dev);
if (of_id) {
core = of_id->data;
fsi_of_parse("fsia", np, &info.port_a, &pdev->dev);
fsi_of_parse("fsib", np, &info.port_b, &pdev->dev);
}
} else {
const struct platform_device_id *id_entry = pdev->id_entry;
if (id_entry)
core = (struct fsi_core *)id_entry->driver_data;
if (pdev->dev.platform_data)
memcpy(&info, pdev->dev.platform_data, sizeof(info));
}
if (!core) {
dev_err(&pdev->dev, "unknown fsi device\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || (int)irq <= 0) {
dev_err(&pdev->dev, "Not enough FSI platform resources.\n");
return -ENODEV;
}
master = devm_kzalloc(&pdev->dev, sizeof(*master), GFP_KERNEL);
if (!master) {
dev_err(&pdev->dev, "Could not allocate master\n");
return -ENOMEM;
}
master->base = devm_ioremap_nocache(&pdev->dev,
res->start, resource_size(res));
if (!master->base) {
dev_err(&pdev->dev, "Unable to ioremap FSI registers.\n");
return -ENXIO;
}
master->core = core;
spin_lock_init(&master->lock);
fsi = &master->fsia;
fsi->base = master->base;
fsi->master = master;
fsi_port_info_init(fsi, &info.port_a);
fsi_handler_init(fsi, &info.port_a);
ret = fsi_stream_probe(fsi, &pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "FSIA stream probe failed\n");
return ret;
}
fsi = &master->fsib;
fsi->base = master->base + 0x40;
fsi->master = master;
fsi_port_info_init(fsi, &info.port_b);
fsi_handler_init(fsi, &info.port_b);
ret = fsi_stream_probe(fsi, &pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "FSIB stream probe failed\n");
goto exit_fsia;
}
pm_runtime_enable(&pdev->dev);
dev_set_drvdata(&pdev->dev, master);
ret = devm_request_irq(&pdev->dev, irq, &fsi_interrupt, 0,
dev_name(&pdev->dev), master);
if (ret) {
dev_err(&pdev->dev, "irq request err\n");
goto exit_fsib;
}
ret = snd_soc_register_platform(&pdev->dev, &fsi_soc_platform);
if (ret < 0) {
dev_err(&pdev->dev, "cannot snd soc register\n");
goto exit_fsib;
}
ret = snd_soc_register_component(&pdev->dev, &fsi_soc_component,
fsi_soc_dai, ARRAY_SIZE(fsi_soc_dai));
if (ret < 0) {
dev_err(&pdev->dev, "cannot snd component register\n");
goto exit_snd_soc;
}
return ret;
exit_snd_soc:
snd_soc_unregister_platform(&pdev->dev);
exit_fsib:
pm_runtime_disable(&pdev->dev);
fsi_stream_remove(&master->fsib);
exit_fsia:
fsi_stream_remove(&master->fsia);
return ret;
}
static int fsi_remove(struct platform_device *pdev)
{
struct fsi_master *master;
master = dev_get_drvdata(&pdev->dev);
pm_runtime_disable(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
fsi_stream_remove(&master->fsia);
fsi_stream_remove(&master->fsib);
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
