static void file_work(struct work_struct *work)
{
struct atomisp_file_device *file_dev =
container_of(work, struct atomisp_file_device, work);
struct atomisp_device *isp = file_dev->isp;
struct atomisp_sub_device *asd = &isp->asd[0];
struct atomisp_video_pipe *out_pipe = &asd->video_in;
unsigned short *buf = videobuf_to_vmalloc(out_pipe->outq.bufs[0]);
struct v4l2_mbus_framefmt isp_sink_fmt;
if (asd->streaming != ATOMISP_DEVICE_STREAMING_ENABLED)
return;
dev_dbg(isp->dev, ">%s: ready to start streaming\n", __func__);
isp_sink_fmt = *atomisp_subdev_get_ffmt(&asd->subdev, NULL,
V4L2_SUBDEV_FORMAT_ACTIVE,
ATOMISP_SUBDEV_PAD_SINK);
while (!atomisp_css_isp_has_started())
usleep_range(1000, 1500);
atomisp_css_send_input_frame(asd, buf, isp_sink_fmt.width,
isp_sink_fmt.height);
dev_dbg(isp->dev, "<%s: streaming done\n", __func__);
}
static int file_input_s_stream(struct v4l2_subdev *sd, int enable)
{
struct atomisp_file_device *file_dev = v4l2_get_subdevdata(sd);
struct atomisp_device *isp = file_dev->isp;
struct atomisp_sub_device *asd = &isp->asd[0];
dev_dbg(isp->dev, "%s: enable %d\n", __func__, enable);
if (enable) {
if (asd->streaming != ATOMISP_DEVICE_STREAMING_ENABLED)
return 0;
queue_work(file_dev->work_queue, &file_dev->work);
return 0;
}
cancel_work_sync(&file_dev->work);
return 0;
}
static int file_input_g_parm(struct v4l2_subdev *sd,
struct v4l2_streamparm *param)
{
return 0;
}
static int file_input_s_parm(struct v4l2_subdev *sd,
struct v4l2_streamparm *param)
{
return 0;
}
static int file_input_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct atomisp_file_device *file_dev = v4l2_get_subdevdata(sd);
struct atomisp_device *isp = file_dev->isp;
struct atomisp_sub_device *asd = &isp->asd[0];
struct v4l2_mbus_framefmt *isp_sink_fmt;
if (format->pad)
return -EINVAL;
isp_sink_fmt = atomisp_subdev_get_ffmt(&asd->subdev, NULL,
V4L2_SUBDEV_FORMAT_ACTIVE,
ATOMISP_SUBDEV_PAD_SINK);
fmt->width = isp_sink_fmt->width;
fmt->height = isp_sink_fmt->height;
fmt->code = isp_sink_fmt->code;
return 0;
}
static int file_input_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
if (format->pad)
return -EINVAL;
file_input_get_fmt(sd, cfg, format);
if (format->which == V4L2_SUBDEV_FORMAT_TRY)
cfg->try_fmt = *fmt;
return 0;
}
static int file_input_log_status(struct v4l2_subdev *sd)
{
return 0;
}
static int file_input_s_power(struct v4l2_subdev *sd, int on)
{
return 0;
}
static int file_input_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
return 0;
}
static int file_input_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
return 0;
}
static int file_input_enum_frame_ival(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_interval_enum
*fie)
{
return 0;
}
void
atomisp_file_input_unregister_entities(struct atomisp_file_device *file_dev)
{
media_entity_cleanup(&file_dev->sd.entity);
v4l2_device_unregister_subdev(&file_dev->sd);
}
int atomisp_file_input_register_entities(struct atomisp_file_device *file_dev,
struct v4l2_device *vdev)
{
return v4l2_device_register_subdev(vdev, &file_dev->sd);
}
void atomisp_file_input_cleanup(struct atomisp_device *isp)
{
struct atomisp_file_device *file_dev = &isp->file_dev;
if (file_dev->work_queue) {
destroy_workqueue(file_dev->work_queue);
file_dev->work_queue = NULL;
}
}
int atomisp_file_input_init(struct atomisp_device *isp)
{
struct atomisp_file_device *file_dev = &isp->file_dev;
struct v4l2_subdev *sd = &file_dev->sd;
struct media_pad *pads = file_dev->pads;
struct media_entity *me = &sd->entity;
file_dev->isp = isp;
file_dev->work_queue = alloc_workqueue(isp->v4l2_dev.name, 0, 1);
if (file_dev->work_queue == NULL) {
dev_err(isp->dev, "Failed to initialize file inject workq\n");
return -ENOMEM;
}
INIT_WORK(&file_dev->work, file_work);
v4l2_subdev_init(sd, &file_input_ops);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
strcpy(sd->name, "file_input_subdev");
v4l2_set_subdevdata(sd, file_dev);
pads[0].flags = MEDIA_PAD_FL_SINK;
me->function = MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN;
return media_entity_pads_init(me, 1, pads);
}
