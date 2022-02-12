static void rcar_drif_write(struct rcar_drif *ch, u32 offset, u32 data)
{
writel(data, ch->base + offset);
}
static u32 rcar_drif_read(struct rcar_drif *ch, u32 offset)
{
return readl(ch->base + offset);
}
static void rcar_drif_release_dmachannels(struct rcar_drif_sdr *sdr)
{
unsigned int i;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask)
if (sdr->ch[i]->dmach) {
dma_release_channel(sdr->ch[i]->dmach);
sdr->ch[i]->dmach = NULL;
}
}
static int rcar_drif_alloc_dmachannels(struct rcar_drif_sdr *sdr)
{
struct dma_slave_config dma_cfg;
unsigned int i;
int ret = -ENODEV;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
struct rcar_drif *ch = sdr->ch[i];
ch->dmach = dma_request_slave_channel(&ch->pdev->dev, "rx");
if (!ch->dmach) {
rdrif_err(sdr, "ch%u: dma channel req failed\n", i);
goto dmach_error;
}
memset(&dma_cfg, 0, sizeof(dma_cfg));
dma_cfg.src_addr = (phys_addr_t)(ch->start + RCAR_DRIF_SIRFDR);
dma_cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
ret = dmaengine_slave_config(ch->dmach, &dma_cfg);
if (ret) {
rdrif_err(sdr, "ch%u: dma slave config failed\n", i);
goto dmach_error;
}
}
return 0;
dmach_error:
rcar_drif_release_dmachannels(sdr);
return ret;
}
static void rcar_drif_release_queued_bufs(struct rcar_drif_sdr *sdr,
enum vb2_buffer_state state)
{
struct rcar_drif_frame_buf *fbuf, *tmp;
unsigned long flags;
spin_lock_irqsave(&sdr->queued_bufs_lock, flags);
list_for_each_entry_safe(fbuf, tmp, &sdr->queued_bufs, list) {
list_del(&fbuf->list);
vb2_buffer_done(&fbuf->vb.vb2_buf, state);
}
spin_unlock_irqrestore(&sdr->queued_bufs_lock, flags);
}
static inline void rcar_drif_set_mdr1(struct rcar_drif_sdr *sdr)
{
unsigned int i;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
rcar_drif_write(sdr->ch[i], RCAR_DRIF_SITMDR1,
RCAR_DRIF_SITMDR1_PCON);
rcar_drif_write(sdr->ch[i], RCAR_DRIF_SIRMDR1, sdr->mdr1);
rdrif_dbg(sdr, "ch%u: mdr1 = 0x%08x",
i, rcar_drif_read(sdr->ch[i], RCAR_DRIF_SIRMDR1));
}
}
static int rcar_drif_set_format(struct rcar_drif_sdr *sdr)
{
unsigned int i;
rdrif_dbg(sdr, "setfmt: bitlen %u wdcnt %u num_ch %u\n",
sdr->fmt->bitlen, sdr->fmt->wdcnt, sdr->fmt->num_ch);
if (sdr->fmt->num_ch > sdr->num_cur_ch) {
rdrif_err(sdr, "fmt num_ch %u cur_ch %u mismatch\n",
sdr->fmt->num_ch, sdr->num_cur_ch);
return -EINVAL;
}
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
u32 mdr;
mdr = RCAR_DRIF_MDR_GRPCNT(2) |
RCAR_DRIF_MDR_BITLEN(sdr->fmt->bitlen) |
RCAR_DRIF_MDR_WDCNT(sdr->fmt->wdcnt);
rcar_drif_write(sdr->ch[i], RCAR_DRIF_SIRMDR2, mdr);
mdr = RCAR_DRIF_MDR_BITLEN(sdr->fmt->bitlen) |
RCAR_DRIF_MDR_WDCNT(sdr->fmt->wdcnt);
rcar_drif_write(sdr->ch[i], RCAR_DRIF_SIRMDR3, mdr);
rdrif_dbg(sdr, "ch%u: new mdr[2,3] = 0x%08x, 0x%08x\n",
i, rcar_drif_read(sdr->ch[i], RCAR_DRIF_SIRMDR2),
rcar_drif_read(sdr->ch[i], RCAR_DRIF_SIRMDR3));
}
return 0;
}
static void rcar_drif_release_buf(struct rcar_drif_sdr *sdr)
{
unsigned int i;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
struct rcar_drif *ch = sdr->ch[i];
if (ch->buf[0].addr) {
dma_free_coherent(&ch->pdev->dev,
sdr->hwbuf_size * RCAR_DRIF_NUM_HWBUFS,
ch->buf[0].addr, ch->dma_handle);
ch->buf[0].addr = NULL;
}
}
}
static int rcar_drif_request_buf(struct rcar_drif_sdr *sdr)
{
int ret = -ENOMEM;
unsigned int i, j;
void *addr;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
struct rcar_drif *ch = sdr->ch[i];
addr = dma_alloc_coherent(&ch->pdev->dev,
sdr->hwbuf_size * RCAR_DRIF_NUM_HWBUFS,
&ch->dma_handle, GFP_KERNEL);
if (!addr) {
rdrif_err(sdr,
"ch%u: dma alloc failed. num hwbufs %u size %u\n",
i, RCAR_DRIF_NUM_HWBUFS, sdr->hwbuf_size);
goto error;
}
for (j = 0; j < RCAR_DRIF_NUM_HWBUFS; j++) {
ch->buf[j].addr = addr + (j * sdr->hwbuf_size);
ch->buf[j].status = 0;
}
}
return 0;
error:
return ret;
}
static int rcar_drif_queue_setup(struct vb2_queue *vq,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct rcar_drif_sdr *sdr = vb2_get_drv_priv(vq);
if (vq->num_buffers + *num_buffers < 16)
*num_buffers = 16 - vq->num_buffers;
*num_planes = 1;
sizes[0] = PAGE_ALIGN(sdr->fmt->buffersize);
rdrif_dbg(sdr, "num_bufs %d sizes[0] %d\n", *num_buffers, sizes[0]);
return 0;
}
static void rcar_drif_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct rcar_drif_sdr *sdr = vb2_get_drv_priv(vb->vb2_queue);
struct rcar_drif_frame_buf *fbuf =
container_of(vbuf, struct rcar_drif_frame_buf, vb);
unsigned long flags;
rdrif_dbg(sdr, "buf_queue idx %u\n", vb->index);
spin_lock_irqsave(&sdr->queued_bufs_lock, flags);
list_add_tail(&fbuf->list, &sdr->queued_bufs);
spin_unlock_irqrestore(&sdr->queued_bufs_lock, flags);
}
static struct rcar_drif_frame_buf *
rcar_drif_get_fbuf(struct rcar_drif_sdr *sdr)
{
struct rcar_drif_frame_buf *fbuf;
unsigned long flags;
spin_lock_irqsave(&sdr->queued_bufs_lock, flags);
fbuf = list_first_entry_or_null(&sdr->queued_bufs, struct
rcar_drif_frame_buf, list);
if (!fbuf) {
rdrif_dbg(sdr, "\napp late: prod %u\n", sdr->produced);
spin_unlock_irqrestore(&sdr->queued_bufs_lock, flags);
return NULL;
}
list_del(&fbuf->list);
spin_unlock_irqrestore(&sdr->queued_bufs_lock, flags);
return fbuf;
}
static inline bool rcar_drif_bufs_done(struct rcar_drif_hwbuf **buf)
{
return (buf[0]->status & buf[1]->status & RCAR_DRIF_BUF_DONE);
}
static inline bool rcar_drif_bufs_overflow(struct rcar_drif_hwbuf **buf)
{
return ((buf[0]->status | buf[1]->status) & RCAR_DRIF_BUF_OVERFLOW);
}
static inline void rcar_drif_bufs_clear(struct rcar_drif_hwbuf **buf,
unsigned int bit)
{
unsigned int i;
for (i = 0; i < RCAR_DRIF_MAX_CHANNEL; i++)
buf[i]->status &= ~bit;
}
static void rcar_drif_channel_complete(struct rcar_drif *ch, u32 idx)
{
u32 str;
ch->buf[idx].status |= RCAR_DRIF_BUF_DONE;
str = rcar_drif_read(ch, RCAR_DRIF_SISTR);
if (unlikely(str & RCAR_DRIF_RFOVF)) {
rcar_drif_write(ch, RCAR_DRIF_SISTR, str);
ch->buf[idx].status |= RCAR_DRIF_BUF_OVERFLOW;
}
}
static void rcar_drif_dma_complete(void *dma_async_param)
{
struct rcar_drif *ch = dma_async_param;
struct rcar_drif_sdr *sdr = ch->sdr;
struct rcar_drif_hwbuf *buf[RCAR_DRIF_MAX_CHANNEL];
struct rcar_drif_frame_buf *fbuf;
bool overflow = false;
u32 idx, produced;
unsigned int i;
spin_lock(&sdr->dma_lock);
if (!vb2_is_streaming(&sdr->vb_queue)) {
spin_unlock(&sdr->dma_lock);
return;
}
idx = sdr->produced % RCAR_DRIF_NUM_HWBUFS;
rcar_drif_channel_complete(ch, idx);
if (sdr->num_cur_ch == RCAR_DRIF_MAX_CHANNEL) {
buf[0] = ch->num ? to_rcar_drif_buf_pair(sdr, ch->num, idx) :
&ch->buf[idx];
buf[1] = ch->num ? &ch->buf[idx] :
to_rcar_drif_buf_pair(sdr, ch->num, idx);
if (!rcar_drif_bufs_done(buf)) {
spin_unlock(&sdr->dma_lock);
return;
}
rcar_drif_bufs_clear(buf, RCAR_DRIF_BUF_DONE);
if (rcar_drif_bufs_overflow(buf)) {
overflow = true;
rcar_drif_bufs_clear(buf, RCAR_DRIF_BUF_OVERFLOW);
}
} else {
buf[0] = &ch->buf[idx];
if (buf[0]->status & RCAR_DRIF_BUF_OVERFLOW) {
overflow = true;
buf[0]->status &= ~RCAR_DRIF_BUF_OVERFLOW;
}
}
produced = sdr->produced++;
spin_unlock(&sdr->dma_lock);
rdrif_dbg(sdr, "ch%u: prod %u\n", ch->num, produced);
fbuf = rcar_drif_get_fbuf(sdr);
if (!fbuf)
return;
for (i = 0; i < RCAR_DRIF_MAX_CHANNEL; i++)
memcpy(vb2_plane_vaddr(&fbuf->vb.vb2_buf, 0) +
i * sdr->hwbuf_size, buf[i]->addr, sdr->hwbuf_size);
fbuf->vb.field = V4L2_FIELD_NONE;
fbuf->vb.sequence = produced;
fbuf->vb.vb2_buf.timestamp = ktime_get_ns();
vb2_set_plane_payload(&fbuf->vb.vb2_buf, 0, sdr->fmt->buffersize);
vb2_buffer_done(&fbuf->vb.vb2_buf,
overflow ? VB2_BUF_STATE_ERROR : VB2_BUF_STATE_DONE);
}
static int rcar_drif_qbuf(struct rcar_drif *ch)
{
struct rcar_drif_sdr *sdr = ch->sdr;
dma_addr_t addr = ch->dma_handle;
struct dma_async_tx_descriptor *rxd;
dma_cookie_t cookie;
int ret = -EIO;
rxd = dmaengine_prep_dma_cyclic(ch->dmach, addr,
sdr->hwbuf_size * RCAR_DRIF_NUM_HWBUFS,
sdr->hwbuf_size, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!rxd) {
rdrif_err(sdr, "ch%u: prep dma cyclic failed\n", ch->num);
return ret;
}
rxd->callback = rcar_drif_dma_complete;
rxd->callback_param = ch;
cookie = dmaengine_submit(rxd);
if (dma_submit_error(cookie)) {
rdrif_err(sdr, "ch%u: dma submit failed\n", ch->num);
return ret;
}
dma_async_issue_pending(ch->dmach);
return 0;
}
static int rcar_drif_enable_rx(struct rcar_drif_sdr *sdr)
{
unsigned int i;
u32 ctr;
int ret;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
ctr = rcar_drif_read(sdr->ch[i], RCAR_DRIF_SICTR);
ctr |= (RCAR_DRIF_SICTR_RX_RISING_EDGE |
RCAR_DRIF_SICTR_RX_EN);
rcar_drif_write(sdr->ch[i], RCAR_DRIF_SICTR, ctr);
}
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
ret = readl_poll_timeout(sdr->ch[i]->base + RCAR_DRIF_SICTR,
ctr, ctr & RCAR_DRIF_SICTR_RX_EN, 7, 100000);
if (ret) {
rdrif_err(sdr, "ch%u: rx en failed. ctr 0x%08x\n", i,
rcar_drif_read(sdr->ch[i], RCAR_DRIF_SICTR));
break;
}
}
return ret;
}
static void rcar_drif_disable_rx(struct rcar_drif_sdr *sdr)
{
unsigned int i;
u32 ctr;
int ret;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
ctr = rcar_drif_read(sdr->ch[i], RCAR_DRIF_SICTR);
ctr &= ~RCAR_DRIF_SICTR_RX_EN;
rcar_drif_write(sdr->ch[i], RCAR_DRIF_SICTR, ctr);
}
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
ret = readl_poll_timeout(sdr->ch[i]->base + RCAR_DRIF_SICTR,
ctr, !(ctr & RCAR_DRIF_SICTR_RX_EN), 7, 100000);
if (ret)
dev_warn(&sdr->vdev->dev,
"ch%u: failed to disable rx. ctr 0x%08x\n",
i, rcar_drif_read(sdr->ch[i], RCAR_DRIF_SICTR));
}
}
static void rcar_drif_stop_channel(struct rcar_drif *ch)
{
rcar_drif_write(ch, RCAR_DRIF_SIIER, 0x00000000);
dmaengine_terminate_sync(ch->dmach);
}
static void rcar_drif_stop(struct rcar_drif_sdr *sdr)
{
unsigned int i;
rcar_drif_disable_rx(sdr);
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask)
rcar_drif_stop_channel(sdr->ch[i]);
}
static int rcar_drif_start_channel(struct rcar_drif *ch)
{
struct rcar_drif_sdr *sdr = ch->sdr;
u32 ctr, str;
int ret;
rcar_drif_write(ch, RCAR_DRIF_SICTR, RCAR_DRIF_SICTR_RESET);
ret = readl_poll_timeout(ch->base + RCAR_DRIF_SICTR, ctr,
!(ctr & RCAR_DRIF_SICTR_RESET), 7, 100000);
if (ret) {
rdrif_err(sdr, "ch%u: failed to reset rx. ctr 0x%08x\n",
ch->num, rcar_drif_read(ch, RCAR_DRIF_SICTR));
return ret;
}
ret = rcar_drif_qbuf(ch);
if (ret)
return ret;
str = RCAR_DRIF_RFFUL | RCAR_DRIF_REOF | RCAR_DRIF_RFSERR |
RCAR_DRIF_RFUDF | RCAR_DRIF_RFOVF;
rcar_drif_write(ch, RCAR_DRIF_SISTR, str);
rcar_drif_write(ch, RCAR_DRIF_SIIER, 0x00009000);
return ret;
}
static int rcar_drif_start(struct rcar_drif_sdr *sdr)
{
unsigned long enabled = 0;
unsigned int i;
int ret;
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
ret = rcar_drif_start_channel(sdr->ch[i]);
if (ret)
goto start_error;
enabled |= BIT(i);
}
ret = rcar_drif_enable_rx(sdr);
if (ret)
goto enable_error;
sdr->produced = 0;
return ret;
enable_error:
rcar_drif_disable_rx(sdr);
start_error:
for_each_rcar_drif_channel(i, &enabled)
rcar_drif_stop_channel(sdr->ch[i]);
return ret;
}
static int rcar_drif_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct rcar_drif_sdr *sdr = vb2_get_drv_priv(vq);
unsigned long enabled = 0;
unsigned int i;
int ret;
mutex_lock(&sdr->v4l2_mutex);
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask) {
ret = clk_prepare_enable(sdr->ch[i]->clk);
if (ret)
goto error;
enabled |= BIT(i);
}
rcar_drif_set_mdr1(sdr);
ret = rcar_drif_set_format(sdr);
if (ret)
goto error;
if (sdr->num_cur_ch == RCAR_DRIF_MAX_CHANNEL)
sdr->hwbuf_size = sdr->fmt->buffersize / RCAR_DRIF_MAX_CHANNEL;
else
sdr->hwbuf_size = sdr->fmt->buffersize;
rdrif_dbg(sdr, "num hwbufs %u, hwbuf_size %u\n",
RCAR_DRIF_NUM_HWBUFS, sdr->hwbuf_size);
ret = rcar_drif_alloc_dmachannels(sdr);
if (ret)
goto error;
ret = rcar_drif_request_buf(sdr);
if (ret)
goto error;
ret = rcar_drif_start(sdr);
if (ret)
goto error;
mutex_unlock(&sdr->v4l2_mutex);
return ret;
error:
rcar_drif_release_queued_bufs(sdr, VB2_BUF_STATE_QUEUED);
rcar_drif_release_buf(sdr);
rcar_drif_release_dmachannels(sdr);
for_each_rcar_drif_channel(i, &enabled)
clk_disable_unprepare(sdr->ch[i]->clk);
mutex_unlock(&sdr->v4l2_mutex);
return ret;
}
static void rcar_drif_stop_streaming(struct vb2_queue *vq)
{
struct rcar_drif_sdr *sdr = vb2_get_drv_priv(vq);
unsigned int i;
mutex_lock(&sdr->v4l2_mutex);
rcar_drif_stop(sdr);
rcar_drif_release_queued_bufs(sdr, VB2_BUF_STATE_ERROR);
rcar_drif_release_buf(sdr);
rcar_drif_release_dmachannels(sdr);
for_each_rcar_drif_channel(i, &sdr->cur_ch_mask)
clk_disable_unprepare(sdr->ch[i]->clk);
mutex_unlock(&sdr->v4l2_mutex);
}
static int rcar_drif_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
strlcpy(cap->driver, KBUILD_MODNAME, sizeof(cap->driver));
strlcpy(cap->card, sdr->vdev->name, sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
sdr->vdev->name);
return 0;
}
static int rcar_drif_set_default_format(struct rcar_drif_sdr *sdr)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
if (sdr->num_hw_ch == formats[i].num_ch) {
sdr->fmt = &formats[i];
sdr->cur_ch_mask = sdr->hw_ch_mask;
sdr->num_cur_ch = sdr->num_hw_ch;
dev_dbg(sdr->dev, "default fmt[%u]: mask %lu num %u\n",
i, sdr->cur_ch_mask, sdr->num_cur_ch);
return 0;
}
}
return -EINVAL;
}
static int rcar_drif_enum_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index >= ARRAY_SIZE(formats))
return -EINVAL;
f->pixelformat = formats[f->index].pixelformat;
return 0;
}
static int rcar_drif_g_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
f->fmt.sdr.pixelformat = sdr->fmt->pixelformat;
f->fmt.sdr.buffersize = sdr->fmt->buffersize;
return 0;
}
static int rcar_drif_s_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
struct vb2_queue *q = &sdr->vb_queue;
unsigned int i;
if (vb2_is_busy(q))
return -EBUSY;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat)
break;
}
if (i == ARRAY_SIZE(formats))
i = 0;
sdr->fmt = &formats[i];
f->fmt.sdr.pixelformat = sdr->fmt->pixelformat;
f->fmt.sdr.buffersize = formats[i].buffersize;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
if (formats[i].num_ch < sdr->num_hw_ch) {
sdr->cur_ch_mask = BIT(0);
sdr->num_cur_ch = formats[i].num_ch;
} else {
sdr->cur_ch_mask = sdr->hw_ch_mask;
sdr->num_cur_ch = sdr->num_hw_ch;
}
rdrif_dbg(sdr, "cur: idx %u mask %lu num %u\n",
i, sdr->cur_ch_mask, sdr->num_cur_ch);
return 0;
}
static int rcar_drif_try_fmt_sdr_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat) {
f->fmt.sdr.buffersize = formats[i].buffersize;
return 0;
}
}
f->fmt.sdr.pixelformat = formats[0].pixelformat;
f->fmt.sdr.buffersize = formats[0].buffersize;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
return 0;
}
static int rcar_drif_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
return v4l2_subdev_call(sdr->ep.subdev, tuner, enum_freq_bands, band);
}
static int rcar_drif_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
return v4l2_subdev_call(sdr->ep.subdev, tuner, g_frequency, f);
}
static int rcar_drif_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
return v4l2_subdev_call(sdr->ep.subdev, tuner, s_frequency, f);
}
static int rcar_drif_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *vt)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
return v4l2_subdev_call(sdr->ep.subdev, tuner, g_tuner, vt);
}
static int rcar_drif_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *vt)
{
struct rcar_drif_sdr *sdr = video_drvdata(file);
return v4l2_subdev_call(sdr->ep.subdev, tuner, s_tuner, vt);
}
static int rcar_drif_sdr_register(struct rcar_drif_sdr *sdr)
{
int ret;
sdr->vdev = video_device_alloc();
if (!sdr->vdev)
return -ENOMEM;
snprintf(sdr->vdev->name, sizeof(sdr->vdev->name), "R-Car DRIF");
sdr->vdev->fops = &rcar_drif_fops;
sdr->vdev->ioctl_ops = &rcar_drif_ioctl_ops;
sdr->vdev->release = video_device_release;
sdr->vdev->lock = &sdr->v4l2_mutex;
sdr->vdev->queue = &sdr->vb_queue;
sdr->vdev->queue->lock = &sdr->vb_queue_mutex;
sdr->vdev->ctrl_handler = &sdr->ctrl_hdl;
sdr->vdev->v4l2_dev = &sdr->v4l2_dev;
sdr->vdev->device_caps = V4L2_CAP_SDR_CAPTURE | V4L2_CAP_TUNER |
V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
video_set_drvdata(sdr->vdev, sdr);
ret = video_register_device(sdr->vdev, VFL_TYPE_SDR, -1);
if (ret) {
video_device_release(sdr->vdev);
sdr->vdev = NULL;
dev_err(sdr->dev, "failed video_register_device (%d)\n", ret);
}
return ret;
}
static void rcar_drif_sdr_unregister(struct rcar_drif_sdr *sdr)
{
video_unregister_device(sdr->vdev);
sdr->vdev = NULL;
}
static int rcar_drif_notify_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct rcar_drif_sdr *sdr =
container_of(notifier, struct rcar_drif_sdr, notifier);
if (sdr->ep.asd.match.fwnode.fwnode !=
of_fwnode_handle(subdev->dev->of_node)) {
rdrif_err(sdr, "subdev %s cannot bind\n", subdev->name);
return -EINVAL;
}
v4l2_set_subdev_hostdata(subdev, sdr);
sdr->ep.subdev = subdev;
rdrif_dbg(sdr, "bound asd %s\n", subdev->name);
return 0;
}
static void rcar_drif_notify_unbind(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
struct rcar_drif_sdr *sdr =
container_of(notifier, struct rcar_drif_sdr, notifier);
if (sdr->ep.subdev != subdev) {
rdrif_err(sdr, "subdev %s is not bound\n", subdev->name);
return;
}
v4l2_ctrl_handler_free(&sdr->ctrl_hdl);
sdr->v4l2_dev.ctrl_handler = NULL;
sdr->ep.subdev = NULL;
rcar_drif_sdr_unregister(sdr);
rdrif_dbg(sdr, "unbind asd %s\n", subdev->name);
}
static int rcar_drif_notify_complete(struct v4l2_async_notifier *notifier)
{
struct rcar_drif_sdr *sdr =
container_of(notifier, struct rcar_drif_sdr, notifier);
int ret;
ret = v4l2_ctrl_handler_init(&sdr->ctrl_hdl, 10);
if (ret)
return -ENOMEM;
sdr->v4l2_dev.ctrl_handler = &sdr->ctrl_hdl;
ret = v4l2_device_register_subdev_nodes(&sdr->v4l2_dev);
if (ret) {
rdrif_err(sdr, "failed: register subdev nodes ret %d\n", ret);
goto error;
}
ret = v4l2_ctrl_add_handler(&sdr->ctrl_hdl,
sdr->ep.subdev->ctrl_handler, NULL);
if (ret) {
rdrif_err(sdr, "failed: ctrl add hdlr ret %d\n", ret);
goto error;
}
ret = rcar_drif_sdr_register(sdr);
if (ret)
goto error;
return ret;
error:
v4l2_ctrl_handler_free(&sdr->ctrl_hdl);
return ret;
}
static void rcar_drif_get_ep_properties(struct rcar_drif_sdr *sdr,
struct fwnode_handle *fwnode)
{
u32 val;
sdr->mdr1 = RCAR_DRIF_SIRMDR1_SYNCMD_LR | RCAR_DRIF_SIRMDR1_MSB_FIRST |
RCAR_DRIF_SIRMDR1_DTDL_1 | RCAR_DRIF_SIRMDR1_SYNCDL_0;
if (!fwnode_property_read_u32(fwnode, "sync-active", &val))
sdr->mdr1 |= val ? RCAR_DRIF_SIRMDR1_SYNCAC_POL_HIGH :
RCAR_DRIF_SIRMDR1_SYNCAC_POL_LOW;
else
sdr->mdr1 |= RCAR_DRIF_SIRMDR1_SYNCAC_POL_HIGH;
dev_dbg(sdr->dev, "mdr1 0x%08x\n", sdr->mdr1);
}
static int rcar_drif_parse_subdevs(struct rcar_drif_sdr *sdr)
{
struct v4l2_async_notifier *notifier = &sdr->notifier;
struct fwnode_handle *fwnode, *ep;
notifier->subdevs = devm_kzalloc(sdr->dev, sizeof(*notifier->subdevs),
GFP_KERNEL);
if (!notifier->subdevs)
return -ENOMEM;
ep = fwnode_graph_get_next_endpoint(of_fwnode_handle(sdr->dev->of_node),
NULL);
if (!ep)
return 0;
notifier->subdevs[notifier->num_subdevs] = &sdr->ep.asd;
fwnode = fwnode_graph_get_remote_port_parent(ep);
if (!fwnode) {
dev_warn(sdr->dev, "bad remote port parent\n");
fwnode_handle_put(ep);
return -EINVAL;
}
sdr->ep.asd.match.fwnode.fwnode = fwnode;
sdr->ep.asd.match_type = V4L2_ASYNC_MATCH_FWNODE;
notifier->num_subdevs++;
rcar_drif_get_ep_properties(sdr, ep);
fwnode_handle_put(fwnode);
fwnode_handle_put(ep);
return 0;
}
static bool rcar_drif_primary_bond(struct platform_device *pdev)
{
return of_property_read_bool(pdev->dev.of_node, "renesas,primary-bond");
}
static struct device_node *rcar_drif_bond_enabled(struct platform_device *p)
{
struct device_node *np;
np = of_parse_phandle(p->dev.of_node, "renesas,bonding", 0);
if (np && of_device_is_available(np))
return np;
return NULL;
}
static int rcar_drif_bond_available(struct rcar_drif_sdr *sdr,
struct device_node *np)
{
struct platform_device *pdev;
struct rcar_drif *ch;
int ret = 0;
pdev = of_find_device_by_node(np);
if (!pdev) {
dev_err(sdr->dev, "failed to get bonded device from node\n");
return -ENODEV;
}
device_lock(&pdev->dev);
ch = platform_get_drvdata(pdev);
if (ch) {
ch->sdr = sdr;
sdr->ch[ch->num] = ch;
sdr->hw_ch_mask |= BIT(ch->num);
} else {
dev_info(sdr->dev, "defer probe\n");
ret = -EPROBE_DEFER;
}
device_unlock(&pdev->dev);
put_device(&pdev->dev);
return ret;
}
static int rcar_drif_sdr_probe(struct rcar_drif_sdr *sdr)
{
int ret;
ret = rcar_drif_set_default_format(sdr);
if (ret) {
dev_err(sdr->dev, "failed to set default format\n");
return ret;
}
sdr->hwbuf_size = RCAR_DRIF_DEFAULT_HWBUF_SIZE;
mutex_init(&sdr->v4l2_mutex);
mutex_init(&sdr->vb_queue_mutex);
spin_lock_init(&sdr->queued_bufs_lock);
spin_lock_init(&sdr->dma_lock);
INIT_LIST_HEAD(&sdr->queued_bufs);
sdr->vb_queue.type = V4L2_BUF_TYPE_SDR_CAPTURE;
sdr->vb_queue.io_modes = VB2_READ | VB2_MMAP | VB2_DMABUF;
sdr->vb_queue.drv_priv = sdr;
sdr->vb_queue.buf_struct_size = sizeof(struct rcar_drif_frame_buf);
sdr->vb_queue.ops = &rcar_drif_vb2_ops;
sdr->vb_queue.mem_ops = &vb2_vmalloc_memops;
sdr->vb_queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(&sdr->vb_queue);
if (ret) {
dev_err(sdr->dev, "failed: vb2_queue_init ret %d\n", ret);
return ret;
}
ret = v4l2_device_register(sdr->dev, &sdr->v4l2_dev);
if (ret) {
dev_err(sdr->dev, "failed: v4l2_device_register ret %d\n", ret);
return ret;
}
ret = rcar_drif_parse_subdevs(sdr);
if (ret)
goto error;
sdr->notifier.bound = rcar_drif_notify_bound;
sdr->notifier.unbind = rcar_drif_notify_unbind;
sdr->notifier.complete = rcar_drif_notify_complete;
ret = v4l2_async_notifier_register(&sdr->v4l2_dev, &sdr->notifier);
if (ret < 0) {
dev_err(sdr->dev, "failed: notifier register ret %d\n", ret);
goto error;
}
return ret;
error:
v4l2_device_unregister(&sdr->v4l2_dev);
return ret;
}
static void rcar_drif_sdr_remove(struct rcar_drif_sdr *sdr)
{
v4l2_async_notifier_unregister(&sdr->notifier);
v4l2_device_unregister(&sdr->v4l2_dev);
}
static int rcar_drif_probe(struct platform_device *pdev)
{
struct rcar_drif_sdr *sdr;
struct device_node *np;
struct rcar_drif *ch;
struct resource *res;
int ret;
ch = devm_kzalloc(&pdev->dev, sizeof(*ch), GFP_KERNEL);
if (!ch)
return -ENOMEM;
ch->pdev = pdev;
ch->clk = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(ch->clk)) {
ret = PTR_ERR(ch->clk);
dev_err(&pdev->dev, "clk get failed (%d)\n", ret);
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ch->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ch->base)) {
ret = PTR_ERR(ch->base);
dev_err(&pdev->dev, "ioremap failed (%d)\n", ret);
return ret;
}
ch->start = res->start;
platform_set_drvdata(pdev, ch);
np = rcar_drif_bond_enabled(pdev);
if (np) {
if (!rcar_drif_primary_bond(pdev)) {
ch->num = 1;
of_node_put(np);
return 0;
}
}
sdr = devm_kzalloc(&pdev->dev, sizeof(*sdr), GFP_KERNEL);
if (!sdr) {
of_node_put(np);
return -ENOMEM;
}
ch->sdr = sdr;
sdr->dev = &pdev->dev;
sdr->ch[ch->num] = ch;
sdr->hw_ch_mask = BIT(ch->num);
if (np) {
ret = rcar_drif_bond_available(sdr, np);
of_node_put(np);
if (ret)
return ret;
}
sdr->num_hw_ch = hweight_long(sdr->hw_ch_mask);
return rcar_drif_sdr_probe(sdr);
}
static int rcar_drif_remove(struct platform_device *pdev)
{
struct rcar_drif *ch = platform_get_drvdata(pdev);
struct rcar_drif_sdr *sdr = ch->sdr;
if (ch->num)
return 0;
rcar_drif_sdr_remove(sdr);
return 0;
}
static int __maybe_unused rcar_drif_suspend(struct device *dev)
{
return 0;
}
static int __maybe_unused rcar_drif_resume(struct device *dev)
{
return 0;
}
