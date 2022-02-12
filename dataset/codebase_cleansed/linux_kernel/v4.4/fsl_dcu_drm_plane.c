static int fsl_dcu_drm_plane_index(struct drm_plane *plane)
{
struct fsl_dcu_drm_device *fsl_dev = plane->dev->dev_private;
unsigned int total_layer = fsl_dev->soc->total_layer;
unsigned int index;
index = drm_plane_index(plane);
if (index < total_layer)
return total_layer - index - 1;
dev_err(fsl_dev->dev, "No more layer left\n");
return -EINVAL;
}
static int fsl_dcu_drm_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_framebuffer *fb = state->fb;
switch (fb->pixel_format) {
case DRM_FORMAT_RGB565:
case DRM_FORMAT_RGB888:
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_BGRA4444:
case DRM_FORMAT_ARGB1555:
case DRM_FORMAT_YUV422:
return 0;
default:
return -EINVAL;
}
}
static void fsl_dcu_drm_plane_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct fsl_dcu_drm_device *fsl_dev = plane->dev->dev_private;
unsigned int value;
int index, ret;
index = fsl_dcu_drm_plane_index(plane);
if (index < 0)
return;
ret = regmap_read(fsl_dev->regmap, DCU_CTRLDESCLN(index, 4), &value);
if (ret)
dev_err(fsl_dev->dev, "read DCU_INT_MASK failed\n");
value &= ~DCU_LAYER_EN;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 4), value);
if (ret)
dev_err(fsl_dev->dev, "set DCU register failed\n");
}
static void fsl_dcu_drm_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct fsl_dcu_drm_device *fsl_dev = plane->dev->dev_private;
struct drm_plane_state *state = plane->state;
struct drm_framebuffer *fb = plane->state->fb;
struct drm_gem_cma_object *gem;
unsigned int alpha, bpp;
int index, ret;
if (!fb)
return;
index = fsl_dcu_drm_plane_index(plane);
if (index < 0)
return;
gem = drm_fb_cma_get_gem_obj(fb, 0);
switch (fb->pixel_format) {
case DRM_FORMAT_RGB565:
bpp = FSL_DCU_RGB565;
alpha = 0xff;
break;
case DRM_FORMAT_RGB888:
bpp = FSL_DCU_RGB888;
alpha = 0xff;
break;
case DRM_FORMAT_ARGB8888:
bpp = FSL_DCU_ARGB8888;
alpha = 0xff;
break;
case DRM_FORMAT_BGRA4444:
bpp = FSL_DCU_ARGB4444;
alpha = 0xff;
break;
case DRM_FORMAT_ARGB1555:
bpp = FSL_DCU_ARGB1555;
alpha = 0xff;
break;
case DRM_FORMAT_YUV422:
bpp = FSL_DCU_YUV422;
alpha = 0xff;
break;
default:
return;
}
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 1),
DCU_LAYER_HEIGHT(state->crtc_h) |
DCU_LAYER_WIDTH(state->crtc_w));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 2),
DCU_LAYER_POSY(state->crtc_y) |
DCU_LAYER_POSX(state->crtc_x));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap,
DCU_CTRLDESCLN(index, 3), gem->paddr);
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 4),
DCU_LAYER_EN |
DCU_LAYER_TRANS(alpha) |
DCU_LAYER_BPP(bpp) |
DCU_LAYER_AB(0));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 5),
DCU_LAYER_CKMAX_R(0xFF) |
DCU_LAYER_CKMAX_G(0xFF) |
DCU_LAYER_CKMAX_B(0xFF));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 6),
DCU_LAYER_CKMIN_R(0) |
DCU_LAYER_CKMIN_G(0) |
DCU_LAYER_CKMIN_B(0));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 7), 0);
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 8),
DCU_LAYER_FG_FCOLOR(0));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 9),
DCU_LAYER_BG_BCOLOR(0));
if (ret)
goto set_failed;
if (!strcmp(fsl_dev->soc->name, "ls1021a")) {
ret = regmap_write(fsl_dev->regmap, DCU_CTRLDESCLN(index, 10),
DCU_LAYER_POST_SKIP(0) |
DCU_LAYER_PRE_SKIP(0));
if (ret)
goto set_failed;
}
ret = regmap_update_bits(fsl_dev->regmap, DCU_DCU_MODE,
DCU_MODE_DCU_MODE_MASK,
DCU_MODE_DCU_MODE(DCU_MODE_NORMAL));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap,
DCU_UPDATE_MODE, DCU_UPDATE_MODE_READREG);
if (ret)
goto set_failed;
return;
set_failed:
dev_err(fsl_dev->dev, "set DCU register failed\n");
}
static void
fsl_dcu_drm_plane_cleanup_fb(struct drm_plane *plane,
const struct drm_plane_state *new_state)
{
}
static int
fsl_dcu_drm_plane_prepare_fb(struct drm_plane *plane,
const struct drm_plane_state *new_state)
{
return 0;
}
static void fsl_dcu_drm_plane_destroy(struct drm_plane *plane)
{
drm_plane_cleanup(plane);
}
struct drm_plane *fsl_dcu_drm_primary_create_plane(struct drm_device *dev)
{
struct drm_plane *primary;
int ret;
primary = kzalloc(sizeof(*primary), GFP_KERNEL);
if (!primary) {
DRM_DEBUG_KMS("Failed to allocate primary plane\n");
return NULL;
}
ret = drm_universal_plane_init(dev, primary, 0,
&fsl_dcu_drm_plane_funcs,
fsl_dcu_drm_plane_formats,
ARRAY_SIZE(fsl_dcu_drm_plane_formats),
DRM_PLANE_TYPE_PRIMARY);
if (ret) {
kfree(primary);
primary = NULL;
}
drm_plane_helper_add(primary, &fsl_dcu_drm_plane_helper_funcs);
return primary;
}
