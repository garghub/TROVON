const struct atomisp_format_bridge *atomisp_get_format_bridge(
unsigned int pixelformat)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(atomisp_output_fmts); i++) {
if (atomisp_output_fmts[i].pixelformat == pixelformat)
return &atomisp_output_fmts[i];
}
return NULL;
}
const struct atomisp_format_bridge *atomisp_get_format_bridge_from_mbus(
u32 mbus_code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(atomisp_output_fmts); i++) {
if (mbus_code == atomisp_output_fmts[i].mbus_code)
return &atomisp_output_fmts[i];
}
return NULL;
}
static int atomisp_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
memset(cap, 0, sizeof(struct v4l2_capability));
WARN_ON(sizeof(DRIVER) > sizeof(cap->driver) ||
sizeof(CARD) > sizeof(cap->card) ||
sizeof(BUS_INFO) > sizeof(cap->bus_info));
strncpy(cap->driver, DRIVER, sizeof(cap->driver) - 1);
strncpy(cap->card, CARD, sizeof(cap->card) - 1);
strncpy(cap->bus_info, BUS_INFO, sizeof(cap->card) - 1);
cap->version = VERSION;
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_STREAMING | V4L2_CAP_VIDEO_OUTPUT;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int atomisp_enum_input(struct file *file, void *fh,
struct v4l2_input *input)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
int index = input->index;
if (index >= isp->input_cnt)
return -EINVAL;
if (!isp->inputs[index].camera)
return -EINVAL;
memset(input, 0, sizeof(struct v4l2_input));
strncpy(input->name, isp->inputs[index].camera->name,
sizeof(input->name) - 1);
#ifndef ISP2401
if (isp->inputs[index].motor &&
strlen(isp->inputs[index].motor->name) > 0) {
#else
if (isp->motor &&
strlen(isp->motor->name) > 0) {
#endif
const int cur_len = strlen(input->name);
const int max_size = sizeof(input->name) - cur_len - 1;
if (max_size > 1) {
input->name[cur_len] = '+';
strncpy(&input->name[cur_len + 1],
#ifndef ISP2401
isp->inputs[index].motor->name, max_size - 1);
#else
isp->motor->name, max_size - 1);
#endif
}
}
input->type = V4L2_INPUT_TYPE_CAMERA;
input->index = index;
input->reserved[0] = isp->inputs[index].type;
input->reserved[1] = isp->inputs[index].port;
return 0;
}
static unsigned int atomisp_subdev_streaming_count(
struct atomisp_sub_device *asd)
{
return asd->video_out_preview.capq.streaming
+ asd->video_out_capture.capq.streaming
+ asd->video_out_video_capture.capq.streaming
+ asd->video_out_vf.capq.streaming
+ asd->video_in.capq.streaming;
}
unsigned int atomisp_streaming_count(struct atomisp_device *isp)
{
unsigned int i, sum;
for (i = 0, sum = 0; i < isp->num_of_streams; i++)
sum += isp->asd[i].streaming ==
ATOMISP_DEVICE_STREAMING_ENABLED;
return sum;
}
unsigned int atomisp_is_acc_enabled(struct atomisp_device *isp)
{
unsigned int i;
for (i = 0; i < isp->num_of_streams; i++)
if (isp->asd[i].acc.pipeline)
return 1;
return 0;
}
static int atomisp_g_input(struct file *file, void *fh, unsigned int *input)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
rt_mutex_lock(&isp->mutex);
*input = asd->input_curr;
rt_mutex_unlock(&isp->mutex);
return 0;
}
static int atomisp_s_input(struct file *file, void *fh, unsigned int input)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct v4l2_subdev *camera = NULL;
int ret;
rt_mutex_lock(&isp->mutex);
if (input >= ATOM_ISP_MAX_INPUTS || input >= isp->input_cnt) {
dev_dbg(isp->dev, "input_cnt: %d\n", isp->input_cnt);
ret = -EINVAL;
goto error;
}
if (isp->inputs[input].asd != NULL && isp->inputs[input].asd != asd) {
dev_err(isp->dev,
"%s, camera is already used by stream: %d\n", __func__,
isp->inputs[input].asd->index);
ret = -EBUSY;
goto error;
}
camera = isp->inputs[input].camera;
if (!camera) {
dev_err(isp->dev, "%s, no camera\n", __func__);
ret = -EINVAL;
goto error;
}
if (atomisp_subdev_streaming_count(asd)) {
dev_err(isp->dev,
"ISP is still streaming, stop first\n");
ret = -EINVAL;
goto error;
}
if (isp->inputs[asd->input_curr].asd == asd &&
asd->input_curr != input) {
ret = v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
core, s_power, 0);
if (ret)
dev_warn(isp->dev,
"Failed to power-off sensor\n");
isp->inputs[asd->input_curr].asd = NULL;
}
ret = v4l2_subdev_call(isp->inputs[input].camera, core, s_power, 1);
if (ret) {
dev_err(isp->dev, "Failed to power-on sensor\n");
goto error;
}
atomisp_update_run_mode(asd);
ret = v4l2_subdev_call(isp->inputs[input].camera, video, s_routing,
0, isp->inputs[input].sensor_index, 0);
if (ret && (ret != -ENOIOCTLCMD)) {
dev_err(isp->dev, "Failed to select sensor\n");
goto error;
}
#ifndef ISP2401
if (!isp->sw_contex.file_input && isp->inputs[input].motor)
ret = v4l2_subdev_call(isp->inputs[input].motor, core,
init, 1);
#else
if (isp->motor)
ret = v4l2_subdev_call(isp->motor, core, s_power, 1);
if (!isp->sw_contex.file_input && isp->motor)
ret = v4l2_subdev_call(isp->motor, core, init, 1);
#endif
asd->input_curr = input;
isp->inputs[input].asd = asd;
rt_mutex_unlock(&isp->mutex);
return 0;
error:
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_enum_fmt_cap(struct file *file, void *fh,
struct v4l2_fmtdesc *f)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct v4l2_subdev_mbus_code_enum code = { 0 };
unsigned int i, fi = 0;
int rval;
rt_mutex_lock(&isp->mutex);
rval = v4l2_subdev_call(isp->inputs[asd->input_curr].camera, pad,
enum_mbus_code, NULL, &code);
if (rval == -ENOIOCTLCMD) {
dev_warn(isp->dev, "enum_mbus_code pad op not supported. Please fix your sensor driver!\n");
}
rt_mutex_unlock(&isp->mutex);
if (rval)
return rval;
for (i = 0; i < ARRAY_SIZE(atomisp_output_fmts); i++) {
const struct atomisp_format_bridge *format =
&atomisp_output_fmts[i];
if (format->sh_fmt == CSS_FRAME_FORMAT_RAW
&& format->mbus_code != code.code)
continue;
if (fi < f->index) {
fi++;
continue;
}
strlcpy(f->description, format->description,
sizeof(f->description));
f->pixelformat = format->pixelformat;
return 0;
}
return -EINVAL;
}
static int atomisp_g_fmt_cap(struct file *file, void *fh,
struct v4l2_format *f)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
int ret;
rt_mutex_lock(&isp->mutex);
ret = atomisp_get_fmt(vdev, f);
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_g_fmt_file(struct file *file, void *fh,
struct v4l2_format *f)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
rt_mutex_lock(&isp->mutex);
f->fmt.pix = pipe->pix;
rt_mutex_unlock(&isp->mutex);
return 0;
}
static int atomisp_try_fmt_cap(struct file *file, void *fh,
struct v4l2_format *f)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
int ret;
rt_mutex_lock(&isp->mutex);
ret = atomisp_try_fmt(vdev, f, NULL);
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_s_fmt_cap(struct file *file, void *fh,
struct v4l2_format *f)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
int ret;
rt_mutex_lock(&isp->mutex);
if (isp->isp_fatal_error) {
ret = -EIO;
rt_mutex_unlock(&isp->mutex);
return ret;
}
ret = atomisp_set_fmt(vdev, f);
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_s_fmt_file(struct file *file, void *fh,
struct v4l2_format *f)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
int ret;
rt_mutex_lock(&isp->mutex);
ret = atomisp_set_fmt_file(vdev, f);
rt_mutex_unlock(&isp->mutex);
return ret;
}
void atomisp_videobuf_free_buf(struct videobuf_buffer *vb)
{
struct videobuf_vmalloc_memory *vm_mem;
if (vb == NULL)
return;
vm_mem = vb->priv;
if (vm_mem && vm_mem->vaddr) {
atomisp_css_frame_free(vm_mem->vaddr);
vm_mem->vaddr = NULL;
}
}
static void atomisp_videobuf_free_queue(struct videobuf_queue *q)
{
int i;
for (i = 0; i < VIDEO_MAX_FRAME; i++) {
atomisp_videobuf_free_buf(q->bufs[i]);
kfree(q->bufs[i]);
q->bufs[i] = NULL;
}
}
int atomisp_alloc_css_stat_bufs(struct atomisp_sub_device *asd,
uint16_t stream_id)
{
struct atomisp_device *isp = asd->isp;
struct atomisp_s3a_buf *s3a_buf = NULL, *_s3a_buf;
struct atomisp_dis_buf *dis_buf = NULL, *_dis_buf;
struct atomisp_metadata_buf *md_buf = NULL, *_md_buf;
int count;
struct atomisp_css_dvs_grid_info *dvs_grid_info =
atomisp_css_get_dvs_grid_info(&asd->params.curr_grid_info);
unsigned int i;
if (list_empty(&asd->s3a_stats) &&
asd->params.curr_grid_info.s3a_grid.enable) {
count = ATOMISP_CSS_Q_DEPTH +
ATOMISP_S3A_BUF_QUEUE_DEPTH_FOR_HAL;
dev_dbg(isp->dev, "allocating %d 3a buffers\n", count);
while (count--) {
s3a_buf = kzalloc(sizeof(struct atomisp_s3a_buf), GFP_KERNEL);
if (!s3a_buf) {
dev_err(isp->dev, "s3a stat buf alloc failed\n");
goto error;
}
if (atomisp_css_allocate_stat_buffers(
asd, stream_id, s3a_buf, NULL, NULL)) {
kfree(s3a_buf);
goto error;
}
list_add_tail(&s3a_buf->list, &asd->s3a_stats);
}
}
if (list_empty(&asd->dis_stats) && dvs_grid_info &&
dvs_grid_info->enable) {
count = ATOMISP_CSS_Q_DEPTH + 1;
dev_dbg(isp->dev, "allocating %d dis buffers\n", count);
while (count--) {
dis_buf = kzalloc(sizeof(struct atomisp_dis_buf), GFP_KERNEL);
if (!dis_buf) {
dev_err(isp->dev, "dis stat buf alloc failed\n");
kfree(s3a_buf);
goto error;
}
if (atomisp_css_allocate_stat_buffers(
asd, stream_id, NULL, dis_buf, NULL)) {
kfree(dis_buf);
goto error;
}
list_add_tail(&dis_buf->list, &asd->dis_stats);
}
}
for (i = 0; i < ATOMISP_METADATA_TYPE_NUM; i++) {
if (list_empty(&asd->metadata[i]) &&
list_empty(&asd->metadata_ready[i]) &&
list_empty(&asd->metadata_in_css[i])) {
count = ATOMISP_CSS_Q_DEPTH +
ATOMISP_METADATA_QUEUE_DEPTH_FOR_HAL;
dev_dbg(isp->dev, "allocating %d metadata buffers for type %d\n",
count, i);
while (count--) {
md_buf = kzalloc(sizeof(struct atomisp_metadata_buf),
GFP_KERNEL);
if (!md_buf) {
dev_err(isp->dev, "metadata buf alloc failed\n");
goto error;
}
if (atomisp_css_allocate_stat_buffers(
asd, stream_id, NULL, NULL, md_buf)) {
kfree(md_buf);
goto error;
}
list_add_tail(&md_buf->list, &asd->metadata[i]);
}
}
}
return 0;
error:
dev_err(isp->dev, "failed to allocate statistics buffers\n");
list_for_each_entry_safe(dis_buf, _dis_buf, &asd->dis_stats, list) {
atomisp_css_free_dis_buffer(dis_buf);
list_del(&dis_buf->list);
kfree(dis_buf);
}
list_for_each_entry_safe(s3a_buf, _s3a_buf, &asd->s3a_stats, list) {
atomisp_css_free_3a_buffer(s3a_buf);
list_del(&s3a_buf->list);
kfree(s3a_buf);
}
for (i = 0; i < ATOMISP_METADATA_TYPE_NUM; i++) {
list_for_each_entry_safe(md_buf, _md_buf, &asd->metadata[i],
list) {
atomisp_css_free_metadata_buffer(md_buf);
list_del(&md_buf->list);
kfree(md_buf);
}
}
return -ENOMEM;
}
int __atomisp_reqbufs(struct file *file, void *fh,
struct v4l2_requestbuffers *req)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
struct atomisp_sub_device *asd = pipe->asd;
struct atomisp_css_frame_info frame_info;
struct atomisp_css_frame *frame;
struct videobuf_vmalloc_memory *vm_mem;
uint16_t source_pad = atomisp_subdev_source_pad(vdev);
uint16_t stream_id = atomisp_source_pad_to_stream_id(asd, source_pad);
int ret = 0, i = 0;
if (req->count == 0) {
mutex_lock(&pipe->capq.vb_lock);
if (!list_empty(&pipe->capq.stream))
videobuf_queue_cancel(&pipe->capq);
atomisp_videobuf_free_queue(&pipe->capq);
mutex_unlock(&pipe->capq.vb_lock);
memset(pipe->frame_request_config_id, 0,
VIDEO_MAX_FRAME * sizeof(unsigned int));
memset(pipe->frame_params, 0,
VIDEO_MAX_FRAME *
sizeof(struct atomisp_css_params_with_list *));
return 0;
}
ret = videobuf_reqbufs(&pipe->capq, req);
if (ret)
return ret;
atomisp_alloc_css_stat_bufs(asd, stream_id);
if (req->memory == V4L2_MEMORY_USERPTR)
return 0;
ret = atomisp_get_css_frame_info(asd, source_pad, &frame_info);
if (ret)
return ret;
for (i = 0; i < req->count; i++) {
if (atomisp_css_frame_allocate_from_info(&frame, &frame_info))
goto error;
vm_mem = pipe->capq.bufs[i]->priv;
vm_mem->vaddr = frame;
}
return ret;
error:
while (i--) {
vm_mem = pipe->capq.bufs[i]->priv;
atomisp_css_frame_free(vm_mem->vaddr);
}
if (asd->vf_frame)
atomisp_css_frame_free(asd->vf_frame);
return -ENOMEM;
}
int atomisp_reqbufs(struct file *file, void *fh,
struct v4l2_requestbuffers *req)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
int ret;
rt_mutex_lock(&isp->mutex);
ret = __atomisp_reqbufs(file, fh, req);
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_reqbufs_file(struct file *file, void *fh,
struct v4l2_requestbuffers *req)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
if (req->count == 0) {
mutex_lock(&pipe->outq.vb_lock);
atomisp_videobuf_free_queue(&pipe->outq);
mutex_unlock(&pipe->outq.vb_lock);
return 0;
}
return videobuf_reqbufs(&pipe->outq, req);
}
static int atomisp_querybuf(struct file *file, void *fh,
struct v4l2_buffer *buf)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
return videobuf_querybuf(&pipe->capq, buf);
}
static int atomisp_querybuf_file(struct file *file, void *fh,
struct v4l2_buffer *buf)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
return videobuf_querybuf(&pipe->outq, buf);
}
static int atomisp_qbuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
static const int NOFLUSH_FLAGS = V4L2_BUF_FLAG_NO_CACHE_INVALIDATE |
V4L2_BUF_FLAG_NO_CACHE_CLEAN;
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
struct atomisp_sub_device *asd = pipe->asd;
struct videobuf_buffer *vb;
struct videobuf_vmalloc_memory *vm_mem;
struct atomisp_css_frame_info frame_info;
struct atomisp_css_frame *handle = NULL;
u32 length;
u32 pgnr;
int ret = 0;
rt_mutex_lock(&isp->mutex);
if (isp->isp_fatal_error) {
ret = -EIO;
goto error;
}
if (asd->streaming == ATOMISP_DEVICE_STREAMING_STOPPING) {
dev_err(isp->dev, "%s: reject, as ISP at stopping.\n",
__func__);
ret = -EIO;
goto error;
}
if (!buf || buf->index >= VIDEO_MAX_FRAME ||
!pipe->capq.bufs[buf->index]) {
dev_err(isp->dev, "Invalid index for qbuf.\n");
ret = -EINVAL;
goto error;
}
if (buf->memory == V4L2_MEMORY_USERPTR) {
struct hrt_userbuffer_attr attributes;
vb = pipe->capq.bufs[buf->index];
vm_mem = vb->priv;
if (!vm_mem) {
ret = -EINVAL;
goto error;
}
length = vb->bsize;
pgnr = (length + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
if (vb->baddr == buf->m.userptr && vm_mem->vaddr)
goto done;
if (atomisp_get_css_frame_info(asd,
atomisp_subdev_source_pad(vdev), &frame_info)) {
ret = -EIO;
goto error;
}
attributes.pgnr = pgnr;
#ifdef CONFIG_ION
#ifndef ISP2401
attributes.type = buf->type == V4L2_BUF_TYPE_VIDEO_CAPTURE_ION
? HRT_USR_ION : HRT_USR_PTR;
#else
if (buf->reserved & ATOMISP_BUFFER_TYPE_IS_ION) {
attributes.type = HRT_USR_ION;
if (asd->ion_dev_fd->val != ION_FD_UNSET) {
dev_dbg(isp->dev, "ION buffer queued, share_fd=%lddev_fd=%d.\n",
buf->m.userptr, asd->ion_dev_fd->val);
if ((buf->m.userptr &
(ATOMISP_ION_DEVICE_FD_MASK)) != 0) {
dev_err(isp->dev,
"Error: v4l2 buffer fd:0X%0lX > 0XFFFF.\n",
buf->m.userptr);
ret = -EINVAL;
goto error;
}
buf->m.userptr |= asd->ion_dev_fd->val <<
ATOMISP_ION_DEVICE_FD_OFFSET;
} else {
dev_err(isp->dev, "v4l2 buffer type is ION, \
but no dev fd set from userspace.\n");
ret = -EINVAL;
goto error;
}
} else {
attributes.type = HRT_USR_PTR;
}
#endif
#else
attributes.type = HRT_USR_PTR;
#endif
ret = atomisp_css_frame_map(&handle, &frame_info,
(void *)buf->m.userptr,
0, &attributes);
if (ret) {
dev_err(isp->dev, "Failed to map user buffer\n");
goto error;
}
if (vm_mem->vaddr) {
mutex_lock(&pipe->capq.vb_lock);
atomisp_css_frame_free(vm_mem->vaddr);
vm_mem->vaddr = NULL;
vb->state = VIDEOBUF_NEEDS_INIT;
mutex_unlock(&pipe->capq.vb_lock);
}
vm_mem->vaddr = handle;
buf->flags &= ~V4L2_BUF_FLAG_MAPPED;
buf->flags |= V4L2_BUF_FLAG_QUEUED;
buf->flags &= ~V4L2_BUF_FLAG_DONE;
} else if (buf->memory == V4L2_MEMORY_MMAP) {
buf->flags |= V4L2_BUF_FLAG_MAPPED;
buf->flags |= V4L2_BUF_FLAG_QUEUED;
buf->flags &= ~V4L2_BUF_FLAG_DONE;
}
done:
if (!((buf->flags & NOFLUSH_FLAGS) == NOFLUSH_FLAGS))
wbinvd();
if (!atomisp_is_vf_pipe(pipe) &&
(buf->reserved2 & ATOMISP_BUFFER_HAS_PER_FRAME_SETTING)) {
pipe->frame_request_config_id[buf->index] = buf->reserved2 &
~ATOMISP_BUFFER_HAS_PER_FRAME_SETTING;
dev_dbg(isp->dev, "This buffer requires per_frame setting which has isp_config_id %d\n",
pipe->frame_request_config_id[buf->index]);
} else {
pipe->frame_request_config_id[buf->index] = 0;
}
pipe->frame_params[buf->index] = NULL;
rt_mutex_unlock(&isp->mutex);
ret = videobuf_qbuf(&pipe->capq, buf);
rt_mutex_lock(&isp->mutex);
if (ret)
goto error;
if (asd->streaming == ATOMISP_DEVICE_STREAMING_ENABLED) {
if (!list_empty(&pipe->buffers_waiting_for_param)) {
atomisp_handle_parameter_and_buffer(pipe);
} else {
atomisp_qbuffers_to_css(asd);
#ifndef ISP2401
if (!atomisp_is_wdt_running(asd) && atomisp_buffers_queued(asd))
atomisp_wdt_start(asd);
#else
if (!atomisp_is_wdt_running(pipe) &&
atomisp_buffers_queued_pipe(pipe))
atomisp_wdt_start(pipe);
#endif
}
}
if (asd->continuous_mode->val &&
atomisp_subdev_source_pad(vdev)
== ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE &&
pipe->capq.streaming &&
!asd->enable_raw_buffer_lock->val &&
asd->params.offline_parm.num_captures == 1) {
#ifndef ISP2401
asd->pending_capture_request++;
dev_dbg(isp->dev, "Add one pending capture request.\n");
#else
if (asd->re_trigger_capture) {
ret = atomisp_css_offline_capture_configure(asd,
asd->params.offline_parm.num_captures,
asd->params.offline_parm.skip_frames,
asd->params.offline_parm.offset);
asd->re_trigger_capture = false;
dev_dbg(isp->dev, "%s Trigger capture again ret=%d\n",
__func__, ret);
} else {
asd->pending_capture_request++;
asd->re_trigger_capture = false;
dev_dbg(isp->dev, "Add one pending capture request.\n");
}
#endif
}
rt_mutex_unlock(&isp->mutex);
dev_dbg(isp->dev, "qbuf buffer %d (%s) for asd%d\n", buf->index,
vdev->name, asd->index);
return ret;
error:
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_qbuf_file(struct file *file, void *fh,
struct v4l2_buffer *buf)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
int ret;
rt_mutex_lock(&isp->mutex);
if (isp->isp_fatal_error) {
ret = -EIO;
goto error;
}
if (!buf || buf->index >= VIDEO_MAX_FRAME ||
!pipe->outq.bufs[buf->index]) {
dev_err(isp->dev, "Invalid index for qbuf.\n");
ret = -EINVAL;
goto error;
}
if (buf->memory != V4L2_MEMORY_MMAP) {
dev_err(isp->dev, "Unsupported memory method\n");
ret = -EINVAL;
goto error;
}
if (buf->type != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
dev_err(isp->dev, "Unsupported buffer type\n");
ret = -EINVAL;
goto error;
}
rt_mutex_unlock(&isp->mutex);
return videobuf_qbuf(&pipe->outq, buf);
error:
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int __get_frame_exp_id(struct atomisp_video_pipe *pipe,
struct v4l2_buffer *buf)
{
struct videobuf_vmalloc_memory *vm_mem;
struct atomisp_css_frame *handle;
int i;
for (i = 0; pipe->capq.bufs[i]; i++) {
vm_mem = pipe->capq.bufs[i]->priv;
handle = vm_mem->vaddr;
if (buf->index == pipe->capq.bufs[i]->i && handle)
return handle->exp_id;
}
return -EINVAL;
}
static int atomisp_dqbuf(struct file *file, void *fh, struct v4l2_buffer *buf)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
struct atomisp_sub_device *asd = pipe->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
int ret = 0;
rt_mutex_lock(&isp->mutex);
if (isp->isp_fatal_error) {
rt_mutex_unlock(&isp->mutex);
return -EIO;
}
if (asd->streaming == ATOMISP_DEVICE_STREAMING_STOPPING) {
rt_mutex_unlock(&isp->mutex);
dev_err(isp->dev, "%s: reject, as ISP at stopping.\n",
__func__);
return -EIO;
}
rt_mutex_unlock(&isp->mutex);
ret = videobuf_dqbuf(&pipe->capq, buf, file->f_flags & O_NONBLOCK);
if (ret) {
dev_dbg(isp->dev, "<%s: %d\n", __func__, ret);
return ret;
}
rt_mutex_lock(&isp->mutex);
buf->bytesused = pipe->pix.sizeimage;
buf->reserved = asd->frame_status[buf->index];
buf->reserved &= 0x0000ffff;
if (!(buf->flags & V4L2_BUF_FLAG_ERROR))
buf->reserved |= __get_frame_exp_id(pipe, buf) << 16;
buf->reserved2 = pipe->frame_config_id[buf->index];
rt_mutex_unlock(&isp->mutex);
dev_dbg(isp->dev, "dqbuf buffer %d (%s) for asd%d with exp_id %d, isp_config_id %d\n",
buf->index, vdev->name, asd->index, buf->reserved >> 16,
buf->reserved2);
return 0;
}
enum atomisp_css_pipe_id atomisp_get_css_pipe_id(struct atomisp_sub_device *asd)
{
if (ATOMISP_USE_YUVPP(asd))
return CSS_PIPE_ID_YUVPP;
if (asd->continuous_mode->val) {
if (asd->run_mode->val == ATOMISP_RUN_MODE_VIDEO)
return CSS_PIPE_ID_VIDEO;
else
return CSS_PIPE_ID_PREVIEW;
}
if (asd->vfpp->val == ATOMISP_VFPP_DISABLE_SCALER)
return CSS_PIPE_ID_VIDEO;
if (asd->vfpp->val == ATOMISP_VFPP_DISABLE_LOWLAT)
return CSS_PIPE_ID_CAPTURE;
switch (asd->run_mode->val) {
case ATOMISP_RUN_MODE_PREVIEW:
return CSS_PIPE_ID_PREVIEW;
case ATOMISP_RUN_MODE_VIDEO:
return CSS_PIPE_ID_VIDEO;
case ATOMISP_RUN_MODE_STILL_CAPTURE:
default:
return CSS_PIPE_ID_CAPTURE;
}
}
static unsigned int atomisp_sensor_start_stream(struct atomisp_sub_device *asd)
{
struct atomisp_device *isp = asd->isp;
if (isp->inputs[asd->input_curr].camera_caps->
sensor[asd->sensor_curr].stream_num > 1) {
if (asd->high_speed_mode)
return 1;
else
return 2;
}
if (asd->vfpp->val != ATOMISP_VFPP_ENABLE ||
asd->copy_mode)
return 1;
if (asd->run_mode->val == ATOMISP_RUN_MODE_VIDEO ||
(asd->run_mode->val == ATOMISP_RUN_MODE_STILL_CAPTURE &&
!atomisp_is_mbuscode_raw(
asd->fmt[
asd->capture_pad].fmt.code) &&
!asd->continuous_mode->val))
return 2;
else
return 1;
}
int atomisp_stream_on_master_slave_sensor(struct atomisp_device *isp,
bool isp_timeout)
{
unsigned int master = -1, slave = -1, delay_slave = 0;
int i, ret;
for (i = 0; i < isp->num_of_streams; i++) {
int sensor_index = isp->asd[i].input_curr;
if (isp->inputs[sensor_index].camera_caps->
sensor[isp->asd[i].sensor_curr].is_slave)
slave = sensor_index;
else
master = sensor_index;
}
if (master == -1 || slave == -1) {
master = ATOMISP_DEPTH_DEFAULT_MASTER_SENSOR;
slave = ATOMISP_DEPTH_DEFAULT_SLAVE_SENSOR;
dev_warn(isp->dev,
"depth mode use default master=%s.slave=%s.\n",
isp->inputs[master].camera->name,
isp->inputs[slave].camera->name);
}
ret = v4l2_subdev_call(isp->inputs[master].camera, core,
ioctl, ATOMISP_IOC_G_DEPTH_SYNC_COMP,
&delay_slave);
if (ret)
dev_warn(isp->dev,
"get depth sensor %s compensation delay failed.\n",
isp->inputs[master].camera->name);
ret = v4l2_subdev_call(isp->inputs[master].camera,
video, s_stream, 1);
if (ret) {
dev_err(isp->dev, "depth mode master sensor %s stream-on failed.\n",
isp->inputs[master].camera->name);
return -EINVAL;
}
if (delay_slave != 0)
udelay(delay_slave);
ret = v4l2_subdev_call(isp->inputs[slave].camera,
video, s_stream, 1);
if (ret) {
dev_err(isp->dev, "depth mode slave sensor %s stream-on failed.\n",
isp->inputs[slave].camera->name);
v4l2_subdev_call(isp->inputs[master].camera, video, s_stream, 0);
return -EINVAL;
}
return 0;
}
static void atomisp_pause_buffer_event(struct atomisp_device *isp)
{
struct v4l2_event event = {0};
int i;
event.type = V4L2_EVENT_ATOMISP_PAUSE_BUFFER;
for (i = 0; i < isp->num_of_streams; i++) {
int sensor_index = isp->asd[i].input_curr;
if (isp->inputs[sensor_index].camera_caps->
sensor[isp->asd[i].sensor_curr].is_slave) {
v4l2_event_queue(isp->asd[i].subdev.devnode, &event);
break;
}
}
}
static void atomisp_dma_burst_len_cfg(struct atomisp_sub_device *asd)
{
struct v4l2_mbus_framefmt *sink;
sink = atomisp_subdev_get_ffmt(&asd->subdev, NULL,
V4L2_SUBDEV_FORMAT_ACTIVE,
ATOMISP_SUBDEV_PAD_SINK);
if (sink->width * sink->height >= 4096*3072)
atomisp_store_uint32(DMA_BURST_SIZE_REG, 0x7F);
else
atomisp_store_uint32(DMA_BURST_SIZE_REG, 0x00);
}
static int atomisp_streamon(struct file *file, void *fh,
enum v4l2_buf_type type)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
struct atomisp_sub_device *asd = pipe->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
enum atomisp_css_pipe_id css_pipe_id;
unsigned int sensor_start_stream;
unsigned int wdt_duration = ATOMISP_ISP_TIMEOUT_DURATION;
int ret = 0;
unsigned long irqflags;
dev_dbg(isp->dev, "Start stream on pad %d for asd%d\n",
atomisp_subdev_source_pad(vdev), asd->index);
if (type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_dbg(isp->dev, "unsupported v4l2 buf type\n");
return -EINVAL;
}
rt_mutex_lock(&isp->mutex);
if (isp->isp_fatal_error) {
ret = -EIO;
goto out;
}
if (asd->streaming == ATOMISP_DEVICE_STREAMING_STOPPING) {
ret = -EBUSY;
goto out;
}
if (pipe->capq.streaming)
goto out;
atomisp_dma_burst_len_cfg(asd);
sensor_start_stream = atomisp_sensor_start_stream(asd);
spin_lock_irqsave(&pipe->irq_lock, irqflags);
if (list_empty(&(pipe->capq.stream))) {
spin_unlock_irqrestore(&pipe->irq_lock, irqflags);
dev_dbg(isp->dev, "no buffer in the queue\n");
ret = -EINVAL;
goto out;
}
spin_unlock_irqrestore(&pipe->irq_lock, irqflags);
ret = videobuf_streamon(&pipe->capq);
if (ret)
goto out;
asd->pending_capture_request = 0;
#ifdef ISP2401
asd->re_trigger_capture = false;
#endif
if ((atomisp_subdev_streaming_count(asd) > sensor_start_stream) &&
(!isp->inputs[asd->input_curr].camera_caps->multi_stream_ctrl)) {
if (asd->continuous_mode->val &&
atomisp_subdev_source_pad(vdev)
== ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE) {
if (asd->run_mode->val == ATOMISP_RUN_MODE_VIDEO)
dev_dbg(isp->dev, "SDV last video raw buffer id: %u\n",
asd->latest_preview_exp_id);
else
dev_dbg(isp->dev, "ZSL last preview raw buffer id: %u\n",
asd->latest_preview_exp_id);
if (asd->delayed_init == ATOMISP_DELAYED_INIT_QUEUED) {
flush_work(&asd->delayed_init_work);
rt_mutex_unlock(&isp->mutex);
if (wait_for_completion_interruptible(
&asd->init_done) != 0)
return -ERESTARTSYS;
rt_mutex_lock(&isp->mutex);
}
atomisp_handle_parameter_and_buffer(pipe);
atomisp_freq_scaling(isp, ATOMISP_DFS_MODE_MAX, false);
if (!asd->enable_raw_buffer_lock->val) {
ret = atomisp_css_offline_capture_configure(asd,
asd->params.offline_parm.num_captures,
asd->params.offline_parm.skip_frames,
asd->params.offline_parm.offset);
if (ret) {
ret = -EINVAL;
goto out;
}
if (asd->depth_mode->val)
atomisp_pause_buffer_event(isp);
}
}
atomisp_qbuffers_to_css(asd);
goto out;
}
if (asd->streaming == ATOMISP_DEVICE_STREAMING_ENABLED) {
atomisp_qbuffers_to_css(asd);
goto start_sensor;
}
css_pipe_id = atomisp_get_css_pipe_id(asd);
ret = atomisp_acc_load_extensions(asd);
if (ret < 0) {
dev_err(isp->dev, "acc extension failed to load\n");
goto out;
}
if (asd->params.css_update_params_needed) {
atomisp_apply_css_parameters(asd, &asd->params.css_param);
if (asd->params.css_param.update_flag.dz_config)
atomisp_css_set_dz_config(asd,
&asd->params.css_param.dz_config);
atomisp_css_update_isp_params(asd);
asd->params.css_update_params_needed = false;
memset(&asd->params.css_param.update_flag, 0,
sizeof(struct atomisp_parameters));
}
asd->params.dvs_6axis = NULL;
ret = atomisp_css_start(asd, css_pipe_id, false);
if (ret)
goto out;
asd->streaming = ATOMISP_DEVICE_STREAMING_ENABLED;
atomic_set(&asd->sof_count, -1);
atomic_set(&asd->sequence, -1);
atomic_set(&asd->sequence_temp, -1);
if (isp->sw_contex.file_input)
wdt_duration = ATOMISP_ISP_FILE_TIMEOUT_DURATION;
asd->params.dis_proj_data_valid = false;
asd->latest_preview_exp_id = 0;
asd->postview_exp_id = 1;
asd->preview_exp_id = 1;
atomisp_handle_parameter_and_buffer(pipe);
atomisp_qbuffers_to_css(asd);
if (atomisp_subdev_streaming_count(asd) < sensor_start_stream)
goto out;
start_sensor:
if (isp->flash) {
asd->params.num_flash_frames = 0;
asd->params.flash_state = ATOMISP_FLASH_IDLE;
atomisp_setup_flash(asd);
}
if (!isp->sw_contex.file_input) {
atomisp_css_irq_enable(isp, CSS_IRQ_INFO_CSS_RECEIVER_SOF,
atomisp_css_valid_sof(isp));
atomisp_csi2_configure(asd);
if (atomisp_streaming_count(isp) > 1) {
if (atomisp_freq_scaling(isp,
ATOMISP_DFS_MODE_MAX, false) < 0)
dev_dbg(isp->dev, "dfs failed!\n");
} else {
if (atomisp_freq_scaling(isp,
ATOMISP_DFS_MODE_AUTO, false) < 0)
dev_dbg(isp->dev, "dfs failed!\n");
}
} else {
if (atomisp_freq_scaling(isp, ATOMISP_DFS_MODE_MAX, false) < 0)
dev_dbg(isp->dev, "dfs failed!\n");
}
if (asd->depth_mode->val && atomisp_streaming_count(isp) ==
ATOMISP_DEPTH_SENSOR_STREAMON_COUNT) {
ret = atomisp_stream_on_master_slave_sensor(isp, false);
if (ret) {
dev_err(isp->dev, "master slave sensor stream on failed!\n");
goto out;
}
#ifndef ISP2401
__wdt_on_master_slave_sensor(isp, wdt_duration);
#else
__wdt_on_master_slave_sensor(pipe, wdt_duration, true);
#endif
goto start_delay_wq;
} else if (asd->depth_mode->val && (atomisp_streaming_count(isp) <
ATOMISP_DEPTH_SENSOR_STREAMON_COUNT)) {
#ifdef ISP2401
__wdt_on_master_slave_sensor(pipe, wdt_duration, false);
#endif
goto start_delay_wq;
}
if (isp->media_dev.hw_revision >= ((ATOMISP_HW_REVISION_ISP2401 <<
ATOMISP_HW_REVISION_SHIFT) | ATOMISP_HW_STEPPING_B0)) {
pci_write_config_word(isp->pdev, MRFLD_PCI_CSI_CONTROL,
isp->saved_regs.csi_control |
MRFLD_PCI_CSI_CONTROL_CSI_READY);
}
ret = v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
video, s_stream, 1);
if (ret) {
asd->streaming = ATOMISP_DEVICE_STREAMING_DISABLED;
ret = -EINVAL;
goto out;
}
#ifndef ISP2401
if (atomisp_buffers_queued(asd))
atomisp_wdt_refresh(asd, wdt_duration);
#else
if (atomisp_buffers_queued_pipe(pipe))
atomisp_wdt_refresh_pipe(pipe, wdt_duration);
#endif
start_delay_wq:
if (asd->continuous_mode->val) {
struct v4l2_mbus_framefmt *sink;
sink = atomisp_subdev_get_ffmt(&asd->subdev, NULL,
V4L2_SUBDEV_FORMAT_ACTIVE,
ATOMISP_SUBDEV_PAD_SINK);
reinit_completion(&asd->init_done);
asd->delayed_init = ATOMISP_DELAYED_INIT_QUEUED;
queue_work(asd->delayed_init_workq, &asd->delayed_init_work);
atomisp_css_set_cont_prev_start_time(isp,
ATOMISP_CALC_CSS_PREV_OVERLAP(sink->height));
} else {
asd->delayed_init = ATOMISP_DELAYED_INIT_NOT_QUEUED;
}
out:
rt_mutex_unlock(&isp->mutex);
return ret;
}
int __atomisp_streamoff(struct file *file, void *fh, enum v4l2_buf_type type)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_video_pipe *pipe = atomisp_to_video_pipe(vdev);
struct atomisp_sub_device *asd = pipe->asd;
struct atomisp_video_pipe *capture_pipe = NULL;
struct atomisp_video_pipe *vf_pipe = NULL;
struct atomisp_video_pipe *preview_pipe = NULL;
struct atomisp_video_pipe *video_pipe = NULL;
struct videobuf_buffer *vb, *_vb;
enum atomisp_css_pipe_id css_pipe_id;
int ret;
unsigned long flags;
bool first_streamoff = false;
dev_dbg(isp->dev, "Stop stream on pad %d for asd%d\n",
atomisp_subdev_source_pad(vdev), asd->index);
BUG_ON(!rt_mutex_is_locked(&isp->mutex));
BUG_ON(!mutex_is_locked(&isp->streamoff_mutex));
if (type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_dbg(isp->dev, "unsupported v4l2 buf type\n");
return -EINVAL;
}
if ((asd->continuous_mode->val ||
isp->inputs[asd->input_curr].camera_caps->multi_stream_ctrl) &&
atomisp_subdev_source_pad(vdev) !=
ATOMISP_SUBDEV_PAD_SOURCE_PREVIEW &&
atomisp_subdev_source_pad(vdev) !=
ATOMISP_SUBDEV_PAD_SOURCE_VIDEO) {
if (isp->inputs[asd->input_curr].camera_caps->multi_stream_ctrl) {
v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
video, s_stream, 0);
} else if (atomisp_subdev_source_pad(vdev)
== ATOMISP_SUBDEV_PAD_SOURCE_CAPTURE) {
if (asd->params.offline_parm.num_captures == -1)
atomisp_css_offline_capture_configure(asd,
0, 0, 0);
atomisp_freq_scaling(isp, ATOMISP_DFS_MODE_AUTO, false);
}
if (pipe->buffers_in_css != 0) {
WARN(1, "%s: buffers of vdev %s still in CSS!\n",
__func__, pipe->vdev.name);
dev_warn(isp->dev, "Reset CSS to clean up css buffers.\n");
atomisp_css_flush(isp);
}
return videobuf_streamoff(&pipe->capq);
}
if (!pipe->capq.streaming)
return 0;
spin_lock_irqsave(&isp->lock, flags);
if (asd->streaming == ATOMISP_DEVICE_STREAMING_ENABLED) {
asd->streaming = ATOMISP_DEVICE_STREAMING_STOPPING;
first_streamoff = true;
}
spin_unlock_irqrestore(&isp->lock, flags);
if (first_streamoff) {
rt_mutex_unlock(&isp->mutex);
atomisp_wdt_stop(asd, true);
if (isp->sw_contex.file_input)
v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
video, s_stream, 0);
rt_mutex_lock(&isp->mutex);
atomisp_acc_unload_extensions(asd);
}
spin_lock_irqsave(&isp->lock, flags);
if (atomisp_subdev_streaming_count(asd) == 1)
asd->streaming = ATOMISP_DEVICE_STREAMING_DISABLED;
spin_unlock_irqrestore(&isp->lock, flags);
if (!first_streamoff) {
ret = videobuf_streamoff(&pipe->capq);
if (ret)
return ret;
goto stopsensor;
}
atomisp_clear_css_buffer_counters(asd);
if (!isp->sw_contex.file_input)
atomisp_css_irq_enable(isp, CSS_IRQ_INFO_CSS_RECEIVER_SOF,
false);
if (asd->delayed_init == ATOMISP_DELAYED_INIT_QUEUED) {
cancel_work_sync(&asd->delayed_init_work);
asd->delayed_init = ATOMISP_DELAYED_INIT_NOT_QUEUED;
}
if (first_streamoff) {
css_pipe_id = atomisp_get_css_pipe_id(asd);
ret = atomisp_css_stop(asd, css_pipe_id, false);
}
if (asd->video_out_capture.users) {
capture_pipe = &asd->video_out_capture;
wake_up_interruptible(&capture_pipe->capq.wait);
}
if (asd->video_out_vf.users) {
vf_pipe = &asd->video_out_vf;
wake_up_interruptible(&vf_pipe->capq.wait);
}
if (asd->video_out_preview.users) {
preview_pipe = &asd->video_out_preview;
wake_up_interruptible(&preview_pipe->capq.wait);
}
if (asd->video_out_video_capture.users) {
video_pipe = &asd->video_out_video_capture;
wake_up_interruptible(&video_pipe->capq.wait);
}
ret = videobuf_streamoff(&pipe->capq);
if (ret)
return ret;
spin_lock_irqsave(&pipe->irq_lock, flags);
list_for_each_entry_safe(vb, _vb, &pipe->activeq, queue) {
vb->state = VIDEOBUF_PREPARED;
list_del(&vb->queue);
}
list_for_each_entry_safe(vb, _vb, &pipe->buffers_waiting_for_param, queue) {
vb->state = VIDEOBUF_PREPARED;
list_del(&vb->queue);
pipe->frame_request_config_id[vb->i] = 0;
}
spin_unlock_irqrestore(&pipe->irq_lock, flags);
atomisp_subdev_cleanup_pending_events(asd);
stopsensor:
if (atomisp_subdev_streaming_count(asd) + 1
!= atomisp_sensor_start_stream(asd))
return 0;
if (!isp->sw_contex.file_input)
ret = v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
video, s_stream, 0);
if (isp->flash) {
asd->params.num_flash_frames = 0;
asd->params.flash_state = ATOMISP_FLASH_IDLE;
}
if (atomisp_streaming_count(isp)) {
atomisp_css_flush(isp);
return 0;
}
if (isp->media_dev.hw_revision >= ((ATOMISP_HW_REVISION_ISP2401 <<
ATOMISP_HW_REVISION_SHIFT) | ATOMISP_HW_STEPPING_B0)) {
pci_write_config_word(isp->pdev, MRFLD_PCI_CSI_CONTROL,
isp->saved_regs.csi_control &
~MRFLD_PCI_CSI_CONTROL_CSI_READY);
}
if (atomisp_freq_scaling(isp, ATOMISP_DFS_MODE_LOW, false))
dev_warn(isp->dev, "DFS failed.\n");
if (isp->sw_contex.power_state == ATOM_ISP_POWER_UP) {
unsigned int i;
bool recreate_streams[MAX_STREAM_NUM] = {0};
if (isp->isp_timeout)
dev_err(isp->dev, "%s: Resetting with WA activated",
__func__);
for (i = 0; i < isp->num_of_streams; i++) {
if (isp->asd[i].stream_prepared) {
atomisp_destroy_pipes_stream_force(&isp->
asd[i]);
recreate_streams[i] = true;
}
}
pci_write_config_dword(isp->pdev, PCI_I_CONTROL, isp->saved_regs.i_control |
MRFLD_PCI_I_CONTROL_SRSE_RESET_MASK);
dev_err(isp->dev, "atomisp_reset");
atomisp_reset(isp);
for (i = 0; i < isp->num_of_streams; i++) {
if (recreate_streams[i])
atomisp_create_pipes_stream(&isp->asd[i]);
}
isp->isp_timeout = false;
}
return ret;
}
static int atomisp_streamoff(struct file *file, void *fh,
enum v4l2_buf_type type)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
int rval;
mutex_lock(&isp->streamoff_mutex);
rt_mutex_lock(&isp->mutex);
rval = __atomisp_streamoff(file, fh, type);
rt_mutex_unlock(&isp->mutex);
mutex_unlock(&isp->streamoff_mutex);
return rval;
}
static int atomisp_g_ctrl(struct file *file, void *fh,
struct v4l2_control *control)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
int i, ret = -EINVAL;
for (i = 0; i < ctrls_num; i++) {
if (ci_v4l2_controls[i].id == control->id) {
ret = 0;
break;
}
}
if (ret)
return ret;
rt_mutex_lock(&isp->mutex);
switch (control->id) {
case V4L2_CID_IRIS_ABSOLUTE:
case V4L2_CID_EXPOSURE_ABSOLUTE:
case V4L2_CID_FNUMBER_ABSOLUTE:
case V4L2_CID_2A_STATUS:
case V4L2_CID_AUTO_N_PRESET_WHITE_BALANCE:
case V4L2_CID_EXPOSURE:
case V4L2_CID_EXPOSURE_AUTO:
case V4L2_CID_SCENE_MODE:
case V4L2_CID_ISO_SENSITIVITY:
case V4L2_CID_ISO_SENSITIVITY_AUTO:
case V4L2_CID_CONTRAST:
case V4L2_CID_SATURATION:
case V4L2_CID_SHARPNESS:
case V4L2_CID_3A_LOCK:
case V4L2_CID_EXPOSURE_ZONE_NUM:
case V4L2_CID_TEST_PATTERN:
case V4L2_CID_TEST_PATTERN_COLOR_R:
case V4L2_CID_TEST_PATTERN_COLOR_GR:
case V4L2_CID_TEST_PATTERN_COLOR_GB:
case V4L2_CID_TEST_PATTERN_COLOR_B:
rt_mutex_unlock(&isp->mutex);
return v4l2_g_ctrl(isp->inputs[asd->input_curr].camera->
ctrl_handler, control);
case V4L2_CID_COLORFX:
ret = atomisp_color_effect(asd, 0, &control->value);
break;
case V4L2_CID_ATOMISP_BAD_PIXEL_DETECTION:
ret = atomisp_bad_pixel(asd, 0, &control->value);
break;
case V4L2_CID_ATOMISP_POSTPROCESS_GDC_CAC:
ret = atomisp_gdc_cac(asd, 0, &control->value);
break;
case V4L2_CID_ATOMISP_VIDEO_STABLIZATION:
ret = atomisp_video_stable(asd, 0, &control->value);
break;
case V4L2_CID_ATOMISP_FIXED_PATTERN_NR:
ret = atomisp_fixed_pattern(asd, 0, &control->value);
break;
case V4L2_CID_ATOMISP_FALSE_COLOR_CORRECTION:
ret = atomisp_false_color(asd, 0, &control->value);
break;
case V4L2_CID_ATOMISP_LOW_LIGHT:
ret = atomisp_low_light(asd, 0, &control->value);
break;
default:
ret = -EINVAL;
break;
}
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_s_ctrl(struct file *file, void *fh,
struct v4l2_control *control)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
int i, ret = -EINVAL;
for (i = 0; i < ctrls_num; i++) {
if (ci_v4l2_controls[i].id == control->id) {
ret = 0;
break;
}
}
if (ret)
return ret;
rt_mutex_lock(&isp->mutex);
switch (control->id) {
case V4L2_CID_AUTO_N_PRESET_WHITE_BALANCE:
case V4L2_CID_EXPOSURE:
case V4L2_CID_EXPOSURE_AUTO:
case V4L2_CID_EXPOSURE_AUTO_PRIORITY:
case V4L2_CID_SCENE_MODE:
case V4L2_CID_ISO_SENSITIVITY:
case V4L2_CID_ISO_SENSITIVITY_AUTO:
case V4L2_CID_POWER_LINE_FREQUENCY:
case V4L2_CID_EXPOSURE_METERING:
case V4L2_CID_CONTRAST:
case V4L2_CID_SATURATION:
case V4L2_CID_SHARPNESS:
case V4L2_CID_3A_LOCK:
case V4L2_CID_COLORFX_CBCR:
case V4L2_CID_TEST_PATTERN:
case V4L2_CID_TEST_PATTERN_COLOR_R:
case V4L2_CID_TEST_PATTERN_COLOR_GR:
case V4L2_CID_TEST_PATTERN_COLOR_GB:
case V4L2_CID_TEST_PATTERN_COLOR_B:
rt_mutex_unlock(&isp->mutex);
return v4l2_s_ctrl(NULL,
isp->inputs[asd->input_curr].camera->
ctrl_handler, control);
case V4L2_CID_COLORFX:
ret = atomisp_color_effect(asd, 1, &control->value);
break;
case V4L2_CID_ATOMISP_BAD_PIXEL_DETECTION:
ret = atomisp_bad_pixel(asd, 1, &control->value);
break;
case V4L2_CID_ATOMISP_POSTPROCESS_GDC_CAC:
ret = atomisp_gdc_cac(asd, 1, &control->value);
break;
case V4L2_CID_ATOMISP_VIDEO_STABLIZATION:
ret = atomisp_video_stable(asd, 1, &control->value);
break;
case V4L2_CID_ATOMISP_FIXED_PATTERN_NR:
ret = atomisp_fixed_pattern(asd, 1, &control->value);
break;
case V4L2_CID_ATOMISP_FALSE_COLOR_CORRECTION:
ret = atomisp_false_color(asd, 1, &control->value);
break;
case V4L2_CID_REQUEST_FLASH:
ret = atomisp_flash_enable(asd, control->value);
break;
case V4L2_CID_ATOMISP_LOW_LIGHT:
ret = atomisp_low_light(asd, 1, &control->value);
break;
default:
ret = -EINVAL;
break;
}
rt_mutex_unlock(&isp->mutex);
return ret;
}
static int atomisp_queryctl(struct file *file, void *fh,
struct v4l2_queryctrl *qc)
{
int i, ret = -EINVAL;
struct video_device *vdev = video_devdata(file);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
switch (qc->id) {
case V4L2_CID_FOCUS_ABSOLUTE:
case V4L2_CID_FOCUS_RELATIVE:
case V4L2_CID_FOCUS_STATUS:
#ifndef ISP2401
return v4l2_queryctrl(isp->inputs[asd->input_curr].camera->
ctrl_handler, qc);
#else
if (isp->motor)
return v4l2_queryctrl(isp->motor->ctrl_handler, qc);
else
return v4l2_queryctrl(isp->inputs[asd->input_curr].
camera->ctrl_handler, qc);
#endif
}
if (qc->id & V4L2_CTRL_FLAG_NEXT_CTRL)
return ret;
for (i = 0; i < ctrls_num; i++) {
if (ci_v4l2_controls[i].id == qc->id) {
memcpy(qc, &ci_v4l2_controls[i],
sizeof(struct v4l2_queryctrl));
qc->reserved[0] = 0;
ret = 0;
break;
}
}
if (ret != 0)
qc->flags = V4L2_CTRL_FLAG_DISABLED;
return ret;
}
static int atomisp_camera_g_ext_ctrls(struct file *file, void *fh,
struct v4l2_ext_controls *c)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
struct v4l2_control ctrl;
int i;
int ret = 0;
for (i = 0; i < c->count; i++) {
ctrl.id = c->controls[i].id;
ctrl.value = c->controls[i].value;
switch (ctrl.id) {
case V4L2_CID_EXPOSURE_ABSOLUTE:
case V4L2_CID_EXPOSURE_AUTO:
case V4L2_CID_IRIS_ABSOLUTE:
case V4L2_CID_FNUMBER_ABSOLUTE:
case V4L2_CID_BIN_FACTOR_HORZ:
case V4L2_CID_BIN_FACTOR_VERT:
case V4L2_CID_3A_LOCK:
case V4L2_CID_TEST_PATTERN:
case V4L2_CID_TEST_PATTERN_COLOR_R:
case V4L2_CID_TEST_PATTERN_COLOR_GR:
case V4L2_CID_TEST_PATTERN_COLOR_GB:
case V4L2_CID_TEST_PATTERN_COLOR_B:
ret =
v4l2_g_ctrl(isp->inputs[asd->input_curr].camera->
ctrl_handler, &ctrl);
break;
case V4L2_CID_FOCUS_ABSOLUTE:
case V4L2_CID_FOCUS_RELATIVE:
case V4L2_CID_FOCUS_STATUS:
case V4L2_CID_FOCUS_AUTO:
#ifndef ISP2401
if (isp->inputs[asd->input_curr].motor)
#else
if (isp->motor)
#endif
ret =
#ifndef ISP2401
v4l2_g_ctrl(isp->inputs[asd->input_curr].
motor->ctrl_handler, &ctrl);
#else
v4l2_g_ctrl(isp->motor->ctrl_handler,
&ctrl);
#endif
else
ret =
v4l2_g_ctrl(isp->inputs[asd->input_curr].
camera->ctrl_handler, &ctrl);
break;
case V4L2_CID_FLASH_STATUS:
case V4L2_CID_FLASH_INTENSITY:
case V4L2_CID_FLASH_TORCH_INTENSITY:
case V4L2_CID_FLASH_INDICATOR_INTENSITY:
case V4L2_CID_FLASH_TIMEOUT:
case V4L2_CID_FLASH_STROBE:
case V4L2_CID_FLASH_MODE:
case V4L2_CID_FLASH_STATUS_REGISTER:
if (isp->flash)
ret =
v4l2_g_ctrl(isp->flash->ctrl_handler,
&ctrl);
break;
case V4L2_CID_ZOOM_ABSOLUTE:
rt_mutex_lock(&isp->mutex);
ret = atomisp_digital_zoom(asd, 0, &ctrl.value);
rt_mutex_unlock(&isp->mutex);
break;
case V4L2_CID_G_SKIP_FRAMES:
ret = v4l2_subdev_call(
isp->inputs[asd->input_curr].camera,
sensor, g_skip_frames, (u32 *)&ctrl.value);
break;
default:
ret = -EINVAL;
}
if (ret) {
c->error_idx = i;
break;
}
c->controls[i].value = ctrl.value;
}
return ret;
}
static int atomisp_g_ext_ctrls(struct file *file, void *fh,
struct v4l2_ext_controls *c)
{
struct v4l2_control ctrl;
int i, ret = 0;
ret = atomisp_camera_g_ext_ctrls(file, fh, c);
if (ret != -EINVAL)
return ret;
for (i = 0; i < c->count; i++) {
ctrl.id = c->controls[i].id;
ctrl.value = c->controls[i].value;
ret = atomisp_g_ctrl(file, fh, &ctrl);
c->controls[i].value = ctrl.value;
if (ret) {
c->error_idx = i;
break;
}
}
return ret;
}
static int atomisp_camera_s_ext_ctrls(struct file *file, void *fh,
struct v4l2_ext_controls *c)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
struct v4l2_control ctrl;
int i;
int ret = 0;
for (i = 0; i < c->count; i++) {
struct v4l2_ctrl *ctr;
ctrl.id = c->controls[i].id;
ctrl.value = c->controls[i].value;
switch (ctrl.id) {
case V4L2_CID_EXPOSURE_ABSOLUTE:
case V4L2_CID_EXPOSURE_AUTO:
case V4L2_CID_EXPOSURE_METERING:
case V4L2_CID_IRIS_ABSOLUTE:
case V4L2_CID_FNUMBER_ABSOLUTE:
case V4L2_CID_VCM_TIMEING:
case V4L2_CID_VCM_SLEW:
case V4L2_CID_3A_LOCK:
case V4L2_CID_TEST_PATTERN:
case V4L2_CID_TEST_PATTERN_COLOR_R:
case V4L2_CID_TEST_PATTERN_COLOR_GR:
case V4L2_CID_TEST_PATTERN_COLOR_GB:
case V4L2_CID_TEST_PATTERN_COLOR_B:
ret = v4l2_s_ctrl(NULL,
isp->inputs[asd->input_curr].camera->
ctrl_handler, &ctrl);
break;
case V4L2_CID_FOCUS_ABSOLUTE:
case V4L2_CID_FOCUS_RELATIVE:
case V4L2_CID_FOCUS_STATUS:
case V4L2_CID_FOCUS_AUTO:
#ifndef ISP2401
if (isp->inputs[asd->input_curr].motor)
#else
if (isp->motor)
#endif
ret = v4l2_s_ctrl(NULL,
#ifndef ISP2401
isp->inputs[asd->input_curr].
motor->ctrl_handler, &ctrl);
#else
isp->motor->ctrl_handler,
&ctrl);
#endif
else
ret = v4l2_s_ctrl(NULL,
isp->inputs[asd->input_curr].
camera->ctrl_handler, &ctrl);
break;
case V4L2_CID_FLASH_STATUS:
case V4L2_CID_FLASH_INTENSITY:
case V4L2_CID_FLASH_TORCH_INTENSITY:
case V4L2_CID_FLASH_INDICATOR_INTENSITY:
case V4L2_CID_FLASH_TIMEOUT:
case V4L2_CID_FLASH_STROBE:
case V4L2_CID_FLASH_MODE:
case V4L2_CID_FLASH_STATUS_REGISTER:
rt_mutex_lock(&isp->mutex);
if (isp->flash) {
ret =
v4l2_s_ctrl(NULL, isp->flash->ctrl_handler,
&ctrl);
if (ctrl.id == V4L2_CID_FLASH_MODE) {
asd->params.flash_state =
ATOMISP_FLASH_IDLE;
asd->params.num_flash_frames = 0;
}
}
rt_mutex_unlock(&isp->mutex);
break;
case V4L2_CID_ZOOM_ABSOLUTE:
rt_mutex_lock(&isp->mutex);
ret = atomisp_digital_zoom(asd, 1, &ctrl.value);
rt_mutex_unlock(&isp->mutex);
break;
default:
ctr = v4l2_ctrl_find(&asd->ctrl_handler, ctrl.id);
if (ctr)
ret = v4l2_ctrl_s_ctrl(ctr, ctrl.value);
else
ret = -EINVAL;
}
if (ret) {
c->error_idx = i;
break;
}
c->controls[i].value = ctrl.value;
}
int atomisp_s_ext_ctrls(struct file *file, void *fh,
struct v4l2_ext_controls *c)
{
struct v4l2_control ctrl;
int i, ret = 0;
ret = atomisp_camera_s_ext_ctrls(file, fh, c);
if (ret != -EINVAL)
return ret;
for (i = 0; i < c->count; i++) {
ctrl.id = c->controls[i].id;
ctrl.value = c->controls[i].value;
ret = atomisp_s_ctrl(file, fh, &ctrl);
c->controls[i].value = ctrl.value;
if (ret) {
c->error_idx = i;
break;
}
}
return ret;
}
static int atomisp_g_parm(struct file *file, void *fh,
struct v4l2_streamparm *parm)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
struct atomisp_device *isp = video_get_drvdata(vdev);
if (parm->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_err(isp->dev, "unsupport v4l2 buf type\n");
return -EINVAL;
}
rt_mutex_lock(&isp->mutex);
parm->parm.capture.capturemode = asd->run_mode->val;
rt_mutex_unlock(&isp->mutex);
return 0;
}
static int atomisp_s_parm(struct file *file, void *fh,
struct v4l2_streamparm *parm)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_sub_device *asd = atomisp_to_video_pipe(vdev)->asd;
int mode;
int rval;
int fps;
if (parm->type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_err(isp->dev, "unsupport v4l2 buf type\n");
return -EINVAL;
}
rt_mutex_lock(&isp->mutex);
asd->high_speed_mode = false;
switch (parm->parm.capture.capturemode) {
case CI_MODE_NONE: {
struct v4l2_subdev_frame_interval fi = {0};
fi.interval = parm->parm.capture.timeperframe;
rval = v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
video, s_frame_interval, &fi);
if (!rval)
parm->parm.capture.timeperframe = fi.interval;
if (fi.interval.numerator != 0) {
fps = fi.interval.denominator / fi.interval.numerator;
if (fps > 30)
asd->high_speed_mode = true;
}
goto out;
}
case CI_MODE_VIDEO:
mode = ATOMISP_RUN_MODE_VIDEO;
break;
case CI_MODE_STILL_CAPTURE:
mode = ATOMISP_RUN_MODE_STILL_CAPTURE;
break;
case CI_MODE_CONTINUOUS:
mode = ATOMISP_RUN_MODE_CONTINUOUS_CAPTURE;
break;
case CI_MODE_PREVIEW:
mode = ATOMISP_RUN_MODE_PREVIEW;
break;
default:
rval = -EINVAL;
goto out;
}
rval = v4l2_ctrl_s_ctrl(asd->run_mode, mode);
out:
rt_mutex_unlock(&isp->mutex);
return rval == -ENOIOCTLCMD ? 0 : rval;
}
static int atomisp_s_parm_file(struct file *file, void *fh,
struct v4l2_streamparm *parm)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
if (parm->type != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
dev_err(isp->dev, "unsupport v4l2 buf type for output\n");
return -EINVAL;
}
rt_mutex_lock(&isp->mutex);
isp->sw_contex.file_input = 1;
rt_mutex_unlock(&isp->mutex);
return 0;
}
static long atomisp_vidioc_default(struct file *file, void *fh,
bool valid_prio, unsigned int cmd, void *arg)
{
struct video_device *vdev = video_devdata(file);
struct atomisp_device *isp = video_get_drvdata(vdev);
struct atomisp_sub_device *asd;
bool acc_node;
int err;
acc_node = !strncmp(vdev->name, "ATOMISP ISP ACC",
sizeof(vdev->name));
if (acc_node)
asd = atomisp_to_acc_pipe(vdev)->asd;
else
asd = atomisp_to_video_pipe(vdev)->asd;
switch (cmd) {
case ATOMISP_IOC_G_MOTOR_PRIV_INT_DATA:
case ATOMISP_IOC_S_EXPOSURE:
case ATOMISP_IOC_G_SENSOR_CALIBRATION_GROUP:
case ATOMISP_IOC_G_SENSOR_PRIV_INT_DATA:
case ATOMISP_IOC_EXT_ISP_CTRL:
case ATOMISP_IOC_G_SENSOR_AE_BRACKETING_INFO:
case ATOMISP_IOC_S_SENSOR_AE_BRACKETING_MODE:
case ATOMISP_IOC_G_SENSOR_AE_BRACKETING_MODE:
case ATOMISP_IOC_S_SENSOR_AE_BRACKETING_LUT:
case ATOMISP_IOC_S_SENSOR_EE_CONFIG:
#ifdef ISP2401
case ATOMISP_IOC_G_UPDATE_EXPOSURE:
#endif
break;
default:
rt_mutex_lock(&isp->mutex);
break;
}
switch (cmd) {
#ifdef ISP2401
case ATOMISP_IOC_S_SENSOR_RUNMODE:
err = atomisp_set_sensor_runmode(asd, arg);
break;
#endif
case ATOMISP_IOC_G_XNR:
err = atomisp_xnr(asd, 0, arg);
break;
case ATOMISP_IOC_S_XNR:
err = atomisp_xnr(asd, 1, arg);
break;
case ATOMISP_IOC_G_NR:
err = atomisp_nr(asd, 0, arg);
break;
case ATOMISP_IOC_S_NR:
err = atomisp_nr(asd, 1, arg);
break;
case ATOMISP_IOC_G_TNR:
err = atomisp_tnr(asd, 0, arg);
break;
case ATOMISP_IOC_S_TNR:
err = atomisp_tnr(asd, 1, arg);
break;
case ATOMISP_IOC_G_BLACK_LEVEL_COMP:
err = atomisp_black_level(asd, 0, arg);
break;
case ATOMISP_IOC_S_BLACK_LEVEL_COMP:
err = atomisp_black_level(asd, 1, arg);
break;
case ATOMISP_IOC_G_EE:
err = atomisp_ee(asd, 0, arg);
break;
case ATOMISP_IOC_S_EE:
err = atomisp_ee(asd, 1, arg);
break;
case ATOMISP_IOC_G_DIS_STAT:
err = atomisp_get_dis_stat(asd, arg);
break;
case ATOMISP_IOC_G_DVS2_BQ_RESOLUTIONS:
err = atomisp_get_dvs2_bq_resolutions(asd, arg);
break;
case ATOMISP_IOC_S_DIS_COEFS:
err = atomisp_css_cp_dvs2_coefs(asd, arg,
&asd->params.css_param, true);
if (!err && arg)
asd->params.css_update_params_needed = true;
break;
case ATOMISP_IOC_S_DIS_VECTOR:
err = atomisp_cp_dvs_6axis_config(asd, arg,
&asd->params.css_param, true);
if (!err && arg)
asd->params.css_update_params_needed = true;
break;
case ATOMISP_IOC_G_ISP_PARM:
err = atomisp_param(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_PARM:
err = atomisp_param(asd, 1, arg);
break;
case ATOMISP_IOC_G_3A_STAT:
err = atomisp_3a_stat(asd, 0, arg);
break;
case ATOMISP_IOC_G_ISP_GAMMA:
err = atomisp_gamma(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_GAMMA:
err = atomisp_gamma(asd, 1, arg);
break;
case ATOMISP_IOC_G_ISP_GDC_TAB:
err = atomisp_gdc_cac_table(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_GDC_TAB:
err = atomisp_gdc_cac_table(asd, 1, arg);
break;
case ATOMISP_IOC_G_ISP_MACC:
err = atomisp_macc_table(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_MACC:
err = atomisp_macc_table(asd, 1, arg);
break;
case ATOMISP_IOC_G_ISP_BAD_PIXEL_DETECTION:
err = atomisp_bad_pixel_param(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_BAD_PIXEL_DETECTION:
err = atomisp_bad_pixel_param(asd, 1, arg);
break;
case ATOMISP_IOC_G_ISP_FALSE_COLOR_CORRECTION:
err = atomisp_false_color_param(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_FALSE_COLOR_CORRECTION:
err = atomisp_false_color_param(asd, 1, arg);
break;
case ATOMISP_IOC_G_ISP_CTC:
err = atomisp_ctc(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_CTC:
err = atomisp_ctc(asd, 1, arg);
break;
case ATOMISP_IOC_G_ISP_WHITE_BALANCE:
err = atomisp_white_balance_param(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_WHITE_BALANCE:
err = atomisp_white_balance_param(asd, 1, arg);
break;
case ATOMISP_IOC_G_3A_CONFIG:
err = atomisp_3a_config_param(asd, 0, arg);
break;
case ATOMISP_IOC_S_3A_CONFIG:
err = atomisp_3a_config_param(asd, 1, arg);
break;
case ATOMISP_IOC_S_ISP_FPN_TABLE:
err = atomisp_fixed_pattern_table(asd, arg);
break;
case ATOMISP_IOC_ISP_MAKERNOTE:
err = atomisp_exif_makernote(asd, arg);
break;
case ATOMISP_IOC_G_SENSOR_MODE_DATA:
err = atomisp_get_sensor_mode_data(asd, arg);
break;
case ATOMISP_IOC_G_MOTOR_PRIV_INT_DATA:
#ifndef ISP2401
if (isp->inputs[asd->input_curr].motor)
#else
if (isp->motor)
#endif
err = v4l2_subdev_call(
#ifndef ISP2401
isp->inputs[asd->input_curr].motor,
#else
isp->motor,
#endif
core, ioctl, cmd, arg);
else
err = v4l2_subdev_call(
isp->inputs[asd->input_curr].camera,
core, ioctl, cmd, arg);
break;
case ATOMISP_IOC_S_EXPOSURE:
case ATOMISP_IOC_G_SENSOR_CALIBRATION_GROUP:
case ATOMISP_IOC_G_SENSOR_PRIV_INT_DATA:
case ATOMISP_IOC_G_SENSOR_AE_BRACKETING_INFO:
case ATOMISP_IOC_S_SENSOR_AE_BRACKETING_MODE:
case ATOMISP_IOC_G_SENSOR_AE_BRACKETING_MODE:
case ATOMISP_IOC_S_SENSOR_AE_BRACKETING_LUT:
#ifdef ISP2401
case ATOMISP_IOC_G_UPDATE_EXPOSURE:
#endif
err = v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
core, ioctl, cmd, arg);
break;
case ATOMISP_IOC_ACC_LOAD:
err = atomisp_acc_load(asd, arg);
break;
case ATOMISP_IOC_ACC_LOAD_TO_PIPE:
err = atomisp_acc_load_to_pipe(asd, arg);
break;
case ATOMISP_IOC_ACC_UNLOAD:
err = atomisp_acc_unload(asd, arg);
break;
case ATOMISP_IOC_ACC_START:
err = atomisp_acc_start(asd, arg);
break;
case ATOMISP_IOC_ACC_WAIT:
err = atomisp_acc_wait(asd, arg);
break;
case ATOMISP_IOC_ACC_MAP:
err = atomisp_acc_map(asd, arg);
break;
case ATOMISP_IOC_ACC_UNMAP:
err = atomisp_acc_unmap(asd, arg);
break;
case ATOMISP_IOC_ACC_S_MAPPED_ARG:
err = atomisp_acc_s_mapped_arg(asd, arg);
break;
case ATOMISP_IOC_S_ISP_SHD_TAB:
err = atomisp_set_shading_table(asd, arg);
break;
case ATOMISP_IOC_G_ISP_GAMMA_CORRECTION:
err = atomisp_gamma_correction(asd, 0, arg);
break;
case ATOMISP_IOC_S_ISP_GAMMA_CORRECTION:
err = atomisp_gamma_correction(asd, 1, arg);
break;
case ATOMISP_IOC_S_PARAMETERS:
err = atomisp_set_parameters(vdev, arg);
break;
case ATOMISP_IOC_S_CONT_CAPTURE_CONFIG:
err = atomisp_offline_capture_configure(asd, arg);
break;
case ATOMISP_IOC_G_METADATA:
err = atomisp_get_metadata(asd, 0, arg);
break;
case ATOMISP_IOC_G_METADATA_BY_TYPE:
err = atomisp_get_metadata_by_type(asd, 0, arg);
break;
case ATOMISP_IOC_EXT_ISP_CTRL:
err = v4l2_subdev_call(isp->inputs[asd->input_curr].camera,
core, ioctl, cmd, arg);
break;
case ATOMISP_IOC_EXP_ID_UNLOCK:
err = atomisp_exp_id_unlock(asd, arg);
break;
case ATOMISP_IOC_EXP_ID_CAPTURE:
err = atomisp_exp_id_capture(asd, arg);
break;
case ATOMISP_IOC_S_ENABLE_DZ_CAPT_PIPE:
err = atomisp_enable_dz_capt_pipe(asd, arg);
break;
case ATOMISP_IOC_G_FORMATS_CONFIG:
err = atomisp_formats(asd, 0, arg);
break;
case ATOMISP_IOC_S_FORMATS_CONFIG:
err = atomisp_formats(asd, 1, arg);
break;
case ATOMISP_IOC_S_EXPOSURE_WINDOW:
err = atomisp_s_ae_window(asd, arg);
break;
case ATOMISP_IOC_S_ACC_STATE:
err = atomisp_acc_set_state(asd, arg);
break;
case ATOMISP_IOC_G_ACC_STATE:
err = atomisp_acc_get_state(asd, arg);
break;
case ATOMISP_IOC_INJECT_A_FAKE_EVENT:
err = atomisp_inject_a_fake_event(asd, arg);
break;
case ATOMISP_IOC_G_INVALID_FRAME_NUM:
err = atomisp_get_invalid_frame_num(vdev, arg);
break;
case ATOMISP_IOC_S_ARRAY_RESOLUTION:
err = atomisp_set_array_res(asd, arg);
break;
default:
err = -EINVAL;
break;
}
switch (cmd) {
case ATOMISP_IOC_G_MOTOR_PRIV_INT_DATA:
case ATOMISP_IOC_S_EXPOSURE:
case ATOMISP_IOC_G_SENSOR_CALIBRATION_GROUP:
case ATOMISP_IOC_G_SENSOR_PRIV_INT_DATA:
case ATOMISP_IOC_EXT_ISP_CTRL:
case ATOMISP_IOC_G_SENSOR_AE_BRACKETING_INFO:
case ATOMISP_IOC_S_SENSOR_AE_BRACKETING_MODE:
case ATOMISP_IOC_G_SENSOR_AE_BRACKETING_MODE:
case ATOMISP_IOC_S_SENSOR_AE_BRACKETING_LUT:
#ifdef ISP2401
case ATOMISP_IOC_G_UPDATE_EXPOSURE:
#endif
break;
default:
rt_mutex_unlock(&isp->mutex);
break;
}
return err;
}
