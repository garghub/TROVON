static int
exynos_update_plane(struct drm_plane *plane, struct drm_crtc *crtc,
struct drm_framebuffer *fb, int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct exynos_plane *exynos_plane =
container_of(plane, struct exynos_plane, base);
struct exynos_drm_overlay *overlay = &exynos_plane->overlay;
struct exynos_drm_crtc_pos pos;
unsigned int x = src_x >> 16;
unsigned int y = src_y >> 16;
int ret;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
memset(&pos, 0, sizeof(struct exynos_drm_crtc_pos));
pos.crtc_x = crtc_x;
pos.crtc_y = crtc_y;
pos.crtc_w = crtc_w;
pos.crtc_h = crtc_h;
pos.fb_x = x;
pos.fb_y = y;
ret = exynos_drm_overlay_update(overlay, fb, &crtc->mode, &pos);
if (ret < 0)
return ret;
exynos_drm_fn_encoder(crtc, overlay,
exynos_drm_encoder_crtc_mode_set);
exynos_drm_fn_encoder(crtc, &overlay->zpos,
exynos_drm_encoder_crtc_plane_commit);
exynos_plane->enabled = true;
return 0;
}
static int exynos_disable_plane(struct drm_plane *plane)
{
struct exynos_plane *exynos_plane =
container_of(plane, struct exynos_plane, base);
struct exynos_drm_overlay *overlay = &exynos_plane->overlay;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
if (!exynos_plane->enabled)
return 0;
exynos_drm_fn_encoder(plane->crtc, &overlay->zpos,
exynos_drm_encoder_crtc_disable);
exynos_plane->enabled = false;
exynos_plane->overlay.zpos = DEFAULT_ZPOS;
return 0;
}
static void exynos_plane_destroy(struct drm_plane *plane)
{
struct exynos_plane *exynos_plane =
container_of(plane, struct exynos_plane, base);
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
exynos_disable_plane(plane);
drm_plane_cleanup(plane);
kfree(exynos_plane);
}
int exynos_plane_init(struct drm_device *dev, unsigned int nr)
{
struct exynos_plane *exynos_plane;
uint32_t possible_crtcs;
exynos_plane = kzalloc(sizeof(struct exynos_plane), GFP_KERNEL);
if (!exynos_plane)
return -ENOMEM;
possible_crtcs = (1 << MAX_CRTC) - 1;
exynos_plane->overlay.zpos = DEFAULT_ZPOS;
return drm_plane_init(dev, &exynos_plane->base, possible_crtcs,
&exynos_plane_funcs, NULL, 0, false);
}
int exynos_plane_set_zpos_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_exynos_plane_set_zpos *zpos_req = data;
struct drm_mode_object *obj;
struct drm_plane *plane;
struct exynos_plane *exynos_plane;
int ret = 0;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
if (zpos_req->zpos < 0 || zpos_req->zpos >= MAX_PLANE) {
if (zpos_req->zpos != DEFAULT_ZPOS) {
DRM_ERROR("zpos not within limits\n");
return -EINVAL;
}
}
mutex_lock(&dev->mode_config.mutex);
obj = drm_mode_object_find(dev, zpos_req->plane_id,
DRM_MODE_OBJECT_PLANE);
if (!obj) {
DRM_DEBUG_KMS("Unknown plane ID %d\n",
zpos_req->plane_id);
ret = -EINVAL;
goto out;
}
plane = obj_to_plane(obj);
exynos_plane = container_of(plane, struct exynos_plane, base);
exynos_plane->overlay.zpos = zpos_req->zpos;
out:
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
