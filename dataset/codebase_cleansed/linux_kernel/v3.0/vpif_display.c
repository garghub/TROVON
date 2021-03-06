static u32 vpif_uservirt_to_phys(u32 virtp)
{
struct mm_struct *mm = current->mm;
unsigned long physp = 0;
struct vm_area_struct *vma;
vma = find_vma(mm, virtp);
if (virtp >= PAGE_OFFSET) {
physp = virt_to_phys((void *)virtp);
} else if (vma && (vma->vm_flags & VM_IO) && (vma->vm_pgoff)) {
physp = (vma->vm_pgoff << PAGE_SHIFT) + (virtp - vma->vm_start);
} else {
int res, nr_pages = 1;
struct page *pages;
down_read(&current->mm->mmap_sem);
res = get_user_pages(current, current->mm,
virtp, nr_pages, 1, 0, &pages, NULL);
up_read(&current->mm->mmap_sem);
if (res == nr_pages) {
physp = __pa(page_address(&pages[0]) +
(virtp & ~PAGE_MASK));
} else {
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
struct common_obj *common;
unsigned long addr;
common = &fh->channel->common[VPIF_VIDEO_INDEX];
if (VIDEOBUF_NEEDS_INIT == vb->state) {
vb->width = common->width;
vb->height = common->height;
vb->size = vb->width * vb->height;
vb->field = field;
}
vb->state = VIDEOBUF_PREPARED;
if (V4L2_MEMORY_USERPTR == common->memory) {
if (!vb->baddr) {
vpif_err("buffer_address is 0\n");
return -EINVAL;
}
vb->boff = vpif_uservirt_to_phys(vb->baddr);
if (!ISALIGNED(vb->boff))
goto buf_align_exit;
}
addr = vb->boff;
if (q->streaming && (V4L2_BUF_TYPE_SLICED_VBI_OUTPUT != q->type)) {
if (!ISALIGNED(addr + common->ytop_off) ||
!ISALIGNED(addr + common->ybtm_off) ||
!ISALIGNED(addr + common->ctop_off) ||
!ISALIGNED(addr + common->cbtm_off))
goto buf_align_exit;
}
return 0;
buf_align_exit:
vpif_err("buffer offset not aligned to 8 bytes\n");
return -EINVAL;
}
static int vpif_buffer_setup(struct videobuf_queue *q, unsigned int *count,
unsigned int *size)
{
struct vpif_fh *fh = q->priv_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
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
struct common_obj *common;
common = &fh->channel->common[VPIF_VIDEO_INDEX];
list_add_tail(&vb->queue, &common->dma_queue);
vb->state = VIDEOBUF_QUEUED;
}
static void vpif_buffer_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct vpif_fh *fh = q->priv_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common;
unsigned int buf_size = 0;
common = &ch->common[VPIF_VIDEO_INDEX];
videobuf_dma_contig_free(q, vb);
vb->state = VIDEOBUF_NEEDS_INIT;
if (V4L2_MEMORY_MMAP != common->memory)
return;
buf_size = config_params.channel_bufsize[ch->channel_id];
}
static void process_progressive_mode(struct common_obj *common)
{
unsigned long addr = 0;
common->next_frm = list_entry(common->dma_queue.next,
struct videobuf_buffer, queue);
list_del(&common->next_frm->queue);
common->next_frm->state = VIDEOBUF_ACTIVE;
addr = videobuf_to_dma_contig(common->next_frm);
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
do_gettimeofday(&common->cur_frm->ts);
common->cur_frm->state = VIDEOBUF_DONE;
wake_up_interruptible(&common->cur_frm->done);
common->cur_frm = common->next_frm;
} else if (1 == fid) {
if (list_empty(&common->dma_queue)
|| (common->cur_frm != common->next_frm)) {
return;
}
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
ch = dev->dev[channel_id];
field = ch->common[VPIF_VIDEO_INDEX].fmt.fmt.pix.field;
for (i = 0; i < VPIF_NUMOBJECTS; i++) {
common = &ch->common[i];
if (0 == common->started)
continue;
if (1 == ch->vpifparams.std_info.frm_fmt) {
if (list_empty(&common->dma_queue))
continue;
if (!channel_first_int[i][channel_id]) {
do_gettimeofday(&common->cur_frm->ts);
common->cur_frm->state = VIDEOBUF_DONE;
wake_up_interruptible(&common->cur_frm->done);
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
config = &ch_params[i];
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
if (!vid_ch->stdid && !vid_ch->dv_preset && !vid_ch->bt_timings.height)
return -EINVAL;
if (vid_ch->stdid || vid_ch->dv_preset) {
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
if (V4L2_MEMORY_USERPTR == common->memory)
sizeimage = pixfmt->sizeimage;
else
sizeimage = config_params.channel_bufsize[ch->channel_id];
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
vpif_dbg(2, debug, "vpif_mmap\n");
return videobuf_mmap_mapper(&common->buffer_queue, vma);
}
static unsigned int vpif_poll(struct file *filep, poll_table *wait)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (common->started)
return videobuf_poll_stream(filep, &common->buffer_queue, wait);
return 0;
}
static int vpif_open(struct file *filep)
{
struct video_device *vdev = video_devdata(filep);
struct channel_obj *ch = NULL;
struct vpif_fh *fh = NULL;
ch = video_get_drvdata(vdev);
fh = kzalloc(sizeof(struct vpif_fh), GFP_KERNEL);
if (fh == NULL) {
vpif_err("unable to allocate memory for file handle object\n");
return -ENOMEM;
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
return 0;
}
static int vpif_release(struct file *filep)
{
struct vpif_fh *fh = filep->private_data;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (fh->io_allowed[VPIF_VIDEO_INDEX]) {
common->io_usrs = 0;
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
videobuf_queue_cancel(&common->buffer_queue);
videobuf_mmap_free(&common->buffer_queue);
common->numbuffers =
config_params.numbuffers[ch->channel_id];
}
atomic_dec(&ch->usrs);
if (fh->initialized)
ch->initialized = 0;
v4l2_prio_close(&ch->prio, fh->prio);
filep->private_data = NULL;
fh->initialized = 0;
kfree(fh);
return 0;
}
static int vpif_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vpif_display_config *config = vpif_dev->platform_data;
cap->version = VPIF_DISPLAY_VERSION_CODE;
cap->capabilities = V4L2_CAP_VIDEO_OUTPUT | V4L2_CAP_STREAMING;
strlcpy(cap->driver, "vpif display", sizeof(cap->driver));
strlcpy(cap->bus_info, "Platform", sizeof(cap->bus_info));
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
u8 index = 0;
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
if (common->fmt.type != reqbuf->type)
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
videobuf_queue_dma_contig_init(&common->buffer_queue,
&video_qops, NULL,
&common->irqlock,
reqbuf->type, field,
sizeof(struct videobuf_buffer), fh,
&common->lock);
fh->io_allowed[index] = 1;
common->io_usrs = 1;
common->memory = reqbuf->memory;
INIT_LIST_HEAD(&common->dma_queue);
return videobuf_reqbufs(&common->buffer_queue, reqbuf);
}
static int vpif_querybuf(struct file *file, void *priv,
struct v4l2_buffer *tbuf)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
if (common->fmt.type != tbuf->type)
return -EINVAL;
return videobuf_querybuf(&common->buffer_queue, tbuf);
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
if (common->fmt.type != tbuf.type)
return -EINVAL;
if (!fh->io_allowed[VPIF_VIDEO_INDEX]) {
vpif_err("fh->io_allowed\n");
return -EACCES;
}
if (!(list_empty(&common->dma_queue)) ||
(common->cur_frm != common->next_frm) ||
!(common->started) ||
(common->started && (0 == ch->field_id)))
return videobuf_qbuf(&common->buffer_queue, buf);
mutex_lock(&common->buffer_queue.vb_lock);
buf1 = common->buffer_queue.bufs[tbuf.index];
if (buf1->memory != tbuf.memory) {
vpif_err("invalid buffer type\n");
goto qbuf_exit;
}
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
addr = buf1->boff;
common->next_frm = buf1;
if (tbuf.type != V4L2_BUF_TYPE_SLICED_VBI_OUTPUT) {
common->set_addr((addr + common->ytop_off),
(addr + common->ybtm_off),
(addr + common->ctop_off),
(addr + common->cbtm_off));
}
local_irq_restore(flags);
list_add_tail(&buf1->stream, &common->buffer_queue.stream);
mutex_unlock(&common->buffer_queue.vb_lock);
return 0;
qbuf_exit:
mutex_unlock(&common->buffer_queue.vb_lock);
return -EINVAL;
}
static int vpif_s_std(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret = 0;
if (!(*std_id & DM646X_V4L2_STD))
return -EINVAL;
if (common->started) {
vpif_err("streaming in progress\n");
return -EBUSY;
}
ch->video.stdid = *std_id;
ch->video.dv_preset = V4L2_DV_INVALID;
memset(&ch->video.bt_timings, 0, sizeof(ch->video.bt_timings));
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
s_std_output, *std_id);
if (ret < 0) {
vpif_err("Failed to set output standard\n");
return ret;
}
ret = v4l2_device_call_until_err(&vpif_obj.v4l2_dev, 1, core,
s_std, *std_id);
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
return videobuf_dqbuf(&common->buffer_queue, p,
(file->f_flags & O_NONBLOCK));
}
static int vpif_streamon(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct channel_obj *oth_ch = vpif_obj.dev[!ch->channel_id];
struct vpif_params *vpif = &ch->vpifparams;
struct vpif_display_config *vpif_config_data =
vpif_dev->platform_data;
unsigned long addr = 0;
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
ret = videobuf_streamon(&common->buffer_queue);
if (ret < 0) {
vpif_err("videobuf_streamon\n");
return ret;
}
if (list_empty(&common->dma_queue)) {
vpif_err("buffer queue is empty\n");
return -EIO;
}
common->next_frm = common->cur_frm =
list_entry(common->dma_queue.next,
struct videobuf_buffer, queue);
list_del(&common->cur_frm->queue);
common->cur_frm->state = VIDEOBUF_ACTIVE;
ch->field_id = 0;
common->started = 1;
if (buftype == V4L2_BUF_TYPE_VIDEO_OUTPUT) {
addr = common->cur_frm->boff;
vpif_calculate_offsets(ch);
if ((ch->vpifparams.std_info.frm_fmt &&
((common->fmt.fmt.pix.field != V4L2_FIELD_NONE)
&& (common->fmt.fmt.pix.field != V4L2_FIELD_ANY)))
|| (!ch->vpifparams.std_info.frm_fmt
&& (common->fmt.fmt.pix.field == V4L2_FIELD_NONE))) {
vpif_err("conflict in field format and std format\n");
return -EINVAL;
}
ret =
vpif_config_data->set_clock(ch->vpifparams.std_info.ycmux_mode,
ch->vpifparams.std_info.hd_sd);
if (ret < 0) {
vpif_err("can't set clock\n");
return ret;
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
if (VPIF_CHANNEL2_VIDEO == ch->channel_id) {
channel2_intr_assert();
channel2_intr_enable(1);
enable_channel2(1);
}
if ((VPIF_CHANNEL3_VIDEO == ch->channel_id)
|| (common->started == 2)) {
channel3_intr_assert();
channel3_intr_enable(1);
enable_channel3(1);
}
channel_first_int[VPIF_VIDEO_INDEX][ch->channel_id] = 1;
}
return ret;
}
static int vpif_streamoff(struct file *file, void *priv,
enum v4l2_buf_type buftype)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
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
enable_channel2(0);
channel2_intr_enable(0);
}
if ((VPIF_CHANNEL3_VIDEO == ch->channel_id) ||
(2 == common->started)) {
enable_channel3(0);
channel3_intr_enable(0);
}
}
common->started = 0;
return videobuf_streamoff(&common->buffer_queue);
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
if (output->index >= config->output_count) {
vpif_dbg(1, debug, "Invalid output index\n");
return -EINVAL;
}
strcpy(output->name, config->output[output->index]);
output->type = V4L2_OUTPUT_TYPE_ANALOG;
output->std = DM646X_V4L2_STD;
return 0;
}
static int vpif_s_output(struct file *file, void *priv, unsigned int i)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct video_obj *vid_ch = &ch->video;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
int ret = 0;
if (common->started) {
vpif_err("Streaming in progress\n");
return -EBUSY;
}
ret = v4l2_device_call_until_err(&vpif_obj.v4l2_dev, 1, video,
s_routing, 0, i, 0);
if (ret < 0)
vpif_err("Failed to set output standard\n");
vid_ch->output_id = i;
return ret;
}
static int vpif_g_output(struct file *file, void *priv, unsigned int *i)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct video_obj *vid_ch = &ch->video;
*i = vid_ch->output_id;
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
static int vpif_enum_dv_presets(struct file *file, void *priv,
struct v4l2_dv_enum_preset *preset)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct video_obj *vid_ch = &ch->video;
return v4l2_subdev_call(vpif_obj.sd[vid_ch->output_id],
video, enum_dv_presets, preset);
}
static int vpif_s_dv_preset(struct file *file, void *priv,
struct v4l2_dv_preset *preset)
{
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct common_obj *common = &ch->common[VPIF_VIDEO_INDEX];
struct video_obj *vid_ch = &ch->video;
int ret = 0;
if (common->started) {
vpif_dbg(1, debug, "streaming in progress\n");
return -EBUSY;
}
ret = v4l2_prio_check(&ch->prio, fh->prio);
if (ret != 0)
return ret;
fh->initialized = 1;
if (mutex_lock_interruptible(&common->lock))
return -ERESTARTSYS;
ch->video.dv_preset = preset->preset;
ch->video.stdid = V4L2_STD_UNKNOWN;
memset(&ch->video.bt_timings, 0, sizeof(ch->video.bt_timings));
if (vpif_update_resolution(ch)) {
ret = -EINVAL;
} else {
vpif_config_format(ch);
ret = v4l2_subdev_call(vpif_obj.sd[vid_ch->output_id],
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
ret = v4l2_subdev_call(vpif_obj.sd[vid_ch->output_id],
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
struct video_obj *vid_ch = &ch->video;
return v4l2_subdev_call(vpif_obj.sd[vid_ch->output_id], core,
g_register, reg);
}
static int vpif_dbg_s_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg){
struct vpif_fh *fh = priv;
struct channel_obj *ch = fh->channel;
struct video_obj *vid_ch = &ch->video;
return v4l2_subdev_call(vpif_obj.sd[vid_ch->output_id], core,
s_register, reg);
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
static __init int vpif_probe(struct platform_device *pdev)
{
struct vpif_subdev_info *subdevdata;
struct vpif_display_config *config;
int i, j = 0, k, q, m, err = 0;
struct i2c_adapter *i2c_adap;
struct common_obj *common;
struct channel_obj *ch;
struct video_device *vfd;
struct resource *res;
int subdev_count;
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
k = 0;
while ((res = platform_get_resource(pdev, IORESOURCE_IRQ, k))) {
for (i = res->start; i <= res->end; i++) {
if (request_irq(i, vpif_channel_isr, IRQF_DISABLED,
"DM646x_Display",
(void *)(&vpif_obj.dev[k]->channel_id))) {
err = -EBUSY;
goto vpif_int_err;
}
}
k++;
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
goto vpif_int_err;
}
*vfd = vpif_video_template;
vfd->v4l2_dev = &vpif_obj.v4l2_dev;
vfd->release = video_device_release;
snprintf(vfd->name, sizeof(vfd->name),
"DM646x_VPIFDisplay_DRIVER_V%d.%d.%d",
(VPIF_DISPLAY_VERSION_CODE >> 16) & 0xff,
(VPIF_DISPLAY_VERSION_CODE >> 8) & 0xff,
(VPIF_DISPLAY_VERSION_CODE) & 0xff);
ch->video_dev = vfd;
}
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
common->ytop_off = common->ybtm_off = 0;
common->ctop_off = common->cbtm_off = 0;
common->cur_frm = common->next_frm = NULL;
memset(&common->fmt, 0, sizeof(common->fmt));
common->numbuffers = config_params.numbuffers[k];
}
ch->initialized = 0;
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
vpif_dbg(1, debug, "channel=%x,channel->video_dev=%x\n",
(int)ch, (int)&ch->video_dev);
err = video_register_device(ch->video_dev,
VFL_TYPE_GRABBER, (j ? 3 : 2));
if (err < 0)
goto probe_out;
video_set_drvdata(ch->video_dev, ch);
}
i2c_adap = i2c_get_adapter(1);
config = pdev->dev.platform_data;
subdev_count = config->subdev_count;
subdevdata = config->subdevinfo;
vpif_obj.sd = kzalloc(sizeof(struct v4l2_subdev *) * subdev_count,
GFP_KERNEL);
if (vpif_obj.sd == NULL) {
vpif_err("unable to allocate memory for subdevice pointers\n");
err = -ENOMEM;
goto probe_out;
}
for (i = 0; i < subdev_count; i++) {
vpif_obj.sd[i] = v4l2_i2c_new_subdev_board(&vpif_obj.v4l2_dev,
i2c_adap,
&subdevdata[i].board_info,
NULL);
if (!vpif_obj.sd[i]) {
vpif_err("Error registering v4l2 subdevice\n");
goto probe_subdev_out;
}
if (vpif_obj.sd[i])
vpif_obj.sd[i]->grp_id = 1 << i;
}
v4l2_info(&vpif_obj.v4l2_dev,
"DM646x VPIF display driver initialized\n");
return 0;
probe_subdev_out:
kfree(vpif_obj.sd);
probe_out:
for (k = 0; k < j; k++) {
ch = vpif_obj.dev[k];
video_unregister_device(ch->video_dev);
video_device_release(ch->video_dev);
ch->video_dev = NULL;
}
vpif_int_err:
v4l2_device_unregister(&vpif_obj.v4l2_dev);
vpif_err("VPIF IRQ request failed\n");
for (q = k; k >= 0; k--) {
for (m = i; m >= res->start; m--)
free_irq(m, (void *)(&vpif_obj.dev[k]->channel_id));
res = platform_get_resource(pdev, IORESOURCE_IRQ, k-1);
m = res->end;
}
return err;
}
static int vpif_remove(struct platform_device *device)
{
struct channel_obj *ch;
int i;
v4l2_device_unregister(&vpif_obj.v4l2_dev);
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++) {
ch = vpif_obj.dev[i];
video_unregister_device(ch->video_dev);
ch->video_dev = NULL;
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
for (i = 0; i < VPIF_DISPLAY_MAX_DEVICES; i++)
kfree(vpif_obj.dev[i]);
}
