static int vimc_sca_init_cfg(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg)
{
struct v4l2_mbus_framefmt *mf;
unsigned int i;
mf = v4l2_subdev_get_try_format(sd, cfg, 0);
*mf = sink_fmt_default;
for (i = 1; i < sd->entity.num_pads; i++) {
mf = v4l2_subdev_get_try_format(sd, cfg, i);
*mf = sink_fmt_default;
mf->width = mf->width * sca_mult;
mf->height = mf->height * sca_mult;
}
return 0;
}
static int vimc_sca_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
const struct vimc_pix_map *vpix = vimc_pix_map_by_index(code->index);
if (!vpix || vpix->bayer)
return -EINVAL;
code->code = vpix->code;
return 0;
}
static int vimc_sca_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
const struct vimc_pix_map *vpix;
if (fse->index)
return -EINVAL;
vpix = vimc_pix_map_by_code(fse->code);
if (!vpix || vpix->bayer)
return -EINVAL;
fse->min_width = VIMC_FRAME_MIN_WIDTH;
fse->min_height = VIMC_FRAME_MIN_HEIGHT;
if (IS_SINK(fse->pad)) {
fse->max_width = VIMC_FRAME_MAX_WIDTH;
fse->max_height = VIMC_FRAME_MAX_HEIGHT;
} else {
fse->max_width = VIMC_FRAME_MAX_WIDTH * MAX_ZOOM;
fse->max_height = VIMC_FRAME_MAX_HEIGHT * MAX_ZOOM;
}
return 0;
}
static int vimc_sca_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct vimc_sca_device *vsca = v4l2_get_subdevdata(sd);
format->format = (format->which == V4L2_SUBDEV_FORMAT_TRY) ?
*v4l2_subdev_get_try_format(sd, cfg, 0) :
vsca->sink_fmt;
if (IS_SRC(format->pad)) {
format->format.width = vsca->sink_fmt.width * sca_mult;
format->format.height = vsca->sink_fmt.height * sca_mult;
}
return 0;
}
static void vimc_sca_adjust_sink_fmt(struct v4l2_mbus_framefmt *fmt)
{
const struct vimc_pix_map *vpix;
vpix = vimc_pix_map_by_code(fmt->code);
if (!vpix || vpix->bayer)
fmt->code = sink_fmt_default.code;
fmt->width = clamp_t(u32, fmt->width, VIMC_FRAME_MIN_WIDTH,
VIMC_FRAME_MAX_WIDTH) & ~1;
fmt->height = clamp_t(u32, fmt->height, VIMC_FRAME_MIN_HEIGHT,
VIMC_FRAME_MAX_HEIGHT) & ~1;
if (fmt->field == V4L2_FIELD_ANY)
fmt->field = sink_fmt_default.field;
vimc_colorimetry_clamp(fmt);
}
static int vimc_sca_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vimc_sca_device *vsca = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *sink_fmt;
if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
if (vsca->src_frame)
return -EBUSY;
sink_fmt = &vsca->sink_fmt;
} else {
sink_fmt = v4l2_subdev_get_try_format(sd, cfg, 0);
}
if (IS_SRC(fmt->pad)) {
fmt->format = *sink_fmt;
fmt->format.width = sink_fmt->width * sca_mult;
fmt->format.height = sink_fmt->height * sca_mult;
} else {
vimc_sca_adjust_sink_fmt(&fmt->format);
dev_dbg(vsca->dev, "%s: sink format update: "
"old:%dx%d (0x%x, %d, %d, %d, %d) "
"new:%dx%d (0x%x, %d, %d, %d, %d)\n", vsca->sd.name,
sink_fmt->width, sink_fmt->height, sink_fmt->code,
sink_fmt->colorspace, sink_fmt->quantization,
sink_fmt->xfer_func, sink_fmt->ycbcr_enc,
fmt->format.width, fmt->format.height, fmt->format.code,
fmt->format.colorspace, fmt->format.quantization,
fmt->format.xfer_func, fmt->format.ycbcr_enc);
*sink_fmt = fmt->format;
}
return 0;
}
static int vimc_sca_s_stream(struct v4l2_subdev *sd, int enable)
{
struct vimc_sca_device *vsca = v4l2_get_subdevdata(sd);
int ret;
if (enable) {
const struct vimc_pix_map *vpix;
unsigned int frame_size;
if (vsca->src_frame)
return 0;
vpix = vimc_pix_map_by_code(vsca->sink_fmt.code);
vsca->bpp = vpix->bpp;
vsca->src_line_size = vsca->sink_fmt.width *
sca_mult * vsca->bpp;
frame_size = vsca->src_line_size * vsca->sink_fmt.height *
sca_mult;
vsca->src_frame = vmalloc(frame_size);
if (!vsca->src_frame)
return -ENOMEM;
ret = vimc_pipeline_s_stream(&vsca->sd.entity, 1);
if (ret) {
vfree(vsca->src_frame);
vsca->src_frame = NULL;
return ret;
}
} else {
if (!vsca->src_frame)
return 0;
ret = vimc_pipeline_s_stream(&vsca->sd.entity, 0);
if (ret)
return ret;
vfree(vsca->src_frame);
vsca->src_frame = NULL;
}
return 0;
}
static void vimc_sca_fill_pix(u8 *const ptr,
const u8 *const pixel,
const unsigned int bpp)
{
unsigned int i;
for (i = 0; i < bpp; i++)
ptr[i] = pixel[i];
}
static void vimc_sca_scale_pix(const struct vimc_sca_device *const vsca,
const unsigned int lin, const unsigned int col,
const u8 *const sink_frame)
{
unsigned int i, j, index;
const u8 *pixel;
index = VIMC_FRAME_INDEX(lin, col,
vsca->sink_fmt.width,
vsca->bpp);
pixel = &sink_frame[index];
dev_dbg(vsca->dev,
"sca: %s: --- scale_pix sink pos %dx%d, index %d ---\n",
vsca->sd.name, lin, col, index);
index = VIMC_FRAME_INDEX(lin * sca_mult, col * sca_mult,
vsca->sink_fmt.width * sca_mult, vsca->bpp);
dev_dbg(vsca->dev, "sca: %s: scale_pix src pos %dx%d, index %d\n",
vsca->sd.name, lin * sca_mult, col * sca_mult, index);
for (i = 0; i < sca_mult; i++) {
for (j = 0; j < sca_mult * vsca->bpp; j += vsca->bpp) {
dev_dbg(vsca->dev,
"sca: %s: sca: scale_pix src pos %d\n",
vsca->sd.name, index + j);
vimc_sca_fill_pix(&vsca->src_frame[index + j],
pixel, vsca->bpp);
}
index += vsca->src_line_size;
}
}
static void vimc_sca_fill_src_frame(const struct vimc_sca_device *const vsca,
const u8 *const sink_frame)
{
unsigned int i, j;
for (i = 0; i < vsca->sink_fmt.height; i++)
for (j = 0; j < vsca->sink_fmt.width; j++)
vimc_sca_scale_pix(vsca, i, j, sink_frame);
}
static void vimc_sca_process_frame(struct vimc_ent_device *ved,
struct media_pad *sink,
const void *sink_frame)
{
struct vimc_sca_device *vsca = container_of(ved, struct vimc_sca_device,
ved);
unsigned int i;
if (!vsca->src_frame)
return;
vimc_sca_fill_src_frame(vsca, sink_frame);
for (i = 1; i < vsca->sd.entity.num_pads; i++) {
struct media_pad *pad = &vsca->sd.entity.pads[i];
vimc_propagate_frame(pad, vsca->src_frame);
}
}
static void vimc_sca_comp_unbind(struct device *comp, struct device *master,
void *master_data)
{
struct vimc_ent_device *ved = dev_get_drvdata(comp);
struct vimc_sca_device *vsca = container_of(ved, struct vimc_sca_device,
ved);
vimc_ent_sd_unregister(ved, &vsca->sd);
kfree(vsca);
}
static int vimc_sca_comp_bind(struct device *comp, struct device *master,
void *master_data)
{
struct v4l2_device *v4l2_dev = master_data;
struct vimc_platform_data *pdata = comp->platform_data;
struct vimc_sca_device *vsca;
int ret;
vsca = kzalloc(sizeof(*vsca), GFP_KERNEL);
if (!vsca)
return -ENOMEM;
ret = vimc_ent_sd_register(&vsca->ved, &vsca->sd, v4l2_dev,
pdata->entity_name,
MEDIA_ENT_F_ATV_DECODER, 2,
(const unsigned long[2]) {MEDIA_PAD_FL_SINK,
MEDIA_PAD_FL_SOURCE},
&vimc_sca_ops);
if (ret) {
kfree(vsca);
return ret;
}
vsca->ved.process_frame = vimc_sca_process_frame;
dev_set_drvdata(comp, &vsca->ved);
vsca->dev = comp;
vsca->sink_fmt = sink_fmt_default;
return 0;
}
static int vimc_sca_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vimc_sca_comp_ops);
}
static int vimc_sca_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vimc_sca_comp_ops);
return 0;
}
