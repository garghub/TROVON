static struct media_entity *vpfe_get_input_entity
(struct vpfe_video_device *video)
{
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct media_pad *remote;
remote = media_entity_remote_pad(&vpfe_dev->vpfe_isif.pads[0]);
if (!remote) {
pr_err("Invalid media connection to isif/ccdc\n");
return NULL;
}
return remote->entity;
}
static int vpfe_update_current_ext_subdev(struct vpfe_video_device *video)
{
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_config *vpfe_cfg;
struct v4l2_subdev *subdev;
struct media_pad *remote;
int i;
remote = media_entity_remote_pad(&vpfe_dev->vpfe_isif.pads[0]);
if (!remote) {
pr_err("Invalid media connection to isif/ccdc\n");
return -EINVAL;
}
subdev = media_entity_to_v4l2_subdev(remote->entity);
vpfe_cfg = vpfe_dev->pdev->platform_data;
for (i = 0; i < vpfe_cfg->num_subdevs; i++) {
if (!strcmp(vpfe_cfg->sub_devs[i].module_name, subdev->name)) {
video->current_ext_subdev = &vpfe_cfg->sub_devs[i];
break;
}
}
if (i == vpfe_cfg->num_subdevs) {
pr_err("Invalid media chain connection to isif/ccdc\n");
return -EINVAL;
}
for (i = 0; i < vpfe_dev->num_ext_subdevs; i++) {
if (!strcmp(video->current_ext_subdev->module_name,
vpfe_dev->sd[i]->name))
video->current_ext_subdev->subdev = vpfe_dev->sd[i];
}
return 0;
}
static struct v4l2_subdev *
vpfe_video_remote_subdev(struct vpfe_video_device *video, u32 *pad)
{
struct media_pad *remote = media_entity_remote_pad(&video->pad);
if (!remote || !is_media_entity_v4l2_subdev(remote->entity))
return NULL;
if (pad)
*pad = remote->index;
return media_entity_to_v4l2_subdev(remote->entity);
}
static int
__vpfe_video_get_format(struct vpfe_video_device *video,
struct v4l2_format *format)
{
struct v4l2_subdev_format fmt;
struct v4l2_subdev *subdev;
struct media_pad *remote;
u32 pad;
int ret;
subdev = vpfe_video_remote_subdev(video, &pad);
if (!subdev)
return -EINVAL;
fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
remote = media_entity_remote_pad(&video->pad);
fmt.pad = remote->index;
ret = v4l2_subdev_call(subdev, pad, get_fmt, NULL, &fmt);
if (ret == -ENOIOCTLCMD)
return -EINVAL;
format->type = video->type;
v4l2_fill_pix_format(&format->fmt.pix, &fmt.format);
mbus_to_pix(&fmt.format, &format->fmt.pix);
return 0;
}
static int vpfe_prepare_pipeline(struct vpfe_video_device *video)
{
struct media_graph graph;
struct media_entity *entity = &video->video_dev.entity;
struct media_device *mdev = entity->graph_obj.mdev;
struct vpfe_pipeline *pipe = &video->pipe;
struct vpfe_video_device *far_end = NULL;
int ret;
pipe->input_num = 0;
pipe->output_num = 0;
if (video->type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
pipe->inputs[pipe->input_num++] = video;
else
pipe->outputs[pipe->output_num++] = video;
mutex_lock(&mdev->graph_mutex);
ret = media_graph_walk_init(&graph, mdev);
if (ret) {
mutex_unlock(&mdev->graph_mutex);
return -ENOMEM;
}
media_graph_walk_start(&graph, entity);
while ((entity = media_graph_walk_next(&graph))) {
if (entity == &video->video_dev.entity)
continue;
if (!is_media_entity_v4l2_video_device(entity))
continue;
far_end = to_vpfe_video(media_entity_to_video_device(entity));
if (far_end->type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
pipe->inputs[pipe->input_num++] = far_end;
else
pipe->outputs[pipe->output_num++] = far_end;
}
media_graph_walk_cleanup(&graph);
mutex_unlock(&mdev->graph_mutex);
return 0;
}
static int vpfe_update_pipe_state(struct vpfe_video_device *video)
{
struct vpfe_pipeline *pipe = &video->pipe;
int ret;
ret = vpfe_prepare_pipeline(video);
if (ret)
return ret;
if (pipe->input_num == 0) {
pipe->state = VPFE_PIPELINE_STREAM_CONTINUOUS;
ret = vpfe_update_current_ext_subdev(video);
if (ret) {
pr_err("Invalid external subdev\n");
return ret;
}
} else {
pipe->state = VPFE_PIPELINE_STREAM_SINGLESHOT;
}
video->initialized = 1;
video->skip_frame_count = 1;
video->skip_frame_count_init = 1;
return 0;
}
int vpfe_video_is_pipe_ready(struct vpfe_pipeline *pipe)
{
int i;
for (i = 0; i < pipe->input_num; i++)
if (!pipe->inputs[i]->started ||
pipe->inputs[i]->state != VPFE_VIDEO_BUFFER_QUEUED)
return 0;
for (i = 0; i < pipe->output_num; i++)
if (!pipe->outputs[i]->started ||
pipe->outputs[i]->state != VPFE_VIDEO_BUFFER_QUEUED)
return 0;
return 1;
}
static int vpfe_video_validate_pipeline(struct vpfe_pipeline *pipe)
{
struct v4l2_subdev_format fmt_source;
struct v4l2_subdev_format fmt_sink;
struct v4l2_subdev *subdev;
struct media_pad *pad;
int ret;
subdev = vpfe_video_remote_subdev(pipe->outputs[0], NULL);
if (!subdev)
return -EPIPE;
while (1) {
pad = &subdev->entity.pads[0];
if (!(pad->flags & MEDIA_PAD_FL_SINK))
break;
fmt_sink.which = V4L2_SUBDEV_FORMAT_ACTIVE;
fmt_sink.pad = pad->index;
ret = v4l2_subdev_call(subdev, pad, get_fmt, NULL,
&fmt_sink);
if (ret < 0 && ret != -ENOIOCTLCMD)
return -EPIPE;
pad = media_entity_remote_pad(pad);
if (!pad || !is_media_entity_v4l2_subdev(pad->entity))
break;
subdev = media_entity_to_v4l2_subdev(pad->entity);
fmt_source.which = V4L2_SUBDEV_FORMAT_ACTIVE;
fmt_source.pad = pad->index;
ret = v4l2_subdev_call(subdev, pad, get_fmt, NULL, &fmt_source);
if (ret < 0 && ret != -ENOIOCTLCMD)
return -EPIPE;
if (fmt_source.format.code != fmt_sink.format.code ||
fmt_source.format.width != fmt_sink.format.width ||
fmt_source.format.height != fmt_sink.format.height)
return -EPIPE;
}
return 0;
}
static int vpfe_pipeline_enable(struct vpfe_pipeline *pipe)
{
struct media_entity *entity;
struct v4l2_subdev *subdev;
struct media_device *mdev;
int ret;
if (pipe->state == VPFE_PIPELINE_STREAM_CONTINUOUS)
entity = vpfe_get_input_entity(pipe->outputs[0]);
else
entity = &pipe->inputs[0]->video_dev.entity;
mdev = entity->graph_obj.mdev;
mutex_lock(&mdev->graph_mutex);
ret = media_graph_walk_init(&pipe->graph, mdev);
if (ret)
goto out;
media_graph_walk_start(&pipe->graph, entity);
while ((entity = media_graph_walk_next(&pipe->graph))) {
if (!is_media_entity_v4l2_subdev(entity))
continue;
subdev = media_entity_to_v4l2_subdev(entity);
ret = v4l2_subdev_call(subdev, video, s_stream, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
break;
}
out:
if (ret)
media_graph_walk_cleanup(&pipe->graph);
mutex_unlock(&mdev->graph_mutex);
return ret;
}
static int vpfe_pipeline_disable(struct vpfe_pipeline *pipe)
{
struct media_entity *entity;
struct v4l2_subdev *subdev;
struct media_device *mdev;
int ret = 0;
if (pipe->state == VPFE_PIPELINE_STREAM_CONTINUOUS)
entity = vpfe_get_input_entity(pipe->outputs[0]);
else
entity = &pipe->inputs[0]->video_dev.entity;
mdev = entity->graph_obj.mdev;
mutex_lock(&mdev->graph_mutex);
media_graph_walk_start(&pipe->graph, entity);
while ((entity = media_graph_walk_next(&pipe->graph))) {
if (!is_media_entity_v4l2_subdev(entity))
continue;
subdev = media_entity_to_v4l2_subdev(entity);
ret = v4l2_subdev_call(subdev, video, s_stream, 0);
if (ret < 0 && ret != -ENOIOCTLCMD)
break;
}
mutex_unlock(&mdev->graph_mutex);
media_graph_walk_cleanup(&pipe->graph);
return ret ? -ETIMEDOUT : 0;
}
static int vpfe_pipeline_set_stream(struct vpfe_pipeline *pipe,
enum vpfe_pipeline_stream_state state)
{
if (state == VPFE_PIPELINE_STREAM_STOPPED)
return vpfe_pipeline_disable(pipe);
return vpfe_pipeline_enable(pipe);
}
static int all_videos_stopped(struct vpfe_video_device *video)
{
struct vpfe_pipeline *pipe = &video->pipe;
int i;
for (i = 0; i < pipe->input_num; i++)
if (pipe->inputs[i]->started)
return 0;
for (i = 0; i < pipe->output_num; i++)
if (pipe->outputs[i]->started)
return 0;
return 1;
}
static int vpfe_open(struct file *file)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_fh *handle;
handle = kzalloc(sizeof(struct vpfe_fh), GFP_KERNEL);
if (!handle)
return -ENOMEM;
v4l2_fh_init(&handle->vfh, &video->video_dev);
v4l2_fh_add(&handle->vfh);
mutex_lock(&video->lock);
if (!video->initialized && vpfe_update_pipe_state(video)) {
mutex_unlock(&video->lock);
return -ENODEV;
}
video->usrs++;
handle->io_allowed = 0;
handle->video = video;
file->private_data = &handle->vfh;
mutex_unlock(&video->lock);
return 0;
}
static unsigned long
vpfe_video_get_next_buffer(struct vpfe_video_device *video)
{
video->cur_frm = video->next_frm =
list_entry(video->dma_queue.next,
struct vpfe_cap_buffer, list);
list_del(&video->next_frm->list);
video->next_frm->vb.vb2_buf.state = VB2_BUF_STATE_ACTIVE;
return vb2_dma_contig_plane_dma_addr(&video->next_frm->vb.vb2_buf, 0);
}
void vpfe_video_schedule_next_buffer(struct vpfe_video_device *video)
{
struct vpfe_device *vpfe_dev = video->vpfe_dev;
unsigned long addr;
if (list_empty(&video->dma_queue))
return;
video->next_frm = list_entry(video->dma_queue.next,
struct vpfe_cap_buffer, list);
if (video->pipe.state == VPFE_PIPELINE_STREAM_SINGLESHOT)
video->cur_frm = video->next_frm;
list_del(&video->next_frm->list);
video->next_frm->vb.vb2_buf.state = VB2_BUF_STATE_ACTIVE;
addr = vb2_dma_contig_plane_dma_addr(&video->next_frm->vb.vb2_buf, 0);
video->ops->queue(vpfe_dev, addr);
video->state = VPFE_VIDEO_BUFFER_QUEUED;
}
void vpfe_video_schedule_bottom_field(struct vpfe_video_device *video)
{
struct vpfe_device *vpfe_dev = video->vpfe_dev;
unsigned long addr;
addr = vb2_dma_contig_plane_dma_addr(&video->cur_frm->vb.vb2_buf, 0);
addr += video->field_off;
video->ops->queue(vpfe_dev, addr);
}
void vpfe_video_process_buffer_complete(struct vpfe_video_device *video)
{
struct vpfe_pipeline *pipe = &video->pipe;
video->cur_frm->vb.vb2_buf.timestamp = ktime_get_ns();
vb2_buffer_done(&video->cur_frm->vb.vb2_buf, VB2_BUF_STATE_DONE);
if (pipe->state == VPFE_PIPELINE_STREAM_CONTINUOUS)
video->cur_frm = video->next_frm;
}
static void vpfe_stop_capture(struct vpfe_video_device *video)
{
struct vpfe_pipeline *pipe = &video->pipe;
video->started = 0;
if (video->type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
return;
if (all_videos_stopped(video))
vpfe_pipeline_set_stream(pipe,
VPFE_PIPELINE_STREAM_STOPPED);
}
static int vpfe_release(struct file *file)
{
struct vpfe_video_device *video = video_drvdata(file);
struct v4l2_fh *vfh = file->private_data;
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_fh *fh = container_of(vfh, struct vpfe_fh, vfh);
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_release\n");
mutex_lock(&video->lock);
if (fh->io_allowed) {
if (video->started) {
vpfe_stop_capture(video);
video->pipe.state = VPFE_PIPELINE_STREAM_STOPPED;
vb2_streamoff(&video->buffer_queue,
video->buffer_queue.type);
}
video->io_usrs = 0;
vb2_queue_release(&video->buffer_queue);
}
video->usrs--;
v4l2_fh_del(&fh->vfh);
v4l2_fh_exit(&fh->vfh);
if (!video->usrs)
video->initialized = 0;
mutex_unlock(&video->lock);
file->private_data = NULL;
v4l2_fh_del(vfh);
kzfree(fh);
return 0;
}
static int vpfe_mmap(struct file *file, struct vm_area_struct *vma)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_mmap\n");
return vb2_mmap(&video->buffer_queue, vma);
}
static unsigned int vpfe_poll(struct file *file, poll_table *wait)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_poll\n");
if (video->started)
return vb2_poll(&video->buffer_queue, file, wait);
return 0;
}
static int vpfe_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_querycap\n");
if (video->type == V4L2_BUF_TYPE_VIDEO_CAPTURE)
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING;
else
cap->device_caps = V4L2_CAP_VIDEO_OUTPUT | V4L2_CAP_STREAMING;
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OUTPUT |
V4L2_CAP_STREAMING | V4L2_CAP_DEVICE_CAPS;
strlcpy(cap->driver, CAPTURE_DRV_NAME, sizeof(cap->driver));
strlcpy(cap->bus_info, "VPFE", sizeof(cap->bus_info));
strlcpy(cap->card, vpfe_dev->cfg->card_name, sizeof(cap->card));
return 0;
}
static int vpfe_g_fmt(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_g_fmt\n");
*fmt = video->fmt;
return 0;
}
static int vpfe_enum_fmt(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct v4l2_subdev_format sd_fmt;
struct v4l2_mbus_framefmt mbus;
struct v4l2_subdev *subdev;
struct v4l2_format format;
struct media_pad *remote;
int ret;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_enum_fmt\n");
if (fmt->index > 0) {
v4l2_err(&vpfe_dev->v4l2_dev, "Invalid index\n");
return -EINVAL;
}
remote = media_entity_remote_pad(&video->pad);
if (!remote) {
v4l2_err(&vpfe_dev->v4l2_dev,
"invalid remote pad for video node\n");
return -EINVAL;
}
subdev = vpfe_video_remote_subdev(video, NULL);
if (!subdev) {
v4l2_err(&vpfe_dev->v4l2_dev,
"invalid remote subdev for video node\n");
return -EINVAL;
}
sd_fmt.pad = remote->index;
sd_fmt.which = V4L2_SUBDEV_FORMAT_ACTIVE;
ret = v4l2_subdev_call(subdev, pad, get_fmt, NULL, &sd_fmt);
if (ret) {
v4l2_err(&vpfe_dev->v4l2_dev,
"invalid remote subdev for video node\n");
return ret;
}
mbus.code = sd_fmt.format.code;
mbus_to_pix(&mbus, &format.fmt.pix);
fmt->pixelformat = format.fmt.pix.pixelformat;
return 0;
}
static int vpfe_s_fmt(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct v4l2_format format;
int ret;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_s_fmt\n");
if (video->started) {
v4l2_err(&vpfe_dev->v4l2_dev, "Streaming is started\n");
return -EBUSY;
}
ret = __vpfe_video_get_format(video, &format);
if (ret)
return ret;
*fmt = format;
video->fmt = *fmt;
return 0;
}
static int vpfe_try_fmt(struct file *file, void *priv,
struct v4l2_format *fmt)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct v4l2_format format;
int ret;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_try_fmt\n");
ret = __vpfe_video_get_format(video, &format);
if (ret)
return ret;
*fmt = format;
return 0;
}
static int vpfe_enum_input(struct file *file, void *priv,
struct v4l2_input *inp)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_ext_subdev_info *sdinfo = video->current_ext_subdev;
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_enum_input\n");
if (inp->index < sdinfo->num_inputs) {
memcpy(inp, &sdinfo->inputs[inp->index],
sizeof(struct v4l2_input));
return 0;
}
return -EINVAL;
}
static int vpfe_g_input(struct file *file, void *priv, unsigned int *index)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_g_input\n");
*index = video->current_input;
return 0;
}
static int vpfe_s_input(struct file *file, void *priv, unsigned int index)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_ext_subdev_info *sdinfo;
struct vpfe_route *route;
struct v4l2_input *inps;
u32 output;
u32 input;
int ret;
int i;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_s_input\n");
ret = mutex_lock_interruptible(&video->lock);
if (ret)
return ret;
if (video->started) {
v4l2_err(&vpfe_dev->v4l2_dev, "Streaming is on\n");
ret = -EBUSY;
goto unlock_out;
}
sdinfo = video->current_ext_subdev;
if (!sdinfo->registered) {
ret = -EINVAL;
goto unlock_out;
}
if (vpfe_dev->cfg->setup_input &&
vpfe_dev->cfg->setup_input(sdinfo->grp_id) < 0) {
ret = -EFAULT;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev,
"couldn't setup input for %s\n",
sdinfo->module_name);
goto unlock_out;
}
route = &sdinfo->routes[index];
if (route && sdinfo->can_route) {
input = route->input;
output = route->output;
ret = v4l2_device_call_until_err(&vpfe_dev->v4l2_dev,
sdinfo->grp_id, video,
s_routing, input, output, 0);
if (ret) {
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev,
"s_input:error in setting input in decoder\n");
ret = -EINVAL;
goto unlock_out;
}
}
for (i = 0; i < sdinfo->num_inputs; i++) {
inps = &sdinfo->inputs[i];
video->video_dev.tvnorms |= inps->std;
}
video->current_input = index;
unlock_out:
mutex_unlock(&video->lock);
return ret;
}
static int vpfe_querystd(struct file *file, void *priv, v4l2_std_id *std_id)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_ext_subdev_info *sdinfo;
int ret;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_querystd\n");
ret = mutex_lock_interruptible(&video->lock);
sdinfo = video->current_ext_subdev;
if (ret)
return ret;
ret = v4l2_device_call_until_err(&vpfe_dev->v4l2_dev, sdinfo->grp_id,
video, querystd, std_id);
mutex_unlock(&video->lock);
return ret;
}
static int vpfe_s_std(struct file *file, void *priv, v4l2_std_id std_id)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_ext_subdev_info *sdinfo;
int ret;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_s_std\n");
ret = mutex_lock_interruptible(&video->lock);
if (ret)
return ret;
sdinfo = video->current_ext_subdev;
if (video->started) {
v4l2_err(&vpfe_dev->v4l2_dev, "streaming is started\n");
ret = -EBUSY;
goto unlock_out;
}
ret = v4l2_device_call_until_err(&vpfe_dev->v4l2_dev, sdinfo->grp_id,
video, s_std, std_id);
if (ret < 0) {
v4l2_err(&vpfe_dev->v4l2_dev, "Failed to set standard\n");
video->stdid = V4L2_STD_UNKNOWN;
goto unlock_out;
}
video->stdid = std_id;
unlock_out:
mutex_unlock(&video->lock);
return ret;
}
static int vpfe_g_std(struct file *file, void *priv, v4l2_std_id *tvnorm)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_g_std\n");
*tvnorm = video->stdid;
return 0;
}
static int
vpfe_enum_dv_timings(struct file *file, void *fh,
struct v4l2_enum_dv_timings *timings)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct v4l2_subdev *subdev = video->current_ext_subdev->subdev;
timings->pad = 0;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_enum_dv_timings\n");
return v4l2_subdev_call(subdev, pad, enum_dv_timings, timings);
}
static int
vpfe_query_dv_timings(struct file *file, void *fh,
struct v4l2_dv_timings *timings)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct v4l2_subdev *subdev = video->current_ext_subdev->subdev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_query_dv_timings\n");
return v4l2_subdev_call(subdev, video, query_dv_timings, timings);
}
static int
vpfe_s_dv_timings(struct file *file, void *fh,
struct v4l2_dv_timings *timings)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_s_dv_timings\n");
video->stdid = V4L2_STD_UNKNOWN;
return v4l2_device_call_until_err(&vpfe_dev->v4l2_dev,
video->current_ext_subdev->grp_id,
video, s_dv_timings, timings);
}
static int
vpfe_g_dv_timings(struct file *file, void *fh,
struct v4l2_dv_timings *timings)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct v4l2_subdev *subdev = video->current_ext_subdev->subdev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_g_dv_timings\n");
return v4l2_subdev_call(subdev, video, g_dv_timings, timings);
}
static int
vpfe_buffer_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct vpfe_fh *fh = vb2_get_drv_priv(vq);
struct vpfe_video_device *video = fh->video;
struct vpfe_device *vpfe_dev = video->vpfe_dev;
unsigned long size;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_buffer_queue_setup\n");
size = video->fmt.fmt.pix.sizeimage;
if (vq->num_buffers + *nbuffers < 3)
*nbuffers = 3 - vq->num_buffers;
*nplanes = 1;
sizes[0] = size;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev,
"nbuffers=%d, size=%lu\n", *nbuffers, size);
return 0;
}
static int vpfe_buffer_prepare(struct vb2_buffer *vb)
{
struct vpfe_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vpfe_video_device *video = fh->video;
struct vpfe_device *vpfe_dev = video->vpfe_dev;
unsigned long addr;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_buffer_prepare\n");
if (vb->state != VB2_BUF_STATE_ACTIVE &&
vb->state != VB2_BUF_STATE_PREPARED)
return 0;
vb2_set_plane_payload(vb, 0, video->fmt.fmt.pix.sizeimage);
if (vb2_plane_vaddr(vb, 0) &&
vb2_get_plane_payload(vb, 0) > vb2_plane_size(vb, 0))
return -EINVAL;
addr = vb2_dma_contig_plane_dma_addr(vb, 0);
if (!ALIGN(addr, 32))
return -EINVAL;
return 0;
}
static void vpfe_buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vpfe_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vpfe_video_device *video = fh->video;
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_pipeline *pipe = &video->pipe;
struct vpfe_cap_buffer *buf = container_of(vbuf,
struct vpfe_cap_buffer, vb);
unsigned long flags;
unsigned long empty;
unsigned long addr;
spin_lock_irqsave(&video->dma_queue_lock, flags);
empty = list_empty(&video->dma_queue);
list_add_tail(&buf->list, &video->dma_queue);
spin_unlock_irqrestore(&video->dma_queue_lock, flags);
if (empty && video->started && pipe->state ==
VPFE_PIPELINE_STREAM_SINGLESHOT &&
video->state == VPFE_VIDEO_BUFFER_NOT_QUEUED) {
spin_lock(&video->dma_queue_lock);
addr = vpfe_video_get_next_buffer(video);
video->ops->queue(vpfe_dev, addr);
video->state = VPFE_VIDEO_BUFFER_QUEUED;
spin_unlock(&video->dma_queue_lock);
if (vpfe_video_is_pipe_ready(pipe))
vpfe_pipeline_set_stream(pipe,
VPFE_PIPELINE_STREAM_SINGLESHOT);
}
}
static int vpfe_start_capture(struct vpfe_video_device *video)
{
struct vpfe_pipeline *pipe = &video->pipe;
int ret = 0;
video->started = 1;
if (vpfe_video_is_pipe_ready(pipe))
ret = vpfe_pipeline_set_stream(pipe, pipe->state);
return ret;
}
static int vpfe_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct vpfe_fh *fh = vb2_get_drv_priv(vq);
struct vpfe_video_device *video = fh->video;
struct vpfe_device *vpfe_dev = video->vpfe_dev;
unsigned long addr;
int ret;
ret = mutex_lock_interruptible(&video->lock);
if (ret)
goto streamoff;
video->cur_frm = video->next_frm =
list_entry(video->dma_queue.next, struct vpfe_cap_buffer, list);
list_del(&video->cur_frm->list);
video->cur_frm->vb.vb2_buf.state = VB2_BUF_STATE_ACTIVE;
video->field_id = 0;
addr = vb2_dma_contig_plane_dma_addr(&video->cur_frm->vb.vb2_buf, 0);
video->ops->queue(vpfe_dev, addr);
video->state = VPFE_VIDEO_BUFFER_QUEUED;
ret = vpfe_start_capture(video);
if (ret) {
struct vpfe_cap_buffer *buf, *tmp;
vb2_buffer_done(&video->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_QUEUED);
list_for_each_entry_safe(buf, tmp, &video->dma_queue, list) {
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf,
VB2_BUF_STATE_QUEUED);
}
goto unlock_out;
}
mutex_unlock(&video->lock);
return ret;
unlock_out:
mutex_unlock(&video->lock);
streamoff:
ret = vb2_streamoff(&video->buffer_queue, video->buffer_queue.type);
return 0;
}
static int vpfe_buffer_init(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vpfe_cap_buffer *buf = container_of(vbuf,
struct vpfe_cap_buffer, vb);
INIT_LIST_HEAD(&buf->list);
return 0;
}
static void vpfe_stop_streaming(struct vb2_queue *vq)
{
struct vpfe_fh *fh = vb2_get_drv_priv(vq);
struct vpfe_video_device *video = fh->video;
if (video->cur_frm == video->next_frm) {
vb2_buffer_done(&video->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
} else {
if (video->cur_frm != NULL)
vb2_buffer_done(&video->cur_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
if (video->next_frm != NULL)
vb2_buffer_done(&video->next_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
}
while (!list_empty(&video->dma_queue)) {
video->next_frm = list_entry(video->dma_queue.next,
struct vpfe_cap_buffer, list);
list_del(&video->next_frm->list);
vb2_buffer_done(&video->next_frm->vb.vb2_buf,
VB2_BUF_STATE_ERROR);
}
}
static void vpfe_buf_cleanup(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vpfe_fh *fh = vb2_get_drv_priv(vb->vb2_queue);
struct vpfe_video_device *video = fh->video;
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_cap_buffer *buf = container_of(vbuf,
struct vpfe_cap_buffer, vb);
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_buf_cleanup\n");
if (vb->state == VB2_BUF_STATE_ACTIVE)
list_del_init(&buf->list);
}
static int vpfe_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *req_buf)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_fh *fh = file->private_data;
struct vb2_queue *q;
int ret;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_reqbufs\n");
if (req_buf->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
req_buf->type != V4L2_BUF_TYPE_VIDEO_OUTPUT){
v4l2_err(&vpfe_dev->v4l2_dev, "Invalid buffer type\n");
return -EINVAL;
}
ret = mutex_lock_interruptible(&video->lock);
if (ret)
return ret;
if (video->io_usrs != 0) {
v4l2_err(&vpfe_dev->v4l2_dev, "Only one IO user allowed\n");
ret = -EBUSY;
goto unlock_out;
}
video->memory = req_buf->memory;
q = &video->buffer_queue;
q->type = req_buf->type;
q->io_modes = VB2_MMAP | VB2_USERPTR;
q->drv_priv = fh;
q->min_buffers_needed = 1;
q->ops = &video_qops;
q->mem_ops = &vb2_dma_contig_memops;
q->buf_struct_size = sizeof(struct vpfe_cap_buffer);
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->dev = vpfe_dev->pdev;
ret = vb2_queue_init(q);
if (ret) {
v4l2_err(&vpfe_dev->v4l2_dev, "vb2_queue_init() failed\n");
goto unlock_out;
}
fh->io_allowed = 1;
video->io_usrs = 1;
INIT_LIST_HEAD(&video->dma_queue);
ret = vb2_reqbufs(&video->buffer_queue, req_buf);
unlock_out:
mutex_unlock(&video->lock);
return ret;
}
static int vpfe_querybuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_querybuf\n");
if (buf->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
buf->type != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_err(&vpfe_dev->v4l2_dev, "Invalid buf type\n");
return -EINVAL;
}
if (video->memory != V4L2_MEMORY_MMAP) {
v4l2_err(&vpfe_dev->v4l2_dev, "Invalid memory\n");
return -EINVAL;
}
return vb2_querybuf(&video->buffer_queue, buf);
}
static int vpfe_qbuf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_fh *fh = file->private_data;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_qbuf\n");
if (p->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
p->type != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_err(&vpfe_dev->v4l2_dev, "Invalid buf type\n");
return -EINVAL;
}
if (!fh->io_allowed) {
v4l2_err(&vpfe_dev->v4l2_dev, "fh->io_allowed\n");
return -EACCES;
}
return vb2_qbuf(&video->buffer_queue, p);
}
static int vpfe_dqbuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_dqbuf\n");
if (buf->type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
buf->type != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_err(&vpfe_dev->v4l2_dev, "Invalid buf type\n");
return -EINVAL;
}
return vb2_dqbuf(&video->buffer_queue,
buf, (file->f_flags & O_NONBLOCK));
}
static int vpfe_streamon(struct file *file, void *priv,
enum v4l2_buf_type buf_type)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_pipeline *pipe = &video->pipe;
struct vpfe_fh *fh = file->private_data;
struct vpfe_ext_subdev_info *sdinfo;
int ret = -EINVAL;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_streamon\n");
if (buf_type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
buf_type != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_err(&vpfe_dev->v4l2_dev, "Invalid buf type\n");
return ret;
}
if (!fh->io_allowed) {
v4l2_err(&vpfe_dev->v4l2_dev, "fh->io_allowed\n");
return -EACCES;
}
sdinfo = video->current_ext_subdev;
if (list_empty(&video->buffer_queue.queued_list)) {
v4l2_err(&vpfe_dev->v4l2_dev, "buffer queue is empty\n");
return -EIO;
}
if (buf_type == V4L2_BUF_TYPE_VIDEO_CAPTURE) {
ret = vpfe_video_validate_pipeline(pipe);
if (ret < 0)
return ret;
}
return vb2_streamon(&video->buffer_queue, buf_type);
}
static int vpfe_streamoff(struct file *file, void *priv,
enum v4l2_buf_type buf_type)
{
struct vpfe_video_device *video = video_drvdata(file);
struct vpfe_device *vpfe_dev = video->vpfe_dev;
struct vpfe_fh *fh = file->private_data;
int ret = 0;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_streamoff\n");
if (buf_type != V4L2_BUF_TYPE_VIDEO_CAPTURE &&
buf_type != V4L2_BUF_TYPE_VIDEO_OUTPUT) {
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "Invalid buf type\n");
return -EINVAL;
}
if (!fh->io_allowed) {
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "fh->io_allowed\n");
return -EACCES;
}
if (!video->started) {
v4l2_err(&vpfe_dev->v4l2_dev, "device is not started\n");
return -EINVAL;
}
ret = mutex_lock_interruptible(&video->lock);
if (ret)
return ret;
vpfe_stop_capture(video);
ret = vb2_streamoff(&video->buffer_queue, buf_type);
mutex_unlock(&video->lock);
return ret;
}
int vpfe_video_init(struct vpfe_video_device *video, const char *name)
{
const char *direction;
int ret;
switch (video->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
direction = "output";
video->pad.flags = MEDIA_PAD_FL_SINK;
video->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
break;
case V4L2_BUF_TYPE_VIDEO_OUTPUT:
direction = "input";
video->pad.flags = MEDIA_PAD_FL_SOURCE;
video->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
break;
default:
return -EINVAL;
}
video->video_dev.release = video_device_release;
video->video_dev.fops = &vpfe_fops;
video->video_dev.ioctl_ops = &vpfe_ioctl_ops;
video->video_dev.minor = -1;
video->video_dev.tvnorms = 0;
snprintf(video->video_dev.name, sizeof(video->video_dev.name),
"DAVINCI VIDEO %s %s", name, direction);
spin_lock_init(&video->irqlock);
spin_lock_init(&video->dma_queue_lock);
mutex_init(&video->lock);
ret = media_entity_pads_init(&video->video_dev.entity,
1, &video->pad);
if (ret < 0)
return ret;
video_set_drvdata(&video->video_dev, video);
return 0;
}
int vpfe_video_register(struct vpfe_video_device *video,
struct v4l2_device *vdev)
{
int ret;
video->video_dev.v4l2_dev = vdev;
ret = video_register_device(&video->video_dev, VFL_TYPE_GRABBER, -1);
if (ret < 0)
pr_err("%s: could not register video device (%d)\n",
__func__, ret);
return ret;
}
void vpfe_video_unregister(struct vpfe_video_device *video)
{
if (video_is_registered(&video->video_dev)) {
video_unregister_device(&video->video_dev);
media_entity_cleanup(&video->video_dev.entity);
}
}
