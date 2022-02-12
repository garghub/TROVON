static int vpif_buffer_prepare(struct vb2_buffer *vb)
{
struct vpif_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_queue *q = vb->vb2_queue;
struct common_obj *common;
unsigned long addr;
common = &fh->channel->common[VPIF_VIDEO_INDEX];
if (vb->state != VB2_BUF_STATE_ACTIVE &&
vb->state != VB2_BUF_STATE_PREPARED) {
vb2_set_plane_payload(vb, 0, common->fmt.fmt.pix.sizeimage);
if (vb2_plane_vaddr(vb, 0) &&
vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0))
goto buf_align_exit;
addr = vb2_dma_contig_plane_dma_addr(vb, 0);
if (q->streaming &&
(V4L2_BUF_TYPE_SLICED_VBI_OUTPUT != q->type)) {
if (!ISALIGNED(addr + common->ytop_off) ||
!ISALIGNED(addr + common->ybtm_off) ||
!ISALIGNED(addr + common->ctop_off) ||
!ISALIGNED(addr + common->cbtm_off))
goto buf_align_exit;
}
}
return 0;
buf_align_exit:
vpif_err("buffer offset not aligned to 8 bytes\n");
return -EINVAL;
}
static int vpif_buffer_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct vpif_fh *fh = vb2_get_drv_priv(vq);
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
unsigned long size;
if (V4L2_MEMORY_MMAP == common->memory) {
size = config_params.channel_bufsize[ch->channel_id];
if (ch->vpifparams.std_info.ycmux_mode == 0) {
if (config_params.video_limit[ch->channel_id])
while (size * *nbuffers >
(config_params.video_limit[0]
+ config_params.video_limit[1]))
(*nbuffers)--;
} else {
if (config_params.video_limit[ch->channel_id])
while (size * *nbuffers >
config_params.video_limit[ch->channel_id])
(*nbuffers)--;
}
} else {
size = common->fmt.fmt.pix.sizeimage;
}
if (*nbuffers < config_params.min_numbuffers)
*nbuffers = config_params.min_numbuffers;
*nplanes = 1;
sizes[0] = size;
alloc_ctxs[0] = common->alloc_ctx;
return 0;
}
static void vpif_buffer_queue(struct vb2_buffer *vb)
{
struct vpif_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vpif_disp_buffer *buf = container_of(vb,
struct vpif_disp_buffer, vb);
struct channel_obj *ch = fh->channel;
struct common_obj *common;
unsigned long flags;
common = &ch->common[VPIF_VIDEO_INDEX];
spin_lock_irqsave(&common->irqlock, flags);
list_add_tail(&buf->list, &common->dma_queue);
spin_unlock_irqrestore(&common->irqlock, flags);
}
static void vpif_buf_cleanup(struct vb2_buffer *vb)
{
struct vpif_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vpif_disp_buffer *buf = container_of(vb,
struct vpif_disp_buffer, vb);
struct channel_obj *ch = fh->channel;
struct common_obj *common;
unsigned long flags;
common = &ch->common[VPIF_VIDEO_INDEX];
spin_lock_irqsave(&common->irqlock, flags);
if (vb->state == VB2_BUF_STATE_ACTIVE)
list_del_init(&buf->list);
spin_unlock_irqrestore(&common->irqlock, flags);
}
static void vpif_wait_prepare(struct vb2_queue *vq)
{
struct vpif_fh *fh = vb2_get_drv_priv(vq);
struct channel_obj *ch = fh->channel;
struct common_obj *common;
common = &ch->common[VPIF_VIDEO_INDEX];
mutex_unlock(&common->lock);
}
static void vpif_wait_finish(struct vb2_queue *vq)
{
struct vpif_fh *fh = vb2_get_drv_priv(vq);
struct channel_obj *ch = fh->channel;
struct common_obj *common;
common = &ch->common[VPIF_VIDEO_INDEX];
mutex_lock(&common->lock);
}
static int vpif_buffer_init(struct vb2_buffer *vb)
{
struct vpif_disp_buffer *buf = container_of(vb,
struct vpif_disp_buffer, vb);
INIT_LIST_HEAD(&buf->list);
return 0;
}
static int vpif_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vpif_display_config *vpif_config_data =
vpif_dev->platform_data;
struct vpif_fh *fh = vb2_get_drv_priv(vq);
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_params *vpif = &ch->vpifparams;
unsigned long addr = 0;
unsigned long flags;
int ret;
spin_lock_irqsave(&common->irqlock, flags);
common->next_frm = common->cur_frm =
list_entry(common->dma_queue.next,
struct vpif_disp_buffer, list);
list_del(&common->cur_frm->list);
spin_unlock_irqrestore(&common->irqlock, flags);
common->cur_frm->vb.state = VB2_BUF_STATE_ACTIVE;
ch->field_id = 0;
common->started = 1;
addr = vb2_dma_contig_plane_dma_addr(&common->cur_frm->vb, 0);
vpif_calculate_offsets(ch);
if ((ch->vpifparams.std_info.frm_fmt &&
((common->fmt.fmt.pix.field != V4L2_FIELD_NONE)
&& (common->fmt.fmt.pix.field != V4L2_FIELD_ANY)))
|| (!ch->vpifparams.std_info.frm_fmt
&& (common->fmt.fmt.pix.field == V4L2_FIELD_NONE))) {
vpif_err("conflict in field format and std format\n");
return -EINVAL;
}
if (vpif_config_data->set_clock) {
ret = vpif_config_data->set_clock(ch->vpifparams.std_info.
ycmux_mode, ch->vpifparams.std_info.hd_sd);
if (ret < 0) {
vpif_err("can't set clock\n");
return ret;
}
}
ret = vpif_set_video_params(vpif, ch->channel_id + 2);
if (ret < 0)
return ret;
common->started = ret;
vpif_config_addr(ch, ret);
common->set_addr((addr + common->ytop_off),
(addr + common->ybtm_off),
(addr + common->ctop_off),
(addr + common->cbtm_off));
channel_first_int[VPIF_VIDEO_INDEX][ch->channel_id] = 1;
if (VPIF_CHANNEL2_VIDEO == ch->channel_id) {
channel2_intr_assert();
channel2_intr_enable(1);
enable_channel2(1);
if (vpif_config_data->chan_config[VPIF_CHANNEL2_VIDEO].clip_en)
channel2_clipping_enable(1);
}
if ((VPIF_CHANNEL3_VIDEO == ch->channel_id)
|| (common->started == 2)) {
channel3_intr_assert();
channel3_intr_enable(1);
enable_channel3(1);
if (vpif_config_data->chan_config[VPIF_CHANNEL3_VIDEO].clip_en)
channel3_clipping_enable(1);
}
return 0;
}
static int vpif_stop_streaming(struct vb2_queue *vq)
{
struct vpif_fh *fh = vb2_get_drv_priv(vq);
struct channel_obj *ch = fh->channel;
struct common_obj *common;
unsigned long flags;
if (!vb2_is_streaming(vq))
return 0;
common = &ch->common[VPIF_VIDEO_INDEX];
if (VPIF_CHANNEL2_VIDEO == ch->channel_id) {
enable_channel2(0);
channel2_intr_enable(0);
}
if ((VPIF_CHANNEL3_VIDEO == ch->channel_id) ||
(2 == common->started)) {
enable_channel3(0);
channel3_intr_enable(0);
}
common->started = 0;
spin_lock_irqsave(&common->irqlock, flags);
if (common->cur_frm == common->next_frm) {
vb2_buffer_done(&common->cur_frm->vb, VB2_BUF_STATE_ERROR);
} else {
if (common->cur_frm != NULL)
vb2_buffer_done(&common->cur_frm->vb,
VB2_BUF_STATE_ERROR);
if (common->next_frm != NULL)
vb2_buffer_done(&common->next_frm->vb,
VB2_BUF_STATE_ERROR);
}
while (!list_empty(&common->dma_queue)) {
common->next_frm = list_entry(common->dma_queue.next,
struct vpif_disp_buffer, list);
list_del(&common->next_frm->list);
vb2_buffer_done(&common->next_frm->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&common->irqlock, flags);
return 0;
}
static void process_progressive_mode(struct common_obj *common)
{
unsigned long addr = 0;
spin_lock(&common->irqlock);
common->next_frm = list_entry(common->dma_queue.next,
struct vpif_disp_buffer, list);
list_del(&common->next_frm->list);
spin_unlock(&common->irqlock);
common->next_frm->vb.state = VB2_BUF_STATE_ACTIVE;
addr = vb2_dma_contig_plane_dma_addr(&common->next_frm->vb, 0);
common->set_addr(addr + common->ytop_off,
addr + common->ybtm_off,
addr + common->ctop_off,
addr + common->cbtm_off);
}
static void process_interlaced_mode(int fid, struct common_obj *common)
{
if (0 == fid) {
if (common->cur_frm == common->next_frm)
return;
v4l2_get_timestamp(&common->cur_frm->vb.v4l2_buf.timestamp);
vb2_buffer_done(&common->cur_frm->vb,
VB2_BUF_STATE_DONE);
common->cur_frm = common->next_frm;
} else if (1 == fid) {
spin_lock(&common->irqlock);
if (list_empty(&common->dma_queue)
|| (common->cur_frm != common->next_frm)) {
spin_unlock(&common->irqlock);
return;
}
spin_unlock(&common->irqlock);
process_progressive_mode(common);
}
}
static irqreturn_t vpif_channel_isr(int irq, void *dev_id)
{
struct vpif_device *dev = &vpif_obj;
struct channel_obj *ch;
struct common_obj *common;
enum v4l2_field field;
int fid = -1, i;
int channel_id = 0;
channel_id = *(int *)(dev_id);
if (!vpif_intr_status(channel_id + 2))
return IRQ_NONE;
ch = dev->dev[channel_id];
field = ch->common[VPIF_VIDEO_INDEX].fmt.fmt.pix.field;
for (i = 0; i < VPIF_NUMOBJECTS; i++) {
common = &ch->common[i];
if (0 == common->started)
continue;
if (1 == ch->vpifparams.std_info.frm_fmt) {
spin_lock(&common->irqlock);
if (list_empty(&common->dma_queue)) {
spin_unlock(&common->irqlock);
continue;
}
spin_unlock(&common->irqlock);
if (!channel_first_int[i][channel_id]) {
v4l2_get_timestamp(&common->cur_frm->vb.
v4l2_buf.timestamp);
vb2_buffer_done(&common->cur_frm->vb,
VB2_BUF_STATE_DONE);
common->cur_frm = common->next_frm;
}
channel_first_int[i][channel_id] = 0;
process_progressive_mode(common);
} else {
if (channel_first_int[i][channel_id]) {
channel_first_int[i][channel_id] = 0;
continue;
}
if (0 == i) {
ch->field_id ^= 1;
fid = vpif_channel_getfid(ch->channel_id + 2);
if (fid != ch->field_id) {
if (0 == fid)
ch->field_id = fid;
return IRQ_HANDLED;
}
}
process_interlaced_mode(fid, common);
}
}
return IRQ_HANDLED;
}
static int vpif_update_std_info(struct channel_obj *ch)
{
struct video_obj *vid_ch = &ch->video;
struct vpif_params *vpifparams = &ch->vpifparams;
struct vpif_channel_config_params *std_info = &vpifparams->std_info;
const struct vpif_channel_config_params *config;
int i;
for (i = 0; i < vpif_ch_params_count; i++) {
config = &vpif_ch_params[i];
if (config->hd_sd == 0) {
vpif_dbg(2, debug, "SD format\n");
if (config->stdid & vid_ch->stdid) {
memcpy(std_info, config, sizeof(*config));
break;
}
}
}
if (i == vpif_ch_params_count) {
vpif_dbg(1, debug, "Format not found\n");
return -EINVAL;
}
return 0;
}
static int vpif_update_resolution(struct channel_obj *ch)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct video_obj *vid_ch = &ch->video;
struct vpif_params *vpifparams = &ch->vpifparams;
struct vpif_channel_config_params *std_info = &vpifparams->std_info;
if (!vid_ch->stdid && !vid_ch->dv_timings.bt.height)
return -EINVAL;
if (vid_ch->stdid) {
if (vpif_update_std_info(ch))
return -EINVAL;
}
common->fmt.fmt.pix.width = std_info->width;
common->fmt.fmt.pix.height = std_info->height;
vpif_dbg(1, debug, "Pixel details: Width = %d,Height = %d\n",
common->fmt.fmt.pix.width, common->fmt.fmt.pix.height);
common->height = std_info->height;
common->width = std_info->width;
return 0;
}
static void vpif_calculate_offsets(struct channel_obj *ch)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_params *vpifparams = &ch->vpifparams;
enum v4l2_field field = common->fmt.fmt.pix.field;
struct video_obj *vid_ch = &ch->video;
unsigned int hpitch, vpitch, sizeimage;
if (V4L2_FIELD_ANY == common->fmt.fmt.pix.field) {
if (ch->vpifparams.std_info.frm_fmt)
vid_ch->buf_field = V4L2_FIELD_NONE;
else
vid_ch->buf_field = V4L2_FIELD_INTERLACED;
} else {
vid_ch->buf_field = common->fmt.fmt.pix.field;
}
sizeimage = common->fmt.fmt.pix.sizeimage;
hpitch = common->fmt.fmt.pix.bytesperline;
vpitch = sizeimage / (hpitch * 2);
if ((V4L2_FIELD_NONE == vid_ch->buf_field) ||
(V4L2_FIELD_INTERLACED == vid_ch->buf_field)) {
common->ytop_off = 0;
common->ybtm_off = hpitch;
common->ctop_off = sizeimage / 2;
common->cbtm_off = sizeimage / 2 + hpitch;
} else if (V4L2_FIELD_SEQ_TB == vid_ch->buf_field) {
common->ytop_off = 0;
common->ybtm_off = sizeimage / 4;
common->ctop_off = sizeimage / 2;
common->cbtm_off = common->ctop_off + sizeimage / 4;
} else if (V4L2_FIELD_SEQ_BT == vid_ch->buf_field) {
common->ybtm_off = 0;
common->ytop_off = sizeimage / 4;
common->cbtm_off = sizeimage / 2;
common->ctop_off = common->cbtm_off + sizeimage / 4;
}
if ((V4L2_FIELD_NONE == vid_ch->buf_field) ||
(V4L2_FIELD_INTERLACED == vid_ch->buf_field)) {
vpifparams->video_params.storage_mode = 1;
} else {
vpifparams->video_params.storage_mode = 0;
}
if (ch->vpifparams.std_info.frm_fmt == 1) {
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline;
} else {
if ((field == V4L2_FIELD_ANY) ||
(field == V4L2_FIELD_INTERLACED))
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline * 2;
else
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline;
}
ch->vpifparams.video_params.stdid = ch->vpifparams.std_info.stdid;
}
static void vpif_config_format(struct channel_obj *ch)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
common->fmt.fmt.pix.field = V4L2_FIELD_ANY;
if (config_params.numbuffers[ch->channel_id] == 0)
common->memory = V4L2_MEMORY_USERPTR;
else
common->memory = V4L2_MEMORY_MMAP;
common->fmt.fmt.pix.sizeimage =
config_params.channel_bufsize[ch->channel_id];
common->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV422P;
common->fmt.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
}
static int vpif_check_format(struct channel_obj *ch,
struct v4l2_pix_format *pixfmt)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
enum v4l2_field field = pixfmt->field;
u32 sizeimage, hpitch, vpitch;
if (pixfmt->pixelformat != V4L2_PIX_FMT_YUV422P)
goto invalid_fmt_exit;
if (!(VPIF_VALID_FIELD(field)))
goto invalid_fmt_exit;
if (pixfmt->bytesperline <= 0)
goto invalid_pitch_exit;
sizeimage = pixfmt->sizeimage;
if (vpif_update_resolution(ch))
return -EINVAL;
hpitch = pixfmt->bytesperline;
vpitch = sizeimage / (hpitch * 2);
if ((hpitch < ch->vpifparams.std_info.width) ||
(vpitch < ch->vpifparams.std_info.height))
goto invalid_pitch_exit;
if (!ISALIGNED(hpitch)) {
vpif_err("invalid pitch alignment\n");
return -EINVAL;
}
pixfmt->width = common->fmt.fmt.pix.width;
pixfmt->height = common->fmt.fmt.pix.height;
return 0;
invalid_fmt_exit:
vpif_err("invalid field format\n");
return -EINVAL;
invalid_pitch_exit:
vpif_err("invalid pitch\n");
return -EINVAL;
}
static void vpif_config_addr(struct channel_obj *ch, int muxmode)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (VPIF_CHANNEL3_VIDEO == ch->channel_id) {
common->set_addr = ch3_set_videobuf_addr;
} else {
if (2 == muxmode)
common->set_addr = ch2_set_videobuf_addr_yc_nmux;
else
common->set_addr = ch2_set_videobuf_addr;
}
}
static int vpif_mmap(struct file *filep, struct vm_area_struct *vma)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &(ch->common[VPIF_VIDEO_INDEX]);
int ret;
vpif_dbg(2, debug, "vpif_mmap\n");
if (mutex_lock_interruptible(&common->lock))
return -ERESTARTSYS;
ret = vb2_mmap(&common->buffer_queue, vma);
mutex_unlock(&common->lock);
return ret;
}
static unsigned int vpif_poll(struct file *filep, poll_table *wait)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
unsigned int res = 0;
if (common->started) {
mutex_lock(&common->lock);
res = vb2_poll(&common->buffer_queue, filep, wait);
mutex_unlock(&common->lock);
}
return res;
}
static int vpif_open(struct file *filep)
{
struct video_device *vdev = video_devdata(filep);
struct channel_obj *ch = video_get_drvdata(vdev);
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_fh *fh;
fh = kzalloc(sizeof(struct vpif_fh), GFP_KERNEL);
if (fh == NULL) {
vpif_err("unable to allocate memory for file handle object\n");
return -ENOMEM;
}
if (mutex_lock_interruptible(&common->lock)) {
kfree(fh);
return -ERESTARTSYS;
}
filep->private_data = fh;
fh->channel = ch;
fh->initialized = 0;
if (!ch->initialized) {
fh->initialized = 1;
ch->initialized = 1;
memset(&ch->vpifparams, 0, sizeof(ch->vpifparams));
}
atomic_inc(&ch->usrs);
fh->io_allowed[VPIF_VIDEO_INDEX] = 0;
fh->prio = V4L2_PRIORITY_UNSET;
v4l2_prio_open(&ch->prio, &fh->prio);
mutex_unlock(&common->lock);
return 0;
}
static int vpif_release(struct file *filep)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
mutex_lock(&common->lock);
if (fh->io_allowed[VPIF_VIDEO_INDEX]) {
common->io_usrs = 0;
vb2_queue_release(&common->buffer_queue);
vb2_dma_contig_cleanup_ctx(common->alloc_ctx);
common->numbuffers =
config_params.numbuffers[ch->channel_id];
}
atomic_dec(&ch->usrs);
if (fh->initialized)
ch->initialized = 0;
v4l2_prio_close(&ch->prio, fh->prio);
filep->private_data = NULL;
fh->initialized = 0;
mutex_unlock(&common->lock);
kfree(fh);
return 0;
}
static int vpif_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vpif_display_config *config = vpif_dev->platform_data;
cap->device_caps = V4L2_CAP_VIDEO_OUTPUT | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
snprintf(cap->driver, sizeof(cap->driver), "%s", dev_name(vpif_dev));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(vpif_dev));
strlcpy(cap->card, config->card_name, sizeof(cap->card));
return 0;
}
static int vpif_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
if (fmt->index != 0) {
vpif_err("Invalid format index\n");
return -EINVAL;
}
fmt->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
strcpy(fmt->description, "YCbCr4:2:2 YC Planar");
fmt->pixelformat = V4L2_PIX_FMT_YUV422P;
return 0;
}
static int vpif_g_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (common->fmt.type != fmt->type)
return -EINVAL;
if (vpif_update_resolution(ch))
return -EINVAL;
*fmt = common->fmt;
return 0;
}
static int vpif_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpif_fh *fh = priv;
struct v4l2_pix_format *pixfmt;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret = 0;
if ((VPIF_CHANNEL2_VIDEO == ch->channel_id)
|| (VPIF_CHANNEL3_VIDEO == ch->channel_id)) {
if (!fh->initialized) {
vpif_dbg(1, debug, "Channel Busy\n");
return -EBUSY;
}
ret = v4l2_prio_check(&ch->prio, fh->prio);
if (0 != ret)
return ret;
fh->initialized = 1;
}
if (common->started) {
vpif_dbg(1, debug, "Streaming in progress\n");
return -EBUSY;
}
pixfmt = &fmt->fmt.pix;
ret = vpif_check_format(ch, pixfmt);
if (ret)
return ret;
common->fmt.fmt.pix = *pixfmt;
common->fmt = *fmt;
return 0;
}
static int vpif_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct v4l2_pix_format *pixfmt = &fmt->fmt.pix;
int ret = 0;
ret = vpif_check_format(ch, pixfmt);
if (ret) {
*pixfmt = common->fmt.fmt.pix;
pixfmt->sizeimage = pixfmt->width * pixfmt->height * 2;
}
return ret;
}
static int vpif_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *reqbuf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
enum v4l2_field field;
struct vb2_queue *q;
u8 index = 0;
int ret;
if ((VPIF_CHANNEL2_VIDEO == ch->channel_id)
|| (VPIF_CHANNEL3_VIDEO == ch->channel_id)) {
if (!fh->initialized) {
vpif_err("Channel Busy\n");
return -EBUSY;
}
}
if (V4L2_BUF_TYPE_VIDEO_OUTPUT != reqbuf->type)
return -EINVAL;
index = VPIF_VIDEO_INDEX;
common = &ch->common[index];
if (common->fmt.type != reqbuf->type || !vpif_dev)
return -EINVAL;
if (0 != common->io_usrs)
return -EBUSY;
if (reqbuf->type == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
if (common->fmt.fmt.pix.field == V4L2_FIELD_ANY)
field = V4L2_FIELD_INTERLACED;
else
field = common->fmt.fmt.pix.field;
} else {
field = V4L2_VBI_INTERLACED;
}
common->alloc_ctx = vb2_dma_contig_init_ctx(vpif_dev);
if (IS_ERR(common->alloc_ctx)) {
vpif_err("Failed to get the context\n");
return PTR_ERR(common->alloc_ctx);
}
q = &common->buffer_queue;
q->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
q->io_modes = VB2_MMAP | VB2_USERPTR;
q->drv_priv = fh;
q->ops = &video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct vpif_disp_buffer);
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 1;
ret = vb2_queue_init(q);
if (ret) {
vpif_err("vpif_display: vb2_queue_init() failed\n");
vb2_dma_contig_cleanup_ctx(common->alloc_ctx);
return ret;
}
fh->io_allowed[index] = 1;
common->io_usrs = 1;
common->memory = reqbuf->memory;
INIT_LIST_HEAD(&common->dma_queue);
return vb2_reqbufs(&common->buffer_queue, reqbuf);
}
static int vpif_querybuf(struct file *file, void *priv,
struct v4l2_buffer *tbuf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (common->fmt.type != tbuf->type)
return -EINVAL;
return vb2_querybuf(&common->buffer_queue, tbuf);
}
static int vpif_qbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct vpif_fh *fh = NULL;
struct channel_obj *ch = NULL;
struct common_obj *common = NULL;
if (!buf || !priv)
return -EINVAL;
fh = priv;
ch = fh->channel;
if (!ch)
return -EINVAL;
common = &(ch->common[VPIF_VIDEO_INDEX]);
if (common->fmt.type != buf->type)
return -EINVAL;
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_err("fh->io_allowed\n");
return -EACCES;
}
return vb2_qbuf(&common->buffer_queue, buf);
}
static int vpif_s_std(struct file *file, void *priv, v4l2_std_id std_id)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret = 0;
if (!(std_id & VPIF_V4L2_STD))
return -EINVAL;
if (common->started) {
vpif_err("streaming in progress\n");
return -EBUSY;
}
ch->video.stdid = std_id;
memset(&ch->video.dv_timings, 0, sizeof(ch->video.dv_timings));
if (vpif_update_resolution(ch))
return -EINVAL;
if ((ch->vpifparams.std_info.width *
ch->vpifparams.std_info.height * 2) >
config_params.channel_bufsize[ch->channel_id]) {
vpif_err("invalid std for this size\n");
return -EINVAL;
}
common->fmt.fmt.pix.bytesperline = common->fmt.fmt.pix.width;
vpif_config_format(ch);
ret = v4l2_device_call_until_err(&vpif_obj.v4l2_dev, 1, video,
s_std_output, std_id);
if (ret < 0) {
vpif_err("Failed to set output standard\n");
return ret;
}
ret = v4l2_device_call_until_err(&vpif_obj.v4l2_dev, 1, core,
s_std, std_id);
if (ret < 0)
vpif_err("Failed to set standard for sub devices\n");
return ret;
}
static int vpif_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
*std = ch->video.stdid;
return 0;
}
static int vpif_dqbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
return vb2_dqbuf(&common->buffer_queue, p,
(file->f_flags & O_NONBLOCK));
}
static int vpif_streamon(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct channel_obj *oth_ch = vpif_obj.dev[!ch->channel_id];
int ret = 0;
if (buftype != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
vpif_err("buffer type not supported\n");
return -EINVAL;
}
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_err("fh->io_allowed\n");
return -EACCES;
}
if (common->started) {
vpif_err("channel->started\n");
return -EBUSY;
}
if ((ch->channel_id == VPIF_CHANNEL2_VIDEO
&& oth_ch->common[VPIF_VIDEO_INDEX].started &&
ch->vpifparams.std_info.ycmux_mode == 0)
|| ((ch->channel_id == VPIF_CHANNEL3_VIDEO)
&& (2 == oth_ch->common[VPIF_VIDEO_INDEX].started))) {
vpif_err("other channel is using\n");
return -EBUSY;
}
ret = vpif_check_format(ch, &common->fmt.fmt.pix);
if (ret < 0)
return ret;
ret = vb2_streamon(&common->buffer_queue, buftype);
if (ret < 0) {
vpif_err("vb2_streamon\n");
return ret;
}
return ret;
}
static int vpif_streamoff(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_display_config *vpif_config_data =
vpif_dev->platform_data;
if (buftype != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
vpif_err("buffer type not supported\n");
return -EINVAL;
}
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_err("fh->io_allowed\n");
return -EACCES;
}
if (!common->started) {
vpif_err("channel->started\n");
return -EINVAL;
}
if (buftype == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
if (VPIF_CHANNEL2_VIDEO == ch->channel_id) {
if (vpif_config_data->
chan_config[VPIF_CHANNEL2_VIDEO].clip_en)
channel2_clipping_enable(0);
enable_channel2(0);
channel2_intr_enable(0);
}
if ((VPIF_CHANNEL3_VIDEO == ch->channel_id) ||
(2 == common->started)) {
if (vpif_config_data->
chan_config[VPIF_CHANNEL3_VIDEO].clip_en)
channel3_clipping_enable(0);
enable_channel3(0);
channel3_intr_enable(0);
}
}
common->started = 0;
return vb2_streamoff(&common->buffer_queue, buftype);
}
static int vpif_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *crop)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (V4L2_BUF_TYPE_VIDEO_OUTPUT != crop->type)
return -EINVAL;
crop->bounds.left = crop->bounds.top = 0;
crop->defrect.left = crop->defrect.top = 0;
crop->defrect.height = crop->bounds.height = common->height;
crop->defrect.width = crop->bounds.width = common->width;
return 0;
}
static int vpif_enum_output(struct file *file, void *fh,
struct v4l2_output *output)
{
struct vpif_display_config *config = vpif_dev->platform_data;
struct vpif_display_chan_config *chan_cfg;
struct vpif_fh *vpif_handler = fh;
struct channel_obj *ch = vpif_handler->channel;
chan_cfg = &config->chan_config[ch->channel_id];
if (output->index >= chan_cfg->output_count) {
vpif_dbg(1, debug, "Invalid output index\n");
return -EINVAL;
}
*output = chan_cfg->outputs[output->index].output;
return 0;
}
static int
vpif_output_to_subdev(struct vpif_display_config *vpif_cfg,
struct vpif_display_chan_config *chan_cfg, int index)
{
struct vpif_subdev_info *subdev_info;
const char *subdev_name;
int i;
vpif_dbg(2, debug, "vpif_output_to_subdev\n");
if (chan_cfg->outputs == NULL)
return -1;
subdev_name = chan_cfg->outputs[index].subdev_name;
if (subdev_name == NULL)
return -1;
for (i = 0; i < vpif_cfg->subdev_count; i++) {
subdev_info = &vpif_cfg->subdevinfo[i];
if (!strcmp(subdev_info->name, subdev_name))
return i;
}
return -1;
}
static int vpif_set_output(struct vpif_display_config *vpif_cfg,
struct channel_obj *ch, int index)
{
struct vpif_display_chan_config *chan_cfg =
&vpif_cfg->chan_config[ch->channel_id];
struct vpif_subdev_info *subdev_info = NULL;
struct v4l2_subdev *sd = NULL;
u32 input = 0, output = 0;
int sd_index;
int ret;
sd_index = vpif_output_to_subdev(vpif_cfg, chan_cfg, index);
if (sd_index >= 0) {
sd = vpif_obj.sd[sd_index];
subdev_info = &vpif_cfg->subdevinfo[sd_index];
}
if (sd) {
input = chan_cfg->outputs[index].input_route;
output = chan_cfg->outputs[index].output_route;
ret = v4l2_subdev_call(sd, video, s_routing, input, output, 0);
if (ret < 0 && ret != -ENOIOCTLCMD) {
vpif_err("Failed to set output\n");
return ret;
}
}
ch->output_idx = index;
ch->sd = sd;
if (chan_cfg->outputs != NULL)
ch->video_dev->tvnorms = chan_cfg->outputs[index].output.std;
return 0;
}
static int vpif_s_output(struct file *file, void *priv, unsigned int i)
{
struct vpif_display_config *config = vpif_dev->platform_data;
struct vpif_display_chan_config *chan_cfg;
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
chan_cfg = &config->chan_config[ch->channel_id];
if (i >= chan_cfg->output_count)
return -EINVAL;
if (common->started) {
vpif_err("Streaming in progress\n");
return -EBUSY;
}
return vpif_set_output(config, ch, i);
}
static int vpif_g_output(struct file *file, void *priv, unsigned int *i)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
*i = ch->output_idx;
return 0;
}
static int vpif_g_priority(struct file *file, void *priv, enum v4l2_priority *p)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
*p = v4l2_prio_max(&ch->prio);
return 0;
}
static int vpif_s_priority(struct file *file, void *priv, enum v4l2_priority p)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
return v4l2_prio_change(&ch->prio, &fh->prio, p);
}
static int
vpif_enum_dv_timings(struct file *file, void *priv,
struct v4l2_enum_dv_timings *timings)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
int ret;
ret = v4l2_subdev_call(ch->sd, video, enum_dv_timings, timings);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
return -EINVAL;
return ret;
}
static int vpif_s_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct vpif_params *vpifparams = &ch->vpifparams;
struct vpif_channel_config_params *std_info = &vpifparams->std_info;
struct video_obj *vid_ch = &ch->video;
struct v4l2_bt_timings *bt = &vid_ch->dv_timings.bt;
int ret;
if (timings->type != V4L2_DV_BT_656_1120) {
vpif_dbg(2, debug, "Timing type not defined\n");
return -EINVAL;
}
ret = v4l2_subdev_call(ch->sd, video, s_dv_timings, timings);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
ret = 0;
if (ret < 0) {
vpif_dbg(2, debug, "Error setting custom DV timings\n");
return ret;
}
if (!(timings->bt.width && timings->bt.height &&
(timings->bt.hbackporch ||
timings->bt.hfrontporch ||
timings->bt.hsync) &&
timings->bt.vfrontporch &&
(timings->bt.vbackporch ||
timings->bt.vsync))) {
vpif_dbg(2, debug, "Timings for width, height, "
"horizontal back porch, horizontal sync, "
"horizontal front porch, vertical back porch, "
"vertical sync and vertical back porch "
"must be defined\n");
return -EINVAL;
}
vid_ch->dv_timings = *timings;
std_info->eav2sav = V4L2_DV_BT_BLANKING_WIDTH(bt) - 8;
std_info->sav2eav = bt->width;
std_info->l1 = 1;
std_info->l3 = bt->vsync + bt->vbackporch + 1;
std_info->vsize = V4L2_DV_BT_FRAME_HEIGHT(bt);
if (bt->interlaced) {
if (bt->il_vbackporch || bt->il_vfrontporch || bt->il_vsync) {
std_info->l5 = std_info->vsize/2 -
(bt->vfrontporch - 1);
std_info->l7 = std_info->vsize/2 + 1;
std_info->l9 = std_info->l7 + bt->il_vsync +
bt->il_vbackporch + 1;
std_info->l11 = std_info->vsize -
(bt->il_vfrontporch - 1);
} else {
vpif_dbg(2, debug, "Required timing values for "
"interlaced BT format missing\n");
return -EINVAL;
}
} else {
std_info->l5 = std_info->vsize - (bt->vfrontporch - 1);
}
strncpy(std_info->name, "Custom timings BT656/1120",
VPIF_MAX_NAME);
std_info->width = bt->width;
std_info->height = bt->height;
std_info->frm_fmt = bt->interlaced ? 0 : 1;
std_info->ycmux_mode = 0;
std_info->capture_format = 0;
std_info->vbi_supported = 0;
std_info->hd_sd = 1;
std_info->stdid = 0;
vid_ch->stdid = 0;
return 0;
}
static int vpif_g_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct video_obj *vid_ch = &ch->video;
*timings = vid_ch->dv_timings;
return 0;
}
static int vpif_log_status(struct file *filep, void *priv)
{
v4l2_device_call_all(&vpif_obj.v4l2_dev, 0, core, log_status);
return 0;
}
static int initialize_vpif(void)
{
int free_channel_objects_index;
int free_buffer_channel_index;
int free_buffer_index;
int err = 0, i, j;
if ((ch2_numbuffers > 0) &&
(ch2_numbuffers < config_params.min_numbuffers))
ch2_numbuffers = config_params.min_numbuffers;
if ((ch3_numbuffers > 0) &&
(ch3_numbuffers < config_params.min_numbuffers))
ch3_numbuffers = config_params.min_numbuffers;
if (ch2_bufsize < config_params.min_bufsize[VPIF_CHANNEL2_VIDEO])
ch2_bufsize =
config_params.min_bufsize[VPIF_CHANNEL2_VIDEO];
if (ch3_bufsize < config_params.min_bufsize[VPIF_CHANNEL3_VIDEO])
ch3_bufsize =
config_params.min_bufsize[VPIF_CHANNEL3_VIDEO];
config_params.numbuffers[VPIF_CHANNEL2_VIDEO] = ch2_numbuffers;
if (ch2_numbuffers) {
config_params.channel_bufsize[VPIF_CHANNEL2_VIDEO] =
ch2_bufsize;
}
config_params.numbuffers[VPIF_CHANNEL3_VIDEO] = ch3_numbuffers;
if (ch3_numbuffers) {
config_params.channel_bufsize[VPIF_CHANNEL3_VIDEO] =
ch3_bufsize;
}
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++) {
vpif_obj.dev[i] =
kzalloc(sizeof(struct channel_obj), GFP_KERNEL);
if (!vpif_obj.dev[i]) {
free_channel_objects_index = i;
err = -ENOMEM;
goto vpif_init_free_channel_objects;
}
}
free_channel_objects_index = VPIF_DISPLAY_MAX_DEVICES;
free_buffer_channel_index = VPIF_DISPLAY_NUM_CHANNELS;
free_buffer_index = config_params.numbuffers[i - 1];
return 0;
vpif_init_free_channel_objects:
for (j = 0; j < free_channel_objects_index; j++)
kfree(vpif_obj.dev[j]);
return err;
}
static int vpif_async_bound(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *subdev,
struct v4l2_async_subdev *asd)
{
int i;
for (i = 0; i < vpif_obj.config->subdev_count; i++)
if (!strcmp(vpif_obj.config->subdevinfo[i].name,
subdev->name)) {
vpif_obj.sd[i] = subdev;
vpif_obj.sd[i]->grp_id = 1 << i;
return 0;
}
return -EINVAL;
}
static int vpif_probe_complete(void)
{
struct common_obj *common;
struct channel_obj *ch;
int j, err, k;
for (j = 0; j < VPIF_DISPLAY_MAX_DEVICES; j++) {
ch = vpif_obj.dev[j];
atomic_set(&ch->usrs, 0);
for (k = 0; k < VPIF_NUMOBJECTS; k++) {
ch->common[k].numbuffers = 0;
common = &ch->common[k];
common->io_usrs = 0;
common->started = 0;
spin_lock_init(&common->irqlock);
mutex_init(&common->lock);
common->numbuffers = 0;
common->set_addr = NULL;
common->ytop_off = 0;
common->ybtm_off = 0;
common->ctop_off = 0;
common->cbtm_off = 0;
common->cur_frm = NULL;
common->next_frm = NULL;
memset(&common->fmt, 0, sizeof(common->fmt));
common->numbuffers = config_params.numbuffers[k];
}
ch->initialized = 0;
if (vpif_obj.config->subdev_count)
ch->sd = vpif_obj.sd[0];
ch->channel_id = j;
if (j < 2)
ch->common[VPIF_VIDEO_INDEX].numbuffers =
config_params.numbuffers[ch->channel_id];
else
ch->common[VPIF_VIDEO_INDEX].numbuffers = 0;
memset(&ch->vpifparams, 0, sizeof(ch->vpifparams));
v4l2_prio_init(&ch->prio);
ch->common[VPIF_VIDEO_INDEX].fmt.type =
V4L2_BUF_TYPE_VIDEO_OUTPUT;
ch->video_dev->lock = &common->lock;
video_set_drvdata(ch->video_dev, ch);
err = vpif_set_output(vpif_obj.config, ch, 0);
if (err)
goto probe_out;
vpif_dbg(1, debug, "channel=%x,channel->video_dev=%x\n",
(int)ch, (int)&ch->video_dev);
err = video_register_device(ch->video_dev,
VFL_TYPE_GRABBER, (j ? 3 : 2));
if (err < 0)
goto probe_out;
}
return 0;
probe_out:
for (k = 0; k < j; k++) {
ch = vpif_obj.dev[k];
video_unregister_device(ch->video_dev);
video_device_release(ch->video_dev);
ch->video_dev = NULL;
}
return err;
}
static int vpif_async_complete(struct v4l2_async_notifier *notifier)
{
return vpif_probe_complete();
}
static __init int vpif_probe(struct platform_device *pdev)
{
struct vpif_subdev_info *subdevdata;
int i, j = 0, err = 0;
int res_idx = 0;
struct i2c_adapter *i2c_adap;
struct channel_obj *ch;
struct video_device *vfd;
struct resource *res;
int subdev_count;
size_t size;
vpif_dev = &pdev->dev;
err = initialize_vpif();
if (err) {
v4l2_err(vpif_dev->driver, "Error initializing vpif\n");
return err;
}
err = v4l2_device_register(vpif_dev, &vpif_obj.v4l2_dev);
if (err) {
v4l2_err(vpif_dev->driver, "Error registering v4l2 device\n");
return err;
}
while ((res = platform_get_resource(pdev, IORESOURCE_IRQ, res_idx))) {
err = devm_request_irq(&pdev->dev, res->start, vpif_channel_isr,
IRQF_SHARED, "VPIF_Display",
(void *)(&vpif_obj.dev[res_idx]->
channel_id));
if (err) {
err = -EINVAL;
vpif_err("VPIF IRQ request failed\n");
goto vpif_unregister;
}
res_idx++;
}
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
vfd = video_device_alloc();
if (vfd == NULL) {
for (j = 0; j < i; j++) {
ch = vpif_obj.dev[j];
video_device_release(ch->video_dev);
}
err = -ENOMEM;
goto vpif_unregister;
}
*vfd = vpif_video_template;
vfd->v4l2_dev = &vpif_obj.v4l2_dev;
vfd->release = video_device_release;
vfd->vfl_dir = VFL_DIR_TX;
snprintf(vfd->name, sizeof(vfd->name),
"VPIF_Display_DRIVER_V%s",
VPIF_DISPLAY_VERSION);
ch->video_dev = vfd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res) {
size = resource_size(res);
for (j = 0; j < VPIF_DISPLAY_MAX_DEVICES; j++) {
ch = vpif_obj.dev[j];
ch->channel_id = j;
config_params.video_limit[ch->channel_id] = 0;
if (size)
config_params.video_limit[ch->channel_id] =
size/2;
}
}
vpif_obj.config = pdev->dev.platform_data;
subdev_count = vpif_obj.config->subdev_count;
subdevdata = vpif_obj.config->subdevinfo;
vpif_obj.sd = kzalloc(sizeof(struct v4l2_subdev *) * subdev_count,
GFP_KERNEL);
if (vpif_obj.sd == NULL) {
vpif_err("unable to allocate memory for subdevice pointers\n");
err = -ENOMEM;
goto vpif_sd_error;
}
if (!vpif_obj.config->asd_sizes) {
i2c_adap = i2c_get_adapter(1);
for (i = 0; i < subdev_count; i++) {
vpif_obj.sd[i] =
v4l2_i2c_new_subdev_board(&vpif_obj.v4l2_dev,
i2c_adap,
&subdevdata[i].
board_info,
NULL);
if (!vpif_obj.sd[i]) {
vpif_err("Error registering v4l2 subdevice\n");
err = -ENODEV;
goto probe_subdev_out;
}
if (vpif_obj.sd[i])
vpif_obj.sd[i]->grp_id = 1 << i;
}
vpif_probe_complete();
} else {
vpif_obj.notifier.subdevs = vpif_obj.config->asd;
vpif_obj.notifier.num_subdevs = vpif_obj.config->asd_sizes[0];
vpif_obj.notifier.bound = vpif_async_bound;
vpif_obj.notifier.complete = vpif_async_complete;
err = v4l2_async_notifier_register(&vpif_obj.v4l2_dev,
&vpif_obj.notifier);
if (err) {
vpif_err("Error registering async notifier\n");
err = -EINVAL;
goto probe_subdev_out;
}
}
return 0;
probe_subdev_out:
kfree(vpif_obj.sd);
vpif_sd_error:
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
video_device_release(ch->video_dev);
}
vpif_unregister:
v4l2_device_unregister(&vpif_obj.v4l2_dev);
return err;
}
static int vpif_remove(struct platform_device *device)
{
struct channel_obj *ch;
int i;
v4l2_device_unregister(&vpif_obj.v4l2_dev);
kfree(vpif_obj.sd);
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
video_unregister_device(ch->video_dev);
ch->video_dev = NULL;
kfree(vpif_obj.dev[i]);
}
return 0;
}
static int vpif_suspend(struct device *dev)
{
struct common_obj *common;
struct channel_obj *ch;
int i;
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
common = &ch->common[VPIF_VIDEO_INDEX];
mutex_lock(&common->lock);
if (atomic_read(&ch->usrs) && common->io_usrs) {
if (ch->channel_id == VPIF_CHANNEL2_VIDEO) {
enable_channel2(0);
channel2_intr_enable(0);
}
if (ch->channel_id == VPIF_CHANNEL3_VIDEO ||
common->started == 2) {
enable_channel3(0);
channel3_intr_enable(0);
}
}
mutex_unlock(&common->lock);
}
return 0;
}
static int vpif_resume(struct device *dev)
{
struct common_obj *common;
struct channel_obj *ch;
int i;
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
common = &ch->common[VPIF_VIDEO_INDEX];
mutex_lock(&common->lock);
if (atomic_read(&ch->usrs) && common->io_usrs) {
if (ch->channel_id == VPIF_CHANNEL2_VIDEO) {
enable_channel2(1);
channel2_intr_enable(1);
}
if (ch->channel_id == VPIF_CHANNEL3_VIDEO ||
common->started == 2) {
enable_channel3(1);
channel3_intr_enable(1);
}
}
mutex_unlock(&common->lock);
}
return 0;
}
