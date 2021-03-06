static inline struct video_mux *v4l2_subdev_to_video_mux(struct v4l2_subdev *sd)
{
return container_of(sd, struct video_mux, subdev);
}
static int video_mux_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct video_mux *vmux = v4l2_subdev_to_video_mux(sd);
int ret = 0;
if (local->flags & MEDIA_PAD_FL_SOURCE)
return 0;
dev_dbg(sd->dev, "link setup '%s':%d->'%s':%d[%d]",
remote->entity->name, remote->index, local->entity->name,
local->index, flags & MEDIA_LNK_FL_ENABLED);
mutex_lock(&vmux->lock);
if (flags & MEDIA_LNK_FL_ENABLED) {
if (vmux->active == local->index)
goto out;
if (vmux->active >= 0) {
ret = -EBUSY;
goto out;
}
dev_dbg(sd->dev, "setting %d active\n", local->index);
ret = mux_control_try_select(vmux->mux, local->index);
if (ret < 0)
goto out;
vmux->active = local->index;
} else {
if (vmux->active != local->index)
goto out;
dev_dbg(sd->dev, "going inactive\n");
mux_control_deselect(vmux->mux);
vmux->active = -1;
}
out:
mutex_unlock(&vmux->lock);
return ret;
}
static int video_mux_s_stream(struct v4l2_subdev *sd, int enable)
{
struct video_mux *vmux = v4l2_subdev_to_video_mux(sd);
struct v4l2_subdev *upstream_sd;
struct media_pad *pad;
if (vmux->active == -1) {
dev_err(sd->dev, "Can not start streaming on inactive mux\n");
return -EINVAL;
}
pad = media_entity_remote_pad(&sd->entity.pads[vmux->active]);
if (!pad) {
dev_err(sd->dev, "Failed to find remote source pad\n");
return -ENOLINK;
}
if (!is_media_entity_v4l2_subdev(pad->entity)) {
dev_err(sd->dev, "Upstream entity is not a v4l2 subdev\n");
return -ENODEV;
}
upstream_sd = media_entity_to_v4l2_subdev(pad->entity);
return v4l2_subdev_call(upstream_sd, video, s_stream, enable);
}
static struct v4l2_mbus_framefmt *
__video_mux_get_pad_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad, u32 which)
{
struct video_mux *vmux = v4l2_subdev_to_video_mux(sd);
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_format(sd, cfg, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &vmux->format_mbus[pad];
default:
return NULL;
}
}
static int video_mux_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct video_mux *vmux = v4l2_subdev_to_video_mux(sd);
mutex_lock(&vmux->lock);
sdformat->format = *__video_mux_get_pad_format(sd, cfg, sdformat->pad,
sdformat->which);
mutex_unlock(&vmux->lock);
return 0;
}
static int video_mux_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct video_mux *vmux = v4l2_subdev_to_video_mux(sd);
struct v4l2_mbus_framefmt *mbusformat;
struct media_pad *pad = &vmux->pads[sdformat->pad];
mbusformat = __video_mux_get_pad_format(sd, cfg, sdformat->pad,
sdformat->which);
if (!mbusformat)
return -EINVAL;
mutex_lock(&vmux->lock);
if ((pad->flags & MEDIA_PAD_FL_SOURCE) && vmux->active >= 0)
sdformat->format = vmux->format_mbus[vmux->active];
*mbusformat = sdformat->format;
mutex_unlock(&vmux->lock);
return 0;
}
static int video_mux_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct device_node *ep;
struct video_mux *vmux;
unsigned int num_pads = 0;
int ret;
int i;
vmux = devm_kzalloc(dev, sizeof(*vmux), GFP_KERNEL);
if (!vmux)
return -ENOMEM;
platform_set_drvdata(pdev, vmux);
v4l2_subdev_init(&vmux->subdev, &video_mux_subdev_ops);
snprintf(vmux->subdev.name, sizeof(vmux->subdev.name), "%s", np->name);
vmux->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vmux->subdev.dev = dev;
for_each_endpoint_of_node(np, ep) {
struct of_endpoint endpoint;
of_graph_parse_endpoint(ep, &endpoint);
num_pads = max(num_pads, endpoint.port + 1);
}
if (num_pads < 2) {
dev_err(dev, "Not enough ports %d\n", num_pads);
return -EINVAL;
}
vmux->mux = devm_mux_control_get(dev, NULL);
if (IS_ERR(vmux->mux)) {
ret = PTR_ERR(vmux->mux);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get mux: %d\n", ret);
return ret;
}
mutex_init(&vmux->lock);
vmux->active = -1;
vmux->pads = devm_kcalloc(dev, num_pads, sizeof(*vmux->pads),
GFP_KERNEL);
vmux->format_mbus = devm_kcalloc(dev, num_pads,
sizeof(*vmux->format_mbus),
GFP_KERNEL);
for (i = 0; i < num_pads - 1; i++)
vmux->pads[i].flags = MEDIA_PAD_FL_SINK;
vmux->pads[num_pads - 1].flags = MEDIA_PAD_FL_SOURCE;
vmux->subdev.entity.function = MEDIA_ENT_F_VID_MUX;
ret = media_entity_pads_init(&vmux->subdev.entity, num_pads,
vmux->pads);
if (ret < 0)
return ret;
vmux->subdev.entity.ops = &video_mux_ops;
return v4l2_async_register_subdev(&vmux->subdev);
}
static int video_mux_remove(struct platform_device *pdev)
{
struct video_mux *vmux = platform_get_drvdata(pdev);
struct v4l2_subdev *sd = &vmux->subdev;
v4l2_async_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
return 0;
}
