static const struct vimc_deb_pix_map *vimc_deb_pix_map_by_code(u32 code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(vimc_deb_pix_map_list); i++)
if (vimc_deb_pix_map_list[i].code == code)
return &vimc_deb_pix_map_list[i];
return NULL;
}
static int vimc_deb_init_cfg(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg)
{
struct vimc_deb_device *vdeb = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *mf;
unsigned int i;
mf = v4l2_subdev_get_try_format(sd, cfg, 0);
*mf = sink_fmt_default;
for (i = 1; i < sd->entity.num_pads; i++) {
mf = v4l2_subdev_get_try_format(sd, cfg, i);
*mf = sink_fmt_default;
mf->code = vdeb->src_code;
}
return 0;
}
static int vimc_deb_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (IS_SRC(code->pad)) {
struct vimc_deb_device *vdeb = v4l2_get_subdevdata(sd);
if (code->index)
return -EINVAL;
code->code = vdeb->src_code;
} else {
if (code->index >= ARRAY_SIZE(vimc_deb_pix_map_list))
return -EINVAL;
code->code = vimc_deb_pix_map_list[code->index].code;
}
return 0;
}
static int vimc_deb_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct vimc_deb_device *vdeb = v4l2_get_subdevdata(sd);
if (fse->index)
return -EINVAL;
if (IS_SINK(fse->pad)) {
const struct vimc_deb_pix_map *vpix =
vimc_deb_pix_map_by_code(fse->code);
if (!vpix)
return -EINVAL;
} else if (fse->code != vdeb->src_code) {
return -EINVAL;
}
fse->min_width = VIMC_FRAME_MIN_WIDTH;
fse->max_width = VIMC_FRAME_MAX_WIDTH;
fse->min_height = VIMC_FRAME_MIN_HEIGHT;
fse->max_height = VIMC_FRAME_MAX_HEIGHT;
return 0;
}
static int vimc_deb_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vimc_deb_device *vdeb = v4l2_get_subdevdata(sd);
fmt->format = fmt->which == V4L2_SUBDEV_FORMAT_TRY ?
*v4l2_subdev_get_try_format(sd, cfg, 0) :
vdeb->sink_fmt;
if (IS_SRC(fmt->pad))
fmt->format.code = vdeb->src_code;
return 0;
}
static void vimc_deb_adjust_sink_fmt(struct v4l2_mbus_framefmt *fmt)
{
const struct vimc_deb_pix_map *vpix;
vpix = vimc_deb_pix_map_by_code(fmt->code);
if (!vpix)
fmt->code = sink_fmt_default.code;
fmt->width = clamp_t(u32, fmt->width, VIMC_FRAME_MIN_WIDTH,
VIMC_FRAME_MAX_WIDTH) & ~1;
fmt->height = clamp_t(u32, fmt->height, VIMC_FRAME_MIN_HEIGHT,
VIMC_FRAME_MAX_HEIGHT) & ~1;
if (fmt->field == V4L2_FIELD_ANY)
fmt->field = sink_fmt_default.field;
vimc_colorimetry_clamp(fmt);
}
static int vimc_deb_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct vimc_deb_device *vdeb = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *sink_fmt;
if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
if (vdeb->src_frame)
return -EBUSY;
sink_fmt = &vdeb->sink_fmt;
} else {
sink_fmt = v4l2_subdev_get_try_format(sd, cfg, 0);
}
if (IS_SRC(fmt->pad)) {
fmt->format = *sink_fmt;
fmt->format.code = vdeb->src_code;
} else {
vimc_deb_adjust_sink_fmt(&fmt->format);
dev_dbg(vdeb->dev, "%s: sink format update: "
"old:%dx%d (0x%x, %d, %d, %d, %d) "
"new:%dx%d (0x%x, %d, %d, %d, %d)\n", vdeb->sd.name,
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
static void vimc_deb_set_rgb_mbus_fmt_rgb888_1x24(struct vimc_deb_device *vdeb,
unsigned int lin,
unsigned int col,
unsigned int rgb[3])
{
unsigned int i, index;
index = VIMC_FRAME_INDEX(lin, col, vdeb->sink_fmt.width, 3);
for (i = 0; i < 3; i++)
vdeb->src_frame[index + i] = rgb[i];
}
static int vimc_deb_s_stream(struct v4l2_subdev *sd, int enable)
{
struct vimc_deb_device *vdeb = v4l2_get_subdevdata(sd);
int ret;
if (enable) {
const struct vimc_pix_map *vpix;
unsigned int frame_size;
if (vdeb->src_frame)
return 0;
vpix = vimc_pix_map_by_code(vdeb->src_code);
frame_size = vdeb->sink_fmt.width * vdeb->sink_fmt.height *
vpix->bpp;
vpix = vimc_pix_map_by_code(vdeb->sink_fmt.code);
vdeb->sink_bpp = vpix->bpp;
vdeb->sink_pix_map =
vimc_deb_pix_map_by_code(vdeb->sink_fmt.code);
vdeb->src_frame = vmalloc(frame_size);
if (!vdeb->src_frame)
return -ENOMEM;
ret = vimc_pipeline_s_stream(&vdeb->sd.entity, 1);
if (ret) {
vfree(vdeb->src_frame);
vdeb->src_frame = NULL;
return ret;
}
} else {
if (!vdeb->src_frame)
return 0;
ret = vimc_pipeline_s_stream(&vdeb->sd.entity, 0);
if (ret)
return ret;
vfree(vdeb->src_frame);
vdeb->src_frame = NULL;
}
return 0;
}
static unsigned int vimc_deb_get_val(const u8 *bytes,
const unsigned int n_bytes)
{
unsigned int i;
unsigned int acc = 0;
for (i = 0; i < n_bytes; i++)
acc = acc + (bytes[i] << (8 * i));
return acc;
}
static void vimc_deb_calc_rgb_sink(struct vimc_deb_device *vdeb,
const u8 *frame,
const unsigned int lin,
const unsigned int col,
unsigned int rgb[3])
{
unsigned int i, seek, wlin, wcol;
unsigned int n_rgb[3] = {0, 0, 0};
for (i = 0; i < 3; i++)
rgb[i] = 0;
seek = deb_mean_win_size / 2;
dev_dbg(vdeb->dev,
"deb: %s: --- Calc pixel %dx%d, window mean %d, seek %d ---\n",
vdeb->sd.name, lin, col, vdeb->sink_fmt.height, seek);
for (wlin = seek > lin ? 0 : lin - seek;
wlin < lin + seek + 1 && wlin < vdeb->sink_fmt.height;
wlin++) {
for (wcol = seek > col ? 0 : col - seek;
wcol < col + seek + 1 && wcol < vdeb->sink_fmt.width;
wcol++) {
enum vimc_deb_rgb_colors color;
unsigned int index;
color = vdeb->sink_pix_map->order[wlin % 2][wcol % 2];
index = VIMC_FRAME_INDEX(wlin, wcol,
vdeb->sink_fmt.width,
vdeb->sink_bpp);
dev_dbg(vdeb->dev,
"deb: %s: RGB CALC: frame index %d, win pos %dx%d, color %d\n",
vdeb->sd.name, index, wlin, wcol, color);
rgb[color] = rgb[color] +
vimc_deb_get_val(&frame[index], vdeb->sink_bpp);
n_rgb[color]++;
dev_dbg(vdeb->dev, "deb: %s: RGB CALC: val %d, n %d\n",
vdeb->sd.name, rgb[color], n_rgb[color]);
}
}
for (i = 0; i < 3; i++) {
dev_dbg(vdeb->dev,
"deb: %s: PRE CALC: %dx%d Color %d, val %d, n %d\n",
vdeb->sd.name, lin, col, i, rgb[i], n_rgb[i]);
if (n_rgb[i])
rgb[i] = rgb[i] / n_rgb[i];
dev_dbg(vdeb->dev,
"deb: %s: FINAL CALC: %dx%d Color %d, val %d\n",
vdeb->sd.name, lin, col, i, rgb[i]);
}
}
static void vimc_deb_process_frame(struct vimc_ent_device *ved,
struct media_pad *sink,
const void *sink_frame)
{
struct vimc_deb_device *vdeb = container_of(ved, struct vimc_deb_device,
ved);
unsigned int rgb[3];
unsigned int i, j;
if (!vdeb->src_frame)
return;
for (i = 0; i < vdeb->sink_fmt.height; i++)
for (j = 0; j < vdeb->sink_fmt.width; j++) {
vimc_deb_calc_rgb_sink(vdeb, sink_frame, i, j, rgb);
vdeb->set_rgb_src(vdeb, i, j, rgb);
}
for (i = 1; i < vdeb->sd.entity.num_pads; i++) {
struct media_pad *pad = &vdeb->sd.entity.pads[i];
vimc_propagate_frame(pad, vdeb->src_frame);
}
}
static void vimc_deb_comp_unbind(struct device *comp, struct device *master,
void *master_data)
{
struct vimc_ent_device *ved = dev_get_drvdata(comp);
struct vimc_deb_device *vdeb = container_of(ved, struct vimc_deb_device,
ved);
vimc_ent_sd_unregister(ved, &vdeb->sd);
kfree(vdeb);
}
static int vimc_deb_comp_bind(struct device *comp, struct device *master,
void *master_data)
{
struct v4l2_device *v4l2_dev = master_data;
struct vimc_platform_data *pdata = comp->platform_data;
struct vimc_deb_device *vdeb;
int ret;
vdeb = kzalloc(sizeof(*vdeb), GFP_KERNEL);
if (!vdeb)
return -ENOMEM;
ret = vimc_ent_sd_register(&vdeb->ved, &vdeb->sd, v4l2_dev,
pdata->entity_name,
MEDIA_ENT_F_ATV_DECODER, 2,
(const unsigned long[2]) {MEDIA_PAD_FL_SINK,
MEDIA_PAD_FL_SOURCE},
&vimc_deb_ops);
if (ret) {
kfree(vdeb);
return ret;
}
vdeb->ved.process_frame = vimc_deb_process_frame;
dev_set_drvdata(comp, &vdeb->ved);
vdeb->dev = comp;
vdeb->sink_fmt = sink_fmt_default;
vdeb->src_code = MEDIA_BUS_FMT_RGB888_1X24;
vdeb->set_rgb_src = vimc_deb_set_rgb_mbus_fmt_rgb888_1x24;
return 0;
}
static int vimc_deb_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vimc_deb_comp_ops);
}
static int vimc_deb_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vimc_deb_comp_ops);
return 0;
}
