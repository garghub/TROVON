void vsp1_entity_route_setup(struct vsp1_entity *source,
struct vsp1_dl_list *dl)
{
struct vsp1_entity *sink;
if (source->route->reg == 0)
return;
sink = container_of(source->sink, struct vsp1_entity, subdev.entity);
vsp1_dl_list_write(dl, source->route->reg,
sink->route->inputs[source->sink_pad]);
}
struct v4l2_subdev_pad_config *
vsp1_entity_get_pad_config(struct vsp1_entity *entity,
struct v4l2_subdev_pad_config *cfg,
enum v4l2_subdev_format_whence which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_ACTIVE:
return entity->config;
case V4L2_SUBDEV_FORMAT_TRY:
default:
return cfg;
}
}
struct v4l2_mbus_framefmt *
vsp1_entity_get_pad_format(struct vsp1_entity *entity,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad)
{
return v4l2_subdev_get_try_format(&entity->subdev, cfg, pad);
}
struct v4l2_rect *
vsp1_entity_get_pad_compose(struct vsp1_entity *entity,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad)
{
return v4l2_subdev_get_try_compose(&entity->subdev, cfg, pad);
}
int vsp1_entity_init_cfg(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg)
{
struct v4l2_subdev_format format;
unsigned int pad;
for (pad = 0; pad < subdev->entity.num_pads - 1; ++pad) {
memset(&format, 0, sizeof(format));
format.pad = pad;
format.which = cfg ? V4L2_SUBDEV_FORMAT_TRY
: V4L2_SUBDEV_FORMAT_ACTIVE;
v4l2_subdev_call(subdev, pad, set_fmt, cfg, &format);
}
return 0;
}
int vsp1_subdev_get_pad_format(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vsp1_entity *entity = to_vsp1_entity(subdev);
struct v4l2_subdev_pad_config *config;
config = vsp1_entity_get_pad_config(entity, cfg, fmt->which);
if (!config)
return -EINVAL;
fmt->format = *vsp1_entity_get_pad_format(entity, config, fmt->pad);
return 0;
}
int vsp1_subdev_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code,
const unsigned int *codes, unsigned int ncodes)
{
struct vsp1_entity *entity = to_vsp1_entity(subdev);
if (code->pad == 0) {
if (code->index >= ncodes)
return -EINVAL;
code->code = codes[code->index];
} else {
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
if (code->index)
return -EINVAL;
config = vsp1_entity_get_pad_config(entity, cfg, code->which);
if (!config)
return -EINVAL;
format = vsp1_entity_get_pad_format(entity, config, 0);
code->code = format->code;
}
return 0;
}
int vsp1_subdev_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse,
unsigned int min_width, unsigned int min_height,
unsigned int max_width, unsigned int max_height)
{
struct vsp1_entity *entity = to_vsp1_entity(subdev);
struct v4l2_subdev_pad_config *config;
struct v4l2_mbus_framefmt *format;
config = vsp1_entity_get_pad_config(entity, cfg, fse->which);
if (!config)
return -EINVAL;
format = vsp1_entity_get_pad_format(entity, config, fse->pad);
if (fse->index || fse->code != format->code)
return -EINVAL;
if (fse->pad == 0) {
fse->min_width = min_width;
fse->max_width = max_width;
fse->min_height = min_height;
fse->max_height = max_height;
} else {
fse->min_width = format->width;
fse->max_width = format->width;
fse->min_height = format->height;
fse->max_height = format->height;
}
return 0;
}
int vsp1_entity_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct vsp1_entity *source;
if (!(local->flags & MEDIA_PAD_FL_SOURCE))
return 0;
source = container_of(local->entity, struct vsp1_entity, subdev.entity);
if (!source->route)
return 0;
if (flags & MEDIA_LNK_FL_ENABLED) {
if (source->sink)
return -EBUSY;
source->sink = remote->entity;
source->sink_pad = remote->index;
} else {
source->sink = NULL;
source->sink_pad = 0;
}
return 0;
}
int vsp1_entity_init(struct vsp1_device *vsp1, struct vsp1_entity *entity,
const char *name, unsigned int num_pads,
const struct v4l2_subdev_ops *ops)
{
struct v4l2_subdev *subdev;
unsigned int i;
int ret;
for (i = 0; i < ARRAY_SIZE(vsp1_routes); ++i) {
if (vsp1_routes[i].type == entity->type &&
vsp1_routes[i].index == entity->index) {
entity->route = &vsp1_routes[i];
break;
}
}
if (i == ARRAY_SIZE(vsp1_routes))
return -EINVAL;
entity->vsp1 = vsp1;
entity->source_pad = num_pads - 1;
entity->pads = devm_kzalloc(vsp1->dev, num_pads * sizeof(*entity->pads),
GFP_KERNEL);
if (entity->pads == NULL)
return -ENOMEM;
for (i = 0; i < num_pads - 1; ++i)
entity->pads[i].flags = MEDIA_PAD_FL_SINK;
entity->pads[num_pads - 1].flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_pads_init(&entity->subdev.entity, num_pads,
entity->pads);
if (ret < 0)
return ret;
subdev = &entity->subdev;
v4l2_subdev_init(subdev, ops);
subdev->entity.ops = &vsp1->media_ops;
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
snprintf(subdev->name, sizeof(subdev->name), "%s %s",
dev_name(vsp1->dev), name);
vsp1_entity_init_cfg(subdev, NULL);
entity->config = v4l2_subdev_alloc_pad_config(&entity->subdev);
if (entity->config == NULL) {
media_entity_cleanup(&entity->subdev.entity);
return -ENOMEM;
}
return 0;
}
void vsp1_entity_destroy(struct vsp1_entity *entity)
{
if (entity->ops && entity->ops->destroy)
entity->ops->destroy(entity);
if (entity->subdev.ctrl_handler)
v4l2_ctrl_handler_free(entity->subdev.ctrl_handler);
v4l2_subdev_free_pad_config(entity->config);
media_entity_cleanup(&entity->subdev.entity);
}
