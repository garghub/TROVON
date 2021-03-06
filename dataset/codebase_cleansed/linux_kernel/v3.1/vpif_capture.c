static inline u32 vpif_uservirt_to_phys(u32 virtp)
{
unsigned long physp = 0;
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
vma = find_vma(mm, virtp);
if (virtp >= PAGE_OFFSET)
physp = virt_to_phys((void *)virtp);
else if (vma && (vma->vm_flags & VM_IO) && (vma->vm_pgoff))
physp = (vma->vm_pgoff << PAGE_SHIFT) + (virtp - vma->vm_start);
else {
int res, nr_pages = 1;
struct page *pages;
down_read(&current->mm->mmap_sem);
res = get_user_pages(current, current->mm,
virtp, nr_pages, 1, 0, &pages, NULL);
up_read(&current->mm->mmap_sem);
if (res == nr_pages)
physp = __pa(page_address(&pages[0]) +
(virtp & ~PAGE_MASK));
else {
vpif_err("get_user_pages failed\n");
return 0;
}
}
return physp;
}
static int vpif_buffer_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct vpif_fh *fh = q->priv_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
unsigned long addr;
vpif_dbg(2, debug, "vpif_buffer_prepare\n");
common = &ch->common[VPIF_VIDEO_INDEX];
if (VIDEOBUF_NEEDS_INIT == vb->state) {
vb->width = common->width;
vb->height = common->height;
vb->size = vb->width * vb->height;
vb->field = field;
}
vb->state = VIDEOBUF_PREPARED;
if (V4L2_MEMORY_USERPTR == common->memory) {
if (0 == vb->baddr) {
vpif_dbg(1, debug, "buffer address is 0\n");
return -EINVAL;
}
vb->boff = vpif_uservirt_to_phys(vb->baddr);
if (!IS_ALIGNED(vb->boff, 8))
goto exit;
}
addr = vb->boff;
if (q->streaming) {
if (!IS_ALIGNED((addr + common->ytop_off), 8) ||
!IS_ALIGNED((addr + common->ybtm_off), 8) ||
!IS_ALIGNED((addr + common->ctop_off), 8) ||
!IS_ALIGNED((addr + common->cbtm_off), 8))
goto exit;
}
return 0;
exit:
vpif_dbg(1, debug, "buffer_prepare:offset is not aligned to 8 bytes\n");
return -EINVAL;
}
static int vpif_buffer_setup(struct videobuf_queue *q, unsigned int *count,
unsigned int *size)
{
struct vpif_fh *fh = q->priv_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_buffer_setup\n");
if (V4L2_MEMORY_MMAP != common->memory)
return 0;
*size = config_params.channel_bufsize[ch->channel_id];
if (*count < config_params.min_numbuffers)
*count = config_params.min_numbuffers;
return 0;
}
static void vpif_buffer_queue(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct vpif_fh *fh = q->priv_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_buffer_queue\n");
list_add_tail(&vb->queue, &common->dma_queue);
vb->state = VIDEOBUF_QUEUED;
}
static void vpif_buffer_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct vpif_fh *fh = q->priv_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
common = &ch->common[VPIF_VIDEO_INDEX];
videobuf_dma_contig_free(q, vb);
vb->state = VIDEOBUF_NEEDS_INIT;
}
static void vpif_process_buffer_complete(struct common_obj *common)
{
do_gettimeofday(&common->cur_frm->ts);
common->cur_frm->state = VIDEOBUF_DONE;
wake_up_interruptible(&common->cur_frm->done);
common->cur_frm = common->next_frm;
}
static void vpif_schedule_next_buffer(struct common_obj *common)
{
unsigned long addr = 0;
common->next_frm = list_entry(common->dma_queue.next,
struct videobuf_buffer, queue);
list_del(&common->next_frm->queue);
common->next_frm->state = VIDEOBUF_ACTIVE;
if (V4L2_MEMORY_USERPTR == common->memory)
addr = common->next_frm->boff;
else
addr = videobuf_to_dma_contig(common->next_frm);
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
ch = dev->dev[channel_id];
field = ch->common[VPIF_VIDEO_INDEX].fmt.fmt.pix.field;
for (i = 0; i < VPIF_NUMBER_OF_OBJECTS; i++) {
common = &ch->common[i];
if (0 == common->started)
continue;
if (1 == ch->vpifparams.std_info.frm_fmt) {
if (list_empty(&common->dma_queue))
continue;
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
if (list_empty(&common->dma_queue) ||
(common->cur_frm != common->next_frm))
continue;
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
if (config->dv_preset == vid_ch->dv_preset) {
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
if (V4L2_MEMORY_USERPTR == common->memory)
sizeimage = common->fmt.fmt.pix.sizeimage;
else
sizeimage = config_params.channel_bufsize[ch->channel_id];
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
if (V4L2_MEMORY_USERPTR == common->memory)
sizeimage = pixfmt->sizeimage;
else
sizeimage = config_params.channel_bufsize[ch->channel_id];
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
vpif_dbg(2, debug, "vpif_mmap\n");
return videobuf_mmap_mapper(&common->buffer_queue, vma);
}
static unsigned int vpif_poll(struct file *filep, poll_table * wait)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *channel = fh->channel;
struct common_obj *common = &(channel->common[VPIF_VIDEO_INDEX]);
vpif_dbg(2, debug, "vpif_poll\n");
if (common->started)
return videobuf_poll_stream(filep, &common->buffer_queue, wait);
return 0;
}
static int vpif_open(struct file *filep)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct video_device *vdev = video_devdata(filep);
struct common_obj *common;
struct video_obj *vid_ch;
struct channel_obj *ch;
struct vpif_fh *fh;
int i;
vpif_dbg(2, debug, "vpif_open\n");
ch = video_get_drvdata(vdev);
vid_ch = &ch->video;
common = &ch->common[VPIF_VIDEO_INDEX];
if (NULL == ch->curr_subdev_info) {
for (i = 0; i < config->subdev_count; i++) {
if (vpif_obj.sd[i]) {
ch->curr_subdev_info = &config->subdev_info[i];
vid_ch->input_idx = 0;
break;
}
}
if (i == config->subdev_count) {
vpif_err("No sub device registered\n");
return -ENOENT;
}
}
fh = kzalloc(sizeof(struct vpif_fh), GFP_KERNEL);
if (NULL == fh) {
vpif_err("unable to allocate memory for file handle object\n");
return -ENOMEM;
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
return 0;
}
static int vpif_release(struct file *filep)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
vpif_dbg(2, debug, "vpif_release\n");
common = &ch->common[VPIF_VIDEO_INDEX];
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
videobuf_queue_cancel(&common->buffer_queue);
videobuf_mmap_free(&common->buffer_queue);
}
ch->usrs--;
v4l2_prio_close(&ch->prio, fh->prio);
if (fh->initialized)
ch->initialized = 0;
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
vpif_dbg(2, debug, "vpif_reqbufs\n");
if ((VPIF_CHANNEL0_VIDEO == ch->channel_id)
|| (VPIF_CHANNEL1_VIDEO == ch->channel_id)) {
if (!fh->initialized) {
vpif_dbg(1, debug, "Channel Busy\n");
return -EBUSY;
}
}
if (V4L2_BUF_TYPE_VIDEO_CAPTURE != reqbuf->type)
return -EINVAL;
index = VPIF_VIDEO_INDEX;
common = &ch->common[index];
if (0 != common->io_usrs)
return -EBUSY;
videobuf_queue_dma_contig_init(&common->buffer_queue,
&video_qops, NULL,
&common->irqlock,
reqbuf->type,
common->fmt.fmt.pix.field,
sizeof(struct videobuf_buffer), fh,
&common->lock);
fh->io_allowed[index] = 1;
common->io_usrs = 1;
common->memory = reqbuf->memory;
INIT_LIST_HEAD(&common->dma_queue);
return videobuf_reqbufs(&common->buffer_queue, reqbuf);
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
return videobuf_querybuf(&common->buffer_queue, buf);
}
static int vpif_qbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct v4l2_buffer tbuf = *buf;
struct videobuf_buffer *buf1;
unsigned long addr = 0;
unsigned long flags;
int ret = 0;
vpif_dbg(2, debug, "vpif_qbuf\n");
if (common->fmt.type != tbuf.type) {
vpif_err("invalid buffer type\n");
return -EINVAL;
}
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_err("fh io not allowed \n");
return -EACCES;
}
if (!(list_empty(&common->dma_queue)) ||
(common->cur_frm != common->next_frm) ||
!common->started ||
(common->started && (0 == ch->field_id)))
return videobuf_qbuf(&common->buffer_queue, buf);
mutex_lock(&common->buffer_queue.vb_lock);
buf1 = common->buffer_queue.bufs[tbuf.index];
if ((buf1->state == VIDEOBUF_QUEUED) ||
(buf1->state == VIDEOBUF_ACTIVE)) {
vpif_err("invalid state\n");
goto qbuf_exit;
}
switch (buf1->memory) {
case V4L2_MEMORY_MMAP:
if (buf1->baddr == 0)
goto qbuf_exit;
break;
case V4L2_MEMORY_USERPTR:
if (tbuf.length < buf1->bsize)
goto qbuf_exit;
if ((VIDEOBUF_NEEDS_INIT != buf1->state)
&& (buf1->baddr != tbuf.m.userptr)) {
vpif_buffer_release(&common->buffer_queue, buf1);
buf1->baddr = tbuf.m.userptr;
}
break;
default:
goto qbuf_exit;
}
local_irq_save(flags);
ret = vpif_buffer_prepare(&common->buffer_queue, buf1,
common->buffer_queue.field);
if (ret < 0) {
local_irq_restore(flags);
goto qbuf_exit;
}
buf1->state = VIDEOBUF_ACTIVE;
if (V4L2_MEMORY_USERPTR == common->memory)
addr = buf1->boff;
else
addr = videobuf_to_dma_contig(buf1);
common->next_frm = buf1;
common->set_addr(addr + common->ytop_off,
addr + common->ybtm_off,
addr + common->ctop_off,
addr + common->cbtm_off);
local_irq_restore(flags);
list_add_tail(&buf1->stream, &common->buffer_queue.stream);
mutex_unlock(&common->buffer_queue.vb_lock);
return 0;
qbuf_exit:
mutex_unlock(&common->buffer_queue.vb_lock);
return -EINVAL;
}
static int vpif_dqbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
vpif_dbg(2, debug, "vpif_dqbuf\n");
return videobuf_dqbuf(&common->buffer_queue, buf,
file->f_flags & O_NONBLOCK);
}
static int vpif_streamon(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct channel_obj *oth_ch = vpif_obj.dev[!ch->channel_id];
struct vpif_params *vpif;
unsigned long addr = 0;
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
ret = v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index], video,
s_stream, 1);
if (ret && (ret != -ENOIOCTLCMD)) {
vpif_dbg(1, debug, "stream on failed in subdev\n");
return ret;
}
ret = videobuf_streamon(&common->buffer_queue);
if (ret) {
vpif_dbg(1, debug, "videobuf_streamon\n");
return ret;
}
if (list_empty(&common->dma_queue)) {
vpif_dbg(1, debug, "buffer queue is empty\n");
ret = -EIO;
goto exit;
}
common->cur_frm = list_entry(common->dma_queue.next,
struct videobuf_buffer, queue);
common->next_frm = common->cur_frm;
list_del(&common->cur_frm->queue);
common->cur_frm->state = VIDEOBUF_ACTIVE;
ch->field_id = 0;
common->started = 1;
if (V4L2_MEMORY_USERPTR == common->memory)
addr = common->cur_frm->boff;
else
addr = videobuf_to_dma_contig(common->cur_frm);
vpif_calculate_offsets(ch);
if ((vpif->std_info.frm_fmt &&
((common->fmt.fmt.pix.field != V4L2_FIELD_NONE) &&
(common->fmt.fmt.pix.field != V4L2_FIELD_ANY))) ||
(!vpif->std_info.frm_fmt &&
(common->fmt.fmt.pix.field == V4L2_FIELD_NONE))) {
vpif_dbg(1, debug, "conflict in field format and std format\n");
ret = -EINVAL;
goto exit;
}
ret = config->setup_input_channel_mode(vpif->std_info.ycmux_mode);
if (ret < 0) {
vpif_dbg(1, debug, "can't set vpif channel mode\n");
goto exit;
}
ret = vpif_set_video_params(vpif, ch->channel_id);
if (ret < 0) {
vpif_dbg(1, debug, "can't set video params\n");
goto exit;
}
common->started = ret;
vpif_config_addr(ch, ret);
common->set_addr(addr + common->ytop_off,
addr + common->ybtm_off,
addr + common->ctop_off,
addr + common->cbtm_off);
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
channel_first_int[VPIF_VIDEO_INDEX][ch->channel_id] = 1;
return ret;
exit:
videobuf_streamoff(&common->buffer_queue);
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
ret = v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index], video,
s_stream, 0);
if (ret && (ret != -ENOIOCTLCMD))
vpif_dbg(1, debug, "stream off failed in subdev\n");
return videobuf_streamoff(&common->buffer_queue);
}
static struct vpif_subdev_info *vpif_map_sub_device_to_input(
struct channel_obj *ch,
struct vpif_capture_config *vpif_cfg,
int input_index,
int *sub_device_index)
{
struct vpif_capture_chan_config *chan_cfg;
struct vpif_subdev_info *subdev_info = NULL;
const char *subdev_name = NULL;
int i;
vpif_dbg(2, debug, "vpif_map_sub_device_to_input\n");
chan_cfg = &vpif_cfg->chan_config[ch->channel_id];
for (i = 0; i < chan_cfg->input_count; i++) {
if (i == input_index) {
subdev_name = chan_cfg->inputs[i].subdev_name;
break;
}
}
if (i == chan_cfg->input_count || (NULL == subdev_name))
return subdev_info;
for (i = 0; i < vpif_cfg->subdev_count; i++) {
subdev_info = &vpif_cfg->subdev_info[i];
if (!strcmp(subdev_info->name, subdev_name))
break;
}
if (i == vpif_cfg->subdev_count)
return subdev_info;
if (NULL == vpif_obj.sd[i])
return NULL;
*sub_device_index = i;
return subdev_info;
}
static int vpif_querystd(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
int ret = 0;
vpif_dbg(2, debug, "vpif_querystd\n");
ret = v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index], video,
querystd, std_id);
if (ret < 0)
vpif_dbg(1, debug, "Failed to set standard for sub devices\n");
return ret;
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
ch->video.dv_preset = V4L2_DV_INVALID;
memset(&ch->video.bt_timings, 0, sizeof(ch->video.bt_timings));
if (vpif_update_std_info(ch)) {
vpif_err("Error getting the standard info\n");
return -EINVAL;
}
vpif_config_format(ch);
ret = v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index], core,
s_std, *std_id);
if (ret < 0)
vpif_dbg(1, debug, "Failed to set standard for sub devices\n");
return ret;
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
struct video_obj *vid_ch = &ch->video;
*index = vid_ch->input_idx;
return 0;
}
static int vpif_s_input(struct file *file, void *priv, unsigned int index)
{
struct vpif_capture_config *config = vpif_dev->platform_data;
struct vpif_capture_chan_config *chan_cfg;
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct video_obj *vid_ch = &ch->video;
struct vpif_subdev_info *subdev_info;
int ret = 0, sd_index = 0;
u32 input = 0, output = 0;
chan_cfg = &config->chan_config[ch->channel_id];
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
subdev_info = vpif_map_sub_device_to_input(ch, config, index,
&sd_index);
if (NULL == subdev_info) {
vpif_dbg(1, debug,
"couldn't lookup sub device for the input index\n");
return -EINVAL;
}
if (config->setup_input_path) {
ret = config->setup_input_path(ch->channel_id,
subdev_info->name);
if (ret < 0) {
vpif_dbg(1, debug, "couldn't setup input path for the"
" sub device %s, for input index %d\n",
subdev_info->name, index);
return ret;
}
}
if (subdev_info->can_route) {
input = subdev_info->input;
output = subdev_info->output;
ret = v4l2_subdev_call(vpif_obj.sd[sd_index], video, s_routing,
input, output, 0);
if (ret < 0) {
vpif_dbg(1, debug, "Failed to set input\n");
return ret;
}
}
vid_ch->input_idx = index;
ch->curr_subdev_info = subdev_info;
ch->curr_sd_index = sd_index;
ch->vpifparams.iface = subdev_info->vpif_if;
ch->video_dev->tvnorms = chan_cfg->inputs[index].input.std;
return ret;
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
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
strlcpy(cap->driver, "vpif capture", sizeof(cap->driver));
strlcpy(cap->bus_info, "DM646x Platform", sizeof(cap->bus_info));
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
static int vpif_enum_dv_presets(struct file *file, void *priv,
struct v4l2_dv_enum_preset *preset)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
return v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index],
video, enum_dv_presets, preset);
}
static int vpif_query_dv_preset(struct file *file, void *priv,
struct v4l2_dv_preset *preset)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
return v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index],
video, query_dv_preset, preset);
}
static int vpif_s_dv_preset(struct file *file, void *priv,
struct v4l2_dv_preset *preset)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret = 0;
if (common->started) {
vpif_dbg(1, debug, "streaming in progress\n");
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
if (ret)
return ret;
fh->initialized = 1;
if (mutex_lock_interruptible(&common->lock))
return -ERESTARTSYS;
ch->video.dv_preset = preset->preset;
ch->video.stdid = V4L2_STD_UNKNOWN;
memset(&ch->video.bt_timings, 0, sizeof(ch->video.bt_timings));
if (vpif_update_std_info(ch)) {
vpif_dbg(1, debug, "Error getting the standard info\n");
ret = -EINVAL;
} else {
vpif_config_format(ch);
ret = v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index],
video, s_dv_preset, preset);
}
mutex_unlock(&common->lock);
return ret;
}
static int vpif_g_dv_preset(struct file *file, void *priv,
struct v4l2_dv_preset *preset)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
preset->preset = ch->video.dv_preset;
return 0;
}
static int vpif_s_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct vpif_params *vpifparams = &ch->vpifparams;
struct vpif_channel_config_params *std_info = &vpifparams->std_info;
struct video_obj *vid_ch = &ch->video;
struct v4l2_bt_timings *bt = &vid_ch->bt_timings;
int ret;
if (timings->type != V4L2_DV_BT_656_1120) {
vpif_dbg(2, debug, "Timing type not defined\n");
return -EINVAL;
}
ret = v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index],
video, s_dv_timings, timings);
if (ret == -ENOIOCTLCMD) {
vpif_dbg(2, debug, "Custom DV timings not supported by "
"subdevice\n");
return -EINVAL;
}
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
*bt = timings->bt;
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
std_info->dv_preset = V4L2_DV_INVALID;
vid_ch->stdid = 0;
vid_ch->dv_preset = V4L2_DV_INVALID;
return 0;
}
static int vpif_g_dv_timings(struct file *file, void *priv,
struct v4l2_dv_timings *timings)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct video_obj *vid_ch = &ch->video;
struct v4l2_bt_timings *bt = &vid_ch->bt_timings;
timings->bt = *bt;
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
return v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index], core,
g_register, reg);
}
static int vpif_dbg_s_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg){
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
return v4l2_subdev_call(vpif_obj.sd[ch->curr_sd_index], core,
s_register, reg);
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
int i, j, k, m, q, err;
struct i2c_adapter *i2c_adap;
struct channel_obj *ch;
struct common_obj *common;
struct video_device *vfd;
struct resource *res;
int subdev_count;
vpif_dev = &pdev->dev;
err = initialize_vpif();
if (err) {
v4l2_err(vpif_dev->driver, "Error initializing vpif\n");
return err;
}
k = 0;
while ((res = platform_get_resource(pdev, IORESOURCE_IRQ, k))) {
for (i = res->start; i <= res->end; i++) {
if (request_irq(i, vpif_channel_isr, IRQF_DISABLED,
"DM646x_Capture",
(void *)(&vpif_obj.dev[k]->channel_id))) {
err = -EBUSY;
i--;
goto vpif_int_err;
}
}
k++;
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
goto vpif_dev_alloc_err;
}
*vfd = vpif_video_template;
vfd->v4l2_dev = &vpif_obj.v4l2_dev;
vfd->release = video_device_release;
snprintf(vfd->name, sizeof(vfd->name),
"DM646x_VPIFCapture_DRIVER_V%s",
VPIF_CAPTURE_VERSION);
ch->video_dev = vfd;
}
for (j = 0; j < VPIF_CAPTURE_MAX_DEVICES; j++) {
ch = vpif_obj.dev[j];
ch->channel_id = j;
common = &(ch->common[VPIF_VIDEO_INDEX]);
spin_lock_init(&common->irqlock);
mutex_init(&common->lock);
ch->video_dev->lock = &common->lock;
v4l2_prio_init(&ch->prio);
err = video_register_device(ch->video_dev,
VFL_TYPE_GRABBER, (j ? 1 : 0));
if (err)
goto probe_out;
video_set_drvdata(ch->video_dev, ch);
}
i2c_adap = i2c_get_adapter(1);
config = pdev->dev.platform_data;
subdev_count = config->subdev_count;
vpif_obj.sd = kzalloc(sizeof(struct v4l2_subdev *) * subdev_count,
GFP_KERNEL);
if (vpif_obj.sd == NULL) {
vpif_err("unable to allocate memory for subdevice pointers\n");
err = -ENOMEM;
goto probe_out;
}
err = v4l2_device_register(vpif_dev, &vpif_obj.v4l2_dev);
if (err) {
v4l2_err(vpif_dev->driver, "Error registering v4l2 device\n");
goto probe_subdev_out;
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
if (vpif_obj.sd[i])
vpif_obj.sd[i]->grp_id = 1 << i;
}
v4l2_info(&vpif_obj.v4l2_dev,
"DM646x VPIF capture driver initialized\n");
return 0;
probe_subdev_out:
kfree(vpif_obj.sd);
j = VPIF_CAPTURE_MAX_DEVICES;
probe_out:
v4l2_device_unregister(&vpif_obj.v4l2_dev);
for (k = 0; k < j; k++) {
ch = vpif_obj.dev[k];
video_unregister_device(ch->video_dev);
}
vpif_dev_alloc_err:
k = VPIF_CAPTURE_MAX_DEVICES-1;
res = platform_get_resource(pdev, IORESOURCE_IRQ, k);
i = res->end;
vpif_int_err:
for (q = k; q >= 0; q--) {
for (m = i; m >= (int)res->start; m--)
free_irq(m, (void *)(&vpif_obj.dev[q]->channel_id));
res = platform_get_resource(pdev, IORESOURCE_IRQ, q-1);
if (res)
i = res->end;
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
static int
vpif_suspend(struct device *dev)
{
return -1;
}
static int
vpif_resume(struct device *dev)
{
return -1;
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
