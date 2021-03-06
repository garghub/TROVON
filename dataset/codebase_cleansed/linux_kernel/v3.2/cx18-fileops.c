int cx18_claim_stream(struct cx18_open_id *id, int type)
{
struct cx18 *cx = id->cx;
struct cx18_stream *s = &cx->streams[type];
struct cx18_stream *s_assoc;
if (type == CX18_ENC_STREAM_TYPE_IDX) {
CX18_WARN("MPEG Index stream cannot be claimed "
"directly, but something tried.\n");
return -EINVAL;
}
if (test_and_set_bit(CX18_F_S_CLAIMED, &s->s_flags)) {
if (s->id == id->open_id) {
return 0;
}
if (s->id == -1 && type == CX18_ENC_STREAM_TYPE_VBI) {
s->id = id->open_id;
CX18_DEBUG_INFO("Start Read VBI\n");
return 0;
}
CX18_DEBUG_INFO("Stream %d is busy\n", type);
return -EBUSY;
}
s->id = id->open_id;
if (type != CX18_ENC_STREAM_TYPE_MPG)
return 0;
s_assoc = &cx->streams[CX18_ENC_STREAM_TYPE_IDX];
if (cx->vbi.insert_mpeg && !cx18_raw_vbi(cx))
s_assoc = &cx->streams[CX18_ENC_STREAM_TYPE_VBI];
else if (!cx18_stream_enabled(s_assoc))
return 0;
set_bit(CX18_F_S_CLAIMED, &s_assoc->s_flags);
set_bit(CX18_F_S_INTERNAL_USE, &s_assoc->s_flags);
return 0;
}
void cx18_release_stream(struct cx18_stream *s)
{
struct cx18 *cx = s->cx;
struct cx18_stream *s_assoc;
s->id = -1;
if (s->type == CX18_ENC_STREAM_TYPE_IDX) {
return;
}
if (s->type == CX18_ENC_STREAM_TYPE_VBI &&
test_bit(CX18_F_S_INTERNAL_USE, &s->s_flags)) {
return;
}
if (!test_and_clear_bit(CX18_F_S_CLAIMED, &s->s_flags)) {
CX18_DEBUG_WARN("Release stream %s not in use!\n", s->name);
return;
}
cx18_flush_queues(s);
if (s->type != CX18_ENC_STREAM_TYPE_MPG)
return;
s_assoc = &cx->streams[CX18_ENC_STREAM_TYPE_IDX];
if (test_and_clear_bit(CX18_F_S_INTERNAL_USE, &s_assoc->s_flags)) {
clear_bit(CX18_F_S_CLAIMED, &s_assoc->s_flags);
cx18_flush_queues(s_assoc);
}
s_assoc = &cx->streams[CX18_ENC_STREAM_TYPE_VBI];
if (test_and_clear_bit(CX18_F_S_INTERNAL_USE, &s_assoc->s_flags)) {
if (s_assoc->id == -1) {
clear_bit(CX18_F_S_CLAIMED, &s_assoc->s_flags);
cx18_flush_queues(s_assoc);
}
}
}
static void cx18_dualwatch(struct cx18 *cx)
{
struct v4l2_tuner vt;
u32 new_stereo_mode;
const u32 dual = 0x0200;
new_stereo_mode = v4l2_ctrl_g_ctrl(cx->cxhdl.audio_mode);
memset(&vt, 0, sizeof(vt));
cx18_call_all(cx, tuner, g_tuner, &vt);
if (vt.audmode == V4L2_TUNER_MODE_LANG1_LANG2 &&
(vt.rxsubchans & V4L2_TUNER_SUB_LANG2))
new_stereo_mode = dual;
if (new_stereo_mode == cx->dualwatch_stereo_mode)
return;
CX18_DEBUG_INFO("dualwatch: change stereo flag from 0x%x to 0x%x.\n",
cx->dualwatch_stereo_mode, new_stereo_mode);
if (v4l2_ctrl_s_ctrl(cx->cxhdl.audio_mode, new_stereo_mode))
CX18_DEBUG_INFO("dualwatch: changing stereo flag failed\n");
}
static struct cx18_mdl *cx18_get_mdl(struct cx18_stream *s, int non_block,
int *err)
{
struct cx18 *cx = s->cx;
struct cx18_stream *s_vbi = &cx->streams[CX18_ENC_STREAM_TYPE_VBI];
struct cx18_mdl *mdl;
DEFINE_WAIT(wait);
*err = 0;
while (1) {
if (s->type == CX18_ENC_STREAM_TYPE_MPG) {
if (time_after(jiffies, cx->dualwatch_jiffies + msecs_to_jiffies(1000))) {
cx->dualwatch_jiffies = jiffies;
cx18_dualwatch(cx);
}
if (test_bit(CX18_F_S_INTERNAL_USE, &s_vbi->s_flags) &&
!test_bit(CX18_F_S_APPL_IO, &s_vbi->s_flags)) {
while ((mdl = cx18_dequeue(s_vbi,
&s_vbi->q_full))) {
cx18_process_vbi_data(cx, mdl,
s_vbi->type);
cx18_stream_put_mdl_fw(s_vbi, mdl);
}
}
mdl = &cx->vbi.sliced_mpeg_mdl;
if (mdl->readpos != mdl->bytesused)
return mdl;
}
mdl = cx18_dequeue(s, &s->q_full);
if (mdl) {
if (!test_and_clear_bit(CX18_F_M_NEED_SWAP,
&mdl->m_flags))
return mdl;
if (s->type == CX18_ENC_STREAM_TYPE_MPG)
cx18_mdl_swap(mdl);
else {
cx18_process_vbi_data(cx, mdl, s->type);
}
return mdl;
}
if (!test_bit(CX18_F_S_STREAMING, &s->s_flags)) {
CX18_DEBUG_INFO("EOS %s\n", s->name);
return NULL;
}
if (non_block) {
*err = -EAGAIN;
return NULL;
}
prepare_to_wait(&s->waitq, &wait, TASK_INTERRUPTIBLE);
if (!atomic_read(&s->q_full.depth))
schedule();
finish_wait(&s->waitq, &wait);
if (signal_pending(current)) {
CX18_DEBUG_INFO("User stopped %s\n", s->name);
*err = -EINTR;
return NULL;
}
}
}
static void cx18_setup_sliced_vbi_mdl(struct cx18 *cx)
{
struct cx18_mdl *mdl = &cx->vbi.sliced_mpeg_mdl;
struct cx18_buffer *buf = &cx->vbi.sliced_mpeg_buf;
int idx = cx->vbi.inserted_frame % CX18_VBI_FRAMES;
buf->buf = cx->vbi.sliced_mpeg_data[idx];
buf->bytesused = cx->vbi.sliced_mpeg_size[idx];
buf->readpos = 0;
mdl->curr_buf = NULL;
mdl->bytesused = cx->vbi.sliced_mpeg_size[idx];
mdl->readpos = 0;
}
static size_t cx18_copy_buf_to_user(struct cx18_stream *s,
struct cx18_buffer *buf, char __user *ubuf, size_t ucount, bool *stop)
{
struct cx18 *cx = s->cx;
size_t len = buf->bytesused - buf->readpos;
*stop = false;
if (len > ucount)
len = ucount;
if (cx->vbi.insert_mpeg && s->type == CX18_ENC_STREAM_TYPE_MPG &&
!cx18_raw_vbi(cx) && buf != &cx->vbi.sliced_mpeg_buf) {
const char *start = buf->buf + buf->readpos;
const char *p = start + 1;
const u8 *q;
u8 ch = cx->search_pack_header ? 0xba : 0xe0;
int stuffing, i;
while (start + len > p) {
q = memchr(p, 0, start + len - p);
if (q == NULL)
break;
p = q + 1;
if ((char *)q + 15 >= buf->buf + buf->bytesused ||
q[1] != 0 || q[2] != 1 || q[3] != ch)
continue;
if (!cx->search_pack_header) {
if ((q[6] & 0xc0) != 0x80)
continue;
if (((q[7] & 0xc0) == 0x80 &&
(q[9] & 0xf0) == 0x20) ||
((q[7] & 0xc0) == 0xc0 &&
(q[9] & 0xf0) == 0x30)) {
ch = 0xba;
cx->search_pack_header = 1;
p = q + 9;
}
continue;
}
stuffing = q[13] & 7;
for (i = 0; i < stuffing; i++)
if (q[14 + i] != 0xff)
break;
if (i == stuffing &&
(q[4] & 0xc4) == 0x44 &&
(q[12] & 3) == 3 &&
q[14 + stuffing] == 0 &&
q[15 + stuffing] == 0 &&
q[16 + stuffing] == 1) {
cx->search_pack_header = 0;
len = (char *)q - start;
cx18_setup_sliced_vbi_mdl(cx);
*stop = true;
break;
}
}
}
if (copy_to_user(ubuf, (u8 *)buf->buf + buf->readpos, len)) {
CX18_DEBUG_WARN("copy %zd bytes to user failed for %s\n",
len, s->name);
return -EFAULT;
}
buf->readpos += len;
if (s->type == CX18_ENC_STREAM_TYPE_MPG &&
buf != &cx->vbi.sliced_mpeg_buf)
cx->mpg_data_received += len;
return len;
}
static size_t cx18_copy_mdl_to_user(struct cx18_stream *s,
struct cx18_mdl *mdl, char __user *ubuf, size_t ucount)
{
size_t tot_written = 0;
int rc;
bool stop = false;
if (mdl->curr_buf == NULL)
mdl->curr_buf = list_first_entry(&mdl->buf_list,
struct cx18_buffer, list);
if (list_entry_is_past_end(mdl->curr_buf, &mdl->buf_list, list)) {
mdl->readpos = mdl->bytesused;
return 0;
}
list_for_each_entry_from(mdl->curr_buf, &mdl->buf_list, list) {
if (mdl->curr_buf->readpos >= mdl->curr_buf->bytesused)
continue;
rc = cx18_copy_buf_to_user(s, mdl->curr_buf, ubuf + tot_written,
ucount - tot_written, &stop);
if (rc < 0)
return rc;
mdl->readpos += rc;
tot_written += rc;
if (stop ||
tot_written >= ucount ||
mdl->curr_buf->readpos < mdl->curr_buf->bytesused ||
mdl->readpos >= mdl->bytesused)
break;
}
return tot_written;
}
static ssize_t cx18_read(struct cx18_stream *s, char __user *ubuf,
size_t tot_count, int non_block)
{
struct cx18 *cx = s->cx;
size_t tot_written = 0;
int single_frame = 0;
if (atomic_read(&cx->ana_capturing) == 0 && s->id == -1) {
CX18_DEBUG_WARN("Stream %s not initialized before read\n",
s->name);
return -EIO;
}
if (s->type == CX18_ENC_STREAM_TYPE_VBI && !cx18_raw_vbi(cx))
single_frame = 1;
for (;;) {
struct cx18_mdl *mdl;
int rc;
mdl = cx18_get_mdl(s, non_block, &rc);
if (mdl == NULL) {
if (tot_written)
break;
if (rc == 0) {
clear_bit(CX18_F_S_STREAMOFF, &s->s_flags);
clear_bit(CX18_F_S_APPL_IO, &s->s_flags);
cx18_release_stream(s);
}
return rc;
}
rc = cx18_copy_mdl_to_user(s, mdl, ubuf + tot_written,
tot_count - tot_written);
if (mdl != &cx->vbi.sliced_mpeg_mdl) {
if (mdl->readpos == mdl->bytesused)
cx18_stream_put_mdl_fw(s, mdl);
else
cx18_push(s, mdl, &s->q_full);
} else if (mdl->readpos == mdl->bytesused) {
int idx = cx->vbi.inserted_frame % CX18_VBI_FRAMES;
cx->vbi.sliced_mpeg_size[idx] = 0;
cx->vbi.inserted_frame++;
cx->vbi_data_inserted += mdl->bytesused;
}
if (rc < 0)
return rc;
tot_written += rc;
if (tot_written == tot_count || single_frame)
break;
}
return tot_written;
}
static ssize_t cx18_read_pos(struct cx18_stream *s, char __user *ubuf,
size_t count, loff_t *pos, int non_block)
{
ssize_t rc = count ? cx18_read(s, ubuf, count, non_block) : 0;
struct cx18 *cx = s->cx;
CX18_DEBUG_HI_FILE("read %zd from %s, got %zd\n", count, s->name, rc);
if (rc > 0)
pos += rc;
return rc;
}
int cx18_start_capture(struct cx18_open_id *id)
{
struct cx18 *cx = id->cx;
struct cx18_stream *s = &cx->streams[id->type];
struct cx18_stream *s_vbi;
struct cx18_stream *s_idx;
if (s->type == CX18_ENC_STREAM_TYPE_RAD) {
return -EPERM;
}
if (cx18_claim_stream(id, s->type))
return -EBUSY;
if (test_bit(CX18_F_S_STREAMOFF, &s->s_flags) ||
test_and_set_bit(CX18_F_S_STREAMING, &s->s_flags)) {
set_bit(CX18_F_S_APPL_IO, &s->s_flags);
return 0;
}
s_vbi = &cx->streams[CX18_ENC_STREAM_TYPE_VBI];
s_idx = &cx->streams[CX18_ENC_STREAM_TYPE_IDX];
if (s->type == CX18_ENC_STREAM_TYPE_MPG) {
if (test_bit(CX18_F_S_INTERNAL_USE, &s_idx->s_flags) &&
!test_and_set_bit(CX18_F_S_STREAMING, &s_idx->s_flags)) {
if (cx18_start_v4l2_encode_stream(s_idx)) {
CX18_DEBUG_WARN("IDX capture start failed\n");
clear_bit(CX18_F_S_STREAMING, &s_idx->s_flags);
goto start_failed;
}
CX18_DEBUG_INFO("IDX capture started\n");
}
if (test_bit(CX18_F_S_INTERNAL_USE, &s_vbi->s_flags) &&
!test_and_set_bit(CX18_F_S_STREAMING, &s_vbi->s_flags)) {
if (cx18_start_v4l2_encode_stream(s_vbi)) {
CX18_DEBUG_WARN("VBI capture start failed\n");
clear_bit(CX18_F_S_STREAMING, &s_vbi->s_flags);
goto start_failed;
}
CX18_DEBUG_INFO("VBI insertion started\n");
}
}
if (!cx18_start_v4l2_encode_stream(s)) {
set_bit(CX18_F_S_APPL_IO, &s->s_flags);
if (test_and_clear_bit(CX18_F_I_ENC_PAUSED, &cx->i_flags))
cx18_vapi(cx, CX18_CPU_CAPTURE_PAUSE, 1, s->handle);
return 0;
}
start_failed:
CX18_DEBUG_WARN("Failed to start capturing for stream %s\n", s->name);
if (s->type == CX18_ENC_STREAM_TYPE_MPG) {
if (test_bit(CX18_F_S_STREAMING, &s_idx->s_flags)) {
cx18_stop_v4l2_encode_stream(s_idx, 0);
clear_bit(CX18_F_S_STREAMING, &s_idx->s_flags);
}
if (test_bit(CX18_F_S_STREAMING, &s_vbi->s_flags) &&
!test_bit(CX18_F_S_APPL_IO, &s_vbi->s_flags)) {
cx18_stop_v4l2_encode_stream(s_vbi, 0);
clear_bit(CX18_F_S_STREAMING, &s_vbi->s_flags);
}
}
clear_bit(CX18_F_S_STREAMING, &s->s_flags);
cx18_release_stream(s);
return -EIO;
}
ssize_t cx18_v4l2_read(struct file *filp, char __user *buf, size_t count,
loff_t *pos)
{
struct cx18_open_id *id = file2id(filp);
struct cx18 *cx = id->cx;
struct cx18_stream *s = &cx->streams[id->type];
int rc;
CX18_DEBUG_HI_FILE("read %zd bytes from %s\n", count, s->name);
mutex_lock(&cx->serialize_lock);
rc = cx18_start_capture(id);
mutex_unlock(&cx->serialize_lock);
if (rc)
return rc;
if ((s->vb_type == V4L2_BUF_TYPE_VIDEO_CAPTURE) &&
(id->type == CX18_ENC_STREAM_TYPE_YUV)) {
return videobuf_read_stream(&s->vbuf_q, buf, count, pos, 0,
filp->f_flags & O_NONBLOCK);
}
return cx18_read_pos(s, buf, count, pos, filp->f_flags & O_NONBLOCK);
}
unsigned int cx18_v4l2_enc_poll(struct file *filp, poll_table *wait)
{
struct cx18_open_id *id = file2id(filp);
struct cx18 *cx = id->cx;
struct cx18_stream *s = &cx->streams[id->type];
int eof = test_bit(CX18_F_S_STREAMOFF, &s->s_flags);
if (!eof && !test_bit(CX18_F_S_STREAMING, &s->s_flags)) {
int rc;
mutex_lock(&cx->serialize_lock);
rc = cx18_start_capture(id);
mutex_unlock(&cx->serialize_lock);
if (rc) {
CX18_DEBUG_INFO("Could not start capture for %s (%d)\n",
s->name, rc);
return POLLERR;
}
CX18_DEBUG_FILE("Encoder poll started capture\n");
}
if ((s->vb_type == V4L2_BUF_TYPE_VIDEO_CAPTURE) &&
(id->type == CX18_ENC_STREAM_TYPE_YUV)) {
int videobuf_poll = videobuf_poll_stream(filp, &s->vbuf_q, wait);
if (eof && videobuf_poll == POLLERR)
return POLLHUP;
else
return videobuf_poll;
}
CX18_DEBUG_HI_FILE("Encoder poll\n");
poll_wait(filp, &s->waitq, wait);
if (atomic_read(&s->q_full.depth))
return POLLIN | POLLRDNORM;
if (eof)
return POLLHUP;
return 0;
}
int cx18_v4l2_mmap(struct file *file, struct vm_area_struct *vma)
{
struct cx18_open_id *id = file->private_data;
struct cx18 *cx = id->cx;
struct cx18_stream *s = &cx->streams[id->type];
int eof = test_bit(CX18_F_S_STREAMOFF, &s->s_flags);
if ((s->vb_type == V4L2_BUF_TYPE_VIDEO_CAPTURE) &&
(id->type == CX18_ENC_STREAM_TYPE_YUV)) {
if (!eof && !test_bit(CX18_F_S_STREAMING, &s->s_flags)) {
int rc;
mutex_lock(&cx->serialize_lock);
rc = cx18_start_capture(id);
mutex_unlock(&cx->serialize_lock);
if (rc) {
CX18_DEBUG_INFO(
"Could not start capture for %s (%d)\n",
s->name, rc);
return -EINVAL;
}
CX18_DEBUG_FILE("Encoder mmap started capture\n");
}
return videobuf_mmap_mapper(&s->vbuf_q, vma);
}
return -EINVAL;
}
void cx18_vb_timeout(unsigned long data)
{
struct cx18_stream *s = (struct cx18_stream *)data;
struct cx18_videobuf_buffer *buf;
unsigned long flags;
spin_lock_irqsave(&s->vb_lock, flags);
while (!list_empty(&s->vb_capture)) {
buf = list_entry(s->vb_capture.next,
struct cx18_videobuf_buffer, vb.queue);
list_del(&buf->vb.queue);
buf->vb.state = VIDEOBUF_ERROR;
wake_up(&buf->vb.done);
}
spin_unlock_irqrestore(&s->vb_lock, flags);
}
void cx18_stop_capture(struct cx18_open_id *id, int gop_end)
{
struct cx18 *cx = id->cx;
struct cx18_stream *s = &cx->streams[id->type];
struct cx18_stream *s_vbi = &cx->streams[CX18_ENC_STREAM_TYPE_VBI];
struct cx18_stream *s_idx = &cx->streams[CX18_ENC_STREAM_TYPE_IDX];
CX18_DEBUG_IOCTL("close() of %s\n", s->name);
if (test_bit(CX18_F_S_STREAMING, &s->s_flags)) {
CX18_DEBUG_INFO("close stopping capture\n");
if (id->type == CX18_ENC_STREAM_TYPE_MPG) {
if (test_bit(CX18_F_S_STREAMING, &s_vbi->s_flags) &&
!test_bit(CX18_F_S_APPL_IO, &s_vbi->s_flags)) {
CX18_DEBUG_INFO("close stopping embedded VBI "
"capture\n");
cx18_stop_v4l2_encode_stream(s_vbi, 0);
}
if (test_bit(CX18_F_S_STREAMING, &s_idx->s_flags)) {
CX18_DEBUG_INFO("close stopping IDX capture\n");
cx18_stop_v4l2_encode_stream(s_idx, 0);
}
}
if (id->type == CX18_ENC_STREAM_TYPE_VBI &&
test_bit(CX18_F_S_INTERNAL_USE, &s->s_flags))
s->id = -1;
else
cx18_stop_v4l2_encode_stream(s, gop_end);
}
if (!gop_end) {
clear_bit(CX18_F_S_APPL_IO, &s->s_flags);
clear_bit(CX18_F_S_STREAMOFF, &s->s_flags);
cx18_release_stream(s);
}
}
int cx18_v4l2_close(struct file *filp)
{
struct v4l2_fh *fh = filp->private_data;
struct cx18_open_id *id = fh2id(fh);
struct cx18 *cx = id->cx;
struct cx18_stream *s = &cx->streams[id->type];
CX18_DEBUG_IOCTL("close() of %s\n", s->name);
v4l2_fh_del(fh);
v4l2_fh_exit(fh);
if (s->id != id->open_id) {
kfree(id);
return 0;
}
mutex_lock(&cx->serialize_lock);
if (id->type == CX18_ENC_STREAM_TYPE_RAD) {
cx18_mute(cx);
clear_bit(CX18_F_I_RADIO_USER, &cx->i_flags);
cx18_call_all(cx, core, s_std, cx->std);
cx18_audio_set_io(cx);
if (atomic_read(&cx->ana_capturing) > 0) {
cx18_vapi(cx, CX18_CPU_SET_VIDEO_MUTE, 2, s->handle,
(v4l2_ctrl_g_ctrl(cx->cxhdl.video_mute) |
(v4l2_ctrl_g_ctrl(cx->cxhdl.video_mute_yuv) << 8)));
}
cx18_unmute(cx);
cx18_release_stream(s);
} else {
cx18_stop_capture(id, 0);
}
kfree(id);
mutex_unlock(&cx->serialize_lock);
return 0;
}
static int cx18_serialized_open(struct cx18_stream *s, struct file *filp)
{
struct cx18 *cx = s->cx;
struct cx18_open_id *item;
CX18_DEBUG_FILE("open %s\n", s->name);
item = kzalloc(sizeof(struct cx18_open_id), GFP_KERNEL);
if (NULL == item) {
CX18_DEBUG_WARN("nomem on v4l2 open\n");
return -ENOMEM;
}
v4l2_fh_init(&item->fh, s->video_dev);
item->cx = cx;
item->type = s->type;
item->open_id = cx->open_id++;
filp->private_data = &item->fh;
if (item->type == CX18_ENC_STREAM_TYPE_RAD) {
if (cx18_claim_stream(item, item->type)) {
v4l2_fh_exit(&item->fh);
kfree(item);
return -EBUSY;
}
if (!test_bit(CX18_F_I_RADIO_USER, &cx->i_flags)) {
if (atomic_read(&cx->ana_capturing) > 0) {
cx18_release_stream(s);
v4l2_fh_exit(&item->fh);
kfree(item);
return -EBUSY;
}
}
set_bit(CX18_F_I_RADIO_USER, &cx->i_flags);
cx18_mute(cx);
cx18_call_all(cx, tuner, s_radio);
cx18_audio_set_io(cx);
cx18_unmute(cx);
}
v4l2_fh_add(&item->fh);
return 0;
}
int cx18_v4l2_open(struct file *filp)
{
int res;
struct video_device *video_dev = video_devdata(filp);
struct cx18_stream *s = video_get_drvdata(video_dev);
struct cx18 *cx = s->cx;
mutex_lock(&cx->serialize_lock);
if (cx18_init_on_first_open(cx)) {
CX18_ERR("Failed to initialize on %s\n",
video_device_node_name(video_dev));
mutex_unlock(&cx->serialize_lock);
return -ENXIO;
}
res = cx18_serialized_open(s, filp);
mutex_unlock(&cx->serialize_lock);
return res;
}
void cx18_mute(struct cx18 *cx)
{
u32 h;
if (atomic_read(&cx->ana_capturing)) {
h = cx18_find_handle(cx);
if (h != CX18_INVALID_TASK_HANDLE)
cx18_vapi(cx, CX18_CPU_SET_AUDIO_MUTE, 2, h, 1);
else
CX18_ERR("Can't find valid task handle for mute\n");
}
CX18_DEBUG_INFO("Mute\n");
}
void cx18_unmute(struct cx18 *cx)
{
u32 h;
if (atomic_read(&cx->ana_capturing)) {
h = cx18_find_handle(cx);
if (h != CX18_INVALID_TASK_HANDLE) {
cx18_msleep_timeout(100, 0);
cx18_vapi(cx, CX18_CPU_SET_MISC_PARAMETERS, 2, h, 12);
cx18_vapi(cx, CX18_CPU_SET_AUDIO_MUTE, 2, h, 0);
} else
CX18_ERR("Can't find valid task handle for unmute\n");
}
CX18_DEBUG_INFO("Unmute\n");
}
