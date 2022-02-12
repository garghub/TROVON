static int vpif_buffer_prepare(struct vb2_buffer *vb)
{
struct vpif_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_queue *q = vb->vb2_queue;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
unsigned long addr;
vpif_dbg(2, debug, "vpif_buffer_prepare\n");
common = &ch->common[VPIF_VIDEO_INDEX];
if (vb->state != VB2_BUF_STATE_ACTIVE &&
vb->state != VB2_BUF_STATE_PREPARED) {
vb2_set_plane_payload(vb, 0, common->fmt.fmt.pix.sizeimage);
if (vb2_plane_vaddr(vb, 0) &&
vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0))
goto exit;
addr = vb2_dma_contig_plane_dma_addr(vb, 0);
if (q->streaming) {
if (!IS_ALIGNED((addr + common->ytop_off), 8) ||
!IS_ALIGNED((addr + common->ybtm_off), 8) ||
!IS_ALIGNED((addr + common->ctop_off), 8) ||
!IS_ALIGNED((addr + common->cbtm_off), 8))
goto exit;
}
}
return 0;
exit:
vpif_dbg(1, debug, "buffer_prepare:offset is not aligned to 8 bytes\n");
return -EINVAL;
}
static int vpif_buffer_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct vpif_fh *fh = vb2_get_drv_priv(vq);
struct channel_obj *ch = fh->channel;
struct common_obj *common;
unsigned long size;
common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_buffer_setup\n");
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
struct channel_obj *ch = fh->channel;
struct vpif_cap_buffer *buf = container_of(vb,
struct vpif_cap_buffer, vb);
struct common_obj *common;
unsigned long flags;
common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_buffer_queue\n");
spin_lock_irqsave(&common->irqlock, flags);
list_add_tail(&buf->list, &common->dma_queue);
spin_unlock_irqrestore(&common->irqlock, flags);
}
static void vpif_buf_cleanup(struct vb2_buffer *vb)
{
struct vpif_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vpif_cap_buffer *buf = container_of(vb,
struct vpif_cap_buffer, vb);
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
struct vpif_cap_buffer *buf = container_of(vb,
struct vpif_cap_buffer, vb);
INIT_LIST_HEAD(&buf->list);
return 0;
}
static int vpif_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vpif_capture_config *vpif_config_data =
vpif_dev->platform_data;
struct vpif_fh *fh = vb2_get_drv_priv(vq);
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_params *vpif = &ch->vpifparams;
unsigned long addr = 0;
unsigned long flags;
int ret;
spin_lock_irqsave(&common->irqlock, flags);
if (list_empty(&common->dma_queue)) {
spin_unlock_irqrestore(&common->irqlock, flags);
vpif_dbg(1, debug, "buffer queue is empty\n");
return -EIO;
}
common->cur_frm = common->next_frm = list_entry(common->dma_queue.next,
struct vpif_cap_buffer, list);
list_del(&common->cur_frm->list);
spin_unlock_irqrestore(&common->irqlock, flags);
common->cur_frm->vb.state = VB2_BUF_STATE_ACTIVE;
ch->field_id = 0;
common->started = 1;
addr = vb2_dma_contig_plane_dma_addr(&common->cur_frm->vb, 0);
vpif_calculate_offsets(ch);
if ((vpif->std_info.frm_fmt &&
((common->fmt.fmt.pix.field != V4L2_FIELD_NONE) &&
(common->fmt.fmt.pix.field != V4L2_FIELD_ANY))) ||
(!vpif->std_info.frm_fmt &&
(common->fmt.fmt.pix.field == V4L2_FIELD_NONE))) {
vpif_dbg(1, debug, "conflict in field format and std format\n");
return -EINVAL;
}
if (vpif_config_data->setup_input_channel_mode) {
ret = vpif_config_data->
setup_input_channel_mode(vpif->std_info.ycmux_mode);
if (ret < 0) {
vpif_dbg(1, debug, "can't set vpif channel mode\n");
return ret;
}
}
ret = vpif_set_video_params(vpif, ch->channel_id);
if (ret < 0) {
vpif_dbg(1, debug, "can't set video params\n");
return ret;
}
common->started = ret;
vpif_config_addr(ch, ret);
common->set_addr(addr + common->ytop_off,
addr + common->ybtm_off,
addr + common->ctop_off,
addr + common->cbtm_off);
channel_first_int[VPIF_VIDEO_INDEX][ch->channel_id] = 1;
if ((VPIF_CHANNEL0_VIDEO == ch->channel_id)) {
channel0_intr_assert();
channel0_intr_enable(1);
enable_channel0(1);
}
if ((VPIF_CHANNEL1_VIDEO == ch->channel_id) ||
(common->started == 2)) {
channel1_intr_assert();
channel1_intr_enable(1);
enable_channel1(1);
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
spin_lock_irqsave(&common->irqlock, flags);
while (!list_empty(&common->dma_queue)) {
common->next_frm = list_entry(common->dma_queue.next,
struct vpif_cap_buffer, list);
list_del(&common->next_frm->list);
vb2_buffer_done(&common->next_frm->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&common->irqlock, flags);
return 0;
}
static void vpif_process_buffer_complete(struct common_obj *common)
{
v4l2_get_timestamp(&common->cur_frm->vb.v4l2_buf.timestamp);
vb2_buffer_done(&common->cur_frm->vb,
VB2_BUF_STATE_DONE);
common->cur_frm = common->next_frm;
}
static void vpif_schedule_next_buffer(struct common_obj *common)
{
unsigned long addr = 0;
spin_lock(&common->irqlock);
common->next_frm = list_entry(common->dma_queue.next,
struct vpif_cap_buffer, list);
list_del(&common->next_frm->list);
spin_unlock(&common->irqlock);
common->next_frm->vb.state = VB2_BUF_STATE_ACTIVE;
addr = vb2_dma_contig_plane_dma_addr(&common->next_frm->vb, 0);
common->set_addr(addr + common->ytop_off,
addr + common->ybtm_off,
addr + common->ctop_off,
addr + common->cbtm_off);
}
static irqreturn_t vpif_channel_isr(int irq, void *dev_id)
{
struct vpif_device *dev = &vpif_obj;
struct common_obj *common;
struct channel_obj *ch;
enum v4l2_field field;
int channel_id = 0;
int fid = -1, i;
channel_id = *(int *)(dev_id);
if (!vpif_intr_status(channel_id))
return IRQ_NONE;
ch = dev->dev[channel_id];
field = ch->common[VPIF_VIDEO_INDEX].fmt.fmt.pix.field;
for (i = 0; i < VPIF_NUMBER_OF_OBJECTS; i++) {
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
if (!channel_first_int[i][channel_id])
vpif_process_buffer_complete(common);
channel_first_int[i][channel_id] = 0;
vpif_schedule_next_buffer(common);
channel_first_int[i][channel_id] = 0;
} else {
if (channel_first_int[i][channel_id]) {
channel_first_int[i][channel_id] = 0;
continue;
}
if (0 == i) {
ch->field_id ^= 1;
fid = vpif_channel_getfid(ch->channel_id);
if (fid != ch->field_id) {
if (0 == fid)
ch->field_id = fid;
return IRQ_HANDLED;
}
}
if (0 == fid) {
if (common->cur_frm == common->next_frm)
continue;
vpif_process_buffer_complete(common);
} else if (1 == fid) {
spin_lock(&common->irqlock);
if (list_empty(&common->dma_queue) ||
(common->cur_frm != common->next_frm)) {
spin_unlock(&common->irqlock);
continue;
}
spin_unlock(&common->irqlock);
vpif_schedule_next_buffer(common);
}
}
}
return IRQ_HANDLED;
}
static int vpif_update_std_info(struct channel_obj *ch)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct vpif_params *vpifparams = &ch->vpifparams;
const struct vpif_channel_config_params *config;
struct vpif_channel_config_params *std_info = &vpifparams->std_info;
struct video_obj *vid_ch = &ch->video;
int index;
vpif_dbg(2, debug, "vpif_update_std_info\n");
for (index = 0; index < vpif_ch_params_count; index++) {
config = &ch_params[index];
if (config->hd_sd == 0) {
vpif_dbg(2, debug, "SD format\n");
if (config->stdid & vid_ch->stdid) {
memcpy(std_info, config, sizeof(*config));
break;
}
} else {
vpif_dbg(2, debug, "HD format\n");
if (!memcmp(&config->dv_timings, &vid_ch->dv_timings,
sizeof(vid_ch->dv_timings))) {
memcpy(std_info, config, sizeof(*config));
break;
}
}
}
if (index == vpif_ch_params_count)
return -EINVAL;
common->fmt.fmt.pix.width = std_info->width;
common->width = std_info->width;
common->fmt.fmt.pix.height = std_info->height;
common->height = std_info->height;
common->fmt.fmt.pix.bytesperline = std_info->width;
vpifparams->video_params.hpitch = std_info->width;
vpifparams->video_params.storage_mode = std_info->frm_fmt;
return 0;
}
static void vpif_calculate_offsets(struct channel_obj *ch)
{
unsigned int hpitch, vpitch, sizeimage;
struct video_obj *vid_ch = &(ch->video);
struct vpif_params *vpifparams = &ch->vpifparams;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
enum v4l2_field field = common->fmt.fmt.pix.field;
vpif_dbg(2, debug, "vpif_calculate_offsets\n");
if (V4L2_FIELD_ANY == field) {
if (vpifparams->std_info.frm_fmt)
vid_ch->buf_field = V4L2_FIELD_NONE;
else
vid_ch->buf_field = V4L2_FIELD_INTERLACED;
} else
vid_ch->buf_field = common->fmt.fmt.pix.field;
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
(V4L2_FIELD_INTERLACED == vid_ch->buf_field))
vpifparams->video_params.storage_mode = 1;
else
vpifparams->video_params.storage_mode = 0;
if (1 == vpifparams->std_info.frm_fmt)
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline;
else {
if ((field == V4L2_FIELD_ANY)
|| (field == V4L2_FIELD_INTERLACED))
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline * 2;
else
vpifparams->video_params.hpitch =
common->fmt.fmt.pix.bytesperline;
}
ch->vpifparams.video_params.stdid = vpifparams->std_info.stdid;
}
static void vpif_config_format(struct channel_obj *ch)
{
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_config_format\n");
common->fmt.fmt.pix.field = V4L2_FIELD_ANY;
if (config_params.numbuffers[ch->channel_id] == 0)
common->memory = V4L2_MEMORY_USERPTR;
else
common->memory = V4L2_MEMORY_MMAP;
common->fmt.fmt.pix.sizeimage
= config_params.channel_bufsize[ch->channel_id];
if (ch->vpifparams.iface.if_type == VPIF_IF_RAW_BAYER)
common->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_SBGGR8;
else
common->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUV422P;
common->fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
}
static inline enum v4l2_field vpif_get_default_field(
struct vpif_interface *iface)
{
return (iface->if_type == VPIF_IF_RAW_BAYER) ? V4L2_FIELD_NONE :
V4L2_FIELD_INTERLACED;
}
static int vpif_check_format(struct channel_obj *ch,
struct v4l2_pix_format *pixfmt,
int update)
{
struct common_obj *common = &(ch->common[VPIF_VIDEO_INDEX]);
struct vpif_params *vpif_params = &ch->vpifparams;
enum v4l2_field field = pixfmt->field;
u32 sizeimage, hpitch, vpitch;
int ret = -EINVAL;
vpif_dbg(2, debug, "vpif_check_format\n");
if (vpif_params->iface.if_type == VPIF_IF_RAW_BAYER) {
if (pixfmt->pixelformat != V4L2_PIX_FMT_SBGGR8) {
if (!update) {
vpif_dbg(2, debug, "invalid pix format\n");
goto exit;
}
pixfmt->pixelformat = V4L2_PIX_FMT_SBGGR8;
}
} else {
if (pixfmt->pixelformat != V4L2_PIX_FMT_YUV422P) {
if (!update) {
vpif_dbg(2, debug, "invalid pixel format\n");
goto exit;
}
pixfmt->pixelformat = V4L2_PIX_FMT_YUV422P;
}
}
if (!(VPIF_VALID_FIELD(field))) {
if (!update) {
vpif_dbg(2, debug, "invalid field format\n");
goto exit;
}
field = vpif_get_default_field(&vpif_params->iface);
} else if (field == V4L2_FIELD_ANY)
field = vpif_get_default_field(&vpif_params->iface);
hpitch = pixfmt->bytesperline;
if (hpitch < vpif_params->std_info.width) {
if (!update) {
vpif_dbg(2, debug, "invalid hpitch\n");
goto exit;
}
hpitch = vpif_params->std_info.width;
}
sizeimage = pixfmt->sizeimage;
vpitch = sizeimage / (hpitch * 2);
if (vpitch < vpif_params->std_info.height) {
if (!update) {
vpif_dbg(2, debug, "Invalid vpitch\n");
goto exit;
}
vpitch = vpif_params->std_info.height;
}
if (!ALIGN(hpitch, 8)) {
if (!update) {
vpif_dbg(2, debug, "invalid pitch alignment\n");
goto exit;
}
hpitch = (((hpitch + 7) / 8) * 8);
}
if (update) {
pixfmt->bytesperline = hpitch;
pixfmt->sizeimage = hpitch * vpitch * 2;
}
pixfmt->width = common->fmt.fmt.pix.width;
pixfmt->height = common->fmt.fmt.pix.height;
return 0;
exit:
return ret;
}
static void vpif_config_addr(struct channel_obj *ch, int muxmode)
{
struct common_obj *common;
vpif_dbg(2, debug, "vpif_config_addr\n");
common = &(ch->common[VPIF_VIDEO_INDEX]);
if (VPIF_CHANNEL1_VIDEO == ch->channel_id)
common->set_addr = ch1_set_videobuf_addr;
else if (2 == muxmode)
common->set_addr = ch0_set_videobuf_addr_yc_nmux;
else
common->set_addr = ch0_set_videobuf_addr;
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
static unsigned int vpif_poll(struct file *filep, poll_table * wait)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *channel = fh->channel;
struct common_obj *common = &(channel->common[VPIF_VIDEO_INDEX]);
unsigned int res = 0;
vpif_dbg(2, debug, "vpif_poll\n");
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
struct common_obj *common;
struct video_obj *vid_ch;
struct channel_obj *ch;
struct vpif_fh *fh;
vpif_dbg(2, debug, "vpif_open\n");
ch = video_get_drvdata(vdev);
vid_ch = &ch->video;
common = &ch->common[VPIF_VIDEO_INDEX];
fh = kzalloc(sizeof(struct vpif_fh), GFP_KERNEL);
if (NULL == fh) {
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
memset(&(ch->vpifparams), 0, sizeof(struct vpif_params));
}
ch->usrs++;
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
struct common_obj *common;
vpif_dbg(2, debug, "vpif_release\n");
common = &ch->common[VPIF_VIDEO_INDEX];
mutex_lock(&common->lock);
if (fh->io_allowed[VPIF_VIDEO_INDEX]) {
common->io_usrs = 0;
if (VPIF_CHANNEL0_VIDEO == ch->channel_id) {
enable_channel0(0);
channel0_intr_enable(0);
}
if ((VPIF_CHANNEL1_VIDEO == ch->channel_id) ||
(2 == common->started)) {
enable_channel1(0);
channel1_intr_enable(0);
}
common->started = 0;
vb2_queue_release(&common->buffer_queue);
vb2_dma_contig_cleanup_ctx(common->alloc_ctx);
}
ch->usrs--;
v4l2_prio_close(&ch->prio, fh->prio);
if (fh->initialized)
ch->initialized = 0;
mutex_unlock(&common->lock);
filep->private_data = NULL;
kfree(fh);
return 0;
}
static int vpif_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *reqbuf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
u8 index = 0;
struct vb2_queue *q;
int ret;
vpif_dbg(2, debug, "vpif_reqbufs\n");
if ((VPIF_CHANNEL0_VIDEO == ch->channel_id)
|| (VPIF_CHANNEL1_VIDEO == ch->channel_id)) {
if (!fh->initialized) {
vpif_dbg(1, debug, "Channel Busy\n");
return -EBUSY;
}
}
if (V4L2_BUF_TYPE_VIDEO_CAPTURE != reqbuf->type || !vpif_dev)
return -EINVAL;
index = VPIF_VIDEO_INDEX;
common = &ch->common[index];
if (0 != common->io_usrs)
return -EBUSY;
common->alloc_ctx = vb2_dma_contig_init_ctx(vpif_dev);
if (IS_ERR(common->alloc_ctx)) {
vpif_err("Failed to get the context\n");
return PTR_ERR(common->alloc_ctx);
}
q = &common->buffer_queue;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR;
q->drv_priv = fh;
q->ops = &video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct vpif_cap_buffer);
ret = vb2_queue_init(q);
if (ret) {
vpif_err("vpif_capture: vb2_queue_init() failed\n");
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
struct v4l2_buffer *buf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_querybuf\n");
if (common->fmt.type != buf->type)
return -EINVAL;
if (common->memory != V4L2_MEMORY_MMAP) {
vpif_dbg(1, debug, "Invalid memory\n");
return -EINVAL;
}
return vb2_querybuf(&common->buffer_queue, buf);
}
static int vpif_qbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct v4l2_buffer tbuf = *buf;
vpif_dbg(2, debug, "vpif_qbuf\n");
if (common->fmt.type != tbuf.type) {
vpif_err("invalid buffer type\n");
return -EINVAL;
}
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_err("fh io not allowed\n");
return -EACCES;
}
return vb2_qbuf(&common->buffer_queue, buf);
}
static int vpif_dqbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_dqbuf\n");
return vb2_dqbuf(&common->buffer_queue, buf,
(file->f_flags & O_NONBLOCK));
}
static int vpif_streamon(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct channel_obj *oth_ch = vpif_obj.dev[!ch->channel_id];
struct vpif_params *vpif;
int ret = 0;
vpif_dbg(2, debug, "vpif_streamon\n");
vpif = &ch->vpifparams;
if (buftype != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
vpif_dbg(1, debug, "buffer type not supported\n");
return -EINVAL;
}
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_dbg(1, debug, "io not allowed\n");
return -EACCES;
}
if (common->started) {
vpif_dbg(1, debug, "channel->started\n");
return -EBUSY;
}
if ((ch->channel_id == VPIF_CHANNEL0_VIDEO &&
oth_ch->common[VPIF_VIDEO_INDEX].started &&
vpif->std_info.ycmux_mode == 0) ||
((ch->channel_id == VPIF_CHANNEL1_VIDEO) &&
(2 == oth_ch->common[VPIF_VIDEO_INDEX].started))) {
vpif_dbg(1, debug, "other channel is being used\n");
return -EBUSY;
}
ret = vpif_check_format(ch, &common->fmt.fmt.pix, 0);
if (ret)
return ret;
ret = v4l2_subdev_call(ch->sd, video, s_stream, 1);
if (ret && ret != -ENOIOCTLCMD && ret != -ENODEV) {
vpif_dbg(1, debug, "stream on failed in subdev\n");
return ret;
}
ret = vb2_streamon(&common->buffer_queue, buftype);
if (ret) {
vpif_dbg(1, debug, "vb2_streamon\n");
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
int ret;
vpif_dbg(2, debug, "vpif_streamoff\n");
if (buftype != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
vpif_dbg(1, debug, "buffer type not supported\n");
return -EINVAL;
}
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_dbg(1, debug, "io not allowed\n");
return -EACCES;
}
if (!common->started) {
vpif_dbg(1, debug, "channel->started\n");
return -EINVAL;
}
if (VPIF_CHANNEL0_VIDEO == ch->channel_id) {
enable_channel0(0);
channel0_intr_enable(0);
} else {
enable_channel1(0);
channel1_intr_enable(0);
}
common->started = 0;
ret = v4l2_subdev_call(ch->sd, video, s_stream, 0);
if (ret && ret != -ENOIOCTLCMD && ret != -ENODEV)
vpif_dbg(1, debug, "stream off failed in subdev\n");
return vb2_streamoff(&common->buffer_queue, buftype);
}
static int vpif_input_to_subdev(
struct vpif_capture_config *vpif_cfg,
struct vpif_capture_chan_config *chan_cfg,
int input_index)
{
struct vpif_subdev_info *subdev_info;
const char *subdev_name;
int i;
vpif_dbg(2, debug, "vpif_input_to_subdev\n");
subdev_name = chan_cfg->inputs[input_index].subdev_name;
if (subdev_name == NULL)
return -1;
for (i = 0; i < vpif_cfg->subdev_count; i++) {
subdev_info = &vpif_cfg->subdev_info[i];
if (!strcmp(subdev_info->name, subdev_name))
return i;
}
return -1;
}
static int vpif_set_input(
struct vpif_capture_config *vpif_cfg,
struct channel_obj *ch,
int index)
{
struct vpif_capture_chan_config *chan_cfg =
&vpif_cfg->chan_config[ch->channel_id];
struct vpif_subdev_info *subdev_info = NULL;
struct v4l2_subdev *sd = NULL;
u32 input = 0, output = 0;
int sd_index;
int ret;
sd_index = vpif_input_to_subdev(vpif_cfg, chan_cfg, index);
if (sd_index >= 0) {
sd = vpif_obj.sd[sd_index];
subdev_info = &vpif_cfg->subdev_info[sd_index];
}
if (sd && vpif_cfg->setup_input_path) {
ret = vpif_cfg->setup_input_path(ch->channel_id,
subdev_info->name);
if (ret < 0) {
vpif_dbg(1, debug, "couldn't setup input path for the" \
" sub device %s, for input index %d\n",
subdev_info->name, index);
return ret;
}
}
if (sd) {
input = chan_cfg->inputs[index].input_route;
output = chan_cfg->inputs[index].output_route;
ret = v4l2_subdev_call(sd, video, s_routing,
input, output, 0);
if (ret < 0 && ret != -ENOIOCTLCMD) {
vpif_dbg(1, debug, "Failed to set input\n");
return ret;
}
}
ch->input_idx = index;
ch->sd = sd;
ch->vpifparams.iface = chan_cfg->vpif_if;
ch->video_dev->tvnorms = chan_cfg->inputs[index].input.std;
return 0;
}
static int vpif_querystd(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
int ret = 0;
vpif_dbg(2, debug, "vpif_querystd\n");
ret = v4l2_subdev_call(ch->sd, video, querystd, std_id);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
return -ENODATA;
if (ret) {
vpif_dbg(1, debug, "Failed to query standard for sub devices\n");
return ret;
}
return 0;
}
static int vpif_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
vpif_dbg(2, debug, "vpif_g_std\n");
*std = ch->video.stdid;
return 0;
}
static int vpif_s_std(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret = 0;
vpif_dbg(2, debug, "vpif_s_std\n");
if (common->started) {
vpif_err("streaming in progress\n");
return -EBUSY;
}
if ((VPIF_CHANNEL0_VIDEO == ch->channel_id) ||
(VPIF_CHANNEL1_VIDEO == ch->channel_id)) {
if (!fh->initialized) {
vpif_dbg(1, debug, "Channel Busy\n");
return -EBUSY;
}
}
ret = v4l2_prio_check(&ch->prio, fh->prio);
if (0 != ret)
return ret;
fh->initialized = 1;
ch->video.stdid = *std_id;
memset(&ch->video.dv_timings, 0, sizeof(ch->video.dv_timings));
if (vpif_update_std_info(ch)) {
vpif_err("Error getting the standard info\n");
return -EINVAL;
}
vpif_config_format(ch);
ret = v4l2_subdev_call(ch->sd, core, s_std, *std_id);
if (ret && ret != -ENOIOCTLCMD && ret != -ENODEV) {
vpif_dbg(1, debug, "Failed to set standard for sub devices\n");
return ret;
}
return 0;
}
static int vpif_enum_input(struct file *file, void *priv,
struct v4l2_input *input)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct vpif_capture_chan_config *chan_cfg;
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
chan_cfg = &config->chan_config[ch->channel_id];
if (input->index >= chan_cfg->input_count) {
vpif_dbg(1, debug, "Invalid input index\n");
return -EINVAL;
}
memcpy(input, &chan_cfg->inputs[input->index].input,
sizeof(*input));
return 0;
}
static int vpif_g_input(struct file *file, void *priv, unsigned int *index)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
*index = ch->input_idx;
return 0;
}
static int vpif_s_input(struct file *file, void *priv, unsigned int index)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct vpif_capture_chan_config *chan_cfg;
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret;
chan_cfg = &config->chan_config[ch->channel_id];
if (index >= chan_cfg->input_count)
return -EINVAL;
if (common->started) {
vpif_err("Streaming in progress\n");
return -EBUSY;
}
if ((VPIF_CHANNEL0_VIDEO == ch->channel_id) ||
(VPIF_CHANNEL1_VIDEO == ch->channel_id)) {
if (!fh->initialized) {
vpif_dbg(1, debug, "Channel Busy\n");
return -EBUSY;
}
}
ret = v4l2_prio_check(&ch->prio, fh->prio);
if (0 != ret)
return ret;
fh->initialized = 1;
return vpif_set_input(config, ch, index);
}
static int vpif_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
if (fmt->index != 0) {
vpif_dbg(1, debug, "Invalid format index\n");
return -EINVAL;
}
if (ch->vpifparams.iface.if_type == VPIF_IF_RAW_BAYER) {
fmt->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
strcpy(fmt->description, "Raw Mode -Bayer Pattern GrRBGb");
fmt->pixelformat = V4L2_PIX_FMT_SBGGR8;
} else {
fmt->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
strcpy(fmt->description, "YCbCr4:2:2 YC Planar");
fmt->pixelformat = V4L2_PIX_FMT_YUV422P;
}
return 0;
}
static int vpif_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct v4l2_pix_format *pixfmt = &fmt->fmt.pix;
return vpif_check_format(ch, pixfmt, 1);
}
static int vpif_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (common->fmt.type != fmt->type)
return -EINVAL;
*fmt = common->fmt;
return 0;
}
static int vpif_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct v4l2_pix_format *pixfmt;
int ret = 0;
vpif_dbg(2, debug, "%s\n", __func__);
if (common->started) {
vpif_dbg(1, debug, "Streaming is started\n");
return -EBUSY;
}
if ((VPIF_CHANNEL0_VIDEO == ch->channel_id) ||
(VPIF_CHANNEL1_VIDEO == ch->channel_id)) {
if (!fh->initialized) {
vpif_dbg(1, debug, "Channel Busy\n");
return -EBUSY;
}
}
ret = v4l2_prio_check(&ch->prio, fh->prio);
if (0 != ret)
return ret;
fh->initialized = 1;
pixfmt = &fmt->fmt.pix;
ret = vpif_check_format(ch, pixfmt, 0);
if (ret)
return ret;
common->fmt = *fmt;
return 0;
}
static int vpif_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
snprintf(cap->driver, sizeof(cap->driver), "%s", dev_name(vpif_dev));
snprintf(cap->bus_info, sizeof(cap->bus_info), "platform:%s",
dev_name(vpif_dev));
strlcpy(cap->card, config->card_name, sizeof(cap->card));
return 0;
}
static int vpif_g_priority(struct file *file, void *priv,
enum v4l2_priority *prio)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
*prio = v4l2_prio_max(&ch->prio);
return 0;
}
static int vpif_s_priority(struct file *file, void *priv, enum v4l2_priority p)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
return v4l2_prio_change(&ch->prio, &fh->prio, p);
}
static int vpif_cropcap(struct file *file, void *priv,
struct v4l2_cropcap *crop)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (V4L2_BUF_TYPE_VIDEO_CAPTURE != crop->type)
return -EINVAL;
crop->bounds.left = 0;
crop->bounds.top = 0;
crop->bounds.height = common->height;
crop->bounds.width = common->width;
crop->defrect = crop->bounds;
return 0;
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
static int
vpif_query_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
int ret;
ret = v4l2_subdev_call(ch->sd, video, query_dv_timings, timings);
if (ret == -ENOIOCTLCMD || ret == -ENODEV)
return -ENODATA;
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
std_info->eav2sav = bt->hbackporch + bt->hfrontporch +
bt->hsync - 8;
std_info->sav2eav = bt->width;
std_info->l1 = 1;
std_info->l3 = bt->vsync + bt->vbackporch + 1;
if (bt->interlaced) {
if (bt->il_vbackporch || bt->il_vfrontporch || bt->il_vsync) {
std_info->vsize = bt->height * 2 +
bt->vfrontporch + bt->vsync + bt->vbackporch +
bt->il_vfrontporch + bt->il_vsync +
bt->il_vbackporch;
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
std_info->vsize = bt->height + bt->vfrontporch +
bt->vsync + bt->vbackporch;
std_info->l5 = std_info->vsize - (bt->vfrontporch - 1);
}
strncpy(std_info->name, "Custom timings BT656/1120", VPIF_MAX_NAME);
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
static int vpif_g_chip_ident(struct file *file, void *priv,
struct v4l2_dbg_chip_ident *chip)
{
chip->ident = V4L2_IDENT_NONE;
chip->revision = 0;
if (chip->match.type != V4L2_CHIP_MATCH_I2C_DRIVER &&
chip->match.type != V4L2_CHIP_MATCH_I2C_ADDR) {
vpif_dbg(2, debug, "match_type is invalid.\n");
return -EINVAL;
}
return v4l2_device_call_until_err(&vpif_obj.v4l2_dev, 0, core,
g_chip_ident, chip);
}
static int vpif_dbg_g_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg){
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
return v4l2_subdev_call(ch->sd, core, g_register, reg);
}
static int vpif_dbg_s_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg){
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
return v4l2_subdev_call(ch->sd, core, s_register, reg);
}
static int vpif_log_status(struct file *filep, void *priv)
{
v4l2_device_call_all(&vpif_obj.v4l2_dev, 0, core, log_status);
return 0;
}
static int initialize_vpif(void)
{
int err = 0, i, j;
int free_channel_objects_index;
if ((ch0_numbuffers > 0) &&
(ch0_numbuffers < config_params.min_numbuffers))
ch0_numbuffers = config_params.min_numbuffers;
if ((ch1_numbuffers > 0) &&
(ch1_numbuffers < config_params.min_numbuffers))
ch1_numbuffers = config_params.min_numbuffers;
if (ch0_bufsize < config_params.min_bufsize[VPIF_CHANNEL0_VIDEO])
ch0_bufsize =
config_params.min_bufsize[VPIF_CHANNEL0_VIDEO];
if (ch1_bufsize < config_params.min_bufsize[VPIF_CHANNEL1_VIDEO])
ch1_bufsize =
config_params.min_bufsize[VPIF_CHANNEL1_VIDEO];
config_params.numbuffers[VPIF_CHANNEL0_VIDEO] = ch0_numbuffers;
config_params.numbuffers[VPIF_CHANNEL1_VIDEO] = ch1_numbuffers;
if (ch0_numbuffers) {
config_params.channel_bufsize[VPIF_CHANNEL0_VIDEO]
= ch0_bufsize;
}
if (ch1_numbuffers) {
config_params.channel_bufsize[VPIF_CHANNEL1_VIDEO]
= ch1_bufsize;
}
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
vpif_obj.dev[i] =
kzalloc(sizeof(*vpif_obj.dev[i]), GFP_KERNEL);
if (!vpif_obj.dev[i]) {
free_channel_objects_index = i;
err = -ENOMEM;
goto vpif_init_free_channel_objects;
}
}
return 0;
vpif_init_free_channel_objects:
for (j = 0; j < free_channel_objects_index; j++)
kfree(vpif_obj.dev[j]);
return err;
}
static __init int vpif_probe(struct platform_device *pdev)
{
struct vpif_subdev_info *subdevdata;
struct vpif_capture_config *config;
int i, j, k, err;
int res_idx = 0;
struct i2c_adapter *i2c_adap;
struct channel_obj *ch;
struct common_obj *common;
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
for (i = res->start; i <= res->end; i++) {
if (request_irq(i, vpif_channel_isr, IRQF_SHARED,
"VPIF_Capture", (void *)
(&vpif_obj.dev[res_idx]->channel_id))) {
err = -EBUSY;
for (j = 0; j < i; j++)
free_irq(j, (void *)
(&vpif_obj.dev[res_idx]->channel_id));
goto vpif_int_err;
}
}
res_idx++;
}
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
vfd = video_device_alloc();
if (NULL == vfd) {
for (j = 0; j < i; j++) {
ch = vpif_obj.dev[j];
video_device_release(ch->video_dev);
}
err = -ENOMEM;
goto vpif_int_err;
}
*vfd = vpif_video_template;
vfd->v4l2_dev = &vpif_obj.v4l2_dev;
vfd->release = video_device_release;
snprintf(vfd->name, sizeof(vfd->name),
"VPIF_Capture_DRIVER_V%s",
VPIF_CAPTURE_VERSION);
ch->video_dev = vfd;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res) {
size = resource_size(res);
for (j = 0; j < VPIF_CAPTURE_MAX_DEVICES; j++) {
ch = vpif_obj.dev[j];
ch->channel_id = j;
config_params.video_limit[ch->channel_id] = 0;
if (size)
config_params.video_limit[ch->channel_id] =
size/2;
}
}
i2c_adap = i2c_get_adapter(1);
config = pdev->dev.platform_data;
subdev_count = config->subdev_count;
vpif_obj.sd = kzalloc(sizeof(struct v4l2_subdev *) * subdev_count,
GFP_KERNEL);
if (vpif_obj.sd == NULL) {
vpif_err("unable to allocate memory for subdevice pointers\n");
err = -ENOMEM;
goto vpif_sd_error;
}
for (i = 0; i < subdev_count; i++) {
subdevdata = &config->subdev_info[i];
vpif_obj.sd[i] =
v4l2_i2c_new_subdev_board(&vpif_obj.v4l2_dev,
i2c_adap,
&subdevdata->board_info,
NULL);
if (!vpif_obj.sd[i]) {
vpif_err("Error registering v4l2 subdevice\n");
goto probe_subdev_out;
}
v4l2_info(&vpif_obj.v4l2_dev, "registered sub device %s\n",
subdevdata->name);
}
for (j = 0; j < VPIF_CAPTURE_MAX_DEVICES; j++) {
ch = vpif_obj.dev[j];
ch->channel_id = j;
common = &(ch->common[VPIF_VIDEO_INDEX]);
spin_lock_init(&common->irqlock);
mutex_init(&common->lock);
ch->video_dev->lock = &common->lock;
v4l2_prio_init(&ch->prio);
video_set_drvdata(ch->video_dev, ch);
err = vpif_set_input(config, ch, 0);
if (err)
goto probe_out;
err = video_register_device(ch->video_dev,
VFL_TYPE_GRABBER, (j ? 1 : 0));
if (err)
goto probe_out;
}
v4l2_info(&vpif_obj.v4l2_dev, "VPIF capture driver initialized\n");
return 0;
probe_out:
for (k = 0; k < j; k++) {
ch = vpif_obj.dev[k];
video_unregister_device(ch->video_dev);
}
probe_subdev_out:
kfree(vpif_obj.sd);
vpif_sd_error:
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
video_device_release(ch->video_dev);
}
vpif_int_err:
v4l2_device_unregister(&vpif_obj.v4l2_dev);
for (i = 0; i < res_idx; i++) {
res = platform_get_resource(pdev, IORESOURCE_IRQ, i);
for (j = res->start; j <= res->end; j++)
free_irq(j, (void *)(&vpif_obj.dev[i]->channel_id));
}
return err;
}
static int vpif_remove(struct platform_device *device)
{
int i;
struct channel_obj *ch;
v4l2_device_unregister(&vpif_obj.v4l2_dev);
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
video_unregister_device(ch->video_dev);
}
return 0;
}
static int vpif_suspend(struct device *dev)
{
struct common_obj *common;
struct channel_obj *ch;
int i;
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
common = &ch->common[VPIF_VIDEO_INDEX];
mutex_lock(&common->lock);
if (ch->usrs && common->io_usrs) {
if (ch->channel_id == VPIF_CHANNEL0_VIDEO) {
enable_channel0(0);
channel0_intr_enable(0);
}
if (ch->channel_id == VPIF_CHANNEL1_VIDEO ||
common->started == 2) {
enable_channel1(0);
channel1_intr_enable(0);
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
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
common = &ch->common[VPIF_VIDEO_INDEX];
mutex_lock(&common->lock);
if (ch->usrs && common->io_usrs) {
if (ch->channel_id == VPIF_CHANNEL0_VIDEO) {
enable_channel0(1);
channel0_intr_enable(1);
}
if (ch->channel_id == VPIF_CHANNEL1_VIDEO ||
common->started == 2) {
enable_channel1(1);
channel1_intr_enable(1);
}
}
mutex_unlock(&common->lock);
}
return 0;
}
static __init int vpif_init(void)
{
return platform_driver_register(&vpif_driver);
}
static void vpif_cleanup(void)
{
struct platform_device *pdev;
struct resource *res;
int irq_num;
int i = 0;
pdev = container_of(vpif_dev, struct platform_device, dev);
while ((res = platform_get_resource(pdev, IORESOURCE_IRQ, i))) {
for (irq_num = res->start; irq_num <= res->end; irq_num++)
free_irq(irq_num,
(void *)(&vpif_obj.dev[i]->channel_id));
i++;
}
platform_driver_unregister(&vpif_driver);
kfree(vpif_obj.sd);
for (i = 0; i < VPIF_CAPTURE_MAX_DEVICES; i++)
kfree(vpif_obj.dev[i]);
}
