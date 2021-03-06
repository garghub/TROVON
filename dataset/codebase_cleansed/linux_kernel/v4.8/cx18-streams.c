static void cx18_dma_free(struct videobuf_queue *q,
struct cx18_stream *s, struct cx18_videobuf_buffer *buf)
{
videobuf_waiton(q, &buf->vb, 0, 0);
videobuf_vmalloc_free(&buf->vb);
buf->vb.state = VIDEOBUF_NEEDS_INIT;
}
static int cx18_prepare_buffer(struct videobuf_queue *q,
struct cx18_stream *s,
struct cx18_videobuf_buffer *buf,
u32 pixelformat,
unsigned int width, unsigned int height,
enum v4l2_field field)
{
struct cx18 *cx = s->cx;
int rc = 0;
buf->bytes_used = 0;
if ((width < 48) || (height < 32))
return -EINVAL;
buf->vb.size = (width * height * 2);
if ((buf->vb.baddr != 0) && (buf->vb.bsize < buf->vb.size))
return -EINVAL;
if (buf->vb.width != width || buf->vb.height != height ||
buf->vb.field != field || s->pixelformat != pixelformat ||
buf->tvnorm != cx->std) {
buf->vb.width = width;
buf->vb.height = height;
buf->vb.field = field;
buf->tvnorm = cx->std;
s->pixelformat = pixelformat;
if (s->pixelformat == V4L2_PIX_FMT_HM12)
s->vb_bytes_per_frame = height * 720 * 3 / 2;
else
s->vb_bytes_per_frame = height * 720 * 2;
cx18_dma_free(q, s, buf);
}
if ((buf->vb.baddr != 0) && (buf->vb.bsize < buf->vb.size))
return -EINVAL;
if (buf->vb.field == 0)
buf->vb.field = V4L2_FIELD_INTERLACED;
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
buf->vb.width = width;
buf->vb.height = height;
buf->vb.field = field;
buf->tvnorm = cx->std;
s->pixelformat = pixelformat;
if (s->pixelformat == V4L2_PIX_FMT_HM12)
s->vb_bytes_per_frame = height * 720 * 3 / 2;
else
s->vb_bytes_per_frame = height * 720 * 2;
rc = videobuf_iolock(q, &buf->vb, NULL);
if (rc != 0)
goto fail;
}
buf->vb.state = VIDEOBUF_PREPARED;
return 0;
fail:
cx18_dma_free(q, s, buf);
return rc;
}
static int buffer_setup(struct videobuf_queue *q,
unsigned int *count, unsigned int *size)
{
struct cx18_stream *s = q->priv_data;
struct cx18 *cx = s->cx;
*size = 2 * cx->cxhdl.width * cx->cxhdl.height;
if (*count == 0)
*count = VB_MIN_BUFFERS;
while (*size * *count > VB_MIN_BUFFERS * VB_MIN_BUFSIZE)
(*count)--;
q->field = V4L2_FIELD_INTERLACED;
q->last = V4L2_FIELD_INTERLACED;
return 0;
}
static int buffer_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct cx18_videobuf_buffer *buf =
container_of(vb, struct cx18_videobuf_buffer, vb);
struct cx18_stream *s = q->priv_data;
struct cx18 *cx = s->cx;
return cx18_prepare_buffer(q, s, buf, s->pixelformat,
cx->cxhdl.width, cx->cxhdl.height, field);
}
static void buffer_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct cx18_videobuf_buffer *buf =
container_of(vb, struct cx18_videobuf_buffer, vb);
struct cx18_stream *s = q->priv_data;
cx18_dma_free(q, s, buf);
}
static void buffer_queue(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct cx18_videobuf_buffer *buf =
container_of(vb, struct cx18_videobuf_buffer, vb);
struct cx18_stream *s = q->priv_data;
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue, &s->vb_capture);
}
static void cx18_stream_init(struct cx18 *cx, int type)
{
struct cx18_stream *s = &cx->streams[type];
memset(s, 0, sizeof(*s));
s->dvb = NULL;
s->cx = cx;
s->type = type;
s->name = cx18_stream_info[type].name;
s->handle = CX18_INVALID_TASK_HANDLE;
s->dma = cx18_stream_info[type].dma;
s->v4l2_dev_caps = cx18_stream_info[type].caps;
s->buffers = cx->stream_buffers[type];
s->buf_size = cx->stream_buf_size[type];
INIT_LIST_HEAD(&s->buf_pool);
s->bufs_per_mdl = 1;
s->mdl_size = s->buf_size * s->bufs_per_mdl;
init_waitqueue_head(&s->waitq);
s->id = -1;
spin_lock_init(&s->q_free.lock);
cx18_queue_init(&s->q_free);
spin_lock_init(&s->q_busy.lock);
cx18_queue_init(&s->q_busy);
spin_lock_init(&s->q_full.lock);
cx18_queue_init(&s->q_full);
spin_lock_init(&s->q_idle.lock);
cx18_queue_init(&s->q_idle);
INIT_WORK(&s->out_work_order, cx18_out_work_handler);
INIT_LIST_HEAD(&s->vb_capture);
s->vb_timeout.function = cx18_vb_timeout;
s->vb_timeout.data = (unsigned long)s;
init_timer(&s->vb_timeout);
spin_lock_init(&s->vb_lock);
if (type == CX18_ENC_STREAM_TYPE_YUV) {
spin_lock_init(&s->vbuf_q_lock);
s->vb_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
videobuf_queue_vmalloc_init(&s->vbuf_q, &cx18_videobuf_qops,
&cx->pci_dev->dev, &s->vbuf_q_lock,
V4L2_BUF_TYPE_VIDEO_CAPTURE,
V4L2_FIELD_INTERLACED,
sizeof(struct cx18_videobuf_buffer),
s, &cx->serialize_lock);
s->pixelformat = V4L2_PIX_FMT_HM12;
s->vb_bytes_per_frame = cx->cxhdl.height * 720 * 3 / 2;
s->vb_bytes_per_line = 720;
}
}
static int cx18_prep_dev(struct cx18 *cx, int type)
{
struct cx18_stream *s = &cx->streams[type];
u32 cap = cx->v4l2_cap;
int num_offset = cx18_stream_info[type].num_offset;
int num = cx->instance + cx18_first_minor + num_offset;
s->video_dev.v4l2_dev = NULL;
s->dvb = NULL;
s->cx = cx;
s->type = type;
s->name = cx18_stream_info[type].name;
if (type == CX18_ENC_STREAM_TYPE_RAD && !(cap & V4L2_CAP_RADIO))
return 0;
if (type == CX18_ENC_STREAM_TYPE_VBI &&
!(cap & (V4L2_CAP_VBI_CAPTURE | V4L2_CAP_SLICED_VBI_CAPTURE)))
return 0;
if (cx18_stream_info[type].dma != PCI_DMA_NONE &&
cx->stream_buffers[type] == 0) {
CX18_INFO("Disabled %s device\n", cx18_stream_info[type].name);
return 0;
}
cx18_stream_init(cx, type);
if (type == CX18_ENC_STREAM_TYPE_TS) {
if (cx->card->hw_all & CX18_HW_DVB) {
s->dvb = kzalloc(sizeof(struct cx18_dvb), GFP_KERNEL);
if (s->dvb == NULL) {
CX18_ERR("Couldn't allocate cx18_dvb structure"
" for %s\n", s->name);
return -ENOMEM;
}
} else {
s->buffers = 0;
}
}
if (num_offset == -1)
return 0;
snprintf(s->video_dev.name, sizeof(s->video_dev.name), "%s %s",
cx->v4l2_dev.name, s->name);
s->video_dev.num = num;
s->video_dev.v4l2_dev = &cx->v4l2_dev;
s->video_dev.fops = &cx18_v4l2_enc_fops;
s->video_dev.release = video_device_release_empty;
if (cx->card->video_inputs->video_type == CX18_CARD_INPUT_VID_TUNER)
s->video_dev.tvnorms = cx->tuner_std;
else
s->video_dev.tvnorms = V4L2_STD_ALL;
s->video_dev.lock = &cx->serialize_lock;
cx18_set_funcs(&s->video_dev);
return 0;
}
int cx18_streams_setup(struct cx18 *cx)
{
int type, ret;
for (type = 0; type < CX18_MAX_STREAMS; type++) {
ret = cx18_prep_dev(cx, type);
if (ret < 0)
break;
ret = cx18_stream_alloc(&cx->streams[type]);
if (ret < 0)
break;
}
if (type == CX18_MAX_STREAMS)
return 0;
cx18_streams_cleanup(cx, 0);
return ret;
}
static int cx18_reg_dev(struct cx18 *cx, int type)
{
struct cx18_stream *s = &cx->streams[type];
int vfl_type = cx18_stream_info[type].vfl_type;
const char *name;
int num, ret;
if (type == CX18_ENC_STREAM_TYPE_TS && s->dvb != NULL) {
ret = cx18_dvb_register(s);
if (ret < 0) {
CX18_ERR("DVB failed to register\n");
return ret;
}
}
if (s->video_dev.v4l2_dev == NULL)
return 0;
num = s->video_dev.num;
if (type != CX18_ENC_STREAM_TYPE_MPG) {
struct cx18_stream *s_mpg = &cx->streams[CX18_ENC_STREAM_TYPE_MPG];
if (s_mpg->video_dev.v4l2_dev)
num = s_mpg->video_dev.num
+ cx18_stream_info[type].num_offset;
}
video_set_drvdata(&s->video_dev, s);
ret = video_register_device_no_warn(&s->video_dev, vfl_type, num);
if (ret < 0) {
CX18_ERR("Couldn't register v4l2 device for %s (device node number %d)\n",
s->name, num);
s->video_dev.v4l2_dev = NULL;
return ret;
}
name = video_device_node_name(&s->video_dev);
switch (vfl_type) {
case VFL_TYPE_GRABBER:
CX18_INFO("Registered device %s for %s (%d x %d.%02d kB)\n",
name, s->name, cx->stream_buffers[type],
cx->stream_buf_size[type] / 1024,
(cx->stream_buf_size[type] * 100 / 1024) % 100);
break;
case VFL_TYPE_RADIO:
CX18_INFO("Registered device %s for %s\n", name, s->name);
break;
case VFL_TYPE_VBI:
if (cx->stream_buffers[type])
CX18_INFO("Registered device %s for %s "
"(%d x %d bytes)\n",
name, s->name, cx->stream_buffers[type],
cx->stream_buf_size[type]);
else
CX18_INFO("Registered device %s for %s\n",
name, s->name);
break;
}
return 0;
}
int cx18_streams_register(struct cx18 *cx)
{
int type;
int err;
int ret = 0;
for (type = 0; type < CX18_MAX_STREAMS; type++) {
err = cx18_reg_dev(cx, type);
if (err && ret == 0)
ret = err;
}
if (ret == 0)
return 0;
cx18_streams_cleanup(cx, 1);
return ret;
}
void cx18_streams_cleanup(struct cx18 *cx, int unregister)
{
struct video_device *vdev;
int type;
for (type = 0; type < CX18_MAX_STREAMS; type++) {
if (type == CX18_ENC_STREAM_TYPE_TS) {
if (cx->streams[type].dvb != NULL) {
if (unregister)
cx18_dvb_unregister(&cx->streams[type]);
kfree(cx->streams[type].dvb);
cx->streams[type].dvb = NULL;
cx18_stream_free(&cx->streams[type]);
}
continue;
}
if (type == CX18_ENC_STREAM_TYPE_IDX) {
if (cx->stream_buffers[type] != 0) {
cx->stream_buffers[type] = 0;
if (cx->streams[type].buffers != 0)
cx18_stream_free(&cx->streams[type]);
}
continue;
}
vdev = &cx->streams[type].video_dev;
if (vdev->v4l2_dev == NULL)
continue;
if (type == CX18_ENC_STREAM_TYPE_YUV)
videobuf_mmap_free(&cx->streams[type].vbuf_q);
cx18_stream_free(&cx->streams[type]);
video_unregister_device(vdev);
}
}
static void cx18_vbi_setup(struct cx18_stream *s)
{
struct cx18 *cx = s->cx;
int raw = cx18_raw_vbi(cx);
u32 data[CX2341X_MBOX_MAX_DATA];
int lines;
if (cx->is_60hz) {
cx->vbi.count = 12;
cx->vbi.start[0] = 10;
cx->vbi.start[1] = 273;
} else {
cx->vbi.count = 18;
cx->vbi.start[0] = 6;
cx->vbi.start[1] = 318;
}
if (raw)
v4l2_subdev_call(cx->sd_av, vbi, s_raw_fmt, &cx->vbi.in.fmt.vbi);
else
v4l2_subdev_call(cx->sd_av, vbi, s_sliced_fmt, &cx->vbi.in.fmt.sliced);
if (raw) {
lines = cx->vbi.count * 2;
} else {
lines = cx->is_60hz ? (21 - 4 + 1) * 2 : (23 - 2 + 1) * 2;
}
data[0] = s->handle;
data[1] = (lines / 2) | ((lines / 2) << 16);
data[2] = (raw ? VBI_ACTIVE_SAMPLES
: (cx->is_60hz ? VBI_HBLANK_SAMPLES_60HZ
: VBI_HBLANK_SAMPLES_50HZ));
data[3] = 1;
if (raw) {
data[4] = 0x20602060;
data[5] = 0x307090d0;
} else {
data[4] = 0xB0F0B0F0;
data[5] = 0xA0E0A0E0;
}
CX18_DEBUG_INFO("Setup VBI h: %d lines %x bpl %d fr %d %x %x\n",
data[0], data[1], data[2], data[3], data[4], data[5]);
cx18_api(cx, CX18_CPU_SET_RAW_VBI_PARAM, 6, data);
}
void cx18_stream_rotate_idx_mdls(struct cx18 *cx)
{
struct cx18_stream *s = &cx->streams[CX18_ENC_STREAM_TYPE_IDX];
struct cx18_mdl *mdl;
if (!cx18_stream_enabled(s))
return;
if ((atomic_read(&s->q_free.depth) + atomic_read(&s->q_busy.depth)) >=
CX18_ENC_STREAM_TYPE_IDX_FW_MDL_MIN)
return;
if (atomic_read(&s->q_full.depth) < 2)
return;
mdl = cx18_dequeue(s, &s->q_full);
if (mdl != NULL)
cx18_enqueue(s, mdl, &s->q_free);
}
static
struct cx18_queue *_cx18_stream_put_mdl_fw(struct cx18_stream *s,
struct cx18_mdl *mdl)
{
struct cx18 *cx = s->cx;
struct cx18_queue *q;
if (s->handle == CX18_INVALID_TASK_HANDLE ||
test_bit(CX18_F_S_STOPPING, &s->s_flags) ||
!test_bit(CX18_F_S_STREAMING, &s->s_flags))
return cx18_enqueue(s, mdl, &s->q_free);
q = cx18_enqueue(s, mdl, &s->q_busy);
if (q != &s->q_busy)
return q;
cx18_mdl_sync_for_device(s, mdl);
cx18_vapi(cx, CX18_CPU_DE_SET_MDL, 5, s->handle,
(void __iomem *) &cx->scb->cpu_mdl[mdl->id] - cx->enc_mem,
s->bufs_per_mdl, mdl->id, s->mdl_size);
return q;
}
static
void _cx18_stream_load_fw_queue(struct cx18_stream *s)
{
struct cx18_queue *q;
struct cx18_mdl *mdl;
if (atomic_read(&s->q_free.depth) == 0 ||
atomic_read(&s->q_busy.depth) >= CX18_MAX_FW_MDLS_PER_STREAM)
return;
do {
mdl = cx18_dequeue(s, &s->q_free);
if (mdl == NULL)
break;
q = _cx18_stream_put_mdl_fw(s, mdl);
} while (atomic_read(&s->q_busy.depth) < CX18_MAX_FW_MDLS_PER_STREAM
&& q == &s->q_busy);
}
void cx18_out_work_handler(struct work_struct *work)
{
struct cx18_stream *s =
container_of(work, struct cx18_stream, out_work_order);
_cx18_stream_load_fw_queue(s);
}
static void cx18_stream_configure_mdls(struct cx18_stream *s)
{
cx18_unload_queues(s);
switch (s->type) {
case CX18_ENC_STREAM_TYPE_YUV:
if (s->pixelformat == V4L2_PIX_FMT_HM12)
s->mdl_size = 720 * s->cx->cxhdl.height * 3 / 2;
else
s->mdl_size = 720 * s->cx->cxhdl.height * 2;
s->bufs_per_mdl = s->mdl_size / s->buf_size;
if (s->mdl_size % s->buf_size)
s->bufs_per_mdl++;
break;
case CX18_ENC_STREAM_TYPE_VBI:
s->bufs_per_mdl = 1;
if (cx18_raw_vbi(s->cx)) {
s->mdl_size = (s->cx->is_60hz ? 12 : 18)
* 2 * VBI_ACTIVE_SAMPLES;
} else {
s->mdl_size = s->cx->is_60hz
? (21 - 4 + 1) * 2 * VBI_HBLANK_SAMPLES_60HZ
: (23 - 2 + 1) * 2 * VBI_HBLANK_SAMPLES_50HZ;
}
break;
default:
s->bufs_per_mdl = 1;
s->mdl_size = s->buf_size * s->bufs_per_mdl;
break;
}
cx18_load_queues(s);
}
int cx18_start_v4l2_encode_stream(struct cx18_stream *s)
{
u32 data[MAX_MB_ARGUMENTS];
struct cx18 *cx = s->cx;
int captype = 0;
struct cx18_stream *s_idx;
if (!cx18_stream_enabled(s))
return -EINVAL;
CX18_DEBUG_INFO("Start encoder stream %s\n", s->name);
switch (s->type) {
case CX18_ENC_STREAM_TYPE_MPG:
captype = CAPTURE_CHANNEL_TYPE_MPEG;
cx->mpg_data_received = cx->vbi_data_inserted = 0;
cx->dualwatch_jiffies = jiffies;
cx->dualwatch_stereo_mode = v4l2_ctrl_g_ctrl(cx->cxhdl.audio_mode);
cx->search_pack_header = 0;
break;
case CX18_ENC_STREAM_TYPE_IDX:
captype = CAPTURE_CHANNEL_TYPE_INDEX;
break;
case CX18_ENC_STREAM_TYPE_TS:
captype = CAPTURE_CHANNEL_TYPE_TS;
break;
case CX18_ENC_STREAM_TYPE_YUV:
captype = CAPTURE_CHANNEL_TYPE_YUV;
break;
case CX18_ENC_STREAM_TYPE_PCM:
captype = CAPTURE_CHANNEL_TYPE_PCM;
break;
case CX18_ENC_STREAM_TYPE_VBI:
#ifdef CX18_ENCODER_PARSES_SLICED
captype = cx18_raw_vbi(cx) ?
CAPTURE_CHANNEL_TYPE_VBI : CAPTURE_CHANNEL_TYPE_SLICED_VBI;
#else
captype = CAPTURE_CHANNEL_TYPE_VBI;
#endif
cx->vbi.frame = 0;
cx->vbi.inserted_frame = 0;
memset(cx->vbi.sliced_mpeg_size,
0, sizeof(cx->vbi.sliced_mpeg_size));
break;
default:
return -EINVAL;
}
clear_bit(CX18_F_S_STREAMOFF, &s->s_flags);
cx18_vapi_result(cx, data, CX18_CREATE_TASK, 1, CPU_CMD_MASK_CAPTURE);
s->handle = data[0];
cx18_vapi(cx, CX18_CPU_SET_CHANNEL_TYPE, 2, s->handle, captype);
if (captype != CAPTURE_CHANNEL_TYPE_TS) {
cx18_vapi(cx, CX18_CPU_SET_VER_CROP_LINE, 2, s->handle, 0);
cx18_vapi(cx, CX18_CPU_SET_MISC_PARAMETERS, 3, s->handle, 3, 1);
cx18_vapi(cx, CX18_CPU_SET_MISC_PARAMETERS, 3, s->handle, 8, 0);
cx18_vapi(cx, CX18_CPU_SET_MISC_PARAMETERS, 3, s->handle, 4, 1);
if (atomic_read(&cx->ana_capturing) == 0)
cx18_vapi(cx, CX18_CPU_SET_MISC_PARAMETERS, 2,
s->handle, 12);
cx18_vapi(cx, CX18_CPU_SET_CAPTURE_LINE_NO, 3,
s->handle, 312, 313);
if (cx->v4l2_cap & V4L2_CAP_VBI_CAPTURE)
cx18_vbi_setup(s);
s_idx = &cx->streams[CX18_ENC_STREAM_TYPE_IDX];
cx18_vapi_result(cx, data, CX18_CPU_SET_INDEXTABLE, 2,
s->handle, cx18_stream_enabled(s_idx) ? 7 : 0);
cx->cxhdl.priv = s;
cx2341x_handler_setup(&cx->cxhdl);
if (!cx->cxhdl.video_mute &&
test_bit(CX18_F_I_RADIO_USER, &cx->i_flags))
cx18_vapi(cx, CX18_CPU_SET_VIDEO_MUTE, 2, s->handle,
(v4l2_ctrl_g_ctrl(cx->cxhdl.video_mute_yuv) << 8) | 1);
if (captype == CAPTURE_CHANNEL_TYPE_YUV) {
if (s->pixelformat == V4L2_PIX_FMT_UYVY)
cx18_vapi(cx, CX18_CPU_SET_VFC_PARAM, 2,
s->handle, 1);
else
cx18_vapi(cx, CX18_CPU_SET_VFC_PARAM, 2,
s->handle, 0);
}
}
if (atomic_read(&cx->tot_capturing) == 0) {
cx2341x_handler_set_busy(&cx->cxhdl, 1);
clear_bit(CX18_F_I_EOS, &cx->i_flags);
cx18_write_reg(cx, 7, CX18_DSP0_INTERRUPT_MASK);
}
cx18_vapi(cx, CX18_CPU_DE_SET_MDL_ACK, 3, s->handle,
(void __iomem *)&cx->scb->cpu_mdl_ack[s->type][0] - cx->enc_mem,
(void __iomem *)&cx->scb->cpu_mdl_ack[s->type][1] - cx->enc_mem);
cx18_stream_configure_mdls(s);
_cx18_stream_load_fw_queue(s);
if (cx18_vapi(cx, CX18_CPU_CAPTURE_START, 1, s->handle)) {
CX18_DEBUG_WARN("Error starting capture!\n");
set_bit(CX18_F_S_STOPPING, &s->s_flags);
if (s->type == CX18_ENC_STREAM_TYPE_MPG)
cx18_vapi(cx, CX18_CPU_CAPTURE_STOP, 2, s->handle, 1);
else
cx18_vapi(cx, CX18_CPU_CAPTURE_STOP, 1, s->handle);
clear_bit(CX18_F_S_STREAMING, &s->s_flags);
cx18_vapi(cx, CX18_CPU_DE_RELEASE_MDL, 1, s->handle);
cx18_vapi(cx, CX18_DESTROY_TASK, 1, s->handle);
s->handle = CX18_INVALID_TASK_HANDLE;
clear_bit(CX18_F_S_STOPPING, &s->s_flags);
if (atomic_read(&cx->tot_capturing) == 0) {
set_bit(CX18_F_I_EOS, &cx->i_flags);
cx18_write_reg(cx, 5, CX18_DSP0_INTERRUPT_MASK);
}
return -EINVAL;
}
if (captype != CAPTURE_CHANNEL_TYPE_TS)
atomic_inc(&cx->ana_capturing);
atomic_inc(&cx->tot_capturing);
return 0;
}
void cx18_stop_all_captures(struct cx18 *cx)
{
int i;
for (i = CX18_MAX_STREAMS - 1; i >= 0; i--) {
struct cx18_stream *s = &cx->streams[i];
if (!cx18_stream_enabled(s))
continue;
if (test_bit(CX18_F_S_STREAMING, &s->s_flags))
cx18_stop_v4l2_encode_stream(s, 0);
}
}
int cx18_stop_v4l2_encode_stream(struct cx18_stream *s, int gop_end)
{
struct cx18 *cx = s->cx;
if (!cx18_stream_enabled(s))
return -EINVAL;
CX18_DEBUG_INFO("Stop Capture\n");
if (atomic_read(&cx->tot_capturing) == 0)
return 0;
set_bit(CX18_F_S_STOPPING, &s->s_flags);
if (s->type == CX18_ENC_STREAM_TYPE_MPG)
cx18_vapi(cx, CX18_CPU_CAPTURE_STOP, 2, s->handle, !gop_end);
else
cx18_vapi(cx, CX18_CPU_CAPTURE_STOP, 1, s->handle);
if (s->type == CX18_ENC_STREAM_TYPE_MPG && gop_end) {
CX18_INFO("ignoring gop_end: not (yet?) supported by the firmware\n");
}
if (s->type != CX18_ENC_STREAM_TYPE_TS)
atomic_dec(&cx->ana_capturing);
atomic_dec(&cx->tot_capturing);
clear_bit(CX18_F_S_STREAMING, &s->s_flags);
cx18_vapi(cx, CX18_CPU_DE_RELEASE_MDL, 1, s->handle);
cx18_vapi(cx, CX18_DESTROY_TASK, 1, s->handle);
s->handle = CX18_INVALID_TASK_HANDLE;
clear_bit(CX18_F_S_STOPPING, &s->s_flags);
if (atomic_read(&cx->tot_capturing) > 0)
return 0;
cx2341x_handler_set_busy(&cx->cxhdl, 0);
cx18_write_reg(cx, 5, CX18_DSP0_INTERRUPT_MASK);
wake_up(&s->waitq);
return 0;
}
u32 cx18_find_handle(struct cx18 *cx)
{
int i;
for (i = 0; i < CX18_MAX_STREAMS; i++) {
struct cx18_stream *s = &cx->streams[i];
if (s->video_dev.v4l2_dev && (s->handle != CX18_INVALID_TASK_HANDLE))
return s->handle;
}
return CX18_INVALID_TASK_HANDLE;
}
struct cx18_stream *cx18_handle_to_stream(struct cx18 *cx, u32 handle)
{
int i;
struct cx18_stream *s;
if (handle == CX18_INVALID_TASK_HANDLE)
return NULL;
for (i = 0; i < CX18_MAX_STREAMS; i++) {
s = &cx->streams[i];
if (s->handle != handle)
continue;
if (cx18_stream_enabled(s))
return s;
}
return NULL;
}
