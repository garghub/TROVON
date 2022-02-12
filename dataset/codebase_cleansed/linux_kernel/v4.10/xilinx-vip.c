const struct xvip_video_format *xvip_get_format_by_code(unsigned int code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(xvip_video_formats); ++i) {
const struct xvip_video_format *format = &xvip_video_formats[i];
if (format->code == code)
return format;
}
return ERR_PTR(-EINVAL);
}
const struct xvip_video_format *xvip_get_format_by_fourcc(u32 fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(xvip_video_formats); ++i) {
const struct xvip_video_format *format = &xvip_video_formats[i];
if (format->fourcc == fourcc)
return format;
}
return ERR_PTR(-EINVAL);
}
const struct xvip_video_format *xvip_of_get_format(struct device_node *node)
{
const char *pattern = "mono";
unsigned int vf_code;
unsigned int i;
u32 width;
int ret;
ret = of_property_read_u32(node, "xlnx,video-format", &vf_code);
if (ret < 0)
return ERR_PTR(ret);
ret = of_property_read_u32(node, "xlnx,video-width", &width);
if (ret < 0)
return ERR_PTR(ret);
if (vf_code == XVIP_VF_MONO_SENSOR)
of_property_read_string(node, "xlnx,cfa-pattern", &pattern);
for (i = 0; i < ARRAY_SIZE(xvip_video_formats); ++i) {
const struct xvip_video_format *format = &xvip_video_formats[i];
if (format->vf_code != vf_code || format->width != width)
continue;
if (vf_code == XVIP_VF_MONO_SENSOR &&
strcmp(pattern, format->pattern))
continue;
return format;
}
return ERR_PTR(-EINVAL);
}
void xvip_set_format_size(struct v4l2_mbus_framefmt *format,
const struct v4l2_subdev_format *fmt)
{
format->width = clamp_t(unsigned int, fmt->format.width,
XVIP_MIN_WIDTH, XVIP_MAX_WIDTH);
format->height = clamp_t(unsigned int, fmt->format.height,
XVIP_MIN_HEIGHT, XVIP_MAX_HEIGHT);
}
void xvip_clr_or_set(struct xvip_device *xvip, u32 addr, u32 mask, bool set)
{
u32 reg;
reg = xvip_read(xvip, addr);
reg = set ? reg | mask : reg & ~mask;
xvip_write(xvip, addr, reg);
}
void xvip_clr_and_set(struct xvip_device *xvip, u32 addr, u32 clr, u32 set)
{
u32 reg;
reg = xvip_read(xvip, addr);
reg &= ~clr;
reg |= set;
xvip_write(xvip, addr, reg);
}
int xvip_init_resources(struct xvip_device *xvip)
{
struct platform_device *pdev = to_platform_device(xvip->dev);
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xvip->iomem = devm_ioremap_resource(xvip->dev, res);
if (IS_ERR(xvip->iomem))
return PTR_ERR(xvip->iomem);
xvip->clk = devm_clk_get(xvip->dev, NULL);
if (IS_ERR(xvip->clk))
return PTR_ERR(xvip->clk);
clk_prepare_enable(xvip->clk);
return 0;
}
void xvip_cleanup_resources(struct xvip_device *xvip)
{
clk_disable_unprepare(xvip->clk);
}
int xvip_enum_mbus_code(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct v4l2_mbus_framefmt *format;
if (code->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
if (code->index)
return -EINVAL;
format = v4l2_subdev_get_try_format(subdev, cfg, code->pad);
code->code = format->code;
return 0;
}
int xvip_enum_frame_size(struct v4l2_subdev *subdev,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct v4l2_mbus_framefmt *format;
if (fse->which == V4L2_SUBDEV_FORMAT_ACTIVE)
return -EINVAL;
format = v4l2_subdev_get_try_format(subdev, cfg, fse->pad);
if (fse->index || fse->code != format->code)
return -EINVAL;
if (fse->pad == XVIP_PAD_SINK) {
fse->min_width = XVIP_MIN_WIDTH;
fse->max_width = XVIP_MAX_WIDTH;
fse->min_height = XVIP_MIN_HEIGHT;
fse->max_height = XVIP_MAX_HEIGHT;
} else {
fse->min_width = format->width;
fse->max_width = format->width;
fse->min_height = format->height;
fse->max_height = format->height;
}
return 0;
}
