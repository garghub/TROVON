static int atmel_hlcdc_format_to_plane_mode(u32 format, u32 *mode)
{
switch (format) {
case DRM_FORMAT_XRGB4444:
*mode = ATMEL_HLCDC_XRGB4444_MODE;
break;
case DRM_FORMAT_ARGB4444:
*mode = ATMEL_HLCDC_ARGB4444_MODE;
break;
case DRM_FORMAT_RGBA4444:
*mode = ATMEL_HLCDC_RGBA4444_MODE;
break;
case DRM_FORMAT_RGB565:
*mode = ATMEL_HLCDC_RGB565_MODE;
break;
case DRM_FORMAT_RGB888:
*mode = ATMEL_HLCDC_RGB888_MODE;
break;
case DRM_FORMAT_ARGB1555:
*mode = ATMEL_HLCDC_ARGB1555_MODE;
break;
case DRM_FORMAT_XRGB8888:
*mode = ATMEL_HLCDC_XRGB8888_MODE;
break;
case DRM_FORMAT_ARGB8888:
*mode = ATMEL_HLCDC_ARGB8888_MODE;
break;
case DRM_FORMAT_RGBA8888:
*mode = ATMEL_HLCDC_RGBA8888_MODE;
break;
case DRM_FORMAT_AYUV:
*mode = ATMEL_HLCDC_AYUV_MODE;
break;
case DRM_FORMAT_YUYV:
*mode = ATMEL_HLCDC_YUYV_MODE;
break;
case DRM_FORMAT_UYVY:
*mode = ATMEL_HLCDC_UYVY_MODE;
break;
case DRM_FORMAT_YVYU:
*mode = ATMEL_HLCDC_YVYU_MODE;
break;
case DRM_FORMAT_VYUY:
*mode = ATMEL_HLCDC_VYUY_MODE;
break;
case DRM_FORMAT_NV21:
*mode = ATMEL_HLCDC_NV21_MODE;
break;
case DRM_FORMAT_NV61:
*mode = ATMEL_HLCDC_NV61_MODE;
break;
case DRM_FORMAT_YUV420:
*mode = ATMEL_HLCDC_YUV420_MODE;
break;
case DRM_FORMAT_YUV422:
*mode = ATMEL_HLCDC_YUV422_MODE;
break;
default:
return -ENOTSUPP;
}
return 0;
}
static bool atmel_hlcdc_format_embedds_alpha(u32 format)
{
int i;
for (i = 0; i < sizeof(format); i++) {
char tmp = (format >> (8 * i)) & 0xff;
if (tmp == 'A')
return true;
}
return false;
}
static void
atmel_hlcdc_plane_update_pos_and_size(struct atmel_hlcdc_plane *plane,
struct atmel_hlcdc_plane_update_req *req)
{
const struct atmel_hlcdc_layer_cfg_layout *layout =
&plane->layer.desc->layout;
if (layout->size)
atmel_hlcdc_layer_update_cfg(&plane->layer,
layout->size,
0xffffffff,
(req->crtc_w - 1) |
((req->crtc_h - 1) << 16));
if (layout->memsize)
atmel_hlcdc_layer_update_cfg(&plane->layer,
layout->memsize,
0xffffffff,
(req->src_w - 1) |
((req->src_h - 1) << 16));
if (layout->pos)
atmel_hlcdc_layer_update_cfg(&plane->layer,
layout->pos,
0xffffffff,
req->crtc_x |
(req->crtc_y << 16));
if (req->crtc_w != req->src_w || req->crtc_h != req->src_h) {
u32 factor_reg = 0;
if (req->crtc_w != req->src_w) {
int i;
u32 factor;
u32 *coeff_tab = heo_upscaling_xcoef;
u32 max_memsize;
if (req->crtc_w < req->src_w)
coeff_tab = heo_downscaling_xcoef;
for (i = 0; i < ARRAY_SIZE(heo_upscaling_xcoef); i++)
atmel_hlcdc_layer_update_cfg(&plane->layer,
17 + i,
0xffffffff,
coeff_tab[i]);
factor = ((8 * 256 * req->src_w) - (256 * 4)) /
req->crtc_w;
factor++;
max_memsize = ((factor * req->crtc_w) + (256 * 4)) /
2048;
if (max_memsize > req->src_w)
factor--;
factor_reg |= factor | 0x80000000;
}
if (req->crtc_h != req->src_h) {
int i;
u32 factor;
u32 *coeff_tab = heo_upscaling_ycoef;
u32 max_memsize;
if (req->crtc_w < req->src_w)
coeff_tab = heo_downscaling_ycoef;
for (i = 0; i < ARRAY_SIZE(heo_upscaling_ycoef); i++)
atmel_hlcdc_layer_update_cfg(&plane->layer,
33 + i,
0xffffffff,
coeff_tab[i]);
factor = ((8 * 256 * req->src_w) - (256 * 4)) /
req->crtc_w;
factor++;
max_memsize = ((factor * req->crtc_w) + (256 * 4)) /
2048;
if (max_memsize > req->src_w)
factor--;
factor_reg |= (factor << 16) | 0x80000000;
}
atmel_hlcdc_layer_update_cfg(&plane->layer, 13, 0xffffffff,
factor_reg);
}
}
static void
atmel_hlcdc_plane_update_general_settings(struct atmel_hlcdc_plane *plane,
struct atmel_hlcdc_plane_update_req *req)
{
const struct atmel_hlcdc_layer_cfg_layout *layout =
&plane->layer.desc->layout;
unsigned int cfg = ATMEL_HLCDC_LAYER_DMA;
if (plane->base.type != DRM_PLANE_TYPE_PRIMARY) {
cfg |= ATMEL_HLCDC_LAYER_OVR | ATMEL_HLCDC_LAYER_ITER2BL |
ATMEL_HLCDC_LAYER_ITER;
if (atmel_hlcdc_format_embedds_alpha(req->fb->pixel_format))
cfg |= ATMEL_HLCDC_LAYER_LAEN;
else
cfg |= ATMEL_HLCDC_LAYER_GAEN;
}
atmel_hlcdc_layer_update_cfg(&plane->layer,
ATMEL_HLCDC_LAYER_DMA_CFG_ID,
ATMEL_HLCDC_LAYER_DMA_BLEN_MASK,
ATMEL_HLCDC_LAYER_DMA_BLEN_INCR16);
atmel_hlcdc_layer_update_cfg(&plane->layer, layout->general_config,
ATMEL_HLCDC_LAYER_ITER2BL |
ATMEL_HLCDC_LAYER_ITER |
ATMEL_HLCDC_LAYER_GAEN |
ATMEL_HLCDC_LAYER_LAEN |
ATMEL_HLCDC_LAYER_OVR |
ATMEL_HLCDC_LAYER_DMA, cfg);
}
static void atmel_hlcdc_plane_update_format(struct atmel_hlcdc_plane *plane,
struct atmel_hlcdc_plane_update_req *req)
{
u32 cfg;
int ret;
ret = atmel_hlcdc_format_to_plane_mode(req->fb->pixel_format, &cfg);
if (ret)
return;
if ((req->fb->pixel_format == DRM_FORMAT_YUV422 ||
req->fb->pixel_format == DRM_FORMAT_NV61) &&
(plane->rotation & (BIT(DRM_ROTATE_90) | BIT(DRM_ROTATE_270))))
cfg |= ATMEL_HLCDC_YUV422ROT;
atmel_hlcdc_layer_update_cfg(&plane->layer,
ATMEL_HLCDC_LAYER_FORMAT_CFG_ID,
0xffffffff,
cfg);
if (req->fb->pixel_format == DRM_FORMAT_RGB888)
cfg = ATMEL_HLCDC_LAYER_DMA_ROTDIS;
else
cfg = 0;
atmel_hlcdc_layer_update_cfg(&plane->layer,
ATMEL_HLCDC_LAYER_DMA_CFG_ID,
ATMEL_HLCDC_LAYER_DMA_ROTDIS, cfg);
}
static void atmel_hlcdc_plane_update_buffers(struct atmel_hlcdc_plane *plane,
struct atmel_hlcdc_plane_update_req *req)
{
struct atmel_hlcdc_layer *layer = &plane->layer;
const struct atmel_hlcdc_layer_cfg_layout *layout =
&layer->desc->layout;
int i;
atmel_hlcdc_layer_update_set_fb(&plane->layer, req->fb, req->offsets);
for (i = 0; i < req->nplanes; i++) {
if (layout->xstride[i]) {
atmel_hlcdc_layer_update_cfg(&plane->layer,
layout->xstride[i],
0xffffffff,
req->xstride[i]);
}
if (layout->pstride[i]) {
atmel_hlcdc_layer_update_cfg(&plane->layer,
layout->pstride[i],
0xffffffff,
req->pstride[i]);
}
}
}
static int atmel_hlcdc_plane_check_update_req(struct drm_plane *p,
struct atmel_hlcdc_plane_update_req *req,
const struct drm_display_mode *mode)
{
struct atmel_hlcdc_plane *plane = drm_plane_to_atmel_hlcdc_plane(p);
const struct atmel_hlcdc_layer_cfg_layout *layout =
&plane->layer.desc->layout;
if (!layout->size &&
(mode->hdisplay != req->crtc_w ||
mode->vdisplay != req->crtc_h))
return -EINVAL;
if (plane->layer.desc->max_height &&
req->crtc_h > plane->layer.desc->max_height)
return -EINVAL;
if (plane->layer.desc->max_width &&
req->crtc_w > plane->layer.desc->max_width)
return -EINVAL;
if ((req->crtc_h != req->src_h || req->crtc_w != req->src_w) &&
(!layout->memsize ||
atmel_hlcdc_format_embedds_alpha(req->fb->pixel_format)))
return -EINVAL;
if (req->crtc_x < 0 || req->crtc_y < 0)
return -EINVAL;
if (req->crtc_w + req->crtc_x > mode->hdisplay ||
req->crtc_h + req->crtc_y > mode->vdisplay)
return -EINVAL;
return 0;
}
int atmel_hlcdc_plane_prepare_update_req(struct drm_plane *p,
struct atmel_hlcdc_plane_update_req *req,
const struct drm_display_mode *mode)
{
struct atmel_hlcdc_plane *plane = drm_plane_to_atmel_hlcdc_plane(p);
unsigned int patched_crtc_w;
unsigned int patched_crtc_h;
unsigned int patched_src_w;
unsigned int patched_src_h;
unsigned int tmp;
int x_offset = 0;
int y_offset = 0;
int hsub = 1;
int vsub = 1;
int i;
if ((req->src_x | req->src_y | req->src_w | req->src_h) &
SUBPIXEL_MASK)
return -EINVAL;
req->src_x >>= 16;
req->src_y >>= 16;
req->src_w >>= 16;
req->src_h >>= 16;
req->nplanes = drm_format_num_planes(req->fb->pixel_format);
if (req->nplanes > ATMEL_HLCDC_MAX_PLANES)
return -EINVAL;
if (plane->rotation & (BIT(DRM_ROTATE_90) | BIT(DRM_ROTATE_270))) {
tmp = req->crtc_w;
req->crtc_w = req->crtc_h;
req->crtc_h = tmp;
tmp = req->src_w;
req->src_w = req->src_h;
req->src_h = tmp;
}
if (req->crtc_x + req->crtc_w > mode->hdisplay)
patched_crtc_w = mode->hdisplay - req->crtc_x;
else
patched_crtc_w = req->crtc_w;
if (req->crtc_x < 0) {
patched_crtc_w += req->crtc_x;
x_offset = -req->crtc_x;
req->crtc_x = 0;
}
if (req->crtc_y + req->crtc_h > mode->vdisplay)
patched_crtc_h = mode->vdisplay - req->crtc_y;
else
patched_crtc_h = req->crtc_h;
if (req->crtc_y < 0) {
patched_crtc_h += req->crtc_y;
y_offset = -req->crtc_y;
req->crtc_y = 0;
}
patched_src_w = DIV_ROUND_CLOSEST(patched_crtc_w * req->src_w,
req->crtc_w);
patched_src_h = DIV_ROUND_CLOSEST(patched_crtc_h * req->src_h,
req->crtc_h);
hsub = drm_format_horz_chroma_subsampling(req->fb->pixel_format);
vsub = drm_format_vert_chroma_subsampling(req->fb->pixel_format);
for (i = 0; i < req->nplanes; i++) {
unsigned int offset = 0;
int xdiv = i ? hsub : 1;
int ydiv = i ? vsub : 1;
req->bpp[i] = drm_format_plane_cpp(req->fb->pixel_format, i);
if (!req->bpp[i])
return -EINVAL;
switch (plane->rotation & 0xf) {
case BIT(DRM_ROTATE_90):
offset = ((y_offset + req->src_y + patched_src_w - 1) /
ydiv) * req->fb->pitches[i];
offset += ((x_offset + req->src_x) / xdiv) *
req->bpp[i];
req->xstride[i] = ((patched_src_w - 1) / ydiv) *
req->fb->pitches[i];
req->pstride[i] = -req->fb->pitches[i] - req->bpp[i];
break;
case BIT(DRM_ROTATE_180):
offset = ((y_offset + req->src_y + patched_src_h - 1) /
ydiv) * req->fb->pitches[i];
offset += ((x_offset + req->src_x + patched_src_w - 1) /
xdiv) * req->bpp[i];
req->xstride[i] = ((((patched_src_w - 1) / xdiv) - 1) *
req->bpp[i]) - req->fb->pitches[i];
req->pstride[i] = -2 * req->bpp[i];
break;
case BIT(DRM_ROTATE_270):
offset = ((y_offset + req->src_y) / ydiv) *
req->fb->pitches[i];
offset += ((x_offset + req->src_x + patched_src_h - 1) /
xdiv) * req->bpp[i];
req->xstride[i] = -(((patched_src_w - 1) / ydiv) *
req->fb->pitches[i]) -
(2 * req->bpp[i]);
req->pstride[i] = req->fb->pitches[i] - req->bpp[i];
break;
case BIT(DRM_ROTATE_0):
default:
offset = ((y_offset + req->src_y) / ydiv) *
req->fb->pitches[i];
offset += ((x_offset + req->src_x) / xdiv) *
req->bpp[i];
req->xstride[i] = req->fb->pitches[i] -
((patched_src_w / xdiv) *
req->bpp[i]);
req->pstride[i] = 0;
break;
}
req->offsets[i] = offset + req->fb->offsets[i];
}
req->src_w = patched_src_w;
req->src_h = patched_src_h;
req->crtc_w = patched_crtc_w;
req->crtc_h = patched_crtc_h;
return atmel_hlcdc_plane_check_update_req(p, req, mode);
}
int atmel_hlcdc_plane_apply_update_req(struct drm_plane *p,
struct atmel_hlcdc_plane_update_req *req)
{
struct atmel_hlcdc_plane *plane = drm_plane_to_atmel_hlcdc_plane(p);
int ret;
ret = atmel_hlcdc_layer_update_start(&plane->layer);
if (ret)
return ret;
atmel_hlcdc_plane_update_pos_and_size(plane, req);
atmel_hlcdc_plane_update_general_settings(plane, req);
atmel_hlcdc_plane_update_format(plane, req);
atmel_hlcdc_plane_update_buffers(plane, req);
atmel_hlcdc_layer_update_commit(&plane->layer);
return 0;
}
int atmel_hlcdc_plane_update_with_mode(struct drm_plane *p,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w,
unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h,
const struct drm_display_mode *mode)
{
struct atmel_hlcdc_plane *plane = drm_plane_to_atmel_hlcdc_plane(p);
struct atmel_hlcdc_plane_update_req req;
int ret = 0;
memset(&req, 0, sizeof(req));
req.crtc_x = crtc_x;
req.crtc_y = crtc_y;
req.crtc_w = crtc_w;
req.crtc_h = crtc_h;
req.src_x = src_x;
req.src_y = src_y;
req.src_w = src_w;
req.src_h = src_h;
req.fb = fb;
ret = atmel_hlcdc_plane_prepare_update_req(&plane->base, &req, mode);
if (ret)
return ret;
if (!req.crtc_h || !req.crtc_w)
return atmel_hlcdc_layer_disable(&plane->layer);
return atmel_hlcdc_plane_apply_update_req(&plane->base, &req);
}
static int atmel_hlcdc_plane_update(struct drm_plane *p,
struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
return atmel_hlcdc_plane_update_with_mode(p, crtc, fb, crtc_x, crtc_y,
crtc_w, crtc_h, src_x, src_y,
src_w, src_h, &crtc->hwmode);
}
static int atmel_hlcdc_plane_disable(struct drm_plane *p)
{
struct atmel_hlcdc_plane *plane = drm_plane_to_atmel_hlcdc_plane(p);
return atmel_hlcdc_layer_disable(&plane->layer);
}
static void atmel_hlcdc_plane_destroy(struct drm_plane *p)
{
struct atmel_hlcdc_plane *plane = drm_plane_to_atmel_hlcdc_plane(p);
if (plane->base.fb)
drm_framebuffer_unreference(plane->base.fb);
atmel_hlcdc_layer_cleanup(p->dev, &plane->layer);
drm_plane_cleanup(p);
devm_kfree(p->dev->dev, plane);
}
static int atmel_hlcdc_plane_set_alpha(struct atmel_hlcdc_plane *plane,
u8 alpha)
{
atmel_hlcdc_layer_update_start(&plane->layer);
atmel_hlcdc_layer_update_cfg(&plane->layer,
plane->layer.desc->layout.general_config,
ATMEL_HLCDC_LAYER_GA_MASK,
alpha << ATMEL_HLCDC_LAYER_GA_SHIFT);
atmel_hlcdc_layer_update_commit(&plane->layer);
return 0;
}
static int atmel_hlcdc_plane_set_rotation(struct atmel_hlcdc_plane *plane,
unsigned int rotation)
{
plane->rotation = rotation;
return 0;
}
static int atmel_hlcdc_plane_set_property(struct drm_plane *p,
struct drm_property *property,
uint64_t value)
{
struct atmel_hlcdc_plane *plane = drm_plane_to_atmel_hlcdc_plane(p);
struct atmel_hlcdc_plane_properties *props = plane->properties;
if (property == props->alpha)
atmel_hlcdc_plane_set_alpha(plane, value);
else if (property == props->rotation)
atmel_hlcdc_plane_set_rotation(plane, value);
else
return -EINVAL;
return 0;
}
static void atmel_hlcdc_plane_init_properties(struct atmel_hlcdc_plane *plane,
const struct atmel_hlcdc_layer_desc *desc,
struct atmel_hlcdc_plane_properties *props)
{
struct regmap *regmap = plane->layer.hlcdc->regmap;
if (desc->type == ATMEL_HLCDC_OVERLAY_LAYER ||
desc->type == ATMEL_HLCDC_CURSOR_LAYER) {
drm_object_attach_property(&plane->base.base,
props->alpha, 255);
regmap_update_bits(regmap,
desc->regs_offset +
ATMEL_HLCDC_LAYER_GENERAL_CFG(&plane->layer),
ATMEL_HLCDC_LAYER_GA_MASK,
ATMEL_HLCDC_LAYER_GA_MASK);
}
if (desc->layout.xstride && desc->layout.pstride)
drm_object_attach_property(&plane->base.base,
props->rotation,
BIT(DRM_ROTATE_0));
if (desc->layout.csc) {
regmap_write(regmap,
desc->regs_offset +
ATMEL_HLCDC_LAYER_CSC_CFG(&plane->layer, 0),
0x4c900091);
regmap_write(regmap,
desc->regs_offset +
ATMEL_HLCDC_LAYER_CSC_CFG(&plane->layer, 1),
0x7a5f5090);
regmap_write(regmap,
desc->regs_offset +
ATMEL_HLCDC_LAYER_CSC_CFG(&plane->layer, 2),
0x40040890);
}
}
static struct atmel_hlcdc_plane *
atmel_hlcdc_plane_create(struct drm_device *dev,
const struct atmel_hlcdc_layer_desc *desc,
struct atmel_hlcdc_plane_properties *props)
{
struct atmel_hlcdc_plane *plane;
enum drm_plane_type type;
int ret;
plane = devm_kzalloc(dev->dev, sizeof(*plane), GFP_KERNEL);
if (!plane)
return ERR_PTR(-ENOMEM);
ret = atmel_hlcdc_layer_init(dev, &plane->layer, desc);
if (ret)
return ERR_PTR(ret);
if (desc->type == ATMEL_HLCDC_BASE_LAYER)
type = DRM_PLANE_TYPE_PRIMARY;
else if (desc->type == ATMEL_HLCDC_CURSOR_LAYER)
type = DRM_PLANE_TYPE_CURSOR;
else
type = DRM_PLANE_TYPE_OVERLAY;
ret = drm_universal_plane_init(dev, &plane->base, 0,
&layer_plane_funcs,
desc->formats->formats,
desc->formats->nformats, type);
if (ret)
return ERR_PTR(ret);
atmel_hlcdc_plane_init_properties(plane, desc, props);
return plane;
}
static struct atmel_hlcdc_plane_properties *
atmel_hlcdc_plane_create_properties(struct drm_device *dev)
{
struct atmel_hlcdc_plane_properties *props;
props = devm_kzalloc(dev->dev, sizeof(*props), GFP_KERNEL);
if (!props)
return ERR_PTR(-ENOMEM);
props->alpha = drm_property_create_range(dev, 0, "alpha", 0, 255);
if (!props->alpha)
return ERR_PTR(-ENOMEM);
props->rotation = drm_mode_create_rotation_property(dev,
BIT(DRM_ROTATE_0) |
BIT(DRM_ROTATE_90) |
BIT(DRM_ROTATE_180) |
BIT(DRM_ROTATE_270));
if (!props->rotation)
return ERR_PTR(-ENOMEM);
return props;
}
struct atmel_hlcdc_planes *
atmel_hlcdc_create_planes(struct drm_device *dev)
{
struct atmel_hlcdc_dc *dc = dev->dev_private;
struct atmel_hlcdc_plane_properties *props;
struct atmel_hlcdc_planes *planes;
const struct atmel_hlcdc_layer_desc *descs = dc->desc->layers;
int nlayers = dc->desc->nlayers;
int i;
planes = devm_kzalloc(dev->dev, sizeof(*planes), GFP_KERNEL);
if (!planes)
return ERR_PTR(-ENOMEM);
for (i = 0; i < nlayers; i++) {
if (descs[i].type == ATMEL_HLCDC_OVERLAY_LAYER)
planes->noverlays++;
}
if (planes->noverlays) {
planes->overlays = devm_kzalloc(dev->dev,
planes->noverlays *
sizeof(*planes->overlays),
GFP_KERNEL);
if (!planes->overlays)
return ERR_PTR(-ENOMEM);
}
props = atmel_hlcdc_plane_create_properties(dev);
if (IS_ERR(props))
return ERR_CAST(props);
planes->noverlays = 0;
for (i = 0; i < nlayers; i++) {
struct atmel_hlcdc_plane *plane;
if (descs[i].type == ATMEL_HLCDC_PP_LAYER)
continue;
plane = atmel_hlcdc_plane_create(dev, &descs[i], props);
if (IS_ERR(plane))
return ERR_CAST(plane);
plane->properties = props;
switch (descs[i].type) {
case ATMEL_HLCDC_BASE_LAYER:
if (planes->primary)
return ERR_PTR(-EINVAL);
planes->primary = plane;
break;
case ATMEL_HLCDC_OVERLAY_LAYER:
planes->overlays[planes->noverlays++] = plane;
break;
case ATMEL_HLCDC_CURSOR_LAYER:
if (planes->cursor)
return ERR_PTR(-EINVAL);
planes->cursor = plane;
break;
default:
break;
}
}
return planes;
}
