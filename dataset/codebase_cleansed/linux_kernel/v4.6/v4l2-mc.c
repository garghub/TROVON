int v4l2_mc_create_media_graph(struct media_device *mdev)
{
struct media_entity *entity;
struct media_entity *if_vid = NULL, *if_aud = NULL;
struct media_entity *tuner = NULL, *decoder = NULL;
struct media_entity *io_v4l = NULL, *io_vbi = NULL, *io_swradio = NULL;
bool is_webcam = false;
u32 flags;
int ret;
if (!mdev)
return 0;
media_device_for_each_entity(entity, mdev) {
switch (entity->function) {
case MEDIA_ENT_F_IF_VID_DECODER:
if_vid = entity;
break;
case MEDIA_ENT_F_IF_AUD_DECODER:
if_aud = entity;
break;
case MEDIA_ENT_F_TUNER:
tuner = entity;
break;
case MEDIA_ENT_F_ATV_DECODER:
decoder = entity;
break;
case MEDIA_ENT_F_IO_V4L:
io_v4l = entity;
break;
case MEDIA_ENT_F_IO_VBI:
io_vbi = entity;
break;
case MEDIA_ENT_F_IO_SWRADIO:
io_swradio = entity;
break;
case MEDIA_ENT_F_CAM_SENSOR:
is_webcam = true;
break;
}
}
if (!io_v4l && !io_vbi && !io_swradio)
return -EINVAL;
if (is_webcam) {
if (!io_v4l)
return -EINVAL;
media_device_for_each_entity(entity, mdev) {
if (entity->function != MEDIA_ENT_F_CAM_SENSOR)
continue;
ret = media_create_pad_link(entity, 0,
io_v4l, 0,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
}
if (!decoder)
return 0;
}
if (!decoder)
return -EINVAL;
if (tuner) {
if (if_vid) {
ret = media_create_pad_link(tuner, TUNER_PAD_OUTPUT,
if_vid,
IF_VID_DEC_PAD_IF_INPUT,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
ret = media_create_pad_link(if_vid, IF_VID_DEC_PAD_OUT,
decoder, DEMOD_PAD_IF_INPUT,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
} else {
ret = media_create_pad_link(tuner, TUNER_PAD_OUTPUT,
decoder, DEMOD_PAD_IF_INPUT,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
}
if (if_aud) {
ret = media_create_pad_link(tuner, TUNER_PAD_AUD_OUT,
if_aud,
IF_AUD_DEC_PAD_IF_INPUT,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
} else {
if_aud = tuner;
}
}
if (io_v4l) {
ret = media_create_pad_link(decoder, DEMOD_PAD_VID_OUT,
io_v4l, 0,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
}
if (io_swradio) {
ret = media_create_pad_link(decoder, DEMOD_PAD_VID_OUT,
io_swradio, 0,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
}
if (io_vbi) {
ret = media_create_pad_link(decoder, DEMOD_PAD_VBI_OUT,
io_vbi, 0,
MEDIA_LNK_FL_ENABLED);
if (ret)
return ret;
}
flags = MEDIA_LNK_FL_ENABLED;
media_device_for_each_entity(entity, mdev) {
switch (entity->function) {
case MEDIA_ENT_F_CONN_RF:
if (!tuner)
continue;
ret = media_create_pad_link(entity, 0, tuner,
TUNER_PAD_RF_INPUT,
flags);
break;
case MEDIA_ENT_F_CONN_SVIDEO:
case MEDIA_ENT_F_CONN_COMPOSITE:
ret = media_create_pad_link(entity, 0, decoder,
DEMOD_PAD_IF_INPUT,
flags);
break;
default:
continue;
}
if (ret)
return ret;
flags = 0;
}
return 0;
}
int v4l_enable_media_source(struct video_device *vdev)
{
struct media_device *mdev = vdev->entity.graph_obj.mdev;
int ret;
if (!mdev || !mdev->enable_source)
return 0;
ret = mdev->enable_source(&vdev->entity, &vdev->pipe);
if (ret)
return -EBUSY;
return 0;
}
void v4l_disable_media_source(struct video_device *vdev)
{
struct media_device *mdev = vdev->entity.graph_obj.mdev;
if (mdev && mdev->disable_source)
mdev->disable_source(&vdev->entity);
}
int v4l_vb2q_enable_media_source(struct vb2_queue *q)
{
struct v4l2_fh *fh = q->owner;
if (fh && fh->vdev)
return v4l_enable_media_source(fh->vdev);
return 0;
}
static int pipeline_pm_use_count(struct media_entity *entity,
struct media_entity_graph *graph)
{
int use = 0;
media_entity_graph_walk_start(graph, entity);
while ((entity = media_entity_graph_walk_next(graph))) {
if (is_media_entity_v4l2_io(entity))
use += entity->use_count;
}
return use;
}
static int pipeline_pm_power_one(struct media_entity *entity, int change)
{
struct v4l2_subdev *subdev;
int ret;
subdev = is_media_entity_v4l2_subdev(entity)
? media_entity_to_v4l2_subdev(entity) : NULL;
if (entity->use_count == 0 && change > 0 && subdev != NULL) {
ret = v4l2_subdev_call(subdev, core, s_power, 1);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
}
entity->use_count += change;
WARN_ON(entity->use_count < 0);
if (entity->use_count == 0 && change < 0 && subdev != NULL)
v4l2_subdev_call(subdev, core, s_power, 0);
return 0;
}
static int pipeline_pm_power(struct media_entity *entity, int change,
struct media_entity_graph *graph)
{
struct media_entity *first = entity;
int ret = 0;
if (!change)
return 0;
media_entity_graph_walk_start(graph, entity);
while (!ret && (entity = media_entity_graph_walk_next(graph)))
if (is_media_entity_v4l2_subdev(entity))
ret = pipeline_pm_power_one(entity, change);
if (!ret)
return ret;
media_entity_graph_walk_start(graph, first);
while ((first = media_entity_graph_walk_next(graph))
&& first != entity)
if (is_media_entity_v4l2_subdev(first))
pipeline_pm_power_one(first, -change);
return ret;
}
int v4l2_pipeline_pm_use(struct media_entity *entity, int use)
{
struct media_device *mdev = entity->graph_obj.mdev;
int change = use ? 1 : -1;
int ret;
mutex_lock(&mdev->graph_mutex);
entity->use_count += change;
WARN_ON(entity->use_count < 0);
ret = pipeline_pm_power(entity, change, &mdev->pm_count_walk);
if (ret < 0)
entity->use_count -= change;
mutex_unlock(&mdev->graph_mutex);
return ret;
}
int v4l2_pipeline_link_notify(struct media_link *link, u32 flags,
unsigned int notification)
{
struct media_entity_graph *graph = &link->graph_obj.mdev->pm_count_walk;
struct media_entity *source = link->source->entity;
struct media_entity *sink = link->sink->entity;
int source_use;
int sink_use;
int ret = 0;
source_use = pipeline_pm_use_count(source, graph);
sink_use = pipeline_pm_use_count(sink, graph);
if (notification == MEDIA_DEV_NOTIFY_POST_LINK_CH &&
!(flags & MEDIA_LNK_FL_ENABLED)) {
pipeline_pm_power(source, -sink_use, graph);
pipeline_pm_power(sink, -source_use, graph);
return 0;
}
if (notification == MEDIA_DEV_NOTIFY_PRE_LINK_CH &&
(flags & MEDIA_LNK_FL_ENABLED)) {
ret = pipeline_pm_power(source, sink_use, graph);
if (ret < 0)
return ret;
ret = pipeline_pm_power(sink, source_use, graph);
if (ret < 0)
pipeline_pm_power(source, -sink_use, graph);
}
return ret;
}
