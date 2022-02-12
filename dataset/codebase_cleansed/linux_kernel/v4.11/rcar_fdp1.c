static int fdp1_fmt_is_rgb(const struct fdp1_fmt *fmt)
{
return fmt->fmt <= 0x1b;
}
static const struct fdp1_fmt *fdp1_find_format(u32 pixelformat)
{
const struct fdp1_fmt *fmt;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fdp1_formats); i++) {
fmt = &fdp1_formats[i];
if (fmt->fourcc == pixelformat)
return fmt;
}
return NULL;
}
static inline struct fdp1_buffer *to_fdp1_buffer(struct vb2_v4l2_buffer *vb)
{
return container_of(vb, struct fdp1_buffer, m2m_buf.vb);
}
static inline struct fdp1_ctx *fh_to_ctx(struct v4l2_fh *fh)
{
return container_of(fh, struct fdp1_ctx, fh);
}
static struct fdp1_q_data *get_q_data(struct fdp1_ctx *ctx,
enum v4l2_buf_type type)
{
if (V4L2_TYPE_IS_OUTPUT(type))
return &ctx->out_q;
else
return &ctx->cap_q;
}
static struct fdp1_job *list_remove_job(struct fdp1_dev *fdp1,
struct list_head *list)
{
struct fdp1_job *job;
unsigned long flags;
spin_lock_irqsave(&fdp1->irqlock, flags);
job = list_first_entry_or_null(list, struct fdp1_job, list);
if (job)
list_del(&job->list);
spin_unlock_irqrestore(&fdp1->irqlock, flags);
return job;
}
static void list_add_job(struct fdp1_dev *fdp1,
struct list_head *list,
struct fdp1_job *job)
{
unsigned long flags;
spin_lock_irqsave(&fdp1->irqlock, flags);
list_add_tail(&job->list, list);
spin_unlock_irqrestore(&fdp1->irqlock, flags);
}
static struct fdp1_job *fdp1_job_alloc(struct fdp1_dev *fdp1)
{
return list_remove_job(fdp1, &fdp1->free_job_list);
}
static void fdp1_job_free(struct fdp1_dev *fdp1, struct fdp1_job *job)
{
memset(job, 0, sizeof(struct fdp1_job));
list_add_job(fdp1, &fdp1->free_job_list, job);
}
static void queue_job(struct fdp1_dev *fdp1, struct fdp1_job *job)
{
list_add_job(fdp1, &fdp1->queued_job_list, job);
}
static struct fdp1_job *get_queued_job(struct fdp1_dev *fdp1)
{
return list_remove_job(fdp1, &fdp1->queued_job_list);
}
static void queue_hw_job(struct fdp1_dev *fdp1, struct fdp1_job *job)
{
list_add_job(fdp1, &fdp1->hw_job_list, job);
}
static struct fdp1_job *get_hw_queued_job(struct fdp1_dev *fdp1)
{
return list_remove_job(fdp1, &fdp1->hw_job_list);
}
static void fdp1_field_complete(struct fdp1_ctx *ctx,
struct fdp1_field_buffer *fbuf)
{
if (!fbuf)
return;
if (fbuf->last_field)
v4l2_m2m_buf_done(fbuf->vb, VB2_BUF_STATE_DONE);
}
static void fdp1_queue_field(struct fdp1_ctx *ctx,
struct fdp1_field_buffer *fbuf)
{
unsigned long flags;
spin_lock_irqsave(&ctx->fdp1->irqlock, flags);
list_add_tail(&fbuf->list, &ctx->fields_queue);
spin_unlock_irqrestore(&ctx->fdp1->irqlock, flags);
ctx->buffers_queued++;
}
static struct fdp1_field_buffer *fdp1_dequeue_field(struct fdp1_ctx *ctx)
{
struct fdp1_field_buffer *fbuf;
unsigned long flags;
ctx->buffers_queued--;
spin_lock_irqsave(&ctx->fdp1->irqlock, flags);
fbuf = list_first_entry_or_null(&ctx->fields_queue,
struct fdp1_field_buffer, list);
if (fbuf)
list_del(&fbuf->list);
spin_unlock_irqrestore(&ctx->fdp1->irqlock, flags);
return fbuf;
}
static struct fdp1_field_buffer *fdp1_peek_queued_field(struct fdp1_ctx *ctx)
{
struct fdp1_field_buffer *fbuf;
unsigned long flags;
spin_lock_irqsave(&ctx->fdp1->irqlock, flags);
fbuf = list_first_entry_or_null(&ctx->fields_queue,
struct fdp1_field_buffer, list);
spin_unlock_irqrestore(&ctx->fdp1->irqlock, flags);
return fbuf;
}
static u32 fdp1_read(struct fdp1_dev *fdp1, unsigned int reg)
{
u32 value = ioread32(fdp1->regs + reg);
if (debug >= 2)
dprintk(fdp1, "Read 0x%08x from 0x%04x\n", value, reg);
return value;
}
static void fdp1_write(struct fdp1_dev *fdp1, u32 val, unsigned int reg)
{
if (debug >= 2)
dprintk(fdp1, "Write 0x%08x to 0x%04x\n", val, reg);
iowrite32(val, fdp1->regs + reg);
}
static void fdp1_set_ipc_dli(struct fdp1_ctx *ctx)
{
struct fdp1_dev *fdp1 = ctx->fdp1;
fdp1_write(fdp1, FD1_IPC_SMSK_THRESH_CONST, FD1_IPC_SMSK_THRESH);
fdp1_write(fdp1, FD1_IPC_COMB_DET_CONST, FD1_IPC_COMB_DET);
fdp1_write(fdp1, FD1_IPC_MOTDEC_CONST, FD1_IPC_MOTDEC);
fdp1_write(fdp1, FD1_IPC_DLI_BLEND_CONST, FD1_IPC_DLI_BLEND);
fdp1_write(fdp1, FD1_IPC_DLI_HGAIN_CONST, FD1_IPC_DLI_HGAIN);
fdp1_write(fdp1, FD1_IPC_DLI_SPRS_CONST, FD1_IPC_DLI_SPRS);
fdp1_write(fdp1, FD1_IPC_DLI_ANGLE_CONST, FD1_IPC_DLI_ANGLE);
fdp1_write(fdp1, FD1_IPC_DLI_ISOPIX0_CONST, FD1_IPC_DLI_ISOPIX0);
fdp1_write(fdp1, FD1_IPC_DLI_ISOPIX1_CONST, FD1_IPC_DLI_ISOPIX1);
}
static void fdp1_set_ipc_sensor(struct fdp1_ctx *ctx)
{
struct fdp1_dev *fdp1 = ctx->fdp1;
struct fdp1_q_data *src_q_data = &ctx->out_q;
unsigned int x0, x1;
unsigned int hsize = src_q_data->format.width;
unsigned int vsize = src_q_data->format.height;
x0 = hsize / 3;
x1 = 2 * hsize / 3;
fdp1_write(fdp1, FD1_IPC_SENSOR_TH0_CONST, FD1_IPC_SENSOR_TH0);
fdp1_write(fdp1, FD1_IPC_SENSOR_TH1_CONST, FD1_IPC_SENSOR_TH1);
fdp1_write(fdp1, FD1_IPC_SENSOR_CTL0_CONST, FD1_IPC_SENSOR_CTL0);
fdp1_write(fdp1, FD1_IPC_SENSOR_CTL1_CONST, FD1_IPC_SENSOR_CTL1);
fdp1_write(fdp1, ((hsize - 1) << FD1_IPC_SENSOR_CTL2_X_SHIFT) |
((vsize - 1) << FD1_IPC_SENSOR_CTL2_Y_SHIFT),
FD1_IPC_SENSOR_CTL2);
fdp1_write(fdp1, (x0 << FD1_IPC_SENSOR_CTL3_0_SHIFT) |
(x1 << FD1_IPC_SENSOR_CTL3_1_SHIFT),
FD1_IPC_SENSOR_CTL3);
}
static void fdp1_write_lut(struct fdp1_dev *fdp1, const u8 *lut,
unsigned int len, unsigned int base)
{
unsigned int i;
u8 pad;
len = min(len, 256u);
for (i = 0; i < len; i++)
fdp1_write(fdp1, lut[i], base + (i*4));
pad = lut[i-1];
for (; i < 256; i++)
fdp1_write(fdp1, pad, base + (i*4));
}
static void fdp1_set_lut(struct fdp1_dev *fdp1)
{
fdp1_write_lut(fdp1, fdp1_diff_adj, ARRAY_SIZE(fdp1_diff_adj),
FD1_LUT_DIF_ADJ);
fdp1_write_lut(fdp1, fdp1_sad_adj, ARRAY_SIZE(fdp1_sad_adj),
FD1_LUT_SAD_ADJ);
fdp1_write_lut(fdp1, fdp1_bld_gain, ARRAY_SIZE(fdp1_bld_gain),
FD1_LUT_BLD_GAIN);
fdp1_write_lut(fdp1, fdp1_dif_gain, ARRAY_SIZE(fdp1_dif_gain),
FD1_LUT_DIF_GAIN);
fdp1_write_lut(fdp1, fdp1_mdet, ARRAY_SIZE(fdp1_mdet),
FD1_LUT_MDET);
}
static void fdp1_configure_rpf(struct fdp1_ctx *ctx,
struct fdp1_job *job)
{
struct fdp1_dev *fdp1 = ctx->fdp1;
u32 picture_size;
u32 pstride;
u32 format;
u32 smsk_addr;
struct fdp1_q_data *q_data = &ctx->out_q;
picture_size = (q_data->format.width << FD1_RPF_SIZE_H_SHIFT)
| (q_data->vsize << FD1_RPF_SIZE_V_SHIFT);
pstride = q_data->stride_y << FD1_RPF_PSTRIDE_Y_SHIFT;
if (q_data->format.num_planes > 1)
pstride |= q_data->stride_c << FD1_RPF_PSTRIDE_C_SHIFT;
format = q_data->fmt->fmt;
if (q_data->fmt->swap_yc)
format |= FD1_RPF_FORMAT_RSPYCS;
if (q_data->fmt->swap_uv)
format |= FD1_RPF_FORMAT_RSPUVS;
if (job->active->field == V4L2_FIELD_BOTTOM) {
format |= FD1_RPF_FORMAT_CF;
smsk_addr = ctx->smsk_addr[0];
} else {
smsk_addr = ctx->smsk_addr[1];
}
if (ctx->deint_mode)
format |= FD1_RPF_FORMAT_CIPM;
fdp1_write(fdp1, format, FD1_RPF_FORMAT);
fdp1_write(fdp1, q_data->fmt->swap, FD1_RPF_SWAP);
fdp1_write(fdp1, picture_size, FD1_RPF_SIZE);
fdp1_write(fdp1, pstride, FD1_RPF_PSTRIDE);
fdp1_write(fdp1, smsk_addr, FD1_RPF_SMSK_ADDR);
if (job->previous)
fdp1_write(fdp1, job->previous->addrs[0], FD1_RPF0_ADDR_Y);
fdp1_write(fdp1, job->active->addrs[0], FD1_RPF1_ADDR_Y);
fdp1_write(fdp1, job->active->addrs[1], FD1_RPF1_ADDR_C0);
fdp1_write(fdp1, job->active->addrs[2], FD1_RPF1_ADDR_C1);
if (job->next)
fdp1_write(fdp1, job->next->addrs[0], FD1_RPF2_ADDR_Y);
}
static void fdp1_configure_wpf(struct fdp1_ctx *ctx,
struct fdp1_job *job)
{
struct fdp1_dev *fdp1 = ctx->fdp1;
struct fdp1_q_data *src_q_data = &ctx->out_q;
struct fdp1_q_data *q_data = &ctx->cap_q;
u32 pstride;
u32 format;
u32 swap;
u32 rndctl;
pstride = q_data->format.plane_fmt[0].bytesperline
<< FD1_WPF_PSTRIDE_Y_SHIFT;
if (q_data->format.num_planes > 1)
pstride |= q_data->format.plane_fmt[1].bytesperline
<< FD1_WPF_PSTRIDE_C_SHIFT;
format = q_data->fmt->fmt;
if (q_data->fmt->swap_yc)
format |= FD1_WPF_FORMAT_WSPYCS;
if (q_data->fmt->swap_uv)
format |= FD1_WPF_FORMAT_WSPUVS;
if (fdp1_fmt_is_rgb(q_data->fmt)) {
format |= FD1_WPF_FORMAT_CSC;
if (src_q_data->format.ycbcr_enc == V4L2_YCBCR_ENC_709)
format |= FD1_WPF_FORMAT_WRTM_709_16;
else if (src_q_data->format.quantization ==
V4L2_QUANTIZATION_FULL_RANGE)
format |= FD1_WPF_FORMAT_WRTM_601_0;
else
format |= FD1_WPF_FORMAT_WRTM_601_16;
}
format |= ctx->alpha << FD1_WPF_FORMAT_PDV_SHIFT;
rndctl = FD1_WPF_RNDCTL_CBRM;
rndctl |= FD1_WPF_RNDCTL_CLMD_NOCLIP;
swap = q_data->fmt->swap << FD1_WPF_SWAP_OSWAP_SHIFT;
swap |= src_q_data->fmt->swap << FD1_WPF_SWAP_SSWAP_SHIFT;
fdp1_write(fdp1, format, FD1_WPF_FORMAT);
fdp1_write(fdp1, rndctl, FD1_WPF_RNDCTL);
fdp1_write(fdp1, swap, FD1_WPF_SWAP);
fdp1_write(fdp1, pstride, FD1_WPF_PSTRIDE);
fdp1_write(fdp1, job->dst->addrs[0], FD1_WPF_ADDR_Y);
fdp1_write(fdp1, job->dst->addrs[1], FD1_WPF_ADDR_C0);
fdp1_write(fdp1, job->dst->addrs[2], FD1_WPF_ADDR_C1);
}
static void fdp1_configure_deint_mode(struct fdp1_ctx *ctx,
struct fdp1_job *job)
{
struct fdp1_dev *fdp1 = ctx->fdp1;
u32 opmode = FD1_CTL_OPMODE_VIMD_NOINTERRUPT;
u32 ipcmode = FD1_IPC_MODE_DLI;
u32 channels = FD1_CTL_CHACT_WR | FD1_CTL_CHACT_RD1;
switch (ctx->deint_mode) {
default:
case FDP1_PROGRESSIVE:
dprintk(fdp1, "Progressive Mode\n");
opmode |= FD1_CTL_OPMODE_PRG;
ipcmode |= FD1_IPC_MODE_DIM_FIXED2D;
break;
case FDP1_ADAPT2D3D:
dprintk(fdp1, "Adapt2D3D Mode\n");
if (ctx->sequence == 0 || ctx->aborting)
ipcmode |= FD1_IPC_MODE_DIM_FIXED2D;
else
ipcmode |= FD1_IPC_MODE_DIM_ADAPT2D3D;
if (ctx->sequence > 1) {
channels |= FD1_CTL_CHACT_SMW;
channels |= FD1_CTL_CHACT_RD0 | FD1_CTL_CHACT_RD2;
}
if (ctx->sequence > 2)
channels |= FD1_CTL_CHACT_SMR;
break;
case FDP1_FIXED3D:
dprintk(fdp1, "Fixed 3D Mode\n");
ipcmode |= FD1_IPC_MODE_DIM_FIXED3D;
if (!(ctx->sequence == 0 || ctx->aborting))
channels |= FD1_CTL_CHACT_RD0 | FD1_CTL_CHACT_RD2;
break;
case FDP1_FIXED2D:
dprintk(fdp1, "Fixed 2D Mode\n");
ipcmode |= FD1_IPC_MODE_DIM_FIXED2D;
break;
case FDP1_PREVFIELD:
dprintk(fdp1, "Previous Field Mode\n");
ipcmode |= FD1_IPC_MODE_DIM_PREVFIELD;
channels |= FD1_CTL_CHACT_RD0;
break;
case FDP1_NEXTFIELD:
dprintk(fdp1, "Next Field Mode\n");
ipcmode |= FD1_IPC_MODE_DIM_NEXTFIELD;
channels |= FD1_CTL_CHACT_RD2;
break;
}
fdp1_write(fdp1, channels, FD1_CTL_CHACT);
fdp1_write(fdp1, opmode, FD1_CTL_OPMODE);
fdp1_write(fdp1, ipcmode, FD1_IPC_MODE);
}
static int fdp1_device_process(struct fdp1_ctx *ctx)
{
struct fdp1_dev *fdp1 = ctx->fdp1;
struct fdp1_job *job;
unsigned long flags;
spin_lock_irqsave(&fdp1->device_process_lock, flags);
job = get_queued_job(fdp1);
if (!job) {
spin_unlock_irqrestore(&fdp1->device_process_lock, flags);
return 0;
}
fdp1_write(fdp1, FD1_CTL_CLKCTRL_CSTP_N, FD1_CTL_CLKCTRL);
fdp1_configure_deint_mode(ctx, job);
fdp1_set_ipc_dli(ctx);
fdp1_set_ipc_sensor(ctx);
fdp1_configure_rpf(ctx, job);
fdp1_configure_wpf(ctx, job);
fdp1_write(fdp1, FD1_IPC_LMEM_LINEAR, FD1_IPC_LMEM);
fdp1_write(fdp1, FD1_CTL_IRQ_MASK, FD1_CTL_IRQENB);
queue_hw_job(fdp1, job);
fdp1_write(fdp1, FD1_CTL_CMD_STRCMD, FD1_CTL_CMD);
fdp1_write(fdp1, FD1_CTL_REGEND_REGEND, FD1_CTL_REGEND);
fdp1_write(fdp1, FD1_CTL_SGCMD_SGEN, FD1_CTL_SGCMD);
spin_unlock_irqrestore(&fdp1->device_process_lock, flags);
return 0;
}
static int fdp1_m2m_job_ready(void *priv)
{
struct fdp1_ctx *ctx = priv;
struct fdp1_q_data *src_q_data = &ctx->out_q;
int srcbufs = 1;
int dstbufs = 1;
dprintk(ctx->fdp1, "+ Src: %d : Dst: %d\n",
v4l2_m2m_num_src_bufs_ready(ctx->fh.m2m_ctx),
v4l2_m2m_num_dst_bufs_ready(ctx->fh.m2m_ctx));
if (V4L2_FIELD_HAS_BOTH(src_q_data->format.field))
dstbufs = 2;
if (v4l2_m2m_num_src_bufs_ready(ctx->fh.m2m_ctx) < srcbufs
|| v4l2_m2m_num_dst_bufs_ready(ctx->fh.m2m_ctx) < dstbufs) {
dprintk(ctx->fdp1, "Not enough buffers available\n");
return 0;
}
return 1;
}
static void fdp1_m2m_job_abort(void *priv)
{
struct fdp1_ctx *ctx = priv;
dprintk(ctx->fdp1, "+\n");
ctx->aborting = 1;
fdp1_write(ctx->fdp1, 0, FD1_CTL_SGCMD);
fdp1_write(ctx->fdp1, FD1_CTL_SRESET_SRST, FD1_CTL_SRESET);
}
static struct fdp1_job *fdp1_prepare_job(struct fdp1_ctx *ctx)
{
struct vb2_v4l2_buffer *vbuf;
struct fdp1_buffer *fbuf;
struct fdp1_dev *fdp1 = ctx->fdp1;
struct fdp1_job *job;
unsigned int buffers_required = 1;
dprintk(fdp1, "+\n");
if (FDP1_DEINT_MODE_USES_NEXT(ctx->deint_mode))
buffers_required = 2;
if (ctx->buffers_queued < buffers_required)
return NULL;
job = fdp1_job_alloc(fdp1);
if (!job) {
dprintk(fdp1, "No free jobs currently available\n");
return NULL;
}
job->active = fdp1_dequeue_field(ctx);
if (!job->active) {
dprintk(fdp1, "No input buffers currently available\n");
fdp1_job_free(fdp1, job);
return NULL;
}
dprintk(fdp1, "+ Buffer en-route...\n");
vbuf = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx);
fbuf = to_fdp1_buffer(vbuf);
job->dst = &fbuf->fields[0];
job->active->vb->sequence = ctx->sequence;
job->dst->vb->sequence = ctx->sequence;
ctx->sequence++;
if (FDP1_DEINT_MODE_USES_PREV(ctx->deint_mode)) {
job->previous = ctx->previous;
ctx->previous = job->active;
}
if (FDP1_DEINT_MODE_USES_NEXT(ctx->deint_mode)) {
job->next = fdp1_peek_queued_field(ctx);
}
job->dst->vb->vb2_buf.timestamp = job->active->vb->vb2_buf.timestamp;
job->dst->vb->flags = job->active->vb->flags &
V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
ctx->translen++;
queue_job(fdp1, job);
dprintk(fdp1, "Job Queued translen = %d\n", ctx->translen);
return job;
}
static void fdp1_m2m_device_run(void *priv)
{
struct fdp1_ctx *ctx = priv;
struct fdp1_dev *fdp1 = ctx->fdp1;
struct vb2_v4l2_buffer *src_vb;
struct fdp1_buffer *buf;
unsigned int i;
dprintk(fdp1, "+\n");
ctx->translen = 0;
src_vb = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx);
buf = to_fdp1_buffer(src_vb);
for (i = 0; i < buf->num_fields; i++) {
struct fdp1_field_buffer *fbuf = &buf->fields[i];
fdp1_queue_field(ctx, fbuf);
dprintk(fdp1, "Queued Buffer [%d] last_field:%d\n",
i, fbuf->last_field);
}
while (fdp1_prepare_job(ctx))
;
if (ctx->translen == 0) {
dprintk(fdp1, "No jobs were processed. M2M action complete\n");
v4l2_m2m_job_finish(fdp1->m2m_dev, ctx->fh.m2m_ctx);
return;
}
fdp1_device_process(ctx);
}
static void device_frame_end(struct fdp1_dev *fdp1,
enum vb2_buffer_state state)
{
struct fdp1_ctx *ctx;
unsigned long flags;
struct fdp1_job *job = get_hw_queued_job(fdp1);
dprintk(fdp1, "+\n");
ctx = v4l2_m2m_get_curr_priv(fdp1->m2m_dev);
if (ctx == NULL) {
v4l2_err(&fdp1->v4l2_dev,
"Instance released before the end of transaction\n");
return;
}
ctx->num_processed++;
if (FDP1_DEINT_MODE_USES_PREV(ctx->deint_mode))
fdp1_field_complete(ctx, job->previous);
else
fdp1_field_complete(ctx, job->active);
spin_lock_irqsave(&fdp1->irqlock, flags);
v4l2_m2m_buf_done(job->dst->vb, state);
job->dst = NULL;
spin_unlock_irqrestore(&fdp1->irqlock, flags);
fdp1_job_free(fdp1, job);
dprintk(fdp1, "curr_ctx->num_processed %d curr_ctx->translen %d\n",
ctx->num_processed, ctx->translen);
if (ctx->num_processed == ctx->translen ||
ctx->aborting) {
dprintk(ctx->fdp1, "Finishing transaction\n");
ctx->num_processed = 0;
v4l2_m2m_job_finish(fdp1->m2m_dev, ctx->fh.m2m_ctx);
} else {
fdp1_device_process(ctx);
}
}
static int fdp1_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strlcpy(cap->driver, DRIVER_NAME, sizeof(cap->driver));
strlcpy(cap->card, DRIVER_NAME, sizeof(cap->card));
snprintf(cap->bus_info, sizeof(cap->bus_info),
"platform:%s", DRIVER_NAME);
return 0;
}
static int fdp1_enum_fmt(struct v4l2_fmtdesc *f, u32 type)
{
unsigned int i, num;
num = 0;
for (i = 0; i < ARRAY_SIZE(fdp1_formats); ++i) {
if (fdp1_formats[i].types & type) {
if (num == f->index)
break;
++num;
}
}
if (i >= ARRAY_SIZE(fdp1_formats))
return -EINVAL;
f->pixelformat = fdp1_formats[i].fourcc;
return 0;
}
static int fdp1_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return fdp1_enum_fmt(f, FDP1_CAPTURE);
}
static int fdp1_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return fdp1_enum_fmt(f, FDP1_OUTPUT);
}
static int fdp1_g_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct fdp1_q_data *q_data;
struct fdp1_ctx *ctx = fh_to_ctx(priv);
if (!v4l2_m2m_get_vq(ctx->fh.m2m_ctx, f->type))
return -EINVAL;
q_data = get_q_data(ctx, f->type);
f->fmt.pix_mp = q_data->format;
return 0;
}
static void fdp1_compute_stride(struct v4l2_pix_format_mplane *pix,
const struct fdp1_fmt *fmt)
{
unsigned int i;
for (i = 0; i < min_t(unsigned int, fmt->num_planes, 2U); ++i) {
unsigned int hsub = i > 0 ? fmt->hsub : 1;
unsigned int vsub = i > 0 ? fmt->vsub : 1;
unsigned int align = 128;
unsigned int bpl;
bpl = clamp_t(unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * fmt->bpp[i] / 8,
round_down(FDP1_MAX_STRIDE, align));
pix->plane_fmt[i].bytesperline = round_up(bpl, align);
pix->plane_fmt[i].sizeimage = pix->plane_fmt[i].bytesperline
* pix->height / vsub;
memset(pix->plane_fmt[i].reserved, 0,
sizeof(pix->plane_fmt[i].reserved));
}
if (fmt->num_planes == 3) {
pix->plane_fmt[2].bytesperline = pix->plane_fmt[1].bytesperline;
pix->plane_fmt[2].sizeimage = pix->plane_fmt[1].sizeimage;
memset(pix->plane_fmt[2].reserved, 0,
sizeof(pix->plane_fmt[2].reserved));
}
}
static void fdp1_try_fmt_output(struct fdp1_ctx *ctx,
const struct fdp1_fmt **fmtinfo,
struct v4l2_pix_format_mplane *pix)
{
const struct fdp1_fmt *fmt;
unsigned int width;
unsigned int height;
fmt = fdp1_find_format(pix->pixelformat);
if (!fmt || !(fmt->types & FDP1_OUTPUT))
fmt = fdp1_find_format(V4L2_PIX_FMT_YUYV);
if (fmtinfo)
*fmtinfo = fmt;
pix->pixelformat = fmt->fourcc;
pix->num_planes = fmt->num_planes;
if (pix->field != V4L2_FIELD_NONE &&
pix->field != V4L2_FIELD_ALTERNATE &&
!V4L2_FIELD_HAS_BOTH(pix->field))
pix->field = V4L2_FIELD_INTERLACED;
if (pix->colorspace == V4L2_COLORSPACE_DEFAULT)
pix->colorspace = V4L2_COLORSPACE_SMPTE170M;
width = round_down(pix->width, fmt->hsub);
pix->width = clamp(width, FDP1_MIN_W, FDP1_MAX_W);
height = round_down(pix->height, fmt->vsub);
if (pix->field == V4L2_FIELD_ALTERNATE)
pix->height = clamp(height, FDP1_MIN_H / 2, FDP1_MAX_H / 2);
else
pix->height = clamp(height, FDP1_MIN_H, FDP1_MAX_H);
fdp1_compute_stride(pix, fmt);
}
static void fdp1_try_fmt_capture(struct fdp1_ctx *ctx,
const struct fdp1_fmt **fmtinfo,
struct v4l2_pix_format_mplane *pix)
{
struct fdp1_q_data *src_data = &ctx->out_q;
enum v4l2_colorspace colorspace;
enum v4l2_ycbcr_encoding ycbcr_enc;
enum v4l2_quantization quantization;
const struct fdp1_fmt *fmt;
bool allow_rgb;
colorspace = src_data->format.colorspace;
ycbcr_enc = src_data->format.ycbcr_enc;
if (ycbcr_enc == V4L2_YCBCR_ENC_DEFAULT)
ycbcr_enc = V4L2_MAP_YCBCR_ENC_DEFAULT(colorspace);
quantization = src_data->format.quantization;
if (quantization == V4L2_QUANTIZATION_DEFAULT)
quantization = V4L2_MAP_QUANTIZATION_DEFAULT(false, colorspace,
ycbcr_enc);
allow_rgb = ycbcr_enc == V4L2_YCBCR_ENC_601 ||
(ycbcr_enc == V4L2_YCBCR_ENC_709 &&
quantization == V4L2_QUANTIZATION_LIM_RANGE);
fmt = fdp1_find_format(pix->pixelformat);
if (!fmt || (!allow_rgb && fdp1_fmt_is_rgb(fmt)))
fmt = fdp1_find_format(V4L2_PIX_FMT_YUYV);
if (fmtinfo)
*fmtinfo = fmt;
pix->pixelformat = fmt->fourcc;
pix->num_planes = fmt->num_planes;
pix->field = V4L2_FIELD_NONE;
pix->colorspace = src_data->format.colorspace;
pix->xfer_func = src_data->format.xfer_func;
if (fdp1_fmt_is_rgb(fmt)) {
pix->ycbcr_enc = V4L2_YCBCR_ENC_DEFAULT;
pix->quantization = V4L2_QUANTIZATION_DEFAULT;
} else {
pix->ycbcr_enc = src_data->format.ycbcr_enc;
pix->quantization = src_data->format.quantization;
}
pix->width = src_data->format.width;
if (src_data->format.field == V4L2_FIELD_ALTERNATE)
pix->height = 2 * src_data->format.height;
else
pix->height = src_data->format.height;
fdp1_compute_stride(pix, fmt);
}
static int fdp1_try_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct fdp1_ctx *ctx = fh_to_ctx(priv);
if (f->type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE)
fdp1_try_fmt_output(ctx, NULL, &f->fmt.pix_mp);
else
fdp1_try_fmt_capture(ctx, NULL, &f->fmt.pix_mp);
dprintk(ctx->fdp1, "Try %s format: %4.4s (0x%08x) %ux%u field %u\n",
V4L2_TYPE_IS_OUTPUT(f->type) ? "output" : "capture",
(char *)&f->fmt.pix_mp.pixelformat, f->fmt.pix_mp.pixelformat,
f->fmt.pix_mp.width, f->fmt.pix_mp.height, f->fmt.pix_mp.field);
return 0;
}
static void fdp1_set_format(struct fdp1_ctx *ctx,
struct v4l2_pix_format_mplane *pix,
enum v4l2_buf_type type)
{
struct fdp1_q_data *q_data = get_q_data(ctx, type);
const struct fdp1_fmt *fmtinfo;
if (type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE)
fdp1_try_fmt_output(ctx, &fmtinfo, pix);
else
fdp1_try_fmt_capture(ctx, &fmtinfo, pix);
q_data->fmt = fmtinfo;
q_data->format = *pix;
q_data->vsize = pix->height;
if (pix->field != V4L2_FIELD_NONE)
q_data->vsize /= 2;
q_data->stride_y = pix->plane_fmt[0].bytesperline;
q_data->stride_c = pix->plane_fmt[1].bytesperline;
if (pix->field == V4L2_FIELD_INTERLACED ||
pix->field == V4L2_FIELD_INTERLACED_TB ||
pix->field == V4L2_FIELD_INTERLACED_BT) {
q_data->stride_y *= 2;
q_data->stride_c *= 2;
}
if (type == V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE) {
struct fdp1_q_data *dst_data = &ctx->cap_q;
dst_data->format = q_data->format;
memset(dst_data->format.plane_fmt, 0,
sizeof(dst_data->format.plane_fmt));
dst_data->format.field = V4L2_FIELD_NONE;
if (pix->field == V4L2_FIELD_ALTERNATE)
dst_data->format.height *= 2;
fdp1_try_fmt_capture(ctx, &dst_data->fmt, &dst_data->format);
dst_data->vsize = dst_data->format.height;
dst_data->stride_y = dst_data->format.plane_fmt[0].bytesperline;
dst_data->stride_c = dst_data->format.plane_fmt[1].bytesperline;
}
}
static int fdp1_s_fmt(struct file *file, void *priv, struct v4l2_format *f)
{
struct fdp1_ctx *ctx = fh_to_ctx(priv);
struct v4l2_m2m_ctx *m2m_ctx = ctx->fh.m2m_ctx;
struct vb2_queue *vq = v4l2_m2m_get_vq(m2m_ctx, f->type);
if (vb2_is_busy(vq)) {
v4l2_err(&ctx->fdp1->v4l2_dev, "%s queue busy\n", __func__);
return -EBUSY;
}
fdp1_set_format(ctx, &f->fmt.pix_mp, f->type);
dprintk(ctx->fdp1, "Set %s format: %4.4s (0x%08x) %ux%u field %u\n",
V4L2_TYPE_IS_OUTPUT(f->type) ? "output" : "capture",
(char *)&f->fmt.pix_mp.pixelformat, f->fmt.pix_mp.pixelformat,
f->fmt.pix_mp.width, f->fmt.pix_mp.height, f->fmt.pix_mp.field);
return 0;
}
static int fdp1_g_ctrl(struct v4l2_ctrl *ctrl)
{
struct fdp1_ctx *ctx =
container_of(ctrl->handler, struct fdp1_ctx, hdl);
struct fdp1_q_data *src_q_data = &ctx->out_q;
switch (ctrl->id) {
case V4L2_CID_MIN_BUFFERS_FOR_CAPTURE:
if (V4L2_FIELD_HAS_BOTH(src_q_data->format.field))
ctrl->val = 2;
else
ctrl->val = 1;
return 0;
}
return 1;
}
static int fdp1_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct fdp1_ctx *ctx =
container_of(ctrl->handler, struct fdp1_ctx, hdl);
switch (ctrl->id) {
case V4L2_CID_ALPHA_COMPONENT:
ctx->alpha = ctrl->val;
break;
case V4L2_CID_DEINTERLACING_MODE:
ctx->deint_mode = ctrl->val;
break;
}
return 0;
}
static int fdp1_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[],
struct device *alloc_ctxs[])
{
struct fdp1_ctx *ctx = vb2_get_drv_priv(vq);
struct fdp1_q_data *q_data;
unsigned int i;
q_data = get_q_data(ctx, vq->type);
if (*nplanes) {
if (*nplanes > FDP1_MAX_PLANES)
return -EINVAL;
return 0;
}
*nplanes = q_data->format.num_planes;
for (i = 0; i < *nplanes; i++)
sizes[i] = q_data->format.plane_fmt[i].sizeimage;
return 0;
}
static void fdp1_buf_prepare_field(struct fdp1_q_data *q_data,
struct vb2_v4l2_buffer *vbuf,
unsigned int field_num)
{
struct fdp1_buffer *buf = to_fdp1_buffer(vbuf);
struct fdp1_field_buffer *fbuf = &buf->fields[field_num];
unsigned int num_fields;
unsigned int i;
num_fields = V4L2_FIELD_HAS_BOTH(vbuf->field) ? 2 : 1;
fbuf->vb = vbuf;
fbuf->last_field = (field_num + 1) == num_fields;
for (i = 0; i < vbuf->vb2_buf.num_planes; ++i)
fbuf->addrs[i] = vb2_dma_contig_plane_dma_addr(&vbuf->vb2_buf, i);
switch (vbuf->field) {
case V4L2_FIELD_INTERLACED:
fbuf->field = (q_data->format.height < 576) == field_num
? V4L2_FIELD_TOP : V4L2_FIELD_BOTTOM;
break;
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_SEQ_TB:
fbuf->field = field_num ? V4L2_FIELD_BOTTOM : V4L2_FIELD_TOP;
break;
case V4L2_FIELD_INTERLACED_BT:
case V4L2_FIELD_SEQ_BT:
fbuf->field = field_num ? V4L2_FIELD_TOP : V4L2_FIELD_BOTTOM;
break;
default:
fbuf->field = vbuf->field;
break;
}
if (!field_num)
return;
switch (vbuf->field) {
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
for (i = 0; i < vbuf->vb2_buf.num_planes; i++)
fbuf->addrs[i] +=
(i == 0 ? q_data->stride_y : q_data->stride_c);
break;
case V4L2_FIELD_SEQ_TB:
case V4L2_FIELD_SEQ_BT:
for (i = 0; i < vbuf->vb2_buf.num_planes; i++)
fbuf->addrs[i] += q_data->vsize *
(i == 0 ? q_data->stride_y : q_data->stride_c);
break;
}
}
static int fdp1_buf_prepare(struct vb2_buffer *vb)
{
struct fdp1_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct fdp1_q_data *q_data = get_q_data(ctx, vb->vb2_queue->type);
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct fdp1_buffer *buf = to_fdp1_buffer(vbuf);
unsigned int i;
if (V4L2_TYPE_IS_OUTPUT(vb->vb2_queue->type)) {
bool field_valid = true;
switch (q_data->format.field) {
case V4L2_FIELD_NONE:
if (vbuf->field != V4L2_FIELD_NONE)
field_valid = false;
break;
case V4L2_FIELD_ALTERNATE:
if (vbuf->field != V4L2_FIELD_TOP &&
vbuf->field != V4L2_FIELD_BOTTOM)
field_valid = false;
break;
case V4L2_FIELD_INTERLACED:
case V4L2_FIELD_SEQ_TB:
case V4L2_FIELD_SEQ_BT:
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_INTERLACED_BT:
if (vbuf->field != q_data->format.field)
field_valid = false;
break;
}
if (!field_valid) {
dprintk(ctx->fdp1,
"buffer field %u invalid for format field %u\n",
vbuf->field, q_data->format.field);
return -EINVAL;
}
} else {
vbuf->field = V4L2_FIELD_NONE;
}
for (i = 0; i < q_data->format.num_planes; i++) {
unsigned long size = q_data->format.plane_fmt[i].sizeimage;
if (vb2_plane_size(vb, i) < size) {
dprintk(ctx->fdp1,
"data will not fit into plane [%u/%u] (%lu < %lu)\n",
i, q_data->format.num_planes,
vb2_plane_size(vb, i), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, i, size);
}
buf->num_fields = V4L2_FIELD_HAS_BOTH(vbuf->field) ? 2 : 1;
for (i = 0; i < buf->num_fields; ++i)
fdp1_buf_prepare_field(q_data, vbuf, i);
return 0;
}
static void fdp1_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct fdp1_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
v4l2_m2m_buf_queue(ctx->fh.m2m_ctx, vbuf);
}
static int fdp1_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct fdp1_ctx *ctx = vb2_get_drv_priv(q);
struct fdp1_q_data *q_data = get_q_data(ctx, q->type);
if (V4L2_TYPE_IS_OUTPUT(q->type)) {
if (q_data->format.field == V4L2_FIELD_NONE)
ctx->deint_mode = FDP1_PROGRESSIVE;
if (ctx->deint_mode == FDP1_ADAPT2D3D) {
u32 stride;
dma_addr_t smsk_base;
const u32 bpp = 2;
stride = round_up(q_data->format.width, 8);
ctx->smsk_size = bpp * stride * q_data->vsize;
ctx->smsk_cpu = dma_alloc_coherent(ctx->fdp1->dev,
ctx->smsk_size, &smsk_base, GFP_KERNEL);
if (ctx->smsk_cpu == NULL) {
dprintk(ctx->fdp1, "Failed to alloc smsk\n");
return -ENOMEM;
}
ctx->smsk_addr[0] = smsk_base;
ctx->smsk_addr[1] = smsk_base + (ctx->smsk_size/2);
}
}
return 0;
}
static void fdp1_stop_streaming(struct vb2_queue *q)
{
struct fdp1_ctx *ctx = vb2_get_drv_priv(q);
struct vb2_v4l2_buffer *vbuf;
unsigned long flags;
while (1) {
if (V4L2_TYPE_IS_OUTPUT(q->type))
vbuf = v4l2_m2m_src_buf_remove(ctx->fh.m2m_ctx);
else
vbuf = v4l2_m2m_dst_buf_remove(ctx->fh.m2m_ctx);
if (vbuf == NULL)
break;
spin_lock_irqsave(&ctx->fdp1->irqlock, flags);
v4l2_m2m_buf_done(vbuf, VB2_BUF_STATE_ERROR);
spin_unlock_irqrestore(&ctx->fdp1->irqlock, flags);
}
if (V4L2_TYPE_IS_OUTPUT(q->type)) {
struct fdp1_field_buffer *fbuf;
fbuf = fdp1_dequeue_field(ctx);
while (fbuf != NULL) {
fdp1_field_complete(ctx, fbuf);
fbuf = fdp1_dequeue_field(ctx);
}
if (ctx->smsk_cpu) {
dma_free_coherent(ctx->fdp1->dev, ctx->smsk_size,
ctx->smsk_cpu, ctx->smsk_addr[0]);
ctx->smsk_addr[0] = ctx->smsk_addr[1] = 0;
ctx->smsk_cpu = NULL;
}
WARN(!list_empty(&ctx->fields_queue),
"Buffer queue not empty");
} else {
struct fdp1_job *job;
job = get_queued_job(ctx->fdp1);
while (job) {
if (FDP1_DEINT_MODE_USES_PREV(ctx->deint_mode))
fdp1_field_complete(ctx, job->previous);
else
fdp1_field_complete(ctx, job->active);
v4l2_m2m_buf_done(job->dst->vb, VB2_BUF_STATE_ERROR);
job->dst = NULL;
job = get_queued_job(ctx->fdp1);
}
fdp1_field_complete(ctx, ctx->previous);
WARN(!list_empty(&ctx->fdp1->queued_job_list),
"Queued Job List not empty");
WARN(!list_empty(&ctx->fdp1->hw_job_list),
"HW Job list not empty");
}
}
static int queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
struct fdp1_ctx *ctx = priv;
int ret;
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE;
src_vq->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
src_vq->drv_priv = ctx;
src_vq->buf_struct_size = sizeof(struct fdp1_buffer);
src_vq->ops = &fdp1_qops;
src_vq->mem_ops = &vb2_dma_contig_memops;
src_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
src_vq->lock = &ctx->fdp1->dev_mutex;
src_vq->dev = ctx->fdp1->dev;
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
dst_vq->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF;
dst_vq->drv_priv = ctx;
dst_vq->buf_struct_size = sizeof(struct fdp1_buffer);
dst_vq->ops = &fdp1_qops;
dst_vq->mem_ops = &vb2_dma_contig_memops;
dst_vq->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_COPY;
dst_vq->lock = &ctx->fdp1->dev_mutex;
dst_vq->dev = ctx->fdp1->dev;
return vb2_queue_init(dst_vq);
}
static int fdp1_open(struct file *file)
{
struct fdp1_dev *fdp1 = video_drvdata(file);
struct v4l2_pix_format_mplane format;
struct fdp1_ctx *ctx = NULL;
struct v4l2_ctrl *ctrl;
int ret = 0;
if (mutex_lock_interruptible(&fdp1->dev_mutex))
return -ERESTARTSYS;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
ret = -ENOMEM;
goto done;
}
v4l2_fh_init(&ctx->fh, video_devdata(file));
file->private_data = &ctx->fh;
ctx->fdp1 = fdp1;
INIT_LIST_HEAD(&ctx->fields_queue);
ctx->translen = 1;
ctx->sequence = 0;
v4l2_ctrl_handler_init(&ctx->hdl, 3);
v4l2_ctrl_new_std_menu_items(&ctx->hdl, &fdp1_ctrl_ops,
V4L2_CID_DEINTERLACING_MODE,
FDP1_NEXTFIELD, BIT(0), FDP1_FIXED3D,
fdp1_ctrl_deint_menu);
ctrl = v4l2_ctrl_new_std(&ctx->hdl, &fdp1_ctrl_ops,
V4L2_CID_MIN_BUFFERS_FOR_CAPTURE, 1, 2, 1, 1);
if (ctrl)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;
v4l2_ctrl_new_std(&ctx->hdl, &fdp1_ctrl_ops,
V4L2_CID_ALPHA_COMPONENT, 0, 255, 1, 255);
if (ctx->hdl.error) {
ret = ctx->hdl.error;
v4l2_ctrl_handler_free(&ctx->hdl);
goto done;
}
ctx->fh.ctrl_handler = &ctx->hdl;
v4l2_ctrl_handler_setup(&ctx->hdl);
memset(&format, 0, sizeof(format));
fdp1_set_format(ctx, &format, V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE);
ctx->fh.m2m_ctx = v4l2_m2m_ctx_init(fdp1->m2m_dev, ctx, &queue_init);
if (IS_ERR(ctx->fh.m2m_ctx)) {
ret = PTR_ERR(ctx->fh.m2m_ctx);
v4l2_ctrl_handler_free(&ctx->hdl);
kfree(ctx);
goto done;
}
pm_runtime_get_sync(fdp1->dev);
v4l2_fh_add(&ctx->fh);
dprintk(fdp1, "Created instance: %p, m2m_ctx: %p\n",
ctx, ctx->fh.m2m_ctx);
done:
mutex_unlock(&fdp1->dev_mutex);
return ret;
}
static int fdp1_release(struct file *file)
{
struct fdp1_dev *fdp1 = video_drvdata(file);
struct fdp1_ctx *ctx = fh_to_ctx(file->private_data);
dprintk(fdp1, "Releasing instance %p\n", ctx);
v4l2_fh_del(&ctx->fh);
v4l2_fh_exit(&ctx->fh);
v4l2_ctrl_handler_free(&ctx->hdl);
mutex_lock(&fdp1->dev_mutex);
v4l2_m2m_ctx_release(ctx->fh.m2m_ctx);
mutex_unlock(&fdp1->dev_mutex);
kfree(ctx);
pm_runtime_put(fdp1->dev);
return 0;
}
static irqreturn_t fdp1_irq_handler(int irq, void *dev_id)
{
struct fdp1_dev *fdp1 = dev_id;
u32 int_status;
u32 ctl_status;
u32 vint_cnt;
u32 cycles;
int_status = fdp1_read(fdp1, FD1_CTL_IRQSTA);
cycles = fdp1_read(fdp1, FD1_CTL_VCYCLE_STAT);
ctl_status = fdp1_read(fdp1, FD1_CTL_STATUS);
vint_cnt = (ctl_status & FD1_CTL_STATUS_VINT_CNT_MASK) >>
FD1_CTL_STATUS_VINT_CNT_SHIFT;
fdp1_write(fdp1, ~(int_status) & FD1_CTL_IRQ_MASK, FD1_CTL_IRQSTA);
if (debug >= 2) {
dprintk(fdp1, "IRQ: 0x%x %s%s%s\n", int_status,
int_status & FD1_CTL_IRQ_VERE ? "[Error]" : "[!E]",
int_status & FD1_CTL_IRQ_VINTE ? "[VSync]" : "[!V]",
int_status & FD1_CTL_IRQ_FREE ? "[FrameEnd]" : "[!F]");
dprintk(fdp1, "CycleStatus = %d (%dms)\n",
cycles, cycles/(fdp1->clk_rate/1000));
dprintk(fdp1,
"Control Status = 0x%08x : VINT_CNT = %d %s:%s:%s:%s\n",
ctl_status, vint_cnt,
ctl_status & FD1_CTL_STATUS_SGREGSET ? "RegSet" : "",
ctl_status & FD1_CTL_STATUS_SGVERR ? "Vsync Error" : "",
ctl_status & FD1_CTL_STATUS_SGFREND ? "FrameEnd" : "",
ctl_status & FD1_CTL_STATUS_BSY ? "Busy" : "");
dprintk(fdp1, "***********************************\n");
}
if (!(FD1_CTL_IRQ_MASK & int_status))
return IRQ_NONE;
if (FD1_CTL_IRQ_VERE & int_status)
device_frame_end(fdp1, VB2_BUF_STATE_ERROR);
else if (FD1_CTL_IRQ_FREE & int_status)
device_frame_end(fdp1, VB2_BUF_STATE_DONE);
return IRQ_HANDLED;
}
static int fdp1_probe(struct platform_device *pdev)
{
struct fdp1_dev *fdp1;
struct video_device *vfd;
struct device_node *fcp_node;
struct resource *res;
struct clk *clk;
unsigned int i;
int ret;
int hw_version;
fdp1 = devm_kzalloc(&pdev->dev, sizeof(*fdp1), GFP_KERNEL);
if (!fdp1)
return -ENOMEM;
INIT_LIST_HEAD(&fdp1->free_job_list);
INIT_LIST_HEAD(&fdp1->queued_job_list);
INIT_LIST_HEAD(&fdp1->hw_job_list);
for (i = 0; i < ARRAY_SIZE(fdp1->jobs); i++)
list_add(&fdp1->jobs[i].list, &fdp1->free_job_list);
mutex_init(&fdp1->dev_mutex);
spin_lock_init(&fdp1->irqlock);
spin_lock_init(&fdp1->device_process_lock);
fdp1->dev = &pdev->dev;
platform_set_drvdata(pdev, fdp1);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fdp1->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fdp1->regs))
return PTR_ERR(fdp1->regs);
fdp1->irq = ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "cannot find IRQ\n");
return ret;
}
ret = devm_request_irq(&pdev->dev, fdp1->irq, fdp1_irq_handler, 0,
dev_name(&pdev->dev), fdp1);
if (ret) {
dev_err(&pdev->dev, "cannot claim IRQ %d\n", fdp1->irq);
return ret;
}
fcp_node = of_parse_phandle(pdev->dev.of_node, "renesas,fcp", 0);
if (fcp_node) {
fdp1->fcp = rcar_fcp_get(fcp_node);
of_node_put(fcp_node);
if (IS_ERR(fdp1->fcp)) {
dev_err(&pdev->dev, "FCP not found (%ld)\n",
PTR_ERR(fdp1->fcp));
return PTR_ERR(fdp1->fcp);
}
}
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
fdp1->clk_rate = clk_get_rate(clk);
clk_put(clk);
ret = v4l2_device_register(&pdev->dev, &fdp1->v4l2_dev);
if (ret) {
v4l2_err(&fdp1->v4l2_dev, "Failed to register video device\n");
return ret;
}
fdp1->m2m_dev = v4l2_m2m_init(&m2m_ops);
if (IS_ERR(fdp1->m2m_dev)) {
v4l2_err(&fdp1->v4l2_dev, "Failed to init mem2mem device\n");
ret = PTR_ERR(fdp1->m2m_dev);
goto unreg_dev;
}
fdp1->vfd = fdp1_videodev;
vfd = &fdp1->vfd;
vfd->lock = &fdp1->dev_mutex;
vfd->v4l2_dev = &fdp1->v4l2_dev;
video_set_drvdata(vfd, fdp1);
strlcpy(vfd->name, fdp1_videodev.name, sizeof(vfd->name));
ret = video_register_device(vfd, VFL_TYPE_GRABBER, 0);
if (ret) {
v4l2_err(&fdp1->v4l2_dev, "Failed to register video device\n");
goto release_m2m;
}
v4l2_info(&fdp1->v4l2_dev,
"Device registered as /dev/video%d\n", vfd->num);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(fdp1->dev);
hw_version = fdp1_read(fdp1, FD1_IP_INTDATA);
switch (hw_version) {
case FD1_IP_H3:
dprintk(fdp1, "FDP1 Version R-Car H3\n");
break;
case FD1_IP_M3W:
dprintk(fdp1, "FDP1 Version R-Car M3-W\n");
break;
default:
dev_err(fdp1->dev, "FDP1 Unidentifiable (0x%08x)\n",
hw_version);
}
pm_runtime_put(fdp1->dev);
return 0;
release_m2m:
v4l2_m2m_release(fdp1->m2m_dev);
unreg_dev:
v4l2_device_unregister(&fdp1->v4l2_dev);
return ret;
}
static int fdp1_remove(struct platform_device *pdev)
{
struct fdp1_dev *fdp1 = platform_get_drvdata(pdev);
v4l2_m2m_release(fdp1->m2m_dev);
video_unregister_device(&fdp1->vfd);
v4l2_device_unregister(&fdp1->v4l2_dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __maybe_unused fdp1_pm_runtime_suspend(struct device *dev)
{
struct fdp1_dev *fdp1 = dev_get_drvdata(dev);
rcar_fcp_disable(fdp1->fcp);
return 0;
}
static int __maybe_unused fdp1_pm_runtime_resume(struct device *dev)
{
struct fdp1_dev *fdp1 = dev_get_drvdata(dev);
fdp1_set_lut(fdp1);
return rcar_fcp_enable(fdp1->fcp);
}
