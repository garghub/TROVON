struct v4l2_mbus_framefmt *
vsp1_entity_get_pad_format(struct vsp1_entity *entity,
struct v4l2_subdev_fh *fh,
unsigned int pad, u32 which)
{
switch (which) {
case V4L2_SUBDEV_FORMAT_TRY:
return v4l2_subdev_get_try_format(fh, pad);
case V4L2_SUBDEV_FORMAT_ACTIVE:
return &entity->formats[pad];
default:
return NULL;
}
}
void vsp1_entity_init_formats(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format;
unsigned int pad;
for (pad = 0; pad < subdev->entity.num_pads - 1; ++pad) {
memset(&format, 0, sizeof(format));
format.pad = pad;
format.which = fh ? V4L2_SUBDEV_FORMAT_TRY
: V4L2_SUBDEV_FORMAT_ACTIVE;
v4l2_subdev_call(subdev, pad, set_fmt, fh, &format);
}
}
static int vsp1_entity_open(struct v4l2_subdev *subdev,
struct v4l2_subdev_fh *fh)
{
vsp1_entity_init_formats(subdev, fh);
return 0;
}
static int vsp1_entity_link_setup(struct media_entity *entity,
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
unsigned int num_pads)
{
unsigned int i;
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
entity->formats = devm_kzalloc(vsp1->dev,
num_pads * sizeof(*entity->formats),
GFP_KERNEL);
if (entity->formats == NULL)
return -ENOMEM;
entity->pads = devm_kzalloc(vsp1->dev, num_pads * sizeof(*entity->pads),
GFP_KERNEL);
if (entity->pads == NULL)
return -ENOMEM;
for (i = 0; i < num_pads - 1; ++i)
entity->pads[i].flags = MEDIA_PAD_FL_SINK;
entity->pads[num_pads - 1].flags = MEDIA_PAD_FL_SOURCE;
return media_entity_init(&entity->subdev.entity, num_pads,
entity->pads, 0);
}
void vsp1_entity_destroy(struct vsp1_entity *entity)
{
if (entity->subdev.ctrl_handler)
v4l2_ctrl_handler_free(entity->subdev.ctrl_handler);
media_entity_cleanup(&entity->subdev.entity);
}
