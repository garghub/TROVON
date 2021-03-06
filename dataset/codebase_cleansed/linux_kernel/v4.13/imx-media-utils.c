static void init_mbus_colorimetry(struct v4l2_mbus_framefmt *mbus,
const struct imx_media_pixfmt *fmt)
{
mbus->colorspace = (fmt->cs == IPUV3_COLORSPACE_RGB) ?
V4L2_COLORSPACE_SRGB : V4L2_COLORSPACE_SMPTE170M;
mbus->xfer_func = V4L2_MAP_XFER_FUNC_DEFAULT(mbus->colorspace);
mbus->ycbcr_enc = V4L2_MAP_YCBCR_ENC_DEFAULT(mbus->colorspace);
mbus->quantization =
V4L2_MAP_QUANTIZATION_DEFAULT(fmt->cs == IPUV3_COLORSPACE_RGB,
mbus->colorspace,
mbus->ycbcr_enc);
}
static const struct imx_media_pixfmt *find_format(u32 fourcc,
u32 code,
enum codespace_sel cs_sel,
bool allow_non_mbus,
bool allow_bayer)
{
const struct imx_media_pixfmt *array, *fmt, *ret = NULL;
u32 array_size;
int i, j;
switch (cs_sel) {
case CS_SEL_YUV:
array_size = NUM_YUV_FORMATS;
array = yuv_formats;
break;
case CS_SEL_RGB:
array_size = NUM_RGB_FORMATS;
array = rgb_formats;
break;
case CS_SEL_ANY:
array_size = NUM_YUV_FORMATS + NUM_RGB_FORMATS;
array = yuv_formats;
break;
default:
return NULL;
}
for (i = 0; i < array_size; i++) {
if (cs_sel == CS_SEL_ANY && i >= NUM_YUV_FORMATS)
fmt = &rgb_formats[i - NUM_YUV_FORMATS];
else
fmt = &array[i];
if ((!allow_non_mbus && fmt->codes[0] == 0) ||
(!allow_bayer && fmt->bayer))
continue;
if (fourcc && fmt->fourcc == fourcc) {
ret = fmt;
goto out;
}
for (j = 0; code && fmt->codes[j]; j++) {
if (code == fmt->codes[j]) {
ret = fmt;
goto out;
}
}
}
out:
return ret;
}
static int enum_format(u32 *fourcc, u32 *code, u32 index,
enum codespace_sel cs_sel,
bool allow_non_mbus,
bool allow_bayer)
{
const struct imx_media_pixfmt *fmt;
u32 mbus_yuv_sz = NUM_MBUS_YUV_FORMATS;
u32 mbus_rgb_sz = NUM_MBUS_RGB_FORMATS;
u32 yuv_sz = NUM_YUV_FORMATS;
u32 rgb_sz = NUM_RGB_FORMATS;
switch (cs_sel) {
case CS_SEL_YUV:
if (index >= yuv_sz ||
(!allow_non_mbus && index >= mbus_yuv_sz))
return -EINVAL;
fmt = &yuv_formats[index];
break;
case CS_SEL_RGB:
if (index >= rgb_sz ||
(!allow_non_mbus && index >= mbus_rgb_sz))
return -EINVAL;
fmt = &rgb_formats[index];
if (!allow_bayer && fmt->bayer)
return -EINVAL;
break;
case CS_SEL_ANY:
if (!allow_non_mbus) {
if (index >= mbus_yuv_sz) {
index -= mbus_yuv_sz;
if (index >= mbus_rgb_sz)
return -EINVAL;
fmt = &rgb_formats[index];
if (!allow_bayer && fmt->bayer)
return -EINVAL;
} else {
fmt = &yuv_formats[index];
}
} else {
if (index >= yuv_sz + rgb_sz)
return -EINVAL;
if (index >= yuv_sz) {
fmt = &rgb_formats[index - yuv_sz];
if (!allow_bayer && fmt->bayer)
return -EINVAL;
} else {
fmt = &yuv_formats[index];
}
}
break;
default:
return -EINVAL;
}
if (fourcc)
*fourcc = fmt->fourcc;
if (code)
*code = fmt->codes[0];
return 0;
}
const struct imx_media_pixfmt *
imx_media_find_format(u32 fourcc, enum codespace_sel cs_sel, bool allow_bayer)
{
return find_format(fourcc, 0, cs_sel, true, allow_bayer);
}
int imx_media_enum_format(u32 *fourcc, u32 index, enum codespace_sel cs_sel)
{
return enum_format(fourcc, NULL, index, cs_sel, true, false);
}
const struct imx_media_pixfmt *
imx_media_find_mbus_format(u32 code, enum codespace_sel cs_sel,
bool allow_bayer)
{
return find_format(0, code, cs_sel, false, allow_bayer);
}
int imx_media_enum_mbus_format(u32 *code, u32 index, enum codespace_sel cs_sel,
bool allow_bayer)
{
return enum_format(NULL, code, index, cs_sel, false, allow_bayer);
}
const struct imx_media_pixfmt *
imx_media_find_ipu_format(u32 code, enum codespace_sel cs_sel)
{
const struct imx_media_pixfmt *array, *fmt, *ret = NULL;
u32 array_size;
int i, j;
switch (cs_sel) {
case CS_SEL_YUV:
array_size = NUM_IPU_YUV_FORMATS;
array = ipu_yuv_formats;
break;
case CS_SEL_RGB:
array_size = NUM_IPU_RGB_FORMATS;
array = ipu_rgb_formats;
break;
case CS_SEL_ANY:
array_size = NUM_IPU_YUV_FORMATS + NUM_IPU_RGB_FORMATS;
array = ipu_yuv_formats;
break;
default:
return NULL;
}
for (i = 0; i < array_size; i++) {
if (cs_sel == CS_SEL_ANY && i >= NUM_IPU_YUV_FORMATS)
fmt = &ipu_rgb_formats[i - NUM_IPU_YUV_FORMATS];
else
fmt = &array[i];
for (j = 0; code && fmt->codes[j]; j++) {
if (code == fmt->codes[j]) {
ret = fmt;
goto out;
}
}
}
out:
return ret;
}
int imx_media_enum_ipu_format(u32 *code, u32 index, enum codespace_sel cs_sel)
{
switch (cs_sel) {
case CS_SEL_YUV:
if (index >= NUM_IPU_YUV_FORMATS)
return -EINVAL;
*code = ipu_yuv_formats[index].codes[0];
break;
case CS_SEL_RGB:
if (index >= NUM_IPU_RGB_FORMATS)
return -EINVAL;
*code = ipu_rgb_formats[index].codes[0];
break;
case CS_SEL_ANY:
if (index >= NUM_IPU_YUV_FORMATS + NUM_IPU_RGB_FORMATS)
return -EINVAL;
if (index >= NUM_IPU_YUV_FORMATS) {
index -= NUM_IPU_YUV_FORMATS;
*code = ipu_rgb_formats[index].codes[0];
} else {
*code = ipu_yuv_formats[index].codes[0];
}
break;
default:
return -EINVAL;
}
return 0;
}
int imx_media_init_mbus_fmt(struct v4l2_mbus_framefmt *mbus,
u32 width, u32 height, u32 code, u32 field,
const struct imx_media_pixfmt **cc)
{
const struct imx_media_pixfmt *lcc;
mbus->width = width;
mbus->height = height;
mbus->field = field;
if (code == 0)
imx_media_enum_mbus_format(&code, 0, CS_SEL_YUV, false);
lcc = imx_media_find_mbus_format(code, CS_SEL_ANY, false);
if (!lcc) {
lcc = imx_media_find_ipu_format(code, CS_SEL_ANY);
if (!lcc)
return -EINVAL;
}
mbus->code = code;
init_mbus_colorimetry(mbus, lcc);
if (cc)
*cc = lcc;
return 0;
}
void imx_media_fill_default_mbus_fields(struct v4l2_mbus_framefmt *tryfmt,
struct v4l2_mbus_framefmt *fmt,
bool ic_route)
{
const struct imx_media_pixfmt *cc;
bool is_rgb = false;
cc = imx_media_find_mbus_format(tryfmt->code, CS_SEL_ANY, true);
if (!cc)
cc = imx_media_find_ipu_format(tryfmt->code, CS_SEL_ANY);
if (cc && cc->cs != IPUV3_COLORSPACE_YUV)
is_rgb = true;
if (tryfmt->field == V4L2_FIELD_ANY)
tryfmt->field = fmt->field;
if (tryfmt->colorspace == V4L2_COLORSPACE_DEFAULT) {
tryfmt->colorspace = fmt->colorspace;
tryfmt->xfer_func = fmt->xfer_func;
tryfmt->ycbcr_enc = fmt->ycbcr_enc;
tryfmt->quantization = fmt->quantization;
} else {
if (tryfmt->xfer_func == V4L2_XFER_FUNC_DEFAULT) {
tryfmt->xfer_func =
V4L2_MAP_XFER_FUNC_DEFAULT(tryfmt->colorspace);
}
if (tryfmt->ycbcr_enc == V4L2_YCBCR_ENC_DEFAULT) {
tryfmt->ycbcr_enc =
V4L2_MAP_YCBCR_ENC_DEFAULT(tryfmt->colorspace);
}
if (tryfmt->quantization == V4L2_QUANTIZATION_DEFAULT) {
tryfmt->quantization =
V4L2_MAP_QUANTIZATION_DEFAULT(
is_rgb, tryfmt->colorspace,
tryfmt->ycbcr_enc);
}
}
if (ic_route) {
tryfmt->quantization = is_rgb ?
V4L2_QUANTIZATION_FULL_RANGE :
V4L2_QUANTIZATION_LIM_RANGE;
tryfmt->ycbcr_enc = V4L2_YCBCR_ENC_601;
}
}
int imx_media_mbus_fmt_to_pix_fmt(struct v4l2_pix_format *pix,
struct v4l2_mbus_framefmt *mbus,
const struct imx_media_pixfmt *cc)
{
u32 stride;
if (!cc) {
cc = imx_media_find_ipu_format(mbus->code, CS_SEL_ANY);
if (!cc)
cc = imx_media_find_mbus_format(mbus->code, CS_SEL_ANY,
true);
if (!cc)
return -EINVAL;
}
if (cc->ipufmt && cc->cs == IPUV3_COLORSPACE_YUV) {
u32 code;
imx_media_enum_mbus_format(&code, 0, CS_SEL_YUV, false);
cc = imx_media_find_mbus_format(code, CS_SEL_YUV, false);
}
stride = cc->planar ? mbus->width : (mbus->width * cc->bpp) >> 3;
pix->width = mbus->width;
pix->height = mbus->height;
pix->pixelformat = cc->fourcc;
pix->colorspace = mbus->colorspace;
pix->xfer_func = mbus->xfer_func;
pix->ycbcr_enc = mbus->ycbcr_enc;
pix->quantization = mbus->quantization;
pix->field = mbus->field;
pix->bytesperline = stride;
pix->sizeimage = (pix->width * pix->height * cc->bpp) >> 3;
return 0;
}
int imx_media_mbus_fmt_to_ipu_image(struct ipu_image *image,
struct v4l2_mbus_framefmt *mbus)
{
int ret;
memset(image, 0, sizeof(*image));
ret = imx_media_mbus_fmt_to_pix_fmt(&image->pix, mbus, NULL);
if (ret)
return ret;
image->rect.width = mbus->width;
image->rect.height = mbus->height;
return 0;
}
int imx_media_ipu_image_to_mbus_fmt(struct v4l2_mbus_framefmt *mbus,
struct ipu_image *image)
{
const struct imx_media_pixfmt *fmt;
fmt = imx_media_find_format(image->pix.pixelformat, CS_SEL_ANY, true);
if (!fmt)
return -EINVAL;
memset(mbus, 0, sizeof(*mbus));
mbus->width = image->pix.width;
mbus->height = image->pix.height;
mbus->code = fmt->codes[0];
mbus->field = image->pix.field;
mbus->colorspace = image->pix.colorspace;
mbus->xfer_func = image->pix.xfer_func;
mbus->ycbcr_enc = image->pix.ycbcr_enc;
mbus->quantization = image->pix.quantization;
return 0;
}
void imx_media_free_dma_buf(struct imx_media_dev *imxmd,
struct imx_media_dma_buf *buf)
{
if (buf->virt)
dma_free_coherent(imxmd->md.dev, buf->len,
buf->virt, buf->phys);
buf->virt = NULL;
buf->phys = 0;
}
int imx_media_alloc_dma_buf(struct imx_media_dev *imxmd,
struct imx_media_dma_buf *buf,
int size)
{
imx_media_free_dma_buf(imxmd, buf);
buf->len = PAGE_ALIGN(size);
buf->virt = dma_alloc_coherent(imxmd->md.dev, buf->len, &buf->phys,
GFP_DMA | GFP_KERNEL);
if (!buf->virt) {
dev_err(imxmd->md.dev, "failed to alloc dma buffer\n");
return -ENOMEM;
}
return 0;
}
void imx_media_grp_id_to_sd_name(char *sd_name, int sz, u32 grp_id, int ipu_id)
{
int id;
switch (grp_id) {
case IMX_MEDIA_GRP_ID_CSI0...IMX_MEDIA_GRP_ID_CSI1:
id = (grp_id >> IMX_MEDIA_GRP_ID_CSI_BIT) - 1;
snprintf(sd_name, sz, "ipu%d_csi%d", ipu_id + 1, id);
break;
case IMX_MEDIA_GRP_ID_VDIC:
snprintf(sd_name, sz, "ipu%d_vdic", ipu_id + 1);
break;
case IMX_MEDIA_GRP_ID_IC_PRP:
snprintf(sd_name, sz, "ipu%d_ic_prp", ipu_id + 1);
break;
case IMX_MEDIA_GRP_ID_IC_PRPENC:
snprintf(sd_name, sz, "ipu%d_ic_prpenc", ipu_id + 1);
break;
case IMX_MEDIA_GRP_ID_IC_PRPVF:
snprintf(sd_name, sz, "ipu%d_ic_prpvf", ipu_id + 1);
break;
default:
break;
}
}
struct imx_media_subdev *
imx_media_find_subdev_by_sd(struct imx_media_dev *imxmd,
struct v4l2_subdev *sd)
{
struct imx_media_subdev *imxsd;
int i;
for (i = 0; i < imxmd->num_subdevs; i++) {
imxsd = &imxmd->subdev[i];
if (sd == imxsd->sd)
return imxsd;
}
return ERR_PTR(-ENODEV);
}
struct imx_media_subdev *
imx_media_find_subdev_by_id(struct imx_media_dev *imxmd, u32 grp_id)
{
struct imx_media_subdev *imxsd;
int i;
for (i = 0; i < imxmd->num_subdevs; i++) {
imxsd = &imxmd->subdev[i];
if (imxsd->sd && imxsd->sd->grp_id == grp_id)
return imxsd;
}
return ERR_PTR(-ENODEV);
}
int imx_media_add_video_device(struct imx_media_dev *imxmd,
struct imx_media_video_dev *vdev)
{
int vdev_idx, ret = 0;
mutex_lock(&imxmd->mutex);
vdev_idx = imxmd->num_vdevs;
if (vdev_idx >= IMX_MEDIA_MAX_VDEVS) {
dev_err(imxmd->md.dev,
"%s: too many video devices! can't add %s\n",
__func__, vdev->vfd->name);
ret = -ENOSPC;
goto out;
}
imxmd->vdev[vdev_idx] = vdev;
imxmd->num_vdevs++;
out:
mutex_unlock(&imxmd->mutex);
return ret;
}
static struct media_pad *
find_pipeline_pad(struct imx_media_dev *imxmd,
struct media_entity *start_entity,
u32 grp_id, bool upstream)
{
struct media_entity *me = start_entity;
struct media_pad *pad = NULL;
struct v4l2_subdev *sd;
int i;
for (i = 0; i < me->num_pads; i++) {
struct media_pad *spad = &me->pads[i];
if ((upstream && !(spad->flags & MEDIA_PAD_FL_SINK)) ||
(!upstream && !(spad->flags & MEDIA_PAD_FL_SOURCE)))
continue;
pad = media_entity_remote_pad(spad);
if (!pad || !is_media_entity_v4l2_subdev(pad->entity))
continue;
sd = media_entity_to_v4l2_subdev(pad->entity);
if (sd->grp_id & grp_id)
return pad;
return find_pipeline_pad(imxmd, pad->entity, grp_id, upstream);
}
return NULL;
}
static struct v4l2_subdev *
find_upstream_subdev(struct imx_media_dev *imxmd,
struct media_entity *start_entity,
u32 grp_id)
{
struct v4l2_subdev *sd;
struct media_pad *pad;
if (is_media_entity_v4l2_subdev(start_entity)) {
sd = media_entity_to_v4l2_subdev(start_entity);
if (sd->grp_id & grp_id)
return sd;
}
pad = find_pipeline_pad(imxmd, start_entity, grp_id, true);
return pad ? media_entity_to_v4l2_subdev(pad->entity) : NULL;
}
int imx_media_find_mipi_csi2_channel(struct imx_media_dev *imxmd,
struct media_entity *start_entity)
{
struct media_pad *pad;
int ret = -EPIPE;
pad = find_pipeline_pad(imxmd, start_entity, IMX_MEDIA_GRP_ID_CSI2,
true);
if (pad) {
ret = pad->index - 1;
dev_dbg(imxmd->md.dev, "found vc%d from %s\n",
ret, start_entity->name);
}
return ret;
}
struct imx_media_subdev *
imx_media_find_upstream_subdev(struct imx_media_dev *imxmd,
struct media_entity *start_entity,
u32 grp_id)
{
struct v4l2_subdev *sd;
sd = find_upstream_subdev(imxmd, start_entity, grp_id);
if (!sd)
return ERR_PTR(-ENODEV);
return imx_media_find_subdev_by_sd(imxmd, sd);
}
struct imx_media_subdev *
__imx_media_find_sensor(struct imx_media_dev *imxmd,
struct media_entity *start_entity)
{
return imx_media_find_upstream_subdev(imxmd, start_entity,
IMX_MEDIA_GRP_ID_SENSOR);
}
struct imx_media_subdev *
imx_media_find_sensor(struct imx_media_dev *imxmd,
struct media_entity *start_entity)
{
struct imx_media_subdev *sensor;
mutex_lock(&imxmd->md.graph_mutex);
sensor = __imx_media_find_sensor(imxmd, start_entity);
mutex_unlock(&imxmd->md.graph_mutex);
return sensor;
}
int imx_media_pipeline_set_stream(struct imx_media_dev *imxmd,
struct media_entity *entity,
bool on)
{
struct v4l2_subdev *sd;
int ret = 0;
if (!is_media_entity_v4l2_subdev(entity))
return -EINVAL;
sd = media_entity_to_v4l2_subdev(entity);
mutex_lock(&imxmd->md.graph_mutex);
if (on) {
ret = __media_pipeline_start(entity, &imxmd->pipe);
if (ret)
goto out;
ret = v4l2_subdev_call(sd, video, s_stream, 1);
if (ret)
__media_pipeline_stop(entity);
} else {
v4l2_subdev_call(sd, video, s_stream, 0);
if (entity->pipe)
__media_pipeline_stop(entity);
}
out:
mutex_unlock(&imxmd->md.graph_mutex);
return ret;
}
