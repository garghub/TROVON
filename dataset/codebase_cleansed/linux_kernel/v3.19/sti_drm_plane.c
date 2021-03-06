static int
sti_drm_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct sti_layer *layer = to_sti_layer(plane);
struct sti_mixer *mixer = to_sti_mixer(crtc);
int res;
DRM_DEBUG_KMS("CRTC:%d (%s) drm plane:%d (%s) drm fb:%d\n",
crtc->base.id, sti_mixer_to_str(mixer),
plane->base.id, sti_layer_to_str(layer), fb->base.id);
DRM_DEBUG_KMS("(%dx%d)@(%d,%d)\n", crtc_w, crtc_h, crtc_x, crtc_y);
res = sti_mixer_set_layer_depth(mixer, layer);
if (res) {
DRM_ERROR("Can not set layer depth\n");
return res;
}
res = sti_layer_prepare(layer, crtc, fb,
&crtc->mode, mixer->id,
crtc_x, crtc_y, crtc_w, crtc_h,
src_x >> 16, src_y >> 16,
src_w >> 16, src_h >> 16);
if (res) {
DRM_ERROR("Layer prepare failed\n");
return res;
}
res = sti_layer_commit(layer);
if (res) {
DRM_ERROR("Layer commit failed\n");
return res;
}
res = sti_mixer_set_layer_status(mixer, layer, true);
if (res) {
DRM_ERROR("Can not enable layer at mixer\n");
return res;
}
return 0;
}
static int sti_drm_disable_plane(struct drm_plane *plane)
{
struct sti_layer *layer;
struct sti_mixer *mixer;
int lay_res, mix_res;
if (!plane->crtc) {
DRM_DEBUG_DRIVER("drm plane:%d not enabled\n", plane->base.id);
return 0;
}
layer = to_sti_layer(plane);
mixer = to_sti_mixer(plane->crtc);
DRM_DEBUG_DRIVER("CRTC:%d (%s) drm plane:%d (%s)\n",
plane->crtc->base.id, sti_mixer_to_str(mixer),
plane->base.id, sti_layer_to_str(layer));
mix_res = sti_mixer_set_layer_status(mixer, layer, false);
if (mix_res)
DRM_ERROR("Can not disable layer at mixer\n");
msleep(WAIT_NEXT_VSYNC_MS);
lay_res = sti_layer_disable(layer);
if (lay_res)
DRM_ERROR("Layer disable failed\n");
if (lay_res || mix_res)
return -EINVAL;
return 0;
}
static void sti_drm_plane_destroy(struct drm_plane *plane)
{
DRM_DEBUG_DRIVER("\n");
sti_drm_disable_plane(plane);
drm_plane_cleanup(plane);
}
static int sti_drm_plane_set_property(struct drm_plane *plane,
struct drm_property *property,
uint64_t val)
{
struct drm_device *dev = plane->dev;
struct sti_drm_private *private = dev->dev_private;
struct sti_layer *layer = to_sti_layer(plane);
DRM_DEBUG_DRIVER("\n");
if (property == private->plane_zorder_property) {
layer->zorder = val;
return 0;
}
return -EINVAL;
}
static void sti_drm_plane_attach_zorder_property(struct drm_plane *plane,
uint64_t default_val)
{
struct drm_device *dev = plane->dev;
struct sti_drm_private *private = dev->dev_private;
struct drm_property *prop;
struct sti_layer *layer = to_sti_layer(plane);
prop = private->plane_zorder_property;
if (!prop) {
prop = drm_property_create_range(dev, 0, "zpos", 0,
GAM_MIXER_NB_DEPTH_LEVEL - 1);
if (!prop)
return;
private->plane_zorder_property = prop;
}
drm_object_attach_property(&plane->base, prop, default_val);
layer->zorder = default_val;
}
struct drm_plane *sti_drm_plane_init(struct drm_device *dev,
struct sti_layer *layer,
unsigned int possible_crtcs,
enum drm_plane_type type)
{
int err, i;
uint64_t default_zorder = 0;
err = drm_universal_plane_init(dev, &layer->plane, possible_crtcs,
&sti_drm_plane_funcs,
sti_layer_get_formats(layer),
sti_layer_get_nb_formats(layer), type);
if (err) {
DRM_ERROR("Failed to initialize plane\n");
return NULL;
}
for (i = 0; i < ARRAY_SIZE(sti_layer_default_zorder); i++)
if (sti_layer_default_zorder[i] == layer->desc)
break;
default_zorder = i;
if (type == DRM_PLANE_TYPE_OVERLAY)
sti_drm_plane_attach_zorder_property(&layer->plane,
default_zorder);
DRM_DEBUG_DRIVER("drm plane:%d mapped to %s with zorder:%llu\n",
layer->plane.base.id,
sti_layer_to_str(layer), default_zorder);
return &layer->plane;
}
