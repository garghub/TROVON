static int tpg_s_stream(struct v4l2_subdev *sd, int enable)
{
return 0;
}
static int tpg_g_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *param)
{
return 0;
}
static int tpg_s_parm(struct v4l2_subdev *sd, struct v4l2_streamparm *param)
{
return 0;
}
static int tpg_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
return 0;
}
static int tpg_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
if (format->pad)
return -EINVAL;
fmt->code = MEDIA_BUS_FMT_SGRBG8_1X8;
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
cfg->try_fmt = *fmt;
return 0;
}
return 0;
}
static int tpg_log_status(struct v4l2_subdev *sd)
{
return 0;
}
static int tpg_s_power(struct v4l2_subdev *sd, int on)
{
return 0;
}
static int tpg_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
return 0;
}
static int tpg_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
return 0;
}
static int tpg_enum_frame_ival(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_interval_enum *fie)
{
return 0;
}
void atomisp_tpg_unregister_entities(struct atomisp_tpg_device *tpg)
{
media_entity_cleanup(&tpg->sd.entity);
v4l2_device_unregister_subdev(&tpg->sd);
}
int atomisp_tpg_register_entities(struct atomisp_tpg_device *tpg,
struct v4l2_device *vdev)
{
int ret;
ret = v4l2_device_register_subdev(vdev, &tpg->sd);
if (ret < 0)
goto error;
return 0;
error:
atomisp_tpg_unregister_entities(tpg);
return ret;
}
void atomisp_tpg_cleanup(struct atomisp_device *isp)
{
}
int atomisp_tpg_init(struct atomisp_device *isp)
{
struct atomisp_tpg_device *tpg = &isp->tpg;
struct v4l2_subdev *sd = &tpg->sd;
struct media_pad *pads = tpg->pads;
struct media_entity *me = &sd->entity;
int ret;
tpg->isp = isp;
v4l2_subdev_init(sd, &tpg_ops);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
strcpy(sd->name, "tpg_subdev");
v4l2_set_subdevdata(sd, tpg);
pads[0].flags = MEDIA_PAD_FL_SINK;
me->function = MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN;
ret = media_entity_pads_init(me, 1, pads);
if (ret < 0)
goto fail;
return 0;
fail:
atomisp_tpg_cleanup(isp);
return ret;
}
